/*
 * SYSCFG_Interface.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 28, 2023
 *	Brief		: This file contains all the interfaces for controlling the SYSCFG
 */

#ifndef MCAL_SYSCFG_SYSCFG_INTERFACE_H_
#define MCAL_SYSCFG_SYSCFG_INTERFACE_H_
/************************************ Includes Start *************************************************/
#include "SYSCFG_Config.h"

/************************************ Includes END  *************************************************/

/************************************ Initialization Helper Start *************************************************/
/************************************ Initialization Helper END  *************************************************/


/************************************ Software Interfaces Start *************************************************/

ES_t SYSCFG_enuEXTI_PortSelect(SysConfigEXTI_t Copy_enuEXTI_Line,SysConfigEXTI_Ports_t Copy_enuEXTI_Port);

/************************************ Software Interfaces END  *************************************************/



#endif /* MCAL_SYSCFG_SYSCFG_INTERFACE_H_ */
