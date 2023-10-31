/*
 * EXTI_Config.c
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 28, 2023
 *	Brief		: This file contains all the initialization objects for the EXTI
 */

/************************************ Includes Start *************************************************/
#include "EXTI_Config.h"
#include "Common/STD_Types.h"
/************************************ Includes END  *************************************************/

/************************************ Initialization Helper Start *************************************************/

uint8_t EXTI_LinesNum = EXTI_NUM;

/*
 * You can add more configurations for this array as you need but change value of the macro EXTI_NUM
 * This is done for linking time configurations
 */
EXTI_Cfg_t EXTI_Configs[EXTI_NUM]={
{
	.SelectedLine = EXTI_Line0,
	.LineState = EXTI_LineEnable,
	.SenseLevel = EXTI_AnyChange,
},

{
	.SelectedLine = EXTI_Line1,
	.LineState = EXTI_LineEnable,
	.SenseLevel = EXTI_AnyChange,
},

{
	.SelectedLine = EXTI_Line4,
	.LineState = EXTI_LineEnable,
	.SenseLevel = EXTI_AnyChange,
},

};
/************************************ Initialization Helper End *************************************************/
