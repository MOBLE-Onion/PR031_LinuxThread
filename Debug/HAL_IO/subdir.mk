################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL_IO/HAL_IO.c 

OBJS += \
./HAL_IO/HAL_IO.o 

C_DEPS += \
./HAL_IO/HAL_IO.d 


# Each subdirectory must supply rules for building sources it contributes
HAL_IO/%.o: ../HAL_IO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler 4 [arm-linux-gnueabihf]'
	arm-linux-gnueabihf-gcc -IC:/intelFPGA/17.1/embedded/ip/altera/hps/altera_hps/hwlib/include -IC:/intelFPGA/17.1/embedded/ip/altera/hps/altera_hps/hwlib/include/soc_cv_av -I"C:\Users\MOSYELIAN\Documents\DS-5 Workspace\Thread_Nano\TCP_Server\include" -O0 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


