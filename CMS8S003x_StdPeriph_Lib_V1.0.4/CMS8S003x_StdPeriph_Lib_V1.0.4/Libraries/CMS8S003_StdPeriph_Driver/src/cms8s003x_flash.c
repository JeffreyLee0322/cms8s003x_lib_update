/**
  ******************************************************************************
  * @file    cms8s003x_flash.c
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file provides all the FLASH firmware functions.
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
#include "cms8s003x_flash.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define FLASH_OPERATION_ERROR   ((uint8_t)0x20)


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private Constants ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

/** @addtogroup FLASH_Public_functions
  * @{
  */

/**
  * @brief  Deinitializes the FLASH registers to their default reset values.
  * @param  None
  * @retval None
  */
void FLASH_DeInit(void)
{
  MDATA |= 0xFF; //Flash data register deinit
	
	MADRL &= 0x00; //Flash address Low register deinit
	MADRH &= 0x00; //Flash address High register deinit
	
	MCTRL &= 0x00; //Flash control register deinit
	MCTRL |= 0x10;
}

/**
  * @brief  Programs one byte in program or data EEPROM memory
  * @param  Flash_Zone : Zone where the flash will be operate
  * @param  Address : Address where the byte will be programmed
  * @param  Data : Value to be programmed
  * @retval None
  */
void FLASH_ProgramByte(FLASH_Zone_TypeDef Flash_Zone, uint32_t Address, uint8_t Data)
{
	uint8_t finishFlag = 0;
	
	/* Flash address config */
	MADRH = (uint8_t)(Address >> 8);
	MADRL = (uint8_t)Address;
	
	/* Judge Flash address whether 'FFH' or not */
	if((MCTRL & FLASH_ERROR_BIT) != 0)
	{
		return;
	}
	
	/* Flash data config */
	MDATA = Data;
	
	/* Enable flash R/W/E, Program mode, Zone select */
	//MCTRL &= 0x00;
	MCTRL = ((uint8_t)Flash_Zone | (uint8_t)Flash_OperationMode_Program | (uint8_t)FLASH_Enable_RWE);
	
	/* Wait flash program finished */
	/* If finishFlag=0, operation finished */
	while(MCTRL & 0x01);
}

/**
  * @brief  Programs one word (4 bytes) in program or data EEPROM memory
  * @param  Flash_Zone : Zone where the flash will be operate
  * @param  Address : The address where the data will be programmed
  * @param  Data : Value to be programmed
  * @retval None
  */
void FLASH_ProgramWord(FLASH_Zone_TypeDef Flash_Zone, uint32_t Address, uint32_t Data)
{
	uint8_t i = 0;
	uint32_t MoveAddress = 0;
	
	MoveAddress = Address;
	/* Program mode, Zone select */
	MCTRL = ((uint8_t)Flash_Zone | (uint8_t)Flash_OperationMode_Program);
	
	for(i = 0; i < 4; i++)
	{
		MoveAddress += i;
		
		/* Flash address config */
		MADRH = (uint8_t)(MoveAddress >> 8);
		MADRL = (uint8_t)MoveAddress;
		
		/* Judge Flash address whether 'FFH' or not */
		if((MCTRL & FLASH_ERROR_BIT) != 0)
		{
			return;
		}
		
		/* Flash data config */
		MDATA = (uint8_t)(Data >> (8*i));
		
		/* Enable flash R/W/E */
		MCTRL |= ((uint8_t)FLASH_Enable_RWE);
		
		/* Wait flash program finished */
		/* If finishFlag=0, operation finished */
		while(MCTRL & 0x01);
	}
}


/**
  * @brief  Reads one byte from flash memory
  * @param  Flash_Zone : Zone where the flash will be operate
  * @param  Address : Address to read
  * @retval Value of the byte
  */
uint8_t FLASH_ReadByte(FLASH_Zone_TypeDef Flash_Zone, uint32_t Address)
{
	uint8_t read_data = 0;
	
  /* Flash address config */
	MADRH = (uint8_t)(Address >> 8);
	MADRL = (uint8_t)Address;

	/* Enable flash R/W/E, Read mode, Zone select */
	MCTRL = ((uint8_t)Flash_Zone | (uint8_t)Flash_OperationMode_Read | (uint8_t)FLASH_Enable_RWE);
	
	/* Wait flash read finished */
	/* If finishFlag=0, operation finished */
	while(MCTRL & 0x01);
	
	/* Flash data result */
	read_data = MDATA;
	
	return read_data;
}

/**
  * @brief  Erases a block in the program or data memory.
  * @param  Flash_Zone : Zone where the flash will be operate
  * @param  Address : Address to erase
  * @retval None.
  */
void FLASH_EraseBlock(FLASH_Zone_TypeDef Flash_Zone, uint32_t Address)
{
  /* Flash address config */
	MADRH = (uint8_t)(Address >> 8);
	MADRL = (uint8_t)Address;
	
	/* Enable flash R/W/E, Erase mode, Zone select */
	MCTRL = ((uint8_t)Flash_Zone | (uint8_t)Flash_OperationMode_Erase | (uint8_t)FLASH_Enable_RWE);
	
	/* Wait flash erase finished */
	/* If finishFlag=0, operation finished */
	while(MCTRL & 0x01);
}

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/