//*******************************************************************************
//  Software Description: 
//        Using CMT2219 communicate with RF-EVB 
//  Software Function:  
//   	  The same with HopeRF RF-EVB
//        1)If Key press, and send data out;
//        2)Without key press, It is in Rx mode;
//        3)If receive valid data, and it is BeepOn; 
//
//  Hardware: 
//        Base on "HopeRF RF-DK for PIC16"
//  Description: 
//                        PIC16F1519
//                     -----------------
//        RFM219-CSB--|RA0               |
//        RFM219-GPO4-|RA1            RD7|---Rx-LED
//        RFM219-GPO3-|RA2            RD6|
//                   -|RA3             | |-\-Tx-LEDs
//               |----|RA6            RD1|
//            XO-16MHz|               RD0|-GPO1-RFM219
//               |----|RA7            RC5|--
//               KEY1-|RB0            RC4|--SDA-RFM219
//	        	 KEY2-|RB1            RC3|--SCK-RFM219
//	        	 KEY3-|RB2            RC2|-Buzzer
//	        	 KEY4-|RB3            RC1|-----| 
//        RFM219-GPO2-|RB4               |  XO-32KHz
//        RFM219-FCSB-|RB5            RC0|-----|
//                     ------------------
//
//  RF module:           RFM219 (CMT2219)
//  Carry Frequency:     315MHz/434MHz/868MHz/915MHz
//  Frequency Deviation: +/-35KHz
//  Bit Rate:            2.4Kbps
//  Coding:              NRZ
//  Packet Format:       0x5555555555+0xAA2DD4+"HopeRF RFM COBRFM219A" (total: 29 Bytes)
//  
//	File Description:
//         1) main.c--------------- Main program 
//         2) keyscan.c------------ Key Press Scan
//         3) buzzer.c------------- Buzzer On or Off
//         4) spi.c---------------- SPI interface (Software simulate)
//         5) radio.c-------------- CMT2219 config interface
//         6) interrupt.c---------- Interrupt service program
//	       7) dk_hal.c------------- Variable definition
//         8) dk_hal.h------------- Head file 
//
//  Writer: QYRuan
//  HOPE MICROELECTRONICS CO.,LTD. 
//  Dec 2014
//
//******************************************************************************

#include "dk_hal.h"

__CONFIG(FOSC_ECH&FOSC_HS&WDTE_OFF&PWRTE_ON&MCLRE_OFF&CP_ON&BOREN_OFF&CLKOUTEN_OFF&IESO_OFF&FCMEN_OFF);
__CONFIG(WRT_OFF&VCAPEN_OFF&STVREN_ON&BORV_LO&LPBOR_OFF&LVP_OFF);

void main(void)
{
 InitSfr();
 InitPort();

 BeepOn();					//Ŀǰ����8ms״̬��ʱ
 for(SysTime=0;SysTime<32;);	//��ʱ
 BeepOff();
 TxLedOff();
 
 RFM219_Config();

 RxLed = 1;
 while(1)
 	{
 	if(RFM219_RxPacket())	//does receive one packet message
 		{
 		RxLimtTime = 0;
 		BeepOn();
 		}
 	if(RxLimtTime>=15)		//over time stop Buzzer		
 		BeepOff();
 	}
}

/**************************************************************
**Name��	TxLedOff
**Function��Off all Tx LEDs
**Input��	none
**Input��	none
**************************************************************/
void TxLedOff(void)
{
 LATD &= 0x81;		
}


/**********************************************************
�������ƣ�InitSfr
�������ܣ���ʼ��Sfr
**********************************************************/
void InitSfr(void)
{
 //Bank7
 IOCBP   = 0;		//û�ж˿��ж�	
 IOCBN	 = 0;	
 IOCBF   = 0;
 
 //Bank6 None
 
 //Bank5
 CCP1CON = 0;		//CCP��ʱû�ã��Ƚ�ģʽռ��Timer1��PWMģʽռ��Timer2
 CCP2CON = 0;		//
	
 //Bank4
 WPUB    = 0x0F;	//PortB.0~PortB.3 ��������ʹ��
 WPUE    = 0;		
 SSPCON1 = 0;		//��ֹӲ��SPI��I2C
 SSPCON2 = 0;
 SSPCON3 = 0;
 
 //Bank3
 //BAUDCON = 0x08;	//BRG16 Enable
 //SPBRG   = 34;		//115.2Kbps
 //RCSTA  |= (NINE_BITS|0x90);
 //TXSTA   = (SPEED|NINE_BITS|0x20);
 
 //SPBRG   = 0xA0;	
 //SPBRGH  = 0x01;
 //RCSTA   = 0x90;	
 //TXSTA   = 0x26;
 //BAUDCON = 0xC8;	//9600bps

 //Bank2
 BORCON  = 0x00;
 FVRCON  = 0x00;
 APFCON  = 0x02;	//RA0 for nSel

 //Bank1
 OPTION_REG  = DIDA_8ms;//��ʱ��RTCC 
 WDTCON  = 0;
 OSCCON  = 0;		//��Config���ã����ΪLF��XH��INTRC
 ADCON0  = 0;
 ADCON1	 = 0;
 PIE1    = 0;		
 PIE2    = 0;

 //Bank0
 PIR1    = 0;
 PIR2    = 0;
 TMR1L	 = (byte)RTC_INTV;
 TMR1H   = (byte)(RTC_INTV>>8);	
 T1CON   = 0x8D;	//�ⲿ32768��1:1	
 T1GCON  = 0;		//Gate �ر�
 
 T2CON   = 0b00000001;	//Fosc/4/4 = 16M/16 = 1MHz
 PR2     = 0xFF;		//�������
 
 
 GIE	 = 1;		//���жϿ�
 PEIE	 = 1;		//�����жϿ�
 TMR0IE  = 1;		//TMR0�жϿ�
 TMR1IE  = 1;		//TMR1�жϿ�
 RCIE    = 1;		//�����ж�

}

/**********************************************************
�������ƣ�InitPort
�������ܣ���ʼ���˿�
**********************************************************/
void InitPort(void)
{
 ANSELA= ANSELA_DATA;
 ANSELB= ANSELB_DATA;
 ANSELC= ANSELC_DATA;
 ANSELD= ANSELD_DATA;
 ANSELE= ANSELE_DATA;
 
 TRISA = TRISA_DATA;
 TRISB = TRISB_DATA;
 TRISC = TRISC_DATA;
 TRISD = TRISD_DATA;
 TRISE = TRISE_DATA;
 
 PORTA = PORTA_DATA;//PA0=1
 PORTB = PORTB_DATA;//PB1=1
 PORTC = PORTC_DATA;//PC0=1,PC2=1
 PORTD = PORTD_DATA;//
 PORTE = PORTE_DATA;//PE2=1;

 LATA  = LATA_DATA;
 LATB  = LATB_DATA;
 LATC  = LATC_DATA;
 LATD  = LATD_DATA;
 LATE  = LATE_DATA;
}

 












