/*
 * SCB_config.h
 *
 *  Created on: Aug 4, 2023
 *      Author: Hamdy Auof
 */

#ifndef MCAL_SYSTEM_CONTROL_BLOCK_DRIVER_SCB_CONFIG_H_
#define MCAL_SYSTEM_CONTROL_BLOCK_DRIVER_SCB_CONFIG_H_

#include "Common/ErrorState.h"
#include "Common/CommonMacros.h"
#include "Common/STD_Types.h"



typedef enum{

	SCB_PRIGROUP_16_0 	=0x00000003U,
	SCB_PRIGROUP_8_2	=0x00000004U,
	SCB_PRIGROUP_4_4	=0x00000005U,
	SCB_PRIGROUP_2_8	=0x00000006U,
	SCB_PRIGROUP_0_16	=0x00000007U,

}SCB_PRIGROUP_enuType;

#endif /* MCAL_SYSTEM_CONTROL_BLOCK_DRIVER_SCB_CONFIG_H_ */
