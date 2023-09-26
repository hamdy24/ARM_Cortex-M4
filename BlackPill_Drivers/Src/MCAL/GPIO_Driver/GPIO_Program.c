/*
 * GPIO_Program.c
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 26, 2023
 *	Brief		: This file contains all the
 */

/************************************ Includes Start *************************************************/

#include "GPIO_Private.h"

/************************************ Includes END  *************************************************/

/************************************************************************/
/*	Description:	This Function makes	sets pin mode: General,input... */
/*	Parameters:							                       			*/
/*		@param1: 	Pin Number					               			*/
/*		&param2:	Pin Mode from the helpers		       				*/
/*	Return:			Returns Error State 	                       		*/
/*	Notes:			You still have to enable the Port Clock first  		*/
/************************************************************************/

ES_t GPIO_enuSetPinMode(GPIO_Pins_t Copy_u8PinID ,GPIO_Mode_t Copy_enuPinMode){
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8PinID <= GPIO_PC15 && Copy_u8PinID >= GPIO_PA0 ){
		if(Copy_enuPinMode <= GPIO_Analog && Copy_enuPinMode >= GPIO_Input){
			if(Copy_u8PinID<= GPIO_PA15){
				UPDATE_BITS_OFFSET(GPIOA->MODER,MASK_2BIT ,Copy_enuPinMode,Copy_u8PinID*BITS_OFFSET);
			}
			else if(Copy_u8PinID<= GPIO_PB15){
				Copy_u8PinID -= GPIO_PB0;
				UPDATE_BITS_OFFSET(GPIOB->MODER,MASK_2BIT ,Copy_enuPinMode,Copy_u8PinID*BITS_OFFSET);
			}
			else{
				Copy_u8PinID -= (GPIO_PB15+1);
				UPDATE_BITS_OFFSET(GPIOC->MODER,MASK_2BIT ,Copy_enuPinMode,Copy_u8PinID*BITS_OFFSET);

			}
		}else{
			Local_enuErrorState = ES_INVALID_INPUTS;
		}
	}
	else{
		Local_enuErrorState = ES_INVALID_INPUTS;
	}

	return Local_enuErrorState;
}
/****************************************************************************/
/*	Description:	This Function Sets output Type push-pull or open-drain	*/
/*	Parameters:							                       				*/
/*		@param1:	Pin Number				    		                   	*/
/*		&param2:	Output Type						                       	*/
/*	Return:			Returns Error State 	            		           	*/
/*	Notes:			You still have to enable the Port Clock first 		 	*/
/****************************************************************************/
ES_t GPIO_enuSetPinType(GPIO_Pins_t Copy_u8PinID ,GPIO_OutType_t Copy_enuOutputType){
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8PinID <= GPIO_PC15 && Copy_u8PinID >= GPIO_PA0 ){
		if(Copy_enuOutputType <= GPIO_OUT_OpenDrain && Copy_enuOutputType >= GPIO_OUT_PushPull){


			if(Copy_u8PinID<= GPIO_PA15){
				UPDATE_BITS_OFFSET(GPIOA->OTYPER,MASK_1BIT ,Copy_enuOutputType,Copy_u8PinID);
			}
			else if(Copy_u8PinID<= GPIO_PB15){
				Copy_u8PinID -= GPIO_PB0;
				UPDATE_BITS_OFFSET(GPIOB->OTYPER,MASK_1BIT ,Copy_enuOutputType,Copy_u8PinID);
			}
			else{
				Copy_u8PinID -= (GPIO_PB15+1);
				UPDATE_BITS_OFFSET(GPIOC->OTYPER,MASK_1BIT ,Copy_enuOutputType,Copy_u8PinID);
			}

		}else{
			Local_enuErrorState = ES_INVALID_INPUTS;
		}
	}
	else{
		Local_enuErrorState = ES_INVALID_INPUTS;
	}

	return Local_enuErrorState;
}
/****************************************************************************/
/*	Description:	This Function Sets Pulling type pull-up/down...			*/
/*	Parameters:							                       				*/
/*		@param1:	Pin Number				    		                   	*/
/*		&param2:	Pull Type						                       	*/
/*	Return:			Returns Error State 	            		           	*/
/*	Notes:			You still have to enable the Port Clock first 		 	*/
/****************************************************************************/
ES_t GPIO_enuSetPinPull(GPIO_Pins_t Copy_u8PinID ,GPIO_PullType_t Copy_enuPullType){
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8PinID <= GPIO_PC15 && Copy_u8PinID >= GPIO_PA0 ){

		if(Copy_enuPullType <= GPIO_Reserved && Copy_enuPullType >= GPIO_NoPull){

			if(Copy_u8PinID <= GPIO_PA15){
				UPDATE_BITS_OFFSET(GPIOA->PUPDR,MASK_2BIT ,Copy_enuPullType,Copy_u8PinID*BITS_OFFSET);

			}
			else if(Copy_u8PinID <= GPIO_PB15){
				Copy_u8PinID -= GPIO_PB0;
				UPDATE_BITS_OFFSET(GPIOB->PUPDR,MASK_2BIT ,Copy_enuPullType,Copy_u8PinID*BITS_OFFSET);
			}
			else{
				Copy_u8PinID -= (GPIO_PB15+1);
				UPDATE_BITS_OFFSET(GPIOC->PUPDR,MASK_2BIT ,Copy_enuPullType,Copy_u8PinID*BITS_OFFSET);
			}

		}else{
			Local_enuErrorState = ES_INVALID_INPUTS;
		}
	}
	else{
		Local_enuErrorState = ES_INVALID_INPUTS;
	}

	return Local_enuErrorState;
}
/****************************************************************************/
/*	Description:	This Function Sets Pin Speed for low, high...			*/
/*	Parameters:							                       				*/
/*		@param1:	Pin Number				    		                   	*/
/*		&param2:	Pin Speed						                       	*/
/*	Return:			Returns Error State 	            		           	*/
/*	Notes:			You still have to enable the Port Clock first 		 	*/
/****************************************************************************/
ES_t GPIO_enuSetPinSpeed(GPIO_Pins_t Copy_u8PinID ,GPIO_OutSpeed_t Copy_enuSpeed){
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8PinID <= GPIO_PC15 && Copy_u8PinID >= GPIO_PA0 ){

		if(Copy_enuSpeed <= GPIO_VeryHighSpeed && Copy_enuSpeed >= GPIO_LowSpeed){

			if(Copy_u8PinID <= GPIO_PA15){
				UPDATE_BITS_OFFSET(GPIOA->OSPEEDR,MASK_2BIT ,Copy_enuSpeed,Copy_u8PinID*BITS_OFFSET);

			}
			else if(Copy_u8PinID <= GPIO_PB15){
				Copy_u8PinID -= GPIO_PB0;
				UPDATE_BITS_OFFSET(GPIOB->OSPEEDR,MASK_2BIT ,Copy_enuSpeed,Copy_u8PinID*BITS_OFFSET);
			}
			else{
				Copy_u8PinID -= (GPIO_PB15+1);
				UPDATE_BITS_OFFSET(GPIOC->OSPEEDR,MASK_2BIT ,Copy_enuSpeed,Copy_u8PinID*BITS_OFFSET);
			}

		}else{
			Local_enuErrorState = ES_INVALID_INPUTS;
		}
	}
	else{
		Local_enuErrorState = ES_INVALID_INPUTS;
	}
	return Local_enuErrorState;
}
/****************************************************************************/
/*	Description:	This Function Sets pins output Value to high or low		*/
/*	Parameters:							                       				*/
/*		@param1:	Pin Number				    		                   	*/
/*		&param2:	Output Value					                       	*/
/*	Return:			Returns Error State 	            		           	*/
/*	Notes:			You still have to enable the Port Clock first 		 	*/
/****************************************************************************/
ES_t GPIO_enuSetPinValue(GPIO_Pins_t Copy_u8PinID ,GPIO_Logic_t Copy_enuValue){
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8PinID <= GPIO_PC15 && Copy_u8PinID >= GPIO_PA0 ){

		if(Copy_enuValue == GPIO_Set || Copy_enuValue == GPIO_Reset){

			if(Copy_u8PinID <= GPIO_PA15){
				UPDATE_BITS_OFFSET(GPIOA->ODR,MASK_1BIT ,Copy_enuValue,Copy_u8PinID);

			}
			else if(Copy_u8PinID <= GPIO_PB15){
				Copy_u8PinID -= GPIO_PB0;
				UPDATE_BITS_OFFSET(GPIOB->ODR,MASK_1BIT ,Copy_enuValue,Copy_u8PinID);
			}
			else{
				Copy_u8PinID -= (GPIO_PB15+1);
				UPDATE_BITS_OFFSET(GPIOC->ODR,MASK_1BIT ,Copy_enuValue,Copy_u8PinID);
			}

		}else{
			Local_enuErrorState = ES_INVALID_INPUTS;
		}
	}
	else{
		Local_enuErrorState = ES_INVALID_INPUTS;
	}
	return Local_enuErrorState;
}
/****************************************************************************/
/*	Description:	This Function Reads Pin Value							*/
/*	Parameters:							                       				*/
/*		@param1:	Pin Number				    		                   	*/
/*		&param2:	Return Variable Address						            */
/*	Return:			Returns Error State 	            		           	*/
/*	Notes:			You still have to enable the Port Clock first 		 	*/
/****************************************************************************/
ES_t GPIO_enuGetPinValue(GPIO_Pins_t Copy_u8PinID ,uint8_t * Copy_pu8RetPinValue){
	ES_t Local_enuErrorState = ES_NOK;

	if(NULL != Copy_pu8RetPinValue){
		if(Copy_u8PinID <= GPIO_PC15 && Copy_u8PinID >= GPIO_PA0 ){

			if(Copy_u8PinID <= GPIO_PA15){
				*Copy_pu8RetPinValue =	READ_BIT(GPIOA->IDR,Copy_u8PinID);
			}
			else if(Copy_u8PinID <= GPIO_PB15){
				Copy_u8PinID -= GPIO_PB0;
				*Copy_pu8RetPinValue = READ_BIT(GPIOB->IDR,Copy_u8PinID);
			}
			else{
				Copy_u8PinID -= (GPIO_PB15+1);
				*Copy_pu8RetPinValue = READ_BIT(GPIOC->IDR,Copy_u8PinID);
			}
		}
		else{
			Local_enuErrorState = ES_INVALID_INPUTS;
		}
	}
	else{
		Local_enuErrorState = ES_POINTER_TO_VOID;
	}

	return Local_enuErrorState;
}

