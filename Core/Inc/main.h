/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

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
#define VD2_A_Pin GPIO_PIN_0
#define VD2_A_GPIO_Port GPIOA
#define VD2_B_Pin GPIO_PIN_1
#define VD2_B_GPIO_Port GPIOA
#define VD2_C_Pin GPIO_PIN_2
#define VD2_C_GPIO_Port GPIOA
#define VD2_D_Pin GPIO_PIN_3
#define VD2_D_GPIO_Port GPIOA
#define VD2_E_Pin GPIO_PIN_4
#define VD2_E_GPIO_Port GPIOA
#define VD2_F_Pin GPIO_PIN_5
#define VD2_F_GPIO_Port GPIOA
#define VD2_G_Pin GPIO_PIN_6
#define VD2_G_GPIO_Port GPIOA
#define VD2_DP_Pin GPIO_PIN_7
#define VD2_DP_GPIO_Port GPIOA
#define VD3_A_Pin GPIO_PIN_0
#define VD3_A_GPIO_Port GPIOB
#define VD3_B_Pin GPIO_PIN_1
#define VD3_B_GPIO_Port GPIOB
#define VD2_GND_Pin GPIO_PIN_8
#define VD2_GND_GPIO_Port GPIOA
#define VD3_GND_Pin GPIO_PIN_11
#define VD3_GND_GPIO_Port GPIOA
#define VD3_DP_Pin GPIO_PIN_12
#define VD3_DP_GPIO_Port GPIOA
#define VD3_C_Pin GPIO_PIN_3
#define VD3_C_GPIO_Port GPIOB
#define VD3_D_Pin GPIO_PIN_4
#define VD3_D_GPIO_Port GPIOB
#define VD3_E_Pin GPIO_PIN_5
#define VD3_E_GPIO_Port GPIOB
#define VD3_F_Pin GPIO_PIN_6
#define VD3_F_GPIO_Port GPIOB
#define VD3_G_Pin GPIO_PIN_7
#define VD3_G_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
