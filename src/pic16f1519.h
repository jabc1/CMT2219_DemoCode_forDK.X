
#ifndef	_HTC_H_
#warning Header file pic16f1519.h included directly. Use #include <htc.h> instead.
#endif

/* header file for the MICROCHIP PIC microcontroller
 *  16F1519
 */


#ifndef __PIC16F1519_H
#define __PIC16F1519_H

//
// Configuration mask definitions
//


// Config Register: CONFIG1
#define CONFIG1              0x8007
// Oscillator Selection
// ECH, External Clock, High Power Mode (4-20 MHz): device clock supplied to CLKIN pin
#define FOSC_ECH             0xFFFF
// ECM, External Clock, Medium Power Mode (0.5-4 MHz): device clock supplied to CLKIN pin
#define FOSC_ECM             0xFFFE
// ECL, External Clock, Low Power Mode (0-0.5 MHz): device clock supplied to CLKIN pin
#define FOSC_ECL             0xFFFD
// INTOSC oscillator: I/O function on CLKIN pin
#define FOSC_INTOSC          0xFFFC
// EXTRC oscillator: External RC circuit connected to CLKIN pin
#define FOSC_EXTRC           0xFFFB
// HS Oscillator, High-speed crystal/resonator connected between OSC1 and OSC2 pins
#define FOSC_HS              0xFFFA
// XT Oscillator, Crystal/resonator connected between OSC1 and OSC2 pins
#define FOSC_XT              0xFFF9
// LP Oscillator, Low-power crystal connected between OSC1 and OSC2 pins
#define FOSC_LP              0xFFF8
// Watchdog Timer Enable
// WDT enabled
#define WDTE_ON              0xFFFF
// WDT enabled while running and disabled in Sleep
#define WDTE_NSLEEP          0xFFF7
// WDT controlled by the SWDTEN bit in the WDTCON register
#define WDTE_SWDTEN          0xFFEF
// WDT disabled
#define WDTE_OFF             0xFFE7
// Power-up Timer Enable
// PWRT disabled
#define PWRTE_OFF            0xFFFF
// PWRT enabled
#define PWRTE_ON             0xFFDF
// MCLR Pin Function Select
// MCLR/VPP pin function is MCLR
#define MCLRE_ON             0xFFFF
// MCLR/VPP pin function is digital input
#define MCLRE_OFF            0xFFBF
// Flash Program Memory Code Protection
// Program memory code protection is disabled
#define CP_OFF               0xFFFF
// Program memory code protection is enabled
#define CP_ON                0xFF7F
// Brown-out Reset Enable
// Brown-out Reset enabled
#define BOREN_ON             0xFFFF
// Brown-out Reset enabled while running and disabled in Sleep
#define BOREN_NSLEEP         0xFDFF
// Brown-out Reset controlled by the SBOREN bit in the BORCON register
#define BOREN_SBODEN         0xFBFF
// Brown-out Reset disabled
#define BOREN_OFF            0xF9FF
// Clock Out Enable
// CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin
#define CLKOUTEN_OFF         0xFFFF
// CLKOUT function is enabled on the CLKOUT pin
#define CLKOUTEN_ON          0xF7FF
// Internal/External Switchover
// Internal/External Switchover mode is enabled
#define IESO_ON              0xFFFF
// Internal/External Switchover mode is disabled
#define IESO_OFF             0xEFFF
// Fail-Safe Clock Monitor Enable
// Fail-Safe Clock Monitor is enabled
#define FCMEN_ON             0xFFFF
// Fail-Safe Clock Monitor is disabled
#define FCMEN_OFF            0xDFFF


// Config Register: CONFIG2
#define CONFIG2              0x8008
// Flash Memory Self-Write Protection
// Write protection off
#define WRT_OFF              0xFFFF
// 000h to 1FFh write protected, 200h to 3FFFh may be modified by EECON control
#define WRT_BOOT             0xFFFE
// 000h to 1FFFh write protected, 2000h to 3FFFh may be modified by EECON control
#define WRT_HALF             0xFFFD
// 000h to 3FFFh write protected, no addresses may be modified by EECON control
#define WRT_ALL              0xFFFC
// Voltage Regulator Capacitor Enable bit
// VCAP pin function disabled
#define VCAPEN_OFF           0xFFFF
// VCAP pin function enabled
#define VCAPEN_ON            0xFFEF
// Stack Overflow/Underflow Reset Enable
// Stack Overflow or Underflow will cause a Reset
#define STVREN_ON            0xFFFF
// Stack Overflow or Underflow will not cause a Reset
#define STVREN_OFF           0xFDFF
// Brown-out Reset Voltage Selection
// Brown-out Reset Voltage (VBOR) set to 2.4V
#define BORV_LO              0xFFFF
// Brown-out Reset Voltage (VBOR) set to 2.7V
#define BORV_HI              0xFBFF
// Low-Power Brown Out Reset
// Low-Power BOR is disabled
#define LPBOR_OFF            0xFFFF
// Low-Power BOR is enabled
#define LPBOR_ON             0xF7FF
// Low-Voltage Programming Enable
// Low-voltage programming enabled
#define LVP_ON               0xFFFF
// High-voltage on MCLR/VPP must be used for programming
#define LVP_OFF              0xDFFF


//
// Special function register definitions
//


// Register: INDF0
volatile unsigned char           INDF0               @ 0x000;
// bit and bitfield definitions

// Register: INDF1
volatile unsigned char           INDF1               @ 0x001;
// bit and bitfield definitions

// Register: PCL
volatile unsigned char           PCL                 @ 0x002;
// bit and bitfield definitions

// Register: STATUS
volatile unsigned char           STATUS              @ 0x003;
// bit and bitfield definitions
volatile bit CARRY               @ ((unsigned)&STATUS*8)+0;
volatile bit DC                  @ ((unsigned)&STATUS*8)+1;
volatile bit ZERO                @ ((unsigned)&STATUS*8)+2;
volatile bit nPD                 @ ((unsigned)&STATUS*8)+3;
volatile bit nTO                 @ ((unsigned)&STATUS*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C                   : 1;
        unsigned	DC                  : 1;
        unsigned	Z                   : 1;
        unsigned	nPD                 : 1;
        unsigned	nTO                 : 1;
        unsigned	                    : 2;
        unsigned	: 1;
    };
} STATUSbits @ 0x003;
#endif
// bit and bitfield definitions

// Register: FSR0L
volatile unsigned char           FSR0L               @ 0x004;
// bit and bitfield definitions

// Register: FSR0H
volatile unsigned char           FSR0H               @ 0x005;
// bit and bitfield definitions

// Register: FSR0
volatile unsigned int            FSR0                @ 0x004;
// bit and bitfield definitions

// Register: FSR1L
volatile unsigned char           FSR1L               @ 0x006;
// bit and bitfield definitions

// Register: FSR1H
volatile unsigned char           FSR1H               @ 0x007;
// bit and bitfield definitions

// Register: FSR1
volatile unsigned int            FSR1                @ 0x006;

// Register: BSR
volatile unsigned char           BSR                 @ 0x008;
// bit and bitfield definitions
volatile bit BSR0                @ ((unsigned)&BSR*8)+0;
volatile bit BSR1                @ ((unsigned)&BSR*8)+1;
volatile bit BSR2                @ ((unsigned)&BSR*8)+2;
volatile bit BSR3                @ ((unsigned)&BSR*8)+3;
volatile bit BSR4                @ ((unsigned)&BSR*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	BSR                 : 5;
    };
    struct {
        unsigned	BSR0                : 1;
        unsigned	BSR1                : 1;
        unsigned	BSR2                : 1;
        unsigned	BSR3                : 1;
        unsigned	BSR4                : 1;
    };
} BSRbits @ 0x008;
#endif

// Register: WREG
volatile unsigned char           WREG                @ 0x009;
// bit and bitfield definitions

// Register: PCLATH
volatile unsigned char           PCLATH              @ 0x00A;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PCLATH              : 7;
    };
} PCLATHbits @ 0x00A;
#endif

// Register: INTCON
volatile unsigned char           INTCON              @ 0x00B;
// bit and bitfield definitions
volatile bit IOCIF               @ ((unsigned)&INTCON*8)+0;
volatile bit INTF                @ ((unsigned)&INTCON*8)+1;
volatile bit TMR0IF              @ ((unsigned)&INTCON*8)+2;
volatile bit IOCIE               @ ((unsigned)&INTCON*8)+3;
volatile bit INTE                @ ((unsigned)&INTCON*8)+4;
volatile bit TMR0IE              @ ((unsigned)&INTCON*8)+5;
volatile bit PEIE                @ ((unsigned)&INTCON*8)+6;
volatile bit GIE                 @ ((unsigned)&INTCON*8)+7;
volatile bit T0IF                @ ((unsigned)&INTCON*8)+2;
volatile bit T0IE                @ ((unsigned)&INTCON*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	IOCIF               : 1;
        unsigned	INTF                : 1;
        unsigned	TMR0IF              : 1;
        unsigned	IOCIE               : 1;
        unsigned	INTE                : 1;
        unsigned	TMR0IE              : 1;
        unsigned	PEIE                : 1;
        unsigned	GIE                 : 1;
    };
    struct {
        unsigned	                    : 2;
        unsigned	T0IF                : 1;
        unsigned	: 2;
        unsigned	T0IE                : 1;
    };
} INTCONbits @ 0x00B;
#endif

