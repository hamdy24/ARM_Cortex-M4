/*
 * SysTick_Config.c
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 25, 2023
 *	Brief		: This file contains the configurations object for the SysTick
 */


/************************************ Includes Start *************************************************/
#include "SysTick_Config.h"
/************************************ Includes END  *************************************************/


STK_Cfg_t STK_strConfigs = {
	.EnableState = STK_Enabled,
	.Initial_Load = 1000000,
	.STK_Prescaler = STK_Pres_1,
	.INT_State = true,
};
