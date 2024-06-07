################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Project_Folders/ST/ST.c/stm32wlxx_it.c \
../Project_Folders/ST/ST.c/syscalls.c \
../Project_Folders/ST/ST.c/sysmem.c \
../Project_Folders/ST/ST.c/system_stm32wlxx.c 

OBJS += \
./Project_Folders/ST/ST.c/stm32wlxx_it.o \
./Project_Folders/ST/ST.c/syscalls.o \
./Project_Folders/ST/ST.c/sysmem.o \
./Project_Folders/ST/ST.c/system_stm32wlxx.o 

C_DEPS += \
./Project_Folders/ST/ST.c/stm32wlxx_it.d \
./Project_Folders/ST/ST.c/syscalls.d \
./Project_Folders/ST/ST.c/sysmem.d \
./Project_Folders/ST/ST.c/system_stm32wlxx.d 


# Each subdirectory must supply rules for building sources it contributes
Project_Folders/ST/ST.c/%.o Project_Folders/ST/ST.c/%.su Project_Folders/ST/ST.c/%.cyclo: ../Project_Folders/ST/ST.c/%.c Project_Folders/ST/ST.c/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32WLE5xx=1 -DCORE_CM4=1 -DUSE_HAL_DRIVER=1 -DUSE_FULL_LL_DRIVER=1 -DHAL_MODULE_ENABLED=1 -c -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Driver/CMSIS/Include" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Driver/CMSIS/Device/ST/STM32WLxx/Include" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Driver/STM32WLxx_HAL_Driver/Inc/Legacy" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Driver/STM32WLxx_HAL_Driver/Inc" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/ST/ST.h" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/clock_conf" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/Inc" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/peripheral/1_Peripheral_conf" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/peripheral/GPIO" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/peripheral/I2C" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/peripheral/SPI" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/peripheral/USART" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/Example" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/main" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/I2c_Sensors" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Project_Folders-2f-ST-2f-ST-2e-c

clean-Project_Folders-2f-ST-2f-ST-2e-c:
	-$(RM) ./Project_Folders/ST/ST.c/stm32wlxx_it.cyclo ./Project_Folders/ST/ST.c/stm32wlxx_it.d ./Project_Folders/ST/ST.c/stm32wlxx_it.o ./Project_Folders/ST/ST.c/stm32wlxx_it.su ./Project_Folders/ST/ST.c/syscalls.cyclo ./Project_Folders/ST/ST.c/syscalls.d ./Project_Folders/ST/ST.c/syscalls.o ./Project_Folders/ST/ST.c/syscalls.su ./Project_Folders/ST/ST.c/sysmem.cyclo ./Project_Folders/ST/ST.c/sysmem.d ./Project_Folders/ST/ST.c/sysmem.o ./Project_Folders/ST/ST.c/sysmem.su ./Project_Folders/ST/ST.c/system_stm32wlxx.cyclo ./Project_Folders/ST/ST.c/system_stm32wlxx.d ./Project_Folders/ST/ST.c/system_stm32wlxx.o ./Project_Folders/ST/ST.c/system_stm32wlxx.su

.PHONY: clean-Project_Folders-2f-ST-2f-ST-2e-c

