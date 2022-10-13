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

W3----------W4


W5----------W6
:::::Back:::::
\            /
 \__________/

*/

/******************************************** Includes ********************************************/

#include "../../MCAL/CCP/hal_ccp.h"
#include "../../MCAL/Timer0/hal_timer0.h"
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

/* Starting Wheels Speed */
#define NAV_SPEED_W2_W4_W6_DEFAULT      100
#define NAV_SPEED_W1_W3_W5_DEFAULT      100


/* Servo Steer Right Angle */
#define NAV_SERVO_STEER_RIGHT_W1_ANGLE   35
#define NAV_SERVO_STEER_RIGHT_W2_ANGLE   55
#define NAV_SERVO_STEER_RIGHT_W3_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_RIGHT_W4_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_RIGHT_W5_ANGLE   35
#define NAV_SERVO_STEER_RIGHT_W6_ANGLE   55

/* Servo Steer Left Angle */
#define NAV_SERVO_STEER_LEFT_W1_ANGLE   -55
#define NAV_SERVO_STEER_LEFT_W2_ANGLE   -35
#define NAV_SERVO_STEER_LEFT_W3_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_LEFT_W4_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_LEFT_W5_ANGLE   -55
#define NAV_SERVO_STEER_LEFT_W6_ANGLE   -35



/* Servo Steer Right Speed */

#define NAV_DC_MOTOR_STEER_RIGHT_W1_SPEED 100
#define NAV_DC_MOTOR_STEER_RIGHT_W2_SPEED 70
#define NAV_DC_MOTOR_STEER_RIGHT_W3_SPEED 100 
#define NAV_DC_MOTOR_STEER_RIGHT_W4_SPEED 70 
#define NAV_DC_MOTOR_STEER_RIGHT_W5_SPEED 100
#define NAV_DC_MOTOR_STEER_RIGHT_W6_SPEED 70

/* Servo Steer Left Speed */

#define NAV_DC_MOTOR_STEER_LEFT_W1_SPEED 70
#define NAV_DC_MOTOR_STEER_LEFT_W2_SPEED 100
#define NAV_DC_MOTOR_STEER_LEFT_W3_SPEED 70 
#define NAV_DC_MOTOR_STEER_LEFT_W4_SPEED 100
#define NAV_DC_MOTOR_STEER_LEFT_W5_SPEED 70
#define NAV_DC_MOTOR_STEER_LEFT_W6_SPEED 100

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

Std_ReturnType Robot_Nav_Init(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj);
Std_ReturnType Robot_Move_Forward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj);
Std_ReturnType Robot_Steer_Right_Forward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj);
Std_ReturnType Robot_Steer_Left_Forward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj);
Std_ReturnType Robot_Move_Backward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj);
Std_ReturnType Robot_Steer_Right_Backward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj);
Std_ReturnType Robot_Steer_Left_Backward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj);


/******************************************** Function prototypes ********************************************/
void Timer0_Handler();


/******************************************** Global Shared Variables ********************************************/

Nav_Movement_State_et Movement_State = NAV_MOV_STOPPED ;


/******************************************** Global Static Variables ********************************************/

static dc_motor_st W1_W5_W2_W6_Motor_Control =
{
    .dc_motor[0].port = PORTD_INDEX ,
    .dc_motor[0].pin = GPIO_PIN0 ,
    .dc_motor[0].logic = GPIO_LOW ,
    .dc_motor[0].direction = GPIO_DIRECTION_OUTPUT , 
    .dc_motor[1].port = PORTD_INDEX ,
    .dc_motor[1].pin = GPIO_PIN1 ,
    .dc_motor[1].logic = GPIO_LOW ,
    .dc_motor[1].direction = GPIO_DIRECTION_OUTPUT  
};

static dc_motor_st W3_Motor_Control =
{
    .dc_motor[0].port = PORTD_INDEX ,
    .dc_motor[0].pin = GPIO_PIN2 ,
    .dc_motor[0].logic = GPIO_LOW ,
    .dc_motor[0].direction = GPIO_DIRECTION_OUTPUT , 
    .dc_motor[1].port = PORTD_INDEX ,
    .dc_motor[1].pin = GPIO_PIN3 ,
    .dc_motor[1].logic = GPIO_LOW ,
    .dc_motor[1].direction = GPIO_DIRECTION_OUTPUT  
};

static dc_motor_st W4_Motor_Control =
{
    .dc_motor[0].port = PORTD_INDEX ,
    .dc_motor[0].pin = GPIO_PIN4 ,
    .dc_motor[0].logic = GPIO_LOW ,
    .dc_motor[0].direction = GPIO_DIRECTION_OUTPUT , 
    .dc_motor[1].port = PORTD_INDEX ,
    .dc_motor[1].pin = GPIO_PIN5 ,
    .dc_motor[1].logic = GPIO_LOW ,
    .dc_motor[1].direction = GPIO_DIRECTION_OUTPUT  
};


static timer0_config_st Timer0 = 
{
    .timer_mode = TMR0_TIMER_MODE ,
    .timer0_InterruptHandler = Timer0_Handler ,
    .reg_bit_size = TMR0_16BIT ,
    .prescaler_enable = TMR0_PRESCALER_ON ,
    .preloaded_value = 34286 ,
    .prescalar_value = TMR0_PRESCALER_BY_256 ,
    .priority = INT_HIGH_PRI 
    
};

/* CCP1 :  W1 , W3 , W5     (Left Side) */
static ccp_st CCP1_Obj =
{
    .ccp_inst = CCP1_INST ,
    .ccp_mode = CCP_PWM_MODE_SELECTED,
    .PWM_Frequency = 10000,
    .ccp_pin.port = PORTC_INDEX,
    .ccp_pin.pin = GPIO_PIN2,
    .ccp_pin.direction = GPIO_DIRECTION_OUTPUT,
    .timer2_prescaler_value = CCP_TIMER2_PRESCALER_DIV_BY_1,   
};

/* CCP2 :  W2 , W4 , W6     (Right Side) */
static ccp_st CCP2_Obj =
{
    .ccp_inst = CCP2_INST ,
    .ccp_mode = CCP_PWM_MODE_SELECTED,
    .PWM_Frequency = 10000,
    .ccp_pin.port = PORTC_INDEX,
    .ccp_pin.pin = GPIO_PIN1,
    .ccp_pin.direction = GPIO_DIRECTION_OUTPUT,
    .timer2_prescaler_value = CCP_TIMER2_PRESCALER_DIV_BY_1,   
};





#endif /* ROBOT_NAVIGATION_H */