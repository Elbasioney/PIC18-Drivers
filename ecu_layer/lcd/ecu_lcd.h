/* 
 * File:   ecu_lcd.h
 * Author: Ahmed Elbasioney
 *
 * Created on April 12, 2023, 10:41 PM
 */

#ifndef ECU_LCD_H
#define	ECU_LCD_H

/*                                includes  section                   */

#include "../../mcal_layer/GPIO/hal_gpio.h"
#include "../bin/../../../diploma project.X/../diploma project.X/mcal_layer/device_conf.h"

/*                                macros  section                      */



#define LCD_CLEAR                    0X01    //in initialization
#define LCD_RETURN_HOME              0X02    //in initialization
#define LCD_ENTRY_MODE               0X06    //in initialization
#define LCD_CURSOR_OFF_DISPLAY_ON    0X0C    //in initialization
#define LCD_CURSOR_OFF_DISPLAY_OFF   0X08
#define LCD_CURSOR_ON_BLINK_ON       0X0F
#define LCD_CURSOR_ON_BLINK_OFF      0X0E
#define LCD_DISPLAY_SHIFT_RIGHT      0X1C
#define LCD_DISPLAY_SHIFT_LEFT       0X18
#define LCD_8BIT_MODE_2_LINES        0X38    //in initialization
#define LCD_4BIT_MODE_2_LINES        0X28    //in initialization
#define LCD_CGRAM_START              0X40
#define LCD_DDRAM_START              0X80

#define ROW1 0
#define ROW2 1
#define ROW3 2
#define ROW4 3

#define COLUMN1   1
#define COLUMN2   2
#define COLUMN3   3
#define COLUMN4   4
#define COLUMN5   5
#define COLUMN6   6
#define COLUMN7   7
#define COLUMN8   8
#define COLUMN9   9
#define COLUMN10  10
#define COLUMN11  11
#define COLUMN12  12
#define COLUMN13  13
#define COLUMN14  14
#define COLUMN15  15
#define COLUMN16  16
#define COLUMN17  17
#define COLUMN18  18
#define COLUMN19  19
#define COLUMN20  20

/*                                data types section                   */

typedef struct {
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[4];
}lcd_4bit_t;

typedef struct {
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[8];
}lcd_8bit_t;

/*                                functions  section                   */

std_ReturnType lcd_4bit_init(const lcd_4bit_t *lcd );
std_ReturnType lcd_4bit_send_command(const lcd_4bit_t *lcd  , char command);
std_ReturnType lcd_4bit_send_data(const lcd_4bit_t *lcd , char data );
std_ReturnType lcd_4bit_send_data_pos(const lcd_4bit_t *lcd , char row , char column ,char data );
std_ReturnType lcd_4bit_send_string(const lcd_4bit_t *lcd , char *str );
std_ReturnType lcd_4bit_send_string_pos(const lcd_4bit_t *lcd , char row , char column , char *str );
std_ReturnType lcd_4bit_send_custom_char(const lcd_4bit_t *lcd , char row , char column ,char _char[] , char mem_pos );


std_ReturnType lcd_8bit_init(const lcd_8bit_t *lcd );
std_ReturnType lcd_8bit_send_command(const lcd_8bit_t *lcd  , char command);
std_ReturnType lcd_8bit_send_data(const lcd_8bit_t *lcd , char data );
std_ReturnType lcd_8bit_send_data_pos(const lcd_8bit_t *lcd , char row , char column ,char data );
std_ReturnType lcd_8bit_send_string(const lcd_8bit_t *lcd , char *str );
std_ReturnType lcd_8bit_send_string_pos(const lcd_8bit_t *lcd , char row , char column , char *str );
std_ReturnType lcd_8bit_send_custom_char(const lcd_8bit_t *lcd , char row , char column ,char _char[] , char mem_pos );


std_ReturnType convert_byte_to_string(char value , char *str);
std_ReturnType convert_short_to_string(short value , char *str);
std_ReturnType convert_int_to_string(int value , char *str);
std_ReturnType lcd_send_4bits(const lcd_4bit_t *lcd , char _data_command);
std_ReturnType lcd_4bit_send_enable_signal(const lcd_4bit_t *lcd );
std_ReturnType lcd_8bit_send_enable_signal(const lcd_8bit_t *lcd );
std_ReturnType lcd_8bit_set_cursor(const lcd_8bit_t *lcd , char row , char column);
std_ReturnType lcd_4bit_set_cursor(const lcd_4bit_t *lcd , char row , char column) ;

#endif	/* ECU_LCD_H */

