/* 
 * File:   application.h
 * Author: ahmed radwan
 *
 * Created on September 16, 2022, 7:47 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/*include section*/
#include"MCAL/std_libraries.h"
#include"MCAL/GPIO/hal_gpio.h"
#include "MCAL/EUSART/mcal_EUSART.h"
#include "ECU/Bluetooth/Bluetooth.h"
#include "Robot/Navigation/robot_navigation.h"
#include "ECU/LCD_for_test_gps/ecu_char_lcd.h"
#include"MCAL/Interrupts/mcal_external_interrupt.h"
#include "ECU/stepper/ecu_stepper.h"
#include "Robot/sensors/DHT11/DHT.h"
#include"Robot/sensors/ultrasonic/ultrasonic.h"
#include"MCAL/WATCH_DOG_TIMER/WDT.h"
#include "MCAL/ADC/mcal_adc.h"

/*macros declarations section*/

#define NOTHING               0
#define LEFT_FORWARD          1
#define FORWARD               2
#define RIGHT_FORWARD         3
#define TURN_LEFT             4
#define TURN_RIGHT            5
#define LEFT_BACKWARD         6
#define BACKWARD              7
#define RIGHT_BACKWARD        8
#define ROTATE_LEFT           9
#define ROTATE_RIGHT          10
////////ARM SECTION/////////
#define BASE_DECREASE         16
#define BASE_INCREAS          17
#define JOINT1_DECREASE       18
#define JOINT1_INCREASE       19
#define JOINT2_DECREASE       20
#define JOINT2_INCREASE       21
#define JOINT3_DECREASE       22
#define JOINT3_INCREASE       23
#define JOINT4_DECREASE       24
#define JOINT4_INCREASE       25
///////////sensors////////////
#define GET_T_RH 77
#define GET_DISTANCE 78
#define GET_LOCATION 79

/*
ROBOT CAR MODEL
    .......
.../       \...
:::::Front:::::

W1----------W2
servo1      servo2

W3----------W4


W5----------W6
servo3      servo4
:::::Back:::::
\            /
 \__________/

*/

///////////servos///////////
#define SERVO_W1 0
#define SERVO_W2 1
#define SERVO_W5 2
#define SERVO_W6 3

#define SERVO_JOINNT_1 4
#define SERVO_JOINNT_2 5
#define SERVO_JOINNT_3 6
#define SERVO_JOINNT_4 7



/*functions like macros section*/

/*data types  section*/

typedef struct {
    uint8_t flag_0 : 1 ;
    uint8_t flag_1 : 1 ;
    uint8_t flag_2 : 1 ;
    uint8_t flag_3 : 1 ;
    uint8_t flag_4 : 1 ;
    uint8_t flag_5 : 1 ;
    uint8_t flag_6 : 1 ;
    uint8_t flag_7 : 1 ;
}Flags_st;

/*function declarations section*/
void application_intialize(void);


#endif	/* APPLICATION_H */

