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
	
	#define SIZE_MSG 	    1

	#define NBR_MODULE    4
	#define TAILLE_MODULE 4

	/***************************************************/
	/* DEFINITION DES IDENTIFICATEURS POUR LES MESSAGES*/
	/***************************************************/
	#define ID_MODULE_SECTION_0	ID_MODULE_0_SECTION_0
	#define ID_MODULE_SECTION_1	ID_MODULE_0_SECTION_1
	#define ID_MODULE_SECTION_2	ID_MODULE_0_SECTION_2
	#define ID_MODULE_SECTION_3	ID_MODULE_0_SECTION_3


	/* Idetificateur de message pour le module 00 */
	#define ID_MODULE_0_SECTION_0  100
	#define ID_MODULE_0_SECTION_1  101
	#define ID_MODULE_0_SECTION_2  102
	#define ID_MODULE_0_SECTION_3  103

	/* Idetificateur de message pour le module 01 */
	#define ID_MODULE_1_SECTION_0  110
	#define ID_MODULE_1_SECTION_1  111
	#define ID_MODULE_1_SECTION_2  112
	#define ID_MODULE_1_SECTION_3  113

	/* Idetificateur de message pour le module 02 */
	#define ID_MODULE_2_SECTION_0  120
	#define ID_MODULE_2_SECTION_1  121
	#define ID_MODULE_2_SECTION_2  122
	#define ID_MODULE_2_SECTION_3  123

	/* Idetificateur de message pour le module 03 */
	#define ID_MODULE_3_SECTION_0  130
	#define ID_MODULE_3_SECTION_1  131
	#define ID_MODULE_3_SECTION_2  132
	#define ID_MODULE_3_SECTION_3  133

	/***************************************************/
	/* DEFINITION DES IDENTIFICATEURS POUR LES REQUETES*/
	/***************************************************/

	/* Idetificateur de requete pour le module 00 */
	#define RQST_MODULE_0_SECTION_0  200 
	#define RQST_MODULE_0_SECTION_1  201
	#define RQST_MODULE_0_SECTION_2  202
	#define RQST_MODULE_0_SECTION_3  203

	/* Idetificateur de requete pour le module 01 */
	#define RQST_MODULE_1_SECTION_0  210
	#define RQST_MODULE_1_SECTION_1  211
	#define RQST_MODULE_1_SECTION_2  212
	#define RQST_MODULE_1_SECTION_3  213

	/* Idetificateur de requete pour le module 02 */
	#define RQST_MODULE_2_SECTION_0  220
	#define RQST_MODULE_2_SECTION_1  221
	#define RQST_MODULE_2_SECTION_2  222
	#define RQST_MODULE_2_SECTION_3  223

	/* Idetificateur de requete pour le module 03 */
	#define RQST_MODULE_3_SECTION_0  230
	#define RQST_MODULE_3_SECTION_1  231
	#define RQST_MODULE_3_SECTION_2  232
	#define RQST_MODULE_3_SECTION_3  233

	// Variables Globales

extern	int ETAT_SYSTEME[NBR_MODULE][TAILLE_MODULE];

	// DECLARATION DES PRO

	void can_initialisation(void);
	void isr_can_reception(void)__irq;
	void can_emission(unsigned long valeur ,unsigned char id_message);
#endif

/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
