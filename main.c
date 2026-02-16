
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
     
    /* infinite loop */
    while(1)
    {
     switch(PORTB)   /* Read PORTB */
     {
         case 0x06:                     /* RB3 button is closed */
            LATD = 0x70;                /* RD6:RD4 = on-on-on */
            TIMER0_Delay();             /* Delay subroutine */
            LATD = 0x00;                /* RD6:RD4 = off-off-off */
            TIMER0_Delay();             /* Delay subroutine */
            break;
         
         case 0x0A:                     /* RB2 button is closed */ 
            LATD = 0x50;                /* RD6:RD4 = off-on-off */
            TIMER0_Delay();             /* Delay subroutine */
            LATD = 0x20;                /* RD6:RD4 = on-off-on */
            TIMER0_Delay();             /* Delay subroutine */
            break;
             
         case 0x0C:                     /* RB1 button is closed */
            LATD = 0x30;                /* RD6:RD4 = off-on-on */
            TIMER0_Delay();             /* Delay subroutine */
            LATD = 0x50;                /* RD6:RD4 = on-off-on */
            TIMER0_Delay();             /* Delay subroutine */          
            LATD = 0x60;                /* RD6:RD4 = on-on-off */
            TIMER0_Delay();             /* Delay subroutine */          
            break;
                         
         default:                       /* No button closed (all buttons opened) */
            LATD = 0x70;                /* RD6:RD4 = off-off-off */
            break;
     } /* end switch */
        
    } /* end while */
    
    return;
}