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

#include "lpc23xx.h"
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
		CAN1TID2 = id_message; // id message = 40 
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
		case ID_TEST_01	:
			CAN_RECEPTION = CAN1RDA;
		 	break;

		case ID_TEST_02	:
			CAN_RECEPTION = CAN1RDA;
			break;

		default:
			CAN_RECEPTION = -1;
			break;
	}
		
	CAN1CMR 	= 0x4; // vide buffer RX
	VICVectAddr = 0x0;
}
