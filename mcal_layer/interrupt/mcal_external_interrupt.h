/* 
 * File:   mcal_external_interrupt.h
 * Author: Ahmed Elbasioney
 *
 * Created on April 19, 2023, 4:18 AM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H


/*                               includes  section                       */

#include "mcal_interrupt_config.h"


/*                               macro functions  section                        */


/*                               external INTx interrupts                        */
#if EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE

#define EXT_INT0_INTERRUPT_ENABLE()       (INTCONbits.INT0IE = 1)   // enable int0 interrupt pin
#define EXT_INT0_INTERRUPT_DISABLE()      (INTCONbits.INT0IE = 0)   // disable int0 interrupt pin
#define CLEAR_INT0_INTERRUPT_FLAG()   (INTCONbits.INT0IF = 0 )  // clear int0 falg bit
#define EXT_INT0_RISING_EDGE_SET()    (INTCON2bits.INTEDG0 = 1) // set int0 action to rising edge
#define EXT_INT0_FALLING_EDGE_SET()   (INTCON2bits.INTEDG0 = 0) // set int0 action to falling edge


#define EXT_INT1_INTERRUPT_ENABLE()       (INTCON3bits.INT1IE = 1)   // enable int1 interrupt pin
#define EXT_INT1_INTERRUPT_DISABLE()      (INTCON3bits.INT1IE = 0)   // disable int1 interrupt pin
#define CLEAR_INT1_INTERRUPT_FLAG()   (INTCON3bits.INT1IF = 0 )  // clear int1 flag bit
#define EXT_INT1_RISING_EDGE_SET()    (INTCON2bits.INTEDG1 = 1)  // set int1 action to rising edge
#define EXT_INT1_FALLING_EDGE_SET()   (INTCON2bits.INTEDG1 = 0)  // set int1 action to falling edge

#define EXT_INT2_INTERRUPT_ENABLE()       (INTCON3bits.INT2IE = 1)   // enable int2 interrupt pin
#define EXT_INT2_INTERRUPT_DISABLE()      (INTCON3bits.INT2IE = 0)   // disable int2 interrupt pin
#define CLEAR_INT2_INTERRUPT_FLAG()   (INTCON3bits.INT2IF = 0 )  // clear int2 flag bit
#define EXT_INT2_RISING_EDGE_SET()    (INTCON2bits.INTEDG2 = 1)  // set int2 action to rising edge
#define EXT_INT2_FALLING_EDGE_SET()   (INTCON2bits.INTEDG2 = 0)  // set int2 action to falling edge


#if INTERRUPT_PRIORITY_LEVELS_ENABLE

#define EXT_INT1_INTERRUPT_HIGH_PRIORITY()       (INTCON3bits.INT1IP = 1)   // enable int1 interrupt priority
#define EXT_INT1_INTERRUPT_LOW_PRIORITY()       (INTCON3bits.INT1IP = 0)   // disable int1 interrupt priority

#define EXT_INT2_INTERRUPT_HIGH_PRIORITY()       (INTCON3bits.INT2IP = 1)   // enable int2 interrupt priority
#define EXT_INT2_INTERRUPT_LOW_PRIORITY()       (INTCON3bits.INT2IP = 0)   // disable int2 interrupt priority

#endif

#endif


/*                               external on-change interrupts                        */
#if EXTERNAL_INTERRUPT_onchange_FEATURE_ENABLE

#define EXT_RBx_INTERRUPT_ENABLE()                    (INTCONbits.RBIE = 1 ) // enable all on-change interrupts
#define EXT_RBx_INTERRUPT_DISABLE()                   (INTCONbits.RBIE = 0 ) // disable all on-change interrupts
#define CLEAR_EXTERNAL_INTERRUPT_onchange_FLAG()      (INTCONbits.RBIF = 0 ) // clear on-change interrupts bit 

#if INTERRUPT_PRIORITY_LEVELS_ENABLE

#define EXT_RBx_PRIORITY_HIGH()        (INTCON2bits.RBIP = 1 )  // on-change interrupts high priority
#define EXT_RBx_PRIORITY_LOW()         (INTCON2bits.RBIP = 0 )  // on-change interrupts low priority


#endif

#endif

/*                               datatype  section                      */

typedef enum {
    INTERRUPT_FALLING_EDGE = 0 ,
    INTERRUPT_RISING_EDGE
}interrupt_INTx_edge;

typedef enum {
    INTERRUPT_EXTERNAL_INT0 = 0 ,
    INTERRUPT_EXTERNAL_INT1     ,
    INTERRUPT_EXTERNAL_INT2  
}interrupt_INTx_source;



typedef struct {
    void (* external_interrupt_handler)(void);
    interrupt_INTx_edge edge ;
    interrupt_INTx_source source ;
    interrupt_INTx_priority priority ;
    pin_config_t mcu_pin ;
}interrupt_INTx_t;

typedef struct {
    void (* external_interrupt_handler)(void);
    pin_config_t mcu_pin ;
    interrupt_INTx_priority priority ;
}interrupt_RBx_t;

/*                               functions  section                      */

std_ReturnType interrupt_INTx_init(const interrupt_INTx_t *interrupt_object );
std_ReturnType interrupt_INTx_deinit(const interrupt_INTx_t *interrupt_object );

std_ReturnType interrupt_RBx_init(const interrupt_RBx_t *interrupt_object );
std_ReturnType interrupt_RBx_deinit(const interrupt_RBx_t *interrupt_object );

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

