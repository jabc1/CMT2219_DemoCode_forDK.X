#include "dk_hal.h"


#define FREQ_SEL		1		//0-----315MHz
                                //1-----434MHz
                                //2-----868MHz
                                //3-----915MHz
	
const byte RFM219Data[] = {"HopeRF RFM COBRFM219S"};

const word RFM219FreqTbl[4][9] = {
        {0x0052, 0x0118, 0x0273, 0x0309, 0x0404, 0x1128, 0x2956, 0x328E, 0x3BEB},	//315MHz
        {0x0072, 0x0121, 0x029B, 0x037F, 0x0406, 0x1114, 0x2956, 0x3290, 0x3BEB},	//434MHz
        {0x0092, 0x0142, 0x02FD, 0x03A6, 0x040C, 0x110F, 0x29AE, 0x328E, 0x3BCA},	//868MHz
		{0x0092, 0x0146, 0x029B, 0x037F, 0x0406, 0x110F, 0x29AE, 0x3290, 0x3BCA},	//915MHz
	                           };

const word RFM219ConfigTbl[53] = {
		0x0563,    
		0x069A,    
		0x0780,    
		0x08C6,    
		0x0953,    
		0x0A01,    
		0x0B00,    
		0x0C62,    
		0x0D2E,    
		0x0E00,    
		0x0F10,    
		0x1074,    
		0x12F0,    
		0x1300,    
		0x1426,    
		0x1594,    
		0x1600,    
		0x17D4,    
		0x182D,    
		0x19AA,    
		0x1A00,    
		0x1B38,    
		0x1C01,    
		0x1D01,    
		0x1E55,    	//Length
		0x1F21,    
		0x2007,    
		0x2180,    
		0x2205,    
		0x2300,    
		0x2419,    
		0x2500,    
		0x2600,    
		0x2700,    
		0x28AC,    
		0x2A53,    
		0x2BD4,    
		0x2C40,    
		0x2D49,    
		0x2EFF,    
		0x2F1D,    
		0x3012,    
		0x3100,    
		0x33FA,    
		0x3400,    
		0x3500,    
		0x3640,    
		0x37C0,    
		0x3800,    
		0x3900,    
		0x3A20,    
		0x3C07,    
		0x3D00};   



#define	PKT_LEN			21			//

#define	INT_EN		0x3F00
	#define RX_DONE_EN		0x01
	#define CRC_PS_EN		0x02
	#define	NODE_PS_EN		0x04
	#define	SYNC_PS_EN		0x08
	#define PREAM_PS_EN		0x10
	#define	RSSI_VLD_EN		0x20
	#define	RX_TMO_EN		0x40
	#define	SL_TMO_EN		0x80

#define	IO_SEL		0x4000
	#define GPIO1_POR		0x00
	#define GPIO1_INT1		0x01
	#define	GPIO1_INT2		0x02
	#define	GPIO1_Dout		0x03
	
	#define	GPIO2_INT1		0x00
	#define	GPIO2_INT2		0x04
	#define	GPIO2_DCLK		0x08
	#define	GPIO2_0			0x0C	
	
	#define	GPIO3_CLK		0x00
	#define GPIO3_INT1		0x10
	#define	GPIO3_INT2		0x20
	#define	GPIO3_DCLK		0x30
	
	#define	GPIO4_Dout		0x00
	#define	GPIO4_INT1		0x40
	#define	GPIO4_INT2		0x80
	#define	GPIO4_DCLK		0xC0
	

#define	INTCTL_A	0x4100
	#define	RSSI_VLD		0x010		//һ����
		
	#define	PREAM_PS		0x020
	#define	SYNC_PS			0x030
	
	#define	NODE_PS			0x040
	#define	CRC_PS			0x050
	#define	RX_DONE			0x060

	#define	SL_TMO			0x040		//+OFFSET
	#define	RX_TMO			0x050
	#define	FIFO_NMTY		0x060
	#define	FIFO_TH			0x070
	#define	FIFO_FULL		0x080
	#define	FIFO_WBYTE		0x090
	#define FIFO_OVF		0x0A0
	#define	RSSI_INDI		0x0B0
	
	#define	OFFSET			0x030



#define	INTCTL_B	0x4200
#define	RX_DONE_CLR		0x01
#define	CRC_PS_CLR		0x02
#define	NODE_PS_CLR		0x04
#define	SYNC_PS_CLR		0x08
#define	PREAM_PS_CLR	0x10
#define	RSSI_VLD_CLR	0x20
#define RX_TMO_CLR		0x40
#define	SL_TMO_CLR		0x80

