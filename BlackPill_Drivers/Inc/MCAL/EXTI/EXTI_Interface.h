/*
 * EXTI_Interface.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 28, 2023
 *	Brief		: This file contains all the
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_
/************************************ Includes Start *************************************************/
#include "EXTI_Config.h"
/************************************ Includes END  *************************************************/

/************************************ Initialization Helper Start *************************************************/

extern EXTI_Cfg_t EXTI_Configs[EXTI_NUM];

/************************************ Initialization Helper END  *************************************************/


/************************************ Software Interfaces Start *************************************************/

ES_t EXTI_enuInit(EXTI_Cfg_t * Copy_pstrArrConfigs);
ES_t EXTI_enuDeInit(void);
ES_t EXTI_enuSetSenseLevel(EXTI_Line_t Copy_enuInterruptLine , EXTI_SenseLevel_t Copy_u8SenseLevel);
ES_t EXTI_enuSetInterruptEnable(EXTI_Line_t Copy_enuInterruptLine,EXTI_LineState_t Copy_enuLineState);
ES_t EXTI_enuSetEventEnable(EXTI_Line_t Copy_enuInterruptLine,EXTI_LineState_t Copy_enuLineState);
ES_t EXTI_enuTriggerInterrupt_SW(EXTI_Line_t Copy_enuInterruptLine);
ES_t EXTI_enuSetCallBack(CallBackFunc_t Copy_pfunAppCallBack);

/************************************ Software Interfaces END  *************************************************/



#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
