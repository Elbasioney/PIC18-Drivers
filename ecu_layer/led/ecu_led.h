/* 
 * File:   ecu_led.h
 * Author: Ahmed Elbasioney
 *
 * Created on March 8, 2023, 5:45 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H
/*                                includes section                      */
#include "../../mcal_layer/GPIO/hal_gpio.h"


/*                                macros section                        */

/*                                datatype section                      */

typedef enum{
    LED_OFF = 0 ,
    LED_ON   
}led_status_t;

typedef struct{
    uint8_t port   : 4 ;
    uint8_t pin    : 3 ;
    uint8_t status : 1 ;
}led_t;

 

/*                                function section                      */

std_ReturnType led_initialize(const led_t *led );
std_ReturnType led_turn_on(const led_t *led );
std_ReturnType led_turn_off(const led_t *led );
std_ReturnType led_toggle(const led_t *led );

#endif

