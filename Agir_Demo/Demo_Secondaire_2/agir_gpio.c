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
#include "agir_gpio.h"
#include "agir_bus_can.h"



extern char contacteur_0;
extern char contacteur_1;

/********Fonction d'initialisation des différents composants éléctroniques********/

void gpio_initialisation(void) 
{
	/*  Les PIN (2.X) seront tous connectés aux 15 LEDs ,
	Ces LED sont également dirigés en sortie           */
	
	PINSEL4  = 0; 					// tous les pinsel sont reglé en mode GPIO
	FIO2DIR = 0XFFFFFF3F;					/* Les pins 0 à 13 sont réglés en sortie 
														correspondant aux LEDs  de 1 à 14 */
	
	/* Les PIN (3.X) seront coonectés aux 5 boutons   
	poussoires et aux 5 contacteurs  									*/
	
	PINSEL6  = 0;
	//PINSEL7  = 0X00000000;
	FIO3DIR |= 0XF6000000;
	/*FIO3DIR &= ~(1<<0);
	FIO3DIR &= ~(1<<1);
	FIO3DIR &= ~(1<<3);*/
	
	/* Les PIN (4.x) seront connectés aux capteurs */
	PINSEL8  = 0X00000000;
}



/********* Fonction de Mise en route ********/
// numero_pin : choix du numero de port a manipuler
// numero_pin   : choix de la broche dans le port choisie

void gpio_out_on (unsigned int numero_port, unsigned int numero_pin) 
{
	switch(numero_port)
	{
		case P0:
			FIO0SET |= (1<<numero_pin) ;
			break;
		
		case P1:
			FIO1SET |= (1<<numero_pin) ;
			break;
				
		case P2:
			FIO2SET |= (1<<numero_pin) ;
			break;
		
		case P3:
			FIO3SET |= (1<<numero_pin) ;
			break;
				
		case P4:
			FIO4SET |= (1<<numero_pin) ;
			break;
		
		default :
			// ERREUR CHOIX DE PIN
			break;
	}
}

/******** Fonction de Mise en veille ********/
// numero_port : choix du numero de port a manipuler
// numero_pin   : choix de la broche dans le port choisie

void gpio_out_off (unsigned int numero_port, unsigned int numero_pin) 
{
	switch(numero_port)
	{
		case P0:
			FIO0CLR |= (1<<numero_pin) ;
			break;
		
		case P1:
			FIO1CLR |= (1<<numero_pin) ;
			break;
				
		case P2:
			FIO2CLR |= (1<<numero_pin) ;
			break;
		
		case P3:
			FIO3CLR |= (1<<numero_pin) ;
			break;
				
		case P4:
			FIO4CLR |= (1<<numero_pin) ;
			break;
		
		default :
			// ERREUR CHOIX DE PIN
			break;
	}
}

/******** Fonction de lecture de valeur ********/
// numero_port  : choix du numero de port a manipuler
// numero_pin   : choix de la broche dans le port choisie

char gpio_get_value(unsigned int numero_port, unsigned int numero_pin) 
{
	char pin_value;

	switch(numero_port)
	{
		case P0:
			pin_value = (FIO0PIN >> numero_pin) & 1;
			break;
		
		case P1:
			pin_value = (FIO1PIN >> numero_pin) & 1;
			break;
				
		case P2:
			pin_value = (FIO2PIN >> numero_pin) & 1;
			break;
		
		case P3:
			pin_value = (FIO3PIN >> numero_pin) & 1;
			break;
				
		case P4:
			pin_value = (FIO4PIN >> numero_pin) & 1;
			break;
		
		default :
			// ERREUR CHOIX DE PIN
			pin_value = -1;
			break;
	}

	return pin_value;
}

