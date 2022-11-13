/* 
 * File:   ecu_char_lcd.h
 * Author: ahmed radwan
 *
 * Created on July 24, 2022, 4:30 AM
 */

#ifndef ECU_CHAR_LCD_H
#define	ECU_CHAR_LCD_H

/*include section*/
#include"../../MCAL/GPIO/hal_gpio.h"
#include"ecu_char_lcd_cnfg.h"
/*macros declarations section*/

// THIS DEFINE BASED ON THE INSTRUCTIONS OF LCD IN THE DATA SHEET

#define LCD_CLEAR_DISPLAY                           0X01
#define LCD_CURSOR_HOME                             0X02
#define LCD_ENTRY_MODE_DECREMENT_SHIFT_OFF          0X04
#define LCD_ENTRY_MODE_DECREMENT_SHIFT_ON           0X05
#define LCD_ENTRY_MODE_INCREMENT_SHIFT_OFF          0X06
#define LCD_ENTRY_MODE_INCREMENT_SHIFT_ON           0X07

#define LCD_DISPLAY_OFF                             0X08
#define LCD_DISPLAY_ON_UNDR_LINE_OFF_CURSOR_OFF     0X0C
#define LCD_DISPLAY_ON_UNDR_LINE_OFF_CURSOR_ON      0X0D
#define LCD_DISPLAY_ON_UNDR_LINE_ON_CURSOR_OFF      0X0E
#define LCD_DISPLAY_ON_UNDR_LINE_ON_CURSOR_ON       0X0F

#define LCD_CURSOR_MOVE_SHIFT_LEFT                  0X10
#define LCD_CURSOR_MOVE_SHIFT_RIGHT                 0X14
#define LCD_DISPLAY_SHIFT_LEFT                      0X18
#define LCD_DISPLAY_SHIFT_RIGHT                     0X1C

#define LCD_8BIT_MODE_2LINE_5_8                     0X38
#define LCD_4BIT_MODE_2LINE_5_8                     0X28


#define LCD_CGRAM_START_ADDRESS                     0X40
#define LCD_DDRAM_START_ADDRESS                     0X80

#define ROW1 1
#define ROW2 2
#define ROW3 3 
#define ROW4 4

#define LCD_2ROWS_FIRST_ROW_ADDREESS                0x80
#define LCD_2ROWS_SECOND_ROW_ADDREESS               0xC0

#define LCD_4ROWS_FIRST_ROW_ADDREESS                0x80
#define LCD_4ROWS_SECOND_ROW_ADDREESS               0xC0
#define LCD_4ROWS_THIRD_ROW_ADDREESS                0x94
#define LCD_4ROWS_FOURTH_ROW_ADDREESS               0xD4


/*data types  section*/

typedef struct{
    pin_config_st lcd_rs_pin;
    pin_config_st lcd_enable_pin;
    pin_config_st lcd_data_pins[4];
}char_lcd_4bit_t;

typedef struct{
    pin_config_st lcd_rs_pin;
    pin_config_st lcd_enable_pin;
    pin_config_st lcd_data_pins[8];
}char_lcd_8bit_t;

/*function declarations section*/
Std_ReturnType lcd_4bit_initialize(const char_lcd_4bit_t *lcd);
Std_ReturnType lcd_4bit_send_command(const char_lcd_4bit_t *lcd,uint8 command);

Std_ReturnType lcd_4bit_send_char_data(const char_lcd_4bit_t *lcd,uint8 data);
Std_ReturnType lcd_4bit_send_char_data_pos(const char_lcd_4bit_t *lcd,uint8 rows,uint8 colums,uint8 data);

Std_ReturnType lcd_4bit_send_string_data(const char_lcd_4bit_t *lcd,uint8* str);
Std_ReturnType lcd_4bit_send_string_data_pos(const char_lcd_4bit_t *lcd,uint8 rows,uint8 colums,uint8* str);

Std_ReturnType lcd_4bit_send_custom_char(const char_lcd_4bit_t *lcd,uint8 rows,uint8 colums,const uint8 _char[],uint8 pos);//why arr



/// 8bit lcd 

Std_ReturnType lcd_8bit_initialize(const char_lcd_8bit_t *lcd);
Std_ReturnType lcd_8bit_send_command(const char_lcd_8bit_t *lcd,uint8 command);

Std_ReturnType lcd_8bit_send_char_data(const char_lcd_8bit_t *lcd,uint8 data);
Std_ReturnType lcd_8bit_send_char_data_pos(const char_lcd_8bit_t *lcd,uint8 rows,uint8 colums,uint8 data);

Std_ReturnType lcd_8bit_send_string_data(const char_lcd_8bit_t *lcd,uint8* str);
Std_ReturnType lcd_8bit_send_string_data_pos(const char_lcd_8bit_t *lcd,uint8 rows,uint8 colums,uint8* str);

Std_ReturnType lcd_8bit_send_custom_char(const char_lcd_8bit_t *lcd,uint8 rows,uint8 colums,const uint8 _char[],uint8 pos);//why arr


Std_ReturnType convert_uint8_to_string(uint8 value,uint8*str);
Std_ReturnType convert_uint16_to_string(uint16 value,uint8*str);
Std_ReturnType convert_uint32_to_string(uint32 value,uint8*str);
Std_ReturnType convert_float32_to_string(float32 value,uint8*str);



#endif	/* ECU_CHAR_LCD_H */

