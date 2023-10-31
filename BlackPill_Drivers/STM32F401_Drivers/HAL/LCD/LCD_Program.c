/*
 * Keypad_Program.c
 *
 *  Author		: Hamdy Aouf
 *  Created on	: Oct 1, 2023
 *	Brief		: This file contains all the
 */

/************************************ Includes Start *************************************************/
#include "LCD_Private.h"
/************************************ Includes END  *************************************************/


/********************************************************************/
/*	Description:	This Function sets  		*/
/*	Parameters:							                       		*/
/*		@param1: 						               		*/
/*		&param2:			       		*/
/*	Return:			Returns Error State 	                       	*/
/*	Notes:			None  	*/
/********************************************************************/


ES_t LCD_enuInit(LCD_t * Copy_pstrConfigs) {
	uint8_t Local_ErrorState = ES_NOK;


	LCD_pstrConfigs = Copy_pstrConfigs;


//	LCD2_t test;
//	test.Pins_4Bits.D7_Pin = 1;


	GPIO_enuSetPinMode(Copy_pstrConfigs->RS_Pin, GPIO_General);
	GPIO_enuSetPinMode(Copy_pstrConfigs->RW_Pin, GPIO_General);
	GPIO_enuSetPinMode(Copy_pstrConfigs->En_Pin, GPIO_General);

	GPIO_enuSetPinType(Copy_pstrConfigs->RS_Pin, GPIO_OUT_PushPull);
	GPIO_enuSetPinType(Copy_pstrConfigs->RW_Pin, GPIO_OUT_PushPull);
	GPIO_enuSetPinType(Copy_pstrConfigs->En_Pin, GPIO_OUT_PushPull);

	GPIO_enuSetPinPull(Copy_pstrConfigs->RS_Pin, GPIO_NoPull);
	GPIO_enuSetPinPull(Copy_pstrConfigs->RW_Pin, GPIO_NoPull);
	GPIO_enuSetPinPull(Copy_pstrConfigs->En_Pin, GPIO_NoPull);

	GPIO_enuSetPinMode(Copy_pstrConfigs->D7_Pin, GPIO_General);
	GPIO_enuSetPinMode(Copy_pstrConfigs->D6_Pin, GPIO_General);
	GPIO_enuSetPinMode(Copy_pstrConfigs->D5_Pin, GPIO_General);
	GPIO_enuSetPinMode(Copy_pstrConfigs->D4_Pin, GPIO_General);

	GPIO_enuSetPinType(Copy_pstrConfigs->D7_Pin, GPIO_OUT_PushPull);
	GPIO_enuSetPinType(Copy_pstrConfigs->D6_Pin, GPIO_OUT_PushPull);
	GPIO_enuSetPinType(Copy_pstrConfigs->D5_Pin, GPIO_OUT_PushPull);
	GPIO_enuSetPinType(Copy_pstrConfigs->D4_Pin, GPIO_OUT_PushPull);

	GPIO_enuSetPinPull(Copy_pstrConfigs->D7_Pin, GPIO_NoPull);
	GPIO_enuSetPinPull(Copy_pstrConfigs->D6_Pin, GPIO_NoPull);
	GPIO_enuSetPinPull(Copy_pstrConfigs->D5_Pin, GPIO_NoPull);
	GPIO_enuSetPinPull(Copy_pstrConfigs->D4_Pin, GPIO_NoPull);


	STK_enuDelay_Blocking(35); //power on

	if(Copy_pstrConfigs->Mode == LCD_4Bit){

		GPIO_enuSetPinValue(Copy_pstrConfigs->RS_Pin, GPIO_Low); //LOW in instruction mode
		LCD_enuWriteAndLatch(FUNC_SET_FOUR_BIT);
	}

	else if(Copy_pstrConfigs->Mode == LCD_8Bit){

		GPIO_enuSetPinValue(Copy_pstrConfigs->RS_Pin, GPIO_Low);
		LCD_enuWriteAndLatch(FUNC_SET_EIGHT_BIT);

		GPIO_enuSetPinMode(Copy_pstrConfigs->D3_Pin, GPIO_General);
		GPIO_enuSetPinMode(Copy_pstrConfigs->D2_Pin, GPIO_General);
		GPIO_enuSetPinMode(Copy_pstrConfigs->D1_Pin, GPIO_General);
		GPIO_enuSetPinMode(Copy_pstrConfigs->D0_Pin, GPIO_General);
	}


	STK_enuDelay_Blocking(1);
	GPIO_enuSetPinValue(Copy_pstrConfigs->RS_Pin, GPIO_Low);
	LCD_enuWriteAndLatch(DISPLAY_ON_CURSOR_OFF);

	STK_enuDelay_Blocking(1);
	GPIO_enuSetPinValue(Copy_pstrConfigs->RS_Pin, GPIO_Low);
	LCD_enuWriteAndLatch(CLEAR_DISPLAY);

	STK_enuDelay_Blocking(3);
	GPIO_enuSetPinValue(Copy_pstrConfigs->RS_Pin, GPIO_Low);
	LCD_enuWriteAndLatch(ENTRY_MOOD);

	return Local_ErrorState;
}