void led_capteur(int margeur,int etat)
{
	switch(margeur)
	{
		case MARGEUR_01:
				if(etat == ON)
					gpio_out_on(PORT_LED_MARGEUR_01_ORANGE, PIN_LED_MARGEUR_01_ORANGE);
				else
					gpio_out_off(PORT_LED_MARGEUR_01_ORANGE, PIN_LED_MARGEUR_01_ORANGE);					
			break;

		case MARGEUR_02:
				if(etat == ON)
					gpio_out_on(PORT_LED_MARGEUR_02_ORANGE, PIN_LED_MARGEUR_02_ORANGE);
				else
					gpio_out_off(PORT_LED_MARGEUR_02_ORANGE, PIN_LED_MARGEUR_02_ORANGE);
			break;

		case MARGEUR_03:
				if(etat == ON)
					gpio_out_on(PORT_LED_MARGEUR_03_ORANGE, PIN_LED_MARGEUR_03_ORANGE);
				else
					gpio_out_off(PORT_LED_MARGEUR_03_ORANGE, PIN_LED_MARGEUR_03_ORANGE);
			break;

		case MARGEUR_04:
				if(etat == ON)
					gpio_out_on(PORT_LED_MARGEUR_04_ORANGE, PIN_LED_MARGEUR_04_ORANGE);
				else
					gpio_out_off(PORT_LED_MARGEUR_04_ORANGE, PIN_LED_MARGEUR_04_ORANGE);
			break;

		default:
			break;		
	}
}

void set_led_margeur_00(int etat_margeur)
{
	switch(etat_margeur)
	{
		case LED_GREEN:
			gpio_out_off (PORT_LED_MARGEUR_00_GREEN , PIN_LED_MARGEUR_00_GREEN );
			gpio_out_on(PORT_LED_MARGEUR_00_RED   , PIN_LED_MARGEUR_00_RED   );
			gpio_out_on(PORT_LED_MARGEUR_00_ORANGE, PIN_LED_MARGEUR_00_ORANGE);
			break;
	
		case LED_RED:
			gpio_out_on(PORT_LED_MARGEUR_00_GREEN , PIN_LED_MARGEUR_00_GREEN );
			gpio_out_off (PORT_LED_MARGEUR_00_RED   , PIN_LED_MARGEUR_00_RED   );
			gpio_out_on(PORT_LED_MARGEUR_00_ORANGE, PIN_LED_MARGEUR_00_ORANGE);
			break;

		case LED_ORANGE:
			gpio_out_on(PORT_LED_MARGEUR_00_GREEN , PIN_LED_MARGEUR_00_GREEN );
			gpio_out_on(PORT_LED_MARGEUR_00_RED   , PIN_LED_MARGEUR_00_RED   );
			gpio_out_off (PORT_LED_MARGEUR_00_ORANGE, PIN_LED_MARGEUR_00_ORANGE);
			break;

		default:
			break;
	}
}

void set_led_margeur_01(int etat_margeur)
{
	switch(etat_margeur)
	{
		case LED_GREEN:
			gpio_out_off (PORT_LED_MARGEUR_01_GREEN , PIN_LED_MARGEUR_01_GREEN );
			gpio_out_on(PORT_LED_MARGEUR_01_RED   , PIN_LED_MARGEUR_01_RED   );
			gpio_out_on(PORT_LED_MARGEUR_01_ORANGE, PIN_LED_MARGEUR_01_ORANGE);
			break;
	
		case LED_RED:
			gpio_out_on(PORT_LED_MARGEUR_01_GREEN , PIN_LED_MARGEUR_01_GREEN );
			gpio_out_off (PORT_LED_MARGEUR_01_RED   , PIN_LED_MARGEUR_01_RED   );
			gpio_out_on(PORT_LED_MARGEUR_01_ORANGE, PIN_LED_MARGEUR_01_ORANGE);
			break;

		case LED_ORANGE:
			gpio_out_on(PORT_LED_MARGEUR_01_GREEN , PIN_LED_MARGEUR_01_GREEN );
			gpio_out_on(PORT_LED_MARGEUR_01_RED   , PIN_LED_MARGEUR_01_RED   );
			gpio_out_off (PORT_LED_MARGEUR_01_ORANGE, PIN_LED_MARGEUR_01_ORANGE);
			break;

		default:
			break;
	}
}

