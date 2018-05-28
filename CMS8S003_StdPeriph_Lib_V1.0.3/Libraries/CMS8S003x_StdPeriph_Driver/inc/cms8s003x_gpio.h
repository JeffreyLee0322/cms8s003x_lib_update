/**
  ******************************************************************************
  * @file    cms8s003x_gpio.h
  * @author  LI WEI
  * @version V1.0.0
  * @date    04/24/2018
  * @brief   This file contains all the functions prototypes for the GPIO firmware
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
#ifndef __CMS8S003x_GPIO_H
#define __CMS8S003x_GPIO_H

/* Includes ------------------------------------------------------------------*/
#include <CMS\CMS8S003.H>
#include "cms8s003x_conf.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Exported variables ------------------------------------------------------- */
/* Exported types ------------------------------------------------------------*/

/** @addtogroup GPIO_Exported_Types
  * @{
  */
typedef enum
{
  GPIO_PIN      	= (uint8_t)0x00,
  GPIO_ALT       	= (uint8_t)0x01,
}GPIO_Mode_TypeDef;

typedef enum
{
	GPIO_PORT_0 = (uint8_t)0x00,
	GPIO_PORT_1 = (uint8_t)0x01,
	GPIO_PORT_2 = (uint8_t)0x02,
	GPIO_PORT_3 = (uint8_t)0x03
} GPIO_Port_Typedef;


typedef enum
{
  GPIO_INPUT      	= (uint8_t)0x00,
  GPIO_OUTPUT     	= (uint8_t)0x01,
}GPIO_Dirction_TypeDef;


typedef enum
{
  GPIO_Digital_Sel     		= (uint8_t)0x01,   /*!< gpio digit function select */
  GPIO_Analog_Sel      		= (uint8_t)0x00,   /*!< gpio analog function select */
}GPIO_Analog_TypeDef;


typedef enum
{
  GPIO_Opendrain_Sel     			= (uint8_t)0x01,   /*!< gpio od state */
  GPIO_Pushpull_Sel      			= (uint8_t)0x00,   /*!< gpio normal state */
}GPIO_OType_TypeDef;


typedef enum
{
  GPIO_Up_Enable     			= (uint8_t)0x01,   /*!< gpio up enable */
  GPIO_Up_Disable      		= (uint8_t)0x00,   /*!< gpio up disable */
}GPIO_Up_TypeDef;

typedef enum
{
  GPIO_Down_Enable     			= (uint8_t)0x01,   /*!< gpio down enable */
  GPIO_Down_Disable      		= (uint8_t)0x00,   /*!< gpio down disable */
}GPIO_Down_TypeDef;

typedef enum
{
  GPIO_Driver_Weak    			= (uint8_t)0x01,   /*!< gpio down enable */
  GPIO_Driver_Strong      		= (uint8_t)0x00,   /*!< gpio down disable */
}GPIO_Driver_TypeDef;

typedef enum
{
  GPIO_Slope_Slow     			= (uint8_t)0x01,   /*!< gpio slow slop */
  GPIO_Slope_Fast       		= (uint8_t)0x00,   /*!< gpio fast slop */
}GPIO_Slope_TypeDef;

/**
  * @brief Definition of the GPIO pins. Used by the @ref GPIO_Init function in
  * order to select the pins to be initialized.
  */

typedef enum
{
  GPIO_PIN_0    = ((uint8_t)0x00),   /*!< Pin 0 selected */
  GPIO_PIN_1    = ((uint8_t)0x01),   /*!< Pin 1 selected */
  GPIO_PIN_2    = ((uint8_t)0x02),   /*!< Pin 2 selected */
  GPIO_PIN_3    = ((uint8_t)0x03),   /*!< Pin 3 selected */
  GPIO_PIN_4    = ((uint8_t)0x04),   /*!< Pin 4 selected */
  GPIO_PIN_5    = ((uint8_t)0x05),   /*!< Pin 5 selected */
  GPIO_PIN_6    = ((uint8_t)0x06),   /*!< Pin 6 selected */
  GPIO_PIN_7    = ((uint8_t)0x07),   /*!< Pin 7 selected */
  GPIO_PIN_LNib = ((uint8_t)0x08),   /*!< Low nibble pins selected */
  GPIO_PIN_HNib = ((uint8_t)0x09),   /*!< High nibble pins selected */
  GPIO_PIN_All  = ((uint8_t)0x0A)    /*!< All pins selected */
}GPIO_Pin_TypeDef;



/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup GPIO_Private_Macros
  * @{
  */

/**
  * @brief Macro used by the assert function to check the different functions parameters.
  */

/**
  * @brief Macro used by the assert function in order to check the different
  * values of GPIOMode_TypeDef.
  */
#define IS_GPIO_MODE(MODE) \
   (((MODE) == GPIO_Opendrain_Sel)       || \
   ((MODE) == GPIO_Pushpull_Sel))

/**
  * @brief Macro used by the assert function in order to check the different
  * values of GPIO_Pins.
  */
#define IS_GPIO_PIN(PIN) ((PIN) != (uint8_t)0x00)

/**
  * @}
  */

typedef struct GPIO_InitDef
{
		GPIO_Mode_TypeDef         Mode;                  //模式
  	GPIO_Dirction_TypeDef 		Direction;             //方向
		GPIO_Analog_TypeDef  			Analog;                //模拟信号选择
		GPIO_OType_TypeDef  			OType;                  //开漏/正常
  	GPIO_Up_TypeDef  					Up;                    //上拉使能
		GPIO_Down_TypeDef  				Down;                  //下拉使能
		GPIO_Driver_TypeDef  			Driver;                //驱动电流
		GPIO_Slope_TypeDef  			Slope;                 //斜率控制
		GPIO_Pin_TypeDef 					Pin;                   //引脚选择
} GPIO_Init_TypeDef;


/* Exported functions ------------------------------------------------------- */
/** @addtogroup GPIO_Exported_Functions
  * @{
  */

void GPIO_DeInit(GPIO_Port_Typedef GPIOx);
void GPIO_Init(GPIO_Port_Typedef GPIOx, GPIO_Init_TypeDef* GPIO_InitParam);
void GPIO_Write(GPIO_Port_Typedef GPIOx, uint8_t GPIO_PortVal);
void GPIO_WriteBit(GPIO_Port_Typedef GPIOx, GPIO_Pin_TypeDef GPIO_Pin, BitAction GPIO_BitVal);
void GPIO_SetBits(GPIO_Port_Typedef GPIOx, uint8_t GPIO_Pin);
void GPIO_ResetBits(GPIO_Port_Typedef GPIOx, uint8_t GPIO_Pin);
void GPIO_ToggleBits(GPIO_Port_Typedef GPIOx, uint8_t GPIO_Pin);
uint8_t GPIO_ReadInputData(GPIO_Port_Typedef GPIOx);
uint8_t GPIO_ReadOutputData(GPIO_Port_Typedef GPIOx);
BitStatus GPIO_ReadInputDataBit(GPIO_Port_Typedef GPIOx, GPIO_Pin_TypeDef GPIO_Pin);
BitStatus GPIO_ReadOutputDataBit(GPIO_Port_Typedef GPIOx, GPIO_Pin_TypeDef GPIO_Pin);
void GPIO_ExternalPullUpConfig(GPIO_Port_Typedef GPIOx, uint8_t GPIO_Pin, FunctionalState NewState);
/**
  * @}
  */

#endif /* __CMS8S003x_GPIO_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/

