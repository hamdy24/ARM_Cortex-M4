/*
 * SysTick_Program.c
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 25, 2023
 *	Brief		: This file contains all the
 */

#include "SysTick_Private.h"


ES_t STK_enuInit(STK_Cfg_t * Copy_pstrSTK_Configs){
	ES_t Local_enuErrorState = ES_NOK;
	/* Stop SysTick to avoid if its exception was fired during setup*/
	CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_POS);
	if(STK_Enabled == Copy_pstrSTK_Configs->State)
	{
		if(MAX_LOAD >= Copy_pstrSTK_Configs->Initial_Load && MIN_LOAD <= Copy_pstrSTK_Configs->Initial_Load){
			/** Set the Load Value **/
			STK->LOAD = (Copy_pstrSTK_Configs->Initial_Load);
			/** Clear the Current to load the new value **/
			STK->VAL = 0;
			/** Select Clock Divider **/
			if(STK_Pres_1 == Copy_pstrSTK_Configs->Prescaler){

				AHB_Clk = Copy_pstrSTK_Configs->AHB_ClockValue;
				AHB_Pres = 1;
				SET_BIT(STK->CTRL,STK_CTRL_CLK_SOURCE_POS);
			}else if(STK_Pres_8 == Copy_pstrSTK_Configs->Prescaler){

				AHB_Clk = Copy_pstrSTK_Configs->AHB_ClockValue;
				AHB_Pres = 8;
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
	else if(STK_Disabled == Copy_pstrSTK_Configs->State){
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

    uint16_t Local_u16Overflow_Counter = 0;


    // TickTime = AHB_Pres/AHB_Clk;
    // time(s) = tick time(s) * tick count
    // count = time / tick time
    // LOAD = ( (Copy_u32Interval_ms * AHB_Clk ) / (AHB_Pres * 1000))

    /** Set the Load Value **/
	STK->LOAD = ( (Copy_u32Interval_ms * AHB_Clk ) / (AHB_Pres * 1000));

	/** Enable SysTick Timer ***/
	SET_BIT(STK->CTRL,STK_CTRL_ENABLE_POS);

    /* Count to the specified time in seconds */
	while(IS_BIT_SET(STK->CTRL,STK_CTRL_COUNT_FLAG_POS))


	/** Disable SysTick Timer ***/
	CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_POS);
	/** Set the Load Value **/
	STK->LOAD = 0;
	/** Clear the Current to load the new value **/
	STK->VAL = 0;

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
