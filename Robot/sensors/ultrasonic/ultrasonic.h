/* 
 * File:   ultrasonic.h
 * Author: ahmed radwan
 *
 * Created on January 23, 2023, 8:56 PM
 */

#ifndef ULTRASONIC_H
#define	ULTRASONIC_H
/*
 ************************************************************************************************************
 * -> note if you change the value of crystal osc you should change the divider in function Get_Distance <- *
 ************************************************************************************************************
 */

/*******************INCLUDE SECTION***************/
#include "../../../MCAL/GPIO/hal_gpio.h"
#include"../../../MCAL/Timer0/hal_timer0.h"
/* Macro Defines */

/* Macro Functions */

/* User-Defined Data Type Declaration */
typedef struct{
    pin_config_st trig_pin;
    pin_config_st echo_pin;
}ultrasonic_config_st;
/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType Ultra_Sonic_Init(const ultrasonic_config_st* ultrasonic_object,const timer0_config_st *_tmr0_config);
Std_ReturnType Get_Distance(const ultrasonic_config_st* ultrasonic_object,const timer0_config_st *_tmr0_config,float32* distance);
#endif	/* ULTRASONIC_H */

