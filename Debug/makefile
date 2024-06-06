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


BUILD_ARTIFACT_NAME := Captor_STHS34PF80_Test
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Captor_STHS34PF80_Test.elf \

MAP_FILES += \
Captor_STHS34PF80_Test.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Captor_STHS34PF80_Test.list \


# All Target
all: main-build

# Main-build Target
main-build: Captor_STHS34PF80_Test.elf secondary-outputs

# Tool invocations
Captor_STHS34PF80_Test.elf Captor_STHS34PF80_Test.map: $(OBJS) $(USER_OBJS) ../STM32WLE5CCUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Captor_STHS34PF80_Test.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"../STM32WLE5CCUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Captor_STHS34PF80_Test.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Captor_STHS34PF80_Test.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Captor_STHS34PF80_Test.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Captor_STHS34PF80_Test.elf Captor_STHS34PF80_Test.list Captor_STHS34PF80_Test.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
