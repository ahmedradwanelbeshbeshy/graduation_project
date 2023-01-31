/* 
 * File:   mcal_timer2.c
 * Author: ahmed radwan
 *
 * Created on August 29, 2022, 11:54 PM
 */
#include"mcal_timer2.h"

#if TIMER0_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE   
static void (*Timer2_Interrupt_Handler)(void)=NULL;
#endif

uint8 Timer2_PreLoaded_Value_Store=ZERO_INIT;


Std_ReturnType Timer2_Init(const timer2_st* _timer2)
{
     Std_ReturnType ERRORSTATUS =E_OK;
    if (NULL==_timer2)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        /*timer1 disable*/
        TIMER2_DISABLE();
        /*timer1 set the Prescaler */
        TIMER2_PRESCALER_SET_VALUE(_timer2->timer2_prescaler_value);
         /*timer1 set the postscaler */
        TIMER2_POSTSCALER_SET_VALUE(_timer2->timer2_postscaler_value);      
        /*set the preloaded value*/
        TMR2=_timer2->timer2_preload_value;
        Timer2_PreLoaded_Value_Store=_timer2->timer2_preload_value;
        /*interrupt set*/
#if TIMER2_INT_ENABLE ==FEATURE_ENABLE
        INT_TMR2_DISABLE();
            #if INT_PRI_LEVELS_ENABLE==FEATURE_ENABLE
            INT_PRI_FET_EN();
        if(INT_PRI_HIGH==_timer2->priority)
        {
            INT_GLOBAL_HIGH_EN();
            INT_TMR2_PRI_SET_HIGH();
        }
        else if(INT_PRI_LOW==_timer2->priority)
        {
                    INT_GLOBAL_LOW_EN();
            INT_TMR2_PRI_SET_LOW();
        }
            else{/*no thing*/}

#else

                 INT_GLOBAL_EN();
                 INT_PERIPHERAL_EN();
#endif 
        INT_TMR2_ENABLE();
        INT_TMR2_CLEAR_FLAG();
        Timer2_Interrupt_Handler=_timer2->Timer2_InterruptHandler;
 
#endif
        TIMER2_ENABLE();
    }
    return ERRORSTATUS;       
}
Std_ReturnType Timer2_DeInit(const timer2_st* _timer2)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if (NULL==_timer2)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        TIMER2_DISABLE();
        #if TIMER2_INT_ENABLE ==FEATURE_ENABLE 
        INT_TMR2_DISABLE();
        #endif
    }
    return ERRORSTATUS;    
}
Std_ReturnType Timer2_Write_Value(const timer2_st* _timer2,uint8 value)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if (NULL==_timer2)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        TMR2=value;
    }
    return ERRORSTATUS;    
   
}
Std_ReturnType Timer2_Read_Value(const timer2_st* _timer2,uint8 *value)
{
     
    Std_ReturnType ERRORSTATUS =E_OK;
    if ((NULL==_timer2)||(NULL==value ))
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        *value=TMR2;
    }
    return ERRORSTATUS;   
    
}
void TMR2_ISR(void)
{
#if TIMER2_INT_ENABLE==FEATURE_ENABLE
   INT_TMR2_CLEAR_FLAG();
   TMR2=Timer2_PreLoaded_Value_Store;
   if(Timer2_Interrupt_Handler){Timer2_Interrupt_Handler();}
#endif
}