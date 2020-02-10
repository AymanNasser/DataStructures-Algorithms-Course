################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Linked-Based-Stack/Lin_stack.cpp 

OBJS += \
./Linked-Based-Stack/Lin_stack.o 

CPP_DEPS += \
./Linked-Based-Stack/Lin_stack.d 


# Each subdirectory must supply rules for building sources it contributes
Linked-Based-Stack/%.o: ../Linked-Based-Stack/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


