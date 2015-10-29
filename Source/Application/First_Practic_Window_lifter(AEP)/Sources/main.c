/*
 * Hugol_main.h
 * First_program_demo
 *
 *  Created on: Oct 21, 2015
 *      Author: Hugol D Cervantes (Oswaldo Garcia)
 */

#include "MPC5606B.h"
#include "Hugol_DEFINITIONs.h"
#include "External_Leds.h"
#include "Timmer_STM.h"


//Variables para checar el .MAP

  int g;
  static int statica;
  extern int externa;
  volatile int volatileee;
  //register int registro;
 

//Main Function
	int main(void) {
  volatile int i = 0;
  
  led_sysclk_init_fnc();
  

  
  

  /* Loop forever */
/*for (;;) {
    i++;
  }*/
  Window_Up(); //Funcion abrir ventana
  //STMconfig(); //Funcion timeer
  
  while(!STM.CH[0].CIR.B.CIF);
  Led_change_status(LED_1, LED_on);
  
  for (;;i++) 
  {}
  

  
return 0;

}

