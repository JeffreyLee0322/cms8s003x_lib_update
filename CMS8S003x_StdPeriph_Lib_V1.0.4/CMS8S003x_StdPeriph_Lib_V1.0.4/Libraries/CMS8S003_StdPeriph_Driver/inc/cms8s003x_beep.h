/**
  ******************************************************************************
  * @file    cms8s003x_beep.h
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file contains all the functions prototypes for the BEEP firmware
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
#ifndef __CMS8S003x_BEEP_H
#define __CMS8S003x_BEEP_H

/* Includes ------------------------------------------------------------------*/
#include "cms8s003x.h"
#include "cms8s003x_conf.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Exported variables ------------------------------------------------------- */
/* Exported types ------------------------------------------------------------*/

typedef uint8_t BEEP_Prescaler2_TypeDef;
/** @addtogroup BEEP_Exported_Types
  * @{
  */

typedef enum {
  BEEP_SysClk_Prescaler_8 	= (uint8_t)0x00,  /*!< Beep system clock prescaler: Fsys/8 */
  BEEP_SysClk_Prescaler_16 	= (uint8_t)0x01,  /*!< Beep system clock prescaler: Fsys/16 */
  BEEP_SysClk_Prescaler_32 	= (uint8_t)0x02,  /*!< Beep system clock prescaler: Fsys/32 */
	BEEP_SysClk_Prescaler_64 	= (uint8_t)0x03   /*!< Beep system clock prescaler: Fsys/64 */
} BEEP_Prescaler1_TypeDef;

typedef struct BEEP_InitDef
{
	BEEP_Prescaler1_TypeDef BEEP_Prescaler1;
	BEEP_Prescaler2_TypeDef BEEP_Prescaler2;
} BEEP_Init_TypeDef;

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
#define BEEP_ENABLE (uint8_t)0x80
/**
  * @brief Macro used by the assert function to check the different functions parameters.
  */


/**
  * @}
  */

/* Exported functions ------------------------------------------------------- */

/** @addtogroup BEEP_Exported_Functions
  * @{
  */

void BEEP_DeInit(void);
void BEEP_Init(BEEP_Init_TypeDef *BEEP_Init);
void BEEP_Cmd(FunctionalState NewState);


/**
  * @}
  */

#endif /* __CMS8S003x_BEEP_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
