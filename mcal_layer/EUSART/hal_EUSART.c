/* 
 * File:   hal_EUSART.c
 * Author: Ahmed Elbasioney
 *
 * Created on May 12, 2023, 9:50 PM
 */

#include "hal_EUSART.h"

static void EUSART_baud_rate_calculations(const eusart_t *eusart);
static void EUSART_TX_Init(const eusart_t *eusart);
static void EUSART_RX_Init(const eusart_t *eusart);

#if EUSART_TX_INTERRUPT_FEATURE_ENABLE
void (*EUSART_TX_INTERRUPT_HANDLER)(void) = NULL;
#endif

#if EUSART_RX_INTERRUPT_FEATURE_ENABLE
void (*EUSART_RX_INTERRUPT_HANDLER)(void) = NULL;
void (*EUSART_FERR_INTERRUPT_HANDLER)(void) = NULL;
void (*EUSART_OERR_INTERRUPT_HANDLER)(void) = NULL;
#endif

std_ReturnType EUSART_Asynchronous_Init(const eusart_t *eusart) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == eusart) {
        RET_VAL = E_NOK;
    } else {
        RCSTAbits.SPEN = EUSART_MODULE_DISABLE; // disable EUSART module  
        TRISCbits.RC6 = 1; // pin RC6 input 
        TRISCbits.RC7 = 1; // pin RC7 input 
        EUSART_baud_rate_calculations(eusart); // baud rate configurations
        EUSART_TX_Init(eusart); // TX configurations
        EUSART_RX_Init(eusart); // RX configurations
        RCSTAbits.SPEN = EUSART_MODULE_ENABLE; // enable EUSART module 
        RET_VAL = E_OK;
    }
    return RET_VAL;
}

std_ReturnType EUSART_Asynchronous_DeInit(const eusart_t *eusart) {
    std_ReturnType RET_VAL = E_NOK;
    if (NULL == eusart) {
        RET_VAL = E_NOK;
    } else {
        RCSTAbits.SPEN = EUSART_MODULE_DISABLE; // disable EUSART module  

        RET_VAL = E_OK;
    }
    return RET_VAL;
}

std_ReturnType EUSART_Asynchronous_Read_Blocking(uint8_t *read_value) {
    std_ReturnType RET_VAL = E_OK;
    while (!(PIR1bits.RCIF));
    *read_value = RCREG;
    return RET_VAL;
}

std_ReturnType EUSART_Asynchronous_Read_non_Blocking(uint8_t *read_value) {
    std_ReturnType RET_VAL = E_NOK;
    if (PIR1bits.RCIF) {
        *read_value = RCREG;
        RET_VAL = E_OK;
    } else {
        RET_VAL = E_NOK;
    }
    return RET_VAL;
}

std_ReturnType EUSART_Asynchronous_Write_Blocking(uint8_t write_value) {
    std_ReturnType RET_VAL = E_OK;
    while (!(TXSTAbits.TRMT));
#if  EUSART_TX_INTERRUPT_FEATURE_ENABLE  
    PIE1bits.TXIE = 1 ;  // enable TX interrupt 
#endif
    TXREG = write_value;
    return RET_VAL;
}

std_ReturnType EUSART_Asynchronous_Write_String_Blocking(uint8_t *write_value, uint16_t str_lenght) {
    std_ReturnType RET_VAL = E_OK;
    for (int i = 0; i < str_lenght; i++) {
        RET_VAL = EUSART_Asynchronous_Write_Blocking(write_value[i]);
    }
    return RET_VAL;
}

std_ReturnType EUSART_Asynchronous_RX_restart(void){
    std_ReturnType RET_VAL = E_OK;
    RCSTAbits.CREN = 0 ;   // disable receiver 
    RCSTAbits.CREN = 1 ;   // enable receiver
    return RET_VAL;
}

/*                       helper functions                    */

static void EUSART_baud_rate_calculations(const eusart_t *eusart) {
    float baud_rate_temp_value = 0;
    switch (eusart->baud_rate_config) {
        case BAUD_RATE_ASYNCHRONOUS_8BIT_LOW_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_LOW_SPEED_MODE;
            BAUDCONbits.BRG16 = EUSART_8BIT_MODE;
            baud_rate_temp_value = ((_XTAL_FREQ / (float) (eusart->baud_rate_value)) / 64) - 1;
            break;
        case BAUD_RATE_ASYNCHRONOUS_16BIT_LOW_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_LOW_SPEED_MODE;
            BAUDCONbits.BRG16 = EUSART_16BIT_MODE;
            baud_rate_temp_value = ((_XTAL_FREQ / (float) (eusart->baud_rate_value)) / 16) - 1;
            break;
        case BAUD_RATE_ASYNCHRONOUS_8BIT_HIGH_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_HIGH_SPEED_MODE;
            BAUDCONbits.BRG16 = EUSART_8BIT_MODE;
            baud_rate_temp_value = ((_XTAL_FREQ / (float) (eusart->baud_rate_value)) / 16) - 1;
            break;
        case BAUD_RATE_ASYNCHRONOUS_16BIT_HIGH_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_HIGH_SPEED_MODE;
            BAUDCONbits.BRG16 = EUSART_16BIT_MODE;
            baud_rate_temp_value = ((_XTAL_FREQ / (float) (eusart->baud_rate_value)) / 4) - 1;
            break;
        case BAUD_RATE_SYNCHRONOUS_8BIT:
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_8BIT_MODE;
            baud_rate_temp_value = ((_XTAL_FREQ / (float) (eusart->baud_rate_value)) / 4) - 1;
            break;
        case BAUD_RATE_SYNCHRONOUS_16BIT:
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_16BIT_MODE;
            baud_rate_temp_value = ((_XTAL_FREQ / (float) (eusart->baud_rate_value)) / 4) - 1;
            break;
        default:;
    }

    SPBRG = (uint8_t) ((uint32_t) baud_rate_temp_value);
    SPBRGH = (uint8_t) (((uint32_t) baud_rate_temp_value) >> 8);
}

