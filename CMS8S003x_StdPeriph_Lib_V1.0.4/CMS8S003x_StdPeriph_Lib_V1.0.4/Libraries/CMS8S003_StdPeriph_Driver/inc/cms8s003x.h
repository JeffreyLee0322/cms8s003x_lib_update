/*--------------------------------------------------------------------------
  CMS8S003.H
 Registers definition for CMS8S003

Copyright CMS Semicon Co., Ltd
 All rights reserved.
-------------------------------------------------------------------------- */
#ifndef _CMS8S003XX_H_
#define _CMS8S003XX_H_



#define MAIN_CLOCK		8000000UL	     // 
//#define MAIN_CLOCK		12500000UL	     // 
//#define MAIN_CLOCK		16000000UL	     // 
//#define MAIN_CLOCK		25000000UL	     // 


#define UART_CKGEN 	"T4"     // "T1" or "T4"

/**********************************************************/
typedef 	unsigned char	u8;
typedef 	unsigned int	u16;
typedef 	unsigned long	u32;
typedef 	unsigned char	uint8_t;
typedef 	unsigned int	uint16_t;
typedef 	unsigned long	uint32_t;

#define		ENABLE		1
#define		DISABLE		0
#define	TRUE	1
#define	FALSE	0
#define	HIGH	1
#define	LOW		0
/* ----------------------------------------------------------------------- */
/* ----------------------------------------------------------------------- */
/* Defined configuration peripherals */

  #define PMU_ENABLED      /* Power Management Unit enabled */
  #define DPTR1_ENABLED    /* Enable second DPTR1           */

  #define PORT0_ENABLED    /* Port 0 enabled                */
  #define PORT1_ENABLED    /* Port 1 enabled                */
  #define PORT2_ENABLED    /* Port 2 enabled                */
  #define PORT3_ENABLED    /* Port 3 enabled                */

  #define TIMERS01_ENABLED /* Timers 0&1 enabled            */
  #define TIMER2_ENABLED   /* Timer 2 enabled               */
  #define TIMER2_CC_ENABLED       /* Timer 2 Compare/Capture enabled       */
  #define TIMERS34_ENABLED /* Timers 3&4 enabled            */
  
  #define ADC_ENABLED       /* ADC enabled       */
  #define EEPROM_ENABLED       /* EEPROM enabled       */
  #define BUZZ_ENABLED       /* BUZZ enabled       */
  #define WUT_ENABLED       /* Wakeup Timer enabled       */
	
  #define DI2CM_ENABLED    /* Master I2C enabled            */
  #define DI2CS_ENABLED    /* Slave I2C enabled             */
  #define WATCHDOG_ENABLED /* Watchdog enabled              */
  #define DSPI_ENABLED     /* Master/Slave SPI enabled      */

  #define FLSC_ENABLED      /* Flash Control enabled     */
	#define UART0_ENABLED
	#define UART1_ENABLED
	
	
/* *********************************************************************** */
/* *********************************************************************** */

/*---------------------------------------------------------------------------
  Defined registers  
---------------------------------------------------------------------------*/

/*  BYTE Register  */
#ifdef PORT0_ENABLED
  sfr P0        = 0x80; /* Port 0                    */
#endif

sfr SP        = 0x81;
sfr DPL       = 0x82;   /* Data Pointer 0 Low byte   */
sfr DPL0      = 0x82;
sfr DPH       = 0x83;   /* Data Pointer 0 Hgih byte  */
sfr DPH0      = 0x83;

#ifdef DPTR1_ENABLED
  sfr DPL1      = 0x84; /* Data Pointer 1 Low byte   */
  sfr DPH1      = 0x85; /* Data Pointer 1 High byte  */
  sfr DPS       = 0x86; /* Data pointers select      */
#endif

sfr PCON      = 0x87;   /* Power Configuration       */
sfr TCON      = 0x88;   /* Timer 0,1 Configuration   */

#ifdef TIMERS01_ENABLED
  sfr TMOD      = 0x89; /* Timer 0,1 Mode            */
  sfr TL0       = 0x8A; /* Timer 0 Low byte counter  */
  sfr TL1       = 0x8B; /* Timer 1 Low byte counter  */
  sfr TH0       = 0x8C; /* Timer 0 High byte counter */
  sfr TH1       = 0x8D; /* Timer 1 High byte counter */
#endif

sfr CKCON     = 0x8E;   /* XDATA Wait States         */

sfr CLKCON     = 0x8F;   /* CPU Clock Setup         */
sfr CLKDIV     = 0x8F;   /* CPU Clock Setup         */


#ifdef PORT1_ENABLED
  sfr P1        = 0x90; /* Port 1                    */
#endif

sfr FUNCCR      = 0x91;   /* */

sfr WTST      = 0x92;   /* Program Wait States       */

sfr DPP       = 0x93;   /* Data Page Pointer 0       */
sfr DPX       = 0x93;   /* Data Page Pointer 0       */
sfr DPX0      = 0x93;

sfr MXAX      = 0x94;   /* MOVX @Ri High address     */

#ifdef DPTR1_ENABLED
  sfr DPX1      = 0x95; /* Data Page Pointer 1       */
#endif

#ifdef WATCHDOG_ENABLED
  sfr TA        = 0x96; /* Timed Access protection   */
#endif

#ifdef WATCHDOG_ENABLED
  sfr WDCON     = 0x97; /* Watchdog configuration    */
  sfr WDTCON     = 0x97; /* Watchdog configuration    */	
#endif

#ifdef UART0_ENABLED
  sfr SCON      = 0x98; /* Serial 0 Configuration    */
  sfr SCON0     = 0x98;
  sfr SBUF      = 0x99; /* Serial 0 I/O Buffer       */
  sfr SBUF0     = 0x99;
#endif

#ifdef PORT0_ENABLED
  sfr P0TRIS        = 0x9A; /*                    */
#endif

  sfr ACON    = 0x9D; /* Address register           */

#ifdef PMU_ENABLED
  sfr STATUS    = 0x9E; /* Status register           */
#endif

  sfr DBGCON    = 0x9F; /* Debug enable register           */

