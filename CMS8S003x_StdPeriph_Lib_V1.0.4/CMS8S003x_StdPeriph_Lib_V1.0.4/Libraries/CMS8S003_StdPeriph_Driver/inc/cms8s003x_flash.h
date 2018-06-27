/**
  ******************************************************************************
  * @file    cms8s003x_flash.h
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file contains all the functions prototypes for the FLASH firmware
  *          library.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, CMSemicon SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTIOzzzN WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2018 CMSemicon</center></h2>
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CMS8S003x_FLASH_H__
#define __CMS8S003x_FLASH_H__

/* Includes ------------------------------------------------------------------*/
#include "cms8s003x.h"
#include "cms8s003x_conf.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Exported variables ------------------------------------------------------- */
/* Exported constants --------------------------------------------------------*/

/** @addtogroup FLASH_Exported_Constants
  * @{
  */


  /**
    * @}
    */

/* Exported types ------------------------------------------------------------*/

  /** @addtogroup FLASH_Exported_Types
    * @{
    */

  /**
    * @brief FLASH Zone types
    */
typedef enum
{
		FLASH_Code_Zone      			= (uint8_t)0x00, /* Flash code zone */
		FLASH_Data_Zone         	= (uint8_t)0x10  /* Flash data zone */
} FLASH_Zone_TypeDef;

typedef enum
{
		Flash_OperationMode_Read       	= (uint8_t)0x00, /* Flash read mode */
		Flash_OperationMode_Reserve     = (uint8_t)0x04, /* Flash reserve mode */
		Flash_OperationMode_Program     = (uint8_t)0x08, /* Flash program mode */
		Flash_OperationMode_Erase       = (uint8_t)0x0C  /* Flash erase mode */
} FLASH_OperationMode_TypeDef;

typedef enum
{
		FLASH_Disable_RWE              =  (uint8_t) 0x00, /* Flash disable R/W/E Operation */
		FLASH_Enable_RWE               =  (uint8_t) 0x01  /* Flash enable R/W/E Operation */
} FLASH_RWE_Typedef;

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup FLASH_Private_Macros
  * @{
  */
#define FLASH_ERROR_BIT    								(uint8_t)0x20
#define FLASH_OPERATION_FINISHED_BIT      (uint8_t)0x01;
/**
  * @}
  */

/* Exported functions ------------------------------------------------------- */
/** @addtogroup FLASH_Exported_Functions
  * @{
  */
void FLASH_DeInit(void);
void FLASH_ProgramByte(FLASH_Zone_TypeDef Flash_Zone, uint32_t Address, uint8_t Data);
void FLASH_ProgramWord(FLASH_Zone_TypeDef Flash_Zone, uint32_t Address, uint32_t Data);
uint8_t FLASH_ReadByte(FLASH_Zone_TypeDef Flash_Zone, uint32_t Address);
void FLASH_EraseBlock(FLASH_Zone_TypeDef Flash_Zone, uint32_t Address);


/**
  * @}
  */

#endif /*__CMS8S003x_FLASH_H__*/

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
