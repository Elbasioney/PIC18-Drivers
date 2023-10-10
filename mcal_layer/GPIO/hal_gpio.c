/*                                                  includes                                         */

#include "hal_gpio.h"

/*                                               memory locations                                    */

volatile uint8_t *PORT_reg[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};        // ports  addresses
volatile uint8_t *LAT_reg[] = {&LATA, &LATB, &LATC, &LATD, &LATE};              // lats   addresses
volatile uint8_t *TRIS_reg[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};        // trises addresses

/************************************************ pins functions ***************************************************/
/**
 * 
 * @param _pin_config
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
#if GPIO_PIN_CONFIG == ENABLED

std_ReturnType gpio_pin_direction_initialize(const pin_config_t * _pin_config) {
    std_ReturnType ret_val = E_OK;
    if (NULL == _pin_config || _pin_config->pin > (PIN_MAX_NUMBER - 1) || _pin_config->port > (PORT_MAX_NUMBER - 1)) {
        ret_val = E_NOK;
    } else {
        switch (_pin_config->direction) {
            case OUTPUT:
                clear_bit(*(TRIS_reg[_pin_config->port]), _pin_config->pin);
                break;
            case INPUT:
                set_bit(*(TRIS_reg[_pin_config->port]), _pin_config->pin);
                break;
            default: ret_val = E_NOK;
        }
    }
    return ret_val;
}
#endif
/**
 * 
 * @param _pin_config
 * @param dir_status
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
#if GPIO_PIN_CONFIG == ENABLED

std_ReturnType gpio_pin_get_direction(const pin_config_t * _pin_config, direction_t * dir_status) {
    std_ReturnType ret_val = E_OK;
    if (NULL == _pin_config || NULL == dir_status || _pin_config->pin > (PIN_MAX_NUMBER - 1) || _pin_config->port > (PORT_MAX_NUMBER - 1)) {
        ret_val = E_NOK;
    } else {
        *dir_status = read_bit(*(TRIS_reg[_pin_config->port]), _pin_config->pin);
    }
    return ret_val;

}
#endif
/**
 * 
 * @param _pin_config
 * @param logic
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
#if GPIO_PIN_CONFIG == ENABLED

std_ReturnType gpio_pin_write_logic(const pin_config_t * _pin_config, logic_t logic) {
    std_ReturnType ret_val = E_OK;
    if (NULL == _pin_config || _pin_config->pin > (PIN_MAX_NUMBER - 1) || _pin_config->port > (PORT_MAX_NUMBER - 1)) {
        ret_val = E_NOK;
    } else {
        switch (logic) {
            case LOW:
                clear_bit(*LAT_reg[_pin_config->port], _pin_config->pin);
                break;
            case HIGH:
                set_bit(*LAT_reg[_pin_config->port], _pin_config->pin);
                break;
            default: ret_val = E_NOK;
        }
    }
    return ret_val;

}
#endif
/**
 * 
 * @param _pin_config
 * @param logic
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
#if GPIO_PIN_CONFIG == ENABLED

std_ReturnType gpio_pin_read_logic(const pin_config_t * _pin_config, logic_t * logic) {
    std_ReturnType ret_val = E_OK;
    if (NULL == _pin_config || NULL == logic || _pin_config->pin > (PIN_MAX_NUMBER - 1) || _pin_config->port > (PORT_MAX_NUMBER - 1)) {
        ret_val = E_NOK;
    } else {
        *logic = read_bit(*PORT_reg[_pin_config->port], _pin_config->pin);
    }
    return ret_val;
}
#endif
/**
 * 
 * @param _pin_config
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
#if GPIO_PIN_CONFIG == ENABLED

std_ReturnType gpio_pin_toggle_logic(const pin_config_t * _pin_config) {
    std_ReturnType ret_val = E_OK;
    if (NULL == _pin_config || _pin_config->pin > (PIN_MAX_NUMBER - 1) || _pin_config->port > (PORT_MAX_NUMBER - 1)) {
        ret_val = E_NOK;
    } else {
        toggle_bit(*LAT_reg[_pin_config->port], _pin_config->pin);
    }
    return ret_val;

}
#endif
/**
 * 
 * @param _pin_config
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
#if GPIO_PIN_CONFIG == ENABLED

std_ReturnType gpio_pin_init(const pin_config_t * _pin_config) {                /*      used for writing direction and logic of the pin       */
    std_ReturnType ret_val = E_OK;
    if (NULL == _pin_config || _pin_config->pin > (PIN_MAX_NUMBER - 1) || _pin_config->port > (PORT_MAX_NUMBER - 1)) {
        ret_val = E_NOK;
    } else {
        ret_val = gpio_pin_direction_initialize(_pin_config);
        ret_val = gpio_pin_write_logic(_pin_config, _pin_config->logic);
    }
    return ret_val;

}
#endif
/************************************************ ports functions ***************************************************/
/**
 * 
 * @param port
 * @param direction
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
#if GPIO_PORT_CONFIG == ENABLED

std_ReturnType gpio_port_direction_initialize(port_index_t  port, uint8_t direction) {
    std_ReturnType ret_val = E_OK;
    if( port > PORT_MAX_NUMBER - 1 )
    {
        ret_val = E_NOK ;
    }else
    {
        *TRIS_reg[port] = direction ;
    }
    return ret_val;

}
#endif
/**
 * 
 * @param port
 * @param dir_status
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
#if GPIO_PORT_CONFIG == ENABLED

std_ReturnType gpio_port_get_direction(port_index_t  port, direction_t * dir_status) {
    std_ReturnType ret_val = E_OK;
    if( port > PORT_MAX_NUMBER - 1 || NULL == dir_status )
    {
        ret_val = E_NOK ;
    }else
    {
        *dir_status = *TRIS_reg[port] ;
    }
    return ret_val ;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
#if GPIO_PORT_CONFIG == ENABLED

std_ReturnType gpio_port_write_logic(port_index_t port, logic_t logic) {
    std_ReturnType ret_val = E_OK;
    if( port > PORT_MAX_NUMBER - 1 )
    {
        ret_val = E_NOK ;
    }else
    {
        *LAT_reg[port] = logic ;
    }
    return ret_val;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
#if GPIO_PORT_CONFIG == ENABLED

std_ReturnType gpio_port_read_logic(port_index_t port, logic_t * logic) {
    std_ReturnType ret_val = E_OK;
    if( port > PORT_MAX_NUMBER - 1 || logic == NULL )
    {
        ret_val = E_NOK ;
    }else
    {
        *logic = *LAT_reg[port] ;
    }
    return ret_val;

}
#endif
/**
 * 
 * @param port
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
#if GPIO_PORT_CONFIG == ENABLED

std_ReturnType gpio_port_toggle_logic(port_index_t port) {
    std_ReturnType ret_val = E_OK;
    if( port > PORT_MAX_NUMBER - 1 )
    {
        ret_val = E_NOK ;
    }else
    {
        *LAT_reg[port] = *LAT_reg[port] ^ PORT_C_MASK ;
    }
    return ret_val;
}
#endif