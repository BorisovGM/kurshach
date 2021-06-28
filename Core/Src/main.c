/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim16;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM16_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void _PrintVD2(uint8_t num){
	if(num == 0){
		  HAL_GPIO_WritePin(VD2_A_GPIO_Port, VD2_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_B_GPIO_Port, VD2_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_C_GPIO_Port, VD2_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_D_GPIO_Port, VD2_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_E_GPIO_Port, VD2_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_F_GPIO_Port, VD2_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_G_GPIO_Port, VD2_G_Pin, GPIO_PIN_RESET);
	} else if(num == 1){
		  HAL_GPIO_WritePin(VD2_A_GPIO_Port, VD2_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_B_GPIO_Port, VD2_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_C_GPIO_Port, VD2_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_D_GPIO_Port, VD2_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_E_GPIO_Port, VD2_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_F_GPIO_Port, VD2_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_G_GPIO_Port, VD2_G_Pin, GPIO_PIN_RESET);
	} else if(num == 2){
		  HAL_GPIO_WritePin(VD2_A_GPIO_Port, VD2_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_B_GPIO_Port, VD2_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_C_GPIO_Port, VD2_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_D_GPIO_Port, VD2_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_E_GPIO_Port, VD2_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_F_GPIO_Port, VD2_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_G_GPIO_Port, VD2_G_Pin, GPIO_PIN_SET);
	} else if(num == 3){
		  HAL_GPIO_WritePin(VD2_A_GPIO_Port, VD2_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_B_GPIO_Port, VD2_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_C_GPIO_Port, VD2_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_D_GPIO_Port, VD2_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_E_GPIO_Port, VD2_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_F_GPIO_Port, VD2_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_G_GPIO_Port, VD2_G_Pin, GPIO_PIN_SET);
	} else if(num == 4){
		  HAL_GPIO_WritePin(VD2_A_GPIO_Port, VD2_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_B_GPIO_Port, VD2_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_C_GPIO_Port, VD2_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_D_GPIO_Port, VD2_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_E_GPIO_Port, VD2_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_F_GPIO_Port, VD2_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_G_GPIO_Port, VD2_G_Pin, GPIO_PIN_SET);
	} else if(num == 5){
		  HAL_GPIO_WritePin(VD2_A_GPIO_Port, VD2_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_B_GPIO_Port, VD2_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_C_GPIO_Port, VD2_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_D_GPIO_Port, VD2_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_E_GPIO_Port, VD2_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_F_GPIO_Port, VD2_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_G_GPIO_Port, VD2_G_Pin, GPIO_PIN_SET);
	} else if(num == 6){
		  HAL_GPIO_WritePin(VD2_A_GPIO_Port, VD2_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_B_GPIO_Port, VD2_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_C_GPIO_Port, VD2_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_D_GPIO_Port, VD2_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_E_GPIO_Port, VD2_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_F_GPIO_Port, VD2_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_G_GPIO_Port, VD2_G_Pin, GPIO_PIN_SET);
	} else if(num == 7){
		  HAL_GPIO_WritePin(VD2_A_GPIO_Port, VD2_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_B_GPIO_Port, VD2_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_C_GPIO_Port, VD2_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_D_GPIO_Port, VD2_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_E_GPIO_Port, VD2_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_F_GPIO_Port, VD2_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_G_GPIO_Port, VD2_G_Pin, GPIO_PIN_RESET);
	} else if(num == 8){
		  HAL_GPIO_WritePin(VD2_A_GPIO_Port, VD2_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_B_GPIO_Port, VD2_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_C_GPIO_Port, VD2_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_D_GPIO_Port, VD2_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_E_GPIO_Port, VD2_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_F_GPIO_Port, VD2_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_G_GPIO_Port, VD2_G_Pin, GPIO_PIN_SET);
	} else if(num == 9){
		  HAL_GPIO_WritePin(VD2_A_GPIO_Port, VD2_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_B_GPIO_Port, VD2_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_C_GPIO_Port, VD2_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_D_GPIO_Port, VD2_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_E_GPIO_Port, VD2_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD2_F_GPIO_Port, VD2_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD2_G_GPIO_Port, VD2_G_Pin, GPIO_PIN_SET);
	} else if(num == 10){
		  HAL_GPIO_WritePin(VD2_DP_GPIO_Port, VD2_DP_Pin, GPIO_PIN_SET);
	} else if(num == 11){
		  HAL_GPIO_WritePin(VD2_DP_GPIO_Port, VD2_DP_Pin, GPIO_PIN_RESET);
	} else if(num == 12){
		HAL_GPIO_TogglePin(VD2_DP_GPIO_Port, VD2_DP_Pin);
	}
}

