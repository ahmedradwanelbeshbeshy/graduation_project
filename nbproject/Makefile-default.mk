#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/graduation_project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/graduation_project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU/Bluetooth/Bluetooth.c ECU/DC_Motor/ecu_dc_motor.c ECU/IR_Sensor/IR_SENSOR.c ECU/LCD_for_test_gps/ecu_char_lcd.c ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.c ECU/stepper/ecu_stepper.c ECU/ecu_layer_init.c MCAL/ADC/mcal_adc.c MCAL/CCP/hal_ccp.c MCAL/EUSART/mcal_EUSART.c MCAL/GPIO/hal_gpio.c MCAL/I2C/mcal_i2c.c MCAL/Interrupts/mcal_interrupt_manager.c MCAL/Interrupts/mcal_internal_interrupt.c MCAL/Interrupts/mcal_external_interrupt.c MCAL/Timer0/hal_timer0.c MCAL/TIMER1/TIMER1.c MCAL/WATCH_DOG_TIMER/WDT.c MCAL/device_config.c Robot/Navigation/robot_navigation.c Robot/sensors/DHT11/DHT.c Robot/sensors/ultrasonic/ultrasonic.c application.c MCAL/TIMER2/mcal_timer2.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1 ${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.p1 ${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.p1 ${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.p1 ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1 ${OBJECTDIR}/ECU/stepper/ecu_stepper.p1 ${OBJECTDIR}/ECU/ecu_layer_init.p1 ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1 ${OBJECTDIR}/MCAL/CCP/hal_ccp.p1 ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1 ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1 ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL/Timer0/hal_timer0.p1 ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1 ${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.p1 ${OBJECTDIR}/MCAL/device_config.p1 ${OBJECTDIR}/Robot/Navigation/robot_navigation.p1 ${OBJECTDIR}/Robot/sensors/DHT11/DHT.p1 ${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1.d ${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.p1.d ${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.p1.d ${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.p1.d ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1.d ${OBJECTDIR}/ECU/stepper/ecu_stepper.p1.d ${OBJECTDIR}/ECU/ecu_layer_init.p1.d ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1.d ${OBJECTDIR}/MCAL/CCP/hal_ccp.p1.d ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1.d ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1.d ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1.d ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1.d ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1.d ${OBJECTDIR}/MCAL/Timer0/hal_timer0.p1.d ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1.d ${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.p1.d ${OBJECTDIR}/MCAL/device_config.p1.d ${OBJECTDIR}/Robot/Navigation/robot_navigation.p1.d ${OBJECTDIR}/Robot/sensors/DHT11/DHT.p1.d ${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.p1.d ${OBJECTDIR}/application.p1.d ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1 ${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.p1 ${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.p1 ${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.p1 ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1 ${OBJECTDIR}/ECU/stepper/ecu_stepper.p1 ${OBJECTDIR}/ECU/ecu_layer_init.p1 ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1 ${OBJECTDIR}/MCAL/CCP/hal_ccp.p1 ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1 ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1 ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL/Timer0/hal_timer0.p1 ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1 ${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.p1 ${OBJECTDIR}/MCAL/device_config.p1 ${OBJECTDIR}/Robot/Navigation/robot_navigation.p1 ${OBJECTDIR}/Robot/sensors/DHT11/DHT.p1 ${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1

