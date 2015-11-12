/*
 * reset_clean.c
 *
 *  Created on: Nov 4, 2015
 *      Author: HP 240
 */

#include "reset_clean.h"


void reset_clean_ch0(){
	  STM.CNT.R = 0; 
	  STM.CH[0].CIR.B.CIF = 1;
}

void reset_clean_ch3(){
	  STM.CNT.R = 0; 
	  STM.CH[3].CIR.B.CIF = 1;
}


void reset_clean_ch2(){
	  STM.CNT.R = 0; 
	  STM.CH[2].CIR.B.CIF = 1;
}


void reset_clean_ch1(){
	  STM.CNT.R = 0; 
		  STM.CH[1].CIR.B.CIF = 1;
}
