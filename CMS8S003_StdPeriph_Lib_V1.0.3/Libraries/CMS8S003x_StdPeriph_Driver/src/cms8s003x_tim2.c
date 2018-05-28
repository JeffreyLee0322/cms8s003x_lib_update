/**
  ******************************************************************************
  * @file    cms8s003x_tim2.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file provides all the TIM1 firmware functions.
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
#include "cms8s003x_tim2.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/**
  * @addtogroup TIM2_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the TIM0 peripheral registers to their default reset values.
  * @param  None
  * @retval None
  */
void TIM2_DeInit(void)
{
	T2CON &= 0x00; /* clear T2 control register reset value */
}

void TIM2_TimeBaseInit(TIM2_Init_TypeDef* TIM2_InitDef)
{
	T2CON &= 0x00; 
	T2CON = (uint8_t)(TIM2_InitDef->Clock_Source) | (uint8_t)((TIM2_InitDef->Clock_Prescaler) << 7) | (uint8_t)((TIM2_InitDef->Reload_Mode) >> 3);
	
	TH2 = ((TIM2_InitDef->Init_Value) >> 8)&0xFF;
	TL2 = (TIM2_InitDef->Init_Value)&0xFF;
}

void TIM2_Cmd(FunctionalState NewState)
{

}

void TIM2_ITConfig(TIM2_IT_Mask_TypeDef TIM2_Mask, TIM2_PRIORITY_TypeDef TIM2_Priority, FunctionalState NewState)
{
	/*Set Timer2*/
	IE &= ~0x20;
	IE |= TIM2_Mask;
	
	
}

FlagStatus TIM2_GetFlagStatus(TIM2_FLAG_TypeDef TIM2_FLAG)
{

}

void TIM2_ClearFlag(TIM2_FLAG_TypeDef TIM2_FLAG)
{

}

ITStatus TIM2_GetITStatus(TIM2_IT_FLAG_TypeDef TIM2_IT)
{

}

void TIM2_ClearITPendingBit(TIM2_IT_FLAG_TypeDef TIM2_IT)
{

}

/**
  * @}
  */

/**
  * @}
  */

/************************************ (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
