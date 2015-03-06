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
#include "agir_gpio.h"


/********Fonction d'initialisation des différents composants éléctroniques********/
void gpio_initialisation(void) 
{
	/*  Les PIN (2.X) seront tous connectés aux 15 LEDs ,
	Ces LED sont également dirigés en sortie           */
	
	PINSEL4 = 0X00000000; 					// tous les pinsel sont reglé en mode GPIO
	FIO2DIR |= 0XFFFF3FFF;					/* Les pins 0 à 13 sont réglés en sortie 
																		 correspondant aux LEDs  de 1 à 14 */
	
	/* Les PIN (3.X) seront coonectés aux 5 boutons   
	poussoires et aux 5 contacteurs  									*/
	
	PINSEL6 = 0X00000000;
	PINSEL7 = 0X00000000;
	FIO3DIR |= 0XF60000FF;
	
	/* Les PIN (4.x) seront connectés aux capteurs */
	PINSEL8 = 0X00000000;
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

