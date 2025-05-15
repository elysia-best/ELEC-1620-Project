#include "utils/Buzzer.h"
#include <cstdint>
#include <stdint.h>

PwmOut Buzzer(PA_15);


/**
  * @brief  Play a music when power on.
  * @retval None
  */
void Buzzer_power_on_notes() {
    uint16_t notes [] = {NOTE_G3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_A3, NOTE_A3, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_D4, NOTE_B3, NOTE_CS4, NOTE_CS4};
    Buzzer_play_note_list(notes, 16);
}

/**
  * @brief  Function to play a note.
  * @retval None
  */
void Buzzer_play_note(int frequency) {
    Buzzer.period_us((float) 1000000.0f/ (float) frequency);    //set the period of the pwm signal (in us)
    Buzzer.pulsewidth_us(Buzzer.read_period_us()/2);            //set pulse width of the pwm to 1/2 the period
    ThisThread::sleep_for(300ms);                               //play sound for 500ms
}

/**
  * @brief  function to play a list of notes.
  * @retval None
  */
void Buzzer_play_note_list(uint16_t * notes, uint8_t length) {
    for(uint8_t i = 0; i < length; ++i) {
        Buzzer_play_note(notes[i]);
    }
    Buzzer.pulsewidth_us(0);            //turn off buzzer
}

