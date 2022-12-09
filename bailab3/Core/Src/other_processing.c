
#include "input_processing.h"
#include "global.h"
#include "main.h"

void fsm_blinking_led (void){
	switch(mainState){
		case 1:
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, LEDY0_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LEDG0_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LEDY1_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LEDG1_Pin,GPIO_PIN_SET);
			HAL_GPIO_TogglePin(GPIOA, LEDR0_Pin);
			HAL_GPIO_TogglePin(GPIOA, LEDR1_Pin);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, LEDR0_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LEDG0_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LEDR1_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LEDG1_Pin,GPIO_PIN_SET);
			HAL_GPIO_TogglePin(GPIOA, LEDY0_Pin);
			HAL_GPIO_TogglePin(GPIOA, LEDY1_Pin);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOA, LEDY0_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LEDR0_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LEDY1_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LEDR1_Pin,GPIO_PIN_SET);
			HAL_GPIO_TogglePin(GPIOA, LEDG0_Pin);
			HAL_GPIO_TogglePin(GPIOA, LEDG1_Pin);
			break;
		default:
			break;
	}
}

int SEGState = 0;
void fsm_display_7SEG(void){

		switch (SEGState){
			case 0:
				HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_SET);
				display7SEG0(timeDisplay0 / 10);
				display7SEG1(timeDisplay1 / 10);
				SEGState = 1;
				break;
			case 1:
				HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_RESET);
				display7SEG0(timeDisplay0 % 10);
				display7SEG1(timeDisplay1 % 10);
				SEGState = 0;
				break;
			default:
				break;
		}
}


void fsm_modify_mode(void){
	if(mainState > 1){
		timeDisplay0 = mainState;
		timeDisplay1 = timeDuration;
	}
}

void fsm_traffic_light ( void ){
	if (mainState == 1){
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_RESET);
		switch(trafficLightState0){
			case 0:
				  HAL_GPIO_WritePin(GPIOA, LEDR0_Pin,GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOA, LEDY0_Pin,GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOA, LEDG0_Pin,GPIO_PIN_SET);
				  timeDisplay0 = count0;
				  count0--;
				  if(count0 <= 0) {
					  trafficLightState0 = 2;
					  count0 = timeGreen;
				  }
				  break;
			case 1:
				  HAL_GPIO_WritePin(GPIOA, LEDR0_Pin,GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOA, LEDY0_Pin,GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOA, LEDG0_Pin,GPIO_PIN_SET);
				  timeDisplay0 = count0;
				  count0--;
				  if(count0 <= 0) {
					  trafficLightState0 = 0;
					  count0 = timeRed;
				  }
				  break;
			case 2:
				  HAL_GPIO_WritePin(GPIOA, LEDR0_Pin,GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOA, LEDY0_Pin,GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOA, LEDG0_Pin,GPIO_PIN_RESET);
				  timeDisplay0 = count0;
				  count0--;
				  if(count0 <= 0 ) {
					  trafficLightState0 = 1;
					  count0 = timeYellow;
				  }
				  break;
			default:
				break;
		}

		switch(trafficLightState1){
			case 2:
				  HAL_GPIO_WritePin(GPIOA, LEDR1_Pin,GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOA, LEDY1_Pin,GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOA, LEDG1_Pin,GPIO_PIN_RESET);
				  timeDisplay1 = count1;
				  count1--;
				  if(count1 <= 0) {
					  trafficLightState1 = 1;
					  count1 = timeYellow;
				  }
				  break;
			case 1:
				  HAL_GPIO_WritePin(GPIOA, LEDR1_Pin,GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOA, LEDY1_Pin,GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOA, LEDG1_Pin,GPIO_PIN_SET);
				  timeDisplay1 = count1;
				  count1--;
				  if(count1 <= 0) {
					  trafficLightState1 = 0;
					  count1 = timeRed;
				  }
				  break;
			case 0:
				  HAL_GPIO_WritePin(GPIOA, LEDR1_Pin,GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(GPIOA, LEDY1_Pin,GPIO_PIN_SET);
				  HAL_GPIO_WritePin(GPIOA, LEDG1_Pin,GPIO_PIN_SET);
				  timeDisplay1 = count1;
				  count1--;
				  if(count1  <= 0) {
					  trafficLightState1 = 2;
					  count1 = timeGreen;
				  }
				  break;
			default:
				break;
		}

	}

}



