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
extern char ETAT_1;
extern char ETAT_2;
extern char CAP_1;
extern char CAP_2;
extern char CAN;
extern char RECEPTION_BL;
extern char EMISSION_BL;

/**********************************************************/

void lcd_initialisation(void)
{
	lcd_init();
  	lcd_clear();
}

// affichage de l'état de la carte fille 
// affichage si capteur recoit une info si la carte envoie une donnée ou recoit
void afficher_carte_fille(void)
{
	char buffer[17];
	
	lcd_clear ();
	set_cursor (0,0);
	sprintf(buffer, "E1:%d ,E2:%d AGIR",ETAT_1,ETAT_2);
	lcd_print(buffer);
	set_cursor (0,1);
	sprintf(buffer, "C:%d,R:%d,E:%d",CAN,RECEPTION_BL,EMISSION_BL);
	lcd_print(buffer);
}


/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
