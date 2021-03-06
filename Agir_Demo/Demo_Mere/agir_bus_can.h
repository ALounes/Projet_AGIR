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

#ifndef AGIR_BUS_CAN_H
#define AGIR_BUS_CAN_H
	
#define ID_MERE 0xAA
#define ID_MODULE_01 0xA1
#define ID_MODULE_02 0xA2

#define CAPTEUR_ON 	0xBB
	/***************************************************/
	/* DEFINITION DES IDENTIFICATEURS POUR LES REQUETES*/
	/***************************************************/

#define PORT_BP_MOTEUR	3
#define PIN_BP_MOTEUR		0

#define PORT_BP_MARGEUR	3
#define PIN_BP_MARGEUR	1

#define PORT_MOTEUR			2
#define PIN_MOTEUR			6

#define PORT_MARGEUR		2
#define PIN_MARGEUR			7


	/* Idetificateur de requete pour le module 00 */
	#define RQST_MOTEUR_ON  		0x01 
	#define RQST_MODULE_OFF  		0x02
	#define RQST_MARGEUR_ON			0x03
	#define RQST_MARGEUR_OFF 		0x04
	#define RQST_ETAT_SYSTEME_0	0xAA
	#define RQST_ETAT_SYSTEME_1	0xAB

	// DECLARATION DES PRO

	void can_initialisation(void);
	void isr_can_reception(void)__irq;
	void can_emission(unsigned long valeur ,unsigned char id_message);
	
	void rqst_etat_systeme(void);
	void rqst_margeur_off(void);
	void rqst_margeur_on(void);
	void rqst_moteur_off(void);
	void rqst_moteur_on(void);
	
	char system_scan(void);
#endif

/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
