
#include "ecu_relay.h"

/**
 * @brief initialize the relay pin
 * @param my_relay
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType relay_init( const relay_t *my_relay ){
    std_ReturnType RET_VAL = E_NOK ; 
    pin_config_t my_relay_config = { .port = my_relay->port
                                    ,.pin = my_relay->pin
                                    ,.logic = my_relay->status
                                    ,.direction = OUTPUT };
    if(NULL == my_relay)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = gpio_pin_init(&my_relay_config);
        RET_VAL = E_OK ;
    }   
    return RET_VAL ;
}
/**
 * @brief turn on the relay pin 
 * @param my_relay
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType relay_on( const relay_t *my_relay ) {
    std_ReturnType RET_VAL = E_NOK ; 
    logic_t turn_on_logic = HIGH ;
    pin_config_t my_relay_config = { .port = my_relay->port
                                    ,.pin = my_relay->pin
                                    ,.logic = my_relay->status
                                    ,.direction = OUTPUT };
    if(NULL == my_relay)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = gpio_pin_write_logic(&my_relay_config , turn_on_logic );
        RET_VAL = E_OK ;
    }   
    return RET_VAL ;    
}
/**
 * @turn off the relay pin 
 * @param my_relay
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType relay_off( const relay_t *my_relay ) {
    std_ReturnType RET_VAL = E_NOK ; 
    logic_t turn_off_logic = LOW ;
    pin_config_t my_relay_config = { .port = my_relay->port
                                    ,.pin = my_relay->pin
                                    ,.logic = my_relay->status
                                    ,.direction = OUTPUT };
    if(NULL == my_relay)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = gpio_pin_write_logic(&my_relay_config , turn_off_logic );
        RET_VAL = E_OK ;
    }    
    return RET_VAL ;    
}

/**
 * @brief toggle the relay pin 
 * @param my_relay
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType relay_toggle( const relay_t *my_relay ) {
    std_ReturnType RET_VAL = E_NOK ;
    pin_config_t my_relay_config = { .port = my_relay->port
                                    ,.pin = my_relay->pin
                                    ,.logic = my_relay->status
                                    ,.direction = OUTPUT };
    if(NULL == my_relay)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = gpio_pin_toggle_logic(&my_relay_config);
        RET_VAL = E_OK ;
    }   
    return RET_VAL ;  
}
