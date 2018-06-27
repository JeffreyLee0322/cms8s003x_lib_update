/**
  ******************************************************************************
  * @file    cms8s003x_gpio.c
  * @author  LI WEI
  * @version V1.0.0
  * @date    04/24/2018
  * @brief   This file provides all the GPIO firmware functions.
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
#include "cms8s003x_gpio.h"
#include "cms8s003x_conf.h"

/** @addtogroup cms8s003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @addtogroup GPIO_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the GPIOx peripheral registers to their default reset values.
  * @param  GPIOx: Select the GPIO peripheral number (x = 0 to 2).
  * @retval None
  */
void GPIO_DeInit(GPIO_Port_Typedef GPIOx)
{

}

/**
  * @brief  Initializes the GPIOx according to the specified parameters.
  * @param  GPIOx : Select the GPIO peripheral number (x = 0 to 2).
  * @param  GPIO_InitParam : This parameter can be any value
  *         of the @ref GPIO_Init_TypeDef enumeration.
  * @retval None
  */
void GPIO_Init(GPIO_Port_Typedef GPIOx, GPIO_Init_TypeDef* GPIO_InitParam)
{
  if(GPIOx == GPIO_PORT_0)
	{
			if(GPIO_InitParam->Mode == GPIO_PIN)
			{
					*(volatile unsigned char xdata *)(P0CFG +(uint8_t)GPIO_InitParam->Pin) = 0;
			}
  		if(GPIO_InitParam->Direction == GPIO_INPUT)    							P0TRIS &= ~GPIO_InitParam->Pin;   //输入模式
  		if(GPIO_InitParam->Direction == GPIO_OUTPUT) 								P0TRIS |= GPIO_InitParam->Pin;    //输出模式
			if(GPIO_InitParam->Analog == GPIO_Digital_Sel)     					P0ANS &= ~GPIO_InitParam->Pin;    //数字端口    
			if(GPIO_InitParam->Analog == GPIO_Analog_Sel)      					P0ANS |= GPIO_InitParam->Pin; 	  //模拟端口
			if(GPIO_InitParam->OType == GPIO_Pushpull_Sel)      				P0OD &= ~GPIO_InitParam->Pin;     //正常状态(推挽)
			if(GPIO_InitParam->OType == GPIO_Opendrain_Sel)     				P0OD |= GPIO_InitParam->Pin;      //开漏模式
			if(GPIO_InitParam->Up == GPIO_Up_Disable)       						P0UP &= ~GPIO_InitParam->Pin;     //关闭上拉
  		if(GPIO_InitParam->Up == GPIO_Up_Enable)		    						P0UP |= GPIO_InitParam->Pin;      //开启上拉
			if(GPIO_InitParam->Down == GPIO_Down_Disable)       				P0DOWN &= ~GPIO_InitParam->Pin;     //关闭下拉
  		if(GPIO_InitParam->Down == GPIO_Down_Enable)		    				P0DOWN |= GPIO_InitParam->Pin;      //开启下拉
			if(GPIO_InitParam->Driver == GPIO_Driver_Strong)       			P0DR &= ~GPIO_InitParam->Pin;     //弱电流驱动
  		if(GPIO_InitParam->Driver == GPIO_Driver_Weak)		    			P0DR |= GPIO_InitParam->Pin;      //强电流驱动
			if(GPIO_InitParam->Slope == GPIO_Slope_Fast)       					P0SR &= ~GPIO_InitParam->Pin;     //快斜率
  		if(GPIO_InitParam->Slope == GPIO_Slope_Slow)		    				P0SR |= GPIO_InitParam->Pin;      //慢斜率
	}
	else if(GPIOx == GPIO_PORT_1)
	{
			if(GPIO_InitParam->Mode == GPIO_PIN)
			{
					*(volatile unsigned char xdata *)(P1CFG +(uint8_t)GPIO_InitParam->Pin) = 0;
			}
  		if(GPIO_InitParam->Direction == GPIO_INPUT)    							P1TRIS &= ~(1 << GPIO_InitParam->Pin);   //输入模式
  		if(GPIO_InitParam->Direction == GPIO_OUTPUT) 								P1TRIS |= (1 << GPIO_InitParam->Pin);    //输出模式
			if(GPIO_InitParam->Analog == GPIO_Digital_Sel)     					P1ANS &= ~(1 << GPIO_InitParam->Pin);    //数字端口    
			if(GPIO_InitParam->Analog == GPIO_Analog_Sel)      					P1ANS |= (1 << GPIO_InitParam->Pin); 	  //模拟端口
			if(GPIO_InitParam->OType == GPIO_Pushpull_Sel)      				P1OD &= ~(1 << GPIO_InitParam->Pin);     //正常状态(推挽)
			if(GPIO_InitParam->OType == GPIO_Opendrain_Sel)     				P1OD |= (1 << GPIO_InitParam->Pin);      //开漏模式
			if(GPIO_InitParam->Up == GPIO_Up_Disable)       						P1UP &= ~(1 << GPIO_InitParam->Pin);     //关闭上拉
  		if(GPIO_InitParam->Up == GPIO_Up_Enable)		    						P1UP |= (1 << GPIO_InitParam->Pin);      //开启上拉
			if(GPIO_InitParam->Down == GPIO_Down_Disable)       				P1DOWN &= ~(1 << GPIO_InitParam->Pin);   //关闭下拉
  		if(GPIO_InitParam->Down == GPIO_Down_Enable)		    				P1DOWN |= (1 << GPIO_InitParam->Pin);    //开启下拉
			if(GPIO_InitParam->Driver == GPIO_Driver_Strong)       			P1DR &= ~(1 << GPIO_InitParam->Pin);     //弱电流驱动
  		if(GPIO_InitParam->Driver == GPIO_Driver_Weak)		    			P1DR |= (1 << GPIO_InitParam->Pin);      //强电流驱动
			if(GPIO_InitParam->Slope == GPIO_Slope_Fast)       					P1SR &= ~(1 << GPIO_InitParam->Pin);     //快斜率
  		if(GPIO_InitParam->Slope == GPIO_Slope_Slow)		    				P1SR |= (1 << GPIO_InitParam->Pin);      //慢斜率
	}
	else if(GPIOx == GPIO_PORT_2)
	{
			if(GPIO_InitParam->Mode == GPIO_PIN)
			{
					*(volatile unsigned char xdata *)(P2CFG +(uint8_t)GPIO_InitParam->Pin) = 0;
					
			}
  		if(GPIO_InitParam->Direction == GPIO_INPUT)    							P2TRIS &= ~GPIO_InitParam->Pin;   //输入模式
  		if(GPIO_InitParam->Direction == GPIO_OUTPUT) 								P2TRIS |= GPIO_InitParam->Pin;    //输出模式
			if(GPIO_InitParam->Analog == GPIO_Digital_Sel)     					P2ANS &= ~GPIO_InitParam->Pin;    //数字端口    
			if(GPIO_InitParam->Analog == GPIO_Analog_Sel)      					P2ANS |= GPIO_InitParam->Pin; 	   //模拟端口
			if(GPIO_InitParam->OType == GPIO_Pushpull_Sel)      				P2OD &= ~GPIO_InitParam->Pin;     //正常状态(推挽)
			if(GPIO_InitParam->OType == GPIO_Opendrain_Sel)     				P2OD |= GPIO_InitParam->Pin;      //开漏模式
			if(GPIO_InitParam->Up == GPIO_Up_Disable)       						P2UP &= ~GPIO_InitParam->Pin;     //关闭上拉
  		if(GPIO_InitParam->Up == GPIO_Up_Enable)		    						P2UP |= GPIO_InitParam->Pin;      //开启上拉
			if(GPIO_InitParam->Down == GPIO_Down_Disable)       				P2DOWN &= ~GPIO_InitParam->Pin;     //关闭下拉
  		if(GPIO_InitParam->Down == GPIO_Down_Enable)		    				P2DOWN |= GPIO_InitParam->Pin;      //开启下拉
			if(GPIO_InitParam->Driver == GPIO_Driver_Strong)       			P2DR &= ~GPIO_InitParam->Pin;     //弱电流驱动
  		if(GPIO_InitParam->Driver == GPIO_Driver_Weak)		    			P2DR |= GPIO_InitParam->Pin;      //强电流驱动
			if(GPIO_InitParam->Slope == GPIO_Slope_Fast)       					P2SR &= ~GPIO_InitParam->Pin;     //快斜率
  		if(GPIO_InitParam->Slope == GPIO_Slope_Slow)		    				P2SR |= GPIO_InitParam->Pin;      //慢斜率
 	}
	else if(GPIOx == GPIO_PORT_3)
 	{
			if(GPIO_InitParam->Mode == GPIO_PIN)
			{
					*(volatile unsigned char xdata *)(P3CFG +(uint8_t)GPIO_InitParam->Pin) = 0;
			}
  		if(GPIO_InitParam->Direction == GPIO_INPUT)    							P3TRIS &= ~GPIO_InitParam->Pin;   //输入模式
  		if(GPIO_InitParam->Direction == GPIO_OUTPUT) 								P3TRIS |= GPIO_InitParam->Pin;    //输出模式
			if(GPIO_InitParam->Analog == GPIO_Digital_Sel)     					P3ANS &= ~GPIO_InitParam->Pin;    //数字端口    
			if(GPIO_InitParam->Analog == GPIO_Analog_Sel)      					P3ANS |= GPIO_InitParam->Pin; 	   //模拟端口
			if(GPIO_InitParam->OType == GPIO_Pushpull_Sel)      				P3OD &= ~GPIO_InitParam->Pin;     //正常状态(推挽)
			if(GPIO_InitParam->OType == GPIO_Opendrain_Sel)     				P3OD |= GPIO_InitParam->Pin;      //开漏模式
			if(GPIO_InitParam->Up == GPIO_Up_Disable)       						P3UP &= ~GPIO_InitParam->Pin;     //关闭上拉
  		if(GPIO_InitParam->Up == GPIO_Up_Enable)		    						P3UP |= GPIO_InitParam->Pin;      //开启上拉
			if(GPIO_InitParam->Down == GPIO_Down_Disable)       				P3DOWN &= ~GPIO_InitParam->Pin;     //关闭下拉
  		if(GPIO_InitParam->Down == GPIO_Down_Enable)		    				P3DOWN |= GPIO_InitParam->Pin;      //开启下拉
			if(GPIO_InitParam->Driver == GPIO_Driver_Strong)       			P3DR &= ~GPIO_InitParam->Pin;     //弱电流驱动
  		if(GPIO_InitParam->Driver == GPIO_Driver_Weak)		    			P3DR |= GPIO_InitParam->Pin;      //强电流驱动
			if(GPIO_InitParam->Slope == GPIO_Slope_Fast)       					P3SR &= ~GPIO_InitParam->Pin;     //快斜率
  		if(GPIO_InitParam->Slope == GPIO_Slope_Slow)		    				P3SR |= GPIO_InitParam->Pin;      //慢斜率
 	}
}

