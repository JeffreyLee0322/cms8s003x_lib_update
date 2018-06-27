/**
  ******************************************************************************
  * @file    main.c
  * @author  LI WEI
  * @version V1.0.0
  * @date    04/26/2018
  * @brief   This file provides MAIN entrance.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, CMSemicon SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2018 CMSemicon</center></h2>
  */

#include <stdio.h>
#include "cms8s003x.h"
#include "cms8s003x_spi.h"
#include "cms8s003x_syscon.h"
#include "cms8s003x_gpio.h"
#include "cms8s003x_clk.h"
#include "cms8s003x_tim01.h"
#include "cms8s003x_tim2.h"
#include "cms8s003x_uart.h"
#include "cms8s003x_beep.h"
#include "cms8s003x_adc.h"
#include "cms8s003x_iic.h"
#include "cms8s003x_flash.h"
#include "cms8s003x_wdg.h"

//#define TEST_SPI
//#define TEST_GPIO
//#define TEST_TIMER01
//#define TEST_TIMER2
//#define TEST_TIMER34
//#define TEST_UART

//#define TEST_ADC
//#define TEST_IIC
//#define TEST_PWM
//#define TEST_WDG
//#define TEST_OP
//#define TEST_COMP
//#define TEST_BEEP
//#define TEST_FLASH
//#define TEST_WDG

#ifdef TEST_SPI
void SPIMaster_Config(void)
{
	SPI_Init_TypeDef SPI_InitStructure;                        			// 结构定义
	SPI_InitStructure.SPI_Mode 			= SPI_Mode_Master;              //SPI选择主机模式
	SPI_InitStructure.SPI_CPOL 			= SPI_CPOL_LOW;                 //SPI空闲模式选择高电平
	SPI_InitStructure.SPI_CPHA 			= SPI_CPHA_1Edge;               //SPI时钟极性选择0 
	SPI_InitStructure.SPI_Frequency = SPI_BaudRatePrescaler_32;     //SPI的时钟选择

	SPI_Init(&SPI_InitStructure);
	//SPI_NSSInternalSoftwareCmd(SPI_SSCR_SSO0, _ENABLE);
	
	SPI_ITConfig(SPI_Interrupt_Priority_LOW, _ENABLE);
	SPI_Cmd(_ENABLE);
	MCU_ITConfig(_ENABLE);
}

void SPI_IO_Config(void)
{
	GPIO_Init_TypeDef GPIO_InitStructure;
	
	SYS_GPIO_Alternate_Config(GPIO_NUM_P15, P15_ALT_SCLK);
	SYS_GPIO_Alternate_Config(GPIO_NUM_P16, P16_ALT_MOSI);
	SYS_GPIO_Alternate_Config(GPIO_NUM_P17, P17_ALT_MISO);
	
	GPIO_InitStructure.Mode 			= GPIO_ALT;
	GPIO_InitStructure.Direction 	= GPIO_OUTPUT;
	GPIO_InitStructure.Analog		 	= GPIO_Digital_Sel;
	GPIO_InitStructure.OType 			= GPIO_Pushpull_Sel;
	GPIO_InitStructure.Up 				= GPIO_Up_Disable;
	GPIO_InitStructure.Down 			= GPIO_Down_Disable;
	GPIO_InitStructure.Driver 		= GPIO_Driver_Weak;
	GPIO_InitStructure.Slope 			= GPIO_Slope_Slow;
	GPIO_InitStructure.Pin 				= GPIO_PIN_5;
	GPIO_Init(GPIO_PORT_1, &GPIO_InitStructure);
	
	GPIO_InitStructure.Mode 			= GPIO_ALT;
	GPIO_InitStructure.Direction 	= GPIO_INPUT;
	GPIO_InitStructure.Analog 		= GPIO_Digital_Sel;
	GPIO_InitStructure.Up 				= GPIO_Up_Enable;
	GPIO_InitStructure.Pin 				= GPIO_PIN_7;
	GPIO_Init(GPIO_PORT_1, &GPIO_InitStructure);
}
#endif

