/**
  ******************************************************************************
  * @file    cms8s003x_beep.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file provides all the BEEP firmware functions.
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
#include "cms8s003x_beep.h"

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

/**
  * @addtogroup BEEP_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the BEEP peripheral registers to their default
  *         reset values.
  * @param  None
  * @retval None
  */
void BEEP_DeInit(void)
{
	BUZCON &= 0x00;
	BUZDIV &= 0x00;
}

/**
  * @brief  Initializes the BEEP function according to the specified parameters.
  * @param  BEEP_Init BEEP initial.
  *         This parameter can be one of the values of @ref BEEP_Init_TypeDef.
	* @retval None
  */
void BEEP_Init(BEEP_Init_TypeDef *BEEP_Init)
{
	BUZCON &= 0x00;
	BUZCON |= (uint8_t)BEEP_Init->BEEP_Prescaler1;
	
	BUZDIV &= 0x00;
	BUZDIV |= (uint8_t)BEEP_Init->BEEP_Prescaler2;
}

/**
  * @brief  Enable or disable the BEEP function.
  * @param  NewState Indicates the new state of the BEEP function.
  * @retval None
  */
void BEEP_Cmd(FunctionalState NewState)
{
	
  if (NewState != _DISABLE)
  {
    /* Enable the BEEP peripheral */
    BUZCON |= BEEP_ENABLE;
  }
  else
  {
    /* Disable the BEEP peripheral */
    BUZCON &= (uint8_t)(~BEEP_ENABLE);
  }
}


/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
