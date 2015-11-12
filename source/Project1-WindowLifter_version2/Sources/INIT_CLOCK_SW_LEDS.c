/*
 * INIT_CLOCK_SW_LEDS.c
 *
 *  Created on: Nov 4, 2015
 *      Author: HP 240
 */


#include "reset_clean.h"


void INIT_CLOCK_SW_LEDS()
{
	char count_ini; 
	ME.RUN[0].R = 0x001F0074;       	/* RUN0 cfg: 16MHzIRCON,OSC0ON,PLL0ON,syclk=PLL */
	ME.RUNPC[0].R = 0x00000010; 	  	/* Peri. Cfg. 0 settings: only run in RUN0 mode */
	ME.PCTL[64].R = 0x0000;         	/* MPC56xxB/S SIUL:  select ME.RUNPC[0] */	
	ME.PCTL[65].R = 0x0000;
	ME.PCTL[66].R = 0x0000;
	ME.PCTL[67].R = 0x0000;
	ME.PCTL[68].R = 0x0000;         	/* MPC56xxB/S SIUL:  select ME.RUNPC[0] */	
	ME.PCTL[69].R = 0x0000;
	ME.PCTL[70].R = 0x0000;
	ME.PCTL[71].R = 0x0000;
										/* Mode Transition to enter RUN0 mode: */
	ME.MCTL.R = 0x40005AF0;         	/* Enter RUN0 Mode & Key */
	ME.MCTL.R = 0x4000A50F;         	/* Enter RUN0 Mode & Inverted Key */  

	 /* INIT_BOARD_BUTTONS*/
	for(count_ini = 64; count_ini <= 67; count_ini++)
	{
		SIU.PCR[count_ini].R = 0x0101;
		
	}
	 /* INIT_BOARD_LEDS*/
	for(count_ini = 68; count_ini <= 71; count_ini++)
		{
			SIU.PCR[count_ini].R = 0x0201;
			SIU.GPDO[count_ini].B.PDO = 1;
		}
	
	for(count_ini = 0; count_ini <= 11; count_ini++)
			{
				SIU.PCR[count_ini].R = 0x0201;
				SIU.GPDO[count_ini].B.PDO = 0;
			}		
}


