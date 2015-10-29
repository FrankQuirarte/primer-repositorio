/*
* Hugol_Leds.h
 *
 *  Created on: Oct 21, 2015
 *      Author: Hugol D Cervantes (Oswaldo Garcia)
 */


#ifndef Led_H_
#define Led_H_

#define LED_on 		0
#define LED_off		1

#define LED1		0
#define LED2		1
#define LED3		2
#define LED4		3
#define LED5		4
#define LED6		5
#define LED7		6
#define LED8		7
#define LED9		8
#define LED10		9

#define LED_GREEN		10
#define LED_BLUE		13

#define LED_1		68
#define LED_2		69
#define LED_3		70
#define LED_4		71

void delay(int num);
void led_sysclk_init_fnc(void);
void Led_change_status(char ch, char Led_state);
int Window_Up();

#endif /* LED_H_ */
