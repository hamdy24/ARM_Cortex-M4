/*
 * SysTick_Program.c
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 25, 2023
 *	Brief		: This file contains all interfaces implementation for SysTick
 */

#include "../SysTick/SysTick_Private.h"


ES_t STK_enuInit(STK_Cfg_t * Copy_pstrSTK_Configs){
	ES_t Local_enuErrorState = ES_NOK;

	STK_CfgHelper = Copy_pstrSTK_Configs;

	/* Stop SysTick to avoid if its exception was fired during setup*/
	CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_POS);
	if(STK_Enabled == Copy_pstrSTK_Configs->EnableState)
	{
		if(MAX_LOAD >= Copy_pstrSTK_Configs->Initial_Load && MIN_LOAD <= Copy_pstrSTK_Configs->Initial_Load){
			/** Set the Load Value **/
			STK->LOAD = (Copy_pstrSTK_Configs->Initial_Load);
			/** Clear the Current to load the new value **/
			STK->VAL = 0;
			/** Select Clock Divider **/
			if(STK_Pres_1 == Copy_pstrSTK_Configs->STK_Prescaler){

				SET_BIT(STK->CTRL,STK_CTRL_CLK_SOURCE_POS);
			}else if(STK_Pres_8 == Copy_pstrSTK_Configs->STK_Prescaler){

				CLR_BIT(STK->CTRL,STK_CTRL_CLK_SOURCE_POS);
			}
			else{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
			/** Set Initial IRQ state **/
			if(true == Copy_pstrSTK_Configs->INT_State){
				SET_BIT(STK->CTRL,STK_CTRL_TICK_INT_POS);
			}
			else if(false == Copy_pstrSTK_Configs->INT_State){
				CLR_BIT(STK->CTRL,STK_CTRL_TICK_INT_POS);
			}
			else{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
			/** Set Error State **/
			if(ES_OUT_OF_RANGE != Local_enuErrorState)
				Local_enuErrorState = ES_OK;
		}
		else{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

	}
	else if(STK_Disabled == Copy_pstrSTK_Configs->EnableState){
		/* Nothing as i already disable it at start */
		Local_enuErrorState = ES_OK;
	}
	else {
		Local_enuErrorState = ES_INVALID_INPUTS;
	}
	return Local_enuErrorState;
}
ES_t STK_enuDeInit(void){
	ES_t Local_enuErrorState = ES_NOK;
	/** Set the Load Value **/
	STK->LOAD = 0;
	/** Clear the Current to load the new value **/
	STK->VAL = 0;
	/** Disable IRQ **/
	CLR_BIT(STK->CTRL,STK_CTRL_TICK_INT_POS);
	/** Enable SysTick Timer ***/
	CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_POS);

	return Local_enuErrorState;
}



ES_t STK_enuDelay_Blocking(uint32_t Copy_u32Interval_ms){
	ES_t Local_enuErrorState = ES_NOK;
/****************************** WORKINGGGGG           ***************************************************************************/

//    uint32_t targetTicks = (uint32_t)( Copy_u32Interval_ms * ((STK_AHB_Clk) / (STK_AHB_Pres*1000.0 )) );// working
    uint32_t targetTicks = (uint32_t)( Copy_u32Interval_ms * ((STK_CfgHelper->STK_AHB_ClockValue) / (STK_CfgHelper->STK_AHB_Prescaler*500)) );// test
//    targetTicks = 2000;
//    targetTicks = 500000 = 1000 * (m  / 1000)
    // Enable SysTick with AHB clock source and disable interrupt
    SET_BIT(STK->CTRL,STK_CTRL_ENABLE_POS);

    while (targetTicks > 0) {
        if (IS_BIT_CLEARED(STK->CTRL, STK_CTRL_COUNT_FLAG_POS)) {
            targetTicks--;
        }
    }

    // Disable SysTick
    CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_POS);

/*********************************************************************************************************/
//
//    /** Set the Load Value **/
//	STK->LOAD = ( (Copy_u32Interval_ms * AHB_Clk ) / (AHB_Pres * 1000));
//
//	/** Enable SysTick Timer ***/
//	SET_BIT(STK->CTRL,STK_CTRL_ENABLE_POS);
//
//    /* Count to the specified time in seconds */
//	while(IS_BIT_SET(STK->CTRL,STK_CTRL_COUNT_FLAG_POS))
//
//
//	/** Disable SysTick Timer ***/
//	CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_POS);
//	/** Set the Load Value **/
//	STK->LOAD = 0;
//	/** Clear the Current to load the new value **/
//	STK->VAL = 0;

	return Local_enuErrorState;
}


ES_t STK_enuSingleInterval(uint32_t Copy_u32Interval_Ticks, CallBackFunc_t Copy_pfunAppCallBack){
	ES_t Local_enuErrorState = ES_NOK;

	if(NULL != Copy_pfunAppCallBack){
		/** Set the Load Value **/
		STK->LOAD = Copy_u32Interval_Ticks;
		/** Set CallBack **/
		SysTick_CallBack = Copy_pfunAppCallBack;
		/** Select Single Mode **/
		SysTick_Mode = SysTick_SingleInterval;
		/** Enable SysTick IRQ **/
		SET_BIT(STK->CTRL,STK_CTRL_TICK_INT_POS);
/*
 * Here we should handle the IRQ Priority
 */
		/** Enable SysTick Timer ***/
		SET_BIT(STK->CTRL,STK_CTRL_ENABLE_POS);
		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_POINTER_TO_VOID;
	}



	return Local_enuErrorState;
}
ES_t STK_enuPeriodicInterval(uint32_t Copy_u32Interval_Ticks, CallBackFunc_t Copy_pfunAppCallBack){
	ES_t Local_enuErrorState = ES_NOK;

	if(NULL != Copy_pfunAppCallBack){
		/** Set the Load Value **/
		STK->LOAD = Copy_u32Interval_Ticks;
		/** Set CallBack **/
		SysTick_CallBack = Copy_pfunAppCallBack;
		/** Select Single Mode **/
		SysTick_Mode = SysTick_PeriodicInterval;
		/** Enable SysTick IRQ **/
		SET_BIT(STK->CTRL,STK_CTRL_TICK_INT_POS);
/*
 * Here we should handle the IRQ Priority
 */
		/** Enable SysTick Timer ***/
		SET_BIT(STK->CTRL,STK_CTRL_ENABLE_POS);
		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_POINTER_TO_VOID;
	}



	return Local_enuErrorState;
}
ES_t STK_enuGetRemainingTicks(uint32_t * Copy_pu32ReturnedTicks){
	ES_t Local_enuErrorState = ES_NOK;
	if(NULL != Copy_pu32ReturnedTicks){
		*Copy_pu32ReturnedTicks = STK->VAL;
		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_POINTER_TO_VOID;

	}
	return Local_enuErrorState;
}


void SysTick_Handler(void){

	if(NULL != SysTick_CallBack){
		if(SysTick_SingleInterval == SysTick_Mode){
			/** Disable SysTick Timer ***/
			CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_POS);
			/** Disable SysTick IRQ ***/
			CLR_BIT(STK->CTRL,STK_CTRL_TICK_INT_POS);
			/** Clear the Load Value **/
			STK->LOAD = 0;
			/** Clear the Current to load the new value **/
			STK->VAL = 0;

		}

		SysTick_CallBack();
	}
}
