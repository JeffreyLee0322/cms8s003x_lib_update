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
uint32_t SystemClock = 0;
#define HSI_CLOCK_FREQUENCY 16000000
const uint8_t SYSDivFactor[5] =
  {
    1, 2, 4, 8, 16
  }
  ; /*!< Holds the different Master clock Divider factors */

/**
  * @}
  */

/**
  * @addtogroup CLK_Public_Functions
  * @{
  */

/**
  * @brief  Initializes the Systerm CLK registers to their values.
  * @param  Prescaler: Must ble even number.
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
	SystemClock = HSI_CLOCK_FREQUENCY / Prescaler;
}

/**
  * @brief  Deinitializes the CLK peripheral registers to their default reset values.
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
