/**
  ******************************************************************************
  * @file    cms8s003x_iic.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file provides all the IIC firmware functions.
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
#include "cms8s003x_iic.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

/**
  * @addtogroup IIC_Public_Functions
  * @{
  */
sfr I2CMSR   = 0xF5;
sfr I2CSSR   = 0xF5;
/**
  * @brief  Deinitializes the IIC peripheral registers to their default
  *         reset values.
  * @param  None
  * @retval None
  */
static void IIC_DeInit(void)
{
	/* IIC Master register deinit */
	I2CMTP &= 0x00;  	//Master mode period register deinit
	I2CMCR &= 0x00;  	//Master mode control register deinit
	I2CMSR &= 0x00;
	I2CMSR |= 0x20;  	//Master mode state register deinit
	I2CMSA &= 0x00;  	//Master mode slave address register deinit
	I2CMBUF &= 0x00;  //Master mode send/receive register deinit

	/* IIC Slave register deinit */
	I2CSADR &= 0x00;  //Slave mode own address register deinit
	I2CSCR &= 0x00;   //Slave mode control register deinit
	I2CSSR &= 0x00;   //Slave mode state register deinit
	I2CSBUF &= 0x00;  //Slabe mode send/receive register deinit
}

/**
  * @brief  Initializes the IIC function according to the specified parameters.
  * @param  IIC_Init IIC initial.
  *         This parameter can be one of the values of @ref IIC_Init_TypeDef.
  * @retval None
  */
void IIC_Init(IIC_Init_TypeDef *IIC_Init)
{
	IIC_DeInit();

	if((uint8_t)(IIC_Init->IIC_Mode) == IIC_Mode_Master)
	{
			/* Master mode period register Set */
			I2CMTP = (uint8_t)IIC_Init->IIC_Frequency;

			/* Master  */
			if((uint8_t)(IIC_Init->IIC_HighSpeed) == IIC_HighSpeed_Enable)
			{
				/* High Speed period timer enable */
				I2CMTP |= 0x80;

				/* High Speed Mode enable */
				I2CMCR = 0x10;
			}
			else if((uint8_t)(IIC_Init->IIC_HighSpeed) == IIC_HighSpeed_Disable)
			{

			}
			else
			{
				while(1);
			}
			
			/* Slave Address Set */
			I2CMSA = 0;
			I2CMSA |= (((uint8_t)(IIC_Init->IIC_SlaveAddress)) | ((uint8_t)(IIC_Init->IIC_Direction)));

			//I2CMCR |= ((uint8_t)(IIC_Init->IIC_MasterMode & (~0x03)));
			/* IIC ACK Set */
			I2CMSA |= ((uint8_t)IIC_Init->IIC_ACK);
	}
	else
	{
			/* Slave Own address config */
			I2CSADR = (uint8_t)IIC_Init->IIC_OwnAddress;
			
			/* Slave Reset config */
			I2CSCR = (uint8_t)IIC_Init->IIC_Reset;
	}
}

/**
  * @brief  Enable or disable the IIC function.
  * @param  NewState Indicates the new state of the IIC function.
  * @retval None
  */
void IIC_Cmd(FunctionalState NewState)
{

  if (NewState != DISABLE)
  {
    /* Enable the BEEP peripheral */
    //BEEP->CSR2 |= BEEP_CSR2_BEEPEN;
  }
  else
  {
    /* Disable the BEEP peripheral */
    //BEEP->CSR2 &= (uint8_t)(~BEEP_CSR2_BEEPEN);
  }
}

void IIC_AckConfig(IIC_Ack_TypeDef Ack)
{
	if (Ack != IIC_Ack_Disable)
  {
    /* Enable the IIC ACK */
    I2CMSA |= (uint8_t)Ack;
  }
  else
  {
    /* Disable the IIC ACK */
    I2CMSA &= (uint8_t)(~Ack);
  }
}

void IIC_MasterSendData(uint8_t Data)
{
	I2CMBUF = Data;
}

uint8_t IIC_MasterReceiveData(void)
{
	uint8_t receiveData = 0;
	receiveData = I2CMBUF;
	return receiveData;
}

void IIC_ITConfig(IIC_ITPriority_TypeDef ITPriority, FunctionalState NewState)
{
	/* Set the IIC priority*/
  EIP2 |= ITPriority;

  /* Set the IIC IT mask Register */
  if (NewState != _DISABLE)
  {
    EIE2 |= IIC_IT_ENABLE_BIT; /* Enable the IIC IT */
  }
  else
  {
    EIE2 &= (uint8_t)(~IIC_IT_ENABLE_BIT); /* Disable the IIC IT */
  }
}

void IIC_Start(void)
{
	/* Start & Run Set 1 */
	I2CMCR |= 0x03;
}

void IIC_Stop(void)
{
	/* Stop Set 1 */
	I2CMCR |= 0x04;
}

uint8_t IIC_MasterGetSendBuf(void)
{
	uint8_t sendData = 0;
	sendData = I2CMBUF;
	
	return sendData;
}

uint8_t IIC_MasterGetReceiveBuf(void)
{
	uint8_t receiveData = 0;
	receiveData = I2CMBUF;
	
	return receiveData;
}

void IIC_SlaveCmd(FunctionalState NewState)
{
	if (NewState != _DISABLE)
  {
		I2CSCR |= IIC_SLAVE_MODE_ENABLE; /* Enable the IIC Slave */
  }
  else
  {
		I2CSCR &= (uint8_t)(~IIC_SLAVE_MODE_ENABLE); /* Disable the IIC Slave */
  }
}

void IIC_SlaveReset(void)
{
	I2CSCR |= IIC_SLAVE_RESET_ENABLE;
}

void IIC_SlaveSendData(uint8_t Data)
{
	I2CSBUF = Data;
}

uint8_t IIC_SlaveReceiveData(void)
{
	uint8_t ReceiveData = 0;
	
	ReceiveData = I2CSBUF;
	
	return I2CSBUF;
}


FlagStatus IIC_GetFlagStatus(IIC_Flag_TypeDef IIC_Flag)
{
	FlagStatus status = _RESET;

  /* Check the status of the specified SPI flag */
  if ((I2CMSR & (uint8_t)IIC_Flag) != (uint8_t)_RESET)
  {
    status = _SET; /* SPI_FLAG is set */
  }
  else
  {
    status = _RESET; /* SPI_FLAG is reset*/
  }
  return status;
}

void IIC_ClearFlag(IIC_Flag_TypeDef IIC_FLAG)
{
	I2CMSR &= (uint8_t)(~IIC_FLAG);
}

ITStatus IIC_GetITStatus(IIC_ITStatus_TypeDef IIC_ITPendingBit)
{
	ITStatus status = _RESET;

  /* Check the status of the specified IIC flag */
  if ((EIF2 & (uint8_t)IIC_ITPendingBit) != (uint8_t)_RESET)
  {
    status = _SET; /* IIC IT Status is set */
  }
  else
  {
    status = _RESET; /* IIC IT Status is reset*/
  }

  /* Return the IIC IT status */
  return status;
}

void IIC_ClearITPendingBit(IIC_ITStatus_TypeDef IIC_ITPendingBit)
{
  //NO Used!!!
}


/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
