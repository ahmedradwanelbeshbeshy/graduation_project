/* 
 * File:   ecu_dc_motor.c
 * Author: ahmed
 *
 * Created on July 23, 2022, 8:35 AM
 */

#include "ecu_dc_motor.h"

/* Global Variables*/


/**
 * @brief 
 * 
 * @param dc_motor 
 * @return Std_ReturnType 
 */
Std_ReturnType ECU_DC_Motor_Init(const dc_motor_st *dc_motor)
{
    Std_ReturnType ret_value = E_OK ;
    if(NULL == dc_motor)
    {
        ret_value = E_NOT_OK ;
    }
    else
    {
        GPIO_Pin_Initialize(&(dc_motor->dc_motor[DC_MOTOR_LEFT_PIN]));
        GPIO_Pin_Initialize(&(dc_motor->dc_motor[DC_MOTOR_RIGHT_PIN]));
    }

    return ret_value ;
}

/**
 * @brief 
 * @param dc_motor
 * @return Std_ReturnType
 */
Std_ReturnType ECU_DC_Motor_Run_Left(const dc_motor_st *dc_motor)
{
    Std_ReturnType ret_value = E_OK ;
    if(NULL == dc_motor)
    {
        ret_value = E_NOT_OK ;
    }
    else
    {
        GPIO_Pin_Write_Logic(&(dc_motor->dc_motor[DC_MOTOR_LEFT_PIN]) , GPIO_HIGH );
        GPIO_Pin_Write_Logic(&(dc_motor->dc_motor[DC_MOTOR_RIGHT_PIN]) , GPIO_LOW );
    }

    return ret_value ;
}
/**
 * @brief 
 * 
 * @param dc_motor 
 * @return Std_ReturnType 
 */
Std_ReturnType ECU_DC_Motor_Run_Right(const dc_motor_st *dc_motor)
{
    Std_ReturnType ret_value = E_OK ;
    if(NULL == dc_motor)
    {
        ret_value = E_NOT_OK ;
    }
    else
    {
        GPIO_Pin_Write_Logic(&(dc_motor->dc_motor[DC_MOTOR_LEFT_PIN]) , GPIO_LOW );
        GPIO_Pin_Write_Logic(&(dc_motor->dc_motor[DC_MOTOR_RIGHT_PIN]) , GPIO_HIGH );
    }

    return ret_value ;
}
/**
 * @brief 
 * 
 * @param dc_motor 
 * @return Std_ReturnType 
 */
Std_ReturnType ECU_DC_Motor_Stop(const dc_motor_st *dc_motor)
{
    Std_ReturnType ret_value = E_OK ;
    if(NULL == dc_motor)
    {
        ret_value = E_NOT_OK ;
    }
    else
    {
        GPIO_Pin_Write_Logic(&(dc_motor->dc_motor[DC_MOTOR_LEFT_PIN]) , GPIO_LOW );
        GPIO_Pin_Write_Logic(&(dc_motor->dc_motor[DC_MOTOR_RIGHT_PIN]) , GPIO_LOW );
    }

    return ret_value ;
}