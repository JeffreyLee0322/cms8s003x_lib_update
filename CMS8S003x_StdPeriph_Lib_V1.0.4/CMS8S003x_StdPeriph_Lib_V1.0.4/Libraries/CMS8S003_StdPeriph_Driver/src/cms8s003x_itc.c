/**
  ******************************************************************************
  * @file    cms8s003x_itc.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file provides all the ITC firmware functions.
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

/* Includes ------------------------------------------------------------------*/
#include "cms8s003x_itc.h"
#include "cms8s003x_spi.h"
#include "cms8s003x_tim01.h"
#include "cms8s003x_tim2.h"
#include "cms8s003x_gpio.h"
#include "cms8s003x_uart.h"
#include "cms8s003x_epwm.h"
#include "cms8s003x_iic.h"
#include "cms8s003x_wdg.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t timer0Count = 0;
uint32_t timer1Count = 0;

uint16_t readCount_TIM0 = 0, readCount_TIM1 = 0;
uint8_t IIC_SendTimes = 0;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @addtogroup ITC_Private_Functions
  * @{
  */

/**
  * @}
  */

/** @addtogroup ITC_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the ITC registers to their default reset value.
  * @param  None
  * @retval None
 */
void ITC_DeInit(void)
{

}

//unsigned int times = 0;   
void SPI_ISR() interrupt 22
{
	FlagStatus status = 0;
	ITStatus  itS = 0;
  if(SPI_GetFlagStatus(Peripheral_SPI_Interrupt)) //SPI总中断指示位  清除具体的中断标志位后 此位自动清除
	{
	  if(SPI_GetITStatus(SPI_FLAG_SPISIF))        //SPI传输完毕中断标志位 先读SPSR 再度写SPDR后清0
		{
			 /*if(times<5)
			 {
				 Master_Received[times] = SPI_ReceiveData();
				
				 if(times < 4)
					 SPI_SendData(0x40);
			 }
			 times++;*/
		}
		else if(SPI_GetITStatus(SPI_FLAG_WCOL))   //SPI 写冲突中断标志位 先读SPSR 再读写SPDR后清0
		{

		}
		else if(SPI_GetITStatus(SPI_FLAG_MODF))   //SPI模式错误中断标志 先读SPSR 再读写SPCR后清0
    {
		}
	}
}


void timer0_int (void) interrupt 1
{
	//这里不需要判断中断标志位，且中断标志位硬件自动清零
	uint32_t counter = 0;
	readCount_TIM0 = TIM0_GetCounter();
	timer0Count++;
	if(timer0Count > 100) timer0Count = 0;
	if(timer0Count%2) GPIO_WriteBit(GPIO_PORT_1, GPIO_PIN_5, 1);
	else GPIO_WriteBit(GPIO_PORT_1, GPIO_PIN_5, 0);
	//counter = TIM0_GetCounter();
}

void timer1_int (void) interrupt 3
{
	P1_5 =~ P1_5;
	//TH1 = (uint8_t)((8192 - (uint16_t)(1000000.0 / 9600 / 0.25))>>5);
	//TL1 = (uint8_t)((8192 - (uint16_t)(1000000.0 / 9600 / 0.25))&0xFF);
	/*readCount_TIM1 = TIM1_GetCounter();
	timer1Count++;
	if(timer1Count > 100) timer1Count = 0;
	if(timer1Count%2) GPIO_WriteBit(GPIO_PORT_1, GPIO_PIN_6, 1);
	else GPIO_WriteBit(GPIO_PORT_1, GPIO_PIN_6, 0);*/
}

void timer2_int (void) interrupt 5
{
	//P1_5 =~ P1_5;
	if(TIM2_GetITStatus(TIM2_Overflow_Flag))
	{
			TIM2_ClearITPendingBit(TIM2_Overflow_Flag);
	}
	
	if(TIM2_GetITStatus(TIM2_Reload_Flag))
	{
			TIM2_ClearITPendingBit(TIM2_Reload_Flag);
	}
	
	if(TIM2_GetITStatus(TIM2_OOC3_Flag))
	{
			TIM2_ClearITPendingBit(TIM2_OOC3_Flag);
	}
	
	if(TIM2_GetITStatus(TIM2_OOC2_Flag))
	{
			TIM2_ClearITPendingBit(TIM2_OOC2_Flag);
	}
	
	if(TIM2_GetITStatus(TIM2_OOC1_Flag))
	{
			TIM2_ClearITPendingBit(TIM2_OOC1_Flag);
	}
	
	if(TIM2_GetITStatus(TIM2_OOC0_Flag))
	{
			TIM2_ClearITPendingBit(TIM2_OOC0_Flag);
	}
}

void timer3_int (void) interrupt 15
{

}

void timer4_int (void) interrupt 16
{

}

void uart0_int (void) interrupt 4
{
	
	if(UART_GetITStatus(UART0, Send_IT_Status))
	{
			UART_ClearITPendingBit(UART0, Send_IT_Status);
	}
	
	if(UART_GetITStatus(UART0, Receive_IT_Status))
	{
			UART_ClearITPendingBit(UART0, Send_IT_Status);
	}
}

void uart1_int (void) interrupt 6
{
	if(UART_GetITStatus(UART1, Send_IT_Status))
	{
			UART_ClearITPendingBit(UART1, Send_IT_Status);
	}
	
	if(UART_GetITStatus(UART1, Receive_IT_Status))
	{
			UART_ClearITPendingBit(UART1, Send_IT_Status);
	}
}

void pwm_int (void) interrupt 18
{
	if(EPWM_GetPeriodITStatus(EPWM0_PeriodIT))
	{
			EPWM_ClearPeriodITStatus(EPWM0_PeriodIT);
	}
	
	if(EPWM_GetPeriodITStatus(EPWM1_PeriodIT))
	{
			EPWM_ClearPeriodITStatus(EPWM1_PeriodIT);
	}
	
	if(EPWM_GetPeriodITStatus(EPWM2_PeriodIT))
	{
			EPWM_ClearPeriodITStatus(EPWM2_PeriodIT);
	}
	
	if(EPWM_GetZeroITStatus(EPWM3_ZeroIT))
	{
			EPWM_ClearZeroITStatus(EPWM3_ZeroIT);
	}
	
	if(EPWM_GetZeroITStatus(EPWM4_ZeroIT))
	{
			EPWM_ClearZeroITStatus(EPWM4_ZeroIT);
	}
	
	if(EPWM_GetZeroITStatus(EPWM5_ZeroIT))
	{
			EPWM_ClearZeroITStatus(EPWM5_ZeroIT);
	}
}

void iic_int()	interrupt 21
{
	 if(IIC_GetITStatus(IIC_IT))  //Whether generate iic interrupt or not  
	 {
			if(_SET == IIC_GetFlagStatus(IIC_Flag_Master_IT))
			{
				IIC_SendTimes++;
				
				if(IIC_SendTimes < 5)
				{
					IIC_MasterSendData(0x55);
				}
				IIC_Stop();
			}
	 }
}

void wdg_int()  interrupt 20
{
	if(WDG_GetITStatus(WDG_Flag_Overflow))
	{
		WDG_ClearITPendingBit(WDG_Flag_Overflow);
	}
	
	if(WDG_GetITStatus(WDG_Flag_Reset))
	{
		WDG_ClearITPendingBit(WDG_Flag_Reset);
	}
}

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