#ifdef PORT2_ENABLED
  sfr P2        = 0xA0; /* Port 2                    */
#endif

#ifdef PORT1_ENABLED
  sfr P1TRIS        = 0xA1; /*                    */
#endif
#ifdef PORT2_ENABLED
  sfr P2TRIS        = 0xA2; /*                    */
#endif
#ifdef PORT3_ENABLED
  sfr P3TRIS        = 0xA3; /*                    */
#endif
/* 
   0xA4
   0xA5
   0xA6
   0xA7*/
sfr IE        = 0xA8;   /* Interrupt Enable          */
/* 0xA9
   0xAA
   0xAB
   0xAC
   0xAD
   0xAE
   0xAF*/

sfr EIE       = 0xA9;   /* External Interrupt Enable */
sfr EIE1       = 0xA9;   /* External Interrupt Enable */

sfr EIE2       = 0xAA;   /* External Interrupt Enable */
	 
sfr EXTIF       = 0xB4;   /* External Interrupt Flag */
sfr P0EXTIF       = 0xB4;   /* P0 Ports External Interrupt Flag */
sfr P1EXTIF       = 0xB5;   /* P1 Ports External Interrupt Flag */
sfr P2EXTIF       = 0xB6;   /* P2 Ports External Interrupt Flag */
sfr P3EXTIF       = 0xB7;   /* P3 Ports External Interrupt Flag */

#ifdef PORT3_ENABLED
  sfr P3        = 0xB0; /* Port 3                    */
#endif

sfr EIF       = 0xB1;   /* External Interrupt Flag */
sfr EIF1       = 0xB1;   /* External Interrupt Flag */
sfr EIF2       = 0xB2;   /* External Interrupt Flag */

/* 0xB1
   0xB2
   0xB3
   0xB4
   0xB5
   0xB6
   0xB7*/

#ifdef WUT_ENABLED
	sfr WUTCRL        = 0xBC; /*                    */
	sfr WUTCRH        = 0xBD; /*                    */
	sfr WKTCL        = 0xBC; /*                    */
	sfr WKTCH        = 0xBD; /*                    */	
#endif	 

#ifdef BUZZ_ENABLED
  	sfr BUZDIV        = 0xBE; /*                    */
	sfr BUZCON        = 0xBF; /*                    */
#endif	 

sfr IP        = 0xB8;
/* 0xB9
   0xBA
   0xBB
   0xBC
   0xBD
   0xBE
   0xBF*/

  sfr EIP     = 0xB9; /* External Interr. Priority */
  sfr EIP1     = 0xB9; /* External Interr. Priority */
  sfr EIP2     = 0xBA; /* External Interr. Priority */

  sfr EXTIE     = 0xAC; /* External Interrupt Enable */
  sfr P0EXTIE     = 0xAC; /* P0 Ports External Interrupt Enable */
  sfr P1EXTIE     = 0xAD; /* P1 Ports External Interrupt Enable */
  sfr P2EXTIE     = 0xAE; /* P2 Ports External Interrupt Enable */
  sfr P3EXTIE     = 0xAF; /* P3 Ports External Interrupt Enable */

#ifdef PORT4_ENABLED
  sfr P4     = 0xC0;  /* Port 4 */
#endif

#ifdef TIMER2_CC_ENABLED
  sfr COUT     = 0xC1;  /* Comare/Capture/Reload 1 Low */
  sfr CCL1     = 0xC2;  /* Comare/Capture/Reload 1 Low */
  sfr CCH1     = 0xC3;  /* Comare/Capture/Reload 1 High*/
  sfr CCL2     = 0xC4;  /* Comare/Capture/Reload 2 Low */
  sfr CCH2     = 0xC5;  /* Comare/Capture/Reload 2 High*/
  sfr CCL3     = 0xC6;  /* Comare/Capture/Reload 3 Low */
  sfr CCH3     = 0xC7;  /* Comare/Capture/Reload 3 High*/
#endif

#if defined(TIMER2_ENABLED)  || defined(TIMER2_CC_ENABLED)
  sfr T2CON     = 0xC8; /* Timer 2 Configuration     */
#endif

#ifdef TIMER2_CC_ENABLED
  sfr T2IF      = 0xC9; /* Timer 2 Interrupt Flags   */
  sfr RCRL      = 0xCA; /* Timer 2 Reload Low byte   */
  sfr RCRH      = 0xCB; /* Timer 2 Reload High byte  */
  sfr TL2       = 0xCC; /* Timer 2 Low byte counter  */
  sfr TH2       = 0xCD; /* Timer 2 High byte counter */
  sfr T2IE       = 0xCF; 
#else
  #ifdef TIMER2_ENABLED
    sfr RLDL      = 0xCA; /* Timer 2 Reload Low byte   */
    sfr RLDH      = 0xCB; /* Timer 2 Reload High byte  */
    sfr TL2       = 0xCC; /* Timer 2 Low byte counter  */
    sfr TH2       = 0xCD; /* Timer 2 High byte counter */
    sfr T2IE       = 0xCF; 
  #endif
#endif

#ifdef TIMER2_CC_ENABLED
  sfr CCEN      = 0xCE; /* Comare/Capture/Reload Enable*/
#endif
/* 0xCF */
sfr PSW       = 0xD0;   /* Program Status Word       */
/* 0xD1
   0xD2
   0xD3
   0xD4
   0xD5
   0xD6
   0xD7*/
   
   
#ifdef ADC_ENABLED
	sfr ADCMPC	= 0xD1;	
#endif

#ifdef TIMERS34_ENABLED
	sfr T34MOD	= 0xD2;	
#endif

#ifdef ADC_ENABLED
	sfr ADDLYL	= 0xD3;	
	sfr ADCMPL	= 0xD4;	
	sfr ADCMPH	= 0xD5;	
#endif

#ifdef TIMER2_CC_ENABLED
  sfr CAPCR1	= 0xD6; 
  sfr CAPCR0	= 0xD6;   
#endif

#ifdef TIMERS34_ENABLED
	sfr TL3			= 0xDA;	
	sfr TH3			= 0xDB;		
