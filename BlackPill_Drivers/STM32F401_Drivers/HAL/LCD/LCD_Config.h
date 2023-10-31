/*
 * LCD_Config.h
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Oct 1, 2023
 *	Brief		: This file contains all the
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_
/************************************ Includes Start *************************************************/
#include "../../Common/CommonMacros.h"
#include "../../Common/ErrorState.h"
#include "../../Common/STD_Types.h"

/************************************ Includes END  *************************************************/

/************************************ Macros Start *************************************************/
/************************************ Macros END  *************************************************/

/************************************ HelperEnums Declaration Start *************************************************/
typedef enum{
	LCD_4Bit = 4,
	LCD_8Bit = 8,
}LCD_Mode_t;

/************************************ HelperEnums Declaration  END  *************************************************/

/************************************ DataTypes Declaration Start *************************************************/

typedef struct{

	LCD_Mode_t Mode;
	uint8_t RowsNum ;
	uint8_t ColumnsNum;

	/** Control Pins  **/
	GPIO_Pins_t RS_Pin;
	GPIO_Pins_t RW_Pin;
	GPIO_Pins_t En_Pin;

	/** Data Pins	**/
	GPIO_Pins_t D7_Pin;
	GPIO_Pins_t D6_Pin;
	GPIO_Pins_t D5_Pin;
	GPIO_Pins_t D4_Pin;
	GPIO_Pins_t D3_Pin;
	GPIO_Pins_t D2_Pin;
	GPIO_Pins_t D1_Pin;
	GPIO_Pins_t D0_Pin;

}LCD_t;


typedef struct{
	GPIO_Pins_t D7_Pin;
	GPIO_Pins_t D6_Pin;
	GPIO_Pins_t D5_Pin;
	GPIO_Pins_t D4_Pin;
}LCD_4Bit_Pins_t;

typedef struct{
	GPIO_Pins_t D7_Pin;
	GPIO_Pins_t D6_Pin;
	GPIO_Pins_t D5_Pin;
	GPIO_Pins_t D4_Pin;
	GPIO_Pins_t D3_Pin;
	GPIO_Pins_t D2_Pin;
	GPIO_Pins_t D1_Pin;
	GPIO_Pins_t D0_Pin;
}LCD_8Bit_Pins_t;

typedef struct{

	union {
		LCD_4Bit_Pins_t Pins_4Bits;
		LCD_8Bit_Pins_t Pins_8Bits;
	};

}LCD2_t;







/************************************ DataTypes Declaration  END  *************************************************/


#endif /* HAL_LCD_LCD_CONFIG_H_ */
