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

extern int ETAT;
extern int ETAT_SYSTEME[NBR_MODULE][TAILLE_MODULE];
extern int Affichage_module;

void comunication_module(void)
{
	int numero_requete;

	/* Recuperation du numero de la requete a partir de l'etat */	
	numero_requete = prochaine_requete(ETAT);

	/* Envoie de la requete via le bus can */
	can_emission(0, numero_requete);	

	/* Mise a jour de la variable etat */
	mise_a_jour_etat_requette();
}

void mise_a_jour_etat_requette(void)
{
	ETAT = (ETAT + 1) % (NOMBRE_MODULE_REEL * 4);
}

int prochaine_requete(const int etat)
{
	switch(etat)
	{

		/* MODULE 00 */
		case 0:
			return RQST_MODULE_0_SECTION_0;
		case 1:
			return RQST_MODULE_0_SECTION_1;
		case 2:
			return RQST_MODULE_0_SECTION_2;
		case 3:
			return RQST_MODULE_0_SECTION_3;

		/* MODULE 01 */
		case 4:
			return RQST_MODULE_1_SECTION_0;
		case 5:
			return RQST_MODULE_1_SECTION_1;
		case 6:
			return RQST_MODULE_1_SECTION_2;
		case 7:
			return RQST_MODULE_1_SECTION_3;

		/* MODULE 02 */
		case 8:
			return RQST_MODULE_2_SECTION_0;
		case 9:
			return RQST_MODULE_2_SECTION_1;
		case 10:
			return RQST_MODULE_2_SECTION_2;
		case 11:
			return RQST_MODULE_2_SECTION_3;

		/* MODULE 03 */
		case 12:
			return RQST_MODULE_3_SECTION_0;
		case 13:
			return RQST_MODULE_3_SECTION_1;
		case 14:
			return RQST_MODULE_3_SECTION_2;
		case 15:
			return RQST_MODULE_3_SECTION_3;

		default:
			// ERREUR CAS IMPOSSIBLE !!
			return -1;
	}
}

/**********************************************************/

void lcd_initialisation(void)
{
	lcd_init();
  	lcd_clear();
}

void afficher_carte_mere(void)
{
	char buffer[17];

	int section_1 = ETAT_SYSTEME[Affichage_module][0];
	int section_2 = ETAT_SYSTEME[Affichage_module][1];
	int section_3 = ETAT_SYSTEME[Affichage_module][2];
	int section_4 = ETAT_SYSTEME[Affichage_module][3];

	lcd_clear ();
	set_cursor (0,0);
	sprintf(buffer, "%d| %d--%d",Affichage_module,section_1,section_2);
	lcd_print(buffer);
	set_cursor (0,1);
	sprintf(buffer, " | %d -- %d",section_3,section_4);
	lcd_print(buffer);
}



void mise_a_jour_affichage_module(void)
{
	Affichage_module = (Affichage_module + 1)%NOMBRE_MODULE_REEL ;
}

/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
