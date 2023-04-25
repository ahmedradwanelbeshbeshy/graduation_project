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
Std_ReturnType Robot_Steer_Right_Backward(void);
Std_ReturnType Robot_Steer_Left_Backward(void);
/******************************************** Function prototypes ********************************************/


/******************************************** Global Shared Variables ********************************************/

Nav_Movement_State_et Movement_State = NAV_MOV_STOPPED ;


/******************************************** Global Static Variables ********************************************/






#endif /* ROBOT_NAVIGATION_H */