#define	INTCTL_C	0x4300
#define	RX_DONE_FLG		0x01
#define	CRC_PS_FLG		0x02
#define	NODE_PS_FLG		0x04
#define	SYNC_PS_FLG		0x08
#define	PREAM_PS_FLG	0x10
#define	RSSI_VLD_FLG	0x20
#define	RX_TMO_FLG		0x40			
#define	SL_TMO_FLG		0x80

#define	INTCTL_D	0x4400
#define	FIFO_WR_METH	0x01
#define	FIFO_WR_EN		0x02
#define	FIFO_CLR		0x04
#define	FIFO_OVF_FLG	0x08
#define	FIFO_TH_FLG		0x10
#define	FIFO_NMTY_FLG	0x20
#define	FIFO_FULL_FLG	0x40
#define	PKT_LEN_ERR_FLG	0x80	//?

#define	RSSI_ADDR	0x4500

#define	FUNC_EN		0x4600
#define	EEPROM_LOCK		0x01
#define	EEPROM_PWRON 	0x02
#define FAST_SPI_EN		0x04
#define	SA_TEST_EN		0x08

#define	OP_MODE		0x4700
#define OP_EEPROM	0x01
#define	OP_STANDBY	0x02	
#define	OP_FS		0x04
#define	OP_RX		0x08
#define	OP_SLEEP	0x10

#define	RD_IDLE		0x00
#define	RD_SLEEP	0x20
#define	RD_STBY		0x40
#define	RD_FS		0x60
#define	RD_RX		0x80
#define	RD_EEPROM	0xA0

#define OP_MASK		0xE0

#define	SOFT_RST 	0x4FFF

#define	EE_DAT_LOW	0x5000
#define EE_DAT_HIGH	0x5100
#define	EE_ADD		0x5200

#define	EE_CTL		0x5300
#define	EE_ERASE	0x01
#define	EE_PROG		0x02
#define	EE_READ		0x04


byte RFM219_RxPacket(void)
{
	byte i;

	if(GPO4In)
	{
		for(i=0;i<PKT_LEN;i++)				//read out buffer
			RxData[i] = FIFORead(); 		
		ClearIRQ();	
		ClearFIFO();
		for(i=0;i<14;i++)
		{
			if(RxData[i]!=RFM219Data[i])//ֻ��ָ���ַ���
			break;	
		}
		if(i>=14)							//compare OK?
		    return(1);
		else
		    return(0); 
		
	}
	return(0);
}

void RFM219_Config(void)
{
 byte i;	
 
 EntryStandby();				//����STB״̬
 for(i=0;i<9;i++) 
 	SPIWrite(RFM219FreqTbl[FREQ_SEL][i]);
 for(i=0;i<53;i++)
	SPIWrite(RFM219ConfigTbl[i]);
 
 ClearIRQ();
 GPIO_FuncCfg();
 EntryRx();
}

//*****************************************************
//Interrupt Mapping
//*****************************************************
void GPIO_FuncCfg(void)
{
 byte mapping;
 byte tmp;
 
 mapping = 0;
 mapping = GPIO4_INT2+GPIO3_INT1+GPIO2_DCLK+GPIO1_Dout;	//	
 SPIWrite(IO_SEL+mapping);

 SPIWrite(INT_EN+0xFF);									//Open All

 SPIWrite(INTCTL_A+RX_DONE+((FIFO_WBYTE+OFFSET)>>4));		//INT2ΪRX_DONE��INT1ΪFIFO_WBYTE
}

//*****************************************************
//Operate Mode
//*****************************************************
void EntryStandby(void)
{
 byte tmp;	
 tmp = SPIRead((byte)(OP_MODE>>8));
 tmp &= OP_MASK;
 SPIWrite(OP_MODE+tmp+OP_STANDBY);
}

void EntrySleep(void)
{
 byte tmp;	
 tmp = SPIRead((byte)(OP_MODE>>8));
 tmp &= OP_MASK;
 SPIWrite(OP_MODE+tmp+OP_SLEEP);
}

void EntryRx(void)
{
 byte tmp;
 tmp = SPIRead((byte)(OP_MODE>>8));
 tmp &= OP_MASK;
 SPIWrite(OP_MODE+tmp+OP_RX);
}

void ReadStatus(void)
{
 SPIRead((byte)(OP_MODE>>8));
}

//*****************************************************
//Auxrl
//*****************************************************
void RFSoftReset(void)
{
 SPIWrite(SOFT_RST); 
}

void ClearIRQ(void)
{
 SPIWrite(INTCTL_B+0xFF);
}

void ClearFIFO(void)
{
 byte tmp;	
 tmp = SPIRead((byte)(INTCTL_D>>8));
 SPIWrite(INTCTL_D+tmp+FIFO_CLR);
}


