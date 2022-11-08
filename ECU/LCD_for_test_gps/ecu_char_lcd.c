/* 
 * File:   ecu_char_lcd.h
 * Author: ahmed radwan
 *
 * Created on July 24, 2022, 4:30 AM
 */

#include"ecu_char_lcd.h"
static Std_ReturnType lcd_8bits_send_enable_signal(const char_lcd_8bit_t *lcd);
static Std_ReturnType lcd_4bits_send_enable_signal(const char_lcd_4bit_t *lcd);
static Std_ReturnType lcd_send_4bits(const char_lcd_4bit_t*lcd,uint8 data_command);
static Std_ReturnType lcd_4bits_set_courser(const char_lcd_4bit_t *lcd,uint8 row,uint8 colum);
static Std_ReturnType lcd_8bits_set_courser(const char_lcd_8bit_t *lcd,uint8 row,uint8 colum);


/**
 * 
 * @param lcd
 * @return 
 */
Std_ReturnType lcd_4bit_initialize(const char_lcd_4bit_t *lcd)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if ( NULL==lcd)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        uint8 pin_lcd_counter=0;
        ERRORSTATUS=GPIO_Pin_Initialize(&(lcd->lcd_rs_pin));   
        ERRORSTATUS=GPIO_Pin_Initialize(&(lcd->lcd_enable_pin));
        for(pin_lcd_counter=0;pin_lcd_counter<4;pin_lcd_counter++)
        {
            ERRORSTATUS=GPIO_Pin_Initialize(&(lcd->lcd_data_pins[pin_lcd_counter]));
 
            
        }
        __delay_ms(20);
        ERRORSTATUS=lcd_4bit_send_command(lcd,LCD_8BIT_MODE_2LINE_5_8);
        __delay_ms(5);
        ERRORSTATUS=lcd_4bit_send_command(lcd,LCD_8BIT_MODE_2LINE_5_8);
        __delay_us(150);
        ERRORSTATUS=lcd_4bit_send_command(lcd,LCD_8BIT_MODE_2LINE_5_8);
        
        ERRORSTATUS=lcd_4bit_send_command(lcd,LCD_CLEAR_DISPLAY);
        ERRORSTATUS=lcd_4bit_send_command(lcd,LCD_CURSOR_HOME);
        ERRORSTATUS=lcd_4bit_send_command(lcd,LCD_ENTRY_MODE_INCREMENT_SHIFT_OFF);
        ERRORSTATUS=lcd_4bit_send_command(lcd,LCD_DISPLAY_ON_UNDR_LINE_OFF_CURSOR_ON);
        ERRORSTATUS=lcd_4bit_send_command(lcd,LCD_4BIT_MODE_2LINE_5_8);
        ERRORSTATUS=lcd_4bit_send_command(lcd,0x80);

        
    
    }
     
    return ERRORSTATUS;
}
/**
 * 
 * @param lcd
 * @param command
 * @return 
 */
Std_ReturnType lcd_4bit_send_command(const char_lcd_4bit_t *lcd,uint8 command)
{
         Std_ReturnType ERRORSTATUS =E_OK;
    if ( NULL==lcd)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
     ERRORSTATUS= GPIO_Pin_Write_Logic(&(lcd->lcd_rs_pin),GPIO_LOW);
    lcd_send_4bits(lcd,(command>>4));
    lcd_4bits_send_enable_signal(lcd);
    lcd_send_4bits(lcd,command);
    lcd_4bits_send_enable_signal(lcd);
     
    }
     
    return ERRORSTATUS;   
}
/**
 * 
 * @param lcd
 * @param data
 * @return 
 */
Std_ReturnType lcd_4bit_send_char_data(const char_lcd_4bit_t *lcd,uint8 data)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if ( NULL==lcd)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
    ERRORSTATUS= GPIO_Pin_Write_Logic(&(lcd->lcd_rs_pin),GPIO_HIGH);
    lcd_send_4bits(lcd,(data>>4));
    lcd_4bits_send_enable_signal(lcd);
    lcd_send_4bits(lcd,data);
    lcd_4bits_send_enable_signal(lcd);
     
    }
     
    return ERRORSTATUS;  
}
/**
 * 
 * @param lcd
 * @param rows
 * @param colums
 * @param data
 * @return 
 */
Std_ReturnType lcd_4bit_send_char_data_pos(const char_lcd_4bit_t *lcd,uint8 row,uint8 colum,uint8 data)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if ( NULL==lcd)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
       lcd_4bits_set_courser(lcd,row,colum);
       lcd_4bit_send_char_data(lcd,data);
    }
     
    return ERRORSTATUS;
}
/**
 * 
 * @param lcd
 * @param str
 * @return 
 */
