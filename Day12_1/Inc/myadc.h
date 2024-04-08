/*
 * myadc.h
 *
 *  Created on: Apr 6, 2024
 *      Author: vinayak
 */

#ifndef MYADC_H_
#define MYADC_H_

#include "stm32f4xx.h"
#include "stm32f407xx.h"

void ADC_Init(void);
uint16_t ADC_GetValue(void);


#endif /* MYADC_H_ */
