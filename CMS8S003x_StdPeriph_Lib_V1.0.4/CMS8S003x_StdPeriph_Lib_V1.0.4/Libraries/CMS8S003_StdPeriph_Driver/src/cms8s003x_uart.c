/**
  ********************************************************************************
  * @file    cms8s003x_uart.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file provides all the UART firmware functions.
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

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "cms8s003x_uart.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
//#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern uint32_t SystemClock;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

/** @}
  * @addtogroup UART_Public_Functions
  * @{
  */

/**
  * @brief   Deinitializes the USART peripheral.
  * @param  UARTx : where x can be 1, 2 or 3 to select the specified USART peripheral.
  * @retval None
  */
void UART_DeInit(UART_TypeDef UARTx)
{

}

/**
  * @brief  Initializes the UART according to the specified parameters.
  * @note   Configure in Push Pull or Open Drain mode the Tx pin by setting the
  *         correct I/O Port register according the product package and line
  *         configuration
  * @param  USARTx : where x can be 1 to select the specified USART peripheral.
  * @param  UART_InitDef : Uart initial @ UART_Init_TypeDef.
  * @retval None
  */
void UART_Init(UART_TypeDef UARTx, UART_Init_TypeDef* UART_InitDef)
{
  uint32_t BaudRate_Mantissa = 0;

  /* Check the parameters */

  if(UARTx == UART0)
  {
		SCON0 &= 0;
		SCON0 |= ((uint8_t)(UART_InitDef->Mode) | ((uint8_t)(UART_InitDef->MutiDevices) << 5) | ((uint8_t)(UART_InitDef->IsReceive) << 4) | ((uint8_t)(UART_InitDef->SendData9Bit) << 3) | ((uint8_t)(UART_InitDef->ReceiveData9Bit) << 2));
		
		PCON &= ~0x80;
		PCON |= ((uint8_t)(UART_InitDef->UartBaudrateDouble) << 7);
		
		if((Mode_8Bit_Unsettled_Freq == UART_InitDef->Mode) || (Mode_9Bit_Unsettled_Freq == UART_InitDef->Mode))
		{
			if(Timer1_Select == UART_InitDef->UartClkSource)
			{
				/* Set Timer1 as uart0`s clock source */
				FUNCCR &= 0xfe; 
				//setup timer1
				/* Timer1 TMOD Clear and Set */
				TMOD &= 0x0f;
				TMOD |= 0x20; //GATE1 disable, Timer select, Mode2: 8bit auto reload
				CKCON |= 0x10; //Timer1 clock source: sys/4 (systerm clock is 8MHz/16MHz, if not CLKDIV)  
				TL1 = 256 - SystemClock * (UART_InitDef->UartBaudrateDouble + 1) / 32 / 4 / UART_InitDef->UartBaurdrate;
				TH1 = 256 - SystemClock * (UART_InitDef->UartBaudrateDouble + 1) / 32 / 4 / UART_InitDef->UartBaurdrate;
				IE |= 0x88; //Enable Timer1 interrupt
				TCON |= 0x40; //Timer1 start
			}
			else if(Timer4_Select == UART_InitDef->UartClkSource)
			{
				/* Set Timer4 as uart0`s clock source */
				FUNCCR |= 0x01;
				//setup timer4
				/* Timer4 T34MOD Clear and Set */
				T34MOD &= 0x0f;
				T34MOD |= 0x60; //Timer4 clock select:sys/4, Mode2: 8bit auto reload
				TL4 = 256 - SystemClock * (UART_InitDef->UartBaudrateDouble + 1) / 32 / 4 / UART_InitDef->UartBaurdrate;
				TH4 = 256 - SystemClock * (UART_InitDef->UartBaudrateDouble + 1) / 32 / 4 / UART_InitDef->UartBaurdrate;
				T34MOD |= 0x80; //Timer4 start
			}
		}
  }
	else if(UARTx == UART1)
  {
		SCON1 &= 0;
		SCON1 |= ((uint8_t)(UART_InitDef->Mode) | ((uint8_t)(UART_InitDef->MutiDevices) << 5) | ((uint8_t)(UART_InitDef->IsReceive) << 4) | ((uint8_t)(UART_InitDef->SendData9Bit) << 3) | ((uint8_t)(UART_InitDef->ReceiveData9Bit) << 2));
		
		PCON &= ~0x40;
		PCON |= ((uint8_t)(UART_InitDef->UartBaudrateDouble) << 6);
		
		if((Mode_8Bit_Unsettled_Freq == UART_InitDef->Mode) || (Mode_9Bit_Unsettled_Freq == UART_InitDef->Mode))
		{
			if(Timer1_Select == UART_InitDef->UartClkSource)
			{
				FUNCCR &= 0xfd; 
				//setup timer1
				/* Set Timer1 as uart0`s clock source */
				FUNCCR &= 0xfe; 
				//setup timer1
				/* Timer1 TMOD Clear and Set */
				TMOD &= 0x0f;
				TMOD |= 0x20; //GATE1 disable, Timer select, Mode2: 8bit auto reload
				CKCON |= 0x10; //Timer1 clock source: sys/4 (systerm clock is 8MHz/16MHz, if not CLKDIV)  
				TL1 = 256 - SystemClock * (UART_InitDef->UartBaudrateDouble + 1) / 32 / 4 / UART_InitDef->UartBaurdrate;
				TH1 = 256 - SystemClock * (UART_InitDef->UartBaudrateDouble + 1) / 32 / 4 / UART_InitDef->UartBaurdrate;
				TCON |= 0x40; //Timer1 start
			}
			else if(Timer4_Select == UART_InitDef->UartClkSource)
			{
				FUNCCR |= 0x02;
				//setup timer4
				/* Set Timer4 as uart0`s clock source */
				FUNCCR |= 0x01;
				//setup timer4
				/* Timer4 T34MOD Clear and Set */
				T34MOD &= 0x0f;
				T34MOD |= 0x60; //Timer4 clock select:sys/4, Mode2: 8bit auto reload
				TL4 = 256 - SystemClock * (UART_InitDef->UartBaudrateDouble + 1) / 32 / 4 / UART_InitDef->UartBaurdrate;
				TH4 = 256 - SystemClock * (UART_InitDef->UartBaudrateDouble + 1) / 32 / 4 / UART_InitDef->UartBaurdrate;
				T34MOD |= 0x80; //Timer4 start
			}
		}
  }

}

