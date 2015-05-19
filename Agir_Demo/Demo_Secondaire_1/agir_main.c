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
#include <LPC23xx.H> 
#include "agir_main.h"
#include "agir_fonctions.h"
#include "agir_bus_can.h"
#include "agir_timer.h"
#include "agir_gpio.h"
#include "agir_bp.h"


// Def Variables glob
char ETAT_SYSTEME[TAILLE_OCTET];


/******************************************/
/********* INITIALISATION DU VIC **********/
/******************************************/

void vic_initialisation(void)
{
	VICVectAddr4  = (unsigned long)isr_timer0;
	VICVectAddr5  = (unsigned long)isr_timer1;
	VICVectAddr14 = (unsigned long)isr_bouton; 
	VICVectAddr23 = (unsigned long)isr_can_reception;

	VICIntEnable |= 1<<4;  // Timer_0 
	VICIntEnable |= 1<<5;  // Timer_1 
	VICIntEnable |= 1<<14; // Bouton
	VICIntEnable |= 1<<23; // CAN
}


/******************************************/
/************* FCT PRINCIPALE *************/
/******************************************/

int main(void)
{
	
	timer_0_initialisation();
	//timer_1_initialisation();
	bouton_initialisation();
	gpio_initialisation();
	can_initialisation();
	lcd_initialisation();

	vic_initialisation();
	
	T0TCR = 1;
	T1TCR = 1;
	
	set_led_margeur(MARGEUR_00,LED_RED);
	set_led_margeur(MARGEUR_01,LED_RED);
	while(1)
	{
		gpio_traitement();
	};
	
	return 1;
}



/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
