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
  * @brief  Deinitializes the TIM2 peripheral registers to their default reset values.
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

void TIM2_OCInit(TIM2_OC_Init_TypeDef TIM2_OCTpye)
{
	/* Clear and Set TIM2 OC T2CON bit */
	T2CON &= ~0x44;
	T2CON |= (((uint8_t)(TIM2_OCTpye->OC_Mode << 2)) | ((uint8_t)(TIM2_OCTpye->OC_INT_Edge << 6)));

	switch((uint8_t)(TIM2_OCTpye->OC_Channel))
	{
		case TIM2_OC_Channel_0:
				RLDL = (uint8_t)(TIM2_OCTpye->OC_Init_Value);
				RLDH = (uint8_t)(TIM2_OCTpye->OC_Init_Value >> 8);
				break;
		case TIM2_OC_Channel_1:
				CCL1 = (uint8_t)(TIM2_OCTpye->OC_Init_Value);
				CCH1 = (uint8_t)(TIM2_OCTpye->OC_Init_Value >> 8);
				break;
		case TIM2_OC_Channel_2:
				CCL2 = (uint8_t)(TIM2_OCTpye->OC_Init_Value);
				CCH2 = (uint8_t)(TIM2_OCTpye->OC_Init_Value >> 8);
				break;
		case TIM2_OC_Channel_3:
				CCL3 = (uint8_t)(TIM2_OCTpye->OC_Init_Value);
				CCH3 = (uint8_t)(TIM2_OCTpye->OC_Init_Value >> 8);
				break;
		default: break;
	}
}

void TIM2_ICInit(TIM2_IC_Init_TypeDef TIM2_ICTpye)
{
	/* Clear and Set T2CON IC bits */
	T2CON &= ~0x40;
	T2CON |= (uint8_t)(TIM2_ICTpye->IC_INT_Edge);
	
	switch((uint8_t)(TIM2_ICTpye->IC_Channel))
	{
		case TIM2_IC_Channel_0:
				CAPCR0 &= 0xF0;
				CAPCR0 |= ((uint8_t)(TIM2_ICTpye->IC_Select));
				break;
		case TIM2_IC_Channel_1:
				CAPCR0 &= 0x0F;
				CAPCR0 |= ((uint8_t)(TIM2_ICTpye->IC_Select));
				break;
		case TIM2_IC_Channel_2:
				CAPCR1 &= 0xF0;
				CAPCR1 |= ((uint8_t)(TIM2_ICTpye->IC_Select));
				break;
		case TIM2_IC_Channel_3:
				CAPCR1 &= 0x0F;
				CAPCR1 |= ((uint8_t)(TIM2_ICTpye->IC_Select));
				break;
		default: break;
	}
}

void TIM2_Cmd(FunctionalState NewState)
{

}

void TIM2_ITConfig(TIM2_IT_Mask_TypeDef TIM2_Mask, TIM2_PRIORITY_TypeDef TIM2_Priority, FunctionalState NewState)
{
	/* Clear Timer2 All interrupt bit5 */
	IE &= ~0x20;
	
	/* Clear and Set Timer2 IP bit5 */
	IP &= ~0x40;
	IP |= TIM2_Priority;
	
	/* Clear and Set Timer2 T2IE */
	T2IE &= 0;
	T2IE |= TIM2_Mask;
	
	/* Set Timer2 All interrupt bit5 */
	if (NewState != _DISABLE)
	{
			IE |= TIM2_All_IT_Enable;
	}
	else
	{
			IE |= ~TIM2_All_IT_Enable;
	}
}

FlagStatus TIM2_GetFlagStatus(TIM2_FLAG_TypeDef TIM2_FLAG)
{

}

void TIM2_ClearFlag(TIM2_FLAG_TypeDef TIM2_FLAG)
{

}

ITStatus TIM2_GetITStatus(TIM2_IT_FLAG_TypeDef TIM2_IT)
{
	ITStatus bitstatus = _RESET;

  uint8_t TIM0_itStatus = 0x0;

  TIM0_itStatus = (uint8_t)(T2IF & TIM2_IT);

  if (TIM0_itStatus != (uint8_t)_RESET )
  {
    bitstatus = _SET;
  }
  else
  {
    bitstatus = _RESET;
  }
	
	/* Return T2IF bit status */
  return (ITStatus)(bitstatus);
}

void TIM2_ClearITPendingBit(TIM2_IT_FLAG_TypeDef TIM2_IT)
{
	T2IF &= (~TIM2_ITTIM2_IT);
}

/**
  * @}
  */

/**
  * @}
  */

/************************************ (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
