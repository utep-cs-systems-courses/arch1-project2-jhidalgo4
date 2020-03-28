//switches.h
#ifndef switches_included
#define swithces_included

#define sw1 BIT0  //p2.0
#define sw2 BIT1  //p2.1
#define sw3 BIT2  //p2.2
#define sw4 BIT3  //p2.3
#define SWITCHES (sw1 | sw2 | sw3 | sw4)

extern char switch_state_down1, switch_state_down2, switch_state_down3, switch_state_down4;
extern unsigned char curState;

void switch_init();  //initialize
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed; //effective boolean

#endif
