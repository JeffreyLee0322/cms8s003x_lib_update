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
	TIM2_Base_timer               					= ((uint8_t)0x00),
	//Mode1_16Bit_Timer_Counter               = ((uint8_t)0x01),
	//Mode2_8Bit_AutoLoad_Timer_Counter       = ((uint8_t)0x02),
	//Mode3_Stop_Counter               	    	= ((uint8_t)0x03),
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

/**
	* TIM2 Output Compare
	*/
typedef enum
{
	TIM2_OC_Channel_0 		=  	((uint8_t)0x00), /* Timer2 OC channel 0 */
	TIM2_OC_Channel_1 		= 	((uint8_t)0x01), /* Timer2 OC channel 1 */
	TIM2_OC_Channel_2			=  	((uint8_t)0x02), /* Timer2 OC channel 2 */
	TIM2_OC_Channel_3			=  	((uint8_t)0x03), /* Timer2 OC channel 3 */
}TIM2_OC_Channel_TypeDef;

typedef enum
{
	TIM2_OC_Falling_Edge_INT 		=  	((uint8_t)0x00), /* Timer2 OC falling edge interrupt */
	TIM2_OC_Rising_Edge_INT 		= 	((uint8_t)0x01), /* Timer2 OC rising edge interrupt */
}TIM2_OC_INT_Edge_TypeDef;

typedef enum
{
	TIM2_OC_Mode_0 		=  	((uint8_t)0x00), /* Timer2 OC Mode 0 interrupt */
	TIM2_OC_Mode_1 		= 	((uint8_t)0x01), /* Timer2 OC Mode 1 interrupt */
}TIM2_OC_Mode_TypeDef;

typedef enum
{
	TIM2_OC_CML0_Disable 		=  	((uint8_t)(0x00 << 0)), /* Timer2 OC0 disable */
	TIM2_OC_CML0_Edge 			= 	((uint8_t)(0x01 << 0)), /* Timer2 OC0 edge trigger */
	TIM2_OC_CML0_Enable    	= 	((uint8_t)(0x02 << 0)), /* Timer2 OC0 enable */
	TIM2_OC_CML0_RLDL    		= 	((uint8_t)(0x03 << 0)), /* Timer2 OC0 write RLDL trigger */
	TIM2_OC_CML1_Disable 		=  	((uint8_t)(0x00 << 2)), /* Timer2 OC1 disable */
	TIM2_OC_CML1_Edge 			= 	((uint8_t)(0x01 << 2)), /* Timer2 OC1 edge trigger */
	TIM2_OC_CML1_Enable    	= 	((uint8_t)(0x02 << 2)), /* Timer2 OC1 enable */
	TIM2_OC_CML1_CC1L    		= 	((uint8_t)(0x03 << 2)), /* Timer2 OC1 write CC1L trigger */
	TIM2_OC_CML2_Disable 		=  	((uint8_t)(0x00 << 4)), /* Timer2 OC2 disable */
	TIM2_OC_CML2_Edge 			= 	((uint8_t)(0x01 << 4)), /* Timer2 OC2 edge trigger */
	TIM2_OC_CML2_Enable    	= 	((uint8_t)(0x02 << 4)), /* Timer2 OC2 enable */
	TIM2_OC_CML2_CC2L    		= 	((uint8_t)(0x03 << 4)), /* Timer2 OC2 write CC2L trigger */
	TIM2_OC_CML3_Disable 		=  	((uint8_t)(0x00 << 6)), /* Timer2 OC3 disable */
	TIM2_OC_CML3_Edge 			= 	((uint8_t)(0x00 << 6)), /* Timer2 OC3 edge trigger */
	TIM2_OC_CML3_Enable    	= 	((uint8_t)(0x00 << 6)), /* Timer2 OC3 enable */
	TIM2_OC_CML3_CC3L    		= 	((uint8_t)(0x00 << 6)), /* Timer2 OC3 write CC3L trigger */
}TIM2_OC_CMLx_TypeDef;

