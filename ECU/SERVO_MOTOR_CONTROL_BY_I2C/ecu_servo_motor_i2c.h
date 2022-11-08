/* 
 * File:   ecu_servo_motor_i2c.h
 * Author: ahmed radwan
 *
 * Created on September 24, 2022, 3:56 AM
 */

#ifndef ECU_SERVO_MOTOR_I2C_H
#define	ECU_SERVO_MOTOR_I2C_H


/* ----------------- Includes -----------------*/
#include"ecu_servo_motor_i2c_cfg.h"
#include"../../MCAL/I2C/mcal_i2c.h"
/* ----------------- Macro Declarations -----------------*/

#define ECU_SM_MODE1_REG                0x00
#define ECU_SM_MODE2_REG                0x01

#define ECU_SM_SUBADR1_REG              0x02
#define ECU_SM_SUBADR2_REG              0x03
#define ECU_SM_SUBADR3_REG              0x04

#define ECU_SM_ALLCALLADDR_REG          0x05

#define ECU_SM_LED0_ON_L_REG            0x06
#define ECU_SM_LED0_ON_H_REG            0x07
#define ECU_SM_LED0_OFF_L_REG           0x08
#define ECU_SM_LED0_OFF_H_REG           0x09

#define ECU_SM_LED1_ON_L_REG            0x0A
#define ECU_SM_LED1_ON_H_REG            0x0B
#define ECU_SM_LED1_OFF_L_REG           0x0C
#define ECU_SM_LED1_OFF_H_REG           0x0D

#define ECU_SM_LED2_ON_L_REG            0x0E
#define ECU_SM_LED2_ON_H_REG            0x0F
#define ECU_SM_LED2_OFF_L_REG           0x10
#define ECU_SM_LED2_OFF_H_REG           0x11

#define ECU_SM_LED3_ON_L_REG            0x12
#define ECU_SM_LED3_ON_H_REG            0x13
#define ECU_SM_LED3_OFF_L_REG           0x14
#define ECU_SM_LED3_OFF_H_REG           0x15

#define ECU_SM_LED4_ON_L_REG            0x16
#define ECU_SM_LED4_ON_H_REG            0x17
#define ECU_SM_LED4_OFF_L_REG           0x18
#define ECU_SM_LED4_OFF_H_REG           0x19

#define ECU_SM_LED5_ON_L_REG            0x1A
#define ECU_SM_LED5_ON_H_REG            0x1B
#define ECU_SM_LED5_OFF_L_REG           0x1C
#define ECU_SM_LED5_OFF_H_REG           0x1D

#define ECU_SM_LED6_ON_L_REG            0x1E
#define ECU_SM_LED6_ON_H_REG            0x1F
#define ECU_SM_LED6_OFF_L_REG           0x20
#define ECU_SM_LED6_OFF_H_REG           0x21

#define ECU_SM_LED7_ON_L_REG            0x22
#define ECU_SM_LED7_ON_H_REG            0x23
#define ECU_SM_LED7_OFF_L_REG           0x24
#define ECU_SM_LED7_OFF_H_REG           0x25

#define ECU_SM_LED8_ON_L_REG            0x26
#define ECU_SM_LED8_ON_H_REG            0x27
#define ECU_SM_LED8_OFF_L_REG           0x28
#define ECU_SM_LED8_OFF_H_REG           0x29

#define ECU_SM_LED9_ON_L_REG            0x2A
#define ECU_SM_LED9_ON_H_REG            0x2B
#define ECU_SM_LED9_OFF_L_REG           0x2C
#define ECU_SM_LED9_OFF_H_REG           0x2D

#define ECU_SM_LED10_ON_L_REG           0x2E
#define ECU_SM_LED10_ON_H_REG           0x2F
#define ECU_SM_LED10_OFF_L_REG          0x30
#define ECU_SM_LED10_OFF_H_REG          0x31

#define ECU_SM_LED11_ON_L_REG           0x32
#define ECU_SM_LED11_ON_H_REG           0x33
#define ECU_SM_LED11_OFF_L_REG          0x34
#define ECU_SM_LED11_OFF_H_REG          0x35

#define ECU_SM_LED12_ON_L_REG           0x36
#define ECU_SM_LED12_ON_H_REG           0x37
#define ECU_SM_LED12_OFF_L_REG          0x38
#define ECU_SM_LED12_OFF_H_REG          0x39

