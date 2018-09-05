#include <pic.h>
#include <htc.h>
#include <stdio.h>
#include <pic16f1519.h>

/**********************************************************
//
**********************************************************/
#define RTC_INTV		0x8000		//RTC interval time    2s==0x0000
									//				       1s==0x8000
									//                  500ms==0xC000					
									//                  250ms==0xE000

#define	DIDA_8ms		0x06		//OPTION_REG 8ms定时单位
#define	DIDA_2ms		0x04		//OPTION_REG 2ms定时单位

#define	S1_KEY		0x01
#define	S2_KEY		0x02
#define	S3_KEY		0x04
#define	S4_KEY		0x08

#define	DOWN_KEY	0x01
#define	LEFT_KEY	0x02
#define	UP_KEY		0x04
#define	RIGHT_KEY	0x08	

/**********************************************************
宏定义
**********************************************************/
#define BitSet(var, bitno) ((var)|=(1<<(bitno)))	
#define BitClr(var, bitno) ((var)&= (~(1<<(bitno))))

typedef unsigned char byte;
typedef unsigned int  word;

/**********************************************************
结构体
**********************************************************/
typedef union               //struct	
{
 struct
	{
	byte Bit0: 1;
	byte Bit1: 1;
	byte Bit2: 1;
	byte Bit3: 1;
	byte Bit4: 1;
	byte Bit5: 1;
	byte Bit6: 1;
	byte Bit7: 1;
	}BBits;
 byte BByte;
}FlagSTR;	

/**********************************************************
IO口定义
**********************************************************/
//Input
//PortA			    			// TRISA   PORTA   LATA  ANSELA   WPA	
//#define	     		RA0		//	0		 1		1      0       -	//
#define		GPO4In		RA1		//	1(0)	 0	    0	   0       -	//RF -GPO4 DATA	 
#define		GPO3In		RA2		//	1(0)     0		0      0       -	//RF -GPO3 DCLK
//#define		 		RA3		//	0        0      0      0       - 	//
//#define				RA4		//  0 		 1      1	   0 	   -    //
//#define				RA5		//  0 		 0 	    0      0       -	//
//#define				RA6		//	1		 0      0      0       -	//HF -Xout
//#define				RA7		//	1	     0      0      0       -	//HF -Xin 

//PortB							// TRISB   PORTB   LATB  ANSELB   WPB
#define		DownKey		RB0		//  1   	 0 		0      0	   1		
#define		LeftKey		RB1		//  1		 0		0      0       1 
#define		UpKey		RB2 	//	1		 0		0      0       1
#define		RightKey	RB3		//	1		 0		0      0       1
#define		GPO2In		RB4		//	1        0      0      0       0	//RF -GPO2 INT2
//#define				RB5		//	0		 1      1      0       0 	//RF -FCSB
//#define				RB6		//  0        0      0      0       0    //PGM-CLK
//#define				RB7		//	0		 0      0      0       0  	//PGM-DAT 

//PortC							// TRISC   PORTC   LATC  ANSELC   WPC
//#define				RC0		//  1		 0      0      0       -   	//LF -Xout
//#define				RC1		//	1        0      0      0       -  	//LF -Xin
//#define	    		RC2		//  0		 0		0	   0	   -	//HAL-Buzzer
//#define	    		RC3		//	0        0      0      0       -    //SPI-SCK
#define		SDO  		RC4		//	0		 1      1      0	   -  	//SPI-SDI
//#define				RC5		//	1        0      0      0       -	//SPI-SDO
//#define				RC6		//	0        1      1      0       - 	//URT-TxD
//#define				RC7		//	1		 0      0      0       - 	//URT-RxD 

//PortD							// TRISD   PORTD   LATD  ANSELD   WPD
#define		GPO1In		RD0		//	1(0)	 0		0      0  	   - 	//RF -GPO1 INT1
//#define				RD1		//	0        0      0      0 	   -  	//HAL-D4
//#define				RD2		//	0        0      0      0 	   -  	//HAL-D5
//#define				RD3		//	0        0      0      0 	   -  	//HAL-D6
//#define				RD4		//	0        0      0      0 	   -  	//HAL-D7
//#define				RD5		//	0        0      0      0 	   -  	//HAL-D8
//#define				RD6		//	0        0      0      0 	   -  	//HAL-D9
//#define				RD7		//	0        0      0      0 	   -  	//HAL-D10

//PortE							// TRISE   PORTE   LATE  ANSELE   WPE
//#define				RE0		//  0        0      0      0       0	//LCD-CLK
//#define				RE1		//  0        0      0      0       0	//LCD-WR
//#define				RE2		//	0        1      1      0       0	//LCD-CSB
//#define 				RE3		//	1        0      0      0       0	//HAL-Reset

//Output
//PortA			    			// TRISA   PORTA   LATA  ANSELA   WPA	
#define		nSEL		LATA0	//	0		 1		1      0       -	//SPI-nSEL
#define		DIO2Out		LATA1	//	1(0)	 0	    0	   0       -	//RF -Data		
#define		DIO3Out		LATA2	//	1(0)     0		0      0       -	//RF -IO1
#define		DIO4Out		LATA3	//	1(0)     0      0      0       - 	//RF -IO2
//#define				LATA4	//  1 		 0      0	   0 	   -    //595-MR
//#define				LATA5	//  1 		 0 	    0      0       -	//595-SCK	
//#define				LATA6	//	1		 0      0      0       -	//HF -Xout
//#define				LATA7	//	1	     0      0      0       -	//HF -Xin 

