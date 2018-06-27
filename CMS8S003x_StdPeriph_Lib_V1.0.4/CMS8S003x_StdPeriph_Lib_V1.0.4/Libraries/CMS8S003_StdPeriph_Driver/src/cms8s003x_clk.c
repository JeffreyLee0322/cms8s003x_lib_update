/**
  ******************************************************************************
  * @file    cms8s003x_clk.c
  * @author  LI WEI
  * @version V1.0.0
  * @date    04/24/2018
  * @brief   This file provides all the CLK firmware functions.
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

#include "cms8s003x_clk.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private Variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @addtogroup CLK_Private_Constants
  * @{
  */
#define HSI_CLOCK_FREQUENCY_8MHZ    8000000
#define HSI_CLOCK_FREQUENCY_16MHZ   16000000
#define HSI_CLOCK_FREQUENCY_24MHZ   24000000

uint32_t SystemClock = HSI_CLOCK_FREQUENCY_24MHZ;
/**
  * @}
  */

/**
  * @addtogroup CLK_Public_Functions
  * @{
  */

/**
  * @brief  System Clock frequency prescaler.
  * @param  Prescaler: Must ble even number(2,4, ~, 510).
  * @retval None
  */
void CLK_SYSCLKDivConfig(uint16_t Prescaler)
{
  uint16_t CLKDIV_Value = 0;
	if(0 != Prescaler%2)
	{
			while(1);
	}
	CLKDIV_Value = Prescaler/2;
	
	CLKDIV = (uint8_t)CLKDIV_Value;
	SystemClock = HSI_CLOCK_FREQUENCY_16MHZ / Prescaler;
}

/**
  * @brief  Get system clock frequency.
  * @param  None
  * @retval None
  */
uint32_t getSystemClock(void)
{
		return SystemClock;
}
/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
