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
#include "agir_bus_can.h"

/**********************************************************/
/********************* Initialisation *********************/
/**********************************************************/

void can_initialisation(void)
{
	PCONP		|= 1<<13; 	 // allumage CAN
	PINSEL0	|= 0x05; 	 // configuration broche
	CAN1MOD 	 = 0x01;		 // mode 1 can 
	CAN1BTR	 = 0x450000; // debit de 1MHZ
	CAN1IER	 = 0x01; 	 // autorise les interuptions RX
	CAN_AFMR  =	0x02; 	 // desactive le filtre CAN1
	CAN1MOD	 =	0x00;  	 // mode 0 can 
}

/**********************************************************/
/************** Fonctions d'envoie de donnees *************/
/**********************************************************/

void can_emission(unsigned long valeur ,unsigned char id_message)
{
	if(CAN1SR & 0x400)
	{
		CAN1TFI2 = 0x10000	; // Taille data 1 octet
		CAN1TID2 = id_message; // identificateur message 
		CAN1TDA2 = valeur;     // Ecriture data dans buffer TX2
		CAN1CMR  = 0x41;       // Envoie du message 	
	}
}

/**********************************************************/
/************* Fonctions Reception de donnees *************/
/**********************************************************/

void isr_can_reception(void)__irq
{
	unsigned long id_message = (CAN1RID & 0x3FF);

	switch(id_message)
	{
		/* MODULE 00 */
		case ID_MODULE_0_SECTION_0:
			ETAT_SYSTEME[0][0] = CAN1RDA;
		 	break;

		case ID_MODULE_0_SECTION_1:
			ETAT_SYSTEME[0][1] = CAN1RDA;
		 	break;

		case ID_MODULE_0_SECTION_2:
			ETAT_SYSTEME[0][2] = CAN1RDA;
		 	break;

		case ID_MODULE_0_SECTION_3:
			ETAT_SYSTEME[0][3] = CAN1RDA;
		 	break;

		/* MODULE 01 */
		case ID_MODULE_1_SECTION_0:
			ETAT_SYSTEME[1][0] = CAN1RDA;
		 	break;

		case ID_MODULE_1_SECTION_1:
			ETAT_SYSTEME[1][1] = CAN1RDA;
		 	break;

		case ID_MODULE_1_SECTION_2:
			ETAT_SYSTEME[1][2] = CAN1RDA;
		 	break;

		case ID_MODULE_1_SECTION_3:
			ETAT_SYSTEME[1][3] = CAN1RDA;
		 	break;

		/* MODULE 02 */
		case ID_MODULE_2_SECTION_0:
			ETAT_SYSTEME[2][0] = CAN1RDA;
		 	break;

		case ID_MODULE_2_SECTION_1:
			ETAT_SYSTEME[2][1] = CAN1RDA;
		 	break;

		case ID_MODULE_2_SECTION_2:
			ETAT_SYSTEME[2][2] = CAN1RDA;
		 	break;

		case ID_MODULE_2_SECTION_3:
			ETAT_SYSTEME[2][3] = CAN1RDA;
		 	break;

		/* MODULE 03 */
		case ID_MODULE_3_SECTION_0:
			ETAT_SYSTEME[3][0] = CAN1RDA;
		 	break;

		case ID_MODULE_3_SECTION_1:
			ETAT_SYSTEME[3][1] = CAN1RDA;
		 	break;

		case ID_MODULE_3_SECTION_2:
			ETAT_SYSTEME[3][2] = CAN1RDA;
		 	break;

		case ID_MODULE_3_SECTION_3:
			ETAT_SYSTEME[3][3] = CAN1RDA;
		 	break;

		/* ERREUR */
		default:
			break;
	}
		
	CAN1CMR 	   = 0x4; // vide buffer RX
	VICVectAddr = 0x0;
}


/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
