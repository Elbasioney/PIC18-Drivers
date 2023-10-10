/* 
 * File:   hal_gpio.h
 * Author: Ahmed Elbasioney 
 *
 * Created on March 8, 2023, 5:24 PM
 */

#ifndef _hal_gpio_h
#define	_hal_gpio_h

/*                   includes   section                */
#include "../../mcal_layer/device_conf.h"
#include "../mcal_std_types.h"
#include <xc.h> 

/*                   macros    section                 */
#define HWREG8(x)   (*((volatile uint8*)(x)))

#define BIT_MASK  (uint8_t)0x01 

#define set_bit(reg,bit_pos) (reg |= (BIT_MASK << bit_pos))
#define clear_bit(reg,bit_pos) (reg &= ~(BIT_MASK << bit_pos))
#define toggle_bit(reg,bit_pos) (reg ^= (BIT_MASK << bit_pos))
#define read_bit(reg,bit_pos)   ((reg >> bit_pos) & BIT_MASK)

#define PIN_MAX_NUMBER     8
#define PORT_MAX_NUMBER    5
#define PORT_C_MASK        0xFF  

#define GPIO_PIN_CONFIG ENABLED
#define GPIO_PORT_CONFIG ENABLED

/*                   datatype  section                 */

typedef enum {
    LOW = 0 ,
    HIGH
}logic_t;

typedef enum {
    OUTPUT = 0 ,
    INPUT
}direction_t;

typedef enum {
    PIN0 = 0 ,
    PIN1 ,
    PIN2 ,
    PIN3 ,
    PIN4 ,
    PIN5 ,
    PIN6 ,
    PIN7       
}pin_index_t;

typedef enum 
{
    PORTA_INDEX = 0 ,
    PORTB_INDEX ,
    PORTC_INDEX ,
    PORTD_INDEX ,
    PORTE_INDEX
}port_index_t;

typedef struct 
{
    uint8_t port        : 3 ; /* @ref port_index_t */
    uint8_t pin         : 3 ; /* @ref pin_index_t */
    uint8_t direction   : 1 ; /* @ref direction_t */
    uint8_t logic       : 1 ; /* @ref logic_t */
}pin_config_t;

/*                   functions section                 */

std_ReturnType gpio_pin_direction_initialize(const pin_config_t * _pin_config );
std_ReturnType gpio_pin_get_direction(const pin_config_t * _pin_config , direction_t  * dir_status );
std_ReturnType gpio_pin_write_logic(const pin_config_t * _pin_config , logic_t  logic );
std_ReturnType gpio_pin_read_logic(const pin_config_t * _pin_config , logic_t * logic );    
std_ReturnType gpio_pin_toggle_logic(const pin_config_t * _pin_config);
std_ReturnType gpio_pin_init(const pin_config_t * _pin_config);

std_ReturnType gpio_port_direction_initialize(port_index_t  port, uint8_t direction);
std_ReturnType gpio_port_get_direction(port_index_t  port, direction_t * dir_status);
std_ReturnType gpio_port_write_logic(port_index_t port, logic_t logic);
std_ReturnType gpio_port_read_logic(port_index_t port, logic_t * logic);
std_ReturnType gpio_port_toggle_logic(port_index_t port);

#endif




