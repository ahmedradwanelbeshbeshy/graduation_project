/* 
 * File:   robot_navigation.h
 * Author: Ahmed Odb
 * Created on October 13, 2022, 7:22 AM
 */


/* Servos are on CH0 , CH1 , CH2 , CH3 */


#ifndef ROBOT_NAVIGATION_H
#define ROBOT_NAVIGATION_H

/*
ROBOT CAR MODEL
    .......
.../       \...
:::::Front:::::

W1----------W2
servo1      servo2

W3----------W4


W5----------W6
servo3      servo4
:::::Back:::::
\            /
 \__________/

*/

/******************************************** Includes ********************************************/
#include "../../MCAL/TIMER2/mcal_timer2.h"
#include "../../MCAL/CCP/hal_ccp.h"
#include "../../MCAL/I2C/mcal_i2c.h"
#include "../../ECU/DC_Motor/ecu_dc_motor.h"
#include "../../ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.h"


/******************************************** Macro Defines ***************************************************************/

/* Timer 0 preload */
#define NAV_TMR0_PRELOAD 34286


/* Servo Starting Angle */
#define NAV_SERVO_STARTING_ANGLE 90
/* Servo No Steering Angle */
#define NAV_SERVO_NO_STEER_ANGLE 90
/* Servo MAX Steering Angle */
#define NAV_SERVO_MAX_STEERING_ANGLE 45
/* Servo MAX Steering Direction */
#define NAV_SERVO_STEER_DIR_POSITIVE   -1
#define NAV_SERVO_STEER_DIR_NEGATIVE    1

#define NAV_SERVO_STEER_BACKW_DIRECTION      -1

/* Starting Wheels Speed */



/* Servo Steer Right Angle */
#define NAV_SERVO_STEER_RIGHT_W1_ANGLE   45 
#define NAV_SERVO_STEER_RIGHT_W2_ANGLE   25
#define NAV_SERVO_STEER_RIGHT_W3_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_RIGHT_W4_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_RIGHT_W5_ANGLE   135
#define NAV_SERVO_STEER_RIGHT_W6_ANGLE   115

/* Servo Steer Left Angle */
#define NAV_SERVO_STEER_LEFT_W1_ANGLE   115
#define NAV_SERVO_STEER_LEFT_W2_ANGLE   135
#define NAV_SERVO_STEER_LEFT_W3_ANGLE    0 /* No Steering Servo */
#define NAV_SERVO_STEER_LEFT_W4_ANGLE    0 /* No Steering Servo */
#define NAV_SERVO_STEER_LEFT_W5_ANGLE   25
#define NAV_SERVO_STEER_LEFT_W6_ANGLE   45


/* Starting Wheels Speed */
#define NAV_SPEED_W2_W4_W6_DEFAULT      95
#define NAV_SPEED_W1_W3_W5_DEFAULT      95

/* Servo Steer Right Speed */

#define NAV_DC_MOTOR_STEER_RIGHT_W1_row_SPEED 95
#define NAV_DC_MOTOR_STEER_RIGHT_W2_row_SPEED 85

/* Servo Steer Left Speed */

#define NAV_DC_MOTOR_STEER_LEFT_W1_row_SPEED 85
#define NAV_DC_MOTOR_STEER_LEFT_W2_row_SPEED 95

#define NAV_DC_MOTOR_stop 0

/******************************************** Macro Functions *************************************************************/


/******************************************** User-Defined Data Type Declaration ********************************************/

typedef enum {
    NAV_MOV_STOPPED = 0,
    NAV_MOV_FORW,
    NAV_MOV_FORW_STEER_RIGHT,
    NAV_MOV_FORW_STEER_LEFT,
    NAV_MOV_BACKW,
    NAV_MOV_BACKW_STEER_RIGHT,
    NAV_MOV_BACKW_STEER_LEFT
}Nav_Movement_State_et;


/******************************************** Software Interfaces (Prototypes) ********************************************/

//Std_ReturnType Robot_Nav_Init(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj);
//Std_ReturnType Robot_Move_Forward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj);
//Std_ReturnType Robot_Steer_Right_Forward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj);
//Std_ReturnType Robot_Steer_Left_Forward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj);
//Std_ReturnType Robot_Move_Backward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj);
//Std_ReturnType Robot_Steer_Right_Backward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj);
//Std_ReturnType Robot_Steer_Left_Backward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj);

