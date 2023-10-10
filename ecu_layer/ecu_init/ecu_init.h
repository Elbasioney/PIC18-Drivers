/* 
 * File:   ecu_init.h
 * Author: LENOVO
 *
 * Created on April 13, 2023, 2:39 PM
 */

#ifndef ECU_INIT_H
#define	ECU_INIT_H

#include "../../mcal_layer/GPIO/hal_gpio.h"
#include "../../mcal_layer/interrupt/mcal_external_interrupt.h"

#include "../led/ecu_led.h"
#include "../pb/ecu_pb.h"
#include "../relay/ecu_relay.h"
#include "../dc_motor/ecu_dc_motor.h"
#include "../seven_segment/ecu_7_segment.h"
#include "../key_pad/ecu_keypad.h"
#include "../lcd/ecu_lcd.h"


extern lcd_4bit_t lcd_1   ;
extern lcd_8bit_t lcd_2   ; 
extern keypad_t keypad_1  ;
extern interrupt_INTx_t int0_object ;
extern interrupt_INTx_t int1_object ;
extern interrupt_INTx_t int2_object ;
extern led_t led_1 ;
extern led_t led_2 ;
extern led_t led_3 ;
extern led_t led_4 ;
extern led_t led_5 ;
extern led_t led_6 ;
extern led_t led_7 ;
extern led_t led_8 ;
extern dc_motor_t motor_1 ;
extern dc_motor_t motor_2 ;

#endif	/* ECU_INIT_H */

