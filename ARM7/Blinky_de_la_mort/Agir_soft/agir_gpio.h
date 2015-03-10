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

	#include <LPC23xx.H>

// DEFINITION DES NUMEROS DE PORTS

	#define P0 0
	#define P1 1
	#define P2 2
	#define P3 3
	#define P4 4

	#define TAILLE_ECRAN 17

// DECLARATION DES PRO

	void gpio_initialisation(void);
	void gpio_out_on   (unsigned int numero_port, unsigned int numero_pin); 
	void gpio_out_off  (unsigned int numero_port, unsigned int numero_pin); 
	char gpio_get_value(unsigned int numero_port, unsigned int numero_pin);
	void gpio_affichage(unsigned int numero_port, unsigned int numero_pin);


/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
