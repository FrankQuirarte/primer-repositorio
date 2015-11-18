################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Exceptions.c" \
"../Sources/INIT_CLOCK_SW_LEDS.c" \
"../Sources/IntcInterrupts.c" \
"../Sources/STM_config.c" \
"../Sources/delay.c" \
"../Sources/ivor_branch_table.c" \
"../Sources/main.c" \
"../Sources/reset_clean.c" \

C_SRCS += \
../Sources/Exceptions.c \
../Sources/INIT_CLOCK_SW_LEDS.c \
../Sources/IntcInterrupts.c \
../Sources/STM_config.c \
../Sources/delay.c \
../Sources/ivor_branch_table.c \
../Sources/main.c \
../Sources/reset_clean.c \

OBJS += \
./Sources/Exceptions_c.obj \
./Sources/INIT_CLOCK_SW_LEDS_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/STM_config_c.obj \
./Sources/delay_c.obj \
./Sources/ivor_branch_table_c.obj \
./Sources/main_c.obj \
./Sources/reset_clean_c.obj \

OBJS_QUOTED += \
"./Sources/Exceptions_c.obj" \
"./Sources/INIT_CLOCK_SW_LEDS_c.obj" \
"./Sources/IntcInterrupts_c.obj" \
"./Sources/STM_config_c.obj" \
"./Sources/delay_c.obj" \
"./Sources/ivor_branch_table_c.obj" \
"./Sources/main_c.obj" \
"./Sources/reset_clean_c.obj" \

C_DEPS += \
./Sources/Exceptions_c.d \
./Sources/INIT_CLOCK_SW_LEDS_c.d \
./Sources/IntcInterrupts_c.d \
./Sources/STM_config_c.d \
./Sources/delay_c.d \
./Sources/ivor_branch_table_c.d \
./Sources/main_c.d \
./Sources/reset_clean_c.d \

OBJS_OS_FORMAT += \
./Sources/Exceptions_c.obj \
./Sources/INIT_CLOCK_SW_LEDS_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/STM_config_c.obj \
./Sources/delay_c.obj \
./Sources/ivor_branch_table_c.obj \
./Sources/main_c.obj \
./Sources/reset_clean_c.obj \

C_DEPS_QUOTED += \
"./Sources/Exceptions_c.d" \
"./Sources/INIT_CLOCK_SW_LEDS_c.d" \
"./Sources/IntcInterrupts_c.d" \
"./Sources/STM_config_c.d" \
"./Sources/delay_c.d" \
"./Sources/ivor_branch_table_c.d" \
"./Sources/main_c.d" \
"./Sources/reset_clean_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Exceptions_c.obj: ../Sources/Exceptions.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Exceptions.args" -o "Sources/Exceptions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/INIT_CLOCK_SW_LEDS_c.obj: ../Sources/INIT_CLOCK_SW_LEDS.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/INIT_CLOCK_SW_LEDS.args" -o "Sources/INIT_CLOCK_SW_LEDS_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/IntcInterrupts_c.obj: ../Sources/IntcInterrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/IntcInterrupts.args" -o "Sources/IntcInterrupts_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/STM_config_c.obj: ../Sources/STM_config.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/STM_config.args" -o "Sources/STM_config_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/delay_c.obj: ../Sources/delay.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/delay.args" -o "Sources/delay_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/ivor_branch_table_c.obj: ../Sources/ivor_branch_table.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/ivor_branch_table.args" -o "Sources/ivor_branch_table_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/main.args" -o "Sources/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/reset_clean_c.obj: ../Sources/reset_clean.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/reset_clean.args" -o "Sources/reset_clean_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