static ES_t LCD_enuWriteAndLatch(uint8_t Copy_u8Data) {/************ static makes sure the function is local and can not be externed*****************/

	uint8_t Local_ErrorState = ES_NOK;

	/******* make sure RW_PORT low to be in write mode *****/
	/******* make sure EN_PORT low to be ready for the latch	*****/

	GPIO_enuSetPinValue(LCD_pstrConfigs->RW_Pin, GPIO_Low); // low as we write data or instruction
	GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_Low); // low to be ready for the latch -> H-L

	/********** Data Writing ************/

	if (Copy_u8Data == FUNC_SET_FOUR_BIT) // function set for four bit mode needs extra send operation
	{
		uint8_t Local_u8RS_Value;
		GPIO_enuGetPinValue(LCD_pstrConfigs->RS_Pin, &Local_u8RS_Value);
		if(Local_u8RS_Value == 0){
			GPIO_enuSetPinValue(GPIO_PC13,GPIO_High);
			STK_enuDelay_Blocking(1000);
			GPIO_enuSetPinValue(GPIO_PC13,GPIO_Low);

		}

		if (Local_u8RS_Value == GPIO_Low) //CHECK if RS is set in instructions mode else it is to display ')' 0x28
				{

			//if true we need to write upper four bits twice.. once here in the if condition the other in the ordinary #if four bit mode
			GPIO_enuSetPinValue(LCD_pstrConfigs->D7_Pin, (Copy_u8Data >> SHIFT_PIN_7) & MASK_BIT);
			GPIO_enuSetPinValue(LCD_pstrConfigs->D6_Pin, (Copy_u8Data >> SHIFT_PIN_6) & MASK_BIT);
			GPIO_enuSetPinValue(LCD_pstrConfigs->D5_Pin, (Copy_u8Data >> SHIFT_PIN_5) & MASK_BIT);
			GPIO_enuSetPinValue(LCD_pstrConfigs->D4_Pin, (Copy_u8Data >> SHIFT_PIN_4) & MASK_BIT);

			/**********the latch ************/

			GPIO_enuSetPinValue(LCD_pstrConfigs->En_Pin, GPIO_High);
			STK_enuDelay_Blocking(1);
			GPIO_enuSetPinValue(LCD_pstrConfigs->En_Pin, GPIO_Low);
			STK_enuDelay_Blocking(1);

		}
	}
	if(LCD_pstrConfigs->Mode == LCD_4Bit){

		//4-4
		GPIO_enuSetPinValue(LCD_pstrConfigs->D7_Pin, (Copy_u8Data >> SHIFT_PIN_7) & MASK_BIT);
		GPIO_enuSetPinValue(LCD_pstrConfigs->D6_Pin, (Copy_u8Data >> SHIFT_PIN_6) & MASK_BIT);
		GPIO_enuSetPinValue(LCD_pstrConfigs->D5_Pin, (Copy_u8Data >> SHIFT_PIN_5) & MASK_BIT);
		GPIO_enuSetPinValue(LCD_pstrConfigs->D4_Pin, (Copy_u8Data >> SHIFT_PIN_4) & MASK_BIT);
		/*		the latch		*/
		GPIO_enuSetPinValue(LCD_pstrConfigs->En_Pin, GPIO_High);
		STK_enuDelay_Blocking(1);
		GPIO_enuSetPinValue(LCD_pstrConfigs->En_Pin, GPIO_Low);
		STK_enuDelay_Blocking(1);

		GPIO_enuSetPinValue(LCD_pstrConfigs->D7_Pin, (Copy_u8Data >> SHIFT_PIN_3) & MASK_BIT);
		GPIO_enuSetPinValue(LCD_pstrConfigs->D6_Pin, (Copy_u8Data >> SHIFT_PIN_2) & MASK_BIT);
		GPIO_enuSetPinValue(LCD_pstrConfigs->D5_Pin, (Copy_u8Data >> SHIFT_PIN_1) & MASK_BIT);
		GPIO_enuSetPinValue(LCD_pstrConfigs->D4_Pin, (Copy_u8Data >> SHIFT_PIN_0) & MASK_BIT);
		/*		the latch		*/
		GPIO_enuSetPinValue(LCD_pstrConfigs->En_Pin, GPIO_High);
		STK_enuDelay_Blocking(1);
		GPIO_enuSetPinValue(LCD_pstrConfigs->En_Pin, GPIO_Low);
		STK_enuDelay_Blocking(1);
	}


	else if (LCD_pstrConfigs->Mode == LCD_8Bit){

		GPIO_enuSetPinValue(LCD_pstrConfigs->D7_Pin, (Copy_u8Data >> SHIFT_PIN_7) & MASK_BIT);
		GPIO_enuSetPinValue(LCD_pstrConfigs->D6_Pin, (Copy_u8Data >> SHIFT_PIN_6) & MASK_BIT);
		GPIO_enuSetPinValue(LCD_pstrConfigs->D5_Pin, (Copy_u8Data >> SHIFT_PIN_5) & MASK_BIT);
		GPIO_enuSetPinValue(LCD_pstrConfigs->D4_Pin, (Copy_u8Data >> SHIFT_PIN_4) & MASK_BIT);

		GPIO_enuSetPinValue(LCD_pstrConfigs->D3_Pin, (Copy_u8Data >> SHIFT_PIN_3) & MASK_BIT);
		GPIO_enuSetPinValue(LCD_pstrConfigs->D2_Pin, (Copy_u8Data >> SHIFT_PIN_2) & MASK_BIT);
		GPIO_enuSetPinValue(LCD_pstrConfigs->D1_Pin, (Copy_u8Data >> SHIFT_PIN_1) & MASK_BIT);
		GPIO_enuSetPinValue(LCD_pstrConfigs->D0_Pin, (Copy_u8Data >> SHIFT_PIN_0) & MASK_BIT);
		/*		the latch		*/
		GPIO_enuSetPinValue(LCD_pstrConfigs->En_Pin, GPIO_High );
		STK_enuDelay_Blocking(1);
		GPIO_enuSetPinValue(LCD_pstrConfigs->En_Pin, GPIO_Low );
		STK_enuDelay_Blocking(1);
	}

	return Local_ErrorState;
}

