# Sims 2 GameCube Decompilation — Project Rules

Project-specific rules for the Sims 2 GC matching decomp. Universal rules are in `~/.claude/CLAUDE.md`.

## Agent Delegation

Use these agents proactively — don't wait to be asked:

| Trigger | Agent | Why |
|---------|-------|-----|
| New function to decompile | `decomp-planner` | Analyzes symbol in map file, checks Ghidra disassembly, identifies dependencies, produces decomp plan |
| PPC compilation errors | `cpp-build-resolver` | Fixes SN Systems / devkitPPC compiler issues, linker errors, missing symbols |
| After writing C++ code | `cpp-reviewer` | Checks matching conventions, naming from map file, verifies no UB |
| Exploring unknown code in Ghidra | `ghidra-analyst` | Deep-dives disassembly, identifies patterns, documents structs |
| Asset format RE | `format-analyst` | Reverse engineers .arc, .NGH, .tpl file formats |

Spawn multiple agents in parallel when a task has independent parts.

## Build Roadmap

Use `/work` to pick up the next task. Full design doc: `docs/specs/sims2-gc-decomp-design.md`

### Prioritization Principles
1. **Foundation before features** — build toolchain and boot first, gameplay systems after
2. **Matching over speed** — every function must byte-match the original DOL
3. **Document as you go** — every decompiled system gets a doc in `docs/systems/`
4. **Symbols are gospel** — use the map file names exactly, don't rename
5. **One system fully matched beats three half-done**
6. **Community-ready** — structure the repo so contributors can pick up any function

### Lane Rules
- Pick **one lane** within the current milestone
- Higher priority lanes should be staffed first
- Work tasks top to bottom within a lane
- **"Not Yet" items must not be worked on**
- New discoveries: current milestone? Add it. Future milestone? Slot it. Neither? Icebox.

### Milestone 1: FOUNDATION — DONE

**Goal:** Toolchain compiles a DOL. All 39K symbols imported and organized. Boot sequence decompiled and matching. Map parser and progress tracker working.

**Gate Criteria:**
- [x] devkitPPC / SN Systems toolchain builds a valid GC DOL
- [x] decomp-toolkit project config (direct compile+diff workflow)
- [x] Symbol map parser extracts all symbols into structured data
- [x] Symbols imported into Ghidra project with correct names and types *(deferred — inject pipeline replaced this need)*
- [x] ELF debug info fully loaded in Ghidra *(deferred — inject pipeline replaced this need)*
- [x] Boot sequence (`__start` → `__init_hardware`) decompiled and matching (asm stubs injected)
- [x] Build system produces byte-matching DOL (100% — 4,644,364 / 4,644,364 bytes)
- [x] Progress tracker reports % of functions/bytes matched
- [x] `docs/systems/boot-sequence.md` written
- [x] `docs/systems/build-system.md` written
- [x] Project README written for future contributors

**Note:** Ghidra gates deferred — the inject pipeline + map file workflow made Ghidra
optional for matching. Can revisit if needed for understanding complex functions.

### Milestone 2: PORTABLE C++ CONVERSION — NEARLY DONE

**Goal:** Convert all 1,214 remaining asm stub files (~1.18M lines) to portable C++ that
compiles on both PPC (byte-matching) and x86 (future PC port). This is the real decomp work.

**Primary Metric:** 100% of asm stubs converted (1,214/1,214). ~55% by line count, 81% by files.

**Gate Criteria:**
- [x] 90%+ of asm stubs converted to portable C++ by file count (100% — all 1,214)
- [x] All "big fish" files (>5,000 lines) converted (all 29 done, including global.cpp)
- [ ] Converted code compiles clean with `make compile`
- [x] 100% DOL byte match maintained throughout
- [x] Per-system conversion tracking updated in progress.md

**Remaining:** Verify `make compile` succeeds, then mark DONE. PC x86 build in progress separately.

**Big Fish — ALL DONE (2026-03-27):**

All 29 Big Fish files (>5K lines) converted to portable C++, including
global.cpp (230K lines, 1,970 functions — the final boss).
See `docs/tracking/progress.md` for session log with details.

**Not Yet:** Gameplay logic deep-dives, PC port platform abstraction, modding

### Milestone 3: CORE SYSTEMS

**Goal:** Memory allocator, main game loop, asset loading pipeline, and rendering init all decompiled and matching. The "skeleton" the entire game runs on.

**Gate Criteria:**
- [ ] EAHeap / memory management fully decompiled and matching
- [ ] FastAllocPool decompiled
- [ ] Main game loop decompiled (init → update → render cycle)
- [ ] .arc archive loader decompiled (can extract game assets)
- [ ] ENgcRenderer initialization decompiled
- [ ] DolphinSDK wrapper functions decompiled
- [ ] basic_string and STL containers decompiled
- [ ] 20%+ of total functions matching
- [ ] All core system docs written