#endif

#ifdef PORT5_ENABLED
  sfr P5      = 0xD8; /* Port 5 */
#endif


/* 
   0xDA
   0xDB*/

#ifdef ADC_ENABLED
  sfr ADRESL     = 0xDC; /* ADC result high 8-bit    */
  sfr ADRESH     = 0xDD; /* ADC result low 8-bit    */
  sfr ADCON1     = 0xDE; /* ADC control 1    */
  sfr ADCON0     = 0xDF; /* ADC control 0    */
#endif

sfr ACC       = 0xE0;   /* Accumulator               */

#ifdef TIMERS34_ENABLED
	sfr TL4			= 0xE2;	
	sfr TH4			= 0xE3;		
#endif

#ifdef EEPROM_ENABLED
  sfr EEADDRH     = 0xE4; /* EEPROM address high 8-bit    */
  sfr EEADDRL     = 0xE5; /* EEPROM address low 8-bit    */
  sfr EEADR       = 0xE5; /* EEPROM address low 8-bit    */	
  sfr EEDATA      = 0xE6; /* EEPROM data    */
  sfr EECON       = 0xE7; /* EEPROM control    */
#endif

#ifdef ADC_ENABLED
	sfr ADCON2	= 0xE9;	
#endif

#ifdef UART1_ENABLED
  sfr SCON1     = 0xEA; /* Serial 1 Configuration    */
  sfr SBUF1     = 0xEB;
#endif

#ifdef DSPI_ENABLED
  sfr SPCR      = 0xEC; /* SPI Control Register      */
  sfr SPSR      = 0xED; /* SPI Status Register       */
  sfr SPDR      = 0xEE; /* SPI I/O Register          */
  sfr SSCR      = 0xEF; /* SPI Sleve Select Register */
#endif

sfr B         = 0xF0;   /* B Working register        */

#ifdef DI2CS_ENABLED
  sfr I2CSADR = 0xF1;   /* I2CS Address              */
  sfr I2CSCR  = 0xF2;   /* I2CS Control Register     */
  sfr I2CSBUF = 0xF3;   /* I2CS I/O Buffer           */
#endif

#ifdef DI2CM_ENABLED
  sfr I2CMSA   = 0xF4;  /* I2CM Slave Address        */
  sfr I2CMCR   = 0xF5;  /* I2CM Control Register     */
  sfr I2CMBUF  = 0xF6;  /* I2CM I/O Buffer           */
  sfr I2CMTP   = 0xF7;  /* I2CM Timer Period         */
#endif

#ifdef FLSC_ENABLED
   sfr MADRL	= 0xFC;
   sfr MADRH	= 0xFD;
   sfr MDATA	= 0xFE;
   sfr MCTRL	= 0xFF;
#endif

/*-------------------------------------------------------------------------*/
/*	sfr 16 */
/*-------------------------------------------------------------------------*/

#if defined(TIMER2_ENABLED)  || defined(TIMER2_CC_ENABLED)
sfr16	T2	= 0xCC;		// {T2L,T2H}
#endif

#ifdef TIMER2_CC_ENABLED
sfr16	CC1	= 0xC2;		// {CCL1,CCH1}
sfr16	CC2	= 0xC4;		// {CCL2,CCH2}
sfr16	CC3	= 0xC6;		// {CCL3,CCH3}
sfr16	RCR	= 0xCA;		// {RCRL,RCRH}
#else
  #ifdef TIMER2_ENABLED
sfr16	RLD	= 0xCA;		// {RCRL,RCRH}
//sfr16	RCAP2	= 0xCA;		// {RCRL,RCRH}
  #endif
#endif

#ifdef ADC_ENABLED	
sfr16	ADRES	= 0xDC;		// {ADRESL,ADRESH}
#endif

#ifdef EEPROM_ENABLED
sfr16	EEADDR	= 0xEC;		// {EEADRL,EEADRH}
#endif

#ifdef FLSC_ENABLED
sfr16	MADR	= 0xFC;		// {MADRL,MADRH}
#endif

/*-------------------------------------------------------------------------*/
/*	XSFR */
/*-------------------------------------------------------------------------*/
#define P0CFG  0xF000
#define P00CFG *(volatile unsigned char xdata *) 0xF000
#define P01CFG *(volatile unsigned char xdata *) 0xF001
#define P02CFG *(volatile unsigned char xdata *) 0xF002
#define P03CFG *(volatile unsigned char xdata *) 0xF003
#define P04CFG *(volatile unsigned char xdata *) 0xF004
#define P05CFG *(volatile unsigned char xdata *) 0xF005
#define P06CFG *(volatile unsigned char xdata *) 0xF006
#define P07CFG *(volatile unsigned char xdata *) 0xF007
#define P0ANS *(volatile unsigned char xdata *) 0xF008
#define P0OD *(volatile unsigned char xdata *) 0xF009
#define P0UP *(volatile unsigned char xdata *) 0xF00A
//#define P0RD	*(volatile unsigned char xdata *) 0xF00B
#define P0DOWN	*(volatile unsigned char xdata *) 0xF00B
#define P0DR	*(volatile unsigned char xdata *) 0xF00C
#define P0SR	*(volatile unsigned char xdata *) 0xF00D

#define P1CFG  0xF010
#define P10CFG *(volatile unsigned char xdata *) 0xF010
#define P11CFG *(volatile unsigned char xdata *) 0xF011
#define P12CFG *(volatile unsigned char xdata *) 0xF012
#define P13CFG *(volatile unsigned char xdata *) 0xF013
#define P14CFG *(volatile unsigned char xdata *) 0xF014
#define P15CFG *(volatile unsigned char xdata *) 0xF015
#define P16CFG *(volatile unsigned char xdata *) 0xF016
#define P17CFG *(volatile unsigned char xdata *) 0xF017
#define P1ANS *(volatile unsigned char xdata *) 0xF018
#define P1OD *(volatile unsigned char xdata *) 0xF019
#define P1UP *(volatile unsigned char xdata *) 0xF01A
//#define P1RD	*(volatile unsigned char xdata *) 0xF01B
#define P1DOWN	*(volatile unsigned char xdata *) 0xF01B
#define P1DR	*(volatile unsigned char xdata *) 0xF01C
#define P1SR	*(volatile unsigned char xdata *) 0xF01D

