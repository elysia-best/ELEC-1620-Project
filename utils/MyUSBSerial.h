#ifndef _USBSERIAL_H_
#define _USBSERIAL_H_

#include "main.h"

extern BufferedSerial pc; //establish serial communications between PC and NUCLEO

/**
  * @brief  Sending msgs when powered on.
  * @retval None
  */
void USB_send_welcome_msg();
void USB_send_info(char * infos);
#endif