/* 
 * File:   mcal_i2c.c
 * Author: ahmed radwan
 *
 * Created on September 24, 2022, 2:45 AM
 */
#include"mcal_i2c.h"
static void I2C_Master_Mode_Clock_Configurations(const mssp_i2c_st *i2c_obj);
static void I2C_Slave_Mode_Clock_Configurations(const mssp_i2c_st *i2c_obj);

static void I2C_Pin_Configurations(void);
static void I2C_Interrupt_configuration(const mssp_i2c_st *i2c_obj);

#if MSSP_I2C_Interrupt_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE
static void (*I2C_DefaultInterruptHandler)(void)=NULL;
static void (*I2C_Report_Receive_Overflow)(void)=NULL;
#endif
#if MSSP_I2C_BUS_COL_Interrupt_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE 
static void (*I2C_Report_Write_Collision)(void)=NULL;
#endif


Std_returnType MSSP_I2C_Init(const mssp_i2c_st *i2c_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==i2c_obj)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        /* Disable MSSP I2C Module */
        MSSP_MODULE_DISABLE_CFG();
        /* MSSP I2C Select Mode */
        if(I2C_MSSP_MASTER_MODE==i2c_obj->i2c_cfg.i2c_mode)
        {
            /* I2C Master Mode Clock Configurations */
           I2C_Master_Mode_Clock_Configurations(i2c_obj);
        }
        else if (I2C_MSSP_SLAVE_MODE==i2c_obj->i2c_cfg.i2c_mode)
        { 
            /* I2C Slave Mode General Call Configurations */
            if(I2C_GENERAL_CALL_ENABLE==i2c_obj->i2c_cfg.i2c_general_call)
            {
                I2C_GENERAL_CALL_ENABLE_CFG();
            }
            else if(I2C_GENERAL_CALL_DISABLE==i2c_obj->i2c_cfg.i2c_general_call)
            {
                I2C_GENERAL_CALL_DISABLE_CFG();
            }      
            else{/*nothing*/}
            /*clear the write collision detected*/
             SSPCON1bits.WCOL=0;
            /*clear the receive over flow indicator */
             SSPCON1bits.SSPOV=0;
            /*release the clock*/
             SSPCON1bits.CKP=1;
            /*Assign i2c slave address*/
             SSPADD=i2c_obj->i2c_cfg.i2c_slave_address;
            /* I2C slave Mode Configurations */
             I2C_Slave_Mode_Clock_Configurations(i2c_obj);
        }
        else{/*nothing*/}
                /* I2C Master Mode GPIO Configurations */
        I2C_Pin_Configurations();
        /* MSSP I2C Slew Rate Control */
        if(I2C_SLEW_RATE_DISABLE == i2c_obj->i2c_cfg.i2c_slew_rate){
            I2C_SLEW_RATE_DISABLE_CFG();
        }
        else if(I2C_SLEW_RATE_ENABLE == i2c_obj->i2c_cfg.i2c_slew_rate){
            I2C_SLEW_RATE_ENABLE_CFG();
        }
        else { /* Nothing */ }
        /* MSSP I2C SMBus Control */
        if(I2C_SMBus_ENABLE == i2c_obj->i2c_cfg.i2c_SMBus_control){
            I2C_SMBus_ENABLE_CFG();
        }
        else if(I2C_SMBus_DISABLE == i2c_obj->i2c_cfg.i2c_SMBus_control){
            I2C_SMBus_DISABLE_CFG();
        }
        else { /* Nothing */ }
               /*interrupt initialization */
#if (MSSP_I2C_Interrupt_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE)||(MSSP_I2C_BUS_COL_Interrupt_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE )

        I2C_Interrupt_configuration(i2c_obj);
#endif
        
        /* Enable MSSP I2C Module */
        MSSP_MODULE_ENABLE_CFG();    
    }
    return ERRORSTATUS;    
}

Std_returnType MSSP_I2C_DeInit(const mssp_i2c_st *i2c_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==i2c_obj)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        /*disable the i2c*/
        MSSP_MODULE_DISABLE_CFG();
#if MSSP_I2C_Interrupt_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE
       INT_MSSP_I2C_DISABLE();
#endif
#if MSSP_I2C_BUS_COL_Interrupt_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE 
       INT_MSSP_I2C_BUS_COL_DISABLE();  
#endif
         
    }
    return ERRORSTATUS;    
}

