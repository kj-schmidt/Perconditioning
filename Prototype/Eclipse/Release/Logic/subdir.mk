################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Logic/MemoryParser.cpp \
../Logic/Timer.cpp 

CPP_DEPS += \
./Logic/MemoryParser.cpp.d \
./Logic/Timer.cpp.d 

LINK_OBJ += \
./Logic/MemoryParser.cpp.o \
./Logic/Timer.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
Logic/MemoryParser.cpp.o: ../Logic/MemoryParser.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Arduino1.5.5.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR    -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/hardware/arduino/avr/cores/arduino" -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/hardware/arduino/avr/variants/mega" -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/libraries/Adafruit_GFX" -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/libraries/Adafruit_ILI9340" -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/libraries/SD" -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/libraries/SD/src" -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/hardware/arduino/avr/libraries/SPI" -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/hardware/arduino/avr/libraries/EEPROM" -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/libraries/DS1302" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Logic/Timer.cpp.o: ../Logic/Timer.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Arduino1.5.5.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -MMD -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=155 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR    -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/hardware/arduino/avr/cores/arduino" -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/hardware/arduino/avr/variants/mega" -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/libraries/Adafruit_GFX" -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/libraries/Adafruit_ILI9340" -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/libraries/SD" -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/libraries/SD/src" -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/hardware/arduino/avr/libraries/SPI" -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/hardware/arduino/avr/libraries/EEPROM" -I"/Applications/Arduino1.5.5.app/Contents/Resources/Java/libraries/DS1302" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


