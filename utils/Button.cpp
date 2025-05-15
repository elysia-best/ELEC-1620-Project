#include "utils/Button.h"
#include <cstdint>

DigitalIn Power_Button(PC_13);
DigitalIn Button_1(PC_10);
DigitalIn Button_2(PC_11);
DigitalIn Button_3(PD_2);

bool bt1_pressed = false;
bool bt2_pressed = false;
bool bt3_pressed = false;
bool bt0_pressed = false;

void Button_Init() {
    /* Turn off internal pull up / pull down resistors **/
    Power_Button.mode(PullUp);
    Button_1.mode(PullNone);
    Button_2.mode(PullNone);
    Button_3.mode(PullNone);
}

/**
  * @brief  Button detection.
  * @retval None
  */
void Detect_Pressed_Buttons() {

    if (Power_Button.read())
        bt0_pressed = false;
    else
        bt0_pressed = true;

    if (Button_1.read())
        bt1_pressed = true;
    else
        bt1_pressed = false;

    if (Button_2.read()) 
        bt2_pressed = true;
    else
        bt2_pressed = false;

    if (Button_3.read()) 
        bt3_pressed = true;
    else
        bt3_pressed = false;
}

uint8_t Mode_selection() {
    if ((bt1_pressed && !bt2_pressed) && ! bt3_pressed)
        return 1;

    if ((bt2_pressed && !bt1_pressed) && ! bt3_pressed)
        return 2;

    return 0;
}
