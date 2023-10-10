/* 
 * File:   ecu_led.c
 * Author: Ahmed Elbasioney
 *
 * Created on March 8, 2023, 5:45 PM
 */

#include "ecu_led.h"

/**
 * @brief  initialize the assigned led to be output and turn the led off
 * @param  led
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType led_initialize(const led_t * led) {
    std_ReturnType ret_val = E_NOK;
    pin_config_t pin_obj = {.port = led->port
        , .pin = led->pin
        , .direction = OUTPUT
        , .logic = led->status};

    if (NULL == led) {
        ret_val = E_NOK;
    } else {
        ret_val = gpio_pin_init(&pin_obj);
        ret_val = E_OK;
    }
    return ret_val;
}

/**
 * @brief  turn on the assigned led 
 * @param  led
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType led_turn_on(const led_t * led) {
    std_ReturnType ret_val = E_NOK;
    pin_config_t pin_obj = {.port = led->port
        , .pin = led->pin
        , .direction = OUTPUT
        , .logic = led->status};

    if (NULL == led) {
        ret_val = E_NOK;
    } else {
        ret_val = gpio_pin_write_logic(&pin_obj,HIGH);
        ret_val = E_OK;
    }
    return ret_val;

}

/**
 * @brief  turn off the assigned led 
 * @param  led
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType led_turn_off(const led_t * led) {
    std_ReturnType ret_val = E_NOK;
    pin_config_t pin_obj = {.port = led->port
        , .pin = led->pin
        , .direction = OUTPUT
        , .logic = led->status};

    if (NULL == led) {
        ret_val = E_NOK;
    } else {
        ret_val = gpio_pin_write_logic(&pin_obj,LOW);
        ret_val = E_OK;
    }
    return ret_val;

}

/**
 * @brief  toggle the assigned led 
 * @param  led
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType led_toggle(const led_t * led) {
    std_ReturnType ret_val = E_NOK;
    pin_config_t pin_obj = {.port = led->port
        , .pin = led->pin
        , .direction = OUTPUT
        , .logic = led->status};

    if (NULL == led) {
        ret_val = E_NOK;
    } else {
        ret_val = gpio_pin_toggle_logic(&pin_obj);
        ret_val = E_OK;
    }
    return ret_val;

}