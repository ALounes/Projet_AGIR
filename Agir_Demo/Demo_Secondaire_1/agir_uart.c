/******************************************************************************/
/* SERIAL.C: Low Level Serial Routines                                        */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2006 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#include <LPC23xx.H>
#include "agir_uart.h"


void uart_initialisation(void)  
{
	/* Initialize Serial Interface       */
	#ifdef UART0
		PINSEL0 |= 0x00000050;              /* Enable TxD0 and RxD0              */
	#elif defined (UART1)
		PINSEL0 |= 0x40000000;              /* Enable TxD1                       */
		PINSEL1 |= 0x00000001;              /* Enable RxD1                       */
	#endif
	UxFDR    = 0;                          /* Fractional divider not used       */
	UxLCR    = 0x83;                       /* 8 bits, no Parity, 1 Stop bit     */
	UxDLL    = 78;                         /* 9600 Baud Rate @ 12.0 MHZ PCLK    */
	UxDLM    = 0;                          /* High divisor latch = 0            */
	UxLCR    = 0x03;                       /* DLAB = 0                          */
}


/* Implementation of putchar (also used by printf function to output data)    */

int uart_emission(int data)  
{
	/* Write character to Serial Port    */

	while (!(UxLSR & 0x20));

	return (UxTHR = data);
}


int uart_reception(void)  
{
	/* Read character from Serial Port   */

	while (!(UxLSR & 0x01));

	return (UxRBR);
}


/**********************************************************/
/********************* FIN FICHIER ************************/
/**********************************************************/
