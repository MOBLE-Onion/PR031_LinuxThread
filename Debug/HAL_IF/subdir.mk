################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL_IF/hal.c \
../HAL_IF/hal_delay.c \
../HAL_IF/hal_log.c \
../HAL_IF/hal_spim.c \
../HAL_IF/hal_uart.c \
../HAL_IF/uart.c 

OBJS += \
./HAL_IF/hal.o \
./HAL_IF/hal_delay.o \
./HAL_IF/hal_log.o \
./HAL_IF/hal_spim.o \
./HAL_IF/hal_uart.o \
./HAL_IF/uart.o 

C_DEPS += \
./HAL_IF/hal.d \
./HAL_IF/hal_delay.d \
./HAL_IF/hal_log.d \
./HAL_IF/hal_spim.d \
./HAL_IF/hal_uart.d \
./HAL_IF/uart.d 


# Each subdirectory must supply rules for building sources it contributes
HAL_IF/%.o: ../HAL_IF/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler 4 [arm-linux-gnueabihf]'
	arm-linux-gnueabihf-gcc -IC:/intelFPGA/17.1/embedded/ip/altera/hps/altera_hps/hwlib/include -IC:/intelFPGA/17.1/embedded/ip/altera/hps/altera_hps/hwlib/include/soc_cv_av -I"C:\Users\MOSYELIAN\Documents\DS-5 Workspace\Thread_Nano\TCP_Server\include" -O0 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


