/**
  ******************************************************************************
  * @file    cms8s003x_epwm.h
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file contains all the functions prototypes for the EPWM firmware
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
#ifndef __CMS8S003x_EPWM_H
#define __CMS8S003x_EPWM_H

/* Includes ------------------------------------------------------------------*/
#include "cms8s003x.h"
#include "cms8s003x_conf.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Exported variables ------------------------------------------------------- */
/* Exported types ------------------------------------------------------------*/


/** @addtogroup EPWM_Exported_Types
  * @{
  */
typedef FunctionalState EPWM_Group_TypeDef; /* EPWM group control type */

typedef enum
{
	EPWM_Mode_Independent      	=  ((uint8_t)0x00),
	EPWM_Mode_Complement      	=  ((uint8_t)0x10),
	EPWM_Mode_Synchronize      	=  ((uint8_t)0x20),
} EPWM_Mode_TypeDef;

typedef enum
{
	Align_Center_Symmetry    		= ((uint8_t)0x00),
	Align_Center_Asymmetry    	= ((uint8_t)0x04),
} Align_Center_TypeDef;

typedef enum
{
	Align_Edge                   = ((uint8_t)0x00),                   
} Align_Edge_TypeDef;

typedef enum
{
	AlignStyle_Edge              = ((uint8_t)0x00),
	AlignStyle_Center            = ((uint8_t)0x20)
} AlignStyle_Typedef;

typedef struct _Align_Type
{
	AlignStyle_Typedef    AlignStyle;
	union _Align
	{
		Align_Center_TypeDef  CenterAlign; 
		Align_Edge_TypeDef    EdgeAlign;
	} Align_TypeDef;
} EPWM_Align_Typedef;

typedef enum
{
	EPWM0_Channel   		=  ((uint8_t)0x01),
	EPWM1_Channel   		=  ((uint8_t)0x02),
	EPWM2_Channel   		=  ((uint8_t)0x04),
	EPWM3_Channel   		=  ((uint8_t)0x08),
	EPWM4_Channel   		=  ((uint8_t)0x10),
	EPWM5_Channel   		=  ((uint8_t)0x20),
	EPWMAll_Channel   	=  ((uint8_t)0xFF),
} EPWM_Channel_TypeDef;

typedef struct EPWM_GroupPrescaler
{
	uint8_t EPWM01_Prescaler; /* Fsys/(EPWM01_Prescaler+1) */
	uint8_t EPWM23_Prescaler;
	uint8_t EPWM45_Prescaler;
} EPWM_GroupPrescaler_TypeDef;

typedef enum
{
	Prescaler_2     	= ((uint8_t)0x00), /* PSC/2 */
	Prescaler_4     	= ((uint8_t)0x01),
	Prescaler_8     	= ((uint8_t)0x02),
	Prescaler_16     	= ((uint8_t)0x03),
	Prescaler_Zero    = ((uint8_t)0x04),
	Prescaler_None    = ((uint8_t)0x07)
} EPWM_Prescaler_TypeDef;

typedef EPWM_Channel_TypeDef  EPWM_DataReload_Typedef;

/**
	* EPWM Output Polarity
	*/
typedef enum
{
	EPWM_OP_NonInverted       = ((uint8_t)0x00),
	EPWM_OP_Inverted					= ((uint8_t)0x01),
} EPWM_OP_TypeDef;

typedef EPWM_Channel_TypeDef  EPWM_OP_Inverted_TypeDef;

typedef enum
{
	EPWM_CounterMode_OneShot        =  ((uint8_t)0x00),
	EPWM_CounterMode_Repetitive     =  ((uint8_t)0x01),
} EPWM_CounterMode_TypeDef;


typedef EPWM_Channel_TypeDef  EPWM_CounterMode_Repetitive_TypeDef;

typedef EPWM_Channel_TypeDef  EPWM_CounterZero_TypeDef;


typedef enum
{
	EPWM01_DeadZone				= ((uint8_t)0x01),
	EPWM23_DeadZone				= ((uint8_t)0x02),
	EPWM45_DeadZone				= ((uint8_t)0x04),
	EPWMAll_DeadZone			= ((uint8_t)0xFF),
} EPWM_DeadZone_TypeDef;

