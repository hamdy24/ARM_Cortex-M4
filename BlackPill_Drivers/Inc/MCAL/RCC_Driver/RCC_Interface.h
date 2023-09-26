/*
 * RCC_Interface.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 23, 2023
 *	Brief		: This file contains all the
 */

#ifndef MCAL_RCC_RCC_INTERFACE_H_
#define MCAL_RCC_RCC_INTERFACE_H_

/************************************ Includes START  *************************************************/
#include "RCC_Config.h"
/************************************ Includes END  *************************************************/

/************************************ Initialization Helper Start *************************************************/

RCC_OSC_Config_t OSC = {
		.OSC_Type = RCC_OSC_HSE,
		.HSE_State = RCC_OSC_ON,
		.HSI_State = RCC_OSC_OFF,
		.LSE_State = RCC_OSC_OFF,
		.LSI_State = RCC_OSC_OFF,
};
RCC_Clock_Config_t CLK = {
		.AHB_Pres = RCC_AHB_PRES_2,
		.APB1_Pres = RCC_APB1_PRES_4,
		.APB2_Pres = RCC_APB1_PRES_8,
};


/************************************ Initialization Helper END  *************************************************/


/************************************ Software Interfaces Start *************************************************/
ES_t RCC_enuOscilatorInit(RCC_OSC_Config_t * Copy_pstrOSC_Config);
ES_t RCC_enuClocksInit(RCC_Clock_Config_t * Copy_pstrClk_Config);

ES_t RCC_enuSetClockState(RCC_Target_t Copy_enuTarget ,bool Copy_enuIsEnabled);

#endif /* MCAL_RCC_RCC_INTERFACE_H_ */