#define P2CFG  0xF020
#define P20CFG *(volatile unsigned char xdata *) 0xF020
#define P21CFG *(volatile unsigned char xdata *) 0xF021
#define P22CFG *(volatile unsigned char xdata *) 0xF022
#define P23CFG *(volatile unsigned char xdata *) 0xF023
#define P24CFG *(volatile unsigned char xdata *) 0xF024
#define P25CFG *(volatile unsigned char xdata *) 0xF025
#define P26CFG *(volatile unsigned char xdata *) 0xF026
#define P27CFG *(volatile unsigned char xdata *) 0xF027
#define P2ANS *(volatile unsigned char xdata *) 0xF028
#define P2OD *(volatile unsigned char xdata *) 0xF029
#define P2UP *(volatile unsigned char xdata *) 0xF02A
//#define P2RD	*(volatile unsigned char xdata *) 0xF02B
#define P2DOWN	*(volatile unsigned char xdata *) 0xF02B
#define P2DR	*(volatile unsigned char xdata *) 0xF02C
#define P2SR	*(volatile unsigned char xdata *) 0xF02D	

#define P3CFG  0xF030
#define P30CFG *(volatile unsigned char xdata *) 0xF030
#define P31CFG *(volatile unsigned char xdata *) 0xF031
#define P32CFG *(volatile unsigned char xdata *) 0xF032
#define P33CFG *(volatile unsigned char xdata *) 0xF033
#define P34CFG *(volatile unsigned char xdata *) 0xF034
#define P35CFG *(volatile unsigned char xdata *) 0xF035
#define P36CFG *(volatile unsigned char xdata *) 0xF036
#define P37CFG *(volatile unsigned char xdata *) 0xF037
#define P3ANS *(volatile unsigned char xdata *) 0xF038
#define P3OD *(volatile unsigned char xdata *) 0xF039
#define P3UP *(volatile unsigned char xdata *) 0xF03A
//#define P3RD	*(volatile unsigned char xdata *) 0xF03B
#define P3DOWN	*(volatile unsigned char xdata *) 0xF03B
#define P3DR	*(volatile unsigned char xdata *) 0xF03C
#define P3SR	*(volatile unsigned char xdata *) 0xF03D	

//#define INT0CFG *(volatile unsigned char xdata *) 0xF080
//#define INT1CFG *(volatile unsigned char xdata *) 0xF081
//#define INT2CFG *(volatile unsigned char xdata *) 0xF082
//#define INT3CFG *(volatile unsigned char xdata *) 0xF083
//#define INT4CFG *(volatile unsigned char xdata *) 0xF084
//#define INT5CFG *(volatile unsigned char xdata *) 0xF085
//#define INT6CFG *(volatile unsigned char xdata *) 0xF086
//#define INT7CFG *(volatile unsigned char xdata *) 0xF087

#define P00EICFG *(volatile unsigned char xdata *) 0xF080
#define P01EICFG *(volatile unsigned char xdata *) 0xF081
#define P02EICFG *(volatile unsigned char xdata *) 0xF082
#define P03EICFG *(volatile unsigned char xdata *) 0xF083
#define P04EICFG *(volatile unsigned char xdata *) 0xF084
#define P05EICFG *(volatile unsigned char xdata *) 0xF085
#define P06EICFG *(volatile unsigned char xdata *) 0xF086
#define P07EICFG *(volatile unsigned char xdata *) 0xF087

#define P10EICFG *(volatile unsigned char xdata *) 0xF088
#define P11EICFG *(volatile unsigned char xdata *) 0xF089
#define P12EICFG *(volatile unsigned char xdata *) 0xF08A
#define P13EICFG *(volatile unsigned char xdata *) 0xF08B
#define P14EICFG *(volatile unsigned char xdata *) 0xF08C
#define P15EICFG *(volatile unsigned char xdata *) 0xF08D
#define P16EICFG *(volatile unsigned char xdata *) 0xF08E
#define P17EICFG *(volatile unsigned char xdata *) 0xF08F

#define P20EICFG *(volatile unsigned char xdata *) 0xF090
#define P21EICFG *(volatile unsigned char xdata *) 0xF091
#define P22EICFG *(volatile unsigned char xdata *) 0xF092
#define P23EICFG *(volatile unsigned char xdata *) 0xF093
#define P24EICFG *(volatile unsigned char xdata *) 0xF094
#define P25EICFG *(volatile unsigned char xdata *) 0xF095
#define P26EICFG *(volatile unsigned char xdata *) 0xF096
#define P27EICFG *(volatile unsigned char xdata *) 0xF097

#define P30EICFG *(volatile unsigned char xdata *) 0xF098
#define P31EICFG *(volatile unsigned char xdata *) 0xF099
#define P32EICFG *(volatile unsigned char xdata *) 0xF09A
#define P33EICFG *(volatile unsigned char xdata *) 0xF09B
#define P34EICFG *(volatile unsigned char xdata *) 0xF09C
#define P35EICFG *(volatile unsigned char xdata *) 0xF09D
#define P36EICFG *(volatile unsigned char xdata *) 0xF09E
#define P37EICFG *(volatile unsigned char xdata *) 0xF09F

#define PWMCON		*(volatile unsigned char xdata *) 0xF120
#define PWMOE			*(volatile unsigned char xdata *) 0xF121  
#define PWMPINV		*(volatile unsigned char xdata *) 0xF122  
#define PWM01PSC	*(volatile unsigned char xdata *) 0xF123  
#define PWM23PSC	*(volatile unsigned char xdata *) 0xF124  
#define PWM45PSC	*(volatile unsigned char xdata *) 0xF125  
#define PWMCNTE		*(volatile unsigned char xdata *) 0xF126  
#define PWMCNTM		*(volatile unsigned char xdata *) 0xF127  
#define PWMCNTCLR	*(volatile unsigned char xdata *) 0xF128  
#define PWMLOADEN	*(volatile unsigned char xdata *) 0xF129  

