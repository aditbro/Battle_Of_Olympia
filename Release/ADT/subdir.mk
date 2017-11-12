################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADT/array.c \
../ADT/jam.c \
../ADT/listlinier.c \
../ADT/matriks.c \
../ADT/mesinkar.c \
../ADT/mesinkata.c \
../ADT/pcolor.c \
../ADT/pcolor_driver.c \
../ADT/point.c \
../ADT/queue.c \
../ADT/stackt.c 

OBJS += \
./ADT/array.o \
./ADT/jam.o \
./ADT/listlinier.o \
./ADT/matriks.o \
./ADT/mesinkar.o \
./ADT/mesinkata.o \
./ADT/pcolor.o \
./ADT/pcolor_driver.o \
./ADT/point.o \
./ADT/queue.o \
./ADT/stackt.o 

C_DEPS += \
./ADT/array.d \
./ADT/jam.d \
./ADT/listlinier.d \
./ADT/matriks.d \
./ADT/mesinkar.d \
./ADT/mesinkata.d \
./ADT/pcolor.d \
./ADT/pcolor_driver.d \
./ADT/point.d \
./ADT/queue.d \
./ADT/stackt.d 


# Each subdirectory must supply rules for building sources it contributes
ADT/%.o: ../ADT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


