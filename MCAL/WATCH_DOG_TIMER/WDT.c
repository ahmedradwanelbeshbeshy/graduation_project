/* 
 * File:   WDT.c
 * Author: ahmed radwan
 *
 * Created on November , 2022, 11:54 PM
 */
#include"WDT.h"
Std_ReturnType WDT_Init(void)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    WDTCONbits.SWDTEN=1;
    return ERRORSTATUS;  
}
Std_ReturnType WDT_DeInit(void)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    WDTCONbits.SWDTEN=0;
    return ERRORSTATUS;  
}