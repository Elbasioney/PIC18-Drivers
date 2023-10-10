/* 
 * File:   ecu_dc_motor.h
 * Author: ahmed elbsioney
 *
 * Created on March 28, 2023, 12:45 AM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/*                                includes  section                   */

#include "../../mcal_layer/GPIO/hal_gpio.h"

/*                                macros  section                      */

#define DC_MOTOR_ON  0x01U
#define DC_MOTOR_OFF 0x00U

/*                                data types section                   */

typedef struct {
    pin_config_t motor_in_1 ;
    pin_config_t motor_in_2 ;
}dc_motor_t;

/*                                functions  section                   */

std_ReturnType dc_motor_init(dc_motor_t *my_dc_motor);
std_ReturnType dc_motor_move_right(dc_motor_t *my_dc_motor);
std_ReturnType dc_motor_move_left(dc_motor_t *my_dc_motor);
std_ReturnType dc_motor_stop(dc_motor_t *my_dc_motor);

#endif	/* ECU_DC_MOTOR_H */