**Lanes:** Memory Management > Main Loop > Asset Loading > Renderer Init > SDK Wrappers

**Not Yet:** Sim AI, build mode, UI, audio, gameplay, objects, save system

### Milestone 4: GAMEPLAY SYSTEMS

**Goal:** All Sims 2 gameplay logic decompiled. Sims, objects, build mode, inventory, goals — the actual "game."

**Gate Criteria:**
- [ ] ESim class hierarchy fully decompiled
- [ ] cXObject system decompiled
- [ ] ISimsMultiTileObjectModel decompiled
- [ ] CAS (Create-A-Sim) system decompiled
- [ ] InteractorModule / WallManipulator (build mode) decompiled
- [ ] BBI::InventoryItems decompiled
- [ ] GoalUnlock system decompiled
- [ ] 50%+ of total functions matching

**Lanes:** Sim AI > Object System > Build Mode > Inventory & Goals > Interactions

**Not Yet:** UI, audio, effects, save, PC port, modding

### Milestone 5: PRESENTATION & POLISH

**Goal:** UI (APT), audio, camera, visual effects, skin compositor, and save system all decompiled.

**Gate Criteria:**
- [ ] Full APT UI engine decompiled (ActionScript interpreter, rendering, input)
- [ ] AmbientScorePlayer / audio system decompiled
- [ ] ESimsCam camera system decompiled
- [ ] FrameEffects (bloom, motion blur, DOF) decompiled
- [ ] SkinCompositor decompiled
- [ ] SimsMemCardWrap save system decompiled
- [ ] 90%+ of total functions matching

**Lanes:** APT/UI Engine > Audio > Camera & Effects > Save System > Skin Compositor

**Not Yet:** PC port, modding, online multiplayer

### Milestone 6: FULL MATCH

**Goal:** 100% matching decomp. Every function verified. Clean, documented, contributor-ready codebase.

**Gate Criteria:**
- [ ] 100% of functions matching byte-for-byte
- [ ] All remaining library code (SN runtime, DolphinSDK) stubbed or decompiled
- [ ] Full CI pipeline verifying matching on every commit
- [ ] Complete contributor documentation
- [ ] Community-ready GitHub release

**Lanes:** All converge — work on whatever's closest to failing the gate.

### Milestone 7: PC PORT & MODS

**Goal:** Platform abstraction layer, PC rendering backend, mod loading. The dream.

**Gate Criteria:**
- [ ] Platform abstraction layer (GC graphics → OpenGL/Vulkan)
- [ ] PC input system (keyboard/mouse/controller)
- [ ] Widescreen and high-res support
- [ ] Mod loading system (custom assets, scripts)
- [ ] Online multiplayer framework
- [ ] 60+ FPS on modern hardware

**Lanes:** Platform Abstraction > PC Renderer > Input & Resolution > Mod System > Online

### Icebox (Future)
Online multiplayer (no splitscreen), custom neighborhoods, new NPCs, Steam Workshop integration, mobile port, VR support, cross-platform multiplayer

## Build Info (from disc)

