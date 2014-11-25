/***************************************************/
/******* Project AGIR [EISE4] Polytech'UPMC ********/
/******* Programme de validation du Bus Can ********/
/***************************************************/

/******************************************/
/******** Inclusion bibliotheques *********/
/******************************************/

#include "lpc23xx.h"
#include <stdio.h> 
#include "lcd.h"

#define SIZE_MSG 1
#define ID_TEST_01 11
#define ID_TEST_02 22

char ETAT = 0;
unsigned long RECEPTION	;

/******************************************/
/************ Initialisation **************/
/******************************************/

void init_CAN(void)
{
	PCONP	|=  1<<13 	; // allumage CAN
	PINSEL0	|=  0x05	; // configuration broche
	CAN1MOD  =  0x01	; // mode 1 can 
	CAN1BTR	 =  0x450000; // debit de 1MHZ
	CAN1IER	 =  0x01	; // autorise les interuptions RX
	CAN_AFMR =	0x02	; // desactive le filtre CAN1
	CAN1MOD	 =	0x00	; // mode 0 can 
}

void init_TIMER0(void)
{
	T0MR0 	 = 	12000000*0.5; // freq horloge de 0.5 S
	T0MCR	|=	3; 
}

void init_BOUTON(void)
{
	PINSEL4 |= 1<<20;
	EXTMODE  = 1;
	EXTPOLAR = 0;
}

void init_lcd (void)
{
	lcd_init()		; // initialisation
	lcd_clear()		; // clear LCD
	set_cursor(0,0)	; // position curseur
}

/******************************************/
/***** Fonctions d'envoie de donnees ******/
/******************************************/

void envoie_donnees(unsigned long valeur ,unsigned char id_message)
{
	if(CAN1SR & 0x400)
	{
		CAN1TFI2 = 0x10000	;  // Taille data 1 octet
		CAN1TID2 = id_message; // id message = 40 
		CAN1TDA2 = valeur;     // Ecriture data dans buffer TX2
		CAN1CMR  = 0x41;       // Envoie du message 	
	}
}

/******************************************/
/***** Fonctions Reception de donnees *****/
/******************************************/

void can_reception(void)__irq
{
	unsigned long id_message = (CAN1RID & 0x3FF);

	switch(id_message)
	{
		case ID_TEST_01	:
			RECEPTION = CAN1RDA;
		 	break;

		case ID_TEST_02	:
			RECEPTION = CAN1RDA;
			break;

		default:
			RECEPTION = 0;
			break;
	}
		
	CAN1CMR 	= 0x4; // vide buffer RX
	VICVectAddr = 0x0;
}

/******************************************/
/**** Fonctions gestion d'interuptions ****/
/******************************************/

void isr_bouton(void)__irq
{
	if (ETAT == 0)
	{
		ETAT = 1;
		envoie_donnees(111, 11);
	}
	else 
	{
		ETAT = 0;
		envoie_donnees(222,22);
	}

	EXTINT = 1;
	VICVectAddr = 0;
}

void isr_timer0(void)__irq
{
	char buffer[17];
	
	// A FAIRE
	
	/* Affichage reception */
	sprintf(buffer,"MSG: %d",RECEPTION);
	lcd_clear();
	lcd_print(buffer);
	
	T0IR = 1 ;
	VICVectAddr = 0;
}

/******************************************/
/********* INITIALISATION DU VIC **********/
/******************************************/

void init_vic(void)
{
	VICVectAddr4  = (unsigned long)isr_timer0;
	VICVectAddr14 = (unsigned long)isr_bouton; 
	VICVectAddr23 = (unsigned long)can_reception;

	VICIntEnable |= 1<<4;  // Timer_0 
	VICIntEnable |= 1<<14; // Bouton
	VICIntEnable |= 1<<23; // CAN
}

/******************************************/
/************* FCT PRINCIPALE *************/
/******************************************/

int main(void)
{
	init_CAN();
	init_TIMER0();
	init_BOUTON();
	init_lcd();
	init_vic();
	
	T0TCR = 1;
	while(1);
	
	return 1;
}

/***************************************************/
/******** Project AGIR [EISE4] Polytech'UPMC ********/
/******* Programme de validation du Bus Can ********/
/***************************************************/
