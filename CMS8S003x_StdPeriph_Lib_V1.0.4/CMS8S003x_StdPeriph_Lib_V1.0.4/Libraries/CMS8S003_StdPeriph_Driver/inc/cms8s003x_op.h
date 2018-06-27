/**
  ******************************************************************************
  * @file    cms8s003x_op.h
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file contains all the functions prototypes for the OP firmware
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
#ifndef __CMS8S003X_OP_H
#define __CMS8S003X_OP_H


/* Includes ------------------------------------------------------------------*/
#include "cms8s003x.h"
#include "cms8s003x_conf.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Exported variables ------------------------------------------------------- */
/* Private define ------------------------------------------------------------*/

/** @addtogroup OP_Exported_Types
  * @{
  */
typedef enum
{
  OP0 = (uint8_t)0x00,
	OP1 = (uint8_t)0x01
} OP_TypeDef;

typedef enum
{
	OP_OutCH_Disable    = (uint8_t)0x00,
	OP_OutCH_0			    = (uint8_t)0x01,
	OP_OutCH_1			    = (uint8_t)0x01,
} OP_OutCH_TypeDef;

typedef enum
{
	OP_PositiveCH_0						= (uint8_t)0x00,
	OP_PositiveCH_1						= (uint8_t)0x00,
	OP_PositiveCH_Disable			= (uint8_t)0x01,
} OP_PositiveCH_TypeDef;

typedef enum
{
	OP_NegativeCH_0						= (uint8_t)0x00,
	OP_NegativeCH_1						= (uint8_t)0x00,
	OP_NegativeCH_Disable			= (uint8_t)0x01,
} OP_NegativeCH_TypeDef;

typedef enum
{
	OP_RegulationMode_In_Positive    = (uint8_t)0x00,
	OP_RegulationMode_In_Negative    = (uint8_t)0x01,
} OP_RegulationMode_TypeDef;

typedef enum
{
	OP_OffsetVoltageMode_Config			= (uint8_t)0x00,
	OP_OffsetVoltageMode_OPnADJ			= (uint8_t)0xAA,
} OP_OffsetVoltageMode_TypeDef;

typedef struct OP_Def
{
	FunctionalState 									OP_EN:1;
	FunctionalState 									OP_Regulation:1;
	FunctionalState 									OP_Filtration:1;
	OP_OutCH_TypeDef 									OP_OutCH:1;
	OP_PositiveCH_TypeDef 						OP_PositiveCH:2;
	OP_NegativeCH_TypeDef 						OP_NegativeCH:2;
	OP_RegulationMode_TypeDef 				OP_RegulationMode:1;
	uint8_t 													OP_OffsetVoltage:5;
	OP_OffsetVoltageMode_TypeDef 			OP_OffsetVoltageMode;
} OP_Init_TypeDef;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup OP_Private_Macros
  * @{
  */
#define OP_ENABLE_BIT  ((uint8_t)0x08)
/**
  * @brief Macro used by the assert function to check the different functions parameters.
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup OP_Exported_Functions
  * @{
  */

void OP_DeInit(OP_TypeDef OPn);
void OP_Init(OP_TypeDef OPn, OP_Init_TypeDef *OP_Init);
void OP_Cmd(OP_TypeDef OPn, FunctionalState NewState);
uint8_t getOPResult(OP_TypeDef OPn); 

/**
  * @}
  */

#endif /* __CMS8S003X_OP_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
