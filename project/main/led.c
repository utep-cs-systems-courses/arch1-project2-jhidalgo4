//led.c
#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachine.h" // is this needed, not calling this method hmmm

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;

static char redVal[]={0,LED_RED}, greenVal[] = {0,LED_GREEN};

void led_init(){
  P1DIR |= LEDS;  //bits in LEDS are outputs
  led_changed = 1;
  led_update();

}


//Blink update
void led_update(){
  if(led_changed){
    char ledFlags = redVal[red_on] | greenVal[green_on];
    P1OUT &= (0xff^LEDS) | ledFlags; //clear bit for OFF Leds
    P1OUT |= ledFlags;  //set bit for ON Leds
    led_changed = 0;
  }

}

//Button update
//  void led_update(){
//    if(switch_state_changed){
//      char ledFlags = 0;  //by deafult, no led's on
//      ledFlags |= switch_state_down ? LED_GREEN:0;
//      ledFlags switch_state_down ? 0:LED_RED;
//      P1OUT &= (0xff-LEDS) | ledFlags; //clear bits for off leds
//      P1OUT |= ledFlags; //set bits for on LED
//  }
//    switch_state_changed = 0;
//}
  

  
