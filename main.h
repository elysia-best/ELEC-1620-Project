/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.cpp file.
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
#ifndef _MAIN_H_
#define _MAIN_H_

/* Includes ------------------------------------------------------------------*/
#include "mbed.h"
#include "rtos.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
extern uint8_t Running_Time;
extern uint8_t Water_Temperature;
extern bool lid_closed;
/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/

/* Private defines -----------------------------------------------------------*/

#endif //_MAIN_H_