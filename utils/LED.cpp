/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : LED.cpp
  * @brief          : LED related functions
  ******************************************************************************
  * @attention
  *
  * Copyright (c) Yuanzhen Gan, SWJTU-Leeds Joint School.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "utils/LED.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
float frequency = 100;  //Create frequency variable to set PWM frequencies to 100 Hz

/* Private variables ---------------------------------------------------------*/
DigitalOut Power_LED(PC_0);
BusOut Status_LED(PC_1, PB_0, PA_4);

PwmOut Multi_Red_LED(PB_3);
PwmOut Multi_Green_LED(PB_4);
PwmOut Multi_Blue_Led(PB_5);
/* Private function prototypes -----------------------------------------------*/


/* Private user code ---------------------------------------------------------*/
/**
  * @brief  LEDs init function.
  * @retval None
  */
void LEDS_Init() {
    Multi_Green_LED.write(0);
    Multi_Blue_Led.write(0);
    Multi_Red_LED.write(0);
    Status_LED.write(0);
    Power_LED.write(1);

    Multi_Red_LED.period(1/frequency);        //set the period of the wave form as 1/100Hz
    Multi_Green_LED.period(1/frequency); 
    Multi_Blue_Led.period(1/frequency); 
}