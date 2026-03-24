# The Sims 2 GameCube — Matching Decompilation

A byte-matching decompilation of **The Sims 2** for Nintendo GameCube.

## Status

**100% byte-matching** — our build produces a byte-identical copy of the original 4.4MB DOL.

| Metric | Value |
|--------|-------|
| DOL byte match | **100.000%** (4,644,364 / 4,644,364 bytes) |
| Byte-identical functions | **18,539** |
| Portable C++ files | **5,012** (80.5% of source files) |
| Portable C++ lines | **~1,398,000** |
| Remaining asm stubs | **1,214 files** to convert for PC port |
| Class struct layouts | **643 classes** with documented fields |
| Header files | **760** |
| Total symbols in map | 36,913 |
| Source files | 6,226 .cpp + 760 .h |
| Tools | 70 Python scripts |
| Toolchain | devkitPPC (GCC 15.2) + decomp-toolkit |

### Portable C++ (PC Port Ready)

Real, portable C++ code converted from PPC assembly in `src/decomp_cpp/`:

| File | Lines | What |
|------|-------|------|
| `ui_system.cpp` | 3,260 | APT engine, 25+ opcodes, 12 UI targets, dialogs |
| `gameplay.cpp` | 2,532 | cXPersonImpl motives, SAnimator2, behavior trees, CAS genetics |
| `renderer.cpp` | 1,693 | ENgcRenderer, shaders, textures, models (with GX→OpenGL notes) |
| `esimsapp.cpp` | 911 | Main loop, init, shutdown, all update functions |
| `cxobjectimpl.cpp` | 732 | 77 game object functions, data system, EdithVariableSet |
| `eaheap.cpp` | 589 | Memory allocator, 3-tier allocation, heap hierarchy |

### Game Systems Documented

Every major system has a detailed decompilation file (`*_decomp.cpp`) with documented logic:

| System | Lines | Key Discoveries |
|--------|-------|-----------------|
| Animation (SAnimator2) | 3,062 | 9-state machine, blend trees, 5 follow modes |
| Build Mode (InteractorModule) | 2,523 | Wall/floor/object manipulation, 13-bit state flags |
| Sim Character (cXPersonImpl) | 2,058 | 7-motive happiness, action queue, death detection |
| Skin Compositor | 1,796 | Bone transforms, clothing layers, texture compositing |
| Renderer (ENgcRenderer) | 1,800 | 75-entry opcode table, 21 GX→OpenGL translation notes |
| Inventory + Goals | 1,722 | Wants/fears, aspiration system, unlock progression |
| Math/Utils | 1,627 | EVec3, EMat4, CTilePt isometric system, EController |
| EGlobal + Config | 1,719 | 211-field global state, cheats, options save/load |
| State Machine | 1,629 | Game flow: title→neighborhood→lot→live mode |
| Behavior Trees | 1,606 | BHAV execution, primitives, TreeSim stack frames |
| Particles + Lighting | 1,620 | Emitters, light grid, 5 light types, room evaluation |
| Resources + Shaders | 1,596 | Resource refcounting, TEV stages, texture management |
| Asset Loading | 1,571 | .ARC format, .NGH format, RefPack, async DVD loader |
| UI Targets | 1,495 | 16 dialog controllers, HUD, screen navigation |
| Containers/Strings | 1,475 | EString, BString, EHashTable, ERedBlackTree, TArray |
| Main Loop (ESimsApp) | 1,373 | 8-step update, 24-step init, 3 state machines |
| World/Rooms (ERLevel) | 1,324 | Tile grid, room detection, wall/floor rendering |
| Objects (cXObjectImpl) | 1,223 | EdithVariableSet, data indices, 146 fields |
| APT UI Engine | 1,206 | 100 SWF opcodes, EA extensions, hybrid GC |
| CAS (Create-A-Sim) | 1,183 | Genetics blending, body parts, clothing cascade |
| Neighborhood | 1,014 | .NGH save tags, families, lot management |
| Save System | 929 | Memory card format, checksum, async save/load |
| Effects | 910 | Bloom, DOF, motion blur pipeline |
| Camera | 902 | 9-state director, rubber-band interpolation |
| EAHeap | 821 | 3-tier allocation, DESU/EERF magic, 13 heaps |
| Audio | 708 | Ambient scores, 64-voice mixer, ARAM heap |
| FastAllocPool | 613 | Binary search tree init order, pool validation |

### How the Pipeline Works

```bash
python tools/gen_skeleton.py   # Generate skeleton assembly from symbol map
make inject                    # Compile C++, inject matching bytes + DOL data → 100% match
make diff                      # Verify against original DOL with decomp-toolkit
make compile                   # Build decompiled C++ source objects (for verification)
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

# Generate skeleton + inject matching bytes → 100% DOL match
python tools/gen_skeleton.py
make inject

# Verify against original DOL
make diff

# Compile decompiled C++ source (for verification)
make compile
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
