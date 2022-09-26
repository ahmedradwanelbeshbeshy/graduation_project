/* 
 * File:   Bluetooth.h
 * Author: Ahmed
 *
 * Created on September 26, 2022, 7:22 AM
 */

#ifndef BLUETOOTH_H
#define	BLUETOOTH_H



/******************************************** Includes ********************************************/
#include "../../MCAL/EUSART/mcal_EUSART.h"


/******************************************** Macro Defines ***************************************************************/



/******************************************** Macro Functions *************************************************************/


/******************************************** User-Defined Data Type Declaration ********************************************/


/******************************************** Software Interfaces (Prototypes) ********************************************/

Std_ReturnType Bluetooth_Init(const uart_config_st *_uart_obj);

Std_ReturnType Bluetooth_Send_Data_Blocking(const uart_config_st *_uart_obj , uint8_t data);
Std_ReturnType Bluetooth_Recieve_Data_Blocking(const uart_config_st *_uart_obj , uint8_t *data );

Std_ReturnType Bluetooth_Send_Data_Non_Blocking(const uart_config_st *_uart_obj , uint8_t data );
Std_ReturnType Bluetooth_Recieve_Data_Non_Blocking(const uart_config_st *_uart_obj , uint8_t *data );



#endif	/* BLUETOOTH_H */

