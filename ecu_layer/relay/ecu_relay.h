/* 
 * File:   ecu_relay.h
 * Author: ahmed elbasioney
 *
 * Created on March 27, 2023, 1:23 AM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/*                            includes section             */
#include "../../mcal_layer/GPIO/hal_gpio.h"



/*                            macros section               */

#define RELAY_ON   0x01U
#define RELAY_OFF  0x00U


/*                           data types section             */

typedef struct {
    char port   : 4 ;
    char pin    : 3 ;
    char status : 1 ;
    
}relay_t;


/*                           functions section              */

std_ReturnType relay_init( const relay_t *my_relay ) ;
std_ReturnType relay_on( const relay_t *my_relay ) ;
std_ReturnType relay_off( const relay_t *my_relay ) ;
std_ReturnType relay_toggle( const relay_t *my_relay ) ;

#endif	/* ECU_RELAY_H */

