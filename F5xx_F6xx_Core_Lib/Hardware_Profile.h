/*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=
* �ļ���-FileName:			 Hardware_Profile.h
* �����ļ�-Dependencies:  	 msp430f6638.h	
* �ļ�����-File Description:	 ( ͷ�ļ�-Header File )
	�� ������"Ӳ�������ļ�" -ͷ�ļ�-Hardware specific definitions for Processor
	01) ������IO��ʹ�ú궨�壬ͳһ��Hardware_Profile.h ����     
	02)      03)    04)    05)    06)	
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* ע������-Attention : 	
	��01)     ��02)     ��03)    ��04)    ��05)    ��06)     
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
* �޸ļ�¼-Change History:   
	����   ʱ��        �汾  ��������
	Author 	 Date		   Rev      Comment
	-------------------------------------------------------------------------------
	BlueS	2012-12-12	  1.0	   
			xxxx-xx-xx	  x.x	   
			xxxx-xx-xx	  x.x				
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
* ��˾-Company: 			CS-EMLAB  Co. , Ltd.
* ������Э��-Software License Agreement:
	Copyright (C) 2012-2020 	CS-EMLAB  Co. , Ltd.	All rights reserved.	

*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*/


#ifndef __Hardware_Profile_H
#define __Hardware_Profile_H


#include "msp430f6638.h"   // "������"ͷ�ļ�: �ڲ��Ĵ���ض����



////////////////////////////////////////////////////////////////////////////
//==**"��ģ��ר��"�궨��**Module-specific macro**==============//
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//==**��Ƭ���ڲ�����**================================//

#define mClose_WDT      (WDTCTL = WDTPW + WDTHOLD)  // �رտ��Ź�
#define mClr_WDTCNT     (WDTCTL = WDTPW + WDTCNTCL) // �忴�Ź�(����MSP430��Ƭ��)
#define	mNop	        (__no_operation())    //�ղ���ָ��(����"����ʱ"��"����")

//#define	mEnable_GIE     (__bis_SR_register(GIE))  // �������ж�
#define	mEnable_GIE     (_EINT())  // �������ж�GIE
#define	mDisable_GIE    (_DINT())  // �ر����ж�GIE

#define	mReset_Soft    (PMMCTL0 |= PMMSWPOR) //"�����λ" (MSP430��Ƭ��)



#define	Fosc_System	    (12)		//ϵͳ����Ƶ�� unit:MHz (��Ƶ�󣬼����յ�)
////////////////////////////////////////////////////////////////////////////
//==** ϵͳƵ��MCLK =12M  (DCO  FLL��Ƶ��12MHz)   **==============//
	//ms����������ʱ������WaitingDelayMs(n); //���ȴ���ʱn��ms(�����忴�Ź�����)
	//us����������ʱ������mDelay_Cycles(n);	//���ȴ���ʱn��ʱ������
#define mDelay_Cycles(n) (__delay_cycles(n)) // ���ȴ���ʱ"n"��ʱ������.
	//��: __delay_cycles(12000000); //(1/12M)*12000000=1s

#define M_Delay_1us   (12)   //������ʱ"1us" //ϵͳƵ��Ϊ12 Mʱ
#define M_Delay_2us   (24)   //������ʱ"2us" //ϵͳƵ��Ϊ12 Mʱ
#define M_Delay_5us   (60)  //������ʱ"5us" //ϵͳƵ��Ϊ12 Mʱ

#define M_Delay_10us  (120)      //������ʱ"10us"//ϵͳƵ��Ϊ12 Mʱ
#define M_Delay_100us (1200)     //������ʱ"100us"//ϵͳƵ��Ϊ12 Mʱ
#define M_Delay_1ms   (12000)    //������ʱ"1ms"//ϵͳƵ��Ϊ12 Mʱ(ʾ����ʵ��1.02ms)
#define M_Delay_1s    (12000000) //������ʱ"1s"//ϵͳƵ��Ϊ12 Mʱ(ʾ����ʵ��1.02s)


#define CPU_F ((double)12000000)
#define _delay_us(x) __delay_cycles((long)(CPU_F*(double)x/1000000.0))
#define _delay_ms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0))


////////////////////////////////////////////////////////////////////////////
//==** ϵͳƵ��MCLK =20M  (DCO  FLL��Ƶ��20MHz)   **==============//

/********************************************
	//ms����������ʱ������WaitingDelayMs(n); //���ȴ���ʱn��ms(�����忴�Ź�����)
	//us����������ʱ������mDelay_Cycles(n);	//���ȴ���ʱn��ʱ������
#define mDelay_Cycles(n) (__delay_cycles(n)) // ���ȴ���ʱ"n"��ʱ������.
	//��: __delay_cycles(20000000); //Լ980ms �� (1/20M)*20000000=1s(ϵͳƵ��>20M(ͨ����Ƶ))

#define M_Delay_1us   (20)   //������ʱ"1us" //ϵͳƵ��Ϊ20 Mʱ
#define M_Delay_2us   (40)   //������ʱ"2us" //ϵͳƵ��Ϊ20 Mʱ
#define M_Delay_5us   (100)  //������ʱ"5us" //ϵͳƵ��Ϊ20 Mʱ

#define M_Delay_10us  (200)   //������ʱ"10us"
#define M_Delay_100us  (2000)   //������ʱ"100us"

//#define M_Delay_1s    (20000000)  //������ʱ"1s"	      //care ϵͳƵ��(����)ԼΪ20M
//#define M_Delay_500ms (10000000) //������ʱ"500ms"	//care ϵͳƵ��(����)ԼΪ20M
//#define M_Delay_5ms   (100000)  //������ʱ"5ms"	    //care ϵͳƵ��(����)ԼΪ20M
//#define M_Delay_1ms   (20000)  //������ʱ"1ms"	    //care ϵͳƵ��(����)ԼΪ20M
//#define M_Delay_250us (5000)  //������ʱ"250us"	    //care ϵͳƵ��(����)ԼΪ20M
//#define M_Delay_50us (1000)  //������ʱ"50us"	    //care ϵͳƵ��(����)ԼΪ20M

#define CPU_F ((double)20000000)
#define _delay_us(x) __delay_cycles((long)(CPU_F*(double)x/1000000.0))
#define _delay_ms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0))
********************************************/




