
#include <xc.h>
#include "main.h"
#include "gpio.h"
#include "timer0.h"

void main(void) {
    
    /* Peripheral and System Initialization*/
      
    /* PortA initialization */
    PortA_Initialize();
    
    /* PortB initialization */
    PortB_Initialize();
    
    /* PortC initialization */
    PortC_Initialize();
    
    /* PortD initialization */
    PortD_Initialize();
    
    /* PortE initialization */
    PortE_Initialize();
    
    /* PortF initialization */
    PortF_Initialize();
   
    /* TIMER0 Initialization */
    TIMER0_Initialize();
    
    /* TIMER0 enabled, start counting */
    TIMER0_Start();
    
    /* infinite loop */
    while(1)
    {
     switch(PORTA)   /* Read PORTA */
     {
         case 0x60:         /* Compare PortA with 0x70 (RA7 button is closed) */
            LATF = 0x03;    /* RF3:RF0 = on-on-off-off */
            TIMER0_Delay_ms(500);     /* Delay subroutine */
            LATF = 0x0C;    /* RF3:RF0 = off-off-on-on */
            TIMER0_Delay_ms(500);     /* Delay subroutine */
            break;
         
         case 0xA0:         /* Compare PortA with 0xB0 (RA6 button is closed) */ 
            LATF = 0x06;    /* RF3:RF0 = on-off-off-on */
            TIMER0_Delay_ms(500);     /* Delay subroutine */
            LATF = 0x09;    /* RF3:RF0 = off-on-on-off */
            TIMER0_Delay_ms(500);     /* Delay subroutine */
            break;
             
         case 0xC0:         /* Compare PortA with 0xC0 (RA5 button is closed)*/
            LATF = 0x0A;    /* RF3:RF0 = off-on-off-on */
            TIMER0_Delay_ms(500);     /* Delay subroutine */
            LATF = 0x05;    /* RF3:RF0 = on-off-on-off */
            TIMER0_Delay_ms(500);     /* Delay subroutine */          
            break;
                         
         default:           /* No button closed (all buttons opened) */
            LATF = 0x0F;    /* RF3:RF0 = off-off-off-off */
            break;
     } /* end switch */
        
    } /* end while */
    
    return;
}