/*
 * SCB_program.c
 *
 *  Author		: Hamdy Aouf
 *  Created on	: August 4, 2023
 *	Brief		: This file contains all interfaces implementation for SCB
 */


#include "SCB_private.h"

ES_t SCB_SetPriorityGrouping(SCB_PRIGROUP_enuType Copy_u8PriorityGroupNum){
	ES_t Local_ErrorState =ES_NOK;

	if(Copy_u8PriorityGroupNum < PRIGROUP_BOTTOM || Copy_u8PriorityGroupNum > PRIGROUP_TOP){
		// if larger we AND the value with 0x00000007 -> 7 -> 111 to get just lower three bits
			Copy_u8PriorityGroupNum &= 0x00000007;
	}
	/********************************************************************************/
	/* Now We MASK our specific bits to zero */
	/* to ensure following logic operations are right */
	/* this makes generic set mechanism */
	/* but also we do changes on a copy from the value */
	/* as the register won't be written without the VECTKEY*/
	/*********************************************************************************/
	uint32_t Local_u32AIRCR_Value = SCB->AIRCR;
	Local_u32AIRCR_Value &= ~(PRIGROUP_FIELD_MASK | VECTKEY_FIELD_MASK);
	/*******************************************************************************
     * Now we perform the operation..
	 * first we write VECTKEY to enable writing to register
	 * Then we write the required PRIGROUP settings
	 *
	 *******************************************************************************/
	 SCB->AIRCR = (Local_u32AIRCR_Value |(VECTKEY << VECTKEY_FIELD_SHIFT) | (Copy_u8PriorityGroupNum << PRIGROUP_SHIFT) ) ;



	return Local_ErrorState;
}

ES_t SCB_GetPriorityGrouping(uint8_t *Copy_Pu8PriorityGroup){
	ES_t Local_ErrorState = ES_NOK;


	*Copy_Pu8PriorityGroup = ((SCB->AIRCR) & PRIGROUP_FIELD_MASK)>> PRIGROUP_SHIFT;

	return Local_ErrorState;

}
