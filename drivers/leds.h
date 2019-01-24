/*
 * ATS LEDs Driver
 * 
 * @Company
 *   ATS Team
 * 
 * @File Name
 *   leds.h
 * 
 * @Summary
 *   Interface to the debug LEDs on the ATS board.
*/

#ifndef LEDS_H
#define LEDS_H


#include <stdbool.h>


#define LED_COUNT 3


#ifdef	__cplusplus
extern "C"
{
#endif


typedef enum
{
    LED_1,
    LED_2,
	LED_3
} led_t;


void led_on     (led_t led);
void led_off    (led_t led);
void led_toggle (led_t led);
bool led_get    (led_t led);


#ifdef	__cplusplus
}
#endif

#endif /* LEDS_H */
