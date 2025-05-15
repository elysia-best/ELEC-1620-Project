#include "utils/Potentialmeter.h"
#include <cstdint>

uint16_t PotMaxValue = (2 << 15) - 1;

AnalogIn pot1(PA_5);
AnalogIn pot2(PA_6);
AnalogIn pot3(PA_7);

uint16_t get_raw_value_of_pot(AnalogIn &potx) {
    return potx.read_u16();
}

/**
  * @brief  Function to change params based on the pots.
  * @retval None
  */
void set_value_of_params() {
    auto temp_raw = get_raw_value_of_pot(pot2);
    auto Time_raw = get_raw_value_of_pot(pot1);
    
    /**
     * Temprature have two settings: normal temp(1) and warm water(0).
     * Time have 3 options: 30min 60min 90min
     */
    uint8_t tmp_Running_Time;
    uint8_t temp_Water_Temperature;
    
    if (temp_raw / 32768) 
        temp_Water_Temperature = 40;
    else
        temp_Water_Temperature = 25;

    if (Time_raw / 43690) 
        tmp_Running_Time = 90;
    else if (Time_raw / 21845)
        tmp_Running_Time = 60;
    else
        tmp_Running_Time = 30;

    if (tmp_Running_Time != Running_Time) 
        printf("[ info ]: Running time changed to %d mins!\n", tmp_Running_Time);

    if (temp_Water_Temperature != Water_Temperature) 
        printf("[ info ]: Water Temperature changed to %d ℃!\n", temp_Water_Temperature);
    Running_Time = tmp_Running_Time;
    Water_Temperature = temp_Water_Temperature;
}