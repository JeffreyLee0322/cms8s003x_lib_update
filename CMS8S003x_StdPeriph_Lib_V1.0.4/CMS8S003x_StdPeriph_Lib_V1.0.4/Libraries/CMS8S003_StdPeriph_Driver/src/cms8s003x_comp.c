/**
  ******************************************************************************
  * @file    cms8s003x_comp.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file provides all the COMP firmware functions.
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
#include "cms8s003x_comp.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @addtogroup COMP_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the COMPx peripheral registers to their default reset values.
  * @param  None.
  * @retval None.
  */
void COMP_DeInit(COMP_TypeDef COMPn)
{
	if(COMP0 == COMPn)
	{
			C0CON0 &= 0x00;
			C0CON1 &= 0x00;
			C0CON1 |= 0x20;
			C0CON2 &= 0x00;
			CNVRCON &= 0x00;
			CNFBCON &= 0x00;
			CNIE &= 0x00;
			CNIF &= 0x00;
			C0ADJE &= 0x00;
	}
	else if(COMP1 == COMPn)
	{
			C1CON0 &= 0x00;
			C1CON1 &= 0x00;
			C1CON1 |= 0x20;
			C1CON2 &= 0x00;
			CNVRCON &= 0x00;
			CNFBCON &= 0x00;
			CNIE &= 0x00;
			CNIF &= 0x00;
			C1ADJE &= 0x00;
	}
}

/**
  * @brief  Initializes the comparator.
  * @param  COMP_TypeDef : selects the comparator index can
  *         be any of the @ref COMP_TypeDef enumeration.
  * @param  COMP_Init : selects the comparator config @ref COMP_Init_TypeDef enumeation.
  * @retval None.
  */
void COMP_Init(COMP_TypeDef COMPn,COMP_Init_TypeDef *COMP_Init)
{
	COMP_DeInit(COMPn);
	
	if(COMP0 == COMPn)
	{
			C0CON0 = ((((uint8_t)COMP_Init->COMP_RegulationMode) << 6) | (((uint8_t)COMP_Init->COMP_NegativeGND) << 5) | ((uint8_t)(COMP_Init->COMP_NegativeCH) << 2) | ((uint8_t)(COMP_Init->COMP_PositiveCH)));
			C0CON1 = (((uint8_t)(COMP_Init->COMP_RegulationModeIn) << 6) | ((uint8_t)(COMP_Init->COMP_OffsetVoltage)));
			C0CON2 = (((uint8_t)(COMP_Init->COMP_OutputPolarity) << 5) | ((uint8_t)(COMP_Init->COMP_OutputFilter) << 4) | ((uint8_t)(COMP_Init->COMP_OutputFilterTime)));
			CNVRCON = (((uint8_t)(COMP_Init->COMP_NegativeVref) << 4) | ((uint8_t)(COMP_Init->COMP_NegativeVDDK)));
			CNFBCON = (((uint8_t)(COMP_Init->COMPn_PWMBrake.COMP0_PWMBrake) << 2) | ((uint8_t)(COMP_Init->COMPn_PWMBrakeEdge.COMP0_PWMBrakeEdge)));
			C0ADJE = ((uint8_t)(COMP_Init->COMP_OffsetVoltageMode));
	}
	else if(COMP1 == COMPn)
	{
			C1CON0 = ((((uint8_t)COMP_Init->COMP_RegulationMode) << 6) | (((uint8_t)COMP_Init->COMP_NegativeGND) << 5) | ((uint8_t)(COMP_Init->COMP_NegativeCH) << 2) | ((uint8_t)(COMP_Init->COMP_PositiveCH)));
			C1CON1 = (((uint8_t)(COMP_Init->COMP_RegulationModeIn) << 6) | ((uint8_t)(COMP_Init->COMP_OffsetVoltage)));
			C1CON2 = (((uint8_t)(COMP_Init->COMP_OutputPolarity) << 5) | ((uint8_t)(COMP_Init->COMP_OutputFilter) << 4) | ((uint8_t)(COMP_Init->COMP_OutputFilterTime)));
			CNVRCON = (((uint8_t)(COMP_Init->COMP_NegativeVref) << 4) | ((uint8_t)(COMP_Init->COMP_NegativeVDDK)));
			CNFBCON = (((uint8_t)(COMP_Init->COMPn_PWMBrake.COMP1_PWMBrake) << 3) | ((uint8_t)(COMP_Init->COMPn_PWMBrakeEdge.COMP1_PWMBrakeEdge) << 1));
			C1ADJE = ((uint8_t)(COMP_Init->COMP_OffsetVoltageMode));
	}
}