Std_ReturnType lcd_4bit_send_string_data(const char_lcd_4bit_t *lcd,uint8* str)
{
        Std_ReturnType ERRORSTATUS =E_OK;
    if (( NULL==lcd)||( NULL==str))
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        while(*str)
        {
           lcd_4bit_send_char_data(lcd,*str++) ;
        }
    }
     
    return ERRORSTATUS;    
}
/**
 * 
 * @param lcd
 * @param rows
 * @param colums
 * @param str
 * @return 
 */
Std_ReturnType lcd_4bit_send_string_data_pos(const char_lcd_4bit_t *lcd,uint8 row,uint8 colum,uint8* str)
{
        Std_ReturnType ERRORSTATUS =E_OK;
    if (( NULL==lcd)||( NULL==str))
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
         lcd_4bits_set_courser(lcd,row,colum);
        while(*str)
        {
           lcd_4bit_send_char_data(lcd,*str++) ;
        }
    }
     
    return ERRORSTATUS;    
}
/**
 * 
 * @param lcd
 * @param rows
 * @param colums
 * @param _char
 * @param pos
 * @return 
 */
Std_ReturnType lcd_4bit_send_custom_char(const char_lcd_4bit_t *lcd,uint8 row,uint8 colum,const uint8 _char[],uint8 memmory_pos)//why arr
{
    uint8 lcd_counter;
    Std_ReturnType ERRORSTATUS =E_OK;
    if ( NULL==lcd)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
       lcd_4bit_send_command(lcd,LCD_CGRAM_START_ADDRESS+(memmory_pos*8));
      for(lcd_counter=0;lcd_counter<8;lcd_counter++)
       {
          lcd_4bit_send_char_data(lcd,_char[lcd_counter]) ;
       }
       lcd_4bit_send_char_data_pos(lcd,row,colum,memmory_pos);
    }
     
    return ERRORSTATUS;
}

//--------------------------------------------------------------8bit_lcd--------------------------------------------------//


/**
 * 
 * @param lcd
 * @return 
 */
Std_ReturnType lcd_8bit_initialize(const char_lcd_8bit_t *lcd)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if ( NULL==lcd)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        uint8 pin_lcd_counter=0;
        ERRORSTATUS=GPIO_Pin_Initialize(&(lcd->lcd_rs_pin));   
        ERRORSTATUS=GPIO_Pin_Initialize(&(lcd->lcd_enable_pin));
        for(pin_lcd_counter=0;pin_lcd_counter<8;pin_lcd_counter++)
        {
        ERRORSTATUS=GPIO_Pin_Initialize(&(lcd->lcd_data_pins[pin_lcd_counter]));
        } 
        __delay_ms(20);
        ERRORSTATUS=lcd_8bit_send_command(lcd,LCD_8BIT_MODE_2LINE_5_8);
        __delay_ms(5);
        ERRORSTATUS=lcd_8bit_send_command(lcd,LCD_8BIT_MODE_2LINE_5_8);
        __delay_us(150);
        ERRORSTATUS=lcd_8bit_send_command(lcd,LCD_8BIT_MODE_2LINE_5_8);
        
        ERRORSTATUS=lcd_8bit_send_command(lcd,LCD_CLEAR_DISPLAY);
        ERRORSTATUS=lcd_8bit_send_command(lcd,LCD_CURSOR_HOME);
        ERRORSTATUS=lcd_8bit_send_command(lcd,LCD_ENTRY_MODE_INCREMENT_SHIFT_OFF);
        ERRORSTATUS=lcd_8bit_send_command(lcd,LCD_DISPLAY_ON_UNDR_LINE_OFF_CURSOR_ON);
        ERRORSTATUS=lcd_8bit_send_command(lcd,LCD_8BIT_MODE_2LINE_5_8);
        ERRORSTATUS=lcd_8bit_send_command(lcd,0x80);


        
        
    
    }
     
    return ERRORSTATUS;   
}
/**
 * 
 * @param lcd
 * @param command
 * @return 
 */
Std_ReturnType lcd_8bit_send_command(const char_lcd_8bit_t *lcd,uint8 command)
{
     Std_ReturnType ERRORSTATUS =E_OK;
    if ( NULL==lcd)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
      uint8  counter=0;
          ERRORSTATUS= GPIO_Pin_Write_Logic(&(lcd->lcd_rs_pin),GPIO_LOW);
          for (counter=0;counter<8;counter++)
          {
                GPIO_Pin_Write_Logic(&(lcd->lcd_data_pins[counter]),((command>>counter)&(uint8)0x01));   
          }
          lcd_8bits_send_enable_signal(lcd);
 
    }
     
    return ERRORSTATUS;    
}

