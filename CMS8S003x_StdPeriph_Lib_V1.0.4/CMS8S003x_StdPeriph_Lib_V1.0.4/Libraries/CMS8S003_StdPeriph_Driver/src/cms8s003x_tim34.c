/**
  ******************************************************************************
  * @file    cms8s003x_tim34.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file provides all the TIM34 firmware functions.
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
#include "cms8s003x_tim34.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/**
  * @addtogroup TIM34_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the TIM34 peripheral registers to their default reset values.
  * @param  None
  * @retval None
  */
void TIM3_DeInit(void)
{
	TMOD &= 0xf0; //timer3 gate set 0
	TCON &= 0xCF; //timer3  control register clear
}

void TIM4_DeInit(void)
{
	TMOD &= 0xf; //timer4 gate set 0
	TCON &= 0x3F; //timer4  control register clear
}

void TIM3_Init(TIM34_Init_TypeDef *TIM3_InitDef)
{
	TMOD &= 0xf0; //GATE0/CT0/TOM0 clear 0-3 bit

	//CKCON clear 3 bit
	CKCON &= 0xf7;
	
	//set GATE0 bit.
	//TMOD |= 0x08;

	//Set
	TMOD |= (((uint8_t)((TIM3_InitDef->Timer_Function) << 2)) | ((uint8_t)(TIM3_InitDef->Timer_Mode)));
	CKCON |= ((uint8_t)((TIM3_InitDef->Timer_Clock) << 3));

	if((TIM3_InitDef->Timer_Mode) == TIM34_Mode0_13Bit_Timer_Counter)
	{
		TH3 = (uint8_t)((TIM3_InitDef->Timer_InitValue)>>5);
		TL3 = (uint8_t)((TIM3_InitDef->Timer_InitValue)&0x1f);
	}else if((TIM3_InitDef->Timer_Mode) == TIM34_Mode1_16Bit_Timer_Counter)
	{
		TH3 = (uint8_t)((TIM3_InitDef->Timer_InitValue)>>8);
		TL3 = (uint8_t)((TIM3_InitDef->Timer_InitValue)&0xff);
	}else if((TIM3_InitDef->Timer_Mode) == TIM34_Mode2_8Bit_AutoLoad_Timer_Counter)
	{
		TH3 = (uint8_t)((TIM3_InitDef->Timer_InitValue)&0xff);
		TL3 = (uint8_t)((TIM3_InitDef->Timer_InitValue)&0xff);
	}else
	{

	}
}

void TIM4_Init(TIM34_Init_TypeDef *TIM4_InitDef)
{

}

void TIM3_Cmd(FunctionalState NewState)
{
	if (NewState != _DISABLE)
	{
		TCON |= TIMER3_START_BIT; /* Enable the TIMER0*/
	}
	else
	{
		TCON &= (uint8_t)(~TIMER3_START_BIT); /* Disable the TIMER0*/
	}
}

void TIM4_Cmd(FunctionalState NewState)
{
	if (NewState != _DISABLE)
	{
		TCON |= TIMER4_START_BIT; /* Enable the TIMER0*/
	}
	else
	{
		TCON &= (uint8_t)(~TIMER4_START_BIT); /* Disable the TIMER0*/
	}
}


void TIM3_ITConfig(TIM34_PriorityTypeDef TIM34_Priority, FunctionalState NewState)
{
	IP &= 0xfd;	//clear bit 1
	IP |= (TIM34_Priority<<1);
	
	/* Set the SPI IT mask Register */
	if (NewState != _DISABLE)
	{
	  IE |= TIME3_INTERRUPT_ENABLE_BIT; /* Enable the SPI IT */
	}
	else
	{
	  IE &= (uint8_t)(~TIME3_INTERRUPT_ENABLE_BIT); /* Disable the SPI IT */
	}
}

void TIM4_ITConfig(TIM34_PriorityTypeDef TIM34_Priority, FunctionalState NewState)
{
	IP &= 0xf7;	//clear bit 3
	IP |= (TIM34_Priority<<3);
	
	/* Set the SPI IT mask Register */
	if (NewState != _DISABLE)
	{
	  IE |= TIME4_INTERRUPT_ENABLE_BIT; /* Enable the SPI IT */
	}
	else
	{
	  IE &= (uint8_t)(~TIME4_INTERRUPT_ENABLE_BIT); /* Disable the SPI IT */
	}
}

/**
  * @brief  Gets the TIM34 Counter value.
  * @param  None
  * @retval Counter Register value.
  */
uint16_t TIM3_GetCounter(void)
{
  /* Get the Counter Register value */
  uint16_t tmpcntr = 0;
  uint8_t tmpcntrl = 0, tmpcntrh = 0;

  tmpcntrh = TH3;
  tmpcntrl = TL3;

  tmpcntr  = (uint16_t)(tmpcntrl);
  tmpcntr |= (uint16_t)((uint16_t)tmpcntrh << 8);

  /* Get the Counter Register value */
  return (uint16_t)tmpcntr;
}

uint16_t TIM4_GetCounter(void)
{
	/* Get the Counter Register value */
  uint16_t tmpcntr = 0;
  uint8_t tmpcntrl = 0, tmpcntrh = 0;

  tmpcntrh = TH4;
  tmpcntrl = TL4;

  tmpcntr  = (uint16_t)(tmpcntrl);
  tmpcntr |= (uint16_t)((uint16_t)tmpcntrh << 8);

  /* Get the Counter Register value */
  return (uint16_t)tmpcntr;
}

/**
  * @brief  Get the TIM3 interrupt Flags.
  * @retval ITStatus The new state of the TIM1_IT(SET or RESET).
  */

ITStatus TIM3_GetITStatus(void)
{
  ITStatus bitstatus = _RESET;

  uint8_t TIM3_itStatus = 0x0;

  /* Check the parameters */
  //assert_param(IS_TIM1_GET_IT(TIM1_IT));

  TIM3_itStatus = (uint8_t)(TCON & 0x20);

  if (TIM3_itStatus != (uint8_t)_RESET )
  {
    bitstatus = _SET;
  }
  else
  {
    bitstatus = _RESET;
  }
  return (ITStatus)(bitstatus);
}

ITStatus TIM4_GetITStatus(void)
{
	ITStatus bitstatus = _RESET;

  uint8_t TIM4_itStatus = 0x0;

  /* Check the parameters */
  //assert_param(IS_TIM1_GET_IT(TIM1_IT));

  TIM4_itStatus = (uint8_t)(TCON & 0x80);

  if (TIM4_itStatus != (uint8_t)_RESET )
  {
    bitstatus = _SET;
  }
  else
  {
    bitstatus = _RESET;
  }
  return (ITStatus)(bitstatus);
}

/**
  * @brief  Clears the TIM34's interrupt pending bits.
  * @param  TIM1_IT specifies the pending bit to clear.
  *   This parameter can be one of the @ref TIM1_IT_TypeDef enumeration.
  * @retval None.
  */
void TIM3_ClearITPendingBit(void)
{
	TCON &= 0xdf;
}

void TIM4_ClearITPendingBit(void)
{
	TCON &= 0x7f;
}
/**
  * @}
  */

/**
  * @}
  */

/************************************ (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
