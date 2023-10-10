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
FINAL_IMAGE=${DISTDIR}/diploma_project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/diploma_project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ecu_layer/dc_motor/ecu_dc_motor.c ecu_layer/ecu_init/ecu_init.c ecu_layer/key_pad/ecu_keypad.c ecu_layer/lcd/ecu_lcd.c ecu_layer/led/ecu_led.c mcal_layer/ADC/hal_adc.c mcal_layer/CCP/hal_ccp.c mcal_layer/EEPROM/hal_eeprom.c mcal_layer/EUSART/hal_EUSART.c mcal_layer/GPIO/hal_gpio.c mcal_layer/interrupt/mcal_internal_interrupt.c mcal_layer/interrupt/mcal_external_interrupt.c mcal_layer/interrupt/mcal_interrupt_manager.c mcal_layer/Timer0/hal_timer0.c mcal_layer/Timer1/hal_timer1.c mcal_layer/Timer2/hal_timer2.c mcal_layer/Timer3/hal_timer3.c ecu_layer/pb/ecu_pb.c ecu_layer/relay/ecu_relay.c ecu_layer/seven_segment/ecu_7_segment.c app.c mcal_layer/device_conf.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1 ${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.p1 ${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.p1 ${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.p1 ${OBJECTDIR}/ecu_layer/led/ecu_led.p1 ${OBJECTDIR}/mcal_layer/ADC/hal_adc.p1 ${OBJECTDIR}/mcal_layer/CCP/hal_ccp.p1 ${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.p1 ${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.p1 ${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.p1 ${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.p1 ${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.p1 ${OBJECTDIR}/ecu_layer/pb/ecu_pb.p1 ${OBJECTDIR}/ecu_layer/relay/ecu_relay.p1 ${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.p1 ${OBJECTDIR}/app.p1 ${OBJECTDIR}/mcal_layer/device_conf.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1.d ${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.p1.d ${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.p1.d ${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.p1.d ${OBJECTDIR}/ecu_layer/led/ecu_led.p1.d ${OBJECTDIR}/mcal_layer/ADC/hal_adc.p1.d ${OBJECTDIR}/mcal_layer/CCP/hal_ccp.p1.d ${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.p1.d ${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.p1.d ${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.p1.d ${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.p1.d ${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.p1.d ${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.p1.d ${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.p1.d ${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.p1.d ${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.p1.d ${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.p1.d ${OBJECTDIR}/ecu_layer/pb/ecu_pb.p1.d ${OBJECTDIR}/ecu_layer/relay/ecu_relay.p1.d ${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.p1.d ${OBJECTDIR}/app.p1.d ${OBJECTDIR}/mcal_layer/device_conf.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1 ${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.p1 ${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.p1 ${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.p1 ${OBJECTDIR}/ecu_layer/led/ecu_led.p1 ${OBJECTDIR}/mcal_layer/ADC/hal_adc.p1 ${OBJECTDIR}/mcal_layer/CCP/hal_ccp.p1 ${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.p1 ${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.p1 ${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.p1 ${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.p1 ${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.p1 ${OBJECTDIR}/ecu_layer/pb/ecu_pb.p1 ${OBJECTDIR}/ecu_layer/relay/ecu_relay.p1 ${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.p1 ${OBJECTDIR}/app.p1 ${OBJECTDIR}/mcal_layer/device_conf.p1

# Source Files
SOURCEFILES=ecu_layer/dc_motor/ecu_dc_motor.c ecu_layer/ecu_init/ecu_init.c ecu_layer/key_pad/ecu_keypad.c ecu_layer/lcd/ecu_lcd.c ecu_layer/led/ecu_led.c mcal_layer/ADC/hal_adc.c mcal_layer/CCP/hal_ccp.c mcal_layer/EEPROM/hal_eeprom.c mcal_layer/EUSART/hal_EUSART.c mcal_layer/GPIO/hal_gpio.c mcal_layer/interrupt/mcal_internal_interrupt.c mcal_layer/interrupt/mcal_external_interrupt.c mcal_layer/interrupt/mcal_interrupt_manager.c mcal_layer/Timer0/hal_timer0.c mcal_layer/Timer1/hal_timer1.c mcal_layer/Timer2/hal_timer2.c mcal_layer/Timer3/hal_timer3.c ecu_layer/pb/ecu_pb.c ecu_layer/relay/ecu_relay.c ecu_layer/seven_segment/ecu_7_segment.c app.c mcal_layer/device_conf.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/diploma_project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F46K20
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1: ecu_layer/dc_motor/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/dc_motor" 
	@${RM} ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1 ecu_layer/dc_motor/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.d ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.p1: ecu_layer/ecu_init/ecu_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/ecu_init" 
	@${RM} ${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.p1 ecu_layer/ecu_init/ecu_init.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.d ${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.p1: ecu_layer/key_pad/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/key_pad" 
	@${RM} ${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.p1 ecu_layer/key_pad/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.d ${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.p1: ecu_layer/lcd/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/lcd" 
	@${RM} ${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.p1 ecu_layer/lcd/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.d ${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/led/ecu_led.p1: ecu_layer/led/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/led" 
	@${RM} ${OBJECTDIR}/ecu_layer/led/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/led/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/led/ecu_led.p1 ecu_layer/led/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/led/ecu_led.d ${OBJECTDIR}/ecu_layer/led/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/led/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/ADC/hal_adc.p1: mcal_layer/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/ADC" 
	@${RM} ${OBJECTDIR}/mcal_layer/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/ADC/hal_adc.p1 mcal_layer/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/ADC/hal_adc.d ${OBJECTDIR}/mcal_layer/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/CCP/hal_ccp.p1: mcal_layer/CCP/hal_ccp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/CCP" 
	@${RM} ${OBJECTDIR}/mcal_layer/CCP/hal_ccp.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/CCP/hal_ccp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/CCP/hal_ccp.p1 mcal_layer/CCP/hal_ccp.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/CCP/hal_ccp.d ${OBJECTDIR}/mcal_layer/CCP/hal_ccp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/CCP/hal_ccp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.p1: mcal_layer/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/EEPROM" 
	@${RM} ${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.p1 mcal_layer/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.d ${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.p1: mcal_layer/EUSART/hal_EUSART.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/EUSART" 
	@${RM} ${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.p1 mcal_layer/EUSART/hal_EUSART.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.d ${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.p1: mcal_layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/GPIO" 
	@${RM} ${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.p1 mcal_layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.d ${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.p1: mcal_layer/interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/interrupt" 
	@${RM} ${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.p1 mcal_layer/interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.p1: mcal_layer/interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/interrupt" 
	@${RM} ${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.p1 mcal_layer/interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.d ${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.p1: mcal_layer/interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/interrupt" 
	@${RM} ${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.p1 mcal_layer/interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.p1: mcal_layer/Timer0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/Timer0" 
	@${RM} ${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.p1 mcal_layer/Timer0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.d ${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.p1: mcal_layer/Timer1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/Timer1" 
	@${RM} ${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.p1 mcal_layer/Timer1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.d ${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.p1: mcal_layer/Timer2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/Timer2" 
	@${RM} ${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.p1 mcal_layer/Timer2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.d ${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.p1: mcal_layer/Timer3/hal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/Timer3" 
	@${RM} ${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.p1 mcal_layer/Timer3/hal_timer3.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.d ${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/pb/ecu_pb.p1: ecu_layer/pb/ecu_pb.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/pb" 
	@${RM} ${OBJECTDIR}/ecu_layer/pb/ecu_pb.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/pb/ecu_pb.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/pb/ecu_pb.p1 ecu_layer/pb/ecu_pb.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/pb/ecu_pb.d ${OBJECTDIR}/ecu_layer/pb/ecu_pb.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/pb/ecu_pb.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/relay/ecu_relay.p1: ecu_layer/relay/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/relay" 
	@${RM} ${OBJECTDIR}/ecu_layer/relay/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/relay/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/relay/ecu_relay.p1 ecu_layer/relay/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/relay/ecu_relay.d ${OBJECTDIR}/ecu_layer/relay/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/relay/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.p1: ecu_layer/seven_segment/ecu_7_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/seven_segment" 
	@${RM} ${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.p1 ecu_layer/seven_segment/ecu_7_segment.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.d ${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/app.p1: app.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app.p1.d 
	@${RM} ${OBJECTDIR}/app.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/app.p1 app.c 
	@-${MV} ${OBJECTDIR}/app.d ${OBJECTDIR}/app.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/app.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/device_conf.p1: mcal_layer/device_conf.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer" 
	@${RM} ${OBJECTDIR}/mcal_layer/device_conf.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/device_conf.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/device_conf.p1 mcal_layer/device_conf.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/device_conf.d ${OBJECTDIR}/mcal_layer/device_conf.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/device_conf.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1: ecu_layer/dc_motor/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/dc_motor" 
	@${RM} ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1 ecu_layer/dc_motor/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.d ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/dc_motor/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.p1: ecu_layer/ecu_init/ecu_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/ecu_init" 
	@${RM} ${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.p1 ecu_layer/ecu_init/ecu_init.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.d ${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/ecu_init/ecu_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.p1: ecu_layer/key_pad/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/key_pad" 
	@${RM} ${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.p1 ecu_layer/key_pad/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.d ${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/key_pad/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.p1: ecu_layer/lcd/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/lcd" 
	@${RM} ${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.p1 ecu_layer/lcd/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.d ${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/lcd/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/led/ecu_led.p1: ecu_layer/led/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/led" 
	@${RM} ${OBJECTDIR}/ecu_layer/led/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/led/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/led/ecu_led.p1 ecu_layer/led/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/led/ecu_led.d ${OBJECTDIR}/ecu_layer/led/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/led/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/ADC/hal_adc.p1: mcal_layer/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/ADC" 
	@${RM} ${OBJECTDIR}/mcal_layer/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/ADC/hal_adc.p1 mcal_layer/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/ADC/hal_adc.d ${OBJECTDIR}/mcal_layer/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/CCP/hal_ccp.p1: mcal_layer/CCP/hal_ccp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/CCP" 
	@${RM} ${OBJECTDIR}/mcal_layer/CCP/hal_ccp.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/CCP/hal_ccp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/CCP/hal_ccp.p1 mcal_layer/CCP/hal_ccp.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/CCP/hal_ccp.d ${OBJECTDIR}/mcal_layer/CCP/hal_ccp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/CCP/hal_ccp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.p1: mcal_layer/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/EEPROM" 
	@${RM} ${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.p1 mcal_layer/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.d ${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.p1: mcal_layer/EUSART/hal_EUSART.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/EUSART" 
	@${RM} ${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.p1 mcal_layer/EUSART/hal_EUSART.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.d ${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/EUSART/hal_EUSART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.p1: mcal_layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/GPIO" 
	@${RM} ${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.p1 mcal_layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.d ${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.p1: mcal_layer/interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/interrupt" 
	@${RM} ${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.p1 mcal_layer/interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.p1: mcal_layer/interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/interrupt" 
	@${RM} ${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.p1 mcal_layer/interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.d ${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.p1: mcal_layer/interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/interrupt" 
	@${RM} ${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.p1 mcal_layer/interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.p1: mcal_layer/Timer0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/Timer0" 
	@${RM} ${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.p1 mcal_layer/Timer0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.d ${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/Timer0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.p1: mcal_layer/Timer1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/Timer1" 
	@${RM} ${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.p1 mcal_layer/Timer1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.d ${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/Timer1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.p1: mcal_layer/Timer2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/Timer2" 
	@${RM} ${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.p1 mcal_layer/Timer2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.d ${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/Timer2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.p1: mcal_layer/Timer3/hal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer/Timer3" 
	@${RM} ${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.p1 mcal_layer/Timer3/hal_timer3.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.d ${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/Timer3/hal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/pb/ecu_pb.p1: ecu_layer/pb/ecu_pb.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/pb" 
	@${RM} ${OBJECTDIR}/ecu_layer/pb/ecu_pb.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/pb/ecu_pb.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/pb/ecu_pb.p1 ecu_layer/pb/ecu_pb.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/pb/ecu_pb.d ${OBJECTDIR}/ecu_layer/pb/ecu_pb.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/pb/ecu_pb.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/relay/ecu_relay.p1: ecu_layer/relay/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/relay" 
	@${RM} ${OBJECTDIR}/ecu_layer/relay/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/relay/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/relay/ecu_relay.p1 ecu_layer/relay/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/relay/ecu_relay.d ${OBJECTDIR}/ecu_layer/relay/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/relay/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.p1: ecu_layer/seven_segment/ecu_7_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ecu_layer/seven_segment" 
	@${RM} ${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.p1.d 
	@${RM} ${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.p1 ecu_layer/seven_segment/ecu_7_segment.c 
	@-${MV} ${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.d ${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ecu_layer/seven_segment/ecu_7_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/app.p1: app.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app.p1.d 
	@${RM} ${OBJECTDIR}/app.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/app.p1 app.c 
	@-${MV} ${OBJECTDIR}/app.d ${OBJECTDIR}/app.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/app.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/mcal_layer/device_conf.p1: mcal_layer/device_conf.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/mcal_layer" 
	@${RM} ${OBJECTDIR}/mcal_layer/device_conf.p1.d 
	@${RM} ${OBJECTDIR}/mcal_layer/device_conf.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/mcal_layer/device_conf.p1 mcal_layer/device_conf.c 
	@-${MV} ${OBJECTDIR}/mcal_layer/device_conf.d ${OBJECTDIR}/mcal_layer/device_conf.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/mcal_layer/device_conf.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
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
${DISTDIR}/diploma_project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/diploma_project.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/diploma_project.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/diploma_project.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/diploma_project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/diploma_project.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../compiler/pic/include/proc" -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/diploma_project.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
