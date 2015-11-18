################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Data/ExternalMemory.cpp \
../Data/InternalMemory.cpp \
../Data/PressureControl.cpp \
../Data/PressureSampling.cpp 

LINK_OBJ += \
./Data/ExternalMemory.cpp.o \
./Data/InternalMemory.cpp.o \
./Data/PressureControl.cpp.o \
./Data/PressureSampling.cpp.o 

CPP_DEPS += \
./Data/ExternalMemory.cpp.d \
./Data/InternalMemory.cpp.d \
./Data/PressureControl.cpp.d \
./Data/PressureSampling.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
Data/ExternalMemory.cpp.o: ../Data/ExternalMemory.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/simon/Dropbox/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR    -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/cores/arduino" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/variants/mega" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/Adafruit_GFX" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/Adafruit_ILI9340" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/SD" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/SD/src" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/SPI" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/EEPROM" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/DS1302" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Data/InternalMemory.cpp.o: ../Data/InternalMemory.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/simon/Dropbox/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR    -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/cores/arduino" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/variants/mega" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/Adafruit_GFX" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/Adafruit_ILI9340" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/SD" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/SD/src" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/SPI" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/EEPROM" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/DS1302" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Data/PressureControl.cpp.o: ../Data/PressureControl.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/simon/Dropbox/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR    -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/cores/arduino" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/variants/mega" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/Adafruit_GFX" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/Adafruit_ILI9340" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/SD" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/SD/src" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/SPI" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/EEPROM" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/DS1302" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Data/PressureSampling.cpp.o: ../Data/PressureSampling.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/simon/Dropbox/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR    -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/cores/arduino" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/variants/mega" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/Adafruit_GFX" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/Adafruit_ILI9340" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/SD" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/SD/src" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/SPI" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/EEPROM" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/DS1302" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