ES_t LCD_enuSendData(uint8_t Copy_u8Data) {
	uint8_t Local_ErrorState = ES_NOK;

	GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_High);   // High for Data

	LCD_enuWriteAndLatch(Copy_u8Data);

	return Local_ErrorState;
}

ES_t LCD_enuSendCommand(uint8_t Copy_u8Command) {

	uint8_t Local_ErrorState = ES_NOK;

	GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_Low);	//Low for Command

	LCD_enuWriteAndLatch(Copy_u8Command);

	return Local_ErrorState;
}

ES_t LCD_enuSendString(const char * Copy_pcString) {

	uint8_t Local_ErrorState = ES_NOK;

	while (*Copy_pcString != 0) //Notice 0 == \0(end of string seq)    but '0' == ASCII of 48
	{
		GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_High);	// High for Data
		LCD_enuWriteAndLatch(*Copy_pcString++);
	}

	return Local_ErrorState;
}

ES_t LCD_enuClearDisplay(void) {
	uint8_t Local_ErrorState = ES_NOK;

	GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_Low);
	LCD_enuWriteAndLatch(CLEAR_DISPLAY);

	return Local_ErrorState;
}

ES_t LCD_enuJumpCursorTo(uint8_t Copy_u8StartX_Position, uint8_t Copy_u8StartY_Position) {

	uint8_t Local_ErrorState = ES_NOK;

//	GPIO_enuSetPinValue(RS_PORT , RS_PIN , GPIO_Low);   // Low for Command
	GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_Low);   // Low for Command

	if (Copy_u8StartX_Position == 1) {
		LCD_enuWriteAndLatch((START_OF_LINE1 + Copy_u8StartY_Position));
		Local_ErrorState = ES_OK;
	}

	else if (Copy_u8StartX_Position == 2) {
		LCD_enuWriteAndLatch((START_OF_LINE2 + Copy_u8StartY_Position));
		Local_ErrorState = ES_OK;
	}
	else if (Copy_u8StartX_Position == 3) {
		LCD_enuWriteAndLatch((START_OF_LINE3 + Copy_u8StartY_Position));
		Local_ErrorState = ES_OK;
	}
	else if (Copy_u8StartX_Position == 4) {
		LCD_enuWriteAndLatch((START_OF_LINE4 + Copy_u8StartY_Position));
		Local_ErrorState = ES_OK;
	} else {
		Local_ErrorState = ES_OUT_OF_RANGE;
	}

	return Local_ErrorState;
}
//
//ES_t LCD_enuShiftDisplay(uint8_t Copy_u8StartX_Position,uint8_t Copy_u8StartY_Position, uint8_t Copy_u8Num_ofShifts)
//{
//	ES_t Local_ErrorState = ES_NOK;
//	if (Copy_u8StartX_Position == 1) {
//			GPIO_enuSetPinValue(RS_PORT, RS_PIN, GPIO_Low);   // Low for Command
//			LCD_enuWriteAndLatch((START_OF_LINE1 + Copy_u8StartY_Position));
//			for(uint8_t Local_u8Iterator = 0 ; Local_u8Iterator < Copy_u8Num_ofShifts; Local_u8Iterator++){
//				GPIO_enuSetPinValue(RS_PORT, RS_PIN, GPIO_Low);	//Low for Command
//				LCD_enuWriteAndLatch(0x1C);
//			}
//			DELAY_MS(50);
//			Local_ErrorState = ES_OK;
//	}
//	else if (Copy_u8StartX_Position == 2) {
//			GPIO_enuSetPinValue(RS_PORT, RS_PIN, GPIO_Low);   // Low for Command
//			LCD_enuWriteAndLatch((START_OF_LINE2 + Copy_u8StartY_Position));
//			for(uint8_t Local_u8Iterator = 0 ; Local_u8Iterator < Copy_u8Num_ofShifts; Local_u8Iterator++){
//				GPIO_enuSetPinValue(RS_PORT, RS_PIN, GPIO_Low);	//Low for Command
//				LCD_enuWriteAndLatch(0x1C);
//			}
//			DELAY_MS(50);
//			Local_ErrorState = ES_OK;
//	}
//	else {
//			Local_ErrorState = ES_OUT_OF_RANGE;
//		}
//
//
//	return Local_ErrorState;
//}

