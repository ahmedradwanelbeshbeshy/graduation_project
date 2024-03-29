/*
 * File:   application.c
 * Author: ahmed Odb
 *
 * Created on September 16, 2022, 7:48 PM
 */



#include "application.h"
#include "MCAL/EUSART/mcal_EUSART.h"
#include "ECU/Bluetooth/Bluetooth.h"
#include "ECU/LCD_for_test_gps/ecu_char_lcd.h"
#include"MCAL/WATCH_DOG_TIMER/WDT.h"
#include "MCAL/ADC/mcal_adc.h"
/*****************************************************************************************************************/
/***********************note the crystal OSC has been changed to be 24MHZ in device_config.h**********************/
/*****************************************************************************************************************/

void  usart_isr (void);
void GPS_Service (void);
void battery_level(void);
uint8 datasend='w';
uint8 datarecive=0;
uint8 gps=1;
uint8 blue=1;
uint8 i=0;
uint8 latitude[13];
uint8 longtude[13];
uint8 gpstemp=0;
uint8 counter;
uint8 battery_string[9];
float32 battery_volt_f;
uart_config_st _uart_obj = {
  .baud_rate_config = BAUDRATE_ASYNC_8BIT_LOW_SPEED ,
  .uart_baud_rate_value =9600,
  .tx_config.tx_9th_bit_en = EUSART_ASYNCH_Tx_BIT_9_DISABLED ,
  .tx_config.tx_enable = EUSART_ASYNCH_TX_EN ,
  //.tx_config.uart_tx_priority = INT_HIGH_PRI ,
  .rx_config.rx_9th_bit_en = EUSART_ASYNCH_Tx_BIT_9_DISABLED ,
  .rx_config.rx_enable = EUSART_ASYNCH_RX_EN,
  .rx_config.uart_rx_priority=INT_PRI_HIGH,
  .rx_config.rx_InterruptHandler=usart_isr
 
};
char_lcd_4bit_t lcd1=
{
    .lcd_rs_pin.port=PORTC_INDEX,
    .lcd_rs_pin.pin=GPIO_PIN0,
    .lcd_rs_pin.direction=GPIO_DIRECTION_OUTPUT,
    .lcd_rs_pin.logic=GPIO_LOW,
    
    .lcd_enable_pin.port=PORTC_INDEX,
    .lcd_enable_pin.pin=GPIO_PIN1,
    .lcd_enable_pin.direction=GPIO_DIRECTION_OUTPUT,
    .lcd_enable_pin.logic=GPIO_LOW,    
    
    .lcd_data_pins[0].port=PORTC_INDEX,
    .lcd_data_pins[0].pin=GPIO_PIN2,
    .lcd_data_pins[0].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_data_pins[0].logic=GPIO_LOW, 
    
    .lcd_data_pins[1].port=PORTC_INDEX,
    .lcd_data_pins[1].pin=GPIO_PIN3,
    .lcd_data_pins[1].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_data_pins[1].logic=GPIO_LOW, 
    
    .lcd_data_pins[2].port=PORTC_INDEX,
    .lcd_data_pins[2].pin=GPIO_PIN4,
    .lcd_data_pins[2].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_data_pins[2].logic=GPIO_LOW, 
    
    .lcd_data_pins[3].port=PORTC_INDEX,
    .lcd_data_pins[3].pin=GPIO_PIN5,
    .lcd_data_pins[3].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_data_pins[3].logic=GPIO_LOW, 
    
};
pin_config_st pind2={
   .direction=GPIO_DIRECTION_OUTPUT,
   .logic=GPIO_LOW,
   .pin=GPIO_PIN2,
   .port=PORTD_INDEX 
};
pin_config_st pind1={
   .direction=GPIO_DIRECTION_OUTPUT,
   .logic=GPIO_HIGH,
   .pin=GPIO_PIN1,
   .port=PORTD_INDEX 
};
pin_config_st pind0={
   .direction=GPIO_DIRECTION_OUTPUT,
   .logic=GPIO_HIGH,
   .pin=GPIO_PIN0,
   .port=PORTD_INDEX 
};

