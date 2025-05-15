/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : Sensor.h
  * @brief          : Header for Sensor.cpp file.
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
#ifndef _SENSOR_H_
#define _SENSOR_H_

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

extern AnalogIn LDR; //LDR pin

extern AnalogIn TMP; //TEMP Sensor pin

extern AnalogIn FSR; //Force sensor pin

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
bool Parameter_check();
/* Private defines -----------------------------------------------------------*/

#endif //_SENSOR_H_