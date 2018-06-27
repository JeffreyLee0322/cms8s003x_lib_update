/**
  ******************************************************************************
  * @file    cms8s003x_adc.h
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file contains all the functions prototypes for the ADC firmware
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
#ifndef __CMS8S003x_ADC_H
#define __CMS8S003x_ADC_H

/* Includes ------------------------------------------------------------------*/
#include "cms8s003x.h"
#include "cms8s003x_conf.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Exported variables ------------------------------------------------------- */
/* Exported types ------------------------------------------------------------*/


/** @addtogroup ADC_Exported_Types
  * @{
  */

typedef enum
{
	ADC_Format_Left_Align 		= (uint8_t)0x00,
	ADC_Format_Right_Align 		= (uint8_t)0x01,
} ADC_ResultFormat_TypeDef;


typedef enum
{
	ADC_Prescaler_2 		= 	((uint8_t)0x00), 		/*!< ADC Clock frequency is divided by 2 */
  ADC_Prescaler_4 		= 	((uint8_t)0x10), 		/*!< ADC Clock frequency is divided by 4 */
	ADC_Prescaler_8 		= 	((uint8_t)0x20), 		/*!< ADC Clock frequency is divided by 8 */
  ADC_Prescaler_16 		= 	((uint8_t)0x30), 		/*!< ADC Clock frequency is divided by 16 */
	ADC_Prescaler_32 		= 	((uint8_t)0x40), 		/*!< ADC Clock frequency is divided by 32 */
  ADC_Prescaler_64 		= 	((uint8_t)0x50), 		/*!< ADC Clock frequency is divided by 64 */
	ADC_Prescaler_128 	= 	((uint8_t)0x60), 		/*!< ADC Clock frequency is divided by 128 */
  ADC_Prescaler_256 	= 	((uint8_t)0x70)  		/*!< ADC Clock frequency is divided by 256 */
} ADC_Prescaler_TypeDef;

typedef enum
{
	ADC_Channel_0           = ((uint16_t)0x00), /*!< Channel 00 */
  ADC_Channel_1           = ((uint16_t)0x01), /*!< Channel 01 */
  ADC_Channel_2           = ((uint16_t)0x02), /*!< Channel 02 */
  ADC_Channel_3           = ((uint16_t)0x03), /*!< Channel 03 */
  ADC_Channel_4           = ((uint16_t)0x04), /*!< Channel 04 */
  ADC_Channel_5           = ((uint16_t)0x05), /*!< Channel 05 */
  ADC_Channel_6           = ((uint16_t)0x06), /*!< Channel 06 */
  ADC_Channel_7           = ((uint16_t)0x07), /*!< Channel 07 */

  ADC_Channel_8           = ((uint16_t)0x08), /*!< Channel 08 */
  ADC_Channel_9           = ((uint16_t)0x09), /*!< Channel 09*/
  ADC_Channel_10          = ((uint16_t)0x0A), /*!< Channel 10 */
  ADC_Channel_11          = ((uint16_t)0x0B), /*!< Channel 11 */
  ADC_Channel_12          = ((uint16_t)0x0C), /*!< Channel 12 */
  ADC_Channel_13          = ((uint16_t)0x0D), /*!< Channel 13 */
  ADC_Channel_14          = ((uint16_t)0x0E), /*!< Channel 14 */
  ADC_Channel_15          = ((uint16_t)0x0F), /*!< Channel 15 */
} ADC_Channel_TypeDef;

/**
	*ADC Output Polarity Selection
	*/
typedef enum
{
	ADC_CompOut_MoreThanComp  	=  ((uint8_t)0x00), /* If ADRES>=ADCMP, ADCMPO=1*/
	ADC_CompOut_LessThanComp  	=  ((uint8_t)0x40), /* If ADRES<ADCMP, ADCMPO=1*/
} ADC_CompOut_TypeDef;

