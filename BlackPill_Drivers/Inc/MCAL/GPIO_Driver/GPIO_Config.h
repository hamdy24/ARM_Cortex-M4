/*
 * GPIO_Config.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Sep 26, 2023
 *	Brief		: This file contains all the
 */

#ifndef MCAL_GPIO_DRIVER_GPIO_CONFIG_H_
#define MCAL_GPIO_DRIVER_GPIO_CONFIG_H_
/************************************ Includes Start *************************************************/

#include "Common/STD_Types.h"

/************************************ Includes END  *************************************************/

/************************************ Macros Start *************************************************/
/************************************ Macros END  *************************************************/

/************************************ HelperEnums Declaration Start *************************************************/

typedef enum{
	GPIO_Input,
	GPIO_General,
	GPIO_Alternate,
	GPIO_Analog,
}GPIO_Mode_t;

typedef enum{
	GPIO_OUT_PushPull,
	GPIO_OUT_OpenDrain,
}GPIO_OutType_t;

typedef enum{
	GPIO_LowSpeed,
	GPIO_MediumSpeed,
	GPIO_HighSpeed,
	GPIO_VeryHighSpeed,
}GPIO_OutSpeed_t;

typedef enum{
	GPIO_NoPull,
	GPIO_PullUp,
	GPIO_PullDown,
	GPIO_Reserved,
}GPIO_PullType_t;

typedef enum{
	GPIO_Reset,
	GPIO_Set,
}GPIO_Logic_t;

typedef enum{
	GPIO_PA0    ,
	GPIO_PA1    ,
	GPIO_PA2    ,
	GPIO_PA3    ,
	GPIO_PA4    ,
	GPIO_PA5    ,
	GPIO_PA6    ,
	GPIO_PA7    ,
	GPIO_PA8    ,
	GPIO_PA9    ,
	GPIO_PA10   ,
	GPIO_PA11   ,
	GPIO_PA12   ,
	GPIO_PA13   ,
	GPIO_PA14   ,
	GPIO_PA15   ,
	GPIO_PB0    ,
	GPIO_PB1    ,
	GPIO_PB2    ,
	GPIO_PB3    ,
	GPIO_PB4    ,
	GPIO_PB5    ,
	GPIO_PB6    ,
	GPIO_PB7    ,
	GPIO_PB8    ,
	GPIO_PB9    ,
	GPIO_PB10   ,
	GPIO_PB11   ,
	GPIO_PB12   ,
	GPIO_PB13   ,
	GPIO_PB14   ,
	GPIO_PB15   ,
	GPIO_PC13=45,
	GPIO_PC14   ,
	GPIO_PC15   ,
}GPIO_Pins_t;


typedef enum{
	GPIO_PortA,
	GPIO_PortB,
	GPIO_PortC,	/*	Only have pins 133,14,15	*/
}GPIO_Port_t;

typedef enum{
	GPIO_AF0,
	GPIO_AF1,
	GPIO_AF2,
	GPIO_AF3,
	GPIO_AF4,
	GPIO_AF5,
	GPIO_AF6,
	GPIO_AF7,
	GPIO_AF8,
	GPIO_AF9,
	GPIO_AF10,
	GPIO_AF11,
	GPIO_AF12,
	GPIO_AF13,
	GPIO_AF14,
	GPIO_AF15,
}GPIO_AlterFunc_t;


/************************************ HelperEnums Declaration  END  *************************************************/

/************************************ DataTypes Declaration Start *************************************************/

//typedef struct{
//
//}GPIO_Cfg_t;
/************************************ DataTypes Declaration  END  *************************************************/


#endif /* MCAL_GPIO_DRIVER_GPIO_CONFIG_H_ */