ES_t LCD_enuDisplayIntNum(sint32_t Copy_s32IntNumber) {

	uint8_t Local_ErrorState = ES_NOK;

	uint32_t Local_u32Remainder;
	uint32_t Local_u32ReverseNum = 0;
	uint8_t Local_u8DigitsNum = 0;
	/******** number given will be displayed reversely cause of LCD prints each number of the whole number individually ******/
	/*********  so we will reverse the whole number just to be displayed correctly at the end of function **********/
	if (Copy_s32IntNumber < 0) {
		GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_High);   //high for data
		LCD_enuWriteAndLatch('-');

		Copy_s32IntNumber *= -1; //after printing negative sign we convert the number to positive and procced
	}
	if(Copy_s32IntNumber == 0){
    	GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_High);   // High for Data
    	LCD_enuWriteAndLatch('0');
	}
	for (; Copy_s32IntNumber > 0; Copy_s32IntNumber /= 10) //number reversing loop
			{
		Local_u32Remainder = Copy_s32IntNumber % 10;
		Local_u32ReverseNum = Local_u32ReverseNum * 10 + Local_u32Remainder;
		Local_u8DigitsNum++; //counting number of digits for the original number
	}

	for (; Local_u8DigitsNum > 0; Local_u32ReverseNum /= 10) //reversed number displaying loop
			{ // for number of cycles equal to Local_u8DigitsNum , print digits

		uint8_t Local_u8NumToPrint = Local_u32ReverseNum % 10;
		GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_High); //high for data
		LCD_enuWriteAndLatch(Local_u8NumToPrint + '0');
		Local_u8DigitsNum--;
	}

	return Local_ErrorState;
}

