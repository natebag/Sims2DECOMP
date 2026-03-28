# Build System

How the matching decompilation build pipeline works.

## Overview

The build system compiles decompiled C/C++ source code and links it into an ELF
that can be compared byte-for-byte against the original GameCube DOL executable.

```
symbols.txt ──► gen_skeleton.py ──► skeleton .s files
                                         │
                                         ▼
                                    GAS assembler ──► skeleton .o files ─┐
                                                                        │
src/*.cpp / src/*.c ──► GCC compiler ──► decomp .o files ───────────────┤
                                                                        │
                                                              ldscript.lcf
                                                                        │
                                                                        ▼
                                                                   GNU LD ──► sims2.elf
                                                                                 │
                                                                                 ▼
                                                                   dtk dol diff ──► match report
                                                                (compares vs main.dol)
```

## Quick Start

```bash
make all        # Generate skeleton, assemble, link → build/sims2.elf
make diff       # Compare linked ELF against original DOL
make clean      # Remove all build artifacts
make info       # Show toolchain configuration
make test       # Verify toolchain is working
```

## Pipeline Details

### 1. Skeleton Generation (`tools/gen_skeleton.py`)

The skeleton is the foundation. It generates one `.s` assembly file per ELF
section from `config/symbols.txt`. Each file defines all symbols as global
labels at the correct byte offsets, with `.space` directives for padding.

This ensures the linked ELF has all ~37K symbols at the right addresses,
allowing `dtk dol diff` to look up any symbol and compare its bytes.

**Section mapping** (dtk names → ELF names):

| symbols.txt | ELF section | Address      | Type    |
|-------------|-------------|--------------|---------|
| `.init`     | `.init`     | `0x80003100` | code    |
| `.text`     | `.text`     | `0x800034C0` | code    |
| `.data2`    | `.ctors`    | `0x803CA900` | data    |
| `.data3`    | `.rodata`   | `0x803CAD20` | data    |
| `.data4`    | `.data`     | `0x804235E0` | data    |
| `.bss`      | `.bss`      | `0x8046E1E0` | bss     |
| `.data5`    | `.sdata`    | `0x804FD920` | data    |
| `.sbss`     | `.sbss`     | `0x804FF6C0` | bss     |
| `.data6`    | `.sdata2`   | `0x80500600` | data    |

### 2. Assembly (devkitPPC GAS)

Each skeleton `.s` file is assembled with:
```
powerpc-eabi-as -mgekko -memb <input.s> -o <output.o>
```

Decompiled source files in `src/` are compiled with GCC:
```
powerpc-eabi-g++ -mcpu=750 -meabi -mhard-float -O2 \
    -fno-exceptions -fno-rtti -fno-builtin -fshort-wchar \
    -c <input.cpp> -o <output.o>
```

### 3. Linking (`config/ldscript.lcf`)

The linker script places sections at exact virtual addresses matching the
original DOL. Key definitions:

| Symbol        | Value          | Purpose                         |
|---------------|----------------|---------------------------------|
| Entry point   | `0x80003100`   | `__start` in `.init`            |
| `_SDA_BASE_`  | `0x80505920`   | r13 base for `.sdata`/`.sbss`   |
| `_SDA2_BASE_` | `0x80515920`   | r2 base for `.sdata2`/`.sbss2`  |
| `__stack_addr` | `0x805115A0`  | Stack pointer (set by `__start`) |

The SDA base values were extracted from the `__start` function where r13 and
r2 are initialized.

### 4. Verification (`dtk dol diff`)

```bash
dtk dol diff config/sims2_gc.yml build/sims2.elf
```

Compares each function symbol in `config/symbols.txt` between the linked ELF
and the original DOL (`extracted/sys/main.dol`). Shows a side-by-side
disassembly diff for any function that doesn't byte-match.

## Decompiling a Function

To decompile a function:

1. Find the function in `config/symbols.txt` to get its address and size
2. Examine the original code in Ghidra or via objdump:
   ```bash
   powerpc-eabi-objdump -d -M gekko \
       --start-address=0xADDRESS --stop-address=0xADDR+SIZE \
       extracted/files/u2_ngc_release_dvd.elf
   ```
3. Write the C/C++ implementation in `src/`
4. Build and diff:
   ```bash
   make all && make diff
   ```

Or use the single-function checker:
```bash
python tools/check_func.py src/your_file.cpp FunctionName --addr 0xADDRESS --size SIZE
```

## Toolchain

| Tool          | Version   | Purpose                      |
|---------------|-----------|------------------------------|
| devkitPPC     | GCC 15.2  | PowerPC cross-compiler       |
| GAS           | 2.45.1    | GNU assembler                |
| GNU LD        | 2.45.1    | Linker                       |
| dtk           | 1.8.3     | DOL splitting and diffing    |
| Python        | 3.14      | Build scripts                |

**Note:** The original game was compiled with SN Systems ProDG, not GCC.
GCC may not produce byte-identical output for all functions. Some functions
may need hand-written assembly to match.

## Symbol Name Sanitization

Some symbols from the map file contain characters invalid in GAS assembly:

| Original  | Sanitized    | Reason                              |
|-----------|-------------|--------------------------------------|
| `@123`    | `_anon_123` | `@` is special in GAS               |
| `op|_eq`  | `op_OR__eq` | `|` not valid in labels              |
| `op^_eq`  | `op_XOR__eq`| `^` not valid in labels              |

These sanitizations are applied in both `config/symbols.txt` and the generated
skeleton assembly, so dtk can still match symbols by name.
