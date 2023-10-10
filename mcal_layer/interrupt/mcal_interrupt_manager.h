/* 
 * File:   mcal_interrupt_manager.h
 * Author: Ahmed Elbasioney
 *
 * Created on April 19, 2023, 4:21 AM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/*                               includes  section                       */
#include "mcal_interrupt_config.h"


/*                               macros  section                        */





/*                               datatype  section                      */



/*                               functions  section                      */

void interrupt_manager_high(void);
void INTEERRUPT_MANAGER_LOW(void);
void INTEERRUPT_MANAGER(void);

void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);

void ADC_ISR(void);
void TIMER0_ISR(void);
void TIMER1_ISR(void);
void TIMER2_ISR(void);
void TIMER3_ISR(void);
void CCP1_ISR(void);
void CCP2_ISR(void);
void EUSART_TX_ISR(void);
void EUSART_RX_ISR(void);

#endif	/* MCAL_INTERRUPT_MANAGER_H */