void COMP_Cmd(COMP_TypeDef COMPn, FunctionalState NewState)
{
	
	if (NewState != _DISABLE)
	{
			/* COMP Enable */
			if(COMP0 == COMPn)
			{
					C0CON0 |= (uint8_t)COMP_ENABLE_BIT;
			}
			else if(COMP1 == COMPn)
			{
					C0CON1 |= (uint8_t)COMP_ENABLE_BIT;
			}
	}
	else
	{
			/* COMP Disable */
			if(COMP0 == COMPn)
			{
					C0CON0 |= (uint8_t)(~COMP_ENABLE_BIT);
			}
			else if(COMP1 == COMPn)
			{
					C0CON1 |= (uint8_t)(~COMP_ENABLE_BIT);
			}
	}
}

uint8_t COMP_GetResult(COMP_TypeDef COMPn)
{
	uint8_t COMP_Out = 0;
	if(COMP0 == COMPn)
	{
			COMP_Out = ((C0CON1 & 0x80) >> 7);
	}
	else if(COMP1 == COMPn)
	{
			COMP_Out = ((C1CON1 & 0x80) >> 7);
	}
	
	return COMP_Out;
}

/**
  * @brief  Enables or disables the interrupt generation when an event is detected.
  * @param  COMP_TypeDef : selects the comparator and can be any of the
  *         @ref COMP_TypeDef enum.
  * @param  NewState : new state of the COMPx peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void COMP_ITConfig(COMP_TypeDef COMPn, FunctionalState NewState)
{
	if (NewState != _DISABLE)
  {
    /* Enable the OP */
		if(COMP0 == COMPn)
		{
				CNIE &= (uint8_t)(~COMP0_IT_DISABLE_BIT);
		}
		else if(COMP1 == COMPn)
		{
				CNIE &= (uint8_t)(~COMP1_IT_DISABLE_BIT);
		}
  }
  else
  {
    /* Disable the OP */
		if(COMP0 == COMPn)
		{
				CNIE |= (uint8_t)(COMP0_IT_DISABLE_BIT);
		}
		else if(COMP1 == COMPn)
		{
				CNIE |= (uint8_t)(COMP0_IT_DISABLE_BIT);
		}
  }
}


/**
  * @brief  Checks whether the comparator flag is set or not.
  * @param  COMP_Selection : selects the comparator and can be any of the
  *         @ref COMP_TypeDef enum.
  * @retval The new state of COMPx event flag (SET or RESET).
  */
FlagStatus COMP_GetFlagStatus(COMP_TypeDef COMPn)
{
  FlagStatus bitstatus = _RESET;
	
	if(COMP0 == COMPn)
	{
			if((CNIF & COMP0_IT_Flag) != _RESET)
			{
				bitstatus = _SET;
			}
	}
	else if(COMP1 == COMPn)
	{
			if((CNIF & COMP1_IT_Flag) != _RESET)
			{
				bitstatus = _SET;
			}
	}

  /* return the comparator event flag status */
  return (FlagStatus)(bitstatus);
}

/**
  * @brief  Clears the comparator’s pending flag.
  * @param  COMPn : selects the comparator and can be any of the
  *         @ref COMP_TypeDef enum.
  * @retval None.
  */
void COMP_ClearFlag(COMP_TypeDef COMPn)
{
	if(COMP0 == COMPn)
	{
			CNIF &= COMP0_IT_Flag;
	}
	else if(COMP1 == COMPn)
	{
			CNIF &= COMP1_IT_Flag;
	}
}

/**
  * @brief  Checks whether the comparator interrupt has occurred or not.
  * @param  COMPn : selects the comparator and can be any of the
  *         @ref COMP_TypeDef enum.
  * @retval ITStatus : The state of the COMPx event flag (SET or RESET).
  */
ITStatus COMP_GetITStatus(COMP_TypeDef COMPn)
{
  ITStatus bitstatus = _RESET;
	
	if(COMP0 == COMPn)
	{
			if((CNIF & COMP0_IT_Flag) != _RESET)
			{
				bitstatus = _SET;
			}
	}
	else if(COMP1 == COMPn)
	{
			if((CNIF & COMP1_IT_Flag) != _RESET)
			{
				bitstatus = _SET;
			}
	}

  /* Return the COMP interrupt status */
  return (ITStatus) bitstatus;
}

/**
  * @brief  Clears the interrupt pending bits of the comparator.
  * @param  COMPn : selects the comparator and can be any of the
  *         @ref COMP_TypeDef enum.
  * @retval None
  */
void COMP_ClearITPendingBit(COMP_TypeDef COMPn)
{
	if(COMP0 == COMPn)
	{
			CNIF &= COMP0_IT_Flag;
	}
	else if(COMP1 == COMPn)
	{
			CNIF &= COMP1_IT_Flag;
	}
}

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