#define PWMDIVBASE	 0xF12A  
#define PWM0DIV		*(volatile unsigned char xdata *) 0xF12A  
#define PWM1DIV		*(volatile unsigned char xdata *) 0xF12B  
#define PWM2DIV		*(volatile unsigned char xdata *) 0xF12C  
#define PWM3DIV		*(volatile unsigned char xdata *) 0xF12D  
#define PWM4DIV		*(volatile unsigned char xdata *) 0xF12E  
#define PWM5DIV		*(volatile unsigned char xdata *) 0xF12F  

#define PWMPLBASE	0xF130  
#define PWMPHBASE	0xF131
#define PWM0PL		*(volatile unsigned char xdata *) 0xF130  
#define PWM0PH		*(volatile unsigned char xdata *) 0xF131 
#define PWM1PL		*(volatile unsigned char xdata *) 0xF132 
#define PWM1PH		*(volatile unsigned char xdata *) 0xF133 
#define PWM2PL		*(volatile unsigned char xdata *) 0xF134 
#define PWM2PH		*(volatile unsigned char xdata *) 0xF135 
#define PWM3PL		*(volatile unsigned char xdata *) 0xF136 
#define PWM3PH		*(volatile unsigned char xdata *) 0xF137 
#define PWM4PL		*(volatile unsigned char xdata *) 0xF138 
#define PWM4PH		*(volatile unsigned char xdata *) 0xF139 
#define PWM5PL		*(volatile unsigned char xdata *) 0xF13A 
#define PWM5PH		*(volatile unsigned char xdata *) 0xF13B 

#define PWMDLBASE	0xF140  
#define PWMDHBASE	0xF141
#define PWM0DL		*(volatile unsigned char xdata *) 0xF140  
#define PWM0DH		*(volatile unsigned char xdata *) 0xF141 
#define PWM1DL		*(volatile unsigned char xdata *) 0xF142 
#define PWM1DH		*(volatile unsigned char xdata *) 0xF143 
#define PWM2DL		*(volatile unsigned char xdata *) 0xF144 
#define PWM2DH		*(volatile unsigned char xdata *) 0xF145 
#define PWM3DL		*(volatile unsigned char xdata *) 0xF146 
#define PWM3DH		*(volatile unsigned char xdata *) 0xF147 
#define PWM4DL		*(volatile unsigned char xdata *) 0xF148 
#define PWM4DH		*(volatile unsigned char xdata *) 0xF149 
#define PWM5DL		*(volatile unsigned char xdata *) 0xF14A 
#define PWM5DH		*(volatile unsigned char xdata *) 0xF14B   

#define PWMDDLBASE 		0xF150  
#define PWMDDHBASE 		0xF151 
#define PWM0DDL		*(volatile unsigned char xdata *) 0xF150  
#define PWM0DDH		*(volatile unsigned char xdata *) 0xF151 
#define PWM1DDL		*(volatile unsigned char xdata *) 0xF152 
#define PWM1DDH		*(volatile unsigned char xdata *) 0xF153 
#define PWM2DDL		*(volatile unsigned char xdata *) 0xF154 
#define PWM2DDH		*(volatile unsigned char xdata *) 0xF155 
#define PWM3DDL		*(volatile unsigned char xdata *) 0xF156 
#define PWM3DDH		*(volatile unsigned char xdata *) 0xF157 
#define PWM4DDL		*(volatile unsigned char xdata *) 0xF158 
#define PWM4DDH		*(volatile unsigned char xdata *) 0xF159 
#define PWM5DDL		*(volatile unsigned char xdata *) 0xF15A 
#define PWM5DDH		*(volatile unsigned char xdata *) 0xF15B   

#define PWMDTE		*(volatile unsigned char xdata *) 0xF160 
#define PWM01DT		*(volatile unsigned char xdata *) 0xF161 
#define PWM23DT		*(volatile unsigned char xdata *) 0xF162
#define PWM45DT		*(volatile unsigned char xdata *) 0xF163 
	
#define PWMMASKE	*(volatile unsigned char xdata *) 0xF164 
#define PWMMASKD	*(volatile unsigned char xdata *) 0xF165 
#define PWMFBKC		*(volatile unsigned char xdata *) 0xF166 
#define PWMFBKD		*(volatile unsigned char xdata *) 0xF167 
	
#define PWMPIE		*(volatile unsigned char xdata *) 0xF168   
#define PWMZIE		*(volatile unsigned char xdata *) 0xF169   
#define PWMUIE		*(volatile unsigned char xdata *) 0xF16A   
#define PWMDIE		*(volatile unsigned char xdata *) 0xF16B   
#define PWMPIF		*(volatile unsigned char xdata *) 0xF16C   
#define PWMZIF		*(volatile unsigned char xdata *) 0xF16D   
#define PWMUIF		*(volatile unsigned char xdata *) 0xF16E   
#define PWMDIF		*(volatile unsigned char xdata *) 0xF16F

#define PWMPLBASE		0xF130
#define PWMPHBASE		0xF131
#define PWMP0L		*(volatile unsigned char xdata *) 0xF130
#define PWMP0H		*(volatile unsigned char xdata *) 0xF131
#define PWMP1L		*(volatile unsigned char xdata *) 0xF132
#define PWMP1H		*(volatile unsigned char xdata *) 0xF133
#define PWMP2L		*(volatile unsigned char xdata *) 0xF134
#define PWMP2H		*(volatile unsigned char xdata *) 0xF135
#define PWMP3L		*(volatile unsigned char xdata *) 0xF136
#define PWMP3H		*(volatile unsigned char xdata *) 0xF137
#define PWMP4L		*(volatile unsigned char xdata *) 0xF138
#define PWMP4H		*(volatile unsigned char xdata *) 0xF139
#define PWMP5L		*(volatile unsigned char xdata *) 0xF13a
#define PWMP5H		*(volatile unsigned char xdata *) 0xF13b
	
