/*
 * File:   application.c
 * Author: ahmed Odb
 *
 * Created on September 16, 2022, 7:48 PM
 */



#include "application.h"
#include "ECU/LCD_for_test_gps/ecu_char_lcd.h"
#include"Robot/sensors/ultrasonic/ultrasonic.h"
#include"ECU/stepper/ecu_stepper.h"



pin_config_st pinc0={
   .direction=GPIO_DIRECTION_OUTPUT,
   .logic=GPIO_HIGH,
   .pin=GPIO_PIN0,
   .port=PORTC_INDEX 
};

 
  /************************************stepper*********************************/
pin_config_st step_pin1 =
{
  .port = PORTC_INDEX ,
  .pin = GPIO_PIN1 ,
  .logic = GPIO_LOW,
  .direction = GPIO_DIRECTION_OUTPUT
};

pin_config_st dir_pin1 =
{
  .port = PORTC_INDEX ,
  .pin = GPIO_PIN2 ,
  .logic = GPIO_LOW,
  .direction = GPIO_DIRECTION_OUTPUT
};

stepper_config_st stepper1 ;


uint16_t counter = 0 ;

    


  /************************************stepper end**********************************/


int main()
{   
    stepper1.step_pin = step_pin1 ;
    stepper1.dir_pin = dir_pin1 ;
    
    application_intialize();
    GPIO_Pin_Write_Logic(&pinc0,GPIO_HIGH);
    __delay_ms(1000);
   while(1)
    {
       GPIO_Pin_Toggle_Logic(&pinc0);
           __delay_ms(500);
               for (counter = 0 ; counter < 200 ; counter++)
        Ecu_Stepper_Step(&stepper1);
   }
   return 0;
}
void application_intialize(void)
{
    Ecu_Stepper_Init(&stepper1);
    GPIO_Pin_Initialize(&pinc0);
}
