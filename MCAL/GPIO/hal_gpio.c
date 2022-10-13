/* 
 * File:   hal_gpio.c
 * Author: ahmed radwan
 *
 * Created on June 28, 2022, 4:24 AM
 */
#include "hal_gpio.h"

/*reference to the data direction control registers*/
volatile   uint8 *tris_registers[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
/*reference to the data latch registers (Read&Write to data latch)*/
volatile uint8 *lat_registers[]={&LATA,&LATB,&LATC,&LATD,&LATE};
/*reference to the port status  registers*/
volatile uint8 *port_registers[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};


#if GPIO_PORT_PIN_CONFIGURATION == CONFIG_ENABLE
/**
 * @brief initialize the direction to specific pin (INPUT OR OUTPUT) @ref direction_et 
 * @param _pin_config pointer to the configuration @ref pin_config_st
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOK): the function has issue to preform this action
 */
Std_ReturnType GPIO_Pin_Direction_Initialize  (const pin_config_st * _pin_config)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if ( NULL==_pin_config||_pin_config->pin> PORT_PIN_MAX_NUMBER -1)
    {
        ERRORSTATUS = E_NOT_OK;
    }
    else
    {
    switch(_pin_config->direction)
    {
        case GPIO_DIRECTION_OUTPUT:
         CLEAR_BIT(*tris_registers[_pin_config->port],_pin_config->pin);
            break;
        case GPIO_DIRECTION_INPUT:
          SET_BIT(*tris_registers[_pin_config->port],_pin_config->pin);
            break;
        
        default:ERRORSTATUS=E_NOT_OK;
            
    }
     }
    return ERRORSTATUS;
}

/**
 * @bref get the direction of specific pin (INPUT OR OUTPUT) @ref direction_et 
 * @param _pin_config pointer to the configuration @ref pin_config_st
 * @param direction_status pointer to the status of the specific pin
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOK): the function has issue to preform this action
 */
Std_ReturnType GPIO_Pin_Get_Direction_Status (const pin_config_st * _pin_config, direction_et *direction_status)
{
     Std_ReturnType ERRORSTATUS = E_OK;
     if ( NULL==_pin_config||NULL==direction_status||_pin_config->pin> PORT_PIN_MAX_NUMBER -1)
    {
        ERRORSTATUS = E_NOT_OK;
    }
    else
    {
       *direction_status= READ_BIT(*tris_registers[_pin_config->port],_pin_config->pin);
         
    }
     return ERRORSTATUS;
    
}

/**
  * write logic(0/1) on gpio pin
  * @param _pin_config pointer to the configuration @ref pin_config_st
  * @param logic
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOK): the function has issue to preform this action
  */
Std_ReturnType GPIO_Pin_Write_Logic  (const pin_config_st * _pin_config, logic_et logic)
{
      Std_ReturnType ERRORSTATUS = E_OK;
     if ( NULL==_pin_config||_pin_config->pin> PORT_PIN_MAX_NUMBER -1)
    {
        ERRORSTATUS = E_NOT_OK;
    }
    else
    {
         switch(logic)
    {
        case GPIO_LOW:
         CLEAR_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
            break;
        case GPIO_HIGH:
          SET_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
            break;
        
        default:ERRORSTATUS = E_NOT_OK;
     }   
         
    }
     return ERRORSTATUS;   
}
/**
 * 
 * @param _pin_config pointer to the configuration @ref pin_config_st
 * @param logic -> its var passed by refrance to get the logic value 
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOK): the function has issue to preform this action
 */
Std_ReturnType GPIO_Pin_Read_Logic   (const pin_config_st * _pin_config,logic_et *logic)
{
      Std_ReturnType ERRORSTATUS =E_OK;
          if ( NULL==_pin_config||NULL==logic||_pin_config->pin> PORT_PIN_MAX_NUMBER -1)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
         *logic= READ_BIT(*port_registers[_pin_config->port],_pin_config->pin);
    }
     return ERRORSTATUS;   
}

/**
 * 
 * @param _pin_config pointer to the configuration @ref pin_config_st
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOK): the function has issue to preform this action
 */
Std_ReturnType GPIO_Pin_Toggle_Logic  (const pin_config_st * _pin_config)
{
     Std_ReturnType ERRORSTATUS =E_OK;
          if ( NULL==_pin_config)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
      TOGGLE_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
    }
     return ERRORSTATUS;    
}



/**
 * initialize the direction and the logic of the pin 
 * @param _pin_config pointer to the configuration @ref pin_config_st
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOK): the function has issue to preform this action
 */
Std_ReturnType GPIO_Pin_Initialize(const pin_config_st * _pin_config)
{
     Std_ReturnType ERRORSTATUS =E_OK;
          if ( NULL==_pin_config)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
         ERRORSTATUS=GPIO_Pin_Direction_Initialize(_pin_config);
         ERRORSTATUS=GPIO_Pin_Write_Logic(_pin_config,_pin_config->logic);
        
    }
     return ERRORSTATUS;   
}
#endif

/******************************************port configurations*********************************************************/

#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE

/**
 * initialize the direction and the logic of the pin 
 * @param port: the port want to set its direction @ref: port_index_et
 * @param direction: the direction of all the pin in the port 
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOK): the function has issue to preform this action
 */
Std_ReturnType GPIO_Port_Direction_Initialize(port_index_et port , uint8 direction)
{
     Std_ReturnType ERRORSTATUS =E_OK;
     if ( PORT_MAX_NUMBER-1<port)
    {
        ERRORSTATUS=E_NOT_OK;
    }
     else
     {
         *tris_registers[port]=direction;
     }
     return ERRORSTATUS;   
}

/**
 * 
 * @param port
 * @param direction_status
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOK): the function has issue to preform this action
 */
Std_ReturnType GPIO_Port_Get_Direction_Status (port_index_et port, uint8 *direction_status)
{
     Std_ReturnType ERRORSTATUS =E_OK;
          if ((PORT_MAX_NUMBER-1<port)||( NULL==direction_status))
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
       *direction_status=*tris_registers[port];
    }
     
     return ERRORSTATUS;
}

/**
 * 
 * @param port
 * @param logic
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOK): the function has issue to preform this action
 */
Std_ReturnType GPIO_Port_Write_Logic (port_index_et port,uint8 logic)
{
       Std_ReturnType ERRORSTATUS =E_OK;
          if ((PORT_MAX_NUMBER-1<port))
         {
              ERRORSTATUS=E_NOT_OK;
         }
          else
          {
              *lat_registers[port]=logic;
          }
     return ERRORSTATUS;  
}

/**
 * 
 * @param port
 * @param logic
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOK): the function has issue to preform this action
 */
Std_ReturnType GPIO_Port_Read_Logic (port_index_et port,uint8 *logic)
{
     Std_ReturnType ERRORSTATUS =E_OK;
          if (( NULL==logic)||(PORT_MAX_NUMBER-1<port))
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
          *logic=*port_registers[port]; 
    }     
     return ERRORSTATUS;    
}

/**
 * 
 * @param port
 * @return Status of the function
 *         (E_OK) : the function done successfully
 *         (E_NOK): the function has issue to preform this action 
 */
Std_ReturnType GPIO_Port_Toggle_Logic (port_index_et port)
{
       Std_ReturnType ERRORSTATUS =E_OK;
          if (PORT_MAX_NUMBER-1<port)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
          *lat_registers[port]^=PORTMASK; 
    }     
     return ERRORSTATUS;     
}
#endif
