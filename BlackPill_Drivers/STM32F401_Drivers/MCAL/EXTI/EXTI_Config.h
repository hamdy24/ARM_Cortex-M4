/*
 * EXTI_Config.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 28, 2023
 *	Brief		: This file contains all the configurations helpers for the EXTI
 */


#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_
/************************************ Includes Start *************************************************/
#include "../../Common/STD_Types.h"

/************************************ Includes END  *************************************************/

/************************************ Macros Start *************************************************/

#define EXTI_NUM				3

/************************************ Macros END  *************************************************/

/************************************ HelperEnums Declaration Start *************************************************/

typedef enum{
	EXTI_None,
	EXTI_Rising,
	EXTI_Falling,
	EXTI_AnyChange,
}EXTI_SenseLevel_t;

typedef enum{
	EXTI_Line0,
	EXTI_Line1,
	EXTI_Line2,
	EXTI_Line3,
	EXTI_Line4,
	EXTI_Line5,
	EXTI_Line6,
	EXTI_Line7,
	EXTI_Line8,
	EXTI_Line9,
	EXTI_Line10,
	EXTI_Line11,
	EXTI_Line12,
	EXTI_Line13,
	EXTI_Line14,
	EXTI_Line15,
	EXTI_Line16,
	EXTI_Line17,
	EXTI_Line18,
	EXTIReserved19,
	EXTIReserved20,
	EXTI_Line21,
	EXTI_Line22,
}EXTI_Line_t;

typedef enum{
	EXTI_LineDisable,
	EXTI_LineEnable,
}EXTI_LineState_t;

/************************************ HelperEnums Declaration  END  *************************************************/

/************************************ DataTypes Declaration Start *************************************************/

typedef struct{
	EXTI_Line_t SelectedLine;
	EXTI_LineState_t LineState;
	EXTI_SenseLevel_t SenseLevel;
}EXTI_Cfg_t;
/************************************ DataTypes Declaration  END  *************************************************/


/************************************ Software Interfaces Start *************************************************/
/************************************ Software Interfaces END  *************************************************/



#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
