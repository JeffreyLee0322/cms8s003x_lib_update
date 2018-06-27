/**
  ******************************************************************************
  * @file    cms8s003x_tim34.h
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file contains all the functions prototypes for the TIM1 firmware
  *          library.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CMS8S003x_TIM34_H
#define __CMS8S003x_TIM34_H

/* Includes ------------------------------------------------------------------*/
#include "cms8s003x.h"
#include "cms8s003x_conf.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/** @addtogroup TIM34_Exported_Types
 * @{
 */
typedef enum
{
	TIM3   =   ((uint8_t)0x00),
	TIM4   =   ((uint8_t)0x01)
}TIM34_TypeDef;

typedef enum
{
	TIM34_Function_Timer               = ((uint8_t)0x00),
	TIM34_Function_Counter             = ((uint8_t)0x01),
}TIM34_Function_TypeDef;

typedef enum
{
	TIM34_Mode0_13Bit_Timer_Counter               = ((uint8_t)0x00),
	TIM34_Mode1_16Bit_Timer_Counter               = ((uint8_t)0x01),
	TIM34_Mode2_8Bit_AutoLoad_Timer_Counter       = ((uint8_t)0x02),
	TIM34_Mode3_Stop_Counter               	    	= ((uint8_t)0x03),
}TIM34_Mode_TypeDef;

typedef enum
{
	TIM34_SYSCLK_Prescaler_12 = ((uint8_t)0x00),
	TIM34_SYSCLK_Prescaler_4  = ((uint8_t)0x01)
}TIM34_CLOCK_SOURCE_TypeDef;


typedef struct TIM34_InitDef
{
	TIM34_Function_TypeDef 				Timer_Function;
	TIM34_Mode_TypeDef 						Timer_Mode;
	TIM34_CLOCK_SOURCE_TypeDef 		Timer_Clock;
	uint32_t 										Timer_InitValue;
}TIM34_Init_TypeDef;

typedef enum
{
	TIM34_HIGH_Priority = ((uint8_t)0x01),
	TIM34_LOW_Priority =  ((uint8_t)0x00),
}TIM34_PriorityTypeDef;


#define TIMER3_START_BIT 	0x10
#define TIMER4_START_BIT 	0x40

#define TIME3_INTERRUPT_ENABLE_BIT  0x02
#define TIME4_INTERRUPT_ENABLE_BIT  0x08

/**
  * @}
  */

/** @addtogroup TIM1_Private_Macros
  * @{
  */


void TIM3_DeInit(void);
void TIM4_DeInit(void);
void TIM3_Init(TIM34_Init_TypeDef *TIM3_InitDef);
void TIM4_Init(TIM34_Init_TypeDef *TIM4_InitDef);
void TIM3_Cmd(FunctionalState NewState);
void TIM4_Cmd(FunctionalState NewState);
void TIM3_ITConfig(TIM34_PriorityTypeDef TIM3_Priority, FunctionalState NewState);
void TIM4_ITConfig(TIM34_PriorityTypeDef TIM4_Priority, FunctionalState NewState);
uint16_t TIM3_GetCounter(void);
uint16_t TIM4_GetCounter(void);
ITStatus TIM3_GetITStatus(void);
ITStatus TIM4_GetITStatus(void);
void TIM3_ClearITPendingBit();
void TIM4_ClearITPendingBit();

/**
  * @}
  */

#endif /* __CMS8S003x_TIM34_H */

/**
  * @}
  */

/******************************************** (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
