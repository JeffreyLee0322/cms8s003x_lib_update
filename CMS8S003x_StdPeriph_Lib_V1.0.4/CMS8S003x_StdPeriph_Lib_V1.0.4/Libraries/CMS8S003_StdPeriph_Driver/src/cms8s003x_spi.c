/**
  ******************************************************************************
  * @file    cms8s003x_spi.c
  * @author  LI WEI
  * @version V1.0.0
  * @date    04/26/2018
  * @brief   This file provides all the SPI firmware functions.
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
#include "cms8s003x_spi.h"
#include "cms8s003x_conf.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @addtogroup SPI_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the SPI peripheral registers to their default reset values.
  * @param  None
  * @retval None
  */
void SPI_DeInit(void)
{
  SPI0_SPCR    = SPI_SPCR_RESET_VALUE;
  SPI0_SPCR    = SPI_SSCR_RESET_VALUE;
}

/**
  * @brief  Initializes the SPI according to the specified parameters.
	* @param  SPI_InitDef:
	*					SPI_BaudRatePrescaler : This parameter can be any of the
  *         @ref SPI_BaudRatePrescaler_TypeDef enumeration.
  * 				SPI_Mode : This parameter can be any of the  @ref SPI_Mode_TypeDef
  *         enumeration.
  * 			  SPI_CPOL : This parameter can be any of the @ref SPI_CPOL_TypeDef
  *         enumeration.
  * 			  SPI_CPHA : This parameter can be any of the @ref SPI_CPHA_TypeDef
  *         enumeration.
  * @retval None
  */
void SPI_Init(SPI_Init_TypeDef* SPI_InitDef)
{
  /* Check structure elements */
  assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_InitDef->SPI_Frequency));
  assert_param(IS_SPI_MODE(SPI_InitDef->SPI_Mode));
  assert_param(IS_SPI_POLARITY(SPI_InitDef->SPI_CPOL));
  assert_param(IS_SPI_PHASE(SPI_InitDef->SPI_CPHA));

  /* Frame Format, BaudRate, Clock Polarity ,Mode, CPOL and CPHA configuration */
	SPI0_SPCR = (SPI_InitDef->SPI_Mode) | (SPI_InitDef->SPI_CPOL) | (SPI_InitDef->SPI_CPHA) | (SPI_InitDef->SPI_Frequency);
}

/**
  * @brief  Enables or disables the SPI peripheral.
  * @param  NewState New state of the SPI peripheral.
  *         This parameter can be: ENABLE or DISABLE
  * @retval None
  */
void SPI_Cmd(FunctionalState NewState)
{
  /* Check function parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != _DISABLE)
  {
		SPI0_SPCR |= SPEN_ENABLE_BIT; /* Enable the SPI peripheral*/
  }
  else
  {
		SPI0_SPCR &= (uint8_t)(~SPEN_ENABLE_BIT); /* Disable the SPI peripheral*/
  }
}

/**
  * @brief  Enables or disables the specified interrupts.
  * @param  Priority Specifies the SPI interrupts priority.
  * @param  NewState: The new state of the specified SPI interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void SPI_ITConfig(InterruptPriority Priority, FunctionalState NewState)
{
  /* Check function parameters */
  assert_param(IS_SPI_PRIORITY(Priority));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  /* Set the SPI priority*/
  EIP2 |= Priority;

  /* Set the SPI IT mask Register */
  if (NewState != _DISABLE)
  {
    EIE2 |= SPIIE_ENABLE_BIT; /* Enable the SPI IT */
  }
  else
  {
    EIE2 &= (uint8_t)(~SPIIE_ENABLE_BIT); /* Disable the SPI IT */
  }
}


/**
  * @brief  Transmits a Data through the SPI peripheral.
  * @param  SPIx : where x is 0 to select the specified SPI peripheral.
  * @param  Data : Byte to be transmitted.
  * @retval None
  */
void SPI_SendData(uint8_t Data)
{
  //SPIx->SPDR = Data; /* Write in the SPDR register the data to be sent*/
	SPI0_SPDR = Data; /* Write in the SPDR register the data to be sent*/
}