////////////////////////////////////////////////////////////////////////////
//==**��Ƭ��IO��ʹ�ú궨��,ͳһ��HardwareProfile.h����**===//
//==**������**MSP430F5xx_6xx �ĵ�Ƭ��**====================//
/*****************************

//==**����"����ѡ��Ĵ���"��IOΪ��Χģ�鹦�����Ż�IO����**IO bits Function Pin/IO Pin**====//
#define mSelect_Xxx_FunctionPin  (P1SEL |= BIT) //��������Ϊ"��Χģ�鹦��"����
#define mSelect_Xxx_IoPin (P1SEL &= (~BIT))     //��������Ϊ"IO"����

//==**����"����Ĵ���"��IOΪ��������**IO bits Input/Output**===================//
#define mSetOut_Xxx   (P1DIR |= BIT)         //��������Ϊ"���"
#define mSetIn_Xxx     (P1DIR &= (~BIT))    //��������Ϊ"����"

//==**����"����Ĵ���"������ߵ�ƽ��͵�ƽ**IO bits Set/Clr**===============//
#define mHigh_Xxx   (P1OUT |= BIT)           //�������"�ߵ�ƽ(1)"
#define mLow_Xxx    (P1OUT &= (~BIT))      //�������"�͵�ƽ(0)"

#define mTurn_Xxx    (P1OUT ^= BIT)        //"��ת"�������״̬

#define mOpen_Xxx   (P1OUT |= BIT)         //���������Ӧ"��"����
#define mClose_Xxx   (P1OUT &= (~BIT))    //���������Ӧ"�ر�"����

//==**���� "��������������ʹ�ܼĴ���"��ʹ�ܻ��ֹ�˹���**IO bits PULL Enabled/Disabled**===//
#define mPullEnabled_Xxx(n)   (P1REN |= BIT)        //ʹ��--����/��������
#define mPullDisabled_Xxx(n)  (P1REN &= (~BIT))   //��ֹ--����/��������

//==**���� "����Ĵ���(����)"��ѡ����������������**IO bits PullUp/PullDown**======//
#define mPullUp_Xxx(n)        (P1OUT |= BIT)      //��������"����"����
#define mPullDown_Xxx(n)    (P1OUT &= (BIT) )   //��������"����"����


//==**��ȡ"����Ĵ���"���������ŵĵ�ƽֵ**IO bits Input**================//
#define mRead_Xxx(n)   (P1IN&n?1:0 )      //��ȡ���ŵ�ƽֵ


//#define _MIN(a,b)			( (a) < (b) ? (a) : (b) )
//#define _MAX(a,b)			( (a) > (b) ? (a) : (b) )
*****************************/


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//==**�ڲ�"��ԴIO��ʹ�ú궨��**=======================//


	//--**UART����*IO��ʹ�ú궨��**----------------//
//#define UART1_TX_TRIS   TRISFbits.TRISF3	//uart1��������
//#define UART1_RX_TRIS   TRISFbits.TRISF2	//uart1��������
	

	////////////////////////////////////////////////////////////////////////////
	//==**SPI_B *IO��ʹ�ú궨��**=============================//

	//--**P8.4 ����: SPI_B_CLK (P8.4/UCB1CLK/UCA1STE/S11)** -------------------//
#define SPI_B_CLK_SEL  (P8SEL)
#define SPI_B_CLK_DIR  (P8DIR)  
#define SPI_B_CLK_PORT (P8OUT)
	
#define SPI_B_CLK_IO   (BIT4)	
	
		//��������Ϊ"��Χģ�鹦��"����
#define mSelect_SPI_B_CLK_FunctionPin  (SPI_B_CLK_SEL |= SPI_B_CLK_IO) 
	
		//����"SPI_B_CLK" ����Ϊ"���"
#define mSetOut_SPI_B_CLK (SPI_B_CLK_DIR |= SPI_B_CLK_IO)  
	
		//��������Ϊ"���",�����"�ߵ�ƽ"
#define mHigh_SPI_B_CLK  {SPI_B_CLK_DIR |= SPI_B_CLK_IO; SPI_B_CLK_PORT |= SPI_B_CLK_IO;}      //�������"�ߵ�ƽ(1)"
		//��������Ϊ"���",�����"�͵�ƽ"
#define mLow_SPI_B_CLK   {SPI_B_CLK_DIR |= SPI_B_CLK_IO; SPI_B_CLK_PORT &= ~SPI_B_CLK_IO;}    //�������"�͵�ƽ(0)"
	
	
	//--**P8.5 ����: SPI_B_MOSI (P8.5/UCB1SIMO/UCB1SDA/S10)** ----------------//
#define SPI_B_MOSI_SEL  (P8SEL)
#define SPI_B_MOSI_DIR  (P8DIR)  
#define SPI_B_MOSI_PORT (P8OUT)
	
#define SPI_B_MOSI_IO   (BIT5)
	
		//��������Ϊ"��Χģ�鹦��"����
#define mSelect_SPI_B_MOSI_FunctionPin  (SPI_B_MOSI_SEL |= SPI_B_MOSI_IO) 
	
		 //����"SPI_B_MOSI" ����Ϊ"���"
#define mSetOut_SPI_B_MOSI (SPI_B_MOSI_DIR |= SPI_B_MOSI_IO)  
	
			//��������Ϊ"���",��"����ߵ�ƽ"
#define mHigh_SPI_B_MOSI {SPI_B_MOSI_DIR |= SPI_B_MOSI_IO; SPI_B_MOSI_PORT |= SPI_B_MOSI_IO;}   
			//��������Ϊ"���",��"����͵�ƽ"
#define mLow_SPI_B_MOSI {SPI_B_MOSI_DIR |= SPI_B_MOSI_IO; SPI_B_MOSI_PORT &= ~SPI_B_MOSI_IO;}   
	
	
	
	//--**P8.6����: SPI_B_MISO (P8.6/UCB1SOMI/UCB1SCL/S9)** ----------------//
#define SPI_B_MISO_SEL  (P8SEL)
#define SPI_B_MISO_DIR  (P8DIR)  
#define SPI_B_MISO_PORT (P8OUT)
	
#define SPI_B_MISO_IO   (BIT6)
	
		//��������Ϊ"��Χģ�鹦��"����
#define mSelect_SPI_B_MISO_FunctionPin  (SPI_B_MISO_SEL |= SPI_B_MISO_IO) 
	
		 //����"SPI_B_MISO" ����Ϊ"����"
#define mSetIn_SPI_B_MISO (SPI_B_MISO_DIR &= (~SPI_B_MISO_IO))  
	
		//����"SPI_B_MISO" ����Ϊ"���"
#define mSetOut_SPI_B_MISO (SPI_B_MISO_DIR |= SPI_B_MISO_IO)  
	
	
			//��������Ϊ"���",��"����ߵ�ƽ"
#define mHigh_SPI_B_MISO {SPI_B_MISO_DIR |= SPI_B_MISO_IO; SPI_B_MISO_PORT |= SPI_B_MISO_IO;}   
			//��������Ϊ"���",��"����͵�ƽ"
#define mLow_SPI_B_MISO {SPI_B_MISO_DIR |= SPI_B_MISO_IO; SPI_B_MISO_PORT &= ~SPI_B_MISO_IO;}   
	




	////////////////////////////////////////////////////////////////////////////
	//==**Potentiometer *ADC12_A--IO��ʹ�ú궨��**=================//
//--**P6.6����: P6.6/CB6/A6/DAC0** --------------------------------------//
#define Potentiometer_Ad_SEL  (P6SEL)
#define Potentiometer_Ad_DIR  (P6DIR)  
#define Potentiometer_Ad_IO   (BIT6)

	//��������Ϊ"��Χģ�鹦��"����
#define mSelect_Potentiometer_Ad (Potentiometer_Ad_SEL |= Potentiometer_Ad_IO) 
	 //��������Ϊ"����"
#define mSetIn_Potentiometer_Ad (Potentiometer_Ad_DIR &= (~Potentiometer_Ad_IO))  


	////////////////////////////////////////////////////////////////////////////
	//==**INA21x *ADC12_A--IO��ʹ�ú궨��**=====================//
//--**P6.7����** -------------------------------------------//
#define INA21x_Ad_SEL  (P6SEL)
#define INA21x_Ad_DIR  (P6DIR)  
#define INA21x_Ad_IO   (BIT7)

	//��������Ϊ"��Χģ�鹦��"����
#define mSelect_INA21x_Ad (INA21x_Ad_SEL |= INA21x_Ad_IO) 
	 //��������Ϊ"����"
