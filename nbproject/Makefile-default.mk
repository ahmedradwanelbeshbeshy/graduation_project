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
SOURCEFILES_QUOTED_IF_SPACED=ECU/Bluetooth/Bluetooth.c ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.c ECU/ecu_layer_init.c MCAL/EUSART/mcal_EUSART.c MCAL/GPIO/hal_gpio.c MCAL/I2C/mcal_i2c.c MCAL/Interrupts/mcal_interrupt_manager.c MCAL/Interrupts/mcal_internal_interrupt.c MCAL/Interrupts/mcal_external_interrupt.c MCAL/device_config.c application.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1 ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1 ${OBJECTDIR}/ECU/ecu_layer_init.p1 ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1 ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1 ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL/device_config.p1 ${OBJECTDIR}/application.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1.d ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1.d ${OBJECTDIR}/ECU/ecu_layer_init.p1.d ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1.d ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1.d ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1.d ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1.d ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1.d ${OBJECTDIR}/MCAL/device_config.p1.d ${OBJECTDIR}/application.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1 ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1 ${OBJECTDIR}/ECU/ecu_layer_init.p1 ${OBJECTDIR}/MCAL/EUSART/mcal_EUSART.p1 ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL/I2C/mcal_i2c.p1 ${OBJECTDIR}/MCAL/Interrupts/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL/Interrupts/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL/Interrupts/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL/device_config.p1 ${OBJECTDIR}/application.p1

# Source Files
SOURCEFILES=ECU/Bluetooth/Bluetooth.c ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.c ECU/ecu_layer_init.c MCAL/EUSART/mcal_EUSART.c MCAL/GPIO/hal_gpio.c MCAL/I2C/mcal_i2c.c MCAL/Interrupts/mcal_interrupt_manager.c MCAL/Interrupts/mcal_internal_interrupt.c MCAL/Interrupts/mcal_external_interrupt.c MCAL/device_config.c application.c



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

MP_PROCESSOR_OPTION=18F4620
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
	
${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1: ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C" 
	@${RM} ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1.d 
	@${RM} ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1 ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.c 
	@-${MV} ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.d ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/ecu_layer_init.p1: ECU/ecu_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU" 
	@${RM} ${OBJECTDIR}/ECU/ecu_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU/ecu_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/ecu_layer_init.p1 ECU/ecu_layer_init.c 
	@-${MV} ${OBJECTDIR}/ECU/ecu_layer_init.d ${OBJECTDIR}/ECU/ecu_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/ecu_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
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
	
${OBJECTDIR}/MCAL/device_config.p1: MCAL/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/device_config.p1 MCAL/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL/device_config.d ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1: ECU/Bluetooth/Bluetooth.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/Bluetooth" 
	@${RM} ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1.d 
	@${RM} ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1 ECU/Bluetooth/Bluetooth.c 
	@-${MV} ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.d ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/Bluetooth/Bluetooth.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1: ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C" 
	@${RM} ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1.d 
	@${RM} ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1 ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.c 
	@-${MV} ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.d ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/SERVO_MOTOR_CONTROL_BY_I2C/ecu_servo_motor_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/ecu_layer_init.p1: ECU/ecu_layer_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU" 
	@${RM} ${OBJECTDIR}/ECU/ecu_layer_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU/ecu_layer_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/ecu_layer_init.p1 ECU/ecu_layer_init.c 
	@-${MV} ${OBJECTDIR}/ECU/ecu_layer_init.d ${OBJECTDIR}/ECU/ecu_layer_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/ecu_layer_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
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
	
${OBJECTDIR}/MCAL/device_config.p1: MCAL/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/device_config.p1 MCAL/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL/device_config.d ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
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