/**
 * 
 * @param lcd
 * @param data
 * @return 
 */
Std_ReturnType lcd_8bit_send_char_data(const char_lcd_8bit_t *lcd,uint8 data)
{
     Std_ReturnType ERRORSTATUS =E_OK;
    if ( NULL==lcd)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        uint8  counter=0;
        ERRORSTATUS= GPIO_Pin_Write_Logic(&(lcd->lcd_rs_pin),GPIO_HIGH);
        for (counter=0;counter<8;counter++)
        {
           GPIO_Pin_Write_Logic(&(lcd->lcd_data_pins[counter]),((data>>counter)&(uint8)0x01));   
        }
        lcd_8bits_send_enable_signal(lcd);

       
    }
     
    return ERRORSTATUS;    
}
/**
 * 
 * @param lcd
 * @param rows
 * @param colums
 * @param data
 * @return 
 */
Std_ReturnType lcd_8bit_send_char_data_pos(const char_lcd_8bit_t *lcd,uint8 row,uint8 colum,uint8 data)
{
     Std_ReturnType ERRORSTATUS =E_OK;
    if ( NULL==lcd)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
       lcd_8bits_set_courser(lcd,row,colum);
       lcd_8bit_send_char_data(lcd,data);
    }
     
    return ERRORSTATUS;   
}

/**
 * 
 * @param lcd
 * @param str
 * @return 
 */
Std_ReturnType lcd_8bit_send_string_data(const char_lcd_8bit_t *lcd,uint8* str)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if (( NULL==lcd)||( NULL==str))
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        while(*str)
        {
          lcd_8bit_send_char_data(lcd,*str);
          str++;
        }
             
    }
     
    return ERRORSTATUS;
}
/**
 * 
 * @param lcd
 * @param rows
 * @param colums
 * @param str
 * @return 
 */
Std_ReturnType lcd_8bit_send_string_data_pos(const char_lcd_8bit_t *lcd,uint8 row,uint8 colum,uint8* str)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if (( NULL==lcd)||( NULL==str))
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        lcd_8bits_set_courser(lcd,row,colum);
        lcd_8bit_send_string_data(lcd,str);

             
    }
     
    return ERRORSTATUS;
}

Std_ReturnType lcd_8bit_send_custom_char(const char_lcd_8bit_t *lcd,uint8 row,uint8 colum,const uint8 _char[],uint8 memmory_pos)//why arr
{
        Std_ReturnType ERRORSTATUS =E_OK;
        uint8 lcd_counter=ZERO_INIT;
    if ( NULL==lcd)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
      lcd_8bit_send_command(lcd,LCD_CGRAM_START_ADDRESS+(memmory_pos*8));
      for(lcd_counter=0;lcd_counter<8;lcd_counter++)
       {
          lcd_8bit_send_char_data(lcd,_char[lcd_counter]) ;
       
       }
       lcd_8bit_send_char_data_pos(lcd,row,colum,memmory_pos);
       
    }
     
    return ERRORSTATUS;
}
//--------------------------------------------------------------converters--------------------------------------------------//
/**
 *  convert no from 0 to 255 to string with null termination in it's end
 * @param value: the value which will be converted to string 
 * @param str:  btr to array of char of 4 elements will include the string as  3 digit and null termination in the end
 */
Std_ReturnType convert_uint8_to_string(uint8 value,uint8*str)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    if ( NULL==str)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        memset(str,'\0',4);
        sprintf(str,"%i",value);
        
    }
      return ERRORSTATUS;
 
}
/**
 *  convert no from 0 to 65635 to string with null termination in it's end
 * @param value: the value which will be converted to string  
 * @param str:    btr to array of char of 6 elements will include the string as  5 digit and null termination in the end
 */
Std_ReturnType convert_uint16_to_string(uint16 value,uint8*str)
{
    Std_ReturnType ERRORSTATUS =E_OK;
    uint8 temp_string[6]={0};
    uint8 data_counter=0;
    if ( NULL==str)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
         memset(str,' ',5);
         str[5]='\0';
         sprintf((char*)temp_string,"%i",value);
         while(temp_string[data_counter]!='\0')
         {
            str[data_counter] =temp_string[data_counter];
            data_counter++;
         }
        sprintf(str,"%i",value);
    }
     
    return ERRORSTATUS;
}
/**
 * convert no from 0 to 4,294,967,296 to string with null termination in it's end
 * @param value:value the value which will be converted to string 
 * @param str btr to array of char of 11 elements will include the string as  10 digit and null termination in the end
 */