pin_config_st selector={
   .direction=GPIO_DIRECTION_OUTPUT,
   .logic=GPIO_LOW,
   .pin=GPIO_PIN0,
   .port=PORTB_INDEX 
};
adc_result_t battery_volt_adc_read;
adc_config_st battery_adc={
    .adc_channel=ADC_CHANEL_AN0,
    .conversion_clock=ADC_CONVERSION_CLOCK_FOSC_DIV_32,
    .acquisition_time=ADC_12_TAD,
    .result_format=ADC_RESULT_RIGHT,
    .voltage_referance=ADC_VOLTAGE_REFERANCE_INTERNAL
};
int main()
{   
    
    application_intialize();
    GPIO_Pin_Toggle_Logic(&pind2);
    lcd_4bit_send_string_data_pos(&lcd1,1,1,"battery: ");    
   while(1)
    {
        GPIO_Pin_Toggle_Logic(&pind1);
        battery_level();
        __delay_ms(1000);
        
        
        
   }
   return 0;
}
void application_intialize(void)
{
    GPIO_Pin_Initialize(&pind0);
    GPIO_Pin_Initialize(&pind1);
    GPIO_Pin_Initialize(&pind2);
    GPIO_Pin_Initialize(&selector);
    EUSART_Async_Init(&_uart_obj);
    lcd_4bit_initialize(&lcd1);
    ADC_Init(&battery_adc);
}
void usart_isr (void)
{
    EUSART_Async_Read_Data(&_uart_obj,&datarecive);
    Bluetooth_Send_Data_Non_Blocking(&_uart_obj,datasend);
    lcd_4bit_send_char_data_pos(&lcd1,2,4,datarecive);
    GPIO_Pin_Toggle_Logic(&pind2);
}
void GPS_Service (void)
{
    uint8 key=1;
    INT_EUSART_Rx_DISABLE();//disable rx interrupt 
    GPIO_Pin_Write_Logic(&selector,GPIO_HIGH);

    while (key)
    {
        EUSART_Async_Read_Data_Blocking(&_uart_obj,&gpstemp); // wait untill recive
        if ('$'==gpstemp)
        {
            while (key)
            {
                    EUSART_Async_Read_Data_Blocking(&_uart_obj,&gpstemp); // wait untill recive
                    if (','==gpstemp)
                    {
                        counter++;
                        if (3==counter)
                        {
                            i=0;
                            //lattitude
                            do
                            {
                                EUSART_Async_Read_Data_Blocking(&_uart_obj,(latitude+i));
                                i++;
                            }while(','!=(latitude[i-1]));
                            counter++;

                        }
                        else if(5==counter)
                        {
                            i=0;
                            //longtude
                            do{
                                EUSART_Async_Read_Data_Blocking(&_uart_obj,(longtude+i));
                                i++;
                            }while(','!=(longtude[i-1]));
                            key=0;
                        }
                    }
            }
        }
    }
    lcd_4bit_send_string_data_pos(&lcd1,1,1,"-             ");
    lcd_4bit_send_string_data_pos(&lcd1,2,1,"-             ");
    lcd_4bit_send_string_data_pos(&lcd1,1,1,latitude);
    lcd_4bit_send_string_data_pos(&lcd1,2,1,longtude);
        __delay_ms(2000);
    GPIO_Pin_Write_Logic(&selector,GPIO_LOW);
    INT_EUSART_Rx_ENABLE() ;//rx interruptenable
}
void battery_level(void)
{
        ADC_Get_Conversion_Blocking(&battery_adc,ADC_CHANEL_AN0,&battery_volt_adc_read);
        battery_volt_f=(float32)(battery_volt_adc_read*13)/1024;//13 get from 5*2.6->->-2.6=(r1+r2)/r2
        convert_float32_to_string( battery_volt_f,battery_string);
        
        lcd_4bit_send_string_data_pos(&lcd1,1,9,"       ");
        lcd_4bit_send_string_data_pos(&lcd1,1,10,battery_string);
        if(battery_volt_f<11.1)
        {
           lcd_4bit_send_string_data_pos(&lcd1,2,0,"                "); 
           lcd_4bit_send_string_data_pos(&lcd1,2,3,"battery low");
           GPIO_Pin_Write_Logic(&pind0,GPIO_HIGH);
        }
        else
        { 
            lcd_4bit_send_string_data_pos(&lcd1,2,0,"                "); 
            GPIO_Pin_Write_Logic(&pind0,GPIO_LOW);
        } 
}