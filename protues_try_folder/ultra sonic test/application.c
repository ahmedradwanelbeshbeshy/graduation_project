/*
 * File:   application.c
 * Author: ahmed Odb
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

 /************************************ultra sonic**********************************/
float32 distance;
uint8 dis[10]={};// needed to display the result on the lcd

 ultrasonic_config_st ultrasonic={
     .trig_pin.direction=GPIO_DIRECTION_OUTPUT,
     .trig_pin.logic=GPIO_LOW,
     .trig_pin.pin=GPIO_PIN1,
     .trig_pin.port=PORTB_INDEX, 
     
     .echo_pin.direction=GPIO_DIRECTION_INPUT,
     .echo_pin.logic=GPIO_LOW,
     .echo_pin.pin=GPIO_PIN0,
     .echo_pin.port=PORTB_INDEX       
 };
 timer0_config_st timer0={
   .preloaded_value=0,
   .prescaler_enable=TMR0_PRESCALER_ON,
   .prescalar_value=TMR0_PRESCALER_BY_2,
   .reg_bit_size=TMR0_16BIT,
   .timer_mode=TMR0_TIMER_MODE
 };
 /************************************ultra sonic end**********************************/

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
       Get_Distance(&ultrasonic,&timer0,&distance);
       convert_float32_to_string(distance,dis);
       lcd_4bit_send_string_data_pos(&lcd1,2,1,"             ");
       lcd_4bit_send_string_data_pos(&lcd1,2,1,dis);
       __delay_ms(2000);
       lcd_4bit_send_string_data_pos(&lcd1,2,1,"              ");
   }
   return 0;
}
void application_intialize(void)
{
    GPIO_Pin_Initialize(&pinc0);
    lcd_4bit_initialize(&lcd1);
   Ultra_Sonic_Init(&ultrasonic,&timer0);
}
