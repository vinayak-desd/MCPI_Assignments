/*
 * myswitch.h
 *
 *  Created on: Apr 5, 2024
 *      Author: vinayak
 */

#ifndef MYSWITCH_H_
#define MYSWITCH_H_

#include "stm32f4xx.h"
#include "stm32f407xx.h"

#define SWITCH_GPIO		GPIOA
#define SWITCH_GPIO_EN	0

#define SWITCH			0

void SwitchInit(uint32_t pin);
int SwitchGetState(uint32_t pin);

extern volatile  int exti0_flag;


#endif /* MYSWITCH_H_ */
