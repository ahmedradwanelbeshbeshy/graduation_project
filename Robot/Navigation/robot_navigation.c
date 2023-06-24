/* 
 * File:   robot_navigation.c
 * Author: Ahmed Odb
 * Created on October 13, 2022, 7:22 AM
 */

#include "./robot_navigation.h"

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
extern ccp_st CCP1_Obj;

/* CCP2 :  W1 , W4 , W6     (Right Side) */
extern ccp_st CCP2_Obj;

/*i2c and servos */
extern mssp_i2c_st i2c_obj;
extern servo_driver_st servo_driver_obj;


Std_ReturnType Robot_Nav_Init(void)
{
    Std_ReturnType ret_val = E_OK ;
    

        /* Init Motor */
        ECU_DC_Motor_Init(&W1_W3_W5_Motor_Control);
        ECU_DC_Motor_Init(&W2_W4_W6_Motor_Control);

        /* Init CCP and set PWM */
        CCP_Init(&CCP1_Obj);
        CCP_Init(&CCP2_Obj);
        CCP_PWM_Set_Duty(&CCP1_Obj , NAV_DC_MOTOR_stop);
        CCP_PWM_Set_Duty(&CCP2_Obj , NAV_DC_MOTOR_stop);
        CCP_PWM_Start(&CCP1_Obj);
        CCP_PWM_Start(&CCP2_Obj);
        
       
        /* Init Servo Driver */
        ServoDriver_Init(&i2c_obj,&servo_driver_obj);

    
    return ret_val ;
}
Std_ReturnType Robot_Move_Forward(void)
{
    Std_ReturnType ret_val = E_OK ;
    

            Movement_State = NAV_MOV_FORW ;
            /*first we stop dc motors*/
            Robot_Steer_Stop(); 
            /*then set all servos on the desires angle*/
            Servo_SetAngle(&i2c_obj , &servo_driver_obj , servo_index_1 , NAV_SERVO_NO_STEER_ANGLE );    // W1 
            Servo_SetAngle(&i2c_obj , &servo_driver_obj , servo_index_2 , NAV_SERVO_NO_STEER_ANGLE );    // W2
            Servo_SetAngle(&i2c_obj , &servo_driver_obj , servo_index_3 , NAV_SERVO_NO_STEER_ANGLE );    // W5
            Servo_SetAngle(&i2c_obj , &servo_driver_obj , servo_index_4 , NAV_SERVO_NO_STEER_ANGLE );    // W6
            /*set the direction of rotation */
            ECU_DC_Motor_Run_Right(&W1_W3_W5_Motor_Control);
            ECU_DC_Motor_Run_Right(&W2_W4_W6_Motor_Control);
            /*set  the speed and run  motors */
            CCP_PWM_Set_Duty(&CCP1_Obj , NAV_SPEED_W1_W3_W5_DEFAULT);
            CCP_PWM_Set_Duty(&CCP2_Obj , NAV_SPEED_W2_W4_W6_DEFAULT);


        
    return ret_val ;
}
Std_ReturnType Robot_Move_Backward(void)
{
    Std_ReturnType ret_val = E_OK ;
      Movement_State = NAV_MOV_BACKW ;
      /*first we stop dc motors*/
      Robot_Steer_Stop();
      /*then set all servos on the desires angle*/
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , servo_index_1 , NAV_SERVO_NO_STEER_ANGLE );    // W1
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , servo_index_2 , NAV_SERVO_NO_STEER_ANGLE );    // W2
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , servo_index_3 , NAV_SERVO_NO_STEER_ANGLE );    // W5
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , servo_index_4 , NAV_SERVO_NO_STEER_ANGLE );    // W6
      /*set the direction of rotation */
      ECU_DC_Motor_Run_Left(&W1_W3_W5_Motor_Control);
      ECU_DC_Motor_Run_Left(&W2_W4_W6_Motor_Control);
      /*set  the speed and run  motors */
      CCP_PWM_Set_Duty(&CCP1_Obj , NAV_SPEED_W1_W3_W5_DEFAULT);
      CCP_PWM_Set_Duty(&CCP2_Obj , NAV_SPEED_W1_W3_W5_DEFAULT);


    return ret_val ;
}

