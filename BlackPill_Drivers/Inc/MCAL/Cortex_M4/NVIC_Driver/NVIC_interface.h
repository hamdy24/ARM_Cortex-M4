/*
 * NVIC_interface.h
 *
 *  Created on: Aug 3, 2023
 *      Author: Hamdy Aouf
 */

#ifndef MCAL_NVIC_DRIVER_NVIC_INTERFACE_H_
#define MCAL_NVIC_DRIVER_NVIC_INTERFACE_H_



#include "MCAL/Cortex_M4/NVIC_Driver/NVIC_config.h"
/********************************************************************************************/
/*************************		Interfaces		*************************************************/
/********************************************************************************************/


ES_t NVIC_enuEnableIRQ(IRQn_t Copy_IRQn);

ES_t NVIC_enuDisableIRQ(IRQn_t Copy_IRQn);

ES_t NVIC_enuSetPindingIRQ(IRQn_t Copy_IRQn);

ES_t NVIC_enuClearPindingIRQ(IRQn_t Copy_IRQn);

ES_t NVIC_enuGetActiveIRQ(IRQn_t IRQn);

ES_t NVIC_enuSetIRQnPriority(IRQn_t Copy_IRQn , uint8_t Copy_u8Priority);

ES_t NVIC_enuGetIRQnPriority(IRQn_t Copy_IRQn , uint8_t *Copy_Pu8Priority);


#endif /* MCAL_NVIC_DRIVER_NVIC_INTERFACE_H_ */
