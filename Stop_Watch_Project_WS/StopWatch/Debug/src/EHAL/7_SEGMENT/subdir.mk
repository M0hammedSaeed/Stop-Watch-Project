################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/EHAL/7_SEGMENT/seven_segment.c 

OBJS += \
./src/EHAL/7_SEGMENT/seven_segment.o 

C_DEPS += \
./src/EHAL/7_SEGMENT/seven_segment.d 


# Each subdirectory must supply rules for building sources it contributes
src/EHAL/7_SEGMENT/%.o: ../src/EHAL/7_SEGMENT/%.c src/EHAL/7_SEGMENT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


