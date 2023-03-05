/* 
 * File:   ultrasonic.c
 * Author: ahmed radwan
 *
 * Created on January 23, 2023, 8:56 PM
 */
#include"ultrasonic.h"
static void send_trig_pulse(const ultrasonic_config_st* ultrasonic_object);
Std_ReturnType Ultra_Sonic_Init(const ultrasonic_config_st* ultrasonic_object,const timer0_config_st *_tmr0_config)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if ( NULL==ultrasonic_object||NULL==_tmr0_config)
    {
        ERRORSTATUS = E_NOT_OK;
    }
    else
    {
        GPIO_Pin_Initialize(&(ultrasonic_object->trig_pin));//trig pin initialized as output
        GPIO_Pin_Initialize(&(ultrasonic_object->echo_pin));//echo pin initialized as input
        HAL_Timer0_Init(_tmr0_config);
    }
    return ERRORSTATUS;

}
Std_ReturnType Get_Distance(const ultrasonic_config_st* ultrasonic_object,const timer0_config_st *_tmr0_config,float32* distance)
{
    logic_et logic=0;
    uint16 timer_val=0;
    Std_ReturnType ERRORSTATUS =E_OK;
    if ( NULL==distance)
    {
        ERRORSTATUS = E_NOT_OK;
        
    }
    else
    {
        TMR0_DISABLE();
        HAL_Timer0_Write_Val(_tmr0_config ,0);
        send_trig_pulse(ultrasonic_object);//send the trig pulse
        while(!logic)
        {
           GPIO_Pin_Read_Logic(&(ultrasonic_object->echo_pin),&logic); 
        }
        TMR0_ENABLE();
        while(logic)
        {
           GPIO_Pin_Read_Logic(&(ultrasonic_object->echo_pin),&logic); 
        }
        TMR0_DISABLE();
        HAL_Timer0_Read_Val(_tmr0_config ,&timer_val);// 340m/s -> 34000*timr val*10-6/2
        
        *distance=timer_val/(float32)58.8;          /*distance in cm div by 2 because of the wave go and return in this timer*/
        
    }
    return ERRORSTATUS;
}
static void send_trig_pulse(const ultrasonic_config_st* ultrasonic_object)
{
    GPIO_Pin_Write_Logic(&(ultrasonic_object->trig_pin),GPIO_HIGH);
    __delay_us(10);
    GPIO_Pin_Write_Logic(&(ultrasonic_object->trig_pin),GPIO_LOW);
}
