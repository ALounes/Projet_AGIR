#include <LPC23xx.H>
#include "math.h"
#include "lcd.h"
#include "stdio.h"
#define B 50
#define Vit_deb 0.2
#define Kp 0.6
#define Kp2 0.1
#define lim 800

volatile unsigned int data ;  //p0.23	  C1
volatile /*unsigned*/ int data_2 ;	  //p0.24	 C2
volatile /*unsigned*/ int data_3 ;	  //p0.25	 C3
volatile unsigned int data_4 ;	  //p0.26	 C4
volatile unsigned int data_5 ;	  //p0.12	  C5
volatile unsigned int data_6 ;	   //p0.13
volatile unsigned int data_7 ;
volatile unsigned int data_8 ;
unsigned char it1=0;
 char str[25] ;

/* fonction de l'ecran lcd */
void ecran(void) {
    
     
	 //char str2[20] ;
    lcd_clear();
    set_cursor(0,0) ;
    sprintf(str,"C1:%d C2:%d", data, data_2);
	lcd_print(str);
	 set_cursor(0,1) ;
    sprintf(str,"C3%dC4%dC5%d", data_3, data_4,data_5);
	lcd_print(str);

} 
 void init_T0(void) {
    T0MR0 = 12e6/1000;
    T0MCR = 0x3;
} 


/* fonction du moteur par defaut */
void init_motor(void){

PCONP |= 1 << 6 ;
PCLKSEL0 |= 1 << 12 ;
PCLKSEL0 |= 1 << 13 ;
PINSEL3 |= (1 << 9) ;  // p1.20	  
PINSEL3 |= (1 << 11) ;   //p1.21  


PWM1MR0 = 12e4*0.5;
PWM1PCR |= (1 << 10) |(1 <<11) ;

PWM1MR2 = 12e4*Vit_deb;	 // vitesse par defaut entrée à E1 et E2      roue droite
PWM1MR3 = 12e4*Vit_deb;  // roue gauche

PWM1MCR = 1<<1;

PWM1TCR = 0x09;

PWM1LER = 0xFF;  // Mise à jour 

}


void init_1(int erreur) {	 // ralentissement roue de droite
	float prop;
	prop = Kp * erreur/1024;
	//prop = 1 - prop;
	PWM1MR2 = PWM1MR0* prop ;
	PWM1MR3 = 12e4*Vit_deb;
	PWM1LER = 0xFF;
}

void init_2(int erreur){  // ralentissement roue de gauche
	float prop;
	prop = Kp * erreur/1024;
	//prop = 1 - prop;
	PWM1MR3 = PWM1MR0* prop ;
	PWM1MR2 = 12e4*Vit_deb;
	PWM1LER = 0xFF;
	
}

void init_12(int erreur) {	 // ralentissement roue de droite
	float prop;
	prop = Kp2 * erreur/1024;
	//prop = 1 - prop;
	PWM1MR2 = PWM1MR0* prop ;
	PWM1MR3 = 12e4*Vit_deb;
	PWM1LER = 0xFF;
}

void init_22(int erreur){  // ralentissement roue de gauche
	float prop;
	prop = Kp2 * erreur/1024;
	//prop = 1 - prop;
	PWM1MR3 = PWM1MR0* prop ;
	PWM1MR2 = 12e4*Vit_deb;
	PWM1LER = 0xFF;
	
}

void control() {
//	static int i = 0 ; // nombre de ligne croisée
	static int j = 0 ; // nombre de demi-tour
/*	static int val ; 
	
	// croisement avec 2 lignes a droite (signalisation du stop)
   if ( data_4 >= data -B && data_2 >= data - B) {
   	init_motor();
	i=i+1;
	}
	if ( i = 2 ) { 
		val = data; 
		PWM1MR3 = PWM1MR0*0.4 ;
		PWM1MR2 = 0;
		PWM1LER = 0xFF;
		
		i=0;
	}

	if ( data - val >= 0 ) {
	j = j + 1 ;
	}
	if ( j == 2  ) {
		init_motor();
		j = 0 ;
	} // fin  de croisement
	*/		

//	if (( data_4 - data_2 >= 5 ) && (data_5-data_3) && ( j== 0 ) ) {
	if ( data_5 - data_4 >= 5 && j==0) {
		init_12(data_5 - data_4 ) ;
	}
	if ( data_4 - data_5 >= 5 && j==0) {
		init_22(data_4 - data_5 ) ;
	}
	if ((data_2 >= data-B) && (data_3 >= data-B )&&  ( j==0 )){
	 	init_motor();
	}
	
	if ( data >= data_2  && j==0){
		
		 init_motor();
	}
	if ( data >= data_3 && j==0){
	 
		 init_motor(); 
	}
	if ( data_3 - data_2 >= 5  && data_2 >= data-B && j==0 ){// data_4 <= data-B && data_5 <= data-B ) {

		init_1(data_3 - data_2) ; 

	}
	if ( data_2 - data_3 >= 5 && data_3 >= data-B && j==0 ){// data_4 <= data-B && data_5 <= data-B) {

		init_2(data_2 - data_3) ; 

	}
	
/*	if ( data_2 >= data - B && data_3 >= data - B  && data_4 >= data - B  && data_5 >= data - B ) {

		init_motor();

	}	*/ 

}
		   

void init_ad() {
	PCONP |= 1 << 12 ;
	AD0CR |= (1 << 21) | 6 ;
	AD0CR |= 0x02FF;
	AD0CR |= ( 1 << 16 ) ;

	/* definition de tous les pinsel pour tous les capteurs */
	
	PINSEL1 |= 1 << 14 ;
	PINSEL1 |= 0 << 15 ;
	PINSEL1 |= 1 << 16;
	PINSEL1 |= 0 << 17 ;
	PINSEL1 |= 1 << 18;
	PINSEL1 |= 0 << 19 ;
	PINSEL1 |= 1 << 20 ;
	PINSEL1 |= 0 << 21 ;
	PINSEL0 |= 1 << 24 ;
	PINSEL0 |= 1 << 25 ;
	PINSEL0 |= 1 << 26 ;
	PINSEL0 |= 1 << 27 ;	
	PINSEL3 |= 1 << 28 ;
	PINSEL3 |= 1 << 29 ;
	//PINSEL3 |= 1 << 30 ;
	//PINSEL3 |= 1 << 31 ;
  	 
	 
}

 

void isr_T0(void)__irq {
	data = (AD0DR0&0xFFFF) >> 6;   // p0.23
    data_2 = (AD0DR1&0xFFFF) >> 6;	  //p0.24
	data_3 = (AD0DR2&0xFFFF ) >> 6;	  //p0.25
	data_4 = (AD0DR3&0xFFFF ) >> 6;	  //p0.26
	data_5 = (AD0DR6&0xFFFF ) >> 6;	  //p1.12
	data_6 = (AD0DR7&0xFFFF ) >> 6;
	//data_7 = (AD0DR6&0xFFFF ) >> 6;
	//data_8 = (AD0DR6&0xFFFF ) >> 6;
   	it1=1;		
    T0IR = 1 ;
    VICVectAddr = 0x00000000 ;
 }


 void init_VIC (void) {
    VICVectAddr4 = (unsigned) (isr_T0) ;
    VICIntEnable |= 1 << 4 ;
}

int main(void) {
	 
	lcd_init();
	
	init_T0() ;
	
	init_ad();
	

	init_VIC();
	T0TCR |= 1 ;

	while(1){

		 
		if(it1){
		 ecran(); 
		 it1=0;
		 }
		control();
		
	}

}	