/*
 * EXTI_Program.c
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 28, 2023
 *	Brief		: This file contains all the
 */


/************************************ Includes Start *************************************************/
#include "EXTI_Private.h"
/************************************ Includes END  *************************************************/


/************************************************************************************/
/*	Description:	This Function sets Initializes configured EXTI Module			*/
/*	Parameters:							                       						*/
/*		@param1:	Address of the Configuration object			       				*/
/*	Return:			Returns Error State 	                       					*/
/*	Notes:			You still must handle the NVIC and Pin and Line Configurations  */
/************************************************************************************/

ES_t EXTI_enuInit(EXTI_Cfg_t * Copy_pstrArrConfigs){	// events not enabled
	ES_t Local_enuErrorState = ES_NOK;
	/** Loop on all configured EXTIs	**/
	uint8_t Local_u8Iterator = 0;
	for(Local_u8Iterator = 0 ; Local_u8Iterator < EXTI_LinesNum ; Local_u8Iterator++){
		/** Check if current EXTI Line should be enabled **/
		if(EXTI_LineEnable == Copy_pstrArrConfigs[Local_u8Iterator].LineState){

			/**  Set this EXTI initial Sense Level **/
			switch(Copy_pstrArrConfigs[Local_u8Iterator].SenseLevel){
			case EXTI_None:
				CLR_BIT(EXTI->RTSR,Copy_pstrArrConfigs[Local_u8Iterator].SelectedLine);
				CLR_BIT(EXTI->FTSR,Copy_pstrArrConfigs[Local_u8Iterator].SelectedLine);
				break;
			case EXTI_Rising:
				SET_BIT(EXTI->RTSR,Copy_pstrArrConfigs[Local_u8Iterator].SelectedLine);
				break;
			case EXTI_Falling:
				SET_BIT(EXTI->FTSR,Copy_pstrArrConfigs[Local_u8Iterator].SelectedLine);
				break;
			case EXTI_AnyChange:
				SET_BIT(EXTI->RTSR,Copy_pstrArrConfigs[Local_u8Iterator].SelectedLine);
				SET_BIT(EXTI->FTSR,Copy_pstrArrConfigs[Local_u8Iterator].SelectedLine);
				break;
			default:
				Local_enuErrorState = ES_INVALID_INPUTS;
				break;
			}

			/**  Enable This EXTI Interrupt **/
			SET_BIT(EXTI->IMR,Copy_pstrArrConfigs[Local_u8Iterator].SelectedLine);

		}else {
			/**  Disable This EXTI Interrupt **/
			CLR_BIT(EXTI->IMR,Copy_pstrArrConfigs[Local_u8Iterator].SelectedLine);

		}

	}
	if(ES_INVALID_INPUTS != Local_enuErrorState){
		Local_enuErrorState = ES_OK;
	}
	else{
		/* Nothing */
	}
	return Local_enuErrorState;
}

/************************************************************************************/
/*	Description:	This Function Resets the EXTI Module							*/
/*	Parameters:		None					       									*/
/*	Return:			Returns Error State 	                       					*/
/*	Notes:			You still must handle the NVIC and Pin and Line Configurations  */
/************************************************************************************/
ES_t EXTI_enuDeInit(void){
	ES_t Local_enuErrorState = ES_OK;
	/**  Disable This EXTI Interrupt **/
	EXTI->IMR = 0;
	/**  Disable This EXTI Events **/
	EXTI->EMR = 0;
	/**  Disable This EXTI Sense Level **/
	EXTI->RTSR= 0;
	EXTI->FTSR= 0;

	return Local_enuErrorState;
}


