/**
  ******************************************************************************
  * @file    cms8s003x_tim01.h
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file contains all the functions prototypes for the TIM01 firmware
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
#ifndef __CMS8S003x_TIM01_H
#define __CMS8S003x_TIM01_H

/* Includes ------------------------------------------------------------------*/
#include "cms8s003x.h"
#include "cms8s003x_conf.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/** @addtogroup TIM01_Exported_Types
 * @{
 */
typedef enum
{
	TIM0   =   ((uint8_t)0x00),
	TIM1   =   ((uint8_t)0x01)
}TIM01_TypeDef;

typedef enum
{
	TIM01_Function_Timer       = ((uint8_t)0x00),
	TIM01_Function_Counter     = ((uint8_t)0x01),
}TIM01_Function_TypeDef;

typedef enum
{
	TIM01_Mode0_13Bit_Timer_Counter               = ((uint8_t)0x00),
	TIM01_Mode1_16Bit_Timer_Counter               = ((uint8_t)0x01),
	TIM01_Mode2_8Bit_AutoLoad_Timer_Counter       = ((uint8_t)0x02),
	TIM01_Mode3_Stop_Counter               	    	= ((uint8_t)0x03),
}TIM01_Mode_TypeDef;

typedef enum
{
	TIM01_SYSCLK_Prescaler_12 = ((uint8_t)0x00),
	TIM01_SYSCLK_Prescaler_4  = ((uint8_t)0x01)
}TIM01_CLOCK_SOURCE_TypeDef;


typedef struct TIM01_InitDef
{
	TIM01_Function_TypeDef 				Timer_Function;
	TIM01_Mode_TypeDef 						Timer_Mode;
	TIM01_CLOCK_SOURCE_TypeDef 		Timer_Clock;
	uint32_t 											Timer_InitValue;
}TIM01_Init_TypeDef;

typedef enum
{
	TIM01_HIGH_Priority 	= ((uint8_t)0x01),
	TIM01_LOW_Priority 		=  ((uint8_t)0x00),
}TIM01_PriorityTypeDef;


#define TIMER0_START_BIT 	0x10
#define TIMER1_START_BIT 	0x40

#define TIME0_INTERRUPT_ENABLE_BIT  0x02
#define TIME1_INTERRUPT_ENABLE_BIT  0x08

/**
  * @}
  */

/** @addtogroup TIM01_Private_Macros
  * @{
  */


void TIM0_DeInit(void);
void TIM1_DeInit(void);
void TIM0_Init(TIM01_Init_TypeDef *TIM0_InitDef);
void TIM1_Init(TIM01_Init_TypeDef *TIM1_InitDef);
void TIM0_Cmd(FunctionalState NewState);
void TIM1_Cmd(FunctionalState NewState);
void TIM0_ITConfig(TIM01_PriorityTypeDef TIM0_Priority, FunctionalState NewState);
void TIM1_ITConfig(TIM01_PriorityTypeDef TIM1_Priority, FunctionalState NewState);
uint16_t TIM0_GetCounter(void);
uint16_t TIM1_GetCounter(void);
ITStatus TIM0_GetITStatus(void);
ITStatus TIM1_GetITStatus(void);
void TIM0_ClearITPendingBit();
void TIM1_ClearITPendingBit();

/**
  * @}
  */

#endif /* __CMS8S003x_TIM1_H */

/**
  * @}
  */

/******************************************** (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
