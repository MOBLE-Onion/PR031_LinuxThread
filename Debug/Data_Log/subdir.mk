################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Data_Log/data_log.c 

OBJS += \
./Data_Log/data_log.o 

C_DEPS += \
./Data_Log/data_log.d 


# Each subdirectory must supply rules for building sources it contributes
Data_Log/%.o: ../Data_Log/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler 4 [arm-linux-gnueabihf]'
	arm-linux-gnueabihf-gcc -IC:/intelFPGA/17.1/embedded/ip/altera/hps/altera_hps/hwlib/include -IC:/intelFPGA/17.1/embedded/ip/altera/hps/altera_hps/hwlib/include/soc_cv_av -I"C:\Users\MOSYELIAN\Documents\DS-5 Workspace\Thread_Nano\TCP_Server\include" -O0 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


