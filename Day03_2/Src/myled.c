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
	LEDGPIO->BSRR |= BV(pin);
}
void LEDoff(uint32_t pin)
{
	LEDGPIO->BSRR |= BV(pin+16);
}
void LEDblink(uint32_t pin,uint32_t pin1,uint32_t pin2,uint32_t pin3,uint32_t delay)
{
	LEDon(pin);
	LEDon(pin1);
	LEDon(pin2);
	LEDon(pin3);
	DelayMs(delay);
	LEDoff(pin);
	LEDoff(pin1);
	LEDoff(pin2);
	LEDoff(pin3);
	DelayMs(delay);

}
