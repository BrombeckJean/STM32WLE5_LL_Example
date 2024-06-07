################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Project_Folders/User/peripheral/USART/subdir.mk
-include Project_Folders/User/peripheral/SPI/subdir.mk
-include Project_Folders/User/peripheral/I2C/subdir.mk
-include Project_Folders/User/peripheral/GPIO/subdir.mk
-include Project_Folders/User/peripheral/1_Peripheral_conf/subdir.mk
-include Project_Folders/User/main/subdir.mk
-include Project_Folders/User/clock_conf/subdir.mk
-include Project_Folders/User/Example/subdir.mk
-include Project_Folders/Startup/subdir.mk
-include Project_Folders/ST/ST.c/subdir.mk
-include I2c_Sensors/subdir.mk
-include Driver/STM32WLxx_HAL_Driver/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := STM32WLE5_LL_Exemple
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32WLE5_LL_Exemple.elf \

MAP_FILES += \
STM32WLE5_LL_Exemple.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32WLE5_LL_Exemple.list \


# All Target
all: main-build

# Main-build Target
main-build: STM32WLE5_LL_Exemple.elf secondary-outputs

dependents:
	-cd /home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Debug && $(MAKE) all

# Tool invocations
STM32WLE5_LL_Exemple.elf STM32WLE5_LL_Exemple.map: $(OBJS) $(USER_OBJS) /home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Debug/STM32WLE5_LL_Exemple.elf ../STM32WLE5CCUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "STM32WLE5_LL_Exemple.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"../STM32WLE5CCUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32WLE5_LL_Exemple.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32WLE5_LL_Exemple.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32WLE5_LL_Exemple.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) STM32WLE5_LL_Exemple.elf STM32WLE5_LL_Exemple.list STM32WLE5_LL_Exemple.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified
/home/jean/STM32CubeIDE/workspace_1.12.1/STM32WLE5_LL_Exemple/Debug/STM32WLE5_LL_Exemple.elf:

-include ../makefile.targets