ES_t LCD_enuDisplayCustomArrCharachter(uint8_t * Copy_u8pAu8CharHEXA,
		uint8_t Copy_u8NumOfPattern, uint8_t Copy_u8InputDirection) {
	uint8_t Local_ErrorState = ES_NOK;

	GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_Low); //for cmd
	LCD_enuWriteAndLatch(START_OF_CGRAM); //go to CG ram pattern 1 **  ( + pos*8)
	/********** pushing array characters to cgram	************/
	for (uint8_t Local_u8Local_Iterator = 0;
			Local_u8Local_Iterator < (Copy_u8NumOfPattern * PATTERN_SIZE);
			Local_u8Local_Iterator++) {
		GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_High);   // High for Data
		LCD_enuWriteAndLatch((Copy_u8pAu8CharHEXA[Local_u8Local_Iterator]));
		/***** starting from address 0x40 of pat 1 so we can call them back by their address from ddram as usual ***/
	}
//	GPIO_enuSetPinValue(RS_PORT , RS_PIN , GPIO_Low); //for cmd
//	LCD_enuWriteAndLatch(START_OF_LINE1);	//  command for ddram to display data starting from address mentioned

	GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_Low); //for cmd
	if (Copy_u8InputDirection == LEFT_INPUT)
		LCD_enuWriteAndLatch(ENGLISH_CURSOR_MODE); //Copy_u8InputDirection
	else
		LCD_enuWriteAndLatch(ARABIC_CURSOR_MODE);
	for (uint8_t Local_u8Local_Iterator = 0;
			Local_u8Local_Iterator < Copy_u8NumOfPattern;
			Local_u8Local_Iterator++) {
		GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_High);   // High for Data
		LCD_enuWriteAndLatch(Local_u8Local_Iterator);
	}

	return Local_ErrorState;
}

ES_t LCD_enuDisplayCustomSingleCharachter(uint8_t * Copy_u8pAu8CharHEXA, uint8_t Copy_u8PatternPosition, uint8_t Copy_u8DisplayPosition){
	uint8_t Local_ErrorState = ES_NOK;
	if (Copy_u8PatternPosition < 8) {
		GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_Low); //for cmd
		LCD_enuWriteAndLatch(START_OF_CGRAM + (Copy_u8PatternPosition * 8)); //go to CG ram pattern 1 **  ( + pos*8)
		/********** pushing array characters to cgram	************/
		for (uint8_t Local_u8Local_Iterator = 0; Local_u8Local_Iterator < PATTERN_SIZE; Local_u8Local_Iterator++) {
			GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_High);   // High for Data
			LCD_enuWriteAndLatch((Copy_u8pAu8CharHEXA[Local_u8Local_Iterator]));
			/***** starting from address 0x40 of pat 1 so we can call them back by their address from ddram as usual ***/
		}
		GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_Low); //for cmd
		LCD_enuWriteAndLatch(START_OF_LINE1 + Copy_u8DisplayPosition);//  command for ddram to display data starting from address mentioned

			GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_High);   // High for Data
			LCD_enuWriteAndLatch(Copy_u8PatternPosition);

	}
	return Local_ErrorState;
}

ES_t LCD_enuSavePattern(uint8_t *Copy_u8pAu8CharHEXA,uint8_t Copy_u8PatternPosition){
	ES_t Local_ErrorState = ES_NOK;

	GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_Low); //for cmd
	LCD_enuWriteAndLatch(START_OF_CGRAM + (Copy_u8PatternPosition * 8)); //go to CG ram pattern 1 **  ( + pos*8)
	/********** pushing array characters to cgram	************/
	for (uint8_t Local_u8Local_Iterator = 0; Local_u8Local_Iterator < PATTERN_SIZE; Local_u8Local_Iterator++) {
		GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_High);   // High for Data
		LCD_enuWriteAndLatch((Copy_u8pAu8CharHEXA[Local_u8Local_Iterator]));
		/***** starting from address 0x40 of pat 1 so we can call them back by their address from ddram as usual ***/
	}
	return Local_ErrorState;
}

