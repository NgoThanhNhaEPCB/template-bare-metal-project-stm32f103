CFLAGS += -I./sys
CPPFLAGS += -I./sys

VPATH += sys

#C source files
SOURCES += ./sys/system_stm32f10x.c

#ASM source files 
SOURCES_ASM += sys/nark_os_startup.s

