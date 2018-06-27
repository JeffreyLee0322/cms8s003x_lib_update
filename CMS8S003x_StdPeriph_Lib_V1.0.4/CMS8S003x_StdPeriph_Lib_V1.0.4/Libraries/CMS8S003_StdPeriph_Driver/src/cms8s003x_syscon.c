#include "cms8s003x_syscon.h"

void SYS_GPIO_Alternate_Config(GPIO_NUM num, uint8_t gpio_alt_func)
{
	if(num < (GPIO_NUM_P07 + 1))
	{
			*(volatile unsigned char xdata *)(P0CFG +(uint8_t)num) = 0;
			*(volatile unsigned char xdata *)(P0CFG +(uint8_t)num) |= gpio_alt_func;
	}else if(num < (GPIO_NUM_P17 + 1))
	{
			*(volatile unsigned char xdata *)(P1CFG +(uint8_t)(num - 10)) = 0;
			*(volatile unsigned char xdata *)(P1CFG +(uint8_t)(num - 10)) |= gpio_alt_func;
	}else if(num < (GPIO_NUM_P27 + 1))
	{
			*(volatile unsigned char xdata *)(P2CFG +(uint8_t)(num-20)) = 0;
			*(volatile unsigned char xdata *)(P2CFG +(uint8_t)(num-20)) |= gpio_alt_func;
	}else if(num < (GPIO_NUM_P37 + 1))
	{
			*(volatile unsigned char xdata *)(P3CFG +(uint8_t)(num-30)) = 0;
			*(volatile unsigned char xdata *)(P3CFG +(uint8_t)(num-30)) |= gpio_alt_func;
	}
}

/**
  * @brief  Enables or disables the ALL interrupts.
  * @param  NewState : The new state of the specified SPI interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void MCU_ITConfig(FunctionalState NewState)
{
	/* Check function parameters */
	//assert_param(IS_FUNCTIONAL_STATE(NewState));
	
	/* Set the SPI IT mask Register */
  if (NewState != _DISABLE)
  {
    EA = 1;  /* Enable the SPI IT */
  }
  else
  {
    EA = 0;  /* Disable the SPI IT */
  }
}

void MCU_SoftwareReset(void)
{
	/* Exe software reset */
	WDCON = 0x80;
}

uint8_t MCU_GetResetFlag(void)
{
	if(WDCON & 0x40)
		return 1;
	else return 0;
}