#define mSetIn_INA21x_Ad (INA21x_Ad_DIR &= (~INA21x_Ad_IO))  


	////////////////////////////////////////////////////////////////////////////
	//==**NTC_Temperature �¶ȴ�����**==========================//
//--**P6.5����** ADC12_A--IO��ʹ�ú궨��**----------//
#define NTC_TMP_Ad_SEL  (P6SEL)
#define NTC_TMP_Ad_DIR  (P6DIR)  
#define NTC_TMP_Ad_IO   (BIT5)

	//��������Ϊ"��Χģ�鹦��"����
#define mSelect_NTC_TMP_Ad (NTC_TMP_Ad_SEL |= NTC_TMP_Ad_IO) 

	 //��������Ϊ"����"
#define mSetIn_NTC_TMP_Ad (NTC_TMP_Ad_DIR &= (~NTC_TMP_Ad_IO))  


//--**P2.5����: P2.5/P2MAP5** ADC12_A--IO��ʹ�ú궨��**----------//
//#define NTC_TMP_Power_DIR  (P2DIR)  
//#define NTC_TMP_Power_PORT (P2OUT)
//#define NTC_TMP_Power_IO   (BIT5)

	  //��������Ϊ"���",����NTC�Ĺ�����Դ(���"�ߵ�ƽ")
//#define mOpen_NTC_TMP_Power {NTC_TMP_Power_DIR |= NTC_TMP_Power_IO; NTC_TMP_Power_PORT |= NTC_TMP_Power_IO;} //�������"�ߵ�ƽ(1)"

	  //��������Ϊ"���",���ر�NTC�Ĺ�����Դ(���"�͵�ƽ")
//#define mClose_NTC_TMP_Power {NTC_TMP_Power_DIR |= NTC_TMP_Power_IO; NTC_TMP_Power_PORT &= ~NTC_TMP_Power_IO;} //�������"�͵�ƽ(0)"


	////////////////////////////////////////////////////////////////////////////
	//==**HR202_Humidity ������ʪ�ȴ�����**====================//
//--**P3.3����** Timer1_CCR2--IO��ʹ�ú궨��**------//
#define HR202_CCR3_SEL  (P3SEL)
#define HR202_CCR3_DIR  (P3DIR)  
#define HR202_CCR3_IO   (BIT3)
	//��������Ϊ"��Χģ�鹦��"����
#define mSelect_HR202_CCR3 (HR202_CCR3_SEL |= HR202_CCR3_IO) 
	 //��������Ϊ"����"
#define mSetIn_HR202_CCR3 (HR202_CCR3_DIR &= (~HR202_CCR3_IO))  


	////////////////////////////////////////////////////////////////////////////
	//==**IIC_B ģ��--"TMP006,TMP100�¶ȴ�����"**===================//

//--**P8.5 ����: IIC_B_SDA (P8.5/UCB1SIMO/UCB1SDA/S10)** ----------------//
#define IIC_B_SDA_SEL  (P8SEL)
#define IIC_B_SDA_REN  (P8REN)  
#define IIC_B_SDA_DIR  (P8DIR)  
#define IIC_B_SDA_IO   (BIT5)
	//��������Ϊ"��Χģ�鹦��"����
#define mSelect_IIC_B_SDA_FunctionPin (IIC_B_SDA_SEL |= IIC_B_SDA_IO) 
#define mPullEnabled_IIC_B_SDA (IIC_B_SDA_REN |= IIC_B_SDA_IO)   //ʹ��--����/��������


//--**P8.6����: IIC_B_SCK (P8.6/UCB1SOMI/UCB1SCL/S9)** ----------------//
#define IIC_B_SCK_SEL  (P8SEL)
#define IIC_B_SCK_REN  (P8REN) 
#define IIC_B_SCK_DIR  (P8DIR)  
#define IIC_B_SCK_PORT (P8OUT)
#define IIC_B_SCK_IO   (BIT6)
	//��������Ϊ"��Χģ�鹦��"����
#define mSelect_IIC_B_SCK_FunctionPin (IIC_B_SCK_SEL |= IIC_B_SCK_IO) 
#define mPullEnabled_IIC_B_SCK (IIC_B_SCK_REN |= IIC_B_SCK_IO)   //ʹ��--����/��������
	 //����"IIC_B_SCK" ����Ϊ"���"
#define mSetOut_IIC_B_SCK (IIC_B_SCK_DIR |= IIC_B_SCK_IO)  


 
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//==**�ⲿ"��ԴIO��ʹ�ú궨��**=======================//


	////////////////////////////////////////////////////////////////////////////
	//==**��Ƭ����������ָʾ��*IO��ʹ�ú궨��**=========//
	//==**ϵͳ��������ʱ��ָʾ��ÿ250ms��һ��)**=========//

//--**P4.5  ����: ��Ƭ����������ָʾ��** ---------------------//
#define WORKING_LED_DIR  (P4DIR)  
#define WORKING_LED_PORT (P4OUT)
#define WORKING_LED_IO   (BIT5)
   
	 //��������Ϊ"���",��"��ת"�������״̬
#define mTurn_Working_Led  {WORKING_LED_DIR |= WORKING_LED_IO; WORKING_LED_PORT ^= WORKING_LED_IO;}              

	//��������Ϊ"���",��"����"����ָʾ��
#define mOpen_Working_Led  {WORKING_LED_DIR |= WORKING_LED_IO; WORKING_LED_PORT |= WORKING_LED_IO;}   

	//��������Ϊ"���",��"Ϩ��"����ָʾ��
#define mClose_Working_Led {WORKING_LED_DIR |= WORKING_LED_IO; WORKING_LED_PORT &= (~WORKING_LED_IO);} 



	////////////////////////////////////////////////////////////////////////////
	//==***LED���������**IO��ʹ�ú궨��**=================//

//--**P4.6  ����: LED_YELLOW** -------------------------------------------//
#define LED_YELLOW_DIR  (P4DIR)  
#define LED_YELLOW_PORT (P4OUT)
#define LED_YELLOW_IO   (BIT6)
	//��������Ϊ"���",��"����"LED_YELLOW
#define mOpen_LED_YELLOW  {LED_YELLOW_DIR |= LED_YELLOW_IO; LED_YELLOW_PORT |= LED_YELLOW_IO;}   
	//��������Ϊ"���",��"Ϩ��"LED_YELLOW
#define mClose_LED_YELLOW {LED_YELLOW_DIR |= LED_YELLOW_IO; LED_YELLOW_PORT &= (~LED_YELLOW_IO);} 
	 //��������Ϊ"���",��"��ת"�������״̬
#define mTurn_LED_YELLOW  {LED_YELLOW_DIR |= LED_YELLOW_IO; LED_YELLOW_PORT ^= LED_YELLOW_IO;}              


//--**P4.5  ����: LED_GREEN** -------------------------------------------//
#define LED_GREEN_DIR   (P4DIR)  
#define LED_GREEN_PORT  (P4OUT)
#define LED_GREEN_IO    (BIT5)
	//��������Ϊ"���",��"����"LED_GREEN
#define mOpen_LED_GREEN  {LED_GREEN_DIR |= LED_GREEN_IO; LED_GREEN_PORT |= LED_GREEN_IO;}   
	//��������Ϊ"���",��"Ϩ��"LED_GREEN
