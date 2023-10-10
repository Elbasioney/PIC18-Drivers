/* 
 * File:   hal_timer2.h
 * Author: Ahmed Elbasioney
 *
 * Created on May 5, 2023, 12:40 AM
 */

#ifndef HAL_TIMER2_H
#define	HAL_TIMER2_H

/*                                        includes                          */

#include <xc.h>
#include "../GPIO/hal_gpio.h"
#include "../interrupt/mcal_internal_interrupt.h"
#include "../mcal_std_libararies.h"
#include "../mcal_std_types.h"

/*                                            macros                         */

#define TIMER2_PRESCALER_DIV_BY_1    0 
#define TIMER2_PRESCALER_DIV_BY_4    1
#define TIMER2_PRESCALER_DIV_BY_16   2 

#define TIMER2_POSTSCALER_DIV_BY_1   0
#define TIMER2_POSTSCALER_DIV_BY_2   1
#define TIMER2_POSTSCALER_DIV_BY_3   2
#define TIMER2_POSTSCALER_DIV_BY_4   3
#define TIMER2_POSTSCALER_DIV_BY_5   4
#define TIMER2_POSTSCALER_DIV_BY_6   5
#define TIMER2_POSTSCALER_DIV_BY_7   6
#define TIMER2_POSTSCALER_DIV_BY_8   7
#define TIMER2_POSTSCALER_DIV_BY_9   8
#define TIMER2_POSTSCALER_DIV_BY_10  9
#define TIMER2_POSTSCALER_DIV_BY_11  10
#define TIMER2_POSTSCALER_DIV_BY_12  11
#define TIMER2_POSTSCALER_DIV_BY_13  12
#define TIMER2_POSTSCALER_DIV_BY_14  13
#define TIMER2_POSTSCALER_DIV_BY_15  14
#define TIMER2_POSTSCALER_DIV_BY_16  15



/*                                        macro like functions                */

#define TIMER2_FEATURE_ENABLE()      (T2CONbits.TMR2ON = 1 )    // enable timer2 module
#define TIMER2_FEATURE_DISABLE()     (T2CONbits.TMR2ON = 0 )    // disable timer2 module


#define TIMER2_SET_PRESCALER_VALUE(X)     ( T2CONbits.T2CKPS  = X)     // set prescaler choosen value 
#define TIMER2_SET_POSTSCALER_VALUE(Y)   ( T2CONbits.T2OUTPS = Y)     // set postscaler choosen value 


/*                                           data types                       */

typedef struct {
#if TIMER2_INTERRUPT_FEATURE_ENABLE
    void (*timer2_interrupt_handler)(void) ;
    interrupt_INTx_priority priority ;
#endif    
    uint8_t postscaler_value : 4 ; 
    uint8_t prescaler_value : 2 ;          
    uint8_t preloaded_value ;           
} timer2_config_t ;


/*                                            functions                       */

std_ReturnType Timer2_Init(timer2_config_t *timer2);
std_ReturnType Timer2_DeInit(timer2_config_t *timer2);

std_ReturnType Timer2_Read_Value(timer2_config_t *timer2, uint8_t *value);
std_ReturnType Timer2_Write_Value(timer2_config_t *timer2, uint8_t value);


#endif	/* HAL_TIMER2_H */