#define PWMDLBASE	0xF140 
#define PWMDHBASE	0xF141 
#define PWMD0L		*(volatile unsigned char xdata *) 0xF140  
#define PWMD0H		*(volatile unsigned char xdata *) 0xF141 
#define PWMD1L		*(volatile unsigned char xdata *) 0xF142 
#define PWMD1H		*(volatile unsigned char xdata *) 0xF143 
#define PWMD2L		*(volatile unsigned char xdata *) 0xF144 
#define PWMD2H		*(volatile unsigned char xdata *) 0xF145 
#define PWMD3L		*(volatile unsigned char xdata *) 0xF146 
#define PWMD3H		*(volatile unsigned char xdata *) 0xF147 
#define PWMD4L		*(volatile unsigned char xdata *) 0xF148 
#define PWMD4H		*(volatile unsigned char xdata *) 0xF149 
#define PWMD5L		*(volatile unsigned char xdata *) 0xF14A 
#define PWMD5H		*(volatile unsigned char xdata *) 0xF14B 


/*---------------??OPA??------------*/
#define OP0CON0		*(volatile unsigned char xdata *) 0xF520 
#define OP0CON1		*(volatile unsigned char xdata *) 0xF521 
#define OP1CON0		*(volatile unsigned char xdata *) 0xF523
#define OP1CON1		*(volatile unsigned char xdata *) 0xF524
#define OP0ADJE		*(volatile unsigned char xdata *) 0xF526
#define OP1ADJE		*(volatile unsigned char xdata *) 0xF527



#define C0CON0		*(volatile unsigned char xdata *) 0xF500  
#define C0CON1		*(volatile unsigned char xdata *) 0xF501 
#define C0CON2		*(volatile unsigned char xdata *) 0xF502
#define C1CON0		*(volatile unsigned char xdata *) 0xF503
#define C1CON1		*(volatile unsigned char xdata *) 0xF504
#define C1CON2		*(volatile unsigned char xdata *) 0xF505
#define CNVRCON		*(volatile unsigned char xdata *) 0xF506 
#define CNFBCON		*(volatile unsigned char xdata *) 0xF507 
#define CNIE	  	*(volatile unsigned char xdata *) 0xF508 
#define CNIF	  	*(volatile unsigned char xdata *) 0xF509 
#define C0ADJE		*(volatile unsigned char xdata *) 0xF50A 
#define C1ADJE		*(volatile unsigned char xdata *) 0xF50B 

#define P0DOWN	*(volatile unsigned char xdata *) 0xF00B
#define P1DOWN	*(volatile unsigned char xdata *) 0xF01B
#define P2DOWN	*(volatile unsigned char xdata *) 0xF02B
#define P3DOWN	*(volatile unsigned char xdata *) 0xF03B





	
/*-------------------------------------------------------------------------
  BIT Register  
  -------------------------------------------------------------------------*/

/*  P0  */
#ifdef PORT0_ENABLED
  sbit P0_7     = P0^7;
  sbit P0_6     = P0^6;
  sbit P0_5     = P0^5;
  sbit P0_4     = P0^4;
  sbit P0_3     = P0^3;
  sbit P0_2     = P0^2;
  sbit P0_1     = P0^1;
  sbit P0_0     = P0^0;
#endif
/*  P1  */
#ifdef PORT1_ENABLED
  sbit P1_7     = P1^7;
  sbit P1_6     = P1^6;
  sbit P1_5     = P1^5;
  sbit P1_4     = P1^4;
  sbit P1_3     = P1^3;
  sbit P1_2     = P1^2;
  sbit P1_1     = P1^1;
  sbit P1_0     = P1^0;
#endif
/*  P2  */
#ifdef PORT2_ENABLED
  sbit P2_7     = P2^7;
  sbit P2_6     = P2^6;
  sbit P2_5     = P2^5;
  sbit P2_4     = P2^4;
  sbit P2_3     = P2^3;
  sbit P2_2     = P2^2;
  sbit P2_1     = P2^1;
  sbit P2_0     = P2^0;
#endif
/*  P3  */
#ifdef PORT3_ENABLED
  sbit P3_7     = P3^7;
  sbit P3_6     = P3^6;
  sbit P3_5     = P3^5;
  sbit P3_4     = P3^4;
  sbit P3_3     = P3^3;
  sbit P3_2     = P3^2;
  sbit P3_1     = P3^1;
  sbit P3_0     = P3^0;
#endif
/*  TCON  */
sbit IT0      = TCON^0;
sbit IE0      = TCON^1;
sbit IT1      = TCON^2;
sbit IE1      = TCON^3;
#ifdef TIMERS01_ENABLED
  sbit TR0      = TCON^4;
  sbit TF0      = TCON^5;
  sbit TR1      = TCON^6;
  sbit TF1      = TCON^7;
#endif

/*  SCON0 */
#ifdef UART0_ENABLED
  sbit RI0      = SCON0^0;
  sbit TI0      = SCON0^1;
  sbit RB08     = SCON0^2;
  sbit TB08     = SCON0^3;
  sbit REN0     = SCON0^4;
  sbit SM02     = SCON0^5;
  sbit SM01     = SCON0^6;
  sbit SM00     = SCON0^7;
  
  /* SCON */
  sbit RI       = SCON0^0;
  sbit TI       = SCON0^1;
  sbit RB8      = SCON0^2;
  sbit TB8      = SCON0^3;
  sbit REN      = SCON0^4;
  sbit SM2      = SCON0^5;
  sbit SM1      = SCON0^6;
  sbit SM0      = SCON0^7;
#endif

/*  IE   */
sbit EX0      = IE^0;
#ifdef TIMERS01_ENABLED
  sbit ET0      = IE^1;
#endif
sbit EX1      = IE^2;
#ifdef TIMERS01_ENABLED
  sbit ET1      = IE^3;
#endif
#ifdef UART0_ENABLED
  sbit ES0      = IE^4;
sbit ES       = IE^4;
#endif
#ifdef TIMER2_ENABLED
  sbit ET2      = IE^5;
#endif

sbit EA       = IE^7;