typedef EPWM_DeadZone_TypeDef  EPWM_DeadZone_Enable_TypeDef;

typedef struct EPWM_DeadZone_Time_Def
{
	uint8_t   EPWM01_DeadZone_Time:3;
	uint8_t   EPWM23_DeadZone_Time:3;
	uint8_t   EPWM45_DeadZone_Time:3;
	uint8_t   EPWMAll_DeadZone_Time:3;
} EPWM_DeadZone_Time_TypeDef;

typedef enum
{
	EPWM_Mask_Out_Low   	= ((uint8_t)0x00),
	EPWM_Mask_Out_High   	= ((uint8_t)0x01),
} EPWM_Mask_Out_TypeDef;

typedef enum
{
	EPWM0_Mask 		= ((uint8_t)0x01),
	EPWM1_Mask 		= ((uint8_t)0x02),
	EPWM2_Mask 		= ((uint8_t)0x04),
	EPWM3_Mask 		= ((uint8_t)0x08),
	EPWM4_Mask 		= ((uint8_t)0x10),
	EPWM5_Mask 		= ((uint8_t)0x20),
	EPWMAll_Mask 	= ((uint8_t)0xFF),
} EPWM_Mask_TypeDef;

typedef EPWM_Mask_TypeDef  EPWM_Mask_Enable_TypeDef;
typedef EPWM_Mask_TypeDef  EPWM_Mask_High_TypeDef;

typedef enum
{
	EPWM0_Brake 		= ((uint8_t)0x01),
	EPWM1_Brake 		= ((uint8_t)0x02),
	EPWM2_Brake 		= ((uint8_t)0x04),
	EPWM3_Brake 		= ((uint8_t)0x08),
	EPWM4_Brake 		= ((uint8_t)0x10),
	EPWM5_Brake 		= ((uint8_t)0x20),
	EPWMAll_Brake 	= ((uint8_t)0xFF),
} EPWM_BrakePWMn_TypeDef;

typedef struct Brake_Enable_Def
{
	FunctionalState  Brake_CH0_ENABLE:1;
	FunctionalState  Brake_CH1_ENABLE:1;
} EPWM_Brake_ENABLE_TypeDef;

typedef enum
{
	Trigger_Level_Low   	= ((uint8_t)0x00),
	Trigger_Level_High   	= ((uint8_t)0x01),
} Brake_Trigger_Level;

typedef struct EPWM_Brake_Trigger_Def
{
	Brake_Trigger_Level  Brake_CH0:1;
	Brake_Trigger_Level  Brake_CH1:1;
} EPWM_Brake_Trigger_TypeDef;

typedef enum
{
	Brake_Clear     	= ((uint8_t)0x00),
	Brake_NoClear     = ((uint8_t)0x01),
} EPWM_Brake_Clear_TypeDef;

typedef enum
{
	Output_Low       	= ((uint8_t)0x00),
  Output_High       = ((uint8_t)0x01),
} EPWM_Brake_Output_TypeDef;

typedef EPWM_BrakePWMn_TypeDef  EPWM_Brake_OutputHigh_TypeDef;

typedef enum
{
	EPWM_Brake_CH0_FB0    = ((uint8_t)0x01),
	EPWM_Brake_CH1_FB1    = ((uint8_t)0x02),
} EPWM_Brake_CH_TypeDef;

typedef struct EPWM_Brake_Def
{
	EPWM_Brake_ENABLE_TypeDef  				BrakeEnable;
	EPWM_Brake_Trigger_TypeDef   			BrakeTrigger;
	EPWM_Brake_Clear_TypeDef      		BrakeClear;
	EPWM_Brake_OutputHigh_TypeDef     BrakeOutputHigh;
	FunctionalState               		BrakeStart;
} EPWM_Brake_TypeDef;

