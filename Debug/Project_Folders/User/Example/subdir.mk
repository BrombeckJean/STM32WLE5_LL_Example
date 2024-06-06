################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Project_Folders/User/Example/code_periph_use_exemple.c 

OBJS += \
./Project_Folders/User/Example/code_periph_use_exemple.o 

C_DEPS += \
./Project_Folders/User/Example/code_periph_use_exemple.d 


# Each subdirectory must supply rules for building sources it contributes
Project_Folders/User/Example/%.o Project_Folders/User/Example/%.su Project_Folders/User/Example/%.cyclo: ../Project_Folders/User/Example/%.c Project_Folders/User/Example/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32WLE5xx=1 -DCORE_CM4=1 -DUSE_HAL_DRIVER=1 -DUSE_FULL_LL_DRIVER=1 -DHAL_MODULE_ENABLED=1 -c -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Example/Driver/CMSIS/Include" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Example/Driver/CMSIS/Device/ST/STM32WLxx/Include" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Example/Driver/STM32WLxx_HAL_Driver/Inc/Legacy" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Example/Driver/STM32WLxx_HAL_Driver/Inc" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Example/Project_Folders/ST/ST.h" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Example/Project_Folders/User/clock_conf" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Example/Project_Folders/User/Inc" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Example/Project_Folders/User/peripheral/1_Peripheral_conf" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Example/Project_Folders/User/peripheral/GPIO" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Example/Project_Folders/User/peripheral/I2C" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Example/Project_Folders/User/peripheral/SPI" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Example/Project_Folders/User/peripheral/USART" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Example/Project_Folders/User/Example" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Example/Project_Folders/User/main" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Example/I2c_Sensors" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Project_Folders-2f-User-2f-Example

clean-Project_Folders-2f-User-2f-Example:
	-$(RM) ./Project_Folders/User/Example/code_periph_use_exemple.cyclo ./Project_Folders/User/Example/code_periph_use_exemple.d ./Project_Folders/User/Example/code_periph_use_exemple.o ./Project_Folders/User/Example/code_periph_use_exemple.su

.PHONY: clean-Project_Folders-2f-User-2f-Example

