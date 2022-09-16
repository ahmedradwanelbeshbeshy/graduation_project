/*
 * File:   application.c
 * Author: ahmed radwan
 *
 * Created on September 16, 2022, 7:48 PM
 */


#include"application.h"
pin_config_st PIN1={
  .port=PORTC_INDEX,
  .pin=GPIO_PIN0,
  .direction=GPIO_DIRECTION_OUTPUT,
  .logic=GPIO_LOW  
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

}