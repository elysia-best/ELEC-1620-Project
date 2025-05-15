#include "utils/7Seg.h"
#include <cstdint>
#include <cstdlib>
#include "utils/LED.h"
#include "utils/MyUSBSerial.h"

DigitalOut seg1(PA_12);
DigitalOut seg2(PA_11);
DigitalOut seg3(PB_12);
DigitalOut seg4(PB_11);
DigitalOut seg5(PB_2);
DigitalOut seg6(PB_1);
DigitalOut seg7(PB_15);
DigitalOut seg8(PB_14);

int get_rand(int min, int max);


//segment       A       B     C      D    E     F      G        
BusOut SegDis(PA_11, PA_12, PB_1, PB_15, PB_14, PB_12, PB_11); //Add remaining pins in correct order
DigitalOut decimal_point(PB_2); //Add pin for the Decimal Point 

//               0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F    
int hexDis[] = {0x3F, 0x06, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0001111, 0b1111111, 0b1101111, 0b1110111, 0b1111100, 0b0111001, 0b1011110, 0b1111001, 0b1110001}; // Add the rest of the hex values associated with the dispplay items 0-F

void SegDis_init() {
    SegDis.write(0x00); //turn off the display by setting all segments to '0'
    decimal_point.write(0);
    ThisThread::sleep_for(200ms);
}

/**
 * @brief Count Down module. Here for convenience, 1min = 100ms.
 */
void count_down(uint8_t time_min) {
    srand(time(0));
    Status_LED.write(0b111); // Indicate for running.
    for (int8_t i = time_min; i >=0; i-=10 ) {
        printf("[ info ]: Time remaining: %d mins\n", i);
        SegDis.write(hexDis[i/10]);

        Multi_Green_LED.write(get_rand(0, 100)/100.);
        Multi_Blue_Led.write(get_rand(0, 100)/100.);
        Multi_Red_LED.write(get_rand(0, 100)/100.);

        ThisThread::sleep_for(1000ms);
    }
    SegDis.write(0);
    Multi_Green_LED.write(0);
    Multi_Blue_Led.write(0);
    Multi_Red_LED.write(0);
    Status_LED.write(0);
    USB_send_info("Washing Finished! (*^_^*)");
}

int get_rand(int min, int max) {
    return ( rand() % (max - min + 1) ) + min ;
}