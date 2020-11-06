################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO/Src/dio.c 

OBJS += \
./MCAL/DIO/Src/dio.o 

C_DEPS += \
./MCAL/DIO/Src/dio.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/DIO/Src/%.o: ../MCAL/DIO/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Eng_Fawzi\Desktop\my_git\Security_System\LIB" -I"C:\Users\Eng_Fawzi\Desktop\my_git\Security_System\MCAL\DIO\Inc" -I"C:\Users\Eng_Fawzi\Desktop\my_git\Security_System\HAL\LCD2x16\Inc" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


