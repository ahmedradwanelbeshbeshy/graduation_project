/*
 * File:   application.c
 * Author: SPATIAL TEAM
 *
 * Created on September 16, 2022, 7:48 PM
 */

#include "application.h"

/*
ROBOT CAR MODEL
    .......
.../       \...
:::::Front:::::

W1----------W2
servo1      servo2

W3----------W4


W5----------W6
servo3      servo4
:::::Back:::::
\            /
 \__________/

*/

uint8 servo1Pos=0, servo2Pos=0, servo3Pos=0,servo4Pos=0,stepper_pos;//to store servo positions

stepper_config_st stepper_base={
    .dir_pin.direction=GPIO_DIRECTION_OUTPUT,
    .dir_pin.logic=GPIO_LOW,
    .dir_pin.pin=GPIO_PIN2,
    .dir_pin.port=PORTD_INDEX,
    
    .step_pin.direction=GPIO_DIRECTION_OUTPUT,
    .step_pin.logic=GPIO_LOW,
    .step_pin.pin=GPIO_PIN3,
    .step_pin.port=PORTD_INDEX
};


/************************************ test pin section **********************************/

pin_config_st TEST_PIN={
   .direction=GPIO_DIRECTION_OUTPUT,
   .logic=GPIO_LOW,
   .pin=GPIO_PIN0,
   .port=PORTC_INDEX 
};
/************************************ test pin section end **********************************/

/************************************ driller pin section **********************************/

pin_config_st driller_PIN={
   .direction=GPIO_DIRECTION_OUTPUT,
   .logic=GPIO_HIGH,
   .pin=GPIO_PIN2,
   .port=PORTA_INDEX 
};
/************************************ test pin section end **********************************/




/***********************************battery_level section***********************************/

void battery_level(void);
adc_result_t battery_volt_adc_read;
float32  battery_volt_f=12;

adc_config_st battery_adc={
    .adc_channel=ADC_CHANEL_AN0,
    .conversion_clock=ADC_CONVERSION_CLOCK_FOSC_DIV_32,
    .acquisition_time=ADC_12_TAD,
    .result_format=ADC_RESULT_RIGHT,
    .voltage_referance=ADC_VOLTAGE_REFERANCE_INTERNAL
};
///***********************note the crystal OSC has been changed to be 24MHZ in device_config.h**********************/

/***********************************battery_level section end *******************************/





/************************************ usart & gps  section **********************************/

void  usart_isr (void);
void GPS_Service (void);

volatile uint8 gps=1;
volatile uint8 blue=1;
volatile uint8 gpstemp=0;
volatile uint8 counter;
volatile uint8 datasend='w';
volatile uint16 datarecive=0;

volatile uint8 latitude[13];
volatile uint8 longtude[13];

uint8 i=0;

uart_config_st _uart_obj = {
  .baud_rate_config = BAUDRATE_ASYNC_8BIT_LOW_SPEED ,
  .uart_baud_rate_value =9600,
  .tx_config.tx_9th_bit_en = EUSART_ASYNCH_Tx_BIT_9_DISABLED ,
  .tx_config.tx_enable = EUSART_ASYNCH_TX_EN ,
  //.tx_config.uart_tx_priority = INT_HIGH_PRI ,
  .rx_config.rx_9th_bit_en = EUSART_ASYNCH_Tx_BIT_9_DISABLED ,
  .rx_config.rx_enable = EUSART_ASYNCH_RX_EN,
  .rx_config.uart_rx_priority=INT_PRI_HIGH,
  .rx_config.rx_InterruptHandler=usart_isr
 
};

pin_config_st selector={
   .direction=GPIO_DIRECTION_OUTPUT,
   .logic=GPIO_HIGH,
   .pin=GPIO_PIN4,
   .port=PORTD_INDEX 
};

/************************************ usart & gps  section  end **********************************/



/************************************dc motor  section **********************************/


