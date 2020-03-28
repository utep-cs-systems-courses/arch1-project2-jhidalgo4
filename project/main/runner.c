//Joaquin Hidalgo
//Main file -> runner.c
#include <msp430.h>
#include "../timerLib/libTimer.h"   //clock timer
#include "buzzer.h"   //buzzer
#include "led.h"   //led's
#include "switches.h"   //switches & buttons


int main(void){
  configureClocks(); //setup mast OSC, CPU & periperal clocks
  
  buzzer_init();
  // Should I inlucde this method from demo?
  //buzzer_set_period(int); //start buzzing
  switch_init();
  led_init();
  
  enableWDTInterrupts();

  or_sr(0x18); //CPU off, GIE on
}
