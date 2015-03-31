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


/********Fonction d'initialisation des différents composants éléctroniques********/
void gpio_initialisation(void) 
{
	/*  Les PIN (2.X) seront tous connectés aux 15 LEDs ,
	Ces LED sont également dirigés en sortie           */
	
	PINSEL4  = 0X00000000; 					// tous les pinsel sont reglé en mode GPIO
	FIO2DIR |= 0XFFFF3FFF;					/* Les pins 0 à 13 sont réglés en sortie 
														correspondant aux LEDs  de 1 à 14 */
	
	/* Les PIN (3.X) seront coonectés aux 5 boutons   
	poussoires et aux 5 contacteurs  									*/
	
	PINSEL6  = 0X00000000;
	PINSEL7  = 0X00000000;
	FIO3DIR |= 0XF60000FF;
	
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
			pin_value = (FIO0PIN << numero_pin) & 1;
			break;
		
		case P1:
			pin_value = (FIO1PIN << numero_pin) & 1;
			break;
				
		case P2:
			pin_value = (FIO2PIN << numero_pin) & 1;
			break;
		
		case P3:
			pin_value = (FIO3PIN << numero_pin) & 1;
			break;
				
		case P4:
			pin_value = (FIO4PIN << numero_pin) & 1;
			break;
		
		default :
			// ERREUR CHOIX DE PIN
			pin_value = -1;
			break;
	}

	return pin_value;
}


void set_led_margeur_00(int etat_margeur)
{
	switch(etat_margeur)
	{
		case LED_GREEN:
			gpio_out_on (PORT_LED_MARGEUR_00_GREEN , PIN_LED_MARGEUR_00_GREEN );
			gpio_out_off(PORT_LED_MARGEUR_00_RED   , PIN_LED_MARGEUR_00_RED   );
			gpio_out_off(PORT_LED_MARGEUR_00_ORANGE, PIN_LED_MARGEUR_00_ORANGE);
			break;
	
		case LED_RED:
			gpio_out_off(PORT_LED_MARGEUR_00_GREEN , PIN_LED_MARGEUR_00_GREEN );
			gpio_out_on (PORT_LED_MARGEUR_00_RED   , PIN_LED_MARGEUR_00_RED   );
			gpio_out_off(PORT_LED_MARGEUR_00_ORANGE, PIN_LED_MARGEUR_00_ORANGE);
			break;

		case LED_ORANGE:
			gpio_out_off(PORT_LED_MARGEUR_00_GREEN , PIN_LED_MARGEUR_00_GREEN );
			gpio_out_off(PORT_LED_MARGEUR_00_RED   , PIN_LED_MARGEUR_00_RED   );
			gpio_out_on (PORT_LED_MARGEUR_00_ORANGE, PIN_LED_MARGEUR_00_ORANGE);
			break

		default:
			break;
	}
}

void set_led_margeur_01(int etat_margeur)
{
	switch(etat_margeur)
	{
		case LED_GREEN:
			gpio_out_on (PORT_LED_MARGEUR_01_GREEN , PIN_LED_MARGEUR_01_GREEN );
			gpio_out_off(PORT_LED_MARGEUR_01_RED   , PIN_LED_MARGEUR_01_RED   );
			gpio_out_off(PORT_LED_MARGEUR_01_ORANGE, PIN_LED_MARGEUR_01_ORANGE);
			break;
	
		case LED_RED:
			gpio_out_off(PORT_LED_MARGEUR_01_GREEN , PIN_LED_MARGEUR_01_GREEN );
			gpio_out_on (PORT_LED_MARGEUR_01_RED   , PIN_LED_MARGEUR_01_RED   );
			gpio_out_off(PORT_LED_MARGEUR_01_ORANGE, PIN_LED_MARGEUR_01_ORANGE);
			break;

		case LED_ORANGE:
			gpio_out_off(PORT_LED_MARGEUR_01_GREEN , PIN_LED_MARGEUR_01_GREEN );
			gpio_out_off(PORT_LED_MARGEUR_01_RED   , PIN_LED_MARGEUR_01_RED   );
			gpio_out_on (PORT_LED_MARGEUR_01_ORANGE, PIN_LED_MARGEUR_01_ORANGE);
			break

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
			break

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
			break

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
			break

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
		case RELAIS_00:
			if (etat_relais == RELAIS_ON)
				gpio_out_on(PORT_RELAIS_MARGEUR_00,PIN_RELAIS_MARGEUR_00);
			else
				gpio_out_off(PORT_RELAIS_MARGEUR_00,PIN_RELAIS_MARGEUR_00);
			break;
	
		case RELAIS_01:
			if (etat_relais == RELAIS_ON)
				gpio_out_on(PORT_RELAIS_MARGEUR_01,PIN_RELAIS_MARGEUR_01);
			else
				gpio_out_off(PORT_RELAIS_MARGEUR_01,PIN_RELAIS_MARGEUR_01);
			break;

		case RELAIS_02:
			if (etat_relais == RELAIS_ON)
				gpio_out_on(PORT_RELAIS_MARGEUR_02,PIN_RELAIS_MARGEUR_02);
			else
				gpio_out_off(PORT_RELAIS_MARGEUR_02,PIN_RELAIS_MARGEUR_02);
			break

		case RELAIS_03:
			if (etat_relais == RELAIS_ON)
				gpio_out_on(PORT_RELAIS_MARGEUR_03,PIN_RELAIS_MARGEUR_03);
			else
				gpio_out_off(PORT_RELAIS_MARGEUR_03,PIN_RELAIS_MARGEUR_03);
			break

		case RELAIS_04:
			if (etat_relais == RELAIS_ON)
				gpio_out_on(PORT_RELAIS_MARGEUR_04,PIN_RELAIS_MARGEUR_04);
			else
				gpio_out_off(PORT_RELAIS_MARGEUR_04,PIN_RELAIS_MARGEUR_04);
			break

		default:
			break;
	}
}