//#ifdef TEST_GPIO
void test_gpio_init(void)
{
	GPIO_Init_TypeDef GPIO_InitStructure;
	GPIO_InitStructure.Mode 			= GPIO_PIN;
	GPIO_InitStructure.Direction 	= GPIO_OUTPUT;
	GPIO_InitStructure.Analog 		= GPIO_Digital_Sel;
	GPIO_InitStructure.OType 			= GPIO_Pushpull_Sel;
	GPIO_InitStructure.Up 				= GPIO_Up_Enable;
	GPIO_InitStructure.Down 			= GPIO_Down_Enable;
	GPIO_InitStructure.Driver 		= GPIO_Driver_Weak;
	GPIO_InitStructure.Slope 			= GPIO_Slope_Slow;
	GPIO_InitStructure.Pin 				= GPIO_PIN_5;
	GPIO_Init(GPIO_PORT_1, &GPIO_InitStructure);
	
	GPIO_InitStructure.Pin 				= GPIO_PIN_6;
	GPIO_Init(GPIO_PORT_1, &GPIO_InitStructure);
}
//#endif

#ifdef TEST_TIMER01
void test_sysClock_init(void)
{
	//CLK_SYSCLKDivConfig(8);//sys clk is 8/4=2MHz
}

void test_timer01_init(void)
{
	TIM01_Init_TypeDef TIM0_InitStructure, TIM1_InitStructure;
	
	TIM0_InitStructure.Timer_Function 		= TIM01_Function_Timer;
	TIM0_InitStructure.Timer_Mode 				= TIM01_Mode2_8Bit_AutoLoad_Timer_Counter;
	TIM0_InitStructure.Timer_Clock 				= TIM01_SYSCLK_Prescaler_4;
	TIM0_InitStructure.Timer_InitValue 		= 100;
	//TIM0_Init(&TIM0_InitStructure);
	
	TIM1_InitStructure.Timer_Function 		= TIM01_Function_Timer;
	//TIM1_InitStructure.Timer_Mode 				= TIM01_Mode0_13Bit_Timer_Counter;
	//TIM1_InitStructure.Timer_Clock 				= TIM01_SYSCLK_Prescaler_4;//timer frequency is 16/4 MHz = 4MHz --> T=0.25us
	//TIM1_InitStructure.Timer_InitValue 		= 8192 - (uint16_t)(1000000.0 / 9600 / 0.25);
	TIM1_InitStructure.Timer_Mode 				= TIM01_Mode2_8Bit_AutoLoad_Timer_Counter;
	TIM1_InitStructure.Timer_Clock 				= TIM01_SYSCLK_Prescaler_12;//timer frequency is 16/12 MHz --> T=0.75us//T=12/24=0.5us
	TIM1_InitStructure.Timer_InitValue 		= 100;//256 - (uint8_t)(1000000.0 / 9600 / 0.75);
	
	TIM1_Init(&TIM1_InitStructure);
	
	//TIM0_ITConfig(TIM01_HIGH_Priority, _ENABLE);
	TIM1_ITConfig(TIM01_LOW_Priority, _ENABLE);
	
	//TIM0_Cmd(_ENABLE);
	TIM1_Cmd(_ENABLE);
	
	MCU_ITConfig(_ENABLE);
}
#endif

