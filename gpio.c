
#include <xc.h>
#include "gpio.h"

/* PortA initialization */
void PortA_Initialize(void)
{
    /* Clear register */
    LATA = 0x00;
    
    /* Pins as digital I/O */
    ANSELA = 0x00;
    
    /* Disable pull-ups */
    WPUA = 0x00;
        
    /* RA7:RA0 as output */
    TRISA = 0x00;
}

/* PortB initialization */
void PortB_Initialize(void)
{
    /* Clear register */
    LATB = 0x00;
    
    /* Pins as digital I/O */
    ANSELB = 0x00;
    
    /* Disable Rpull-ups */
    WPUB = 0x00;
        
    /* RB7:RB4, RB0 as output; RB3:RB1 as input */
    TRISB = 0x00;
}

/* PortC initialization */
void PortC_Initialize(void)
{
    /* Clear register */
    LATA = 0x00;
    
    /* Pins as digital I/O */
    ANSELC = 0x00;
    
    /* Disable Rpull-ups */
    WPUC = 0x00;
        
    /* PortC as output */
    TRISC = 0x00;
}
    
/* PortD initialization */
void PortD_Initialize(void)
{
    /* Clear register */
    LATD = 0x00;
    
    /* Pins as digital I/O */
    ANSELD = 0x00;
    
    /* Disable Rpull-ups */
    WPUD = 0x00;
        
    /* RD6:RD4 as input; RD7, RD3:RD0 as output */
    TRISD = 0x00;
}

/* PortE initialization */
void PortE_Initialize(void)
{
    /* Clear register */
    LATE = 0x00;
    
    /* Pins as digital I/O */
    ANSELE = 0x00;
    
    /* Disable Rpull-ups */
    WPUE = 0x00;
        
    /* PortE as output */
    TRISE = 0x00;
}    

/* PortF initialization */
void PortF_Initialize(void)
{
    /* Clear register */
    LATF = 0x00;
    
    /* Pins as digital I/O */
    ANSELF = 0x00;
    
    /* Disable Rpull-ups */
    WPUF = 0x00;
        
    /* PortF as output */
    TRISF = 0x00;
}
