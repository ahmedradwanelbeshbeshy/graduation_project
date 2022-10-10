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


/******************************************** Macro Defines ***************************************************************/



/* Servo Starting Angle */
#define NAV_SERVO_STARTING_ANGLE 90
/* Servo MAX Steering Angle */
#define NAV_SERVO_MAX_STEERING_ANGLE 45
/* Servo MAX Steering Direction */
#define NAV_SERVO_STEER_DIR_POSITIVE   -1
#define NAV_SERVO_STEER_DIR_NEGATIVE    1

/* Servo Steer Right Angle */
#define NAV_SERVO_STEER_RIGHT_W1_ANGLE   45
#define NAV_SERVO_STEER_RIGHT_W2_ANGLE   45
#define NAV_SERVO_STEER_RIGHT_W3_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_RIGHT_W4_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_RIGHT_W5_ANGLE   45
#define NAV_SERVO_STEER_RIGHT_W6_ANGLE   45


/* Servo Steer Right Angle */
#define NAV_SERVO_STEER_LEFT_W1_ANGLE   45
#define NAV_SERVO_STEER_LEFT_W2_ANGLE   45
#define NAV_SERVO_STEER_LEFT_W3_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_LEFT_W4_ANGLE   0 /* No Steering Servo */
#define NAV_SERVO_STEER_LEFT_W5_ANGLE   45
#define NAV_SERVO_STEER_LEFT_W6_ANGLE   45

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

/******************************************** Macro Functions *************************************************************/

/******************************************** User-Defined Data Type Declaration ********************************************/

/******************************************** Software Interfaces (Prototypes) ********************************************/

/******************************************** Global Shared Variables ********************************************/



#endif /* ROBOT_NAVIGATION_H */