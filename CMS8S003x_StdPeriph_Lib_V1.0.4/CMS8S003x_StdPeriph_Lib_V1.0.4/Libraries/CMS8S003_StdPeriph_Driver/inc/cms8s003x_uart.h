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
#include "cms8s003x.h"
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
  * @brief UART Word length possible values
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
  * @brief USART Last Bit possible values
  */
typedef enum
{
  USART_LastBit_Disable  = (uint8_t)0x00,  /*!< The clock pulse of the last data bit is not output to the SCLK pin.*/
  USART_LastBit_Enable   = (uint8_t)0x01   /*!< The clock pulse of the last data bit is output to the SCLK pin.*/
} USART_LastBit_TypeDef;




typedef enum
{
	Mode_8Bit_Settled_Freq 	 = 	(uint8_t)0x00,	//Fsys/12 					/* Master control synchronize mode 0 */
	Mode_8Bit_Unsettled_Freq = 	(uint8_t)0x40,	//variable 					/* 8 bit asynchronize mode 1 */
	Mode_9Bit_Settled_Freq 	 = 	(uint8_t)0x80,	//Fsys/32 or /64 		/* 9 bit asynchronize mode 2 */
	Mode_9Bit_Unsettled_Freq = 	(uint8_t)0xC0		//variable  				/* 9 bit asynchronize mode 3 */
} UART_Mode_TypeDef;

typedef enum
{
	Data_9Bit_Is0 = (uint8_t)0x00, /* Data ninth bi is 0 */
	Data_9Bit_Is1 = (uint8_t)0x01, /* Data ninth bi is 1 */
} UART_Data_9Bit_TypeDef;

typedef enum
{
	Baudrate_Normal = (uint8_t)0x00, /* Baudrate is not double */
	Baudrate_Double = (uint8_t)0x01, /* Baudrate is double */
} UART_Baudrate_Double_TypeDef;

typedef enum
{
	Timer1_Select 			= (uint8_t)0x00, /* Uart clock source is timer1 */
	Timer4_Select 			= (uint8_t)0x01, /* Uart clock source is timer4 */
	Timer_SysClk_Select = (uint8_t)0x01, /* Uart clock source is systerm clock */
} UART_CLK_Source_TypeDef;

#if 0
typedef enum
{
	Baudrate_9600 		= (uint32_t)9600, /* Baudrate is 9600 */
	Baudrate_14400 		= (uint32_t)14400, /* Baudrate is 14400 */
	Baudrate_38400 		= (uint32_t)38400, /* Baudrate is 38400 */
	Baudrate_57600 		= (uint32_t)57600, /* Baudrate is 57600 */
	//Baudrate_115200 	= (uint32_t)115200, /* Baudrate is 115200 */
} UART_Baudrate_TypeDef;
#endif

typedef enum
{
	HIGH_Priority 	= 	(uint8_t)0x01,
	LOW_Priority 		=  	(uint8_t)0x00,
} UART_Priority_TypeDef;

typedef enum
{
	Send_IT_Status     	=   (uint8_t)0x02,
	Receive_IT_Status   =   (uint8_t)0x01,
} UART_IT_Status_TypeDef;


typedef struct UART_INIT
{
	UART_Mode_TypeDef 						Mode;
	FunctionalState 							MutiDevices;
	FunctionalState 							IsReceive;
	UART_Data_9Bit_TypeDef 				SendData9Bit;
	UART_Data_9Bit_TypeDef 				ReceiveData9Bit;
	UART_Baudrate_Double_TypeDef 	UartBaudrateDouble;
	UART_CLK_Source_TypeDef 			UartClkSource;
	uint32_t         							UartBaurdrate;
} UART_Init_TypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
#define UART0_INTERRUPT_ENABLE_BIT  0x10
#define UART1_INTERRUPT_ENABLE_BIT  0x40

/** @addtogroup UART_Private_Macros
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

void UART_DeInit(UART_TypeDef UARTx);
void UART_Init(UART_TypeDef UARTx, UART_Init_TypeDef* UART_InitDef);
void UART_ClockInit();
void UART_Cmd(UART_TypeDef UARTx, FunctionalState NewState);
void UART_ITConfig(UART_TypeDef UARTx, UART_Priority_TypeDef UART_Priority, FunctionalState NewState);
uint8_t UART_ReceiveData8(UART_TypeDef UARTx);
uint16_t UART_ReceiveData9(UART_TypeDef UARTx);
void UART_SendData8(UART_TypeDef UARTx, uint8_t Data);
void UART_SendData9(UART_TypeDef UARTx, uint16_t Data);
/*
void USART_SetPrescaler(USART_TypeDef USARTx, uint8_t USART_Prescaler);
void USART_SendBreak(USART_TypeDef USARTx);
*/
//FlagStatus UART_GetFlagStatus(UART_TypeDef USARTx, USART_FLAG_TypeDef USART_FLAG);
//void USART_ClearFlag(USART_TypeDef USARTx, USART_FLAG_TypeDef USART_FLAG);
ITStatus UART_GetITStatus(UART_TypeDef UARTx, UART_IT_Status_TypeDef UART_IT);
void UART_ClearITPendingBit(UART_TypeDef UARTx, UART_IT_Status_TypeDef UART_IT);
/**
  * @}
  */

#endif /* __CMS8S003x_UART_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
