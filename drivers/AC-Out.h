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

#ifndef AC_OUT_H
#define AC_OUT_H


#include <stdbool.h>


#define AC_COUNT 2


#ifdef	__cplusplus
extern "C"
{
#endif


typedef enum
{
    AC_1,
    AC_2,
} ac_t;


void AC_on (ac_t ac);
void AC_off (void);


#ifdef	__cplusplus
}
#endif

#endif /* LEDS_H */
