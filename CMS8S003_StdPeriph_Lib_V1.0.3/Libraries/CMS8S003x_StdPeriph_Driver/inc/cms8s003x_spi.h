/**
  ******************************************************************************
  * @file    cms8s003x_spi.h
  * @author  LI WEI
  * @version V1.0.0
  * @date    04/26/2018
  * @brief   This file contains all the functions prototypes for the SPI firmware
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
#ifndef __CMS8S003X_SPI_H
#define __CMS8S003X_SPI_H

/* Includes ------------------------------------------------------------------*/
//#include "cms8s003x.h"
#include <CMS\CMS51F003.H>
#include "cms8s003x_conf.h"

/** @addtogroup CMS8S003x_StdPeriph_Driver
  * @{
  */

/** @addtogroup SPI_Exported_Types
  * @{
  */

/**
  * @brief SPI master/slave mode
  * Warning: element values correspond to MSTR bit position
  */
typedef enum {
  SPI_Mode_Master = (uint8_t)0x10, /*!< SPI Master configuration */
  SPI_Mode_Slave  = (uint8_t)0x00  /*!< SPI Slave configuration */
} SPI_Mode_TypeDef;

/**
  * @brief SPI BaudRate Prescaler
  * Warning: element values correspond to BR bits position
  */
typedef enum {
  SPI_BaudRatePrescaler_4   = (uint8_t)0x00, /*!< SPI frequency = frequency(CPU)/4 */
  SPI_BaudRatePrescaler_8   = (uint8_t)0x01, /*!< SPI frequency = frequency(CPU)/8 */
  SPI_BaudRatePrescaler_16  = (uint8_t)0x02, /*!< SPI frequency = frequency(CPU)/16 */
  SPI_BaudRatePrescaler_32  = (uint8_t)0x03, /*!< SPI frequency = frequency(CPU)/32 */
  SPI_BaudRatePrescaler_64  = (uint8_t)0x20, /*!< SPI frequency = frequency(CPU)/64 */
  SPI_BaudRatePrescaler_128 = (uint8_t)0x21, /*!< SPI frequency = frequency(CPU)/128 */
  SPI_BaudRatePrescaler_256 = (uint8_t)0x22,  /*!< SPI frequency = frequency(CPU)/256 */
  SPI_BaudRatePrescaler_512 = (uint8_t)0x23  /*!< SPI frequency = frequency(CPU)/256 */
} SPI_BaudRatePrescaler_TypeDef;

/**
  * @brief SPI Clock Polarity
  * Warning: element values correspond to CPOL bit position
  */
typedef enum {
  SPI_CPOL_LOW  = (uint8_t)0x00, /*!< Clock to 0 when idle */
  SPI_CPOL_HIGH = (uint8_t)0x08  /*!< Clock to 1 when idle */
} SPI_CPOL_TypeDef;

/**
  * @brief SPI Clock Phase
  * Warning: element values correspond to CPHA bit position
  */
typedef enum {
  SPI_CPHA_1Edge = (uint8_t)0x04, /*!< The first clock transition is the first data capture edge, Rising edge */
  SPI_CPHA_2Edge = (uint8_t)0x00  /*!< The second clock transition is the first data capture edge, Falling edge */
} SPI_CPHA_TypeDef;

/**

  */
typedef enum {
  SPI_SSCR_SSO0 = (uint8_t)0x01,
  SPI_SSCR_SSO1 = (uint8_t)0x02,
  SPI_SSCR_SSO2 = (uint8_t)0x04,
  SPI_SSCR_SSO3 = (uint8_t)0x08,
  SPI_SSCR_SSO4 = (uint8_t)0x10,
  SPI_SSCR_SSO5 = (uint8_t)0x20,
  SPI_SSCR_SSO6 = (uint8_t)0x40,
  SPI_SSCR_SSO7 = (uint8_t)0x80
} SPI_SSCR_TypeDef; 


typedef enum {
  SPI_NSS0 = (uint8_t)0x00,
  SPI_NSS7 = (uint8_t)0x02,
} SPI_SLAVE_SSI_TypeDef; 

/**
  * @brief SPI_IT possible values
  * Elements values convention: 0xYX
  *   X: Position of the corresponding Interrupt
  *   Y: ITPENDINGBIT position
  */
typedef enum {
  SPI_FLAG_SPISIF = (uint8_t)0x80, /*!< SPI transmit finish state flag */
  SPI_FLAG_WCOL   = (uint8_t)0x40,  /*!< SPI write conflict state flag */
  SPI_FLAG_MODF   = (uint8_t)0x10, /*!< SPI mode error state flag */
} SPI_IT_TypeDef;

//------------------------------------------------------------------Add------------------------
/**
  * @brief Serial Peripheral Interface (SPI)
  */
sfr SPI0_SPCR      = 0xEC; /* SPI Control Register      */
sfr SPI0_SPSR      = 0xED; /* SPI Status Register       */
sfr SPI0_SPDR      = 0xEE; /* SPI I/O Register          */
sfr SPI0_SSCR      = 0xEF; /* SPI Sleve Select Register */

