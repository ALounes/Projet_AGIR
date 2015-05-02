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
#ifndef AGIR_GPIO_H
#define AGIR_GPIO_H

	#include <LPC23xx.H>

 
#define ID_MERE 0xAF
#define ID_MODULE_01 0xA1
#define ID_MODULE_02 0xA2
#define ID_MODULE ID_MODULE_02

#define CAPTEUR_ON 	0xBB

// DEFINITION DES NUMEROS DE PORTS
	#define TAILLE_OCTET 4

	#define P0 0
	#define P1 1
	#define P2 2
	#define P3 3
	#define P4 4
	
	#define ON  1
	#define OFF 0

	#define TAILLE_ECRAN 17

	#define LED_GREEN   1
	#define LED_RED     0
	#define LED_ORANGE -1

	#define MOTEUR		  0
	#define MARGEUR_00  0
	#define MARGEUR_01  1 
	#define MARGEUR_02  2
	#define MARGEUR_03  3
	#define MARGEUR_04  4

// DEFINITION des port et leurs pin pour les LED

	// MOTEUR 00
	#define PORT_LED_MARGEUR_00_GREEN	2
	#define PIN_LED_MARGEUR_00_GREEN	0	
	
	#define PORT_LED_MARGEUR_00_ORANGE	2
	#define PIN_LED_MARGEUR_00_ORANGE		1

	#define PORT_LED_MARGEUR_00_RED		2	
	#define PIN_LED_MARGEUR_00_RED		2	

	#define PORT_RELAIS_MARGEUR_00	2
	#define PIN_RELAIS_MARGEUR_00		6

	#define PORT_BP_MARGEUR_00	3
	#define PIN_BP_MARGEUR_00		0

	// MARGEUR 01
	#define PORT_LED_MARGEUR_01_GREEN		2	
	#define PIN_LED_MARGEUR_01_GREEN	3	
	
	#define PORT_LED_MARGEUR_01_ORANGE	2	
	#define PIN_LED_MARGEUR_01_ORANGE		4

	#define PORT_LED_MARGEUR_01_RED		2		
	#define PIN_LED_MARGEUR_01_RED		5	

	#define PORT_RELAIS_MARGEUR_01	2
	#define PIN_RELAIS_MARGEUR_01		7

	#define PORT_BP_MARGEUR_01	3
	#define PIN_BP_MARGEUR_01		1

	#define PORT_CAPTEUR_MARGEUR_01	3
	#define PIN_CAPTEUR_MARGEUR_01	3
	


	// MARGEUR 02
	#define PORT_LED_MARGEUR_02_GREEN		2
	#define PIN_LED_MARGEUR_02_GREEN		6
	
	#define PORT_LED_MARGEUR_02_ORANGE	2
	#define PIN_LED_MARGEUR_02_ORANGE		7

	#define PORT_LED_MARGEUR_02_RED			2
	#define PIN_LED_MARGEUR_02_RED			8

	#define PORT_RELAIS_MARGEUR_02	3
	#define PIN_RELAIS_MARGEUR_02		7

	#define PORT_BP_MARGEUR_02	3
	#define PIN_BP_MARGEUR_02		2

	#define PORT_CAPTEUR_MARGEUR_02	4
	#define PIN_CAPTEUR_MARGEUR_02	1

	// MARGEUR 03
	#define PORT_LED_MARGEUR_03_GREEN		2
	#define PIN_LED_MARGEUR_03_GREEN		9
	
	#define PORT_LED_MARGEUR_03_ORANGE	2
	#define PIN_LED_MARGEUR_03_ORANGE		10

	#define PORT_LED_MARGEUR_03_RED			2
	#define PIN_LED_MARGEUR_03_RED			11

	#define PORT_RELAIS_MARGEUR_03	3
	#define PIN_RELAIS_MARGEUR_03		25

	#define PORT_BP_MARGEUR_03	3
	#define PIN_BP_MARGEUR_03		3

	#define PORT_CAPTEUR_MARGEUR_03	4
	#define PIN_CAPTEUR_MARGEUR_03	2

	// MARGEUR 04
	#define PORT_LED_MARGEUR_04_GREEN	2	
	#define PIN_LED_MARGEUR_04_GREEN	12	
	
	#define PORT_LED_MARGEUR_04_ORANGE	2
	#define PIN_LED_MARGEUR_04_ORANGE		13

	#define PORT_LED_MARGEUR_04_RED			4
	#define PIN_LED_MARGEUR_04_RED			4

	#define PORT_RELAIS_MARGEUR_04	3
	#define PIN_RELAIS_MARGEUR_04		26

	#define PORT_BP_MARGEUR_04	3
	#define PIN_BP_MARGEUR_04		4

	#define PORT_CAPTEUR_MARGEUR_04	4
	#define PIN_CAPTEUR_MARGEUR_04	3


// DECLARATION DES PROTO
extern char ETAT_SYSTEME[TAILLE_OCTET];

void led_traitement(void);
void capteur_traitement(void);
void relais_traitement(void);
int  bp_traitement(void);
void gpio_traitement(void);
void gpio_affichage(unsigned int numero_port, unsigned int numero_pin);
void relais_all_off(void);
void relais_all_on(void);
void gpio_all_out_off(void);
void set_relais_margeur(int relais, int etat_relais);
void led_all_orange(void);
void led_all_green(void);
void led_all_red(void);
void set_led_margeur(int margeur, int etat_margeur);
void set_led_margeur_04(int etat_margeur);
void set_led_margeur_03(int etat_margeur);
void set_led_margeur_02(int etat_margeur);
void set_led_margeur_01(int etat_margeur);
void set_led_margeur_00(int etat_margeur);
void led_capteur(int margeur,int etat);
char gpio_get_value(unsigned int numero_port, unsigned int numero_pin);
void gpio_out_off (unsigned int numero_port, unsigned int numero_pin); 
void gpio_out_on (unsigned int numero_port, unsigned int numero_pin); 
void gpio_initialisation(void); 
char system_scan(void);

#endif

/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