#define mClose_LED_GREEN {LED_GREEN_DIR |= LED_GREEN_IO; LED_GREEN_PORT &= (~LED_GREEN_IO);} 
	 //��������Ϊ"���",��"��ת"�������״̬
#define mTurn_LED_GREEN  {LED_GREEN_DIR |= LED_GREEN_IO; LED_GREEN_PORT ^= LED_GREEN_IO;}              


//--**P4.4  ����: LED_RED** -------------------------------------------//
#define LED_RED_DIR     (P4DIR)    
#define LED_RED_PORT    (P4OUT)
#define LED_RED_IO      (BIT4)
	//��������Ϊ"���",��"����"LED_RED
#define mOpen_LED_RED  {LED_RED_DIR |= LED_RED_IO; LED_RED_PORT |= LED_RED_IO;}   
	//��������Ϊ"���",��"Ϩ��"LED_RED
#define mClose_LED_RED {LED_RED_DIR |= LED_RED_IO; LED_RED_PORT &= (~LED_RED_IO);} 
	 //��������Ϊ"���",��"��ת"�������״̬
#define mTurn_LED_RED  {LED_RED_DIR |= LED_RED_IO; LED_RED_PORT ^= LED_RED_IO;}              




	////////////////////////////////////////////////////////////////////////////
	//==***IO����**IO��ʹ�ú궨��**=========================//

//--**P4.2 ����:  Key_1 (IO ����)** -------------------//
//--**P4.3 ����:  Key_2 (IO ����)**--------------------//

#define Key_DIR    (P4DIR)  
#define Key_IN     (P4IN)
#define Key_1_IO   (BIT2)
#define Key_2_IO   (BIT3)

#define mSetIn_Key_1_IO   (Key_DIR &= (~Key_1_IO)) //��������Ϊ"����"
#define mSetIn_Key_2_IO   (Key_DIR &= (~Key_2_IO)) //��������Ϊ"����"



	////////////////////////////////////////////////////////////////////////////
	//==**������*IO��ʹ�ú궨��**==========================//
//--**P4.1  ����: BUZZER** -------------------------------------------//
#define BUZZER_DIR     (P4DIR)    
#define BUZZER_PORT    (P4OUT)
#define BUZZER_IO      (BIT1)

	//��������Ϊ"���",��"��"������
#define mOpen_BUZZER  {BUZZER_DIR |= BUZZER_IO; BUZZER_PORT |= BUZZER_IO;}   
	//��������Ϊ"���",��"�ر�"������
#define mClose_BUZZER {BUZZER_DIR |= BUZZER_IO; BUZZER_PORT &= (~BUZZER_IO);} 
	//��������Ϊ"���",��"��ת"�������״̬
#define mTurn_BUZZER  {BUZZER_DIR |= BUZZER_IO; BUZZER_PORT ^= BUZZER_IO;}              



	////////////////////////////////////////////////////////////////////////////
	//==**"TM1638 �����������"*IO��ʹ�ú궨��**============//

//--**P3.5 ����: DIO (��������/���) ** ----------------------------//
#define TM1638_DIO_DIR  (P3DIR)  
#define TM1638_DIO_PORT (P3OUT)
#define TM1638_DIO_IN   (P3IN)   
#define TM1638_DIO_IO   (BIT5)

#define mSetOut_TM1638_DIO (TM1638_DIO_DIR |= TM1638_DIO_IO) //��������Ϊ"���"
	//��������Ϊ"���",�����"�ߵ�ƽ"
#define mHigh_TM1638_DIO  {TM1638_DIO_DIR |= TM1638_DIO_IO; TM1638_DIO_PORT |= TM1638_DIO_IO;} //�������"�ߵ�ƽ(1)"
	//��������Ϊ"���",�����"�͵�ƽ"
#define mLow_TM1638_DIO {TM1638_DIO_DIR |= TM1638_DIO_IO; TM1638_DIO_PORT &= (~TM1638_DIO_IO);} //�������"�͵�ƽ(0)"

#define mSetIn_TM1638_DIO (TM1638_DIO_DIR &= ~TM1638_DIO_IO) //��������Ϊ"����"
#define mRead_TM1638_DIO  (TM1638_DIO_IN & TM1638_DIO_IO ? 1 : 0)  //��ȡ����"��ƽ"

//--**P3.2 ����: STB (Ƭѡ)  ** -----------------------------------------//
#define TM1638_STB_DIR  (P3DIR)  
#define TM1638_STB_PORT (P3OUT)
#define TM1638_STB_IO   (BIT2)

	//��������Ϊ"���",�����"�ߵ�ƽ"
#define mHigh_TM1638_STB  {TM1638_STB_DIR |= TM1638_STB_IO; TM1638_STB_PORT |= TM1638_STB_IO;}      //�������"�ߵ�ƽ(1)"
	//��������Ϊ"���",�����"�͵�ƽ"
#define mLow_TM1638_STB   {TM1638_STB_DIR |= TM1638_STB_IO; TM1638_STB_PORT &= ~TM1638_STB_IO;}    //�������"�͵�ƽ(0)"

//--**P3.4 ����: CLK (ʱ������) ** -----------------------------------//
#define TM1638_CLK_DIR  (P3DIR)  
#define TM1638_CLK_PORT (P3OUT)
#define TM1638_CLK_IO   (BIT4)

	//��������Ϊ"���",�����"�ߵ�ƽ"
#define mHigh_TM1638_CLK  {TM1638_CLK_DIR |= TM1638_CLK_IO; TM1638_CLK_PORT |= TM1638_CLK_IO;}      //�������"�ߵ�ƽ(1)"
	//��������Ϊ"���",�����"�͵�ƽ"
#define mLow_TM1638_CLK   {TM1638_CLK_DIR |= TM1638_CLK_IO; TM1638_CLK_PORT &= ~TM1638_CLK_IO;}    //�������"�͵�ƽ(0)"


	////////////////////////////////////////////////////////////////////////////
	//==**"LCD_Segment ��ʽLCD" ������*IO��ʹ�ú궨��**========//

//--**P8.0 ����:  LCD_Segment����(1��Ч)** ---------------------------//
#define LCD_SEG_BackLight_DIR  (P8DIR)  
#define LCD_SEG_BackLight_PORT (P8OUT)
#define LCD_SEG_BackLight_IO   (BIT0)

	//��������Ϊ"���",��"��"LCD_Segment ����
#define mOpen_LCD_SEG_BackLight {LCD_SEG_BackLight_DIR |= LCD_SEG_BackLight_IO; LCD_SEG_BackLight_PORT |= LCD_SEG_BackLight_IO;}   
	//��������Ϊ"���",��"�ر�"LCD_Segment ����
#define mClose_LCD_SEG_BackLight {LCD_SEG_BackLight_DIR |= LCD_SEG_BackLight_IO; LCD_SEG_BackLight_PORT &= (~LCD_SEG_BackLight_IO);} 


//--**P5.5, P5.4, P5.3����:  ����LCD_B��������** ----------------------//
#define LCD_SEG_COM_SEL  (P5SEL)
#define LCD_SEG_COM_DIR  (P5DIR)  
#define LCD_SEG_COM_PORT (P5OUT)
#define LCD_SEG_COM_IO   (BIT3 + BIT4 + BIT5)

	//��������Ϊ"��Χģ�鹦��"����
#define mSelect_LCD_SEG_FunctionPin (LCD_SEG_COM_SEL |= LCD_SEG_COM_IO) //P5.5, P5.4, P5.3 ����LCD_B��������(��������Ϊ"��Χģ�鹦��"���� )
	//��������Ϊ"ͨ������IO"����
#define mSelect_LCD_SEG_IoPin (LCD_SEG_COM_SEL &= ~LCD_SEG_COM_IO) 

#define mSetOut_LCD_SEG_COM (LCD_SEG_COM_DIR |= LCD_SEG_COM_IO)   //�������Ŷ�Ϊ"���"
#define mSetIn_LCD_SEG_COM (LCD_SEG_COM_DIR &= ~LCD_SEG_COM_IO)    //�������Ŷ�Ϊ"����"

	//��������Ϊ"���",�����"�ߵ�ƽ"
#define mHigh_LCD_SEG_COM  {mSetOut_LCD_SEG_COM; LCD_SEG_COM_PORT |= LCD_SEG_COM_IO;}     
	//��������Ϊ"���",�����"�͵�ƽ"
#define mLow_LCD_SEG_COM   {mSetOut_LCD_SEG_COM; LCD_SEG_COM_PORT &= ~LCD_SEG_COM_IO;}   





	////////////////////////////////////////////////////////////////////////////
	//==**LCD_TFT Һ����ʾ��*IO��ʹ�ú궨��**===============//
//--**P5.2 ����: ����LCD_TFT����** ----------------------------------//
	//�������������ռ�ձȣ����Ա�������
#define LCD_TFT_BackLight_DIR  (P5DIR)  
#define LCD_TFT_BackLight_PORT (P5OUT)
#define LCD_TFT_BackLight_IO   (BIT2)

	//����: ����ߵ�ƽ(ռ�ձ�Ϊ100%)(��ʱ��������)
	//��������Ϊ"���",��"��"LCD_TFT����
#define mOpen_LCD_TFT_BackLight {LCD_TFT_BackLight_DIR |= LCD_TFT_BackLight_IO; LCD_TFT_BackLight_PORT |= LCD_TFT_BackLight_IO;}   

	//����: ����͵�ƽ(ռ�ձ�Ϊ  0%)(��ʱ����ر�)
	//��������Ϊ"���",��"�ر�"LCD_TFT����
#define mClose_LCD_TFT_BackLight {LCD_TFT_BackLight_DIR |= LCD_TFT_BackLight_IO; LCD_TFT_BackLight_PORT &= (~LCD_TFT_BackLight_IO);} 


//--**P2.6 ����: LCD_TFTʹ������CS ("��"��Ч)** -------------------//
#define LCD_TFT_CS_DIR  (P2DIR)  
#define LCD_TFT_CS_PORT (P2OUT)
#define LCD_TFT_CS_IO   (BIT6)

	//�������Ŷ�Ϊ"���"
#define mSetOut_LCD_TFT_CS (LCD_TFT_CS_DIR |= LCD_TFT_CS_IO) 
	//���"��"��ƽ
#define mHigh_LCD_TFT_CS (LCD_TFT_CS_PORT |= LCD_TFT_CS_IO) 
	//���"��"��ƽ
#define mLow_LCD_TFT_CS  (LCD_TFT_CS_PORT &= ~LCD_TFT_CS_IO)
		//��������Ϊ"���",��"ʹ��"LCD_TFT ģ��(�͵�ƽ��Ч)
#define mOpen_LCD_TFT_CS  {LCD_TFT_CS_DIR |= LCD_TFT_CS_IO; LCD_TFT_CS_PORT &= (~LCD_TFT_CS_IO);} 
		//��������Ϊ"���",��"����"LCD_TFT ģ��
#define mClose_LCD_TFT_CS {LCD_TFT_CS_DIR |= LCD_TFT_CS_IO; LCD_TFT_CS_PORT |= LCD_TFT_CS_IO;} 
			
	//��������Ϊ"���" ,��"����"CS�����ź�(�����½���)
#define mTrigger_LCD_TFT_CS {LCD_TFT_CS_DIR |= LCD_TFT_CS_IO; LCD_TFT_CS_PORT |= LCD_TFT_CS_IO; LCD_TFT_CS_PORT &= ~LCD_TFT_CS_IO;} 


//--**P2.7 ����: ����LCD_TFT��λ** ----------------------------------//
#define LCD_TFT_Reset_DIR  (P2DIR)  
#define LCD_TFT_Reset_PORT (P2OUT)
#define LCD_TFT_Reset_IO   (BIT7)

	//�������Ŷ�Ϊ"���"
#define mSetOut_LCD_TFT_Reset (LCD_TFT_Reset_DIR |= LCD_TFT_Reset_IO) 
	//���"��"��ƽ"==ʹ��"��λ����(��λ"��"��ƽ��Ч)
#define mOpen_LCD_TFT_Reset  (LCD_TFT_Reset_PORT &= ~LCD_TFT_Reset_IO)  
	//���"��"��ƽ=="�ر�"��λ����
#define mClose_LCD_TFT_Reset (LCD_TFT_Reset_PORT |= LCD_TFT_Reset_IO)


//--**P8.4 ����: LCD_TFT ��ʱ������CLK** -------------------//
#define LCD_TFT_CLK_SEL  (P8SEL)
#define LCD_TFT_CLK_DIR  (P8DIR)  
#define LCD_TFT_CLK_PORT (P8OUT)
#define LCD_TFT_CLK_IO   (BIT4)

	//��������Ϊͨ������"IO"����
#define mSelect_LCD_TFT_CLK_IoPin  (LCD_TFT_CLK_SEL &= ~LCD_TFT_CLK_IO) 
	//�������Ŷ�Ϊ"���"
#define mSetOut_LCD_TFT_CLK (LCD_TFT_CLK_DIR |= LCD_TFT_CLK_IO) 
	//���"��"��ƽ
#define mHigh_LCD_TFT_CLK (LCD_TFT_CLK_PORT |= LCD_TFT_CLK_IO)   
	//���"��"��ƽ	
#define mLow_LCD_TFT_CLK  (LCD_TFT_CLK_PORT &= ~LCD_TFT_CLK_IO)   


//--**P8.5 ����: LCD_TFT ����������SDA(MOSI)** -------------------//
#define LCD_TFT_SDA_SEL  (P8SEL)
#define LCD_TFT_SDA_DIR  (P8DIR)  
#define LCD_TFT_SDA_PORT (P8OUT)
#define LCD_TFT_SDA_IO   (BIT5)

	//��������Ϊͨ������"IO"����
#define mSelect_LCD_TFT_SDA_IoPin  (LCD_TFT_SDA_SEL &= ~LCD_TFT_SDA_IO) 
	//�������Ŷ�Ϊ"���"
#define mSetOut_LCD_TFT_SDA (LCD_TFT_SDA_DIR |= LCD_TFT_SDA_IO) 
	//���"��"��ƽ
#define mHigh_LCD_TFT_SDA (LCD_TFT_SDA_PORT |= LCD_TFT_SDA_IO)
	//���"��"��ƽ
#define mLow_LCD_TFT_SDA  (LCD_TFT_SDA_PORT &= ~LCD_TFT_SDA_IO) 


//--**P8.6 ����: LCD_TFT ������Ĵ��������ݼĴ���ѡ������RS(A0)** -------------//
//0:  ѡ������Ĵ��� //1: ѡ�����ݼĴ���
#define LCD_TFT_RS_SEL  (P8SEL)
#define LCD_TFT_RS_DIR  (P8DIR)  
#define LCD_TFT_RS_PORT (P8OUT)
#define LCD_TFT_RS_IO   (BIT6)

	//��������Ϊͨ������"IO"����
#define mSelect_LCD_TFT_RS_IoPin  (LCD_TFT_RS_SEL &= ~LCD_TFT_RS_IO) 
	//�������Ŷ�Ϊ"���"
#define mSetOut_LCD_TFT_RS (LCD_TFT_RS_DIR |= LCD_TFT_RS_IO) 
	//���"��"��ƽ //1: ѡ�����ݼĴ���
#define mHigh_LCD_TFT_RS (LCD_TFT_RS_PORT |= LCD_TFT_RS_IO) 
	//���"��"��ƽ //0:  ѡ������Ĵ���
#define mLow_LCD_TFT_RS  (LCD_TFT_RS_PORT &= ~LCD_TFT_RS_IO) 



	////////////////////////////////////////////////////////////////////////////
	//==**"Aģ��"��·������TS3A5017 ģ��*IO��ʹ�ú궨��**==========//

	//--**P7.5 ����: ���ӵ���·������:����IN1** -------------------//
#define TS3A5017_A_IN1_DIR  (P7DIR)  
#define TS3A5017_A_IN1_PORT (P7OUT)
#define TS3A5017_A_IN1_IO   (BIT5)
			
#define mSetOut_TS3A5017_A_IN1 (TS3A5017_A_IN1_DIR |= TS3A5017_A_IN1_IO)   //����IN1���Ŷ�Ϊ"���"
#define mHigh_TS3A5017_A_IN1   (TS3A5017_A_IN1_PORT |= TS3A5017_A_IN1_IO)    //�������"�ߵ�ƽ(1)"
#define mLow_TS3A5017_A_IN1    (TS3A5017_A_IN1_PORT &= (~TS3A5017_A_IN1_IO)) //�������"�͵�ƽ(0)"
			
#define mConfig_TS3A5017_A_IN1(IN1) {mSetOut_TS3A5017_A_IN1; IN1 ? mHigh_TS3A5017_A_IN1 : mLow_TS3A5017_A_IN1;} 
			
	//--**P7.4 ����: ���ӵ���·������:����IN2** -------------------//
#define TS3A5017_A_IN2_DIR  (P7DIR)  
#define TS3A5017_A_IN2_PORT (P7OUT)
#define TS3A5017_A_IN2_IO   (BIT4)	
			
#define mSetOut_TS3A5017_A_IN2 (TS3A5017_A_IN2_DIR |= TS3A5017_A_IN2_IO)   //����IN2���Ŷ�Ϊ"���"
#define mHigh_TS3A5017_A_IN2   (TS3A5017_A_IN2_PORT |= TS3A5017_A_IN2_IO)    //�������"�ߵ�ƽ(1)"
#define mLow_TS3A5017_A_IN2    (TS3A5017_A_IN2_PORT &= (~TS3A5017_A_IN2_IO)) //�������"�͵�ƽ(0)"
			
#define mConfig_TS3A5017_A_IN2(IN2) {mSetOut_TS3A5017_A_IN2; IN2 ? mHigh_TS3A5017_A_IN2 : mLow_TS3A5017_A_IN2;} 
		



	////////////////////////////////////////////////////////////////////////////
	//==**"B ģ��"��·������TS3A5017*IO��ʹ�ú궨��**==========//
//--**P1.7 ����: ���ӵ���·������:����IN1** -------------------//
#define TS3A5017_B_IN1_DIR  (P1DIR)  
#define TS3A5017_B_IN1_PORT (P1OUT)
#define TS3A5017_B_IN1_IO   (BIT7)
	
#define mSetOut_TS3A5017_B_IN1 (TS3A5017_B_IN1_DIR |= TS3A5017_B_IN1_IO)   //����IN1���Ŷ�Ϊ"���"
#define mHigh_TS3A5017_B_IN1   (TS3A5017_B_IN1_PORT |= TS3A5017_B_IN1_IO)    //�������"�ߵ�ƽ(1)"
#define mLow_TS3A5017_B_IN1    (TS3A5017_B_IN1_PORT &= (~TS3A5017_B_IN1_IO)) //�������"�͵�ƽ(0)"
	
#define mConfig_TS3A5017_B_IN1(IN1) {mSetOut_TS3A5017_B_IN1; IN1 ? mHigh_TS3A5017_B_IN1 : mLow_TS3A5017_B_IN1;} 
	
//--**P1.6 ����: ���ӵ���·������:����IN2** -------------------//
#define TS3A5017_B_IN2_DIR  (P1DIR)  
#define TS3A5017_B_IN2_PORT (P1OUT)
#define TS3A5017_B_IN2_IO   (BIT6)	
	
#define mSetOut_TS3A5017_B_IN2 (TS3A5017_B_IN2_DIR |= TS3A5017_B_IN2_IO)   //����IN2���Ŷ�Ϊ"���"
#define mHigh_TS3A5017_B_IN2   (TS3A5017_B_IN2_PORT |= TS3A5017_B_IN2_IO)    //�������"�ߵ�ƽ(1)"
#define mLow_TS3A5017_B_IN2    (TS3A5017_B_IN2_PORT &= (~TS3A5017_B_IN2_IO)) //�������"�͵�ƽ(0)"
	
#define mConfig_TS3A5017_B_IN2(IN2) {mSetOut_TS3A5017_B_IN2; IN2 ? mHigh_TS3A5017_B_IN2 : mLow_TS3A5017_B_IN2;} 






	////////////////////////////////////////////////////////////////////////////
	//==**"CD405x_Multiplexer��·ѡ��ģ�⿪��" *IO��ʹ�ú궨��**=//
//--**P2.4 ����: ���ӵ�CD405x: ����INH** ---------------------------//
//#define CD405x_INH_DIR  (P2DIR)  
//#define CD405x_INH_PORT (P2OUT)
//#define CD405x_INH_IO   (BIT4)	

	//��������Ϊ"���",��"ʹ��"CD405x ģ��("��"��ƽ��Ч)
//#define mOpen_CD405x_INH {CD405x_INH_DIR |= CD405x_INH_IO; CD405x_INH_PORT &= ~CD405x_INH_IO;}   
	//��������Ϊ"���",��"����"CD405x ģ��("��"��ƽ��Ч)
//#define mClose_CD405x_INH {CD405x_INH_DIR |= CD405x_INH_IO; CD405x_INH_PORT |= CD405x_INH_IO;}   


//--**P2.5 ����: ���ӵ�CD405x: ����A** -----------------------------//
#define CD405x_A_DIR  (P2DIR)  
#define CD405x_A_PORT (P2OUT)
#define CD405x_A_IO   (BIT5)	

#define mSetOut_CD405x_A (CD405x_A_DIR |= CD405x_A_IO)   //�������Ŷ�Ϊ"���"
#define mHigh_CD405x_A   (CD405x_A_PORT |= CD405x_A_IO)    //�������"�ߵ�ƽ(1)"
#define mLow_CD405x_A    (CD405x_A_PORT &= (~CD405x_A_IO)) //�������"�͵�ƽ(0)"

#define mConfig_CD405x_A(n) {mSetOut_CD405x_A; n ? mHigh_CD405x_A : mLow_CD405x_A;} 