void set_led_margeur_02(int etat_margeur)
{
	switch(etat_margeur)
	{
		case LED_GREEN:
			gpio_out_on (PORT_LED_MARGEUR_02_GREEN , PIN_LED_MARGEUR_02_GREEN );
			gpio_out_off(PORT_LED_MARGEUR_02_RED   , PIN_LED_MARGEUR_02_RED   );
			gpio_out_off(PORT_LED_MARGEUR_02_ORANGE, PIN_LED_MARGEUR_02_ORANGE);
			break;
	
		case LED_RED:
			gpio_out_off(PORT_LED_MARGEUR_02_GREEN , PIN_LED_MARGEUR_02_GREEN );
			gpio_out_on (PORT_LED_MARGEUR_02_RED   , PIN_LED_MARGEUR_02_RED   );
			gpio_out_off(PORT_LED_MARGEUR_02_ORANGE, PIN_LED_MARGEUR_02_ORANGE);
			break;

		case LED_ORANGE:
			gpio_out_off(PORT_LED_MARGEUR_02_GREEN , PIN_LED_MARGEUR_02_GREEN );
			gpio_out_off(PORT_LED_MARGEUR_02_RED   , PIN_LED_MARGEUR_02_RED   );
			gpio_out_on (PORT_LED_MARGEUR_02_ORANGE, PIN_LED_MARGEUR_02_ORANGE);
			break;

		default:
			break;
	}
}

void set_led_margeur_03(int etat_margeur)
{
	switch(etat_margeur)
	{
		case LED_GREEN:
			gpio_out_on (PORT_LED_MARGEUR_03_GREEN , PIN_LED_MARGEUR_03_GREEN );
			gpio_out_off(PORT_LED_MARGEUR_03_RED   , PIN_LED_MARGEUR_03_RED   );
			gpio_out_off(PORT_LED_MARGEUR_03_ORANGE, PIN_LED_MARGEUR_03_ORANGE);
			break;
	
		case LED_RED:
			gpio_out_off(PORT_LED_MARGEUR_03_GREEN , PIN_LED_MARGEUR_03_GREEN );
			gpio_out_on (PORT_LED_MARGEUR_03_RED   , PIN_LED_MARGEUR_03_RED   );
			gpio_out_off(PORT_LED_MARGEUR_03_ORANGE, PIN_LED_MARGEUR_03_ORANGE);
			break;

		case LED_ORANGE:
			gpio_out_off(PORT_LED_MARGEUR_03_GREEN , PIN_LED_MARGEUR_03_GREEN );
			gpio_out_off(PORT_LED_MARGEUR_03_RED   , PIN_LED_MARGEUR_03_RED   );
			gpio_out_on (PORT_LED_MARGEUR_03_ORANGE, PIN_LED_MARGEUR_03_ORANGE);
			break;

		default:
			break;
	}
}

void set_led_margeur_04(int etat_margeur)
{
	switch(etat_margeur)
	{
		case LED_GREEN:
			gpio_out_on (PORT_LED_MARGEUR_04_GREEN , PIN_LED_MARGEUR_04_GREEN );
			gpio_out_off(PORT_LED_MARGEUR_04_RED   , PIN_LED_MARGEUR_04_RED   );
			gpio_out_off(PORT_LED_MARGEUR_04_ORANGE, PIN_LED_MARGEUR_04_ORANGE);
			break;
	
		case LED_RED:
			gpio_out_off(PORT_LED_MARGEUR_04_GREEN , PIN_LED_MARGEUR_04_GREEN );
			gpio_out_on (PORT_LED_MARGEUR_04_RED   , PIN_LED_MARGEUR_04_RED   );
			gpio_out_off(PORT_LED_MARGEUR_04_ORANGE, PIN_LED_MARGEUR_04_ORANGE);
			break;

		case LED_ORANGE:
			gpio_out_off(PORT_LED_MARGEUR_04_GREEN , PIN_LED_MARGEUR_04_GREEN );
			gpio_out_off(PORT_LED_MARGEUR_04_RED   , PIN_LED_MARGEUR_04_RED   );
			gpio_out_on (PORT_LED_MARGEUR_04_ORANGE, PIN_LED_MARGEUR_04_ORANGE);
			break;

		default:
			break;
	}
}

