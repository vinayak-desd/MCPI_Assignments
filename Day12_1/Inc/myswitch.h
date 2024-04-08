/*
 * myswitch.h
 *
 *  Created on: Mar 30, 2024
 *      Author: vinayak
 */

#ifndef MYSWITCH_H_
#define MYSWITCH_H_


#include <stdio.h>
#include "myi2c_lcd.h"
#include "stm32f4xx.h"
#include "stm32f407xx.h"
#include "myadc.h"


#define SWITCH_GPIO GPIOA
#define SWITCH_GPIO_en 0

#define SWITCH 0
//extern volatile uint16_t val;
extern int exti0_flag;
void Switchinit(uint32_t pin);
int Switchgetstate(uint32_t pin);

#endif /* MYSWITCH_H_ */