typedef struct TIM2_OC_InitDef
{
	TIM2_OC_Channel_TypeDef       OC_Channel;
	TIM2_OC_INT_Edge_TypeDef 			OC_INT_Edge;
	TIM2_OC_Mode_TypeDef 					OC_Mode;
	TIM2_OC_CMLx_TypeDef        	OC_CMLx;
	uint16_t 											OC_Init_Value;
}TIM2_OC_Init_TypeDef;

/**
	* TIM2 Iutput Capture
	*/
typedef enum
{
	TIM2_IC_Channel_0 		=  	((uint8_t)0x00), /* Timer2 IC channel 0 */
	TIM2_IC_Channel_1 		= 	((uint8_t)0x01), /* Timer2 IC channel 1 */
	TIM2_IC_Channel_2			=  	((uint8_t)0x02), /* Timer2 IC channel 2 */
	TIM2_IC_Channel_3			=  	((uint8_t)0x03), /* Timer2 IC channel 3 */
}TIM2_IC_Channel_TypeDef;

typedef enum
{
	TIM2_IC_Falling_Edge_INT 		=  	((uint8_t)0x00), /* Timer2 IC falling edge capture RLD */
	TIM2_IC_Rising_Edge_INT 		= 	((uint8_t)0x01), /* Timer2 IC rising edge capture RLD */
}TIM2_IC_INT_Edge_TypeDef;

