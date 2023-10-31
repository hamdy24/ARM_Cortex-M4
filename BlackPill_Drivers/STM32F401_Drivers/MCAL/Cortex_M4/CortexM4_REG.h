/*
 * STM32F401_REG.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: August 1, 2023
 *	Brief		: This file contains all MACROs, STRUCTs and registers addresses for the Cortex_M 4 Core Peripherals
 */

#ifndef MCAL_STM32F401_REG_H_
#define MCAL_STM32F401_REG_H_

/************************************ Includes Start *************************************************/
#include "../../Common/STD_Types.h"
/************************************ Includes END  *************************************************/

/************************************ Macros Start *************************************************/
/*
 *  STM32 core peripheral register regions
 */

#define NVIC_BASE_ADDRESS	(0xE000E100UL)
#define SCB_BASE_ADDRESS	(0xE000ED00UL)
#define STK_BASE_ADDRESS	(0xE000E010UL)

//#define FPU_BASE_ADDRESS	(0xE000ED88)
//#define MPU_BASE_ADDRESS	(0xE000E010)

#define NVIC			((volatile NVIC_t *)NVIC_BASE_ADDRESS)
#define SCB				((volatile SCB_t *) SCB_BASE_ADDRESS)
#define STK				((volatile STK_t *) STK_BASE_ADDRESS)
//#define MPU
//#define FPU

/************************************ Macros END  *************************************************/

/************************************ HelperEnums Declaration Start *************************************************/

/************************************ HelperEnums Declaration  END  *************************************************/

/************************************ DataTypes Declaration Start *************************************************/

/********************************************************************************************/

typedef struct{
	volatile uint32_t ISER[8];					/* Interrupt Set-Enable Registers */
	const uint32_t RESERVED0[24U];
	volatile uint32_t ICER[8];					/* Interrupt Clear-Enable Registers */
	const uint32_t RESERVED1[24U];
	volatile uint32_t ISPR[8];					/* Interrupt Set-Pending Registers */
	const uint32_t RESERVED2[24U];
	volatile uint32_t ICPR[8];					/* Interrupt Clear-Pending Registers */
	const uint32_t RESERVED3[24U];
	volatile uint32_t IABR[8];					/* Interrupt Active Bit Register */
	const uint32_t RESERVED4[56U];
	/*
	 * IPR should be uint32_t IPR[60U] but it is better to divide it by making it as follows
	 * so now we access each 8 bits for any EXTI by its number
	 */
	volatile uint8_t IP[240U];				    /* Interrupt Priority Register */
	const uint32_t RESERVED5[644U];
	volatile uint32_t STIR[8];					/* Software Trigger Interrupt Register */
}NVIC_t;

/********************************************************************************************/

typedef struct{
	volatile uint32_t CPUID;
	volatile uint32_t ICSR;
	volatile uint32_t VTOR;
	volatile uint32_t AIRCR;
	volatile uint32_t SCR;
	volatile uint32_t CCR;
	volatile uint32_t SHPR1;
	volatile uint32_t SHPR2;
	volatile uint32_t SHPR3;
	volatile uint32_t SHCRS;
	volatile uint32_t CFSR;

	/*
	 *
	 *
	 * Still some registers
	 *
	 *
	 *
	 */
}SCB_t;

/********************************************************************************************/
typedef struct{
	volatile uint32_t CTRL;
	volatile uint32_t LOAD;
	volatile uint32_t VAL;
	volatile uint32_t CALIB;
}STK_t;

/************************************ DataTypes Declaration  END  *************************************************/


#endif /* MCAL_STM32F401_REG_H_ */
