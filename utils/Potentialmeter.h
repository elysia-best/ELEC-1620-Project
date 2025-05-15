#ifndef _Potentialmeter_H_
#define _Potentialmeter_H_

#include "main.h"
extern uint16_t PotMaxValue;
extern AnalogIn pot1;
extern AnalogIn pot2;
extern AnalogIn pot3;

uint16_t get_raw_value_of_pot(AnalogIn &potx);
void set_value_of_params();

#endif