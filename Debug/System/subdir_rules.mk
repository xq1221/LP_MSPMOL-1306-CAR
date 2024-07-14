################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
System/%.o: ../System/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/APP_INSTALL_CONTENT/CCSThia/ccs/tools/compiler/ti-cgt-armllvm_3.2.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"D:/electric_racing/workspace_ccstheia/Car" -I"D:/electric_racing/workspace_ccstheia/Car/Debug" -I"D:/APP_INSTALL_CONTENT/CCSThia/mspm0_sdk_2_01_00_03/source/third_party/CMSIS/Core/Include" -I"D:/APP_INSTALL_CONTENT/CCSThia/mspm0_sdk_2_01_00_03/source" -gdwarf-3 -MMD -MP -MF"System/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


