
#include "ecu_init.h"



lcd_4bit_t lcd_1 = {
    
  .lcd_rs.port = PORTA_INDEX ,
  .lcd_rs.pin = PIN0,
  .lcd_rs.direction = OUTPUT ,
  .lcd_rs.logic = LOW ,
  
  .lcd_en.port = PORTA_INDEX,
  .lcd_en.pin = PIN1,
  .lcd_en.direction = OUTPUT,
  .lcd_en.logic = LOW ,
  
  .lcd_data[0].port = PORTA_INDEX ,
  .lcd_data[0].pin = PIN2,
  .lcd_data[0].direction = OUTPUT ,
  .lcd_data[0].logic = LOW ,
  
  .lcd_data[1].port = PORTA_INDEX ,
  .lcd_data[1].pin = PIN3,
  .lcd_data[1].direction = OUTPUT ,
  .lcd_data[1].logic = LOW ,
  
  .lcd_data[2].port = PORTA_INDEX ,
  .lcd_data[2].pin = PIN4,
  .lcd_data[2].direction = OUTPUT ,
  .lcd_data[2].logic = LOW ,
  
  .lcd_data[3].port = PORTA_INDEX ,
  .lcd_data[3].pin = PIN5,
  .lcd_data[3].direction = OUTPUT ,
  .lcd_data[3].logic = LOW 
  
};


lcd_8bit_t lcd_2 = {
    
  .lcd_rs.port = PORTC_INDEX ,
  .lcd_rs.pin = PIN6,
  .lcd_rs.direction = OUTPUT ,
  .lcd_rs.logic = LOW ,
  
  .lcd_en.port = PORTC_INDEX,
  .lcd_en.pin = PIN7,
  .lcd_en.direction = OUTPUT,
  .lcd_en.logic = LOW ,
  
  .lcd_data[0].port = PORTD_INDEX ,
  .lcd_data[0].pin = PIN0,
  .lcd_data[0].direction = OUTPUT ,
  .lcd_data[0].logic = LOW ,
  
  .lcd_data[1].port = PORTD_INDEX ,
  .lcd_data[1].pin = PIN1,
  .lcd_data[1].direction = OUTPUT ,
  .lcd_data[1].logic = LOW ,
  
  .lcd_data[2].port = PORTD_INDEX ,
  .lcd_data[2].pin = PIN2,
  .lcd_data[2].direction = OUTPUT ,
  .lcd_data[2].logic = LOW ,
  
  .lcd_data[3].port = PORTD_INDEX ,
  .lcd_data[3].pin = PIN3,
  .lcd_data[3].direction = OUTPUT ,
  .lcd_data[3].logic = LOW ,
          
          
  .lcd_data[4].port = PORTD_INDEX ,
  .lcd_data[4].pin = PIN4,
  .lcd_data[4].direction = OUTPUT ,
  .lcd_data[4].logic = LOW ,
  
  .lcd_data[5].port = PORTD_INDEX ,
  .lcd_data[5].pin = PIN5,
  .lcd_data[5].direction = OUTPUT ,
  .lcd_data[5].logic = LOW ,
  
  .lcd_data[6].port = PORTD_INDEX ,
  .lcd_data[6].pin = PIN6,
  .lcd_data[6].direction = OUTPUT ,
  .lcd_data[6].logic = LOW ,
  
  .lcd_data[7].port = PORTD_INDEX ,
  .lcd_data[7].pin = PIN7,
  .lcd_data[7].direction = OUTPUT ,
  .lcd_data[7].logic = LOW 
  
};


