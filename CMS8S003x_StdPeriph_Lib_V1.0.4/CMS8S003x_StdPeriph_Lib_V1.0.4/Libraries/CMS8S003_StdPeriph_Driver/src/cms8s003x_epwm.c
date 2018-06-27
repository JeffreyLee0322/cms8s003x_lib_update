/**
  ******************************************************************************
  * @file    cms8s003x_epwm.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file provides all the EPWM firmware functions.
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
#include "cms8s003x_epwm.h"

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
  * @addtogroup EPWM_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the EPWM peripheral registers to their default
  *         reset values.
  * @param  None
  * @retval None
  */
void EPWM_DeInit(void)
{
	PWMCON &= 0x00;
	PWMOE &= 0x00;
}

/**
  * @brief  Initializes the EPWM function according to the specified parameters.
  * @param  EPWM_Init EPWM initial.
  *         This parameter can be one of the values of @ref EPWM_Init_TypeDef.
	* @retval None
  */
void EPWM_Init(EPWM_Init_TypeDef *EPWM_Init)
{
	uint8_t i = 0;
	
	/* Set EPWM control config */
	PWMCON &= 0x00;
	PWMCON = (((uint8_t)EPWM_Init->Mode) | ((uint8_t)EPWM_Init->Group) | ((uint8_t)EPWM_Init->Aligh.AlignStyle)); 
	if(AlignStyle_Center == EPWM_Init->Aligh.AlignStyle)
	{
		PWMCON |= ((uint8_t)EPWM_Init->Aligh.Align_TypeDef.CenterAlign);
	}
	/*else if(AlignStyle_Edge == EPWM_Init->Aligh.AlignStyle)
	{
	
	}*/
	
	/* Set group EPWM clock prescaler */
	/* Set EPWM01 clock prescaler */  
	PWM01PSC &= 0x00;
	PWM01PSC = ((uint8_t)EPWM_Init->GroupPrescaler.EPWM01_Prescaler);
	/* Set EPWM23 clock prescaler */
	PWM23PSC &= 0x00;
	PWM23PSC = ((uint8_t)EPWM_Init->GroupPrescaler.EPWM23_Prescaler);
	/* Set EPWM45 clock prescaler */
	PWM45PSC &= 0x00;
	PWM45PSC = ((uint8_t)EPWM_Init->GroupPrescaler.EPWM45_Prescaler);
	#if 0
	while(i < 6)
	{
		if(((EPWM_Init->EPWMChannel) >> i) & 0x01)
		{
				/* Set EPWM clock prescaler */
				*(volatile unsigned char xdata *)(PWMDIVBASE + i) = 0x00;
				*(volatile unsigned char xdata *)(PWMDIVBASE + i) = ((uint8_t)EPWM_Init->Prescaler);
			
				/* Set period value */
				*(volatile unsigned char xdata *)(PWMPLBASE + i * 2) &= 0x00;
				*(volatile unsigned char xdata *)(PWMPHBASE + i * 2) &= 0x00;
				*(volatile unsigned char xdata *)(PWMPLBASE + i * 2) = ((uint8_t)EPWM_Init->PeriodValue);
				*(volatile unsigned char xdata *)(PWMPHBASE + i * 2) = ((uint8_t)(EPWM_Init->PeriodValue >> 8));
				
				/* Set compare value */
				*(volatile unsigned char xdata *)(PWMDLBASE + i * 2) &= 0x00;
				*(volatile unsigned char xdata *)(PWMDHBASE + i * 2) &= 0x00;
				*(volatile unsigned char xdata *)(PWMDLBASE + i * 2) = ((uint8_t)EPWM_Init->CompareValue);
				*(volatile unsigned char xdata *)(PWMDHBASE + i * 2) = ((uint8_t)(EPWM_Init->CompareValue >> 8));
		
				/* Set down compare value */
				*(volatile unsigned char xdata *)(PWMDDLBASE + i * 2) &= 0x00;
				*(volatile unsigned char xdata *)(PWMDDHBASE + i * 2) &= 0x00;
				*(volatile unsigned char xdata *)(PWMDDLBASE + i * 2) = ((uint8_t)EPWM_Init->DownCompareValue);
				*(volatile unsigned char xdata *)(PWMDDHBASE + i * 2) = ((uint8_t)(EPWM_Init->DownCompareValue >> 8));
		}
		i++;
	}
	#endif
	/* Set data reload control */
	PWMLOADEN &= 0x00;
	PWMLOADEN = ((uint8_t)EPWM_Init->DataReload);
	
	/* Set EPWM output polarity */
	PWMPINV &= 0x00;
	PWMPINV = ((uint8_t)EPWM_Init->OPInverted);
	
	/* Set EPWM counter mode */
	PWMCNTM &= 0x00;
	PWMCNTM = ((uint8_t)EPWM_Init->CounterModeRepetitive);
	
	/* Set EPWM counter clear */
	PWMCNTCLR &= 0x00;
	PWMCNTCLR = ((uint8_t)EPWM_Init->CounterZero);
	
	/* Dead zone enable */
	PWMDTE &= 0x00;
	PWMDTE = ((uint8_t)EPWM_Init->DeadZoneEnable);
	
	/* Set dead zone delay time */
	if(EPWM_Init->DeadZoneTime.EPWMAll_DeadZone_Time)
	{
			PWM01DT = (EPWM_Init->DeadZoneTime.EPWMAll_DeadZone_Time);
			PWM23DT = (EPWM_Init->DeadZoneTime.EPWMAll_DeadZone_Time);
			PWM45DT = (EPWM_Init->DeadZoneTime.EPWMAll_DeadZone_Time);
	}
	else
	{
			if(EPWM_Init->DeadZoneTime.EPWM01_DeadZone_Time)
			{
					PWM01DT = (EPWM_Init->DeadZoneTime.EPWM01_DeadZone_Time);
			}
			
			if(EPWM_Init->DeadZoneTime.EPWM23_DeadZone_Time)
			{
					PWM23DT = (EPWM_Init->DeadZoneTime.EPWM23_DeadZone_Time);
			}
			
			if(EPWM_Init->DeadZoneTime.EPWM45_DeadZone_Time)
			{
					PWM45DT = (EPWM_Init->DeadZoneTime.EPWM45_DeadZone_Time);
			}
	}
	
	/* Enable mask */
	PWMMASKE &= 0x00;
	PWMMASKE = ((uint8_t)EPWM_Init->Mask);
	
	/* Set mask high */  
	PWMMASKD &= 0x00;
	PWMMASKD = ((uint8_t)EPWM_Init->MaskHigh);
	
	/* Set EPWM brake config */
	PWMFBKC &= 0x00;
	PWMFBKC = (((uint8_t)EPWM_Init->Brake.BrakeEnable.Brake_CH0_ENABLE) |\
						((uint8_t)EPWM_Init->Brake.BrakeEnable.Brake_CH1_ENABLE << 1) |\
						((uint8_t)EPWM_Init->Brake.BrakeTrigger.Brake_CH0 << 2) |\
						((uint8_t)EPWM_Init->Brake.BrakeTrigger.Brake_CH1 << 3) |\
						((uint8_t)EPWM_Init->Brake.BrakeStart << 4) |\
						((uint8_t)EPWM_Init->Brake.BrakeClear << 5));
	
	/* Set EPWM brake output high */
	PWMFBKD &= 0X00;
	PWMFBKD = ((uint8_t)EPWM_Init->Brake.BrakeOutputHigh);
}