/**
  * @brief  Writes data to the specified GPIO data port.
  * @note   The port must be configured in output mode.
  * @param  GPIOx : Select the GPIO peripheral number (x = 0 to 2).
  * @param  GPIO_PortVal : Specifies the value to be written to the port output
  *         data register.
  * @retval None
  */
void GPIO_Write(GPIO_Port_Typedef GPIOx, uint8_t GPIO_PortVal)
{
  if(GPIOx == GPIO_PORT_0)
  {
		P0 = GPIO_PortVal;
  }else if(GPIOx == GPIO_PORT_1)
  {
		P1 = GPIO_PortVal;
  }else if(GPIOx == GPIO_PORT_2)
  {
		P2 = GPIO_PortVal;
  }else if(GPIOx == GPIO_PORT_3)
  {
		P3 = GPIO_PortVal;
  }else
  {

  }
}

/**
  * @brief  Sets or clears the selected data port bit.
  * @param  GPIOx : Select the GPIO peripheral number (x = 0 to 2).
  * @param  GPIO_Pin: Specifies the port bit to be written.
  *         This parameter can be a value of GPIO_Pin_TypeDef enumeration.
  * @param  GPIO_BitVal: specifies the desired status to be written.
  *         This parameter can be a value of @ref BitAction enumeration.
  * @retval None
  */
