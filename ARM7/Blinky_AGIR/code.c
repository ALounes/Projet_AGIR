					#include <LPC23xx.H>
#include "math.h"
#include "lcd.h"
#include "stdio.h"
int data ;

void ecran(void) {
    static char str[20] ;
    lcd_init();
    lcd_clear();
    set_cursor(0,0) ;
    sprintf(str,"Resistance : %d" , data);
    lcd_print(str);
}

void init_t0(void) {
    T0MR0 = 12e6 * 0.5;
    T0MCR |= 0x3;
 }



void init(){
	FIO0DIR |= 1 << 24 ; 
	FIO0DIR |= 1 << 22 ;
	FIO0DIR |= 1 << 21 ;
	FIO3DIR |= 1 << 3 ;
	FIO0DIR |=  1 << 12 ;
	FIO0DIR |=  1 << 13 ; 
	FIO1DIR |=  1 << 19 ;
}

void init_ad(void) {
	PCONP |= 1 << 12 ;
	AD0CR |= (1 << 21) | 6 ;
	AD0CR |= 0x0200;
	AD0CR |= ( 1 << 16 ) ;
//CLKSEL0 |= 1 << 24 ;
//CLKSEL0 |= 1 << 25 ;
	PINSEL1 |= 1 << 18; 
	PINSEL1 |= 1 << 16;
	PINMODE1 |= 0x2A8000 ;
//	data = AD0DR2 >> 6 ;	 
}


void isr_t0(void)__irq {
    
    data = AD0DR1 >> 6 ;
    ecran() ; 
    T0IR = 1 ;
    VICVectAddr = 0x00000000 ;

}
void init_VIC (void) {
    VICVectAddr4 = (unsigned long) (isr_t0) ;
    VICIntEnable |= 1 << 4 ;
//	VICVectAddr18 = (unsigned) (isr_2) ;
//	VICIntEnable |= 1 << 18;
}
int main() {
	init() ;
	init_t0() ;
	init_ad();
	T0TCR |= 1 ;

	init_VIC();


	while(1);
	
}