#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "main.h"

extern DigitalIn Power_Button;
extern DigitalIn Button_1;
extern DigitalIn Button_2;
extern DigitalIn Button_3;

extern bool bt1_pressed;
extern bool bt2_pressed;
extern bool bt3_pressed;
extern bool bt0_pressed;

void Button_Init();

void Detect_Pressed_Buttons();

uint8_t Mode_selection();

#endif //_BUTTON_H_