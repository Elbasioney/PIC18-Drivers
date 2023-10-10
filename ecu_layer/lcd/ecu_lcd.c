/*
 * File:   ecu_lcd.c
 * Author: Ahmed Elbasioney
 *
 * Created on April 12, 2023, 10:41 PM
 */

#include "ecu_lcd.h"

/*                                                 4-bit mode                                */

std_ReturnType lcd_4bit_init(const lcd_4bit_t *lcd ){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = gpio_pin_init(&(lcd->lcd_en));
        RET_VAL = gpio_pin_init(&(lcd->lcd_rs));
        for(int i = 0 ; i <4 ; i++)
        {
            RET_VAL = gpio_pin_init(&(lcd->lcd_data[i]));
        }
        __delay_ms(20);
        RET_VAL = lcd_4bit_send_command(lcd , LCD_8BIT_MODE_2_LINES);
        __delay_ms(5);
        RET_VAL = lcd_4bit_send_command(lcd , LCD_8BIT_MODE_2_LINES);
        __delay_us(150);
        RET_VAL = lcd_4bit_send_command(lcd , LCD_8BIT_MODE_2_LINES);
        RET_VAL = lcd_4bit_send_command(lcd , LCD_CLEAR);
        RET_VAL = lcd_4bit_send_command(lcd , LCD_RETURN_HOME);
        RET_VAL = lcd_4bit_send_command(lcd , LCD_ENTRY_MODE);
        RET_VAL = lcd_4bit_send_command(lcd , LCD_CURSOR_OFF_DISPLAY_ON);
        RET_VAL = lcd_4bit_send_command(lcd , LCD_4BIT_MODE_2_LINES);
        RET_VAL = lcd_4bit_send_command(lcd , 0x80);

    }
    return RET_VAL ;
}

std_ReturnType lcd_4bit_send_command(const lcd_4bit_t *lcd  , char command){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = gpio_pin_write_logic(&(lcd->lcd_rs),LOW);
        RET_VAL = lcd_send_4bits(lcd , command >> 4 );    // send 4 higher bits
        RET_VAL = lcd_4bit_send_enable_signal( lcd );
        RET_VAL = lcd_send_4bits(lcd , command );         // send 4 lower bits
        RET_VAL = lcd_4bit_send_enable_signal( lcd );
    }
    return RET_VAL ;

}

std_ReturnType lcd_4bit_send_data(const lcd_4bit_t *lcd , char data ){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = gpio_pin_write_logic(&(lcd->lcd_rs),HIGH);
        RET_VAL = lcd_send_4bits(lcd , data >> 4 );    // send 4 higher bits
        RET_VAL = lcd_4bit_send_enable_signal( lcd );
        RET_VAL = lcd_send_4bits(lcd , data );         // send 4 lower bits
        RET_VAL = lcd_4bit_send_enable_signal( lcd );
    }
    return RET_VAL ;

}

std_ReturnType lcd_4bit_send_data_pos(const lcd_4bit_t *lcd , char row , char column ,char data ){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = lcd_4bit_set_cursor(lcd , row , column);
        RET_VAL = lcd_4bit_send_data(lcd , data );
    }
    return RET_VAL ;

}

std_ReturnType lcd_4bit_send_string(const lcd_4bit_t *lcd , char *str ){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{
        while(*str){
            RET_VAL = lcd_4bit_send_data(lcd , *str ) ;
            str++ ;
        }
    }
    return RET_VAL ;

}

std_ReturnType lcd_4bit_send_string_pos(const lcd_4bit_t *lcd , char row , char column , char *str ){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = lcd_4bit_set_cursor(lcd , row , column );
        while(*str){
            RET_VAL = lcd_4bit_send_data(lcd , *str ) ;
            str++ ;
        }
    }
    return RET_VAL ;

}

std_ReturnType lcd_4bit_send_custom_char(const lcd_4bit_t *lcd , char row , char column ,char _char[] , char mem_pos ){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{

    }
    return RET_VAL ;

}

/*                                                 8-bit mode                                */

