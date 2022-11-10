/* 
 * File:   mcal_adc.c
 * Author: ahmed radwan
 *
 * Created on August 23, 2022, 2:50 AM
 */

#include"mcal_adc.h"
static Std_ReturnType adc_channel_pin_config_as_input(const adc_channel_select_t _channel);
static Std_ReturnType adc_select_result_formate(const adc_config_t* _adc);
static Std_ReturnType adc_select_voltage_reference(const adc_config_t* _adc);
#if ADC_INTERRUPT_FEATURE_ENABLE ==FEATURE_ENABLE   
static void (*ADC_Interrupt_Handler)(void)=NULL;

#endif

/**
 * 
 * @param _adc
 * @return 
 */
Std_ReturnType ADC_Init(const adc_config_t* _adc)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if (NULL==_adc)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        /* disable the ADC */
          ADC_CONVERTER_DISABLE();
        
        /* configure the digital/analog pins */
        //  ADC_ANALOG_DIGITAL_SET_PORT_CONFIG()
        
          /* set the acquisition time */
         ADCON2bits.ACQT=_adc->acquisition_time;
         
        /* set the clock source */
         ADCON2bits.ADCS=_adc->conversion_clock;
                 
        /* select the ADC default channel */
         ADCON0bits.CHS=_adc->adc_channel;
         
        /* configure the pin to be input*/
        adc_channel_pin_config_as_input(_adc->adc_channel);
        
        /* set result formate */
         adc_select_result_formate(_adc);
         
        /* set the voltage reference */
         adc_select_voltage_reference(_adc);
         /*init the interrupt*/
         #if ADC_INT_ENABLE ==FEATURE_ENABLE
      
            ADC_Interrupt_Disable();
            #if Interrupt_priority_Levels_Enable==FEATURE_ENABLE
            Interrupt_poriority_Level_Enable();
            Interrupt_Global_Iinterrupt_High_Enable();
            Interrupt_Global_Iinterrupt_Low_Enable();
                if(INTERRUPT_HIGH_priority==_adc->priority)
                {
                    ADC_Interrupt_High_priority_set();
                }
                else if(INTERRUPT_LOW_priority==_adc->priority)
                {
                    ADC_Interrupt_Low_priority_set();
                }
                else{/*no thing*/}
            #else
                 Interrupt_Global_Iinterrupt_Enable();
                 Interrupt_Peripheral_Interrupt_Enable();
            #endif 
            ADC_Interrupt_Handler=_adc->ADC_Interupt_handler;
            ADC_Interrupt_Enable();
            ADC_Interrupt_Flag_clear();
 
            #endif            
            


                  
        /* enable the ADC */
         ADC_CONVERTER_ENABLE();
        
    }
    return ERRORSTATUS;
}
/**
 * 
 * @param _adc
 * @return 
 */
Std_ReturnType ADC_DeInit(const adc_config_t* _adc)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if (NULL==_adc)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        /* disable the ADC */
        ADC_CONVERTER_DISABLE();
        /*deinit the interrupt*/
        #if ADC_INTERRUPT_FEATURE_ENABLE ==FEATURE_ENABLE   
            ADC_Interrupt_Disable();
            
        #endif
        
    }
    return ERRORSTATUS;
}
/**
 * 
 * @param _adc
 * @param _channel
 * @return 
 */
Std_ReturnType ADC_select_channel(const adc_config_t* _adc,adc_channel_select_t _channel)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if (NULL==_adc)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
      /* select the ADC  channel */
       ADCON0bits.CHS=_channel;
       
     /* configure the pin to be input*/
       adc_channel_pin_config_as_input(_channel);
    }
    return ERRORSTATUS;
}
/**
 * 
 * @param _adc
 * @return 
 */
Std_ReturnType ADC_Start_Conversion(const adc_config_t* _adc)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if (NULL==_adc)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        ADC_START_CONVERSION();
    }
    return ERRORSTATUS;
}
/**
 * 
 * @param _adc
 * @param _status the conversion statues
 *       true  (1)- if conversion is complete
 *       false (0)- if conversion is not complete 
 * @return 
 */
Std_ReturnType ADC_Is_Conversion_Done(const adc_config_t* _adc,adc_conversion_status_t*_status)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if ((NULL==_adc)||(NULL==_status))
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
      *_status=(uint8)!(ADC_CONVERSION_STATUS());
    }
    return ERRORSTATUS;
}
/**
 *
 * @param _adc
 * @param _result
 * @return 
 */