void GPIO_WriteBit(GPIO_Port_Typedef GPIOx, GPIO_Pin_TypeDef GPIO_Pin, BitAction GPIO_BitVal)
{
  /* Check the parameters */
  //assert_param(IS_GPIO_PIN(GPIO_Pin));
  //assert_param(IS_STATE_VALUE(GPIO_BitVal));

  if(GPIOx == GPIO_PORT_0)
  {
	 if (GPIO_BitVal != _RESET)
	 {
	    P0  |= (1 << GPIO_Pin);
	 }else
	 {
	    P0  &= (uint8_t)(~(1 << GPIO_Pin));
	 }
  }else if(GPIOx == GPIO_PORT_1)
  {
	 if (GPIO_BitVal != _RESET)
	 {
	    P1  |= (1 << GPIO_Pin);
	 }else
	 {
	    P1  &= (uint8_t)(~(1 << GPIO_Pin));
	 }
  }else if(GPIOx == GPIO_PORT_2)
  {
	 if (GPIO_BitVal != _RESET)
	 {
	    P2  |= (1 << GPIO_Pin);
	 }else
	 {
	    P2  &= (uint8_t)(~(1 << GPIO_Pin));
	 }
  }else if(GPIOx == GPIO_PORT_3)
  {
	 if (GPIO_BitVal != _RESET)
	 {
	    P3  |= (1 << GPIO_Pin);
	 }else
	 {
	    P3  &= (uint8_t)(~(1 << GPIO_Pin));
	 }
  }else
  {

  }
}

