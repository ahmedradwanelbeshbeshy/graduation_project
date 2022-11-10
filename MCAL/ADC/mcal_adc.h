/* 
 * File:   mcal_adc.h
 * Author: ahmed radwan
 *
 * Created on August 23, 2022, 2:50 AM
 */

#ifndef MCAL_ADC_H
#define	MCAL_ADC_H


/********************************include section********************************/

#include"../std_libraries.h"
#include"../mcal_std_types.h"
#include"../Interrupts/mcal_internal_interrupt.h"
#include"../GPIO/hal_gpio.h"
#include"mcal_adc_cfg.h"

/********************************macros declarations section********************************/

// port configuration options
/** if you chose AN8 thats mean channels from AN0 to AN8 analog functionality 
                     but from AN9 to AN12 digital functionality*/

#define ADC_AN0_ANALOG_FUNCTIONALITY  0x0E
#define ADC_AN1_ANALOG_FUNCTIONALITY  0x0D
#define ADC_AN2_ANALOG_FUNCTIONALITY  0x0C
#define ADC_AN3_ANALOG_FUNCTIONALITY  0x0B
#define ADC_AN4_ANALOG_FUNCTIONALITY  0x0A
#define ADC_AN5_ANALOG_FUNCTIONALITY  0x09
#define ADC_AN6_ANALOG_FUNCTIONALITY  0x08
#define ADC_AN7_ANALOG_FUNCTIONALITY  0x07
#define ADC_AN8_ANALOG_FUNCTIONALITY  0x06
#define ADC_AN9_ANALOG_FUNCTIONALITY  0x05
#define ADC_AN10_ANALOG_FUNCTIONALITY 0x04
#define ADC_AN11_ANALOG_FUNCTIONALITY 0x03
#define ADC_AN12_ANALOG_FUNCTIONALITY 0x02
#define ADC_ALL_ANALOG_FUNCTIONALITY  0x00
#define ADC_ALL_DIGITAL_FUNCTIONALITY 0x0F



/********************************macros function declarations section***********************/

#define ADC_CONVERSION_STATUS() (ADCON0bits.GO_nDONE)//A/D Conversion Status bit
#define ADC_START_CONVERSION() (ADCON0bits.GODONE=1)//A/D start conversion

#define ADC_CONVERTER_ENABLE()  (ADCON0bits.ADON=1)//Enable analog to digital converter
#define ADC_CONVERTER_DISABLE()  (ADCON0bits.ADON=0)//Disable analog to digital converter

// external voltage reference connected to AN3 and AN2 
#define ADC_ENABLE_VOLTAGE_REFERANCE() do{ADCON1bits.VCFG1=1;\
                                          ADCON1bits.VCFG0=1;\
                                          }while(0)
// The voltage reference is VDD and VSS 
#define ADC_DISABLE_VOLTAGE_REFERANCE() do{ADCON1bits.VCFG1=0;\
                                           ADCON1bits.VCFG0=0;\
                                          }while(0)
/* @breif:this function to set analog to digital port configuration control 
 * @ref:port configuration options
 * @note:if you chose AN8 thats mean channels from AN0 to AN8 analog functionality 
                     but from AN9 to AN12 digital functionalit
 */
#define ADC_ANALOG_DIGITAL_SET_PORT_CONFIG(_CONFIG) (ADCON1bits.PCFG=_CONFIG)

#define ADC_RESULT_RIGHT_FORMATE() (ADCON2bits.ADFM=1)
#define ADC_RESULT_LEFT_FORMATE()  (ADCON2bits.ADFM=0)



/********************************data types  section********************************/

/**
 * @breif:select the input ADC channel
 */
typedef enum {
    ADC_CHANEL_AN0=0,
    ADC_CHANEL_AN1,
    ADC_CHANEL_AN2,
    ADC_CHANEL_AN3,
    ADC_CHANEL_AN4,
    ADC_CHANEL_AN5,
    ADC_CHANEL_AN6,
    ADC_CHANEL_AN7,
    ADC_CHANEL_AN8,
    ADC_CHANEL_AN9,
    ADC_CHANEL_AN10,
    ADC_CHANEL_AN11,
    ADC_CHANEL_AN12       
    
}adc_channel_select_t;

