/**
  ******************************************************************************
  * @file    cms8s003x_conf.h
  * @author  LI WEI
  * @version V1.0.0
  * @date    04/21/2018
  * @brief   Library configuration file.
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
#ifndef __CMS8S003x_CONF_H
#define __CMS8S003x_CONF_H

/* Includes ------------------------------------------------------------------*/
#include <CMS\CMS8S003.H>

typedef enum{_FALSE = 0, _TRUE = !FALSE} _bool;

typedef enum{_RESET = 0, _SET = !_RESET} FlagStatus, ITStatus, BitStatus, BitAction;

typedef enum{_DISABLE = 0, _ENABLE = !_DISABLE} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == _DISABLE) || ((STATE) == _ENABLE))

typedef enum {_ERROR = 0, _SUCCESS = !_ERROR} ErrorStatus;

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Uncomment the line below to expanse the "assert_param" macro in the 
   Standard Peripheral Library drivers code */
/* #define USE_FULL_ASSERT    (1) */ 

/* Exported macro ------------------------------------------------------------*/
#ifdef  USE_FULL_ASSERT

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param expr: If expr is false, it calls assert_failed function
  *   which reports the name of the source file and the source
  *   line number of the call that failed. 
  *   If expr is true, it returns no value.
  * @retval : None
  */
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) //((void)0)
#endif /* USE_FULL_ASSERT */

#endif /* __STM8L15x_CONF_H */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
