# The Sims 2 GameCube — Matching Decompilation

A byte-matching decompilation of **The Sims 2** for Nintendo GameCube.

## Status

**Milestone 2: CORE SYSTEMS** — Active decompilation in progress across all major systems.

| Metric | Value |
|--------|-------|
| Functions decompiled | 16,292 / 31,776 |
| Progress | **51.3%** |
| Symbols identified | 23,068 |
| Struct layouts recovered | 50+ classes |
| Source files | 100+ .cpp / .s |
| Toolchain | devkitPPC + decomp-toolkit |

### Systems Covered

| System | Status | Key Classes |
|--------|--------|-------------|
| Boot / SDK Runtime | Done | __start, libgcc, libm, libc |
| DolphinSDK (OS/HW) | 912 functions | OS, DVD, GX, VI, PAD, AI, EXI, MTX |
| EA Base Engine | In progress | EString, EVec3, EAHeap, FastAllocPool, EHashTable |
| Sim AI | In progress | Person, Neighbor, Family, Behavior, Interaction |
| Objects | In progress | cXObject, IObject, Slots, ObjDefinition |
| UI / APT Engine | In progress | Wrapper, AptValue, AptCharacter, AptAction |
| Rendering | In progress | ERC, EShader, EGraphics, ENgcRenderer, Lighting |
| Camera | In progress | ESimsCam, CameraDirector, CameraMotion |
| Build Mode | In progress | Interactor, WallManipulator, FloorPainter |
| Audio / Save | In progress | AmbientScore, GameSound, SimsMemCardWrap |
| State Machine | In progress | StateMachine, GameState, TheSims, LiveMode |

## What is this?

This project aims to produce C++ source code that compiles to a byte-identical copy of the original Sims 2 GameCube executable (`main.dol`). Once complete, this enables:

- **PC port** with modern resolution, widescreen, uncapped framerate
- **Modding** — new objects, NPCs, maps, and gameplay mechanics
- **Online multiplayer** without splitscreen
- **Preservation** of a beloved game

## Why is this possible?

EA's build team left extensive debug artifacts on the retail disc:

- Full ELF binary with debug symbols (`u2_ngc_release_dvd.elf`)
- Symbol maps with 23,068 named symbols (18,547 functions)
- Original build logs
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
1. Pick an unmatched function from `docs/tracking/progress.md`
2. Find it in the map file (`extracted/files/u2_ngc_release_dvd.map`)
3. Analyze in Ghidra or [decomp.me](https://decomp.me)
4. Write matching C++ or assembly
5. Verify with `make diff`
6. Submit a PR

### Tools

| Tool | Purpose |
|------|---------|
| `tools/sn_map_to_dtk.py` | Convert SN Systems map to dtk format |
| `tools/map_parser.py` | Parse map files into JSON |
| `tools/check_func.py` | Compile and compare individual functions |
| `tools/launch-workers.ps1` | Launch parallel Claude Code agents in worktrees |

## Project Structure

```
src/          — Decompiled C++ and assembly source code
include/      — Shared headers
libs/         — External library stubs (APT, DolphinSDK, SN runtime)
config/       — decomp-toolkit config, symbols, splits
tools/        — Python scripts and build utilities
docs/         — Documentation, specs, and progress tracking
extracted/    — Raw disc extraction (not in repo)
build/        — Build output (not in repo)
```

## Legal

This project does not contain any original game assets or copyrighted code. You must provide your own legally obtained copy of The Sims 2 (GameCube) to use this project.

## Credits

- The Sims 2 is a trademark of Electronic Arts Inc.
- Built with [decomp-toolkit](https://github.com/encounter/decomp-toolkit)
- Inspired by the GameCube decompilation community
