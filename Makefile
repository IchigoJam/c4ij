CSRC	= main.c
ASRC	=

PROJECT	= c4ij

# Programs to build porject
# https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads
CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
SIZE    = arm-none-eabi-size
NM      = arm-none-eabi-nm
BIN2BAS = ./bin2bas # default 0x700
BAS2BIN = ./bas2bin
#BIN2BAS = ./bin2bas --startaddress 2048 # 0x800 for expcg
#BIN2BAS = ./bin2bas --nolineno --startaddress 3328 # 0xd00 for exchg

# Optimization (0, 1, 2, 3, 4, s)
OPTIMIZE = s

# C Standard (c89, gnu89, c99, gnu99)
CSTD = gnu99

# Processor type and use Thumb(-2) mode for CSRC/ASRC files (YES or NO)
CPU   = cortex-m0
THUMB = YES

# Linker script for the target MCU
LINKSCRIPT = c4ij.ld # ROM:1KB RAM:1KB?

### Output file type (hex, bin or both) and debugger type
OUTPUT	= both
HEXFMT  = ihex
DEBUG	= # dwarf-2

### Include dirs, library dirs and definitions
MATHLIB	= #-lm
LIBS	=
LIBDIRS	=
INCDIRS	= src
DEFS	=
ADEFS	=

# Warning contorls
WARNINGS = all extra

# Directory
SRCDIR = src
OBJDIR = obj

# Programs to write
LPC21ISP  = ../../../c/lpc21isp_197k/lpc21isp
USBSERIAL = /dev/tty.SLAB_USBtoUART

# Define all object files
COBJ      = $(CSRC:.c=.o)
AOBJ      = $(ASRC:.S=.o)
COBJ      := $(addprefix $(OBJDIR)/,$(COBJ))
AOBJ      := $(addprefix $(OBJDIR)/,$(AOBJ))
PROJECT   := $(OBJDIR)/$(PROJECT)

### Compiler flags
ifeq ($(THUMB),YES)
THUMBFLAG = -mthumb
THUMBIW = -mthumb-interwork
else
THUMBFLAG =
THUMBIW =
endif

# Compiler flags
CFLAGS += -std=$(CSTD)
CFLAGS += -g$(DEBUG)
CFLAGS += -O$(OPTIMIZE)
#CFLAGS += $(addprefix -W,$(WARNINGS))
#CFLAGS += -Wunused-parameter
CFLAGS += $(addprefix -I,$(INCDIRS))
CFLAGS += $(addprefix -D,$(DEFS))
CFLAGS += -fomit-frame-pointer -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections
#CFLAGS += -w -c
# -W -Wall -c -fno-builtin
#CFLAGS += -Wp,-M,-MP,-MT,$(OBJDIR)/$(*F).o,-MF,$(OBJDIR)/$(*F).d
CFLAGS += -Wp,-M,-MP,-MT,$(OBJDIR)/$(*F).o,-MF,$(OBJDIR)/$(*F).d

# Assembler flags
ASFLAGS += $(addprefix -D,$(ADEFS)) -Wa,-g$(DEBUG)

# Linker flags
LDFLAGS += -nostartfiles -Wl,-Map=$(PROJECT).map,--cref,--gc-sections
LDFLAGS += -lc -lgcc
LDFLAGS += $(patsubst %,-L%,$(LIBDIRS)) $(patsubst %,-l%,$(LIBS))
LDFLAGS += $(MATHLIB)
LDFLAGS += -T$(LINKSCRIPT)

ALL_CFLAGS  = -mcpu=$(CPU) $(THUMBIW) -I. $(CFLAGS)
ALL_ASFLAGS = -mcpu=$(CPU) $(THUMBIW) -I. -x assembler-with-cpp $(ASFLAGS)

BAS2BIN_FLAGS = # --nopadding

#all: bas2bin build size
all: build size

ifeq ($(OUTPUT),hex)
build: axf hex lst sym
hex: $(PROJECT).hex
else
ifeq ($(OUTPUT),bin)
build: axf bin lst sym
bin: $(PROJECT).bin
else
ifeq ($(OUTPUT),both)
build: axf hex bin lst sym
hex: $(PROJECT).hex
bin: $(PROJECT).bin
else
$(error "Invalid format: $(OUTPUT)")
endif
endif
endif

axf: $(PROJECT).axf
lst: $(PROJECT).lst 
sym: $(PROJECT).sym

#bas2bin: bas2bin.c

%.bas: %.o
	@echo
	#$(BAS2BIN) --nopadding $< $@

%.hex: %.axf
	@echo
	$(OBJCOPY) -O $(HEXFMT) $< $@

%.bin: %.axf
	@echo
	$(OBJCOPY) -O binary $< $@

%.lst: %.axf
	@echo
	$(OBJDUMP) -h -S -C $< > $@

%.sym: %.axf
	@echo
	$(NM) -n $< > $@

size:
	$(SIZE) $(PROJECT).axf
	ls -l $(PROJECT).bin

%.axf:  $(AOBJARM) $(AOBJ) $(COBJARM) $(COBJ)
	@echo
	@echo Linking...
	$(CC) $(THUMBFLAG) $(ALL_CFLAGS) $(AOBJ) $(COBJ) -o $@ $(LDFLAGS)

$(COBJ) : $(OBJDIR)/%.o : $(SRCDIR)/%.c #$(BOBJ)
	@echo
	@echo $< :
	#gcc bas2bin.c -o bas2bin
	#$(BAS2BIN) $(BAS2BIN_FLAGS) $(SRCDIR)/entry.bas $(OBJDIR)/entry.o
	$(CC) -c $(THUMBFLAG) $(ALL_CFLAGS) $< -o $@

$(AOBJ) : $(OBJDIR)/%.o : %.S
	@echo
	@echo $< :
	$(CC) -c $(THUMBFLAG) $(ALL_ASFLAGS) $< -o $@

#$(BOBJ) : $(OBJDIR)/%.o : %.bas
#	@echo
#	@echo $< :
#	$(BAS2BIN) --nopadding $< $@

clean:
	@echo
#	rm $(BAS2BIN)
	rm -f -r $(OBJDIR) | exit 0

dasm:
	$(OBJDUMP) -D -bbinary -marm $(PROJECT).bin -Mforce-thumb2 > asm.s
	cat asm.s
	@echo 'see ./asm.s'
#	cat $(PROJECT).bin >> $(OBJDIR)/ij.bin
#	$(LPC21ISP) -control -bin $(OBJDIR)/ij.bin $(USBSERIAL) 115200 1200

write: build
	echo "1 @ARUN:POKE#700,3,180,4,73,8,104,64,28,0,209,3,73,1,49,140,70,3,188,96,71,0,100,0,0,0,116,0,0:?USR(#700):END" > entry.bas
	$(BAS2BIN) entry.bas entry.bin
	cat entry.bin obj/c4ij.bin > sector6.bin
	$(LPC21ISP) -control -bin -sector6 sector6.bin $(USBSERIAL) 115200 1200

poke: build
	$(BIN2BAS) $(PROJECT).bin > main.bas
	cat main.bas

-include $(shell mkdir $(OBJDIR) 2>/dev/null) $(wildcard $(OBJDIR)/*.d)
