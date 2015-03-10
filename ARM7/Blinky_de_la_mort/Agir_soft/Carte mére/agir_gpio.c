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


void gpio_all_out_off(void)
{
	// Contacteur OFF 
	gpio_out_off(,);
	gpio_out_off(,); 
	gpio_out_off(,);
	gpio_out_off(,); 
	gpio_out_off(,);

	// Led Turned on a RED value
	led_all_off();
}

void led_all_off(void)
{
	led_margeur_set(MARGEUR_00, LED_RED);
	led_margeur_set(MARGEUR_01, LED_RED);
	led_margeur_set(MARGEUR_02, LED_RED);
	led_margeur_set(MARGEUR_03, LED_RED);
	led_margeur_set(MARGEUR_04, LED_RED);
}

void led_all_on(void)
{
	led_margeur_set(MARGEUR_00, LED_GREEN);
	led_margeur_set(MARGEUR_01, LED_GREEN);
	led_margeur_set(MARGEUR_02, LED_GREEN);
	led_margeur_set(MARGEUR_03, LED_GREEN);
	led_margeur_set(MARGEUR_04, LED_GREEN);	
}

void led_all_XX(void)
{
	led_margeur_set(MARGEUR_00, LED_ORANGE);
	led_margeur_set(MARGEUR_01, LED_ORANGE);
	led_margeur_set(MARGEUR_02, LED_ORANGE);
	led_margeur_set(MARGEUR_03, LED_ORANGE);
	led_margeur_set(MARGEUR_04, LED_ORANGE);
}

void led_margeur_set(int margeur, int etat_margeur)
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