void gpio_all_out_off(void)
{
	// Contacteur OFF 
	relais_all_off();

	// Led Turned on a RED value
	led_all_off();
}

void relais_all_on(void)
{
	set_relais_margeur(RELAIS_00, RELAIS_ON);
	set_relais_margeur(RELAIS_01, RELAIS_ON);
	set_relais_margeur(RELAIS_02, RELAIS_ON);
	set_relais_margeur(RELAIS_03, RELAIS_ON);
}

void relais_all_off(void)
{
	set_relais_margeur(RELAIS_00, RELAIS_OFF);
	set_relais_margeur(RELAIS_01, RELAIS_OFF);
	set_relais_margeur(RELAIS_02, RELAIS_OFF);
	set_relais_margeur(RELAIS_03, RELAIS_OFF);	
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

	lcd_print (str);


	// 2 eme ligne de l'afficheur 
	set_cursor (0, 1);

	if (pin_value == -1)
	{
		sprintf(str_02,"Erreur Lecture");
	}
	else
	{
		if (pin_value == LEVEL_LOW)
			sprintf(str_02,"Value : Low");
		else
			sprintf(str_02,"Value : Hight");
	}		

	lcd_print (str);
}


/*********************************************************/

void gpio_traitement(void)
{
	int arret_urgence;
	
	arret_urgence = bp_traitement();

	if(arret_urgence == -1)
	{
		gpio_all_out_off();
	}
	else
	{
		relais_traitement();
		capteur_traitement();
		led_traitement();
	}
}

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
		ETAT_SYSTEME[0] = gpio_get_value(PORT_BP_MARGEUR_00,PIN_BP_MARGEUR_00);

		// Correspond au 4 margeur 
		ETAT_SYSTEME[0] = (ETAT_SYSTEME[0] & 0xFE)+ (gpio_get_value(PORT_BP_MARGEUR_01,PIN_BP_MARGEUR_01) << 1);
		ETAT_SYSTEME[0] = (ETAT_SYSTEME[0] & 0xFD)+ (gpio_get_value(PORT_BP_MARGEUR_02,PIN_BP_MARGEUR_02) << 2);
		ETAT_SYSTEME[0] = (ETAT_SYSTEME[0] & 0xFB)+ (gpio_get_value(PORT_BP_MARGEUR_03,PIN_BP_MARGEUR_03) << 3);
		ETAT_SYSTEME[0] = (ETAT_SYSTEME[0] & 0xF7)+ (gpio_get_value(PORT_BP_MARGEUR_04,PIN_BP_MARGEUR_04) << 4);
	}

	return arret_urgence;
}

void relais_traitement(void)
{
	if (ETAT_SYSTEME[0] == 0)
		relais_all_off(void)
	else
	{
		set_relais_margeur(MARGEUR_00, (ETAT_SYSTEME[0] >> 0) & 1);
		set_relais_margeur(MARGEUR_01, (ETAT_SYSTEME[0] >> 1) & 1);
		set_relais_margeur(MARGEUR_02, (ETAT_SYSTEME[0] >> 2) & 1);
		set_relais_margeur(MARGEUR_03, (ETAT_SYSTEME[0] >> 3) & 1);
		set_relais_margeur(MARGEUR_04, (ETAT_SYSTEME[0] >> 4) & 1);
	}
}

/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