typedef enum
{
	ADC_CH15_Input_RefVoltage    	= 	((uint8_t)0x00),
	ADC_CH15_Input_OP0    				= 	((uint8_t)0x00),
	ADC_CH15_Input_OP1   		 			= 	((uint8_t)0x00),
} ADC_CH15_Input_TypeDef;

typedef enum
{
	ADC_ExtEventSelection_PWM0   	=  ((uint8_t)0x00),
	ADC_ExtEventSelection_PWM2   	=  ((uint8_t)0x10),
	ADC_ExtEventSelection_PWM4   	=  ((uint8_t)0x20),
	ADC_ExtEventSelection_ADCET   =  ((uint8_t)0x30),
} ADC_ExtEventSelection_TypeDef;

typedef enum
{
	ADC_ExtPortSelection_ADCET0		=  ((uint8_t)0x00),
	ADC_ExtPortSelection_ADCET1		=  ((uint8_t)0x40),
} ADC_ExtPortSelection_TypeDef;

typedef enum
{
	ADC_ExtEdgeSelection_Falling  			=  ((uint8_t)0x00),
	ADC_ExtEdgeSelection_Rising  				=  ((uint8_t)0x04),
	ADC_ExtEdgeSelection_PWM_Middle  		=  ((uint8_t)0x08),
	ADC_ExtEdgeSelection_PWM_End  			=  ((uint8_t)0x0C),
} ADC_ExtEdgeSelection_TypeDef;

/**
  * @brief  ADC  interrupts definition
  */
typedef enum
{
  ADC_Flag_EOC  		= ((uint8_t)0x02), /*!< End of Conversation: ADGO bit  */
  ADC_Flag_CompOut  = ((uint8_t)0x10), /*!< Compare output  */
}ADC_Flag_TypeDef;

typedef struct ADC_InitDef
{
	ADC_Prescaler_TypeDef     Prescaler;
	ADC_Channel_TypeDef				Channel;
	ADC_ResultFormat_TypeDef  ResultFormat;
	FunctionalState           Brake; 
	ADC_CompOut_TypeDef       CompOut;
	uint16_t                  CompValue;
} ADC_Init_TypeDef;

typedef struct ADC_ExtDef
{
	ADC_ExtEventSelection_TypeDef     ExtTrigEvent;
	ADC_ExtEdgeSelection_TypeDef			ExtTrigEdge;
	ADC_ExtPortSelection_TypeDef  		ExtTrigPort;
	uint16_t                          ExtTrigDelay; //10 bit valid
} ADC_ExtTrigConfig_TypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/



/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup ADC_Private_Macros
  * @{
  */
#define ADC_ENABLE_BIT 							((uint8_t)0x80)
#define ADC_START_BIT 							((uint8_t)0x02)
#define ADC_EXT_TRIG_ENABLE_BIT 		((uint8_t)0x80)
#define ADC_COMP_OUT_BIT            ((uint8_t)0x10)
/**
  * @brief Macro used by the assert function to check the different functions parameters.
  */


/**
  * @}
  */

/* Exported functions ------------------------------------------------------- */

/** @addtogroup ADC_Exported_Functions
  * @{
  */

void ADC_DeInit(void);
void ADC_Init(ADC_Init_TypeDef *ADC_Init);
void ADC_ExternalTrigConfig(ADC_ExtTrigConfig_TypeDef *ADC_ExtConfig);
void ADC_Cmd(FunctionalState NewState);
void ADC_ExtTrig_Cmd(FunctionalState NewState);
void ADC_CH15_Input_Selection(ADC_CH15_Input_TypeDef CH15_Input);
uint16_t ADC_GetConversionValue(void);
void ADC_SetCompareValue(uint16_t CompValue);
uint8_t ADC_GetCompareOutput(void);
void ADC_SetCompareOP(ADC_CompOut_TypeDef CompOut);
FlagStatus ADC_GetFlagStatus(ADC_Flag_TypeDef ADC_Flag);
void ADC_ClearFlag(ADC_Flag_TypeDef ADC_Flag);
/**
  * @}
  */

#endif /* __CMS8S003x_ADC_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
