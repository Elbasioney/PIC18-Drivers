/* 
 * File:   hal_timer3.h
 * Author: Ahmed Elbasioney
 *
 * Created on May 5, 2023, 4:43 PM
 */

#ifndef HAL_TIMER3_H
#define	HAL_TIMER3_H


/*                                        includes                          */

#include <xc.h>
#include "../GPIO/hal_gpio.h"
#include "../interrupt/mcal_internal_interrupt.h"
#include "../mcal_std_libararies.h"
#include "../mcal_std_types.h"
/*                                            macros                         */

#define TIMER3_PRESCALER_DIV_BY_1    0 
#define TIMER3_PRESCALER_DIV_BY_2    1
#define TIMER3_PRESCALER_DIV_BY_4    2 
#define TIMER3_PRESCALER_DIV_BY_8    3

#define TIMER3_Synchronization_DISABLED   1 
#define TIMER3_Synchronization_ENABLED    0

#define TIMER3_COUNTER_MODE 1
#define TIMER3_TIMER_MODE   0

#define TIMER3_16_BIT_MODE 1
#define TIMER3_8_BIT_MODE  0

/*                                        macro like functions                */

#define TIMER3_FEATURE_ENABLE()      (T3CONbits.TMR3ON = 1 )      // enable timer3 module
#define TIMER3_FEATURE_DISABLE()     (T3CONbits.TMR3ON = 0 )     // disable timer3 module

#define TIMER3_COUNTER_MODE_SET()    (T3CONbits.TMR3CS = 1 )    // set timer 3 to be counter mode
#define TIMER3_TIMER_MODE_SET()      (T3CONbits.TMR3CS = 0 )   // set timer 3 to be timer mode


#define TIMER3_Synchronization_ENABLE_SET()    (T3CONbits.T3SYNC = 0 )   // enable Synchronization with timer1 and timer3 oscillator
#define TIMER3_Synchronization_DISABLE_SET()   (T3CONbits.T3SYNC = 1 )   // disable Synchronization with timer1 and timer3 oscillator 

#define TIMER3_SET_PRESCALER_VALUE(X)     ( T3CONbits.T3CKPS  = X)     // set prescaler choosen value 

#define TIMER3_16_BIT_MODE_SET()          ( T3CONbits.RD16 = 1 )   // set timer 3 R/W register size to 16 bit mode
#define TIMER3_8_BIT_MODE_SET()           ( T3CONbits.RD16 = 0 )   // set timer 3 R/W register size to 8 bit mode

/*                                           data types                       */

typedef struct {
#if TIMER3_INTERRUPT_FEATURE_ENABLE
    void (*timer3_interrupt_handler)(void) ;
    interrupt_INTx_priority priority ;
#endif     
    uint8_t prescaler_value : 2 ;          
    uint16_t preloaded_value ;
    uint8_t Synchronization : 1 ;
    uint8_t mode : 1 ;
    uint8_t resolution : 1 ;
    uint8_t timer3_reserved : 3 ;
} timer3_config_t ;


/*                                            functions                       */

std_ReturnType Timer3_Init(const timer3_config_t *timer3);
std_ReturnType Timer3_DeInit(const timer3_config_t *timer3);

std_ReturnType Timer3_Read_Value(const timer3_config_t *timer3, uint16_t *value);
std_ReturnType Timer3_Write_Value(const timer3_config_t *timer3, uint16_t value);


#endif	/* HAL_TIMER3_H */

