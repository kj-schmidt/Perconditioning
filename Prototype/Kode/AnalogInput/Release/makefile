################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/avr-libc/subdir.mk
-include arduino/core/subdir.mk
-include Libraries/EEPROM/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/home/simon/Dropbox/eclipseArduino/AnalogInput/Release/arduino.ar \

ELF += \
AnalogInput.elf \

EEP += \
AnalogInput.eep \

FLASH_IMAGE += \
AnalogInput.hex \


# All Target
all: AnalogInput

# Tool invocations
AnalogInput: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/home/simon/Dropbox/arduino-1.5.5/hardware/tools/avr/bin/avr-size" -A "/home/simon/Dropbox/eclipseArduino/AnalogInput/Release/AnalogInput.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/home/simon/Dropbox/eclipseArduino/AnalogInput/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/home/simon/Dropbox/arduino-1.5.5/hardware/tools/avr/bin/avr-ar" rcs "/home/simon/Dropbox/eclipseArduino/AnalogInput/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

AnalogInput.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/home/simon/Dropbox/arduino-1.5.5/hardware/tools/avr/bin/avr-gcc" -Os -Wl,--gc-sections -mmcu=atmega328p -o "/home/simon/Dropbox/eclipseArduino/AnalogInput/Release/AnalogInput.elf"   $(LINK_OBJ) $(AR)  "/home/simon/Dropbox/eclipseArduino/AnalogInput/Release/arduino.ar" "-L/home/simon/Dropbox/eclipseArduino/AnalogInput/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

AnalogInput.eep: $(ELF)
	@echo 'Create eeprom image'
	"/home/simon/Dropbox/arduino-1.5.5/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 "/home/simon/Dropbox/eclipseArduino/AnalogInput/Release/AnalogInput.elf" "/home/simon/Dropbox/eclipseArduino/AnalogInput/Release/AnalogInput.eep"
	@echo 'Finished building: $@'
	@echo ' '

AnalogInput.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/home/simon/Dropbox/arduino-1.5.5/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom "/home/simon/Dropbox/eclipseArduino/AnalogInput/Release/AnalogInput.elf" "/home/simon/Dropbox/eclipseArduino/AnalogInput/Release/AnalogInput.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(EEP)$(FLASH_IMAGE)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS) AnalogInput
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