#ifdef TEST_TIMER2
void test_timer2_init(void)
{
	GPIO_Init_TypeDef GPIO_InitStructure;
	TIM2_Init_TypeDef TIM2_InitStructure;
	TIM2_OC_Init_TypeDef TIM2_OC_InitStructure;
	TIM2_IC_Init_TypeDef TIM2_IC_InitStructure;
	
	TIM2_InitStructure.Clock_Source 		= TIM2_SysClock_Prescaler;  	 //Timer2的时钟输入选择：系统时钟的分频
	TIM2_InitStructure.Clock_Prescaler 	= TIM2_SysClock_Prescaler_12;  //Timer2时钟预分频选择
	TIM2_InitStructure.Reload_Mode 			= TIM2_Overflow_Auto_Reload;   //Timer2加载模式选择
	TIM2_InitStructure.Init_Value 			= 0;                         		//Timer2 数据寄存器初始值
	
	TIM2_DeInit();
	TIM2_TimeBaseInit(&TIM2_InitStructure);
	
	//Output Compare IO setup
	SYS_GPIO_Alternate_Config(GPIO_NUM_P24, P24_ALT_CC1);
	
	GPIO_InitStructure.Mode 			= GPIO_ALT;
	GPIO_InitStructure.Pin 				= GPIO_PIN_4;
	GPIO_InitStructure.Direction 	= GPIO_OUTPUT;
	GPIO_InitStructure.Analog 		= GPIO_Digital_Sel;
	GPIO_InitStructure.OType 			= GPIO_Pushpull_Sel;
	GPIO_InitStructure.Up 				= GPIO_Up_Enable;
	GPIO_InitStructure.Down 			= GPIO_Down_Enable;
	GPIO_InitStructure.Driver 		= GPIO_Driver_Weak;
	GPIO_InitStructure.Slope 			= GPIO_Slope_Slow;
	GPIO_Init(GPIO_PORT_2, &GPIO_InitStructure);
	
	//Output Compare Register setup
	/*TIM2_OC_InitStructure.OC_Channel			= TIM2_OC_Channel_1;
	TIM2_OC_InitStructure.OC_INT_Edge   	= TIM2_OC_Falling_Edge_INT;
	TIM2_OC_InitStructure.OC_Mode       	= TIM2_OC_Mode_0;
	TIM2_OC_InitStructure.OC_CMLx					= TIM2_OC_CML1_Enable;
	TIM2_OC_InitStructure.OC_Init_Value		= 0x8000;
	
	TIM2_OCInit(&TIM2_OC_InitStructure);*/

	TIM2_IC_InitStructure.IC_Channel      = TIM2_IC_Channel_0;
	TIM2_IC_InitStructure.IC_INT_Edge     = TIM2_IC_Falling_Edge_INT;
	TIM2_IC_InitStructure.IC_Select      	= TIM2_IC_Channel0_IC0;
	
	TIM2_ICInit(&TIM2_IC_InitStructure);
	
	//Tim2 timer/oc/ic setup
	//TIM2_ITConfig(TIM2_Overflow_IT_Enable | TIM2_All_IT_Enable, TIM2_LOW_Priority, _ENABLE);
	TIM2_ITConfig(TIM2_Overflow_IT_Enable | TIM2_OOC1_IT_Enable | TIM2_All_IT_Enable, TIM2_HIGH_Priority, _ENABLE);
	MCU_ITConfig(_ENABLE);
}
#endif

#ifdef TEST_UART
void test_uart_init()
{
	GPIO_Init_TypeDef GPIO_InitStructure;
	UART_Init_TypeDef UART_InitStructure;
	
	//Uart0 IO setup
	SYS_GPIO_Alternate_Config(GPIO_NUM_P25, P25_ALT_TXD0);
	//SYS_GPIO_Alternate_Config(GPIO_NUM_P26, P26_ALT_RXD0);
	
	GPIO_InitStructure.Mode 			= GPIO_ALT;
	GPIO_InitStructure.Pin 				= GPIO_PIN_5;
	GPIO_InitStructure.Direction 	= GPIO_OUTPUT;
	GPIO_InitStructure.Analog 		= GPIO_Digital_Sel;
	GPIO_InitStructure.OType 			= GPIO_Pushpull_Sel;
	GPIO_InitStructure.Up 				= GPIO_Up_Enable;
	GPIO_InitStructure.Down 			= GPIO_Down_Enable;
	GPIO_InitStructure.Driver 		= GPIO_Driver_Weak;
	GPIO_InitStructure.Slope 			= GPIO_Slope_Slow;
	GPIO_Init(GPIO_PORT_2, &GPIO_InitStructure);
	
	UART_InitStructure.Mode 							= Mode_8Bit_Unsettled_Freq; 
	UART_InitStructure.MutiDevices 				= _DISABLE;
	UART_InitStructure.IsReceive 					= _DISABLE;
	UART_InitStructure.SendData9Bit 			= Data_9Bit_Is1;
	UART_InitStructure.ReceiveData9Bit 		= Data_9Bit_Is1;
	UART_InitStructure.UartBaudrateDouble = Baudrate_Double;
	UART_InitStructure.UartClkSource 			= Timer1_Select;//Timer_SysClk_Select;
	UART_InitStructure.UartBaurdrate 			= 9600;
	
	UART_Init(UART0, &UART_InitStructure);
	
	//UART_ITConfig(UART0, HIGH_Priority, _ENABLE);
	
	//UART_SendData8(UART0, 0x12);
	//printf("<<----UART0 test---->>");
}
#endif