#define ECU_SM_LED13_ON_L_REG           0x3A
#define ECU_SM_LED13_ON_H_REG           0x3B
#define ECU_SM_LED13_OFF_L_REG          0x3C
#define ECU_SM_LED13_OFF_H_REG          0x3D

#define ECU_SM_LED14_ON_L_REG           0x3E
#define ECU_SM_LED14_ON_H_REG           0x3F
#define ECU_SM_LED14_OFF_L_REG          0x40
#define ECU_SM_LED14_OFF_H_REG          0x41

#define ECU_SM_LED15_ON_L_REG           0x42
#define ECU_SM_LED15_ON_H_REG           0x43
#define ECU_SM_LED15_OFF_L_REG          0x44
#define ECU_SM_LED15_OFF_H_REG          0x45

#define ECU_SM_ALL_LED_ON_L_REG         0xFA
#define ECU_SM_ALL_LED_ON_H_REG         0xFB
#define ECU_SM_ALL_LED_OFF_L_REG        0xFC
#define ECU_SM_ALL_LED_OFF_H_REG        0xFD

#define ECU_SM_PRE_SCALE_REG            0xFE

/*sleep and restart commands*/
#define ECU_SM_MODE1_SLEEP_COMAND             0x10
#define ECU_SM_MODE1_RESTART_COMAND           0x80


/*macros off servo index with its crospending address of registers in PCA9685*/


#define ECU_servo1_ON_L_REG                        ECU_SM_LED0_ON_L_REG            
#define ECU_servo1_ON_H_REG                        ECU_SM_LED0_ON_H_REG            
#define ECU_servo1_OFF_L_REG                       ECU_SM_LED0_OFF_L_REG           
#define ECU_servo1_OFF_H_REG                       ECU_SM_LED0_OFF_H_REG          

#define ECU_servo2_ON_L_REG                        ECU_SM_LED1_ON_L_REG            
#define ECU_servo2_ON_H_REG                        ECU_SM_LED1_ON_H_REG            
#define ECU_servo2_OFF_L_REG                       ECU_SM_LED1_OFF_L_REG           
#define ECU_servo2_OFF_H_REG                       ECU_SM_LED1_OFF_H_REG  

#define ECU_servo3_ON_L_REG                        ECU_SM_LED2_ON_L_REG            
#define ECU_servo3_ON_H_REG                        ECU_SM_LED2_ON_H_REG            
#define ECU_servo3_OFF_L_REG                       ECU_SM_LED2_OFF_L_REG           
#define ECU_servo3_OFF_H_REG                       ECU_SM_LED2_OFF_H_REG  

#define ECU_servo4_ON_L_REG                        ECU_SM_LED3_ON_L_REG            
#define ECU_servo4_ON_H_REG                        ECU_SM_LED3_ON_H_REG            
#define ECU_servo4_OFF_L_REG                       ECU_SM_LED3_OFF_L_REG           
#define ECU_servo4_OFF_H_REG                       ECU_SM_LED3_OFF_H_REG  

#define ECU_servo5_ON_L_REG                        ECU_SM_LED4_ON_L_REG            
#define ECU_servo5_ON_H_REG                        ECU_SM_LED4_ON_H_REG            
#define ECU_servo5_OFF_L_REG                       ECU_SM_LED4_OFF_L_REG           
#define ECU_servo5_OFF_H_REG                       ECU_SM_LED4_OFF_H_REG  

#define ECU_servo6_ON_L_REG                        ECU_SM_LED5_ON_L_REG            
#define ECU_servo6_ON_H_REG                        ECU_SM_LED5_ON_H_REG            
#define ECU_servo6_OFF_L_REG                       ECU_SM_LED5_OFF_L_REG           
#define ECU_servo6_OFF_H_REG                       ECU_SM_LED5_OFF_H_REG  

#define ECU_servo7_ON_L_REG                        ECU_SM_LED6_ON_L_REG            
#define ECU_servo7_ON_H_REG                        ECU_SM_LED6_ON_H_REG            
#define ECU_servo7_OFF_L_REG                       ECU_SM_LED6_OFF_L_REG           
#define ECU_servo7_OFF_H_REG                       ECU_SM_LED6_OFF_H_REG  

#define ECU_servo8_ON_L_REG                        ECU_SM_LED7_ON_L_REG            
#define ECU_servo8_ON_H_REG                        ECU_SM_LED7_ON_H_REG            
#define ECU_servo8_OFF_L_REG                       ECU_SM_LED7_OFF_L_REG           
#define ECU_servo8_OFF_H_REG                       ECU_SM_LED7_OFF_H_REG  

