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
/home/simon/Dropbox/Eclipse/BloodPressure/Release/arduino.ar \

ELF += \
BloodPressure.elf \

EEP += \
BloodPressure.eep \

FLASH_IMAGE += \
BloodPressure.hex \


# All Target
all: BloodPressure

# Tool invocations
BloodPressure: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/home/simon/Dropbox/arduino-1.6.0/hardware/tools/avr/bin/avr-size" -A "/home/simon/Dropbox/Eclipse/BloodPressure/Release/BloodPressure.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/home/simon/Dropbox/Eclipse/BloodPressure/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/home/simon/Dropbox/arduino-1.6.0/hardware/tools/avr/bin/avr-ar" rcs  "/home/simon/Dropbox/Eclipse/BloodPressure/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

BloodPressure.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/home/simon/Dropbox/arduino-1.6.0/hardware/tools/avr/bin/avr-gcc" -w -Os -Wl,--gc-sections -mmcu=atmega328p  -o "/home/simon/Dropbox/Eclipse/BloodPressure/Release/BloodPressure.elf"   $(LINK_OBJ) $(AR)  "/home/simon/Dropbox/Eclipse/BloodPressure/Release/arduino.ar" "-L/home/simon/Dropbox/Eclipse/BloodPressure/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

BloodPressure.eep: $(ELF)
	@echo 'Create eeprom image'
	"/home/simon/Dropbox/arduino-1.6.0/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "/home/simon/Dropbox/Eclipse/BloodPressure/Release/BloodPressure.elf" "/home/simon/Dropbox/Eclipse/BloodPressure/Release/BloodPressure.eep"
	@echo 'Finished building: $@'
	@echo ' '

BloodPressure.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/home/simon/Dropbox/arduino-1.6.0/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom  "/home/simon/Dropbox/Eclipse/BloodPressure/Release/BloodPressure.elf" "/home/simon/Dropbox/Eclipse/BloodPressure/Release/BloodPressure.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(C_DEPS)$(AR)$(EEP)$(FLASH_IMAGE)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(SIZEDUMMY)$(ELF)$(CPP_DEPS) BloodPressure
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
