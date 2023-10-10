/* 
 * File:   hal_timer3.c
 * Author: Ahmed Elbasioney
 *
 * Created on May 5, 2023, 4:43 PM
 */

#include "hal_timer3.h"

#if TIMER3_INTERRUPT_FEATURE_ENABLE
    static void (* timer3_interrupt_handler)(void) = NULL ;
#endif

    static uint16_t timer3_preloaded_value = 0 ;
    static inline void timer3_mode_select(const timer3_config_t *timer3);
    static inline void timer3_resolution_select(const timer3_config_t *timer3);
    static inline void timer3_Synchronization_select(const timer3_config_t *timer3);

    
    
/**
 * 
 * @param timer3
 * @return 
 */
std_ReturnType Timer3_Init(const timer3_config_t *timer3) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == timer3) {
        RET_VAL = E_NOK;
    } else {
        TIMER3_FEATURE_DISABLE();
        timer3_mode_select(timer3);        // select mode ( counter or timer ) 
        TIMER3_SET_PRESCALER_VALUE(timer3->prescaler_value);   // set chosen pre-scaler value 
        timer3_resolution_select(timer3);      // select the R/W register size ( 16 or 8 ) bits
        timer3_Synchronization_select(timer3);       // set timer3 Synchronization with timer1 oscillator to be on or off 
        TMR3H = ((timer3->preloaded_value) >> 8) ;
        TMR3L = (uint8_t)(timer3->preloaded_value);
        timer3_preloaded_value = timer3->preloaded_value ;
#if TIMER3_INTERRUPT_FEATURE_ENABLE
        TIMER3_INTERRUPT_ENABLE();
        TIMER3_INTERRUPT_CLEAR_FLAG();
        timer3_interrupt_handler = timer3->timer3_interrupt_handler ;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
    INTERRUPT_PRIORITY_ENABLE();
    if(timer3->priority == INTERRUPT_HIGH_PRIORITY){
        INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
        TIMER3_INTERRUPT_SET_HIGH_PRIORITY();
    }else if(timer3->priority == INTERRUPT_LOW_PRIORITY){
        INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
        TIMER3_INTERRUPT_SET_LOW_PRIORITY();
    }else{
        
    }
#else
    INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
    INTERRUPT_PERIPHERALS_INTERRUPT_ENABLE();
#endif
        
#endif
        TIMER3_FEATURE_ENABLE();
        RET_VAL = E_OK;
    }
    return RET_VAL;
}

std_ReturnType Timer3_DeInit(const timer3_config_t *timer3) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == timer3) {
        RET_VAL = E_NOK;
    } else {
        TIMER3_FEATURE_DISABLE();
#if TIMER3_INTERRUPT_FEATURE_ENABLE
        TIMER3_INTERRUPT_ENABLE();
#endif
        RET_VAL = E_OK;
    }
    return RET_VAL;
}

std_ReturnType Timer3_Read_Value(const timer3_config_t *timer3, uint16_t *value) {
    std_ReturnType RET_VAL = E_NOK;
    uint8_t temp_high = 0 ;
    uint8_t temp_low  = 0 ;
    if ((NULL == timer3) || (NULL == value)) {
        RET_VAL = E_NOK;
    } else {
        temp_high = TMR3H ;
        temp_low = TMR3L ;
        *value = (uint16_t)((temp_high << 8 ) + temp_low) ;
        RET_VAL = E_OK;
    }
    return RET_VAL;
}

std_ReturnType Timer3_Write_Value(const timer3_config_t *timer3, uint16_t value) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == timer3) {
        RET_VAL = E_NOK;
    } else {
        TMR3H = value >> 8 ;
        TMR3L = (uint8_t)value ;
        RET_VAL = E_OK;
    }
    return RET_VAL;
}


/*                                 helper   functions                          */

static inline void timer3_mode_select(const timer3_config_t *timer3){
    if(timer3->mode == TIMER3_COUNTER_MODE ){
        TIMER3_COUNTER_MODE_SET();
    }else if(timer3->mode == TIMER3_TIMER_MODE){
        TIMER3_TIMER_MODE_SET();
    }else{
        /*   no thing   */
    }
}

static inline void timer3_resolution_select(const timer3_config_t *timer3){
    if( timer3->resolution == TIMER3_16_BIT_MODE ){
        TIMER3_16_BIT_MODE_SET();
    }else if(timer3->resolution == TIMER3_8_BIT_MODE){
        TIMER3_8_BIT_MODE_SET();
    }else{
        /*   no thing   */
    }
}

static inline void timer3_Synchronization_select(const timer3_config_t *timer3){
    if(TIMER3_Synchronization_ENABLED == timer3->Synchronization){
        TIMER3_Synchronization_ENABLE_SET();
    }else if(TIMER3_Synchronization_DISABLED == timer3->Synchronization){
        TIMER3_Synchronization_DISABLE_SET();
    }else{
        /*   no thing    */
    }
    
}


void TIMER3_ISR(void){
    TIMER3_INTERRUPT_CLEAR_FLAG();
    TMR3H = timer3_preloaded_value >> 8 ;
    TMR3L = (uint8_t)(timer3_preloaded_value);
    if(timer3_interrupt_handler){
        timer3_interrupt_handler();
    }else{
        /*   no thing   */
    }
}
