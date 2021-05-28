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
#include "stm32h7xx_hal.h"

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
#define VSYNC_Pin GPIO_PIN_0
#define VSYNC_GPIO_Port GPIOA
#define VSYNC_EXTI_IRQn EXTI0_IRQn
#define SCL_Pin GPIO_PIN_0
#define SCL_GPIO_Port GPIOB
#define SDA_Pin GPIO_PIN_1
#define SDA_GPIO_Port GPIOB
#define RCLK_Pin GPIO_PIN_2
#define RCLK_GPIO_Port GPIOB
#define D0_Pin GPIO_PIN_0
#define D0_GPIO_Port GPIOD
#define D1_Pin GPIO_PIN_1
#define D1_GPIO_Port GPIOD
#define D2_Pin GPIO_PIN_2
#define D2_GPIO_Port GPIOD
#define D3_Pin GPIO_PIN_3
#define D3_GPIO_Port GPIOD
#define D4_Pin GPIO_PIN_4
#define D4_GPIO_Port GPIOD
#define D5_Pin GPIO_PIN_5
#define D5_GPIO_Port GPIOD
#define D6_Pin GPIO_PIN_6
#define D6_GPIO_Port GPIOD
#define D7_Pin GPIO_PIN_7
#define D7_GPIO_Port GPIOD
#define WEN_Pin GPIO_PIN_5
#define WEN_GPIO_Port GPIOB
#define WRST_Pin GPIO_PIN_6
#define WRST_GPIO_Port GPIOB
#define RRST_Pin GPIO_PIN_7
#define RRST_GPIO_Port GPIOB
#define OE_Pin GPIO_PIN_8
#define OE_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
