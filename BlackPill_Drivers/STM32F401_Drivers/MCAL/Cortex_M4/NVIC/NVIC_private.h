/*
 * NVIC_private.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: August 3, 2023
 *	Brief		: This file contains all private declarations and macros for the NVIC
 */

#ifndef MCAL_NVIC_DRIVER_NVIC_PRIVATE_H_
#define MCAL_NVIC_DRIVER_NVIC_PRIVATE_H_

/************************* Includes ********************************/
#include <MCAL/Cortex_M4/NVIC/NVIC_config.h>
#include "Common/CommonMacros.h"
#include "Common/ErrorState.h"
#include "Common/STD_Types.h"


#include "MCAL/Cortex_M4/CortexM4_REG.h"



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
