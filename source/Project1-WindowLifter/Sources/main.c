#include "MPC5606B.h"
#include "Drivers.h"

void inicializa_pbutt();
void STMconfig();
void delay_for(int);
int antipinch(int);
int valid_press=0;
int antipinch(int led)

{
	int cont_ms=0;
	//validar 10 ms
	STM.CNT.R = 0; //reiniciar el contador
	STM.CH[0].CIR.B.CIF = 1;//limpia
	do
	{
		if(!STM.CH[0].CIR.B.CIF && !SIU.GPDI[64].B.PDI)
		{
			cont_ms++;
			STM.CNT.R = 0; //reiniciar el contador
			STM.CH[0].CIR.B.CIF = 1;//limpia
			}
	}while(!SIU.GPDI[64].B.PDI && cont_ms<9);
	if(cont_ms >= 9){
		valid_press = 1;
	}
	if(valid_press == 1)
	{
		 while(led<=15)
		 {
			 SIU.GPDO[led].B.PDO = 0;
			 STM.CNT.R = 0; //reiniciar el contador
			 STM.CH[1].CIR.B.CIF = 1;//limpia 
			 while(!STM.CH[1].CIR.B.CIF);
			 led++;
		 }
		 STM.CNT.R = 0; //reiniciar el contador
		 STM.CH[3].CIR.B.CIF = 1;//limpia 
		 while(!STM.CH[3].CIR.B.CIF);
	}
	return led;
}

int main(void) {
  //volatile int i = 0;
  volatile int b_arriba = SIU.GPDI[64].B.PDI;
  volatile int b_abajo = SIU.GPDI[65].B.PDI;
  int cont_ms = 0, i=0, cont400=0, automatic=0;
  int led=0, band_antipinch=0;
  inicializa_pbutt();
  STMconfig();

  
  while(1)
  {
	  if(!SIU.GPDI[64].B.PDI)
	  {
		  STM.CNT.R = 0; //reiniciar el contador
		  STM.CH[0].CIR.B.CIF = 1;//limpia
		  do
		  {
			  if(!STM.CH[0].CIR.B.CIF && !SIU.GPDI[64].B.PDI)
			  {
				  cont_ms++;
				  STM.CNT.R = 0; //reiniciar el contador
				  STM.CH[0].CIR.B.CIF = 1;//limpia
			  }
			  
		  }while(!SIU.GPDI[64].B.PDI && cont_ms<9);
		  
		  if(cont_ms >= 9){
			  //cont_ms =0;
			  valid_press = 1;
		  }

		  
		  if( valid_press==1)
		  {
			  SIU.GPDO[68].B.PDO = 0; //encender led1 de la bolero
			  
			  //Evaluación de tiempo(One touch / Manual)
			  STM.CNT.R = 0; //reiniciar el contador
			  STM.CH[2].CIR.B.CIF = 1;//limpia
			  while(!STM.CH[2].CIR.B.CIF);
			  if(!SIU.GPDI[64].B.PDI)
			  {
				  automatic = 0;
			  }
			  else
			  {
				  automatic = 1;
			  }
			  

//////////////////////////////////////////////////////////////////////bajar automático one touch
			  if(automatic==1)
			  {
				  
				  while(led<=9)
				  {
					  SIU.GPDO[10].B.PDO = 0; //apaga led azul up
					  SIU.GPDO[11].B.PDO = 1;//enciende led verde down
					  
					  SIU.GPDO[led].B.PDO = 0;
					  STM.CNT.R = 0; //reiniciar el contador
					  STM.CH[1].CIR.B.CIF = 1;//limpia 
					  while(!STM.CH[1].CIR.B.CIF);
					  led++;
				  }
			  }
			  else
			  {
				  
	///////////////////////////////////////////////////////////////////////////////////////////bajar  manual
				  while(!SIU.GPDI[64].B.PDI && led<=9)
				  {
					  SIU.GPDO[10].B.PDO = 0; //apaga led azul up
					  SIU.GPDO[11].B.PDO = 1;//enciende led verde down
					  
					  SIU.GPDO[led].B.PDO = 0;
					  STM.CNT.R = 0; //reiniciar el contador
					  STM.CH[1].CIR.B.CIF = 1;//limpia 
					  while(!STM.CH[1].CIR.B.CIF);
					  led++;
				  }
				  
			  }
			  cont_ms=0;
			  valid_press=0;
			  SIU.GPDO[68].B.PDO = 1; //apagar led1 de la bolero
			  SIU.GPDO[11].B.PDO = 0;//apagar led verde down
		  }
		  
	  }
	  
	  
	  
///////////////////////////////////////////// SUBIR ////////////////////////////////////////////////////////////////////////////
	  if(!SIU.GPDI[65].B.PDI)
	  {
		  /////validar boton presionado
		  STM.CNT.R = 0; //reiniciar el contador
		  STM.CH[0].CIR.B.CIF = 1;//limpia
		  do
		  {
			  if(!STM.CH[0].CIR.B.CIF && !SIU.GPDI[65].B.PDI)
			  {
				  cont_ms++;
				  STM.CNT.R = 0; //reiniciar el contador
				  STM.CH[0].CIR.B.CIF = 1;//limpia 
			  } 
		  }while(!SIU.GPDI[65].B.PDI && cont_ms<9);
		  
		  if(cont_ms >= 9){
			 // cont_ms = 0;
			  valid_press = 1;
		  }
		  if(valid_press == 1)
		  {
			  SIU.GPDO[69].B.PDO = 0; //encender led
			  if(!SIU.GPDI[66].B.PDI)//revisar antipinch
			  {
				  led = antipinch(led);
			  }
			  //Evaluación de tiempo(One touch / Manual)
			  STM.CNT.R = 0; //reiniciar el contador
			  STM.CH[2].CIR.B.CIF = 1;//limpia
			  while(!STM.CH[2].CIR.B.CIF);
			  automatic=0;
			  if(!SIU.GPDI[66].B.PDI)//revisar antipinch
			  {
				  led = antipinch(led);
			  }
			  if(!SIU.GPDI[65].B.PDI)
			  {
				  automatic = 0;
			  }
			  else
			  {
				  automatic = 1;
			  }
			  
			  if(automatic == 1)
			  {
				  while(led>=0 && band_antipinch==0)
				  {
/////////////////////////////////////////////////////////////////////////////////subir manual 
					  SIU.GPDO[11].B.PDO = 0; //apaga led verde down
					  SIU.GPDO[10].B.PDO = 1;//enciende led azul up
					  
					  SIU.GPDO[led].B.PDO = 1;
					  STM.CNT.R = 0; //reiniciar el contador
					  STM.CH[1].CIR.B.CIF = 1;//limpia 
					  while(!STM.CH[1].CIR.B.CIF);
					  led--;
					  if(!SIU.GPDI[66].B.PDI)//revisar antipinch
					  {
						  led = antipinch(led);
						  band_antipinch=1;
					  }
				  }
				  band_antipinch=0;
			  }
			  else
			  {
				  while(!SIU.GPDI[65].B.PDI && led>=0)
				  {
/////////////////////////////////////////////////////////////////////////////////subir one touch
					  SIU.GPDO[11].B.PDO = 0; //apaga led verde down
				      SIU.GPDO[10].B.PDO = 1;//enciende led azul up
					  
					  SIU.GPDO[led].B.PDO = 1;
					  STM.CNT.R = 0; //reiniciar el contador
					  STM.CH[1].CIR.B.CIF = 1;//limpia 
					  while(!STM.CH[1].CIR.B.CIF);
					  led--;
					  if(!SIU.GPDI[66].B.PDI)//revisar antipinch
					  {
						  led = antipinch(led);
					  }

				  }
			  }
			  cont_ms=0;
			  valid_press=0;
			  
		  }
		  SIU.GPDO[69].B.PDO = 1; //apagar led2 de la bolero
		  SIU.GPDO[10].B.PDO = 0;//apagar led azul up

	  }
  }

  
  
  
}



