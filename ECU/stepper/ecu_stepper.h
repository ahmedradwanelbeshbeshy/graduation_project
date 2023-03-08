/* 
 * File:   ecu_stepper.h
 * Author: ahmed Odb
 *
 * Created on March 5, 2023, 11:30 PM
 */

#ifndef ECU_STEPPER_H
#define	ECU_STEPPER_H

#include "../../MCAL/GPIO/hal_gpio.h"

#define PULSE_DURATION_HIGH_MICRO_SEC 1000
#define PULSE_DURATION_LOW_MICRO_SEC  1000

#define PULSE_DURATION_HIGH_MILLI_SEC 1
#define PULSE_DURATION_LOW_MILLI_SEC  1

typedef struct 
{
    pin_config_st step_pin ;  
    pin_config_st dir_pin  ;  
} stepper_config_st ;

typedef enum
{
    DIR_CCW= 0,
    DIR_CW
} stepper_direction_et ;



Std_ReturnType Ecu_Stepper_Init(stepper_config_st *stepper);
Std_ReturnType Ecu_Stepper_Step(stepper_config_st *stepper);
Std_ReturnType Ecu_Stepper_Change_Direction(stepper_config_st *stepper , stepper_direction_et dir);







#endif/* ECU_STEPPER_H */

