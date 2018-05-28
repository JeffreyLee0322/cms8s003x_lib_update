/**
  ******************************************************************************
  * @file    cms8s003x_tim2.h
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
#ifndef __CMS8S003x_TIM2_H
#define __CMS8S003x_TIM2_H

/* Includes ------------------------------------------------------------------*/
//#include "cms8s003x.h"
#include <CMS\CMS8S003.H>
#include "cms8s003x_conf.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/** @addtogroup TIM2_Exported_Types
 * @{
 */

typedef enum
{
	TIM2_Base_timer               = ((uint8_t)0x00),
	Mode1_16Bit_Timer_Counter               = ((uint8_t)0x01),
	Mode2_8Bit_AutoLoad_Timer_Counter       = ((uint8_t)0x02),
	Mode3_Stop_Counter               	    	= ((uint8_t)0x03),
}TIM2_Mode_TypeDef;

typedef enum
{
	TIM2_Reload_Disable               =        ((uint8_t)0x00),
	TIM2_Overflow_Auto_Reload         =        ((uint8_t)0x02),
	TIM2_T2EX_Falling_Edge_Reload     =        ((uint8_t)0x03),
}TIM2_RELOAD_MODE_TypeDef;

typedef enum
{
	TIM2_Stop								 = 		((uint8_t)0x00), /* Timer2 stop */
	TIM2_SysClock_Prescaler  = 		((uint8_t)0x01), /* Timer2 clock source is from system clock prescale */
	TIM2_ExtPin_T2 					 = 		((uint8_t)0x02), /* Timer2 clock source is from ext pin T2 */
	TIM2_ExtPin_T2_And_T2EX	 = 		((uint8_t)0x03), /* Timer2 clock source is from ext pin T2 and T2EX gate */
}TIM2_CLOCK_SOURCE_TypeDef;

typedef enum
{
	TIM2_SysClock_Prescaler_12     = 		((uint8_t)0x00), /* System 12 prescaler */
	TIM2_SysClock_Prescaler_24     = 		((uint8_t)0x01), /* System 24 prescaler */
}TIM2_CLOCK_PRESCALER_TypeDef;

typedef enum
{
	TIM2_Flag_One  = 		((uint8_t)0x00),
}TIM2_FLAG_TypeDef;

typedef enum
{
	TIM2_Overflow_IT_Enable  		=  ((uint8_t)0x80), /* TIM2 overflow IT enable or not */
	TIM2_Reload_IT_Enable  			=  ((uint8_t)0x40), /* TIM2 reload IT enable or not */
	TIM2_All_IT_Enable  				=  ((uint8_t)0x20), /* TIM2 ALL IT enable or not */
	TIM2_OOC3_IT_Enable 				=  ((uint8_t)0x08), /* TIM2 ooc3 IT enable or not */
	TIM2_OOC2_IT_Enable  				=  ((uint8_t)0x04), /* TIM2 ooc2 IT enable or not */
	TIM2_OOC1_IT_Enable  				=  ((uint8_t)0x02), /* TIM2 ooc1 IT enable or not */
	TIM2_OOC0_IT_Enable  				=  ((uint8_t)0x01), /* TIM2 ooc0 IT enable or not */
}TIM2_IT_Mask_TypeDef;


typedef enum
{
	TIM2_LOW_Priority 		=  	((uint8_t)0x00), /* Timer2 low priority interrupt */
	TIM2_HIGH_Priority 		= 	((uint8_t)0x01), /* Timer2 high priority interrupt */
}TIM2_PRIORITY_TypeDef;

typedef enum
{
	TIM2_Overflow_Flag      =   ((uint8_t)0x80), /* TIM2 overflow IT flag */
	TIM2_Reload_Flag  			=  	((uint8_t)0x40), /* TIM2 reload IT flag */
	TIM2_OOC3_Flag 					=  	((uint8_t)0x08), /* TIM2 ooc3 IT flag */
	TIM2_OOC2_Flag  				=  	((uint8_t)0x04), /* TIM2 ooc2 IT flag */
	TIM2_OOC1_Flag  				=  	((uint8_t)0x02), /* TIM2 ooc1 IT flag */
	TIM2_OOC0_Flag  				=  	((uint8_t)0x01), /* TIM2 ooc0 IT flag */
}TIM2_IT_FLAG_TypeDef;

typedef struct TIM2_InitDef
{
	TIM2_CLOCK_SOURCE_TypeDef 			Clock_Source;
	TIM2_CLOCK_PRESCALER_TypeDef 		Clock_Prescaler;
	TIM2_RELOAD_MODE_TypeDef        Reload_Mode;
	uint16_t 												Init_Value;
}TIM2_Init_TypeDef;

/*
typedef struct TIM2_ItDef
{
	TIM2_IT_Mask_TypeDef   		IT_Mask;
	TIM2_PRIORITY_TypeDef  		IT_Priorty;
}TIM2_IT_TypeDef;*/


#define TIMER2_START_BIT 	0x10
#define TIME2_INTERRUPT_ENABLE_BIT  0x20


/**
  * @}
  */

/** @addtogroup TIM2_Private_Macros
  * @{
  */


void TIM2_DeInit(void);
void TIM2_TimeBaseInit(TIM2_Init_TypeDef* TIM1_InitDef);
void TIM2_Cmd(FunctionalState NewState);


void TIM2_ITConfig(TIM2_IT_Mask_TypeDef TIM2_Mask, TIM2_PRIORITY_TypeDef TIM2_Priority, FunctionalState NewState);
FlagStatus TIM2_GetFlagStatus(TIM2_FLAG_TypeDef TIM2_FLAG);
void TIM2_ClearFlag(TIM2_FLAG_TypeDef TIM2_FLAG);
ITStatus TIM2_GetITStatus(TIM2_IT_FLAG_TypeDef TIM2_IT);
void TIM2_ClearITPendingBit(TIM2_IT_FLAG_TypeDef TIM2_IT);

/**
  * @}
  */

#endif /* __CMS8S003x_TIM2_H */

/**
  * @}
  */

/******************************************** (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
