/* 
 * File:   robot_navigation.c
 * Author: Ahmed Odb
 * Created on October 13, 2022, 7:22 AM
 */

#include "./robot_navigation.h"




Std_ReturnType Robot_Nav_Init(mssp_i2c_st *_i2c_obj)
{
    Std_ReturnType ret_val = E_OK ;
    
    if(NULL == _i2c_obj)
    {
        ret_val = E_NOT_OK ;
    }
    else
    {
        
    }
    
    return ret_val ;
}


Std_ReturnType Robot_Move_Forward(mssp_i2c_st *_i2c_obj)
{
    Std_ReturnType ret_val = E_OK ;
    
    if(NULL == _i2c_obj)
    {
        ret_val = E_NOT_OK ;
    }
    else
    {
        
    }
    
    return ret_val ;
}
Std_ReturnType Robot_Steer_Right_Forward(mssp_i2c_st *_i2c_obj)
{
    Std_ReturnType ret_val = E_OK ;
    
    if(NULL == _i2c_obj)
    {
        ret_val = E_NOT_OK ;
    }
    else
    {
        
    }
    
    return ret_val ;
}
Std_ReturnType Robot_Steer_Left_Forward(mssp_i2c_st *_i2c_obj)
{
    Std_ReturnType ret_val = E_OK ;
    
    if(NULL == _i2c_obj)
    {
        ret_val = E_NOT_OK ;
    }
    else
    {
        
    }
    
    return ret_val ;
}
Std_ReturnType Robot_Move_Backward(mssp_i2c_st *_i2c_obj)
{
    Std_ReturnType ret_val = E_OK ;
    
    if(NULL == _i2c_obj)
    {
        ret_val = E_NOT_OK ;
    }
    else
    {
        
    }
    
    return ret_val ;
}
Std_ReturnType Robot_Steer_Right_Backward(mssp_i2c_st *_i2c_obj)
{
    Std_ReturnType ret_val = E_OK ;
    
    if(NULL == _i2c_obj)
    {
        ret_val = E_NOT_OK ;
    }
    else
    {
        
    }
    
    return ret_val ;
}
Std_ReturnType Robot_Steer_Left_Backward(mssp_i2c_st *_i2c_obj)
{
    Std_ReturnType ret_val = E_OK ;
    
    if(NULL == _i2c_obj)
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
    
}

