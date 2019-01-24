/*
 * ATS Port Definitions
 * 
 * @Company
 *   ATS Team
 * 
 * @File Name
 *   ports.h
 * 
 * @Summary
 *   Defines the IO ports used by the hardware.
*/

#include <xc.h>

#ifndef PORTS_H
#define	PORTS_H

#define LED_1_LAT      LATGbits.LATG6
#define LED_1_PORT     PORTGbits.RG6
#define LED_1_TRIS     TRISGbits.TRISG6
#define LED_1_ANSEL    ANSELGbits.ANSG6

#define LED_2_LAT      LATGbits.LATG7
#define LED_2_PORT     PORTGbits.RG7
#define LED_2_TRIS     TRISGbits.TRISG7
#define LED_2_ANSEL    ANSELGbits.ANSG7

#define LED_3_LAT      LATGbits.LATG8
#define LED_3_PORT     PORTGbits.RG8
#define LED_3_TRIS     TRISGbits.TRISG8
#define LED_3_ANSEL    ANSELGbits.ANSG8

#define AC_1_LAT       LATBbits.LATB2
#define AC_1_PORT      PORTBbits.RB2
#define AC_1_TRIS      TRISBbits.TRISB2
#define AC_1_ANSEL     ANSELBbits.ANSB2

#define AC_2_LAT       LATBbits.LATB3
#define AC_2_PORT      PORTBbits.RB3
#define AC_2_TRIS      TRISBbits.TRISB3
#define AC_2_ANSEL     ANSELBbits.ANSB3

#define EN_1_LAT      LATEbits.LATE0
#define EN_1_PORT     PORTEbits.RE0
#define EN_1_TRIS     TRISEbits.TRISE0

#define EN_2_LAT      LATEbits.LATE1
#define EN_2_PORT     PORTEbits.RE1
#define EN_2_TRIS     TRISEbits.TRISE1


#define PORT_INPUT  1
#define PORT_OUTPUT 0

#define PIN_DIGITAL 0
#define PIN_ANALOG  1

#define PIN_ON      1
#define PIN_OFF     0


#ifdef	__cplusplus
extern "C"
{
#endif


void ports_init(void);


#ifdef	__cplusplus
}
#endif

#endif /* PORTS_H */