Std_ReturnType convert_uint32_to_string(uint32 value,uint8*str)
{
     Std_ReturnType ERRORSTATUS =E_OK;
    if ( NULL==str)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
        memset(str,'\0',11);
        sprintf(str,"%i",value);
    }
      return ERRORSTATUS;
   
}

//-----------------------------------------------------------helper static functions -------------------------------------------//
/**
 * 
 * @param lcd
 * @return 
 */
static Std_ReturnType lcd_4bits_send_enable_signal(const char_lcd_4bit_t *lcd)
{
    Std_ReturnType ERRORSTATUS =E_OK;
        if ( NULL==lcd)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
            GPIO_Pin_Write_Logic(&(lcd->lcd_enable_pin),GPIO_HIGH);
            __delay_us(5);
             GPIO_Pin_Write_Logic(&(lcd->lcd_enable_pin),GPIO_LOW);
            
    }
    return ERRORSTATUS;
}

static Std_ReturnType lcd_send_4bits(const char_lcd_4bit_t *lcd,uint8 data_command)
{
    Std_ReturnType ERRORSTATUS =E_OK;
        if ( NULL==lcd)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
            GPIO_Pin_Write_Logic(&(lcd->lcd_data_pins[0]),((data_command>>0)&(uint8)0x01));
            GPIO_Pin_Write_Logic(&(lcd->lcd_data_pins[1]),((data_command>>1)&(uint8)0x01));
            GPIO_Pin_Write_Logic(&(lcd->lcd_data_pins[2]),((data_command>>2)&(uint8)0x01));
            GPIO_Pin_Write_Logic(&(lcd->lcd_data_pins[3]),((data_command>>3)&(uint8)0x01));
            
    }
    return ERRORSTATUS;
}

/**
 * 
 * @param lcd
 * @return 
 */
static Std_ReturnType lcd_8bits_send_enable_signal(const char_lcd_8bit_t *lcd)
{
    Std_ReturnType ERRORSTATUS =E_OK;
        if ( NULL==lcd)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
            GPIO_Pin_Write_Logic(&(lcd->lcd_enable_pin),GPIO_HIGH);
            __delay_us(5);
             GPIO_Pin_Write_Logic(&(lcd->lcd_enable_pin),GPIO_LOW);
            
    }
    return ERRORSTATUS;
}

static Std_ReturnType lcd_8bits_set_courser(const char_lcd_8bit_t *lcd,uint8 row,uint8 colum)
{
    Std_ReturnType ERRORSTATUS =E_OK;
        if ( NULL==lcd)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
            colum--;
            switch (row)
            {
                case ROW1: lcd_8bit_send_command(lcd,(LCD_4ROWS_FIRST_ROW_ADDREESS+colum)); break;
                case ROW2: lcd_8bit_send_command(lcd,(LCD_4ROWS_SECOND_ROW_ADDREESS+colum));break;
                case ROW3: lcd_8bit_send_command(lcd,(LCD_4ROWS_THIRD_ROW_ADDREESS+colum));break;
                case ROW4: lcd_8bit_send_command(lcd,(LCD_4ROWS_FOURTH_ROW_ADDREESS+colum));break;
                default:                                break;
            }        
    }
    return ERRORSTATUS;
}

static Std_ReturnType lcd_4bits_set_courser(const char_lcd_4bit_t *lcd,uint8 row,uint8 colum)
{
    Std_ReturnType ERRORSTATUS =E_OK;
        if ( NULL==lcd)
    {
        ERRORSTATUS=E_NOT_OK;
    }
    else
    {
            colum--;
            switch (row)
            {
                case ROW1: lcd_4bit_send_command(lcd,(LCD_4ROWS_FIRST_ROW_ADDREESS+colum)); break;
                case ROW2: lcd_4bit_send_command(lcd,(LCD_4ROWS_SECOND_ROW_ADDREESS+colum));break;
                case ROW3: lcd_4bit_send_command(lcd,(LCD_4ROWS_THIRD_ROW_ADDREESS+colum));break;
                case ROW4: lcd_4bit_send_command(lcd,(LCD_4ROWS_FOURTH_ROW_ADDREESS+colum));break;
                default:                                break;
            }        
    }
    return ERRORSTATUS;
}