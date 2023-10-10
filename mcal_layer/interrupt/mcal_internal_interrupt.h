/* 
 * File:   mcal_internal_interrupt.h
 * Author: Ahmed Elbasioney
 *
 * Created on April 19, 2023, 4:17 AM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H


/*                               includes  section                       */
#include "mcal_interrupt_config.h"


/*                               macros  section                        */

#if  ADC_INTERRUPT_FEATURE_ENABLE  == INTERRUPT_FEATURE_ENABLE 
#define ADC_INTERRUPT_DISABLE()       ( PIE1bits.ADIE = 0 )  // disable ADC interrupt feature
#define ADC_INTERRUPT_ENABLE()        ( PIE1bits.ADIE = 1 )  // enable ADC interrupt feature
#define ADC_INTERRUPT_CLEAR_FLAG()    ( PIR1bits.ADIF = 0 )  // clear ADC interrupt flag
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
#define ADC_INTERRUPT_SET_HIGH_PRIORITY()  ( IPR1bits.ADIP = 1 )
#define ADC_INTERRUPT_SET_LOW_PRIORITY()   ( IPR1bits.ADIP = 0 )
#endif
#endif


#if  TIMER0_INTERRUPT_FEATURE_ENABLE  == INTERRUPT_FEATURE_ENABLE 
#define TIMER0_INTERRUPT_DISABLE()       ( INTCONbits.T0IE = 0 )  // disable TIMER0 interrupt feature
#define TIMER0_INTERRUPT_ENABLE()        ( INTCONbits.T0IE = 1 )  // enable TIMER0 interrupt feature
#define TIMER0_INTERRUPT_CLEAR_FLAG()    ( INTCONbits.T0IF = 0 )  // clear TIMER0 interrupt flag
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
#define TIMER0_INTERRUPT_SET_HIGH_PRIORITY()  ( INTCON2bits.TMR0IP = 1 )   // set timer 0 to be a high priority interrupt
#define TIMER0_INTERRUPT_SET_LOW_PRIORITY()   ( INTCON2bits.TMR0IP = 0 )   // set timer 0 to be a low priority interrupt
#endif
#endif

#if  TIMER1_INTERRUPT_FEATURE_ENABLE  == INTERRUPT_FEATURE_ENABLE 
#define TIMER1_INTERRUPT_DISABLE()       ( PIE1bits.TMR1IE = 0 )  // disable TIMER1 interrupt feature
#define TIMER1_INTERRUPT_ENABLE()        ( PIE1bits.TMR1IE = 1 )  // enable TIMER1 interrupt feature
#define TIMER1_INTERRUPT_CLEAR_FLAG()    ( PIR1bits.TMR1IF = 0 )  // clear TIMER1 interrupt flag
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
#define TIMER1_INTERRUPT_SET_HIGH_PRIORITY()  ( IPR1bits.TMR1IP = 1 )  // set timer 1 to be a high priority interrupt
#define TIMER1_INTERRUPT_SET_LOW_PRIORITY()   ( IPR1bits.TMR1IP = 0 )  // set timer 1 to be a low priority interrupt
#endif
#endif

#if  TIMER2_INTERRUPT_FEATURE_ENABLE  == INTERRUPT_FEATURE_ENABLE 
#define TIMER2_INTERRUPT_DISABLE()       ( PIE1bits.TMR2IE = 0 )  // disable TIMER2 interrupt feature
#define TIMER2_INTERRUPT_ENABLE()        ( PIE1bits.TMR2IE = 1 )  // enable TIMER2 interrupt feature
#define TIMER2_INTERRUPT_CLEAR_FLAG()    ( PIR1bits.TMR2IF = 0 )  // clear TIMER2 interrupt flag
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
#define TIMER2_INTERRUPT_SET_HIGH_PRIORITY()  ( IPR1bits.TMR2IP = 1 )   // set timer 2 to be a high priority interrupt
#define TIMER2_INTERRUPT_SET_LOW_PRIORITY()   ( IPR1bits.TMR2IP = 0 )   // set timer 2 to be a low priority interrupt
#endif
#endif