#define ECU_servo9_ON_L_REG                        ECU_SM_LED8_ON_L_REG            
#define ECU_servo9_ON_H_REG                        ECU_SM_LED8_ON_H_REG            
#define ECU_servo9_OFF_L_REG                       ECU_SM_LED8_OFF_L_REG           
#define ECU_servo9_OFF_H_REG                       ECU_SM_LED8_OFF_H_REG  

#define ECU_servo10_ON_L_REG                        ECU_SM_LED9_ON_L_REG            
#define ECU_servo10_ON_H_REG                        ECU_SM_LED9_ON_H_REG            
#define ECU_servo10_OFF_L_REG                       ECU_SM_LED9_OFF_L_REG           
#define ECU_servo10_OFF_H_REG                       ECU_SM_LED9_OFF_H_REG  

#define ECU_servo11_ON_L_REG                        ECU_SM_LED10_ON_L_REG            
#define ECU_servo11_ON_H_REG                        ECU_SM_LED10_ON_H_REG            
#define ECU_servo11_OFF_L_REG                       ECU_SM_LED10_OFF_L_REG           
#define ECU_servo11_OFF_H_REG                       ECU_SM_LED10_OFF_H_REG  

#define ECU_servo12_ON_L_REG                        ECU_SM_LED11_ON_L_REG            
#define ECU_servo12_ON_H_REG                        ECU_SM_LED11_ON_H_REG            
#define ECU_servo12_OFF_L_REG                       ECU_SM_LED11_OFF_L_REG           
#define ECU_servo12_OFF_H_REG                       ECU_SM_LED11_OFF_H_REG  

#define ECU_servo13_ON_L_REG                        ECU_SM_LED12_ON_L_REG            
#define ECU_servo13_ON_H_REG                        ECU_SM_LED12_ON_H_REG            
#define ECU_servo13_OFF_L_REG                       ECU_SM_LED12_OFF_L_REG           
#define ECU_servo13_OFF_H_REG                       ECU_SM_LED12_OFF_H_REG  

#define ECU_servo14_ON_L_REG                        ECU_SM_LED13_ON_L_REG            
#define ECU_servo14_ON_H_REG                        ECU_SM_LED13_ON_H_REG            
#define ECU_servo14_OFF_L_REG                       ECU_SM_LED13_OFF_L_REG           
#define ECU_servo14_OFF_H_REG                       ECU_SM_LED13_OFF_H_REG  

#define ECU_servo15_ON_L_REG                        ECU_SM_LED14_ON_L_REG            
#define ECU_servo15_ON_H_REG                        ECU_SM_LED14_ON_H_REG            
#define ECU_servo15_OFF_L_REG                       ECU_SM_LED14_OFF_L_REG           
#define ECU_servo15_OFF_H_REG                       ECU_SM_LED14_OFF_H_REG  

#define ECU_servo16_ON_L_REG                        ECU_SM_LED15_ON_L_REG            
#define ECU_servo16_ON_H_REG                        ECU_SM_LED15_ON_H_REG            
#define ECU_servo16_OFF_L_REG                       ECU_SM_LED15_OFF_L_REG           
#define ECU_servo16_OFF_H_REG                       ECU_SM_LED15_OFF_H_REG  




/* ----------------- Macro Functions Declarations -----------------*/
/* ----------------- Data Type Declarations -----------------*/

typedef enum{
    servo_index_1=0,        
    servo_index_2,
    servo_index_3,   
    servo_index_4,
    servo_index_5,
    servo_index_6,
    servo_index_7,
    servo_index_8,
    servo_index_9,
    servo_index_10,
    servo_index_11,
    servo_index_12,        
    servo_index_13,        
    servo_index_14,        
    servo_index_15,        
    servo_index_16,        
}servo_index_et;

typedef struct{
    uint8 slave_address;
    uint8 frequancy;
    uint8 mode_1_cfg;
    uint8 mode_2_cfg;
}servo_driver_st;
/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType ServoDriver_Init(const mssp_i2c_st *i2c_obj,const servo_driver_st *servo_driver_obj);
Std_ReturnType ServoDriver_DeInit(const mssp_i2c_st *i2c_obj);
Std_ReturnType Servo_SetAngle(const mssp_i2c_st *i2c_obj,const servo_driver_st *servo_driver_obj,const servo_index_et servo_no,const uint8 angle);


#endif	/* ECU_SERVO_MOTOR_I2C_H */

