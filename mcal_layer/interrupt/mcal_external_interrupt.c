/* 
 * File:   mcal_external_interrupt.c
 * Author: Ahmed Elbasioney
 *
 * Created on April 19, 2023, 4:18 AM
 */

#include "mcal_external_interrupt.h"

/*                                        helper functions declarations                                */

static void (* INT0_interrupt_handler)(void) = NULL;
static void (* INT1_interrupt_handler)(void) = NULL;
static void (* INT2_interrupt_handler)(void) = NULL;

static void (* RB4_interrupt_handler)(void) = NULL;
static void (* RB5_interrupt_handler)(void) = NULL;
static void (* RB6_interrupt_handler)(void) = NULL;
static void (* RB7_interrupt_handler)(void) = NULL;

static std_ReturnType interrupt_INTx_enable(const interrupt_INTx_t *interrupt_object);
static std_ReturnType interrupt_INTx_disable(const interrupt_INTx_t *interrupt_object);
static std_ReturnType interrupt_INTx_priority_init(const interrupt_INTx_t *interrupt_object);
static std_ReturnType interrupt_INTx_edge_init(const interrupt_INTx_t *interrupt_object);
static std_ReturnType interrupt_INTx_pin_init(const interrupt_INTx_t *interrupt_object);
static std_ReturnType interrupt_INTx_clear_flag(const interrupt_INTx_t *interrupt_object);

static std_ReturnType INT0_set_interrupt_handler(void (*interrupt_handler)(void));
static std_ReturnType INT1_set_interrupt_handler(void (*interrupt_handler)(void));
static std_ReturnType INT2_set_interrupt_handler(void (*interrupt_handler)(void));


static std_ReturnType interrupt_INTx_set_interrupt_handler(const interrupt_INTx_t *interrupt_object);

static std_ReturnType interrupt_RBx_enable(const interrupt_RBx_t *interrupt_object);
static std_ReturnType interrupt_RBx_disable(const interrupt_RBx_t *interrupt_object);
static std_ReturnType interrupt_RBx_priority_init(const interrupt_RBx_t *interrupt_object);
static std_ReturnType interrupt_RBx_pin_init(const interrupt_RBx_t *interrupt_object);

void INT0_ISR(void) {
    CLEAR_INT0_INTERRUPT_FLAG();
    if (INT0_interrupt_handler) {
        INT0_interrupt_handler();
    } else {
    }
}

void INT1_ISR(void) {
    CLEAR_INT1_INTERRUPT_FLAG();
    if (INT1_interrupt_handler) {
        INT1_interrupt_handler();
    } else {
    }
}

void INT2_ISR(void) {
    CLEAR_INT2_INTERRUPT_FLAG();
    if (INT2_interrupt_handler) {
        INT2_interrupt_handler();
    } else {
    }
}

void RB4_ISR(void) {
    CLEAR_EXTERNAL_INTERRUPT_onchange_FLAG();

    if (RB4_interrupt_handler) {
        RB4_interrupt_handler();
    } else {
    }
}

void RB5_ISR(void) {
    CLEAR_EXTERNAL_INTERRUPT_onchange_FLAG();
    if (RB5_interrupt_handler) {
        RB5_interrupt_handler();
    } else {
    }
}

void RB6_ISR(void) {
    CLEAR_EXTERNAL_INTERRUPT_onchange_FLAG();
    if (RB6_interrupt_handler) {
        RB6_interrupt_handler();
    } else {
    }
}

void RB7_ISR(void) {
    CLEAR_EXTERNAL_INTERRUPT_onchange_FLAG();
    if (RB7_interrupt_handler) {
        RB7_interrupt_handler();
    } else {
    }
}


/*                                                                                         */

/**
 * @brief initialize the INTx pin 
 * @param interrupt_object
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType interrupt_INTx_init(const interrupt_INTx_t *interrupt_object) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == interrupt_object) {
        RET_VAL = E_NOK;
    } else {
        RET_VAL = interrupt_INTx_disable(interrupt_object); // disable interrupt  
        RET_VAL = interrupt_INTx_clear_flag(interrupt_object); // clear flag bit 
        RET_VAL = interrupt_INTx_edge_init(interrupt_object); // selecting rising or falling edge 
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
        RET_VAL = interrupt_INTx_priority_init(interrupt_object); // select high or low priority  
#endif        
        RET_VAL = interrupt_INTx_pin_init(interrupt_object); // select the interrupt pin 
        RET_VAL = interrupt_INTx_set_interrupt_handler(interrupt_object); // call back function 
        RET_VAL = interrupt_INTx_enable(interrupt_object); // enable interrupt 
    }
    return RET_VAL;
}

/**
 * @brief cancel the initialization of the INTx pin 
 * @param interrupt_object
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType interrupt_INTx_deinit(const interrupt_INTx_t *interrupt_object) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == interrupt_object) {
        RET_VAL = E_NOK;
    } else {
        RET_VAL = interrupt_INTx_disable(interrupt_object);
    }
    return RET_VAL;
}

/**
 * @brief initialize the RBx pin 
 * @param interrupt_object
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType interrupt_RBx_init(const interrupt_RBx_t *interrupt_object) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == interrupt_object) {
        RET_VAL = E_NOK;
    } else {
        EXT_RBx_INTERRUPT_DISABLE(); // disable on-change interrupts
        CLEAR_EXTERNAL_INTERRUPT_onchange_FLAG(); //  clear on-change interrupts flag

#if     INTERRUPT_PRIORITY_LEVELS_ENABLE
        INTERRUPT_PRIORITY_ENABLE();
        if (interrupt_object->priority == INTERRUPT_LOW_PRIORITY) {
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE(); // enable all low priority interrupts 
            EXT_RBx_PRIORITY_LOW(); // set the RBx interrupt priority to low
        } else if (interrupt_object->priority == INTERRUPT_HIGH_PRIORITY) {
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE(); // enable all high priority interrupts
            EXT_RBx_PRIORITY_HIGH(); // set the RBx interrupt priority to high 
        } else {
            /*   no thing       */
        }
