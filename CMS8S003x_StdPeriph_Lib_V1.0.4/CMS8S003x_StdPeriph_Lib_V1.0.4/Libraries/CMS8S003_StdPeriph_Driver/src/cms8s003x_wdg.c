/**
  ********************************************************************************
  * @file    cms8s003x_wdg.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file provides all the WDG firmware functions.
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
#include "cms8s003x_wdg.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

/** @addtogroup WDG_Public_Functions
  * @{
  */

/**
  * @brief  Initializes the WWDG peripheral.
  *         This function set Window Register = WindowValue, Counter Register
  *         according to Counter and \b ENABLE \b WWDG
  * @param  Counter : WWDG counter value
  * @param  WindowValue : specifies the WWDG Window Register, range is 0x00 to 0x7F.
  * @retval None
  */
void WDG_Init(WDG_Init_TypeDef *WDG_Init)
{
	WDCON = (uint8_t)WDG_Init->WDG_Clear;
	CKCON |= (uint8_t)WDG_Init->WDG_OverflowTime;
}

/**
  * @brief  Enables WWDG and load the counter value.
  * @param  Counter: specifies the watchdog counter value.
  *         This parameter must be a number between 0x40 and 0x7F.
  * @retval None
  */
void WDG_Enable(void)
{
	WDCON |= WDG_RESET_ENABLE_BIT;
}

/**
  * @brief  Enables WWDG and load the counter value.
  * @param  Counter: specifies the watchdog counter value.
  *         This parameter must be a number between 0x40 and 0x7F.
  * @retval None
  */
void WDG_Disable(void)
{
	WDCON &= ~WDG_RESET_ENABLE_BIT;
}

/**
  * @brief Gets the WWDG Counter Value.
  *        This value could be used to check if WWDG is in the window, where
  *        refresh is allowed.
  * @param  None
  * @retval WWDG Counter Value
  */
uint8_t WDG_GetCounter(void)
{
	return 0;
}

ITStatus WDG_GetITStatus(WDG_Flag_TypeDef WDG_Flag)
{
  ITStatus bitstatus = _RESET;
	
	if ((WDCON & WDG_Flag) != (uint8_t)_RESET )
  {
    bitstatus = _SET;
  }
  else
  {
    bitstatus = _RESET;
  }

  /* Return the USART_IT status*/
  return  bitstatus;
}

void WDG_ClearITPendingBit(WDG_Flag_TypeDef WDG_Flag)
{
	WDCON &= (uint8_t)(~WDG_Flag);
}

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
