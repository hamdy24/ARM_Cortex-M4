/*
 * SCB_private.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Aug 4, 2023
 *	Brief		: This file contains all private declarations and macros for the SCB
 */

#ifndef MCAL_SYSTEM_CONTROL_BLOCK_DRIVER_SCB_PRIVATE_H_
#define MCAL_SYSTEM_CONTROL_BLOCK_DRIVER_SCB_PRIVATE_H_
/**************************** Includes *********************************/
#include <MCAL/Cortex_M4/SCB/SCB_config.h>
#include "../../../MCAL/Cortex_M4/CortexM4_REG.h"
#include "../../../Common/ErrorState.h"


/***************************** MACROS ************************************/

#define VECTKEY					0x5FA
#define VECTKEYSTAT				0xFA05
#define VECTKEY_FIELD_SHIFT		16		/* shift 16 to access VECTKEY bits*/
#define PRIGROUP_SHIFT			8		/* shift 8 to access priority grouping bits */


#define VECTKEY_FIELD_MASK		(0xFFFF << VECTKEY_FIELD_SHIFT)
#define PRIGROUP_FIELD_MASK		(0x00000007 << PRIGROUP_SHIFT)


#define PRIGROUP_TOP			SCB_Priority_0Group_16Sub
#define PRIGROUP_BOTTOM			SCB_Priority_16Group_0Sub


#endif /* MCAL_SYSTEM_CONTROL_BLOCK_DRIVER_SCB_PRIVATE_H_ */
