################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../buzzer.c \
../cutsom_delay.c \
../dc_motor.c \
../external_eeprom.c \
../gpio.c \
../lcd.c \
../slave_device.c \
../timer.c \
../twi.c \
../uart.c 

OBJS += \
./buzzer.o \
./cutsom_delay.o \
./dc_motor.o \
./external_eeprom.o \
./gpio.o \
./lcd.o \
./slave_device.o \
./timer.o \
./twi.o \
./uart.o 

C_DEPS += \
./buzzer.d \
./cutsom_delay.d \
./dc_motor.d \
./external_eeprom.d \
./gpio.d \
./lcd.d \
./slave_device.d \
./timer.d \
./twi.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


