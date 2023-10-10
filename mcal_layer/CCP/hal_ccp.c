/* 
 * File:   hal_ccp.c
 * Author: Ahmed Elbasioney
 *
 * Created on May 7, 2023, 9:22 PM
 */


#include "hal_ccp.h"

#if CCP1_INTERRUPT_FEATURE_ENABLE
void (* CCP1_interrupt_handler)(void) = NULL;
#endif

#if CCP2_INTERRUPT_FEATURE_ENABLE
void (* CCP2_interrupt_handler)(void) = NULL;
#endif


static inline void ccp_interrupt_config(ccp_config_t *ccp);
static inline void CCP_CAPTURE_MODE_TIMER_SELECT(ccp_config_t *ccp);

/**
 * @brief this function initialize the CCP module to work in ( Compare - Capture - PWM ) mode 
 * @param ccp
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType CCP_Init(const ccp_config_t *ccp) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == ccp) {
        RET_VAL = E_NOK;
    } else {
        if (ccp->ccp_inst == CCP1_INST) {
            CCP1_SET_MODE(CCP_MODULE_DISABLED);
        } else if (ccp->ccp_inst == CCP2_INST) {
            CCP2_SET_MODE(CCP_MODULE_DISABLED);
        } else {
            /*   no thing   */
        }
        if (CCP_CAPTURE_MODE_SELECTED == ccp->mode) {
            if(ccp->ccp_inst == CCP1_INST){
                switch (ccp->mode_variant) {
                case CCP_CAPTURE_MODE_1_RAISING_EDGE: CCP1_SET_MODE(CCP_CAPTURE_MODE_1_RAISING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_1_FALLING_EDGE: CCP1_SET_MODE(CCP_CAPTURE_MODE_1_FALLING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_4_RAISING_EDGE: CCP1_SET_MODE(CCP_CAPTURE_MODE_4_RAISING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_16_RAISING_EDGE: CCP1_SET_MODE(CCP_CAPTURE_MODE_16_RAISING_EDGE);
                    break;
                default: RET_VAL = E_NOK;
            }
            }else if(ccp->ccp_inst == CCP2_INST){
                switch (ccp->mode_variant) {
                case CCP_CAPTURE_MODE_1_RAISING_EDGE: CCP2_SET_MODE(CCP_CAPTURE_MODE_1_RAISING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_1_FALLING_EDGE: CCP2_SET_MODE(CCP_CAPTURE_MODE_1_FALLING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_4_RAISING_EDGE: CCP2_SET_MODE(CCP_CAPTURE_MODE_4_RAISING_EDGE);
                    break;
                case CCP_CAPTURE_MODE_16_RAISING_EDGE: CCP2_SET_MODE(CCP_CAPTURE_MODE_16_RAISING_EDGE);
                    break;
                default: RET_VAL = E_NOK;
            }
            }else{
                
            }
            
        } else if (CCP_COMPARE_MODE_SELECTED == ccp->mode) {
            if(ccp->ccp_inst == CCP1_INST){
                switch (ccp->mode_variant) {
                case CCP_COMPARE_MODE_GEN_EVENT: CCP1_SET_MODE(CCP_COMPARE_MODE_GEN_EVENT);
                    break;
                case CCP_COMPARE_MODE_GEN_SW_INTERRUPT: CCP1_SET_MODE(CCP_COMPARE_MODE_GEN_SW_INTERRUPT);
                    break;
                case CCP_COMPARE_MODE_TOGGLE_ON_MATCH: CCP1_SET_MODE(CCP_COMPARE_MODE_TOGGLE_ON_MATCH);
                    break;
                case CCP_COMPARE_MODE_SET_PIN_HIGH: CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);
                    break;
                case CCP_COMPARE_MODE_SET_PIN_LOW: CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);
                    break;
                default: RET_VAL = E_NOK;
            }
            }else if(ccp->ccp_inst == CCP2_INST){
                switch (ccp->mode_variant) {
                case CCP_COMPARE_MODE_GEN_EVENT: CCP2_SET_MODE(CCP_COMPARE_MODE_GEN_EVENT);
                    break;
                case CCP_COMPARE_MODE_GEN_SW_INTERRUPT: CCP2_SET_MODE(CCP_COMPARE_MODE_GEN_SW_INTERRUPT);
                    break;
                case CCP_COMPARE_MODE_TOGGLE_ON_MATCH: CCP2_SET_MODE(CCP_COMPARE_MODE_TOGGLE_ON_MATCH);
                    break;
                case CCP_COMPARE_MODE_SET_PIN_HIGH: CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);
                    break;
                case CCP_COMPARE_MODE_SET_PIN_LOW: CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);
                    break;
                default: RET_VAL = E_NOK;
            }
            }else{
            
            }
        } else if (CCP_PWM_MODE_SELECTED == ccp->mode) {
#if  ( CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED )  
            if (ccp->ccp_inst == CCP1_INST) {
                if (CCP_PWM_MODE == ccp->mode_variant) {
                    CCP1_SET_MODE(CCP_PWM_MODE);
                } else {
                    /*  no thing  */
                }
            } else if (ccp->ccp_inst == CCP2_INST) {
                if (CCP_PWM_MODE == ccp->mode_variant) {
                    CCP2_SET_MODE(CCP_PWM_MODE);
                } else {
                    /*  no thing  */
                }
            } else {
                /*   no thing   */
            }

            PR2 = ccp->PR2_VALUE;
#endif      
        } else {
            /*   no thing   */
        }

        RET_VAL = gpio_pin_init(&(ccp->pin));
        ccp_interrupt_config(ccp); // ccp interrupt configurations for ccp1 and ccp2
        CCP_CAPTURE_MODE_TIMER_SELECT(ccp); // CCP MODULES OPERTAING TIMER SELECT
    }
    return RET_VAL;
}

