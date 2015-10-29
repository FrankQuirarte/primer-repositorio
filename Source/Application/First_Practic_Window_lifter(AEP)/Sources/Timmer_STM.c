/*
* Hugol_Leds.c
 *
 *  Created on: Oct 21, 2015
 *      Author: Hugol D Cervantes (Oswaldo Garcia)
 */

#include "Timmer_STM.h"
#include "MPC5606B.h"

//Funcion configuracion del timmer
void STMconfig(){
	STM.CNT.R = 0; 
	STM.CH[0].CMP.R = 0x2625A001;
	STM.CH[0].CCR.B.CEN = 1;
	STM.CR.B.FRZ = 0;
	STM.CR.B.CPS = 0;
	STM.CR.B.TEN = 1;
}
