/**
  ******************************************************************************
  * @�ļ��� TM1638.H
  * @����   DY
  * @�汾   V1.0
  * @����   03/12/2012
  * @ժҪ   TM1638ͷ�ļ�
  ******************************************************************************
  * @Copyright (c)2012,�Ϻ����е��ӿƼ����޹�˾
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

#define DIO_IN  	(P3DIR &= ~BIT5) //����״̬
#define DIO_OUT  	(P3DIR |= BIT5)  //���״̬
#define DIO_READ 	(P3IN & BIT5) 	 //�����ŵ�ƽ


void TM1638_Write(unsigned char DATA);   //д���ݺ���
unsigned char TM1638_Read(void);         //�����ݺ���
void Write_COM(unsigned char cmd);       //����������
unsigned char Read_key(void);
void Write_DATA(unsigned char add,unsigned char DATA);  //ָ����ַд������
void Write_ALLDATA(unsigned char add,unsigned char *p,unsigned char cnt);
void Write_oneLED(unsigned char num,unsigned char flag); //��������һ��LED���������Ҳ�Ӱ��������led״̬��numΪ��Ҫ���Ƶ�led���,
void Write_allLED(unsigned char flag);     //����ȫ��LED������flag��ʾLED״̬
void init_TM1638(void);
#endif