// Register: PORTA
volatile unsigned char           PORTA               @ 0x00C;
// bit and bitfield definitions
volatile bit RA0                 @ ((unsigned)&PORTA*8)+0;
volatile bit RA1                 @ ((unsigned)&PORTA*8)+1;
volatile bit RA2                 @ ((unsigned)&PORTA*8)+2;
volatile bit RA3                 @ ((unsigned)&PORTA*8)+3;
volatile bit RA4                 @ ((unsigned)&PORTA*8)+4;
volatile bit RA5                 @ ((unsigned)&PORTA*8)+5;
volatile bit RA6                 @ ((unsigned)&PORTA*8)+6;
volatile bit RA7                 @ ((unsigned)&PORTA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RA0                 : 1;
        unsigned	RA1                 : 1;
        unsigned	RA2                 : 1;
        unsigned	RA3                 : 1;
        unsigned	RA4                 : 1;
        unsigned	RA5                 : 1;
        unsigned	RA6                 : 1;
        unsigned	RA7                 : 1;
    };
} PORTAbits @ 0x00C;
#endif

// Register: PORTB
volatile unsigned char           PORTB               @ 0x00D;
// bit and bitfield definitions
volatile bit RB0                 @ ((unsigned)&PORTB*8)+0;
volatile bit RB1                 @ ((unsigned)&PORTB*8)+1;
volatile bit RB2                 @ ((unsigned)&PORTB*8)+2;
volatile bit RB3                 @ ((unsigned)&PORTB*8)+3;
volatile bit RB4                 @ ((unsigned)&PORTB*8)+4;
volatile bit RB5                 @ ((unsigned)&PORTB*8)+5;
volatile bit RB6                 @ ((unsigned)&PORTB*8)+6;
volatile bit RB7                 @ ((unsigned)&PORTB*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RB0                 : 1;
        unsigned	RB1                 : 1;
        unsigned	RB2                 : 1;
        unsigned	RB3                 : 1;
        unsigned	RB4                 : 1;
        unsigned	RB5                 : 1;
        unsigned	RB6                 : 1;
        unsigned	RB7                 : 1;
    };
} PORTBbits @ 0x00D;
#endif

// Register: PORTC
volatile unsigned char           PORTC               @ 0x00E;
// bit and bitfield definitions
volatile bit RC0                 @ ((unsigned)&PORTC*8)+0;
volatile bit RC1                 @ ((unsigned)&PORTC*8)+1;
volatile bit RC2                 @ ((unsigned)&PORTC*8)+2;
volatile bit RC3                 @ ((unsigned)&PORTC*8)+3;
volatile bit RC4                 @ ((unsigned)&PORTC*8)+4;
volatile bit RC5                 @ ((unsigned)&PORTC*8)+5;
volatile bit RC6                 @ ((unsigned)&PORTC*8)+6;
volatile bit RC7                 @ ((unsigned)&PORTC*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RC0                 : 1;
        unsigned	RC1                 : 1;
        unsigned	RC2                 : 1;
        unsigned	RC3                 : 1;
        unsigned	RC4                 : 1;
        unsigned	RC5                 : 1;
        unsigned	RC6                 : 1;
        unsigned	RC7                 : 1;
    };
} PORTCbits @ 0x00E;
#endif

// Register: PORTD
volatile unsigned char           PORTD               @ 0x00F;
// bit and bitfield definitions
volatile bit RD0                 @ ((unsigned)&PORTD*8)+0;
volatile bit RD1                 @ ((unsigned)&PORTD*8)+1;
volatile bit RD2                 @ ((unsigned)&PORTD*8)+2;
volatile bit RD3                 @ ((unsigned)&PORTD*8)+3;
volatile bit RD4                 @ ((unsigned)&PORTD*8)+4;
volatile bit RD5                 @ ((unsigned)&PORTD*8)+5;
volatile bit RD6                 @ ((unsigned)&PORTD*8)+6;
volatile bit RD7                 @ ((unsigned)&PORTD*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RD0                 : 1;
        unsigned	RD1                 : 1;
        unsigned	RD2                 : 1;
        unsigned	RD3                 : 1;
        unsigned	RD4                 : 1;
        unsigned	RD5                 : 1;
        unsigned	RD6                 : 1;
        unsigned	RD7                 : 1;
    };
} PORTDbits @ 0x00F;
#endif

// Register: PORTE
volatile unsigned char           PORTE               @ 0x010;
// bit and bitfield definitions
volatile bit RE0                 @ ((unsigned)&PORTE*8)+0;
volatile bit RE1                 @ ((unsigned)&PORTE*8)+1;
volatile bit RE2                 @ ((unsigned)&PORTE*8)+2;
volatile bit RE3                 @ ((unsigned)&PORTE*8)+3;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RE0                 : 1;
        unsigned	RE1                 : 1;
        unsigned	RE2                 : 1;
        unsigned	RE3                 : 1;
    };
} PORTEbits @ 0x010;
#endif

// Register: PIR1
volatile unsigned char           PIR1                @ 0x011;
// bit and bitfield definitions
// TMR1 Overflow Interrupt Flag bit
volatile bit TMR1IF              @ ((unsigned)&PIR1*8)+0;
// TMR2 to PR2 Match Interrupt Flag bit
volatile bit TMR2IF              @ ((unsigned)&PIR1*8)+1;
// CCP1 Interrupt Flag bit
volatile bit CCP1IF              @ ((unsigned)&PIR1*8)+2;
// Master Synchronous Serial Port (MSSP) Interrupt Flag bit
volatile bit SSPIF               @ ((unsigned)&PIR1*8)+3;
// EUSART Transmit Interrupt Flag bit
volatile bit TXIF                @ ((unsigned)&PIR1*8)+4;
// EUSART Receive Interrupt Flag bit
volatile bit RCIF                @ ((unsigned)&PIR1*8)+5;
// A/D Converter Interrupt Flag bit
volatile bit ADIF                @ ((unsigned)&PIR1*8)+6;
// Timer1 Gate Interrupt Flag bit
volatile bit TMR1GIF             @ ((unsigned)&PIR1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TMR1IF              : 1;
        unsigned	TMR2IF              : 1;
        unsigned	CCP1IF              : 1;
        unsigned	SSPIF               : 1;
        unsigned	TXIF                : 1;
        unsigned	RCIF                : 1;
        unsigned	ADIF                : 1;
        unsigned	TMR1GIF             : 1;
    };
} PIR1bits @ 0x011;
#endif

// Register: PIR2
volatile unsigned char           PIR2                @ 0x012;
// bit and bitfield definitions
volatile bit CCP2IF              @ ((unsigned)&PIR2*8)+0;
volatile bit BCLIF               @ ((unsigned)&PIR2*8)+3;
volatile bit OSFIF               @ ((unsigned)&PIR2*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP2IF              : 1;
        unsigned	                    : 1;
        unsigned	: 1;
        unsigned	BCLIF               : 1;
        unsigned	: 1;
        unsigned	: 1;
        unsigned	: 1;
        unsigned	OSFIF               : 1;
    };
} PIR2bits @ 0x012;
#endif

// Register: TMR0
volatile unsigned char           TMR0                @ 0x015;
// bit and bitfield definitions
// bit and bitfield definitions

// Register: TMR1L
volatile unsigned char           TMR1L               @ 0x016;
// bit and bitfield definitions

// Register: TMR1H
volatile unsigned char           TMR1H               @ 0x017;
// bit and bitfield definitions

// Register: TMR1
volatile unsigned int            TMR1                @ 0x016;

// Register: T1CON
volatile unsigned char           T1CON               @ 0x018;
// bit and bitfield definitions
volatile bit TMR1ON              @ ((unsigned)&T1CON*8)+0;
volatile bit nT1SYNC             @ ((unsigned)&T1CON*8)+2;
volatile bit T1OSCEN             @ ((unsigned)&T1CON*8)+3;
volatile bit T1CKPS0             @ ((unsigned)&T1CON*8)+4;
volatile bit T1CKPS1             @ ((unsigned)&T1CON*8)+5;
volatile bit TMR1CS0             @ ((unsigned)&T1CON*8)+6;
volatile bit TMR1CS1             @ ((unsigned)&T1CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TMR1ON              : 1;
        unsigned	                    : 1;
        unsigned	nT1SYNC             : 1;
        unsigned	T1OSCEN             : 1;
        unsigned	T1CKPS              : 2;
        unsigned	TMR1CS              : 2;
    };
    struct {
        unsigned	: 4;
        unsigned	T1CKPS0             : 1;
        unsigned	T1CKPS1             : 1;
        unsigned	TMR1CS0             : 1;
        unsigned	TMR1CS1             : 1;
    };
} T1CONbits @ 0x018;
#endif

