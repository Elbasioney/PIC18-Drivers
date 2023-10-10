/* 
 * File:   app.h
 * Author: ahmed elbasioney
 *
 * Created on March 8, 2023, 5:52 PM
 */

#ifndef APP_H
#define	APP_H

/*                               includes  section                       */


#include <builtins.h>
#include "mcal_layer/compiler.h" 
#include "mcal_layer/GPIO/hal_gpio.h"

#include "mcal_layer/device_conf.h"

#include "ecu_layer/ecu_init/ecu_init.h"

#include "mcal_layer/interrupt/mcal_external_interrupt.h"

#include "mcal_layer/EEPROM/hal_eeprom.h"

#include "mcal_layer/ADC/hal_adc.h"

#include "mcal_layer/Timer0/hal_timer0.h"

#include "mcal_layer/Timer1/hal_timer1.h"

#include "mcal_layer/Timer2/hal_timer2.h"

#include "mcal_layer/Timer3/hal_timer3.h"

#include "mcal_layer/CCP/hal_ccp.h"

#include "mcal_layer/EUSART/hal_EUSART.h"


/*                               macros  section                        */


/*                               datatype  section                      */




/*                               functions  section                      */

void APP_INIT(void);
void program_selected_function(void);

#endif
