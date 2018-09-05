#include "dk_hal.h"

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
/*
			PORTA = PORTA_DATA;//PA0=1
			PORTB = PORTB_DATA;//PB5=1
			PORTC = PORTC_DATA;//PC4=1,PC6=1
			PORTD = PORTD_DATA;//
			PORTE = PORTE_DATA;//PE2=1;
*/

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

/**********************************************************
函数名称：Interrupt ISR
函数功能：初始化Sfr
**********************************************************/
void interrupt ISR(void)
{
 //byte i;	
 if(TMR0IF)						//TMR0中断
 	{
 	TMR0IF = 0;
	SysTime++;
 	RxLimtTime++;
 	}
 
 if(TMR1IF)						//TMR1中断
 	{
 	TMR1IF = 0;
 	TMR1L  = (byte)RTC_INTV;
 	TMR1H  = (byte)(RTC_INTV>>8);	
	SecTime++;
 	}
 
 if(RCIF)
 	{
 	RCIF = 0;
	TXREG = RCREG;
 	}	
}