Std_ReturnType Robot_Steer_Right_Forward(void)
{
    Std_ReturnType ret_val = E_OK ;
    
        
      Movement_State = NAV_MOV_FORW_STEER_RIGHT ;
      /*first we stop dc motors*/
      Robot_Steer_Stop();
      /*then set all servos on the desires angle*/
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W1 , NAV_SERVO_STEER_RIGHT_FORWARD_W1_ANGLE );    // W1
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W2 , NAV_SERVO_STEER_RIGHT_FORWARD_W2_ANGLE );    // W2
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W5 , NAV_SERVO_STEER_RIGHT_FORWARD_W5_ANGLE );    // W5
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W6 , NAV_SERVO_STEER_RIGHT_FORWARD_W6_ANGLE );    // W6
      /*set the direction of rotation */
      ECU_DC_Motor_Run_Right(&W1_W3_W5_Motor_Control);
      ECU_DC_Motor_Run_Right(&W2_W4_W6_Motor_Control);
      /*set  the speed and run  motors */
      CCP_PWM_Set_Duty(&CCP1_Obj , NAV_DC_MOTOR_STEER_RIGHT_FORWARD_W1_row_SPEED);           
      CCP_PWM_Set_Duty(&CCP2_Obj , NAV_DC_MOTOR_STEER_RIGHT_FORWARD_W2_row_SPEED);
    
    return ret_val ;
}
Std_ReturnType Robot_Steer_Left_Forward(void)
{
    Std_ReturnType ret_val = E_OK ;
            Movement_State = NAV_MOV_FORW_STEER_LEFT ;       
     /*first we stop dc motors*/
      Robot_Steer_Stop();
      /*then set all servos on the desires angle*/
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W1 , NAV_SERVO_STEER_LEFT_FORWARD_W1_ANGLE );    // W1
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W2 , NAV_SERVO_STEER_LEFT_FORWARD_W2_ANGLE );    // W2
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W5 , NAV_SERVO_STEER_LEFT_FORWARD_W5_ANGLE );    // W5
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W6 , NAV_SERVO_STEER_LEFT_FORWARD_W6_ANGLE );    // W6
      /*set the direction of rotation */
      ECU_DC_Motor_Run_Right(&W1_W3_W5_Motor_Control);
      ECU_DC_Motor_Run_Right(&W2_W4_W6_Motor_Control);
      /*set  the speed and run  motors */
      CCP_PWM_Set_Duty(&CCP1_Obj , NAV_DC_MOTOR_STEER_LEFT_FORWARD_W1_row_SPEED);           
      CCP_PWM_Set_Duty(&CCP2_Obj , NAV_DC_MOTOR_STEER_LEFT_FORWARD_W2_row_SPEED);
    
    
    return ret_val ;
}
Std_ReturnType Robot_Steer_Right_Backward(void)
{
       Std_ReturnType ret_val = E_OK ;
    
      /*first we stop dc motors*/
      Robot_Steer_Stop();
      /*then set all servos on the desires angle*/
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W1 , NAV_SERVO_STEER_RIGHT_BACKWARD_W1_ANGLE );    // W1
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W2 , NAV_SERVO_STEER_RIGHT_BACKWARD_W2_ANGLE );    // W2
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W5 , NAV_SERVO_STEER_RIGHT_BACKWARD_W5_ANGLE );    // W5
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W6 , NAV_SERVO_STEER_RIGHT_BACKWARD_W6_ANGLE );    // W6
      /*set the direction of rotation */
      ECU_DC_Motor_Run_Left(&W1_W3_W5_Motor_Control);
      ECU_DC_Motor_Run_Left(&W2_W4_W6_Motor_Control);
      /*set  the speed and run  motors */
      CCP_PWM_Set_Duty(&CCP1_Obj , NAV_DC_MOTOR_STEER_RIGHT_BACKWARD_W1_row_SPEED);           
      CCP_PWM_Set_Duty(&CCP2_Obj , NAV_DC_MOTOR_STEER_RIGHT_BACKWARD_W2_row_SPEED);
    
    return ret_val;
    
}
Std_ReturnType Robot_Steer_Left_Backward(void)
{
      Std_ReturnType ret_val = E_OK ;
     /*first we stop dc motors*/
      Robot_Steer_Stop();
      /*then set all servos on the desires angle*/
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W1 , NAV_SERVO_STEER_LEFT_BACKWARD_W1_ANGLE );    // W1
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W2 , NAV_SERVO_STEER_LEFT_BACKWARD_W2_ANGLE );    // W2
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W5 , NAV_SERVO_STEER_LEFT_BACKWARD_W5_ANGLE );    // W5
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W6 , NAV_SERVO_STEER_LEFT_BACKWARD_W6_ANGLE );    // W6
      /*set the direction of rotation */
      ECU_DC_Motor_Run_Left(&W1_W3_W5_Motor_Control);
      ECU_DC_Motor_Run_Left(&W2_W4_W6_Motor_Control);
      /*set  the speed and run  motors */
      CCP_PWM_Set_Duty(&CCP1_Obj , NAV_DC_MOTOR_STEER_LEFT_BACKWARD_W1_row_SPEED);           
      CCP_PWM_Set_Duty(&CCP2_Obj , NAV_DC_MOTOR_STEER_LEFT_BACKWARD_W2_row_SPEED);
    
    
    return ret_val ;
    
}
Std_ReturnType Robot_Steer_Stop(void)
{
        Std_ReturnType ret_val = E_OK ;
            CCP_PWM_Set_Duty(&CCP1_Obj , NAV_DC_MOTOR_stop);           
            CCP_PWM_Set_Duty(&CCP2_Obj , NAV_DC_MOTOR_stop);
              return ret_val ;
}
Std_ReturnType Robot_Steer_Right(void)
{
    Std_ReturnType ret_val = E_OK ;
    
        
      Movement_State = NAV_MOV_FORW_STEER_RIGHT ;
      /*first we stop dc motors*/
      Robot_Steer_Stop();
      /*then set all servos on the desires angle*/
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W1 , NAV_SERVO_NO_STEER_ANGLE );    // W1
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W2 , NAV_SERVO_NO_STEER_ANGLE );    // W2
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W5 , NAV_SERVO_NO_STEER_ANGLE );    // W5
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W6 , NAV_SERVO_NO_STEER_ANGLE );    // W6
      /*set the direction of rotation */
      ECU_DC_Motor_Run_Right(&W1_W3_W5_Motor_Control);
      ECU_DC_Motor_Run_Right(&W2_W4_W6_Motor_Control);
      /*set  the speed and run  motors */
      CCP_PWM_Set_Duty(&CCP1_Obj , NAV_DC_MOTOR_STEER_RIGHT_FORWARD_W1_row_SPEED);           
      CCP_PWM_Set_Duty(&CCP2_Obj , 0);
    
    return ret_val ;
}
Std_ReturnType Robot_Steer_Left(void)
{
    Std_ReturnType ret_val = E_OK ;
            Movement_State = NAV_MOV_FORW_STEER_LEFT ;       
     /*first we stop dc motors*/
      Robot_Steer_Stop();
      /*then set all servos on the desires angle*/
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W1 , NAV_SERVO_NO_STEER_ANGLE );    // W1
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W2 , NAV_SERVO_NO_STEER_ANGLE );    // W2
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W5 , NAV_SERVO_NO_STEER_ANGLE );    // W5
      Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W6 , NAV_SERVO_NO_STEER_ANGLE );    // W6
      /*set the direction of rotation */
      ECU_DC_Motor_Run_Right(&W1_W3_W5_Motor_Control);
      ECU_DC_Motor_Run_Right(&W2_W4_W6_Motor_Control);
      /*set  the speed and run  motors */
      CCP_PWM_Set_Duty(&CCP1_Obj , 0);           
      CCP_PWM_Set_Duty(&CCP2_Obj , NAV_DC_MOTOR_STEER_LEFT_FORWARD_W2_row_SPEED);
    
    
    return ret_val ;
}