/*
 * led.h
 *
 *  Created on: Feb 7, 2026
 *      Author: erkutdonmez
 */

#include <stdint.h>

#ifndef LED_H_
#define LED_H_

#define DELAY125MS 285714
#define DELAY250MS (DELAY125MS) * 2
#define DELAY500MS (DELAY125MS) * 4
#define DELAY1SEC  (DELAY125MS) * 8

#define GLOBAL_DELAY_COUNT		0U

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
void delay(void);
void init_gpio_pins_as_output(LED_COLORS* pins, uint8_t pins_len);

#endif /* LED_H_ */