/************************************************************************************/
/*	Description:	This Function sets Interrupt Sense Level						*/
/*	Parameters:							                       						*/
/*		@param1:	Desired Line 						               				*/
/*		&param2:	Desired Sense Level			       								*/
/*	Return:			Returns Error State 	                       					*/
/*	Notes:			You still must handle the NVIC and Pin and Line Configurations  */
/************************************************************************************/
ES_t EXTI_enuSetSenseLevel(EXTI_Line_t Copy_enuInterruptLine , EXTI_SenseLevel_t Copy_u8SenseLevel){
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_enuInterruptLine<=EXTI_Line22)
		&& (Copy_enuInterruptLine!= EXTIReserved19)
		&& (Copy_enuInterruptLine!= EXTIReserved20)){

		switch(Copy_u8SenseLevel){
		case EXTI_None:
			CLR_BIT(EXTI->RTSR,Copy_enuInterruptLine);
			CLR_BIT(EXTI->FTSR,Copy_enuInterruptLine);
			break;
		case EXTI_Rising:
			SET_BIT(EXTI->RTSR,Copy_enuInterruptLine);
			break;
		case EXTI_Falling:
			SET_BIT(EXTI->FTSR,Copy_enuInterruptLine);
			break;
		case EXTI_AnyChange:
			SET_BIT(EXTI->RTSR,Copy_enuInterruptLine);
			SET_BIT(EXTI->FTSR,Copy_enuInterruptLine);
			break;
		default:
			Local_enuErrorState = ES_INVALID_INPUTS;
			break;
		}
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


/************************************************************************************/
/*	Description:	This Function sets Interrupt Enable State 						*/
/*	Parameters:							                       						*/
/*		@param1:	Desired Line 						               				*/
/*		&param2:	Desired State			       									*/
/*	Return:			Returns Error State 	                       					*/
/*	Notes:			You still must handle the NVIC and Pin and Line Configurations  */
/************************************************************************************/
ES_t EXTI_enuSetInterruptEnable(EXTI_Line_t Copy_enuInterruptLine,EXTI_LineState_t Copy_enuLineState){
	ES_t Local_enuErrorState = ES_NOK;

	if((Copy_enuInterruptLine<=EXTI_Line22)
			&& (Copy_enuInterruptLine!= EXTIReserved19)
			&& (Copy_enuInterruptLine!= EXTIReserved20)){

		if(EXTI_LineEnable == Copy_enuLineState){
			/**  Enable This EXTI Interrupt **/
			CLR_BIT(EXTI->IMR,Copy_enuInterruptLine);
		}else {
			/**  Disable This EXTI Interrupt **/
			CLR_BIT(EXTI->IMR,Copy_enuInterruptLine);

		}
		Local_enuErrorState = ES_OK;
	}else {
		Local_enuErrorState = ES_INVALID_INPUTS;
	}

	return Local_enuErrorState;
}


/************************************************************************************/
/*	Description:	This Function sets Event Enable State							*/
/*	Parameters:							                       						*/
/*		@param1:	Desired Line 						               				*/
/*		&param2:	Desired State			       									*/
/*	Return:			Returns Error State 	                       					*/
/*	Notes:			You still must handle the NVIC and Pin and Line Configurations  */
/************************************************************************************/
ES_t EXTI_enuSetEventEnable(EXTI_Line_t Copy_enuEventLine,EXTI_LineState_t Copy_enuLineState){
	ES_t Local_enuErrorState = ES_NOK;


	if((Copy_enuEventLine<=EXTI_Line22)
			&& (Copy_enuEventLine!= EXTIReserved19)
			&& (Copy_enuEventLine!= EXTIReserved20)){
		if(EXTI_LineEnable == Copy_enuLineState){
			/**  Enable This EXTI Event **/
			CLR_BIT(EXTI->EMR,Copy_enuEventLine);
		}else {
			/**  Disable This EXTI Event **/
			CLR_BIT(EXTI->EMR,Copy_enuEventLine);

		}

		Local_enuErrorState = ES_OK;
	}else {
		Local_enuErrorState = ES_INVALID_INPUTS;
	}

	return Local_enuErrorState;
}


/************************************************************************************/
/*	Description:	This Function Generate SW signal sets pending indicate interrupt*/
/*	Parameters:							                       						*/
/*		@param1:	Desired Line 						               				*/
/*	Return:			Returns Error State 	                       					*/
/*	Notes:			You still must handle the NVIC and Pin and Line Configurations  */
/************************************************************************************/
ES_t EXTI_enuTriggerInterrupt_SW(EXTI_Line_t Copy_enuInterruptLine){
	ES_t Local_enuErrorState = ES_NOK;


	if((Copy_enuInterruptLine<=EXTI_Line22)
			&& (Copy_enuInterruptLine!= EXTIReserved19)
			&& (Copy_enuInterruptLine!= EXTIReserved20)){
		SET_BIT(EXTI->SWIER ,Copy_enuInterruptLine);
//		EXTI->SWIER = (MASK_1BIT<<Copy_enuInterruptLine);

		Local_enuErrorState = ES_OK;
	}else {
		Local_enuErrorState = ES_INVALID_INPUTS;
	}

	return Local_enuErrorState;
}


/************************************************************************************/
/*	Description:	This Function sets APP callback to our module related callback	*/
/*	Parameters:							                       						*/
/*		@param1:	Desired Line 						               				*/
/*		&param2:	Desired State			       									*/
/*	Return:			Returns Error State 	                       					*/
/*	Notes:			You still must handle the NVIC and Pin and Line Configurations  */
/************************************************************************************/
ES_t EXTI_enuSetCallBack(CallBackFunc_t Copy_pfunAppCallBack){
	ES_t Local_enuErrorState = ES_NOK;

	if(NULL != Copy_pfunAppCallBack){
		EXTI_CallBack = Copy_pfunAppCallBack;
		Local_enuErrorState = ES_OK;
	}else{
		Local_enuErrorState = ES_POINTER_TO_VOID;
	}

	return Local_enuErrorState;
}


void EXTI_Handler(void){
	if(NULL != EXTI_CallBack){
		EXTI_CallBack();
	}
}


