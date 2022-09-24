/*
 * File:   application.c
 * Author: ahmed radwan
 *
 * Created on September 16, 2022, 7:48 PM
 */

#include"application.h"

void INT1_Handler(void);
void OnChanggeINT_Handler(void);

pin_config_st PIN1={
  .port=PORTC_INDEX,
  .pin=GPIO_PIN0,
  .direction=GPIO_DIRECTION_OUTPUT,
  .logic=GPIO_LOW  
};
pin_config_st PIN2={
  .port=PORTC_INDEX,
  .pin=GPIO_PIN2,
  .direction=GPIO_DIRECTION_OUTPUT,
  .logic=GPIO_LOW  
};

Interrupt_INTx_st INTERUPT1={
  .Ext_Interrupt_Handler=INT1_Handler,
  .edge=INT_FALLING_EDGE,
  .priority=INT_LOW_PRI,
  .src=INTERRUPT_INT1
};
Interrupt_RBx_st INTERUPT_oncahnge={
  .pin.direction= GPIO_DIRECTION_INPUT,
  .pin.logic=GPIO_LOW,
  .pin.port=PORTB_INDEX,
  .pin.pin=GPIO_PIN4,
  .Ext_Interrupt_Handler_Low=OnChanggeINT_Handler,
  .priority=INT_LOW_PRI,
};
void main(void)
{
    application_intialize();
    while(1)
    {
      
    }
    return;
}
void application_intialize(void)
{
GPIO_Pin_Initialize(&PIN1);
GPIO_Pin_Initialize(&PIN2);
Interrupt_INTx_INIT(&INTERUPT1);
Interrupt_RBx_INIT(&INTERUPT_oncahnge);

}
void INT1_Handler(void)
{
    GPIO_Pin_Toggle_Logic(&PIN1);  
}
void OnChanggeINT_Handler(void)
{
   GPIO_Pin_Toggle_Logic(&PIN2);   
}