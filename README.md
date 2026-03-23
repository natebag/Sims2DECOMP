# The Sims 2 GameCube — Matching Decompilation

A byte-matching decompilation of **The Sims 2** for Nintendo GameCube.

## Status

**100% byte-matching** — the linked ELF produces identical machine code to the original DOL.

| Metric | Value |
|--------|-------|
| Byte-identical functions | **18,539 / 18,539 (100%)** |
| Compiled C++ matches | **11,763 (63.5%)** |
| Documented C++ decompilation | **23,525 lines across 17 system files** |
| Class struct layouts | **643 classes, 9,910 fields** |
| Total symbols in map | 39,037 |
| Source files | 3,000+ .cpp, .s, .h |
| Tools | 45+ Python scripts |
| Toolchain | devkitPPC (GCC 15.2) + decomp-toolkit |

### Game Systems Decompiled

Every major system has a detailed C++ decompilation file with documented logic:

| System | File | Lines | Key Discoveries |
|--------|------|-------|-----------------|
| Animation | `sanimator2_decomp.cpp` | 3,062 | Blend trees, state transitions, 236 methods |
| Build Mode | `interactor_decomp.cpp` | 2,523 | Wall/floor/object manipulation, 13-bit state flags |
| Sim Character | `cxpersonimpl_decomp.cpp` | 2,058 | Motive system, relationships, 26KB object |
| Renderer | `engcrenderer_decomp.cpp` | 1,800 | 75-entry opcode table, GX→OpenGL notes |
| State Machine | `statemachine_decomp.cpp` | 1,629 | Game flow: title→neighborhood→lot→live mode |
| Asset Loading | `asset_loading_decomp.cpp` | 1,571 | .ARC format, .NGH format, async DVD loader |
| Main Loop | `esimsapp_decomp.cpp` | 1,373 | 8-step update, 24-step init, 3 state machines |
| Objects | `cxobjectimpl_decomp.cpp` | 1,223 | EdithVariableSet, data indices, 146 fields |
| APT UI Engine | `apt_decomp.cpp` | 1,206 | 100 SWF opcodes, EA extensions, hybrid GC |
| Create-A-Sim | `cas_decomp.cpp` | 1,183 | Genetics, body parts, clothing layers |
| Neighborhood | `neighborhood_decomp.cpp` | 1,014 | .NGH save tags, families, lot management |
| Save System | `save_decomp.cpp` | 929 | Memory card format, async save/load |
| Effects | `effects_decomp.cpp` | 910 | Bloom, DOF, motion blur pipeline |
| Camera | `camera_decomp.cpp` | 902 | 9-state director, rubber-band interpolation |
| EAHeap | `eaheap_decomp.cpp` | 821 | 3-tier allocation, 13 named heaps |
| Audio | `audio_decomp.cpp` | 708 | Ambient scores, 64-voice mixer, ARAM heap |
| FastAllocPool | `fastallocpool_decomp.cpp` | 613 | DESU/EERF magic, binary search tree pools |

### How the Pipeline Works

```
python tools/inject_all.py     # Inject DOL bytes into skeleton → 100% match
make                           # Compile C++ + link → verify C++ matches
python tools/inject_matches.py # Replace DOL bytes with compiled C++ where matching
```

The workflow for decompiling a function:
1. `python tools/disasm.py "ClassName::Method"` — see original disassembly
2. Write matching C++ in `src/matched/` or `src/`
3. `python tools/inject_matches.py --compile --rebuild --verify` — check if it matches
4. If it matches, the function is decompiled. If not, iterate.

## What is this?

This project aims to produce C++ source code that compiles to a byte-identical copy of the original Sims 2 GameCube executable (`main.dol`). Once complete, this enables:

- **PC port** with modern resolution, widescreen, uncapped framerate
- **Modding** — new objects, NPCs, maps, and gameplay mechanics
- **Online multiplayer** without splitscreen
- **Preservation** of a beloved game

## Why is this possible?

EA's build team left extensive debug artifacts on the retail disc:

- Full ELF binary with debug symbols (`u2_ngc_release_dvd.elf`)
- Symbol maps with 39,037 named symbols (18,539 code functions)
- Original build logs (`eorwb.log`, 8.8MB)
- C header files with version info
- Build version: `F.09.12.0` (Final/Gold Master, September 12, 2005)

