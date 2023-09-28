/*
 * NVIC_program.c
 *
 *  Created on: August 3, 2023
 *      Author: Hamdy Aouf
 */

#include "../NVIC/NVIC_private.h"
/*
 * Disabled
 * Enabled
 * Pending
 *\\\\\\\\\\\
 * Active
 */

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
		//////////// in video no '|' is done
		NVIC->ISER[( (uint32_t)IRQn) >> SHIFT_FIVE] = (MASK_BIT << (((uint32_t)IRQn) & GET_BIT_HELPER));
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
		NVIC->ICER[( (uint32_t)IRQn) >> SHIFT_FIVE] = (MASK_BIT << (((uint32_t)IRQn) & GET_BIT_HELPER));
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
		NVIC->ISPR[( (uint32_t)IRQn) >> SHIFT_FIVE] = (MASK_BIT << (((uint32_t)IRQn) & GET_BIT_HELPER));
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
		NVIC->ICPR[( (uint32_t)IRQn) >> SHIFT_FIVE] = (MASK_BIT << (((uint32_t)IRQn) & GET_BIT_HELPER));
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
		Local_u8BitValue = ( NVIC->IABR[( (uint32_t)IRQn) >> SHIFT_FIVE] & (MASK_BIT << (((uint32_t)IRQn) & GET_BIT_HELPER)));
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
