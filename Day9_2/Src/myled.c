#include "myled.h"//my header file
#include "stm32f4xx.h"//stm32f4 header file

void LEDInIt(uint32_t pin) //function to initialize in built LED
{
	RCC->AHB1ENR |= BV(LEDGPIO_en);
	LEDGPIO->MODER &= ~BV(pin*2+1);
	LEDGPIO->MODER |= BV(pin*2);
	LEDGPIO->OSPEEDR &= ~BV(pin*2+1) | BV(pin*2);
	LEDGPIO->PUPDR &= ~BV(pin*2+1) | BV(pin*2);
	LEDGPIO->OTYPER &= ~BV(pin);
}

void LEDon(uint32_t pin)
{
	LEDGPIO->ODR |= BV(pin);
}
void LEDoff(uint32_t pin)
{
	LEDGPIO->ODR &= ~BV(pin);
}
void LEDblink(uint32_t pin,uint32_t delay)
{
	LEDon(pin);
	DelayMs(delay);
	LEDoff(pin);
}
