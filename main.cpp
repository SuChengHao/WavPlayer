#include <stdint.h>
#include <string.h>
#include "msp430.h"
#include "ff.h"
#include "TM1638.h"
#include "wav.h"

#define XT1_PORT_SEL            P5SEL
#define XT1_ENABLE              (BIT4 + BIT5)
extern char buffer[30]; //255
const uint8_t Num[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77,0x7C, 0x39, 0x5E, 0x79, 0x71};
const uint8_t Addr[8] = {0x08, 0x0a, 0x0c, 0x0e, 0x00, 0x02, 0x04, 0x06};
const TCHAR* musicname = "Music";
const TCHAR* musicDir = "Music/";
DIRS musicDirec;

void init_port(void)
{
	P3DIR |= BIT5;
	P3DIR |= BIT4 + BIT2;

	// Configure SDCard ports
	PJDIR |= BIT0;                 // SD_CS to high
	PJOUT |= BIT0; 
}

void init_clk(void)
{
	XT1_PORT_SEL |= XT1_ENABLE;               // Select XT1
	UCSCTL3 |= SELREF_2;                      // Set DCO FLL reference = REFO
	UCSCTL4 |= SELA_2;                        // Set ACLK = REFO

	__bis_SR_register(SCG0);                  // Disable the FLL control loop
	UCSCTL0 = 0x0000;                         // Set lowest possible DCOx, MODx
	UCSCTL1 = DCORSEL_5;                      // Select DCO range 24MHz operation
	UCSCTL2 = FLLD_1 + 374;                   // Set DCO Multiplier for 12MHz
		                                      // (N + 1) * FLLRef = Fdco
		                                      // (374 + 1) * 32768 = 12MHz
		                                      // Set FLL Div = fDCOCLK/2
	__bic_SR_register(SCG0);              	  // Enable the FLL control loop
	// Loop until XT1,XT2 & DCO fault flag is cleared
	do
	{
		UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);		// Clear XT2,XT1,DCO fault flags
		SFRIFG1 &= ~OFIFG;                      		// Clear fault flags
	}while (SFRIFG1&OFIFG);                   			// Test oscillator fault flag
}

void show_Num(int num)
{
  Write_DATA(Addr[2],Num[num%10]);
  num/=10;
  Write_DATA(Addr[1],Num[num%10]);
  num/=10;
  Write_DATA(Addr[0],Num[num%10]);
}
int playList(DIRS* openedDir)
{
  FILINFO direcEnt;
  int readDirres;
  int parseres;
  int t_start;
  char ItersongName[20];
  int Numt = 1;
  for(;;)
  {
    Numt++;
   show_Num(Numt);
   if ((readDirres = f_readdir(openedDir,&direcEnt))!= 0) 
   {
     Write_DATA(Addr[4],Num[readDirres]);
     //f_closedir(openedDir);
     return 3;//fata error
   }
   
   if (direcEnt.fname[0] == '0')
   {
     //f_closedir(openedDir);
     return 0; //over
   }
   strcpy(ItersongName,musicDir);
   strcat(ItersongName,direcEnt.fname);
   Write_DATA(Addr[5],Num[5]);
   if ((parseres = parseWav (ItersongName))!=0)
   {
     
     t_start = start_play();
     
     if (t_start == 3||t_start == 4) continue;
     else 
     {
       Write_DATA(Addr[4],Num[t_start]);
       //f_closedir(openedDir);
       return 1;                       // hard error
     }
   }
   else continue;
   
  }
}

void main(void)
{
  
 
        FATFS fatfs;
        const char TestName[] = "Music/03.wav";
       // FIL fil; 
       //FILINFO direcEnt;

        //int codes;
       // char ItersongName[20];
	
        static int mins;
        WDTCTL = WDTPW+WDTHOLD;

	init_port();
	init_clk();
	init_TM1638();

 //       Init_DAC();
 //       SDCard_init();
        f_mount(0, &fatfs);
        while ((f_opendir(&musicDirec,musicname)) == 0) {
          mins = playList(&musicDirec);
          if (mins != 0) break;
        }
//        mins = parseWav(TestName);
//        Write_DATA(Addr[7],Num[mins]);
//        mins = start_play();
        Write_DATA(Addr[3],Num[mins]);
        for (;;);
        
        LPM3;
}
