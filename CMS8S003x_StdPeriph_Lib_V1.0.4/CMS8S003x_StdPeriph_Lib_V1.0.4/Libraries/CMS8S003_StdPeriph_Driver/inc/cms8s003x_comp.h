/**
  ******************************************************************************
  * @file    cms8s003x_comp.h
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file contains all the functions prototypes for the COMP firmware
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
#ifndef __CMS8S003X_COMP_H
#define __CMS8S003X_COMP_H


/* Includes ------------------------------------------------------------------*/
#include "cms8s003x.h"
#include "cms8s003x_conf.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Exported variables ------------------------------------------------------- */
/* Private define ------------------------------------------------------------*/

/** @addtogroup COMP_Exported_Types
  * @{
  */

/**
  * @brief Definition of the COMP selection.
  */
typedef enum
{
  COMP0 = ((uint8_t)0x01), /*!< Selection of Comparator 1. */
  COMP1 = ((uint8_t)0x02)  /*!< Selection of Comparator 2. */
} COMP_TypeDef;

typedef enum
{
	COMP_NegativeCH_C0N						= ((uint8_t)0x00),
	COMP_NegativeCH_C1N						= ((uint8_t)0x00),
	COMP_NegativeCH_VREF					= ((uint8_t)0x01)
} COMP_NegativeCH_TypeDef;

typedef enum
{
	COMP_PositiveCH_C0P0						= ((uint8_t)0x00),
	COMP_PositiveCH_C1P0						= ((uint8_t)0x00),
	COMP_PositiveCH_C0P1						= ((uint8_t)0x01),
	COMP_PositiveCH_C1P1						= ((uint8_t)0x01),
	COMP_PositiveCH_C0P2						= ((uint8_t)0x02),
	COMP_PositiveCH_C1P2						= ((uint8_t)0x02),
	COMP_PositiveCH_C0N							= ((uint8_t)0x03),
	COMP_PositiveCH_C1N							= ((uint8_t)0x03)
} COMP_PositiveCH_TypeDef;

typedef enum
{
	COMP_RegulationModeIn_Positive		= ((uint8_t)0x00),
	COMP_RegulationModeIn_Negative		= ((uint8_t)0x01)
} COMP_RegulationModeIn_TypeDef;

typedef enum
{
	COMP_OutputPolarity_Normal 				= ((uint8_t)0x00),
	COMP_OutputPolarity_Reverse 			= ((uint8_t)0x01)
} COMP_OutputPolarity_TypeDef;

typedef enum
{
	COMP_OutputFilterTime_0 					= ((uint8_t)0x0000), /* (0-1)*Tsys */
	COMP_OutputFilterTime_1 					= ((uint8_t)0x0001), /* (1-2)*Tsys */
	COMP_OutputFilterTime_2 					= ((uint8_t)0x0000), /* (2-3)*Tsys */
	COMP_OutputFilterTime_4 					= ((uint8_t)0x0001), /* (4-5)*Tsys */
	COMP_OutputFilterTime_8 					= ((uint8_t)0x0000), /* (8-9)*Tsys */
	COMP_OutputFilterTime_16 					= ((uint8_t)0x0001), /* (16-17)*Tsys */
	COMP_OutputFilterTime_32 					= ((uint8_t)0x0000), /* (32-33)*Tsys */
	COMP_OutputFilterTime_64 					= ((uint8_t)0x0001), /* (64-65)*Tsys */
	COMP_OutputFilterTime_128 				= ((uint8_t)0x0000), /* (128-129)*Tsys */
	COMP_OutputFilterTime_256 				= ((uint8_t)0x0001), /* (256-257)*Tsys */
	COMP_OutputFilterTime_512 				= ((uint8_t)0x0000)  /* (512-513)*Tsys */
} COMP_OutputFilterTime_TypeDef;

typedef enum
{
	COMP_NegativeVref_1dot2v          = ((uint8_t)0x00),
	COMP_NegativeVref_KVDD          	= ((uint8_t)0x01)
} COMP_NegativeVref_TypeDef;

typedef enum
{
	COMP_PWMBrakeEdge_Rising          = ((uint8_t)0x00),
	COMP_PWMBrakeEdge_Falling         = ((uint8_t)0x01),
} COMPn_PWMBrakeEdge_Typedef;

typedef enum
{
	COMP_OffsetVoltageMode_Config			= (uint8_t)0x00,
	COMP_OffsetVoltageMode_CnADJ			= (uint8_t)0xAA,
} COMP_OffsetVoltageMode_TypeDef;

typedef enum
{
	COMP0_IT_Flag					= ((uint8_t)0x01),
	COMP1_IT_Flag					= ((uint8_t)0x02)
} COMP_IT_Flag_TypeDef;

typedef struct COMP_Def
{
	FunctionalState										COMP_RegulationMode:1;
	FunctionalState										COMP_NegativeGND:1;
	COMP_NegativeCH_TypeDef     			COMP_NegativeCH:2;
	COMP_PositiveCH_TypeDef     			COMP_PositiveCH:2;
	COMP_RegulationModeIn_TypeDef    	COMP_RegulationModeIn:1;
	uint8_t                           COMP_OffsetVoltage:6;
	COMP_OutputPolarity_TypeDef       COMP_OutputPolarity:1;
	FunctionalState                   COMP_OutputFilter:1;
	COMP_OutputFilterTime_TypeDef     COMP_OutputFilterTime:4;
	COMP_NegativeVref_TypeDef         COMP_NegativeVref:1;
	uint8_t                           COMP_NegativeVDDK:4; 		/* 0000 - 1111 = VDD*(2/20) ~ VDD*(17/20) */
  union Brake_
	{
		FunctionalState 		COMP0_PWMBrake;
		FunctionalState 		COMP1_PWMBrake;
	} COMPn_PWMBrake;
	union Brake_Edge
	{
		COMPn_PWMBrakeEdge_Typedef 		COMP0_PWMBrakeEdge;
		COMPn_PWMBrakeEdge_Typedef 		COMP1_PWMBrakeEdge;
	} COMPn_PWMBrakeEdge;
	COMP_OffsetVoltageMode_TypeDef     COMP_OffsetVoltageMode;
} COMP_Init_TypeDef;


/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup COMP_Private_Macros
  * @{
  */
#define COMP_ENABLE_BIT    				((uint8_t)0x80)
#define COMP0_IT_DISABLE_BIT    	((uint8_t)0x01)
#define COMP1_IT_DISABLE_BIT    	((uint8_t)0x02)
/**
  * @brief Macro used by the assert function to check the different functions parameters.
  */


/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup COMP_Exported_Functions
  * @{
  */

void COMP_DeInit(COMP_TypeDef COMPn);
void COMP_Init(COMP_TypeDef COMPn,COMP_Init_TypeDef *COMP_Init);
void COMP_Cmd(COMP_TypeDef COMPn, FunctionalState NewState);
uint8_t COMP_GetResult(COMP_TypeDef COMPn);
void COMP_ITConfig(COMP_TypeDef COMPn, FunctionalState NewState);
FlagStatus COMP_GetFlagStatus(COMP_TypeDef COMPn);
void COMP_ClearFlag(COMP_TypeDef COMPn);
ITStatus COMP_GetITStatus(COMP_TypeDef COMPn);
void COMP_ClearITPendingBit(COMP_TypeDef COMPn);

/**
  * @}
  */

#endif /* __CMS8S003x_COMP_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