Std_ReturnType Robot_Nav_Init(void);
Std_ReturnType Robot_Steer_Stop(void);
Std_ReturnType Robot_Move_Forward(void);
Std_ReturnType Robot_Move_Backward(void);
Std_ReturnType Robot_Steer_Right_Forward(void);
Std_ReturnType Robot_Steer_Left_Forward(void);
/******************************************** Function prototypes ********************************************/


/******************************************** Global Shared Variables ********************************************/

Nav_Movement_State_et Movement_State = NAV_MOV_STOPPED ;


/******************************************** Global Static Variables ********************************************/

static dc_motor_st W1_W3_W5_Motor_Control =
{
    .dc_motor.port = PORTD_INDEX ,
    .dc_motor.pin = GPIO_PIN0 ,
    .dc_motor.logic = GPIO_LOW ,
    .dc_motor.direction = GPIO_DIRECTION_OUTPUT , 

};

static dc_motor_st W2_W4_W6_Motor_Control =
{
    .dc_motor.port = PORTD_INDEX ,
    .dc_motor.pin = GPIO_PIN1 ,
    .dc_motor.logic = GPIO_LOW ,
    .dc_motor.direction = GPIO_DIRECTION_OUTPUT , 

};

/* CCP1 :  W1 , W3 , W5     (Left Side) */
ccp_st CCP1_Obj =
{
    .ccp_inst = CCP1_INST ,
    .ccp_mode = CCP_PWM_MODE_SELECTED,
    .PWM_Frequency = 500,
    .ccp_pin.port = PORTC_INDEX,
    .ccp_pin.pin = GPIO_PIN2,
    .ccp_pin.direction = GPIO_DIRECTION_OUTPUT,
    .timer2.timer2_preload_value=249,/*((_XTAL_FREQ / ((_ccp_obj->PWM_Frequency )* 4.0 * _ccp_obj->timer2.timer2_prescaler_value) - 1))*/
    .timer2.timer2_postscaler_value=TIMER2_postscaler_DIV_BY_16,
    .timer2.timer2_prescaler_value=TIMER2_PRESCALER_DIV_BY_1
};
ccp_st CCP2_Obj =
{
    .ccp_inst = CCP2_INST ,
    .ccp_mode = CCP_PWM_MODE_SELECTED,
    .PWM_Frequency = 500,
    .ccp_pin.port = PORTC_INDEX,
    .ccp_pin.pin = GPIO_PIN1,
    .ccp_pin.direction = GPIO_DIRECTION_OUTPUT,
    .timer2.timer2_preload_value=249,/*((_XTAL_FREQ / ((_ccp_obj->PWM_Frequency )* 4.0 * _ccp_obj->timer2.timer2_prescaler_value) - 1))*/
    .timer2.timer2_postscaler_value=TIMER2_postscaler_DIV_BY_16,
    .timer2.timer2_prescaler_value=TIMER2_PRESCALER_DIV_BY_1
};

/*i2c and servos */
mssp_i2c_st i2c_obj={
  .i2c_cfg.i2c_mode=  I2C_MSSP_MASTER_MODE,
  .i2c_cfg.i2c_mode_cfg=I2C_MASTER_MODE_DEFINED_CLOCK,
  .i2c_clock=100000,
  .i2c_cfg.i2c_SMBus_control=I2C_SMBus_DISABLE,
  .i2c_cfg.i2c_slew_rate=I2C_SLEW_RATE_DISABLE,
  //.I2C_DefaultInterruptHandler=NULL,
  //.I2C_Report_Receive_Overflow=NULL,
  //.I2C_Report_Write_Collision=NULL
};
servo_driver_st servo_driver_obj={
   .slave_address=SERVO_DRIVER_SLAVE_ADDRESS,
   .frequancy=ECU_SM_PRE_SCALE_REG_VAL,
   .mode_1_cfg=0x21,
   .mode_2_cfg=0x04   
};



#endif /* ROBOT_NAVIGATION_H */