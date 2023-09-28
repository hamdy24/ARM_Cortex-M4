/*
 * SCB_private.h
 *
 *  Created on: Aug 4, 2023
 *      Author: Hamdy Aouf
 */

#ifndef MCAL_SYSTEM_CONTROL_BLOCK_DRIVER_SCB_PRIVATE_H_
#define MCAL_SYSTEM_CONTROL_BLOCK_DRIVER_SCB_PRIVATE_H_
/**************************** Includes *********************************/
#include <MCAL/Cortex_M4/SCB/SCB_config.h>
#include "MCAL/Cortex_M4/CortexM4_REG.h"
#include "Common/ErrorState.h"


/***************************** MACROS ************************************/

#define VECTKEY					0x5FA
#define VECTKEYSTAT				0xFA05
#define VECTKEY_FIELD_SHIFT		16		/* shift 16 to access VECTKEY bits*/
#define PRIGROUP_SHIFT			8		/* shift 8 to access priority grouping bits */


#define VECTKEY_FIELD_MASK		(0xFFFF << VECTKEY_FIELD_SHIFT)
#define PRIGROUP_FIELD_MASK		(0x00000007 << PRIGROUP_SHIFT)



//#define PRIGROUP_16_0 			0x00000003U
//#define PRIGROUP_8_2			0x00000004U
//#define PRIGROUP_4_4			0x00000005U
//#define PRIGROUP_2_8			0x00000006U
//#define PRIGROUP_0_16			0x00000007U

#define PRIGROUP_TOP			0x00000007U
#define PRIGROUP_BOTTOM			0x00000003U


#endif /* MCAL_SYSTEM_CONTROL_BLOCK_DRIVER_SCB_PRIVATE_H_ */