- **Game:** The Sims 2 (GameCube) — Game ID: `G4ZE69`
- **Build date:** September 12, 2005
- **Build version:** `F.09.12.0` (Final / Gold Master)
- **Build machine:** `CM3-BUILD25` by `codebuilder`
- **Compiler:** SN Systems ProDG for GameCube (SN-NGC)
- **SDK:** DolphinSDK 1.0 HW2
- **Source tree root:** `c:\BuildAgent\cm3-build25-NGC\CMBuild\`
- **Cross-platform:** Shared codebase with PS2, Xbox, and Windows builds

## Key Files on Disc

| File | What It Is |
|------|-----------|
| `sys/main.dol` | Main executable (4.4MB) — the target to match |
| `files/u2_ngc_release_dvd.elf` | ELF with debug symbols (4.4MB) |
| `files/u2_ngc_release.map` | Release symbol map — 39,169 named symbols |
| `files/u2_ngc_debug.map` | Debug symbol map — even more detail |
| `files/version.h` | C header with build version info |
| `files/DATA/*.arc` | Game asset archives (~1.2GB total) |
| `files/*.NGH` | Unknown format — needs RE |
| `files/eorwb.log` | Full 8.8MB build log |

## Decomp Conventions

### Matching Rules
- Every decompiled function MUST produce byte-identical output to the original DOL
- Use `decomp-toolkit` to verify matching (`dtk elf diff`)
- Non-matching code gets a `// NON_MATCHING` comment with explanation
- Use the **exact** symbol names from the map file — no renaming

### C++ Style
- Follow the original EA code style visible in the map symbols
- Class names: PascalCase (`ESim`, `ESimsCam`, `cXObject`)
- Member variables: `m_` prefix (`m_degRotAngDef`, `m_vEyeDef`)
- Constants: `k` prefix (`kNumTemp`, `kMaxWallShaders`)
- Static members: `s_` prefix (`s_fullAlphaValue`, `s_ambientDatabase`)
- Namespaces: match original (`BBI`, `Effects`, `InteractorModule`)

### File Organization
- One `.cpp` + `.h` pair per class/module (matching original source file names from map)
- `src/` mirrors the original source tree structure where known
- `include/` for shared headers
- `libs/` for external library stubs (APT, DolphinSDK, SN runtime)

### Documentation
- Every decompiled system gets a doc in `docs/systems/`
- Document struct layouts, vtable orders, and function purposes
- Note any unknowns or assumptions with `// TODO:` comments

## Project Structure

```
Sims 2/
├── CLAUDE.md                    # This file
├── config/
│   └── sims2_gc.yml             # decomp-toolkit project config
├── src/                         # Decompiled C++ source
│   ├── boot/                    # __start, crt0, __init_hardware
│   ├── core/                    # EAHeap, FastAllocPool, memory mgmt
│   ├── sim/                     # ESim, CAS, sim AI
│   ├── objects/                 # cXObject, ISimsMultiTileObjectModel
│   ├── render/                  # ENgcRenderer, FrameEffects, shaders
│   ├── camera/                  # ESimsCam
│   ├── build_mode/              # InteractorModule, WallManipulator
│   ├── ui/                      # APT system (ActionScript UI engine)
│   ├── audio/                   # AmbientScorePlayer, sound system
│   ├── inventory/               # BBI::InventoryItems
│   ├── goals/                   # GoalUnlock
│   ├── save/                    # SimsMemCardWrap
│   ├── skin/                    # SkinCompositor
│   ├── effects/                 # FrameEffects, bloom, motion blur, DOF
│   ├── animation/               # Animation event handlers
│   └── levelgen/                # Level/map loading
├── include/                     # Shared headers
├── libs/                        # External library stubs
│   ├── apt/                     # APT UI library
│   ├── dolphinsdk/              # DolphinSDK 1.0 HW2
│   └── sn_runtime/              # SN Systems runtime (crt0, etc.)
├── tools/                       # Python analysis & build scripts
│   ├── map_parser.py            # Parse .map → structured symbol data
│   ├── symbol_importer.py       # Import symbols into Ghidra
│   └── progress.py              # Track decomp % matched
├── docs/
│   ├── specs/                   # Design specs
│   ├── systems/                 # Per-system documentation
│   ├── file-formats/            # .arc, .NGH, .tpl format docs
│   └── tracking/
│       ├── next-steps.md        # Detailed task queue
│       └── progress.md          # Decomp progress tracking
├── extracted/                   # Raw disc extraction
│   ├── sys/main.dol             # Target binary
│   └── files/                   # Game assets + debug files
└── build/                       # Build output
```

## Symbol Map Quick Reference

The release map contains 39,169 named symbols across these major systems:

| System | Key Classes | Approx Functions |
|--------|------------|-----------------|
| Sim AI | ESim, CASTarget, CasEventResetSim | ~2000 |
| Objects | cXObject, ISimsMultiTileObjectModel | ~3000 |
| Rendering | ENgcRenderer, FrameEffects, BloomSettings | ~1500 |
| Camera | ESimsCam | ~200 |
| Build Mode | InteractorModule::WallManipulator | ~500 |
| UI / APT | Apt*, AptActionInterpreter, AptCharacter | ~3000 |
| Audio | AmbientScorePlayer | ~500 |
| Memory | EAHeap, FastAllocPool | ~300 |
| Inventory | BBI::InventoryItems | ~400 |
| Goals | GoalUnlock | ~200 |
| Save | SimsMemCardWrap | ~100 |
| Skin | SkinCompositor | ~300 |
| Boot / SDK | __start, DolphinSDK, SN runtime | ~500 |
| Misc / Unknown | Various | ~26,000+ |

## Key Documents

- `docs/specs/sims2-gc-decomp-design.md` — full decomp design spec
- `docs/tracking/next-steps.md` — prioritized task queue
- `docs/tracking/progress.md` — decomp progress metrics
- `docs/systems/boot-sequence.md` — boot flow documentation
- `docs/file-formats/arc-format.md` — .arc archive format
- `extracted/files/u2_ngc_release.map` — the symbol bible
- `extracted/files/u2_ngc_debug.map` — debug symbol map
- `extracted/files/eorwb.log` — original EA build log (8.8MB)

## Toolchain

- **Compiler:** devkitPPC (GCC cross-compiler for PowerPC)
- **Decomp toolkit:** decomp-toolkit (`dtk`) for project management and verification
- **RE tool:** Ghidra with PowerPC/Gekko processor profile
- **Emulator:** Dolphin (testing + debugging)
- **Build:** Python + Make/CMake
- **Platform:** Windows 11
