/*
 * SCB_interface.h
 *
 *  Author		: hamdy
 *  Created on	: Aug 4, 2023
 *	Brief		: This file contains all the interfaces for controlling the SCB
 */

#ifndef MCAL_SYSTEM_CONTROL_BLOCK_DRIVER_SCB_INTERFACE_H_
#define MCAL_SYSTEM_CONTROL_BLOCK_DRIVER_SCB_INTERFACE_H_

#include "../../../MCAL/Cortex_M4/SCB/SCB_config.h"


ES_t SCB_SetPriorityGrouping(SCB_PRIGROUP_enuType Copy_u8PriorityGroupNum);
ES_t SCB_GetPriorityGrouping(uint8_t *Copy_Pu8PriorityGroup);



#endif /* MCAL_SYSTEM_CONTROL_BLOCK_DRIVER_SCB_INTERFACE_H_ */
