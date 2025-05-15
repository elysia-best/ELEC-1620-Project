#ifndef _BUZZER_H_
#define _BUZZER_H_

#include "main.h"
#include "utils/BuzzerNotes.h"

extern PwmOut Buzzer;

void Buzzer_play_note(int frequency);
void Buzzer_play_note_list(uint16_t * notes, uint8_t length);
void Buzzer_power_on_notes();

#endif