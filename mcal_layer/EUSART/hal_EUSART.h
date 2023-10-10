/* 
 * File:   hal_EUSART.h
 * Author: Ahmed Elbasioney
 *
 * Created on May 12, 2023, 9:50 PM
 */

#ifndef HAL_EUSART_H
#define	HAL_EUSART_H


/*                      includes                             */


#include "hal_EUSART_cfg.h"
#include <xc.h>
#include "../GPIO/hal_gpio.h"
#include "../interrupt/mcal_internal_interrupt.h"
#include "../mcal_std_libararies.h"
#include "../mcal_std_types.h"
#include "../device_conf.h"

/*                       macros                              */

#define EUSART_MODULE_ENABLE    1
#define EUSART_MODULE_DISABLE   0

#define EUSART_LOW_SPEED_MODE    0   
#define EUSART_HIGH_SPEED_MODE   1


#define EUSART_16BIT_MODE   1
#define EUSART_8BIT_MODE   0

#define EUSART_SYNCHRONOUS_MODE   1
#define EUSART_ASYNCHRONOUS_MODE  0

/*                                TX                          */

#define EUSART_TX_MODULE_ENABLE    1
#define EUSART_TX_MODULE_DISABLE   0

#define EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE   1
#define EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE  0

#define EUSART_ASYNCHRONOUS_9BIT_TX_ENABLE   1
#define EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE  0


/*                               RX                      */


#define EUSART_RX_MODULE_ENABLE    1
#define EUSART_RX_MODULE_DISABLE   0

#define EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE   1
#define EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE  0

#define EUSART_ASYNCHRONOUS_9BIT_RX_ENABLE   1
#define EUSART_ASYNCHRONOUS_9BIT_RX_DISABLE  0


/*                  macro like functions                     */

/*                       data types                          */

typedef enum {
    BAUD_RATE_ASYNCHRONOUS_8BIT_LOW_SPEED,
    BAUD_RATE_ASYNCHRONOUS_8BIT_HIGH_SPEED,
    BAUD_RATE_ASYNCHRONOUS_16BIT_LOW_SPEED,
    BAUD_RATE_ASYNCHRONOUS_16BIT_HIGH_SPEED,
    BAUD_RATE_SYNCHRONOUS_8BIT,
    BAUD_RATE_SYNCHRONOUS_16BIT
} baud_rate_config_t;

typedef struct {
    uint8_t eusart_tx_module_enable : 1;
    uint8_t eusart_tx_interrupt_enable : 1;
    uint8_t eusart_tx_9bit_enable : 1;
} eusart_tx_cfg_t;

typedef struct {
    uint8_t eusart_rx_module_enable : 1;
    uint8_t eusart_rx_interrupt_enable : 1;
    uint8_t eusart_rx_9bit_enable : 1;
} eusart_rx_cfg_t;

typedef struct {
    uint32_t baud_rate_value;
    baud_rate_config_t baud_rate_config;
    eusart_tx_cfg_t tx_cfg;
    eusart_rx_cfg_t rx_cfg;
    uint8_t eusart_interrupt : 1;
#if EUSART_TX_INTERRUPT_FEATURE_ENABLE
    void(* TX_interrupt_handler)(void);
    uint8_t TX_interrupt_priority : 1;
#endif  
#if EUSART_RX_INTERRUPT_FEATURE_ENABLE
    void(* RX_interrupt_handler)(void);
    uint8_t RX_interrupt_priority : 1;
#endif  
    void(* FERR_interrupt_handler)(void);
    void(* OERR_interrupt_handler)(void);
} eusart_t;


/*                        functions                          */

std_ReturnType EUSART_Asynchronous_Init(const eusart_t *eusart);
std_ReturnType EUSART_Asynchronous_DeInit(const eusart_t *eusart);

std_ReturnType EUSART_Asynchronous_Read_Blocking(uint8_t *read_value);
std_ReturnType EUSART_Asynchronous_Read_non_Blocking(uint8_t *read_value);

std_ReturnType EUSART_Asynchronous_Write_Blocking(uint8_t write_value);
std_ReturnType EUSART_Asynchronous_Write_String_Blocking(uint8_t *write_value, uint16_t str_lenght);

std_ReturnType EUSART_Asynchronous_RX_restart(void);

#endif	/* HAL_EUSART_H */

