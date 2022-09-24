/* 
 * File:   ecu_servo_motor_i2c.c
 * Author: ahmed radwan
 *
 * Created on September 24, 2022, 3:56 AM
 */
#include"ecu_servo_motor_i2c.h"

static void PCA_Write_Reg(const mssp_i2c_st *i2c_obj,uint8 slave_adrres,uint8 reg_aderres,uint8 data);
void PCA_Read_Reg(const mssp_i2c_st *i2c_obj,uint8 slave_adrres,uint8 reg_aderres,uint8 *data);


Std_returnType ServoDriver_Init(const mssp_i2c_st *i2c_obj,const servo_driver_st *servo_driver_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
    if ((NULL==i2c_obj)||(NULL==servo_driver_obj))
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
     MSSP_I2C_Init(i2c_obj);
     PCA_Write_Reg(i2c_obj,servo_driver_obj->slave_address,ECU_SM_PRE_SCALE_REG,servo_driver_obj->frequancy);
     PCA_Write_Reg(i2c_obj,servo_driver_obj->slave_address,ECU_SM_MODE1_REG,servo_driver_obj->mode_1_cfg);
     PCA_Write_Reg(i2c_obj,servo_driver_obj->slave_address,ECU_SM_MODE2_REG,servo_driver_obj->mode_2_cfg);
     
    }   
    return ERRORSTATUS;
}
Std_returnType ServoDriver_DeInit(const mssp_i2c_st *i2c_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==i2c_obj)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
    MSSP_I2C_DeInit(i2c_obj);
     }   
    return ERRORSTATUS;
}
Std_returnType Servo_SetAngle(const mssp_i2c_st *i2c_obj,const servo_driver_st *servo_driver_obj,const servo_index_et servo_no,const uint8 angle)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==i2c_obj)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        uint8 reg_addrees=6+(servo_no*4)+2;
        uint16 angle_in_reg=(uint16)(angle*1.14+205);
//        PCA_Write_Reg(i2c_obj,servo_driver_obj->slave_address,reg_addrees,0x00);
//        reg_addrees++;
//        PCA_Write_Reg(i2c_obj,servo_driver_obj->slave_address,reg_addrees,0x00);
//        reg_addrees++;
        PCA_Write_Reg(i2c_obj,servo_driver_obj->slave_address,reg_addrees,((uint8)angle_in_reg));
        reg_addrees++;
        PCA_Write_Reg(i2c_obj,servo_driver_obj->slave_address,reg_addrees,((uint8)(angle_in_reg>>8)));        
    }   
    return ERRORSTATUS;
}

static void PCA_Write_Reg(const mssp_i2c_st *i2c_obj,uint8 slave_address,uint8 reg_address,uint8 data)
{
    uint8 ack=6;
    //start
    MSSP_I2C_Master_Send_Start(i2c_obj);
    //slave address
    MSSP_I2C_Master_Write_Blocking(i2c_obj,slave_address,&ack);
    //control REG address
    MSSP_I2C_Master_Write_Blocking(i2c_obj,reg_address,&ack);
    //data
    MSSP_I2C_Master_Write_Blocking(i2c_obj,data,&ack);
    //stop
    MSSP_I2C_Master_Send_Stop(i2c_obj);
}