keypad_t keypad_1 = {
  .keypad_rows[0].port = PORTC_INDEX ,
  .keypad_rows[0].pin = PIN0 ,
  .keypad_rows[0].direction = OUTPUT ,
  .keypad_rows[0].logic = LOW ,
  
  .keypad_rows[1].port = PORTC_INDEX ,
  .keypad_rows[1].pin = PIN1 ,
  .keypad_rows[1].direction = OUTPUT ,
  .keypad_rows[1].logic = LOW ,
  
  .keypad_rows[2].port = PORTC_INDEX ,
  .keypad_rows[2].pin = PIN2 ,
  .keypad_rows[2].direction = OUTPUT ,
  .keypad_rows[2].logic = LOW ,
  
  .keypad_rows[3].port = PORTC_INDEX ,
  .keypad_rows[3].pin = PIN3 ,
  .keypad_rows[3].direction = OUTPUT ,
  .keypad_rows[3].logic = LOW ,
  
  .keypad_columns[0].port = PORTC_INDEX ,
  .keypad_columns[0].pin = PIN4 ,
  .keypad_columns[0].direction = INPUT ,
  .keypad_columns[0].logic = LOW ,
  
  .keypad_columns[1].port = PORTC_INDEX ,
  .keypad_columns[1].pin = PIN5 ,
  .keypad_columns[1].direction = INPUT ,
  .keypad_columns[1].logic = LOW ,
  
  .keypad_columns[2].port = PORTC_INDEX ,
  .keypad_columns[2].pin = PIN6 ,
  .keypad_columns[2].direction = INPUT ,
  .keypad_columns[2].logic = LOW ,
  
  .keypad_columns[3].port = PORTC_INDEX ,
  .keypad_columns[3].pin = PIN7 ,
  .keypad_columns[3].direction = INPUT ,
  .keypad_columns[3].logic = LOW ,
    
};


/*interrupt_INTx_t int1_object = {
    .external_interrupt_handler = MY_INT1_ISR,
    .edge = INTERRUPT_RISING_EDGE , 
    .priority = INTERRUPT_LOW_PRIORITY ,
    .source =   INTERRUPT_EXTERNAL_INT1 ,
    .mcu_pin.port = PORTB_INDEX ,
    .mcu_pin.pin = PIN1 ,
    .mcu_pin.direction = INPUT , 
};
interrupt_INTx_t int2_object = {
    .external_interrupt_handler = MY_INT2_ISR,
    .edge = INTERRUPT_RISING_EDGE , 
    .priority = INTERRUPT_HIGH_PRIORITY ,
    .source =   INTERRUPT_EXTERNAL_INT2 ,
    .mcu_pin.port = PORTB_INDEX ,
    .mcu_pin.pin = PIN2 ,
    .mcu_pin.direction = INPUT , 
};*/
    
led_t led_1 = {
  .port = PORTC_INDEX ,
  .pin = PIN0 ,
  .status = LED_OFF 
};
led_t led_2 = {
  .port = PORTC_INDEX ,
  .pin = PIN1 ,
  .status = LED_OFF 
};
led_t led_3 = {
  .port = PORTC_INDEX ,
  .pin = PIN2 ,
  .status = LED_OFF 
};
led_t led_4 = {
  .port = PORTC_INDEX ,
  .pin = PIN3 ,
  .status = LED_OFF 
};
led_t led_5 = {
  .port = PORTC_INDEX ,
  .pin = PIN4 ,
  .status = LED_OFF 
};
led_t led_6 = {
  .port = PORTC_INDEX ,
  .pin = PIN5 ,
  .status = LED_OFF 
};
led_t led_7 = {
  .port = PORTC_INDEX ,
  .pin = PIN6 ,
  .status = LED_OFF 
};
led_t led_8 = {
  .port = PORTC_INDEX ,
  .pin = PIN7 ,
  .status = LED_OFF 
};

dc_motor_t motor_1 = {
  .motor_in_1.port = PORTD_INDEX ,
  .motor_in_1.pin = PIN0 ,
  .motor_in_1.direction  = OUTPUT ,
  .motor_in_1.logic = LOW ,
  .motor_in_2.port = PORTD_INDEX ,
  .motor_in_2.pin = PIN1 ,
  .motor_in_2.direction  = OUTPUT ,
  .motor_in_2.logic = LOW ,
};
dc_motor_t motor_2 = {
  .motor_in_1.port = PORTD_INDEX ,
  .motor_in_1.pin = PIN2 ,
  .motor_in_1.direction  = OUTPUT ,
  .motor_in_1.logic = LOW ,
  .motor_in_2.port = PORTD_INDEX ,
  .motor_in_2.pin = PIN3 ,
  .motor_in_2.direction  = OUTPUT ,
  .motor_in_2.logic = LOW ,
};