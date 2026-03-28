# Contributing to The Sims 2 GameCube Decompilation

This guide covers everything you need to start contributing. The decompilation is complete (100% byte-matching DOL, 18,539 functions), so current work focuses on improving code quality, documentation, and the future PC port.

## Prerequisites

- [devkitPro](https://devkitpro.org/) with devkitPPC (GCC cross-compiler for PowerPC)
- [decomp-toolkit](https://github.com/encounter/decomp-toolkit) (`dtk`)
- [Python 3.10+](https://www.python.org/)
- [Ghidra](https://ghidra-sre.org/) (optional, for reverse engineering complex functions)
- A legally obtained copy of The Sims 2 (GameCube)

## Getting Started

```bash
# Clone the repo
git clone https://github.com/natebag/Sims2DECOMP.git
cd Sims2DECOMP

# Place your disc files (not included in repo)
# extracted/sys/main.dol          — the target binary
# extracted/files/u2_ngc_release_dvd.elf  — ELF with debug symbols
# extracted/files/u2_ngc_release.map      — symbol map (36,913 symbols)

# Build and verify
python tools/gen_skeleton.py   # Generate skeleton assembly from symbol map
make inject                    # Compile C++, inject matching bytes into DOL
make diff                      # Verify byte match against original DOL
make compile                   # Build decompiled C++ source objects
```

## How to Decompile a Function

### 1. Find the function

Use the symbol map (`extracted/files/u2_ngc_release.map`) to find the function you want to work on. The map contains every function name and address.

### 2. Disassemble it

```bash
python tools/disasm.py "ClassName::Method"
```

This shows the original PowerPC disassembly from the ELF.

### 3. Analyze the function

```bash
python tools/match_function.py "ClassName::Method"
```

This classifies the function difficulty and gives matching hints.

### 4. Write matching C++

Create or edit a file in `src/matched/` following the naming convention `ClassName_auto.cpp`. Write C++ that produces identical machine code to the original.

### 5. Verify the match

```bash
python tools/inject_matches.py --compile --rebuild --verify
```

This compiles your C++, injects it into the skeleton, and verifies byte-for-byte matching against the original DOL.

### 6. Submit a PR

If it matches, open a pull request. Include the function name, address, and size in the PR description.

## The Inject Pipeline

The build system uses a "skeleton + inject" approach:

1. `gen_skeleton.py` generates assembly files with labels for all 36,913 symbols
2. Original DOL bytes are injected into the skeleton at the correct addresses
3. Decompiled C++ functions replace the injected bytes when they match
4. The linker produces an ELF that is compared against the original DOL

This means the DOL always matches 100%, and individual functions can be progressively replaced with real C++ without breaking the build.

## Coding Standards

### Naming Conventions

All names come from the symbol map. Use them exactly as written.

| Element | Convention | Example |
|---------|-----------|---------|
| Classes | PascalCase | `ESim`, `ESimsCam`, `cXObject` |
| Member variables | `m_` prefix | `m_degRotAngDef`, `m_vEyeDef` |
| Constants | `k` prefix | `kNumTemp`, `kMaxWallShaders` |
| Static members | `s_` prefix | `s_fullAlphaValue`, `s_ambientDatabase` |
| Namespaces | Match original | `BBI`, `Effects`, `InteractorModule` |

### Compiler Flags

The original game was built with SN Systems ProDG (not CodeWarrior). We use devkitPPC (GCC) with flags tuned to match:

```
-mcpu=750 -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline
-fno-exceptions -fno-rtti -fno-builtin -fshort-wchar
```

Some functions require inline asm or register binding tricks to match. See `docs/register-matching-recipes.md` for patterns.

### File Organization

- One `.cpp` + `.h` pair per class/module
- `src/` mirrors the original source tree where known
- `include/classes/` for class headers (760 headers, 643 struct layouts documented)
- `src/matched/` for verified byte-matching implementations
- `src/decomp_cpp/` for portable C++ (PC port, not byte-matching)
- `src/asm_decomp/` for legacy inline asm stubs

### Code Style

- Follow the original EA code style visible in map symbols
- Use `// NON_MATCHING` comments when a function cannot match with GCC
- Use `// TODO:` for unknowns or assumptions
- Document struct layouts with field offsets (e.g., `// 0x528: m_name`)
- Every decompiled function should have an address comment: `// Address: 0x802D09DC | 128 bytes`

## Key Tools

| Tool | Purpose |
|------|---------|
| `tools/inject_all.py` | Inject all DOL bytes for 100% match |
| `tools/inject_matches.py` | Inject verified C++ matches into skeleton |
| `tools/disasm.py` | Disassemble any function from original ELF |
| `tools/match_function.py` | Classify function difficulty and suggest C++ |
| `tools/auto_match.py` | Auto-generate C++ for trivial functions (4-20 bytes) |
| `tools/compare_obj_vs_dol.py` | Compare compiled .o files against DOL |
| `tools/progress.py` | Track overall decomp progress |
| `tools/flag_sweep.py` | Test GCC flag combinations for matching |
| `tools/gen_headers.py` | Generate class declaration headers |
| `tools/gen_skeleton.py` | Generate skeleton assembly from symbols |

## What NOT To Do

- **Do not rename symbols.** The map file names are gospel. Use them exactly.
- **Do not break the byte match.** Every change must maintain 100% DOL matching. Run `make diff` before submitting.
- **Do not add features to matched code.** The `src/matched/` and `src/asm_decomp/` directories must produce identical output to the original. Feature work goes in `src/decomp_cpp/` (for the PC port).
- **Do not commit disc files.** The `extracted/` directory is not checked in. Contributors provide their own legally obtained copy.
- **Do not use CodeWarrior conventions.** This game was built with SN Systems ProDG, not CW. The calling conventions and ABI are different.

## Project Structure

```
src/              -- Decompiled C++ source (6,226 files)
  matched/        -- Auto-matched and verified C++ implementations
  decomp_cpp/     -- Portable C++ for PC port (not byte-matching)
  asm_decomp/     -- Legacy inline asm stubs (all converted)
  core/           -- Engine core, memory, math, strings
  sim/            -- Sim AI, CAS, behavior, state machines
  objects/        -- Game objects, slots, multi-tile objects
  ui/             -- APT UI engine, wrappers, targets
  render/         -- Renderer, shaders, models
  build_mode/     -- Build mode interactors
  audio/          -- Ambient score, sound events
  animation/      -- Animation controllers
  camera/         -- Camera system
  effects/        -- Frame effects (bloom, motion blur, DOF)
  save/           -- Memory card, save/load
  templates/      -- TArray and STL template instantiations
  libs/           -- DolphinSDK, SN runtime, C library stubs
include/          -- Shared headers (760 files)
config/           -- decomp-toolkit config, symbols, linker scripts
tools/            -- 70 Python scripts and build utilities
docs/             -- Documentation, system docs, progress tracking
extracted/        -- Raw disc extraction (not in repo)
build/            -- Build output (not in repo)
```

## Getting Help

- Read `docs/systems/` for documentation on each game system
- Check `docs/tracking/progress.md` for current status
- Look at existing decompiled functions in `src/decomp_cpp/` for patterns
- The original build log (`extracted/files/eorwb.log`, 8.8MB) contains compiler invocations and source file paths
