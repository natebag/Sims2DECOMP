# The Sims 2 GameCube — Matching Decompilation

A work-in-progress byte-matching decompilation of **The Sims 2** for Nintendo GameCube (G4ZE69).

## Status

**~27% decompiled.** Functions are being matched one at a time — hand-written C++ that compiles to byte-identical PPC output, verified against the original DOL.

| Metric | Value |
|--------|-------|
| **Functions matched** | **~5,600 / 20,508 (27.3%)** |
| Functions remaining | ~14,900 |
| Total symbols in map | 39,169 |
| Class struct layouts | 643 documented |
| Toolchain | devkitPPC (GCC) + decomp-toolkit |

**How matching works:** Every matched function has C++ source code that, when compiled with devkitPPC, produces the exact same bytes as the original game binary. No byte injection, no copying — real compiled C++ output matching the original.

## What's Done

- **Build pipeline** — devkitPPC toolchain, decomp-toolkit config, CI verification
- **Symbol map** — All 39,169 symbols from the disc imported and mapped
- **Struct layouts** — 643 classes with documented field offsets from assembly analysis
- **Trivial functions** — ~1,650 matched via automated batch script (getters, setters, empty functions)
- **AI agent matches** — ~3,950 matched via parallel Claude Code + OpenAI agents
- **Verification tools** — `verify_match.sh` for end-to-end compile-and-compare

## What's Not Done

- **~14,900 functions** still need matching (the other 73%)
- **Complex functions** — large functions with control flow, vtable dispatch, floating-point math
- **GCC vs SN Systems gaps** — the original compiler (SN Systems ProDG) differs from GCC in register allocation, instruction scheduling, and prologue/epilogue generation. ~47% of functions match directly; the rest need workaround patterns
- **PC port** — a prototype exists but is blocked until real decomp progress is further along

## Building

### Prerequisites

- devkitPro with devkitPPC
- decomp-toolkit (`dtk`)
- Python 3.10+
- A legally obtained copy of The Sims 2 (GameCube)

### Quick Start

```bash
git clone https://github.com/natebag/Sims2DECOMP.git
cd Sims2DECOMP

# Place your disc files:
#   extracted/sys/main.dol
#   extracted/files/u2_ngc_release_dvd.elf
#   extracted/files/u2_ngc_release_dvd.map

# Build and verify
python tools/gen_skeleton.py
make inject
make diff
```

### Compiler Note

The original game was compiled with **SN Systems ProDG** for GameCube — a proprietary compiler, not CodeWarrior. We use devkitPPC (GCC) with flags tuned to match:

```
-mcpu=750 -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline
```

Some functions need inline asm or register-binding tricks to match due to compiler differences.

## Contributing

### Matching a Function

```bash
# 1. Find an unmatched function
python tools/extract_function.py --name "FunctionName"

# 2. Write matching C++ in src/matched/
#    (see existing matches for patterns)

# 3. Verify it matches
bash tools/verify_match.sh src/matched/your_file.cpp 0xADDRESS SIZE

# 4. If MATCH — commit and PR. If not — iterate.
```

### Automated Matching

```bash
# Batch match trivial functions (getters/setters/empty)
python tools/batch_match_trivial.py --verify

# AI-assisted matching via API
python tools/decomp_agent.py --api openai --key YOUR_KEY --count 100
```

### Key Tools

| Tool | Purpose |
|------|---------|
| `tools/extract_function.py` | Disassemble any function from the DOL |
| `tools/verify_match.sh` | Compile C++ and verify bytes match DOL |
| `tools/batch_match_trivial.py` | Auto-match trivial 4-20 byte functions |
| `tools/decomp_agent.py` | AI-powered matching via Claude/OpenAI APIs |
| `tools/gen_skeleton.py` | Generate skeleton assembly from symbols |
| `tools/inject_matches.py` | Inject verified matches into build |

## Why This Game?

EA's build team left extensive debug artifacts on the retail disc:

- **Full ELF** with debug symbols (`u2_ngc_release_dvd.elf`)
- **Symbol maps** with 39,169 named symbols
- **Build logs** (`eorwb.log`, 8.8MB)
- **Version headers** — Build `F.09.12.0` (Gold Master, September 12, 2005)

This gives us every function name, class name, and variable name — dramatically reducing the RE effort.

## Project Structure

```
src/matched/       — Verified byte-matching C++ implementations
src/asm_decomp/    — Original PPC assembly (reference)
src/core/          — Annotated pseudocode for key systems
include/classes/   — Class headers with struct layouts
config/            — decomp-toolkit config, symbols, linker scripts
tools/             — Python scripts for matching and verification
docs/              — Documentation and progress tracking
extracted/         — Disc files (not in repo — you provide these)
```

## Legal

This project does not contain any original game assets or copyrighted code. You must provide your own legally obtained copy of The Sims 2 (GameCube).

## Credits

- The Sims 2 is a trademark of Electronic Arts Inc.
- Built with [decomp-toolkit](https://github.com/encounter/decomp-toolkit)
- Inspired by the GameCube decompilation community
