/*
 * mylcd.h
 *
 *  Created on: Mar 28, 2024
 *      Author: vinayak
 */

#ifndef MYLCD_H_
#define MYLCD_H_

#include "stm32f4xx.h"
#include "stm32f407xx.h"

#define LCD_data_GPIO GPIOD//this macro is for set GPIO Port D as data
#define LCD_data_GPIO_en 3//this macro is for set clock of GPIO D port (STM32f407 user manual PgNo 233 7.3.5)
#define LCD_D7 3//this macro is for LCD's D7 pin to GPIO Port D's pin no 3
#define LCD_D6 2//this macro is for LCD's D6 pin to GPIO Port D's pin no 2
#define LCD_D5 1//this macro is for LCD's D5 pin to GPIO Port D's pin no 2
#define LCD_D4 0//this macro is for LCD's D4 pin to GPIO Port D's pin no 0
#define LCD_BF LCD_D7//this Macro is for When RS = 0 & R/W = 1 then, the busy flag is output to D7
#define LCD_D7_clr (LCD_D7+16)// this macro is for clear D7 using BSRR thats why +16
#define LCD_D6_clr (LCD_D6+16)// this macro is for clear D6 using BSRR thats why +16
#define LCD_D5_clr (LCD_D5+16)// this macro is for clear D5 using BSRR thats why +16
#define LCD_D4_clr (LCD_D4+16)// this macro is for clear D4 using BSRR thats why +16

#define LCD_ctr_GPIO GPIOD//this macro is for set GPIO Port D as control
#define LCD_ctr_GPIO_en 3//this macro is for set clock of GPIO D port(STM32f407 user manual PgNo 233 7.3.5)
#define LCD_rs 5//this macro is for LCD's RS pin to GPIO Port D's pin no 5
#define LCD_rw 6//this macro is for LCD's RW pin to GPIO Port D's pin no 6
#define LCD_en 7//this macro is for LCD's EN pin to GPIO Port D's pin no 7
#define LCD_rs_clr (LCD_rs+16)// this macro is for clear RS using BSRR thats why +16
#define LCD_rw_clr (LCD_rw+16)// this macro is for clear RW using BSRR thats why +16
#define LCD_en_clr (LCD_en+16)// this macro is for clear RW using BSRR thats why +16

#define LCD_clear 0x01//this macro is for clear display(LCD manual PgNo 24)
#define LCD_fn_set 0x28//this macro is for function set (4-bit data,2-line,5*8font)(LCD manual PgNo 24)
#define LCD_disp_ON 0x0F//this macro is for display ON (disp on,Cursor on, Blinking ON)(LCD manual PgNo 24)
#define LCD_disp_sft 0x18
#define LCD_entry_mode 0x06//this macro is for entry mode (for address increment by 1 for each char print,NO shift of display)(LCD manual PgNo 24)
#define LCD_line1 0x80//this macro is for set address of line1
#define LCD_line2 0xC0//this macro is for set address of line2


#define LCD_cmd 0//this macro is for RS (0 is for command/instruction)
#define LCD_data 1//this macro is for RS (1 is for data)

void LCDbusywait(void);//this function is to check busyflag
void LCDwritenibble(uint8_t rs,uint8_t val);//this function is to set nibble because we set LCD to write 4-bit
void LCDwrite(uint8_t rs,uint8_t val);//this function is to convert 8-bit to 2 4-bit for nibble

void LCDinit(void);//this function is for initialize LCD pins
void LCDputs(uint8_t line,char str[]);//this function is for Display data on LCD

#endif /* MYLCD_H_ */
