/**
  ******************************************************************************
  * @文件名 TM1638.c
  * @作者   DY
  * @版本   V1.0
  * @日期   03/12/2012
  * @摘要   TM1638源文件
  ******************************************************************************
  * @Copyright (c)2012,上海德研电子科技有限公司
  * @All right reserved.
  */
/* Includes ------------------------------------------------------------------*/
#include "TM1638.h"
#include "stdint.h"


/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
const uint8_t tab2[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

void TM1638_Write(unsigned char DATA)   //写数据函数
{
	unsigned char i;
	DIO_OUT;
	for(i=0;i<8;i++)
	{
	  CLK_low;
	  if(DATA & 0x01){
		  DIO_high;
	  }else{
		  DIO_low;
	  }
	  CLK_high;
	  DATA>>=1;
	}
}

unsigned char TM1638_Read(void)     //读数据函数
{
	unsigned char i;
	unsigned char temp=0;
	DIO_IN;
	STB_low;
	for(i=0;i<8;i++)
	{
		  temp>>=1;
		  CLK_low;
		  _delay_us(100);
		  if(DIO_READ)
			  temp |= 0x80;
		  else
			  temp &= 0x7f;
		  CLK_high;
	}
	return temp;
}

void Write_COM(unsigned char cmd)  //发送命令字
{
	CLK_high;
	STB_high;
	STB_low;
	TM1638_Write(cmd);
	STB_high;
}

/*!
*函数功能：读取按键值
*输入参数：无
*输出参数：无
*返回值：  无
*/
unsigned char Read_key(void)
{
	unsigned char c[4];
	unsigned int key_value=0x00;
	unsigned int i;
	STB_high;
	STB_low;
	TM1638_Write(0x42);
	_delay_us(1);
	for(i=0;i<4;i++)
		c[i]=TM1638_Read();
	STB_high;
	if(c[0]&BIT2)
	{
		key_value |= BIT1;
	}
	else if(c[0]&BIT6)
	{
		key_value |= BIT4;
	}
	else if(c[0]&BIT0)
	{
		key_value |= BIT2;
	}
	else if(c[0]&BIT1)
	{
		key_value |= BIT3;
	}
	else if(c[0]&BIT5)
	{
		key_value |= BIT6;
	}
	else if(c[0]&BIT4)
	{
		key_value |= BIT5;
	}
	else if(c[1]&BIT0)
	{
		key_value |= BITB;
	}
	else if(c[1]&BIT4)
	{
		key_value |= BITC;
	}
	else if(c[2]&BIT0)
	{
		key_value |= BITD;
	}
	else if(c[2]&BIT4)
	{
		key_value |= BIT8;
	}
	else if(c[1]&BIT1)
	{
		key_value |= BITA;
	}
	else if(c[1]&BIT5)
	{
		key_value |= BITB;
	}
	else if(c[2]&BIT5)
	{
		key_value |= BIT9;
	}
	else if(c[2]&BIT6)
	{
		key_value |= BIT7;
	}
	//-----------------------
	else if(c[3]&BIT0)
	{
		key_value |= BITF;
	}
	else if(c[3]&BIT1)
	{
		key_value |= BITE;
	}
	else if(c[3]&BIT2)
	{
		key_value |= BIT0;
	}
	//特殊符号‘AC’ ‘+’ ‘-’ ‘=’
	else if(c[1]&BIT2)
	{
		Write_allLED(0);//按下AC，清除所有显示
	}

	for(i=0;i<16;i++)
		if((0x01<<i)==key_value)
			break;
	return	i;
}

void Write_DATA(unsigned char add,unsigned char DATA)  //指定地址写入数据
{
	Write_COM(0x44);
	STB_low;
	TM1638_Write(0xc0|add);
	TM1638_Write(DATA);
	STB_high;
}

void init_TM1638(void)
{
	unsigned char count = 0;
	unsigned char times = 16;
	while(times--){
		 Write_allLED(tab2[count]);
		count++;
		if(count == 16)
			count = 0;
		_delay_ms(100);
	}
	Write_allLED(0xff);
	_delay_ms(100);
	Write_allLED(0);
}

void  Write_allLED(unsigned char DATA){
	unsigned char i;
	Write_COM(0x8F);//显示控制
	Write_COM(0x40); //数据命令
	STB_low;
	TM1638_Write(0xc0);
	for(i=0;i<16;i++)
    TM1638_Write(DATA);
	STB_high;
}
