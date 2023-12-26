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
FINAL_IMAGE=${DISTDIR}/EE2361_Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/EE2361_Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=EE2361_main.c EE2361_buffer_lib.c EE2361_zero_crossing_lib.c EE2361_input_lib.c EE2361_output_lib.c EE2361_lcd_lib.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/EE2361_main.o ${OBJECTDIR}/EE2361_buffer_lib.o ${OBJECTDIR}/EE2361_zero_crossing_lib.o ${OBJECTDIR}/EE2361_input_lib.o ${OBJECTDIR}/EE2361_output_lib.o ${OBJECTDIR}/EE2361_lcd_lib.o
POSSIBLE_DEPFILES=${OBJECTDIR}/EE2361_main.o.d ${OBJECTDIR}/EE2361_buffer_lib.o.d ${OBJECTDIR}/EE2361_zero_crossing_lib.o.d ${OBJECTDIR}/EE2361_input_lib.o.d ${OBJECTDIR}/EE2361_output_lib.o.d ${OBJECTDIR}/EE2361_lcd_lib.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/EE2361_main.o ${OBJECTDIR}/EE2361_buffer_lib.o ${OBJECTDIR}/EE2361_zero_crossing_lib.o ${OBJECTDIR}/EE2361_input_lib.o ${OBJECTDIR}/EE2361_output_lib.o ${OBJECTDIR}/EE2361_lcd_lib.o

