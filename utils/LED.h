/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : LED.h
  * @brief          : Header for LED.cpp file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Yuanzhen Gan.
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
#ifndef _LED_H_
#define _LED_H_

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
extern DigitalOut Power_LED;
extern BusOut Status_LED;

extern PwmOut Multi_Red_LED;
extern PwmOut Multi_Green_LED;
extern PwmOut Multi_Blue_Led;
/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void LEDS_Init();
/* Private defines -----------------------------------------------------------*/

#endif //_LED_H_