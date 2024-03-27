/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "myled.h"
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "myled.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	SystemInit();
	DelayMs(1);
	LEDInIt(LED_green);
	LEDInIt(LED_orange);
	LEDInIt(LED_red);
	LEDInIt(LED_blue);

	while(1)
	{
		LEDblink(LED_green,500);
		LEDblink(LED_orange,500);
		LEDblink(LED_red,500);
		LEDblink(LED_blue,500);


		LEDblink(LED_red,500);
		LEDblink(LED_orange,500);
		LEDblink(LED_green,500);
		LEDblink(LED_blue,500);
	}



	return 0;
}