/**
  * @brief  Returns the most recent received data by the SPI peripheral.
  * @param  SPIx : where x is 0 to select the specified SPI peripheral.
  * @retval The value of the received data.
  */
uint8_t SPI_ReceiveData(void)
{
  return ((uint8_t)SPI0_SPDR); /* Return the data in the SPDR register*/
}


/**
  * @brief  Configures internally by software the NSS pin.
  * @param  SPIx : where x is 0 to select the specified SPI peripheral.
  * @param  Ss0x : where x is 0 to 7.
  * @param  NewState Indicates the new state of the SPI Software slave management.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void SPI_NSSInternalSoftwareCmd(SPI_SSCR_TypeDef Ss0x, FunctionalState NewState)
{
  /* Check function parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));
	
  /* Set SSCR Register */
  SPI0_SSCR = Ss0x;
	 
  ///* Set SPI Master Mode SSO Output Control bit*/
  if (NewState != _DISABLE)
  {
    SPI0_SPSR |= SPSR_SSCEN_ENABLE_BIT;    /* Set NSS pin internally by software*/
  }
  else
  {
    SPI0_SPSR &= (uint8_t)(~SPSR_SSCEN_ENABLE_BIT); /* Reset NSS pin internally by software*/
  }
}

/**
  * @brief  Checks whether the specified SPI flag is set or not.
  * @param  SPIx : where x is 0 to select the specified SPI peripheral.
  * @param  SPI_FLAG : Specifies the flag to check.
  * @retval FlagStatus : Indicates the state of SPI_FLAG.
  *         This parameter can be any of the @ref PeripheralInterruptFlags enumeration.
  */
FlagStatus SPI_GetFlagStatus(PeripheralInterruptFlags SPI_FLAG)
{
  FlagStatus status = _RESET;
  /* Check parameters */
  assert_param(IS_SPI_FLAG(SPI_FLAG));

  /* Check the status of the specified SPI flag */
  if ((EIF2 & (uint8_t)SPI_FLAG) != (uint8_t)_RESET)
  {
    status = _SET; /* SPI_FLAG is set */
  }
  else
  {
    status = _RESET; /* SPI_FLAG is reset*/
  }
  return status;
}


/**
  * @brief  Checks whether the specified interrupt has occurred or not.
  * @param  SPIx : where x is 0 to select the specified SPI peripheral.
  * @param  SPI_FLAG: Specifies the SPI interrupt pending bit to check.
  *         This parameter can be one of the following values:
  *         	SPI_FLAG_SPISIF
				SPI_FLAG_WCOL
				SPI_FLAG_MODF
  * @retval ITStatus : Indicates the state of the SPI_FLAG.
  *         This parameter can be any of the @ref ITStatus enumeration.
  */
ITStatus SPI_GetITStatus(SPI_IT_TypeDef SPI_FLAG)
{
  ITStatus status = _RESET;
  /* Check parameters */
  assert_param(IS_SPI_FLAG(SPI_FLAG));
  
  /* Check the status of the specified SPI flag */
  if ((SPI0_SPSR & (uint8_t)SPI_FLAG) != (uint8_t)_RESET)
  {
    status = _SET; /* SPI_FLAG is set */
  }
  else
  {
    status = _RESET; /* SPI_FLAG is reset*/
  }

  /* Return the SPI_FLAG status */
  return status;
}

/**
  * @brief  Clears the interrupt pending bits.
  * @note   - OVR (OverRun Error) interrupt pending bit is cleared by software sequence:
  *         a read operation to SPI_DR register (SPI_ReceiveData()) followed by
  *         a read operation to SPI_SR register (SPI_GetITStatus()).
  *         - MODF (Mode Fault) interrupt pending bit is cleared by software sequence:
  *         a read/write operation to SPI_SR register (SPI_GetITStatus()) followed by
  *         a write operation to SPI_CR register (SPI_Cmd() to enable the SPI).
  * @retval None
  */
void SPI_ClearITPendingBit(SPI_IT_TypeDef SPI_IT)
{
	//NOT USE!!!
}

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
