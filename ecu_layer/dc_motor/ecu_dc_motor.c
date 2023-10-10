/* 
 * File:   ecu_dc_motor.c
 * Author: ahmed elbsioney
 *
 * Created on March 28, 2023, 12:45 AM
 */


#include "ecu_dc_motor.h"

/**
 * @brief initialize the dc_motor pins
 * @param my_dc_motor
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType dc_motor_init(dc_motor_t *my_dc_motor){
    std_ReturnType RET_VAL = E_NOK ;
    if( NULL == my_dc_motor){
        RET_VAL = E_NOK ;    
    }else{
        pin_config_t my_pin_1 = {.port = my_dc_motor->motor_in_1.port
                                ,.pin = my_dc_motor->motor_in_1.pin
                                ,.direction = OUTPUT
                                ,.logic = my_dc_motor->motor_in_1.logic};
        pin_config_t my_pin_2= {.port = my_dc_motor->motor_in_2.port
                                ,.pin = my_dc_motor->motor_in_2.pin
                                ,.direction = OUTPUT
                                ,.logic = my_dc_motor->motor_in_2.logic};
        RET_VAL = gpio_pin_init(&my_pin_1);
        RET_VAL = gpio_pin_init(&my_pin_2);
        RET_VAL = E_OK ;
    }
    return RET_VAL ;
}
/**
 * @brief make the dc_motor work and turn right
 * @param my_dc_motor
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType dc_motor_move_right(dc_motor_t *my_dc_motor){
   std_ReturnType RET_VAL = E_NOK ;
    if( NULL == my_dc_motor){
        RET_VAL = E_NOK ;    
    }else{
        pin_config_t my_pin_1 = {.port = my_dc_motor->motor_in_1.port
                                ,.pin = my_dc_motor->motor_in_1.pin
                                ,.direction = OUTPUT
                                ,.logic = my_dc_motor->motor_in_1.logic};
        pin_config_t my_pin_2= {.port = my_dc_motor->motor_in_2.port
                                ,.pin = my_dc_motor->motor_in_2.pin
                                ,.direction = OUTPUT
                                ,.logic = my_dc_motor->motor_in_2.logic};
        RET_VAL = gpio_pin_write_logic(&my_pin_1 , HIGH);
        RET_VAL = gpio_pin_write_logic(&my_pin_2 , LOW);
        RET_VAL = E_OK ;
    }
    
    return RET_VAL ; 
}
/**
 * @brief make the dc_motor work and turn left 
 * @param my_dc_motor
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType dc_motor_move_left(dc_motor_t *my_dc_motor){
    std_ReturnType RET_VAL = E_NOK ;
    if( NULL == my_dc_motor){
        RET_VAL = E_NOK ;    
    }else{
        pin_config_t my_pin_1 = {.port = my_dc_motor->motor_in_1.port
                                ,.pin = my_dc_motor->motor_in_1.pin
                                ,.direction = OUTPUT
                                ,.logic = my_dc_motor->motor_in_1.logic};
        pin_config_t my_pin_2= {.port = my_dc_motor->motor_in_2.port
                                ,.pin = my_dc_motor->motor_in_2.pin
                                ,.direction = OUTPUT
                                ,.logic = my_dc_motor->motor_in_2.logic};
        RET_VAL = gpio_pin_write_logic(&my_pin_1 , LOW);
        RET_VAL = gpio_pin_write_logic(&my_pin_2 , HIGH);
        RET_VAL = E_OK ;
    }
    
    return RET_VAL ; 
}
/**
 * @brief stop the dc_motor from working
 * @param my_dc_motor
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType dc_motor_stop(dc_motor_t *my_dc_motor){
    std_ReturnType RET_VAL = E_NOK ;
    if( NULL == my_dc_motor){
        RET_VAL = E_NOK ;    
    }else{
        pin_config_t my_pin_1 = {.port = my_dc_motor->motor_in_1.port
                                ,.pin = my_dc_motor->motor_in_1.pin
                                ,.direction = OUTPUT
                                ,.logic = my_dc_motor->motor_in_1.logic};
        pin_config_t my_pin_2= {.port = my_dc_motor->motor_in_2.port
                                ,.pin = my_dc_motor->motor_in_2.pin
                                ,.direction = OUTPUT
                                ,.logic = my_dc_motor->motor_in_2.logic};
        RET_VAL = gpio_pin_write_logic(&my_pin_1 , LOW);
        RET_VAL = gpio_pin_write_logic(&my_pin_2 , LOW);
        RET_VAL = E_OK ;    
    }
    
    return RET_VAL ;   
}