typedef enum
{
	EPWM0_PeriodIT  		= ((uint8_t)0x01),
	EPWM1_PeriodIT  		= ((uint8_t)0x02),
	EPWM2_PeriodIT  		= ((uint8_t)0x04),
	EPWM3_PeriodIT  		= ((uint8_t)0x08),
	EPWM4_PeriodIT  		= ((uint8_t)0x10),
	EPWM5_PeriodIT  		= ((uint8_t)0x20),
	EPWMAll_PeriodIT  	= ((uint8_t)0xFF),
} EPWM_PeriodIT_TypeDef;


typedef enum
{
	EPWM0_ZeroIT  		= ((uint8_t)0x01),
	EPWM1_ZeroIT  		= ((uint8_t)0x02),
	EPWM2_ZeroIT  		= ((uint8_t)0x04),
	EPWM3_ZeroIT  		= ((uint8_t)0x08),
	EPWM4_ZeroIT  		= ((uint8_t)0x10),
	EPWM5_ZeroIT  		= ((uint8_t)0x20),
	EPWMAll_ZeroIT  	= ((uint8_t)0xFF),
} EPWM_ZeroIT_TypeDef;


typedef enum
{
	EPWM_Brake_Flag        = ((uint8_t)0x40),
} EPWM_Flag_TypeDef;


typedef struct EPWM_InitDef
{
	EPWM_Mode_TypeDef    											Mode;
	EPWM_Group_TypeDef   											Group;
	EPWM_Align_Typedef   											Aligh;
	EPWM_Channel_TypeDef          						EPWMChannel;
	EPWM_GroupPrescaler_TypeDef  							GroupPrescaler;
	EPWM_Prescaler_TypeDef        						Prescaler;
	EPWM_DataReload_Typedef       						DataReload;
	EPWM_OP_Inverted_TypeDef      						OPInverted;
	EPWM_CounterMode_Repetitive_TypeDef      	CounterModeRepetitive;
	EPWM_CounterZero_TypeDef       						CounterZero;
	uint16_t                                    PeriodValue;
	uint16_t                                    CompareValue;
	uint16_t                                    DownCompareValue;
	EPWM_DeadZone_Enable_TypeDef         			DeadZoneEnable;
	EPWM_DeadZone_Time_TypeDef    						DeadZoneTime;
	EPWM_Mask_Enable_TypeDef             			Mask;
	EPWM_Mask_High_TypeDef      							MaskHigh;
	EPWM_Brake_TypeDef            						Brake;
} EPWM_Init_TypeDef;


/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/



