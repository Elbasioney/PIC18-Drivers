/* 
 * File:   app.c
 * Author: Ahmed Elbasioeny 
 *
 * Created on March 8, 2023, 5:24 PM
 */
#include "main.h"

void TMR_ISR(void);

int main() {
    TMR0_Init(TMR_ISR);

    
    
    while (1) {
        
    }
    return 0;
}

void TMR_ISR(void){
    
    
    
}