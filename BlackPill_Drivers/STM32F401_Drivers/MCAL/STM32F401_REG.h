/*
 * STM32F401_REG.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: August 1, 2023
 *	Brief		: This file contains all MACROs, STRUCTs and registers addresses for the STM32F401
 */

#ifndef HAL_STM32F401_REG_H_
#define HAL_STM32F401_REG_H_


#include "../Common/STD_Types.h"
#include "../Common/CommonMacros.h"

/*************************		MACROS		*****************************/
/*
 *	Black Pill Mapped peripheral register regions
 */

/** System Buses **/
#define	APB1_BASE		0x40000000
#define	APB2_BASE		0x40010000
#define	AHB1_BASE		0x40020000
#define	AHB2_BASE		0x50000000

/** Peripherals Bases **/
#define RCC_BASE		(AHB1_BASE+0x3800UL)

#define EXTI_BASE		(APB2_BASE+0x3C00UL)

#define SYSCFG_BASE	   (APB2_BASE+0x3800UL)

#define GPIOA_BASE     (AHB1_BASE+0x0000UL)
#define GPIOB_BASE     (AHB1_BASE+0x0400UL)
#define GPIOC_BASE     (AHB1_BASE+0x0800UL)
#define GPIOD_BASE     (AHB1_BASE+0x0C00UL)
#define GPIOE_BASE     (AHB1_BASE+0x1000UL)
#define GPIOH_BASE     (AHB1_BASE+0x1C00UL)


#define CRC_BASE	   (AHB1_BASE+0x3000UL)

/** Peripherals Addresses	**/

#define GPIOA			((volatile GPIO_t*) GPIOA_BASE)
#define GPIOB			((volatile GPIO_t*) GPIOB_BASE)
#define GPIOC			((volatile GPIO_t*) GPIOC_BASE)
#define GPIOD			((volatile GPIO_t*) GPIOD_BASE)
#define GPIOE			((volatile GPIO_t*) GPIOE_BASE)
#define GPIOH			((volatile GPIO_t*) GPIOH_BASE)

#define EXTI			((volatile EXTI_t*) EXTI_BASE)

#define RCC				((volatile RCC_t*) RCC_BASE)

#define SYSCFG			((volatile SYSCFG_t*) SYSCFG_BASE)

#define CRC				((volatile CRC_t*) CRC_BASE)

/********************************************************************************************/
/*************************		MACRO FUNCTIONS		*****************************************/
/********************************************************************************************/



/********************************************************************************************/
/*************************		ENUMS		*************************************************/
/********************************************************************************************/


/********************************************************************************************/
/************************* 		DataTypes	*************************************************/
/********************************************************************************************/

/************************* GPIO Type **********************************************************/
typedef struct{
	volatile uint32_t MODER;		                      	/** Direction Control **/
	volatile uint32_t OTYPER;	                      	    /** Output Type **/
	volatile uint32_t OSPEEDR;	                      	    /** Output Speed **/
	volatile uint32_t PUPDR;		                        /** Pull-up/down Control **/
	volatile uint32_t IDR;		                      	    /** Port input data **/
	volatile uint32_t ODR;		                      	    /** Port output data **/
	volatile uint32_t BSRR;		                      	    /** Set/Reset Corresponding Bits **/
	volatile uint32_t LCKR;		                      	    /** Lock the configuration of the port bits **/
	volatile uint32_t AFRL;		                      	    /** configure alternate function of LOW I/O **/
	volatile uint32_t AFRH;		                      	    /** configure alternate function of HIGH I/O **/
}GPIO_t;

/***************************** RCC Type*********************************************************/
typedef struct{
	volatile uint32_t CR;			/** RCC clock control register **/
	volatile uint32_t PLLCFGR;		/** RCC clock control register **/
	volatile uint32_t CFGR;			/** RCC clock configuration register **/
	volatile uint32_t CIR;			/** RCC clock interrupt register **/
	volatile uint32_t AHB1RSTR;		/** RCC AHB1 peripheral reset register (GPIOs,DMA,CRC)**/
	volatile uint32_t AHB2RSTR;		/** RCC AHB2 peripheral reset register (OTG)**/
	const uint32_t RESERVED1[2];
	volatile uint32_t APB1RSTR;		/** RCC APB1 peripheral reset **/
	volatile uint32_t APB2RSTR;		/** RCC APB2 peripheral reset **/
	const uint32_t RESERVED2[2];
	volatile uint32_t AHB1ENR;		/** RCC AHB1 peripheral clock enable register (GPIOs,DMA,CRC)**/
	volatile uint32_t AHB2ENR;		/** RCC AHB2 peripheral clock enable register **/
	const uint32_t RESERVED3[2];
	volatile uint32_t APB1ENR;		/** **/
	volatile uint32_t APB2ENR;		/** **/
	const uint32_t RESERVED4[2];
	volatile uint32_t AHB1LPENR;	/** RCC AHB1 peripheral clock enable in low power mode register **/
	volatile uint32_t AHB2LPENR;	/** **/
	const uint32_t RESERVED5[2];
	volatile uint32_t APB1LPENR;	/** **/
	volatile uint32_t APB2LPENR;	/** **/
	volatile uint32_t BDCR;			/** RCC Backup domain control register **/
	volatile uint32_t CSR;			/**RCC clock control & status register  **/
	const uint32_t RESERVED6[2];
	volatile uint32_t SSCGR;		/** **/
	volatile uint32_t PLLI2SCFGR;	/** **/
	const uint32_t RESERVED7;
	volatile uint32_t DCKCFGR;		/** **/

}RCC_t;

/********************************************************************************************/
typedef struct{
	volatile uint32_t IMR;		/** Interrupt Mask Register **/
	volatile uint32_t EMR;		/** Event Mask Register **/
	volatile uint32_t RTSR;		/** Rising Trigger selection Register **/
	volatile uint32_t FTSR;		/** Falling Trigger selection Register **/
	volatile uint32_t SWIER;	/** Software Interrupt event Register **/
	volatile uint32_t PR;		/** Pending Interrupt Register **/
}EXTI_t;
/********************************************************************************************/
typedef struct{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	const uint32_t RESERVED[2];
	volatile uint32_t CMPCR;
}SYSCFG_t;

/********************************************************************************************/
typedef struct{

}DMA_t;


/********************************************************************************************/
#endif /* HAL_STM32F401_REG_H_ */
