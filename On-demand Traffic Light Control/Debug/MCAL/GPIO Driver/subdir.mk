################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO\ Driver/gpio.c 

OBJS += \
./MCAL/GPIO\ Driver/gpio.o 

C_DEPS += \
./MCAL/GPIO\ Driver/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GPIO\ Driver/gpio.o: ../MCAL/GPIO\ Driver/gpio.c MCAL/GPIO\ Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"MCAL/GPIO Driver/gpio.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


