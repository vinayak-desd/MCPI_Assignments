/*
 * myswitch.c
 *
 *  Created on: Mar 30, 2024
 *      Author: vinayak
 */

#include "myswitch.h"


void Switchinit(uint32_t pin)
{
	RCC->AHB1ENR |= BV(SWITCH_GPIO_en);

	SWITCH_GPIO->MODER &= ~(BV(pin*2+1) | BV(pin*2));

	SWITCH_GPIO->OSPEEDR &= ~(BV(pin*2+1) | BV(pin*2));

	SWITCH_GPIO->PUPDR &= ~(BV(pin*2+1) | BV(pin*2));

	EXTI->FTSR |= BV(SWITCH);

	EXTI->IMR |= BV(SWITCH);

	SYSCFG->EXTICR[0] &= ~(BV(3) | BV(2) | BV(1) | BV(0));

	NVIC_EnableIRQ(EXTI0_IRQn);
}

int Switchgetstate(uint32_t pin)
{
	uint32_t state = SWITCH_GPIO->IDR;

	if(state & BV(pin))
		return 1;
	return 0;
}
int exti0_flag = 0;
void EXTI0_IRQHandler(void)
{
	EXTI->PR |= BV(SWITCH);

	exti0_flag = 1;


}
