/**********************************************************/
/*===================== PROJET AGIR ======================*/
/*--------------------------------------------------------*/
/*-- Projet AGIR [EI-SE4] 2014/2015 Polytech Paris'UPMC --*/
/*-- [GITHUB]: https://github.com/Hapinness/Projet_AGIR --*/
/*-- [MAIL]  :	polytech.projetagir@gmail.com            --*/
/*-- [FB]    :	Projet.Agir@groups.facebook.com          --*/
/*========================================================*/
/*----------------- [PROGRAMMEURS MAIL] ------------------*/
/*-- {Achab Lounes}      : achab.lounes@gmail.com       --*/
/*-- {Afonso Jordan}     : afonso.jordan@hotmail.fr     --*/
/*-- {Kalghdoost Afshin} : afshin_90@hotmail.fr         --*/
/*-- {Younsi Thin-hinane}: thin-hinane@hotmail.fr       --*/
/*========================================================*/
/**********************************************************/

#include <stdio.h>  
#include "agir_main.h"

/******************************************/
/********* INITIALISATION DU VIC **********/
/******************************************/

void init_vic(void)
{
	VICVectAddr4  = (unsigned long)isr_timer0;
	VICVectAddr14 = (unsigned long)isr_bouton; 
	VICVectAddr23 = (unsigned long)can_reception;

	VICIntEnable |= 1<<4;  // Timer_0 
	VICIntEnable |= 1<<14; // Bouton
	VICIntEnable |= 1<<23; // CAN
}


/******************************************/
/************* FCT PRINCIPALE *************/
/******************************************/

int main(void)
{
	timer_0_initialisation();
	timer_1_initialisation();
	bouton_initialisation();
	//gpio_initialisation();
	uart_initialisation();
	can_initialisation();
	lcd_initialisation();

	vic_initialisation();
	
	T0TCR = 1;
	T1TCR = 1;

	while(1);
	
	return 1;
}



/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