static void EUSART_TX_Init(const eusart_t *eusart) {
    if (eusart->tx_cfg.eusart_tx_module_enable == EUSART_TX_MODULE_ENABLE) {
        TXSTAbits.TXEN = EUSART_TX_MODULE_ENABLE;
        if (eusart->tx_cfg.eusart_tx_interrupt_enable == EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE) {
            PIE1bits.TXIE = EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE; // enable transmitting interrupt 
#if EUSART_TX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
            EUSART_TX_INTERRUPT_HANDLER = (eusart->TX_interrupt_handler);
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
            INTERRUPT_PRIORITY_ENABLE();
            if (eusart->TX_interrupt_priority == INTERRUPT_HIGH_PRIORITY) {
                INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
                EUSART_TX_INTERRUPT_SET_HIGH_PRIORITY();
            } else if (eusart->TX_interrupt_priority == INTERRUPT_LOW_PRIORITY) {
                INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
                EUSART_TX_INTERRUPT_SET_LOW_PRIORITY();
            } else {
                /*  no thing   */
            }
#else 
            INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
            INTERRUPT_PERIPHERALS_INTERRUPT_ENABLE();
            EUSART_TX_INTERRUPT_ENABLE();
#endif
#endif    
        } else if (eusart->tx_cfg.eusart_tx_interrupt_enable == EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE) {
            EUSART_TX_INTERRUPT_DISABLE(); // disable transmitting interrupt 
        } else {
            /*   no thing   */
        }
        if (eusart->tx_cfg.eusart_tx_9bit_enable == EUSART_ASYNCHRONOUS_9BIT_TX_ENABLE) {
            TXSTAbits.TX9 = EUSART_ASYNCHRONOUS_9BIT_TX_ENABLE; // enable transmitting the 9th bit
        } else if (eusart->tx_cfg.eusart_tx_9bit_enable == EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE) {
            TXSTAbits.TX9 = EUSART_ASYNCHRONOUS_9BIT_TX_DISABLE; // disable transmitting the 9th bit 
        } else {
            /*   no thing   */
        }
    } else {
        /*   no thing   */
    }

}

static void EUSART_RX_Init(const eusart_t *eusart) {
    if (eusart->rx_cfg.eusart_rx_module_enable == EUSART_RX_MODULE_ENABLE) {
        RCSTAbits.CREN = EUSART_RX_MODULE_ENABLE;
        if (eusart->rx_cfg.eusart_rx_interrupt_enable == EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE) {
#if EUSART_RX_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
            EUSART_RX_INTERRUPT_ENABLE();
            EUSART_RX_INTERRUPT_HANDLER = eusart->RX_interrupt_handler ;
            EUSART_FERR_INTERRUPT_HANDLER = eusart->FERR_interrupt_handler ;
            EUSART_OERR_INTERRUPT_HANDLER = eusart->OERR_interrupt_handler ;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE
            INTERRUPT_PRIORITY_ENABLE();
            if (eusart->RX_interrupt_priority == INTERRUPT_HIGH_PRIORITY) {
                INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
                EUSART_RX_INTERRUPT_SET_HIGH_PRIORITY();
            } else if (eusart->RX_interrupt_priority == INTERRUPT_LOW_PRIORITY) {
                INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
                EUSART_RX_INTERRUPT_SET_LOW_PRIORITY();
            } else {
                /*  no thing   */
            }
#else 
            INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
            INTERRUPT_PERIPHERALS_INTERRUPT_ENABLE();
            EUSART_RX_INTERRUPT_ENABLE();
#endif 
#endif     
        } else if (eusart->rx_cfg.eusart_rx_interrupt_enable == EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE) {
            EUSART_RX_INTERRUPT_DISABLE(); // disable receiving interrupt 
        } else {
            /*   no thing   */
        }
        if (eusart->rx_cfg.eusart_rx_9bit_enable == EUSART_ASYNCHRONOUS_9BIT_RX_ENABLE) {
            RCSTAbits.RX9 = EUSART_ASYNCHRONOUS_9BIT_RX_ENABLE; // enable receiving the 9th bit
        } else if (eusart->rx_cfg.eusart_rx_9bit_enable == EUSART_ASYNCHRONOUS_9BIT_RX_DISABLE) {
            RCSTAbits.RX9 = EUSART_ASYNCHRONOUS_9BIT_RX_DISABLE; // disable receiving the 9th bit 
        } else {
            /*   no thing   */
        }
    } else {
        /*   no thing   */
    }

}

void EUSART_TX_ISR(void) {
    PIE1bits.TXIE = 0  ;
    if (EUSART_TX_INTERRUPT_HANDLER) {
        EUSART_TX_INTERRUPT_HANDLER();
    } else {

    }
}

void EUSART_RX_ISR(void) {
    
    if (EUSART_RX_INTERRUPT_HANDLER) {
        EUSART_RX_INTERRUPT_HANDLER();
    } else {

    }
    if (EUSART_FERR_INTERRUPT_HANDLER) {
        EUSART_FERR_INTERRUPT_HANDLER();
    } else {

    }
    if (EUSART_OERR_INTERRUPT_HANDLER) {
        EUSART_OERR_INTERRUPT_HANDLER();
    } else {

    }
}