/* CCP1 :  W1 , W3 , W5     (Left Side) */
ccp_st CCP1_Obj =
{
    .ccp_inst = CCP1_INST ,
    .ccp_mode = CCP_PWM_MODE_SELECTED,
    .PWM_Frequency = 500,
    .ccp_pin.port = PORTC_INDEX,
    .ccp_pin.pin = GPIO_PIN2,
    .ccp_pin.direction = GPIO_DIRECTION_OUTPUT,
    .timer2.timer2_preload_value=249,/*((_XTAL_FREQ / ((_ccp_obj->PWM_Frequency )* 4.0 * _ccp_obj->timer2.timer2_prescaler_value) - 1))*/
    .timer2.timer2_postscaler_value=TIMER2_postscaler_DIV_BY_16,
    .timer2.timer2_prescaler_value=TIMER2_PRESCALER_DIV_BY_1
};
/* CCP2 :  W1 , W4 , W6     (Right Side) */
ccp_st CCP2_Obj =
{
    .ccp_inst = CCP2_INST ,
    .ccp_mode = CCP_PWM_MODE_SELECTED,
    .PWM_Frequency = 500,
    .ccp_pin.port = PORTC_INDEX,
    .ccp_pin.pin = GPIO_PIN1,
    .ccp_pin.direction = GPIO_DIRECTION_OUTPUT,
    .timer2.timer2_preload_value=249,/*((_XTAL_FREQ / ((_ccp_obj->PWM_Frequency )* 4.0 * _ccp_obj->timer2.timer2_prescaler_value) - 1))*/
    .timer2.timer2_postscaler_value=TIMER2_postscaler_DIV_BY_16,
    .timer2.timer2_prescaler_value=TIMER2_PRESCALER_DIV_BY_1
};

/************************************dc motor  section end**********************************/

/************************************I2C section **********************************/

/*i2c and servos */
mssp_i2c_st i2c_obj={
  .i2c_cfg.i2c_mode=  I2C_MSSP_MASTER_MODE,
  .i2c_cfg.i2c_mode_cfg=I2C_MASTER_MODE_DEFINED_CLOCK,
  .i2c_clock=100000,
  .i2c_cfg.i2c_SMBus_control=I2C_SMBus_DISABLE,
  .i2c_cfg.i2c_slew_rate=I2C_SLEW_RATE_DISABLE,
  //.I2C_DefaultInterruptHandler=NULL,
  //.I2C_Report_Receive_Overflow=NULL,
  //.I2C_Report_Write_Collision=NULL
};
servo_driver_st servo_driver_obj={
   .slave_address=SERVO_DRIVER_SLAVE_ADDRESS,
   .frequancy=ECU_SM_PRE_SCALE_REG_VAL,
   .mode_1_cfg=0x21,
   .mode_2_cfg=0x04   
};

/************************************I2C section end**********************************/


/************************************dht sensor section**********************************/

uint8 RH_Decimal=77, RH_Integral, T_Decimal=19, T_Integral, Checksum;
// to change dht pin check DHT_CFG.h file

/************************************dht sensor section end**********************************/


/************************************ultra sonic**********************************/

float32 distance;
// uint8 dis[10]={};// needed to display the result on the lcd

 ultrasonic_config_st ultrasonic={
     .trig_pin.direction=GPIO_DIRECTION_OUTPUT,
     .trig_pin.logic=GPIO_LOW,
     .trig_pin.pin=GPIO_PIN3,
     .trig_pin.port=PORTB_INDEX, 
     
     .echo_pin.direction=GPIO_DIRECTION_INPUT,
     .echo_pin.logic=GPIO_LOW,
     .echo_pin.pin=GPIO_PIN2,
     .echo_pin.port=PORTB_INDEX       
 };
 timer0_config_st timer0={
   .preloaded_value=0,
   .prescaler_enable=TMR0_PRESCALER_ON,
   .prescalar_value=TMR0_PRESCALER_BY_2,
   .reg_bit_size=TMR0_16BIT,
   .timer_mode=TMR0_TIMER_MODE
 };
 
 /************************************ultra sonic end**********************************/

