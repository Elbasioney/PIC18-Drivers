/* 
 * File:   ecu_7_segment.c
 * Author: AHMED ELBASIONEY
 *
 * Created on April 10, 2023, 11:38 AM
 */

#include "ecu_7_segment.h"


/**
 * @brief initialize the 7 segment pins 
 * @param seg
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType seven_segment_init(const segment_t *seg){
    std_ReturnType RET_VAL = E_NOK ; 
    if(NULL == seg )
    {
        RET_VAL = E_NOK ; 
    }else{
        RET_VAL = gpio_pin_init(&(seg->seg_pin_1));
        RET_VAL = gpio_pin_init(&(seg->seg_pin_2));
        RET_VAL = gpio_pin_init(&(seg->seg_pin_3));
        RET_VAL = gpio_pin_init(&(seg->seg_pin_4));
        RET_VAL = E_OK ; 
    }
    
    return RET_VAL ; 
}

/**
 * @brief write number on the seven segment display
 * @param seg
 * @param number
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType seven_segment_write_number(const segment_t *seg, const char number){
    std_ReturnType RET_VAL = E_NOK ; 
    if((NULL == seg) || (number > 9))
    {
        RET_VAL = E_NOK ; 
    }else{
        RET_VAL = gpio_pin_write_logic(&(seg->seg_pin_1),(number&1));
        RET_VAL = gpio_pin_write_logic(&(seg->seg_pin_2),((number >> 1)&1));
        RET_VAL = gpio_pin_write_logic(&(seg->seg_pin_3),((number >> 2)&1));
        RET_VAL = gpio_pin_write_logic(&(seg->seg_pin_4),((number >> 3)&1));
        RET_VAL = E_OK ;
    }
    
    return RET_VAL ;    
}
