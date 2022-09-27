/*
 * File:   application.c
 * Author: ahmed Odb
 *
 * Created on September 16, 2022, 7:48 PM
 */



#include "application.h"
#include "MCAL/EUSART/mcal_EUSART.h"
#include "ECU/Bluetooth/Bluetooth.h"

void Rx_ISR(void);

uart_config_st Uart = {
  .baud_rate_config = BAUDRATE_ASYNC_8BIT_LOW_SPEED ,
  .uart_baud_rate_value =38400,
  .tx_config.tx_9th_bit_en = EUSART_ASYNCH_Tx_BIT_9_DISABLED ,
  .tx_config.tx_enable = EUSART_ASYNCH_TX_EN ,
  .tx_config.uart_tx_priority = INT_HIGH_PRI ,
  .rx_config.rx_9th_bit_en = EUSART_ASYNCH_Tx_BIT_9_DISABLED ,
  .rx_config.rx_enable = EUSART_ASYNCH_RX_EN,
  .rx_config.rx_InterruptHandler = Rx_ISR,
  .rx_config.uart_rx_priority = INT_HIGH_PRI
};

pin_config_st PIO11_Pin =
{
    .port = PORTC_INDEX ,
    .pin = GPIO_PIN0 ,
    .logic = GPIO_HIGH ,
    .direction = GPIO_DIRECTION_OUTPUT
};

pin_config_st Led_Down =
{
    .port = PORTC_INDEX ,
    .pin = GPIO_PIN1 ,
    .logic = GPIO_LOW ,
    .direction = GPIO_DIRECTION_OUTPUT
};

pin_config_st Led_Up =
{
    .port = PORTC_INDEX ,
    .pin = GPIO_PIN2 ,
    .logic = GPIO_LOW ,
    .direction = GPIO_DIRECTION_OUTPUT
};



Flags_st Up_Down_flags =
{
  .flag_0 = 0 ,     /* Up flag */
  .flag_1 = 0       /* Down flag */
};

uint8 data = 0 ;

int main()
{
    application_intialize();
    /* bluetooth init */
    
    Bluetooth_Send_String_Blocking(&Uart , "AT+RNAME:Ahmed\r\n" , 16 );
    Bluetooth_Send_String_Blocking(&Uart , "AT+ROLE:0\r\n" , 11 );
    Bluetooth_Send_String_Blocking(&Uart , "AT+PSWD:1234\r\n" , 14);
    Bluetooth_Send_String_Blocking(&Uart , "AT+UART:9600,0,0\r\n" , 18 );
    
    /* Turn Data mode on and change baud rate */
    GPIO_Pin_Toggle_Logic(&PIO11_Pin);
    Uart.uart_baud_rate_value = 9600 ;
    EUSART_Async_Init(&Uart);


     while(1)
     {
         
    if(1 == Up_Down_flags.flag_0)
    {
        GPIO_Pin_Toggle_Logic(&Led_Up);
        Up_Down_flags.flag_0 = 0 ;
    }
    else if(1 == Up_Down_flags.flag_1)
    {
        GPIO_Pin_Toggle_Logic(&Led_Down);
        Up_Down_flags.flag_1 = 0 ;


    }
    else {}
           
    }    
    return 0;

}
void application_intialize(void)
{
    EUSART_Async_Init(&Uart);
    GPIO_Pin_Initialize(&PIO11_Pin);
    GPIO_Pin_Initialize(&Led_Down);
    GPIO_Pin_Initialize(&Led_Up);

}

void Rx_ISR(void)
{
    EUSART_Async_Read_Data(&Uart , &data );
    if('u'== data)
    {
        Up_Down_flags.flag_0 = 1 ;
    }
    else if('d' == data)
    {
        Up_Down_flags.flag_1 = 1 ;

    }
    else {}
}

