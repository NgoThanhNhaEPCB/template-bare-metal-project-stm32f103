# Include sources file
include app/Makefile.mk
include drivers/Makefile.mk
include libraries/Makefile.mk
include sys/Makefile.mk
include irq/Makefile.mk

# Utilitis define
Print = @echo "~"

# Name of build PROJECT ex: template-bare-metal-project-stm32f103.bin
NAME_MODULE = template-bare-metal-project-stm32f103
PROJECT = $(NAME_MODULE)
TARGET = $(NAME_MODULE)
OBJECTS_DIR = build_$(NAME_MODULE)

GCC_PATH		= $(HOME)/workspace/tools/gcc-arm-none-eabi-10.3-2021.10
PROGRAMER_PATH		= $(HOME)/workspace/tools/STM32CubeProgrammer/bin

# App start address, that need sync with declare in linker file and interrupt vector table.
APP_START_ADDR_VAL = 0x8000000

OPTIMIZE_OPTION = -g -Os

LIBC		= $(GCC_PATH)/arm-none-eabi/lib/thumb/v7-m/nofp/libc.a
LIBM		= $(GCC_PATH)/arm-none-eabi/lib/thumb/v7-m/nofp/libm.a
LIBFPU		= $(GCC_PATH)/arm-none-eabi/lib/thumb/v7-m/nofp/libg.a
LIBRDPMON	= $(GCC_PATH)/arm-none-eabi/lib/thumb/v7-m/nofp/librdpmon.a
LIBSTDCPP_NANO	= $(GCC_PATH)/arm-none-eabi/lib/thumb/v7-m/nofp/libstdc++_nano.a

LIBGCC		= $(GCC_PATH)/lib/gcc/arm-none-eabi/10.3.1/thumb/v7-m/nofp/libgcc.a
LIBGCOV		= $(GCC_PATH)/lib/gcc/arm-none-eabi/10.3.1/thumb/v7-m/nofp/libgcov.a

LIB_PATH += -L$(GCC_PATH)/arm-none-eabi/lib/thumb/v7-m/nofp
LIB_PATH += -L$(GCC_PATH)/lib/gcc/arm-none-eabi/10.3.1/thumb/v7-m/nofp

# The command for calling the compiler.
CC		=	$(GCC_PATH)/bin/arm-none-eabi-gcc
CPP		=	$(GCC_PATH)/bin/arm-none-eabi-g++
AR		=	$(GCC_PATH)/bin/arm-none-eabi-ar
AS		=	$(GCC_PATH)/bin/arm-none-eabi-gcc -x assembler-with-cpp
LD 		= 	$(GCC_PATH)/bin/arm-none-eabi-ld
OBJCOPY		=	$(GCC_PATH)/bin/arm-none-eabi-objcopy
ARM_SIZE	=	$(GCC_PATH)/bin/arm-none-eabi-size

# Set the compiler CPU/FPU options.
CPU = -mthumb -march=armv7-m -mcpu=cortex-m3
FPU = -mfloat-abi=soft

GENERAL_FLAGS +=			\
		$(OPTIMIZE_OPTION)	\
		-DNDEBUG		\
		-DUSE_STDPERIPH_DRIVER	\
		-DSTM32F10X_MD		\
		-DSTM32F103xB		\

# C compiler flags
CFLAGS +=	\
		$(CPU)			\
		$(FPU)			\
		-ffunction-sections	\
		-fdata-sections		\
		-fstack-usage		\
		-MD			\
		-Wall			\
		-Wno-enum-conversion	\
		-std=c99		\
		-c			\
		$(GENERAL_FLAGS)	\

# C++ compiler flags
CPPFLAGS += $(CPU)			\
		$(FPU)			\
		-ffunction-sections	\
		-fdata-sections		\
		-fstack-usage		\
		-fno-rtti		\
		-fno-exceptions		\
		-fno-use-cxa-atexit	\
		-MD			\
		-Wall			\
		-std=c++11		\
		-c			\
		$(GENERAL_FLAGS)	\

# linker file
LDFILE = sys/nark_os.ld

LDFLAGS = 	$(CPU) -T$(LDFILE) -Wl,-Map=$(OBJECTS_DIR)/$(TARGET).map,--cref -Wl,--gc-sections	\
			$(LIB_PATH) $(LIBC) $(LIBM) $(LIBSTDCPP_NANO) $(LIBGCC) $(LIBGCOV) $(LIBFPU) $(LIBRDPMON)

TARGET_ELF = $(OBJECTS_DIR)/$(TARGET).elf
TARGET_HEX = $(OBJECTS_DIR)/$(TARGET).hex
TARGET_BIN = $(OBJECTS_DIR)/$(TARGET).bin

all: $(TARGET_HEX) $(TARGET_BIN)

OBJECTS = $(addprefix $(OBJECTS_DIR)/,$(notdir $(SOURCES_ASM:.s=.o)))
OBJECTS += $(addprefix $(OBJECTS_DIR)/,$(notdir $(SOURCES:.c=.o)))
OBJECTS += $(addprefix $(OBJECTS_DIR)/,$(notdir $(SOURCES_CPP:.cpp=.o)))

#################################
# build
#################################
$(TARGET_BIN): $(TARGET_ELF)
	@$(OBJCOPY) -O binary --set-start 0x8000000 $< $@

$(TARGET_HEX): $(TARGET_ELF)
	@$(OBJCOPY) -O ihex --set-start 0x8000000 $< $@

$(TARGET_ELF): $(OBJECTS)
	@$(CPP) -o $@ $^ $(LDFLAGS)
	@$(ARM_SIZE) $(TARGET_ELF)

$(OBJECTS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(Print) "CPP $(dir $@)$(notdir $<)"
	@$(CPP) -c -o $@ $(CPPFLAGS) $<

$(OBJECTS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(Print) "CC $(dir $@)$(notdir $<)"
	@$(CC) -c -o $@ $(CFLAGS) $<

$(OBJECTS_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	@$(Print) "AS $(dir $@)$(notdir $<)"
	@$(AS) -c -o $@ $(CFLAGS) $<

flash: all
	$(PROGRAMER_PATH)/STM32_Programmer.sh -c port=SWD -w $(TARGET_BIN) $(APP_START_ADDR_VAL) -rst

clean:
	$(Print) CLEAN $(OBJECTS_DIR) folder
	@rm -rf $(OBJECTS_DIR)
