/*
 * GPIO_Interface.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 26, 2023
 *	Brief		: This file contains all the
 */

#ifndef MCAL_GPIO_DRIVER_GPIO_INTERFACE_H_
#define MCAL_GPIO_DRIVER_GPIO_INTERFACE_H_
/************************************ Includes Start *************************************************/

#include "GPIO_Config.h"

/************************************ Includes END  *************************************************/

/************************************ Initialization Helper Start *************************************************/

/************************************ Initialization Helper END  *************************************************/


/************************************ Software Interfaces Start *************************************************/

ES_t GPIO_enuSetPinMode(GPIO_Pins_t Copy_u8PinID ,GPIO_Mode_t Copy_enuPinMode);
ES_t GPIO_enuSetPinType(GPIO_Pins_t Copy_u8PinID ,GPIO_OutType_t Copy_enuOutputType);
ES_t GPIO_enuSetPinPull(GPIO_Pins_t Copy_u8PinID ,GPIO_PullType_t Copy_enuPullType);
ES_t GPIO_enuSetPinSpeed(GPIO_Pins_t Copy_u8PinID ,GPIO_OutSpeed_t Copy_enuSpeed);
ES_t GPIO_enuSetPinValue(GPIO_Pins_t Copy_u8PinID ,GPIO_Logic_t Copy_enuValue);
ES_t GPIO_enuGetPinValue(GPIO_Pins_t Copy_u8PinID ,uint8_t * Copy_pu8RetPinValue);

ES_t GPIO_enuSetPinAlternateFunc(GPIO_Pins_t Copy_u8PinID ,GPIO_AlterFunc_t Copy_enuAlternate);


ES_t GPIO_enuSetPortMode(GPIO_Port_t Copy_u8PortID ,GPIO_Mode_t Copy_enuPinMode);
ES_t GPIO_enuSetPortType(GPIO_Port_t Copy_u8PortID ,GPIO_OutType_t Copy_enuOutputType);
ES_t GPIO_enuSetPortPull(GPIO_Port_t Copy_u8PortID ,GPIO_PullType_t Copy_enuPullType);
ES_t GPIO_enuSetPortSpeed(GPIO_Port_t Copy_u8PortID ,GPIO_OutSpeed_t Copy_enuSpeed);
ES_t GPIO_enuSetPortValue(GPIO_Port_t Copy_u8PortID ,uint8_t Copy_u8PortValue);
ES_t GPIO_enuGetPortValue(GPIO_Port_t Copy_u8PortID ,uint8_t * Copy_pu8RetPortValue);
/************************************ Software Interfaces END  *************************************************/



#endif /* MCAL_GPIO_DRIVER_GPIO_INTERFACE_H_ */