/**
 * @brief this function cancel the initialization of the CCP1 module 
 * @param duty_cycle
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType CCP_DeInit(const ccp_config_t *ccp) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == ccp) {
        RET_VAL = E_NOK;
    } else {
        if (ccp->ccp_inst == CCP1_INST) {
            CCP1_SET_MODE(CCP_MODULE_DISABLED);
#if CCP1_INTERRUPT_FEATURE_ENABLE 
            CCP1_INTERRUPT_DISABLE();
#endif        
        } else if (ccp->ccp_inst == CCP2_INST) {
            CCP2_SET_MODE(CCP_MODULE_DISABLED);
#if CCP2_INTERRUPT_FEATURE_ENABLE 
            CCP2_INTERRUPT_DISABLE();
#endif
        } else {
            /*   no thing  */
        }
        RET_VAL = E_OK;
    }
    return RET_VAL;
}


#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED || CCP2_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED)

std_ReturnType CCP_Is_Capture_Data_Ready(uint8_t *capture_status) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == capture_status) {
        RET_VAL = E_NOK;
    } else {
        if (CCP_CAPTURE_READY == PIR1bits.CCP1IF) {
            *capture_status = CCP_CAPTURE_READY;
            CCP1_INTERRUPT_CLEAR_FLAG();
        } else {
            *capture_status = CCP_CAPTURE_NOT_READY;
        }
        RET_VAL = E_OK;
    }
    return RET_VAL;
}

std_ReturnType CCP_Capture_Read_Value(uint16_t *capture_value) {
    std_ReturnType RET_VAL = E_NOK;
    uint8_t temp_high = 0;
    uint8_t temp_low = 0;
    if (NULL == capture_value) {
        RET_VAL = E_NOK;
    } else {
        temp_low = CCPR1L;
        temp_high = CCPR1H;
        *capture_value = (uint16_t) ((temp_high << 8) + ((uint8_t) (temp_low)));
        RET_VAL = E_OK;
    }
    return RET_VAL;
}

#endif

#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED || CCP2_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED)

std_ReturnType CCP1_Is_Compare_complete(uint8_t *Compare_status) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == Compare_status) {
        RET_VAL = E_NOK;
    } else {
        if (CCP_CAPTURE_READY == PIR1bits.CCP1IF) {
            *Compare_status = CCP_COMPARE_READY;
            CCP1_INTERRUPT_CLEAR_FLAG();
        } else {
            *Compare_status = CCP_COMPARE_NOT_READY;
        }
        RET_VAL = E_OK;
    }
    return RET_VAL;
}

std_ReturnType CCP_Compare_set_Value(const ccp_config_t *ccp, uint16_t Compare_value) {
    std_ReturnType RET_VAL = E_NOK;
    if(NULL == ccp){
        RET_VAL = E_NOK;
    }else{
        if(ccp->ccp_inst == CCP1_INST){
    CCPR1L = (uint8_t)(Compare_value);
    CCPR1H = (uint8_t)(Compare_value >> 8);
    RET_VAL = E_OK;
    }else if(ccp->ccp_inst == CCP2_INST){
    CCPR2L = (uint8_t)(Compare_value);
    CCPR2H = (uint8_t)(Compare_value >> 8);
    RET_VAL = E_OK;
    }else{
        RET_VAL = E_NOK;
    }
    }
    RET_VAL = E_OK;
    return RET_VAL;
}

#endif

#if (CCP_CFG_SELECTED_MODE == CCP1_CFG_PWM_MODE_SELECTED || CCP_CFG_SELECTED_MODE == CCP2_CFG_PWM_MODE_SELECTED)