#else
        INTERRUPT_PERIPHERALS_INTERRUPT_ENABLE();
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
#endif
        RET_VAL = gpio_pin_direction_initialize(&(interrupt_object->mcu_pin)); // initialize the RBx pin to be input
        /************** initialize the call back function ******************/
        switch (interrupt_object->mcu_pin.pin) {
            case PIN4:
                RB4_interrupt_handler = interrupt_object->external_interrupt_handler;
                break;
            case PIN5:
                RB5_interrupt_handler = interrupt_object->external_interrupt_handler;
                break;
            case PIN6:
                RB6_interrupt_handler = interrupt_object->external_interrupt_handler;
                break;
            case PIN7:
                RB7_interrupt_handler = interrupt_object->external_interrupt_handler;
                break;
            default: RET_VAL = E_NOK;
        }
        EXT_RBx_INTERRUPT_ENABLE(); // enable on-change interrupts
    }
    return RET_VAL;
}

/**
 * @brief cancel the initialization of the RBx pin
 * @param interrupt_object
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType interrupt_RBx_deinit(const interrupt_RBx_t *interrupt_object) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == interrupt_object) {
        RET_VAL = E_NOK;
    } else {
        EXT_RBx_INTERRUPT_DISABLE();
    }
    return RET_VAL;
}

/*                                        helper functions definitions                                 */

static std_ReturnType interrupt_INTx_enable(const interrupt_INTx_t *interrupt_object) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == interrupt_object) {
        RET_VAL = E_NOK;
    } else {
        switch (interrupt_object->source) {
            case INTERRUPT_EXTERNAL_INT0:
#if     INTERRUPT_PRIORITY_LEVELS_ENABLE
                INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
#else
                INTERRUPT_PERIPHERALS_INTERRUPT_ENABLE();
                INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
#endif

                EXT_INT0_INTERRUPT_ENABLE();
                RET_VAL = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1:
#if     INTERRUPT_PRIORITY_LEVELS_ENABLE
                INTERRUPT_PRIORITY_ENABLE();
                if (interrupt_object->priority == INTERRUPT_LOW_PRIORITY) {
                    INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
                } else if (interrupt_object->priority == INTERRUPT_HIGH_PRIORITY) {
                    INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
                } else {
                    /*   no thing       */
                }
#else
                INTERRUPT_PERIPHERALS_INTERRUPT_ENABLE();
                INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
#endif

                EXT_INT1_INTERRUPT_ENABLE();
                RET_VAL = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT2:
#if     INTERRUPT_PRIORITY_LEVELS_ENABLE
                INTERRUPT_PRIORITY_ENABLE();
                if (interrupt_object->priority == INTERRUPT_LOW_PRIORITY) {
                    INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
                } else if (interrupt_object->priority == INTERRUPT_HIGH_PRIORITY) {
                    INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
                } else {
                    /*   no thing       */
                }
#else
                INTERRUPT_PERIPHERALS_INTERRUPT_ENABLE();
                INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
#endif

                EXT_INT2_INTERRUPT_ENABLE();
                RET_VAL = E_OK;
                break;
            default: RET_VAL = E_NOK;
        }
    }
    return RET_VAL;
}

static std_ReturnType interrupt_INTx_disable(const interrupt_INTx_t *interrupt_object) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == interrupt_object) {
        RET_VAL = E_NOK;
    } else {
        switch (interrupt_object->source) {
            case INTERRUPT_EXTERNAL_INT0:
                EXT_INT0_INTERRUPT_DISABLE();
                RET_VAL = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1:
                EXT_INT1_INTERRUPT_DISABLE();
                RET_VAL = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT2:
                EXT_INT2_INTERRUPT_DISABLE();
                RET_VAL = E_OK;
                break;
            default: RET_VAL = E_NOK;
        }
    }
    return RET_VAL;
}


#if INTERRUPT_PRIORITY_LEVELS_ENABLE