Std_returnType MSSP_I2C_Master_Send_Start(const mssp_i2c_st *i2c_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==i2c_obj)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        /* Initiates Start condition on SDA and SCL pins */
        SSPCON2bits.SEN = 1; /* Initiates Start condition on SDA and SCL pins. Automatically cleared by hardware. */
        /* Wait for the completion of the Start condition */
        while(SSPCON2bits.SEN);
        /* Clear The MSSP Interrupt Flag bit -> SSPIF */
        PIR1bits.SSPIF = 0;
        /* Report The Start Condition Detection */
        if(I2C_START_BIT_DETECTED == SSPSTATbits.S)
        {
            ERRORSTATUS = E_OK; /* Indicates that a Start bit has been detected last */
        }
        else
        {
            ERRORSTATUS = E_NOK; /* Start bit was not detected last */
        }
         
    }
    return ERRORSTATUS;    
}

Std_returnType MSSP_I2C_Master_Send_Repeated_Start(const mssp_i2c_st *i2c_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==i2c_obj)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        /* Initiates Repeated Start condition on SDA and SCL pins */
        SSPCON2bits.RSEN = 1; /* Initiates Repeated Start condition on SDA and SCL pins. Automatically cleared by hardware */
        /* Wait for the completion of the Repeated Start condition */
        while(SSPCON2bits.RSEN);
        /* Clear The MSSP Interrupt Flag bit -> SSPIF */
        PIR1bits.SSPIF = 0;
        ERRORSTATUS = E_OK;
         
    }
    return ERRORSTATUS;    
}

Std_returnType MSSP_I2C_Master_Send_Stop(const mssp_i2c_st *i2c_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==i2c_obj)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        /* Initiates Stop condition on SDA and SCL pins */
        SSPCON2bits.PEN = 1; 
         /* Wait for the completion of the Start condition */
        while(SSPCON2bits.PEN);
        /* Clear The MSSP Interrupt Flag bit -> SSPIF */
        PIR1bits.SSPIF = 0;
        /* Report The Start Condition Detection */
        if(I2C_START_BIT_DETECTED == SSPSTATbits.P)
        {
            ERRORSTATUS = E_OK; /* Indicates that a Start bit has been detected last */
        }
        else
        {
            ERRORSTATUS = E_NOK; /* Start bit was not detected last */
        }
         
         
    }
    return ERRORSTATUS;   
}

Std_returnType MSSP_I2C_Master_Write_Blocking(const mssp_i2c_st *i2c_obj, uint8 i2c_data, uint8 *_ack)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==i2c_obj||NULL==_ack)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        /* Write Data to the Data register */
        SSPBUF=i2c_data;
        /* Wait The transmission to be completed */
        while(SSPSTATbits.BF);
        /* Clear The MSSP Interrupt Flag bit -> SSPIF */
        PIR1bits.SSPIF = 0;
        /* Report the acknowledge received from the slave */
        if(I2C_ACK_RECEIVED_FROM_SLAVE == SSPCON2bits.ACKSTAT)
        {
            *_ack = I2C_ACK_RECEIVED_FROM_SLAVE; /* Acknowledge was received from slave */
        }
        else
        {
            *_ack = I2C_ACK_NOT_RECEIVED_FROM_SLAVE; /* Acknowledge was not received from slave */
        }    
    }
    return ERRORSTATUS;
}

Std_returnType MSSP_I2C_Master_Read_Blocking(const mssp_i2c_st *i2c_obj, uint8 ack, uint8 *i2c_data)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==i2c_obj||NULL==i2c_data)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {
        /* Master Mode Receive Enable */
        I2C_MASTER_RECEIVE_ENABLE_CFG();
        /* Wait for buffer full flag : A complete byte received */       
        while(!SSPSTATbits.BF);
        /* Copy The data registers to buffer variable */
        *i2c_data = SSPBUF;
        if(ack==I2C_MASTER_SEND_ACK)
        {
            SSPCON2bits.ACKDT=I2C_MASTER_SEND_ACK;/*Acknowledge*/
            SSPCON2bits.ACKEN=1;/*Initiates Acknowledge sequence on SDA and SCL pins and transmit ACKDT data bit*/
            while(SSPCON2bits.ACKEN);
        }
        else if(ack==I2C_MASTER_SEND_NACK)
        {
             SSPCON2bits.ACKDT=I2C_MASTER_SEND_NACK;/*Not Acknowledge*/
             SSPCON2bits.ACKEN=1;/*Initiates Acknowledge sequence on SDA and SCL pins and transmit ACKDT data bit*/
             while(SSPCON2bits.ACKEN);
           
        }
        else{/*nothing*/}
         
    }
    return ERRORSTATUS;    
}

Std_returnType MSSP_I2C_Master_Write_NBlocking(const mssp_i2c_st *i2c_obj, uint8 i2c_data, uint8 *_ack)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==i2c_obj||NULL==_ack)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {

    
    }
    return ERRORSTATUS;    
} 