// Register: T1GCON
volatile unsigned char           T1GCON              @ 0x019;
// bit and bitfield definitions
volatile bit T1GVAL              @ ((unsigned)&T1GCON*8)+2;
volatile bit T1GGO_nDONE         @ ((unsigned)&T1GCON*8)+3;
volatile bit T1GSPM              @ ((unsigned)&T1GCON*8)+4;
volatile bit T1GTM               @ ((unsigned)&T1GCON*8)+5;
volatile bit T1GPOL              @ ((unsigned)&T1GCON*8)+6;
volatile bit TMR1GE              @ ((unsigned)&T1GCON*8)+7;
volatile bit T1GSS0              @ ((unsigned)&T1GCON*8)+0;
volatile bit T1GSS1              @ ((unsigned)&T1GCON*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	T1GSS               : 2;
        unsigned	T1GVAL              : 1;
        unsigned	T1GGO_nDONE         : 1;
        unsigned	T1GSPM              : 1;
        unsigned	T1GTM               : 1;
        unsigned	T1GPOL              : 1;
        unsigned	TMR1GE              : 1;
    };
    struct {
        unsigned	T1GSS0              : 1;
        unsigned	T1GSS1              : 1;
    };
} T1GCONbits @ 0x019;
#endif

// Register: TMR2
volatile unsigned char           TMR2                @ 0x01A;
// bit and bitfield definitions

// Register: PR2
volatile unsigned char           PR2                 @ 0x01B;
// bit and bitfield definitions

// Register: T2CON
volatile unsigned char           T2CON               @ 0x01C;
// bit and bitfield definitions
volatile bit TMR2ON              @ ((unsigned)&T2CON*8)+2;
volatile bit T2CKPS0             @ ((unsigned)&T2CON*8)+0;
volatile bit T2CKPS1             @ ((unsigned)&T2CON*8)+1;
volatile bit T2OUTPS0            @ ((unsigned)&T2CON*8)+3;
volatile bit T2OUTPS1            @ ((unsigned)&T2CON*8)+4;
volatile bit T2OUTPS2            @ ((unsigned)&T2CON*8)+5;
volatile bit T2OUTPS3            @ ((unsigned)&T2CON*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	T2CKPS              : 2;
        unsigned	TMR2ON              : 1;
        unsigned	T2OUTPS             : 4;
    };
    struct {
        unsigned	T2CKPS0             : 1;
        unsigned	T2CKPS1             : 1;
        unsigned	                    : 1;
        unsigned	T2OUTPS0            : 1;
        unsigned	T2OUTPS1            : 1;
        unsigned	T2OUTPS2            : 1;
        unsigned	T2OUTPS3            : 1;
    };
} T2CONbits @ 0x01C;
#endif

//
// Special function register definitions: Bank 1
//


// Register: TRISA
// PORTA Data Direction Control Register
volatile unsigned char           TRISA               @ 0x08C;
// bit and bitfield definitions
volatile bit TRISA0              @ ((unsigned)&TRISA*8)+0;
volatile bit TRISA1              @ ((unsigned)&TRISA*8)+1;
volatile bit TRISA2              @ ((unsigned)&TRISA*8)+2;
volatile bit TRISA3              @ ((unsigned)&TRISA*8)+3;
volatile bit TRISA4              @ ((unsigned)&TRISA*8)+4;
volatile bit TRISA5              @ ((unsigned)&TRISA*8)+5;
volatile bit TRISA6              @ ((unsigned)&TRISA*8)+6;
volatile bit TRISA7              @ ((unsigned)&TRISA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TRISA0              : 1;
        unsigned	TRISA1              : 1;
        unsigned	TRISA2              : 1;
        unsigned	TRISA3              : 1;
        unsigned	TRISA4              : 1;
        unsigned	TRISA5              : 1;
        unsigned	TRISA6              : 1;
        unsigned	TRISA7              : 1;
    };
} TRISAbits @ 0x08C;
#endif

// Register: TRISB
// PORTB Data Direction Control Register
volatile unsigned char           TRISB               @ 0x08D;
// bit and bitfield definitions
volatile bit TRISB0              @ ((unsigned)&TRISB*8)+0;
volatile bit TRISB1              @ ((unsigned)&TRISB*8)+1;
volatile bit TRISB2              @ ((unsigned)&TRISB*8)+2;
volatile bit TRISB3              @ ((unsigned)&TRISB*8)+3;
volatile bit TRISB4              @ ((unsigned)&TRISB*8)+4;
volatile bit TRISB5              @ ((unsigned)&TRISB*8)+5;
volatile bit TRISB6              @ ((unsigned)&TRISB*8)+6;
volatile bit TRISB7              @ ((unsigned)&TRISB*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TRISB0              : 1;
        unsigned	TRISB1              : 1;
        unsigned	TRISB2              : 1;
        unsigned	TRISB3              : 1;
        unsigned	TRISB4              : 1;
        unsigned	TRISB5              : 1;
        unsigned	TRISB6              : 1;
        unsigned	TRISB7              : 1;
    };
} TRISBbits @ 0x08D;
#endif

// Register: TRISC
// PORTC Data Direction Control Register
volatile unsigned char           TRISC               @ 0x08E;
// bit and bitfield definitions
volatile bit TRISC0              @ ((unsigned)&TRISC*8)+0;
volatile bit TRISC1              @ ((unsigned)&TRISC*8)+1;
volatile bit TRISC2              @ ((unsigned)&TRISC*8)+2;
volatile bit TRISC3              @ ((unsigned)&TRISC*8)+3;
volatile bit TRISC4              @ ((unsigned)&TRISC*8)+4;
volatile bit TRISC5              @ ((unsigned)&TRISC*8)+5;
volatile bit TRISC6              @ ((unsigned)&TRISC*8)+6;
volatile bit TRISC7              @ ((unsigned)&TRISC*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TRISC0              : 1;
        unsigned	TRISC1              : 1;
        unsigned	TRISC2              : 1;
        unsigned	TRISC3              : 1;
        unsigned	TRISC4              : 1;
        unsigned	TRISC5              : 1;
        unsigned	TRISC6              : 1;
        unsigned	TRISC7              : 1;
    };
} TRISCbits @ 0x08E;
#endif

// Register: TRISD
// PORTD Data Direction Control Register
volatile unsigned char           TRISD               @ 0x08F;
// bit and bitfield definitions
volatile bit TRISD0              @ ((unsigned)&TRISD*8)+0;
volatile bit TRISD1              @ ((unsigned)&TRISD*8)+1;
volatile bit TRISD2              @ ((unsigned)&TRISD*8)+2;
volatile bit TRISD3              @ ((unsigned)&TRISD*8)+3;
volatile bit TRISD4              @ ((unsigned)&TRISD*8)+4;
volatile bit TRISD5              @ ((unsigned)&TRISD*8)+5;
volatile bit TRISD6              @ ((unsigned)&TRISD*8)+6;
volatile bit TRISD7              @ ((unsigned)&TRISD*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TRISD0              : 1;
        unsigned	TRISD1              : 1;
        unsigned	TRISD2              : 1;
        unsigned	TRISD3              : 1;
        unsigned	TRISD4              : 1;
        unsigned	TRISD5              : 1;
        unsigned	TRISD6              : 1;
        unsigned	TRISD7              : 1;
    };
} TRISDbits @ 0x08F;
#endif

// Register: TRISE
volatile unsigned char           TRISE               @ 0x090;
// bit and bitfield definitions
volatile bit TRISE0              @ ((unsigned)&TRISE*8)+0;
volatile bit TRISE1              @ ((unsigned)&TRISE*8)+1;
volatile bit TRISE2              @ ((unsigned)&TRISE*8)+2;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TRISE0              : 1;
        unsigned	TRISE1              : 1;
        unsigned	TRISE2              : 1;
        unsigned	                    : 1;
    };
} TRISEbits @ 0x090;
#endif

// Register: PIE1
// Peripheral Interrupt Enable Register 1
volatile unsigned char           PIE1                @ 0x091;
// bit and bitfield definitions
// TMR1 Overflow Interrupt Enable bit
volatile bit TMR1IE              @ ((unsigned)&PIE1*8)+0;
// TMR2 to PR2 Match Interrupt Enable bit
volatile bit TMR2IE              @ ((unsigned)&PIE1*8)+1;
// CCP1 Interrupt Enable bit
volatile bit CCP1IE              @ ((unsigned)&PIE1*8)+2;
// Master Synchronous Serial Port (MSSP) Interrupt Enable bit
volatile bit SSPIE               @ ((unsigned)&PIE1*8)+3;
// EUSART Transmit Interrupt Enable bit
volatile bit TXIE                @ ((unsigned)&PIE1*8)+4;
// EUSART Receive Interrupt Enable bit
volatile bit RCIE                @ ((unsigned)&PIE1*8)+5;
// A/D Converter Interrupt Enable bit
volatile bit ADIE                @ ((unsigned)&PIE1*8)+6;
// Timer1 Gate Interrupt Enable bit
volatile bit TMR1GIE             @ ((unsigned)&PIE1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TMR1IE              : 1;
        unsigned	TMR2IE              : 1;
        unsigned	CCP1IE              : 1;
        unsigned	SSPIE               : 1;
        unsigned	TXIE                : 1;
        unsigned	RCIE                : 1;
        unsigned	ADIE                : 1;
        unsigned	TMR1GIE             : 1;
    };
} PIE1bits @ 0x091;
#endif

