
#include "input_processing.h"
#include "main.h"
#include "input_reading.h"
#include "global.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND} ;

enum ButtonState button0State = BUTTON_RELEASED;
void fsm_for_button0( void ){
	switch(button0State){
		case BUTTON_RELEASED:
			if(is_button_pressed(0)){
				timeDuration = 1;
				timer0_flag = 1;
				timer1_flag = 1;
				//timer2_flag = 1;
				mainState++;
				if(mainState > 4) {
					mainState = 1;
					trafficLightState0 = 0;
					trafficLightState1 = 2;
					count0 = timeRed;
					count1 = timeGreen;
				}
				button0State = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(0)){
				button0State = BUTTON_RELEASED;
			}
			break;
		default:
			break;
	}
}

enum ButtonState button1State = BUTTON_RELEASED;
void fsm_for_button1( void ) {
	switch(button1State){
		case BUTTON_RELEASED:
			if(is_button_pressed(1)){
				timeDuration++;
				if (timeDuration > 99) timeDuration = 1;
				button1State = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED:
			if(!is_button_pressed(1)){
				button1State = BUTTON_RELEASED;
			}
			else {
				if(is_button_pressed_1s(1)){
					button1State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if(!is_button_pressed(1)){
				button1State = BUTTON_RELEASED;
			}
			else{
				if(flagForAutoCountUp[1] == 1){
					timeDuration++;
					if (timeDuration > 99) timeDuration = 1;
					flagForAutoCountUp[1] = 0;
					button1State = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		default:
			break;
	}
}

enum ButtonState button2State = BUTTON_RELEASED;
void fsm_for_button2(){
		switch(button2State){
			case BUTTON_RELEASED:
				if(is_button_pressed(2)){
					switch(mainState){
						case 1:
							break;
						case 2:
							timeRed = timeDuration;
							break;
						case 3:
							timeYellow = timeDuration;
							break;
						case 4:
							timeGreen = timeDuration;
							break;
						default:
							break;
					}
					button2State = BUTTON_PRESSED;
				}
				break;
			case BUTTON_PRESSED:
				if(!is_button_pressed(2)){
					button2State = BUTTON_RELEASED;
				}
				break;
			default:
				break;
		}
}

