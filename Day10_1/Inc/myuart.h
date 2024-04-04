/*
 * myuart.h
 *
 *  Created on: Apr 1, 2024
 *      Author: vinayak
 */

#ifndef MYUART_H_
#define MYUART_H_


#include "stm32f4xx.h"
#include "stm32f407xx.h"

#define BAUD_9600 9600
#define BAUD_38400 38400
#define BAUD_115200 115200

#define BAUD_brr_9600 0x683
#define BAUD_brr_38400 0x1A1
#define BAUD_brr_115200 0x8B

#define TX_PIN 2
#define RX_PIN 3
#define USART_alt_fn 7

void uartinit(uint32_t baud);
void uartputch(uint8_t ch);
uint8_t uartgetch(void);
void uartputs(char str[]);
void uartgets(char str[]);

#endif /* MYUART_H_ */
