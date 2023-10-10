/* 
 * File:   ecu_pb.h
 * Author: ahmed elbasioney
 *
 * Created on March 23, 2023, 5:17 PM
 */

#ifndef ECU_PB_H
#define	ECU_PB_H

/*                                     includes section                      */
#include "../../mcal_layer/GPIO/hal_gpio.h"


/*                                     macros section                       */


/*                                     datatype section                     */

typedef enum {
    PB_PRESSED  ,
    PB_RELEASED 
}pb_status_t;

typedef enum {
    PB_ACTIVE_HIGH ,
    PB_ACTIVE_LOW
}pb_active_status_t;

typedef struct {
    pin_config_t my_pb ;
    pb_active_status_t my_pb_active_status ;
    pb_status_t  my_pb_status ;
}push_button_t;

/*                                     functions section                     */

std_ReturnType pb_initialize(const push_button_t *my_pb );
std_ReturnType pb_read_status(const push_button_t *my_pb , pb_status_t *my_pb_status);


#endif	/* ECU_PB_H */

