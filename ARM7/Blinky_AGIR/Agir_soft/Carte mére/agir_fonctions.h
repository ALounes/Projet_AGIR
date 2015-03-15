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

#ifndef AGIR_FONCTION_H
#define AGIR_FONCTION_H

	#include <LPC23xx.H>

	#define NOMBRE_MODULE_REEL 2

	int ETAT_REQUETE = 0;

	int  prochaine_requete(const int etat);
	void mise_a_jour_etat_requette(void);
	extern void comunication_module(void);

	void lcd_initialisation(void);

#endif
	
/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
