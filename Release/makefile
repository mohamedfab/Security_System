################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/Src/subdir.mk
-include HAL/LCD2x16/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
libSecurity_system.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: libSecurity_system.a secondary-outputs

# Tool invocations
libSecurity_system.a: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR Archiver'
	avr-ar -r  "libSecurity_system.a" $(OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

libSecurity_system.lss: libSecurity_system.a
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S libSecurity_system.a  >"libSecurity_system.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: libSecurity_system.a
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 libSecurity_system.a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(ARCHIVES)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) libSecurity_system.a
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
