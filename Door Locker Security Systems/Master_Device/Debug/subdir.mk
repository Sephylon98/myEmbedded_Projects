################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cutsom_delay.c \
../gpio.c \
../keypad.c \
../lcd.c \
../master_device.c \
../timer.c \
../uart.c 

OBJS += \
./cutsom_delay.o \
./gpio.o \
./keypad.o \
./lcd.o \
./master_device.o \
./timer.o \
./uart.o 

C_DEPS += \
./cutsom_delay.d \
./gpio.d \
./keypad.d \
./lcd.d \
./master_device.d \
./timer.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


