#include "dk_hal.h"

/******************************************************************************
**函数名称：SPIWrite
**函数功能：SPI写入一个16数据（高8位地址，低8位数据）
**输入参数：WrPara
**输出参数：无
******************************************************************************/
void SPIWrite(word WrPara)								
{                                                       
	byte bitcnt;    

	FCSB = 1;				//保持高
	SDI_OUT();				//SDA为输出
	SDI  = 1;				//SDA = 1;

	SCK  = 0;				//注意SCK先清0，保持低
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
**函数名称：SPIRead
**函数功能：SPI读取一个地址数据
**输入参数：adr
**输出参数：无
******************************************************************************/
byte SPIRead(byte adr)
{
	byte tmp;	
	SPICmd8bit(0x80+adr);			//地址
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
**函数名称：SPICmd8bit
**函数功能：SPI写入参数8bit
**输入参数：WrPara
**输出参数：无
**注意：    保留nCS输出Low
******************************************************************************/
void SPICmd8bit(byte WrPara)
{
	byte bitcnt;	

	FCSB = 1;
	SDI_OUT();				//SDA为输出
	SDI  = 1;				//SDA = 1; 

	SCK  = 0;				//注意SCK先清0，保持低
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
	//nSEL = 1;			//*此处不关闭nCS，使用连续模式*
}

/******************************************************************************
**函数名称：SPIRead8bitt
**函数功能：SPI读取参数8bit
**输入参数：读取8bit数据——RdPara
**输出参数：无
**注意：    保留nCS输出Low
******************************************************************************/
byte SPIRead8bit(void)
{
	byte RdPara = 0;
	byte bitcnt;

	nSEL = 0;
	SDI_IN();				//读FIFO，维持SDI为H		

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
	//nSEL = 1;		//*此处不关闭nCS，使用连续模式*
	return(RdPara);
}


/******************************************************************************
**函数名称：FIFORead
**函数功能：SPI读取FIFO
**输入参数：None
**输出参数：FIFO Byte
**注意：    
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


