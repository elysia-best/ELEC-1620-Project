#ifndef _7SEG_H_
#define _7SEG_H_

#include "main.h"

extern DigitalOut seg1;
extern DigitalOut seg2;
extern DigitalOut seg3;
extern DigitalOut seg4;
extern DigitalOut seg5;
extern DigitalOut seg6;
extern DigitalOut seg7;
extern DigitalOut seg8;

extern BusOut SegDis;
extern DigitalOut decimal_point;

extern int hexDis[];

void SegDis_init();

void count_down(uint8_t time_min);

#endif