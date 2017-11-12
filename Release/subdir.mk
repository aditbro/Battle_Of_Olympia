################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Building.c \
../Offbattle.c \
../main.c \
../map.c \
../mapDriver.c \
../move.c \
../unit.c \
../unit_battle.c 

OBJS += \
./Building.o \
./Offbattle.o \
./main.o \
./map.o \
./mapDriver.o \
./move.o \
./unit.o \
./unit_battle.o 

C_DEPS += \
./Building.d \
./Offbattle.d \
./main.d \
./map.d \
./mapDriver.d \
./move.d \
./unit.d \
./unit_battle.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