# Source Files
SOURCEFILES=ECU/Bluetooth/Bluetooth.c ECU/DC_Motor/ecu_dc_motor.c ECU/IR_Sensor/IR_SENSOR.c ECU/LCD_for_test_gps/ecu_char_lcd.c ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.c ECU/stepper/ecu_stepper.c ECU/ecu_layer_init.c MCAL/ADC/mcal_adc.c MCAL/CCP/hal_ccp.c MCAL/EUSART/mcal_EUSART.c MCAL/GPIO/hal_gpio.c MCAL/I2C/mcal_i2c.c MCAL/Interrupts/mcal_interrupt_manager.c MCAL/Interrupts/mcal_internal_interrupt.c MCAL/Interrupts/mcal_external_interrupt.c MCAL/Timer0/hal_timer0.c MCAL/TIMER1/TIMER1.c MCAL/WATCH_DOG_TIMER/WDT.c MCAL/device_config.c Robot/Navigation/robot_navigation.c Robot/sensors/DHT11/DHT.c Robot/sensors/ultrasonic/ultrasonic.c application.c MCAL/TIMER2/mcal_timer2.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/graduation_project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F46K20
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1: ECU/Bluetooth/Bluetooth.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/Bluetooth" 
	@${RM} ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1.d 
	@${RM} ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1 ECU/Bluetooth/Bluetooth.c 
	@-${MV} ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.d ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.p1: ECU/DC_Motor/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.p1 ECU/DC_Motor/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.d ${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.p1: ECU/IR_Sensor/IR_SENSOR.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/IR_Sensor" 
	@${RM} ${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.p1.d 
	@${RM} ${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.p1 ECU/IR_Sensor/IR_SENSOR.c 
	@-${MV} ${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.d ${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.p1: ECU/LCD_for_test_gps/ecu_char_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LCD_for_test_gps" 
	@${RM} ${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.p1 ECU/LCD_for_test_gps/ecu_char_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.d ${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1: ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C" 
	@${RM} ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1.d 
	@${RM} ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1 ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.c 
	@-${MV} ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.d ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/stepper/ecu_stepper.p1: ECU/stepper/ecu_stepper.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/stepper" 
	@${RM} ${OBJECTDIR}/ECU/stepper/ecu_stepper.p1.d 
	@${RM} ${OBJECTDIR}/ECU/stepper/ecu_stepper.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/stepper/ecu_stepper.p1 ECU/stepper/ecu_stepper.c 
	@-${MV} ${OBJECTDIR}/ECU/stepper/ecu_stepper.d ${OBJECTDIR}/ECU/stepper/ecu_stepper.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/stepper/ecu_stepper.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/ecu_layer_init.p1: ECU/ecu_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU" 
	@${RM} ${OBJECTDIR}/ECU/ecu_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU/ecu_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/ecu_layer_init.p1 ECU/ecu_layer_init.c 
	@-${MV} ${OBJECTDIR}/ECU/ecu_layer_init.d ${OBJECTDIR}/ECU/ecu_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/ecu_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/ADC/mcal_adc.p1: MCAL/ADC/mcal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/ADC" 
	@${RM} ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1 MCAL/ADC/mcal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL/ADC/mcal_adc.d ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/CCP/hal_ccp.p1: MCAL/CCP/hal_ccp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/CCP" 
	@${RM} ${OBJECTDIR}/MCAL/CCP/hal_ccp.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/CCP/hal_ccp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/CCP/hal_ccp.p1 MCAL/CCP/hal_ccp.c 
	@-${MV} ${OBJECTDIR}/MCAL/CCP/hal_ccp.d ${OBJECTDIR}/MCAL/CCP/hal_ccp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/CCP/hal_ccp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1: MCAL/EUSART/mcal_EUSART.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EUSART" 
	@${RM} ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1 MCAL/EUSART/mcal_EUSART.c 
	@-${MV} ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.d ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1: MCAL/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 MCAL/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1: MCAL/I2C/mcal_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/I2C" 
	@${RM} ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1 MCAL/I2C/mcal_i2c.c 
	@-${MV} ${OBJECTDIR}/MCAL/I2C/mcal_i2c.d ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1: MCAL/Interrupts/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupts" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1 MCAL/Interrupts/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1: MCAL/Interrupts/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupts" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1 MCAL/Interrupts/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1: MCAL/Interrupts/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupts" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1 MCAL/Interrupts/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.d ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Timer0/hal_timer0.p1: MCAL/Timer0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Timer0" 
	@${RM} ${OBJECTDIR}/MCAL/Timer0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Timer0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Timer0/hal_timer0.p1 MCAL/Timer0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL/Timer0/hal_timer0.d ${OBJECTDIR}/MCAL/Timer0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Timer0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1: MCAL/TIMER1/TIMER1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1 MCAL/TIMER1/TIMER1.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER1/TIMER1.d ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.p1: MCAL/WATCH_DOG_TIMER/WDT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/WATCH_DOG_TIMER" 
	@${RM} ${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.p1 MCAL/WATCH_DOG_TIMER/WDT.c 
	@-${MV} ${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.d ${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/device_config.p1: MCAL/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/device_config.p1 MCAL/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL/device_config.d ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Robot/Navigation/robot_navigation.p1: Robot/Navigation/robot_navigation.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Robot/Navigation" 
	@${RM} ${OBJECTDIR}/Robot/Navigation/robot_navigation.p1.d 
	@${RM} ${OBJECTDIR}/Robot/Navigation/robot_navigation.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Robot/Navigation/robot_navigation.p1 Robot/Navigation/robot_navigation.c 
	@-${MV} ${OBJECTDIR}/Robot/Navigation/robot_navigation.d ${OBJECTDIR}/Robot/Navigation/robot_navigation.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Robot/Navigation/robot_navigation.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Robot/sensors/DHT11/DHT.p1: Robot/sensors/DHT11/DHT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Robot/sensors/DHT11" 
	@${RM} ${OBJECTDIR}/Robot/sensors/DHT11/DHT.p1.d 
	@${RM} ${OBJECTDIR}/Robot/sensors/DHT11/DHT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Robot/sensors/DHT11/DHT.p1 Robot/sensors/DHT11/DHT.c 
	@-${MV} ${OBJECTDIR}/Robot/sensors/DHT11/DHT.d ${OBJECTDIR}/Robot/sensors/DHT11/DHT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Robot/sensors/DHT11/DHT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.p1: Robot/sensors/ultrasonic/ultrasonic.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Robot/sensors/ultrasonic" 
	@${RM} ${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.p1.d 
	@${RM} ${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.p1 Robot/sensors/ultrasonic/ultrasonic.c 
	@-${MV} ${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.d ${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1: MCAL/TIMER2/mcal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER2" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1 MCAL/TIMER2/mcal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.d ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1: ECU/Bluetooth/Bluetooth.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/Bluetooth" 
	@${RM} ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1.d 
	@${RM} ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1 ECU/Bluetooth/Bluetooth.c 
	@-${MV} ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.d ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.p1: ECU/DC_Motor/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.p1 ECU/DC_Motor/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.d ${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/DC_Motor/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.p1: ECU/IR_Sensor/IR_SENSOR.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/IR_Sensor" 
	@${RM} ${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.p1.d 
	@${RM} ${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.p1 ECU/IR_Sensor/IR_SENSOR.c 
	@-${MV} ${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.d ${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/IR_Sensor/IR_SENSOR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.p1: ECU/LCD_for_test_gps/ecu_char_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LCD_for_test_gps" 
	@${RM} ${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.p1 ECU/LCD_for_test_gps/ecu_char_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.d ${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LCD_for_test_gps/ecu_char_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1: ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C" 
	@${RM} ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1.d 
	@${RM} ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1 ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.c 
	@-${MV} ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.d ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/stepper/ecu_stepper.p1: ECU/stepper/ecu_stepper.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/stepper" 
	@${RM} ${OBJECTDIR}/ECU/stepper/ecu_stepper.p1.d 
	@${RM} ${OBJECTDIR}/ECU/stepper/ecu_stepper.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/stepper/ecu_stepper.p1 ECU/stepper/ecu_stepper.c 
	@-${MV} ${OBJECTDIR}/ECU/stepper/ecu_stepper.d ${OBJECTDIR}/ECU/stepper/ecu_stepper.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/stepper/ecu_stepper.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/ecu_layer_init.p1: ECU/ecu_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU" 
	@${RM} ${OBJECTDIR}/ECU/ecu_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU/ecu_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/ecu_layer_init.p1 ECU/ecu_layer_init.c 
	@-${MV} ${OBJECTDIR}/ECU/ecu_layer_init.d ${OBJECTDIR}/ECU/ecu_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/ecu_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/ADC/mcal_adc.p1: MCAL/ADC/mcal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/ADC" 
	@${RM} ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1 MCAL/ADC/mcal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL/ADC/mcal_adc.d ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/ADC/mcal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/CCP/hal_ccp.p1: MCAL/CCP/hal_ccp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/CCP" 
	@${RM} ${OBJECTDIR}/MCAL/CCP/hal_ccp.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/CCP/hal_ccp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/CCP/hal_ccp.p1 MCAL/CCP/hal_ccp.c 
	@-${MV} ${OBJECTDIR}/MCAL/CCP/hal_ccp.d ${OBJECTDIR}/MCAL/CCP/hal_ccp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/CCP/hal_ccp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1: MCAL/EUSART/mcal_EUSART.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EUSART" 
	@${RM} ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1 MCAL/EUSART/mcal_EUSART.c 
	@-${MV} ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.d ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1: MCAL/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 MCAL/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1: MCAL/I2C/mcal_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/I2C" 
	@${RM} ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1 MCAL/I2C/mcal_i2c.c 
	@-${MV} ${OBJECTDIR}/MCAL/I2C/mcal_i2c.d ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1: MCAL/Interrupts/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupts" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1 MCAL/Interrupts/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1: MCAL/Interrupts/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupts" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1 MCAL/Interrupts/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1: MCAL/Interrupts/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupts" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1 MCAL/Interrupts/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.d ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Timer0/hal_timer0.p1: MCAL/Timer0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Timer0" 
	@${RM} ${OBJECTDIR}/MCAL/Timer0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Timer0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Timer0/hal_timer0.p1 MCAL/Timer0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL/Timer0/hal_timer0.d ${OBJECTDIR}/MCAL/Timer0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Timer0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1: MCAL/TIMER1/TIMER1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1 MCAL/TIMER1/TIMER1.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER1/TIMER1.d ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER1/TIMER1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.p1: MCAL/WATCH_DOG_TIMER/WDT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/WATCH_DOG_TIMER" 
	@${RM} ${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.p1 MCAL/WATCH_DOG_TIMER/WDT.c 
	@-${MV} ${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.d ${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/WATCH_DOG_TIMER/WDT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/device_config.p1: MCAL/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/device_config.p1 MCAL/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL/device_config.d ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Robot/Navigation/robot_navigation.p1: Robot/Navigation/robot_navigation.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Robot/Navigation" 
	@${RM} ${OBJECTDIR}/Robot/Navigation/robot_navigation.p1.d 
	@${RM} ${OBJECTDIR}/Robot/Navigation/robot_navigation.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Robot/Navigation/robot_navigation.p1 Robot/Navigation/robot_navigation.c 
	@-${MV} ${OBJECTDIR}/Robot/Navigation/robot_navigation.d ${OBJECTDIR}/Robot/Navigation/robot_navigation.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Robot/Navigation/robot_navigation.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Robot/sensors/DHT11/DHT.p1: Robot/sensors/DHT11/DHT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Robot/sensors/DHT11" 
	@${RM} ${OBJECTDIR}/Robot/sensors/DHT11/DHT.p1.d 
	@${RM} ${OBJECTDIR}/Robot/sensors/DHT11/DHT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Robot/sensors/DHT11/DHT.p1 Robot/sensors/DHT11/DHT.c 
	@-${MV} ${OBJECTDIR}/Robot/sensors/DHT11/DHT.d ${OBJECTDIR}/Robot/sensors/DHT11/DHT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Robot/sensors/DHT11/DHT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.p1: Robot/sensors/ultrasonic/ultrasonic.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Robot/sensors/ultrasonic" 
	@${RM} ${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.p1.d 
	@${RM} ${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.p1 Robot/sensors/ultrasonic/ultrasonic.c 
	@-${MV} ${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.d ${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Robot/sensors/ultrasonic/ultrasonic.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1: MCAL/TIMER2/mcal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/TIMER2" 
	@${RM} ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1 MCAL/TIMER2/mcal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.d ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/TIMER2/mcal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/graduation_project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/graduation_project.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/graduation_project.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/graduation_project.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/graduation_project.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/graduation_project.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/graduation_project.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
