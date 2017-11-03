#include <stdint.h>
#include "msp430f6638.h"
#include "TM1638.h"
#include "wav.h"
#include "ff.h"


#define  _MY_CPU_F 12288000 
static Wav the_Song; //the song will be played;
FIL songfile;
uint16_t volume = 0; // 音量

extern const uint8_t Num[16];
extern const uint8_t Addr[8];

typedef enum {
    BUFF1 = 0,
  BUFF2 = 1,
  NOTREADY = 2

  
} buffState;

uint8_t streambuff [513];




static buffState    _BUFFSTATE; //正在播放哪一面
static SongfileStat _MYSTATE;
#define FCC(c1,c2,c3,c4)	(((uint32_t)c4<<24)+((uint32_t)c3<<16)+((uint16_t)c2<<8)+(uint8_t)c1)
int parseWav(const char* Name)
{

  uint16_t numOfRead = 0;
  _MYSTATE = NOINIT;
  _BUFFSTATE = NOTREADY;

  if ((numOfRead = f_open(&songfile,Name,FA_READ))!=0)
  return 2;
  if (f_read(&songfile,&the_Song.riff,12,&numOfRead)) return 0;
  if (numOfRead!=12 || *((uint32_t*)the_Song.riff.Format) != FCC('W','A','V','E') ) return 0;
  if (f_read(&songfile,&the_Song.fmt,8,&numOfRead)) return 0;
  if  (numOfRead != 8 || *((uint32_t*)the_Song.fmt.Subchunk1ID) != FCC('f','m','t',' ') ) return 0;
  if  (f_read(&songfile,&the_Song.fmt.AudioFormat,the_Song.fmt.Subchunk1Size,&numOfRead)) return 0;
  if (numOfRead != the_Song.fmt.Subchunk1Size) return 0;
  if (f_read(&songfile,&the_Song.data,8,&numOfRead)) return 0;
  if  (numOfRead != 8 ) return 0;
  switch (*((uint32_t*)the_Song.data.Subchunk2ID))
  {
  case FCC('D','I','S','P'):		/* 'DISP' chunk */
  case FCC('L','I','S','T'):		/* 'LIST' chunk */
  case FCC('f','a','c','t'):
    if (f_read(&songfile,&the_Song.data,8,&numOfRead)) return 0;
  case FCC('d','a','t','a'):
    break;
  }
  if (the_Song.fmt.AudioFormat !=1 
      || (the_Song.fmt.BitsPerSample != 8 && the_Song.fmt.BitsPerSample != 16) 
      || the_Song.fmt.SampleRate > 48000 ) 
    return 0;
  

  _MYSTATE = WORKING;
  return 1;
}
SongfileStat Songstate(void)
{
  return _MYSTATE;
}
uint32_t seconds(void)
{
  if (!_MYSTATE) return 0;
  else return the_Song.data.Subchunk2Size/the_Song.fmt.ByteRate;
}

static void _SET_TIMERA(void)
{
    DAC12_1CTL0 = DAC12IR + DAC12SREF_1 + DAC12AMP_5 + DAC12ENC + DAC12CALON+DAC12OPS;
    DAC12_1DAT =0;
    P5DIR|=BIT6;
    P5OUT&=~BIT6;

    //ADC setting
    P6SEL |= BIT6;
    ADC12CTL0 |= ADC12ON + ADC12SHT0_9 + ADC12MSC;
    ADC12CTL1 |= ADC12SHP + ADC12CONSEQ_2 +ADC12SSEL_2;
    ADC12MCTL0 |= ADC12INCH_6;
    ADC12CTL0 |= ADC12SC + ADC12ENC;



    TA0CCTL0 |= CCIE;                          // CCR0 interrupt enabled
    // negedge interrupt
    P4IES |= BIT2 + BIT3;
    // enable interrupt
    P4IE |= BIT2 + BIT3;
    TA0CCR0 = _MY_CPU_F / the_Song.fmt.SampleRate-1;
    TA0CTL = TASSEL_2 + MC_1 + TACLR ;         // SMCLK, upmode, clear TAR
    _EINT();
}

