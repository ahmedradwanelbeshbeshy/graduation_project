/* 
 * File:   WDT.h
 * Author: ahmed radwan
 *
 * Created on November 8, 2022, 11:54 PM
 */

#ifndef WDT_H
#define	WDT_H
/*include section*/
#include"../std_libraries.h"
#include "../mcal_std_types.h"
/*********************************************************************
 * the watch dog timwe clock source came from intrc which provide 32kHZ frequency then devision on 128 from here
 * we could control the desired time to reset by chose the postscaler value in configurations bits 
 *  we set the postscaler on value 512 wich provide reset after 2 seconds
 ******************************************************************************
 */

/*macros declarations section*/
 #define Reset_Watch_Dog_Timer()  asm("clrwdt")  //to reset the wdt counter 

/*data types  section*/
typedef enum {
    wdt_postscaler_BY_1 = 0,
    wdt_postscaler_BY_2,
    wdt_postscaler_BY_4,
    wdt_postscaler_BY_8,
    wdt_postscaler_BY_16,
    wdt_postscaler_BY_32,
    wdt_postscaler_BY_64,
    wdt_postscaler_BY_128,
    wdt_postscaler_BY_256,
    wdt_postscaler_BY_512,
    wdt_postscaler_BY_1024,              
    wdt_postscaler_BY_2048,
    wdt_postscaler_BY_4096,
    wdt_postscaler_BY_8192,
    wdt_postscaler_BY_16384,
    wdt_postscaler_BY_32768            
}wdt_postscaler_et; //not used to set the postscaler go to configuration bits  or to file device_config.h line 18
/*function declarations section*/
Std_ReturnType WDT_Init(void);
Std_ReturnType WDT_DeInit(void);


#endif	/* WDT_H */

