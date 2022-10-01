/* 
 * File:   Bluetooth.h
 * Author: Ahmed
 *
 * Created on September 26, 2022, 7:22 AM
 */

#include "Bluetooth.h"




Std_ReturnType Bluetooth_Init()
{

    
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