Std_ReturnType ADC_Get_Conversion_Results(const adc_config_t* _adc,adc_result_t*_result)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if ((NULL==_adc)||(NULL==_result))
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        if(ADC_RESULT_LEFT==_adc->result_format)
         {
             *_result =(adc_result_t)(((ADRESH<<8)+ADRESL)>>6);
         }
         else if(ADC_RESULT_RIGHT==_adc->result_format)
         {
             *_result =(adc_result_t)((ADRESH<<8)+ADRESL);
         }
         else
         {
              *_result =(adc_result_t)((ADRESH<<8)+ADRESL);
         }
       
    }
    return ERRORSTATUS;
}
/**
 * 
 * @param _adc
 * @param _channel
 * @param _result
 * @return 
 */
Std_ReturnType ADC_Get_Conversion_Blocking(const adc_config_t* _adc,adc_channel_select_t _channel,
                                                            adc_result_t*_result)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if ((NULL==_adc)||(NULL==_result))
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
 
        /*select a/d channel*/
          ERRORSTATUS= ADC_select_channel(_adc,_channel);
        /*start the conversion*/
          ERRORSTATUS= ADC_Start_Conversion(_adc);
        /*blocking until the conversion done */
          while(ADC_CONVERSION_STATUS())
         /*get the result*/
         ERRORSTATUS= ADC_Get_Conversion_Results(_adc,_result);
          __delay_ms(20);
    }
    return ERRORSTATUS;
}

Std_ReturnType ADC_Get_Conversion_Interrupt(const adc_config_t* _adc,adc_channel_select_t _channel)
{
 Std_ReturnType ERRORSTATUS =E_OK;
    if (NULL==_adc)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        /*select a/d channel*/
          ERRORSTATUS= ADC_select_channel(_adc,_channel);
        /*start the conversion*/
          ERRORSTATUS= ADC_Start_Conversion(_adc);
    }
    return ERRORSTATUS;   
}
static Std_ReturnType adc_channel_pin_config_as_input(const adc_channel_select_t _channel)
{
Std_ReturnType ERRORSTATUS=E_OK;
       switch (_channel)
       {
           case ADC_CHANEL_AN0:  SET_BIT(TRISA,_TRISA_RA0_POSN);  break;
           case ADC_CHANEL_AN1:  SET_BIT(TRISA,_TRISA_RA1_POSN);  break;
           case ADC_CHANEL_AN2:  SET_BIT(TRISA,_TRISA_RA2_POSN);  break;
           case ADC_CHANEL_AN3:  SET_BIT(TRISA,_TRISA_RA3_POSN);  break;
           case ADC_CHANEL_AN4:  SET_BIT(TRISA,_TRISA_RA5_POSN);  break;              
           case ADC_CHANEL_AN5:  SET_BIT(TRISE,_TRISE_RE0_POSN);  break;
           case ADC_CHANEL_AN6:  SET_BIT(TRISE,_TRISE_RE1_POSN);  break;
           case ADC_CHANEL_AN7:  SET_BIT(TRISE,_TRISE_RE2_POSN);  break;              
           case ADC_CHANEL_AN8:  SET_BIT(TRISB,_TRISB_RB2_POSN);  break;              
           case ADC_CHANEL_AN9:  SET_BIT(TRISB,_TRISB_RB3_POSN);  break;              
           case ADC_CHANEL_AN10: SET_BIT(TRISB,_TRISB_RB1_POSN);  break;  
           case ADC_CHANEL_AN11: SET_BIT(TRISB,_TRISB_RB4_POSN);  break;              
           case ADC_CHANEL_AN12: SET_BIT(TRISB,_TRISB_RB0_POSN);  break;
       }

    return ERRORSTATUS;
}
static Std_ReturnType adc_select_result_formate(const adc_config_t* _adc)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if (NULL==_adc)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
         if(ADC_RESULT_LEFT==_adc->result_format)
         {
             ADC_RESULT_LEFT_FORMATE();
         }
         else if(ADC_RESULT_RIGHT==_adc->result_format)
         {
             ADC_RESULT_RIGHT_FORMATE();
         }
         else
         {
             ADC_RESULT_RIGHT_FORMATE();
         }
    }
    return ERRORSTATUS;
}
static Std_ReturnType adc_select_voltage_reference(const adc_config_t* _adc)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if (NULL==_adc)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
         if(ADC_VOLTAGE_REFERANCE_INTERNAL==_adc->voltage_referance)
         {
            ADC_DISABLE_VOLTAGE_REFERANCE();
         }
         else if(ADC_VOLTAGE_REFERANCE_EXTERNAL==_adc->voltage_referance)
         {
             ADC_ENABLE_VOLTAGE_REFERANCE();
         }
         else
         {
           ADC_DISABLE_VOLTAGE_REFERANCE();  
         }
    }
    return ERRORSTATUS;
}


void ADC_ISR(void)
{
    #if ADC_INTERRUPT_FEATURE_ENABLE ==FEATURE_ENABLE   

   ADC_Interrupt_Flag_clear();
    if(ADC_Interrupt_Handler){ADC_Interrupt_Handler();}
   #endif
}
