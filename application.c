/*
 * File:   application.c
 * Author: ahmed Odb
 *
 * Created on September 16, 2022, 7:48 PM
 */



#include "application.h"
#include "MCAL/EUSART/mcal_EUSART.h"
#include "ECU/Bluetooth/Bluetooth.h"


void bluetooth_isr(void);

uart_config_st _uart_obj = {
  .baud_rate_config = BAUDRATE_ASYNC_8BIT_LOW_SPEED ,
  .uart_baud_rate_value =38400,
  .tx_config.tx_9th_bit_en = EUSART_ASYNCH_Tx_BIT_9_DISABLED ,
  .tx_config.tx_enable = EUSART_ASYNCH_TX_EN ,
  .tx_config.uart_tx_priority = INT_HIGH_PRI ,
  .rx_config.rx_9th_bit_en = EUSART_ASYNCH_Tx_BIT_9_DISABLED ,
  .rx_config.rx_enable = EUSART_ASYNCH_RX_EN,
  .rx_config.uart_rx_priority=INT_PRI_HIGH,
  .rx_config.rx_InterruptHandler=bluetooth_isr
 
};
pin_config_st pind2={
   .direction=GPIO_DIRECTION_OUTPUT,
   .logic=GPIO_LOW,
   .pin=GPIO_PIN2,
   .port=PORTD_INDEX 
};
pin_config_st pind1={
   .direction=GPIO_DIRECTION_OUTPUT,
   .logic=GPIO_LOW,
   .pin=GPIO_PIN1,
   .port=PORTD_INDEX 
};

uint8 counter = 0 ;
uint8 data = 0 ;


int main()
{   
application_intialize();
Bluetooth_Init(&_uart_obj);
     while(1)
     {
         GPIO_Pin_Toggle_Logic(&pind1);
         __delay_ms(500);
     }    
    return 0;

}
void application_intialize(void)
{

    GPIO_Pin_Initialize(&pind1);
    GPIO_Pin_Initialize(&pind2);
    //EUSART_Async_Init(&_uart_obj);
}
void bluetooth_isr(void)
{
  counter++;
  GPIO_Pin_Toggle_Logic(&pind2);
   EUSART_Async_Read_Data(&_uart_obj , &data );
   EUSART_Async_Transmit_Data(&_uart_obj , 'w'); 
}