/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup BEEP_Private_Macros
  * @{
  */
#define EPWM01_DIED_ZONE_ENABLE 	((uint8_t)0x01)
#define EPWM23_DIED_ZONE_ENABLE 	((uint8_t)0x02)
#define EPWM45_DIED_ZONE_ENABLE 	((uint8_t)0x04)
#define EPWMAll_DIED_ZONE_ENABLE 	((uint8_t)0x04)

#define EPWM0_MASK_ENABLE          ((uint8_t)0x01)
#define EPWM1_MASK_ENABLE          ((uint8_t)0x02)
#define EPWM2_MASK_ENABLE          ((uint8_t)0x04)
#define EPWM3_MASK_ENABLE          ((uint8_t)0x08)
#define EPWM4_MASK_ENABLE          ((uint8_t)0x10)
#define EPWM5_MASK_ENABLE          ((uint8_t)0x20)
#define EPWMAll_MASK_ENABLE        ((uint8_t)0xFF)

#define EPWM0_MASK_HIGH          ((uint8_t)0x01)
#define EPWM1_MASK_HIGH          ((uint8_t)0x02)
#define EPWM2_MASK_HIGH          ((uint8_t)0x04)
#define EPWM3_MASK_HIGH          ((uint8_t)0x08)
#define EPWM4_MASK_HIGH          ((uint8_t)0x10)
#define EPWM5_MASK_HIGH          ((uint8_t)0x20)
#define EPWMAll_MASK_HIGH        ((uint8_t)0xFF)

#define EPWM_BRAKE_CH0_ENABLE    ((uint8_t)0x01)
#define EPWM_BRAKE_CH1_ENABLE    ((uint8_t)0x02)
#define EPWM_BRAKE_CH0_TRIGGER_HIGH  ((uint8_t)0x04)
#define EPWM_BRAKE_CH1_TRIGGER_HIGH  ((uint8_t)0x08)
#define EPWM_BRAKE_START             ((uint8_t)0x10)

#define EPWM0_PERIOD_IT_ENABLE        ((uint8_t)0x01)
#define EPWM1_PERIOD_IT_ENABLE        ((uint8_t)0x02)
#define EPWM2_PERIOD_IT_ENABLE        ((uint8_t)0x04)
#define EPWM3_PERIOD_IT_ENABLE        ((uint8_t)0x08)
#define EPWM4_PERIOD_IT_ENABLE        ((uint8_t)0x10)
#define EPWM5_PERIOD_IT_ENABLE        ((uint8_t)0x20)
#define EPWMAll_PERIOD_IT_ENABLE      ((uint8_t)0xFF)

#define EPWM0_ZERO_IT_ENABLE        ((uint8_t)0x01)
#define EPWM1_ZERO_IT_ENABLE        ((uint8_t)0x02)
#define EPWM2_ZERO_IT_ENABLE        ((uint8_t)0x04)
#define EPWM3_ZERO_IT_ENABLE        ((uint8_t)0x08)
#define EPWM4_ZERO_IT_ENABLE        ((uint8_t)0x10)
#define EPWM5_ZERO_IT_ENABLE        ((uint8_t)0x20)
#define EPWMAll_ZERO_IT_ENABLE      ((uint8_t)0xFF)

#define EPWM_BRAKE_START_BIT        ((uint8_t)0x10)

/**
  * @brief Macro used by the assert function to check the different functions parameters.
  */


/**
  * @}
  */

/* Exported functions ------------------------------------------------------- */

/** @addtogroup EPWM_Exported_Functions
  * @{
  */

void EPWM_DeInit(void);
void EPWM_Init(EPWM_Init_TypeDef *EPWM_Init);
void EPWM_Cmd(EPWM_Channel_TypeDef EPWM_Channel, FunctionalState NewState);

void EPWM_Enable_DataReload(EPWM_DataReload_Typedef EPWMn_Load);
void EPWM_SetOutPolarity(EPWM_OP_TypeDef OP, EPWM_Channel_TypeDef CH);
void EPWM_SetCounterMode(EPWM_CounterMode_TypeDef CounterMode, EPWM_Channel_TypeDef CH);
void EPWM_ClearCounter(EPWM_CounterZero_TypeDef CounterZero);

void EPEM_DeadZoneCmd(EPWM_DeadZone_TypeDef DeadZone, FunctionalState NewState);

void EPWM_MaskCmd(EPWM_Mask_TypeDef Mask, FunctionalState NewState);
void EPWM_MaskOutConfig(EPWM_Mask_TypeDef Mask, EPWM_Mask_Out_TypeDef MaskOut);

void EPWM_BrakeOutputConfig(EPWM_BrakePWMn_TypeDef BrakePWMn, EPWM_Brake_Output_TypeDef Brake_Output);
void EPWM_BrakeCmd(EPWM_Brake_CH_TypeDef BrakeCH, FunctionalState NewState);

void EPWM_PeriodITCmd(EPWM_PeriodIT_TypeDef PeriodIT, FunctionalState NewState);
void EPWM_ZeroITCmd(EPWM_ZeroIT_TypeDef ZeroIT, FunctionalState NewState);
FlagStatus EPWM_GetPeriodITStatus(EPWM_PeriodIT_TypeDef PeriodIT);
FlagStatus EPWM_GetZeroITStatus(EPWM_ZeroIT_TypeDef ZeroIT);
void EPWM_ClearPeriodITStatus(EPWM_PeriodIT_TypeDef PeriodIT);
void EPWM_ClearZeroITStatus(EPWM_ZeroIT_TypeDef ZeroIT);

/**
  * @}
  */

#endif /* __CMS8S003x_EPWM_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