/**
 * @breif:A/D acquisition time select 
 * @note: Acquisition time is the time required for ADC to capture the input voltage during sampling
 */
typedef enum
{
    ADC_0_TAD=0,
    ADC_2_TAD,
    ADC_4_TAD,
    ADC_6_TAD,
    ADC_8_TAD,            
    ADC_12_TAD,
    ADC_16_TAD, 
    ADC_20_TAD            
}adc_acquisition_time_t;

/**
 * @breif:A/D Clock source s select 
 * @note: Acquisition time is the time required for ADC to capture the input voltage during sampling
 */
typedef enum
{
    ADC_CONVERSION_CLOCK_FOSC_DIV_2=0,
    ADC_CONVERSION_CLOCK_FOSC_DIV_8,
    ADC_CONVERSION_CLOCK_FOSC_DIV_32,
    ADC_CONVERSION_CLOCK_FOSC_DIV_FRC,
    ADC_CONVERSION_CLOCK_FOSC_DIV_4,            
    ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    ADC_CONVERSION_CLOCK_FOSC_DIV_64, 
}adc_conversion_clock_source_t;
/**
 * @breif:A/D result format select 
 */
typedef enum
{
    ADC_RESULT_LEFT=0,
    ADC_RESULT_RIGHT
}adc_result_format_t;
/**
 * @breif:A/D voltage source select 
 * @note: ADC_VOLTAGE_REFERANCE_INTERNAL VDD and VSS
 *        ADC_VOLTAGE_REFERANCE_EXTERNAL AN3 and AN2
 */
typedef enum
{
    ADC_VOLTAGE_REFERANCE_INTERNAL=0,
    ADC_VOLTAGE_REFERANCE_EXTERNAL
}adc_voltage_reference_t;

typedef enum
{
    ADC_CONVERSION_STATUS_DONE=0,
    ADC_CONVERSION_STATUS_INPROGRESS
}adc_conversion_status_t;
typedef struct
{
#if ADC_INTERRUPT_FEATURE_ENABLE ==FEATURE_ENABLE   
    void (*ADC_Interupt_handler) (void);
    #if Interrupt_priority_Levels_Enable==FEATURE_ENABLE
    interrupt_priority_cfg priority;
    #endif
#endif
    adc_channel_select_t adc_channel;                    /*@ref:adc_channel_select_t*/
    adc_acquisition_time_t  acquisition_time;          /*@ref:adc_acquisition_time_t*/
    adc_conversion_clock_source_t conversion_clock;    /*@ref:adc_conversion_clock_source_t*/
    adc_result_format_t result_format;                        /*@ref:adc_result_t*/
    adc_voltage_reference_t voltage_referance;         /*@ref:adc_voltage_reference_t*/
}adc_config_t;

typedef uint16 adc_result_t;
/*******************************function declarations section*************************************/
Std_ReturnType ADC_Init(const adc_config_t* _adc);
Std_ReturnType ADC_DeInit(const adc_config_t* _adc);
Std_ReturnType ADC_select_channel(const adc_config_t* _adc,adc_channel_select_t _channel);
Std_ReturnType ADC_Start_Conversion(const adc_config_t* _adc);
Std_ReturnType ADC_Is_Conversion_Done(const adc_config_t* _adc,adc_conversion_status_t*_status);
Std_ReturnType ADC_Get_Conversion_Results(const adc_config_t* _adc,adc_result_t*_result);
Std_ReturnType ADC_Get_Conversion_Blocking(const adc_config_t* _adc,adc_channel_select_t _channel,
                                                                      adc_result_t*_result);
Std_ReturnType ADC_Get_Conversion_Interrupt(const adc_config_t* _adc,adc_channel_select_t _channel);







#endif	/* MCAL_ADC_H */

