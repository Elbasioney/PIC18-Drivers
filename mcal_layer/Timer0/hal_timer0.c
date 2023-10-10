/* 
 * File:   hal_timer0.c
 * Author: Ahmed Elbasioney
 *
 * Created on April 30, 2023, 10:30 PM
 */


#include "hal_timer0.h"

/*                             helper function declarations                  */
static inline void Timer0_prescaler_config(const timer0_config_t *timer0) ;
static inline void Timer0_mode_select(const timer0_config_t *timer0) ;
static inline void Timer0_resolution_select(const timer0_config_t *timer0);
static uint16_t timer0_preloaded_value = 0 ;

#if TIMER0_INTERRUPT_FEATURE_ENABLE  
static void (*TIMER0_INTERRUPT_HANDLER)(void) = NULL;
#endif


/**
 * @brief This routine initialize the Timer0 module 
 * @param timer0
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType Timer0_Init(const timer0_config_t *timer0) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == timer0) {
        RET_VAL = E_NOK;
    } else {
        TIMER0_FEATURE_DISABLE();
    /*       set PRESCALER module to be on or off and set its value       */
        Timer0_prescaler_config(timer0); 
    /*     set the timer0 module mode and edge if selected as counter     */    
        Timer0_mode_select(timer0);
    /*         set the timer0 module resolution 16-bit or 8-bit           */   
        Timer0_resolution_select(timer0);
                       // initialize the pre-loaded value  
        timer0_preloaded_value = timer0->preloaded_value ;       // save the pre-loaded value to a variable and pass it to the TIMER0_ISR function 
#if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER0_INTERRUPT_ENABLE();
        TIMER0_INTERRUPT_CLEAR_FLAG();
        TIMER0_INTERRUPT_HANDLER = timer0->TIMER0_INTERRUPT_HANDLER ;
        TMR0H = ((timer0->preloaded_value)>>8);
        TMR0L = (uint8_t)(timer0->preloaded_value);
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
        INTERRUPT_PRIORITY_ENABLE();
        if( timer0->priority == INTERRUPT_HIGH_PRIORITY){
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
            TIMER0_INTERRUPT_SET_HIGH_PRIORITY(); 
        }else if( timer0->priority == INTERRUPT_LOW_PRIORITY){
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
            TIMER0_INTERRUPT_SET_LOW_PRIORITY();
        }else{
            /*  no thing   */
        }
#else 
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PERIPHERALS_INTERRUPT_ENABLE();
        TIMER0_INTERRUPT_ENABLE();
        TIMER0_INTERRUPT_CLEAR_FLAG();
#endif
#endif   
        
        TIMER0_FEATURE_ENABLE();
    }
    return RET_VAL;
}

/**
 * @brief This routine cancel the initialization of the Timer0 module 
 * @param timer0
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType Timer0_DeInit(const timer0_config_t *timer0) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == timer0) {
        RET_VAL = E_NOK;
    } else {
        TIMER0_FEATURE_DISABLE();
#if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER0_INTERRUPT_DISABLE();
#endif
    }
    return RET_VAL;
}

/**
 * @brief This routine reads the value stored in the TMR0L and TMR0H registers
 * @param timer0
 * @param value
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType Timer0_Read_Value(const timer0_config_t *timer0, uint16_t *value) {
    std_ReturnType RET_VAL = E_NOK;
    uint8_t Temp_TRM0L = 0 ;
    uint8_t Temp_TRM0H = 0 ;
    if ((NULL == timer0) || (NULL == value)) {
        RET_VAL = E_NOK;
    } else {
        Temp_TRM0L = TMR0L ;
        Temp_TRM0H = TMR0H ;
        *value = (uint16_t)((Temp_TRM0H << 8) + Temp_TRM0L) ;
    }
    return RET_VAL;
}

/**
 * @brief This routine writes a value into the TMR0L and TMR0H registers
 * @param timer0
 * @param value
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType Timer0_Write_Value(const timer0_config_t *timer0, uint16_t value) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == timer0) {
        RET_VAL = E_NOK;
    } else {
        TMR0H = ((value)>>8);
        TMR0L = (uint8_t)(value);
    }
    return RET_VAL;
}

 
/*      timer0 interrupt handler function       */
void TIMER0_ISR(void) {
    TIMER0_INTERRUPT_CLEAR_FLAG();
    TMR0H = (timer0_preloaded_value >> 8) ;
    TMR0L = (uint8_t)(timer0_preloaded_value) ;
    if (TIMER0_INTERRUPT_HANDLER) {
        TIMER0_INTERRUPT_HANDLER();
    } else {

    }
}
/*                             helper function definitions                  */

static inline void Timer0_prescaler_config(const timer0_config_t *timer0){
    if(timer0->prescaler_status == TIMER0_PRESCALER_ENABLE_CFG){
        TIMER0_ENABLE_PRESCALER();
        T0CONbits.T0PS = timer0->prescaler_value ;
    }else if(timer0->prescaler_status == TIMER0_PRESCALER_DISABLE_CFG){
        TIMER0_DISABLE_PRESCALER();
    }else{
        /*   no thing   */
    } 
}

static inline void Timer0_mode_select(const timer0_config_t *timer0){
    if(timer0->mode == TIMER0_TIMER_MODE_ENABLE_CFG){
        TIMER0_TIMER_MODE_SET();
    }else if(timer0->mode == TIMER0_COUNTER_MODE_ENABLE_CFG){
        TIMER0_COUNTER_MODE_SET();
        if(timer0->edge == TIMER0_RAISING_EDGE_ENABLE_CFG){
            TIMER0_RAISING_EDGE_SET();
        }else if(timer0->edge == TIMER0_FALLING_EDGE_ENABLE_CFG){
            TIMER0_FALLING_EDGE_SET();
        }else{
            TIMER0_RAISING_EDGE_SET();
        }
    }else{
        /*   no thing   */
    }
}

static inline void Timer0_resolution_select(const timer0_config_t *timer0){
    if(timer0->resolution == TIMER0_16BIT_MODE_ENABLE_CFG){
        TIMER0_16BIT_SET();
    }else if(timer0->resolution == TIMER0_8BIT_MODE_ENABLE_CFG){
        TIMER0_8BIT_SET();
    }else{
        /*   no thing   */
    }
}