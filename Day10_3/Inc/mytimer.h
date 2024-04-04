/*
 * mytimer.c
 *
 *  Created on: Apr 4, 2024
 *      Author: vinayak
 */

#ifndef MYTIMER_C_
#define MYTIMER_C_

#include "stm32f4xx.h"
#include "stm32f407xx.h"

#define TCLK		16000000
#define TIM_PR		16000
extern int count;
void TimerInit(uint32_t ms);


#endif /* MYTIMER_C_ */
