################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/EEPROM/EEPROM.cpp 

LINK_OBJ += \
./Libraries/EEPROM/EEPROM.cpp.o 

CPP_DEPS += \
./Libraries/EEPROM/EEPROM.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/EEPROM/EEPROM.cpp.o: /home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/EEPROM/EEPROM.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/simon/Dropbox/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR    -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/cores/arduino" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/variants/standard" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

