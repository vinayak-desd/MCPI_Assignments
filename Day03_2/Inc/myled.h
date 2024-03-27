/*
 * myled.h
 *
 *  Created on: Mar 27, 2024
 *      Author: vinayak
 */

#ifndef MYLED_H_
#define MYLED_H_

#include "stm32f4xx.h"

#define LEDGPIO GPIOD//MACRO FOR GPIOD
#define LEDGPIO_en 3//select D port of GPIO


#define LED_green 12
#define LED_orange 13
#define LED_red 14
#define LED_blue 15


void LEDInIt(uint32_t pin);
void LEDon(uint32_t pin);
void LEDoff(uint32_t pin);
void LEDblink(uint32_t pin,uint32_t pin1,uint32_t pin2,uint32_t pin3,uint32_t delay);

#endif /* MYLED_H_ */
