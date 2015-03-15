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
#include "agir_bp.h"

/**********************************************************/
/************ Fonctions gestion d'interuptions ************/
/**********************************************************/

void bouton_initialisation(void)
{
	PINSEL  |= (1<<20);
	EXTMODE  = 1;
	EXTPOLAR = 0;
}

void isr_bouton(void)__irq
{

	bouton_traitement();

	EXTINT = 1;
	VICVectAddr = 0;
}

void bouton_traitement(void)
{
	// A FAIRE 
}



/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