void set_led_margeur_00(int etat_margeur)
{
	switch(etat_margeur)
	{
		case LED_GREEN:
			gpio_out_on (PORT_LED_MAGEUR_00_GREEN , PIN_LED_MAGEUR_00_GREEN );
			gpio_out_off(PORT_LED_MAGEUR_00_RED   , PIN_LED_MAGEUR_00_RED   );
			gpio_out_off(PORT_LED_MAGEUR_00_ORANGE, PIN_LED_MAGEUR_00_ORANGE);
			break;
	
		case LED_RED:
			gpio_out_off(PORT_LED_MAGEUR_00_GREEN , PIN_LED_MAGEUR_00_GREEN );
			gpio_out_on (PORT_LED_MAGEUR_00_RED   , PIN_LED_MAGEUR_00_RED   );
			gpio_out_off(PORT_LED_MAGEUR_00_ORANGE, PIN_LED_MAGEUR_00_ORANGE);
			break;

		case LED_ORANGE:
			gpio_out_off(PORT_LED_MAGEUR_00_GREEN , PIN_LED_MAGEUR_00_GREEN );
			gpio_out_off(PORT_LED_MAGEUR_00_RED   , PIN_LED_MAGEUR_00_RED   );
			gpio_out_on (PORT_LED_MAGEUR_00_ORANGE, PIN_LED_MAGEUR_00_ORANGE);
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
			gpio_out_on (PORT_LED_MAGEUR_01_GREEN , PIN_LED_MAGEUR_01_GREEN );
			gpio_out_off(PORT_LED_MAGEUR_01_RED   , PIN_LED_MAGEUR_01_RED   );
			gpio_out_off(PORT_LED_MAGEUR_01_ORANGE, PIN_LED_MAGEUR_01_ORANGE);
			break;
	
		case LED_RED:
			gpio_out_off(PORT_LED_MAGEUR_01_GREEN , PIN_LED_MAGEUR_01_GREEN );
			gpio_out_on (PORT_LED_MAGEUR_01_RED   , PIN_LED_MAGEUR_01_RED   );
			gpio_out_off(PORT_LED_MAGEUR_01_ORANGE, PIN_LED_MAGEUR_01_ORANGE);
			break;

		case LED_ORANGE:
			gpio_out_off(PORT_LED_MAGEUR_01_GREEN , PIN_LED_MAGEUR_01_GREEN );
			gpio_out_off(PORT_LED_MAGEUR_01_RED   , PIN_LED_MAGEUR_01_RED   );
			gpio_out_on (PORT_LED_MAGEUR_01_ORANGE, PIN_LED_MAGEUR_01_ORANGE);
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
			gpio_out_on (PORT_LED_MAGEUR_02_GREEN , PIN_LED_MAGEUR_02_GREEN );
			gpio_out_off(PORT_LED_MAGEUR_02_RED   , PIN_LED_MAGEUR_02_RED   );
			gpio_out_off(PORT_LED_MAGEUR_02_ORANGE, PIN_LED_MAGEUR_02_ORANGE);
			break;
	
		case LED_RED:
			gpio_out_off(PORT_LED_MAGEUR_02_GREEN , PIN_LED_MAGEUR_02_GREEN );
			gpio_out_on (PORT_LED_MAGEUR_02_RED   , PIN_LED_MAGEUR_02_RED   );
			gpio_out_off(PORT_LED_MAGEUR_02_ORANGE, PIN_LED_MAGEUR_02_ORANGE);
			break;

		case LED_ORANGE:
			gpio_out_off(PORT_LED_MAGEUR_02_GREEN , PIN_LED_MAGEUR_02_GREEN );
			gpio_out_off(PORT_LED_MAGEUR_02_RED   , PIN_LED_MAGEUR_02_RED   );
			gpio_out_on (PORT_LED_MAGEUR_02_ORANGE, PIN_LED_MAGEUR_02_ORANGE);
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
			gpio_out_on (PORT_LED_MAGEUR_03_GREEN , PIN_LED_MAGEUR_03_GREEN );
			gpio_out_off(PORT_LED_MAGEUR_03_RED   , PIN_LED_MAGEUR_03_RED   );
			gpio_out_off(PORT_LED_MAGEUR_03_ORANGE, PIN_LED_MAGEUR_03_ORANGE);
			break;
	
		case LED_RED:
			gpio_out_off(PORT_LED_MAGEUR_03_GREEN , PIN_LED_MAGEUR_03_GREEN );
			gpio_out_on (PORT_LED_MAGEUR_03_RED   , PIN_LED_MAGEUR_03_RED   );
			gpio_out_off(PORT_LED_MAGEUR_03_ORANGE, PIN_LED_MAGEUR_03_ORANGE);
			break;

		case LED_ORANGE:
			gpio_out_off(PORT_LED_MAGEUR_03_GREEN , PIN_LED_MAGEUR_03_GREEN );
			gpio_out_off(PORT_LED_MAGEUR_03_RED   , PIN_LED_MAGEUR_03_RED   );
			gpio_out_on (PORT_LED_MAGEUR_03_ORANGE, PIN_LED_MAGEUR_03_ORANGE);
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
			gpio_out_on (PORT_LED_MAGEUR_04_GREEN , PIN_LED_MAGEUR_04_GREEN );
			gpio_out_off(PORT_LED_MAGEUR_04_RED   , PIN_LED_MAGEUR_04_RED   );
			gpio_out_off(PORT_LED_MAGEUR_04_ORANGE, PIN_LED_MAGEUR_04_ORANGE);
			break;
	
		case LED_RED:
			gpio_out_off(PORT_LED_MAGEUR_04_GREEN , PIN_LED_MAGEUR_04_GREEN );
			gpio_out_on (PORT_LED_MAGEUR_04_RED   , PIN_LED_MAGEUR_04_RED   );
			gpio_out_off(PORT_LED_MAGEUR_04_ORANGE, PIN_LED_MAGEUR_04_ORANGE);
			break;

		case LED_ORANGE:
			gpio_out_off(PORT_LED_MAGEUR_04_GREEN , PIN_LED_MAGEUR_04_GREEN );
			gpio_out_off(PORT_LED_MAGEUR_04_RED   , PIN_LED_MAGEUR_04_RED   );
			gpio_out_on (PORT_LED_MAGEUR_04_ORANGE, PIN_LED_MAGEUR_04_ORANGE);
			break

		default:
			break;
	}
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

	lcd_print (str);}
}