void set_led_margeur(int margeur, int etat_margeur)
{
	switch(margeur)
	{
		case MARGEUR_00:
			set_led_margeur_00(etat_margeur);
			break;

		case MARGEUR_01:
			set_led_margeur_01(etat_margeur);
			break;

		case MARGEUR_02:
			set_led_margeur_02(etat_margeur);
			break;

		case MARGEUR_03:
			set_led_margeur_03(etat_margeur);
			break;

		case MARGEUR_04:
			set_led_margeur_04(etat_margeur);
			break;

		default:
			break;	
	}
}

void led_all_red(void)
{
	set_led_margeur(MARGEUR_00, LED_RED);
	set_led_margeur(MARGEUR_01, LED_RED);
	set_led_margeur(MARGEUR_02, LED_RED);
	set_led_margeur(MARGEUR_03, LED_RED);
	set_led_margeur(MARGEUR_04, LED_RED);
}

void led_all_green(void)
{
	set_led_margeur(MARGEUR_00, LED_GREEN);
	set_led_margeur(MARGEUR_01, LED_GREEN);
	set_led_margeur(MARGEUR_02, LED_GREEN);
	set_led_margeur(MARGEUR_03, LED_GREEN);
	set_led_margeur(MARGEUR_04, LED_GREEN);	
}

void led_all_orange(void)
{
	set_led_margeur(MARGEUR_00, LED_ORANGE);
	set_led_margeur(MARGEUR_01, LED_ORANGE);
	set_led_margeur(MARGEUR_02, LED_ORANGE);
	set_led_margeur(MARGEUR_03, LED_ORANGE);
	set_led_margeur(MARGEUR_04, LED_ORANGE);
}


void set_relais_margeur(int relais, int etat_relais)
{
	switch(relais)
	{
		case MARGEUR_00:
			if (etat_relais == ON)
				gpio_out_on(PORT_RELAIS_MARGEUR_00,PIN_RELAIS_MARGEUR_00);
			else
				gpio_out_off(PORT_RELAIS_MARGEUR_00,PIN_RELAIS_MARGEUR_00);
			break;
	
		case MARGEUR_01:
			if (etat_relais == ON)
				gpio_out_on(PORT_RELAIS_MARGEUR_01,PIN_RELAIS_MARGEUR_01);
			else
				gpio_out_off(PORT_RELAIS_MARGEUR_01,PIN_RELAIS_MARGEUR_01);
			break;

		case MARGEUR_02:
			if (etat_relais == ON)
				gpio_out_on(PORT_RELAIS_MARGEUR_02,PIN_RELAIS_MARGEUR_02);
			else
				gpio_out_off(PORT_RELAIS_MARGEUR_02,PIN_RELAIS_MARGEUR_02);
			break;

		case MARGEUR_03:
			if (etat_relais == ON)
				gpio_out_on(PORT_RELAIS_MARGEUR_03,PIN_RELAIS_MARGEUR_03);
			else
				gpio_out_off(PORT_RELAIS_MARGEUR_03,PIN_RELAIS_MARGEUR_03);
			break;

		case MARGEUR_04:
			if (etat_relais == ON)
				gpio_out_on(PORT_RELAIS_MARGEUR_04,PIN_RELAIS_MARGEUR_04);
			else
				gpio_out_off(PORT_RELAIS_MARGEUR_04,PIN_RELAIS_MARGEUR_04);
			break;

		default:
			break;
	}
}

void gpio_all_out_off(void)
{
	// Contacteur OFF 
	relais_all_off();

	// Led Turned on a RED value
	led_all_red();
}

void relais_all_on(void)
{
	set_relais_margeur(MARGEUR_00, ON);
	set_relais_margeur(MARGEUR_01, ON);
	set_relais_margeur(MARGEUR_02, ON);
	set_relais_margeur(MARGEUR_03, ON);
	set_relais_margeur(MARGEUR_04, ON);
}

void relais_all_off(void)
{
	set_relais_margeur(MARGEUR_00, OFF);
	set_relais_margeur(MARGEUR_01, OFF);
	set_relais_margeur(MARGEUR_02, OFF);
	set_relais_margeur(MARGEUR_03, OFF);	
	set_relais_margeur(MARGEUR_04, OFF);	
}

