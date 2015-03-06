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
void initialisation(void) 
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
// decalage   : choix de la broche dans le port choisie
void OUT_ON (unsigned int numero_pin, unsigned int decalage) 
{
	switch(numero_pin)
	{
		case P0:
			FIO0SET |= (1<<decalage) ;
			break;
		
		case P1:
			FIO1SET |= (1<<decalage) ;
			break;
				
		case P2:
			FIO2SET |= (1<<decalage) ;
			break;
		
		case P3:
			FIO3SET |= (1<<decalage) ;
			break;
				
		case P4:
			FIO4SET |= (1<<decalage) ;
			break;
		
		default :
			// ERREUR CHOIX DE PIN
			break;
	}
}

/******** Fonction de Mise en veille ********/
// numero_pin : choix du numero de port a manipuler
// decalage   : choix de la broche dans le port choisie
void OUT_OFF (unsigned int numero_pin, unsigned int decalage) 
{
	switch(numero_pin)
	{
		case P0:
			FIO0CLR |= (1<<decalage) ;
			break;
		
		case P1:
			FIO1CLR |= (1<<decalage) ;
			break;
				
		case P2:
			FIO2CLR |= (1<<decalage) ;
			break;
		
		case P3:
			FIO3CLR |= (1<<decalage) ;
			break;
				
		case P4:
			FIO4CLR |= (1<<decalage) ;
			break;
		
		default :
			// ERREUR CHOIX DE PIN
			break;
	}
}

void aff_start(void) 
{
  static char str[20] ;
  sprintf(str,"Ca marche");
	set_cursor (1, 0);
	lcd_print (str);
	//set_cursor (0, 1);
	//lcd_print (str);
}
