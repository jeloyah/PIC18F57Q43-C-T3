#include <xc.h>
#include "timer0.h"

/* Config Timer0 */
void TIMER0_Initialize(void)
{
    /* Timer0 disabled; 16-bit; no postscaler */
	T0CON0 = 0x10;
    
    /* HFINTOSC; counter not synchronized; prescaler 1:2048 */
	T0CON1 = 0x7B;
       
}

void TIMER0_Delay()
{
    /* Load TMR0 with value (hex) */
	TMR0H = 0xFC;
	TMR0L = 0x17;
    
    /* Timer0 enabled; 16-bit */
	T0CON0 |= 0x80;       
   
    /* Wait for TMR0IF = 1 */
    while ((PIR3 & 0x80) != 0x80) 
        /* empty loop */ 
        ;
        
    /* Clear TMR0IF bit */
    PIR3 &= 0x7F;
    
    /* Timer0 disabled */
	T0CON0 &= 0x7F; 
}
