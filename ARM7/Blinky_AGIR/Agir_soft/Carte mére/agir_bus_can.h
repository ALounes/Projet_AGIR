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

	#define NBR_MODULE    4
	#define TAILLE_MODULE 4

	/* Idetificateur pour le module 00 */
	#define ID_MODULE_0_SECTION_0  00
	#define ID_MODULE_0_SECTION_1  01
	#define ID_MODULE_0_SECTION_2  02
	#define ID_MODULE_0_SECTION_3  03

	/* Idetificateur pour le module 01 */
	#define ID_MODULE_1_SECTION_0  10
	#define ID_MODULE_1_SECTION_1  11
	#define ID_MODULE_1_SECTION_2  12
	#define ID_MODULE_1_SECTION_3  13

	/* Idetificateur pour le module 02 */
	#define ID_MODULE_2_SECTION_0  10
	#define ID_MODULE_2_SECTION_1  11
	#define ID_MODULE_2_SECTION_2  12
	#define ID_MODULE_2_SECTION_3  13

	/* Idetificateur pour le module 03 */
	#define ID_MODULE_3_SECTION_0  10
	#define ID_MODULE_3_SECTION_1  11
	#define ID_MODULE_3_SECTION_2  12
	#define ID_MODULE_3_SECTION_3  13

	// Variables Globales

	char ETAT_SYSTEME[NBR_MODULE][TAILLE_MODULE];

	// DECLARATION DES PRO

	void can_initialisation(void);
	void isr_can_reception(void)__irq;
	void can_emission(unsigned long valeur ,unsigned char id_message);

#endif

/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
