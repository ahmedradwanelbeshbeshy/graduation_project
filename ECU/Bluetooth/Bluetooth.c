/* 
 * File:   Bluetooth.h
 * Author: Ahmed
 *
 * Created on September 26, 2022, 7:22 AM
 */

#include "Bluetooth.h"



/**
 * send the intialze parameters of bluetooth module
 * @param _uart_obj
 * @return 
 */
Std_ReturnType Bluetooth_Init(uart_config_st *_uart_obj)
{
    //set the uart baud rate to be  38400
    _uart_obj->uart_baud_rate_value = 38400;
    EUSART_Async_Init(_uart_obj);
    
    //send the bluetooth channel name
    EUSART_Async_Transmit_Data_String_Blocking(_uart_obj ,BLUETOOTH_CHANNEL_NAME, BLUETOOTH_CHANNEL_NAME_NO_OF_CHAR );
    //send the bluetooth module role as slave
    EUSART_Async_Transmit_Data_String_Blocking(_uart_obj ,BLUETOOTH_CHANNEL_ROLE, BLUETOOTH_CHANNEL_ROLE_NO_OF_CHAR );
    //send the bluetooth module pin
    EUSART_Async_Transmit_Data_String_Blocking(_uart_obj ,BLUETOOTH_CHANNEL_PASS,BLUETOOTH_CHANNEL_PASS_NO_OF_CHAR);
    //send the bluetooth modulebaud rate
    EUSART_Async_Transmit_Data_String_Blocking(_uart_obj ,BLUETOOTH_CHANNEL_BAUD_RATE,BLUETOOTH_CHANNEL_BAUD_RATE_NO_OF_CHAR); 
    
    //set the uart baud rate to the requred value
    _uart_obj->uart_baud_rate_value = 9600;
    //reintialize the uart module
    EUSART_Async_Init(_uart_obj);

}

Std_ReturnType Bluetooth_Send_Data_Blocking(const uart_config_st *_uart_obj , uint8_t data)
{
    Std_ReturnType ret_val = E_OK ;
    
    if((NULL ==_uart_obj ))
    {
        ret_val = E_NOT_OK ;
    }
    else 
    {
        EUSART_Async_Transmit_Data_Blocking(_uart_obj , data);
    }
    
    return ret_val ;
}
Std_ReturnType Bluetooth_Recieve_Data_Blocking(const uart_config_st *_uart_obj , uint8_t *data )
{
    
    Std_ReturnType ret_val = E_OK ;
    
    if((NULL ==_uart_obj )|| (NULL == data) )
    {
        ret_val = E_NOT_OK ;
    }
    else 
    {
        EUSART_Async_Read_Data_Blocking(_uart_obj , data);
    }
    
    return ret_val ;  
}

Std_ReturnType Bluetooth_Send_Data_Non_Blocking(const uart_config_st *_uart_obj , uint8_t data )
{
    
    Std_ReturnType ret_val = E_OK ;
    
    if((NULL ==_uart_obj ) )
    {
        ret_val = E_NOT_OK ;
    }
    else 
    {
        EUSART_Async_Transmit_Data(_uart_obj , data);
    }
    
    return ret_val ;
    
}
Std_ReturnType Bluetooth_Recieve_Data_Non_Blocking(const uart_config_st *_uart_obj , uint8_t *data )
{
    
    Std_ReturnType ret_val = E_OK ;
    
    if((NULL ==_uart_obj ) || (NULL == data))
    {
        ret_val = E_NOT_OK ;
    }
    else 
    {
        EUSART_Async_Read_Data(_uart_obj , data);
    }
    
    return ret_val ;
    
}

Std_ReturnType Bluetooth_Send_String_Blocking(const uart_config_st *_uart_obj , uint8_t *data , uint8_t length )
{
    Std_ReturnType ret_val = E_OK ;
    
    if((NULL ==_uart_obj ) || (NULL == data))
    {
        ret_val = E_NOT_OK ;
    }
    else 
    {
        EUSART_Async_Transmit_Data_String_Blocking(_uart_obj , data , length );
    }
    
        return ret_val ;

}
