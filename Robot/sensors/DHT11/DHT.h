/* 
 * File:   DHT11.h
 * Author: ahmed radwan
 *
 * Created on January 21, 2023, 6:09 PM
 */

#ifndef DHT11_H
#define	DHT11_H
/**************************************************************************
 *                                                                       *
 *     note to use you should config the pin in DHT11_cfg.h file         *
 *                                                                       *
 *                                                                       *
 *************************************************************************/

/*******************INCLUDE SECTION***************/
#include "../../../MCAL/GPIO/hal_gpio.h"
#include"DHT_CFG.h"
/* Macro Defines */

/* Macro Functions */

/* User-Defined Data Type Declaration */

/* ----------------- Software Interfaces Declarations -----------------*/


Std_ReturnType Get_Temp_HUM(uint8* RH_Decimal,uint8* RH_Integral,uint8* T_Decimal,uint8* T_Integral,uint8* Checksum);



#endif	/* DHT11_H */

