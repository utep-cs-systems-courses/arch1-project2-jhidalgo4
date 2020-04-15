//led.c
#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachine.h" // is this needed, not calling this method hmmm

unsigned char red_on = 0, green_on = 0, new_green_on = 0, new_red_on = 0;
unsigned char led_changed = 0;
static char pwCount= 0;

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

void switched_light(){
  //if the updated state of lights differs and update lights
  if (green_on != new_green_on || red_on != new_red_on){
    red_on = new_red_on;
    green_on = new_green_on;
    led_changed = 1;
  }
  //both new led states are the same as previoud
  if (new_green_on == green_on && new_red_on == red_on){
    red_on = new_red_on;
    green_on = new_green_on;
    led_changed = 1;
  }
}

//show binary bit 2 (red)
char state1_red(){
  new_green_on = 0;
  new_red_on = 1;
  switched_light();
  if(led_changed) return 1;
  return 0;
}

//Show binary bit 1(green)
char state2_green(){
  new_green_on = 1;
  new_red_on = 0;
  switched_light();
  if(led_changed) return 1;
  return 0;
}

//DIM the LIGHTS
//show binary bit number 3 (both)
char state3_bothOn(){
  pwCount = (pwCount +1) % 5; //0,1,2,3 or 4. change to 8 or higher to get flikering lights
  new_green_on = (pwCount <1); //turn green on only 1/14 of the time
  new_red_on = (pwCount <1); //only turn on 1/14 of the time
  switched_light();
  if(led_changed) return 1;
  return 0;
}

char state4_bothOff(){
  new_green_on = 0;
  new_red_on = 0;
  switched_light();
  if(led_changed) return 1;
  return 0;
}

  

  
