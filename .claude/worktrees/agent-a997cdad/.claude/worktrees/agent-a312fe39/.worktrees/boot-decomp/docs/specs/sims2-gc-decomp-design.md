# Sims 2 GameCube — Matching Decompilation Design Spec

**Date:** 2026-03-21
**Status:** Approved
**Goal:** Produce a byte-matching C++ decompilation of The Sims 2 (GameCube), enabling a PC port, modding, and community contributions.

## Background

The Sims 2 GameCube (Game ID: G4ZE69) was built by EA on September 12, 2005 using SN Systems ProDG for GameCube. The retail disc contains extensive debug artifacts:

- **ELF with debug symbols** (`u2_ngc_release_dvd.elf`, 4.4MB)
- **Release symbol map** (`u2_ngc_release.map`, 39,169 named symbols)
- **Debug symbol map** (`u2_ngc_debug.map`, additional debug info)
- **C header file** (`version.h`, build version definitions)
- **Full build log** (`eorwb.log`, 8.8MB)

This is exceptionally rare for a retail GameCube game and dramatically accelerates the decomp process.

## Architecture

### Original Build Environment
- **Compiler:** SN Systems ProDG NGC (SN-NGC)
- **SDK:** DolphinSDK 1.0 HW2
- **Build system:** EA's CM3 automated builder
- **Source tree:** `c:\BuildAgent\cm3-build25-NGC\CMBuild\`
- **Platform:** Cross-platform (PS2, Xbox, GameCube, Windows shared codebase)

### Decomp Build Environment
- **Compiler:** devkitPPC (GCC for PowerPC — may need SN Systems compat flags)
- **Toolkit:** decomp-toolkit (`dtk`) for DOL splitting, linking, and verification
- **Verification:** Byte-level comparison of compiled output vs original DOL
- **RE Tool:** Ghidra with PowerPC/Gekko processor module

### Key Technical Challenges
1. **Compiler differences:** Original used SN Systems, we use GCC. Some functions may need compiler-specific intrinsics or pragma workarounds.
2. **Inline assembly:** GC games often have PPC assembly for performance-critical code.
3. **C++ ABI:** SN Systems may have a different C++ ABI (vtable layout, name mangling) than GCC — needs investigation.
4. **Library code:** APT UI engine, DolphinSDK, and SN runtime are precompiled libraries. May need stubs or separate decomp.

## Major Game Systems

### Boot & Initialization
- `__start` → `__init_hardware` → `__premain` → `main()`
- SN Systems crt0 initializes hardware, sets up stack, calls constructors
- DolphinSDK `os.a` handles GC hardware init

### Memory Management
- `EAHeap` — EA's custom heap allocator with small object counters
- `FastAllocPool` — Pool allocator with alignment support
- These underpin every other system

### Main Game Loop
- Standard init → update → render cycle
- Frame effects pipeline (bloom, motion blur, DOF)
- Game state management

### Sim AI (`ESim`)
- Core Sim class hierarchy
- CAS (Create-A-Sim) system with `CASTarget`
- Sim behavior and interaction system

### Object System (`cXObject`)
- Base object class with data management (`kNumTemp`, `kNumData`)
- Multi-tile object support (`ISimsMultiTileObjectModel`)
- Object interaction framework

### Build Mode
- `InteractorModule::WallManipulator` — wall placement/manipulation
- Wall shader system (`kMaxWallShaders`)
- Validation states (valid, invalid, sell, fence)

### UI — APT Engine
- Full ActionScript-based UI system (43 source files)
- Action interpreter, animation, character instances
- XML-based layout with rendering context
- This is a standalone library (`libaptz.a`) — may be shared across EA games

### Rendering
- `ENgcRenderer` — GameCube-specific renderer
- Frame effects: bloom, motion blur, depth of field
- Shader system
- Skin compositor for character rendering

### Audio
- `AmbientScorePlayer` with ambient database
- Sound event system

### Inventory & Goals
- `BBI::InventoryItems` — category-based inventory with GUID lookup
- `GoalUnlock` — goal/unlock variable system

### Save System
- `SimsMemCardWrap` — GameCube memory card interface

## Decomp Strategy

### Approach: Bottom-Up Matching
1. Start with boot code (smallest, most self-contained)
2. Build up through core systems (memory, main loop)
3. Tackle gameplay systems with core dependencies satisfied
4. Finish with presentation layer (UI, audio, effects)

### Function Workflow
For each function:
1. Find symbol in map file (address, size, source file)
2. Load disassembly in Ghidra
3. Analyze control flow, identify types, understand logic
4. Write C++ that compiles to matching PPC assembly
5. Verify with `dtk elf diff`
6. If non-matching, iterate or mark `// NON_MATCHING` with notes
7. Update progress tracker

### Verification
- Every function verified against original DOL byte-for-byte
- decomp-toolkit handles comparison
- CI pipeline (future) runs verification on every commit

## Data Flow

```
u2_ngc_release.map  →  map_parser.py  →  symbols.json
                                              ↓
main.dol  →  decomp-toolkit  →  split objects  →  per-function verification
                                              ↑
u2_ngc_release_dvd.elf  →  Ghidra  →  decompiled C++  →  devkitPPC  →  compiled objects
```

## Community & Contribution Model

### Repository Structure
- Public GitHub repo (once initial framework is solid)
- decomp.me integration for collaborative function matching
- Discord server for coordination
- CONTRIBUTING.md with clear onboarding guide

### Contributor Workflow
1. Pick an unmatched function from the tracker
2. Analyze in Ghidra or decomp.me
3. Write matching C++
4. Submit PR with verification proof
5. Reviewer checks matching + code quality

## Long-Term Vision

### PC Port (Milestone 6)
- Abstract GC hardware calls behind platform interface
- Replace GX rendering with OpenGL/Vulkan
- Replace GC input with keyboard/mouse/controller
- Widescreen, high-res, uncapped framerate

### Modding
- Asset loading from filesystem (bypass .arc archives)
- Mod manifest system
- New objects, NPCs, maps, UI elements
- Scripting system for custom behaviors

### Online Multiplayer
- Network state synchronization
- No splitscreen — each player gets full screen
- Host-authoritative game state
- Lobby/matchmaking system