void inicializa_pbutt()
{
	char count;


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
								
	ME.MCTL.R = 0x40005AF0;         	/* Enter RUN0 Mode & Key */
	ME.MCTL.R = 0x4000A50F;         	/* Enter RUN0 Mode & Inverted Key */  
//		while (ME.GS.B.S_MTRANS) {}     	/* Wait for mode transition to complete */    
//		                          			/* Note: could wait here using timer and/or I_TC IRQ */
//		while(ME.GS.B.S_CURRENTMODE != 4) {}/* Verify RUN0 is the current mode */
//		
//		while (ME.IS.B.I_MTC != 1) {}    /* Wait for mode transition to complete */    
//		ME.IS.R = 0x00000001;           /* Clear Transition flag */
	/*
	 * inicializar botones de la tarjeta*/
	for(count = 64; count <= 67; count++)
	{
		SIU.PCR[count].R = 0x0101;
		
	}
	/*
	 * inicializar leds de la tarjeta*/
	for(count = 68; count <= 71; count++)
		{
			SIU.PCR[count].R = 0x0201;
			SIU.GPDO[count].B.PDO = 1;
		}
	
	for(count = 0; count <= 12; count++)
			{
				SIU.PCR[count].R = 0x0201;
				SIU.GPDO[count].B.PDO = 0;
			}
				
}


void STMconfig(){
	STM.CNT.R = 0; 
	STM.CH[0].CMP.R = 0x9C401;//1msec
	STM.CH[0].CCR.B.CEN = 1;
	STM.CH[1].CMP.R = 0x186A001;//400ms
	STM.CH[1].CCR.B.CEN = 1;
	STM.CH[2].CMP.R = 0x1E84801;//500ms
	STM.CH[2].CCR.B.CEN = 1;
	STM.CH[3].CMP.R = 0x1E84801;//5 sec
	STM.CH[3].CCR.B.CEN = 1;
	STM.CR.B.FRZ = 0;
	STM.CR.B.CPS = 0;
	STM.CR.B.TEN = 1;
	
}

