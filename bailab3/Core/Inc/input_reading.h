
#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#define N0_OF_BUTTONS 				       3
extern uint8_t flagForAutoCountUp[N0_OF_BUTTONS];

void button_reading(void);

unsigned char is_button_pressed(unsigned char index);

unsigned char is_button_pressed_1s(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
