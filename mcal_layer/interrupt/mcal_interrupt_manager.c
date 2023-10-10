/* 
 * File:   mcal_interrupt_manager.c
 * Author: Ahmed Elbasioney
 *
 * Created on April 19, 2023, 4:21 AM
 */

#include <xc.h>

#include "mcal_interrupt_manager.h"


#if INTERRUPT_PRIORITY_LEVELS_ENABLE
void __interrupt() interrupt_manager_high(void){
   if((INTCONbits.INT0IE == INTERRUPT_ENABLE) && (INTCONbits.INT0IF == INTERRUPT_OCCUR)){
        INT0_ISR();
    }else{
        /*          no thing         */
    }
    if((INTCON3bits.INT1IE == INTERRUPT_ENABLE) && (INTCON3bits.INT1IF == INTERRUPT_OCCUR)){
        INT1_ISR();
    }else{
        /*          no thing         */
    }
    if((INTCON3bits.INT2IE == INTERRUPT_ENABLE) && (INTCON3bits.INT2IF == INTERRUPT_OCCUR)){
        INT2_ISR();
    }else{
        /*          no thing         */
    }
}

void __interrupt(low_priority) INTEERRUPT_MANAGER_LOW(void){
    
    if((PIE1bits.ADIE == INTERRUPT_ENABLE) && (PIR1bits.ADIF == INTERRUPT_OCCUR)){
        ADC_ISR();
    }else{
        /*          no thing         */
    } 
    
    if((INTCONbits.TMR0IE == INTERRUPT_ENABLE) && (INTCONbits.TMR0IF == INTERRUPT_OCCUR)){
        TIMER0_ISR();
    }else{
        /*          no thing         */
    }
    
} 

#else

void __interrupt() INTEERRUPT_MANAGER(void){
    if((INTCONbits.INT0IE == INTERRUPT_ENABLE) && (INTCONbits.INT0IF == INTERRUPT_OCCUR)){
        INT0_ISR();
    }else{
        /*          no thing         */
    }
    if((INTCON3bits.INT1IE == INTERRUPT_ENABLE) && (INTCON3bits.INT1IF == INTERRUPT_OCCUR)){
        INT1_ISR();
    }else{
        /*          no thing         */
    }
    if((INTCON3bits.INT2IE == INTERRUPT_ENABLE) && (INTCON3bits.INT2IF == INTERRUPT_OCCUR)){
        INT2_ISR();
    }else{
        /*          no thing         */
    }
    if((PIE1bits.ADIE == INTERRUPT_ENABLE) && (PIR1bits.ADIF == INTERRUPT_OCCUR)){
        ADC_ISR();
    }else{
        /*          no thing         */
    }
    /*                                  TIMERS   INTERRUPTS                             */
    if((INTCONbits.TMR0IE == INTERRUPT_ENABLE) && (INTCONbits.TMR0IF == INTERRUPT_OCCUR)){
        TIMER0_ISR();
    }else{
        /*          no thing         */
    }
    if((PIE1bits.TMR1IE == INTERRUPT_ENABLE) && (PIR1bits.TMR1IF == INTERRUPT_OCCUR)){
        TIMER1_ISR();
    }else{
        /*          no thing         */
    }
    if(( PIE1bits.TMR2IE == INTERRUPT_ENABLE) && ( PIR1bits.TMR2IF == INTERRUPT_OCCUR )){
#if TIMER2_INTERRUPT_FEATURE_ENABLE 
        TIMER2_ISR();
#endif
    }else{
        /*          no thing         */
    }
    if(( PIE2bits.TMR3IE == INTERRUPT_ENABLE) && ( PIR2bits.TMR3IF == INTERRUPT_OCCUR )){
        TIMER3_ISR();
    }else{
        /*          no thing         */
    }
    
    
    /*                           CCP1    &    CCP2   INTERRUPTS                         */
    if(( PIE1bits.CCP1IE == INTERRUPT_ENABLE) && ( PIR1bits.CCP1IF == INTERRUPT_OCCUR )){
        CCP1_ISR();
    }else{
        /*          no thing         */
    }
    
    if(( PIE2bits.CCP2IE == INTERRUPT_ENABLE) && ( PIR2bits.CCP2IF == INTERRUPT_OCCUR )){
        CCP2_ISR();
    }else{
        /*          no thing         */
    }
    if(( PIE1bits.TXIE == INTERRUPT_ENABLE) && ( PIR1bits.TXIF == INTERRUPT_OCCUR )){
        EUSART_TX_ISR();
    }else{
        /*          no thing         */
    }
    if(( PIE1bits.RCIE == INTERRUPT_ENABLE) && ( PIR1bits.RCIF == INTERRUPT_OCCUR )){
        EUSART_RX_ISR();
    }else{
        /*          no thing         */
    }
} 

#endif