################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/hello_world.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/hello_world.d \
./source/semihost_hardfault.d 

OBJS += \
./source/hello_world.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\xglosm01\Documents\MCUXpressoIDE_11.10.0_3148\workspace\lpcxpresso55s69_hello_world\source" -I"C:\Users\xglosm01\Documents\MCUXpressoIDE_11.10.0_3148\workspace\lpcxpresso55s69_hello_world\utilities" -I"C:\Users\xglosm01\Documents\MCUXpressoIDE_11.10.0_3148\workspace\lpcxpresso55s69_hello_world\drivers" -I"C:\Users\xglosm01\Documents\MCUXpressoIDE_11.10.0_3148\workspace\lpcxpresso55s69_hello_world\device" -I"C:\Users\xglosm01\Documents\MCUXpressoIDE_11.10.0_3148\workspace\lpcxpresso55s69_hello_world\startup" -I"C:\Users\xglosm01\Documents\MCUXpressoIDE_11.10.0_3148\workspace\lpcxpresso55s69_hello_world\component\uart" -I"C:\Users\xglosm01\Documents\MCUXpressoIDE_11.10.0_3148\workspace\lpcxpresso55s69_hello_world\component\lists" -I"C:\Users\xglosm01\Documents\MCUXpressoIDE_11.10.0_3148\workspace\lpcxpresso55s69_hello_world\CMSIS" -I"C:\Users\xglosm01\Documents\MCUXpressoIDE_11.10.0_3148\workspace\lpcxpresso55s69_hello_world\board" -O0 -fno-common -g3 -gdwarf-4 -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/hello_world.d ./source/hello_world.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

