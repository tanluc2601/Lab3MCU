
#include "global.h"
#include "main.h"


int TIMER_CYCLE = 10;
int timeRed = 5;
int timeYellow = 2;
int timeGreen = 3;
int timer0_flag = 0;
int timer0_counter = 0;
int timer1_flag = 0;
int timer1_counter = 0;
int timer2_flag = 0;
int timer2_counter = 0;
int timeDuration = 0;
int mainState = 0;
int timeDisplay0 = 5;
int timeDisplay1 = 2;
int trafficLightState0 = 0;
int trafficLightState1 = 2;
int count0 = 5;
int count1 = 3;

void setTimer0 ( int duration ){
	timer0_counter = duration / TIMER_CYCLE ;
	timer0_flag = 0;
}

void setTimer1 ( int duration ){
	timer1_counter = duration / TIMER_CYCLE ;
	timer1_flag = 0;
}

void setTimer2 ( int duration ){
	timer2_counter = duration / TIMER_CYCLE ;
	timer2_flag = 0;
}

void timer_run (void){
	if( timer0_counter > 0){
		timer0_counter --;
		if ( timer0_counter == 0) timer0_flag = 1;
	}
	if( timer1_counter > 0){
		timer1_counter --;
		if ( timer1_counter == 0) timer1_flag = 1;
	}
//	if( timer2_counter > 0){
//		timer2_counter --;
//		if ( timer2_counter == 0) timer2_flag = 1;
//	}
}

void display7SEG0(int num){
  	  switch(num) {
  	  case 0:
  		  HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_1_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_2_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_3_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_4_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_5_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_6_Pin,GPIO_PIN_SET);
  		  break;
  	  case 1:
  		  HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_1_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_2_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_3_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_4_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_5_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_6_Pin,GPIO_PIN_SET);
  		  break;
  	  case 2:
  		  HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_1_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_2_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_3_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_4_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_5_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_6_Pin,GPIO_PIN_RESET);
  		  break;
  	  case 3:
  		  HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_1_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_2_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_3_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_4_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_5_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_6_Pin,GPIO_PIN_RESET);
  		  break;
  	  case 4:
  		  HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_1_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_2_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_3_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_4_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_5_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_6_Pin,GPIO_PIN_RESET);
  		  break;
  	  case 5:
  		  HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_1_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_2_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_3_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_4_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_5_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_6_Pin,GPIO_PIN_RESET);
  		  break;
  	  case 6:
  		  HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_1_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_2_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_3_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_4_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_5_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_6_Pin,GPIO_PIN_RESET);
  		  break;
  	  case 7:
  		 HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin,GPIO_PIN_RESET);
  		 HAL_GPIO_WritePin(GPIOB, SEG0_1_Pin,GPIO_PIN_RESET);
  		 HAL_GPIO_WritePin(GPIOB, SEG0_2_Pin,GPIO_PIN_RESET);
  		 HAL_GPIO_WritePin(GPIOB, SEG0_3_Pin,GPIO_PIN_SET);
  		 HAL_GPIO_WritePin(GPIOB, SEG0_4_Pin,GPIO_PIN_SET);
  		 HAL_GPIO_WritePin(GPIOB, SEG0_5_Pin,GPIO_PIN_SET);
  		 HAL_GPIO_WritePin(GPIOB, SEG0_6_Pin,GPIO_PIN_SET);
  		 break;
  	  case 8:
  		  HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_1_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_2_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_3_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_4_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_5_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_6_Pin,GPIO_PIN_RESET);
  		  break;
  	  case 9:
  		  HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_1_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_2_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_3_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_4_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_5_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_6_Pin,GPIO_PIN_RESET);
  		  break;
  	  default:
  		  HAL_GPIO_WritePin(GPIOB, SEG0_0_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_1_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_2_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_3_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_4_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_5_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG0_6_Pin,GPIO_PIN_SET);
  		  break;
  	  }
}

void display7SEG1(int num){
  	  switch(num) {
  	  case 0:
  		  HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_1_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_2_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_3_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_4_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_5_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_6_Pin,GPIO_PIN_SET);
  		  break;
  	  case 1:
  		  HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_1_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_2_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_3_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_4_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_5_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_6_Pin,GPIO_PIN_SET);
  		  break;
  	  case 2:
  		  HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_1_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_2_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_3_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_4_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_5_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_6_Pin,GPIO_PIN_RESET);
  		  break;
  	  case 3:
  		  HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_1_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_2_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_3_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_4_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_5_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_6_Pin,GPIO_PIN_RESET);
  		  break;
  	  case 4:
  		  HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_1_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_2_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_3_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_4_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_5_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_6_Pin,GPIO_PIN_RESET);
  		  break;
  	  case 5:
  		  HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_1_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_2_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_3_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_4_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_5_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_6_Pin,GPIO_PIN_RESET);
  		  break;
  	  case 6:
  		  HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_1_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_2_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_3_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_4_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_5_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_6_Pin,GPIO_PIN_RESET);
  		  break;
  	  case 7:
  		 HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin,GPIO_PIN_RESET);
  		 HAL_GPIO_WritePin(GPIOB, SEG1_1_Pin,GPIO_PIN_RESET);
  		 HAL_GPIO_WritePin(GPIOB, SEG1_2_Pin,GPIO_PIN_RESET);
  		 HAL_GPIO_WritePin(GPIOB, SEG1_3_Pin,GPIO_PIN_SET);
  		 HAL_GPIO_WritePin(GPIOB, SEG1_4_Pin,GPIO_PIN_SET);
  		 HAL_GPIO_WritePin(GPIOB, SEG1_5_Pin,GPIO_PIN_SET);
  		 HAL_GPIO_WritePin(GPIOB, SEG1_6_Pin,GPIO_PIN_SET);
  		 break;
  	  case 8:
  		  HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_1_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_2_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_3_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_4_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_5_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_6_Pin,GPIO_PIN_RESET);
  		  break;
  	  case 9:
  		  HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_1_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_2_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_3_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_4_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_5_Pin,GPIO_PIN_RESET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_6_Pin,GPIO_PIN_RESET);
  		  break;
  	  default:
  		  HAL_GPIO_WritePin(GPIOB, SEG1_0_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_1_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_2_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_3_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_4_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_5_Pin,GPIO_PIN_SET);
  		  HAL_GPIO_WritePin(GPIOB, SEG1_6_Pin,GPIO_PIN_SET);
  		  break;
  	  }
}



