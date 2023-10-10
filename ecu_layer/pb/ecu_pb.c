
#include "ecu_pb.h"

/**
 * @brief initialize the push button regular status
 * @param my_pb
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType pb_initialize(const push_button_t *my_pb) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == my_pb) {
        RET_VAL = E_NOK;
    } else {
        RET_VAL = gpio_pin_direction_initialize(&(my_pb->my_pb));

        RET_VAL = E_OK;
    }
    return RET_VAL;
}

/**
 * @brief read the logic at the pin connected to the push button 
 * @param my_pb 
 * @param my_pb_status
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType pb_read_status(const push_button_t *my_pb, pb_status_t *my_pb_status) {
    std_ReturnType RET_VAL = E_NOK;
    logic_t pb_logic_status = LOW;
    if ((NULL == my_pb) || (NULL == my_pb_status)) {
        RET_VAL = E_NOK;
    } else {
        RET_VAL = gpio_pin_read_logic(&(my_pb->my_pb), &pb_logic_status);
        if ((my_pb->my_pb_active_status) == PB_ACTIVE_HIGH) {
            if (HIGH == pb_logic_status) {
                *my_pb_status = PB_PRESSED;
            } else {
                *my_pb_status = PB_RELEASED;
            }
        } else if ((my_pb->my_pb_active_status) == PB_ACTIVE_LOW) {
            if (HIGH == pb_logic_status) {
                *my_pb_status = PB_RELEASED;
            } else {
                *my_pb_status = PB_PRESSED;
            }
        } else {
        }
        RET_VAL = E_OK;
    }
    return RET_VAL;
}
