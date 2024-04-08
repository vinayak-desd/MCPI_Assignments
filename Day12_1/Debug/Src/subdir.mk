################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/itm.c \
../Src/main.c \
../Src/myadc.c \
../Src/myi2c.c \
../Src/myi2c_lcd.c \
../Src/myswitch.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f4xx.c 

OBJS += \
./Src/itm.o \
./Src/main.o \
./Src/myadc.o \
./Src/myi2c.o \
./Src/myi2c_lcd.o \
./Src/myswitch.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f4xx.o 

C_DEPS += \
./Src/itm.d \
./Src/main.d \
./Src/myadc.d \
./Src/myi2c.d \
./Src/myi2c_lcd.d \
./Src/myswitch.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/itm.cyclo ./Src/itm.d ./Src/itm.o ./Src/itm.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/myadc.cyclo ./Src/myadc.d ./Src/myadc.o ./Src/myadc.su ./Src/myi2c.cyclo ./Src/myi2c.d ./Src/myi2c.o ./Src/myi2c.su ./Src/myi2c_lcd.cyclo ./Src/myi2c_lcd.d ./Src/myi2c_lcd.o ./Src/myi2c_lcd.su ./Src/myswitch.cyclo ./Src/myswitch.d ./Src/myswitch.o ./Src/myswitch.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/system_stm32f4xx.cyclo ./Src/system_stm32f4xx.d ./Src/system_stm32f4xx.o ./Src/system_stm32f4xx.su

.PHONY: clean-Src

