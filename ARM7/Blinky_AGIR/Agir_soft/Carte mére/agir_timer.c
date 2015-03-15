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
#include "agir_timer.h"

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
	
	/* Lancement des communication avec les modules */
	comunication_module();
	
	T0IR = 1 ;
	VICVectAddr = 0;
}


void isr_timer1(void)__irq
{
	char buffer[TAILLE_LIGNE_LCD];
	
	/* affichage sur l'ecrans LCD de l'etat systeme */
	affichage_carte_mere();
	
	T1IR = 1 ;
	VICVectAddr = 0;
}


/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
