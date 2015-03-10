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

/******************************************/
/**** Fonctions gestion d'interuptions ****/
/******************************************/

void isr_bouton(void)__irq
{
	if (ETAT == 0)
	{
		ETAT = 1;
		can_emission(111, 11);
	}
	else 
	{
		ETAT = 0;
		can_emission(222,22);
	}

	EXTINT = 1;
	VICVectAddr = 0;
}

void isr_timer0(void)__irq
{
	char buffer[17];
	
	/* Affichage reception */
	sprintf(buffer,"MSG: %d",RECEPTION);
	lcd_clear();
	lcd_print(buffer);
	
	T0IR = 1 ;
	VICVectAddr = 0;
}

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

	init_vic();
	
	T0TCR = 1;

	while(1);
	
	return 1;
}
