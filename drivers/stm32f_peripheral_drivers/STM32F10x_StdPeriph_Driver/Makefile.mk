CFLAGS += -I./drivers/stm32f_peripheral_drivers/STM32F10x_StdPeriph_Driver/inc
CPPFLAGS += -I./drivers/stm32f_peripheral_drivers/STM32F10x_StdPeriph_Driver/inc

VPATH += ./drivers/stm32f_peripheral_drivers/STM32F10x_StdPeriph_Driver/src

# C source files
SOURCES += ./drivers/stm32f_peripheral_drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c
SOURCES += ./drivers/stm32f_peripheral_drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c
SOURCES += ./drivers/stm32f_peripheral_drivers/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c
SOURCES += ./drivers/stm32f_peripheral_drivers/STM32F10x_StdPeriph_Driver/src/misc.c