#include "cms8s003x_syscon.h"


void SYS_GPIO_Alternate_Config(GPIO_NUM num, uint8_t gpio_alt_func)
{
	/*switch(num)
	{
		case GPIO_NUM_P00: P00CFG |= gpio_alt_func; break;
		case GPIO_NUM_P01: P01CFG |= gpio_alt_func; break;
		case GPIO_NUM_P02: P02CFG |= gpio_alt_func; break;
		case GPIO_NUM_P03: P03CFG |= gpio_alt_func; break;
		case GPIO_NUM_P04: P04CFG |= gpio_alt_func; break;
		case GPIO_NUM_P05: P05CFG |= gpio_alt_func; break;
		case GPIO_NUM_P06: P06CFG |= gpio_alt_func; break;
		case GPIO_NUM_P07: P07CFG |= gpio_alt_func; break;
		case GPIO_NUM_P10: P10CFG |= gpio_alt_func; break;
		case GPIO_NUM_P11: P11CFG |= gpio_alt_func; break;
		case GPIO_NUM_P12: P12CFG |= gpio_alt_func; break;
		case GPIO_NUM_P13: P13CFG |= gpio_alt_func; break;
		case GPIO_NUM_P14: P14CFG |= gpio_alt_func; break;
		case GPIO_NUM_P15: P15CFG |= gpio_alt_func; break;
		case GPIO_NUM_P16: P16CFG |= gpio_alt_func; break;
		case GPIO_NUM_P17: P17CFG |= gpio_alt_func; break;
		case GPIO_NUM_P20: P20CFG |= gpio_alt_func; break;
		case GPIO_NUM_P21: P21CFG |= gpio_alt_func; break;
		case GPIO_NUM_P22: P22CFG |= gpio_alt_func; break;
		case GPIO_NUM_P23: P23CFG |= gpio_alt_func; break;
		case GPIO_NUM_P24: P24CFG |= gpio_alt_func; break;
		case GPIO_NUM_P25: P25CFG |= gpio_alt_func; break;
		case GPIO_NUM_P26: P26CFG |= gpio_alt_func; break;
		case GPIO_NUM_P27: P27CFG |= gpio_alt_func; break;
		case GPIO_NUM_P30: P30CFG |= gpio_alt_func; break;
		case GPIO_NUM_P31: P31CFG |= gpio_alt_func; break;
		case GPIO_NUM_P32: P32CFG |= gpio_alt_func; break;
		case GPIO_NUM_P33: P33CFG |= gpio_alt_func; break;
		case GPIO_NUM_P34: P34CFG |= gpio_alt_func; break;
		case GPIO_NUM_P35: P35CFG |= gpio_alt_func; break;
		case GPIO_NUM_P36: P36CFG |= gpio_alt_func; break;
		case GPIO_NUM_P37: P37CFG |= gpio_alt_func; break;
		default: break;
	}*/
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