/**
  * @brief  Enable the USART peripheral.
  * @param  USARTx : where x can be 1 to select the specified USART peripheral.
  * @param  NewState : The new state of the USART Communication.
  *         This parameter can be any of the @ref FunctionalState enumeration.
  * @retval None
  */
void UART_Cmd(UART_TypeDef UARTx, FunctionalState NewState)
{

}


/**
  * @brief  Enables or disables the specified USART interrupts.
  * @param  USARTx : where x can be 1 to select the specified USART peripheral.
  * @param  USART_IT specifies the USART interrupt sources to be enabled or disabled.
  *         This parameter can be one of the following values:
  *         - USART_IT_TXE:  Tansmit Data Register empty interrupt
  *         - USART_IT_TC:   Transmission complete interrupt
  *         - USART_IT_RXNE: Receive Data register not empty interrupt
  *         - USART_IT_OR: Overrun error interrupt
  *         - USART_IT_IDLE: Idle line detection interrupt
  *         - USART_IT_ERR:  Error interrupt
  * @param  NewState new state of the specified USART interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */

void UART_ITConfig(UART_TypeDef UARTx, UART_Priority_TypeDef UART_Priority, FunctionalState NewState)
{
	if(UART0 == UARTx)
	{
		if (NewState != _DISABLE)
		{
			/*Clear and Set uart0 IT priority */
			IP &= ~0x10;
			IP |= (UART_Priority << 4);
			
			IE |= UART0_INTERRUPT_ENABLE_BIT; /* Enable the UART0 IT */
		}
		else
		{
			IE &= (uint8_t)(~UART0_INTERRUPT_ENABLE_BIT); /* Disable the UART0 IT */
		}
	}
	else if(UART1 == UARTx)
	{
		if (NewState != _DISABLE)
		{
			/*Clear and Set uart1 IT priority */
			IP &= ~0x40;
			IP |= (UART_Priority << 6);
			
			IE |= UART1_INTERRUPT_ENABLE_BIT; /* Enable the UART1 IT */
		}
		else
		{
			IE &= (uint8_t)(~UART1_INTERRUPT_ENABLE_BIT); /* Disable the UART1 IT */
		}
	}
}

/**
  * @brief  Returns the most recent received data by the USART peripheral.
  * @param  USARTx : where x can be 1 to select the specified USART peripheral.
  * @retval The received data.
  */
uint8_t UART_ReceiveData8(UART_TypeDef UARTx)
{
	/*uint8_t returnData = 0;
	if(UART0 == UARTx)
	{
			returnData = SBUF0;
	}
	else if(UART1 == UARTx)
	{
			returnData = SBUF1;
	}
	
	return returnData;*/
	return ((UARTx == UART0)?(uint8_t)SBUF0:(uint8_t)SBUF1);
}


