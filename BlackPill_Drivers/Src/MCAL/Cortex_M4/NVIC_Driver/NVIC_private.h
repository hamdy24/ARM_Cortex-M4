/*
 * NVIC_private.h
 *
 *  Created on: August 3, 2023
 *      Author: Hamdy Aouf
 */

#ifndef MCAL_NVIC_DRIVER_NVIC_PRIVATE_H_
#define MCAL_NVIC_DRIVER_NVIC_PRIVATE_H_

/************************* Includes ********************************/
#include "Common/CommonMacros.h"
#include "Common/ErrorState.h"
#include "Common/STD_Types.h"


#include "MCAL/Cortex_M4/CortexM4_REG.h"

#include "MCAL/Cortex_M4/NVIC_Driver/NVIC_config.h"


#define SHIFT_FIVE				5		/* Shift five to get register number from IRQn*/
#define GET_BIT_HELPER			0x1F	/* AND with 31 hex value to get Bit number from IRQn*/

typedef enum{
	/**************	Exceptions ***************************/
	NMI				= -10,
	MemManage		= -9,
	BusFault		= -8,
	UsageFault		= -7,
	SVCall			= -5,
	Debug_Monitor	= -4,
	PendSV			= -2,
	Systick			= -1,

}MVIC_Exceptions_t;


#endif /* MCAL_NVIC_DRIVER_NVIC_PRIVATE_H_ */