// Register: PIE2
// Peripheral Interrupt Enable Register 2
volatile unsigned char           PIE2                @ 0x092;
// bit and bitfield definitions
// CCP2 Interrupt Enable bit
volatile bit CCP2IE              @ ((unsigned)&PIE2*8)+0;
// MSSP Bus Collision Interrupt Interrupt Enable bit
volatile bit BCLIE               @ ((unsigned)&PIE2*8)+3;
// CCP2 Interrupt Enable bit
volatile bit OSFIE               @ ((unsigned)&PIE2*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP2IE              : 1;
        unsigned	                    : 1;
        unsigned	: 1;
        unsigned	BCLIE               : 1;
        unsigned	: 1;
        unsigned	: 1;
        unsigned	: 1;
        unsigned	OSFIE               : 1;
    };
} PIE2bits @ 0x092;
#endif

// Register: OPTION_REG
// Option Register
volatile unsigned char           OPTION_REG          @ 0x095;
// bit and bitfield definitions
// Prescaler Active bit
volatile bit PSA                 @ ((unsigned)&OPTION_REG*8)+3;
// TMR0 Source Edge Select bit
volatile bit TMR0SE              @ ((unsigned)&OPTION_REG*8)+4;
// TMR0 Clock Source Select bit
volatile bit TMR0CS              @ ((unsigned)&OPTION_REG*8)+5;
// Interrupt Edge Select bit
volatile bit INTEDG              @ ((unsigned)&OPTION_REG*8)+6;
// Weak Pull-up Enable bit
volatile bit nWPUEN              @ ((unsigned)&OPTION_REG*8)+7;
volatile bit PS0                 @ ((unsigned)&OPTION_REG*8)+0;
volatile bit PS1                 @ ((unsigned)&OPTION_REG*8)+1;
volatile bit PS2                 @ ((unsigned)&OPTION_REG*8)+2;
volatile bit T0SE                @ ((unsigned)&OPTION_REG*8)+4;
volatile bit T0CS                @ ((unsigned)&OPTION_REG*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PS                  : 3;
        unsigned	PSA                 : 1;
        unsigned	TMR0SE              : 1;
        unsigned	TMR0CS              : 1;
        unsigned	INTEDG              : 1;
        unsigned	nWPUEN              : 1;
    };
    struct {
        unsigned	PS0                 : 1;
        unsigned	PS1                 : 1;
        unsigned	PS2                 : 1;
        unsigned	                    : 1;
        unsigned	T0SE                : 1;
        unsigned	T0CS                : 1;
    };
} OPTION_REGbits @ 0x095;
#endif

// Register: PCON
// Power Control Register
volatile unsigned char           PCON                @ 0x096;
// bit and bitfield definitions
// Brown-out Reset Status bit
volatile bit nBOR                @ ((unsigned)&PCON*8)+0;
// Power-on Reset Status bit
volatile bit nPOR                @ ((unsigned)&PCON*8)+1;
// RESET Instruction Flag bit
volatile bit nRI                 @ ((unsigned)&PCON*8)+2;
// MCLR Reset Flag bit
volatile bit nRMCLR              @ ((unsigned)&PCON*8)+3;
volatile bit nRWDT               @ ((unsigned)&PCON*8)+4;
// Stack Underflow Flag bit
volatile bit STKUNF              @ ((unsigned)&PCON*8)+6;
// Stack Overflow Flag bit
volatile bit STKOVF              @ ((unsigned)&PCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	nBOR                : 1;
        unsigned	nPOR                : 1;
        unsigned	nRI                 : 1;
        unsigned	nRMCLR              : 1;
        unsigned	nRWDT               : 1;
        unsigned	                    : 1;
        unsigned	STKUNF              : 1;
        unsigned	STKOVF              : 1;
    };
} PCONbits @ 0x096;
#endif

// Register: WDTCON
// Watchdog Timer Control Register
volatile unsigned char           WDTCON              @ 0x097;
// bit and bitfield definitions
// Software Enable/Disable for Watch Dog Timer bit
volatile bit SWDTEN              @ ((unsigned)&WDTCON*8)+0;
volatile bit WDTPS0              @ ((unsigned)&WDTCON*8)+1;
volatile bit WDTPS1              @ ((unsigned)&WDTCON*8)+2;
volatile bit WDTPS2              @ ((unsigned)&WDTCON*8)+3;
volatile bit WDTPS3              @ ((unsigned)&WDTCON*8)+4;
volatile bit WDTPS4              @ ((unsigned)&WDTCON*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SWDTEN              : 1;
        unsigned	WDTPS               : 5;
    };
    struct {
        unsigned	                    : 1;
        unsigned	WDTPS0              : 1;
        unsigned	WDTPS1              : 1;
        unsigned	WDTPS2              : 1;
        unsigned	WDTPS3              : 1;
        unsigned	WDTPS4              : 1;
    };
} WDTCONbits @ 0x097;
#endif

// Register: OSCCON
// Oscillator Control Register
volatile unsigned char           OSCCON              @ 0x099;
// bit and bitfield definitions
volatile bit SCS0                @ ((unsigned)&OSCCON*8)+0;
volatile bit SCS1                @ ((unsigned)&OSCCON*8)+1;
volatile bit IRCF0               @ ((unsigned)&OSCCON*8)+3;
volatile bit IRCF1               @ ((unsigned)&OSCCON*8)+4;
volatile bit IRCF2               @ ((unsigned)&OSCCON*8)+5;
volatile bit IRCF3               @ ((unsigned)&OSCCON*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SCS                 : 2;
        unsigned	                    : 1;
        unsigned	IRCF                : 4;
        unsigned	: 1;
    };
    struct {
        unsigned	SCS0                : 1;
        unsigned	SCS1                : 1;
        unsigned	: 1;
        unsigned	IRCF0               : 1;
        unsigned	IRCF1               : 1;
        unsigned	IRCF2               : 1;
        unsigned	IRCF3               : 1;
    };
} OSCCONbits @ 0x099;
#endif

// Register: OSCSTAT
// Oscillator Status Register
volatile unsigned char           OSCSTAT             @ 0x09A;
// bit and bitfield definitions
// Low Freqency Internal Oscillator Ready bit
volatile bit HFIOFS              @ ((unsigned)&OSCSTAT*8)+0;
// Low Freqency Internal Oscillator Ready bit
volatile bit LFIOFR              @ ((unsigned)&OSCSTAT*8)+1;
volatile bit HFIOFR              @ ((unsigned)&OSCSTAT*8)+4;
// Oscillator Start-up Time-out Status bit
volatile bit OSTS                @ ((unsigned)&OSCSTAT*8)+5;
// Timer1 Oscillator Ready bit
volatile bit SOSCR               @ ((unsigned)&OSCSTAT*8)+7;
volatile bit T1OSCR              @ ((unsigned)&OSCSTAT*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	HFIOFS              : 1;
        unsigned	LFIOFR              : 1;
        unsigned	                    : 1;
        unsigned	: 1;
        unsigned	HFIOFR              : 1;
        unsigned	OSTS                : 1;
        unsigned	: 1;
        unsigned	SOSCR               : 1;
    };
    struct {
        unsigned	: 7;
        unsigned	T1OSCR              : 1;
    };
} OSCSTATbits @ 0x09A;
#endif
// bit and bitfield definitions

// Register: ADRESL
// A/D Result Register LSB
volatile unsigned char           ADRESL              @ 0x09B;
// bit and bitfield definitions

// Register: ADRESH
// A/D Result Register MSB
volatile unsigned char           ADRESH              @ 0x09C;
// bit and bitfield definitions

// Register: ADRES
volatile unsigned int            ADRES               @ 0x09B;

// Register: ADCON0
// Analog-to-Digital Control Register 0
volatile unsigned char           ADCON0              @ 0x09D;
// bit and bitfield definitions
// A/D Module Enable bit
volatile bit ADON                @ ((unsigned)&ADCON0*8)+0;
// A/D Conversion Status bit
volatile bit GO_nDONE            @ ((unsigned)&ADCON0*8)+1;
// A/D Conversion Status bit
volatile bit ADGO                @ ((unsigned)&ADCON0*8)+1;
volatile bit CHS0                @ ((unsigned)&ADCON0*8)+2;
volatile bit CHS1                @ ((unsigned)&ADCON0*8)+3;
volatile bit CHS2                @ ((unsigned)&ADCON0*8)+4;
volatile bit CHS3                @ ((unsigned)&ADCON0*8)+5;
volatile bit CHS4                @ ((unsigned)&ADCON0*8)+6;
// A/D Conversion Status bit
volatile bit GO                  @ ((unsigned)&ADCON0*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ADON                : 1;
        unsigned	GO_nDONE            : 1;
        unsigned	CHS                 : 5;
        unsigned	                    : 1;
    };
    struct {
        unsigned	: 1;
        unsigned	ADGO                : 1;
        unsigned	CHS0                : 1;
        unsigned	CHS1                : 1;
        unsigned	CHS2                : 1;
        unsigned	CHS3                : 1;
        unsigned	CHS4                : 1;
    };
    struct {
        unsigned	: 1;
        unsigned	GO                  : 1;
    };
} ADCON0bits @ 0x09D;
#endif