/**
  * @brief  Writes high level to the specified GPIO pins.
  * @note   The port must be configured in output mode.
  * @param  GPIOx : Select the GPIO peripheral number (x = 0 to 2).
  * @param  GPIO_Pin : Specifies the pins to be turned high.
  * @retval None
  */
void GPIO_SetBits(GPIO_Port_Typedef GPIOx, uint8_t GPIO_Pin)
{
  if(GPIOx == GPIO_PORT_0)
  {
	P0 |= GPIO_Pin;
  }else if(GPIOx == GPIO_PORT_1)
  {
	P1 |= GPIO_Pin;
  }else if(GPIOx == GPIO_PORT_2)
  {
	P2 |= GPIO_Pin;
  }else if(GPIOx == GPIO_PORT_3)
  {
	P3 |= GPIO_Pin;
  }else
  {

  }
}

/**
  * @brief  Writes low level to the specified GPIO pins.
  * @param  GPIOx : Select the GPIO peripheral number (x = A to I).
  * @param  GPIO_Pin : Specifies the pins to be turned low
  * @retval None
  * @par    Required preconditions:
  *   The port must be configured in output mode.
  */
void GPIO_ResetBits(GPIO_Port_Typedef GPIOx, uint8_t GPIO_Pin)
{
  if(GPIOx == GPIO_PORT_0)
  {
	P0  &= (uint8_t)(~GPIO_Pin);
  }else if(GPIOx == GPIO_PORT_1)
  {
	P1 &= (uint8_t)(~GPIO_Pin);
  }else if(GPIOx == GPIO_PORT_2)
  {
	P2 &= (uint8_t)(~GPIO_Pin);
  }else if(GPIOx == GPIO_PORT_3)
  {
	P3 &= (uint8_t)(~GPIO_Pin);
  }else
  {

  }
}

/**
  * @brief  Toggles the specified GPIO pins.
  * @note   The port must be configured in output mode.
  * @param  GPIOx : Select the GPIO peripheral number (x = A to I).
  * @param  GPIO_Pin : Specifies the pins to be toggled.
  * @retval None
  */
void GPIO_ToggleBits(GPIO_Port_Typedef GPIOx, uint8_t GPIO_Pin)
{
  if(GPIOx == GPIO_PORT_0)
  {
	P0  ^= GPIO_Pin;
  }else if(GPIOx == GPIO_PORT_1)
  {
	P1 ^= GPIO_Pin;
  }else if(GPIOx == GPIO_PORT_2)
  {
	P2 ^= GPIO_Pin;
  }else if(GPIOx == GPIO_PORT_3)
  {
	P3 ^= GPIO_Pin;
  }else
  {

  }
}

