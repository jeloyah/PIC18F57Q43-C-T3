#include <xc.h>
#include "timer0.h"

/* Config Timer0 */
void TIMER0_Initialize(void)
{
    /* Timer0 disabled; 16-bit; no postscaler */
	T0CON0 = 0x10;
    
    /* HFINTOSC; counter not synchronized; prescaler 1:2048 */
	//T0CON1 = 0x7B;
    
    /* HFINTOSC; counter not synchronized; prescaler 1:2 */
	T0CON1 = 0x72;
    
    /* sequence for unlock PPS */
    //PPS_unlock();
    
    /* TMR0 output on pin RF3 */
    //RF3PPS = 0x39;
    
    /* sequence for lock PPS */
    //PPS_lock();
    
    
    /* Load TMR0 with initial value (hex) */
    /* tCLK1 x counts  x prescaler = TMR0 counting time */
    /* 1/64MHz * (65535-34285) * 2 = 1 s */
	TMR0H = 0x85;
	TMR0L = 0xED;
    
    /* Load TMR0 with initial value (hex) */
    /* tCLK1 x counts  x prescaler = TMR0 counting time */
    /* 1/1MHz * (65535-64535) * 64 = 1 ms */
	//TMR0H = 0xFC;
	//TMR0L = 0x17;
    
    /* Load TMR0 with initial value (hex) */
    /* tCLK1 x counts  x prescaler = TMR0 counting time */
    /* 1/64MHz * (65535-18660) * 2048 = 1.5 s */
	//TMR0H = 0x48;
	//TMR0L = 0xE4;
}


void TIMER0_Start(void)
{
    /* Timer0 enabled; 16-bit */
	T0CON0 |= 0x80;
    
}

/* Timer0 Delay = 1 ms x Time */
void TIMER0_Delay_ms(unsigned short Time)
{
    /* Timer0 enabled; 16-bit */
	/* T0CON0 |= 0x80; */
    T0CON0bits.EN = 1;
        
    while (Time != 0x00)
        {
    
    	/* Wait for TMR0IF = 1 */
        /* while ((PIR3 & 0x80) != 0x80) */
        while (PIR3bits.TMR0IF != 1)
            ;
        
        /* Clear TMR0IF bit */
        /* PIR3 &= 0x7F; */
        PIR3bits.TMR0IF = 0;
        
        /* Decrement Time variable */
        Time-=1;
        
        /* Reload TMR0 with value (hex) */
        /* tCLK1 x counts  x prescaler = TMR0 counting time */
        /* 1/64MHz * (65535-33535) * 1 =  1 ms */
	    TMR0H = 0x82;
	    TMR0L = 0xFF;
        }   
    
    /* Timer0 disabled; 16-bit */
	/* T0CON0 &= 0x7F; */
    T0CON0bits.EN = 0;
}
