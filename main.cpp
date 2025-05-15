/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.cpp
  * @brief          : Main program body
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
#include <cstdio>
#include <iostream>

#include "utils/Button.h"
#include "utils/LED.h"
#include "utils/Sensor.h"
#include "utils/Buzzer.h"
#include "utils/7Seg.h"
#include "utils/MyUSBSerial.h"
#include "utils/Potentialmeter.h"


/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define WAIT_TIME_MS 100

/* Private variables ---------------------------------------------------------*/

int power_mode = 1; // 1 for on, 0 for off.
uint8_t selected_mode = 0; 
uint8_t Water_Temperature = 25;
uint8_t Running_Time = 30;
bool lid_closed = 0;
/* Private function prototypes -----------------------------------------------*/

void User_Init();

void power_off();

void select_modes_thread();

void start_washing();

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  The application entry point.
  * @retval int
  */
int main() {
    User_Init();

    while (true) {
        //Detecting Keys
        Detect_Pressed_Buttons();

        if (bt0_pressed) {
            power_off();
        }

        select_modes_thread();

        set_value_of_params();

        if (bt3_pressed) {    
            start_washing();
        }

    }
}

/**
  * @brief  System init function.
  * @retval None
  */
void User_Init() {
    USB_send_welcome_msg();
    Buzzer_power_on_notes();
    LEDS_Init();
    Button_Init();
    SegDis.write(0);
    power_mode = true;
    USB_send_info("Start-up finished!");
}


/**
  * @brief  System power-off function.
  * @retval None
  */
void power_off() {
    if (power_mode) {
        bt0_pressed = false; // Reset the state of the power key.
        USB_send_info("Powering off ...");
        Buzzer.pulsewidth_us(0);            // Turn off buzzer

        Multi_Green_LED.write(0); // Trun off LEDs.
        Multi_Blue_Led.write(0);
        Multi_Red_LED.write(0);
        Status_LED.write(0);
        Power_LED.write(0);
        power_mode = false;
        ThisThread::sleep_for(500ms);

        while (!bt0_pressed) {
            Detect_Pressed_Buttons();
        }
        User_Init();
    }
}

/**
  * @brief  Washing mode seleting function.
  * @retval None
  */
void select_modes_thread() {

    auto tmp_selected_mode = Mode_selection();
    if (tmp_selected_mode) {
        switch(tmp_selected_mode) {
                case 1:
                    USB_send_info("Selected Normal Mode.");
                    ThisThread::sleep_for(300ms);
                    Status_LED.write(0b100);
                    selected_mode = tmp_selected_mode;
                    break;
                case 2:
                    USB_send_info("Selected Strong Mode.");
                    ThisThread::sleep_for(300ms);
                    Status_LED.write(0b010);
                    selected_mode = tmp_selected_mode;
                    break;
            }
    }
    
}

/**
  * @brief  start washing function.
  * @retval None
  */
void start_washing() {
    if(Parameter_check()) {
        USB_send_info("Start washing! Params are listed below!");
        printf("[ info ]: Water temprature: %d\n", Water_Temperature);
        printf("[ info ]: Running time: %d minutes\n", Running_Time);
        switch(selected_mode) {
            case 1:
                printf("[ info ]: Washing mode: normal mode.\n");
                break;
            case 2:
                printf("[ info ]: Washing mode: normal mode.\n");
                break;
            default:
                printf("[ erro ]: Error! Washing mode not selected!\n");
                ThisThread::sleep_for(500ms);
                return;
        }
        count_down(Running_Time);
    } else {
        ThisThread::sleep_for(500ms);
    }
}
