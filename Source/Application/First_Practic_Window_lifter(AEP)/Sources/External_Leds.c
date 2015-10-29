/*
* Hugol_Leds.c
 *
 *  Created on: Oct 21, 2015
 *      Author: Hugol D Cervantes (Oswaldo Garcia)
 */
#include "External_Leds.h"
#include "MPC5606B.h"

void led_sysclk_init_fnc(void)
{
	//	ME.MER.R = 0x0000001D;          	/* Enable DRUN, RUN0, SAFE, RESET modes */
		
		/* Initialize PLL before turning it on: */
		
		/* Use 1 of the next 2 lines depending on crystal frequency: */
		//CGM.FMPLL_CR.R = 0x02400100;    	/* 8 MHz xtal: Set PLL0 to 64 MHz */   
		/* CGM.FMPLL_R = 0x12400100;*/     	/* 40 MHz xtal: Set PLL0 to 64 MHz */   
		char count = 0;
		char count_1 = 0;
		ME.RUN[0].R = 0x001F0074;       	/* RUN0 cfg: 16MHzIRCON,OSC0ON,PLL0ON,syclk=PLL */
		
//Definition bar leds 		
		ME.RUNPC[0].R = 0x00000010; 	  	/* Peri. Cfg. 0 settings: only run in RUN0 mode */
		ME.PCTL[0].R = 0x0000;         	/* MPC56xxB/S SIUL:  select ME.RUNPC[0] */	
		ME.PCTL[1].R = 0x0000;
		ME.PCTL[2].R = 0x0000;
		ME.PCTL[3].R = 0x0000;
		ME.PCTL[4].R = 0x0000;         	/* MPC56xxB/S SIUL:  select ME.RUNPC[0] */	
		ME.PCTL[5].R = 0x0000;
		ME.PCTL[6].R = 0x0000;
		ME.PCTL[7].R = 0x0000;
		ME.PCTL[8].R = 0x0000;
		ME.PCTL[9].R = 0x0000;

//Definition Leds internal
		ME.PCTL[68].R = 0x0000;
		ME.PCTL[69].R = 0x0000;
		ME.PCTL[70].R = 0x0000;
		ME.PCTL[71].R = 0x0000;
		
//Led Green
		ME.PCTL[10].R = 0x0000;
//Led blue
		ME.PCTL[13].R = 0x0000;
		
//		ME.RUNPC[1].R = 0x00000010;     	/* Peri. Cfg. 1 settings: only run in RUN0 mode */
//		ME.PCTL[57].R = 0x01;       		/* MPC56xxB CTUL: select ME.RUNPC[1] */
//	  	ME.PCTL[68].R = 0x01;           	/* MPC56xxB/S SIUL:  select ME.RUNPC[1] */
//			PCR PCTL
											/* Mode Transition to enter RUN0 mode: */
		ME.MCTL.R = 0x40005AF0;         	/* Enter RUN0 Mode & Key */
		ME.MCTL.R = 0x4000A50F;         	/* Enter RUN0 Mode & Inverted Key */  
		while (ME.GS.B.S_MTRANS) {}     	/* Wait for mode transition to complete */    
//		                          			/* Note: could wait here using timer and/or I_TC IRQ */
		while(ME.GS.B.S_CURRENTMODE != 4) {}/* Verify RUN0 is the current mode */
//		
		while (ME.IS.B.I_MTC != 1) {}    /* Wait for mode transition to complete */    
		ME.IS.R = 0x00000001;           /* Clear Transition flag */
		
		for(count = 0; count <= 9; count++)
		{
			SIU.PCR[count].R = 0x0201;
			SIU.GPDO[count].B.PDO = 1;
		}
		
		for(count_1 = 68; count_1 <= 71; count_1++)
		{
			SIU.PCR[count].R = 0x0201;
			SIU.GPDO[count].B.PDO = 1;
		}

}

//for delay
void delay(int num)
{
	int j;
	for(j=0; j<=num; j++){}
}


//Void led_change_status
void Led_change_status(char ch, char Led_state)
{
	SIU.GPDO[ch].B.PDO = Led_state;
}

//Funcion Subir Ventana
int Window_Up()
{
	  int k = 0;
	  for (;;k++) 
	  {
		Led_change_status(LED1, LED_on);
	    delay(10000);
		Led_change_status(LED2, LED_on);
	    delay(10000);
		Led_change_status(LED3, LED_on);
	    delay(100000);
	    Led_change_status(LED4, LED_on);
	    delay(1000000);
	    Led_change_status(LED5, LED_on);
	     delay(10000000);

		Led_change_status(LED1,LED_off);
		delay(1000);
		Led_change_status(LED2,LED_off);
		delay(10000);
		Led_change_status(LED3,LED_off);
		delay(100000);
		Led_change_status(LED2,LED_off);
		delay(1000000);
		Led_change_status(LED3,LED_off);
		delay(10000000);
		Led_change_status(LED4,LED_off);
		delay(1000000);
		Led_change_status(LED5,LED_off);
		delay(10000000);
		
		
		        Led_change_status(LED_1, LED_on);
			    delay(10000);
		        Led_change_status(LED_1, LED_off);
			    delay(10000);
				Led_change_status(LED_2, LED_on);
			    delay(10000);
		        Led_change_status(LED_2, LED_off);
			    delay(10000);
				Led_change_status(LED_3, LED_on);
			    delay(100000);
		        Led_change_status(LED_3, LED_off);
			    delay(10000);
			    Led_change_status(LED_4, LED_on);
			    delay(1000000);
		        Led_change_status(LED_4, LED_off);
			    delay(10000);
		
  }

}


