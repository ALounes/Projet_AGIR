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


/**********************************************************/
/************ Fonctions gestion d'interuptions ************/
/**********************************************************/

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


/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