#ifdef TEST_BEEP
void test_beep_init(void)
{
	GPIO_Init_TypeDef GPIO_InitStructure;
	BEEP_Init_TypeDef BEEP_InitStructure;
	
	SYS_GPIO_Alternate_Config(GPIO_NUM_P24, P24_ALT_BEEP);
	
	GPIO_InitStructure.Mode 			= GPIO_ALT;
	GPIO_InitStructure.Direction 	= GPIO_OUTPUT;
	GPIO_InitStructure.Analog		 	= GPIO_Digital_Sel;
	GPIO_InitStructure.OType 			= GPIO_Pushpull_Sel;
	GPIO_InitStructure.Up 				= GPIO_Up_Disable;
	GPIO_InitStructure.Down 			= GPIO_Down_Disable;
	GPIO_InitStructure.Driver 		= GPIO_Driver_Weak;
	GPIO_InitStructure.Slope 			= GPIO_Slope_Fast;
	GPIO_InitStructure.Pin 				= GPIO_PIN_4;
	GPIO_Init(GPIO_PORT_2, &GPIO_InitStructure);
	
	BEEP_InitStructure.BEEP_Prescaler1 = BEEP_SysClk_Prescaler_8;
	BEEP_InitStructure.BEEP_Prescaler2 = 100;
	
	BEEP_Init(&BEEP_InitStructure); //BEEP Fre = SystemClock/2*BEEP_Prescaler1/BEEP_Prescaler2
	BEEP_Cmd(_ENABLE);
}
#endif

#ifdef TEST_ADC
void test_adc_init(void)
{
	GPIO_Init_TypeDef GPIO_InitStructure;
	ADC_Init_TypeDef ADC_InitStructure;
	ADC_ExtTrigConfig_TypeDef ADC_ExtTrigConfigStructure;  
	
	SYS_GPIO_Alternate_Config(GPIO_NUM_P00, P00_ALT_AN0);
	//SYS_GPIO_Alternate_Config(GPIO_NUM_P04, P04_ALT_ADET1);
	
	GPIO_InitStructure.Mode 			= GPIO_ALT;
	GPIO_InitStructure.Direction 	= GPIO_INPUT;
	GPIO_InitStructure.Analog		 	= GPIO_Analog_Sel;
	GPIO_InitStructure.Pin 				= GPIO_PIN_0;
	GPIO_Init(GPIO_PORT_0, &GPIO_InitStructure);
	
	GPIO_InitStructure.Mode 			= GPIO_PIN;
	GPIO_InitStructure.Direction 	= GPIO_INPUT;
	GPIO_InitStructure.Analog		 	= GPIO_Digital_Sel;
	GPIO_InitStructure.Up 				= GPIO_Up_Enable;
	GPIO_InitStructure.Down 			= GPIO_Down_Disable;
	GPIO_InitStructure.Pin 				= GPIO_PIN_4; //Config P04 as ADET1
	GPIO_Init(GPIO_PORT_0, &GPIO_InitStructure);
	
	//ADC config
	ADC_InitStructure.Prescaler   	= ADC_Prescaler_2;
	ADC_InitStructure.Channel     	= ADC_Channel_0;
	ADC_InitStructure.ResultFormat 	= ADC_Format_Left_Align;
	ADC_InitStructure.Brake       	= _DISABLE;
	ADC_InitStructure.CompOut     	= ADC_CompOut_MoreThanComp;
	ADC_InitStructure.CompValue   	= 0xffff;
	
	ADC_Init(&ADC_InitStructure);
	
	//ADC Ext trigger config
	ADC_ExtTrigConfigStructure.ExtTrigEvent   = ADC_ExtEventSelection_ADCET;
	ADC_ExtTrigConfigStructure.ExtTrigEdge    = ADC_ExtEdgeSelection_Falling;
	ADC_ExtTrigConfigStructure.ExtTrigPort    = ADC_ExtPortSelection_ADCET0;
	ADC_ExtTrigConfigStructure.ExtTrigDelay   = 0x0f; //10bit valid
	
	ADC_ExternalTrigConfig(&ADC_ExtTrigConfigStructure);
	
	//ADC Start/ ADC Ext trigger disable
	ADC_ExtTrig_Cmd(_DISABLE);
	ADC_Cmd(_ENABLE);
}
#endif