std_ReturnType CCP_PWM_set_duty_cycle(const ccp_config_t *ccp, const uint8_t duty_cycle) {
    std_ReturnType RET_VAL = E_NOK;
    uint16_t duty_temp = 0;
    if (NULL == ccp) {

    } else {
        duty_temp = (uint16_t) ((4 * (PR2 + 1)) * (duty_cycle / 100.0));
        if (ccp->ccp_inst == CCP1_INST) {
            CCP1CONbits.DC1B = ((uint8_t) (duty_temp & 0x0003));
            CCPR1L = ((uint8_t) (duty_temp >> 2));
            RET_VAL = E_OK;
        } else if (ccp->ccp_inst == CCP2_INST) {
            CCP2CONbits.DC2B = ((uint8_t) (duty_temp & 0x0003));
            CCPR2L = ((uint8_t) (duty_temp >> 2));
            RET_VAL = E_OK;
        } else {
            RET_VAL = E_NOK;
        }
    }
    return RET_VAL;
}

std_ReturnType CCP_PWM_start(const ccp_config_t *ccp) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == ccp) {
        RET_VAL = E_NOK;
    } else {
        if (ccp->ccp_inst == CCP1_INST) {
            CCP1CONbits.CCP1M = CCP_PWM_MODE;
        } else if (ccp->ccp_inst == CCP2_INST) {
            CCP2CONbits.CCP2M = CCP_PWM_MODE;
        } else {
            /*   no thing   */
        }
        RET_VAL = E_OK;
    }

    return RET_VAL;
}

std_ReturnType CCP_PWM_stopconst(ccp_config_t *ccp) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == ccp) {
        RET_VAL = E_NOK;
    } else {
        if (ccp->ccp_inst == CCP1_INST) {
            CCP1CONbits.CCP1M = CCP_MODULE_DISABLED;
        } else if (ccp->ccp_inst == CCP2_INST) {
            CCP2CONbits.CCP2M = CCP_MODULE_DISABLED;
        } else {
            /*   no thing   */
        }
        RET_VAL = E_OK;
    }

    return RET_VAL;
}


#endif

void CCP1_ISR(void) {
    CCP1_INTERRUPT_CLEAR_FLAG();
    if (CCP1_interrupt_handler) {
        CCP1_interrupt_handler();
    } else {
        /*  no thing  */
    }

}

void CCP2_ISR(void) {
    CCP2_INTERRUPT_CLEAR_FLAG();
    if (CCP2_interrupt_handler) {
        CCP2_interrupt_handler();
    } else {
        /*  no thing  */
    }
}

static inline void ccp_interrupt_config(ccp_config_t *ccp) {
    if (ccp->ccp_inst == CCP1_INST) {
#if   CCP1_INTERRUPT_FEATURE_ENABLE
        CCP1_INTERRUPT_ENABLE();
        CCP1_INTERRUPT_CLEAR_FLAG();
        CCP1_interrupt_handler = ccp->CCP_INTERRUPT_HANDLER;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
        INTERRUPT_PRIORITY_ENABLE();
        if (ccp->priority == INTERRUPT_HIGH_PRIORITY) {
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
            CCP1_INTERRUPT_SET_HIGH_PRIORITY();
        } else if (ccp->priority == INTERRUPT_LOW_PRIORITY) {
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
            CCP1_INTERRUPT_SET_LOW_PRIORITY();
        } else {

        }
#else
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PERIPHERALS_INTERRUPT_ENABLE();
#endif

#endif

    } else if (ccp->ccp_inst == CCP1_INST) {
#if   CCP2_INTERRUPT_FEATURE_ENABLE
        CCP2_INTERRUPT_ENABLE();
        CCP2_INTERRUPT_CLEAR_FLAG();
        CCP2_interrupt_handler = ccp->CCP_INTERRUPT_HANDLER;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
        INTERRUPT_PRIORITY_ENABLE();
        if (ccp->priority == INTERRUPT_HIGH_PRIORITY) {
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
            CCP2_INTERRUPT_SET_HIGH_PRIORITY();
        } else if (ccp->priority == INTERRUPT_LOW_PRIORITY) {
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
            CCP2_INTERRUPT_SET_LOW_PRIORITY();
        } else {

        }
#else
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PERIPHERALS_INTERRUPT_ENABLE();
#endif

#endif            
    } else {

    }
}

static inline void CCP_CAPTURE_MODE_TIMER_SELECT(ccp_config_t *ccp) {
        if (ccp->ccp_capture == CCP1_CCP2_TIMER3) {
            T3CONbits.T3CCP1 = 0;
            T3CONbits.T3CCP2 = 1;
        } else if (ccp->ccp_capture == CCP1_CCP2_TIMER1) {
            T3CONbits.T3CCP1 = 0;
            T3CONbits.T3CCP2 = 0;
        } else if (ccp->ccp_capture == CCP1_TIMER1_CCP2_TIMER3) {
            T3CONbits.T3CCP1 = 1;
            T3CONbits.T3CCP2 = 0;
        } else {
            /*   no thing   */
        }
}