//--**P2.0 ����: ���ӵ�CD405x: ����B** -----------------------------//
#define CD405x_B_DIR  (P2DIR)  
#define CD405x_B_PORT (P2OUT)
#define CD405x_B_IO   (BIT0)

#define mSetOut_CD405x_B (CD405x_B_DIR |= CD405x_B_IO)   //�������Ŷ�Ϊ"���"
#define mHigh_CD405x_B   (CD405x_B_PORT |= CD405x_B_IO)    //�������"�ߵ�ƽ(1)"
#define mLow_CD405x_B    (CD405x_B_PORT &= (~CD405x_B_IO)) //�������"�͵�ƽ(0)"

#define mConfig_CD405x_B(n) {mSetOut_CD405x_B; n ? mHigh_CD405x_B : mLow_CD405x_B;} 


	////////////////////////////////////////////////////////////////////////////
	//==**"DC_Motor ֱ�����"*IO��ʹ�ú궨��**================//
//--**P2.5����: ���ӵ�"DRV8833 ": ����nSleep** --DC_Motor-------------//
#define DC_Motor_nSleep_DIR  (P2DIR)  
#define DC_Motor_nSleep_PORT (P2OUT)
#define DC_Motor_nSleep_IO   (BIT5)

	//��������Ϊ"���",��"ʹ��"����("��"��ƽ��Ч)
#define mOpen_DC_Motor_nSleep {DC_Motor_nSleep_DIR |= DC_Motor_nSleep_IO; DC_Motor_nSleep_PORT |= DC_Motor_nSleep_IO;}   

	//��������Ϊ"���",��"��ֹ"����(�ͣ�����͹���)
#define mClose_DC_Motor_nSleep {DC_Motor_nSleep_DIR |= DC_Motor_nSleep_IO; DC_Motor_nSleep_PORT &= ~DC_Motor_nSleep_IO;}   


//--**P3.6����: ���ӵ�"DRV8833 ": ����AIN1��BIN1** --DC_Motor-----//
#define DC_Motor_AIN1_BIN1_SEL  (P3SEL)
#define DC_Motor_AIN1_BIN1_DIR  (P3DIR)  
#define DC_Motor_AIN1_BIN1_PORT (P3OUT)
#define DC_Motor_AIN1_BIN1_IO   (BIT6)

	//��������Ϊ"���",�����"��"��ƽ
#define mHigh_DC_Motor_AIN1_BIN1 {DC_Motor_AIN1_BIN1_DIR |= DC_Motor_AIN1_BIN1_IO; DC_Motor_AIN1_BIN1_PORT |= DC_Motor_AIN1_BIN1_IO;}   
	//��������Ϊ"���",�����"��"��ƽ
#define mLow_DC_Motor_AIN1_BIN1 {DC_Motor_AIN1_BIN1_DIR |= DC_Motor_AIN1_BIN1_IO; DC_Motor_AIN1_BIN1_PORT &= ~DC_Motor_AIN1_BIN1_IO;}   
	//��������Ϊ"��Χģ�鹦��"����
#define mSelect_DC_Motor_AIN1_BIN1_FunctionPin (DC_Motor_AIN1_BIN1_SEL |= DC_Motor_AIN1_BIN1_IO) //��������Ϊ"��Χģ�鹦��"���� 
	//�������Ŷ�Ϊ"���"
#define mSetOut_DC_Motor_AIN1_BIN1 (DC_Motor_AIN1_BIN1_DIR |= DC_Motor_AIN1_BIN1_IO)   


//--**P3.7 ����: ���ӵ�"DRV8833 ": ����AIN2��BIN2** --DC_Motor-----//
#define DC_Motor_AIN2_BIN2_SEL  (P3SEL)
#define DC_Motor_AIN2_BIN2_DIR  (P3DIR)  
#define DC_Motor_AIN2_BIN2_PORT (P3OUT)
#define DC_Motor_AIN2_BIN2_IO   (BIT7)

	//��������Ϊ"���",�����"��"��ƽ
#define mHigh_DC_Motor_AIN2_BIN2 {DC_Motor_AIN2_BIN2_DIR |= DC_Motor_AIN2_BIN2_IO; DC_Motor_AIN2_BIN2_PORT |= DC_Motor_AIN2_BIN2_IO;}   
	//��������Ϊ"���",�����"��"��ƽ
#define mLow_DC_Motor_AIN2_BIN2 {DC_Motor_AIN2_BIN2_DIR |= DC_Motor_AIN2_BIN2_IO; DC_Motor_AIN2_BIN2_PORT &= ~DC_Motor_AIN2_BIN2_IO;}   
	//��������Ϊ"��Χģ�鹦��"����
#define mSelect_DC_Motor_AIN2_BIN2_FunctionPin (DC_Motor_AIN2_BIN2_SEL |= DC_Motor_AIN2_BIN2_IO)  //��������Ϊ"��Χģ�鹦��"���� 
	//�������Ŷ�Ϊ"���"
#define mSetOut_DC_Motor_AIN2_BIN2 (DC_Motor_AIN2_BIN2_DIR |= DC_Motor_AIN2_BIN2_IO)   


//--**P3.3����** ��Ϊת�ټ�����������TA1_CCR2**--DC_Motor----//
#define DC_Motor_CCR3_SEL  (P3SEL)
#define DC_Motor_CCR3_DIR  (P3DIR)  
#define DC_Motor_CCR3_IO   (BIT3)

#define mSelect_DC_Motor_CCR3 (DC_Motor_CCR3_SEL |= DC_Motor_CCR3_IO) //��������Ϊ"��Χģ�鹦��"����
#define mSetIn_DC_Motor_CCR3 (DC_Motor_CCR3_DIR &= (~DC_Motor_CCR3_IO))  //��������Ϊ"����"





	////////////////////////////////////////////////////////////////////////////
	//==**"Step_Motor �������"*IO��ʹ�ú궨��**===============//
//--**P2.0 ����: ���ӵ�"DRV8833 ": ����nSleep** --Step_Motor-------------//
#define Step_Motor_nSleep_DIR  (P2DIR)  
#define Step_Motor_nSleep_PORT (P2OUT)
#define Step_Motor_nSleep_IO   (BIT0)

	//��������Ϊ"���",��"ʹ��"����("��"��ƽ��Ч)
#define mOpen_Step_Motor_nSleep {Step_Motor_nSleep_DIR |= Step_Motor_nSleep_IO; Step_Motor_nSleep_PORT |= Step_Motor_nSleep_IO;}   

	//��������Ϊ"���",��"��ֹ"����(�ͣ�����͹���)
#define mClose_Step_Motor_nSleep {Step_Motor_nSleep_DIR |= Step_Motor_nSleep_IO; Step_Motor_nSleep_PORT &= ~Step_Motor_nSleep_IO;}   


//--**P2.4����: ���ӵ�"DRV8833 ": ����AIN1** --Step_Motor-----//
#define Step_Motor_AIN1_DIR  (P2DIR)  
#define Step_Motor_AIN1_PORT (P2OUT)
#define Step_Motor_AIN1_IO   (BIT4)

	//��������Ϊ"���",�����"��"��ƽ
#define mHigh_Step_Motor_AIN1 {Step_Motor_AIN1_DIR |= Step_Motor_AIN1_IO; Step_Motor_AIN1_PORT |= Step_Motor_AIN1_IO;}   
	//��������Ϊ"���",�����"��"��ƽ