#ifdef TEST_IIC
void test_iic_init()
{
	uint8_t times = 0;
	GPIO_Init_TypeDef GPIO_InitStructure;
	IIC_Init_TypeDef IIC_InitStructure;
	
	IIC_InitStructure.IIC_Mode = IIC_Mode_Master;
	IIC_InitStructure.IIC_Frequency = 0x05;
	IIC_InitStructure.IIC_HighSpeed = IIC_HighSpeed_Disable;
	IIC_InitStructure.IIC_SlaveAddress = 0;
	IIC_InitStructure.IIC_Direction = IIC_Direction_Transmitter;
	IIC_InitStructure.IIC_ACK = IIC_Ack_Disable;
	
	/*IIC_InitStructure.IIC_Mode = IIC_Mode_Slave;
	IIC_InitStructure.IIC_OwnAddress = 0;
	IIC_InitStructure.IIC_Reset = IIC_Reset;*/
	
	IIC_Init(&IIC_InitStructure);
	//IIC_ITConfig(IIC_Priority_High, _ENABLE);
	//MCU_ITConfig(_ENABLE);
	
	IIC_Start();
}
#endif

void Delay_Time(int time)
{
	while(time> 0)
	{
		time--;
	}
}

void main(void)
{
	int Uart_Test_Count = 0x00;
#ifdef TEST_SPI
	SPI_IO_Config();
	SPIMaster_Config();
  while(1)
	{
		SPI_SendData(0x42);
		Delay_Time(100);
	}
#endif

#ifdef TEST_GPIO
		test_gpio_init();
		//GPIO_Write(GPIO_PORT_1, 0x20);
#endif

#ifdef TEST_TIMER01
	test_sysClock_init();
	test_gpio_init();
	GPIO_Write(GPIO_PORT_1, 0);
	test_timer01_init();
#endif
	
#ifdef TEST_TIMER2
	test_gpio_init();
	GPIO_Write(GPIO_PORT_1, 0);
	test_timer2_init();
#endif
	
#ifdef TEST_UART
	test_gpio_init();
	test_uart_init();
	while(1)
	{
		//Delay_Time(2000);
		UART_SendData8(UART0, 0xa5);
		//Uart_Test_Count++;
		//if(Uart_Test_Count > 100) Uart_Test_Count = 0;
	}
#endif
	
#ifdef TEST_BEEP
	test_beep_init();
#endif
	
#ifdef TEST_ADC
	test_adc_init();
#endif
	
#ifdef TEST_IIC
	test_iic_init();
	while(1)
	{
		
	}
#endif

	while(1);
}





