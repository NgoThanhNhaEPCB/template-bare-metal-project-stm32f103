CFLAGS += -I./drivers/stm32f_peripheral_drivers/CMSIS/CM3/CoreSupport
CFLAGS += -I./drivers/stm32f_peripheral_drivers/CMSIS/CM3/DeviceSupport/ST/STM32F10x

CPPFLAGS += -I./drivers/stm32f_peripheral_drivers/CMSIS/CM3/CoreSupport
CPPFLAGS += -I./drivers/stm32f_peripheral_drivers/CMSIS/CM3/DeviceSupport/ST/STM32F10x

VPATH += ./drivers/stm32f_peripheral_drivers/CMSIS/CM3/DeviceSupport/ST/STM32F10x
SOURCES += ./drivers/stm32f_peripheral_drivers/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c