// Register: ADCON1
// Analog-to-Digital Control Register 1
volatile unsigned char           ADCON1              @ 0x09E;
// bit and bitfield definitions
// A/D Result Format Select bit
volatile bit ADFM                @ ((unsigned)&ADCON1*8)+7;
volatile bit ADPREF0             @ ((unsigned)&ADCON1*8)+0;
volatile bit ADPREF1             @ ((unsigned)&ADCON1*8)+1;
volatile bit ADCS0               @ ((unsigned)&ADCON1*8)+4;
volatile bit ADCS1               @ ((unsigned)&ADCON1*8)+5;
volatile bit ADCS2               @ ((unsigned)&ADCON1*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ADPREF              : 2;
        unsigned	                    : 1;
        unsigned	: 1;
        unsigned	ADCS                : 3;
        unsigned	ADFM                : 1;
    };
    struct {
        unsigned	ADPREF0             : 1;
        unsigned	ADPREF1             : 1;
        unsigned	: 2;
        unsigned	ADCS0               : 1;
        unsigned	ADCS1               : 1;
        unsigned	ADCS2               : 1;
    };
} ADCON1bits @ 0x09E;
#endif

//
// Special function register definitions: Bank 2
//


// Register: LATA
volatile unsigned char           LATA                @ 0x10C;
// bit and bitfield definitions
volatile bit LATA0               @ ((unsigned)&LATA*8)+0;
volatile bit LATA1               @ ((unsigned)&LATA*8)+1;
volatile bit LATA2               @ ((unsigned)&LATA*8)+2;
volatile bit LATA3               @ ((unsigned)&LATA*8)+3;
volatile bit LATA4               @ ((unsigned)&LATA*8)+4;
volatile bit LATA5               @ ((unsigned)&LATA*8)+5;
volatile bit LATA6               @ ((unsigned)&LATA*8)+6;
volatile bit LATA7               @ ((unsigned)&LATA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	LATA0               : 1;
        unsigned	LATA1               : 1;
        unsigned	LATA2               : 1;
        unsigned	LATA3               : 1;
        unsigned	LATA4               : 1;
        unsigned	LATA5               : 1;
        unsigned	LATA6               : 1;
        unsigned	LATA7               : 1;
    };
} LATAbits @ 0x10C;
#endif

// Register: LATB
volatile unsigned char           LATB                @ 0x10D;
// bit and bitfield definitions
volatile bit LATB0               @ ((unsigned)&LATB*8)+0;
volatile bit LATB1               @ ((unsigned)&LATB*8)+1;
volatile bit LATB2               @ ((unsigned)&LATB*8)+2;
volatile bit LATB3               @ ((unsigned)&LATB*8)+3;
volatile bit LATB4               @ ((unsigned)&LATB*8)+4;
volatile bit LATB5               @ ((unsigned)&LATB*8)+5;
volatile bit LATB6               @ ((unsigned)&LATB*8)+6;
volatile bit LATB7               @ ((unsigned)&LATB*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	LATB0               : 1;
        unsigned	LATB1               : 1;
        unsigned	LATB2               : 1;
        unsigned	LATB3               : 1;
        unsigned	LATB4               : 1;
        unsigned	LATB5               : 1;
        unsigned	LATB6               : 1;
        unsigned	LATB7               : 1;
    };
} LATBbits @ 0x10D;
#endif

// Register: LATC
volatile unsigned char           LATC                @ 0x10E;
// bit and bitfield definitions
volatile bit LATC0               @ ((unsigned)&LATC*8)+0;
volatile bit LATC1               @ ((unsigned)&LATC*8)+1;
volatile bit LATC2               @ ((unsigned)&LATC*8)+2;
volatile bit LATC3               @ ((unsigned)&LATC*8)+3;
volatile bit LATC4               @ ((unsigned)&LATC*8)+4;
volatile bit LATC5               @ ((unsigned)&LATC*8)+5;
volatile bit LATC6               @ ((unsigned)&LATC*8)+6;
volatile bit LATC7               @ ((unsigned)&LATC*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	LATC0               : 1;
        unsigned	LATC1               : 1;
        unsigned	LATC2               : 1;
        unsigned	LATC3               : 1;
        unsigned	LATC4               : 1;
        unsigned	LATC5               : 1;
        unsigned	LATC6               : 1;
        unsigned	LATC7               : 1;
    };
} LATCbits @ 0x10E;
#endif

// Register: LATD
volatile unsigned char           LATD                @ 0x10F;
// bit and bitfield definitions
volatile bit LATD0               @ ((unsigned)&LATD*8)+0;
volatile bit LATD1               @ ((unsigned)&LATD*8)+1;
volatile bit LATD2               @ ((unsigned)&LATD*8)+2;
volatile bit LATD3               @ ((unsigned)&LATD*8)+3;
volatile bit LATD4               @ ((unsigned)&LATD*8)+4;
volatile bit LATD5               @ ((unsigned)&LATD*8)+5;
volatile bit LATD6               @ ((unsigned)&LATD*8)+6;
volatile bit LATD7               @ ((unsigned)&LATD*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	LATD0               : 1;
        unsigned	LATD1               : 1;
        unsigned	LATD2               : 1;
        unsigned	LATD3               : 1;
        unsigned	LATD4               : 1;
        unsigned	LATD5               : 1;
        unsigned	LATD6               : 1;
        unsigned	LATD7               : 1;
    };
} LATDbits @ 0x10F;
#endif

// Register: LATE
volatile unsigned char           LATE                @ 0x110;
// bit and bitfield definitions
volatile bit LATE0               @ ((unsigned)&LATE*8)+0;
volatile bit LATE1               @ ((unsigned)&LATE*8)+1;
volatile bit LATE2               @ ((unsigned)&LATE*8)+2;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	LATE0               : 1;
        unsigned	LATE1               : 1;
        unsigned	LATE2               : 1;
        unsigned	                    : 1;
    };
    struct {
        unsigned	LATE                : 3;
        unsigned	: 5;
    };
} LATEbits @ 0x110;
#endif

// Register: BORCON
// Brown-out Reset Control Register
volatile unsigned char           BORCON              @ 0x116;
// bit and bitfield definitions
// Brown-out Reset Circuit Ready Status bit
volatile bit BORRDY              @ ((unsigned)&BORCON*8)+0;
volatile bit BORFS               @ ((unsigned)&BORCON*8)+6;
// Software Brown Out Reset Enable bit
volatile bit SBOREN              @ ((unsigned)&BORCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	BORRDY              : 1;
        unsigned	                    : 5;
        unsigned	BORFS               : 1;
        unsigned	SBOREN              : 1;
    };
} BORCONbits @ 0x116;
#endif

// Register: FVRCON
// Voltage Reference Control Register 0
volatile unsigned char           FVRCON              @ 0x117;
// bit and bitfield definitions
// Temperature Sensor Range Select
volatile bit TSRNG               @ ((unsigned)&FVRCON*8)+4;
// Temperature Sensor Enable
volatile bit TSEN                @ ((unsigned)&FVRCON*8)+5;
// Fixed Voltage Reference Ready Flag
volatile bit FVRRDY              @ ((unsigned)&FVRCON*8)+6;
// Fixed Voltage Reference Enable
volatile bit FVREN               @ ((unsigned)&FVRCON*8)+7;
// A/D Converter Fixed Voltage Reference Selection
volatile bit ADFVR0              @ ((unsigned)&FVRCON*8)+0;
// A/D Converter Fixed Voltage Reference Selection
volatile bit ADFVR1              @ ((unsigned)&FVRCON*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ADFVR               : 2;
        unsigned	                    : 2;
        unsigned	TSRNG               : 1;
        unsigned	TSEN                : 1;
        unsigned	FVRRDY              : 1;
        unsigned	FVREN               : 1;
    };
    struct {
        unsigned	ADFVR0              : 1;
        unsigned	ADFVR1              : 1;
    };
} FVRCONbits @ 0x117;
#endif

// Register: APFCON
// Alternate Pin Function Control Register
volatile unsigned char           APFCON              @ 0x11D;
// bit and bitfield definitions
// CCP2 Input/Output Pin Selection
volatile bit CCP2SEL             @ ((unsigned)&APFCON*8)+0;
// SS Input Pin Selection
volatile bit SSSEL               @ ((unsigned)&APFCON*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP2SEL             : 1;
        unsigned	SSSEL               : 1;
        unsigned	                    : 1;
        unsigned	: 1;
        unsigned	: 1;
        unsigned	: 1;
        unsigned	: 1;
    };
} APFCONbits @ 0x11D;
#endif

//
// Special function register definitions: Bank 3
//


