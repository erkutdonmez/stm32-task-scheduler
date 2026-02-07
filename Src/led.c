/*
 * led.c
 *
 *  Created on: Feb 7, 2026
 *      Author: erkutdonmez
 */

#include "led.h"

volatile uint32_t* const RCC_AHB1ENR = (volatile uint32_t*)0x40023830; // reset clock contro register AHB1 enabler
volatile uint32_t* const GPIOD_MODER = (volatile uint32_t*)0x40020C00; //port d i/o moder
volatile uint32_t* const GPIOD_OTYPER= (volatile uint32_t*)0x40020C04;
volatile uint32_t* const GPIOD_ODR   = (volatile uint32_t*)0x40020C14;



void init_clock() {
	//first initialze the clock
	*RCC_AHB1ENR |= (1 << 3);
}

void init_gpio_pins_as_output(LED_COLORS* pins, uint8_t pins_len) {
	for(volatile uint8_t i = 0; i < pins_len; i++) {
		*GPIOD_MODER &= ~(3 << (pins[i] * 2));
		*GPIOD_MODER |= (1 << (pins[i] * 2));
		*GPIOD_OTYPER &= ~(1 << pins[i]);
	}
}

void led_on(LED_COLORS pin) {
	*GPIOD_ODR |= (1 << pin);
}


void led_off(LED_COLORS pin) {
	*GPIOD_ODR &= ~(1 << pin);
}

/*
 how to approximate working time of a loop:
 approximate delay analysis:
	processor running with 16Mhz of internal RC oscillator
	lets assume 1 instruction takes 1 clock cycle
	1 instruction = 0.0625 microseconds, each loop is 7 instruction
	counter parameter is 300000,
	approximate delay time is => 300000 * 7 * 0.0625 = 131250 microseconds => 131,25 milliseconds => 0.131 seconds

	for 125ms of delay counter parameter should be 285714

 */

void delay(void) {
	for(volatile uint32_t i = 0; i < cycles; i++) {
		GLOBAL_DELAY_COUNT++;
		if(GLOBAL_DELAY_COUNT % DELAY125MS == 0) {

		}
		if(GLOBAL_DELAY_COUNT % DELAY125MS == 0) {

		}
		if(GLOBAL_DELAY_COUNT % DELAY125MS == 0) {

		}
		if(GLOBAL_DELAY_COUNT % DELAY125MS == 0) {

		}

	}
}