#define mLow_Step_Motor_AIN1 {Step_Motor_AIN1_DIR |= Step_Motor_AIN1_IO; Step_Motor_AIN1_PORT &= ~Step_Motor_AIN1_IO;}   


//--**P2. 3����: ���ӵ�"DRV8833 ": ����AIN2** --Step_Motor-----------//
#define Step_Motor_AIN2_DIR  (P2DIR)  
#define Step_Motor_AIN2_PORT (P2OUT)
#define Step_Motor_AIN2_IO   (BIT3)

	//��������Ϊ"���",�����"��"��ƽ
#define mHigh_Step_Motor_AIN2 {Step_Motor_AIN2_DIR |= Step_Motor_AIN2_IO; Step_Motor_AIN2_PORT |= Step_Motor_AIN2_IO;}   
	//��������Ϊ"���",�����"��"��ƽ
#define mLow_Step_Motor_AIN2 {Step_Motor_AIN2_DIR |= Step_Motor_AIN2_IO; Step_Motor_AIN2_PORT &= ~Step_Motor_AIN2_IO;}   



//--**P3.6 ��: ���ӵ�"DRV8833 ": ����BIN1** --Step_Motor-----//
#define Step_Motor_BIN1_SEL  (P3SEL)
#define Step_Motor_BIN1_DIR  (P3DIR)  
#define Step_Motor_BIN1_PORT (P3OUT)
#define Step_Motor_BIN1_IO   (BIT6)

		//��������Ϊ"IO"����
#define mSelect_Step_Motor_BIN1_IoPin (Step_Motor_BIN1_SEL &= ~Step_Motor_BIN1_IO)  //��������Ϊ"IO"����

	//��������Ϊ"���",�����"��"��ƽ
#define mHigh_Step_Motor_BIN1 {Step_Motor_BIN1_DIR |= Step_Motor_BIN1_IO; Step_Motor_BIN1_PORT |= Step_Motor_BIN1_IO;}   
	//��������Ϊ"���",�����"��"��ƽ
#define mLow_Step_Motor_BIN1 {Step_Motor_BIN1_DIR |= Step_Motor_BIN1_IO; Step_Motor_BIN1_PORT &= ~Step_Motor_BIN1_IO;}   



//--**P3.7 ����: ���ӵ�"DRV8833 ": ����BIN2** --Step_Motor-----//
#define Step_Motor_BIN2_SEL  (P3SEL)
#define Step_Motor_BIN2_DIR  (P3DIR)  
#define Step_Motor_BIN2_PORT (P3OUT)
#define Step_Motor_BIN2_IO   (BIT7)
	//��������Ϊ"IO"����
#define mSelect_Step_Motor_BIN2_IoPin (Step_Motor_BIN2_SEL &= ~Step_Motor_BIN2_IO)  //��������Ϊ"IO"����

	//��������Ϊ"���",�����"��"��ƽ
#define mHigh_Step_Motor_BIN2 {Step_Motor_BIN2_DIR |= Step_Motor_BIN2_IO; Step_Motor_BIN2_PORT |= Step_Motor_BIN2_IO;}   
	//��������Ϊ"���",�����"��"��ƽ
#define mLow_Step_Motor_BIN2 {Step_Motor_BIN2_DIR |= Step_Motor_BIN2_IO; Step_Motor_BIN2_PORT &= ~Step_Motor_BIN2_IO;}   


//--**P3.3����** ��Ϊת�ټ�����������TA1_CCR2**--Step_Motor----//
#define Step_Motor_CCR3_SEL  (P3SEL)
#define Step_Motor_CCR3_DIR  (P3DIR)  
#define Step_Motor_CCR3_IO   (BIT3)

#define mSelect_Step_Motor_CCR3 (Step_Motor_CCR3_SEL |= Step_Motor_CCR3_IO) //��������Ϊ"��Χģ�鹦��"����
#define mSetIn_Step_Motor_CCR3 (Step_Motor_CCR3_DIR &= (~Step_Motor_CCR3_IO))  //��������Ϊ"����"



	////////////////////////////////////////////////////////////////////////////
	//==**CC1101 ģ��*IO��ʹ�ú궨��**=========================//
//--**PJ.1 ����: CC1101 ģ���ʹ������CS** ----------------------//
#define CC1101_CS_DIR  (PJDIR)  
#define CC1101_CS_PORT (PJOUT)
#define CC1101_CS_IO   (BIT1)
	//��������Ϊ"���",��"ʹ��"CC1101 ģ��(�͵�ƽ��Ч)
#define mOpen_CC1101_CS  {CC1101_CS_DIR |= CC1101_CS_IO; CC1101_CS_PORT &= (~CC1101_CS_IO);} 

	//��������Ϊ"���",��"����"CC1101 ģ��
#define mClose_CC1101_CS {CC1101_CS_DIR |= CC1101_CS_IO; CC1101_CS_PORT |= CC1101_CS_IO;} 


	////////////////////////////////////////////////////////////////////////////
	//==**SD��ģ��*IO��ʹ�ú궨��**=========================//
//--**PJ.0 ����: SD��ģ���ʹ������CS** ----------------------//
#define SDcard_CS_DIR  (PJDIR)  
#define SDcard_CS_PORT (PJOUT)
#define SDcard_CS_IO   (BIT0)
	//��������Ϊ"���",��"ʹ��"SD��ģ��(�͵�ƽ��Ч)
#define mOpen_SDcard_CS  {SDcard_CS_DIR |= SDcard_CS_IO; SDcard_CS_PORT &= (~SDcard_CS_IO);} 

	//��������Ϊ"���",��"����"SD�� ģ��
#define mClose_SDcard_CS {SDcard_CS_DIR |= SDcard_CS_IO; SDcard_CS_PORT |= SDcard_CS_IO;} 
		

	////////////////////////////////////////////////////////////////////////////
	//==**SPI ����ģ�飬ʹ�ܿ���**=========================//
	//SPI��������LCD_TFTʱ��Ҫ���������õ�SPI��ģ��
#define mSPI_Select_LCD_TFT {mOpen_LCD_TFT_CS; mClose_CC1101_CS; mClose_SDcard_CS;}              	
	//SPI��������CC1101ʱ��Ҫ���������õ�SPI��ģ��
#define mSPI_Select_CC1101  {mOpen_CC1101_CS; mClose_LCD_TFT_CS; mClose_SDcard_CS;}    
	//SPI��������SD��ʱ��Ҫ���������õ�SPI��ģ��
#define mSPI_Select_SDcard  {mOpen_SDcard_CS; mClose_LCD_TFT_CS; mClose_CC1101_CS;}    

	//����LCD_segment��IIC(TMP006)ʱ��Ҫ���������õ�SPI_B��ģ��
#define mSPI_All_Disable  {mClose_LCD_TFT_CS; mClose_CC1101_CS; mClose_SDcard_CS;}    






////////////////////////////////////////////////////////////////////////////
//==**��Ŀ"ר��"�궨��**Project-specific macro**================//
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
//==**ȫ�ֱ�������**Global variables**========================//
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
//==**�ֲ���������**Local variables**========================//
////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////
//==**"����"�궨��**Functions macro**=========================//
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
//==**"��ģ��ר��"��������**Exported Module-specific funcitions**====//
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
//==**"�ⲿ" API ��������**Exported  API funcitions**===============//
////////////////////////////////////////////////////////////////////////////




#endif  /* __Hardware_Profile_H */






