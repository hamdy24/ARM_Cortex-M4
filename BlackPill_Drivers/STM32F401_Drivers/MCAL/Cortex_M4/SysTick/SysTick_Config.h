/*
 * SysTick_Config.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 25, 2023
 *	Brief		: This file contains all the configurations helpers for the SysTick
 */


#ifndef MCAL_CORTEX_M4_SYSTICK_SYSTICK_CONFIG_H_
#define MCAL_CORTEX_M4_SYSTICK_SYSTICK_CONFIG_H_
/************************************ Includes Start *************************************************/
/************************************ Includes END  *************************************************/
#include "../../../Common/CommonMacros.h"
#include "../../../Common/ErrorState.h"
#include "../../../Common/STD_Types.h"

/************************************ Macros Start *************************************************/
/************************************ Macros END  *************************************************/


/************************************ HelperEnums Declaration Start *************************************************/

typedef enum{
	STK_Pres_8,
	STK_Pres_1,
}STK_Pres_enuType;

typedef enum{
	STK_Disabled,
	STK_Enabled,
}STK_State_enuType;


/************************************ HelperEnums Declaration  END  *************************************************/
/************************************ DataTypes Declaration Start *************************************************/

typedef struct{
	STK_State_enuType EnableState:1;
	STK_Pres_enuType STK_Prescaler:1;
	uint32_t STK_AHB_ClockValue;
	uint8_t STK_AHB_Prescaler;
	uint32_t Initial_Load;
	bool INT_State:1;
}STK_Cfg_t;



/************************************ DataTypes Declaration  END  *************************************************/



#endif /* MCAL_CORTEX_M4_SYSTICK_SYSTICK_CONFIG_H_ */
