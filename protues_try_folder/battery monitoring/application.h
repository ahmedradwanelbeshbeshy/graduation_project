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
#include"MCAL/Interrupts/mcal_external_interrupt.h"

/*macros declarations section*/

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