static std_ReturnType interrupt_INTx_priority_init(const interrupt_INTx_t *interrupt_object) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == interrupt_object) {
        RET_VAL = E_NOK;
    } else {
        switch (interrupt_object->source) {
            case INTERRUPT_EXTERNAL_INT1:
                if (interrupt_object->priority == INTERRUPT_LOW_PRIORITY) {
                    EXT_INT1_INTERRUPT_LOW_PRIORITY();
                } else if (interrupt_object->priority == INTERRUPT_HIGH_PRIORITY) {
                    EXT_INT1_INTERRUPT_HIGH_PRIORITY();
                } else {
                    /*   no thing       */
                }
                break;
            case INTERRUPT_EXTERNAL_INT2:
                if (interrupt_object->priority == INTERRUPT_LOW_PRIORITY) {
                    EXT_INT2_INTERRUPT_LOW_PRIORITY();
                } else if (interrupt_object->priority == INTERRUPT_HIGH_PRIORITY) {
                    EXT_INT2_INTERRUPT_HIGH_PRIORITY();
                } else {
                    /*   no thing       */
                }
                break;
            default: RET_VAL = E_NOK;
        }
    }
    return RET_VAL;
}
#endif

static std_ReturnType interrupt_INTx_edge_init(const interrupt_INTx_t *interrupt_object) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == interrupt_object) {
        RET_VAL = E_NOK;
    } else {
        switch (interrupt_object->source) {
            case INTERRUPT_EXTERNAL_INT0:
                if (interrupt_object->edge == INTERRUPT_FALLING_EDGE) {
                    EXT_INT0_FALLING_EDGE_SET();
                } else if (interrupt_object->edge == INTERRUPT_RISING_EDGE) {
                    EXT_INT0_RISING_EDGE_SET();
                } else {
                    /*   no thing       */
                }
                break;
            case INTERRUPT_EXTERNAL_INT1:
                if (interrupt_object->edge == INTERRUPT_FALLING_EDGE) {
                    EXT_INT1_FALLING_EDGE_SET();
                } else if (interrupt_object->edge == INTERRUPT_RISING_EDGE) {
                    EXT_INT1_RISING_EDGE_SET();
                } else {
                    /*   no thing       */
                }
                break;
            case INTERRUPT_EXTERNAL_INT2:
                if (interrupt_object->edge == INTERRUPT_FALLING_EDGE) {
                    EXT_INT2_FALLING_EDGE_SET();
                } else if (interrupt_object->edge == INTERRUPT_RISING_EDGE) {
                    EXT_INT2_RISING_EDGE_SET();
                } else {
                    /*   no thing       */
                }
                break;
            default: RET_VAL = E_NOK;
        }
    }
    return RET_VAL;
}

static std_ReturnType interrupt_INTx_pin_init(const interrupt_INTx_t *interrupt_object) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == interrupt_object) {
        RET_VAL = E_NOK;
    } else {
        RET_VAL = gpio_pin_direction_initialize(&(interrupt_object->mcu_pin));
    }
    return RET_VAL;
}

static std_ReturnType interrupt_INTx_clear_flag(const interrupt_INTx_t *interrupt_object) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == interrupt_object) {
        RET_VAL = E_NOK;
    } else {
        switch (interrupt_object->source) {
            case INTERRUPT_EXTERNAL_INT0:
                CLEAR_INT0_INTERRUPT_FLAG();
                RET_VAL = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1:
                CLEAR_INT1_INTERRUPT_FLAG();
                RET_VAL = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT2:
                CLEAR_INT2_INTERRUPT_FLAG();
                RET_VAL = E_OK;
                break;
            default: RET_VAL = E_NOK;
        }
    }
    return RET_VAL;
}

static std_ReturnType INT0_set_interrupt_handler(void (*interrupt_handler)(void)) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == interrupt_handler) {
        RET_VAL = E_NOK;
    } else {
        INT0_interrupt_handler = interrupt_handler;
        RET_VAL = E_OK;
    }
    return RET_VAL;
}

static std_ReturnType INT1_set_interrupt_handler(void (*interrupt_handler)(void)) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == interrupt_handler) {
        RET_VAL = E_NOK;
    } else {
        INT1_interrupt_handler = interrupt_handler;
        RET_VAL = E_OK;
    }
    return RET_VAL;
}

static std_ReturnType INT2_set_interrupt_handler(void (*interrupt_handler)(void)) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == interrupt_handler) {
        RET_VAL = E_NOK;
    } else {
        INT2_interrupt_handler = interrupt_handler;
        RET_VAL = E_OK;
    }
    return RET_VAL;
}

static std_ReturnType interrupt_INTx_set_interrupt_handler(const interrupt_INTx_t *interrupt_object) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == interrupt_object) {
        RET_VAL = E_NOK;
    } else {
        switch (interrupt_object->source) {
            case INTERRUPT_EXTERNAL_INT0:
                RET_VAL = INT0_set_interrupt_handler(interrupt_object ->external_interrupt_handler);
                RET_VAL = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1:
                RET_VAL = INT1_set_interrupt_handler(interrupt_object ->external_interrupt_handler);
                RET_VAL = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT2:
                RET_VAL = INT2_set_interrupt_handler(interrupt_object ->external_interrupt_handler);
                RET_VAL = E_OK;
                break;
            default: RET_VAL = E_NOK;
        }
    }
    return RET_VAL;
}


/******************************************************************************************************************/


/************************************************************************/