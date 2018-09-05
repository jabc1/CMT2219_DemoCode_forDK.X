#include "dk_hal.h"

/******************************************************************************
**�������ƣ�SPIWrite
**�������ܣ�SPIд��һ��16���ݣ���8λ��ַ����8λ���ݣ�
**���������WrPara
**�����������
******************************************************************************/
void SPIWrite(word WrPara)								
{                                                       
	byte bitcnt;    

	FCSB = 1;				//���ָ�
	SDI_OUT();				//SDAΪ���
	SDI  = 1;				//SDA = 1;

	SCK  = 0;				//ע��SCK����0�����ֵ�
	nSEL = 0;

	for(bitcnt=16; bitcnt!=0; bitcnt--)
	{
		SCK = 0;	
		if(WrPara&0x8000)
			SDI = 1;
		else
			SDI = 0;
		SCK = 1;
		WrPara <<= 1;
	}

	SCK = 0;
	SDI = 1;

	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	nSEL = 1;
}        

/******************************************************************************
**�������ƣ�SPIRead
**�������ܣ�SPI��ȡһ����ַ����
**���������adr
**�����������
******************************************************************************/
byte SPIRead(byte adr)
{
	byte tmp;	
	SPICmd8bit(0x80+adr);			//��ַ
	tmp = SPIRead8bit();	
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	nSEL = 1;
	return(tmp);
}  					

/******************************************************************************
**�������ƣ�SPICmd8bit
**�������ܣ�SPIд�����8bit
**���������WrPara
**�����������
**ע�⣺    ����nCS���Low
******************************************************************************/
void SPICmd8bit(byte WrPara)
{
	byte bitcnt;	

	FCSB = 1;
	SDI_OUT();				//SDAΪ���
	SDI  = 1;				//SDA = 1; 

	SCK  = 0;				//ע��SCK����0�����ֵ�
	nSEL = 0;

	for(bitcnt=8; bitcnt!=0; bitcnt--)
	{
		SCK = 0;	
		if(WrPara&0x80)
			SDI = 1;
		else
			SDI = 0;
		SCK = 1;
		WrPara <<= 1; 		
	}
	SCK = 0;
	SDI = 1;
	//nSEL = 1;			//*�˴����ر�nCS��ʹ������ģʽ*
}

/******************************************************************************
**�������ƣ�SPIRead8bitt
**�������ܣ�SPI��ȡ����8bit
**�����������ȡ8bit���ݡ���RdPara
**�����������
**ע�⣺    ����nCS���Low
******************************************************************************/
byte SPIRead8bit(void)
{
	byte RdPara = 0;
	byte bitcnt;

	nSEL = 0;
	SDI_IN();				//��FIFO��ά��SDIΪH		

	for(bitcnt=8; bitcnt!=0; bitcnt--)
	{
		SCK = 0;
		RdPara <<= 1;
		asm("NOP");
		SCK = 1;
		if(SDO)
			RdPara |= 0x01;
		else
			asm("NOP");
	} 
	SCK = 0;
	SDI_OUT();
	SDI = 1;
	//nSEL = 1;		//*�˴����ر�nCS��ʹ������ģʽ*
	return(RdPara);
}


/******************************************************************************
**�������ƣ�FIFORead
**�������ܣ�SPI��ȡFIFO
**���������None
**���������FIFO Byte
**ע�⣺    
******************************************************************************/
byte FIFORead(void)
{
 byte RdPara;
 byte bitcnt;	
 
 nSEL = 1;
 FCSB = 0;
 
 SCK  = 0;
 SDI  = 1; 
 SDI_IN();
  
 for(bitcnt=8; bitcnt!=0; bitcnt--)
 	{
 	SCK = 0;	
 	RdPara <<= 1;
	SCK = 1;
 	if(SDO)
 		RdPara |= 0x01;		//NRZ MSB
 	else
 	 	asm("NOP");
 	}
 SCK = 0;
 asm("NOP");
 asm("NOP");
 asm("NOP");
 asm("NOP");
 asm("NOP");
 asm("NOP");
 asm("NOP");
 FCSB = 1;
 SDI_OUT();
 SDI = 1; 		
 asm("NOP");
 asm("NOP");
 asm("NOP");
 asm("NOP");
 asm("NOP");
 asm("NOP");
 asm("NOP");
 return(RdPara);
}


