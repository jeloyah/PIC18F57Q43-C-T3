
#include <xc.h>
#include "main.h"
#include "gpio.h"
#include "timer0.h"

void main(void) {
    
    /* Peripheral and System Initialization*/
      
    /* PortA initialization */

    
    /* PortB initialization */
    
    
    /* PortC initialization */
    
    
    /* PortD initialization */
    
    
    /* PortE initialization */
    
    
    /* PortF initialization */
    
   
    /* TIMER0 Initialization */
    
     
    /* infinite loop */
    while(1)
    {
     switch(  )   /* Read PORTB */
     {
         case ??:                     /* RB3 button is closed */
                            /* RD6:RD4 = on-on-on */
            TIMER0_Delay();             /* Delay subroutine */
                            /* RD6:RD4 = off-off-off */
            TIMER0_Delay();             /* Delay subroutine */
            break;
         
         case ??:                     /* RB2 button is closed */ 
                            /* RD6:RD4 = off-on-off */
            TIMER0_Delay();             /* Delay subroutine */
                            /* RD6:RD4 = on-off-on */
            TIMER0_Delay();             /* Delay subroutine */
            break;
             
         case ??:                     /* RB1 button is closed */
                            /* RD6:RD4 = off-on-on */
            TIMER0_Delay();             /* Delay subroutine */
                            /* RD6:RD4 = on-off-on */
            TIMER0_Delay();             /* Delay subroutine */          
                            /* RD6:RD4 = on-on-off */
            TIMER0_Delay();             /* Delay subroutine */          
            break;
                         
         default:                       /* No button closed (all buttons opened) */
                            /* RD6:RD4 = off-off-off */
            break;
     } /* end switch */
        
    } /* end while */
    
    return;
}