ES_t LCD_enuPrintPattern(uint8_t Copy_u8PatternNum,uint8_t Copy_u8PositionX,uint8_t Copy_u8PositionY){
	ES_t Local_ErrorState = ES_NOK;

	GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_Low); //for cmd
	if(Copy_u8PositionX == 1)
		LCD_enuWriteAndLatch(START_OF_LINE1 + Copy_u8PositionY);//  command for ddram to display data starting from address mentioned
	if(Copy_u8PositionY == 2)
		LCD_enuWriteAndLatch(START_OF_LINE2 + Copy_u8PositionY);//  command for ddram to display data starting from address mentioned

	GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_High);   // High for Data
	LCD_enuWriteAndLatch(Copy_u8PatternNum);


	return Local_ErrorState;
}

ES_t LCD_enuDisplayFloatNum(fint32_t Copy_f32FloatNumber, uint8_t Copy_u8FractionDigits)
{
	ES_t Local_ErrorState = ES_NOK;
    // Check for negative number
    if (Copy_f32FloatNumber < 0) {
    	GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_High);   // High for Data
    	LCD_enuWriteAndLatch('-');
    	Copy_f32FloatNumber = -Copy_f32FloatNumber; // Make the number positive
    }

    // Extract integer part
    sint32_t Local_s32IntPart = (sint32_t)Copy_f32FloatNumber;
    uint32_t Local_u32Remainder;
    // Display the integer part
    if (Local_s32IntPart == 0) {
    	GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_High);   // High for Data
    	LCD_enuWriteAndLatch('0');
    } else {
    	uint32_t Local_u32ReverseNum = 0;
    	uint8_t Local_u8DigitsNum = 0;
    	for (; Local_s32IntPart > 0; Local_s32IntPart /= 10) //number reversing loop
    			{
    		Local_u32Remainder = Local_s32IntPart % 10;
    		Local_u32ReverseNum = Local_u32ReverseNum * 10 + Local_u32Remainder;
    		Local_u8DigitsNum++; //counting number of digits for the original number
    	}

    	for (; Local_u8DigitsNum > 0; Local_u32ReverseNum /= 10) //reversed number displaying loop
    			{ // for number of cycles equal to Local_u8DigitsNum , print digits

    		uint8_t Local_u8NumToPrint = Local_u32ReverseNum % 10;
    		GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_High); //high for data
    		LCD_enuWriteAndLatch(Local_u8NumToPrint + '0');
    		Local_u8DigitsNum--;
    	}
    }

    // Display decimal point and fractional part
	GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_High);   // High for Data
	LCD_enuWriteAndLatch('.');

    // Calculate the multiplier based on the number of fractional digits
    sint32_t Local_s32Multiplier = 1;
    for (uint8_t Local_u8Iterator = 0; Local_u8Iterator < Copy_u8FractionDigits; Local_u8Iterator++) {
    	Local_s32Multiplier *= 10;
    }

    sint32_t Local_s32FractionalPart = (sint32_t)(Copy_f32FloatNumber * Local_s32Multiplier) % Local_s32Multiplier;

	uint32_t Local_u32ReverseNum = 0;

	for (; Local_s32FractionalPart > 0; Local_s32FractionalPart /= 10) //number reversing loop
			{
		Local_u32Remainder = Local_s32FractionalPart % 10;
		Local_u32ReverseNum = Local_u32ReverseNum * 10 + Local_u32Remainder;
	}

	for (; Copy_u8FractionDigits > 0; Local_u32ReverseNum /= 10) //reversed number displaying loop
			{ // for number of cycles equal to Local_u8DigitsNum , print digits

		uint8_t Local_u8NumToPrint = Local_u32ReverseNum % 10;
		GPIO_enuSetPinValue(LCD_pstrConfigs->RS_Pin, GPIO_High); //high for data
		LCD_enuWriteAndLatch(Local_u8NumToPrint + '0');
		Copy_u8FractionDigits--;
	}


    return Local_ErrorState;
}


