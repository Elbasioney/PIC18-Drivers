/* 
 * File:   ecu_keypad.c
 * Author: Ahmed Elbasioney
 *
 * Created on April 10, 2023, 8:10 PM
 */

#include "ecu_keypad.h"

const char btn_values[keypad_rows_number][keypad_columns_number] = {
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'#', '0', '=', '+'}
};

/**
 * @brief initialize the keypad pins
 * @param my_keypad
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType keypad_init(const keypad_t *my_keypad) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == my_keypad) {
        RET_VAL = E_NOK;
    } else {
        for (int i = 0; i < keypad_rows_number; i++) {
            RET_VAL = gpio_pin_init(&(my_keypad->keypad_rows[i]));
        }

        for (int j = 0; j < keypad_columns_number; j++) {
            RET_VAL = gpio_pin_init(&(my_keypad->keypad_columns[j]));
        }
        RET_VAL = E_OK;

    }
    return RET_VAL;
}

/**
 * @brief get the value at the pressed pin in the keypad
 * @param my_keypad
 * @param value
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType keypad_get_value(const keypad_t *my_keypad, char *value) {
    std_ReturnType RET_VAL = E_NOK;
    logic_t column_logic = LOW;
    char i = 0;
    char j = 0;
    char x = 0;
    if ((NULL == my_keypad) || (NULL == value)) {
        RET_VAL = E_NOK;
    } else {
        for (i = 0; i < keypad_rows_number; i++) {
            for (j = 0; j < keypad_rows_number; j++) {
                RET_VAL = gpio_pin_write_logic(&(my_keypad->keypad_rows[j]), LOW);
            }
            RET_VAL = gpio_pin_write_logic(&(my_keypad->keypad_rows[i]), HIGH);
            for (x = 0; x < keypad_columns_number; x++) {
                RET_VAL = gpio_pin_read_logic(&(my_keypad->keypad_columns[x]), &column_logic);
                if ((HIGH == column_logic)) {
                    *value = btn_values[i][x];
                } else {

                }
            }
        }


        RET_VAL = E_OK;
    }
    return RET_VAL;
}
