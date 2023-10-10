/* 
 * File:   hal_adc.h
 * Author: Ahmed Elbasioney
 *
 * Created on April 28, 2023, 4:14 PM
 */

#ifndef HAL_ADC_H
#define	HAL_ADC_H

/*                      includes                             */

#include <xc.h>
#include "../GPIO/hal_gpio.h"
#include "../interrupt/mcal_internal_interrupt.h"
#include "../mcal_std_libararies.h"
#include "../mcal_std_types.h"
#include "hal_adc_cfg.h"



/*                       macros                              */

/**
 *@brief enable analog functionality up to the selected pin
 *@examble if ADC_AN3_ANALOG_FUNCTIONALITY is chosen then : 
 *         AN0 , AN1 , AN2 , AN3 are analog pins 
 */ // NOT supported in pic1846k20 
#define ADC_AN0_ANALOG_FUNCTIONALITY   0x0E
#define ADC_AN1_ANALOG_FUNCTIONALITY   0x0D
#define ADC_AN2_ANALOG_FUNCTIONALITY   0x0C
#define ADC_AN3_ANALOG_FUNCTIONALITY   0x0B
#define ADC_AN4_ANALOG_FUNCTIONALITY   0x0A
#define ADC_AN5_ANALOG_FUNCTIONALITY   0x09
#define ADC_AN6_ANALOG_FUNCTIONALITY   0x08
#define ADC_AN7_ANALOG_FUNCTIONALITY   0x07
#define ADC_AN8_ANALOG_FUNCTIONALITY   0x06
#define ADC_AN9_ANALOG_FUNCTIONALITY   0x05
#define ADC_AN10_ANALOG_FUNCTIONALITY  0x04
#define ADC_AN11_ANALOG_FUNCTIONALITY  0x03
#define ADC_AN12_ANALOG_FUNCTIONALITY  0x02
#define ADC_AN12_ANALOG_FUNCTIONALITY  0x02
#define ADC_ALL_ANALOG_FUNCTIONALITY   0x01
#define ADC_ALL_DIGITAL_FUNCTIONALITY  0x0F


#define ADC_RESULT_RIGHT       0x01U                                 
#define ADC_RESULT_LEFT        0x00U

#define ADC_VOLTAGE_REFRENCE_ENABLE      0x01U   
#define ADC_VOLTAGE_REFRENCE_DISABLE     0x00U

#define ADC_CONVERSION_COMPLETED          0x01U 
#define ADC_CONVERSION_NOT_COMPLETED      0x00U

/*                  macro like functions                     */

#define ADC_CONVERSION_STATUS()        ( ADCON0bits.GODONE )    // ADC conversion status ( in progress or in idle state )
#define ADC_START_CONVERSION()         ( ADCON0bits.GODONE = 1) // ADC start conversion 

#define ADC_CONVERTER_ENABLE()         (ADCON0bits.ADON = 1) // enable ADC module
#define ADC_CONVERTER_DISABLE()        (ADCON0bits.ADON = 0) // disable ADC module

/**
 *@brief enable or disable Voltage reference 
 */


#define ADC_RIGHT_FORMAT()             (ADCON2bits.ADFM = 1)
#define ADC_LEFT_FORMAT()             (ADCON2bits.ADFM = 0)  



/*                       data types                          */

/**
 *@brief analog channel select 
 */
typedef enum {
    ADC_CHANNEL_AN0,
    ADC_CHANNEL_AN1,
    ADC_CHANNEL_AN2,
    ADC_CHANNEL_AN3,
    ADC_CHANNEL_AN4,
    ADC_CHANNEL_AN5,
    ADC_CHANNEL_AN6,
    ADC_CHANNEL_AN7,
    ADC_CHANNEL_AN8,
    ADC_CHANNEL_AN9,
    ADC_CHANNEL_AN10,
    ADC_CHANNEL_AN11,
    ADC_CHANNEL_AN12
} adc_channel_select_t;

/**
 *@brief A/D Acquisition time select
 */
typedef enum {
    ADC_0_TAD,
    ADC_2_TAD,
    ADC_4_TAD,
    ADC_6_TAD,
    ADC_8_TAD,
    ADC_12_TAD,
    ADC_16_TAD,
    ADC_20_TAD
} adc_acquisition_time_t;

/*
 *@brief A/D conversion time select
 */
typedef enum {
    ADC_CONVERSION_CLOCK_FOSC_DIV_2,
    ADC_CONVERSION_CLOCK_FOSC_DIV_8,
    ADC_CONVERSION_CLOCK_FOSC_DIV_32,
    ADC_CONVERSION_CLOCK_FOSC_DIV_FRC,
    ADC_CONVERSION_CLOCK_FOSC_DIV_4,
    ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    ADC_CONVERSION_CLOCK_FOSC_DIV_64,
} adc_conversion_clock_t;

typedef struct {
#if  ADC_INTERRUPT_FEATURE_ENABLE  == INTERRUPT_FEATURE_ENABLE 
    void (*ADC_Interrupt_Handler)(void); /* call back function */
#if  INTERRUPT_PRIORITY_LEVELS_ENABLE
    interrupt_INTx_priority priority ;
#endif 
#endif
    adc_acquisition_time_t acquisition_time; /* @ref adc_acquisition_time_t */
    adc_conversion_clock_t conversion_clock; /* @ref adc_conversion_clock_t */
    adc_channel_select_t adc_channel; /* @ref adc_channel_select_t   */
    uint8_t voltage_refrence : 1; /* voltage reference configurations */
    uint8_t result_format : 1; /* result format configurations ( left or right ) */
    uint8_t ADC_Reserved : 6;
} adc_config_t;

typedef enum {
    conversion_done,
    conversion_not_done
} conversion_status_t;

/*                        functions                          */

std_ReturnType ADC_Init(adc_config_t *_adc);
std_ReturnType ADC_DeInit(adc_config_t *_adc);
std_ReturnType ADC_select_channel(adc_config_t *_adc, adc_channel_select_t channel);
std_ReturnType ADC_start_conversion(adc_config_t *_adc);
std_ReturnType ADC_check_conversion(adc_config_t *_adc, conversion_status_t *conversion_status);
std_ReturnType ADC_read_converion_result(adc_config_t *_adc, uint16_t *result);
std_ReturnType ADC_GET_CONVERSION_BLOCKING(adc_config_t *_adc, adc_channel_select_t channel, uint16_t *result);
std_ReturnType ADC_START_CONVERSION_INTERRUPT(adc_config_t *_adc, adc_channel_select_t channel);


#endif	/* HAL_ADC_H */