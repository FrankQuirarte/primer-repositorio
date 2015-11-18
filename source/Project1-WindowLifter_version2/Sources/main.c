 
#include "DRIVERS.h"
/*comentario*/

int antipinch(int);
T_UBYTE validpress=0;							
T_UBYTE main(void) { 
  volatile int b_arriba = SIU.GPDI[SW2].B.PDI;
  volatile int b_abajo = SIU.GPDI[SW1].B.PDI;
  T_UBYTE count = 0,  automatic=0;
  int led=0, band_antipinch=0;
  INIT_CLOCK_SW_LEDS(); 
  STMconfig();
  while(1)
  {
	/******** PRINCIPAL CONDITION TO SELECT AUTOMATIC / MANUAL DOWN  ***/  
	  if(!SIU.GPDI[SW2].B.PDI)
	  {
		  reset_clean_ch0();
		  do
		  {
			  if(!STM.CH[0].CIR.B.CIF && !SIU.GPDI[SW2].B.PDI)
			  {
				  count++;
				  reset_clean_ch0();
			  }
			  
		  }while(!SIU.GPDI[SW2].B.PDI && count < 9);
		  
		  if(count >= 9){
			
			  validpress = 1;
		  }
 
		  if( validpress == 1)
		  {
		/******* SELECT DOWN One touch / Manual **************/
		/**/	  /*TURN ON LED 1 BOARD*/				   /**/
		/**/	  SIU.GPDO[69].B.PDO = LED_OFF;                  /**/
		/**/	 reset_clean_ch2();                        /**/
		/**/   while(!(STM.CH[2].CIR.B.CIF)){}	     	   /**/	
		/**/	  if(!SIU.GPDI[SW2].B.PDI)				   /**/
		/**/	  {										   /**/
		/**/		  automatic = 0;					   /**/
		/**/	  }										   /**/
		/******************************************************/
		 
	/******** ACTIVE FUNCTION DOWN AUTOMATIC *******************************/
	/**/	  else									                    /**/
	/**/	  {										                    /**/
	/**/		  automatic = 1;					                    /**/
	/**/	  }										                    /**/
	/**/		if(automatic == 1)										/**/
	/**/			{													/**/
	/**/			  while(led <= 9)										/**/
	/**/			  {													/**/
	/**/				  /* TURN OFF LED BLUE / TURN ON LED GREEN */	/**/
	/**/				  SIU.GPDO[10].B.PDO = LED_OFF; 						/**/
	/**/				  SIU.GPDO[11].B.PDO = LED_ON;						/**/
	/**/				  /*TURN OFF LED BAR AUTOMATIC*/				/**/
	/**/				  SIU.GPDO[led].B.PDO = LED_OFF;						/**/
	/**/				   reset_clean_ch1(); 							/**/
	/**/				  while(!(STM.CH[1].CIR.B.CIF)){}				/**/
	/**/				  led++;										/**/
	/**/			  }													/**/
	/**/		  }														/**/
	/**********************************************************************/
	
	/**************************** ACTIVE DOWN MANUAL **********************/		
	/**/		  else													/**/
	/**/		  {														/**/
	/**/			  while(!SIU.GPDI[SW2].B.PDI && led <= 9)			/**/
	/**/			  {   /* TURN OFF LED BLUE / TURN ON LED GREEN*/    /**/
	/**/				  SIU.GPDO[10].B.PDO = LED_OFF;                       /**/
	/**/				  SIU.GPDO[11].B.PDO = LED_ON;                       /**/
	/**/				  /*TURN OFF LED BAR STEP BY STEP*/             /**/
	/**/				  SIU.GPDO[led].B.PDO = LED_OFF;                      /**/
	/**/				  reset_clean_ch1();                            /**/
	/**/				  while(!(STM.CH[1].CIR.B.CIF)){}               /**/
	/**/				  led++;                                        /**/
	/**/			  }                                                 /**/
	/**/		  }                                                     /**/
	/**/		  count = 0;											/**/
	/**/		  validpress = 0;										/**/
	/**/		  /* TURN ON LED 1 TARGET / TURN OFF LED GREEN*/		/**/
	/**/		  SIU.GPDO[69].B.PDO = LED_ON;								/**/
	/**/		  SIU.GPDO[11].B.PDO = LED_OFF;								/**/
	/**/	  }															/**/
	/**********************************************************************/	  
	  }
	  
	  
	/***************** SELECT AUTOMATIC/ MANUAL UP ************************/  
	  
	  if(!SIU.GPDI[SW1].B.PDI)// VALIDATED PRESS BUTTON UP
	  {
		  reset_clean_ch0();
		  do
		  {
			  if(!STM.CH[0].CIR.B.CIF && !SIU.GPDI[SW1].B.PDI)
			  {
				  count++;
				  reset_clean_ch0(); 
			  } 
		  }while(!SIU.GPDI[SW1].B.PDI && count < 9);
		  
		  if(count >= 9){
			  validpress = 1;

		  }
		  if(validpress == 1)
		  {   
			  SIU.GPDO[68].B.PDO = LED_OFF;
			  /*CHECK ANTIPINCH*/
			  if(!SIU.GPDI[SW3].B.PDI)
			  {
				  led = antipinch(led);
			  }
			  /*EVALUATED TIME One touch / Manual*/
			  reset_clean_ch2(); 
			  while(!(STM.CH[2].CIR.B.CIF)){}
			  automatic=0;
			  /*CHECK ANTIPINCH*/
			  if(!SIU.GPDI[SW3].B.PDI)
			  {
				  led = antipinch(led);
			  }
			  if(!SIU.GPDI[SW1].B.PDI)
			  {
				  automatic = 0;
			  }
			  else
			  {
				  automatic = 1;
			  }
	/******  FUNCTION UP MANUAL  *******************************************/		  
	/**/		  if(automatic == 1)									/**/
	/**/		  {														/**/
	/**/			  while(led >= 0 && band_antipinch==0)				/**/
	/**/			  {													/**/
	/**/				  /*TURN OFF LED VERDE / TURN ON LED GREEN*/	/**/
	/**/				  SIU.GPDO[11].B.PDO = LED_OFF;					/**/
	/**/				  SIU.GPDO[10].B.PDO = LED_ON;					/**/
	/**/				  /* TURN ON LED BAR STEP BY STEP*/				/**/
	/**/				  SIU.GPDO[led].B.PDO = LED_ON;					/**/
	/**/				  reset_clean_ch1();							/**/
	/**/				  while(!(STM.CH[1].CIR.B.CIF)){}				/**/
	/**/				  led--;										/**/
	/**/				  /*CHECK ANTIPINCH*/							/**/
	/**/				  if(!SIU.GPDI[SW3].B.PDI)						/**/
	/**/				  {												/**/
	/**/					  led = antipinch(led);						/**/
	/**/					  band_antipinch=1;							/**/
	/**/				  }												/**/
	/**/			  }													/**/
	/**/			  band_antipinch=0;									/**/
	/**/		  }														/**/
	/**********************************************************************/		  
			  
	/***** ELSE FUNCTION ACTIVE UP AUTOMATIC   *******************************/
	/**/		else														/**/
	/**/		  {															/**/
	/**/			  while(!SIU.GPDI[SW1].B.PDI && led >= 0)				/**/
	/**/			  {														/**/
	/**/                  /*TURN OFF LED GREEN / TURN ON LED BLUE*/			/**/
    /**/				  SIU.GPDO[11].B.PDO = LED_OFF; 					/**/
    /**/			      SIU.GPDO[10].B.PDO = LED_ON;			     		/**/
    /**/				  SIU.GPDO[led].B.PDO = LED_ON;						/**/
    /**/				  reset_clean_ch1();								/**/
    /**/				  while(!(STM.CH[1].CIR.B.CIF)){}					/**/
    /**/				  led--;											/**/
    /**/				  if(!SIU.GPDI[SW3].B.PDI)//CHECK ANTIPINCH			/**/
    /**/				  {													/**/
    /**/					  led = antipinch(led);							/**/
    /**/				  }													/**/
    /**/			  }														/**/
	/**/		  }															/**/
	/**************************************************************************/
			  count = 0;
			  validpress =0;
		  }
		  /*TURN ON LED2 Trget / turn off led blue*/
		  SIU.GPDO[68].B.PDO = LED_ON;
		  SIU.GPDO[10].B.PDO = LED_OFF;
	  }//END VALIDATED SELECT AUTOMATIC / MANUAL UP
  }//END LOOP FOREVER

}//END MAIN FUNCTION

int antipinch(int led)
{  
	int count=0;
	
	//validar 10 ms

	reset_clean_ch0();
	do
	{
		if(!SIU.GPDI[SW2].B.PDI && !STM.CH[0].CIR.B.CIF )
		{
			count++;
			 reset_clean_ch0();
			}
	}while(!SIU.GPDI[SW2].B.PDI && count < 9);
	if(count >= 9){
		validpress = 1;
	}
	if(validpress == 1)
	{
		 while(led <= 9)
		 {
			 SIU.GPDO[led].B.PDO = LED_OFF;
			 reset_clean_ch1(); 
			 while(!(STM.CH[1].CIR.B.CIF)){}
			 led++;
		 }
		 reset_clean_ch3();
		 while(!(STM.CH[3].CIR.B.CIF)){}
	}
	return led;
} 
   