/**
  * @brief  Returns the most recent received data by the USART peripheral.
  * @param  USARTx : where x can be 1 to select the specified USART peripheral.
  * @retval The received data.
  */
uint16_t UART_ReceiveData9(UART_TypeDef UARTx)
{
	/*if(UART0 == UARTx)
	{
	
	}
	else if(UART1 == UARTx)
	{
	
	}*/
	return ((UARTx == UART0)?(uint8_t)SBUF0:(uint8_t)SBUF1);
}

/**
  * @brief  Transmits 8 bit data through the USART peripheral.
  * @param  Data: The data to transmit.
  * @retval None
  */
void UART_SendData8(UART_TypeDef UARTx, uint8_t Data)
{
	if(UART0 == UARTx)
	{
			while(1 == ((SCON0 & 0x02)>>1));
			SBUF0 = Data;
			while(0 == ((SCON0 & 0x02)>>1));
			SCON0 &= (~0x02);
	}
	else if(UART1 == UARTx)
	{
			while(1 == ((SCON1 & 0x02)>>1));
			SBUF1 = Data;
			while(0 == ((SCON1 & 0x02)>>1));
			SCON1 &= (~0x02);
	}
}

/**
  * @brief  Transmits 9 bit data through the USART peripheral.
  * @param  USARTx: Select the USARTx peripheral.
  * @param  Data : The data to transmit.
  *         This parameter should be lower than 0x1FF.
  * @retval None
  */
void UART_SendData9(UART_TypeDef UARTx, uint16_t Data)
{
	if(UART0 == UARTx)
	{
			SBUF0 = Data;
	}
	else if(UART1 == UARTx)
	{
			SBUF1 = Data;
	}
}

#if 0
/**
  * @brief  Transmits break characters.
  * @param  USARTx : where x can be 1 to select the specified USART peripheral.
  * @retval None
  */
void USART_SendBreak(USART_TypeDef* USARTx)
{

}

/**
  * @brief  Sets the system clock prescaler.
  * @note   IrDA Low Power mode or smartcard mode should be enabled
  * @note   This function is related to SmartCard and IrDa mode.
  * @param  USARTx: Select the USARTx peripheral.
  * @param  USART_Prescaler: specifies the prescaler clock.
  *         This parameter can be one of the following values:
  *         @par IrDA Low Power Mode
  *         The clock source is diveded by the value given in the register (8 bits)
  *         - 0000 0000 Reserved
  *         - 0000 0001 divides the clock source by 1
  *         - 0000 0010 divides the clock source by 2
  *         - ...........................................................
  *        @par Smart Card Mode
  *        The clock source is diveded by the value given in the register
  *        (5 significant bits) multipied by 2
  *         - 0 0000 Reserved
  *         - 0 0001 divides the clock source by 2
  *         - 0 0010 divides the clock source by 4
  *         - 0 0011 divides the clock source by 6
  *         - ...........................................................
  * @retval None
  */
void USART_SetPrescaler(USART_TypeDef* USARTx, uint8_t USART_Prescaler)
{

}

/**
  * @brief  Sets the address of the USART node.
  * @param  USARTx: Select the USARTx peripheral.
  * @param  Address : Indicates the address of the USART node.
  *         This parameter should be lower than 16
  * @retval None
  */
void USART_SetAddress(USART_TypeDef* USARTx, uint8_t USART_Address)
{

}

/**
  * @brief  Checks whether the specified USART flag is set or not.
  * @param  USARTx: Select the USARTx peripheral.
  * @param  USART_FLAG specifies the flag to check.
  *         This parameter can be any of the @ref USART_FLAG_TypeDef enumeration.
  * @retval FlagStatus (SET or RESET)
  */
FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, USART_FLAG_TypeDef USART_FLAG)
{
  FlagStatus status = RESET;

  
  /* Return the USART_FLAG status*/
  return status;
}

