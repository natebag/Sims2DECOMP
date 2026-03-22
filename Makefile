# Sims 2 GameCube — Matching Decompilation Build System
# Compiler: devkitPPC (GCC cross-compiler for PowerPC/Gekko)
# Target: Nintendo GameCube (Gekko CPU, PowerPC 750CXe)
#
# Build pipeline:
#   1. gen_skeleton.py generates .s files with all symbol labels
#   2. GAS assembles skeleton + decompiled source into .o files
#   3. LD links with ldscript.lcf placing sections at original addresses
#   4. dtk dol diff compares linked ELF against original DOL

#==============================================================================
# Toolchain paths
#==============================================================================
DEVKITPPC ?= F:/coding/Decompiles/Tools/devkitPro/devkitPPC
DTK       ?= F:/coding/Decompiles/Tools/dtk-windows-x86_64.exe
PYTHON    ?= python3.14

CC      := $(DEVKITPPC)/bin/powerpc-eabi-gcc
CXX     := $(DEVKITPPC)/bin/powerpc-eabi-g++
AS      := $(DEVKITPPC)/bin/powerpc-eabi-as
LD      := $(DEVKITPPC)/bin/powerpc-eabi-ld
AR      := $(DEVKITPPC)/bin/powerpc-eabi-ar
OBJCOPY := $(DEVKITPPC)/bin/powerpc-eabi-objcopy
OBJDUMP := $(DEVKITPPC)/bin/powerpc-eabi-objdump

#==============================================================================
# Target
#==============================================================================
TARGET_DOL   := extracted/sys/main.dol
TARGET_ELF   := extracted/files/u2_ngc_release_dvd.elf
DTK_CONFIG   := config/sims2_gc.yml
BUILD_DIR    := build
SKELETON_DIR := $(BUILD_DIR)/skeleton
OUTPUT_ELF   := $(BUILD_DIR)/sims2.elf
OUTPUT_DOL   := $(BUILD_DIR)/sims2.dol

#==============================================================================
# Compiler flags
# Original compiler: SN Systems ProDG for GameCube
# We use GCC flags that approximate SN Systems output as closely as possible.
# NOTE: Exact byte-matching with GCC may not be achievable for all functions
# since SN Systems uses a different code generator. Some functions may need
# hand-written assembly or compiler-specific workarounds.
#==============================================================================
# CPU: Gekko (PowerPC 750CXe derivative)
ARCH_FLAGS := -mcpu=750 -meabi -mhard-float

# Optimization: SN Systems release builds typically use -O2
OPT_FLAGS := -O2

# C++ flags matching EA's coding conventions
CXXFLAGS := $(ARCH_FLAGS) $(OPT_FLAGS) \
	-fno-exceptions \
	-fno-rtti \
	-fno-builtin \
	-fshort-wchar \
	-nostdinc++ \
	-Wall -Wno-unused -Wno-return-type \
	-fpermissive

CFLAGS := $(ARCH_FLAGS) $(OPT_FLAGS) \
	-fno-builtin \
	-Wall -Wno-unused

ASFLAGS := -mgekko -mregnames -memb

# Include paths
INCLUDES := -Iinclude -Isrc -Ilibs/dolphinsdk -Ilibs/sn_runtime -Ilibs/apt

# Defines matching the original build
DEFINES := -DNDEBUG \
	-DEA_PLATFORM_GAMECUBE=1 \
	-DGEKKO

CXXFLAGS += $(INCLUDES) $(DEFINES)
CFLAGS   += $(INCLUDES) $(DEFINES)

#==============================================================================
# Linker
#==============================================================================
LDSCRIPT := config/ldscript.lcf

LDFLAGS := -T $(LDSCRIPT) \
	-nostdlib \
	--allow-multiple-definition \
	--no-check-sections \
	--noinhibit-exec

#==============================================================================
# Sources
#==============================================================================
# Skeleton sections (auto-generated from symbols.txt)
SKELETON_SECTIONS := init text ctors rodata data bss sdata sbss sdata2
SKELETON_SRCS := $(addprefix $(SKELETON_DIR)/,$(addsuffix .s,$(SKELETON_SECTIONS)))
SKELETON_OBJS := $(SKELETON_SRCS:.s=.o)

