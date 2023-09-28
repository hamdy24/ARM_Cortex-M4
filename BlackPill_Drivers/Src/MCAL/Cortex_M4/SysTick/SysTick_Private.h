/*
 * SysTick_Private.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 25, 2023
 *	Brief		: This file contains all the
 */

#ifndef MCAL_CORTEX_M4_SYSTICK_SYSTICK_PRIVATE_H_
#define MCAL_CORTEX_M4_SYSTICK_SYSTICK_PRIVATE_H_
/************************************ Includes Start *************************************************/
/************************************ Includes END  *************************************************/
#include <MCAL/Cortex_M4/SysTick/SysTick_Config.h>
#include "Common/CommonMacros.h"
#include "Common/ErrorState.h"
#include "Common/STD_Types.h"

#include "MCAL/Cortex_M4/CortexM4_REG.h"


/************************************ Macros Start *************************************************/

#define STK_CTRL_COUNT_FLAG_POS			16
#define STK_CTRL_CLK_SOURCE_POS			2
#define STK_CTRL_TICK_INT_POS			1
#define STK_CTRL_ENABLE_POS				0

#define STK_LOAD_POS					0

#define STK_VAL_POS						0

#define MAX_LOAD						0x00FFFFFF
#define MIN_LOAD						0x00000001


#define SysTick_SingleInterval			0
#define SysTick_PeriodicInterval		1

#define TICKS_1SECOND					1000000


/************************************ Macros END  *************************************************/
/************************************ Module Private Declaration Start *************************************************/

CallBackFunc_t SysTick_CallBack = NULL;

uint8_t SysTick_Mode = SysTick_SingleInterval;

uint32_t STK_AHB_Clk = 0;
uint8_t  STK_AHB_Pres= 0;
/************************************ Module Private Declaration  END  *************************************************/

/************************************ DataTypes Declaration Start *************************************************/
/************************************ DataTypes Declaration  END  *************************************************/

/************************************ HelperEnums Declaration Start *************************************************/
/************************************ HelperEnums Declaration  END  *************************************************/


/************************************ Private Software Interfaces Start *************************************************/
/************************************ Private Software Interfaces END  *************************************************/



#endif /* MCAL_CORTEX_M4_SYSTICK_SYSTICK_PRIVATE_H_ */
