################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../.ino.cpp \
../Utilities.cpp 

PDE_SRCS += \
../Konditioneringsapparat.pde 

PDE_DEPS += \
./Konditioneringsapparat.pde.d 

LINK_OBJ += \
./.ino.cpp.o \
./Utilities.cpp.o 

CPP_DEPS += \
./.ino.cpp.d \
./Utilities.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
.ino.cpp.o: ../.ino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/simon/Dropbox/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR    -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/cores/arduino" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/variants/mega" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/Adafruit_GFX" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/Adafruit_ILI9340" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/SD" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/SD/src" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/SPI" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/EEPROM" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/DS1302" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Konditioneringsapparat.o: ../Konditioneringsapparat.pde
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/simon/Dropbox/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR    -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/cores/arduino" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/variants/mega" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/Adafruit_GFX" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/Adafruit_ILI9340" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/SD" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/SD/src" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/SPI" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/EEPROM" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/DS1302" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Utilities.cpp.o: ../Utilities.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/simon/Dropbox/arduino-1.5.5/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR    -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/cores/arduino" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/variants/mega" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/Adafruit_GFX" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/Adafruit_ILI9340" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/SD" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/SD/src" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/SPI" -I"/home/simon/Dropbox/arduino-1.5.5/hardware/arduino/avr/libraries/EEPROM" -I"/home/simon/Dropbox/arduino-1.5.5/libraries/DS1302" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


