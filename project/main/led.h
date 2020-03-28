//led.h file
#ifndef led_included
#define led_included

#include <msp430.h>
#define LED_RED BIT0 //p1.0
#define LED_GREEN BIT6 //p1.6
#define LEDS (BIT0 | BIT6)

void led_init(); //initialize
void led_update();

extern unsigned char red_on, green_on;
extern unsigned char green_led_state, red_led_state; //boolean flags??
extern unsigned char led_changed;

#endif
