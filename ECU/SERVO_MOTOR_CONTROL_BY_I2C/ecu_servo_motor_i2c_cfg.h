/* 
 * File:   ecu_servo_motor_i2c_cfg.h
 * Author: ahmed radwan
 *
 * Created on September 24, 2022, 4:03 AM
 */

#ifndef ECU_SERVO_MOTOR_I2C_CFG_H
#define	ECU_SERVO_MOTOR_I2C_CFG_H
/* set the slave address of the PCA9685 The bit no 8 always set by 1 and bit no 0 depend on read(1) or write(0) oberation
 *the other bits hardware  selectable */

#define SERVO_DRIVER_SLAVE_ADDRESS 0x80

/* configure the pre scaler of the PCA9685 the servo motor need to wave of frequency of 50HZ by substetude in the equation from data sheet 
 * 
 * prescaler=(osc_clock/(4096*update_rate))-1
 * OSC_clock =25MHZ
 * update rate 50HZ
 * prescaler=121=0x79
 * 
 **/
#define ECU_SM_PRE_SCALE_REG_VAL           0x79

/*set the configuration of the PCA9685 in mode 1 register
 * here we cofigar as 
 * bit7: Restart disabled
 * bit6: Use internal clock
 * bit5: Register Auto-Increment enabled
 * bit4: Normal mode
 * bit3: PCA9685 does not respond to I2C-bus subaddress 1.
 * bit2: PCA9685 does not respond to I2C-bus subaddress 2.
 * bit1: PCA9685 does not respond to I2C-bus subaddress 3.
 * bit0: PCA9685 responds to LED All Call I2C-bus address. 
 * in binary:00100001
 **/
#define ECU_SM_MODE1_REG_INIT_VAL       0x21

/*set the configuration of the PCA9685 in mode 2 register
 * here we cofigar as 
 * bit (7-5): Reserved
 * bit4: Output logic state not inverted. Value to use when external driver used
 * bit3: Outputs change on STOP command[2].
 * bit2: The 16 LEDn outputs are configured with a totem pole structure.
 * bit1: When OE = 1 (output drivers not enabled), LEDn = 0.
 * bit0: When OE = 1 (output drivers not enabled), LEDn = 0.
 * in binary:00000100
 **/
#define ECU_SM_MODE2_REG_INIT_VAL       0x04

/* the value of the internal OSC of PCA9685*/
#define ECU_SM_INT_OSC                  25000000UL


#endif	/* ECU_SERVO_MOTOR_I2C_CFG_H */