# Decompiled C/C++ source files (including auto-matched in src/matched/)
# Use wildcard instead of find for Windows compatibility
C_SRCS   := $(wildcard src/**/*.c) $(wildcard src/**/**/*.c)
CXX_SRCS := $(wildcard src/**/*.cpp) $(wildcard src/**/**/*.cpp)
ASM_SRCS := $(wildcard src/**/*.s) $(wildcard src/**/**/*.s)

# Object files from decompiled sources
C_OBJS   := $(C_SRCS:src/%.c=$(BUILD_DIR)/obj/%.o)
CXX_OBJS := $(CXX_SRCS:src/%.cpp=$(BUILD_DIR)/obj/%.o)
ASM_OBJS := $(ASM_SRCS:src/%.s=$(BUILD_DIR)/obj/%.o)
DECOMP_OBJS := $(C_OBJS) $(CXX_OBJS) $(ASM_OBJS)

# All objects: decomp first (real code), skeleton last (fills gaps with stubs)
ALL_OBJS := $(DECOMP_OBJS) $(SKELETON_OBJS)

#==============================================================================
# Rules
#==============================================================================
.PHONY: all clean diff test skeleton info

all: $(OUTPUT_ELF)

#--- Skeleton generation ---

# Generate skeleton assembly from symbols.txt
skeleton: $(SKELETON_SRCS)

$(SKELETON_SRCS): config/symbols.txt tools/gen_skeleton.py | $(SKELETON_DIR)
	@echo "  GEN     Generating skeleton assembly..."
	@$(PYTHON) tools/gen_skeleton.py

$(SKELETON_DIR):
	@mkdir -p $(SKELETON_DIR)

# Assemble skeleton sections
$(SKELETON_DIR)/%.o: $(SKELETON_DIR)/%.s
	@echo "  AS      $<"
	@$(AS) $(ASFLAGS) $< -o $@

#--- Decompiled source compilation ---

$(BUILD_DIR)/obj/%.o: src/%.cpp | $(BUILD_DIR)/obj
	@mkdir -p $(dir $@)
	@echo "  CXX     $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/obj/%.o: src/%.c | $(BUILD_DIR)/obj
	@mkdir -p $(dir $@)
	@echo "  CC      $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/obj/%.o: src/%.s | $(BUILD_DIR)/obj
	@mkdir -p $(dir $@)
	@echo "  AS      $<"
	@$(AS) $(ASFLAGS) $< -o $@

$(BUILD_DIR)/obj:
	@mkdir -p $(BUILD_DIR)/obj

#--- Linking ---

# Link all objects into ELF (use response file for Windows arg length limit)
$(OUTPUT_ELF): $(ALL_OBJS) $(LDSCRIPT) | $(BUILD_DIR)
	@echo "  LINK    $@ ($(words $(ALL_OBJS)) objects)"
	@printf '%s\n' $(ALL_OBJS) > $(BUILD_DIR)/objects.rsp
	@$(LD) $(LDFLAGS) -o $@ @$(BUILD_DIR)/objects.rsp

# Convert ELF to DOL
$(OUTPUT_DOL): $(OUTPUT_ELF)
	@echo "  DOL     $@"
	@$(DTK) elf2dol $< $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

#--- Verification ---

# Diff linked ELF against original DOL (shows mismatched functions)
diff: $(OUTPUT_ELF)
	@echo "  DIFF    Comparing against original DOL..."
	@$(DTK) dol diff $(DTK_CONFIG) $(OUTPUT_ELF)

# Quick test: verify toolchain is working
test:
	@echo "Testing devkitPPC toolchain..."
	@$(CXX) --version | head -1
	@$(AS) --version | head -1
	@echo "Toolchain OK"

# Disassemble a single object file (usage: make disasm FILE=build/obj/foo.o)
disasm:
	@$(OBJDUMP) -d -M gekko $(FILE)

#--- Cleanup ---

clean:
	rm -rf $(BUILD_DIR)

# Print useful info
info:
	@echo "DEVKITPPC:  $(DEVKITPPC)"
	@echo "DTK:        $(DTK)"
	@echo "CC:         $(CC)"
	@echo "CXX:        $(CXX)"
	@echo "Linker:     $(LDSCRIPT)"
	@echo "Skeleton:   $(words $(SKELETON_OBJS)) sections"
	@echo "Decomp src: $(words $(CXX_SRCS)) C++ / $(words $(C_SRCS)) C / $(words $(ASM_SRCS)) ASM"
	@echo "Total objs: $(words $(ALL_OBJS))"
