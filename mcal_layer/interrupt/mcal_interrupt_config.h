/* 
 * File:   mcal_interrupt_config.h
 * Author: LENOVO
 *
 * Created on April 19, 2023, 4:16 AM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

/*                               includes  section                       */

#include <xc.h>
#include "../mcal_std_libararies.h"
#include "../mcal_std_types.h"
#include "mcal_interrupt_gen_cfg.h"
#include "../GPIO/hal_gpio.h"

/*                               macros  section                        */

#define INTERRUPT_ENABLE            1
#define INTERRUPT_DISABLE           0
#define INTERRUPT_OCCUR             1
#define INTERRUPT_NOT_OCCUR         0
#define INTERRUPT_PRIORITY_ENABLE   1


/*                              macro functions section                 */

#if INTERRUPT_PRIORITY_LEVELS_ENABLE

#define INTERRUPT_PRIORITY_ENABLE()  (RCONbits.IPEN = 1)   // enable priortiy levels
#define INTERRUPT_PRIORITY_DISABLE()  (RCONbits.IPEN = 0)  // disable priortiy levels

#define INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE()  (INTCONbits.GIEH = 1)   // enable high priortiy global interrupts
#define INTERRUPT_GLOBAL_INTERRUPT_HIGH_DISABLE()  (INTCONbits.GIEH = 0)  // disable high priortiy global interrupts

#define INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE()  (INTCONbits.GIEL = 1)    // enable low priortiy global interrupts
#define INTERRUPT_GLOBAL_INTERRUPT_LOW_DISABLE()  (INTCONbits.GIEL = 0)   // disable low priortiy global interrupts

#define INTERRUPT_PERIPHERALS_INTERRUPT_ENABLE()   (INTCONbits.PEIE = 1)  // enable peripherals interrupts
#define INTERRUPT_PERIPHERALS_INTERRUPT_DISABLE()   (INTCONbits.PEIE = 0) // disable peripherals interrupts

#define INTERRUPT_GLOBAL_INTERRUPT_ENABLE()  (INTCONbits.GIE = 1)   // enable global interrupts
#define INTERRUPT_GLOBAL_INTERRUPT_DISABLE()  (INTCONbits.GIE = 0)  // disable global interrupts

#else

#define INTERRUPT_GLOBAL_INTERRUPT_ENABLE()  (INTCONbits.GIE = 1)   // enable global interrupts
#define INTERRUPT_GLOBAL_INTERRUPT_DISABLE()  (INTCONbits.GIE = 0)  // disable global interrupts

#define INTERRUPT_PERIPHERALS_INTERRUPT_ENABLE()   (INTCONbits.PEIE = 1)  // enable peripherals interrupts
#define INTERRUPT_PERIPHERALS_INTERRUPT_DISABLE()   (INTCONbits.PEIE = 0) // disable peripherals interrupts


#endif

/*                              datatype  section                       */

typedef enum {
    INTERRUPT_LOW_PRIORITY = 0 ,
    INTERRUPT_HIGH_PRIORITY   
}interrupt_INTx_priority;

/*                              functions  section                      */


#endif	/* MCAL_INTERRUPT_CONFIG_H */

