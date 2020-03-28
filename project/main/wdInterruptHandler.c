//wdInterruptHandler.c file
#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "led.h"

// Button's from New Board attached to MSP430
// All the buttons need to trigger something to execute
void
__interrupt_vec(PORT2_VECTOR) Port_2(){ // /* port 2 because we are dealing with different buttons from demo lab 1 "buttons" */
  if(P2IFG & SWITCHES ){  //did a button come to this interrupt
    P2IFG &= ~SWITCHES; //clear pending sw interrupts
    switch_interrupt_handler(); // single handler for all switches
  }
}


//Blink demo
void
__interrupt_vec(WDT_VECTOR) WDT(){  // 250 interrupts / sec
  static int blink_count = 0;
  state_advance();
  
  
  //if(++blink_count == 500){
  //  state_advance();  //Connects to stateMachine.c
  //  blink_count = 0;
  //}
  
}
  
  
