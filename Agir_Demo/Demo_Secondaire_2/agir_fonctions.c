/**********************************************************/
/*===================== PROJET AGIR ======================*/
/*--------------------------------------------------------*/
/*-- Projet AGIR [EI-SE4] 2014/2015 Polytech Paris'UPMC --*/
/*-- [GITHUB]: https://github.com/Hapinness/Projet_AGIR --*/
/*-- [MAIL]  :	polytech.projetagir@gmail.com           --*/
/*-- [FB]    :	Projet.Agir@groups.facebook.com         --*/
/*========================================================*/
/*----------------- [PROGRAMMEURS MAIL] ------------------*/
/*-- {Achab Lounes}      : achab.lounes@gmail.com       --*/
/*-- {Afonso Jordan}     : afonso.jordan@hotmail.fr     --*/
/*-- {Kalghdoost Afshin} : afshin_90@hotmail.fr         --*/
/*-- {Younsi Thin-hinane}: thin-hinane@hotmail.fr       --*/
/*========================================================*/
/**********************************************************/

#include <LPC23xx.H>
#include "agir_fonctions.h"
#include "agir_bus_can.h"
#include "LCD.h"
#include "agir_gpio.h"

extern char ETAT_SYSTEME[TAILLE_OCTET];
extern char contacteur_0;
extern char contacteur_1;
extern char CAN;

/**********************************************************/

void lcd_initialisation(void)
{
	lcd_init();
  	lcd_clear();
}

void afficher_carte_fille(void)
{
	char buffer[17];
	char etat =  system_scan(); 
	
	lcd_clear ();
	set_cursor (0,0);
	sprintf(buffer, "Etat_2:%d, cap:%d",etat,gpio_get_value(PORT_CAPTEUR_MARGEUR_01,PIN_CAPTEUR_MARGEUR_01));
	lcd_print(buffer);
	set_cursor (0,1);
	sprintf(buffer, "Mo:%d,Ma:%d,C:%d",contacteur_0,contacteur_1,CAN);
	lcd_print(buffer);
}


/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
