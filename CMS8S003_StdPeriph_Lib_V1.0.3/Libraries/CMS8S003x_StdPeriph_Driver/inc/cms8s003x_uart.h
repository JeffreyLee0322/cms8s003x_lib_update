/**
  ********************************************************************************
  * @file    cms8s003x_uart.h
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file contains all the functions prototypes for the UART firmware
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
#ifndef __CMS8S003x_UART_H
#define __CMS8S003x_UART_H

/* Includes ------------------------------------------------------------------*/
#include <CMS\CMS8S003.H>
#include "cms8s003x_conf.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Exported variables ------------------------------------------------------- */
/* Exported types ------------------------------------------------------------*/

/** @addtogroup UART_Exported_Types
  * @{
  */


typedef enum
{
	UART0 = 0,
	UART1 = 1
}UART_TypeDef;


/**
  * @brief USART Word length possible values
  */
typedef enum
{
  USART_WordLength_8b = (uint8_t)0x00,  /*!< 8 bits Data */
  USART_WordLength_9b = (uint8_t)0x10   /*!< 9 bits Data */
} USART_WordLength_TypeDef;

/**
  * @brief USART Mode possible values
  */
typedef enum
{
  USART_Mode_Rx    = (uint8_t)0x04,  /*!< Receive Enable */
  USART_Mode_Tx    = (uint8_t)0x08   /*!< Transmit Enable */
} USART_Mode_TypeDef;




/**
  * @brief USART Clock possible values
  */
typedef enum
{
  USART_Clock_Disable    = (uint8_t)0x00,  /*!< CK pin disabled */
  USART_Clock_Enable     = (uint8_t)0x08   /*!< CK pin enabled */
} USART_Clock_TypeDef;

/**
  * @brief USART Clock Polarity possible values
  */
typedef enum
{
  USART_CPOL_Low      = (uint8_t)0x00,  /*!< CK to 0 when idle */
  USART_CPOL_High     = (uint8_t)0x04   /*!< CK to 1 when idle.*/
} USART_CPOL_TypeDef;

/**
  * @brief USART Clock Phase possible values
  */
typedef enum
{
  USART_CPHA_1Edge     = (uint8_t)0x00,  /*!< The first clock transition is the first data capture edge*/
  USART_CPHA_2Edge     = (uint8_t)0x02   /*!< The second clock transition is the first data capture edge*/
} USART_CPHA_TypeDef;

/**
  * @brief USART Last Bit possible values
  */
typedef enum
{
  USART_LastBit_Disable  = (uint8_t)0x00,  /*!< The clock pulse of the last data bit is not output to the SCLK pin.*/
  USART_LastBit_Enable   = (uint8_t)0x01   /*!< The clock pulse of the last data bit is output to the SCLK pin.*/
} USART_LastBit_TypeDef;


typedef enum
{
	Data_8Bit_Settled_Freq 	 = 	(uint8_t)0x00,//Fsys/12
	Data_8Bit_Unsettled_Freq = 	(uint8_t)0x40,//variable
	Data_9Bit_Settled_Freq 	 = 	(uint8_t)0x80,//Fsys/32 or /64
	Data_9Bit_Unsettled_Freq = 	(uint8_t)0xC0//variable
} UART_DataBit_TypeDef;

typedef enum
{
	Data_9Bit_Is0 = (uint8_t)0x00,
	Data_9Bit_Is1 = (uint8_t)0x01,
} UART_Data_9Bit_TypeDef;

typedef enum
{
	Baudrate_Normal = (uint8_t)0x00,
	Baudrate_Double = (uint8_t)0x01,
} UART_Baudrate_Double_TypeDef;

typedef enum
{
	Timer1_Select = (uint8_t)0x00,
	Timer4_Select = (uint8_t)0x01,
} UART_CLK_Source_TypeDef;

typedef struct UART_INIT
{
	UART_DataBit_TypeDef 			DataBit;
	uint8_t 						MutiDevices;
	uint8_t 						IsReceive;
	UART_Data_9Bit_TypeDef 			SendData9Bit;
	UART_Data_9Bit_TypeDef 			ReceiveData9Bit;
	UART_Baudrate_Double_TypeDef 	Uart0Double;
	UART_Baudrate_Double_TypeDef 	Uart1Double;
	UART_CLK_Source_TypeDef 		UartClkSource;
} UART_Init_TypeDef;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup USART_Private_Macros
  * @{
  */

/**
  * @brief Macro used by the assert function to check the different functions parameters.
  */



/**
 * @brief Macro used by the assert function in order to check the different
 *  sensitivity values for the node address
 */
#define USART_ADDRESS_MAX ((uint8_t)16)
#define IS_USART_ADDRESS(address) ((address) < USART_ADDRESS_MAX)

/**
 * @brief Macro used by the assert function in order to check the different
 *  sensitivity values  for the data
 */
#define USART_DATA_9BITS_MAX ((uint16_t)0x1FF)
#define IS_USART_DATA_9BITS(DATA) ((DATA) < USART_DATA_9BITS_MAX)

/**
  * @}
  */

/* Exported functions ------------------------------------------------------- */
/** @addtogroup USART_Exported_functions
  * @{
  */

void USART_DeInit(UART_TypeDef USARTx);
void UART_Init(UART_TypeDef UARTx, UART_Init_TypeDef* UART_InitDef);
void USART_ClockInit();
void USART_Cmd(UART_TypeDef USARTx, FunctionalState NewState);
/*void USART_ITConfig(USART_TypeDef USARTx, USART_IT_TypeDef USART_IT, FunctionalState NewState);
void USART_HalfDuplexCmd(USART_TypeDef USARTx, FunctionalState NewState);
void USART_SetPrescaler(USART_TypeDef USARTx, uint8_t USART_Prescaler);
uint8_t USART_ReceiveData8(USART_TypeDef USARTx);
uint16_t USART_ReceiveData9(USART_TypeDef USARTx);
void USART_SendBreak(USART_TypeDef USARTx);
void USART_SendData8(USART_TypeDef USARTx, uint8_t Data);
void USART_SendData9(USART_TypeDef USARTx, uint16_t Data);
FlagStatus USART_GetFlagStatus(USART_TypeDef USARTx, USART_FLAG_TypeDef USART_FLAG);
void USART_ClearFlag(USART_TypeDef USARTx, USART_FLAG_TypeDef USART_FLAG);
ITStatus USART_GetITStatus(USART_TypeDef USARTx, USART_IT_TypeDef USART_IT);
void USART_ClearITPendingBit(USART_TypeDef USARTx, USART_IT_TypeDef USART_IT);*/
/**
  * @}
  */

#endif /* __CMS8S003x_UART_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
