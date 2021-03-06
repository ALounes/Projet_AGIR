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

#ifndef AGIR_TIMER_H
#define AGIR_TIMER_H

	#define TAILLE_LIGNE_LCD 17

	#define TIMER_0_FREQ    12000000/2
	#define TIMER_0_CONTROL 3

	#define TIMER_1_FREQ    12000000/4
	#define TIMER_1_CONTROL 3

	#define ID_MERE 0xAA
	#define ID_MODULE_01 0xA1
	#define ID_MODULE_02 0xA2
	#define ID_MODULE ID_MODULE_01

	// DECLARATION DES PRO

	void timer_0_initialisation(void);
	void timer_1_initialisation(void);

	void isr_timer0(void)__irq;
	void isr_timer1(void)__irq;

#endif

/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
