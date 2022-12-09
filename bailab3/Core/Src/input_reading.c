
#include "main.h"
#include "input_reading.h"
#include "global.h"

#define N0_OF_BUTTONS 				       3
#define DURATION_FOR_AUTO_INCREASING	   1000/TIMER_CYCLE
#define DURATION_FOR_AUTO_COUNT_UP		   500/TIMER_CYCLE
#define BUTTON_IS_PRESSED                  GPIO_PIN_RESET
#define BUTTON_IS_RELEASED                 GPIO_PIN_SET
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];
static uint16_t counterAutoCountUp[N0_OF_BUTTONS];
uint8_t flagForAutoCountUp[N0_OF_BUTTONS];
void button_reading(void){
	for(char i = 0; i < N0_OF_BUTTONS; i ++){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[0] = HAL_GPIO_ReadPin(BUTTON0_GPIO_Port, BUTTON0_Pin);
		debounceButtonBuffer1[1] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
		debounceButtonBuffer1[2] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){
			buttonBuffer[i] = debounceButtonBuffer1[i];
		}
			if(buttonBuffer[i] == BUTTON_IS_PRESSED){
				if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING){
					counterForButtonPress1s[i]++;
				}
				else {
					flagForButtonPress1s[i] = 1;
					counterAutoCountUp[i]++;
					if(counterAutoCountUp[i] >= DURATION_FOR_AUTO_COUNT_UP){
						flagForAutoCountUp[i] = 1;
						counterAutoCountUp[i] = 0;
					}
				}
			} else {
				counterForButtonPress1s[i] = 0;
				counterAutoCountUp[i] = 0;
				flagForButtonPress1s[i] = 0;
				flagForAutoCountUp[i] = 0;
			}
	}
}
unsigned char is_button_pressed(unsigned char index){
	if(index >= N0_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}
unsigned char is_button_pressed_1s(unsigned char index){
	//if(index >= N0_OF_BUTTONS) return 0xff;
	//return (flagForButtonPress1s[index] == 1);
	return 0;
}


