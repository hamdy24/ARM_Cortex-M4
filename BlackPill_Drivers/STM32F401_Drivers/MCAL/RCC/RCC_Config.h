/*
 * RCC_Config.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 23, 2023
 *	Brief		: This file contains all the configurations helpers for the SYSCFG
 */

#ifndef MCAL_RCC_RCC_CONFIG_H_
#define MCAL_RCC_RCC_CONFIG_H_

#include "../../Common/ErrorState.h"
#include "../../Common/STD_Types.h"
#include "../../Common/CommonMacros.h"

typedef enum{
	RCC_OSC_Disabled,
	RCC_OSC_HSE = 1UL,
	RCC_OSC_LSE = 2UL,
	RCC_OSC_HSI = 4UL,
	RCC_OSC_LSI = 8UL,
}RCC_OSC_Src_enuType;
typedef enum{
	RCC_OSC_OFF,
	RCC_OSC_ON,
}RCC_OSC_State_enuType;

typedef struct{
	RCC_OSC_Src_enuType OSC_Type;
	RCC_OSC_State_enuType HSE_State;
	RCC_OSC_State_enuType LSE_State;
	RCC_OSC_State_enuType HSI_State;
	RCC_OSC_State_enuType LSI_State;
}RCC_OSC_Config_t;

/*
 *
 */

typedef enum{
	RCC_AHB_PRES_NONE	=0x00UL,
	RCC_AHB_PRES_2		=0x80UL,
	RCC_AHB_PRES_4		=0x90UL,
	RCC_AHB_PRES_8		=0xA0UL,
	RCC_AHB_PRES_16		=0xB0UL,
	RCC_AHB_PRES_64		=0xC0UL,
	RCC_AHB_PRES_128	=0xD0UL,
	RCC_AHB_PRES_256	=0xE0UL,
	RCC_AHB_PRES_512	=0xF0UL,
}AHB_Pres_enuType;

typedef enum{
	RCC_APB1_PRES_NONE	=0x0000UL,
	RCC_APB1_PRES_2		=0x1000UL,
	RCC_APB1_PRES_4		=0x1400UL,
	RCC_APB1_PRES_8		=0x1800UL,
	RCC_APB1_PRES_16	=0x1C00UL,
}APB1_Pres_enuType;


typedef enum{
	RCC_APB2_PRES_NONE	=0x0000UL,
	RCC_APB2_PRES_2		=0x8000UL,
	RCC_APB2_PRES_4		=0xA000UL,
	RCC_APB2_PRES_8		=0xC000UL,
	RCC_APB2_PRES_16	=0xE000UL,
}APB2_Pres_enuType;

typedef struct{
	AHB_Pres_enuType AHB_Pres;
	APB1_Pres_enuType APB1_Pres;
	APB2_Pres_enuType APB2_Pres;
}RCC_Clock_Config_t;


typedef enum{
	RCC_GPIOA,
	RCC_GPIOB,
	RCC_GPIOC,
	RCC_GPIOD,
	RCC_GPIOE,
	RCC_GPIOH,
	RCC_CRC,
	RCC_DMA1,
	RCC_DMA2,
	RCC_SYSCFG,
}RCC_Target_t;

#endif /* MCAL_RCC_RCC_CONFIG_H_ */
