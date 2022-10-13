/* 
 * File:   robot_navigation.c
 * Author: Ahmed Odb
 * Created on October 13, 2022, 7:22 AM
 */

#include "./robot_navigation.h"




Std_ReturnType Robot_Nav_Init(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj)
{
    Std_ReturnType ret_val = E_OK ;
    
    if((NULL == _i2c_obj) || (NULL == servo_driver_obj))
    {
        ret_val = E_NOT_OK ;
    }
    else
    {
        /* Init Motor */
        ECU_DC_Motor_Init(&W1_W5_W2_W6_Motor_Control);
        ECU_DC_Motor_Init(&W3_Motor_Control);
        ECU_DC_Motor_Init(&W4_Motor_Control);
        /* Init Timer */
        HAL_Timer0_Init(&Timer0);
        /* Init CCP and set PWM */
        CCP_Init(&CCP1_Obj);
        CCP_Init(&CCP2_Obj);
        CCP_PWM_Set_Duty(&CCP1_Obj , NAV_SPEED_W1_W3_W5_DEFAULT);
        CCP_PWM_Set_Duty(&CCP2_Obj , NAV_SPEED_W1_W3_W5_DEFAULT);
        CCP_PWM_Start(&CCP1_Obj);
        CCP_PWM_Start(&CCP2_Obj);
        
        /* If needed */
        /* Init I2C */
        /* Init Servo Driver */
    }
    
    return ret_val ;
}


