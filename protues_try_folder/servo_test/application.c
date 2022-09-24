/*
 * File:   application.c
 * Author: ahmed radwan
 *
 * Created on September 16, 2022, 7:48 PM
 */

#include"application.h"

#include "application.h"
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
servo_driver_st s1_obj={
   .slave_address=SERVO_DRIVER_SLAVE_ADDRESS,
   .frequancy=ECU_SM_PRE_SCALE_REG_VAL,
   .mode_1_cfg=0x21,
   .mode_2_cfg=0x04   
};
#define delay 100
uint8 angle=0;
int main()
{
    application_intialize();

    for(int i=0;i<16;i++)
    {
        Servo_SetAngle(&i2c_obj,&s1_obj,i,angle);
        //__delay_ms(delay);
        angle+=15;
    }
     while(1)
     {
         
     }    
    return 0;

}
void application_intialize(void)
{
    MSSP_I2C_Init(&i2c_obj);
    ServoDriver_Init(&i2c_obj,&s1_obj);
}