# Source Files
SOURCEFILES=EE2361_main.c EE2361_buffer_lib.c EE2361_zero_crossing_lib.c EE2361_input_lib.c EE2361_output_lib.c EE2361_lcd_lib.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/EE2361_Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ64GA002
MP_LINKER_FILE_OPTION=,--script=p24FJ64GA002.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/EE2361_main.o: EE2361_main.c  .generated_files/flags/default/e0b455f2c08cd0a2a0077b248f1a99bfbd440fcd .generated_files/flags/default/b43b81a7dc69b2af1a20a238e492a0564e575dd1
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EE2361_main.o.d 
	@${RM} ${OBJECTDIR}/EE2361_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EE2361_main.c  -o ${OBJECTDIR}/EE2361_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/EE2361_main.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/EE2361_buffer_lib.o: EE2361_buffer_lib.c  .generated_files/flags/default/522a22a673242bbcd13441c9586dd3629b364737 .generated_files/flags/default/b43b81a7dc69b2af1a20a238e492a0564e575dd1
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EE2361_buffer_lib.o.d 
	@${RM} ${OBJECTDIR}/EE2361_buffer_lib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EE2361_buffer_lib.c  -o ${OBJECTDIR}/EE2361_buffer_lib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/EE2361_buffer_lib.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/EE2361_zero_crossing_lib.o: EE2361_zero_crossing_lib.c  .generated_files/flags/default/a8117ae29863692171f9fc532c364d9f7f0fabf6 .generated_files/flags/default/b43b81a7dc69b2af1a20a238e492a0564e575dd1
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EE2361_zero_crossing_lib.o.d 
	@${RM} ${OBJECTDIR}/EE2361_zero_crossing_lib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EE2361_zero_crossing_lib.c  -o ${OBJECTDIR}/EE2361_zero_crossing_lib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/EE2361_zero_crossing_lib.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/EE2361_input_lib.o: EE2361_input_lib.c  .generated_files/flags/default/fe31325e1b4191d0800e6e239dd90731f9a3c4ba .generated_files/flags/default/b43b81a7dc69b2af1a20a238e492a0564e575dd1
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EE2361_input_lib.o.d 
	@${RM} ${OBJECTDIR}/EE2361_input_lib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EE2361_input_lib.c  -o ${OBJECTDIR}/EE2361_input_lib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/EE2361_input_lib.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/EE2361_output_lib.o: EE2361_output_lib.c  .generated_files/flags/default/9694c1f8d74a66285c2c641b268e411a8625bbf8 .generated_files/flags/default/b43b81a7dc69b2af1a20a238e492a0564e575dd1
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EE2361_output_lib.o.d 
	@${RM} ${OBJECTDIR}/EE2361_output_lib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EE2361_output_lib.c  -o ${OBJECTDIR}/EE2361_output_lib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/EE2361_output_lib.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/EE2361_lcd_lib.o: EE2361_lcd_lib.c  .generated_files/flags/default/f8bb7d3be6f7c3edc4fd86e85e33e4d24d18c21d .generated_files/flags/default/b43b81a7dc69b2af1a20a238e492a0564e575dd1
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EE2361_lcd_lib.o.d 
	@${RM} ${OBJECTDIR}/EE2361_lcd_lib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EE2361_lcd_lib.c  -o ${OBJECTDIR}/EE2361_lcd_lib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/EE2361_lcd_lib.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/EE2361_main.o: EE2361_main.c  .generated_files/flags/default/b1c6fb9142633dfcdbda7fcc32da0481ec0bd715 .generated_files/flags/default/b43b81a7dc69b2af1a20a238e492a0564e575dd1
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EE2361_main.o.d 
	@${RM} ${OBJECTDIR}/EE2361_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EE2361_main.c  -o ${OBJECTDIR}/EE2361_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/EE2361_main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/EE2361_buffer_lib.o: EE2361_buffer_lib.c  .generated_files/flags/default/bae8fedc64dc5617839d2c343224a9f5686214e4 .generated_files/flags/default/b43b81a7dc69b2af1a20a238e492a0564e575dd1
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EE2361_buffer_lib.o.d 
	@${RM} ${OBJECTDIR}/EE2361_buffer_lib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EE2361_buffer_lib.c  -o ${OBJECTDIR}/EE2361_buffer_lib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/EE2361_buffer_lib.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/EE2361_zero_crossing_lib.o: EE2361_zero_crossing_lib.c  .generated_files/flags/default/a799b41b28850212f964217b0a63a68075c09ea .generated_files/flags/default/b43b81a7dc69b2af1a20a238e492a0564e575dd1
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EE2361_zero_crossing_lib.o.d 
	@${RM} ${OBJECTDIR}/EE2361_zero_crossing_lib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EE2361_zero_crossing_lib.c  -o ${OBJECTDIR}/EE2361_zero_crossing_lib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/EE2361_zero_crossing_lib.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/EE2361_input_lib.o: EE2361_input_lib.c  .generated_files/flags/default/90a9fd03ee1621fdbc7712905b3f833f45a56993 .generated_files/flags/default/b43b81a7dc69b2af1a20a238e492a0564e575dd1
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EE2361_input_lib.o.d 
	@${RM} ${OBJECTDIR}/EE2361_input_lib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EE2361_input_lib.c  -o ${OBJECTDIR}/EE2361_input_lib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/EE2361_input_lib.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/EE2361_output_lib.o: EE2361_output_lib.c  .generated_files/flags/default/6cdf78c68d724c6561cf853c8e725246b1f3ff00 .generated_files/flags/default/b43b81a7dc69b2af1a20a238e492a0564e575dd1
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EE2361_output_lib.o.d 
	@${RM} ${OBJECTDIR}/EE2361_output_lib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EE2361_output_lib.c  -o ${OBJECTDIR}/EE2361_output_lib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/EE2361_output_lib.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/EE2361_lcd_lib.o: EE2361_lcd_lib.c  .generated_files/flags/default/fe982f11eb689bfdc6098983407c54f3e47b501b .generated_files/flags/default/b43b81a7dc69b2af1a20a238e492a0564e575dd1
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EE2361_lcd_lib.o.d 
	@${RM} ${OBJECTDIR}/EE2361_lcd_lib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EE2361_lcd_lib.c  -o ${OBJECTDIR}/EE2361_lcd_lib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/EE2361_lcd_lib.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/EE2361_Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/EE2361_Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/EE2361_Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/EE2361_Final_Project.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/EE2361_Final_Project.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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
