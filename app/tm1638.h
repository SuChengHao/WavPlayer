/**
  ******************************************************************************
  * @文件名 TM1638.H
  * @作者   DY
  * @版本   V1.0
  * @日期   03/12/2012
  * @摘要   TM1638头文件
  ******************************************************************************
  * @Copyright (c)2012,上海德研电子科技有限公司
  * @All right reserved.
  */
#ifndef _TM1638_H
#define _TM1638_H

#include "msp430f6638.h"
#include <stdint.h>

#define CPU_F ((double)20000000)
#define _delay_us(x) __delay_cycles((long)(CPU_F*(double)x/1000000.0))
#define _delay_ms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0))

#define DIO_high	(P3OUT |= BIT5)
#define DIO_low		(P3OUT &= ~BIT5)
#define CLK_high	(P3OUT |= BIT4)
#define CLK_low		(P3OUT &= ~BIT4)
#define STB_high	(P3OUT |= BIT2)
#define STB_low		(P3OUT &= ~BIT2)

#define DIO_IN  	(P3DIR &= ~BIT5) //输入状态
#define DIO_OUT  	(P3DIR |= BIT5)  //输出状态
#define DIO_READ 	(P3IN & BIT5) 	 //读引脚电平


void TM1638_Write(unsigned char DATA);   //写数据函数
unsigned char TM1638_Read(void);         //读数据函数
void Write_COM(unsigned char cmd);       //发送命令字
unsigned char Read_key(void);
void Write_DATA(unsigned char add,unsigned char DATA);  //指定地址写入数据
void Write_ALLDATA(unsigned char add,unsigned char *p,unsigned char cnt);
void Write_oneLED(unsigned char num,unsigned char flag); //单独控制一个LED函数，并且不影响其他的led状态，num为需要控制的led序号,
void Write_allLED(unsigned char flag);     //控制全部LED函数，flag表示LED状态
void init_TM1638(void);
#endif
