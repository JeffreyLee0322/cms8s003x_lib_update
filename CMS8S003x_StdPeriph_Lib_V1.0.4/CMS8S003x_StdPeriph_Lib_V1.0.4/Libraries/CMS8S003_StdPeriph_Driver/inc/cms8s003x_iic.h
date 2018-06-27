/**
  ******************************************************************************
  * @file    cms8s003x_iic.h
  * @author  LI WEI
  * @version V1.0.3
  * @date    04/24/2018
  * @brief   This file contains all the functions prototypes for the IIC firmware
  *          library.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CMS8S003x_IIC_H
#define __CMS8S003x_IIC_H

/* Includes ------------------------------------------------------------------*/
#include "cms8s003x.h"
#include "cms8s003x_conf.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/* Exported variables ------------------------------------------------------- */
/* Exported types ------------------------------------------------------------*/


/** @addtogroup IIC_Exported_Types
  * @{
  */
/** @defgroup IIC_Mode
  */
typedef enum
{
	IIC_Mode_Master    		= 	(uint8_t)0x00,  /* IIC master mode */
	IIC_Mode_Slave    		= 	(uint8_t)0x01		/* IIC slave mode */
} IIC_Mode_TypeDef;

/** @defgroup IIC_HighSpeedTimer
  */
typedef enum
{
	IIC_HighSpeedTimer_Disable    	= 	(uint8_t)0x00,  /* IIC High speed timer disable */
	IIC_HighSpeedTimer_Enable    		= 	(uint8_t)0x80		/* IIC High speed timer enable */
} IIC_HighSpeedTimer_TypeDef;

/** @defgroup IIC_HighSpeed
  */
typedef enum
{
	IIC_HighSpeed_Disable    	= 	(uint8_t)0x00,  /* IIC High speed mode disable */
	IIC_HighSpeed_Enable    	= 	(uint8_t)0x10		/* IIC High speed mode enable */
} IIC_HighSpeed_TypeDef;

/** @defgroup IIC_acknowledgement
  */
typedef enum
{
  IIC_Ack_Disable 	= 	(uint8_t)0x00,  /* No acknowledge */
  IIC_Ack_Enable  	= 	(uint8_t)0x08   /* Acknowledge Enabled */
} IIC_Ack_TypeDef;

/** @defgroup IIC_Stop
  */
typedef enum
{
  IIC_Stop_Disable 	= 	(uint8_t)0x00,  /* IIC Stop disable */
  IIC_Stop_Enable  	= 	(uint8_t)0x04   /* IIC Stop enable */
} IIC_Stop_TypeDef;

/** @defgroup IIC_Start
  */
typedef enum
{
  IIC_Start_Disable 	= 	(uint8_t)0x00,  /* IIC Start disable */
  IIC_Start_Enable  	= 	(uint8_t)0x02   /* IIC Start enable */
} IIC_Start_TypeDef;

/** @defgroup IIC_Run
  */
typedef enum
{
  IIC_Run_Disable 	= 	(uint8_t)0x00,  /* IIC run disable */
  IIC_Run_Enable  	= 	(uint8_t)0x01   /* IIC run enable */
} IIC_Run_TypeDef;

/** @defgroup IIC_Flag
  */
typedef enum
{
  IIC_Flag_Master_IT 							= 	(uint8_t)0x80,  	/* IIC master IT flag(Tx/Rx finished , or error) */
  IIC_Flag_Master_Bus_Busy  			= 	(uint8_t)0x40,   	/* IIC master bus busy */
	IIC_Flag_Master_Idle  					= 	(uint8_t)0x20,   	/* IIC master bus idle */
	IIC_Flag_Master_ARB_Lost  			= 	(uint8_t)0x10,   	/* IIC master bus idle */
	IIC_Flag_Master_Data_ACK  			= 	(uint8_t)0x08,   	/* IIC master data ack */
	IIC_Flag_Master_Add_ACK  				= 	(uint8_t)0x04,   	/* IIC master address ack */
	IIC_Flag_Master_Error  					= 	(uint8_t)0x02,   	/* IIC master error */
	IIC_Flag_Master_Busy  					= 	(uint8_t)0x01   	/* IIC master module busy */
} IIC_Flag_TypeDef;

/** @defgroup I2C_transfer_direction
  */
typedef enum
{
  IIC_Direction_Transmitter 	= (uint8_t)0x00,  /* Transmission direction */
  IIC_Direction_Receiver    	= (uint8_t)0x01   /* Reception direction */
} IIC_Direction_TypeDef;

