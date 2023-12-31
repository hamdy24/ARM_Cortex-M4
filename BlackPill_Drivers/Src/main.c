/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 */

#include <stdint.h>

#include "main.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "../STM32F401_Drivers/MCAL/RCC/RCC_Interface.h"


void SoftDelay_MS(uint32_t time);


//void Test1_AppCall(void);
//void Test2_AppCall(void);
//void Test3_AppCall(void);

int main(void)
{


	RCC_enuClocksInit(&CLK);


	return 0;
}

/*
int main(void)
{


	RCC_enuOscilatorInit(&OSC);
	RCC_enuClocksInit(&CLK);

// for black pill clk = 500000 and don't use ahb pres
	STK_strConfigs.STK_AHB_ClockValue = 500000;
	STK_strConfigs.STK_AHB_Prescaler = RCC_AHB_PRES_2;
	STK_strConfigs.STK_Prescaler = STK_Pres_1;

	STK_enuInit(&STK_strConfigs);



	EXTI_enuInit(EXTI_Configs);

//	EXTI_enuSetCallBack(EXTI_Line0, Test1_AppCall);
//	EXTI_enuSetCallBack(EXTI_Line1, Test2_AppCall);
//	EXTI_enuSetCallBack(EXTI_Line4, Test3_AppCall);

//	SYSCFG_enuEXTI_PortSelect(SysConfigEXTI_0, SysConfigPort_A);
//	SYSCFG_enuEXTI_PortSelect(SysConfigEXTI_1, SysConfigPort_B);
//	SYSCFG_enuEXTI_PortSelect(SysConfigEXTI_4, SysConfigPort_B);

	RCC_enuSetTargetClockState(RCC_GPIOA, true);
	RCC_enuSetTargetClockState(RCC_GPIOB, true);
	RCC_enuSetTargetClockState(RCC_GPIOC, true);
	RCC_enuSetTargetClockState(RCC_SYSCFG, true);



	GPIO_enuSetPinMode(GPIO_PA0, GPIO_Input);
	GPIO_enuSetPinMode(GPIO_PB1, GPIO_Input);
	GPIO_enuSetPinMode(GPIO_PB4, GPIO_Input);

	GPIO_enuSetPinType(GPIO_PA0, GPIO_OUT_PushPull);
	GPIO_enuSetPinType(GPIO_PB1, GPIO_OUT_PushPull);
	GPIO_enuSetPinType(GPIO_PB4, GPIO_OUT_PushPull);

	GPIO_enuSetPinPull(GPIO_PA0, GPIO_NoPull);
	GPIO_enuSetPinPull(GPIO_PB1, GPIO_NoPull);
	GPIO_enuSetPinPull(GPIO_PB4, GPIO_NoPull);



	GPIO_enuSetPinMode(GPIO_PC13, GPIO_General);
	GPIO_enuSetPinMode(GPIO_PC14, GPIO_General);
	GPIO_enuSetPinMode(GPIO_PC15, GPIO_General);

	GPIO_enuSetPinType(GPIO_PC13, GPIO_OUT_PushPull);
	GPIO_enuSetPinType(GPIO_PC14, GPIO_OUT_PushPull);
	GPIO_enuSetPinType(GPIO_PC15, GPIO_OUT_PushPull);


	GPIO_enuSetPinPull(GPIO_PC13, GPIO_NoPull);
	GPIO_enuSetPinPull(GPIO_PC14, GPIO_NoPull);
	GPIO_enuSetPinPull(GPIO_PC15, GPIO_NoPull);


	GPIO_enuSetPinSpeed(GPIO_PC13, GPIO_LowSpeed);

	SCB_SetPriorityGrouping(SCB_Priority_16Group_0Sub);

	NVIC_enuEnableIRQ(IRQ_EXTI0);
	NVIC_enuEnableIRQ(IRQ_EXTI1);
	NVIC_enuEnableIRQ(IRQ_EXTI4);

	NVIC_enuSetIRQnPriority(IRQ_EXTI0, 2);
	NVIC_enuSetIRQnPriority(IRQ_EXTI1, 1);
	NVIC_enuSetIRQnPriority(IRQ_EXTI4, 0);






	LCD_enuInit(&LCD_Configs);



//	EXTI_enuTriggerInterrupt_SW(EXTI_Line0|EXTI_Line1|EXTI_Line4);

//		LCD_enuSendString("Google");

	while(1){

		LCD_enuSendData('G');
	}

}
//
//void Test1_AppCall(void){
//
////	EXTI_enuTriggerInterrupt_SW(EXTI_Line1);
////	EXTI_enuTriggerInterrupt_SW(EXTI_Line4);
//
//	GPIO_enuSetPinValue(GPIO_PC13,GPIO_High);
//	SoftDelay_MS(1000);
//	GPIO_enuSetPinValue(GPIO_PC13,GPIO_Low);
//	SoftDelay_MS(1000);
//
//}
//
//void Test2_AppCall(void){
//
//	GPIO_enuSetPinValue(GPIO_PC14,GPIO_High);
//	SoftDelay_MS(1000);
//	GPIO_enuSetPinValue(GPIO_PC14,GPIO_Low);
//	SoftDelay_MS(1000);
//}
//
//
//
//
//void Test3_AppCall(void){
//
//	GPIO_enuSetPinValue(GPIO_PC15,GPIO_High);
//	SoftDelay_MS(40);
//	GPIO_enuSetPinValue(GPIO_PC15,GPIO_Low);
//	SoftDelay_MS(40);
//
//}
//




void SoftDelay_MS(uint32_t time){

	for (int Local_Iterator1 = 0; Local_Iterator1 < time*1.3; ++Local_Iterator1) {
		for (int Local_Iterator2 = 0; Local_Iterator2 < time; ++Local_Iterator2) {
			__asm("NOP");
		}
	}



}

*/
