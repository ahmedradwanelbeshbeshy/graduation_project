/*
 * File:   application.c
 * Author: SPATIAL TEAM
 *
 * Created on September 16, 2022, 7:48 PM
 */



#include "application.h"
#include"MCAL/TIMER1/TIMER1.h"
void servo();
volatile uint16 counter=0;
volatile uint8 angle1=90;
volatile uint8 state=0;
volatile pin_config_st pinc0 =
{
  .port = PORTC_INDEX ,
  .pin = GPIO_PIN0 ,
  .logic = GPIO_HIGH,
  .direction = GPIO_DIRECTION_OUTPUT
};
pin_config_st pinc1 =
{
  .port = PORTC_INDEX ,
  .pin = GPIO_PIN1 ,
  .logic = GPIO_HIGH,
  .direction = GPIO_DIRECTION_OUTPUT
};

//timer1_t timer_for_servo={
//  .Timer1_InterruptHandler=servo,
//  .timer1_mode=TIMER1_TIMER_MODE_CFG,
//  .timer1_register_mode=TIMER1_RW_REG_16BIT_MODE,
//  .timer1_preload_value=65492,
//  .timer1_prescaler_value=TIMER1_PRESCALER_DIV_BY_1,
//};
/*******************************************************/
#include "MCAL/I2C/mcal_i2c.h"
#include"ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.h"

mssp_i2c_st i2c_obj={
  .i2c_cfg.i2c_mode=  I2C_MSSP_MASTER_MODE,
  .i2c_cfg.i2c_mode_cfg=I2C_MASTER_MODE_DEFINED_CLOCK,
  .i2c_clock=100000,
  .i2c_cfg.i2c_SMBus_control=I2C_SMBus_DISABLE,
  .i2c_cfg.i2c_slew_rate=I2C_SLEW_RATE_DISABLE,
  .I2C_DefaultInterruptHandler=NULL,
  .I2C_Report_Receive_Overflow=NULL,
  .I2C_Report_Write_Collision=NULL
};
uint8 ack;
/*******************************************************/
int main()
{
    application_intialize();

 
     while(1)
     {
         GPIO_Pin_Toggle_Logic(&pinc1); 
          __delay_ms(500);
          
    //start
    MSSP_I2C_Master_Send_Start(&i2c_obj);
    //slave address
    MSSP_I2C_Master_Write_Blocking(&i2c_obj,8,&ack);
    //data
    MSSP_I2C_Master_Write_Blocking(&i2c_obj,'1',&ack);
    //stop
    MSSP_I2C_Master_Send_Stop(&i2c_obj);
    __delay_ms(500);
    //start
    MSSP_I2C_Master_Send_Start(&i2c_obj);
    //slave address
    MSSP_I2C_Master_Write_Blocking(&i2c_obj,8,&ack);
    //data
    MSSP_I2C_Master_Write_Blocking(&i2c_obj,'0',&ack);
    //stop
    MSSP_I2C_Master_Send_Stop(&i2c_obj);
     }

    return 0;

}
void application_intialize(void)
{
    GPIO_Pin_Initialize(&pinc0);
    GPIO_Pin_Initialize(&pinc1);
    MSSP_I2C_Init(&i2c_obj);
    //Timer1_Init(&timer_for_servo);
}
//void servo()
//{
//    GPIO_Pin_Toggle_Logic(&pinc0); 
//    counter++;
//    if (state==0)
//    {
//     GPIO_Pin_Write_Logic(&pinc0,GPIO_HIGH);
//     state=1;
//    }
//    else if (counter==(angle1+180))
//    {
//        GPIO_Pin_Write_Logic(&pinc0,GPIO_LOW); 
//    }
//    else if (counter==3600)
//    {
//        counter=0;
//        state=0;
//    }  
