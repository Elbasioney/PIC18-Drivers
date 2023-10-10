/* 
 * File:   ecu_7_segment.h
 * Author: AHMED ELBASIONEY
 *
 * Created on April 10, 2023, 11:38 AM
 */

#ifndef ECU_7_SEGMENT_H
#define	ECU_7_SEGMENT_H


/*                   includes   section                */

#include "../../mcal_layer/GPIO/hal_gpio.h"

/*                   macros    section                 */


/*                   datatype  section                 */

typedef enum{
    common_anode ,
    common_cathode
}segment_type_t;

typedef struct {
    pin_config_t    seg_pin_1 ;
    pin_config_t    seg_pin_2 ;
    pin_config_t    seg_pin_3 ;
    pin_config_t    seg_pin_4 ;
    segment_type_t  seg_type  ;
}segment_t;

/*                   functions section                 */

std_ReturnType seven_segment_init(const segment_t *seg);
std_ReturnType seven_segment_write_number(const segment_t *seg, const char number);

#endif	/* ECU_7_SEGMENT_H */

