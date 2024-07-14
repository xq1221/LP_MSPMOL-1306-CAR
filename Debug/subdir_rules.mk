################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/APP_INSTALL_CONTENT/CCSThia/ccs/tools/compiler/ti-cgt-armllvm_3.2.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"D:/electric_racing/workspace_ccstheia/Car" -I"D:/electric_racing/workspace_ccstheia/Car/Debug" -I"D:/APP_INSTALL_CONTENT/CCSThia/mspm0_sdk_2_01_00_03/source/third_party/CMSIS/Core/Include" -I"D:/APP_INSTALL_CONTENT/CCSThia/mspm0_sdk_2_01_00_03/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1250001809: ../main.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"D:/APP_INSTALL_CONTENT/CCSThia/sysconfig_1.19.0/sysconfig_cli.bat" --script "D:/electric_racing/workspace_ccstheia/Car/main.syscfg" -o "." -s "D:/APP_INSTALL_CONTENT/CCSThia/mspm0_sdk_2_01_00_03/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-1250001809 ../main.syscfg
device.opt: build-1250001809
device.cmd.genlibs: build-1250001809
ti_msp_dl_config.c: build-1250001809
ti_msp_dl_config.h: build-1250001809
Event.dot: build-1250001809

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/APP_INSTALL_CONTENT/CCSThia/ccs/tools/compiler/ti-cgt-armllvm_3.2.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"D:/electric_racing/workspace_ccstheia/Car" -I"D:/electric_racing/workspace_ccstheia/Car/Debug" -I"D:/APP_INSTALL_CONTENT/CCSThia/mspm0_sdk_2_01_00_03/source/third_party/CMSIS/Core/Include" -I"D:/APP_INSTALL_CONTENT/CCSThia/mspm0_sdk_2_01_00_03/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0l130x_ticlang.o: D:/APP_INSTALL_CONTENT/CCSThia/mspm0_sdk_2_01_00_03/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0l130x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/APP_INSTALL_CONTENT/CCSThia/ccs/tools/compiler/ti-cgt-armllvm_3.2.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"D:/electric_racing/workspace_ccstheia/Car" -I"D:/electric_racing/workspace_ccstheia/Car/Debug" -I"D:/APP_INSTALL_CONTENT/CCSThia/mspm0_sdk_2_01_00_03/source/third_party/CMSIS/Core/Include" -I"D:/APP_INSTALL_CONTENT/CCSThia/mspm0_sdk_2_01_00_03/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