void gpio_affichage(unsigned int numero_port, unsigned int numero_pin) 
{
	static char str_01[TAILLE_ECRAN];
	static char str_02[TAILLE_ECRAN];
	char pin_value;

	// Recuperation de la veleur du pin
	pin_value = gpio_get_value(numero_port, numero_pin);
	

	// 1ere ligne de l'afficheur 

	set_cursor (1, 0);

	sprintf(str_02,"GPIO : P%d.%d",numero_port,numero_pin);

	lcd_print (str_01);


	// 2 eme ligne de l'afficheur 
	set_cursor (0, 1);

	if (pin_value == -1)
	{
		sprintf(str_02,"Erreur Lecture");
	}
	else
	{
		if (pin_value == OFF)
			sprintf(str_02,"Value : Low");
		else
			sprintf(str_02,"Value : Hight");
	}		

	lcd_print (str_02);
}


/*********************************************************/

int bp_traitement(void)
{
	int arret_urgence = 0;

	if(gpio_get_value(PORT_BP_MARGEUR_00,PIN_BP_MARGEUR_00) == 0)
	{
		ETAT_SYSTEME[0] = 0;
		arret_urgence   =-1;
	}
	else
	{
		// Correspond au bouton d'arret d'urgence !! 
		ETAT_SYSTEME[0] |= 1;

		// Correspond au 4 margeur 
		ETAT_SYSTEME[0] =  (ETAT_SYSTEME[0] & 0xFD) + (gpio_get_value(PORT_BP_MARGEUR_01,PIN_BP_MARGEUR_01) << 1);
		ETAT_SYSTEME[0] =  (ETAT_SYSTEME[0] & 0xFB) + (gpio_get_value(PORT_BP_MARGEUR_02,PIN_BP_MARGEUR_02) << 2);
		ETAT_SYSTEME[0] =  (ETAT_SYSTEME[0] & 0xF7) + (gpio_get_value(PORT_BP_MARGEUR_03,PIN_BP_MARGEUR_03) << 3);
		ETAT_SYSTEME[0] =  (ETAT_SYSTEME[0] & 0xEF) + (gpio_get_value(PORT_BP_MARGEUR_04,PIN_BP_MARGEUR_04) << 4);
	}

		arret_urgence = ETAT_SYSTEME[0];
	return arret_urgence;
}

void relais_traitement(void)
{
	// SI le BP du margeur 0 est en oFF tout est en OFF
	if (ETAT_SYSTEME[0] == 0)
		relais_all_off();
	else
	{
		// ON test pour chaque margeur si son BP correspondant n'est pas en OFF
		// et on recopie la valeur de la commande
		if( ((ETAT_SYSTEME[0] >> 0) & 1) != 0 )
			set_relais_margeur(MARGEUR_00, (ETAT_SYSTEME[1] >> 0) & 1);

		if( ((ETAT_SYSTEME[0] >> 1) & 1) != 0 )
			set_relais_margeur(MARGEUR_01, (ETAT_SYSTEME[1] >> 1) & 1);

		if( ((ETAT_SYSTEME[0] >> 2) & 1) != 0 )
			set_relais_margeur(MARGEUR_02, (ETAT_SYSTEME[1] >> 2) & 1);

		if( ((ETAT_SYSTEME[0] >> 3) & 1) != 0 )
			set_relais_margeur(MARGEUR_03, (ETAT_SYSTEME[1] >> 3) & 1);

		if( ((ETAT_SYSTEME[0] >> 4) & 1) != 0 )
			set_relais_margeur(MARGEUR_04, (ETAT_SYSTEME[1] >> 4) & 1);
	}
}

