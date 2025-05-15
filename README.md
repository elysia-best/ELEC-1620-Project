# ELEC 1620 Unit4 Individual Project

## Warning!

This is a PRIVATE work, just uploaded here for my convinence. You must NOT present this work, in whole or in part, as your own. Work means any intellectual output, and typically includes text, data, images, designs, sound and performance in this project. 
Otherwise, you are at risk of PLAGIARISM!

Meanwile, this software is provided “as is”, without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. 

## 1b) Breadboard Layout:

![IMG_0084 - labelled](https://github.com/user-attachments/assets/ace0f8ac-4e42-48e9-8931-af92b9081d88)

## 1a) Project Brief:
On/off function: The On/Off status of the washing machine panel is controlled by the on-board button B1, which is connected to PC13 internally. Also, a red LED is used to indicate the On/Off status. When the LED is on, the panel is switched on with all the designed functions enabled. Conversely, when the LED is off, the panel is totally switched off.

Serial communication function: The on-board USB port is connected to the UART pins of the MCU internally, making the control panel able to communicate with the PC. Thus, the status of the panel can be monitored and altered via the serial console.

Power status function: The red LED on the top right corner is used to indicate the power status of the control panel. When the LED is on, the panel is powered on. On the contrary, when the LED is off, the panel is switched off.

Mode status function: The green LEDs on the top right corner is used to indicate the current selected mode on the control panel. Different arrange of LEDs represents different modes.

Running status function: The multi-colored LED is used to indicate the various states of the control panel. For example, running/stop of the machine, errors from the sensors, etc.

Noticing function: The buzzer on the right bottom corner is used to inform users with important events, such as power on/off, start/finish jobs, errors, etc.

Parameter monitoring function: The three sensors on the bottom are connected with the panel to monitor the status of the washing machine. Light sensor monitors the close/open of the lid of the machine. Temperature sensor monitors the temperature the water in the machine. Force sensor is used to check whether there are clothes in the washing machine.

Mode selecting function: The three buttons on the left are used to select different washing cycles.

Parameter adjusting functions: The three blue potentiometers are used to modify some parameters of the washing machine. For example, water temperature, speed, etc.

## 2a) Function descriptions
On/off function: The on/off function has been designed using an if statement and a while loop. It uses a button to control the on/off and uses a red led (‘Power_LED ‘, pin PC_0) to show the status. If the led is on, the control panel is enabled. Conversely, when the red led is off, the panel is disabled.
Serial communication function: The serial communication function is achieved by the Mbed OS’s library. It is connected to the USBTX and USBRX ports to send and receive messages from PCs. 
Status display function: The four LEDs are used to display the status of the panel. The RED LED is the Power LED. The remaining three green LEDs (‘Status_LED’,PC_1, PB_0, PA_4) show the selected washing modes. When the first LED is on, the normal mode is selected. Similarly, when the second LED is on, the strong mode will be selected. When all the three LEDs are on, the washing machine is currently washing clothes. Additionaly, the multi-colored LED(Multi_Red_LED(PB_3), Multi_Green_LED(PB_4), Multi_Blue_Led(PB_5);) will also be lighted to indicate the washing process.

Noticing function: The Buzzer is connected to PA_15. It will play a music to notice the user that the panel is on and ready to be operated. The buzzer is controlled using a PwmOut object, and notes are played at different frequencies by changing the period of a PWM signal. 

Parameter monitoring function: This is achived by three if statements and two if-else statements. There are there sensors (LDR(PC_2), TMP(PC_3), FSR(PA_1)), and the functions use the AnalogIn objects to read analog values from the sensors and store them in variables.

Mode selecting function: The two buttons (Button_1(PC_10), Button_2(PC_11)) are used to select the different two modes. It uses several if statements to judge which button is pressed. When Button_1 is pressed, normal mode will be selected. Similarly, when Button_2 is pressed, strong mode will be seleted.

Parameter adjusting functions: The three blue potentiometers (pot1(PA_5), pot2(PA_6), pot3(PA_7)) are used to modify water temperature and running time of the washing machine using some if statements

Washing function: The third button (Button_3(PD_2)) is used to start the washing. The 7SegDisplay (SegDis(PA_11, PA_12, PB_1, PB_15, PB_14, PB_12, PB_11)) will display the remaining time.  

## 2b) Limitations
There are several limitations in my designs. Firstly, all the functions are excecuted in a signle process, which means that users can only use one function at a time. Seconedly, when the machine is washing, it cannot be stoped or canceled. Finally, the values of the sensors are unstable, making the condition checking unreliable.

## 2c) Flow diagrams

![11](https://github.com/user-attachments/assets/35b738ea-204e-45cc-8274-3d45f711cff2)

![12](https://github.com/user-attachments/assets/a4fef675-c8a4-452f-9ae7-b14fb54e4483)

![13](https://github.com/user-attachments/assets/1987dafa-3ced-4b52-bb98-201931bbaa92)

