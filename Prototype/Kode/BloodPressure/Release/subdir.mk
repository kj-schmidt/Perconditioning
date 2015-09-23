################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BloodPressure.cpp 

LINK_OBJ += \
./BloodPressure.cpp.o 

CPP_DEPS += \
./BloodPressure.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
BloodPressure.cpp.o: ../BloodPressure.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/simon/Dropbox/arduino-1.6.0/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=160 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/cores/arduino" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/variants/standard" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/EEPROM" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


