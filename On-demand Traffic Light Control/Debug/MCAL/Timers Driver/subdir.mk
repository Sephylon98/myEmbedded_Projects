################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Timers\ Driver/timer.c 

OBJS += \
./MCAL/Timers\ Driver/timer.o 

C_DEPS += \
./MCAL/Timers\ Driver/timer.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Timers\ Driver/timer.o: ../MCAL/Timers\ Driver/timer.c MCAL/Timers\ Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"MCAL/Timers Driver/timer.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


