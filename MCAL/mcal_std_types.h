/* 
 * File:   mcal_std_types.h
 * Author: ahmed radwan
 *
 * Created on June 28, 2022, 4:25 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/*include section*/




/*data types  section*/



typedef unsigned char        uint8;
typedef unsigned short       uint16;
typedef unsigned long        uint32;


typedef signed char          sint8;
typedef signed short         sint16;
typedef signed long          sint32;

typedef float                float32;

typedef uint8                Std_returnType;


/*macros declarations section*/
#define NULL ((void*)0)

#define STD_HIGH                0x01
#define STD_LOW                 0x00


   
#define STD_ON                  0x01
#define STD_OFF                 0x00

#define STD_ACTIVE              0x01
#define STD_IDLE                0x00

#define E_OK         (Std_returnType)  0x01
#define E_NOK        (Std_returnType)  0x00
#define E_NOT_OK     (Std_returnType)  0x00 

#define ZERO_INIT        0
/*function declarations section*/

#endif	/* MCAL_STD_TYPES_H */

