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

#ifndef AGIR_UART_H
#define AGIR_UART_H

	/* Use UART 0 for printf             */
	#define UART1                            

	/* If UART 0 is used for printf */
	#ifdef UART0
	  #define UxFDR  U0FDR
	  #define UxLCR  U0LCR
	  #define UxDLL  U0DLL
	  #define UxDLM  U0DLM
	  #define UxLSR  U0LSR
	  #define UxTHR  U0THR
	  #define UxRBR  U0RBR
	/* If UART 1 is used for printf */
	#elif defined(UART1)
	  #define UxFDR  U1FDR
	  #define UxLCR  U1LCR
	  #define UxDLL  U1DLL
	  #define UxDLM  U1DLM
	  #define UxLSR  U1LSR
	  #define UxTHR  U1THR
	  #define UxRBR  U1RBR
	#endif

	// Declaration des protos

	int  uart_reception (void); 
	int  uart_emission (int data);
	void uart_initialisation (void);
	void bluetooth_reception(void);
	void bluetooth_emission(int data);
#endif 


/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
