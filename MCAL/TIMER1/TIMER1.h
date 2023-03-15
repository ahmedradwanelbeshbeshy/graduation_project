/* 
 * File:   TIMER1.h
 * Author: ahmed radwan
 *
 * Created on March 13, 2023, 6:36 PM
 */

#ifndef TIMER1_H
#define	TIMER1_H

/********************************include section********************************/

#include"../std_libraries.h"
#include"../mcal_std_types.h"
#include"../GPIO/hal_gpio.h"
#include"../Interrupts/mcal_internal_interrupt.h"


/********************************macros declarations section********************************/

/********************************macros function declarations section***********************/

#define TIMER1_ENABLE()                     (T1CONbits.TMR1ON=1)
#define TIMER1_DISABLE()                    (T1CONbits.TMR1ON=0)


#define TIMER1_TIMER_MODE()                 (T1CONbits.TMR1CS=0)
#define TIMER1_COUNTER_MODE()               (T1CONbits.TMR1CS=1)
    
#define TIMER1_SYNC_COUNTER_MODE()          (T1CONbits.T1SYNC=0)
#define TIMER1_ASYNC_COUNTER_MODE()         (T1CONbits.T1SYNC=1)

#define TIMER1_OSC_ENABLE()                 (T1CONbits.T1OSCEN=1)
#define TIMER1_OSC_DISABLE()                (T1CONbits.T1OSCEN=0)

#define TIMER1_PRESCALER_SET_VALUE(_value)  (T1CONbits.T1CKPS=_value)

#define TIMER1_SYSTEM_CLOCK_STAUS_BIT()     (T1CONbits.T1RUN)

#define TIMER1_RW_REG_8BIT_MODE_set()       (T1CONbits.RD16=0)
#define TIMER1_RW_REG_16BIT_MODE_set()      (T1CONbits.RD16=1)

/********************************data types  section********************************/

typedef enum{
    TIMER1_COUNTER_MODE_CFG=0,
    TIMER1_TIMER_MODE_CFG
}timer1_mode_cfg_t;

typedef enum{
    TIMER1_SYNC_COUNTER_MODE_CFG=0,
    TIMER1_ASYNC_COUNTER_MODE_CFG
}timer1_sync_cfg_t;

typedef enum{
    TIMER1_OSC_HW_DISABLE=0,
    TIMER1_OSC_HW_ENABLE
}timer1_ocs_cfg_t;

typedef enum{
    TIMER1_PRESCALER_DIV_BY_1=0,
    TIMER1_PRESCALER_DIV_BY_2,
    TIMER1_PRESCALER_DIV_BY_4,
    TIMER1_PRESCALER_DIV_BY_8,
}timer1_prescaler_select_t;

typedef enum{
    TIMER1_RW_REG_8BIT_MODE=0,
    TIMER1_RW_REG_16BIT_MODE
}timer1_Read_Write_Mode_select_t;


        
typedef struct{
    uint16 timer1_preload_value;
#if TIMER1_INT_ENABLE ==FEATURE_ENABLE 
    void(*Timer1_InterruptHandler)(void);
#if INT_PRI_LEVELS_ENABLE==FEATURE_ENABLE
    interrupt_pri_et priority;
#endif
#endif
    timer1_prescaler_select_t timer1_prescaler_value;
    timer1_mode_cfg_t timer1_mode;
    timer1_sync_cfg_t counter_mode;
    timer1_Read_Write_Mode_select_t timer1_register_mode;
    timer1_ocs_cfg_t timer1_osc_cfg;//
}timer1_t;
/*******************************function declarations section*************************************/
Std_ReturnType Timer1_Init(const timer1_t* _timer1);
Std_ReturnType Timer1_DeInit(const timer1_t* _timer1);
Std_ReturnType Timer1_Write_Value(const timer1_t* _timer1,uint16 value);
Std_ReturnType Timer1_Read_Value(const timer1_t* _timer1,uint16 *value);

#endif	/* TIMER1_H */