Std_returnType MSSP_I2C_Master_Read_NBlocking(const mssp_i2c_st *i2c_obj, uint8 ack, uint8 *i2c_data)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==i2c_obj||NULL==i2c_data)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {

         
    }
    return ERRORSTATUS;    
}

void I2C_ISR(void)
{
#if MSSP_I2C_Interrupt_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE

    INT_MSSP_I2C_CLEAR_FLAG();
    if(I2C_DefaultInterruptHandler)
    {
        I2C_DefaultInterruptHandler();
    }
#endif
 
}
void I2C_BC_ISR(void)
{
#if MSSP_I2C_BUS_COL_Interrupt_FEATURE_ENABLE ==Interrupt_FEATURE_ENABLE
    INT_MSSP_I2C_BUS_COL_CLEAR_FLAG(); 
    if(I2C_Report_Write_Collision)
    {
        I2C_Report_Write_Collision();
    }
#endif
}
static void I2C_Master_Mode_Clock_Configurations(const mssp_i2c_st *i2c_obj)
{
    Std_returnType ERRORSTATUS =E_OK;
    if (NULL==i2c_obj)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {

        SSPCON1bits.SSPM=i2c_obj->i2c_cfg.i2c_mode_cfg;
        SSPADD=(uint8)(((_XTAL_FREQ/4.0)/i2c_obj->i2c_clock)-1);
    }
    
}
static void I2C_Slave_Mode_Clock_Configurations(const mssp_i2c_st *i2c_obj)
{
     Std_returnType ERRORSTATUS =E_OK;
    if (NULL==i2c_obj)
    {
        ERRORSTATUS=E_NOK;
    }
    else
    {

        SSPCON1bits.SSPM=i2c_obj->i2c_cfg.i2c_mode_cfg;
    }    
}

static void I2C_Pin_Configurations(void)
{
    TRISCbits.RC3=1;
    TRISCbits.RC4=1;

    
}
static void I2C_Interrupt_configuration(const mssp_i2c_st *i2c_obj)
{
#if MSSP_I2C_INT_ENABLE ==FEATURE_ENABLE
       INT_MSSP_I2C_DISABLE();
#if INT_PRI_LEVELS_ENABLE==FEATURE_ENABLE
        INT_PRI_FET_EN();
        INT_GLOBAL_HIGH_EN();
        INT_GLOBAL_HIGH_DIS();
        if(INT_HIGH_PRI==i2c_obj->i2c_cfg.mssp_i2c_priority)
        {
            INT_MSSP_I2C_PRI_SET_HIGH();
        }
            else if(INT_LOW_PRI==i2c_obj->i2c_cfg.mssp_i2c_priority)
            {
                INT_MSSP_I2C_PRI_SET_LOW();
            }
            else{/*no thing*/}

#else
        
        INT_GLOBAL_EN();
        INT_PERIPHERAL_EN();
#endif 
        INT_MSSP_I2C_CLEAR_FLAG();
        INT_MSSP_I2C_ENABLE();

        I2C_DefaultInterruptHandler=i2c_obj->I2C_DefaultInterruptHandler;
        I2C_Report_Receive_Overflow =i2c_obj->I2C_Report_Receive_Overflow;
        
 
#endif
        /*bus collision interrupt initialization*/
#if MSSP_I2C_BUS_COL_INT_ENABLE==FEATURE_ENABLE    
       INT_MSSP_I2C_BUS_COL_DISABLE();
        
#if INT_PRI_LEVELS_ENABLE==FEATURE_ENABLE
        INT_PRI_FET_EN();
        INT_GLOBAL_HIGH_EN();
        INT_GLOBAL_HIGH_DIS();
        if(INT_HIGH_PRI==i2c_obj->i2c_cfg.mssp_i2c_bc_priority)
        {
            INT_MSSP_I2C_BUS_COL_PRI_SET_HIGH();
        }
        else if(INT_LOW_PRI==i2c_obj->i2c_cfg.mssp_i2c_bc_priority)
        {
            INT_MSSP_I2C_BUS_COL_PRI_SET_LOW();
        }
        else{/*no thing*/}
#else
        
        INT_GLOBAL_EN();
        INT_PERIPHERAL_EN();
#endif 
        INT_MSSP_I2C_BUS_COL_CLEAR_FLAG();
        INT_MSSP_I2C_BUS_COL_ENABLE();
        
        I2C_Report_Write_Collision=i2c_obj->I2C_Report_Write_Collision;
        
#endif    
}
