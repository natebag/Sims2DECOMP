# Boot Sequence — The Sims 2 (GameCube)

## Overview

The GameCube boot ROM loads the DOL executable into memory and jumps to `__start` at `0x80003100`. The entire boot sequence lives in the `.init` section (960 bytes) and is split across two object files:

| Object File | Source | Address Range | Size |
|-------------|--------|---------------|------|
| `crt0.o` | SN Systems libsn.a | `0x80003100 — 0x80003467` | 872 bytes |
| `__ppc_eabi_init.o` | DolphinSDK 1.0 HW2 os.a | `0x80003468 — 0x800034BF` | 88 bytes |

## Boot Flow

```
Boot ROM
  └─ __start (0x80003100) ─── SN Systems crt0
       ├─ Set r1 (stack), r2 (SDA2), r13 (SDA)
       ├─ __init_gqr (0x80003300) ─── Clear all 8 GQR registers
       ├─ __init_fprs (0x80003334) ─── Clear all FPR + PS registers, FPSCR
       ├─ __init_hardware (0x80003468) ─── DolphinSDK
       │    ├─ Enable MSR[FP]
       │    ├─ __OSPSInit (0x8024BBF4)
       │    ├─ __OSFPRInit (0x8024B05C)
       │    └─ __OSCacheInit (0x8024D448)
       ├─ Set up terminating stack frame (LR = 0xFFFFFFFF)
       ├─ memset .bss to zero
       ├─ memset .sbss to zero
       ├─ Clear ArenaHi (0x80000044)
       ├─ Check BS2 DVD args (0x800000F4)
       │    └─ If present: SNDebugInit (0x8023CCBC)
       ├─ __init_args (0x80003254) ─── Parse command-line args from DVD
       ├─ DBInit (0x8025A844) ─── Debug communication init
       ├─ OSInit (0x8024B348) ─── Dolphin OS init
       ├─ Check MEM1 arena flags (0x800030E6)
       │    └─ __check_pad3 (0x800032C0) ─── Reset if pad3 combo held
       ├─ __premain (0x80003464) ─── Stub (blr)
       ├─ __init_user (0x80255C4C) ─── C++ static constructors
       │
       ├─ [If debug probe active]:
       │    ├─ OSReport SN Systems version strings
       │    └─ rfi to main (sets up MSR with RI, clears EE)
       │
       └─ [Normal path]:
            ├─ main(argc, argv) (0x802E39F0)
            └─ exit (0x80242898)
```

## Functions

### `__start` (0x80003100, crt0.o)
**Entry point.** Sets up the C runtime environment:
1. Loads stack pointer, SDA2 base (r2), and SDA base (r13) from linker symbols
2. Initializes GQR registers, FPRs, and hardware
3. Creates a terminating stack frame with invalid back-chain (0xFFFFFFFF)
4. Zeroes `.bss` and `.sbss` sections via `memset`
5. Checks for SN Systems debug probe via BS2 DVD argument block at `0x800000F4`
6. Parses command-line arguments, initializes OS subsystems
7. Runs C++ static constructors via `__init_user`
8. Calls `main()` then `exit()`

The debug probe path uses `rfi` (return from interrupt) to transition to `main()` with a specific MSR configuration (RI set, EE cleared).

### `__init_gqr` (0x80003300, internal to crt0.o)
Zeroes all 8 Gekko Quantize Registers (GQR0-GQR7). These control paired-single load/store quantization and must be initialized before PS instructions are used.

### `__init_fprs` (0x80003334, internal to crt0.o)
1. Enables FPU by setting MSR[FP]
2. Checks HID2[LSQE] to see if paired singles are available
3. If PS available: loads zero from embedded constant, copies to all 32 PS registers via `ps_mr`
4. Loads double zero from embedded constant, copies to all 32 FPR registers via `fmr`
5. Clears FPSCR via `mtfsf 255, f0`

Embedded data between `__init_gqr` and `__init_fprs`:
- `0x80003328`: 8 bytes — double 0.0 (for `lfd`)
- `0x80003330`: 4 bytes — float 0.0 (for `psq_l`)

### `__init_args` (0x80003254, internal to crt0.o)
Parses command-line arguments from the BS2 area:
1. Reads DVD argument block pointer from `0x800000F4`
2. If present, reads argc and argv offset table
3. Relocates argv pointers from offsets to absolute addresses (base + offset)
4. Stores aligned argv base to ArenaLo (`0x80000034`)
5. Returns argc in r3, argv in r4

### `__check_pad3` (0x800032C0, internal to crt0.o)
Reads PAD status at `0x800030E4`. If button combo `0x0EEF` is fully held, calls `OSResetSystem(0, 0, 0)` to perform a hot reset. This is a development/debug feature.

### `__init_vm` / `__premain` (0x80003464, crt0.o)
Stub — just `blr`. Called twice by `__start`; exists as a hook point that could be overridden by the linker.

### `__init_hardware` (0x80003468, __ppc_eabi_init.o)
DolphinSDK hardware initialization:
1. Enables FPU (MSR[FP])
2. `__OSPSInit` — paired singles hardware init
3. `__OSFPRInit` — FPR register init (OS-level)
4. `__OSCacheInit` — instruction and data cache init

### `__flush_cache` (0x8000348C, __ppc_eabi_init.o)
Flushes data cache and invalidates instruction cache for a memory range. Used after writing code to memory (e.g., patching).
- Aligns start address down (mask `0xFFFFFFF1`)
- Loops: `dcbst` (flush D-cache), `sync`, `icbi` (invalidate I-cache), stride 8 bytes
- Final `isync` to synchronize instruction stream

## Key Memory Addresses

| Address | Purpose |
|---------|---------|
| `0x80000034` | ArenaLo — set to aligned argv base |
| `0x80000044` | ArenaHi — cleared to 0 during boot |
| `0x800000F4` | BS2 DVD argument block pointer |
| `0x800030E4` | PAD status word (for pad3 reset check) |
| `0x800030E6` | MEM1 arena flags |

## Source Files

| File | Contents |
|------|----------|
| `src/boot/crt0.s` | `__start`, `__init_gqr`, `__init_fprs`, `__init_args`, `__check_pad3`, `__init_vm`, `__premain` |
| `src/boot/__ppc_eabi_init.s` | `__init_hardware`, `__flush_cache` |

## Verification

All 960 bytes of `.init` section code have been verified to match the original ELF byte-for-byte (excluding linker relocations which are resolved at link time).
