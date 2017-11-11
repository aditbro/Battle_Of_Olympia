################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Offbattle.c \
../map.c \
../mapDriver.c \
../move.c \
../unit.c 

OBJS += \
./Offbattle.o \
./map.o \
./mapDriver.o \
./move.o \
./unit.o 

C_DEPS += \
./Offbattle.d \
./map.d \
./mapDriver.d \
./move.d \
./unit.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


