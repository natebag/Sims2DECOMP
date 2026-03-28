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

### Milestone 1: INFRASTRUCTURE — DONE

**Goal:** Build toolchain that produces a DOL. Symbols imported. Build pipeline working.

**What this actually means:** The build system uses `decomp-toolkit` to inject original
bytes from the DOL into the linked ELF. The DOL "matches" because the bytes are copied,
NOT because C++ was written that compiles to matching output. This is the standard
starting point for a decomp project — not the finish line.

**Gate Criteria:**
- [x] devkitPPC toolchain builds a valid GC DOL
- [x] decomp-toolkit project config working
- [x] Symbol map parser extracts 39,169 symbols
- [x] Skeleton generator + byte injection pipeline
- [x] Build system produces DOL (via byte injection, NOT real decomp)
- [x] Compiler flags tuned (47% byte-exact match rate on simple functions)
- [x] CI pipeline for build verification

### Milestone 2: SCAFFOLDING — DONE

**Goal:** Create empty C++ source files for every class/function so the project compiles
on x86. These are empty shells — the function bodies do nothing.

**What this actually means:** 1,214 files with empty function bodies were created.
They compile on x86 but contain NO game logic. The "portable C++" is a scaffold
for future decomp work, not completed decomp work.

**Gate Criteria:**
- [x] 1,214 source files with empty function bodies
- [x] 643 class struct layouts documented from assembly analysis
- [x] Files compile on x86 (empty bodies)
- [x] Pseudocode comments describing what functions should do

### Milestone 3: ACTUAL DECOMP — IN PROGRESS (the real work starts here)

**Goal:** Hand-write C++ for every function that compiles to byte-identical PPC output.
This is the core decomp work. We are at the very beginning.

**Current Status:**
- ~5 trivial functions hand-matched in `src/matched/` (simple getters/setters, ~44 bytes)
- ~18,534 functions remaining (99.97% of the work)
- Compiler flag sweep shows 47% of functions CAN potentially match with GCC
- The other 53% need inline asm hints or tricks due to GCC vs SN Systems differences

**IMPORTANT: The DOL "matches" via byte injection. Real decomp progress is measured by
how many functions have hand-written C++ that compiles to matching bytes WITHOUT injection.**

**Gate Criteria:**
- [ ] 1,000 functions hand-matched (currently ~5)
- [ ] 5,000 functions hand-matched
- [ ] 10,000 functions hand-matched
- [ ] 15,000 functions hand-matched
- [ ] 18,539 functions hand-matched — TRUE 100% decomp

**Approach:** Agent-parallelized matching — see strategy below.

**Priority Order:**
1. 8-byte getter/setter functions (~500+ functions, trivially matchable)
2. 12-20 byte simple functions (~1,000+ functions)
3. 32-100 byte functions with documented pseudocode
4. 100-500 byte medium functions
5. 500+ byte complex functions (need deep RE work)

### Milestone 4: PC PORT — NOT STARTED (requires Milestone 3)

**Goal:** Once functions have real logic (not empty stubs), build a PC port.

**Current Prototype:** An OpenGL tech demo exists in `src/platform/pc/` that loads
game textures and renders a custom menu. This is NOT a real port — the game code
doesn't run because all function bodies are empty. A real PC port requires actual
decompiled game logic.

### Icebox (Future — requires completed decomp)
PC port, mod system, online multiplayer, widescreen, Steam Workshop

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
