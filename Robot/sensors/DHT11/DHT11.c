/* 
 * File:   DHT11.c
 * Author: ahmed radwan
 *
 * Created on January 21, 2023, 6:09 PM
 */
#include "DHT11.h"

 static void DHT11_Start(void);  			/* send start pulse to DHT11 module */
 static void DHT11_Check_Response(void);  	/* wait for response from DHT11 module */
 static void DHT11_Read_Data(uint8* data);         /* READ DATA FROM SENSOR*/

Std_ReturnType Get_Temp_HUM( uint8* RH_Decimal,uint8* RH_Integral,uint8* T_Decimal,uint8* T_Integral,uint8* Checksum)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if ( NULL==RH_Decimal||NULL==RH_Integral||NULL==T_Decimal||NULL==T_Integral||NULL==Checksum)
    {
        ERRORSTATUS = E_NOT_OK;
    }
    else
    {
       DHT11_Start();  			
       DHT11_Check_Response();  
       DHT11_Read_Data(RH_Decimal);
       DHT11_Read_Data(RH_Integral);
       DHT11_Read_Data(T_Decimal);
       DHT11_Read_Data(T_Integral);
       DHT11_Read_Data(Checksum);  
    }
    return ERRORSTATUS;
}
static void DHT11_Start(void)
{
    DHT1_PIN_DIR=GPIO_DIRECTION_OUTPUT;   /* make the pin out put*/
    DHT1_PIN_OUT=GPIO_LOW;               /*send start condition*/
    __delay_ms(18);                     /*wait the required delay*/
    DHT1_PIN_OUT=GPIO_HIGH;
    __delay_us(30);
    DHT1_PIN_DIR=GPIO_DIRECTION_INPUT; /* make the pin input*/
}
static void DHT11_Check_Response(void)
{
    while(DHT1_PIN_STAT == 1);  /* wait till bus is High */     
    while(!(DHT1_PIN_STAT & 1));  /* wait till bus is Low */
    while(DHT1_PIN_STAT & 1);  /* wait till bus is High */
}
static void DHT11_Read_Data(uint8* data)
{
  uint8 i;
  *data = 0;  
    for(i=0;i<8;i++)
    {
        while(!(DHT1_PIN_STAT & 1));  /* wait till 0 pulse, this is start of data pulse */
        __delay_us(40);         
        if(DHT1_PIN_STAT & 1)  /* check whether data is 1 or 0 */ 
        {
            *data = (((*data)<<1)|1); 
            
        }
        else
        {  
            *data = ((*data)<<1); 
          
        }
            while(DHT1_PIN_STAT & 1); 
    }
 
}