std_ReturnType lcd_8bit_init(const lcd_8bit_t *lcd ){
    std_ReturnType RET_VAL = E_NOK ;
    int i = 0 ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = gpio_pin_init(&(lcd->lcd_en));
        RET_VAL = gpio_pin_init(&(lcd->lcd_rs));
        for( i = 0 ; i <8 ; i++)
        {
            RET_VAL = gpio_pin_init(&(lcd->lcd_data[i]));
        }
        __delay_ms(20);
        RET_VAL = lcd_8bit_send_command(lcd , LCD_8BIT_MODE_2_LINES);
        __delay_ms(5);
        RET_VAL = lcd_8bit_send_command(lcd , LCD_8BIT_MODE_2_LINES);
        __delay_us(150);
        RET_VAL = lcd_8bit_send_command(lcd , LCD_8BIT_MODE_2_LINES);
        RET_VAL = lcd_8bit_send_command(lcd , LCD_CLEAR);
        RET_VAL = lcd_8bit_send_command(lcd , LCD_RETURN_HOME);
        RET_VAL = lcd_8bit_send_command(lcd , LCD_ENTRY_MODE);
        RET_VAL = lcd_8bit_send_command(lcd , LCD_CURSOR_OFF_DISPLAY_ON);
        RET_VAL = lcd_8bit_send_command(lcd , LCD_8BIT_MODE_2_LINES);
        RET_VAL = lcd_8bit_send_command(lcd , 0x80);

    }
    return RET_VAL ;

}

std_ReturnType lcd_8bit_send_command(const lcd_8bit_t *lcd  , char command){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = gpio_pin_write_logic(&(lcd->lcd_rs),LOW);
        for(int i = 0 ; i < 8 ; i++)
        {
            RET_VAL = gpio_pin_write_logic(&(lcd->lcd_data[i]),(command >> i)&1 );
        }
        RET_VAL = lcd_8bit_send_enable_signal(lcd);
    }
    return RET_VAL ;

}

std_ReturnType lcd_8bit_send_data(const lcd_8bit_t *lcd , char data ){
    std_ReturnType RET_VAL = E_NOK ;
    int i = 0 ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = gpio_pin_write_logic(&(lcd->lcd_rs),HIGH);
        for( i = 0 ; i < 8 ; i++)
        {
            RET_VAL = gpio_pin_write_logic(&(lcd->lcd_data[i]),((data >> i)&1) );
        }
        RET_VAL = lcd_8bit_send_enable_signal(lcd);
    }
    return RET_VAL ;

}

std_ReturnType lcd_8bit_send_data_pos(const lcd_8bit_t *lcd , char row , char column ,char data ){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = lcd_8bit_set_cursor(lcd ,row , column );
        RET_VAL = lcd_8bit_send_data(lcd ,data);
    }
    return RET_VAL ;

}

std_ReturnType lcd_8bit_send_string(const lcd_8bit_t *lcd , char
                                     *str ){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{
        while(*str){
            RET_VAL = lcd_8bit_send_data(lcd , *str );
            str++;
        }
    }
    return RET_VAL ;

}

std_ReturnType lcd_8bit_send_string_pos(const lcd_8bit_t *lcd , char row , char column , char *str ){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = lcd_8bit_set_cursor(lcd ,row, column );
        while(*str){
            RET_VAL = lcd_8bit_send_data(lcd , *str );
            str++;
        }
    }
    return RET_VAL ;

}

std_ReturnType lcd_8bit_send_custom_char(const lcd_8bit_t *lcd , char row , char column ,char _char[] , char mem_pos ){
    std_ReturnType RET_VAL = E_NOK ;
    char lcd_counter = 0 ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = lcd_8bit_send_command( lcd , (LCD_CGRAM_START + mem_pos*8));
        for(lcd_counter= 0 ; lcd_counter <=7 ;lcd_counter++){
            RET_VAL = lcd_8bit_send_data(lcd ,_char[lcd_counter] );
        }
        RET_VAL = lcd_8bit_send_data_pos(lcd ,row , column ,mem_pos );
    }
    return RET_VAL ;

}


/*                                                 helper functions                                */

std_ReturnType convert_byte_to_string(char value , char *str){
    uint8_t Temp_string[4] = {0} ;
    std_ReturnType RET_VAL = E_NOK ;
    uint8_t Data_counter = 0 ;
    if(NULL == str)
    {
        RET_VAL = E_NOK ;
    }else{
        memset( str , ' ' , 3 );
        str[3] = '\0' ;
        sprintf( (char *)Temp_string , "%i" , value);
        while(Temp_string[Data_counter] != '\0'){
            str[Data_counter] = Temp_string[Data_counter] ;
            Data_counter++ ;
        }
        RET_VAL = E_OK ;
    }

    return RET_VAL ;
}

