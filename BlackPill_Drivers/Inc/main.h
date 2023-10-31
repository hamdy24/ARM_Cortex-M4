/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/************************************ Includes Start *************************************************/
/************************************ Includes END  *************************************************/

#include "../STM32F401_Drivers/Common/CommonMacros.h"
#include "../STM32F401_Drivers/Common/ErrorState.h"
#include "../STM32F401_Drivers/Common/STD_Types.h"

#include "../STM32F401_Drivers/MCAL/Cortex_M4/CortexM4_REG.h"
#include "../STM32F401_Drivers/MCAL/STM32F401_REG.h"

#include <../STM32F401_Drivers/MCAL/RCC/RCC_Interface.h>
#include <../STM32F401_Drivers/MCAL/GPIO/GPIO_Interface.h>
#include "../STM32F401_Drivers/MCAL/EXTI/EXTI_Interface.h"
#include "../STM32F401_Drivers/MCAL/SYSCFG/SYSCFG_Interface.h"

#include <../STM32F401_Drivers/MCAL/Cortex_M4/NVIC/NVIC_interface.h>
#include <../STM32F401_Drivers/MCAL/Cortex_M4/SysTick/SysTick_Interface.h>
#include <../STM32F401_Drivers/MCAL/Cortex_M4/SCB/SCB_interface.h>


#include "../STM32F401_Drivers/HAL/LCD/LCD_Interface.h"



/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
