/*
 * NVIC_config.h
 *
 *  Created on: August 4, 2023
 *      Author: Hamdy Aouf
 */

#ifndef MCAL_NVIC_CONFIG_H_
#define MCAL_NVIC_CONFIG_H_


#include "Common/ErrorState.h"


#define NVIC_PRIORITY_BITS				4


/********************************************************************************************/
/*************************		ENUMS		*************************************************/
/********************************************************************************************/

typedef enum{

	/*************	Interrupts	**************************/
	IRQ_WWDG			= 0,
	IRQ_EXTI16			= 1,
	IRQ_EXTI21			= 2,
	IRQ_EXTI22			= 3,
	IRQ_FLASH			= 4,
	IRQ_RCC_INTERRUPT	= 5,
	IRQ_EXTI0			= 6,
	IRQ_EXTI1			= 7,
	IRQ_EXTI2			= 8,
	IRQ_EXTI3			= 9,
	IRQ_EXTI4			= 10,
	IRQ_DMA1_Stream0	= 11,
	IRQ_DMA1_Stream1	= 12,
	IRQ_DMA1_Stream2	= 13,
	IRQ_DMA1_Stream3	= 14,
	IRQ_DMA1_Stream4	= 15,
	IRQ_DMA1_Stream5	= 16,
	IRQ_DMA1_Stream6	= 17,
	/*
	 *
	 *
	 * STILL Interrupts
	 *
	 *
	 */
}IRQn_t;




#endif /* MCAL_NVIC_CONFIG_H_ */
