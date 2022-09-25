/*
 * File:   application.c
 * Author: ahmed Odb
 *
 * Created on September 16, 2022, 7:48 PM
 */

#include"application.h"

#include "application.h"
#include "MCAL/EUSART/mcal_EUSART.h"

uart_config_st uart = {
  .baud_rate_config = BAUDRATE_ASYNC_8BIT_LOW_SPEED ,
  .uart_baud_rate_reg_value = 223 ,
  .tx_config.tx_9th_bit_en = EUSART_ASYNCH_Tx_BIT_9_DISABLED ,
  .tx_config.tx_enable = EUSART_ASYNCH_TX_EN ,
  .rx_config.rx_9th_bit_en = EUSART_ASYNCH_Tx_BIT_9_DISABLED ,
  .rx_config.rx_enable = EUSART_ASYNCH_RX_EN 
};


uint16_t data = 0 ;

int main()
{
    application_intialize();

     while(1)
     {
         
         EUSART_Async_Transmit_Data(&uart , 'A');         
         EUSART_Async_Read_Data(&uart , &data );
         
     }    
    return 0;

}
void application_intialize(void)
{
    EUSART_Async_Init(&uart);
    
}