/*
 * File:   application.c
 * Author: ahmed radwan
 *
 * Created on September 16, 2022, 7:48 PM
 */

#include"application.h"

#include "application.h"
#include "MCAL/I2C/mcal_i2c.h"

#define slave1 0x60
#define slave2 0x62

uint32 master_counter=0;
 uint8 ack=6;
void master_isr(void){
    master_counter++;
}
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




void mssp_i2c_send_1_byte(uint8 slave_adrres,uint8 data)
{
    MSSP_I2C_Master_Send_Start(&i2c_obj);
    MSSP_I2C_Master_Write_Blocking(&i2c_obj,slave_adrres,&ack);
    MSSP_I2C_Master_Write_Blocking(&i2c_obj,data,&ack);
    MSSP_I2C_Master_Send_Stop(&i2c_obj);
}



int main()
{
 application_intialize();
     while(1)
     {
        mssp_i2c_send_1_byte(slave1,'a');
        __delay_ms(1000);
        mssp_i2c_send_1_byte(slave2,'b');
        __delay_ms(1000);
        mssp_i2c_send_1_byte(slave1,'c');
        __delay_ms(1000);
        mssp_i2c_send_1_byte(slave2,'d');
        __delay_ms(1000);
     }
    return 0;

}
void application_intialize(void)
{
    MSSP_I2C_Init(&i2c_obj);
}
