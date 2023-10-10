/* 
 * File:   hal_eeprom.h
 * Author: Ahmed Elbasioney
 *
 * Created on April 25, 2023, 2:24 AM
 */

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H

/*                                        includes                          */

#include <xc.h>
#include "../GPIO/hal_gpio.h"
#include "../interrupt/mcal_internal_interrupt.h"
#include "../mcal_std_libararies.h"
#include "../mcal_std_types.h"

/*                                            macros                         */

#define ACCESS_FLASH_PROGRAM_MEMORY                  1 
#define ACCESS_EEPROM_PROGRAM_MEMORY                 0 

#define ACCESS_CONFIGURATIONS_BITS                   1 
#define ACCESS_FLASH_EEPROM_MEMORY                   0 

#define ALLOW_WRITE_CYCLES_FLASH_EEPROM              1 
#define INHIBTS_WRITE_CYCLES_FLASH_EEPROM            0

#define INITIATE_DATA_EEPROM_WRITE_ERASE             1 
#define INITIATE_DATA_EEPROM_WRITE_ERASE_COMPLETED   0 

#define INITIATE_DATA_EEPROM_READ             1 
#define INITIATE_DATA_EEPROM_READ_COMPLETED   0

/*                                        macro like functions                */




/*                                           data types                       */




/*                                            functions                       */

std_ReturnType data_eeprom_write_byte(uint16_t byte_address , uint8_t byte_data);
std_ReturnType data_eeprom_read_byte(uint16_t byte_address , uint8_t *byte_data);

#endif	/* HAL_EEPROM_H */

