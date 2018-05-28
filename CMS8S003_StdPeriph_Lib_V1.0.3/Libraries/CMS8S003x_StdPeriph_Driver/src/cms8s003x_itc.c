/**
  ******************************************************************************
  * @file    cms8s003x_itc.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2010
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
#include "cms8s003x_gpio.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t timer0Count = 0;
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
	uint32_t counter = 0;
	if(TIM0_GetITStatus())
	{
		timer0Count++;
		if(timer0Count > 100) timer0Count = 0;
		if(timer0Count%2) GPIO_Write(GPIO_PORT_1, 0xff);
		else GPIO_Write(GPIO_PORT_1, 0);
		//counter = TIM0_GetCounter();
	}
	TIM0_ClearITPendingBit();
}



/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