void _PrintVD3(uint8_t num){
	if(num == 0){
		  HAL_GPIO_WritePin(VD3_A_GPIO_Port, VD3_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_B_GPIO_Port, VD3_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_C_GPIO_Port, VD3_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_D_GPIO_Port, VD3_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_E_GPIO_Port, VD3_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_F_GPIO_Port, VD3_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_G_GPIO_Port, VD3_G_Pin, GPIO_PIN_RESET);
	} else if(num == 1){
		  HAL_GPIO_WritePin(VD3_A_GPIO_Port, VD3_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_B_GPIO_Port, VD3_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_C_GPIO_Port, VD3_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_D_GPIO_Port, VD3_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_E_GPIO_Port, VD3_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_F_GPIO_Port, VD3_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_G_GPIO_Port, VD3_G_Pin, GPIO_PIN_RESET);
	} else if(num == 2){
		  HAL_GPIO_WritePin(VD3_A_GPIO_Port, VD3_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_B_GPIO_Port, VD3_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_C_GPIO_Port, VD3_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_D_GPIO_Port, VD3_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_E_GPIO_Port, VD3_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_F_GPIO_Port, VD3_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_G_GPIO_Port, VD3_G_Pin, GPIO_PIN_SET);
	} else if(num == 3){
		  HAL_GPIO_WritePin(VD3_A_GPIO_Port, VD3_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_B_GPIO_Port, VD3_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_C_GPIO_Port, VD3_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_D_GPIO_Port, VD3_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_E_GPIO_Port, VD3_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_F_GPIO_Port, VD3_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_G_GPIO_Port, VD3_G_Pin, GPIO_PIN_SET);
	} else if(num == 4){
		  HAL_GPIO_WritePin(VD3_A_GPIO_Port, VD3_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_B_GPIO_Port, VD3_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_C_GPIO_Port, VD3_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_D_GPIO_Port, VD3_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_E_GPIO_Port, VD3_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_F_GPIO_Port, VD3_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_G_GPIO_Port, VD3_G_Pin, GPIO_PIN_SET);
	} else if(num == 5){
		  HAL_GPIO_WritePin(VD3_A_GPIO_Port, VD3_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_B_GPIO_Port, VD3_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_C_GPIO_Port, VD3_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_D_GPIO_Port, VD3_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_E_GPIO_Port, VD3_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_F_GPIO_Port, VD3_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_G_GPIO_Port, VD3_G_Pin, GPIO_PIN_SET);
	} else if(num == 6){
		  HAL_GPIO_WritePin(VD3_A_GPIO_Port, VD3_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_B_GPIO_Port, VD3_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_C_GPIO_Port, VD3_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_D_GPIO_Port, VD3_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_E_GPIO_Port, VD3_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_F_GPIO_Port, VD3_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_G_GPIO_Port, VD3_G_Pin, GPIO_PIN_SET);
	} else if(num == 7){
		  HAL_GPIO_WritePin(VD3_A_GPIO_Port, VD3_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_B_GPIO_Port, VD3_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_C_GPIO_Port, VD3_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_D_GPIO_Port, VD3_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_E_GPIO_Port, VD3_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_F_GPIO_Port, VD3_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_G_GPIO_Port, VD3_G_Pin, GPIO_PIN_RESET);
	} else if(num == 8){
		  HAL_GPIO_WritePin(VD3_A_GPIO_Port, VD3_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_B_GPIO_Port, VD3_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_C_GPIO_Port, VD3_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_D_GPIO_Port, VD3_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_E_GPIO_Port, VD3_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_F_GPIO_Port, VD3_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_G_GPIO_Port, VD3_G_Pin, GPIO_PIN_SET);
	} else if(num == 9){
		  HAL_GPIO_WritePin(VD3_A_GPIO_Port, VD3_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_B_GPIO_Port, VD3_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_C_GPIO_Port, VD3_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_D_GPIO_Port, VD3_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_E_GPIO_Port, VD3_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(VD3_F_GPIO_Port, VD3_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(VD3_G_GPIO_Port, VD3_G_Pin, GPIO_PIN_SET);
	} else if(num == 10){
		  HAL_GPIO_WritePin(VD3_DP_GPIO_Port, VD3_DP_Pin, GPIO_PIN_SET);
	} else if(num == 11){
		  HAL_GPIO_WritePin(VD3_DP_GPIO_Port, VD3_DP_Pin, GPIO_PIN_RESET);
	} else if(num == 12){
		HAL_GPIO_TogglePin(VD3_DP_GPIO_Port, VD3_DP_Pin);
	}
}


uint8_t TimeCounter;
uint8_t flagstop = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(TimeCounter < 99){
		TimeCounter++;
		char str[64] = {0};
		sprintf(str, "timer: %d sec.\r\n", TimeCounter);
		HAL_UART_Transmit(&huart1, str, strlen(str), -1);
	} else {
		if(flagstop == 0){
			flagstop = 1;
		}
		_PrintVD3(12);
	}
	if(flagstop == 1){
		flagstop = 2;
		char str[64] = {0};
		sprintf(str, "timer: stop\r\n");
		HAL_UART_Transmit(&huart1, str, strlen(str), -1);
	}

}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_TIM16_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim16);
  HAL_GPIO_WritePin(VD2_GND_GPIO_Port, VD2_GND_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(VD3_GND_GPIO_Port, VD3_GND_Pin, GPIO_PIN_SET);


  TimeCounter=0;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  _PrintVD2(TimeCounter / 10);
	  _PrintVD3(TimeCounter % 10);



    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI48;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM16 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM16_Init(void)
{

  /* USER CODE BEGIN TIM16_Init 0 */

  /* USER CODE END TIM16_Init 0 */

  /* USER CODE BEGIN TIM16_Init 1 */

  /* USER CODE END TIM16_Init 1 */
  htim16.Instance = TIM16;
  htim16.Init.Prescaler = 48000-1;
  htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim16.Init.Period = 1000;
  htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim16.Init.RepetitionCounter = 0;
  htim16.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim16) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM16_Init 2 */

  /* USER CODE END TIM16_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, VD2_A_Pin|VD2_B_Pin|VD2_C_Pin|VD2_D_Pin
                          |VD2_E_Pin|VD2_F_Pin|VD2_G_Pin|VD2_DP_Pin
                          |VD2_GND_Pin|VD3_GND_Pin|VD3_DP_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, VD3_A_Pin|VD3_B_Pin|VD3_C_Pin|VD3_D_Pin
                          |VD3_E_Pin|VD3_F_Pin|VD3_G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : VD2_A_Pin VD2_B_Pin VD2_C_Pin VD2_D_Pin
                           VD2_E_Pin VD2_F_Pin VD2_G_Pin VD2_DP_Pin
                           VD2_GND_Pin VD3_GND_Pin VD3_DP_Pin */
  GPIO_InitStruct.Pin = VD2_A_Pin|VD2_B_Pin|VD2_C_Pin|VD2_D_Pin
                          |VD2_E_Pin|VD2_F_Pin|VD2_G_Pin|VD2_DP_Pin
                          |VD2_GND_Pin|VD3_GND_Pin|VD3_DP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : VD3_A_Pin VD3_B_Pin VD3_C_Pin VD3_D_Pin
                           VD3_E_Pin VD3_F_Pin VD3_G_Pin */
  GPIO_InitStruct.Pin = VD3_A_Pin|VD3_B_Pin|VD3_C_Pin|VD3_D_Pin
                          |VD3_E_Pin|VD3_F_Pin|VD3_G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
