/* 
 * File:   hal_adc.c
 * Author: Ahmed Elbasioney
 *
 * Created on April 28, 2023, 4:14 PM
 */


#include "hal_adc.h"

#if ADC_INTERRUPT_FEATURE_ENABLE
static void (*ADC_INTERRUPT_HANDLER)(void) = NULL;
#endif



static inline void ADC_input_channel_port_configuration(adc_channel_select_t channel);
static inline void ADC_RESULT_FORMAT_configuration(adc_config_t *_adc);
static inline void ADC_VOLTAGE_REF_configuration(adc_config_t *_adc);

/**
 * @brief This routine initialize the ADC
 * @param _adc
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType ADC_Init(adc_config_t *_adc) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == _adc) {
        RET_VAL = E_NOK;
    } else {
        ADC_CONVERTER_DISABLE(); // disable ADC module
        /*                     if ADC interrupt is enabled           */
#if  ADC_INTERRUPT_FEATURE_ENABLE  == INTERRUPT_FEATURE_ENABLE 
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PERIPHERALS_INTERRUPT_ENABLE();
        ADC_INTERRUPT_ENABLE();
        ADC_INTERRUPT_CLEAR_FLAG();
#if  INTERRUPT_PRIORITY_LEVELS_ENABLE
        INTERRUPT_PRIORITY_ENABLE();
        if (INTERRUPT_HIGH_PRIORITY == _adc->priority) {
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
            ADC_INTERRUPT_SET_HIGH_PRIORITY();
        } else if (INTERRUPT_LOW_PRIORITY == _adc->priority) {
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
            ADC_INTERRUPT_SET_LOW_PRIORITY();
        } else {
            /*   no thing   */
        }
#else
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PERIPHERALS_INTERRUPT_ENABLE();
        ADC_INTERRUPT_ENABLE();
        ADC_INTERRUPT_CLEAR_FLAG();
#endif
        ADC_INTERRUPT_HANDLER = _adc->ADC_Interrupt_Handler;
#endif

        ADCON2bits.ACQT = _adc->acquisition_time; // setting Acquisition time 
        ADCON2bits.ADCS = _adc->conversion_clock; // setting conversion clock 
        ADC_RESULT_FORMAT_configuration(_adc); // setting result format ( Right or Left )
        ADCON0bits.CHS = _adc->adc_channel; // setting the default channel 
        ADC_input_channel_port_configuration(_adc->adc_channel); // configure the pin to be input
        ADC_VOLTAGE_REF_configuration(_adc); // setting the voltage reference ( external or internal )
        ADC_CONVERTER_ENABLE();
        RET_VAL = E_OK;
    }
    return RET_VAL;
}

/**
 * @brief This routine cancel the initialization of the ADC
 * @param _adc
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType ADC_DeInit(adc_config_t *_adc) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == _adc) {
        RET_VAL = E_NOK;
    } else {
        ADC_CONVERTER_DISABLE(); // disable ADC module 
        ADC_INTERRUPT_ENABLE(); // disable ADC interrupt feature 
        RET_VAL = E_OK;
    }
    return RET_VAL;

}

/**
 * @brief This routine is used to select the channel 
 * @param _adc
 * @param channel
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType ADC_select_channel(adc_config_t *_adc, adc_channel_select_t channel) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == _adc) {
        RET_VAL = E_NOK;
    } else {
        ADCON0bits.CHS = channel;
        ADC_input_channel_port_configuration(channel);
        RET_VAL = E_OK;
    }
    return RET_VAL;

}

/**
 * @brief This routine is used to start the conversion 
 * @param _adc
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType ADC_start_conversion(adc_config_t *_adc) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == _adc) {
        RET_VAL = E_NOK;
    } else {
        ADC_START_CONVERSION();
    }
    return RET_VAL;

}

/**
 * @brief This routine is used to check the conversion status if it is done or not yet
 * @param _adc
 * @param conversion_status     ( done converting or not yet )
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType ADC_check_conversion(adc_config_t *_adc, conversion_status_t *conversion_status) {
    std_ReturnType RET_VAL = E_NOK;
    if ((NULL == _adc) || (NULL == conversion_status)) {
        RET_VAL = E_NOK;
    } else {
        *conversion_status = (uint8_t) (!ADC_CONVERSION_STATUS()); // check if done converting or not
    }
    return RET_VAL;

}

/**
 * @brief This routine is used to get the result of the conversion
 * @param _adc
 * @param result
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType ADC_read_converion_result(adc_config_t *_adc, uint16_t *result) {
    std_ReturnType RET_VAL = E_NOK;
    if ((NULL == _adc) || (NULL == result)) {
        RET_VAL = E_NOK;
    } else {
        if ((_adc->result_format == ADC_RESULT_RIGHT)) {
            *result = (uint16_t) ((ADRESH << 8) + ADRESL);

        } else if ((_adc->result_format == ADC_RESULT_LEFT)) {
            *result = (uint16_t) (((ADRESH << 8) + ADRESL) >> 6);
        } else {
            *result = (uint16_t) ((ADRESH << 8) + ADRESL);
        }
        RET_VAL = E_OK;
    }
    return RET_VAL;

}

/**
 * @brief This routine is used to get the result of the ADC module on a channel by blocking method 
 * @param _adc
 * @param channel
 * @param result
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType ADC_GET_CONVERSION_BLOCKING(adc_config_t *_adc, adc_channel_select_t channel, uint16_t *result) {
    std_ReturnType RET_VAL = E_NOK;
    if ((NULL == _adc) || (NULL == result)) {
        RET_VAL = E_NOK;
    } else {
        RET_VAL = ADC_select_channel(_adc, channel); // select the channel
        RET_VAL = ADC_start_conversion(_adc); // start converting
        while (ADCON0bits.GODONE); // blocking mechanism 
        RET_VAL = ADC_read_converion_result(_adc, result);
    }
    return RET_VAL;

}

/**
 * @brief This routine is used to get the result of the ADC module on a channel by interrupt method 
 * @param _adc
 * @param channel
 * @param result
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType ADC_START_CONVERSION_INTERRUPT(adc_config_t *_adc, adc_channel_select_t channel) {
    std_ReturnType RET_VAL = E_NOK;
    if ((NULL == _adc)) {
        RET_VAL = E_NOK;
    } else {
        RET_VAL = ADC_select_channel(_adc, channel); // select the channel
        RET_VAL = ADC_start_conversion(_adc); // start converting
    }
    return RET_VAL;

}

/********************** helper functions *******************************/

