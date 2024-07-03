################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Project_Folders/Startup/startup_stm32wle5ccux.s 

OBJS += \
./Project_Folders/Startup/startup_stm32wle5ccux.o 

S_DEPS += \
./Project_Folders/Startup/startup_stm32wle5ccux.d 


# Each subdirectory must supply rules for building sources it contributes
Project_Folders/Startup/%.o: ../Project_Folders/Startup/%.s Project_Folders/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DCORE_CM4 -c -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Driver/CMSIS/Include" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Driver/CMSIS/Device/ST/STM32WLxx/Include" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Driver/STM32WLxx_HAL_Driver/Inc/Legacy" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Driver/STM32WLxx_HAL_Driver/Inc" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/ST/ST.h" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/Inc" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/Example" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/Clock_Conf" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/Peripheral/I2C" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/Peripheral/GPIO" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/Peripheral/USART" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/Peripheral/SPI" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/Main" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/Peripheral/RNG" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/Peripheral/I2C/I2c_Sensors" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/Option" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/Peripheral/Peripheral_Init" -I"/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Project_Folders/User/TEST" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Project_Folders-2f-Startup

clean-Project_Folders-2f-Startup:
	-$(RM) ./Project_Folders/Startup/startup_stm32wle5ccux.d ./Project_Folders/Startup/startup_stm32wle5ccux.o

.PHONY: clean-Project_Folders-2f-Startup

