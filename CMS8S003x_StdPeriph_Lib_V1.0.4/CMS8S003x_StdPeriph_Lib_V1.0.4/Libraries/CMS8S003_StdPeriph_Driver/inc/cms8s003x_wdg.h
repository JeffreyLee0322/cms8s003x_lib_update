/**
  ******************************************************************************
  * @file    cms8s003x_wdg.h
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file contains all the functions prototypes for the WDG firmware
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
#ifndef __CMS8S003x_WDG_H
#define __CMS8S003x_WDG_H

/* Includes ------------------------------------------------------------------*/
#include "cms8s003x.h"
#include "cms8s003x_conf.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Exported variables ------------------------------------------------------- */
/* Exported types ------------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup WDG_Private_Macros
  * @{
  */
typedef enum
{
	WDG_Flag_Overflow     =  (uint8_t)0x08,
	WDG_Flag_Reset        =  (uint8_t)0x04
} WDG_Flag_TypeDef;

typedef enum
{
	WDG_Reset_Disable     =  (uint8_t)0x00,
  WDG_Reset_Enable      =  (uint8_t)0x02
} WDG_Reset_TypeDef;

typedef enum
{
  WDG_Clear_Disable     =  (uint8_t)0x00,
	WDG_Clear_Enable      =  (uint8_t)0x01
} WDG_Clear_TypeDef;

typedef enum
{
	WDG_OverflowTime_2x17   = (uint8_t)0x00, /* Overflow Time: 2x17 * sysclock */
	WDG_OverflowTime_2x20   = (uint8_t)0x40,
	WDG_OverflowTime_2x23   = (uint8_t)0x80,
	WDG_OverflowTime_2x26   = (uint8_t)0xC0,
} WDG_OverflowTime_TypeDef;

typedef struct WDG_InitDef
{
	WDG_Clear_TypeDef  					WDG_Clear;
	WDG_OverflowTime_TypeDef  	WDG_OverflowTime;
} WDG_Init_TypeDef;
/**
  * @}
  */
#define WDG_RESET_ENABLE_BIT    (uint8_t)0x02
/* Exported types ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

/** @addtogroup WWDG_Exported_Functions
  * @{
  */

void WDG_Init(WDG_Init_TypeDef *WDG_Init);
void WDG_Enable(void);
void WDG_Disable(void);
uint8_t WDG_GetCounter(void);
ITStatus WDG_GetITStatus(WDG_Flag_TypeDef WDG_Flag);
void WDG_ClearITPendingBit(WDG_Flag_TypeDef WDG_Flag);



/**
  * @}
  */

#endif /* __CMS8S003x_WDG_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/