	   					
#include <LPC23xx.h>                    /* LPC23xx definitions                */


/* Function that initializes LEDs                                             */
void init_LED(void) {
  FIO2DIR  = 0x000000FF;                /* P2.0..7 defined as Outputs         */
}

void int_BP(void) {
 PINSEL4 |= (1 << 20);
 PINSEL4 &= ~(1 << 21);
 EXTMODE |= 1;
 EXTPOLAR &= ~(0x1);
}

void isrBP(void) __irq {
	FIO2PIN = FIO2PIN ^ 0x00000001;  
	//FIO2PIN ^= 0xFF;
	EXTINT |= 0x1;
	VICVectAddr = 0;
}
void init_VIC(void) {
	VICIntEnable = 1 << 14;
	VICVectAddr14 = (unsigned long) isrBP;

}
int main (void) {
	init_LED();
	int_BP();
	init_VIC();
	while (1);
	return 1;
}