/*
 * timer.h
 *
 *  Created on: Apr 4, 2024
 *      Author: vinayak
 */

#ifndef MYTIMER_H_
#define MYTIMER_H_

#include "stm32f4xx.h"
#include "stm32f407xx.h"

#define TCLK		16000000
#define TIM_PR		16000

void TimerInit(void);
void TimerDelayMs(uint32_t ms);



#endif /* MYTIMER_H_ */
