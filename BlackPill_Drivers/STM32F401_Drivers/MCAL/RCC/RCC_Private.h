/*
 * RCC_Private.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 23, 2023
 *	Brief		: This file contains all private declarations and macros for RCC
 */

#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_
/*************************		Includes	*****************************************/
#include "RCC_Config.h"

#include "../STM32F401_Drivers/MCAL/STM32F401_REG.h"

/********************************************************************************************/
/*************************		MACRO		*************************************************/
/********************************************************************************************/
// CR REG
#define HSI_ON_BIT_POS						0
#define HSI_RDY_BIT_POS						1
// CR REG
#define HSE_ON_BIT_POS						16
#define HSE_RDY_BIT_POS						17
#define HSE_BYP_BIT_POS						18
// BDCR REG
#define LSE_ON_BIT_POS						0
#define LSE_RDY_BIT_POS						1
#define LSE_BYP_BIT_POS						2
// CSR REG
#define LSI_ON_BIT_POS						0
#define LSI_RDY_BIT_POS						1
// CR REG
#define RCC_CFGR_SW0_POS					0
#define RCC_CFGR_SW1_POS					1
// APB2 Prescaler
#define PPRE2_BIT_POS						13
#define PPRE2_BITS_MSK						(0x7<<PPRE2_BIT_POS)
// APB1 Prescaler
#define PPRE1_BIT_POS						10
#define PPRE1_BITS_MSK						(0x7<<PPRE1_BIT_POS)
// AHB Prescaler
#define HPRE_BIT_POS						4
#define HPRE_BITS_MSK						(0xF<<HPRE_BIT_POS)




/********************************************************************************************/
/*************************		MACRO FUNCTIONS		*****************************************/
/********************************************************************************************/

#define HAL_RCC_GPIOA_CLK_ENABLE()			(SET_BIT(RCC->AHB1ENR,RCC_GPIOA_EN))
#define HAL_RCC_GPIOB_CLK_ENABLE()			(SET_BIT(RCC->AHB1ENR,RCC_GPIOB_EN))
#define HAL_RCC_GPIOC_CLK_ENABLE()			(SET_BIT(RCC->AHB1ENR,RCC_GPIOC_EN))
#define HAL_RCC_GPIOD_CLK_ENABLE()			(SET_BIT(RCC->AHB1ENR,RCC_GPIOD_EN))
#define HAL_RCC_GPIOE_CLK_ENABLE()			(SET_BIT(RCC->AHB1ENR,RCC_GPIOE_EN))
#define HAL_RCC_GPIOH_CLK_ENABLE()			(SET_BIT(RCC->AHB1ENR,RCC_GPIOH_EN))

#define HAL_RCC_DMA1_CLK_ENABLE()			(SET_BIT(RCC->AHB1ENR,RCC_DMA1_EN))
#define HAL_RCC_DMA2_CLK_ENABLE()			(SET_BIT(RCC->AHB1ENR,RCC_DMA2_EN))

#define HAL_RCC_CRC_CLK_ENABLE()			(SET_BIT(RCC->AHB1ENR,RCC_CRC_EN))



#define HAL_RCC_GPIOA_CLK_DISABLE()			(CLR_BIT(RCC->AHB1ENR,RCC_GPIOA_EN))
#define HAL_RCC_GPIOB_CLK_DISABLE()			(CLR_BIT(RCC->AHB1ENR,RCC_GPIOB_EN))
#define HAL_RCC_GPIOC_CLK_DISABLE()			(CLR_BIT(RCC->AHB1ENR,RCC_GPIOC_EN))
#define HAL_RCC_GPIOD_CLK_DISABLE()			(CLR_BIT(RCC->AHB1ENR,RCC_GPIOD_EN))
#define HAL_RCC_GPIOE_CLK_DISABLE()			(CLR_BIT(RCC->AHB1ENR,RCC_GPIOE_EN))
#define HAL_RCC_GPIOH_CLK_DISABLE()			(CLR_BIT(RCC->AHB1ENR,RCC_GPIOH_EN))

#define HAL_RCC_DMA1_CLK_DISABLE()			(CLR_BIT(RCC->AHB1ENR,RCC_DMA1_EN))
#define HAL_RCC_DMA2_CLK_DISABLE()			(CLR_BIT(RCC->AHB1ENR,RCC_DMA2_EN))

#define HAL_RCC_CRC_CLK_DISABLE()			(CLR_BIT(RCC->AHB1ENR,RCC_CRC_EN))




#define HAL_RCC_SYSCFG_CLK_ENABLE()			(SET_BIT(RCC->APB2ENR,RCC_SYSCFG_EN))


/********************************************************************************************/
/*************************		ENUMS		*************************************************/
/********************************************************************************************/

typedef enum{
	RCC_GPIOA_EN,
	RCC_GPIOB_EN,
	RCC_GPIOC_EN,
	RCC_GPIOD_EN,
	RCC_GPIOE_EN,
	RCC_GPIOH_EN  = 7,
	RCC_CRC_EN  = 12,
	RCC_DMA1_EN = 21,
	RCC_DMA2_EN = 22,
	RCC_SYSCFG_EN = 14,
}AHB1ENR_Bits_enuType;

//typedef enum{
//	HSI_ON = 0,
//	HSI_RDY,
//
//	HSE_ON = 16,
//	HSE_RDY,
//	HSE_BYP,
//
//
//}OSC_ControlBits_enuType;
#endif /* MCAL_RCC_RCC_PRIVATE_H_ */