typedef enum {
  SPI_Interrupt_Priority_HIGH = (uint8_t)0x80, /*!< SPI interrupt high priority configuration */
  SPI_Interrupt_Priority_LOW  = (uint8_t)0x00  /*!< SPI interrupt low priority configuration */
} InterruptPriority;

typedef enum {
  Peripheral_SPI_Interrupt = (uint8_t)0x80, /*!< SPI interrupt have generate flag*/
  
} PeripheralInterruptFlags;

#define SPI_SPCR_RESET_VALUE  ((uint8_t)0x00) /*!< Control Register reset value */
#define SPI_SSCR_RESET_VALUE   ((uint8_t)0xFF) /*!< SSCR Register reset value */

#define SPEN_ENABLE_BIT  (uint8_t)0x40
#define SPIIE_ENABLE_BIT  (uint8_t)0x80
#define SPSR_SSCEN_ENABLE_BIT (uint8_t)0x01


typedef struct spi_initdef
{
	SPI_Mode_TypeDef SPI_Mode;          //SPI模式选择位 SPI_MasterMode   SPI_SlaveMode
	SPI_CPOL_TypeDef SPI_CPOL;          //SPI时钟极性选择位： SPI_IDLEH  SPI_IDLEL
	SPI_CPHA_TypeDef SPI_CPHA;          //SPI时钟相位选择位： SPI_CPHA1  SPI_CPHA2
	SPI_BaudRatePrescaler_TypeDef SPI_Frequency;     //SPI时钟频率选择位
} SPI_Init_TypeDef;

/**
  * @}
  */

/* Private define ------------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/** @addtogroup SPI_Private_Macros
  * @brief Macros used by the assert_param function to check the different functions parameters.
  * @{
  */
/**
  * @brief Macro used by the assert_param function in order to check the baudrate values
  */
#define IS_SPI_BAUDRATE_PRESCALER(Prescaler) (((Prescaler) == SPI_BaudRatePrescaler_4) || \
                                              ((Prescaler) == SPI_BaudRatePrescaler_8) || \
                                              ((Prescaler) == SPI_BaudRatePrescaler_16) || \
                                              ((Prescaler) == SPI_BaudRatePrescaler_32) || \
                                              ((Prescaler) == SPI_BaudRatePrescaler_64) || \
                                              ((Prescaler) == SPI_BaudRatePrescaler_128) || \
                                              ((Prescaler) == SPI_BaudRatePrescaler_256) || \
                                              ((Prescaler) == SPI_BaudRatePrescaler_512))
											  
/**
  * @brief Macro used by the assert_param function in order to check the SPI Mode values
  */
#define IS_SPI_MODE(Mode) (((Mode) == SPI_Mode_Master) || \
                           ((Mode) == SPI_Mode_Slave))
						   
/**
  * @brief Macro used by the assert_param function in order to check the polarity values
  */
#define IS_SPI_POLARITY(ClkPol) (((ClkPol) == SPI_CPOL_LOW) || \
                                 ((ClkPol) == SPI_CPOL_HIGH))
								 
/**
  * @brief Macro used by the assert_param function in order to check the phase values  
  */
#define IS_SPI_PHASE(ClkPha) (((ClkPha) == SPI_CPHA_1Edge) || \
                              ((ClkPha) == SPI_CPHA_2Edge))

/**
  * @brief Macro used by the assert_param function in order to check the priority values
  */
#define IS_SPI_PRIORITY(ClkPol) (((ClkPol) == SPI_Interrupt_Priority_HIGH) || \
                                 ((ClkPol) == SPI_Interrupt_Priority_LOW))		

/**
  * @brief Macro used by the assert_param function in order to check the different flags values
  */
#define IS_SPI_FLAG(Flag) (((Flag) == Peripheral_SPI_Interrupt))

/**
  * @brief Macro used by the assert_param function in order to check the different
  *   sensitivity values for the pending bit
  */
#define IS_SPI_GET_IT(ITPendingBit) (((ITPendingBit) == SPI_FLAG_SPISIF)  || \
                                     ((ITPendingBit) == SPI_FLAG_WCOL) || \
                                     ((ITPendingBit) == SPI_FLAG_MODF))
/**
  * @}
  */

/* Exported functions ------------------------------------------------------- */

/** @addtogroup SPI_Exported_Functions
  * @{
  */
void SPI_DeInit(void);
void SPI_Init(SPI_Init_TypeDef* SPI_InitDef);
void SPI_Cmd(FunctionalState NewState);
void SPI_ITConfig(InterruptPriority Priority, FunctionalState NewState);
void SPI_SendData(uint8_t Data);
uint8_t SPI_ReceiveData();
void SPI_NSSInternalSoftwareCmd(SPI_SSCR_TypeDef Ss0x, FunctionalState NewState);
FlagStatus SPI_GetFlagStatus(PeripheralInterruptFlags SPI_FLAG);
ITStatus SPI_GetITStatus(SPI_IT_TypeDef SPI_FLAG);
void SPI_ClearITPendingBit(SPI_IT_TypeDef SPI_IT);

/**
  * @}
  */

#endif /* __CMS8S003X_SPI_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2018 CMSemicon *****END OF FILE****/
