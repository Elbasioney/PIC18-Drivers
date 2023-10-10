/* 
 * File:   hal_eeprom.c
 * Author: Ahmed Elbasioney
 *
 * Created on April 25, 2023, 2:24 AM
 */

#include "hal_eeprom.h"


/**
 * @brief write data to the EEPROM 
 * @param byte_address
 * @param byte_data
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */

std_ReturnType data_eeprom_write_byte(uint16_t byte_address , uint8_t byte_data){
    std_ReturnType RET_VAL = E_NOK ;
    uint8_t interrupt_status = INTCONbits.GIE ;   // read interrupt status 
    EEADRH = (byte_address >> 8) & 0x03 ;         // update the address register
    EEADR = (byte_address) & 0xFF ;               // update the address register
    EEDATA  = byte_data ;        // write the data to the registers
    EECON1bits.EEPGD = ACCESS_EEPROM_PROGRAM_MEMORY ;       // clear EEPGD bit
    EECON1bits.CFGS = ACCESS_FLASH_EEPROM_MEMORY ;                 // clear CFGS bit
    EECON1bits.WREN  = ALLOW_WRITE_CYCLES_FLASH_EEPROM ;    // allow writing on EEPROM memory
    INTCONbits.GIE = 0 ;   // disable general interrupts
                /*    required sequence     EECON2 0x55 --> 0xAA    */
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1 ;    // initiate writing 
    /*           wait for the WR bit to be cleared (completed writing )        */
    while(EECON1bits.WR){   
        
    }
    EECON1bits.WREN  = INHIBTS_WRITE_CYCLES_FLASH_EEPROM ;
    INTCONbits.GIE = interrupt_status ;
    return RET_VAL ; 
}

/**
 * @brief read data from the EEPROM
 * @param byte_address
 * @param byte_data
 * @return status of the function 
 *          ( E_OK  ) : the function has been done successfully   
 *          ( E_NOK ) : the function has been failed
 */
std_ReturnType data_eeprom_read_byte(uint16_t byte_address , uint8_t *byte_data){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == byte_data){
        RET_VAL = E_NOK ;
    }else{
    EEADRH = (byte_address >> 8) & 0x03 ;                   // update the address register
    EEADR = (byte_address) & 0xFF ;                         // update the address register
    EECON1bits.EEPGD = ACCESS_EEPROM_PROGRAM_MEMORY ;       // clear EEPGD bit
    EECON1bits.CFGS = ACCESS_FLASH_EEPROM_MEMORY ;          // clear CFGS bit
    EECON1bits.RD = INITIATE_DATA_EEPROM_READ ;             // initiate reading
    NOP();
    NOP();
    *byte_data = EEDATA ;
    }
    return RET_VAL ; 
}

