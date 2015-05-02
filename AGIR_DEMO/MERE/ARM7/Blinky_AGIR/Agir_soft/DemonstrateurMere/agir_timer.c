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
#include "agir_uart.h"
#include "agir_timer.h"
#include "agir_fonctions.h"
#include "agir_bus_can.h"

char TT = 0;

void timer_0_initialisation(void)
{
	T0MR0  = TIMER_0_FREQ;
	T0MCR |= TIMER_0_CONTROL;
}

void timer_1_initialisation(void)
{
	T1MR0  = TIMER_1_FREQ;
	T1MCR |= TIMER_1_CONTROL;
}


/**********************************************************/
/************ Fonctions gestion d'interuptions ************/
/**********************************************************/

void isr_timer0(void)__irq
{
	char buffer[TAILLE_LIGNE_LCD];

	/* affichage sur l'ecrans LCD de l'etat systeme */
	afficher_carte_fille();	
	
	T0IR = 1 ;
	VICVectAddr = 0;
}


void isr_timer1(void)__irq
{
	if(TT == 0)
		uart_emission(0xAA);
	else
		uart_emission(0xAB);
	
	TT = (TT+1)%2;
	
	T1IR = 1 ;
	VICVectAddr = 0;
}


/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
