################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MCAL/EX_INTERRUPT/ex_interrupt.c 

OBJS += \
./src/MCAL/EX_INTERRUPT/ex_interrupt.o 

C_DEPS += \
./src/MCAL/EX_INTERRUPT/ex_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
src/MCAL/EX_INTERRUPT/%.o: ../src/MCAL/EX_INTERRUPT/%.c src/MCAL/EX_INTERRUPT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


