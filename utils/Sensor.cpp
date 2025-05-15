/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : Sensor.cpp
  * @brief          : Sensor related functions
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
#include "utils/Sensor.h"
#include <cstdint>
#include <stdint.h>
#include <math.h>

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
AnalogIn LDR(PC_2); // LDR pin

AnalogIn TMP(PC_3); // TEMP Sensor pin

AnalogIn FSR(PA_1); // Force sensor pin

/* Private variables ---------------------------------------------------------*/
auto TMP_25 = 6497;
// When lid closed, LDR < 5 digits.
// When no cloth in the machine, FSR is 3 digits.
uint16_t TMP_val;
uint16_t LDR_val;
uint16_t FSR_val;
/* Private function prototypes -----------------------------------------------*/


/* Private user code ---------------------------------------------------------*/
//Get the value of sensors.
void get_sensor_values() {
    TMP_val = TMP.read_u16();
    LDR_val = LDR.read_u16();
    FSR_val = FSR.read_u16();
}

// Check the paramater before washing.
bool Parameter_check() {
    get_sensor_values();
    if (FSR_val <= 350) {
        printf("[ erro ]: Error! No clothes in the machine!\n");
        return 0;
    }

    if (LDR_val > 15000) {
        printf("[ erro ]: Error! The lid is not closed!\n");
        return 0;
    }

    if (Water_Temperature == 25) {
        if (abs(TMP_val - TMP_25) <= 3000.) {
            ;
        } else {
            printf("[ erro ]: Error! The water temp is not correct!\n");
            return 0;
        }
    } else {
        if (abs(TMP_val - TMP_25) <= 3000.) {
            printf("[ erro ]: Error! The water temp is not correct!\n");
            return 0;
        }
    }
    return 1;
} 

