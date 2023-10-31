/*
 * NVIC_program.c
 *
 *  Author		: Hamdy Aouf
 *  Created on	: August 3, 2023
 *	Brief		: This file contains all interfaces implementation for NVIC
 */

#include "NVIC_private.h"

/*
 *
  	Interrupt enable bits.
	Write:
	0 = no effect
	1 = enable interrupt.
	Read:
	0 = interrupt disabled
	1 = interrupt enabled.
 */
ES_t NVIC_enuEnableIRQ(IRQn_t IRQn){
	ES_t Local_ErrorState = ES_NOK;
	if(IRQn >= 0){/** To Ensure it is an External Interrupt **/

		uint8_t Local_u8RegOffset = ( (uint32_t)IRQn) >> SHIFT_FIVE;
		uint8_t Local_u8BitsOffset = (((uint32_t)IRQn) & GET_BIT_HELPER);

		// here writing zero have no effect so it's okay to set the bit in the following way
		NVIC->ISER[Local_u8RegOffset] = (MASK_BIT <<Local_u8BitsOffset);
		Local_ErrorState = ES_OK;
	}
	else{
		Local_ErrorState = ES_INVALID_INPUTS;
	}

	return Local_ErrorState;
}

ES_t NVIC_enuDisableIRQ(IRQn_t IRQn){
	ES_t Local_ErrorState = ES_NOK;

	if(IRQn >= 0){ /** To Ensure it is an External Interrupt **/

		uint8_t Local_u8RegOffset = ( (uint32_t)IRQn) >> SHIFT_FIVE;
		uint8_t Local_u8BitsOffset = (((uint32_t)IRQn) & GET_BIT_HELPER);

		NVIC->ICER[Local_u8RegOffset] = (MASK_BIT << Local_u8BitsOffset);
		Local_ErrorState = ES_OK;
	}
	else{
		Local_ErrorState = ES_INVALID_INPUTS;
	}

	return Local_ErrorState;
}

ES_t NVIC_enuSetPindingIRQ(IRQn_t IRQn){
	ES_t Local_ErrorState = ES_NOK;


	if(IRQn >= 0){

		uint8_t Local_u8RegOffset = ( (uint32_t)IRQn) >> SHIFT_FIVE;
		uint8_t Local_u8BitsOffset = (((uint32_t)IRQn) & GET_BIT_HELPER);

		NVIC->ISPR[Local_u8RegOffset] = (MASK_BIT <<Local_u8BitsOffset);
		Local_ErrorState = ES_OK;
	}
	else{
		Local_ErrorState = ES_INVALID_INPUTS;
	}

	return Local_ErrorState;
}

ES_t NVIC_enuClearPindingIRQ(IRQn_t IRQn){
	ES_t Local_ErrorState = ES_NOK;

	if(IRQn >= 0){
		uint8_t Local_u8RegOffset = ( (uint32_t)IRQn) >> SHIFT_FIVE;
		uint8_t Local_u8BitsOffset = (((uint32_t)IRQn) & GET_BIT_HELPER);

		NVIC->ICPR[Local_u8RegOffset] = (MASK_BIT << Local_u8BitsOffset);
		Local_ErrorState = ES_OK;
	}
	else{
		Local_ErrorState = ES_INVALID_INPUTS;
	}

	return Local_ErrorState;
}

ES_t NVIC_enuGetActiveIRQ(IRQn_t IRQn,uint8_t *Copy_u8ReturnedActiveState){
	ES_t Local_ErrorState = ES_NOK;

	if(IRQn >= 0){
		uint8_t Local_u8BitValue;
		uint8_t Local_u8RegOffset = ( (uint32_t)IRQn) >> SHIFT_FIVE;
		uint8_t Local_u8BitsOffset = (((uint32_t)IRQn) & GET_BIT_HELPER);

		Local_u8BitValue = ( NVIC->IABR[Local_u8RegOffset] & (MASK_BIT << Local_u8BitsOffset ));
		if(Local_u8BitValue){
			*Copy_u8ReturnedActiveState = 1;
		}
		else{
			*Copy_u8ReturnedActiveState = 0;
		}
		Local_ErrorState = ES_OK;
	}
	else{
		Local_ErrorState = ES_INVALID_INPUTS;
	}

	return Local_ErrorState;
}



ES_t NVIC_enuSetIRQnPriority(IRQn_t Copy_IRQn , uint8_t Copy_u8Priority){

	ES_t Local_ErrorState = ES_NOK;
	if(Copy_IRQn >= 0 ){

		NVIC->IP[(uint32_t)Copy_IRQn] = (uint8_t)( (Copy_u8Priority << (8 - NVIC_PRIORITY_BITS)) & (uint32_t)0xFF);

		Local_ErrorState = ES_OK;
	}
	else{
		Local_ErrorState = ES_INVALID_INPUTS;
	}


	return Local_ErrorState;
}

ES_t NVIC_enuGetIRQnPriority(IRQn_t Copy_IRQn , uint8_t *Copy_Pu8Priority){

	ES_t Local_ErrorState = ES_NOK;
	if(Copy_IRQn >= 0 && Copy_Pu8Priority != NULL){
		*Copy_Pu8Priority = (NVIC->IP[(uint32_t)Copy_IRQn])>> (8 - NVIC_PRIORITY_BITS);

		Local_ErrorState = ES_OK;
	}
	else if (Copy_Pu8Priority == NULL) {
		Local_ErrorState = ES_POINTER_TO_VOID;
	}
	else{
		Local_ErrorState = ES_INVALID_INPUTS;
	}


	return Local_ErrorState;
}
