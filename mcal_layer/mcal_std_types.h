
/* 
 * File:   mcal_std_types.h
 * Author: ahmed elbasioney
 *
 * Created on March 8, 2023, 5:34 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H
/*                   includes   section                */
#include "mcal_std_libararies.h"
#include "compiler.h"
/*                   macro     section                 */
#define STD_HIGH     0X01
#define STD_LOW      0x00
#define STD_ON       0X01
#define STD_OFF      0x00
#define STD_ACTIVE   0X01
#define STD_IDLE     0x00

#define ENABLED      0x01
#define DISABLED     0x00

#define E_OK      (std_ReturnType)0x01
#define E_NOK     (std_ReturnType)0x00
/*                   datatype  section                 */

typedef uint8_t std_ReturnType ; 

/*                   function  section                 */

#endif


