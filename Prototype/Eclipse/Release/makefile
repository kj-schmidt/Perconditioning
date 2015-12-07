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
-include Logic/subdir.mk
-include Libraries/SPI/subdir.mk
-include Libraries/SD/src/utility/subdir.mk
-include Libraries/SD/src/subdir.mk
-include Libraries/EEPROM/subdir.mk
-include Libraries/DS1302/subdir.mk
-include Libraries/Adafruit_ILI9340/subdir.mk
-include Libraries/Adafruit_GFX/subdir.mk
-include GUI/subdir.mk
-include Data/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
arduino.ar \

ELF += \
Konditioneringsapparat.elf \

EEP += \
Konditioneringsapparat.eep \

FLASH_IMAGE += \
Konditioneringsapparat.hex \


# All Target
all: Konditioneringsapparat

# Tool invocations
Konditioneringsapparat: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/Applications/Arduino1.5.5.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-size" -A "/Users/kjschmidt/GitHub/Perconditioning/Prototype/Eclipse/Release/Konditioneringsapparat.elf"
	@echo 'Finished building target: $@'
	@echo ' '

arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/Applications/Arduino1.5.5.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-ar" rcs "/Users/kjschmidt/GitHub/Perconditioning/Prototype/Eclipse/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

Konditioneringsapparat.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/Applications/Arduino1.5.5.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-gcc"  -Os -Wl,--gc-sections,--relax -mmcu=atmega2560 -o "/Users/kjschmidt/GitHub/Perconditioning/Prototype/Eclipse/Release/Konditioneringsapparat.elf"   $(LINK_OBJ) $(AR)  "/Users/kjschmidt/GitHub/Perconditioning/Prototype/Eclipse/Release/arduino.ar" "-L/Users/kjschmidt/GitHub/Perconditioning/Prototype/Eclipse/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

Konditioneringsapparat.eep: $(ELF)
	@echo 'Create eeprom image'
	"/Applications/Arduino1.5.5.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 "/Users/kjschmidt/GitHub/Perconditioning/Prototype/Eclipse/Release/Konditioneringsapparat.elf" "/Users/kjschmidt/GitHub/Perconditioning/Prototype/Eclipse/Release/Konditioneringsapparat.eep"
	@echo 'Finished building: $@'
	@echo ' '

Konditioneringsapparat.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/Applications/Arduino1.5.5.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom "/Users/kjschmidt/GitHub/Perconditioning/Prototype/Eclipse/Release/Konditioneringsapparat.elf" "/Users/kjschmidt/GitHub/Perconditioning/Prototype/Eclipse/Release/Konditioneringsapparat.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_DEPS)$(AR)$(FLASH_IMAGE)$(EEP)$(CXX_DEPS)$(S_UPPER_DEPS)$(ELF)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(AR_OBJ)$(CPP_DEPS)$(PDE_DEPS)$(LINK_OBJ)$(C_UPPER_DEPS)$(SIZEDUMMY) Konditioneringsapparat
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
