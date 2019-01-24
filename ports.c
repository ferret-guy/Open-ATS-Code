/*
 * ATS Port Definitions
 * 
 * @Company
 *   ATS Team
 * 
 * @File Name
 *   ports.c
 * 
 * @Summary
 *   Configures the IO ports used by the hardware.
*/

#include "ports.h"

#include <xc.h>


void ports_init(void){
	LED_1_LAT = 0;
	LED_1_PORT = 0;
	LED_1_TRIS = PORT_OUTPUT;
	LED_1_ANSEL = 0;

	LED_2_LAT = 0;
	LED_2_PORT = 0;
	LED_2_TRIS = PORT_OUTPUT;
	LED_2_ANSEL = 0;

	LED_3_LAT = 0;
	LED_3_PORT = 0;
	LED_3_TRIS = PORT_OUTPUT;
	LED_3_ANSEL = 0;

	AC_1_LAT = 0;
	AC_1_PORT = 0;
	AC_1_TRIS = PORT_INPUT;
	AC_1_ANSEL = 0;
    
    AC_2_LAT = 0;
	AC_2_PORT = 0;
	AC_2_TRIS = PORT_INPUT;
	AC_2_ANSEL = 0;
    
    EN_1_LAT = 0;
	EN_1_PORT = 0;
	EN_1_TRIS = PORT_OUTPUT;
    
    EN_2_LAT = 0;
	EN_2_PORT = 0;
	EN_2_TRIS = PORT_OUTPUT;
}