#if 0
typedef enum
{
	IIC_Idle_StartAndSend									= 	(uint8_t)0x03,   	//配置IIC模式为START后跟SEND  
	IIC_Idle_StartSendAndStop 						= 	(uint8_t)0x07,    //配置IIC模式为START后跟SEND和STOP
	IIC_Idle_StartAndReceive_NoACK 				= 	(uint8_t)0x03,   	//配置IIC模式为START后接收采用应答 - 主机保持接收模式
	IIC_Idle_StartReceiveAndStop 					= 	(uint8_t)0x07,   	//配置IIC模式为START后跟RECEIVE和STOP
	IIC_Idle_StartAndReceive_ACK 					= 	(uint8_t)0x0B,   	//配置IIC模式为START后跟RECEIVE - 主机保持接收模式
	IIC_Idle_Forbidden_Sequence 					= 	(uint8_t)0x0F,   	//配置IIC模式为禁止组合
	IIC_Idle_HighSpeed  									= 	(uint8_t)0x11,   	//配置IIC模式为主代码发送并切换到高速模式

	IIC_Send                              = 	(uint8_t)0x01,  	//配置IIC模式为SEND操作
	IIC_Send_STOP                         = 	(uint8_t)0x04,    //配置IIC模式为停止
	IIC_Send_SendAndStop                  = 	(uint8_t)0x05,    //配置IIC模式为SEND后跟STOP
	IIC_Send_RepeatStartAndSend           = 	(uint8_t)0x03,    //配置IIC模式为重复START后跟SEND
	IIC_Send_RepeatStartSendAndStop       = 	(uint8_t)0x07,    //配置IIC模式为重复START后跟SEND和STOP
	IIC_Send_RepeatStartReceive_NoACK     = 	(uint8_t)0x03,    //配置IIC模式为重复START后跟应答RECEIVE - 主机保持接收
	IIC_Send_RepeatStartSendAndStop       = 	(uint8_t)0x07,    //配置IIC模式为重复START后跟SEND和STOP
	IIC_Send_RepeatStartReceive_ACK       = 	(uint8_t)0x0B,    //配置IIC模式为重复START后跟RECEIVE - 主机保持接收
	IIC_Send_ForbiddenSequence            = 	(uint8_t)0x0F,    //配置IIC模式为禁止组合

	IIC_Receive_NoACK                     = 	(uint8_t)0x01,    //配置IIC模式为采用应答的RECEIVE操作 - 主机保持接收
	IIC_Receive_STOP                      = 	(uint8_t)0x04,		//配置IIC位STOP
	IIC_Receive_ReceiveAndStop            = 	(uint8_t)0x05,  	//配置IIC模式为RECEIVE后跟STOP
	IIC_Receive_ACK                       = 	(uint8_t)0x09,		//配置IIC模式为RECEIVE操作 - 主机保持接收
	IIC_Receive_ForbiddenSequence         = 	(uint8_t)0x0D,		//配置IIC模式为禁止组合
	IIC_Receive_RepeatStartReceive_NoACK  = 	(uint8_t)0x03,		//配置IIC模式为重复START接着采用应答RECEIVE操作 - 主机保持接收
	IIC_Receive_RepeatStartReceiveStop    = 	(uint8_t)0x07,		//配置IIC模式为重复START 接着是RECEIVE和STOP
	IIC_Receive_RepeatStartReceive        = 	(uint8_t)0x0B,		//配置IIC模式为重复START后跟RECEIBE - 主机保持接收
	IIC_Receive_RepeatStartSend           = 	(uint8_t)0x03,		//配置IIC模式为重复START后跟SNED - 主机保持在发送模式
	IIC_Receive_RepeatStartSendStop       = 	(uint8_t)0x07			//配置IIC模式为重复START 后跟SEND 和 STOP
} IIC_MasterMode_TypeDef;
#endif
/**
	* IIC Slave mode config
	*/
typedef enum
{
	IIC_Reset         = 	(uint8_t)0x80,
	IIC_Reset_None    = 	(uint8_t)0x00
} IIC_Reset_TypeDef;

typedef enum
{
	IIC_Priority_High     = 	(uint8_t)0x40,
	IIC_Priority_Low     	= 	(uint8_t)0x00
} IIC_ITPriority_TypeDef;

typedef enum
{
	IIC_IT                = 	(uint8_t)0x40,
} IIC_ITStatus_TypeDef;

typedef struct IIC_InitDef
{
	/* IIC Master Mode Register */
	IIC_Mode_TypeDef          IIC_Mode;
	uint8_t                   IIC_Frequency;
	IIC_HighSpeed_TypeDef 		IIC_HighSpeed:1;
	uint8_t                   IIC_SlaveAddress;
	IIC_Direction_TypeDef     IIC_Direction:1;
	IIC_Ack_TypeDef						IIC_ACK:1;

	/* IIC Slave Mode Register */
	uint8_t                   IIC_OwnAddress;
	IIC_Reset_TypeDef         IIC_Reset;

} IIC_Init_TypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup IIC_Private_Macros
  * @{
  */
#define IIC_ENABLE_BIT 						(uint8_t)0x80
#define IIC_SLAVE_MODE_ENABLE   	(uint8_t)0x01
#define IIC_SLAVE_RESET_ENABLE   	(uint8_t)0x80
#define IIC_IT_ENABLE_BIT         (uint8_t)0x40
/**
  * @brief Macro used by the assert function to check the different functions parameters.
  */


/**
  * @}
  */

/* Exported functions ------------------------------------------------------- */

/** @addtogroup IIC_Exported_Functions
  * @{
  */
/* IIC Master Mode Functions */
void IIC_Init(IIC_Init_TypeDef *IIC_Init);
void IIC_Cmd(FunctionalState NewState);
void IIC_MasterSendData(uint8_t Data);
uint8_t IIC_MasterReceiveData(void);
void IIC_Start(void);
void IIC_Stop(void);
void IIC_AckConfig(IIC_Ack_TypeDef Ack);
uint8_t IIC_MasterGetSendBuf(void);
uint8_t IIC_MasterGetReceiveBuf(void);

/* IIC Slave Mode Functions */
void IIC_SlaveCmd(FunctionalState NewState);
void IIC_SlaveReset(void);
void IIC_SlaveSendData(uint8_t Data);
uint8_t IIC_SlaveReceiveData(void);

/* IIC Interrupt Functions */
void IIC_ITConfig(IIC_ITPriority_TypeDef ITPriority, FunctionalState NewState);
FlagStatus IIC_GetFlagStatus(IIC_Flag_TypeDef IIC_Flag);
void IIC_ClearFlag(IIC_Flag_TypeDef IIC_FLAG);
ITStatus IIC_GetITStatus(IIC_ITStatus_TypeDef IIC_ITPendingBit);
void IIC_ClearITPendingBit(IIC_ITStatus_TypeDef IIC_ITPendingBit);
/**
  * @}
  */

#endif /* __CMS8S003x_IIC_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