typedef enum
{
	TIM2_IC_Channel0_IC0 		=  	((uint8_t)0x00), /* Timer2 IC0 channel 0 */
	TIM2_IC_Channel0_IC1 		= 	((uint8_t)0x01), /* Timer2 IC1 channel 0 */
	TIM2_IC_Channel0_IC2		=  	((uint8_t)0x02), /* Timer2 IC2 channel 0 */
	TIM2_IC_Channel0_IC3		=  	((uint8_t)0x03), /* Timer2 IC3 channel 0 */
	TIM2_IC_Channel0_IC4 		=  	((uint8_t)0x04), /* Timer2 IC4 channel 0 */
	TIM2_IC_Channel0_IC5 		=  	((uint8_t)0x05), /* Timer2 IC5 channel 0 */
	TIM2_IC_Channel0_IC6 		= 	((uint8_t)0x06), /* Timer2 IC6 channel 0 */
	TIM2_IC_Channel0_IC7		=  	((uint8_t)0x07), /* Timer2 IC7 channel 0 */
	TIM2_IC_Channel0_IC8		=  	((uint8_t)0x08), /* Timer2 IC8 channel 0 */
	TIM2_IC_Channel0_ICx 		=  	((uint8_t)0x09), /* Timer2 ICX channel 0 */

	TIM2_IC_Channel1_IC0 		=  	((uint8_t)(0x00 << 4)), /* Timer2 IC0 channel 1 */
	TIM2_IC_Channel1_IC1 		= 	((uint8_t)(0x01 << 4)), /* Timer2 IC1 channel 1 */
	TIM2_IC_Channel1_IC2		=  	((uint8_t)(0x02 << 4)), /* Timer2 IC2 channel 1 */
	TIM2_IC_Channel1_IC3		=  	((uint8_t)(0x03 << 4)), /* Timer2 IC3 channel 1 */
	TIM2_IC_Channel1_IC4 		=  	((uint8_t)(0x04 << 4)), /* Timer2 IC4 channel 1 */
	TIM2_IC_Channel1_IC5 		=  	((uint8_t)(0x05 << 4)), /* Timer2 IC5 channel 1 */
	TIM2_IC_Channel1_IC6 		= 	((uint8_t)(0x06 << 4)), /* Timer2 IC6 channel 1 */
	TIM2_IC_Channel1_IC7		=  	((uint8_t)(0x07 << 4)), /* Timer2 IC7 channel 1 */
	TIM2_IC_Channel1_IC8		=  	((uint8_t)(0x08 << 4)), /* Timer2 IC8 channel 1 */
	TIM2_IC_Channel1_ICx 		=  	((uint8_t)(0x09 << 4)), /* Timer2 ICX channel 1 */

	TIM2_IC_Channel2_IC0 		=  	((uint8_t)0x00), /* Timer2 IC0 channel 2 */
	TIM2_IC_Channel2_IC1 		= 	((uint8_t)0x01), /* Timer2 IC1 channel 2 */
	TIM2_IC_Channel2_IC2		=  	((uint8_t)0x02), /* Timer2 IC2 channel 2 */
	TIM2_IC_Channel2_IC3		=  	((uint8_t)0x03), /* Timer2 IC3 channel 2 */
	TIM2_IC_Channel2_IC4 		=  	((uint8_t)0x04), /* Timer2 IC4 channel 2*/
	TIM2_IC_Channel2_IC5 		=  	((uint8_t)0x05), /* Timer2 IC5 channel 2 */
	TIM2_IC_Channel2_IC6 		= 	((uint8_t)0x06), /* Timer2 IC6 channel 2 */
	TIM2_IC_Channel2_IC7		=  	((uint8_t)0x07), /* Timer2 IC7 channel 2 */
	TIM2_IC_Channel2_IC8		=  	((uint8_t)0x08), /* Timer2 IC8 channel 2 */
	TIM2_IC_Channel2_ICx 		=  	((uint8_t)0x09), /* Timer2 ICX channel 2 */

	TIM2_IC_Channel3_IC0 		=  	((uint8_t)(0x00 << 4)), /* Timer2 IC0 channel 3 */
	TIM2_IC_Channel3_IC1 		= 	((uint8_t)(0x01 << 4)), /* Timer2 IC1 channel 3 */
	TIM2_IC_Channel3_IC2		=  	((uint8_t)(0x02 << 4)), /* Timer2 IC2 channel 3 */
	TIM2_IC_Channel3_IC3		=  	((uint8_t)(0x03 << 4)), /* Timer2 IC3 channel 3 */
	TIM2_IC_Channel3_IC4 		=  	((uint8_t)(0x04 << 4)), /* Timer2 IC4 channel 3 */
	TIM2_IC_Channel3_IC5 		=  	((uint8_t)(0x05 << 4)), /* Timer2 IC5 channel 3 */
	TIM2_IC_Channel3_IC6 		= 	((uint8_t)(0x06 << 4)), /* Timer2 IC6 channel 3 */
	TIM2_IC_Channel3_IC7		=  	((uint8_t)(0x07 << 4)), /* Timer2 IC7 channel 3 */
	TIM2_IC_Channel3_IC8		=  	((uint8_t)(0x08 << 4)), /* Timer2 IC8 channel 3 */
	TIM2_IC_Channel3_ICx 		=  	((uint8_t)(0x09 << 4)), /* Timer2 ICX channel 3 */
}TIM2_IC_Select_TypeDef;

typedef struct TIM2_IC_InitDef
{
	TIM2_IC_Channel_TypeDef       IC_Channel;
	TIM2_IC_INT_Edge_TypeDef 			IC_INT_Edge;
	TIM2_IC_Select_TypeDef        IC_Select;
}TIM2_IC_Init_TypeDef;


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



/**
  * @}
  */

/** @addtogroup TIM2_Private_Macros
  * @{
  */


void TIM2_DeInit(void);
void TIM2_TimeBaseInit(TIM2_Init_TypeDef* TIM1_InitDef);
void TIM2_Cmd(FunctionalState NewState);
void TIM2_OCInit(TIM2_OC_Init_TypeDef* TIM2_OCTpye);
void TIM2_ICInit(TIM2_IC_Init_TypeDef* TIM2_ICTpye);
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