/**
  * @brief  Reads the specified GPIO input data port.
  * @note   The port must be configured in input mode.
  * @param  GPIOx : Select the GPIO peripheral number (x = A to I).
  * @retval The GPIOx input data port value.
  */
uint8_t GPIO_ReadInputData(GPIO_Port_Typedef GPIOx)
{
	uint8_t dataRead = 0;
  if(GPIOx == GPIO_PORT_0)
  {
	dataRead = (uint8_t)P0;
  }else if(GPIOx == GPIO_PORT_1)
  {
	dataRead = (uint8_t)P1;
  }else if(GPIOx == GPIO_PORT_2)
  {
	dataRead = (uint8_t)P2;
  }else if(GPIOx == GPIO_PORT_3)
  {
	dataRead = (uint8_t)P3;
  }else
  {

  }
  return dataRead;
}

/**
  * @brief  Reads the specified GPIO output data port.
  * @note   The port must be configured in input mode.
  * @param  GPIOx : Select the GPIO peripheral number (x = A to I).
  * @retval The GPIOx  output data port value.
  */
uint8_t GPIO_ReadOutputData(GPIO_Port_Typedef GPIOx)
{
  uint8_t dataRead = 0;
  if(GPIOx == GPIO_PORT_0)
  {
	dataRead = (uint8_t)P0;
  }else if(GPIOx == GPIO_PORT_1)
  {
	dataRead = (uint8_t)P1;
  }else if(GPIOx == GPIO_PORT_2)
  {
	dataRead = (uint8_t)P2;
  }else if(GPIOx == GPIO_PORT_3)
  {
	dataRead = (uint8_t)P3;
  }else
  {

  }
  return dataRead;
}

/**
  * @brief  Reads the specified GPIO input data pin.
  * @param  GPIOx : Select the GPIO peripheral number (x = A to I).
  * @param  GPIO_Pin : Specifies the pin number.
  * @retval BitStatus : GPIO input pin status.
  */
BitStatus GPIO_ReadInputDataBit(GPIO_Port_Typedef GPIOx, GPIO_Pin_TypeDef GPIO_Pin)
{
  uint8_t dataRead = 0;
  if(GPIOx == GPIO_PORT_0)
  {
	dataRead = ((BitStatus)(P0 & (uint8_t)GPIO_Pin));
  }else if(GPIOx == GPIO_PORT_1)
  {
	dataRead = ((BitStatus)(P1 & (uint8_t)GPIO_Pin));
  }else if(GPIOx == GPIO_PORT_2)
  {
	dataRead = ((BitStatus)(P2 & (uint8_t)GPIO_Pin));
  }else if(GPIOx == GPIO_PORT_3)
  {
	dataRead = ((BitStatus)(P3 & (uint8_t)GPIO_Pin));
  }else
  {

  }
  return dataRead;
}

/**
  * @brief  Reads the specified GPIO Output data pin.
  * @param  GPIOx : Select the GPIO peripheral number (x = A to I).
  * @param  GPIO_Pin : Specifies the pin number
  * @retval BitStatus : GPIO output pin status.
  */
BitStatus GPIO_ReadOutputDataBit(GPIO_Port_Typedef GPIOx, GPIO_Pin_TypeDef GPIO_Pin)
{
  uint8_t dataRead = 0;
  if(GPIOx == GPIO_PORT_0)
  {
	dataRead = ((BitStatus)(P0 & (uint8_t)GPIO_Pin));
  }else if(GPIOx == GPIO_PORT_1)
  {
	dataRead = ((BitStatus)(P1 & (uint8_t)GPIO_Pin));
  }else if(GPIOx == GPIO_PORT_2)
  {
	dataRead = ((BitStatus)(P2 & (uint8_t)GPIO_Pin));
  }else if(GPIOx == GPIO_PORT_3)
  {
	dataRead = ((BitStatus)(P3 & (uint8_t)GPIO_Pin));
  }else
  {

  }
  return dataRead;
}



/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/

