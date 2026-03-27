# Next Steps — Sims 2 GC Decomp

Current milestone: **Milestone 2: PORTABLE C++ CONVERSION** — nearly complete

Last session: 2026-03-27 — All 1,214 asm stubs now have portable C++ equivalents.
global.cpp (230K lines, 1,970 functions) was the final boss. PC x86 build system is
being set up in parallel (CMake + platform abstraction — 23 errors, 86 warnings on
first compile).

---

## How to pick up work

Run `git log --oneline -10` to see recent commits, then continue
with the highest-priority unchecked task below.

---

## Milestone 2 Gate Status

- [x] 90%+ of asm stubs converted to portable C++ by file count (100% — all 1,214)
- [x] All "big fish" files (>5,000 lines) converted
- [ ] Converted code compiles clean with `make compile`
- [x] 100% DOL byte match maintained throughout
- [x] Per-system conversion tracking updated in progress.md

**One gate remains:** verify `make compile` succeeds cleanly on the portable C++ code.

---

## Lane 1: Big Fish (>5K lines) — DONE

All Big Fish files converted as of 2026-03-27.

### Tier 1 — Massive (>20K lines)
- [x] `global.cpp` (230,640 lines) — converted in 4 chunks (12,970 lines portable C++)
- [x] `InteractorModule.cpp` (40,471 lines) — bigfish_batch_4.cpp
- [x] `cXObjectImpl.cpp` (35,751 lines) — bigfish_batch_4.cpp
- [x] `AptActionInterpreter.cpp` (24,436 lines) — bigfish_batch_4.cpp
- [x] `cXPersonImpl.cpp` (20,023 lines) — bigfish_batch_4.cpp

### Tier 2 — Large (10K-20K lines)
- [x] `SAnimator2.cpp` (15,998 lines) — bigfish_batch_4.cpp
- [x] `ENgcRenderer.cpp` (13,056 lines) — bigfish_batch_4.cpp
- [x] `INVTarget.cpp` (11,687 lines) — bigfish_batch_3.cpp
- [x] `EAnimController.cpp` (10,212 lines) — bigfish_batch_3.cpp
- [x] `static_init.cpp` (10,212 lines) — bigfish_batch_3.cpp

### Tier 3 — Medium-Large (5K-10K lines)
- [x] All 19 files converted across bigfish_batch_1/2/3.cpp

## Lane 2: System Sweeps — DONE

All systems now at 82%+ portable C++ coverage. Effects at 100%.

| System | Status |
|--------|--------|
| UI / APT | 82.3% (remaining stubs have portable equiv) |
| Sim AI | 85.5% (remaining stubs have portable equiv) |
| Effects | **100%** |
| Build Mode | 87.2% (remaining stubs have portable equiv) |
| Audio | 88.2% (remaining stubs have portable equiv) |
| Misc | 89.0% (remaining stubs have portable equiv) |

## Lane 3: Small Batch — DONE

All small/medium/large stubs converted across batch sessions (330 + 385 + 114 + 185 stubs).

## Lane 4: Ghidra Setup (optional, as needed)

Not needed for Milestone 2. Defer to Milestone 3 if complex functions need it.

- [ ] Create Ghidra project for Sims 2 GC
- [ ] Import `main.dol` with PowerPC/Gekko processor
- [ ] Import `u2_ngc_release_dvd.elf` for debug symbols
- [ ] Apply map symbols via script

## Lane 5: Documentation

- [ ] Write CONTRIBUTING.md
- [x] Write `docs/systems/boot-sequence.md`
- [x] Write `docs/systems/build-system.md`
- [ ] Document build flags used by EA
- [ ] Create CI-ready build script

---

## What's Next After Milestone 2

### Immediate (close M2)
- [ ] Run `make compile` and fix any remaining build errors
- [ ] Mark Milestone 2 DONE in CLAUDE.md once gate is met

### PC Build (in progress — separate session)
- [ ] Get x86 CMake build compiling clean (currently 23 errors, 86 warnings)
- [ ] Create platform abstraction headers (GX→OpenGL, PAD→SDL, DVD→stdio, OS→stdlib)
- [ ] Split batch decomp_cpp files into per-class/per-system source files

### Milestone 3: CORE SYSTEMS
- [ ] EAHeap / memory management fully decompiled and matching
- [ ] FastAllocPool decompiled
- [ ] Main game loop decompiled (init → update → render cycle)
- [ ] .arc archive loader decompiled
- [ ] ENgcRenderer initialization decompiled
- [ ] basic_string and STL containers decompiled
- [ ] 20%+ of total functions matching

---

## Completed Milestones

### Milestone 1: FOUNDATION — DONE (2026-03-24)
- devkitPPC toolchain working
- 100% DOL byte match via inject pipeline
- Map parser + symbol extraction done
- README written
- Progress tracker working

### Milestone 2: PORTABLE C++ CONVERSION — NEARLY DONE (2026-03-27)
- All 1,214 asm stubs have portable C++ equivalents (100%)
- All Big Fish files (>5K lines) converted
- 100% DOL byte match maintained
- Progress tracking updated
- Pending: `make compile` verification
