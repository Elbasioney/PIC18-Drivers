/* 
 * File:   hal_timer1.c
 * Author: Ahmed Elbasioney
 *
 * Created on May 4, 2023, 3:46 PM
 */


#include "hal_timer1.h"

static inline void Timer1_mode_select(const timer1_config_t *timer1);

static uint16_t timer1_preloaded_value = 0 ; 

#if TIMER1_INTERRUPT_FEATURE_ENABLE  
static void (*TIMER1_INTERRUPT_HANDLER)(void) = NULL;
#endif

/**
 * @brief This routine initialize the Timer1 module
 * @param timer1
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType Timer1_Init(timer1_config_t *timer1){
    std_ReturnType RET_VAL = E_NOK ; 
    if(NULL ==timer1){
        RET_VAL = E_NOK ; 
    }else{
        TIMER1_FEATURE_DISABLE();
        TIMER1_SET_PRESCALER_VALUE(timer1->prescaler_value);
        Timer1_mode_select(timer1);
        TMR1H = ((timer1->preloaded_value) >> 8);            // set the high register to pre-loaded value
        TMR1L = (uint8_t)(timer1->preloaded_value);          // set the low register to pre-loaded value
        timer1_preloaded_value = timer1->preloaded_value ;   // pass the pre-loaded value
#if TIMER1_INTERRUPT_FEATURE_ENABLE 
        TIMER1_INTERRUPT_ENABLE();       // enable timer1 interrupt feature 
        TIMER1_INTERRUPT_CLEAR_FLAG();   // clear timer1 interrupt flag
        TIMER1_INTERRUPT_HANDLER = timer1->timer1_interrupt_handler ;   // pass the TIMER1 ISR 
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
        INTERRUPT_PRIORITY_ENABLE();    // enable interrupt priority levels feature
        if(INTERRUPT_HIGH_PRIORITY == timer1->priority){
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();  // enable all high priority interrupts
            TIMER1_INTERRUPT_SET_HIGH_PRIORITY();      // set timer 1 to be high priority interrupt
        }else if(INTERRUPT_LOW_PRIORITY == timer1->priority){
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();   // enable all low priority interrupts
            TIMER1_INTERRUPT_SET_LOW_PRIORITY();       // set timer 1 to be low priority interrupt
        }
#else
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PERIPHERALS_INTERRUPT_ENABLE();
#endif        

#endif
        TIMER1_FEATURE_ENABLE();
        RET_VAL = E_OK ;
    }
    return RET_VAL ;
}
/**
 * @brief This routine cancel the initialization of the Timer1 module
 * @param timer1
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType Timer1_DeInit(timer1_config_t *timer1){
    std_ReturnType RET_VAL = E_NOK ; 
    if(NULL ==timer1){
        RET_VAL = E_NOK ; 
    }else{
        TIMER1_FEATURE_DISABLE();
#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TIMER1_INTERRUPT_DISABLE();
#endif
        RET_VAL = E_OK ;
    }
    return RET_VAL ;
}

/**
 * @brief This routine reads the value stored in the TMR1L and TMR1H registers
 * @param 
 * @param value
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType Timer1_Read_Value(timer1_config_t *timer1 , uint16_t *value){
    std_ReturnType RET_VAL = E_NOK ;
    uint8_t temp_low  = 0 ;
    uint8_t temp_high = 0 ;
    if(( NULL ==timer1 ) || (NULL == value )){
        RET_VAL = E_NOK ; 
    }else{
        temp_low  = TMR1L ;
        temp_high = TMR1H ; 
        *value = (uint16_t)((temp_high << 8 ) + temp_low);
        RET_VAL = E_OK ;
    }
    return RET_VAL ;
}
/**
 * @brief This routine writes a value into the TMR1L and TMR1H registers
 * @param timer1
 * @param value
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType Timer1_Write_Value(timer1_config_t *timer1 , uint16_t value){
    std_ReturnType RET_VAL = E_NOK ; 
    if(NULL ==timer1){
        RET_VAL = E_NOK ; 
    }else{
        TMR1H = ((value) >> 8) ;
        TMR1L = (uint8_t)(value);
        RET_VAL = E_OK ;
    }
    return RET_VAL ;
}

/*                                 helper functions                           */

static inline void Timer1_mode_select(const timer1_config_t *timer1){
    if(timer1->timer1_mode == TIMER1_COUNTER_MODE){
        TIMER1_COUNTER_MODE_SET();
    }else if(timer1->timer1_mode == TIMER1_TIMER_MODE){
        TIMER1_TIMER_MODE_SET();
    }else{
        /*   no thing   */
    }
}

/*      timer1 interrupt handler function       */
void TIMER1_ISR(void) {
    TIMER1_INTERRUPT_CLEAR_FLAG();
    TMR1H = timer1_preloaded_value >> 8 ;
    TMR1L = (uint8_t)(timer1_preloaded_value) ;
    if(TIMER1_INTERRUPT_HANDLER){
        TIMER1_INTERRUPT_HANDLER();
    }else{
        /*     no thing      */
    }
}


