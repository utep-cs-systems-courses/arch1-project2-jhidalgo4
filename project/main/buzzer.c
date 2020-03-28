//buzer.c file
#include <msp430.h>
#include "../timerLib/libTimer.h"
#include "buzzer.h"
#include "switches.h"
#include "stateMachine.h" //not sure if this one is needed


//NOTES
#define N_A 440
#define N_B 494
#define N_C 523
#define N_D 587
#define N_E 659
#define N_F 698
#define N_G 784
#define N_As 466
#define N_Cs 554
#define N_Ds 622
#define N_Fs 740
#define N_Gs 831


//5 octive
int note[15] = {N_B, N_Cs, N_E, N_Gs, N_Ds, N_B, N_Fs, N_Gs, N_E, N_B, N_E, N_B, N_Ds, N_B, N_E }; //15 in length

int note2[9] = {N_Cs, N_As, N_Gs, N_E, N_E, N_Fs, N_Gs, N_Cs, N_Cs}; // 9 in length

void buzzer_init(){ 
  timerAUpmode(); //use|d to drive speaker
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;  //enable output to P2.6
}

void buzzer_set_period(short cycles){
  CCR0 =cycles;
  CCR1 =cycles >>1; //one half cycle
}


// 2MHz clock cycle
void play_noise(){
  switch(curState){

    //plays short tune like video game
  case 1:
    for(int i =0; i<4;i++){
      buzzer_set_period(note[i] );
      __delay_cycles(100000);
    }
    buzzer_set_period(0); //makes it stop
    break;

    
    //plays short tune like video game
  case 2:
    for(int i =0; i<4;i++){
      buzzer_set_period(note2[i]);
      __delay_cycles(500000);
    }
    buzzer_set_period(0);
    break;

    
    //plays a song by Deadmau5
  case 3:
    for(int i =0; i<9; i++){
      buzzer_set_period(note2[i]);
      __delay_cycles(2000000);
    }
    buzzer_set_period(0);
    break;
    

  //plays a 2nd song of Deadmau5
  case 4:
    for(int i =0; i<15;i++){
      buzzer_set_period(note[i] );
      __delay_cycles(8000000);
    }
    buzzer_set_period(0);
  break;
  }
}
