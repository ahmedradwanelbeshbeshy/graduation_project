/* 
 * File:   TIMER1.h
 * Author: ahmed radwan
 *
 * Created on March 13, 2023, 6:36 PM
 */
#include"TIMER1.h"
static inline void Timer1_Prescaler_Config(const timer1_t* _timer1);
static inline void Timer1_Mode_Select(const timer1_t* _timer1);
static inline void Timer1_RW_Mode_Select(const timer1_t* _timer1);
static inline void Timer1_Preload_Value(const timer1_t* _timer1);


uint16 Timer1_PreLoaded_Value_Store=ZERO_INIT;//use in ISR to re write the preload value in the register after the overflow


#if TIMER1_INTERRUPT_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE   
static void (*Timer1_Interrupt_Handler)(void)=NULL;
#endif

Std_ReturnType Timer1_Init(const timer1_t* _timer1)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if (NULL==_timer1)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        /*timer1 disable*/
        TIMER1_DISABLE();
        /*timer1 set the Prescaler */
        Timer1_Prescaler_Config(_timer1);
        /*timer1 select mode*/
        Timer1_Mode_Select(_timer1);
        /*timer1 set the R/W Mode */
        Timer1_RW_Mode_Select(_timer1);
        /*set the preloaded value*/
        Timer1_Preload_Value(_timer1);
        Timer1_PreLoaded_Value_Store=_timer1->timer1_preload_value;
        /*interrupt set*/
#if TIMER1_INT_ENABLE ==FEATURE_ENABLE
        INT_TMR1_DISABLE();
#if INT_PRI_LEVELS_ENABLE==FEATURE_ENABLE
        INT_PRI_FET_EN();
        INT_GLOBAL_HIGH_EN();
        INT_GLOBAL_LOW_EN();
        if(INT_PRI_HIGH==_timer1->priority)
        {
            INT_TMR1_PRI_SET_HIGH();
        }
            else if(INT_PRI_LOW==_timer1->priority)
            {
                INT_TMR1_PRI_SET_LOW();
            }
            else{/*no thing*/}

#else

        INT_GLOBAL_EN();
        INT_PERIPHERAL_EN();
#endif 
        INT_TMR1_CLEAR_FLAG();
        INT_TMR1_ENABLE();

        Timer1_Interrupt_Handler=_timer1->Timer1_InterruptHandler;
 
#endif
        TIMER1_ENABLE();
    }
    return ERRORSTATUS;    
}
Std_ReturnType Timer1_DeInit(const timer1_t* _timer1)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if (NULL==_timer1)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        TIMER1_DISABLE();
        #if TIMER1_INT_ENABLE ==FEATURE_ENABLE
        INT_TMR1_DISABLE();
        #endif
    }
    return ERRORSTATUS;
}
Std_ReturnType Timer1_Write_Value(const timer1_t* _timer1,uint16 value)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if (NULL==_timer1)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
       TMR1H=(value)>>8;
       TMR1L=(uint8)(value);  
    }
    return ERRORSTATUS;
    
}       
Std_ReturnType Timer1_Read_Value(const timer1_t* _timer1,uint16 *value)
{
     uint8 tmr1l=ZERO_INIT,tmr1h=ZERO_INIT;
    Std_ReturnType ERRORSTATUS =E_OK;
    if ((NULL==_timer1)||(NULL==value ))
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        tmr1l=TMR1L;
        tmr1h=TMR1H;
     *value=(uint16)((tmr1h<<8)+tmr1l);
    }
    return ERRORSTATUS;
       
}

#if TIMER1_INT_ENABLE ==FEATURE_ENABLE
void TMR1_ISR(void)
{
   INT_TMR1_CLEAR_FLAG();
   TMR1H=Timer1_PreLoaded_Value_Store>>8;
   TMR1L=(uint8)Timer1_PreLoaded_Value_Store;
    if(Timer1_Interrupt_Handler){Timer1_Interrupt_Handler();}
}
#endif
static inline void Timer1_Prescaler_Config(const timer1_t* _timer1)
{
       TIMER1_PRESCALER_SET_VALUE(_timer1->timer1_prescaler_value); 
}
static inline void Timer1_Mode_Select(const timer1_t* _timer1)
{
   if(_timer1->timer1_mode==TIMER1_COUNTER_MODE_CFG)
   {
       TIMER1_COUNTER_MODE();
       if(_timer1->counter_mode==TIMER1_SYNC_COUNTER_MODE_CFG)
       {
           TIMER1_SYNC_COUNTER_MODE(); 
       }
       else if(_timer1->counter_mode==TIMER1_ASYNC_COUNTER_MODE_CFG)
       {
           TIMER1_ASYNC_COUNTER_MODE(); 
       }
       else{/*no thing*/}
   }
   else if (_timer1->timer1_mode==TIMER1_TIMER_MODE_CFG)
   {
       TIMER1_TIMER_MODE();
   }
   else{/*no thing*/}
}
static inline void Timer1_RW_Mode_Select(const timer1_t* _timer1)
{
   if(_timer1->timer1_register_mode==TIMER1_RW_REG_8BIT_MODE )
   {
       TIMER1_RW_REG_8BIT_MODE_set();
   }
   else if(_timer1->timer1_register_mode==TIMER1_RW_REG_16BIT_MODE )
   {
       TIMER1_RW_REG_16BIT_MODE_set();
   }
   else{/*no thing*/}
}   
static inline void Timer1_Preload_Value(const timer1_t* _timer1)
{     
       TMR1H=(_timer1->timer1_preload_value)>>8;
       TMR1L=(uint8)(_timer1->timer1_preload_value);
}  
