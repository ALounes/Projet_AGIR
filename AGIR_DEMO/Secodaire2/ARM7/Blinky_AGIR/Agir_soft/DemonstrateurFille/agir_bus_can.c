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
#include "agir_bus_can.h"
#include "agir_gpio.h"

/**********************************************************/
/********************* Initialisation *********************/
/**********************************************************/
#define ID_MERE 0xAF
#define ID_MODULE_01 0xA1
#define ID_MODULE_02 0xA2
#define ID_MODULE ID_MODULE_02

#define CAPTEUR_ON 	0xBB

char contacteur_0 = 0;
char contacteur_1 = 0;


void can_initialisation(void)
{
	PCONP		|= 1<<13; 	 // allumage CAN
	PINSEL0	|= 0x05; 	   // configuration broche
	CAN1MOD  = 0x01;		 // mode 1 can 
	CAN1BTR	 = 0x450000; // debit de 1MHZ
	CAN1IER	 = 0x01; 	   // autorise les interuptions RX
	CAN_AFMR = 0x02; 	   // desactive le filtre CAN1
	CAN1MOD	 = 0x00;  	 // mode 0 can 
}

/**********************************************************/
/************** Fonctions d'envoie de donnees *************/
/**********************************************************/

void can_emission(unsigned long valeur ,unsigned char id_message)
{
	if(CAN1SR & 0x400)
	{
		CAN1TFI2 = 0x10000	;  // Taille data 1 octet
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
	
	if ( id_message == ID_MERE )
	{	
		switch(CAN1RDA)
		{
			case RQST_MODULE_1_NUM_1:
				rqst_moteur_on();
				break;

			case RQST_MODULE_1_NUM_2:
				rqst_moteur_off();
				break;

			case RQST_MODULE_1_NUM_3:
				rqst_margeur_on();	
				break;
			
			case RQST_MODULE_1_NUM_4:
				rqst_margeur_off();
				break;
			
			case RQST_MODULE_1_NUM_5:
				rqst_etat_systeme();
				break;
				
			/* ERREUR */
			default:	
				break;
		}
	
	}	
	CAN1CMR 	   = 0x4; // vide buffer RX
	VICVectAddr = 0x0;
}

void rqst_moteur_on(void)
{
		contacteur_0 = 1;
		/*
		gpio_out_on(PORT_MOTEUR,PIN_MOTEUR);   // MOTEUR ON
		set_led_margeur(MOTEUR,LED_GREEN); 		 // mise a jour de l'affichage led des moteur
		*/
}

void rqst_moteur_off(void)
{
		contacteur_0 = 0;
		contacteur_1 = 0;
	/*
	gpio_out_off(PORT_MOTEUR,PIN_MOTEUR);   // MOTEUR OFF
	gpio_out_off(PORT_MARGEUR,PIN_MARGEUR); // MARGEUR OFF
	
	set_led_margeur(MOTEUR,LED_ORANGE);
	set_led_margeur(MARGEUR_01,LED_ORANGE);
	*/
}

void rqst_margeur_on(void)
{
	contacteur_1 = 1;
	/*
	gpio_out_on(PORT_MARGEUR,PIN_MARGEUR);  // margeur ON
	set_led_margeur(MARGEUR_01,LED_GREEN);  // LED Margeur GREEN
	*/
}

void rqst_margeur_off(void)
{
	contacteur_1 = 0;
	/*
	gpio_out_on(PORT_MARGEUR,PIN_MARGEUR);   // margeur ON
	set_led_margeur(MARGEUR_01,LED_ORANGE);  // LED Margeur ORANGE
	*/
}

void rqst_etat_systeme(void)
{
	char etat_systeme = 0;
	
	etat_systeme = system_scan();
	can_emission(etat_systeme,ID_MODULE);	
}

char system_scan(void)
{
	char etat = 0;

// recuperaion des etats des boutons 	
	if (gpio_get_value(PORT_BP_MOTEUR,PIN_BP_MOTEUR) == OFF)
			etat += 0x01;
	
	if (gpio_get_value(PORT_BP_MARGEUR,PIN_BP_MARGEUR) == OFF)
			etat += 0x02;		
	
	if ( !contacteur_0 )
			etat += 0x4;

	if ( !contacteur_1 )
			etat += 0x8;
	

	
	/*
	// recuperation des etat des contacteur
	if (gpio_get_value(PORT_MOTEUR,PIN_MOTEUR) == ON )
		etat += 0x04;	
	if (gpio_get_value(PORT_MOTEUR,PIN_MOTEUR) == ON )
		etat += 0x08;	
	*/						
	return etat;
}
/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
