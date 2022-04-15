################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := clean

# All of the sources participating in the build are defined here
-include sources.mk
-include TCP_Server/subdir.mk
-include HAL_IO/subdir.mk
-include HAL_IF/subdir.mk
-include Data_Log/subdir.mk
-include DWM1001_host/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Thread_Nano

# Tool invocations
Thread_Nano: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker 4 [arm-linux-gnueabihf]'
	arm-linux-gnueabihf-gcc  -o "Thread_Nano" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES) $(OBJS) $(C_DEPS) Thread_Nano 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