Std_ReturnType Robot_Move_Forward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj)
{
    Std_ReturnType ret_val = E_OK ;
    
    if((NULL == _i2c_obj) || (NULL == servo_driver_obj))
    {
        ret_val = E_NOT_OK ;
    }
    else
    {
        HAL_Timer0_Write_Val(&Timer0 , NAV_TMR0_PRELOAD);
        
        if(Movement_State == NAV_MOV_FORW)
        {
            /* Robot Already Moving Forward Do Nothing */
        }
        else
        {
            Movement_State = NAV_MOV_FORW ;
            ECU_DC_Motor_Run_Left(&W1_W5_W2_W6_Motor_Control);
            ECU_DC_Motor_Run_Left(&W3_Motor_Control);
            ECU_DC_Motor_Run_Left(&W4_Motor_Control);
            Servo_SetAngle(_i2c_obj , servo_driver_obj , servo_index_1 , NAV_SERVO_NO_STEER_ANGLE );    // W1
            Servo_SetAngle(_i2c_obj , servo_driver_obj , servo_index_2 , NAV_SERVO_NO_STEER_ANGLE );    // W2
            Servo_SetAngle(_i2c_obj , servo_driver_obj , servo_index_3 , NAV_SERVO_NO_STEER_ANGLE );    // W3
            Servo_SetAngle(_i2c_obj , servo_driver_obj , servo_index_4 , NAV_SERVO_NO_STEER_ANGLE );    // W4
            CCP_PWM_Set_Duty(&CCP1_Obj , NAV_SPEED_W1_W3_W5_DEFAULT);
            CCP_PWM_Set_Duty(&CCP2_Obj , NAV_SPEED_W1_W3_W5_DEFAULT);
        }
    }
    
    return ret_val ;
}
Std_ReturnType Robot_Steer_Right_Forward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj)
{
    Std_ReturnType ret_val = E_OK ;
    
    if((NULL == _i2c_obj) || (NULL == servo_driver_obj))
    {
        ret_val = E_NOT_OK ;
    }
    else
    {
        
        HAL_Timer0_Write_Val(&Timer0 , NAV_TMR0_PRELOAD);
        if(Movement_State == NAV_MOV_FORW_STEER_RIGHT)
        {
            /* Robot Already Moving Forward and Steering Right */
        }
        else
        {
            Movement_State = NAV_MOV_FORW_STEER_RIGHT ;
            ECU_DC_Motor_Run_Left(&W1_W5_W2_W6_Motor_Control);
            ECU_DC_Motor_Run_Left(&W3_Motor_Control);
            ECU_DC_Motor_Run_Left(&W4_Motor_Control);
            Servo_SetAngle(_i2c_obj , servo_driver_obj , servo_index_1 , 90 + NAV_SERVO_STEER_RIGHT_W1_ANGLE );    // W1
            Servo_SetAngle(_i2c_obj , servo_driver_obj , servo_index_2 , 90 + NAV_SERVO_STEER_RIGHT_W2_ANGLE );    // W2
            Servo_SetAngle(_i2c_obj , servo_driver_obj , servo_index_3 , 90 + NAV_SERVO_STEER_RIGHT_W5_ANGLE );    // W3
            Servo_SetAngle(_i2c_obj , servo_driver_obj , servo_index_4 , 90 + NAV_SERVO_STEER_RIGHT_W6_ANGLE );    // W4
            CCP_PWM_Set_Duty(&CCP1_Obj , NAV_DC_MOTOR_STEER_RIGHT_W1_SPEED);           
            CCP_PWM_Set_Duty(&CCP2_Obj , NAV_DC_MOTOR_STEER_RIGHT_W2_SPEED);
        }
        
    }
    
    return ret_val ;
}
Std_ReturnType Robot_Steer_Left_Forward(const mssp_i2c_st *_i2c_obj  , const servo_driver_st *servo_driver_obj)
{
    Std_ReturnType ret_val = E_OK ;
    
    if((NULL == _i2c_obj) || (NULL == servo_driver_obj))
    {
        ret_val = E_NOT_OK ;
    }
    else
    {
        HAL_Timer0_Write_Val(&Timer0 , NAV_TMR0_PRELOAD);
        if(Movement_State == NAV_MOV_FORW_STEER_LEFT)
        {
            /* Robot Already Moving Forward and Steering Left */
        }
        else
        {
            Movement_State = NAV_MOV_FORW_STEER_LEFT ;       
            ECU_DC_Motor_Run_Left(&W1_W5_W2_W6_Motor_Control);
            ECU_DC_Motor_Run_Left(&W3_Motor_Control);
            ECU_DC_Motor_Run_Left(&W4_Motor_Control);
            Servo_SetAngle(_i2c_obj , servo_driver_obj , servo_index_1 , 90 + NAV_SERVO_STEER_LEFT_W1_ANGLE );    // W1
            Servo_SetAngle(_i2c_obj , servo_driver_obj , servo_index_2 , 90 + NAV_SERVO_STEER_LEFT_W2_ANGLE );    // W2
            Servo_SetAngle(_i2c_obj , servo_driver_obj , servo_index_3 , 90 + NAV_SERVO_STEER_LEFT_W3_ANGLE );    // W3
            Servo_SetAngle(_i2c_obj , servo_driver_obj , servo_index_4 , 90 + NAV_SERVO_STEER_LEFT_W4_ANGLE );    // W4
            CCP_PWM_Set_Duty(&CCP1_Obj , NAV_DC_MOTOR_STEER_LEFT_W1_SPEED);           
            CCP_PWM_Set_Duty(&CCP2_Obj , NAV_DC_MOTOR_STEER_LEFT_W2_SPEED);
        }
        
    }
    
    return ret_val ;
}
Std_ReturnType Robot_Move_Backward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj)
{
    Std_ReturnType ret_val = E_OK ;
    
    if((NULL == _i2c_obj) || (NULL == servo_driver_obj))
    {
        ret_val = E_NOT_OK ;
    }
    else
    {
        
    }
    
    return ret_val ;
}
Std_ReturnType Robot_Steer_Right_Backward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj)
{
    Std_ReturnType ret_val = E_OK ;
    
    if((NULL == _i2c_obj) || (NULL == servo_driver_obj))
    {
        ret_val = E_NOT_OK ;
    }
    else
    {
        
    }
    
    return ret_val ;
}
Std_ReturnType Robot_Steer_Left_Backward(const mssp_i2c_st *_i2c_obj , const servo_driver_st *servo_driver_obj)
{
    Std_ReturnType ret_val = E_OK ;
    
    if((NULL == _i2c_obj) || (NULL == servo_driver_obj))
    {
        ret_val = E_NOT_OK ;
    }
    else
    {
        
    }
    
    return ret_val ;
}

void Timer0_Handler()
{
    ECU_DC_Motor_Stop(&W1_W5_W2_W6_Motor_Control);
    ECU_DC_Motor_Stop(&W3_Motor_Control);
    ECU_DC_Motor_Stop(&W4_Motor_Control);
}