/**
  * @brief  Enable or disable the EPWM function.
  * @param  EPWM_Channel EPWM channel select.
  *         This parameter can be one of the values of @ref EPWM_Channel_TypeDef.
  * @param  NewState Indicates the new state of the EPWM function.
  * @retval None
  */
void EPWM_Cmd(EPWM_Channel_TypeDef EPWM_Channel, FunctionalState NewState)
{
  if (NewState != _DISABLE)
  {
    /* Enable the EPWM peripheral */
    PWMOE |= EPWM_Channel;
		
		/* Start work */
		PWMCNTE |= EPWM_Channel;
  }
  else
  {
    /* Disable the EPWM peripheral */
    PWMOE &= (uint8_t)(~EPWM_Channel);
		
		/* Start work */
		PWMCNTE &= (uint8_t)(~EPWM_Channel);
  }
}

void EPWM_Enable_DataReload(EPWM_DataReload_Typedef EPWMn_Load)
{
	PWMLOADEN |= EPWMn_Load;
}

void EPWM_SetOutPolarity(EPWM_OP_TypeDef OP, EPWM_Channel_TypeDef CH)
{
	if(EPWM_OP_Inverted == OP)
	{
			/* Enable the EPWM inverted */
			PWMPINV |= CH;
	}
	else if(EPWM_OP_NonInverted == OP)
	{
			/* Enable the EPWM inverted */
			PWMPINV &= (uint8_t)(~CH);
	}
}

void EPWM_SetCounterMode(EPWM_CounterMode_TypeDef CounterMode, EPWM_Channel_TypeDef CH)
{
	if(EPWM_CounterMode_Repetitive == CounterMode)
	{
			/* Enable the EPWM counter mode repetitive */
			PWMCNTM |= CH;
	}
	else if(EPWM_CounterMode_OneShot == CounterMode)
	{
			/* Enable the EPWM counter mode one shot */
			PWMCNTM &= (uint8_t)(~CH);
	}
}

