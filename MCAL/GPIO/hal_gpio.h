/* 
 * File:   hal_gpio.h
 * Author: ahmed radwan
 *
 * Created on June 28, 2022, 4:24 AM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/********************************include section********************************/
#include"../std_libraries.h"
#include"../device_config.h"
#include "../mcal_std_types.h"
#include "hal_gpio_cfg.h"

/********************************macros declarations section********************************/

#define BIT_MASK (uint8)1
#define PORTMASK  (uint8)0xff

#define PORT_PIN_MAX_NUMBER 8
#define PORT_MAX_NUMBER 5

#define GPIO_PORT_PIN_CONFIGURATION CONFIG_ENABLE
#define GPIO_PORT_CONFIGURATION     CONFIG_ENABLE


#define HWREG8   (_x) (*((volatile uint8 *)(_x)))


#define SET_BIT(REG,BIT_POSN)              (REG|=( BIT_MASK<<BIT_POSN ))
#define CLEAR_BIT(REG,BIT_POSN)            (REG&=~( BIT_MASK<<BIT_POSN ))
#define TOGGLE_BIT(REG,BIT_POSN)           (REG^=( BIT_MASK<<BIT_POSN ))
#define READ_BIT(REG,BIT_POSN)             (( REG>>BIT_POSN )&BIT_MASK)




/********************************data types  section********************************/

typedef enum{
   GPIO_LOW=0,
   GPIO_HIGH        
}logic_et;

typedef enum{
   GPIO_DIRECTION_OUTPUT=0,
   GPIO_DIRECTION_INPUT        
}direction_et;

typedef enum{
    GPIO_PIN0=0,
    GPIO_PIN1,  
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7        
}pin_index_et;

typedef enum{
    PORTA_INDEX=0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX, 
    PORTE_INDEX
}port_index_et;


typedef struct 
{   
    uint8 pin         :3;   /*@ref  pin_index_et*/
    uint8 port        :3;   /*@ref  port_index_et*/
    uint8 direction   :1;   /*@ref  direction_et*/
    uint8 logic       :1;   /*@ref  logic_et*/
}pin_config_st;

/*******************************function declarations section*************************************/



Std_ReturnType GPIO_Pin_Direction_Initialize            (const pin_config_st * _pin_config);
Std_ReturnType GPIO_Pin_Get_Direction_Status            (const pin_config_st * _pin_config, direction_et *direction_status); 
Std_ReturnType GPIO_Pin_Write_Logic                     (const pin_config_st * _pin_config,logic_et logic);
Std_ReturnType GPIO_Pin_Logic                      (const pin_config_st * _pin_config,logic_et *logic);
Std_ReturnType GPIO_Pin_Toggle_Logic                    (const pin_config_st * _pin_config);
Std_ReturnType GPIO_Pin_Initialize                      (const pin_config_st * _pin_config);

Std_ReturnType GPIO_Pin_Direction_Initialize            (const pin_config_st * _pin_config);
Std_ReturnType GPIO_Pin_Get_Direction_Status            (const pin_config_st * _pin_config, direction_et *direction_status); 
Std_ReturnType GPIO_Pin_Write_Logic                    (const pin_config_st * _pin_config,logic_et logic);
Std_ReturnType GPIO_Pin_Logic                           (const pin_config_st * _pin_config,logic_et *logic);
Std_ReturnType GPIO_Pin_Toggle_Logic                    (const pin_config_st * _pin_config);
Std_ReturnType GPIO_Pin_Initialize                      (const pin_config_st * _pin_config);


Std_ReturnType GPIO_Port_Direction_Initialize           (port_index_et port , uint8 direction);
Std_ReturnType GPIO_Port_Get_Direction_Status           (port_index_et port, uint8 *direction_status); //*
Std_ReturnType GPIO_Port_Write_Logic                    (port_index_et port,uint8 logic);
Std_ReturnType GPIO_Port_Read_Logic                     (port_index_et port,uint8 *logic);
Std_ReturnType GPIO_Port_Toggle_Logic                   (port_index_et port);

#endif	/* HAL_GPIO_H */