//PortB							// TRISB   PORTB   LATB  ANSELB   WPB
//#define				LATB0	//  1   	 0 		0      0	   1		
//#define				LATB1	//  1		 0		0      0       1 
//#define				LATB2 	//	1		 0		0      0       1
//#define				LATB3	//	1		 0		0      0       1
//#define				LATB4	//	1        0      0      0       0	//RF -IRQ1
#define		FCSB		LATB5	//	0		 1      1      0       0 	//RF -FCSB
//#define				LATB6	//  0        0      0      0       0    //PGM-CLK
//#define				LATB7	//	0		 0      0      0       0  	//PGM-DAT 

//PortC							// TRISC   PORTC   LATC  ANSELC   WPC
//#define				LATC0	//  1		 0      0      0       -   	//LF -Xout
//#define				LATC1	//	1        0      0      0       -  	//LF -Xin
#define		Buzzer		LATC2	//  0		 0		0	   0	   -	//HAL-Buzzer
#define		SCK			LATC3	//	0        0      0      0       -    //SPI-SCK
#define		SDI			LATC4	//	0		 1      1      0	   -  	//SPI-SDI
//#define				LATC5	//	1        0      0      0       -	//SPI-SDO
//#define				LATC6	//	0        1      1      0       - 	//URT-TxD
//#define				LATC7	//	1		 0      0      0       - 	//URT-RxD 

//PortD							// TRISD   PORTD   LATD  ANSELD   WPD
#define		POROut		LATD0	//	1(0)	 0		0      0  	   - 	//RF -POR	
#define		TxLed4		LATD1	//	0        0      0      0 	   -  	//HAL-D4
#define		TxLed5		LATD2	//	0        0      0      0 	   -  	//HAL-D5
#define		TxLed6		LATD3	//	0        0      0      0 	   -  	//HAL-D6
#define		TxLed7		LATD4	//	0        0      0      0 	   -  	//HAL-D7
#define		TxLed8		LATD5	//	0        0      0      0 	   -  	//HAL-D8
#define		TxLed9		LATD6	//	0        0      0      0 	   -  	//HAL-D9
#define		RxLed		LATD7	//	0        0      0      0 	   -  	//HAL-D10

//PortE							// TRISE   PORTE   LATE  ANSELE   WPE
//#define				LATE0	//  1        0      0      0       0	//595-SHOLD
//#define				LATE1	//  1        0      0      0       0	//595-nSEL
//#define				LATE2	//	1        1      1      0       0	//595-SDI
//#define 				LATE3	//	1        0      0      0       0	//HAL-Reset


#define		TRISA_DATA		0xC6
#define 	PORTA_DATA		0x01
#define		LATA_DATA		0x01
#define		ANSELA_DATA		0x00	
                        	
#define		TRISB_DATA		0x1F
#define 	PORTB_DATA		0x20
#define		LATB_DATA		0x20
#define		ANSELB_DATA		0x00
#define		WPUB_DATA		0x0F
                        	
#define		TRISC_DATA		0xA3
#define		PORTC_DATA		0x50
#define		LATC_DATA		0x50
#define		ANSELC_DATA 	0x00
                        	
#define		TRISD_DATA		0x01	
#define		PORTD_DATA  	0x00	
#define		LATD_DATA   	0x00
#define		ANSELD_DATA 	0x00
                        	
#define		TRISE_DATA  	0x08
#define		PORTE_DATA  	0x04
#define		LATE_DATA   	0x04
#define		ANSELE_DATA 	0x00
#define		WPUE_DATA		0x00

#define		SDI_IN()		(TRISC |= 0x10)
#define		SDI_OUT()		(TRISC &= 0xEF)

/**********************************************************
变量声明
**********************************************************/
extern byte RxData[32];
extern byte	RxLimtTime;

extern FlagSTR _SysTime;
	#define	SysTime		_SysTime.BByte
	#define	SysTime0	_SysTime.BBits.Bit0	
	#define	SysTime1	_SysTime.BBits.Bit1
	#define	SysTime2	_SysTime.BBits.Bit2
	#define	SysTime3	_SysTime.BBits.Bit3
	#define	SysTime4	_SysTime.BBits.Bit4
	#define	SysTime5	_SysTime.BBits.Bit5
	#define	SysTime6	_SysTime.BBits.Bit6
	#define	SysTime7	_SysTime.BBits.Bit7
	
extern FlagSTR _SecTime;
	#define	SecTime		_SecTime.BByte
	#define	SecTime0	_SecTime.BBits.Bit0
	#define	SecTime1	_SecTime.BBits.Bit1
	#define	SecTime2	_SecTime.BBits.Bit2
	#define	SecTime3	_SecTime.BBits.Bit3
	#define	SecTime4	_SecTime.BBits.Bit4
	#define	SecTime5	_SecTime.BBits.Bit5
	#define	SecTime6	_SecTime.BBits.Bit6
	#define	SecTime7	_SecTime.BBits.Bit7






/**********************************************************
函数声明
**********************************************************/
//main.c
extern void InitSfr(void);
extern void InitPort(void);
extern void TxLedOff(void);

//interrupt.c

//buzzer.c
extern void BeepOn(void);
extern void BeepOff(void);
extern void BeepInd(byte cnt);

//spi.c
extern void SPIWrite(word WrPara);
extern byte SPIRead(byte adr);
extern void SPICmd8bit(byte WrPara);
extern byte SPIRead8bit(void);
extern byte FIFORead(void);

//radio.c
extern byte RFM219_RxPacket(void);
extern void RFM219_Config(void);
extern void GPIO_FuncCfg(void);
extern void EntryStandby(void);
extern void EntrySleep(void);
extern void EntryRx(void);
extern void RFSoftReset(void);
extern void ClearIRQ(void);
extern void ClearFIFO(void);
extern void ReadStatus(void);