void EPWM_ClearCounter(EPWM_CounterZero_TypeDef CounterZero)
{
	PWMCNTCLR |= CounterZero;
}

void EPEM_DeadZoneCmd(EPWM_DeadZone_TypeDef DeadZone, FunctionalState NewState)
{
	if(NewState != _DISABLE)
	{
			/* Enable the EPWM dead zone */
			PWMDTE |= DeadZone;
	}
	else
	{
			/* Disable the EPWM dead zone */
			PWMDTE &= (uint8_t)(~DeadZone);
	}
}

void EPWM_MaskCmd(EPWM_Mask_TypeDef Mask, FunctionalState NewState)
{
	if(NewState != _DISABLE)
	{
			/* Enable the EPWM mask */
			PWMMASKE |= ((uint8_t)Mask);
	}
	else
	{
			/* Disable the EPWM mask */
			PWMMASKE &= (uint8_t)(~Mask);
	}
}

void EPWM_MaskOutConfig(EPWM_Mask_TypeDef Mask, EPWM_Mask_Out_TypeDef MaskOut)
{
	if(EPWM_Mask_Out_High == MaskOut)
	{
			/* Enable the EPWM mask high */
			PWMMASKD |= Mask;
	}
	else if(EPWM_Mask_Out_Low == MaskOut)
	{
			/* Enable the EPWM mask low */
			PWMMASKD &= (uint8_t)(~Mask);
	}
}

void EPWM_BrakeOutputConfig(EPWM_BrakePWMn_TypeDef BrakePWMn, EPWM_Brake_Output_TypeDef Brake_Output)
{
	if(Output_High == Brake_Output)
	{
			/* Enable the EPWM mask high */
			PWMFBKD |= BrakePWMn;
	}
	else if(Output_Low == Brake_Output)
	{
			/* Enable the EPWM mask low */
			PWMFBKD &= (uint8_t)(~BrakePWMn);
	}
}

void EPWM_BrakeCmd(EPWM_Brake_CH_TypeDef BrakeCH, FunctionalState NewState)
{
	if(NewState != _DISABLE)
	{
			/* Enable the EPWM brake CH0/CH1 */
			PWMFBKC |= ((uint8_t)BrakeCH);
		
			/* Start brake */
			PWMFBKC |= ((uint8_t)EPWM_BRAKE_START_BIT);
	}
	else
	{
			/* Disable the EPWM brake CH0/CH1 */
			PWMFBKC &= (uint8_t)(~BrakeCH);
		
			/* Disable brake */
			PWMFBKC &= (uint8_t)(~EPWM_BRAKE_START_BIT);
	}
}

void EPWM_PeriodITCmd(EPWM_PeriodIT_TypeDef PeriodIT, FunctionalState NewState)
{
	if(NewState != _DISABLE)
	{
			/* Enable the EPWM Period IT */
			PWMPIE |= ((uint8_t)PeriodIT);
	}
	else
	{
			/* Disable the EPWM Period IT */
			PWMPIE &= (uint8_t)(~PeriodIT);
	}
}

void EPWM_ZeroITCmd(EPWM_ZeroIT_TypeDef ZeroIT, FunctionalState NewState)
{
	if(NewState != _DISABLE)
	{
			/* Enable the EPWM zero IT */
			PWMZIE |= ((uint8_t)ZeroIT);
	}
	else
	{
			/* Disable the EPWM zero IT */
			PWMZIE &= (uint8_t)(~ZeroIT);
	}
}

FlagStatus EPWM_GetPeriodITStatus(EPWM_PeriodIT_TypeDef PeriodIT)
{
	FlagStatus Flag = _RESET;
	
	if((PWMPIF & PeriodIT) != (uint8_t)_RESET)
	{
			Flag = _SET;
	}
	else
	{
			Flag = _RESET;
	}
	return Flag;
}
FlagStatus EPWM_GetZeroITStatus(EPWM_ZeroIT_TypeDef ZeroIT)
{
	FlagStatus Flag = _RESET;
	
	if((PWMZIF & ZeroIT) != (uint8_t)_RESET)
	{
			Flag = _SET;
	}
	else
	{
			Flag = _RESET;
	}
	return Flag;
}

void EPWM_ClearPeriodITStatus(EPWM_PeriodIT_TypeDef PeriodIT)
{
	PWMPIF &= (uint8_t)(~PeriodIT);
}

void EPWM_ClearZeroITStatus(EPWM_ZeroIT_TypeDef ZeroIT)
{
	PWMZIF &= (uint8_t)(~ZeroIT);
}


/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
