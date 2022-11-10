/* 
 * File:   IR_SENSOR.h
 * Author: Ahmed Elsayed
 *
 * Created on November 8, 2022, 2:50 PM
 */

#ifndef IR_SENSOR_H
#define	IR_SENSOR_H

/******************************************** Includes ********************************************/
#include "../../MCAL/GPIO/hal_gpio.h"
/******************************************** Macro Defines ***************************************************************/

/******************************************** Macro Functions *************************************************************/


/******************************************** User-Defined Data Type Declaration ********************************************/
typedef struct
{
    pin_config_st IR_Sensor_Obstacle_cfg_pin ;
}IR_cfg_t; 

/******************************************** Software Interfaces (Prototypes) ********************************************/
   Std_ReturnType IR_Sensor_Init(const IR_cfg_t *IR_sensor);
   Std_ReturnType IR_Sensor_DeInit(const IR_cfg_t *IR_sensor);
   Std_ReturnType IR_Sensor_Detect(const IR_cfg_t *IR_sensor);

#endif	/* IR_SENSOR_H */