/*  IP   */ 
sbit PX0      = IP^0;
#ifdef TIMERS01_ENABLED
  sbit PT0      = IP^1;
#endif
sbit PX1      = IP^2;
#ifdef TIMERS01_ENABLED
  sbit PT1      = IP^3;
#endif
#ifdef UART0_ENABLED
  sbit PS0      = IP^4;
  sbit PS       = IP^4;
#endif
#ifdef TIMER2_ENABLED
  sbit PT2      = IP^5;
#endif

/*  T2CON  */
#ifdef TIMER2_CC_ENABLED
  sbit T2I0     = T2CON^0;
  sbit T2I1     = T2CON^1;
  sbit T2CM     = T2CON^2;
  sbit T2R0     = T2CON^3;
  sbit T2R1     = T2CON^4;
  /* T2CON^5;*/
  sbit I3FR     = T2CON^6;
  sbit T2PS     = T2CON^7;
#else
  #ifdef TIMER2_ENABLED
    sbit CPRL2    = T2CON^0;
    sbit CT2      = T2CON^1;
    sbit TR2      = T2CON^2;
    sbit EXEN2    = T2CON^3;
    sbit TCLK     = T2CON^4;
    sbit RCLK     = T2CON^5;
    sbit EXF2     = T2CON^6;
    sbit TF2      = T2CON^7;
  #endif
#endif

/*  PSW   */
sbit P        = PSW^0;
sbit F1       = PSW^1;
sbit OV       = PSW^2;
sbit RS0      = PSW^3;
sbit RS1      = PSW^4;
sbit F0       = PSW^5;
sbit AC       = PSW^6;
sbit CY       = PSW^7;

/*-------------------------------------------------------------------------
  BIT Values  
  -------------------------------------------------------------------------*/

/* TMOD Bit Values */
#define T0_M0_   0x01
#define T0_M1_   0x02
#define T0_CT_   0x04
#define T0_GATE_ 0x08
#define T1_M0_   0x10
#define T1_M1_   0x20
#define T1_CT_   0x40
#define T1_GATE_ 0x80

/* CKCON Bit Values  */
#define MD_    0x07
#define T0M_   0x08
#define T1M_   0x10
#define T2M_   0x20
#define WD_    0xC0

/* EIF Bit Values  */
#define  INT2F_   0x01
#define  INT3F_   0x02
#define  INT4F_   0x04
#define  INT5F_   0x08
#define  INT6F_   0x10

#ifdef DI2CM_ENABLED
  #define  I2CMIF_  0x40
#endif
#ifdef DI2CS_ENABLED
  #define  I2CSIF_  0x80
#endif

/* T2IF Bit Values */
#ifdef TIMER2_CC_ENABLED
  #define T2_TF2_    0x01
  #define T2_EXF2_   0x02
  #define T2_EXEN2_  0x04
#endif

/* CCEN Bit Values */
#ifdef TIMER2_CC_ENABLED
  #define T2_CM0_    0x03
  #define T2_CM1_    0x0C
  #define T2_CM2_    0x30
  #define T2_CM3_    0xC0
#endif

#ifdef DSPI_ENABLED
  /* DSPI Control bits                                             */
  #define SPCR_SPIE_          0x80 /* Interrupt enable */
  #define SPCR_SPE_           0x40 /* SPI Enable */
  #define SPCR_MSTR_          0x10 /* Master(1)/Slave(0) */
  #define SPCR_CPOL_          0x08 /* Clock polarity Low(1)/High(0) */
  #define SPCR_CPHA_          0x04 /* Clock phase */
  
  #define SPCR_SPR_           0x23 /* Clock rate mask */
  #define SPR(x)              ((x&0x03)| ((x<<3)&0x20) )
  #define DIV_BY_4            0x0
  #define DIV_BY_8            0x1
  #define DIV_BY_16           0x2
  #define DIV_BY_32           0x3
  #define DIV_BY_64           0x4
  #define DIV_BY_128          0x5
  #define DIV_BY_256          0x6
  #define DIV_BY_512          0x7
  
  /* DSPI Status bits                                            */
  #define SPSR_SPIF_          0x80 /* Interrupt */
  #define SPSR_WCOL_          0x40 /* Write colision */
  #define SPSR_MODF_          0x10 /* Model fault */
  
  /* DSPI Select Codes For SSCR register                         */
  #define SEL_7               0x80
  #define SEL_6               0x40
  #define SEL_5               0x20
  #define SEL_4               0x10
  #define SEL_3               0x08
  #define SEL_2               0x04
  #define SEL_1               0x02
  #define SEL_0               0x01
#endif


#ifdef DI2CS_ENABLED
  /* DI2CS Status bits                                           */
  #define SR_TREQ                        0x02
  #define SR_RREQ                        0x01
  
/*
  DI2CS CODES written into control register I2CSCR to perfrom an action 
  Naming rules
  <actual state of DI2CS>_<next code>_<RS_value>
*/
  /* DI2CS in IDLE                                               */
  #define IDLE_START_SEND_0             0x03 /* RS=0 */
  #define IDLE_START_SEND_STOP_0        0x07 /* RS=0 */
  
  #define IDLE_START_RECEIVE_nACK_1     0x03 /* RS=1 */
  #define IDLE_START_RECEIVE_STOP_1     0x07 /* RS=1 */
  
  #define IDLE_START_RECEIVE_1          0x0B /* RS=1 */
  #define IDLE_MASTERCODE_HS_0          0x11 /* RS=0 */
  
  /* DI2CS in TRANSMIT                                           */
  #define TRANSMIT_SEND_x               0x01 /* RS=x */
  #define TRANSMIT_STOP_x               0x04 /* RS=x */
  #define TRANSMIT_SEND_STOP_x          0x05 /* RS=x */
  
  #define TRANSMIT_START_SEND_0         0x03 /* RS=0 */
  #define TRANSMIT_START_SEND_STOP_0    0x07 /* RS=0 */
  
  #define TRANSMIT_START_RECEIVE_nACK_1 0x03 /* RS=1 */
  #define TRANSMIT_START_SEND_STOP_1    0x07 /* RS=1 */
  #define TRANSMIT_START_RECEIVE_1      0x0B /* RS=1 */
  
  /* DI2CS in RECEIVE                                            */
  #define RECEIVE_RECEIVE_nACK_x        0x01 /* RS=x */
  #define RECEIVE_STOP_x                0x04 /* RS=x */
  #define RECEIVE_RECEIVE_STOP_x        0x05 /* RS=x */
  #define RECEIVE_RECEIVE_x             0x09 /* RS=x */
  
  #define RECEIVE_START_RECEIVE_nACK_1  0x03 /* RS=1 */
  #define RECEIVE_START_RECEIVE_STOP_1  0x07 /* RS=1 */
  #define RECEIVE_START_RECEIVE_1       0x0B /* RS=1 */
  
  #define RECEIVE_START_SEND_0          0x03 /* RS=0 */
  #define RECEIVE_START_SEND_STOP_0     0x07 /* RS=0 */