void capteur_traitement(void)
{
		ETAT_SYSTEME[2] = (ETAT_SYSTEME[2] & 0xFE)+ (gpio_get_value(PORT_CAPTEUR_MARGEUR_01,PIN_CAPTEUR_MARGEUR_01) << 0);
		if (((ETAT_SYSTEME[2] >> 0) & 1) == 1)
			led_capteur(MARGEUR_01,ON);
		else
			led_capteur(MARGEUR_01,OFF);

		ETAT_SYSTEME[2] = (ETAT_SYSTEME[2] & 0xFC)+ (gpio_get_value(PORT_CAPTEUR_MARGEUR_02,PIN_CAPTEUR_MARGEUR_02) << 1);
		if (((ETAT_SYSTEME[2] >> 1) & 1) == 1)
			led_capteur(MARGEUR_02,ON);
		else
			led_capteur(MARGEUR_02,OFF);

		ETAT_SYSTEME[2] = (ETAT_SYSTEME[2] & 0xFB)+ (gpio_get_value(PORT_CAPTEUR_MARGEUR_03,PIN_CAPTEUR_MARGEUR_03) << 2);
		if (((ETAT_SYSTEME[2] >> 2) & 1) == 1)
			led_capteur(MARGEUR_03,ON);
		else
			led_capteur(MARGEUR_03,OFF);

		ETAT_SYSTEME[2] = (ETAT_SYSTEME[2] & 0xF7)+ (gpio_get_value(PORT_CAPTEUR_MARGEUR_04,PIN_CAPTEUR_MARGEUR_04) << 3);
		if (((ETAT_SYSTEME[2] >> 3) & 1) == 1)
			led_capteur(MARGEUR_04,ON);
		else
			led_capteur(MARGEUR_04,OFF);
}
	
void led_traitement(void)
{
		// SI le BP du margeur 0 est en oFF tout est en OFF
	if (ETAT_SYSTEME[1] == 0)
		led_all_red();
	else
	{
		// ON test pour chaque margeur si son BP correspondant n'est pas en OFF
		// et on recopie la valeur de la commande
		if( ((ETAT_SYSTEME[1] >> 0) & 1) == 0 )
			set_led_margeur_00(LED_RED);
		else
			set_led_margeur_00(LED_GREEN);

		if( ((ETAT_SYSTEME[1] >> 1) & 1) == 0 )
			set_led_margeur_01(LED_RED);
		else
			set_led_margeur_01(LED_GREEN);

		if( ((ETAT_SYSTEME[1] >> 2) & 1) == 0 )
			set_led_margeur_02(LED_RED);
		else
			set_led_margeur_02(LED_GREEN);

		if( ((ETAT_SYSTEME[1] >> 3) & 1) == 0 )
			set_led_margeur_03(LED_RED);
		else
			set_led_margeur_03(LED_GREEN);

		if( ((ETAT_SYSTEME[1] >> 4) & 1) == 0 )
			set_led_margeur_04(LED_RED);
		else
			set_led_margeur_04(LED_GREEN);
	}
}

/*********************************************************************/


void gpio_traitement(void)
{	
	// gestion des led pour le moteur
	if ((gpio_get_value(PORT_BP_MOTEUR,PIN_BP_MOTEUR) == ON) && (!contacteur_0))
		set_led_margeur(MOTEUR,LED_ORANGE);
	else if ((gpio_get_value(PORT_BP_MOTEUR,PIN_BP_MOTEUR) == ON) && (contacteur_0))
		set_led_margeur(MOTEUR,LED_GREEN);
	else 
		set_led_margeur(MOTEUR,LED_RED);
	
	// gestion des led pour le margeur
	if ((gpio_get_value(PORT_BP_MARGEUR,PIN_BP_MARGEUR) == ON) && (!contacteur_1)&& ((gpio_get_value(PORT_BP_MOTEUR,PIN_BP_MOTEUR) == ON) && (contacteur_0)))
		set_led_margeur(MARGEUR_01,LED_ORANGE); 
	else if ((gpio_get_value(PORT_BP_MARGEUR,PIN_BP_MARGEUR) == ON) && (contacteur_1) && ((gpio_get_value(PORT_BP_MOTEUR,PIN_BP_MOTEUR) == ON) && (contacteur_0)))
		set_led_margeur(MARGEUR_01,LED_GREEN);		
	else
		set_led_margeur(MARGEUR_01,LED_RED);
}

/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/

