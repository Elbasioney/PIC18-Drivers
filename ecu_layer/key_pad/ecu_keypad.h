/* 
 * File:   ecu_keypad.h
 * Author: Ahmed Elbasioney
 *
 * Created on April 10, 2023, 8:10 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H


/*                            includes section             */
#include "../../mcal_layer/GPIO/hal_gpio.h"



/*                            macros section               */

#define keypad_rows_number      4
#define keypad_columns_number   4

/*                           data types section             */

typedef struct {
    pin_config_t keypad_rows[keypad_rows_number];
    pin_config_t keypad_columns[keypad_columns_number];  
}keypad_t;
  

/*                           functions section              */

std_ReturnType keypad_init(const keypad_t *my_keypad );
std_ReturnType keypad_get_value(const keypad_t *my_keypad , char *value);

#endif	/* ECU_KEYPAD_H */

