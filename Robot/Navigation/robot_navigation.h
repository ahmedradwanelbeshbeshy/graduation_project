/* 
 * File:   robot_navigation.h
 * Author: Ahmed Odb
 * Created on October 13, 2022, 7:22 AM
 */



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


/******************************************** Macro Defines ***************************************************************/



/* Servo Starting Angle */
#define NAV_SERVO_STARTING_ANGLE 90
/* Servo MAX Steering Angle */
#define NAV_SERVO_MAX_STEERING_ANGLE 45
/* Servo MAX Steering Direction */
#define NAV_SERVO_STEER_DIR_POSITIVE   -1
#define NAV_SERVO_STEER_DIR_NEGATIVE    1

/* Servo Steer Right Angle */
#define NAV_SERVO_STEER_RIGHT_W1_ANGLE   35
#define NAV_SERVO_STEER_RIGHT_W2_ANGLE   55
#define NAV_SERVO_STEER_RIGHT_W3_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_RIGHT_W4_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_RIGHT_W5_ANGLE   35
#define NAV_SERVO_STEER_RIGHT_W6_ANGLE   55

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
/* Wheel at 90 deg
        0   ___   180
           |   |
           |   |
           |   |
           -----
  <<< neg         pos >>>
 */

/* Servo Steer Left Angle */
#define NAV_SERVO_STEER_LEFT_W1_ANGLE   -55
#define NAV_SERVO_STEER_LEFT_W2_ANGLE   -35
#define NAV_SERVO_STEER_LEFT_W3_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_LEFT_W4_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_LEFT_W5_ANGLE   -55
#define NAV_SERVO_STEER_LEFT_W6_ANGLE   -35



/* Servo Steer Right Angle */

#define NAV_DC_MOTOR_STEER_RIGHT_W1_SPEED 45
#define NAV_DC_MOTOR_STEER_RIGHT_W2_SPEED 45
#define NAV_DC_MOTOR_STEER_RIGHT_W3_SPEED 0 /* No Speed Control */
#define NAV_DC_MOTOR_STEER_RIGHT_W4_SPEED 0 /* No Speed Control */
#define NAV_DC_MOTOR_STEER_RIGHT_W5_SPEED 45
#define NAV_DC_MOTOR_STEER_RIGHT_W6_SPEED 45


#define NAV_DC_MOTOR_STEER_LEFT_W1_SPEED 45
#define NAV_DC_MOTOR_STEER_LEFT_W2_SPEED 45
#define NAV_DC_MOTOR_STEER_LEFT_W3_SPEED 0 /* No Speed Control */
#define NAV_DC_MOTOR_STEER_LEFT_W4_SPEED 0 /* No Speed Control */
#define NAV_DC_MOTOR_STEER_LEFT_W5_SPEED 45
#define NAV_DC_MOTOR_STEER_LEFT_W6_SPEED 45

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

/******************************************** Macro Functions *************************************************************/

/******************************************** User-Defined Data Type Declaration ********************************************/

/******************************************** Software Interfaces (Prototypes) ********************************************/


Std_ReturnType Robot_Move_Forward(mssp_i2c_st *_i2c_obj);
Std_ReturnType Robot_Steer_Right_Forward(mssp_i2c_st *_i2c_obj);
Std_ReturnType Robot_Steer_Left_Forward(mssp_i2c_st *_i2c_obj);
Std_ReturnType Robot_Move_Backward(mssp_i2c_st *_i2c_obj);
Std_ReturnType Robot_Steer_Right_Backward(mssp_i2c_st *_i2c_obj);
Std_ReturnType Robot_Steer_Left_Backward(mssp_i2c_st *_i2c_obj);



/******************************************** Global Shared Variables ********************************************/


/******************************************** Global Static Variables ********************************************/

static dc_motor_st W1_W3_W5_Motor_Driver =
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

static dc_motor_st W2_W4_W6_Motor_Driver =
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







#endif /* ROBOT_NAVIGATION_H */