int main()
{
    application_intialize();
    GPIO_Pin_Toggle_Logic(&TEST_PIN);
    while(1)
    {
     
     //GPIO_Pin_Toggle_Logic(&TEST_PIN);
    //_delay_ms(500);
switch(datarecive)
        {

            case NOTHING:
                //no thing
                Robot_Steer_Stop();
                datarecive=DO_ONE_TIME;// make sure that will do the command only one time
                break;
            case LEFT_FORWARD:
                // left forward
                Robot_Steer_Left_Forward();
                datarecive=DO_ONE_TIME;// make sure that will do the command only one time
                break;
            case FORWARD:
                // forward
                Robot_Move_Forward();
                datarecive=DO_ONE_TIME;// make sure that will do the command only one time
                break;
            case RIGHT_FORWARD:
                // right forward
                Robot_Steer_Right_Forward();
                datarecive=DO_ONE_TIME;// make sure that will do the command only one time
                break;
            case TURN_LEFT:
                // turn left
                /*first we stop dc motors*/
                 Robot_Steer_Left();
                datarecive=DO_ONE_TIME;// make sure that will do the command only one time
                break;
            case TURN_RIGHT:
                // turn right
                Robot_Steer_Right();
                datarecive=DO_ONE_TIME;// make sure that will do the command only one time
                break;
            case LEFT_BACKWARD:
                // left backward
                Robot_Steer_Left_Backward();
                datarecive=DO_ONE_TIME;// make sure that will do the command only one time
                break;
            case BACKWARD:
                //  backward
                Robot_Move_Backward();
                datarecive=DO_ONE_TIME;// make sure that will do the command only one time
                break;
            case RIGHT_BACKWARD:
                // right backward
                Robot_Steer_Right_Backward();
                datarecive=DO_ONE_TIME;// make sure that will do the command only one time
                break;
            case ROTATE_LEFT:
                // rotate left
                datarecive=DO_ONE_TIME;// make sure that will do the command only one time
                break;
            case driller_Buttom:
                // rotate right 
                GPIO_Pin_Toggle_Logic(&driller_PIN);//
                //datarecive=DO_ONE_TIME;// make sure that will do the command only one time
                 break;
//->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>///////////robot arm section///////////<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-//
             case BASE_DECREASE:
                // base decrease
                 stepper_move_one_deg_cw(&stepper_base);
                 break;
             
             case BASE_INCREAS:
                 // base increas
                stepper_move_one_deg_ccw(&stepper_base);
                break;
             
             case JOINT1_DECREASE:
                  //joint1 decrease
                  servo1Pos--;
                  if(servo1Pos<1)
                  {
                    servo1Pos=1;
                  }
                  Servo_SetAngle(&i2c_obj , &servo_driver_obj , servo_index_9 , servo1Pos ); 
                  __delay_ms(SERVO_DELAY);

 
                  break;
             
             case JOINT1_INCREASE:
                 //joint1 increase 
                 servo1Pos++;
                 if(servo1Pos>180)
                 {
                   servo1Pos=180;
                 }
                 Servo_SetAngle(&i2c_obj , &servo_driver_obj , servo_index_9 , servo1Pos );  
                 __delay_ms(SERVO_DELAY);

                 break;
          
             case JOINT2_DECREASE:
                  //joint2 decrease 
                  servo2Pos--;
                  if(servo2Pos<1)
                  {
                    servo2Pos=1;
                  }
                  Servo_SetAngle(&i2c_obj , &servo_driver_obj , servo_index_10 , servo2Pos );
                  __delay_ms(SERVO_DELAY);
                  break;
             
             case JOINT2_INCREASE:
                  //joint2 increase 
                  servo2Pos++;
                  if(servo2Pos>180)
                  {
                    servo2Pos=180;
                  }
                  Servo_SetAngle(&i2c_obj , &servo_driver_obj , servo_index_10 , servo2Pos );
                  __delay_ms(SERVO_DELAY);
                  break;
                  
             case JOINT3_DECREASE:
                  //joint3 decrease 
                  servo3Pos--;
                  if(servo3Pos<1)
                  {
                    servo3Pos=1;
                  }
                  Servo_SetAngle(&i2c_obj , &servo_driver_obj , servo_index_11 , servo3Pos );
                  __delay_ms(SERVO_DELAY);
                  break;
             
             case JOINT3_INCREASE:
                  //joint3 increase
                  servo3Pos++;
                  if(servo3Pos>180)
                  {
                    servo3Pos=180;
                  }
                  Servo_SetAngle(&i2c_obj , &servo_driver_obj , servo_index_11 , servo3Pos );
                  __delay_ms(SERVO_DELAY);
                  break;
             
             case JOINT4_DECREASE:
                  //joint4 decrease 
                  servo4Pos--;
                  if(servo4Pos<1)
                  {
                    servo4Pos=1;
                  }
                  Servo_SetAngle(&i2c_obj , &servo_driver_obj , servo_index_12 , servo4Pos );
                  __delay_ms(SERVO_DELAY);
                  break;
             
             case JOINT4_INCREASE:
                  //joint4 increase
                  servo4Pos++;
                  if(servo4Pos>180)
                  {
                    servo4Pos=180;
                  }
                  Servo_SetAngle(&i2c_obj , &servo_driver_obj , servo_index_12 , servo4Pos );
                  __delay_ms(SERVO_DELAY);
                  break;
//->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>///////////sensors///////////<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-//
             case GET_T:
                 //GET_temp
                 Get_Temp_HUM(&RH_Decimal, &RH_Integral, &T_Decimal, &T_Integral, &Checksum);
                 Bluetooth_Send_Data_Non_Blocking(&_uart_obj,48+((uint8)(T_Decimal/10)));
                 __delay_ms(5);
                 Bluetooth_Send_Data_Non_Blocking(&_uart_obj,48+((uint8)(T_Decimal%10)));
                 datarecive=DO_ONE_TIME;// make sure that will do the command only one time        
                 break;
             case GET_RH:
                 //GET_RH
                 Bluetooth_Send_Data_Non_Blocking(&_uart_obj,48+((uint8)(RH_Decimal/10)));
                  __delay_ms(5);
                 Bluetooth_Send_Data_Non_Blocking(&_uart_obj,48+((uint8)(RH_Decimal%10)));

                 datarecive=DO_ONE_TIME;// make sure that will do the command only one time        
                 break;
             case GET_DISTANCE:
                 //GET_DISTANCE
                 Get_Distance(&ultrasonic,&timer0,&distance);
                 Bluetooth_Send_Data_Non_Blocking(&_uart_obj,48+((uint8)(distance/100)));
                 Bluetooth_Send_Data_Non_Blocking(&_uart_obj,48+((uint8)(((uint8)distance%100)/10)));
                 Bluetooth_Send_Data_Non_Blocking(&_uart_obj,48+((uint8)(((uint8)distance%100)%10)));

                 
                 datarecive=DO_ONE_TIME;// make sure that will do the command only one time
                 break;
             case GET_LOCATION:
                 //GET_LOCATION
                 GPS_Service();
                 datarecive=DO_ONE_TIME;// make sure that will do the command only one time
                 break;
             case GET_VOLT:
                 //GET_VOLT_from battery
                 battery_level();
                 __delay_ms(5);
                 Bluetooth_Send_Data_Non_Blocking(&_uart_obj,(uint8)battery_volt_f);
                 datarecive=DO_ONE_TIME;// make sure that will do the command only one time
                 break;  
             default:
                   // do no thing stay on your place
                   break;
        } 
    }
    return 0;
}
void application_intialize(void)
{
    /*initialize test pin & selector pin which select bluetooth or gps   */
    
    GPIO_Pin_Initialize(&TEST_PIN);
    GPIO_Pin_Initialize(&selector);
    GPIO_Pin_Initialize(&driller_PIN);
    
    
    /*initialize Stepper pins*/
    Ecu_Stepper_Init(&stepper_base);

    /*initialize dc driver pins & servo driver */
    
    Robot_Nav_Init();
    
    
    /*set all steer servos on angle 90*/
    Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W1 , NAV_SERVO_NO_STEER_ANGLE );    // W1
    __delay_ms(10);
    Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W2 , NAV_SERVO_NO_STEER_ANGLE );    // W2
    __delay_ms(10);
    Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W5 , NAV_SERVO_NO_STEER_ANGLE );    // W5 
    __delay_ms(10);
    Servo_SetAngle(&i2c_obj , &servo_driver_obj , SERVO_W6 , NAV_SERVO_NO_STEER_ANGLE );    // W6
    __delay_ms(10);
    /*set all arm servos on angle 0*/
    
    Servo_SetAngle(&i2c_obj , &servo_driver_obj ,  SERVO_JOINNT_1 , 0);    // JOINNT_1 
    __delay_ms(10);
    Servo_SetAngle(&i2c_obj , &servo_driver_obj ,  SERVO_JOINNT_2 , 0);    // JOINNT_2 
    __delay_ms(10);
    Servo_SetAngle(&i2c_obj , &servo_driver_obj ,  SERVO_JOINNT_3 , 0);    // JOINNT_3 
    __delay_ms(10);
    Servo_SetAngle(&i2c_obj , &servo_driver_obj ,  SERVO_JOINNT_4 , 0);    // JOINNT_4 
    __delay_ms(10);
    /*initialize UltraSonic pins*/
    Ultra_Sonic_Init(&ultrasonic,&timer0);
    
    /*initialize EUSART */
    EUSART_Async_Init(&_uart_obj);

    
      /*initialize ADC pins*/
   ADC_Init(&battery_adc);    
}

