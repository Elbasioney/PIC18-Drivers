/* 
 * File:   hal_timer2.c
 * Author: Ahmed Elbasioney
 *
 * Created on May 5, 2023, 12:40 AM
 */

#include "hal_timer2.h"


#if TIMER2_INTERRUPT_FEATURE_ENABLE  
static void (*TIMER2_INTERRUPT_HANDLER)(void) = NULL;
#endif

static uint8_t timer2_preloaded_value = 0;

/**
 * @brief This routine cancel the initialization of the Timer2 module
 * @param timer2
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType Timer2_Init(timer2_config_t *timer2) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == timer2) {
        RET_VAL = E_NOK;
    } else {
        TIMER2_FEATURE_DISABLE();
        TIMER2_SET_PRESCALER_VALUE(timer2->prescaler_value);
        TIMER2_SET_POSTSCALER_VALUE(timer2->postscaler_value);
        TMR2 = timer2->preloaded_value;
        timer2_preloaded_value = TMR2;
#if TIMER2_INTERRUPT_FEATURE_ENABLE
        TIMER2_INTERRUPT_ENABLE();
        TIMER2_INTERRUPT_CLEAR_FLAG();
        TIMER2_INTERRUPT_HANDLER = timer2->timer2_interrupt_handler;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
        INTERRUPT_PRIORITY_ENABLE(); // enable interrupt priority levels feature
        if (INTERRUPT_HIGH_PRIORITY == timer2->priority) {
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE(); // enable all high priority interrupts
            TIMER2_INTERRUPT_SET_HIGH_PRIORITY(); // set timer 2 to be high priority interrupt
        } else if (INTERRUPT_LOW_PRIORITY == timer2->priority) {
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE(); // enable all low priority interrupts
            TIMER2_INTERRUPT_SET_LOW_PRIORITY(); // set timer 2 to be low priority interrupt
        }
#else
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PERIPHERALS_INTERRUPT_ENABLE();
#endif
#endif        
        TIMER2_FEATURE_ENABLE();
        RET_VAL = E_OK;
    }
    return RET_VAL;
}
/**
 * @brief This routine cancel the initialization of the Timer2 module
 * @param timer2
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType Timer2_DeInit(timer2_config_t *timer2) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == timer2) {
        RET_VAL = E_NOK;
    } else {
        TIMER2_FEATURE_DISABLE();
#if TIMER2_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER2_INTERRUPT_DISABLE();
#endif
        RET_VAL = E_OK;
    }
    return RET_VAL;
}
/**
 * @brief This routine reads the value stored in the TMR2 register
 * @param timer2
 * @param value
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType Timer2_Read_Value(timer2_config_t *timer2, uint8_t *value) {
    std_ReturnType RET_VAL = E_NOK;
    if ((NULL == timer2) || (NULL == value)) {
        RET_VAL = E_NOK;
    } else {
        *value = (uint8_t)TMR2 ;

        RET_VAL = E_OK;
    }
    return RET_VAL;
}
/**
 * @brief This routine writes a value into the TMR2 registers
 * @param timer2
 * @param value
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType Timer2_Write_Value(timer2_config_t *timer2, uint8_t value) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == timer2) {
        RET_VAL = E_NOK;
    } else {
        
        TMR2 = (uint8_t)value ;
        RET_VAL = E_OK;
    }
    return RET_VAL;
}

#if TIMER2_INTERRUPT_FEATURE_ENABLE  
void TIMER2_ISR(void) {
    TIMER1_INTERRUPT_CLEAR_FLAG();
    TMR2 = timer2_preloaded_value;
    if (TIMER2_INTERRUPT_HANDLER) {
        TIMER2_INTERRUPT_HANDLER();
    } else {
        /*   no thing   */
    }
}
#endif


