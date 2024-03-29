/*
 * mylcd.c
 *
 *  Created on: Mar 28, 2024
 *      Author: vinayak
 */

#include "mylcd.h"

void LCDbusywait(void)//this function is to check busyflag
{
	uint32_t state;
	//to make the D7 pin as input
	//#define LCD_BF LCD_D7(in mylcd.h)
	//to set MODER (mode register) as a General Purpose input (00)
	LCD_data_GPIO->MODER &= ~(BV(LCD_BF*2) | BV(LCD_BF*2+1));

	//to set RS = 0 as for command and instruction
	//to set RW = 1 for read mode
	//to set EN = 1
	//the data is to be fetch only when falling edge of EN
	//here BSRR (bit set/reset register) is used to set and reset the port
	LCD_ctr_GPIO->BSRR = BV(LCD_rs_clr) | BV(LCD_rw)| BV(LCD_en);

	//to read data
	do
	{
		state = LCD_data_GPIO->IDR;
		//this loop will run until busy flag is on
	}while((state & BV(LCD_BF)) !=0 );
	//Now as the busy flag is off

	//we can write data on LCD
	//to write data on LCD
	//set RW = 0// #define LCD_rw_clr (LCD_rw+16)
	//set EN = 0 // falling edge....#define LCD_en_clr (LCD_en+16)
	//here BSRR (bit set/reset register) is used to set and reset the port
	LCD_ctr_GPIO->BSRR = BV(LCD_rw_clr) | BV(LCD_en_clr);

	//to make the D7 pin as output
	//to set MODER (mode register) as a General Purpose output (01)
	LCD_data_GPIO->MODER |= BV(LCD_BF*2);

}
void LCDwritenibble(uint8_t rs,uint8_t val)//this function is to set nibble because we set LCD to write 4-bit
{
	//if lCD is set for command
	//to write data make RS = 1 and RW = 0
	//if LCD in data mode do nothing with RS and make RW = 1
	if(rs == LCD_cmd)
		LCD_ctr_GPIO->BSRR = BV(LCD_rs_clr) | BV(LCD_rw_clr);
	else
		LCD_ctr_GPIO->BSRR =BV(LCD_rs) | BV(LCD_rw_clr);

	//to write 4 bit data on LCD
	//to make GPIO as output ODR (output Data register)
	LCD_data_GPIO->ODR &= ~(BV(LCD_D7) | BV(LCD_D6) | BV(LCD_D5) | BV(LCD_D4));
	LCD_data_GPIO->ODR |= val << LCD_D4;

	//to make falling edge to fetch data
	LCD_ctr_GPIO->BSRR = BV(LCD_en);
	DelayMs(1);
	LCD_ctr_GPIO->BSRR = BV(LCD_en_clr);

}
void LCDwrite(uint8_t rs,uint8_t val)//this function is to convert 8-bit to 2 4-bit for nibble
{
	uint8_t high = val >> 4, low = val & 0x0F;

	LCDwritenibble(rs,high);
	LCDwritenibble(rs,low);
	LCDbusywait();
	DelayMs(3);
}
void LCDinit(void)
{
	DelayMs(50);
	RCC->AHB1ENR |= BV(LCD_data_GPIO_en);
	RCC->AHB1ENR |= BV(LCD_ctr_GPIO_en);

	LCD_data_GPIO->MODER &= ~(BV(LCD_D7*2+1) | BV(LCD_D6*2+1) | BV(LCD_D5*2+1) | BV(LCD_D4*2+1));
	LCD_data_GPIO->MODER |= BV(LCD_D7*2) | BV(LCD_D6*2) | BV(LCD_D5*2) | BV(LCD_D4*2);
	LCD_data_GPIO->OSPEEDR &= ~(BV(LCD_D7*2+1) | BV(LCD_D6*2+1) | BV(LCD_D5*2+1) | BV(LCD_D4*2+1) | BV(LCD_D7*2) | BV(LCD_D6*2) | BV(LCD_D5*2) | BV(LCD_D4*2));
	LCD_data_GPIO->PUPDR &= ~(BV(LCD_D7*2+1) | BV(LCD_D6*2+1) | BV(LCD_D5*2+1) | BV(LCD_D4*2+1) | BV(LCD_D7*2) | BV(LCD_D6*2) | BV(LCD_D5*2) | BV(LCD_D4*2));
	LCD_data_GPIO->OTYPER &= ~(BV(LCD_D7) | BV(LCD_D6) | BV(LCD_D5) | BV(LCD_D4));
	LCD_data_GPIO->BSRR = (BV(LCD_D7_clr) | BV(LCD_D6_clr) | BV(LCD_D5_clr) | BV(LCD_D4_clr));

	LCD_ctr_GPIO->MODER &= ~(BV(LCD_rs*2+1) | BV(LCD_rw*2+1) | BV(LCD_en*2+1));
	LCD_ctr_GPIO->MODER |= (BV(LCD_rs*2) | BV(LCD_rw*2) | BV(LCD_en*2));
	LCD_ctr_GPIO->OSPEEDR &= ~(BV(LCD_rs*2+1) | BV(LCD_rw*2+1) | BV(LCD_en*2+1) | BV(LCD_rs*2) | BV(LCD_rw*2) | BV(LCD_en*2));
	LCD_ctr_GPIO->PUPDR &= ~(BV(LCD_rs*2+1) | BV(LCD_rw*2+1) | BV(LCD_en*2+1) | BV(LCD_rs*2) | BV(LCD_rw*2) | BV(LCD_en*2));
	LCD_data_GPIO->OTYPER &= ~(BV(LCD_rs) | BV(LCD_rw) | BV(LCD_en));

	LCD_ctr_GPIO->BSRR = (BV(LCD_rs_clr) | BV(LCD_rw_clr) | BV(LCD_en_clr));

	DelayMs(200);


	LCDwrite(LCD_cmd,LCD_fn_set);

	LCDwrite(LCD_cmd,LCD_disp_ON);

	LCDwrite(LCD_cmd,LCD_entry_mode);

	//LCDwrite(LCD_cmd, LCD_disp_sft);
	LCDwrite(LCD_cmd,LCD_clear);

	DelayMs(200);

}

void LCDputs(uint8_t line,char str[])
{
	int i;

	LCDwrite(LCD_cmd,line);

	for(i=0;str[i] != '\0';i++)
		LCDwrite(LCD_data,str[i]);
}
