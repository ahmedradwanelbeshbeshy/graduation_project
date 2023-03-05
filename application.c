/*
 * File:   application.c
 * Author: spatial team members 
 *
 * Created on September 16, 2022, 7:48 PM
 */



#include "application.h"
#include "ECU/LCD_for_test_gps/ecu_char_lcd.h"
#include"Robot/sensors/ultrasonic/ultrasonic.h"

char_lcd_4bit_t lcd1=
{
    .lcd_rs_pin.port=PORTD_INDEX,
    .lcd_rs_pin.pin=GPIO_PIN0,
    .lcd_rs_pin.direction=GPIO_DIRECTION_OUTPUT,
    .lcd_rs_pin.logic=GPIO_LOW,
    
    .lcd_enable_pin.port=PORTD_INDEX,
    .lcd_enable_pin.pin=GPIO_PIN1,
    .lcd_enable_pin.direction=GPIO_DIRECTION_OUTPUT,
    .lcd_enable_pin.logic=GPIO_LOW,    
    
    .lcd_data_pins[0].port=PORTD_INDEX,
    .lcd_data_pins[0].pin=GPIO_PIN2,
    .lcd_data_pins[0].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_data_pins[0].logic=GPIO_LOW, 
    
    .lcd_data_pins[1].port=PORTD_INDEX,
    .lcd_data_pins[1].pin=GPIO_PIN3,
    .lcd_data_pins[1].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_data_pins[1].logic=GPIO_LOW, 
    
    .lcd_data_pins[2].port=PORTD_INDEX,
    .lcd_data_pins[2].pin=GPIO_PIN4,
    .lcd_data_pins[2].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_data_pins[2].logic=GPIO_LOW, 
    
    .lcd_data_pins[3].port=PORTD_INDEX,
    .lcd_data_pins[3].pin=GPIO_PIN5,
    .lcd_data_pins[3].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_data_pins[3].logic=GPIO_LOW
    
};

pin_config_st pinc0={
   .direction=GPIO_DIRECTION_OUTPUT,
   .logic=GPIO_HIGH,
   .pin=GPIO_PIN0,
   .port=PORTC_INDEX 
};

int main()
{   
    application_intialize();
    lcd_4bit_send_string_data_pos(&lcd1,1,1,"              ");
    lcd_4bit_send_string_data_pos(&lcd1,2,1,"              ");
    lcd_4bit_send_string_data_pos(&lcd1,2,1,"-> ");
    GPIO_Pin_Write_Logic(&pinc0,GPIO_HIGH);
    __delay_ms(1000);
   while(1)
    {
       GPIO_Pin_Toggle_Logic(&pinc0);
           __delay_ms(500);
   }
   return 0;
}
void application_intialize(void)
{
    GPIO_Pin_Initialize(&pinc0);
    lcd_4bit_initialize(&lcd1);
} 
