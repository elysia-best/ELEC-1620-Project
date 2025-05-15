#include "utils/MyUSBSerial.h"

BufferedSerial pc(USBTX, USBRX, 115200); // establish serial communications between PC and NUCLEO

/**
  * @brief  Sending msg when power on.
  * @retval None
  */
void USB_send_welcome_msg() {
    printf("/*******************************************/\n");
    printf("/****** Washing Machine Control Panel ******/\n");
    printf("/************* Serial Console **************/\n");
    USB_send_info("Initializing peripherals ...");
}

void USB_send_info(char * infos) {
    printf("[ info ]: %s\n", infos);
}