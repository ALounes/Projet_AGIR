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

extern int ETAT_SYSTEME[TAILLE_MODULE];

/**********************************************************/

void lcd_initialisation(void)
{
	lcd_init();
  	lcd_clear();
}

void afficher_carte_fille(void)
{
	char buffer[17];

	lcd_clear ();
	set_cursor (0,0);
	sprintf(buffer, "LED:%d CON:%d",ETAT_SYSTEME[0],ETAT_SYSTEME[1]);
	lcd_print(buffer);
	set_cursor (0,1);
	sprintf(buffer, "BOT:%d CAP:%d",ETAT_SYSTEME[2],ETAT_SYSTEME[3]);
	lcd_print(buffer);
}


/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
