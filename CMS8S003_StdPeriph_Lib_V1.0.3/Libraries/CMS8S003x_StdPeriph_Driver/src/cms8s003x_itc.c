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

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
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
  if(SPI_GetFlagStatus(Peripheral_SPI_Interrupt)) //SPI���ж�ָʾλ  ���������жϱ�־λ�� ��λ�Զ����
	{
	  if(SPI_GetITStatus(SPI_FLAG_SPISIF))        //SPI��������жϱ�־λ �ȶ�SPSR �ٶ�дSPDR����0
		{
			 /*if(times<5)
			 {
				 Master_Received[times] = SPI_ReceiveData();
				
				 if(times < 4)
					 SPI_SendData(0x40);
			 }
			 times++;*/
		}
		else if(SPI_GetITStatus(SPI_FLAG_WCOL))   //SPI д��ͻ�жϱ�־λ �ȶ�SPSR �ٶ�дSPDR����0
		{

		}
		else if(SPI_GetITStatus(SPI_FLAG_MODF))   //SPIģʽ�����жϱ�־ �ȶ�SPSR �ٶ�дSPCR����0
    {
		}
	}
}


void timer0_int (void) interrupt 1
{
	uint32_t counter = 0;
	if(TIM0_GetITStatus())
	{
		counter = TIM0_GetCounter();
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