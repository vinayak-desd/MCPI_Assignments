/*
 * mytimer.c
 *
 *  Created on: Apr 5, 2024
 *      Author: vinayak
 */

#include "mytimer.h"

void TimerInit(void){
	//Enable GPIO Clock for C.6
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN ;
	//CONFIGURE PC6 AS ALT. FUN MODE
	GPIOC->MODER |= (2<<6*2);
	//SET ALT. FUN AS TIMER8 OUTPUT (AF3)
	GPIOC->AFR[0] |= (3 << GPIO_AFRL_AFSEL6_Pos);

	//ENABLE TIMER8 CLOCK
	RCC->APB2ENR |= RCC_APB2ENR_TIM8EN ;

	//SET PRESCALAR VALUE
	TIM8->PSC = (TIM_PSC-1); // PRESCALAR VALUE
	//SET ARR VALUE TO 100 FOR 10KHZ PWM OUTPUT FREQ
	TIM8->ARR = (100-1);
	//SET CCR VALUE I.E. DUTY CYCLE (MUST BE LESS THAN ARR VALUE)
	TIM8->CCR1 = 1-1;
	//CONFIGURE TIMER8 CHANNELS AS OUTPUT CHANNEL
	// Configure Timer8 channels as output channel
	//TIM8->CCMR1 &= ~TIM_CCMR1_CC1S;	// default
    // Configure Timer8 channel polarity as active high
    //TIM8->CCER &= ~TIM_CCER_CC1P;		// default
    // Configure Timer8 for output compare mode
    TIM8->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1; // PWM Mode 1 => 110

    // Set the preload bit in CCMRx register
    TIM8->CCR1 |= TIM_CCMR1_OC1PE;
    //SET THE ARPE BIT IN THE CR1 REGR.
    TIM8->CR1 |= TIM_CR1_ARPE;
    //SET THE PWM EDGE ALIGN MODE IN THE CR1 REGISTER
    //TIM8->CR1 &= ~TIM_CR1_CMS;	// default

    // Configure Timer8 output OCx signal to output pin
    TIM8->CCER |= TIM_CCER_CC1E;

      // Enable Timer 8 Main output and Timer8 peripheral
     TIM8->BDTR |= TIM_BDTR_MOE;
     TIM8->CR1 |= TIM_CR1_CEN;
}
