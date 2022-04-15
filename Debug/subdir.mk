################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CN0397.c \
../DataRecord.c \
../ad7799.c \
../main.c 

OBJS += \
./CN0397.o \
./DataRecord.o \
./ad7799.o \
./main.o 

C_DEPS += \
./CN0397.d \
./DataRecord.d \
./ad7799.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler 4 [arm-linux-gnueabihf]'
	arm-linux-gnueabihf-gcc -IC:/intelFPGA/17.1/embedded/ip/altera/hps/altera_hps/hwlib/include -IC:/intelFPGA/17.1/embedded/ip/altera/hps/altera_hps/hwlib/include/soc_cv_av -I"C:\Users\MOSYELIAN\Documents\DS-5 Workspace\Thread_Nano\TCP_Server\include" -O0 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.o: ../main.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler 4 [arm-linux-gnueabihf]'
	arm-linux-gnueabihf-gcc -IC:/intelFPGA/17.1/embedded/ip/altera/hps/altera_hps/hwlib/include -IC:/intelFPGA/17.1/embedded/ip/altera/hps/altera_hps/hwlib/include/soc_cv_av -I"C:\Users\MOSYELIAN\Documents\DS-5 Workspace\Thread_Nano\TCP_Server\include" -O0 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


