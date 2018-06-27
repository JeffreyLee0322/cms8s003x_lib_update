#ifndef _CMS8S003X_H
#define _CMS8S003X_H
#include "cms8s003x.h"
#include "cms8s003x_conf.h"

//P00
#define P00_ALT_INT0    (uint8_t)0x00 //GPIO
#define P00_ALT_AN0     (uint8_t)0x01
#define P00_ALT_PG0     (uint8_t)0x05

//P01
#define P01_ALT_INT1    (uint8_t)0x00 //GPIO
#define P01_ALT_AN1     (uint8_t)0x01
#define P01_ALT_PG1     (uint8_t)0x05

//P02
#define P02_ALT_AN2     (uint8_t)0x01
#define P02_ALT_PG2     (uint8_t)0x05

//P03
#define P03_ALT_T2EX     (uint8_t)0x00//GPIO
#define P03_ALT_AN3      (uint8_t)0x01

//P04
#define P04_ALT_ADET1    (uint8_t)0x00 //GPIO
#define P04_ALT_AN4      (uint8_t)0x01
#define P04_ALT_SCL      (uint8_t)0x03

//P05
#define P05_ALT_FB1    	 (uint8_t)0x00 //GPIO
#define P05_ALT_AN5      (uint8_t)0x01
#define P05_ALT_SDA      (uint8_t)0x03
#define P05_ALT_PG1      (uint8_t)0x06

//P06
#define P06_ALT_NSS2     (uint8_t)0x04

//P07
#define P07_ALT_NSS1     (uint8_t)0x04

//P10
#define P10_ALT_NSS0     (uint8_t)0x04

//P11
#define P11_ALT_PG3      (uint8_t)0x05

//P12
#define P12_ALT_PG4      (uint8_t)0x05

//P13
#define P13_ALT_IC0    	 (uint8_t)0x00 //GPIO
#define P13_ALT_AN6      (uint8_t)0x01
#define P13_ALT_PG5      (uint8_t)0x05
#define P13_ALT_PG0      (uint8_t)0x06

//P14
#define P14_ALT_IC1    	 (uint8_t)0x00 //GPIO
#define P14_ALT_AN7      (uint8_t)0x01
#define P14_ALT_NSS3     (uint8_t)0x04
#define P14_ALT_CLO      (uint8_t)0x05
#define P14_ALT_PG1      (uint8_t)0x06

//P15
#define P15_ALT_IC2    	 (uint8_t)0x00 //GPIO
#define P15_ALT_SCLK     (uint8_t)0x04
#define P15_ALT_PG2      (uint8_t)0x06

//P16
#define P16_ALT_IC3_T1   (uint8_t)0x00 //GPIO
#define P16_ALT_MOSI     (uint8_t)0x04
#define P16_ALT_PG3      (uint8_t)0x06

//P17
#define P17_ALT_IC4      (uint8_t)0x00 //GPIO
#define P17_ALT_MISO     (uint8_t)0x04
#define P17_ALT_PG4      (uint8_t)0x06

//P20
#define P20_ALT_FB0      (uint8_t)0x00 //GPIO
#define P20_ALT_AN8      (uint8_t)0x01
#define P20_ALT_NSS4     (uint8_t)0x04
#define P20_ALT_CLO      (uint8_t)0x05

//P21
#define P21_ALT_AN9      (uint8_t)0x01
#define P21_ALT_RXD1     (uint8_t)0x02
#define P21_ALT_SCL      (uint8_t)0x03
#define P21_ALT_NSS5     (uint8_t)0x04

//P22
#define P22_ALT_IC5      (uint8_t)0x00 //GPIO
#define P22_ALT_AN10     (uint8_t)0x01
#define P22_ALT_CC3      (uint8_t)0x03
#define P22_ALT_NSS6     (uint8_t)0x04
#define P22_ALT_PG5      (uint8_t)0x06

//P23
#define P23_ALT_IC8_ADET0   (uint8_t)0x00 //GPIO
#define P23_ALT_AN11     		(uint8_t)0x01
#define P23_ALT_CC2      		(uint8_t)0x03
#define P23_ALT_PG3     		(uint8_t)0x06

//P24
#define P24_ALT_IC6_T0   (uint8_t)0x00 //GPIO
#define P24_ALT_AN12     (uint8_t)0x01
#define P24_ALT_CC1      (uint8_t)0x03
#define P24_ALT_BEEP     (uint8_t)0x05
#define P24_ALT_PG2      (uint8_t)0x06

//P25
#define P25_ALT_AN13     (uint8_t)0x01 
#define P25_ALT_TXD0     (uint8_t)0x02

//P26
#define P26_ALT_AN14     (uint8_t)0x01 
#define P26_ALT_RXD0     (uint8_t)0x02

//P27
#define P27_ALT_T2       (uint8_t)0x00 //GPIO
#define P27_ALT_NSS0     (uint8_t)0x04

//P30
//NRST

//P31
//XIN
#define P31_ALT_T0G       (uint8_t)0x00 //GPIO

//P32
//XOUT
#define P32_ALT_T1G       (uint8_t)0x00 //GPIO

//P35
//DSDA
#define P35_ALT_TXD1      (uint8_t)0x02
#define P35_ALT_SDA       (uint8_t)0x03

//P36
#define P36_ALT_IC7      (uint8_t)0x00
#define P36_ALT_CC0      (uint8_t)0x03
#define P36_ALT_NSS7     (uint8_t)0x04
#define P36_ALT_PG5      (uint8_t)0x06

typedef enum
{
	GPIO_NUM_P00 = 0,
	GPIO_NUM_P01 = 1,
	GPIO_NUM_P02 = 2,
	GPIO_NUM_P03 = 3,
	GPIO_NUM_P04 = 4,
	GPIO_NUM_P05 = 5,
	GPIO_NUM_P06 = 6,
	GPIO_NUM_P07 = 7,
	GPIO_NUM_P10 = 10,
	GPIO_NUM_P11 = 11,
	GPIO_NUM_P12 = 12,
	GPIO_NUM_P13 = 13,
	GPIO_NUM_P14 = 14,
	GPIO_NUM_P15 = 15,
	GPIO_NUM_P16 = 16,
	GPIO_NUM_P17 = 17,
	GPIO_NUM_P20 = 20,
	GPIO_NUM_P21 = 21,
	GPIO_NUM_P22 = 22,
	GPIO_NUM_P23 = 23,
	GPIO_NUM_P24 = 24,
	GPIO_NUM_P25 = 25,
	GPIO_NUM_P26 = 26,
	GPIO_NUM_P27 = 27,
	GPIO_NUM_P30 = 30,
	GPIO_NUM_P31 = 31,
	GPIO_NUM_P32 = 32,
	GPIO_NUM_P33 = 33,
	GPIO_NUM_P34 = 34,
	GPIO_NUM_P35 = 35,
	GPIO_NUM_P36 = 36,
	GPIO_NUM_P37 = 37,
}GPIO_NUM;

void SYS_GPIO_Alternate_Config(GPIO_NUM num, uint8_t gpio_alt_func);
void MCU_ITConfig(FunctionalState NewState);
void MCU_SoftwareReset(void);
uint8_t MCU_GetResetFlag(void);//Power on reset flag
#endif

