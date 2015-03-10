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


#define SIZE_MSG 1
#define ID_TEST_01 11
#define ID_TEST_02 22

char ETAT = 0;
unsigned long RECEPTION	;


/**********************************************************/
/********************* Initialisation *********************/
/**********************************************************/

void init_CAN(void)
{
	PCONP		|= 1<<13; 	 // allumage CAN
	PINSEL0	|= 0x05; 	 // configuration broche
	CAN1MOD 	 = 0x01;		 // mode 1 can 
	CAN1BTR	 = 0x450000; // debit de 1MHZ
	CAN1IER	 = 0x01; 	 // autorise les interuptions RX
	CAN_AFMR  =	0x02; 	 // desactive le filtre CAN1
	CAN1MOD	 =	0x00;  	 // mode 0 can 
}
