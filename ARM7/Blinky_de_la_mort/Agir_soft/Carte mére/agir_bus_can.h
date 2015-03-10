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

#ifndef AGIR_BUS_CAN_H
#define AGIR_BUS_CAN_H

	#include <LPC23xx.H>

	#define SIZE_MSG 	    1

	#define ID_MODULE_01  1
	#define ID_MODULE_02  2
	#define ID_MODULE_03  3
	#define ID_MODULE_04  4

	#define NBR_MODULE    4
	#define TAILLE_MODULE 4

	unsigned long CAN_RECEPTION;
	char ETAT[NBR_MODULE][TAILLE_MODULE];

	// DECLARATION DES PRO

	void can_initialisation(void);
	void isr_can_reception(void)__irq;
	void can_emission(unsigned long valeur ,unsigned char id_message);


/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
