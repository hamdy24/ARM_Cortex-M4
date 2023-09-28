/*
 * EXTI_Private.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 28, 2023
 *	Brief		: This file contains any private Helpers for EXTI
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_
/************************************ Includes Start *************************************************/

#include "Common/CommonMacros.h"
#include "Common/ErrorState.h"
#include "Common/STD_Types.h"

#include "MCAL/STM32F401_REG.h"

#include "MCAL/EXTI/EXTI_Config.h"

/************************************ Includes END  *************************************************/

/************************************ Macros Start *************************************************/
/************************************ Macros END  *************************************************/

/************************************ HelperEnums Declaration Start *************************************************/
/************************************ HelperEnums Declaration  END  *************************************************/

/************************************ Private Declaration Start *************************************************/

static CallBackFunc_t EXTI_CallBack = NULL;

extern uint8_t EXTI_LinesNum;

/************************************ Private Declaration  END  *************************************************/

/************************************ Initialization Helper Start *************************************************/
/************************************ Initialization Helper END  *************************************************/


/************************************ Software Interfaces Start *************************************************/
/************************************ Software Interfaces END  *************************************************/



#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
