################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DWM1001_host/dwm.c 

OBJS += \
./DWM1001_host/dwm.o 

C_DEPS += \
./DWM1001_host/dwm.d 


# Each subdirectory must supply rules for building sources it contributes
DWM1001_host/%.o: ../DWM1001_host/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler 4 [arm-linux-gnueabihf]'
	arm-linux-gnueabihf-gcc -IC:/intelFPGA/17.1/embedded/ip/altera/hps/altera_hps/hwlib/include -IC:/intelFPGA/17.1/embedded/ip/altera/hps/altera_hps/hwlib/include/soc_cv_av -I"C:\Users\MOSYELIAN\Documents\DS-5 Workspace\Thread_Nano\TCP_Server\include" -O0 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


