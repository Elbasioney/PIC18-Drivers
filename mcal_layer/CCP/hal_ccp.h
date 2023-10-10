/* 
 * File:   hal_ccp.h
 * Author: Ahmed Elbasioney
 *
 * Created on May 7, 2023, 9:22 PM
 */

#ifndef HAL_CCP_H
#define	HAL_CCP_H


/*                                        includes                          */

#include <xc.h>
#include "../GPIO/hal_gpio.h"
#include "../interrupt/mcal_internal_interrupt.h"
#include "../mcal_std_libararies.h"
#include "../mcal_std_types.h"
#include "hal_ccp_cfg.h"
#include "../device_conf.h"

/*                                            macros                         */

#define CCP_MODULE_DISABLED                ((uint8_t)0x00) 
#define CCP_CAPTURE_MODE_1_FALLING_EDGE    ((uint8_t)0x04)
#define CCP_CAPTURE_MODE_1_RAISING_EDGE    ((uint8_t)0x05)
#define CCP_CAPTURE_MODE_4_RAISING_EDGE    ((uint8_t)0x06)            
#define CCP_CAPTURE_MODE_16_RAISING_EDGE   ((uint8_t)0x07)            
#define CCP_COMPARE_MODE_SET_PIN_LOW       ((uint8_t)0x08)
#define CCP_COMPARE_MODE_SET_PIN_HIGH      ((uint8_t)0x09)
#define CCP_COMPARE_MODE_TOGGLE_ON_MATCH   ((uint8_t)0x02)
#define CCP_COMPARE_MODE_GEN_SW_INTERRUPT  ((uint8_t)0x0A)
#define CCP_COMPARE_MODE_GEN_EVENT         ((uint8_t)0x0B)
#define CCP_PWM_MODE                       ((uint8_t)0x0C)

#define CCP_COMPARE_NOT_READY   0x00
#define CCP_COMPARE_READY       0x01

#define CCP_CAPTURE_NOT_READY   0x00
#define CCP_CAPTURE_READY       0x01

/*                                        macro like functions                */

#define CCP1_SET_MODE(_CONFIG)      ( CCP1CONbits.CCP1M = _CONFIG )   // to set the ccp1 opertaing mode
#define CCP2_SET_MODE(_CONFIG)      ( CCP2CONbits.CCP2M = _CONFIG )   // to set the ccp2 opertaing mode

/*                                           data types                       */

typedef enum {
    CCP1_INST,
    CCP2_INST,
} ccp_inst_t;

typedef enum {
    CCP_CAPTURE_MODE_SELECTED,
    CCP_COMPARE_MODE_SELECTED,
    CCP_PWM_MODE_SELECTED
} ccp_mode_t;

typedef enum {
    CCP1_CCP2_TIMER3,
    CCP1_TIMER1_CCP2_TIMER3,
    CCP1_CCP2_TIMER1
} ccp_capture_timer_t;

typedef struct {
    ccp_inst_t ccp_inst ;
    ccp_capture_timer_t ccp_capture ;
#if ( CCP1_INTERRUPT_FEATURE_ENABLE || CCP2_INTERRUPT_FEATURE_ENABLE )
    void ( * CCP_INTERRUPT_HANDLER)(void);
    uint8_t priority : 1;
#endif  
#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED || CCP2_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED )
    uint8_t PR2_VALUE;
#endif
    pin_config_t pin;
    ccp_mode_t mode;
    uint8_t mode_variant;
} ccp_config_t;

/*                                            functions                       */

std_ReturnType CCP_Init(const ccp_config_t *ccp);
std_ReturnType CCP_DeInit(const ccp_config_t *ccp);

#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED || CCP2_CFG_SELECTED_MODE == CCP_CFG_CAPTURE_MODE_SELECTED)
std_ReturnType CCP_Is_Capture_Data_Ready(uint8_t *capture_status);
std_ReturnType CCP_Capture_Read_Value(uint16_t *capture_value);
#endif

#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED || CCP2_CFG_SELECTED_MODE == CCP_CFG_COMPARE_MODE_SELECTED)
std_ReturnType CCP_Is_Compare_complete(uint8_t *Compare_status);
std_ReturnType CCP_Compare_set_Value(const ccp_config_t *ccp, uint16_t Compare_value);
#endif

#if (CCP1_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED || CCP2_CFG_SELECTED_MODE == CCP_CFG_PWM_MODE_SELECTED)
std_ReturnType CCP_PWM_set_duty_cycle(const ccp_config_t *ccp, const uint8_t duty_cycle);
std_ReturnType CCP_PWM_start(const ccp_config_t *ccp);
std_ReturnType CCP_PWM_stopconst(ccp_config_t *ccp);

#endif


#endif	/* HAL_CCP_H */

