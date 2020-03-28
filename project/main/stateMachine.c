//stateMachine.c file
#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

static char stateOfWDT = 0;

//display 1 in binary LED
char state1_unknown(){
  if(!green_on & red_on){
    return 0;
  }
  green_on = 0;
  red_on = 1;
  return 1;
}


//display 2 with LED in binary
char state2_light(){
  if(!red_on & green_on){
    return 0;
  }
  red_on = 0;
  green_on = 1;
  
  //show lights
  return 1;
}

//display 3 with LED in binary
char state3_noise(){
  if(red_on & green_on){
    return 0;
  }
  red_on = 1;
  green_on = 1;
  
  //play noises
  return 1;
}

//play long song and dim lights somehow
char state4_dim(){
  if (!red_on & !green_on){
    return 0;
  }
  red_on = 0;
  green_on = 0;
  
  //dim light
  return 1;
}

// Parameter st is the state of the machine depending on the button pushed
void state_advance(){
  char changed = 0;   //Is this needed? //update yes it is lol  
  switch(curState){
  case 1: changed = state1_unknown(); break;
  case 2: changed = state2_light(); break;
  case 3: changed = state3_noise(); break;  //3rd state
  case 4: changed = state4_dim(); break; //4th state
    

  }
  led_changed = changed;
  led_update(); //double led_update from also switches.c, this one seems more valuable thou?!
  
}

//NOT USED RN
//void wdt_advance(){
//  switch(stateOfWDT){
//  case 0: stateOfWDT = 1; break;
//  case 1: stateOfWDT = 2; break;
//  case 2: stateOfWDT = 3; break;
//  case 3: stateOfWDT = 4; break;
//  }
//}
