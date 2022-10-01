/*
 * File:   application.c
 * Author: ahmed Odb
 *
 * Created on September 16, 2022, 7:48 PM
 */

#include"application.h"

#include "application.h"
#include "MCAL/EUSART/mcal_EUSART.h"
void bluetooth_isr(void);

uart_config_st uart = {
  .baud_rate_config = BAUDRATE_ASYNC_8BIT_LOW_SPEED ,
  .uart_baud_rate_value =9600,
  .tx_config.tx_9th_bit_en = EUSART_ASYNCH_Tx_BIT_9_DISABLED ,
  .tx_config.tx_enable = EUSART_ASYNCH_TX_EN ,
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

uint8 counter = 0 ;
uint8 data = 0 ;


int main()
{
    application_intialize();
     while(1)
     {
         
         __delay_ms(500);
         EUSART_Async_Transmit_Data_String_Blocking(&uart,"ahmed\r\n",6);
//         EUSART_Async_Transmit_Data(&uart , 'A');         
//        __delay_ms(500);
//         
     }    
    return 0;

}
void application_intialize(void)
{
     GPIO_Pin_Initialize(&pind2);
    EUSART_Async_Init(&uart);
}
void bluetooth_isr(void)
{
  counter++;
  GPIO_Pin_Toggle_Logic(&pind2);
   EUSART_Async_Read_Data(&uart , &data );
   EUSART_Async_Transmit_Data(&uart , 'w'); 
}