// Register: ANSELA
volatile unsigned char           ANSELA              @ 0x18C;
// bit and bitfield definitions
volatile bit ANSA0               @ ((unsigned)&ANSELA*8)+0;
volatile bit ANSA1               @ ((unsigned)&ANSELA*8)+1;
volatile bit ANSA2               @ ((unsigned)&ANSELA*8)+2;
volatile bit ANSA3               @ ((unsigned)&ANSELA*8)+3;
volatile bit ANSA5               @ ((unsigned)&ANSELA*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ANSA0               : 1;
        unsigned	ANSA1               : 1;
        unsigned	ANSA2               : 1;
        unsigned	ANSA3               : 1;
        unsigned	                    : 1;
        unsigned	ANSA5               : 1;
        unsigned	: 1;
        unsigned	: 1;
    };
    struct {
        unsigned	ANSELA              : 6;
    };
} ANSELAbits @ 0x18C;
#endif

// Register: ANSELB
volatile unsigned char           ANSELB              @ 0x18D;
// bit and bitfield definitions
volatile bit ANSB0               @ ((unsigned)&ANSELB*8)+0;
volatile bit ANSB1               @ ((unsigned)&ANSELB*8)+1;
volatile bit ANSB2               @ ((unsigned)&ANSELB*8)+2;
volatile bit ANSB3               @ ((unsigned)&ANSELB*8)+3;
volatile bit ANSB4               @ ((unsigned)&ANSELB*8)+4;
volatile bit ANSB5               @ ((unsigned)&ANSELB*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ANSB0               : 1;
        unsigned	ANSB1               : 1;
        unsigned	ANSB2               : 1;
        unsigned	ANSB3               : 1;
        unsigned	ANSB4               : 1;
        unsigned	ANSB5               : 1;
        unsigned	                    : 2;
    };
    struct {
        unsigned	ANSELB              : 6;
    };
} ANSELBbits @ 0x18D;
#endif

// Register: ANSELC
volatile unsigned char           ANSELC              @ 0x18E;
// bit and bitfield definitions
volatile bit ANSC0               @ ((unsigned)&ANSELC*8)+0;
volatile bit ANSC1               @ ((unsigned)&ANSELC*8)+1;
volatile bit ANSC2               @ ((unsigned)&ANSELC*8)+2;
volatile bit ANSC3               @ ((unsigned)&ANSELC*8)+3;
volatile bit ANSC4               @ ((unsigned)&ANSELC*8)+4;
volatile bit ANSC5               @ ((unsigned)&ANSELC*8)+5;
volatile bit ANSC6               @ ((unsigned)&ANSELC*8)+6;
volatile bit ANSC7               @ ((unsigned)&ANSELC*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ANSC0               : 1;
        unsigned	ANSC1               : 1;
        unsigned	ANSC2               : 1;
        unsigned	ANSC3               : 1;
        unsigned	ANSC4               : 1;
        unsigned	ANSC5               : 1;
        unsigned	ANSC6               : 1;
        unsigned	ANSC7               : 1;
    };
} ANSELCbits @ 0x18E;
#endif

// Register: ANSELD
volatile unsigned char           ANSELD              @ 0x18F;
// bit and bitfield definitions
volatile bit ANSD0               @ ((unsigned)&ANSELD*8)+0;
volatile bit ANSD1               @ ((unsigned)&ANSELD*8)+1;
volatile bit ANSD2               @ ((unsigned)&ANSELD*8)+2;
volatile bit ANSD3               @ ((unsigned)&ANSELD*8)+3;
volatile bit ANSD4               @ ((unsigned)&ANSELD*8)+4;
volatile bit ANSD5               @ ((unsigned)&ANSELD*8)+5;
volatile bit ANSD6               @ ((unsigned)&ANSELD*8)+6;
volatile bit ANSD7               @ ((unsigned)&ANSELD*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ANSD0               : 1;
        unsigned	ANSD1               : 1;
        unsigned	ANSD2               : 1;
        unsigned	ANSD3               : 1;
        unsigned	ANSD4               : 1;
        unsigned	ANSD5               : 1;
        unsigned	ANSD6               : 1;
        unsigned	ANSD7               : 1;
    };
} ANSELDbits @ 0x18F;
#endif

// Register: ANSELE
volatile unsigned char           ANSELE              @ 0x190;
// bit and bitfield definitions
volatile bit ANSE0               @ ((unsigned)&ANSELE*8)+0;
volatile bit ANSE1               @ ((unsigned)&ANSELE*8)+1;
volatile bit ANSE2               @ ((unsigned)&ANSELE*8)+2;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ANSE0               : 1;
        unsigned	ANSE1               : 1;
        unsigned	ANSE2               : 1;
        unsigned	                    : 5;
    };
    struct {
        unsigned	ANSELE              : 3;
    };
} ANSELEbits @ 0x190;
#endif
// bit and bitfield definitions

// Register: PMADRL
volatile unsigned char           PMADRL              @ 0x191;
// bit and bitfield definitions

// Register: PMADRH
volatile unsigned char           PMADRH              @ 0x192;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PMADRH              : 7;
    };
} PMADRHbits @ 0x192;
#endif

// Register: PMADR
volatile unsigned int            PMADR               @ 0x191;
// bit and bitfield definitions

// Register: PMDATL
volatile unsigned char           PMDATL              @ 0x193;
// bit and bitfield definitions

// Register: PMDATH
volatile unsigned char           PMDATH              @ 0x194;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PMDATH              : 6;
    };
} PMDATHbits @ 0x194;
#endif

// Register: PMDAT
volatile unsigned int            PMDAT               @ 0x193;

// Register: PMCON1
volatile unsigned char           PMCON1              @ 0x195;
// bit and bitfield definitions
// Read Control bit
volatile bit RD                  @ ((unsigned)&PMCON1*8)+0;
// Write Control bit
volatile bit WR                  @ ((unsigned)&PMCON1*8)+1;
// Program/Erase Enable bit
volatile bit WREN                @ ((unsigned)&PMCON1*8)+2;
// Sequence Error Flag bit
volatile bit WRERR               @ ((unsigned)&PMCON1*8)+3;
// Program FLASH Erase Enable bit
volatile bit FREE                @ ((unsigned)&PMCON1*8)+4;
// Load Write Latches Only bit
volatile bit LWLO                @ ((unsigned)&PMCON1*8)+5;
// FLASH Program / Data EEPROM or Configuration Select bit
volatile bit CFGS                @ ((unsigned)&PMCON1*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RD                  : 1;
        unsigned	WR                  : 1;
        unsigned	WREN                : 1;
        unsigned	WRERR               : 1;
        unsigned	FREE                : 1;
        unsigned	LWLO                : 1;
        unsigned	CFGS                : 1;
        unsigned	                    : 1;
    };
} PMCON1bits @ 0x195;
#endif

// Register: PMCON2
volatile unsigned char           PMCON2              @ 0x196;
// bit and bitfield definitions

// Register: VREGCON
volatile unsigned char           VREGCON             @ 0x197;
// bit and bitfield definitions
volatile bit reserved            @ ((unsigned)&VREGCON*8)+0;
volatile bit VREGPM              @ ((unsigned)&VREGCON*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	reserved            : 1;
        unsigned	VREGPM              : 1;
    };
} VREGCONbits @ 0x197;
#endif

// Register: RCREG
volatile unsigned char           RCREG               @ 0x199;
// bit and bitfield definitions

// Register: TXREG
volatile unsigned char           TXREG               @ 0x19A;
// bit and bitfield definitions

// Register: SPBRGL
volatile unsigned char           SPBRGL              @ 0x19B;
volatile unsigned char           SPBRG               @ 0x19B;
// bit and bitfield definitions

// Register: SPBRGH
volatile unsigned char           SPBRGH              @ 0x19C;
// bit and bitfield definitions

// Register: RCSTA
// Receive Status and Control Register
volatile unsigned char           RCSTA               @ 0x19D;
// bit and bitfield definitions
// 9th bit of received data (can be parity bit)
volatile bit RX9D                @ ((unsigned)&RCSTA*8)+0;
// Overrun Error bit
volatile bit OERR                @ ((unsigned)&RCSTA*8)+1;
// Framing Error bit
volatile bit FERR                @ ((unsigned)&RCSTA*8)+2;
// Address Detect Enable bit
volatile bit ADDEN               @ ((unsigned)&RCSTA*8)+3;
// Continuous Receive Enable bit
volatile bit CREN                @ ((unsigned)&RCSTA*8)+4;
// Single Receive Enable bit
volatile bit SREN                @ ((unsigned)&RCSTA*8)+5;
// 9-bit Receive Enable bit
volatile bit RX9                 @ ((unsigned)&RCSTA*8)+6;
// Serial Port Enable bit
volatile bit SPEN                @ ((unsigned)&RCSTA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RX9D                : 1;
        unsigned	OERR                : 1;
        unsigned	FERR                : 1;
        unsigned	ADDEN               : 1;
        unsigned	CREN                : 1;
        unsigned	SREN                : 1;
        unsigned	RX9                 : 1;
        unsigned	SPEN                : 1;
    };
} RCSTAbits @ 0x19D;
#endif