#if  TIMER3_INTERRUPT_FEATURE_ENABLE  == INTERRUPT_FEATURE_ENABLE 
#define TIMER3_INTERRUPT_DISABLE()       ( PIE2bits.TMR3IE = 0 )  // disable TIMER3 interrupt feature
#define TIMER3_INTERRUPT_ENABLE()        ( PIE2bits.TMR3IE = 1 )  // enable TIMER3 interrupt feature
#define TIMER3_INTERRUPT_CLEAR_FLAG()    ( PIR2bits.TMR3IF = 0 )  // clear TIMER3 interrupt flag
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
#define TIMER3_INTERRUPT_SET_HIGH_PRIORITY()  ( IPR2bits.TMR3IP = 1 )   // set timer 3 to be a high priority interrupt
#define TIMER3_INTERRUPT_SET_LOW_PRIORITY()   ( IPR2bits.TMR3IP = 0 )   // set timer 3 to be a low priority interrupt
#endif
#endif

#if  CCP1_INTERRUPT_FEATURE_ENABLE  == INTERRUPT_FEATURE_ENABLE 
#define CCP1_INTERRUPT_DISABLE()       ( PIE1bits.CCP1IE = 0 )  // disable CCP1 module interrupt feature
#define CCP1_INTERRUPT_ENABLE()        ( PIE1bits.CCP1IE = 1 )  // enable CCP1 module interrupt feature
#define CCP1_INTERRUPT_CLEAR_FLAG()    ( PIR1bits.CCP1IF = 0 )  // clear CCP1 module interrupt flag
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
#define CCP1_INTERRUPT_SET_HIGH_PRIORITY()  ( IPR1bits.CCP1IP = 1 )   // set CCP1 module to be a high priority interrupt
#define CCP1_INTERRUPT_SET_LOW_PRIORITY()   ( IPR1bits.CCP1IP = 0 )   // set CCP1 module to be a low priority interrupt
#endif
#endif

#if  CCP2_INTERRUPT_FEATURE_ENABLE  == INTERRUPT_FEATURE_ENABLE 
#define CCP2_INTERRUPT_DISABLE()       ( PIE2bits.CCP2IE = 0 )  // disable CCP2 module interrupt feature
#define CCP2_INTERRUPT_ENABLE()        ( PIE2bits.CCP2IE = 1 )  // enable CCP2 module interrupt feature
#define CCP2_INTERRUPT_CLEAR_FLAG()    ( PIR2bits.CCP2IF = 0 )  // clear CCP2 module interrupt flag
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
#define CCP2_INTERRUPT_SET_HIGH_PRIORITY()  ( IPR2bits.CCP2IP = 1 )   // set CCP2 module to be a high priority interrupt
#define CCP2_INTERRUPT_SET_LOW_PRIORITY()   ( IPR2bits.CCP2IP = 0 )   // set CCP2 module to be a low priority interrupt
#endif
#endif

#if  EUSART_TX_INTERRUPT_FEATURE_ENABLE  == INTERRUPT_FEATURE_ENABLE 
#define EUSART_TX_INTERRUPT_DISABLE()       ( PIE1bits.TXIE = 0 )  // disable EUSART_TX module interrupt feature
#define EUSART_TX_INTERRUPT_ENABLE()        ( PIE1bits.TXIE = 1 )  // enable EUSART_TX module interrupt feature
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
#define EUSART_TX_INTERRUPT_SET_HIGH_PRIORITY()  ( IPR1bits.TXIP = 1 )   // set EUSART_TX module to be a high priority interrupt
#define EUSART_TX_INTERRUPT_SET_LOW_PRIORITY()   ( IPR1bits.TXIP = 0 )   // set EUSART_TX module to be a low priority interrupt
#endif
#endif

#if  EUSART_RX_INTERRUPT_FEATURE_ENABLE  == INTERRUPT_FEATURE_ENABLE 
#define EUSART_RX_INTERRUPT_DISABLE()       ( PIE1bits.RCIE = 0 )  // disable EUSART_RX module interrupt feature
#define EUSART_RX_INTERRUPT_ENABLE()        ( PIE1bits.RCIE = 1 )  // enable EUSART_RX module interrupt feature
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
#define EUSART_RX_INTERRUPT_SET_HIGH_PRIORITY()  ( IPR1bits.RCIP = 1 )   // set EUSART_RX module to be a high priority interrupt
#define EUSART_RX_INTERRUPT_SET_LOW_PRIORITY()   ( IPR1bits.RCIP = 0 )   // set EUSART_RX module to be a low priority interrupt
#endif
#endif


/*                               datatype  section                      */



/*                               functions  section                      */


#endif	/* MCAL_INTERNAL_INTERRUPT_H */

