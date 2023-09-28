/*
 * SysTick_Interface.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 25, 2023
 *	Brief		: This file contains all the
 */

#ifndef MCAL_CORTEX_M4_SYSTICK_SYSTICK_INTERFACE_H_
#define MCAL_CORTEX_M4_SYSTICK_SYSTICK_INTERFACE_H_
/************************************ Includes Start *************************************************/
#include <MCAL/Cortex_M4/SysTick/SysTick_Config.h>
/************************************ Includes END  *************************************************/

/************************************ Initialization Helper Start *************************************************/

STK_Cfg_t STK_strConfigs = {
	.State = STK_Enabled,
	.Initial_Load = 1000000,
	.STK_Prescaler = STK_Pres_1,
	.INT_State = true,
};


/************************************ Initialization Helper END  *************************************************/
/************************************ Software Interfaces Start *************************************************/

ES_t STK_enuInit(STK_Cfg_t * Copy_pstrSTK_Configs);
ES_t STK_enuDeInit(void);
ES_t STK_enuDelay_Blocking(uint32_t Copy_u32Interval_Ticks);
ES_t STK_enuSingleInterval(uint32_t Copy_u32Interval_Ticks, CallBackFunc_t Copy_pfunAppCallBack);
ES_t STK_enuPeriodicInterval(uint32_t Copy_u32Interval_Ticks, CallBackFunc_t Copy_pfunAppCallBack);
ES_t STK_enuGetRemainingTicks(uint32_t * Copy_pu32ReturnedTicks);

/************************************ Software Interfaces END  *************************************************/



#endif /* MCAL_CORTEX_M4_SYSTICK_SYSTICK_INTERFACE_H_ */
