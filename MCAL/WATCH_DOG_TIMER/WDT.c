/* 
 * File:   WDT.c
 * Author: ahmed radwan
 *
 * Created on November , 2022, 11:54 PM
 */
#include"WDT.h"
/**
 * enable the watch dog timer 
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOT_OK): the function has issue to preform this action
 */
Std_ReturnType WDT_Init(void)
{
    Std_ReturnType ERRORSTATUS =E_NOT_OK;
    WDTCONbits.SWDTEN=1;
    ERRORSTATUS =E_OK;
    return ERRORSTATUS;  
}
/**
 * disable the watch dog timer
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOT_OK): the function has issue to preform this action
 */
Std_ReturnType WDT_DeInit(void)
{
    Std_ReturnType ERRORSTATUS =E_NOT_OK;
    WDTCONbits.SWDTEN=0;
     ERRORSTATUS =E_OK;
    return ERRORSTATUS;  
}