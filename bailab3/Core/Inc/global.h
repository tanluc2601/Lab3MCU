
#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_


extern int timeRed;
extern int timeYellow;
extern int timeGreen;
extern int TIMER_CYCLE;
extern int timer0_counter;
extern int timer0_flag;
extern int timer1_counter;
extern int timer1_flag;
extern int timer2_counter;
extern int timer2_flag;
extern int timeDuration;
extern int mainState;
extern int timeDisplay0;
extern int timeDisplay1;
extern int trafficLightState0;
extern int trafficLightState1;
extern int count0;
extern int count1;

void display7SEG0(int num);

void display7SEG1(int num);

void setTimer0 ( int duration );

void setTimer1 ( int duration );

void setTimer2 ( int duration );

void timer_run(void);

#endif /* INC_GLOBAL_H_ */