void usart_isr (void)
{
    EUSART_Async_Read_Data(&_uart_obj,&datarecive);
    Bluetooth_Send_Data_Non_Blocking(&_uart_obj,datasend);
    GPIO_Pin_Toggle_Logic(&TEST_PIN);
}
void GPS_Service (void)
{
    uint8 key=1;
    INT_EUSART_Rx_DISABLE();//disable rx interrupt 
    GPIO_Pin_Write_Logic(&selector,GPIO_HIGH);

    while (key)
    {
        EUSART_Async_Read_Data_Blocking(&_uart_obj,&gpstemp); // wait untill recive
        if ('$'==gpstemp)
        {
            while (key)
            {
                    EUSART_Async_Read_Data_Blocking(&_uart_obj,&gpstemp); // wait untill recive
                    if (','==gpstemp)
                    {
                        counter++;
                        if (3==counter)
                        {
                            i=0;
                            //lattitude
                            do
                            {
                                EUSART_Async_Read_Data_Blocking(&_uart_obj,(latitude+i));
                                i++;
                            }while(','!=(latitude[i-1]));
                            counter++;

                        }
                        else if(5==counter)
                        {
                            i=0;
                            //longtude
                            do{
                                EUSART_Async_Read_Data_Blocking(&_uart_obj,(longtude+i));
                                i++;
                            }while(','!=(longtude[i-1]));
                            key=0;
                        }
                    }
            }
        }
    }
      __delay_ms(2000);
    GPIO_Pin_Write_Logic(&selector,GPIO_LOW);
    INT_EUSART_Rx_ENABLE() ;//rx interruptenable
}



void battery_level(void)
{
        ADC_Get_Conversion_Blocking(&battery_adc,ADC_CHANEL_AN0,&battery_volt_adc_read);
        battery_volt_f=(float32)(battery_volt_adc_read*13)/1024;//13 get from 5*2.6->->-2.6=(r1+r2)/r2   
}
