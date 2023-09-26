/*
 * RCC_Program.c
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 23, 2023
 *	Brief		: This file contains all the
 */


#include "MCAL/RCC_Driver/RCC_Config.h"
#include "RCC_Private.h"

/***************************************************************/
/*	Function Name: 	Name				                       */
/*	Description:	This Function makes	                       */
/*	Parameters:							                       */
/*			@param1:					                       */
/*			&param2:					                       */
/*	Return:		Returns Error State 	                       */
/***************************************************************/
ES_t RCC_enuOscilatorInit(RCC_OSC_Config_t * Copy_pstrOSC_Config){
	ES_t Local_enuErrorState = ES_NOK;

	if(NULL != Copy_pstrOSC_Config){
		switch(Copy_pstrOSC_Config->OSC_Type){
		case RCC_OSC_Disabled:
			/* Nothing */
			break;
		case RCC_OSC_HSE:
			if(RCC_OSC_ON == Copy_pstrOSC_Config->HSE_State){
				/*	System Clock Switch before applying ON enable */
				SET_BIT(RCC->CR,RCC_CFGR_SW0_POS);
				CLR_BIT(RCC->CR,RCC_CFGR_SW1_POS);
				/*	Enable the OSC after we switched to it	*/
				SET_BIT(RCC->CR,HSE_ON_BIT_POS);
			}else if(RCC_OSC_OFF == Copy_pstrOSC_Config->HSE_State){
				CLR_BIT(RCC->CR,HSE_ON_BIT_POS);
			}
			else{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
			break;
		case RCC_OSC_HSI:
			if(RCC_OSC_ON == Copy_pstrOSC_Config->HSI_State){
				/*	System Clock Switch before applying ON enable */
				CLR_BIT(RCC->CR,RCC_CFGR_SW0_POS);
				CLR_BIT(RCC->CR,RCC_CFGR_SW1_POS);
				/*	Enable the OSC after we switched to it	*/
				SET_BIT(RCC->CR,HSI_ON_BIT_POS);
			}else if(RCC_OSC_OFF == Copy_pstrOSC_Config->HSI_State){
				CLR_BIT(RCC->CR,HSI_ON_BIT_POS);
			}
			else{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
			break;
		case RCC_OSC_LSE:
			if(RCC_OSC_ON == Copy_pstrOSC_Config->LSE_State){
				SET_BIT(RCC->BDCR,LSE_ON_BIT_POS);
			}else if(RCC_OSC_OFF == Copy_pstrOSC_Config->LSE_State){
				CLR_BIT(RCC->BDCR,LSE_ON_BIT_POS);
			}
			else{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
			break;
		case RCC_OSC_LSI:
			if(RCC_OSC_ON == Copy_pstrOSC_Config->LSI_State){
				SET_BIT(RCC->CR,LSE_ON_BIT_POS);
			}else if(RCC_OSC_OFF == Copy_pstrOSC_Config->LSI_State){
				CLR_BIT(RCC->CR,LSE_ON_BIT_POS);
			}
			else{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
			break;
		}
	}else{
		Local_enuErrorState = ES_POINTER_TO_VOID;
	}

	return Local_enuErrorState;
}


/***************************************************************/
/*	Function Name: 	Name				                       */
/*	Description:	This Function makes	                       */
/*	Parameters:							                       */
/*			@param1:					                       */
/*			&param2:					                       */
/*	Return:		Returns Error State 	                       */
/***************************************************************/
ES_t RCC_enuClocksInit(RCC_Clock_Config_t * Copy_pstrClk_Config){
	ES_t Local_enuErrorState = ES_NOK;
	if(NULL != Copy_pstrClk_Config){

		UPDATE_BITS(RCC->CFGR,HPRE_BITS_MSK,Copy_pstrClk_Config->AHB_Pres);

		UPDATE_BITS(RCC->CFGR,PPRE1_BITS_MSK,Copy_pstrClk_Config->APB1_Pres);

		UPDATE_BITS(RCC->CFGR,PPRE2_BITS_MSK,Copy_pstrClk_Config->APB2_Pres);

	}else{
		Local_enuErrorState = ES_POINTER_TO_VOID;
	}

	return Local_enuErrorState;
}


/***************************************************************/
/*	Function Name: 	Name				                       */
/*	Description:	This Function makes	                       */
/*	Parameters:							                       */
/*			@param1:					                       */
/*			&param2:					                       */
/*	Return:		Returns Error State 	                       */
/***************************************************************/
ES_t RCC_enuSetClockState(RCC_Target_t Copy_enuTarget ,bool Copy_enuIsEnabled){
	ES_t Local_enuErrorState = ES_NOK;

	if(true == Copy_enuIsEnabled){
		switch(Copy_enuTarget){
		case RCC_GPIOA:
			HAL_RCC_GPIOA_CLK_ENABLE();
			break;
		case RCC_GPIOB:
			HAL_RCC_GPIOB_CLK_ENABLE();
			break;
		case RCC_GPIOC:
			HAL_RCC_GPIOC_CLK_ENABLE();
			break;
		case RCC_GPIOD:
			HAL_RCC_GPIOD_CLK_ENABLE();
			break;
		case RCC_GPIOE:
			HAL_RCC_GPIOE_CLK_ENABLE();
			break;
		case RCC_GPIOH:
			HAL_RCC_GPIOH_CLK_ENABLE();
			break;
		case RCC_DMA1:
			HAL_RCC_DMA1_CLK_ENABLE();
			break;
		case RCC_DMA2:
			HAL_RCC_DMA2_CLK_ENABLE();
			break;
		case RCC_CRC:
			HAL_RCC_CRC_CLK_ENABLE();
			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

		if(ES_OUT_OF_RANGE != Local_enuErrorState){
			Local_enuErrorState = ES_OK;
		}

	}else if(false == Copy_enuIsEnabled){
		switch(Copy_enuTarget){
		case RCC_GPIOA:
			HAL_RCC_GPIOA_CLK_DISABLE();
			break;
		case RCC_GPIOB:
			HAL_RCC_GPIOB_CLK_DISABLE();
			break;
		case RCC_GPIOC:
			HAL_RCC_GPIOC_CLK_DISABLE();
			break;
		case RCC_GPIOD:
			HAL_RCC_GPIOD_CLK_DISABLE();
			break;
		case RCC_GPIOE:
			HAL_RCC_GPIOE_CLK_DISABLE();
			break;
		case RCC_GPIOH:
			HAL_RCC_GPIOH_CLK_DISABLE();
			break;
		case RCC_DMA1:
			HAL_RCC_DMA1_CLK_DISABLE();
			break;
		case RCC_DMA2:
			HAL_RCC_DMA2_CLK_DISABLE();
			break;
		case RCC_CRC:
			HAL_RCC_CRC_CLK_DISABLE();
			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

		if(ES_OUT_OF_RANGE != Local_enuErrorState){
			Local_enuErrorState = ES_OK;
		}
	}else{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}



	return Local_enuErrorState;
}

