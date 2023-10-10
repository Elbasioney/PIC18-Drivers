/* 
 * File:   hal_timer1.h
 * Author: Ahmed Elbasioney
 *
 * Created on May 4, 2023, 3:46 PM
 */

#ifndef HAL_TIMER1_H
#define	HAL_TIMER1_H

/*                                        includes                          */

#include <xc.h>
#include "../GPIO/hal_gpio.h"
#include "../interrupt/mcal_internal_interrupt.h"
#include "../mcal_std_libararies.h"
#include "../mcal_std_types.h"

/*                                            macros                         */


#define TIMER1_COUNTER_MODE   0x01U
#define TIMER1_TIMER_MODE     0x00U

#define TIMER1_Synchronization_ON  0x00U
#define TIMER1_Synchronization_OFF 0x01U

#define TIMER1_HW_OSCILLATOR_ENABLE   0x01U
#define TIMER1_HW_OSCILLATOR_DISABLE  0x00U

#define TIMER1_16BIT_MODE     0x01U
#define TIMER1_8BIT_MODE      0x00U

/*                                        macro like functions                */

#define TIMER1_FEATURE_ENABLE()      (T1CONbits.TMR1ON = 1 )    // enable timer1 module
#define TIMER1_FEATURE_DISABLE()     (T1CONbits.TMR1ON = 0 )    // disable timer1 module

#define TIMER1_COUNTER_MODE_SET()    (T1CONbits.TMR1CS = 1 )    // set timer1 to be at counter mode 
#define TIMER1_TIMER_MODE_SET()      (T1CONbits.TMR1CS = 0 )    // set timer1 to be at timer mode 

#define TIMER1_ENABLE_Synchronization()  (T1CONbits.T1SYNC = 0 )    // Synchronize the input clock with timer1
#define TIMER1_DISABLE_Synchronization() (T1CONbits.T1SYNC = 1 )    // do not Synchronize the input clock with timer1

#define TIMER1_HW_OSCILLATOR_ENABLE_SET()   (T1CONbits.T1OSCEN = 1)    // enable timer1 oscillator
#define TIMER1_HW_OSCILLATOR_DISABLE_SET()  (T1CONbits.T1OSCEN = 0)    // disable timer1 oscillator

#define TIMER1_16BIT_MODE_SET()   (T1CONbits.RD16 = 1)          // set timer1 to 16-bit register mode 
#define TIMER1_8BIT_MODE_SET()    (T1CONbits.RD16 = 0)          // set timer1 to 8-bit register mode 

#define TIMER1_SET_PRESCALER_VALUE(_prescaler_value_)   ( T1CONbits.T1CKPS = _prescaler_value_)     // set prescaler choosen value 

#define TIMER1_SYSTEM_CLK_STATUS()     (T1CONbits.T1RUN)    // describe the oscillator connected to timer 1 status

/*                                           data types                       */

typedef enum {
    TIMER1_PRESCALER_DIV_BY_1 = 0,
    TIMER1_PRESCALER_DIV_BY_2,
    TIMER1_PRESCALER_DIV_BY_4,
    TIMER1_PRESCALER_DIV_BY_8
} prescaler_value_t;

typedef struct {
#if TIMER1_INTERRUPT_FEATURE_ENABLE
    void (*timer1_interrupt_handler)(void) ;
    interrupt_INTx_priority priority ;
#endif    
    uint8_t timer1_mode : 1;  // counter or timer
    uint8_t timer1_counter_mode_synchronization_status : 1;  //  Synchronization_ON or Synchronization_OFF
    uint8_t timer1_oscillator_status : 1;   // enabled or disabled
    uint8_t prescaler_value : 2 ;          // set pre-scaler value ( 1 , 2 , 4 , 8 )
    uint8_t timer1_register_size : 1 ;    // 8-bit or 16-bit 
    uint16_t preloaded_value ;           // set the pre-loaded value into TMR1H & TMR1L 
} timer1_config_t;


/*                                            functions                       */

std_ReturnType Timer1_Init(timer1_config_t *timer1);
std_ReturnType Timer1_DeInit(timer1_config_t *timer1);

std_ReturnType Timer1_Read_Value(timer1_config_t *timer1, uint16_t *value);
std_ReturnType Timer1_Write_Value(timer1_config_t *timer1, uint16_t value);

#endif	/* HAL_TIMER1_H */