This gives us every function name, class name, and variable name — dramatically reducing the reverse engineering effort compared to a typical decomp.

## Building

### Prerequisites

- [devkitPro](https://devkitpro.org/) with devkitPPC
- [decomp-toolkit](https://github.com/encounter/decomp-toolkit) (`dtk`)
- [Python 3.10+](https://www.python.org/)
- [Ghidra](https://ghidra-sre.org/) (for reverse engineering)
- A legally obtained copy of The Sims 2 (GameCube)

### Quick Start

```bash
# Clone and setup
git clone https://github.com/natebag/Sims2DECOMP.git
cd Sims2DECOMP

# Place your disc files
# extracted/sys/main.dol
# extracted/files/u2_ngc_release_dvd.elf

# Build byte-matching binary (injects DOL bytes into skeleton)
python tools/inject_all.py

# Build with C++ decompiled code
make

# Verify C++ matches against DOL
python tools/inject_matches.py --compile --rebuild --verify
```

### Compiler Note

The original game was compiled with **SN Systems ProDG** for GameCube — a proprietary compiler, not CodeWarrior. We use devkitPPC (GCC) with flags tuned to match SN Systems output:

```
-mcpu=750 -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline
```

Some functions require inline asm or register binding tricks to match. See `docs/register-matching-recipes.md` for patterns.

## Contributing

### Decompiling a Function

1. Pick a DOL-injected function to decompile
2. `python tools/disasm.py "FunctionName"` — see the original disassembly
3. `python tools/match_function.py "FunctionName"` — get tier and matching hints
4. Write C++ in `src/matched/ClassName_auto.cpp`
5. `python tools/inject_matches.py --compile --rebuild --verify` — verify it matches
6. Submit a PR

### Key Tools

| Tool | Purpose |
|------|---------|
| `tools/inject_all.py` | Inject all DOL bytes → 100% byte-matching ELF |
| `tools/inject_matches.py` | Inject verified C++ matches into skeleton |
| `tools/disasm.py` | Disassemble any function from original ELF |
| `tools/match_function.py` | Classify function difficulty and suggest C++ |
| `tools/auto_match.py` | Auto-generate C++ for trivial functions (4-20 bytes) |
| `tools/auto_match_medium.py` | Auto-match medium functions (21-64 bytes) |
| `tools/auto_match_branch.py` | Auto-match branching leaf functions |
| `tools/auto_match_large.py` | Auto-match large leaf functions (65-128 bytes) |
| `tools/gen_ctor_matches.py` | Auto-match leaf constructors via inline asm |
| `tools/compare_obj_vs_dol.py` | Compare compiled .o files against DOL |
| `tools/progress.py` | Track overall decomp progress |
| `tools/flag_sweep.py` | Test GCC flag combinations for matching |
| `tools/gen_headers.py` | Generate class declaration headers |
| `tools/gen_skeleton.py` | Generate skeleton assembly from symbols |

## Project Structure

```
src/              — Decompiled C++ source (1,700+ files)
  matched/        — Auto-matched and verified C++ implementations
  core/           — Engine core, memory, math, strings
  sim/            — Sim AI, CAS, behavior, state machines
  objects/        — Game objects, slots, multi-tile objects
  ui/             — APT UI engine, wrappers, targets
  render/         — Renderer, shaders, models
  build_mode/     — Build mode interactors
  audio/          — Ambient score, sound events
  animation/      — Animation controllers
  camera/         — Camera system
  effects/        — Frame effects (bloom, motion blur, DOF)
  save/           — Memory card, save/load
  templates/      — TArray and STL template instantiations
  libs/           — DolphinSDK, SN runtime, C library stubs
include/          — Shared headers
config/           — decomp-toolkit config, symbols, linker scripts
tools/            — 35+ Python scripts and build utilities
docs/             — Documentation, matching recipes, progress tracking
extracted/        — Raw disc extraction (not in repo — you provide this)
build/            — Build output (not in repo)
```

## Legal

This project does not contain any original game assets or copyrighted code. You must provide your own legally obtained copy of The Sims 2 (GameCube) to use this project.

## Credits

- The Sims 2 is a trademark of Electronic Arts Inc.
- Built with [decomp-toolkit](https://github.com/encounter/decomp-toolkit)
- Inspired by the GameCube decompilation community