/*
*播放函数，双缓冲技术
*
*/

int start_play(void)
{
  uint16_t numOfRead;
  //如果未有文件可读，则返回
  if (_MYSTATE == NOINIT) return 0; 
  if (_BUFFSTATE != NOTREADY) return 1;
  //首先读到BUFF1
  if (f_read(&songfile,streambuff,256,&numOfRead))
    return 2;
  _BUFFSTATE = BUFF1;
  
  _SET_TIMERA();
  int i_state = BUFF2;
  while (1)
  {
    if (_MYSTATE == STOPED) // play stoped by stop function
    {  _DINT();
       f_close(&songfile);
      //               disable timer Interrupt
      // TODO :                DESET TIMER
      TA0CTL |= MC_0;
      return                    3;
    }
    else
    {
        Write_DATA(Addr[6],Num[8-volume]);
    }
    if (i_state != _BUFFSTATE) // 换面
    {
     
      f_read(&songfile,streambuff + (((uint16_t)i_state) << 8),256,&numOfRead);
      i_state = _BUFFSTATE;
      if (numOfRead != 256)
      {
          _DINT();
        stop_play();
        f_close(&songfile);
        // TODO                  DESET TIMER
        TA0CTL |= MC_0;
        return                  4;
      }
    }
    
  }
  
}

int stop_play(void)
{
  //TODO
   P5OUT|= BIT6;
  _MYSTATE = STOPED;
  _BUFFSTATE = NOTREADY;
  ADC12CTL0 = 0; // 简单粗暴
//  f_close(&songfile);
  return 1;
}


#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer_A0(void)
{
  static uint8_t iter_Sample = 0;   // 总是指向下一个要读取的字节
  if (ADC12IFG&BIT0)
  {
      volume = ADC12MEM0 >> 9;
      ADC12IFG &= ~BIT0;

  }
  uint8_t* datait =  streambuff + ((_BUFFSTATE << 8) + iter_Sample);
  if (the_Song.fmt.BitsPerSample == 16)
  {
    if (the_Song.fmt.NumChannels == 1)
    {
      DAC12_1DAT = (((datait[1] - 0x80)<<4)|(datait[0]>>4)) >> volume;
      iter_Sample += 2;
    }
    else if(the_Song.fmt.NumChannels == 2)
    {
     DAC12_1DAT = (((datait[1] - 0x80)<<3)|(datait[0]>>5) + ((datait[3] - 0x80)<<3)|(datait[2]>>5)) >> volume;
     iter_Sample += 4;
    }
  }
  else if (the_Song.fmt.BitsPerSample == 8)
  {
    if (the_Song.fmt.NumChannels == 1)
    {
      DAC12_1DAT = ((*(uint8_t*)datait) << 4) >> volume;
      iter_Sample += 1;
    }
    else if(the_Song.fmt.NumChannels == 2)
    {
      DAC12_1DAT = (((*(uint8_t*)datait) << 3) + ((*(uint8_t*)(datait + 1)) << 3))>>volume;
      iter_Sample += 2;
    }
  }
  if (datait ==  streambuff + ((_BUFFSTATE << 8) + iter_Sample))
    return;
  if (iter_Sample == 0)
    _BUFFSTATE ^= 1;
  
}
#pragma vector = PORT4_VECTOR
__interrupt void Port_4(void)
{
  if (P4IFG & BIT2)
  {
     TA0CTL|= MC_0;
 //    P5DIR&= ~BIT6;
     stop_play();
     P4IFG &= ~BIT2;
  }
  else if (P4IFG & BIT3)
  {
    if (TA0CTL & MC_1) 
    {
      P5OUT  |= BIT6;
      TA0CTL &= ~MC_3;
    }
    else
    {
      P5OUT &= ~BIT6;
      TA0CTL|= MC_1;
    }
    P4IFG &= ~BIT3;
  }
  return;
}
