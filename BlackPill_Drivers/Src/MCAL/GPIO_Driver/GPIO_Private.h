/*
 * GPIO_Private.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 26, 2023
 *	Brief		: This file contains all the
 */

#ifndef MCAL_GPIO_DRIVER_GPIO_PRIVATE_H_
#define MCAL_GPIO_DRIVER_GPIO_PRIVATE_H_
/************************************ Includes Start *************************************************/

#include "Common/CommonMacros.h"
#include "Common/STD_Types.h"
#include "Common/ErrorState.h"

#include "MCAL/STM32F401_REG.h"
#include "MCAL/GPIO_Driver/GPIO_Config.h"

/************************************ Includes END  *************************************************/

/************************************ Macros Start *************************************************/

#define BITS_OFFSET				2

/************************************ Macros END  *************************************************/

/************************************ HelperEnums Declaration Start *************************************************/

//typedef enum{
//	GPIO_NoAction,
//	GPIO_Set,
//	GPIO_Reset,
//}GPIO_SetReset_enuType;

typedef enum{
	GPIO_LockNotActive,
	GPIO_LockActive,
}GPIO_PortLock_enuType;
/************************************ HelperEnums Declaration  END  *************************************************/

/************************************ DataTypes Declaration Start *************************************************/
/************************************ DataTypes Declaration  END  *************************************************/

/************************************ Initialization Helper Start *************************************************/
/************************************ Initialization Helper END  *************************************************/


/************************************ Software Interfaces Start *************************************************/
/************************************ Software Interfaces END  *************************************************/



#endif /* MCAL_GPIO_DRIVER_GPIO_PRIVATE_H_ */