// Register: TXSTA
// Transmit Status and Control Register
volatile unsigned char           TXSTA               @ 0x19E;
// bit and bitfield definitions
// 9th bit of transmit data; can be used as parity bit
volatile bit TX9D                @ ((unsigned)&TXSTA*8)+0;
// Transmit Operation Idle Status bit
volatile bit TRMT                @ ((unsigned)&TXSTA*8)+1;
// High Baud Rate Select bit
volatile bit BRGH                @ ((unsigned)&TXSTA*8)+2;
// Send BREAK character bit
volatile bit SENDB               @ ((unsigned)&TXSTA*8)+3;
// USART Mode Select bit
volatile bit SYNC                @ ((unsigned)&TXSTA*8)+4;
// Transmit Enable bit
volatile bit TXEN                @ ((unsigned)&TXSTA*8)+5;
// 9-bit Transmit Enable bit
volatile bit TX9                 @ ((unsigned)&TXSTA*8)+6;
// Clock Source Select bit
volatile bit CSRC                @ ((unsigned)&TXSTA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TX9D                : 1;
        unsigned	TRMT                : 1;
        unsigned	BRGH                : 1;
        unsigned	SENDB               : 1;
        unsigned	SYNC                : 1;
        unsigned	TXEN                : 1;
        unsigned	TX9                 : 1;
        unsigned	CSRC                : 1;
    };
} TXSTAbits @ 0x19E;
#endif

// Register: BAUDCON
// Baud Rate Control Register
volatile unsigned char           BAUDCON             @ 0x19F;
// bit and bitfield definitions
// Auto-Baud Detect Enable bit
volatile bit ABDEN               @ ((unsigned)&BAUDCON*8)+0;
// Wake-Up Enable bit
volatile bit WUE                 @ ((unsigned)&BAUDCON*8)+1;
// 16-bit Baud Rate Register enable bit
volatile bit BRG16               @ ((unsigned)&BAUDCON*8)+3;
// Clock/Transmit Polarity Select bit
volatile bit SCKP                @ ((unsigned)&BAUDCON*8)+4;
// Receive Operation Idle Status bit
volatile bit RCIDL               @ ((unsigned)&BAUDCON*8)+6;
// BRG Rollover Status bit
volatile bit ABDOVF              @ ((unsigned)&BAUDCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ABDEN               : 1;
        unsigned	WUE                 : 1;
        unsigned	                    : 1;
        unsigned	BRG16               : 1;
        unsigned	SCKP                : 1;
        unsigned	: 1;
        unsigned	RCIDL               : 1;
        unsigned	ABDOVF              : 1;
    };
} BAUDCONbits @ 0x19F;
#endif

//
// Special function register definitions: Bank 4
//


// Register: WPUB
volatile unsigned char           WPUB                @ 0x20D;
// bit and bitfield definitions
volatile bit WPUB0               @ ((unsigned)&WPUB*8)+0;
volatile bit WPUB1               @ ((unsigned)&WPUB*8)+1;
volatile bit WPUB2               @ ((unsigned)&WPUB*8)+2;
volatile bit WPUB3               @ ((unsigned)&WPUB*8)+3;
volatile bit WPUB4               @ ((unsigned)&WPUB*8)+4;
volatile bit WPUB5               @ ((unsigned)&WPUB*8)+5;
volatile bit WPUB6               @ ((unsigned)&WPUB*8)+6;
volatile bit WPUB7               @ ((unsigned)&WPUB*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	WPUB0               : 1;
        unsigned	WPUB1               : 1;
        unsigned	WPUB2               : 1;
        unsigned	WPUB3               : 1;
        unsigned	WPUB4               : 1;
        unsigned	WPUB5               : 1;
        unsigned	WPUB6               : 1;
        unsigned	WPUB7               : 1;
    };
} WPUBbits @ 0x20D;
#endif

// Register: WPUE
volatile unsigned char           WPUE                @ 0x210;
// bit and bitfield definitions
volatile bit WPUE3               @ ((unsigned)&WPUE*8)+3;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 3;
        unsigned	WPUE3               : 1;
    };
} WPUEbits @ 0x210;
#endif

// Register: SSPBUF
volatile unsigned char           SSPBUF              @ 0x211;
volatile unsigned char           SSP1BUF             @ 0x211;
// bit and bitfield definitions

// Register: SSPADD
volatile unsigned char           SSPADD              @ 0x212;
volatile unsigned char           SSP1ADD             @ 0x212;
// bit and bitfield definitions

// Register: SSPMSK
volatile unsigned char           SSPMSK              @ 0x213;
volatile unsigned char           SSP1MSK             @ 0x213;
// bit and bitfield definitions

// Register: SSPSTAT
volatile unsigned char           SSPSTAT             @ 0x214;
volatile unsigned char           SSP1STAT            @ 0x214;
// bit and bitfield definitions
volatile bit BF                  @ ((unsigned)&SSPSTAT*8)+0;
volatile bit UA                  @ ((unsigned)&SSPSTAT*8)+1;
volatile bit R_nW                @ ((unsigned)&SSPSTAT*8)+2;
volatile bit S                   @ ((unsigned)&SSPSTAT*8)+3;
volatile bit P                   @ ((unsigned)&SSPSTAT*8)+4;
volatile bit D_nA                @ ((unsigned)&SSPSTAT*8)+5;
volatile bit CKE                 @ ((unsigned)&SSPSTAT*8)+6;
volatile bit SMP                 @ ((unsigned)&SSPSTAT*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	BF                  : 1;
        unsigned	UA                  : 1;
        unsigned	R_nW                : 1;
        unsigned	S                   : 1;
        unsigned	P                   : 1;
        unsigned	D_nA                : 1;
        unsigned	CKE                 : 1;
        unsigned	SMP                 : 1;
    };
} SSPSTATbits @ 0x214;
#endif

// Register: SSPCON1
volatile unsigned char           SSPCON1             @ 0x215;
volatile unsigned char           SSPCON              @ 0x215;
volatile unsigned char           SSP1CON1            @ 0x215;
// bit and bitfield definitions
volatile bit CKP                 @ ((unsigned)&SSPCON1*8)+4;
volatile bit SSPEN               @ ((unsigned)&SSPCON1*8)+5;
volatile bit SSPOV               @ ((unsigned)&SSPCON1*8)+6;
volatile bit WCOL                @ ((unsigned)&SSPCON1*8)+7;
volatile bit SSPM0               @ ((unsigned)&SSPCON1*8)+0;
volatile bit SSPM1               @ ((unsigned)&SSPCON1*8)+1;
volatile bit SSPM2               @ ((unsigned)&SSPCON1*8)+2;
volatile bit SSPM3               @ ((unsigned)&SSPCON1*8)+3;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SSPM                : 4;
        unsigned	CKP                 : 1;
        unsigned	SSPEN               : 1;
        unsigned	SSPOV               : 1;
        unsigned	WCOL                : 1;
    };
    struct {
        unsigned	SSPM0               : 1;
        unsigned	SSPM1               : 1;
        unsigned	SSPM2               : 1;
        unsigned	SSPM3               : 1;
    };
} SSPCON1bits @ 0x215;
#endif

// Register: SSPCON2
volatile unsigned char           SSPCON2             @ 0x216;
volatile unsigned char           SSP1CON2            @ 0x216;
// bit and bitfield definitions
volatile bit SEN                 @ ((unsigned)&SSPCON2*8)+0;
volatile bit RSEN                @ ((unsigned)&SSPCON2*8)+1;
volatile bit PEN                 @ ((unsigned)&SSPCON2*8)+2;
volatile bit RCEN                @ ((unsigned)&SSPCON2*8)+3;
volatile bit ACKEN               @ ((unsigned)&SSPCON2*8)+4;
volatile bit ACKDT               @ ((unsigned)&SSPCON2*8)+5;
volatile bit ACKSTAT             @ ((unsigned)&SSPCON2*8)+6;
volatile bit GCEN                @ ((unsigned)&SSPCON2*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SEN                 : 1;
        unsigned	RSEN                : 1;
        unsigned	PEN                 : 1;
        unsigned	RCEN                : 1;
        unsigned	ACKEN               : 1;
        unsigned	ACKDT               : 1;
        unsigned	ACKSTAT             : 1;
        unsigned	GCEN                : 1;
    };
} SSPCON2bits @ 0x216;
#endif

// Register: SSPCON3
volatile unsigned char           SSPCON3             @ 0x217;
volatile unsigned char           SSP1CON3            @ 0x217;
// bit and bitfield definitions
volatile bit DHEN                @ ((unsigned)&SSPCON3*8)+0;
volatile bit AHEN                @ ((unsigned)&SSPCON3*8)+1;
volatile bit SBCDE               @ ((unsigned)&SSPCON3*8)+2;
volatile bit SDAHT               @ ((unsigned)&SSPCON3*8)+3;
volatile bit BOEN                @ ((unsigned)&SSPCON3*8)+4;
volatile bit SCIE                @ ((unsigned)&SSPCON3*8)+5;
volatile bit PCIE                @ ((unsigned)&SSPCON3*8)+6;
volatile bit ACKTIM              @ ((unsigned)&SSPCON3*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	DHEN                : 1;
        unsigned	AHEN                : 1;
        unsigned	SBCDE               : 1;
        unsigned	SDAHT               : 1;
        unsigned	BOEN                : 1;
        unsigned	SCIE                : 1;
        unsigned	PCIE                : 1;
        unsigned	ACKTIM              : 1;
    };
} SSPCON3bits @ 0x217;
#endif

