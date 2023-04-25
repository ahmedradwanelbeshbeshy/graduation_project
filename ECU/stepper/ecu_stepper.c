/* 
 * File:   ecu_stepper.h
 * Author: ahmed Odb
 *
 * Created on March 5, 2023, 11:30 PM
 */
#include "ecu_stepper.h"

Std_ReturnType Ecu_Stepper_Init(stepper_config_st *stepper)
{
    if(NULL == stepper)
    {
        return E_NOT_OK ;
    }
    else
    {
        GPIO_Pin_Initialize(&(stepper->step_pin));
        GPIO_Pin_Initialize(&(stepper->dir_pin));
        GPIO_Pin_Direction_Initialize(&(stepper->dir_pin));
        GPIO_Pin_Direction_Initialize(&(stepper->step_pin));
        GPIO_Pin_Write_Logic(&(stepper->step_pin) , GPIO_LOW);
        GPIO_Pin_Write_Logic(&(stepper->dir_pin) , GPIO_LOW);
    }
    return E_OK ;
}
Std_ReturnType Ecu_Stepper_Step(stepper_config_st *stepper)
{
    if(NULL == stepper)
    {
        return E_NOT_OK ;
    }
    else
    {
        GPIO_Pin_Write_Logic(&(stepper->step_pin) , 1);
        __delay_ms(PULSE_DURATION_HIGH_MILLI_SEC);
        GPIO_Pin_Write_Logic(&(stepper->step_pin) , 0);
        __delay_ms(PULSE_DURATION_LOW_MILLI_SEC);

    }
    return E_OK ;
}
Std_ReturnType Ecu_Stepper_Change_Direction(stepper_config_st *stepper , stepper_direction_et dir)
{
    if(NULL == stepper)
    {
        return E_NOT_OK ;
    }
    else
    {
        if(dir == DIR_CW)
        {
            GPIO_Pin_Write_Logic(&(stepper->dir_pin) , GPIO_HIGH);
        }
        else
        {
            GPIO_Pin_Write_Logic(&(stepper->dir_pin) , GPIO_LOW);
        }
    }
    return E_OK ;
}
Std_ReturnType stepper_move_one_deg_cw(stepper_config_st *stepper)
{
    if(NULL == stepper)
    {
        return E_NOT_OK ;
    }
    else
    {
       GPIO_Pin_Write_Logic(&(stepper->dir_pin) , GPIO_HIGH);
        for(int i=0; i<= STEPPER_ONE_DEG_PULSE_NO; i++)
        {
            Ecu_Stepper_Step(stepper);
        }
    }
}

Std_ReturnType stepper_move_one_deg_ccw(stepper_config_st *stepper)
{
    if(NULL == stepper)
    {
        return E_NOT_OK ;
    }
    else
    {
        GPIO_Pin_Write_Logic(&(stepper->dir_pin) , GPIO_LOW);
        for(int i=0; i<= STEPPER_ONE_DEG_PULSE_NO; i++)
        {
            Ecu_Stepper_Step(stepper);
        }
    }
}