#endif

#ifdef DI2CM_ENABLED
  #define RS_1      0x01
  #define RS_0      0xFE
  
  /* DI2CM Status bits                                           */
  #define SR_BUS_BUSY                   0x40
  #define SR_IDLE                       0x20
  #define SR_ARB_LOST                   0x10
  #define SR_DATA_ACK                   0x08
  #define SR_ADDR_ACK                   0x04
  #define SR_ERROR                      0x02
  #define SR_BUSY                       0x01
  
/*
  DI2CM CODES written into control register I2CMCR to perfrom 
  an action. Naming rules
  <actual state of DI2CM>_<next code>_<RS_value>
*/

  /* DI2CM in IDLE state                                        */
  #define IDLE_START_SEND_0             0x03 /* RS=0 */
  #define IDLE_START_SEND_STOP_0        0x07 /* RS=0 */
  
  #define IDLE_START_RECEIVE_nACK_1     0x03 /* RS=1 */
  #define IDLE_START_RECEIVE_STOP_1     0x07 /* RS=1 */
  
  #define IDLE_START_RECEIVE_1          0x0B /* RS=1 */
  #define IDLE_MASTERCODE_HS_x          0x11 /* RS=x */
  
  /* DI2CM in TRANSMIT state                                    */
  #define TRANSMIT_SEND_x               0x01 /* RS=x */
  #define TRANSMIT_STOP_x               0x04 /* RS=x */
  #define TRANSMIT_SEND_STOP_x          0x05 /* RS=x */
  
  #define TRANSMIT_START_SEND_0         0x03 /* RS=0 */
  #define TRANSMIT_START_SEND_STOP_0    0x07 /* RS=0 */
  
  #define TRANSMIT_START_RECEIVE_nACK_1 0x03 /* RS=1 */
  #define TRANSMIT_START_SEND_STOP_1    0x07 /* RS=1 */
  #define TRANSMIT_START_RECEIVE_1      0x0B /* RS=1 */
  
  /* DI2CM in RECEIVE state                                     */
  #define RECEIVE_RECEIVE_nACK_x        0x01 /* RS=x */
  #define RECEIVE_STOP_x                0x04 /* RS=x */
  #define RECEIVE_RECEIVE_STOP_x        0x05 /* RS=x */
  #define RECEIVE_RECEIVE_x             0x09 /* RS=x */
  
  #define RECEIVE_START_RECEIVE_nACK_1  0x03 /* RS=1 */
  #define RECEIVE_START_RECEIVE_STOP_1  0x07 /* RS=1 */
  #define RECEIVE_START_RECEIVE_1       0x0B /* RS=1 */
  
  #define RECEIVE_START_SEND_0          0x03 /* RS=0 */
  #define RECEIVE_START_SEND_STOP_0     0x07 /* RS=0 */
#endif

//----------------------------------------------------
//----------------------------------------------------
  #define _nop2_()	_nop_(), _nop_()
  #define _nop3_()	_nop_(), _nop2_()
  #define _nop4_()	_nop_(), _nop3_()	
  #define _nop5_()	_nop_(), _nop4_()	
  #define _nop6_()	_nop_(), _nop5_()		
	
  #define clrwdt()	TA=0x55, TA=0xAA, WDT|=0x01;
	
  #define software_reset_system()	TA=0x55, TA=0xAA, WDT|=0x01;	
	
  #define idle()	_nop6_(), PCON=PCON|0x01, _nop6_()	
  #define sleep()	_nop6_(), PCON=PCON|0x06, _nop6_()
	#define stop()	_nop6_(), PCON=PCON|0x06, _nop6_()
  #define sleep_forever()	_nop6_(), PCON=PCON|0x02, _nop6_()
	
  #define IDLE()	_nop6_(), PCON=PCON|0x01, _nop6_()
  #define SLEEP()	_nop6_(), PCON=PCON|0x06, _nop6_()	
  #define STOP()	_nop6_(), PCON=PCON|0x06, _nop6_()
  #define STOP_FOREVER()	_nop6_(), PCON=PCON|0x02, _nop6_()
	 #define STOP_1()	_nop6_(), PCON=PCON|0x06, _nop6_()
	
	
//----------------------------------------------------
//----------------------------------------------------
 /*   interrupt vector all 23  */
 #define         INT0_VECTOR		0
 #define         TIMER0_VECTOR		1
 #define         INT1_VECTOR		2
 #define         TIMER1_VECTOR   	3
 #define         UART0_VECTOR    	4
 #define         TIMER2_VECTOR		5
 #define         UART1_VECTOR    	6
 #define         P0EI_VECTOR		7
 #define         P1EI_VECTOR		8
 #define         P2EI_VECTOR		9
 #define         P3EI_VECTOR		10
 #define         TIMER3_VECTOR		15
 #define         TIMER4_VECTOR		16
 #define         EEDATA_VECTOR		17
 #define         PWM_VECTOR		18
 #define         ADC_VECTOR   		19
 #define         WDT_VECTOR             20
 #define         I2C_VECTOR		21
 #define         SPI_VECTOR	22

//----------------------------------------------------	


#endif /*_CMS8S003XX_H_*/