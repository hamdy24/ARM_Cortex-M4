/*
 * SYSCFG_Program.c
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 28, 2023
 *	Brief		: This file contains basic implementations for System Configurations
 */


/************************************ Includes Start *************************************************/
#include "SYSCFG_Private.h"
/************************************ Includes END  *************************************************/


/****************************************************************************************/
/*	Description:	This Function sets EXTI Line Corresponding Alternate Function		*/
/*	Parameters:							                       							*/
/*		@param1:	EXTI Line Selected		 						               		*/
/*		&param2:	Corresponding Port For the selected EXTI				       		*/
/*	Return:			Returns Error State 	                    					   	*/
/*	Notes:			You still need the GPIO, EXTI drivers beside this configuration 	*/
/****************************************************************************************/

ES_t SYSCFG_enuEXTI_PortSelect(SysConfigEXTI_t Copy_enuEXTI_Line,SysConfigEXTI_Ports_t Copy_enuEXTI_Port){
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_enuEXTI_Line<=SysConfigEXTI_22)
		&& (Copy_enuEXTI_Line!= SysConfigEXTIReserved19)
		&& (Copy_enuEXTI_Line!= SysConfigEXTIReserved20)){

		uint8_t LocalScaledLine = (Copy_enuEXTI_Line%BIT_OFFSET_HELPER);
		uint8_t Local_u8BitOffset = LocalScaledLine*BIT_OFFSET_HELPER;
		uint8_t Local_u8RegOffset = (Copy_enuEXTI_Line>>REG_OFFSET_HELPER);

		UPDATE_BITS_OFFSET(SYSCFG->EXTICR[Local_u8RegOffset],MASK_4BIT,Copy_enuEXTI_Port,Local_u8BitOffset);

	}else{
		Local_enuErrorState = ES_INVALID_INPUTS;
	}

	if(ES_INVALID_INPUTS != Local_enuErrorState){
		Local_enuErrorState = ES_OK;
	}
	else{
		/* Nothing */
	}

	return Local_enuErrorState;

}
