/**
  ******************************************************************************
  * @file    cms8s003x_op.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file provides all the OP firmware functions.
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
#include "cms8s003x_op.h"

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
  * @addtogroup OP_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the OP peripheral registers to their default reset values.
  * @param  None.
  * @retval None.
  */
void OP_DeInit(OP_TypeDef OPn)
{
	if(OP0 == OPn)
	{
			OP0CON0 &= 0x00;
			OP0CON0 |= 0x20;
		
			OP0CON1 &= 0x00;
			OP0CON1 |= 0x10;
		
			OP0ADJE &= 0x00;
	}
	else if(OP1 == OPn)
	{
			OP1CON0 &= 0x00;
			OP1CON0 |= 0x20;
		
			OP1CON1 &= 0x00;
			OP1CON1 |= 0x10;
		
			OP1ADJE &= 0x00;
	}
}

/**
  * @brief  Initializes the comparator.
  * @note   This function configures COMP.
  * @param  OPn : selects the comparator can
  *         be any of the @ref OP_TypeDef.
  * @param  OP_Init : OP initial can be any of
  *         the @ref OP_Init_TypeDef enumeation.
  * @retval None.
  */
void OP_Init(OP_TypeDef OPn, OP_Init_TypeDef *OP_Init)
{
	OP_DeInit(OPn);
	
	if(OP0 == OPn)
	{
			OP0CON0 = (((uint8_t)OP_Init->OP_EN << 7) | ((uint8_t)OP_Init->OP_Regulation << 6) | ((uint8_t)OP_Init->OP_Filtration << 5) | ((uint8_t)OP_Init->OP_OutCH << 4) | ((uint8_t)OP_Init->OP_PositiveCH << 2) | ((uint8_t)OP_Init->OP_NegativeCH));
			OP0CON1 = (((uint8_t)OP_Init->OP_RegulationMode << 6) | ((uint8_t)OP_Init->OP_OffsetVoltage));
			OP0ADJE = ((uint8_t)OP_Init->OP_OffsetVoltageMode);
	}
	else if(OP1 == OPn)
	{
			OP1CON0 = (((uint8_t)OP_Init->OP_EN << 7) | ((uint8_t)OP_Init->OP_Regulation << 6) | ((uint8_t)OP_Init->OP_Filtration << 5) | ((uint8_t)OP_Init->OP_OutCH << 4) | ((uint8_t)OP_Init->OP_PositiveCH << 2) | ((uint8_t)OP_Init->OP_NegativeCH));
			OP1CON1 = (((uint8_t)OP_Init->OP_RegulationMode << 6) | ((uint8_t)OP_Init->OP_OffsetVoltage));
			OP1ADJE = ((uint8_t)OP_Init->OP_OffsetVoltageMode);
	}
}

void OP_Cmd(OP_TypeDef OPn, FunctionalState NewState)
{
	if (NewState != _DISABLE)
  {
    /* Enable the OP */
		if(OP0 == OPn)
		{
				OP0CON0 |= (uint8_t)OP_ENABLE_BIT;
		}
		else if(OP1 == OPn)
		{
				OP1CON0 |= (uint8_t)OP_ENABLE_BIT;
		}
  }
  else
  {
    /* Disable the OP */
		if(OP0 == OPn)
		{
				OP0CON0 |= (uint8_t)(~OP_ENABLE_BIT);
		}
		else if(OP1 == OPn)
		{
				OP1CON0 |= (uint8_t)(~OP_ENABLE_BIT);
		}
  }
}

uint8_t getOPResult(OP_TypeDef OPn)
{
	uint8_t OP_OUT = 0;
	if(OP0 == OPn)
	{
			OP_OUT = ((OP0CON1 & 0x80) >> 7);
	}
	else if(OP1 == OPn)
	{
			OP_OUT = ((OP1CON1 & 0x80) >> 7);
	}
	
	return OP_OUT;
}


/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
