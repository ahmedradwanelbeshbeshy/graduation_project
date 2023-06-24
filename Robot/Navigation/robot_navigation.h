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



/* Servo Steer Right FORWARD Angle */
#define NAV_SERVO_STEER_RIGHT_FORWARD_W1_ANGLE   135 
#define NAV_SERVO_STEER_RIGHT_FORWARD_W2_ANGLE   120
#define NAV_SERVO_STEER_RIGHT_FORWARD_W3_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_RIGHT_FORWARD_W4_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_RIGHT_FORWARD_W5_ANGLE   45
#define NAV_SERVO_STEER_RIGHT_FORWARD_W6_ANGLE   30

/* Servo Steer Right BACKWARD Angle */
#define NAV_SERVO_STEER_RIGHT_BACKWARD_W1_ANGLE   135 
#define NAV_SERVO_STEER_RIGHT_BACKWARD_W2_ANGLE   120
#define NAV_SERVO_STEER_RIGHT_BACKWARD_W3_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_RIGHT_BACKWARD_W4_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_RIGHT_BACKWARD_W5_ANGLE   45
#define NAV_SERVO_STEER_RIGHT_BACKWARD_W6_ANGLE   30

/* Servo Steer Left FORWARD Angle */
#define NAV_SERVO_STEER_LEFT_FORWARD_W1_ANGLE   45
#define NAV_SERVO_STEER_LEFT_FORWARD_W2_ANGLE   30
#define NAV_SERVO_STEER_LEFT_FORWARD_W3_ANGLE    0 /* No Steering Servo */
#define NAV_SERVO_STEER_LEFT_FORWARD_W4_ANGLE    0 /* No Steering Servo */
#define NAV_SERVO_STEER_LEFT_FORWARD_W5_ANGLE   135
#define NAV_SERVO_STEER_LEFT_FORWARD_W6_ANGLE   120

/* Servo Steer Left BACKWARD Angle */
#define NAV_SERVO_STEER_LEFT_BACKWARD_W1_ANGLE   45
#define NAV_SERVO_STEER_LEFT_BACKWARD_W2_ANGLE   30
#define NAV_SERVO_STEER_LEFT_BACKWARD_W3_ANGLE    0 /* No Steering Servo */
#define NAV_SERVO_STEER_LEFT_BACKWARD_W4_ANGLE    0 /* No Steering Servo */
#define NAV_SERVO_STEER_LEFT_BACKWARD_W5_ANGLE   135
#define NAV_SERVO_STEER_LEFT_BACKWARD_W6_ANGLE   120


/* Starting Wheels Speed */
#define NAV_SPEED_W2_W4_W6_DEFAULT      85
#define NAV_SPEED_W1_W3_W5_DEFAULT      85

/* Servo Steer Right_FORWARD Speed */

#define NAV_DC_MOTOR_STEER_RIGHT_FORWARD_W1_row_SPEED 85
#define NAV_DC_MOTOR_STEER_RIGHT_FORWARD_W2_row_SPEED 45

/* Servo Steer Left_FORWARD Speed */

#define NAV_DC_MOTOR_STEER_LEFT_FORWARD_W1_row_SPEED 45
#define NAV_DC_MOTOR_STEER_LEFT_FORWARD_W2_row_SPEED 85

/* Servo Steer Right_BACKWARD Speed */

#define NAV_DC_MOTOR_STEER_RIGHT_BACKWARD_W1_row_SPEED 85
#define NAV_DC_MOTOR_STEER_RIGHT_BACKWARD_W2_row_SPEED 45

/* Servo Steer Left_BACKWARD Speed */

#define NAV_DC_MOTOR_STEER_LEFT_BACKWARD_W1_row_SPEED 45
#define NAV_DC_MOTOR_STEER_LEFT_BACKWARD_W2_row_SPEED 85

#define NAV_DC_MOTOR_stop 0

///////////servos///////////
#define SERVO_W1 0
#define SERVO_W2 1
#define SERVO_W5 2
#define SERVO_W6 3

#define SERVO_JOINNT_1 8
#define SERVO_JOINNT_2 9
#define SERVO_JOINNT_3 10
#define SERVO_JOINNT_4 11



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
Std_ReturnType Robot_Steer_Right_Backward(void);
Std_ReturnType Robot_Steer_Left_Backward(void);
Std_ReturnType Robot_Steer_Right(void);
Std_ReturnType Robot_Steer_Left(void);
/******************************************** Function prototypes ********************************************/


/******************************************** Global Shared Variables ********************************************/

Nav_Movement_State_et Movement_State = NAV_MOV_STOPPED ;


/******************************************** Global Static Variables ********************************************/






#endif /* ROBOT_NAVIGATION_H */