/**
  * @brief  Clears the USARTx's pending flags.
  * @param  USARTx : where x can be 1 to select the specified USART peripheral.
  * @param  USART_FLAG: specifies the flag to clear.
  *         This parameter can be any combination of the following values:
  *         USART_FLAG_TC:   Transmission Complete flag.
  *         USART_FLAG_RXNE: Receive data register not empty flag.
  *
  * @Note
  *     - PE (Parity error), FE (Framing error), NE (Noise error), OR (OverRun error)
  *       and IDLE (Idle line detected) flags are cleared by software sequence: a read
  *       operation to USART_SR register (USART_GetFlagStatus())followed by a read
  *       operation to USART_DR register(USART_ReceiveData8() or USART_ReceiveData9()).
  *
  *     - RXNE flag can be also cleared by a read to the USART_DR register
  *       (USART_ReceiveData8()or USART_ReceiveData9()).
  *
  *     - TC flag can be also cleared by software sequence: a read operation to USART_SR
  *       register (USART_GetFlagStatus()) followed by a write operation to USART_DR
  *       register (USART_SendData8() or USART_SendData9()).
  *
  *     - TXE flag is cleared only by a write to the USART_DR register
  *       (USART_SendData8() or USART_SendData9()).
  *
  *     - SBK flag is cleared during the stop bit of break.
  *
  * @retval None
  */
void USART_ClearFlag(USART_TypeDef* USARTx, USART_FLAG_TypeDef USART_FLAG)
{
  
}
#endif

/**
  * @brief  Checks whether the specified USART interrupt has occurred or not.
  * @param  USARTx : where x can be 1 to select the specified USART peripheral.
  * @param  USART_IT: Specifies the USART interrupt pending bit to check.
  *         This parameter can be one of the following values:
  *         - USART_IT_TXE: Transmit Data Register empty interrupt
  *         - USART_IT_TC: Transmission complete interrupt
  *         - USART_IT_RXNE: Receive Data register not empty interrupt
  *         - USART_IT_IDLE: Idle line detection interrupt
  *         - USART_IT_OR: OverRun Error interrupt
  *         - USART_IT_PE: Parity Error interrupt
  *         - USART_IT_FE: Frame Error interrupt
  *         - USART_IT_NF: Noise Flag Error interrupt
  * @retval ITStatus The new state of USART_IT (SET or RESET).
  */
ITStatus UART_GetITStatus(UART_TypeDef UARTx, UART_IT_Status_TypeDef UART_IT)
{
  ITStatus bitstatus = _RESET;
	uint8_t UART_itStatus = 0x0;
  
	if(UART0 == UARTx)
	{
		UART_itStatus = SCON0 & UART_IT;
	}
	else if(UART1 == UARTx)
	{
		UART_itStatus = SCON1 & UART_IT;
	}
	
	if (UART_itStatus != (uint8_t)_RESET )
  {
    bitstatus = _SET;
  }
  else
  {
    bitstatus = _RESET;
  }

  /* Return the USART_IT status*/
  return  bitstatus;
}

/**
  * @brief  Clears the USARTx’s interrupt pending bits.
  * @param  USARTx : where x can be 1 to select the specified USART peripheral.
  * @param  USART_IT: specifies the interrupt pending bit to clear.
  *         This parameter can be one of the following values:
  *         USART_IT_RXNE: Receive Data register not empty interrupt.
  *         USART_IT_TC:   Transmission complete interrupt.
  *
  * @note
  *         - PE (Parity error), FE (Framing error), NE (Noise error),
  *         OR (OverRun error) and IDLE (Idle line detected) pending bits are
  *         cleared by software sequence: a read operation to USART_SR register
  *         (USART_GetITStatus()) followed by a read operation to USART_DR
  *         register (USART_ReceiveData8() or USART_ReceiveData9()).
  *
  *         - RXNE pending bit can be also cleared by a read to the USART_DR register
  *         (USART_ReceiveData8() or USART_ReceiveData9()).
  *
  *         - TC (Transmit complet) pending bit can be also cleared by software
  *         sequence: a read operation to USART_SR register (USART_GetITStatus())
  *         followed by a write operation to USART_DR register (USART_SendData8()
  *         or USART_SendData9()).
  *
  *         - TXE pending bit is cleared only by a write to the USART_DR register
  *         (USART_SendData8() or USART_SendData9()).
  *
  * @retval None
  */
void UART_ClearITPendingBit(UART_TypeDef UARTx, UART_IT_Status_TypeDef UART_IT)
{
	if(UART0 == UARTx)
	{
		SCON0 = (~UART_IT);
	}
	else if(UART1 == UARTx)
	{
		SCON1 = (~UART_IT);
	}
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
#if 0
//PUTCHAR_PROTOTYPE
//int fputc(int ch, FILE *f)
int fputc(int ch, const char *f)
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the UART0 */
  UART_SendData8(UART0, (uint8_t) ch);
	
  /* Loop until the end of transmission */
  //while (USART_GetFlagStatus(UART0, USART_FLAG_TC) == RESET)
  //{}

  return ch;
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemion *****END OF FILE****/
