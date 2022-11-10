/* 
 * File:   IR_SENSOR.c
 * Author: Ahmed Elsayed
 *
 * Created on November 8, 2022, 2:50 PM
 */
#include"IR_SENSOR.h"

/************************************************************************************************************************/
Std_ReturnType IR_Sensor_Init(const IR_cfg_t *IR_sensor) 
{
    Std_ReturnType ret_value = E_OK ;
    if(NULL == IR_sensor)
    {
        ret_value = E_NOT_OK ;
    }
    else
    {
        ret_value = GPIO_Pin_Initialize(&(IR_sensor->IR_Sensor_Obstacle_cfg_pin));
    }
    return ret_value ;
}
Std_ReturnType IR_Sensor_DeInit(const IR_cfg_t *IR_sensor)
{
    Std_ReturnType ret_value = E_OK ;
    if(NULL == IR_sensor)
    {
        ret_value = E_NOT_OK ;
    }
    else
    { 
        
    }
    return ret_value ;
}
Std_ReturnType IR_Sensor_Detect(const IR_cfg_t *IR_sensor,logic_et *status)
{
    Std_ReturnType ret_value = E_OK ;
    if(NULL == IR_sensor)
    {
        ret_value = E_NOT_OK ;
    }
    else
    {
      GPIO_Pin_Read_Logic(&(IR_sensor->IR_Sensor_Obstacle_cfg_pin), status);   
    }
    return ret_value ;
}