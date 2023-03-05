/* 
 * File:   ecu_dc_motor.h
 * Author: ahmed
 *
 * Created on July 23, 2022, 8:34 AM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/* Includes */
#include "../../MCAL/GPIO/hal_gpio.h"
#include "ecu_dc_motor_config.h"


/* Macro Defines */

#define DC_MOTOR_RIGHT_PIN 0x00U
#define DC_MOTOR_LEFT_PIN  0x01U

/* Macro Functions */

/* User-Defined Data Type Declaration */

typedef enum {
    DC_MOTOR_PIN_OFF = 0,
    DC_MOTOR_PIN_ON
}dc_motor_pin_state_et ;



// typedef struct {
//     dc_motor_pin_t forward_pin ;
//     dc_motor_pin_t reverse_pin ;

// }dc_motor_t ;

typedef struct {
    pin_config_st dc_motor[2]; // array of two pins

} dc_motor_st ;


/* Software Interfaces (Prototypes) */

Std_ReturnType ECU_DC_Motor_Init(const dc_motor_st *dc_motor);
Std_ReturnType ECU_DC_Motor_Run_Left(const dc_motor_st *dc_motor);
Std_ReturnType ECU_DC_Motor_Run_Right(const dc_motor_st *dc_motor);
Std_ReturnType ECU_DC_Motor_Stop(const dc_motor_st *dc_motor);


/* Global Shared Variables */


#endif	/* ECU_DC_MOTOR_H */

