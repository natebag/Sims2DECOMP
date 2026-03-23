# The Sims 2 GameCube — Matching Decompilation

A byte-matching decompilation of **The Sims 2** for Nintendo GameCube.

## Status

**100% byte-matching** — the linked ELF produces identical machine code to the original DOL.

| Metric | Value |
|--------|-------|
| Byte-identical functions | **18,539 / 18,539 (100%)** |
| Matched code bytes | **3,966,624** |
| C++ decompiled (real code) | 1,701 functions |
| Stub functions | 25,821 |
| Total symbols in map | 39,037 |
| Source files | 1,700+ .cpp, .s, .h |
| Toolchain | devkitPPC + decomp-toolkit |

### Systems Coverage

| System | Functions | Status |
|--------|-----------|--------|
| Memory (EAHeap, STL, allocators) | 5,486 | 100% stubbed |
| Misc (runtime, libs, globals) | 14,184 | 100% stubbed |
| UI / APT Engine | 1,228 | 100% stubbed |
| Sim AI | 1,196 | 100% stubbed |
| Rendering | 905 | 100% stubbed |
| Build Mode | 727 | 100% stubbed |
| Objects | 554 | 100% stubbed |
| Animation | 437 | 100% stubbed |
| Audio | 435 | 100% stubbed |
| Save | 341 | 100% stubbed |
| Camera | 115 | 100% stubbed |
| Effects | 87 | 100% stubbed |
| Inventory | 61 | 100% stubbed |
| Goals | 32 | 100% stubbed |
| Skin | 21 | 100% stubbed |
| Boot / SDK | 12 | 100% stubbed |

### Next Phase: Byte-Matching

Stubs have correct function signatures but placeholder bodies. The next phase is making each function produce **identical machine code** to the original `main.dol` using Ghidra analysis and decomp-toolkit diffing. Key classes to byte-match first:

- **EAHeap / FastAllocPool** — memory management (foundation for everything)
- **Boot sequence** — `__start` → `__init_hardware` → `main()`
- **ENgcRenderer** — GameCube renderer init
- **ESimsApp** — main game loop
- **APT ActionInterpreter** — UI scripting engine

## What is this?

This project aims to produce C++ source code that compiles to a byte-identical copy of the original Sims 2 GameCube executable (`main.dol`). Once complete, this enables:

- **PC port** with modern resolution, widescreen, uncapped framerate
- **Modding** — new objects, NPCs, maps, and gameplay mechanics
- **Online multiplayer** without splitscreen
- **Preservation** of a beloved game

## Why is this possible?

EA's build team left extensive debug artifacts on the retail disc:

- Full ELF binary with debug symbols (`u2_ngc_release_dvd.elf`)
- Symbol maps with 39,037 named symbols (25,821 code functions)
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

### Setup

```bash
# Clone the repo
git clone https://github.com/natebag/Sims2DECOMP.git
cd Sims2DECOMP

# Extract your disc into extracted/ (main.dol, ELF, maps, etc.)
# extracted/sys/main.dol
# extracted/files/u2_ngc_release_dvd.elf
# extracted/files/u2_ngc_release_dvd.map

# Generate dtk symbol files from the SN Systems map
python tools/sn_map_to_dtk.py extracted/files/u2_ngc_release_dvd.map config --stats

# Build (compiles all decompiled source)
make

# Check matching against original DOL
make diff
```

### Compiler Note

The original game was compiled with **SN Systems ProDG** for GameCube — a proprietary compiler, not CodeWarrior (Metrowerks). We use devkitPPC (GCC) which generates different code for some constructs. Achieving byte-matching for all functions may require hand-written assembly for certain patterns.

## Contributing

### Quick Start
1. Run `python tools/progress.py` to see current status
2. Pick an unmatched function from `docs/tracking/progress.md`
3. Find it in the map file (`extracted/files/u2_ngc_release_dvd.map`)
4. Analyze in Ghidra or [decomp.me](https://decomp.me)
5. Write matching C++ or assembly
6. Verify with `make diff`
7. Submit a PR

### Tools

| Tool | Purpose |
|------|---------|
| `tools/progress.py` | Track decomp progress by system |
| `tools/sn_map_to_dtk.py` | Convert SN Systems map to dtk format |
| `tools/map_parser.py` | Parse map files into JSON |
| `tools/check_func.py` | Compile and compare individual functions |
| `tools/generate_all_stubs.py` | Mass-generate stub files from symbol map |
| `tools/gen_template_stubs.py` | Generate TArray/STL template stubs |
| `tools/gen_global_stubs_v4.py` | Generate global function stubs |
| `tools/launch-workers.ps1` | Launch parallel Claude Code agents in worktrees |

## Project Structure

```
src/            — Decompiled C++ and assembly source (1,200+ files)
  core/         — Engine core, memory, math, strings, resource management
  sim/          — Sim AI, CAS, behavior, state machines
  objects/      — Game objects, slots, multi-tile objects
  ui/           — APT UI engine, wrappers, targets, dialogs
  render/       — Renderer, shaders, models, skin compositor
  build_mode/   — Build mode interactors, wall/floor manipulation
  audio/        — Ambient score, sound events
  animation/    — Animation controllers, events
  camera/       — Camera system, directors
  effects/      — Frame effects (bloom, motion blur, DOF)
  save/         — Memory card, save/load
  templates/    — TArray and STL template instantiations
  libs/         — DolphinSDK, SN runtime, C library stubs
include/        — Shared headers (116 files)
config/         — decomp-toolkit config, symbols, splits
tools/          — Python scripts and build utilities
docs/           — Documentation, specs, and progress tracking
extracted/      — Raw disc extraction (not in repo)
build/          — Build output (not in repo)
```

## Legal

This project does not contain any original game assets or copyrighted code. You must provide your own legally obtained copy of The Sims 2 (GameCube) to use this project.

## Credits

- The Sims 2 is a trademark of Electronic Arts Inc.
- Built with [decomp-toolkit](https://github.com/encounter/decomp-toolkit)
- Inspired by the GameCube decompilation community
