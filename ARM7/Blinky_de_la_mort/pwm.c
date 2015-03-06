#include <LPC23xx.H>
#include "math.h"
#include "lcd.h"
#include "stdio.h"

void init_motor(void){

PCONP |= 1 << 6 ;
PCLKSEL0 |= 1 << 12 ;
PCLKSEL0 |= 1 << 13 ;
PINSEL3 |= (1 << 9) ;  // p1.20
PINSEL3 |= (1 << 11) ;   //p1.21


PWM1MR0 = 12e4;
PWM1PCR |= (1 << 10) |(1 <<11) ;

PWM1MR2 = 12e4*0.4;
PWM1MR3 = 12e4*0.4;

PWM1MCR = (1<<1) ;
PWM1TCR = 0x09;

PWM1LER = 0xFF;

}






int main(void) {

init_motor() ;

while(1);

}