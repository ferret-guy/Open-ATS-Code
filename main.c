/*
 * ATS Firmware
 * 
 * @Company
 *   ATS Team
 * 
 * @File Name
 *   main.c
 * 
 * @Summary
 *   Contains initialization and main task loop for ATS
*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/attribs.h>
#include <math.h>

#include "drivers/leds.h"
#include "drivers/AC-Out.h"
#include "ports.h"
#include "common/sw_timer.h"

// BF1SEQ0
#pragma config TSEQ = 0x0000
#pragma config CSEQ = 0xFFFF


int main(void){
    int pulse_count = 0;
    
	// CPU Performance Optimization:
	register unsigned long tmp_cache;                 //KSEG0 cache enable
	__asm__("mfc0 %0,$16,0" :  "=r"(tmp_cache));
	tmp_cache = (tmp_cache & ~7) | 3;
	__asm__("mtc0 %0,$16,0" :: "r" (tmp_cache));
	PRECONbits.PFMWS=2;       //Flash wait states = 2 CPU clock cycles @ 200Mhz        
	PRECONbits.PREFEN = 2;    //Enable predictive prefetch for CPU instructions and CPU data
	
	// Interrupt setup
	PRISSbits.PRI7SS = 7;	//DMA Interrupt with priority level of 7 uses Shadow Set 7
	PRISSbits.PRI6SS = 6;	//Interrupt with priority level of 6 uses Shadow Set 6
	PRISSbits.PRI5SS = 5;	//Interrupt with priority level of 5 uses Shadow Set 5
	PRISSbits.PRI4SS = 4;	//Interrupt with priority level of 4 uses Shadow Set 4
	PRISSbits.PRI3SS = 3;	//Interrupt with priority level of 3 uses Shadow Set 3
	PRISSbits.PRI2SS = 2;	//Interrupt with priority level of 2 uses Shadow Set 2
	INTCONbits.MVEC = 1;	//Enable multi-vector interrupts
	__builtin_enable_interrupts(); // Global Interrupt Enable 
	
	// Subsystem initialization
	ports_init();
	sw_timer_init();
	
	// Timers
	sw_timer blink_timer = TIMER(1000);
	sw_timer output_timer = TIMER(1000);
    sw_timer AC_1_timeout = TIMER(10);
    sw_timer AC_2_timeout = TIMER(10);
	sw_timer_reset(&blink_timer);
	sw_timer_reset(&output_timer);
    sw_timer_reset(&AC_1_timeout);
    sw_timer_reset(&AC_2_timeout);
    
    led_on(LED_1);
    led_off(LED_3);
    AC_on(AC_1);
    
    bool AC_1_pulse_high = false;
	while(1){
        if (AC_1_PORT == 0){
            sw_timer_reset(&AC_1_timeout);
            if (AC_1_pulse_high == false){
                pulse_count++;
            }
            AC_1_pulse_high = true;
        } else {
            AC_1_pulse_high = false;
        }
        if (AC_2_PORT == 0){
            sw_timer_reset(&AC_2_timeout);
        }
        if (sw_timer_expired(AC_1_timeout)){
            led_on(LED_3);
            led_off(LED_1);
            AC_on(AC_2);
        }
        if (sw_timer_expired(AC_2_timeout)){
            led_on(LED_1);
            led_off(LED_3);
            AC_on(AC_1);
        }
		// Blink LED
		if (sw_timer_expired(blink_timer)){
			sw_timer_reset(&blink_timer);
            led_toggle(LED_2);
		}
	}
}
