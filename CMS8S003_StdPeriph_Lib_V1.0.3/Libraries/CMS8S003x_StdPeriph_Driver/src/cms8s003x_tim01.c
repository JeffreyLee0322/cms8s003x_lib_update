/**
  ******************************************************************************
  * @file    cms8s003x_tim1.c
  * @author  LI WEI
  * @version V1.0.0
  * @date    04/24/2018
  * @brief   This file provides all the TIM1 firmware functions.
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
#include "cms8s003x_tim01.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/**
  * @addtogroup TIM0_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the TIM0 peripheral registers to their default reset values.
  * @param  None
  * @retval None
  */
void TIM0_DeInit(void)
{
	TMOD &= 0xf0; //timer0 gate set 0
	TCON &= 0xCF; //timer0  control register clear
}

void TIM1_DeInit(void)
{
	TMOD &= 0xf; //timer1 gate set 0
	TCON &= 0x3F; //timer1  control register clear
}

void TIM0_Init(TIM01_Init_TypeDef *TIM0_InitDef)
{
	TMOD &= 0xf8; //GATE0/CT0/TOM0 clear 0-2 bit, set GATE0 bit.

	//CKCON clear 3 bit
	CKCON &= 0xf7;

	//Set
	TMOD |= (((uint8_t)((TIM0_InitDef->Timer_Function) << 2)) | ((uint8_t)(TIM0_InitDef->Timer_Mode)));
	CKCON |= ((uint8_t)((TIM0_InitDef->Timer_Clock) << 3));

	if((TIM0_InitDef->Timer_Mode) == Mode0_13Bit_Timer_Counter)
	{
		TH0 = (uint8_t)((TIM0_InitDef->Timer_InitValue)>>5);
		TL0 = (uint8_t)((TIM0_InitDef->Timer_InitValue)&0x1f);
	}else if((TIM0_InitDef->Timer_Mode) == Mode1_16Bit_Timer_Counter)
	{
		TH0 = (uint8_t)((TIM0_InitDef->Timer_InitValue)>>8);
		TL0 = (uint8_t)((TIM0_InitDef->Timer_InitValue)&0xff);
	}else if((TIM0_InitDef->Timer_Mode) == Mode2_8Bit_AutoLoad_Timer_Counter)
	{
		TH0 = (uint8_t)((TIM0_InitDef->Timer_InitValue)&0xff);
		TL0 = (uint8_t)((TIM0_InitDef->Timer_InitValue)&0xff);
	}else
	{

	}
}

void TIM1_Init(TIM01_Init_TypeDef *TIM1_InitDef)
{

}

void TIM0_Cmd(FunctionalState NewState)
{
	if (NewState != _DISABLE)
	{
		TCON |= TIMER0_START_BIT; /* Enable the TIMER0*/
	}
	else
	{
		TCON &= (uint8_t)(~TIMER0_START_BIT); /* Disable the TIMER0*/
	}
}

void TIM1_Cmd(FunctionalState NewState)
{
	if (NewState != _DISABLE)
	{
		TCON |= TIMER1_START_BIT; /* Enable the TIMER0*/
	}
	else
	{
		TCON &= (uint8_t)(~TIMER1_START_BIT); /* Disable the TIMER0*/
	}
}


void TIM0_ITConfig(TIM_PriorityTypeDef TIM0_Priority, FunctionalState NewState)
{
	IP &= 0xfd;	//clear bit 1
	IP |= (TIM0_Priority<<1);
	
	/* Set the SPI IT mask Register */
	if (NewState != _DISABLE)
	{
	  IE |= TIME0_INTERRUPT_ENABLE_BIT; /* Enable the SPI IT */
	}
	else
	{
	  IE &= (uint8_t)(~TIME0_INTERRUPT_ENABLE_BIT); /* Disable the SPI IT */
	}
}

void TIM1_ITConfig(TIM_PriorityTypeDef TIM1_Priority, FunctionalState NewState)
{
	IP &= 0xf7;	//clear bit 3
	IP |= (TIM1_Priority<<3);
	
	/* Set the SPI IT mask Register */
	if (NewState != _DISABLE)
	{
	  IE |= TIME1_INTERRUPT_ENABLE_BIT; /* Enable the SPI IT */
	}
	else
	{
	  IE &= (uint8_t)(~TIME1_INTERRUPT_ENABLE_BIT); /* Disable the SPI IT */
	}
}

/**
  * @brief  Gets the TIM1 Counter value.
  * @param  None
  * @retval Counter Register value.
  */
uint16_t TIM0_GetCounter(void)
{
  /* Get the Counter Register value */
  uint16_t tmpcntr = 0;
  uint8_t tmpcntrl = 0, tmpcntrh = 0;

  tmpcntrh = TH0;
  tmpcntrl = TL0;

  tmpcntr  = (uint16_t)(tmpcntrl);
  tmpcntr |= (uint16_t)((uint16_t)tmpcntrh << 8);

  /* Get the Counter Register value */
  return (uint16_t)tmpcntr;
}

uint16_t TIM1_GetCounter(void)
{
	/* Get the Counter Register value */
  uint16_t tmpcntr = 0;
  uint8_t tmpcntrl = 0, tmpcntrh = 0;

  tmpcntrh = TH1;
  tmpcntrl = TL1;

  tmpcntr  = (uint16_t)(tmpcntrl);
  tmpcntr |= (uint16_t)((uint16_t)tmpcntrh << 8);

  /* Get the Counter Register value */
  return (uint16_t)tmpcntr;
}
/**
  * @brief  Checks whether the TIM1 interrupt has occurred or not.
  * @param  TIM1_IT specifies the TIM1 interrupt source to check.
  *   This parameter can be one of the @ref TIM1_IT_TypeDef enumeration.
  * @retval ITStatus The new state of the TIM1_IT(SET or RESET).
  */

ITStatus TIM0_GetITStatus(void)
{
  ITStatus bitstatus = _RESET;

  uint8_t TIM0_itStatus = 0x0;

  /* Check the parameters */
  //assert_param(IS_TIM1_GET_IT(TIM1_IT));

  TIM0_itStatus = (uint8_t)(TCON & 0x20);

  if (TIM0_itStatus != (uint8_t)_RESET )
  {
    bitstatus = _SET;
  }
  else
  {
    bitstatus = _RESET;
  }
  return (ITStatus)(bitstatus);
}

ITStatus TIM1_GetITStatus(void)
{
	ITStatus bitstatus = _RESET;

  uint8_t TIM0_itStatus = 0x0;

  /* Check the parameters */
  //assert_param(IS_TIM1_GET_IT(TIM1_IT));

  TIM0_itStatus = (uint8_t)(TCON & 0x80);

  if (TIM0_itStatus != (uint8_t)_RESET )
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
  * @brief  Clears the TIM0's interrupt pending bits.
  * @param  TIM1_IT specifies the pending bit to clear.
  *   This parameter can be one of the @ref TIM1_IT_TypeDef enumeration.
  * @retval None.
  */
void TIM0_ClearITPendingBit(void)
{
	TCON &= 0xdf;
}

void TIM1_ClearITPendingBit(void)
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