//
// Special function register definitions: Bank 5
//


// Register: CCPR1L
volatile unsigned char           CCPR1L              @ 0x291;
// bit and bitfield definitions

// Register: CCPR1H
volatile unsigned char           CCPR1H              @ 0x292;
// bit and bitfield definitions

// Register: CCP1CON
volatile unsigned char           CCP1CON             @ 0x293;
// bit and bitfield definitions
volatile bit CCP1M0              @ ((unsigned)&CCP1CON*8)+0;
volatile bit CCP1M1              @ ((unsigned)&CCP1CON*8)+1;
volatile bit CCP1M2              @ ((unsigned)&CCP1CON*8)+2;
volatile bit CCP1M3              @ ((unsigned)&CCP1CON*8)+3;
volatile bit DC1B0               @ ((unsigned)&CCP1CON*8)+4;
volatile bit DC1B1               @ ((unsigned)&CCP1CON*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP1M               : 4;
        unsigned	DC1B                : 2;
        unsigned	                    : 2;
    };
    struct {
        unsigned	CCP1M0              : 1;
        unsigned	CCP1M1              : 1;
        unsigned	CCP1M2              : 1;
        unsigned	CCP1M3              : 1;
        unsigned	DC1B0               : 1;
        unsigned	DC1B1               : 1;
        unsigned	: 1;
        unsigned	: 1;
    };
} CCP1CONbits @ 0x293;
#endif

// Register: CCPR2L
volatile unsigned char           CCPR2L              @ 0x298;
// bit and bitfield definitions

// Register: CCPR2H
volatile unsigned char           CCPR2H              @ 0x299;
// bit and bitfield definitions

// Register: CCP2CON
volatile unsigned char           CCP2CON             @ 0x29A;
// bit and bitfield definitions
volatile bit CCP2M0              @ ((unsigned)&CCP2CON*8)+0;
volatile bit CCP2M1              @ ((unsigned)&CCP2CON*8)+1;
volatile bit CCP2M2              @ ((unsigned)&CCP2CON*8)+2;
volatile bit CCP2M3              @ ((unsigned)&CCP2CON*8)+3;
volatile bit DC2B0               @ ((unsigned)&CCP2CON*8)+4;
volatile bit DC2B1               @ ((unsigned)&CCP2CON*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP2M               : 4;
        unsigned	DC2B                : 2;
        unsigned	                    : 2;
    };
    struct {
        unsigned	CCP2M0              : 1;
        unsigned	CCP2M1              : 1;
        unsigned	CCP2M2              : 1;
        unsigned	CCP2M3              : 1;
        unsigned	DC2B0               : 1;
        unsigned	DC2B1               : 1;
        unsigned	: 1;
        unsigned	: 1;
    };
} CCP2CONbits @ 0x29A;
#endif

//
// Special function register definitions: Bank 7
//


// Register: IOCBP
// Interrupt-On-Change Positive Edge Register
volatile unsigned char           IOCBP               @ 0x394;
// bit and bitfield definitions
volatile bit IOCBP0              @ ((unsigned)&IOCBP*8)+0;
volatile bit IOCBP1              @ ((unsigned)&IOCBP*8)+1;
volatile bit IOCBP2              @ ((unsigned)&IOCBP*8)+2;
volatile bit IOCBP3              @ ((unsigned)&IOCBP*8)+3;
volatile bit IOCBP4              @ ((unsigned)&IOCBP*8)+4;
volatile bit IOCBP5              @ ((unsigned)&IOCBP*8)+5;
volatile bit IOCBP6              @ ((unsigned)&IOCBP*8)+6;
volatile bit IOCBP7              @ ((unsigned)&IOCBP*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	IOCBP0              : 1;
        unsigned	IOCBP1              : 1;
        unsigned	IOCBP2              : 1;
        unsigned	IOCBP3              : 1;
        unsigned	IOCBP4              : 1;
        unsigned	IOCBP5              : 1;
        unsigned	IOCBP6              : 1;
        unsigned	IOCBP7              : 1;
    };
} IOCBPbits @ 0x394;
#endif

// Register: IOCBN
// Interrupt-On-Change Negative Edge Register
volatile unsigned char           IOCBN               @ 0x395;
// bit and bitfield definitions
volatile bit IOCBN0              @ ((unsigned)&IOCBN*8)+0;
volatile bit IOCBN1              @ ((unsigned)&IOCBN*8)+1;
volatile bit IOCBN2              @ ((unsigned)&IOCBN*8)+2;
volatile bit IOCBN3              @ ((unsigned)&IOCBN*8)+3;
volatile bit IOCBN4              @ ((unsigned)&IOCBN*8)+4;
volatile bit IOCBN5              @ ((unsigned)&IOCBN*8)+5;
volatile bit IOCBN6              @ ((unsigned)&IOCBN*8)+6;
volatile bit IOCBN7              @ ((unsigned)&IOCBN*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	IOCBN0              : 1;
        unsigned	IOCBN1              : 1;
        unsigned	IOCBN2              : 1;
        unsigned	IOCBN3              : 1;
        unsigned	IOCBN4              : 1;
        unsigned	IOCBN5              : 1;
        unsigned	IOCBN6              : 1;
        unsigned	IOCBN7              : 1;
    };
} IOCBNbits @ 0x395;
#endif

// Register: IOCBF
// Interrupt-On-Change Flag Register
volatile unsigned char           IOCBF               @ 0x396;
// bit and bitfield definitions
volatile bit IOCBF0              @ ((unsigned)&IOCBF*8)+0;
volatile bit IOCBF1              @ ((unsigned)&IOCBF*8)+1;
volatile bit IOCBF2              @ ((unsigned)&IOCBF*8)+2;
volatile bit IOCBF3              @ ((unsigned)&IOCBF*8)+3;
volatile bit IOCBF4              @ ((unsigned)&IOCBF*8)+4;
volatile bit IOCBF5              @ ((unsigned)&IOCBF*8)+5;
volatile bit IOCBF6              @ ((unsigned)&IOCBF*8)+6;
volatile bit IOCBF7              @ ((unsigned)&IOCBF*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	IOCBF0              : 1;
        unsigned	IOCBF1              : 1;
        unsigned	IOCBF2              : 1;
        unsigned	IOCBF3              : 1;
        unsigned	IOCBF4              : 1;
        unsigned	IOCBF5              : 1;
        unsigned	IOCBF6              : 1;
        unsigned	IOCBF7              : 1;
    };
} IOCBFbits @ 0x396;
#endif

//
// Special function register definitions: Bank 31
//


// Register: STATUS_SHAD
volatile unsigned char           STATUS_SHAD         @ 0xFE4;
// bit and bitfield definitions
volatile bit C_SHAD              @ ((unsigned)&STATUS_SHAD*8)+0;
volatile bit DC_SHAD             @ ((unsigned)&STATUS_SHAD*8)+1;
volatile bit Z_SHAD              @ ((unsigned)&STATUS_SHAD*8)+2;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C_SHAD              : 1;
        unsigned	DC_SHAD             : 1;
        unsigned	Z_SHAD              : 1;
    };
} STATUS_SHADbits @ 0xFE4;
#endif

// Register: WREG_SHAD
volatile unsigned char           WREG_SHAD           @ 0xFE5;
// bit and bitfield definitions

// Register: BSR_SHAD
volatile unsigned char           BSR_SHAD            @ 0xFE6;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	BSR_SHAD            : 5;
    };
} BSR_SHADbits @ 0xFE6;
#endif

// Register: PCLATH_SHAD
volatile unsigned char           PCLATH_SHAD         @ 0xFE7;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PCLATH_SHAD         : 7;
    };
} PCLATH_SHADbits @ 0xFE7;
#endif

// Register: FSR0L_SHAD
volatile unsigned char           FSR0L_SHAD          @ 0xFE8;
// bit and bitfield definitions

// Register: FSR0H_SHAD
volatile unsigned char           FSR0H_SHAD          @ 0xFE9;
// bit and bitfield definitions

// Register: FSR1L_SHAD
volatile unsigned char           FSR1L_SHAD          @ 0xFEA;
// bit and bitfield definitions

// Register: FSR1H_SHAD
volatile unsigned char           FSR1H_SHAD          @ 0xFEB;
// bit and bitfield definitions

// Register: STKPTR
// Current Stack pointer
volatile unsigned char           STKPTR              @ 0xFED;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	STKPTR              : 5;
    };
} STKPTRbits @ 0xFED;
#endif

// Register: TOSL
// Top of Stack Low byte
volatile unsigned char           TOSL                @ 0xFEE;
// bit and bitfield definitions

// Register: TOSH
// Top of Stack High byte
volatile unsigned char           TOSH                @ 0xFEF;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TOSH                : 7;
    };
} TOSHbits @ 0xFEF;
#endif

#endif