static inline void ADC_input_channel_port_configuration(adc_channel_select_t channel) {
    std_ReturnType RET_VAL = E_NOK;
    switch (channel) {
        case ADC_CHANNEL_AN0: set_bit(TRISA, _TRISA_RA0_POSITION);
            break;
        case ADC_CHANNEL_AN1: set_bit(TRISA, _TRISA_RA1_POSITION);
            break;
        case ADC_CHANNEL_AN2: set_bit(TRISA, _TRISA_RA2_POSITION);
            break;
        case ADC_CHANNEL_AN3: set_bit(TRISA, _TRISA_RA3_POSITION);
            break;
        case ADC_CHANNEL_AN4: set_bit(TRISA, _TRISA_RA5_POSITION);
            break;
        case ADC_CHANNEL_AN5: set_bit(TRISE, _TRISE_RE0_POSITION);
            break;
        case ADC_CHANNEL_AN6: set_bit(TRISE, _TRISE_RE1_POSITION);
            break;
        case ADC_CHANNEL_AN7: set_bit(TRISE, _TRISE_RE2_POSITION);
            break;
        case ADC_CHANNEL_AN8: set_bit(TRISB, _TRISB_RB2_POSITION);
            break;
        case ADC_CHANNEL_AN9: set_bit(TRISB, _TRISB_RB3_POSITION);
            break;
        case ADC_CHANNEL_AN10: set_bit(TRISB, _TRISB_RB1_POSITION);
            break;
        case ADC_CHANNEL_AN11: set_bit(TRISB, _TRISB_RB4_POSITION);
            break;
        case ADC_CHANNEL_AN12: set_bit(TRISB, _TRISB_RB0_POSITION);
            break;
    }
}

static inline void ADC_RESULT_FORMAT_configuration(adc_config_t *_adc) {
    if ((_adc->result_format) == ADC_RESULT_RIGHT) {
        ADC_RIGHT_FORMAT();
    } else if ((_adc->result_format) == ADC_RESULT_LEFT) {
        ADC_LEFT_FORMAT();
    } else {
        ADC_RIGHT_FORMAT();
    }
}

static inline void ADC_VOLTAGE_REF_configuration(adc_config_t *_adc) {
    if ((_adc->voltage_refrence) == ADC_VOLTAGE_REFRENCE_ENABLE) {
        ADCON1bits.VCFG0 = 1;
        ADCON1bits.VCFG1 = 1;
    } else if ((_adc->result_format) == ADC_VOLTAGE_REFRENCE_DISABLE) {
        ADCON1bits.VCFG0 = 0;
        ADCON1bits.VCFG1 = 0;
    } else {
        ADCON1bits.VCFG0 = 0;
        ADCON1bits.VCFG1 = 0;
    }
}

void ADC_ISR(void) {
    ADC_INTERRUPT_CLEAR_FLAG();
    if (ADC_INTERRUPT_HANDLER) {
        ADC_INTERRUPT_HANDLER();
    } else {

    }
}















