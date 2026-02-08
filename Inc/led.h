/*
 * led.h
 *
 *  Created on: Feb 7, 2026
 *      Author: erkutdonmez
 */

#include <stdint.h>

#ifndef LED_H_
#define LED_H_

#define DELAY125MS 125U
#define DELAY250MS 250U
#define DELAY500MS 500U
#define DELAY1SEC  1000U

#define TASK_RUNNING_STATE 		1U
#define TASK_BLOCKED_STATE 		0U

//green led  -> PD12 -> 1s delay
//orange led -> PD13 -> 500ms delay
//red led    -> PD14 -> 250ms delay
//blue led   -> PD15 -> 125ms delay

typedef enum {
	GREEN = 12,
	ORANGE,
	RED,
	BLUE
}LED_COLORS;

void init_clock();
void led_on(LED_COLORS pin);
void led_off(LED_COLORS pin);
void delay(uint32_t cycles);
void init_gpio_pins_as_output(LED_COLORS* pins, uint8_t pins_len);

#endif /* LED_H_ */
