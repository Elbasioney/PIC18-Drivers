/* 
 * File:   hal_timer0.h
 * Author: Ahmed Elbasioney
 *
 * Created on April 30, 2023, 10:30 PM
 */

#ifndef HAL_TIMER0_H
#define	HAL_TIMER0_H


/*                              includes                   */

#include "../interrupt/mcal_internal_interrupt.h"
#include "../xc.h"
#include "../GPIO/hal_gpio.h"
#include "../mcal_std_libararies.h"
#include "../mcal_std_types.h"

/*                               macros  section                        */

#define TIMER0_PRESCALER_ENABLE_CFG     0x01U
#define TIMER0_PRESCALER_DISABLE_CFG    0x00U

#define TIMER0_RAISING_EDGE_ENABLE_CFG  0x01U
#define TIMER0_FALLING_EDGE_ENABLE_CFG  0x00U

#define TIMER0_COUNTER_MODE_ENABLE_CFG  0x01U
#define TIMER0_TIMER_MODE_ENABLE_CFG    0x00U

#define TIMER0_16BIT_MODE_ENABLE_CFG    0x01U
#define TIMER0_8BIT_MODE_ENABLE_CFG     0x00U

/*                         macro like  functions section                 */

#define TIMER0_FEATURE_ENABLE()        (T0CONbits.TMR0ON =  1)
#define TIMER0_FEATURE_DISABLE()       (T0CONbits.TMR0ON =  0)

#define TIMER0_ENABLE_PRESCALER()      (T0CONbits.PSA =  0)
#define TIMER0_DISABLE_PRESCALER()     (T0CONbits.PSA =  1)

#define TIMER0_RAISING_EDGE_SET()      (T0CONbits.T0SE =  0) 
#define TIMER0_FALLING_EDGE_SET()      (T0CONbits.T0SE =  1)

#define TIMER0_8BIT_SET()              (T0CONbits.T08BIT =  1)
#define TIMER0_16BIT_SET()             (T0CONbits.T08BIT =  0)

#define TIMER0_COUNTER_MODE_SET()      (T0CONbits.T0CS =  1)
#define TIMER0_TIMER_MODE_SET()        (T0CONbits.T0CS =  0)

/*                               datatype  section                      */




typedef enum {
    TIMER0_PRESCALER_DIV_BY_2 = 0,
    TIMER0_PRESCALER_DIV_BY_4,
    TIMER0_PRESCALER_DIV_BY_8,
    TIMER0_PRESCALER_DIV_BY_16,
    TIMER0_PRESCALER_DIV_BY_32,
    TIMER0_PRESCALER_DIV_BY_64,
    TIMER0_PRESCALER_DIV_BY_128,
    TIMER0_PRESCALER_DIV_BY_256
} timer0_prescaler_value_t;

typedef struct {
#if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (* TIMER0_INTERRUPT_HANDLER)(void);
    interrupt_INTx_priority priority;
#endif
    uint16_t preloaded_value;
    timer0_prescaler_value_t prescaler_value;
    uint8_t edge : 1; // raising or falling edge
    uint8_t prescaler_status : 1; // enabled or disabled
    uint8_t mode : 1; // counter or timer
    uint8_t resolution : 1; // 8-bit or 16-bit
} timer0_config_t;


/*                               functions  section                      */

std_ReturnType Timer0_Init(const timer0_config_t *timer0);
std_ReturnType Timer0_DeInit(const timer0_config_t *timer0);

std_ReturnType Timer0_Read_Value(const timer0_config_t *timer0, uint16_t *value);
std_ReturnType Timer0_Write_Value(const timer0_config_t *timer0, uint16_t value);

#endif	/* HAL_TIMER0_H */

