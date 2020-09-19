################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/basic.c \
../src/pthreads.c \
../src/structure.c \
../src/union.c 

OBJS += \
./src/basic.o \
./src/pthreads.o \
./src/structure.o \
./src/union.o 

C_DEPS += \
./src/basic.d \
./src/pthreads.d \
./src/structure.d \
./src/union.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


