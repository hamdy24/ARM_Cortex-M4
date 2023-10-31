/*
 * SCB_config.h
 *
 *  Author: Hamdy Auof
 *  Created on: Aug 4, 2023
 *	Brief		: This file contains all the configurations helpers for the SCB
 */

#ifndef MCAL_SYSTEM_CONTROL_BLOCK_DRIVER_SCB_CONFIG_H_
#define MCAL_SYSTEM_CONTROL_BLOCK_DRIVER_SCB_CONFIG_H_

#include "../../../Common/ErrorState.h"
#include "../../../Common/CommonMacros.h"
#include "../../../Common/STD_Types.h"



typedef enum{

	SCB_Priority_16Group_0Sub 	=0x00000003U,
	SCB_Priority_8Group_2Sub	=0x00000004U,
	SCB_Priority_4Group_4Sub	=0x00000005U,
	SCB_Priority_2Group_8Sub	=0x00000006U,
	SCB_Priority_0Group_16Sub	=0x00000007U,

}SCB_PRIGROUP_enuType;

#endif /* MCAL_SYSTEM_CONTROL_BLOCK_DRIVER_SCB_CONFIG_H_ */