std_ReturnType convert_short_to_string(short value , char *str){
    uint8_t Temp_string[6] = {0} ;
    std_ReturnType RET_VAL = E_NOK ;
    uint8_t Data_counter = 0 ;
    if(NULL == str)
    {
        RET_VAL = E_NOK ;
    }else{
        memset( str , ' ' , 5 );
        str[5] = '\0' ;
        sprintf( (char *)Temp_string , "%i" , value);
        while(Temp_string[Data_counter] != '\0'){
            str[Data_counter] = Temp_string[Data_counter] ;
            Data_counter++ ;
        }
        RET_VAL = E_OK ;
    }

    return RET_VAL ;

}

std_ReturnType convert_int_to_string(int value , char *str){
    uint8_t Temp_string[11] = {0} ;
    std_ReturnType RET_VAL = E_NOK ;
    uint8_t Data_counter = 0 ;
    if(NULL == str)
    {
        RET_VAL = E_NOK ;
    }else{
        memset( str , ' ' , 10 );
        str[10] = '\0' ;
        sprintf( (char *)Temp_string , "%i" , value);
        while(Temp_string[Data_counter] != '\0'){
            str[Data_counter] = Temp_string[Data_counter] ;
            Data_counter++ ;
        }
        RET_VAL = E_OK ;
    }

    return RET_VAL ;
}

std_ReturnType lcd_send_4bits(const lcd_4bit_t *lcd , char _data_command){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{
        for(int i = 0 ; i < 4 ; i++)
        {
            RET_VAL = gpio_pin_write_logic(&(lcd->lcd_data[i]),(_data_command >> i) & 1);
        }
    }

    return RET_VAL ;
}

std_ReturnType lcd_4bit_send_enable_signal(const lcd_4bit_t *lcd ){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = gpio_pin_write_logic(&(lcd->lcd_en) , HIGH);
        __delay_us(5);                                          // enable signal ( pulse )
        RET_VAL = gpio_pin_write_logic(&(lcd->lcd_en) , LOW);
    }
    return RET_VAL ;
}

std_ReturnType lcd_8bit_send_enable_signal(const lcd_8bit_t *lcd ){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == lcd)
    {
        RET_VAL = E_NOK ;
    }else{
        RET_VAL = gpio_pin_write_logic(&(lcd->lcd_en) , HIGH);
        __delay_us(5);                                          // enable signal ( pulse )
        RET_VAL = gpio_pin_write_logic(&(lcd->lcd_en) , LOW);
    }
    return RET_VAL ;
}

std_ReturnType lcd_8bit_set_cursor(const lcd_8bit_t *lcd , char row , char column){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == lcd )
    {
        RET_VAL = E_NOK ;
    }else{
        column--;
        switch(row){
            case ROW1 : RET_VAL = lcd_8bit_send_command(lcd , (0x80 + column));    break ;
            case ROW2 : RET_VAL = lcd_8bit_send_command(lcd , (0xC0 + column));    break ;
            case ROW3 : RET_VAL = lcd_8bit_send_command(lcd , (0x94 + column));    break ;
            case ROW4 : RET_VAL = lcd_8bit_send_command(lcd , (0xD4 + column));    break ;
            default : ;
        }

        RET_VAL = E_OK ;
    }
    return RET_VAL ;

}

std_ReturnType lcd_4bit_set_cursor(const lcd_4bit_t *lcd , char row , char column){
    std_ReturnType RET_VAL = E_NOK ;
    if(NULL == lcd )
    {
        RET_VAL = E_NOK ;
    }else{
        column--;
        switch(row){
            case ROW1 : RET_VAL = lcd_4bit_send_command(lcd , (0x80 + column));    break ;
            case ROW2 : RET_VAL = lcd_4bit_send_command(lcd , (0xC0 + column));    break ;
            case ROW3 : RET_VAL = lcd_4bit_send_command(lcd , (0x94 + column));    break ;
            case ROW4 : RET_VAL = lcd_4bit_send_command(lcd , (0xD4 + column));    break ;
            default : ;
        }

        RET_VAL = E_OK ;
    }
    return RET_VAL ;

}
