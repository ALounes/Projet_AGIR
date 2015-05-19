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
#include "agir_bp.h"
#include "agir_fonctions.h" 
#include "agir_bus_can.h" 
	

	
	
/**********************************************************/
/************ Fonctions gestion d'interuptions ************/
/**********************************************************/

void bouton_initialisation(void)
{
	PINSEL4 |= (1<<20);	//config du bouton
	EXTMODE  = 1;
	EXTPOLAR = 0;
}

void isr_bouton(void)__irq
{
	afficher_carte_fille();	// affichage infos carte fille

	EXTINT = 1;
	VICVectAddr = 0;
}




/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
