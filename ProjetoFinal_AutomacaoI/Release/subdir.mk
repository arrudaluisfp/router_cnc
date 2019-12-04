################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\botoes.cpp \
..\heart_beat.cpp \
..\motor.cpp \
..\serial.cpp \
..\sloeber.ino.cpp \
..\telas.cpp 

LINK_OBJ += \
.\botoes.cpp.o \
.\heart_beat.cpp.o \
.\motor.cpp.o \
.\serial.cpp.o \
.\sloeber.ino.cpp.o \
.\telas.cpp.o 

CPP_DEPS += \
.\botoes.cpp.d \
.\heart_beat.cpp.d \
.\motor.cpp.d \
.\serial.cpp.d \
.\sloeber.ino.cpp.d \
.\telas.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
botoes.cpp.o: ..\botoes.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\mega" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\Stepper\1.1.3\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

heart_beat.cpp.o: ..\heart_beat.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\mega" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\Stepper\1.1.3\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

motor.cpp.o: ..\motor.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\mega" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\Stepper\1.1.3\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

serial.cpp.o: ..\serial.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\mega" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\Stepper\1.1.3\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

sloeber.ino.cpp.o: ..\sloeber.ino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\mega" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\Stepper\1.1.3\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"

	@echo 'Finished building: $<'
	@echo ' '

telas.cpp.o: ..\telas.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\mega" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\Bounce2\2.52.0\src" -I"C:\Users\161855\Downloads\sloeber\arduinoPlugin\libraries\Stepper\1.1.3\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