/****************************************************************************/
/*	Description:	This Function Sets output Type push-pull or open-drain	*/
/*	Parameters:							                       				*/
/*		@param1:	Pin Number				    		                   	*/
/*		&param2:	Output Type						                       	*/
/*	Return:			Returns Error State 	            		           	*/
/*	Notes:			You still have to enable the Port Clock first 		 	*/
/****************************************************************************/
ES_t GPIO_enuSetPinAlternateFunc(GPIO_Pins_t Copy_u8PinID ,GPIO_AlterFunc_t Copy_enuAlternate){
	ES_t Local_enuErrorState = ES_NOK;


	return Local_enuErrorState;
}

/****************************************************************************/
/*	Description:	This Function Sets output Type push-pull or open-drain	*/
/*	Parameters:							                       				*/
/*		@param1:	Pin Number				    		                   	*/
/*		&param2:	Output Type						                       	*/
/*	Return:			Returns Error State 	            		           	*/
/*	Notes:			You still have to enable the Port Clock first 		 	*/
/****************************************************************************/
ES_t GPIO_enuSetPortMode(GPIO_Port_t Copy_u8PortID ,GPIO_Mode_t Copy_enuPinMode){
	ES_t Local_enuErrorState = ES_NOK;


	return Local_enuErrorState;
}
/****************************************************************************/
/*	Description:	This Function Sets output Type push-pull or open-drain	*/
/*	Parameters:							                       				*/
/*		@param1:	Pin Number				    		                   	*/
/*		&param2:	Output Type						                       	*/
/*	Return:			Returns Error State 	            		           	*/
/*	Notes:			You still have to enable the Port Clock first 		 	*/
/****************************************************************************/
ES_t GPIO_enuSetPortType(GPIO_Port_t Copy_u8PortID ,GPIO_OutType_t Copy_enuOutputType){
	ES_t Local_enuErrorState = ES_NOK;


	return Local_enuErrorState;
}
/****************************************************************************/
/*	Description:	This Function Sets output Type push-pull or open-drain	*/
/*	Parameters:							                       				*/
/*		@param1:	Pin Number				    		                   	*/
/*		&param2:	Output Type						                       	*/
/*	Return:			Returns Error State 	            		           	*/
/*	Notes:			You still have to enable the Port Clock first 		 	*/
/****************************************************************************/
ES_t GPIO_enuSetPortPull(GPIO_Port_t Copy_u8PortID ,GPIO_PullType_t Copy_enuPullType){
	ES_t Local_enuErrorState = ES_NOK;


	return Local_enuErrorState;
}
/****************************************************************************/
/*	Description:	This Function Sets output Type push-pull or open-drain	*/
/*	Parameters:							                       				*/
/*		@param1:	Pin Number				    		                   	*/
/*		&param2:	Output Type						                       	*/
/*	Return:			Returns Error State 	            		           	*/
/*	Notes:			You still have to enable the Port Clock first 		 	*/
/****************************************************************************/
ES_t GPIO_enuSetPortSpeed(GPIO_Port_t Copy_u8PortID ,GPIO_OutSpeed_t Copy_enuSpeed){
	ES_t Local_enuErrorState = ES_NOK;


	return Local_enuErrorState;
}
/****************************************************************************/
/*	Description:	This Function Sets output Type push-pull or open-drain	*/
/*	Parameters:							                       				*/
/*		@param1:	Pin Number				    		                   	*/
/*		&param2:	Output Type						                       	*/
/*	Return:			Returns Error State 	            		           	*/
/*	Notes:			You still have to enable the Port Clock first 		 	*/
/****************************************************************************/
ES_t GPIO_enuSetPortValue(GPIO_Port_t Copy_u8PortID ,uint8_t Copy_u8PortValue){
	ES_t Local_enuErrorState = ES_NOK;


	return Local_enuErrorState;
}
/***************************************************************/
/****************************************************************************/
/*	Description:	This Function Sets output Type push-pull or open-drain	*/
/*	Parameters:							                       				*/
/*		@param1:	Pin Number				    		                   	*/
/*		&param2:	Output Type						                       	*/
/*	Return:			Returns Error State 	            		           	*/
/*	Notes:			You still have to enable the Port Clock first 		 	*/
/****************************************************************************/
ES_t GPIO_enuGetPortValue(GPIO_Port_t Copy_u8PortID ,uint8_t * Copy_pu8RetPortValue){
	ES_t Local_enuErrorState = ES_NOK;


	return Local_enuErrorState;
}
