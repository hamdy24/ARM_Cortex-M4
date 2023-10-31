/*
 * SYSCFG_Config.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 28, 2023
 *	Brief		: This file contains all the configurations helpers for the SYSCFG
 */

#ifndef MCAL_SYSCFG_SYSCFG_CONFIG_H_
#define MCAL_SYSCFG_SYSCFG_CONFIG_H_
/************************************ Includes Start *************************************************/

#include "../../Common/CommonMacros.h"
#include "../../Common/ErrorState.h"
#include "../../Common/STD_Types.h"

/************************************ Includes END  *************************************************/

/************************************ Macros Start *************************************************/
/************************************ Macros END  *************************************************/

/************************************ HelperEnums Declaration Start *************************************************/

typedef enum{
	SysConfigPort_A,
	SysConfigPort_B,
	SysConfigPort_C,
}SysConfigEXTI_Ports_t;


typedef enum{
	SysConfigEXTI_0,
	SysConfigEXTI_1,
	SysConfigEXTI_2,
	SysConfigEXTI_3,
	SysConfigEXTI_4,
	SysConfigEXTI_5,
	SysConfigEXTI_6,
	SysConfigEXTI_7,
	SysConfigEXTI_8,
	SysConfigEXTI_9,
	SysConfigEXTI_10,
	SysConfigEXTI_11,
	SysConfigEXTI_12,
	SysConfigEXTI_13,
	SysConfigEXTI_14,
	SysConfigEXTI_15,
	SysConfigEXTI_16,
	SysConfigEXTI_17,
	SysConfigEXTI_18,
	SysConfigEXTIReserved19,
	SysConfigEXTIReserved20,
	SysConfigEXTI_21,
	SysConfigEXTI_22,
}SysConfigEXTI_t;


/************************************ HelperEnums Declaration  END  *************************************************/

/************************************ DataTypes Declaration Start *************************************************/
/************************************ DataTypes Declaration  END  *************************************************/

/************************************ Initialization Helper Start *************************************************/
/************************************ Initialization Helper END  *************************************************/


/************************************ Software Interfaces Start *************************************************/
/************************************ Software Interfaces END  *************************************************/



#endif /* MCAL_SYSCFG_SYSCFG_CONFIG_H_ */
