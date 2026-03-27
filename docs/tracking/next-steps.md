# Next Steps — Sims 2 GC Decomp

Current milestone: **Milestone 2: PORTABLE C++ CONVERSION**

Last session: 2026-03-27 — Worktree parallel blitz: 4 agents converted ~385 medium
stubs (101-500 lines) in parallel. Previous session converted 330 small/template stubs.
~720 asm stubs now have portable C++ equivalents. See `git log` for exact details.

---

## How to pick up work

Run `git log --oneline -5` to see the last session's commits, then continue
with the highest-priority unchecked task below.

---

## Lane 1: Big Fish (>5K lines) — HIGHEST PRIORITY

These files contain the most asm lines. Converting them moves the needle fastest.

### Tier 1 — Massive (>20K lines)
- [ ] `global.cpp` (230,640 lines) — globals, static data, misc functions
- [ ] `InteractorModule.cpp` (40,471 lines) — build mode / wall manipulation
- [ ] `cXObjectImpl.cpp` (35,751 lines) — core object system
- [ ] `AptActionInterpreter.cpp` (24,436 lines) — APT ActionScript VM
- [ ] `cXPersonImpl.cpp` (20,023 lines) — sim person AI

### Tier 2 — Large (10K-20K lines)
- [ ] `SAnimator2.cpp` (15,998 lines) — animation system
- [ ] `ENgcRenderer.cpp` (13,056 lines) — GameCube renderer
- [ ] `INVTarget.cpp` (11,687 lines) — inventory UI target
- [ ] `EAnimController.cpp` (10,212 lines) — animation controller
- [ ] `static_init.cpp` (10,212 lines) — static initializers

### Tier 3 — Medium-Large (5K-10K lines)
- [ ] `EdithVariableSet.cpp` (8,431 lines)
- [ ] `ObjectModuleImpl.cpp` (8,264 lines)
- [ ] `AptCharacterInst.cpp` (8,058 lines)
- [ ] `PCTTarget.cpp` (7,689 lines)
- [ ] `ObjectFolderImpl.cpp` (7,239 lines)
- [ ] `ERLevel.cpp` (6,936 lines)
- [ ] `cFixedWorldImpl.cpp` (6,791 lines)
- [ ] `ISimsObjectModel.cpp` (6,718 lines)
- [ ] `StringPool.cpp` (6,615 lines)
- [ ] `CASTarget.cpp` (6,480 lines)
- [ ] `ENgcMemoryCard.cpp` (6,317 lines)
- [ ] `EA.cpp` (6,286 lines)
- [ ] `NghResFile.cpp` (6,154 lines)
- [ ] `Effects.cpp` (5,780 lines)
- [ ] `AptDate.cpp` (5,669 lines)
- [ ] `NeighborhoodImpl.cpp` (5,641 lines)
- [ ] `FAMTarget.cpp` (5,521 lines)
- [ ] `CasSimPartsS2C.cpp` (5,365 lines)
- [ ] `ESimsCam.cpp` (5,214 lines)

## Lane 2: System Sweeps — complete lowest-% systems

Focus on systems with the most remaining asm stubs:

| System | Converted | Total | % | Remaining |
|--------|-----------|-------|---|-----------|
| UI / APT | 1,216 | 1,478 | 82.3% | 262 |
| Sim AI | 1,187 | 1,389 | 85.5% | 202 |
| Effects | 96 | 112 | 85.7% | 16 |
| Build Mode | 730 | 837 | 87.2% | 107 |
| Audio | 473 | 536 | 88.2% | 63 |
| Misc | 16,669 | 18,723 | 89.0% | 2,054 |

- [ ] Sweep UI/APT system — convert remaining 262 stubs
- [ ] Sweep Sim AI system — convert remaining 202 stubs
- [ ] Sweep Effects system — convert remaining 16 stubs (quick win!)
- [ ] Sweep Build Mode — convert remaining 107 stubs
- [ ] Sweep Audio — convert remaining 63 stubs

## Lane 3: Small Batch — files <1K lines

~790 remaining small files. Can be batch-converted in groups of 50-100.

- [ ] Batch A: next 100 smallest asm stubs
- [ ] Batch B: next 100
- [ ] (continue until done)

## Lane 4: Ghidra Setup (optional, as needed)

Only pursue if a Big Fish file is too complex to convert without disassembly analysis.

- [ ] Create Ghidra project for Sims 2 GC
- [ ] Import `main.dol` with PowerPC/Gekko processor
- [ ] Import `u2_ngc_release_dvd.elf` for debug symbols
- [ ] Apply map symbols via script

## Lane 5: Documentation (low priority, do alongside other work)

- [ ] Write CONTRIBUTING.md
- [ ] Write `docs/systems/boot-sequence.md`
- [ ] Document build flags used by EA
- [ ] Create CI-ready build script

---

## Completed Milestones

### Milestone 1: FOUNDATION — DONE (2026-03-24)
- devkitPPC toolchain working
- 100% DOL byte match via inject pipeline
- Map parser + symbol extraction done
- README written
- Progress tracker working
