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
#include "agir_uart.h"
#include "agir_bus_can.h"

extern char RECEPTION_BL;
extern char CAP_1;
extern char CAN;

void uart_initialisation(void)  
{
	/* Initialize Serial Interface       */
//	#ifdef UART0
		PINSEL0 |= 0x00000050;              /* Enable TxD0 and RxD0              */
//	#elif defined (UART1)
//		PINSEL0 |= 0x40000000;              /* Enable TxD1                       */
//		PINSEL1 |= 0x00000001;              /* Enable RxD1                       */
//	#endif
	
	U0FDR    = 0;                          /* Fractional divider not used       */
	U0LCR    = 0x83;                       /* 8 bits, no Parity, 1 Stop bit     */
	U0DLL    = 78;                         /* 9600 Baud Rate @ 12.0 MHZ PCLK    */
	U0DLM    = 0;                          /* High divisor latch = 0            */
	U0LCR    = 0x03;                       /* DLAB = 0                          */
}


/* Implementation of putchar (also used by printf function to output data)    */

int uart_emission(int data)  
{
	/* Write character to Serial Port    */

	while (!(U0LSR & 0x20));

	return (U0THR = data);
}


int uart_reception(void)  
{
	/* Read character from Serial Port   */

	while (!(U0LSR & 0x01));

	return (U0RBR);
}

void bluetooth_reception(void)  
{
	
	if((U0LSR & 0x01))
	{
		RECEPTION_BL = U0RBR;
		//bluetooth_emission('Y');
		can_emission(RECEPTION_BL,ID_MERE);
		CAN = RECEPTION_BL;
	}
}

void bluetooth_emission(int data)  
{
	while(!uart_emission(data));
}

/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
