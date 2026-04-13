# Attack Plan — Session 6: "The 40B Frontier"

**Date drafted:** 2026-04-13 (mid-session, continuing from Session 5)
**Baseline:** ~8,305 unique (40.5%)
**Goal:** Crack the 40-64B pool systematically, push to 8,500+ (50% of matchable)

---

## Context

Sessions 4+5 exhausted the easy pools:
- 24B leaf functions: DONE (technique #15 cleaned them out)
- 28-36B wrappers: DONE
- Version_diff flag fixes: DONE (-fno-elide-constructors swept it)
- Version_diff permuter sweep: DONE (confirmed exhausted, 0 near-misses)

**What's left:**
- **40-64B DOL scan: 374 targets** (biggest untapped pool — THIS SESSION)
- True concatenated-TU compilation (future unlock for beq/bne walls)
- 64-128B complex functions (needs Ghidra + deep RE)

## Tracks

### Track A: 40-64B Mass Crack (Primary — all workers)
OpusWorker opened this frontier with techniques #15, #16 (dual-exit). Now blast it.

**Proven patterns in 40-64B range:**
- Pre-set return (#15) on single-conditional functions
- Dual-exit shared return (#16) for nested if/if
- Wrappers (prologue + bl + epilogue)
- SDA delegate patterns
- State machine checks

**Lane assignments:**
- OpusWorker: Sim core / Camera / Person (40-64B)
- SonnetWorker: APT / Effects / Animation (40-64B)
- SonnetWorker2: Objects / Inventory / Build mode (40-64B)
- KimiWorker + Kmiworker2: Support — scan DVD map for all unmatched 40-64B, post target lists

### Track B: Permuter Hot Leads (Quick wins)
2 files from permuter scouting:
- EEngine::GetMemoryUseSystemInfo (40B, 75%) — hand-crack
- SAnimator2::SetSkillName (40B, 50%) — hand-crack

### Track C: Struct Scaffolding (Unlock compilation errors)
7 version_diff files fail to compile due to missing struct defs:
- ERSoundEvent, ERSoundTrackData, RParticle, ERDataset, REffectsEmitter
Build the missing struct headers from Ghidra/map analysis → unlocks these for matching.

### Track D: True TU Compilation PoC (Research)
ld -r doesn't work (Session 5 finding). Build a script that concatenates all .cpp files for a TU and compiles as single cc1plus invocation. Test on a TU with known beq/bne walls.

## Success Criteria

| Metric | Target | Stretch |
|--------|--------|---------|
| 40-64B fresh cracks | +30 | +60 |
| Permuter hot leads | +2 | +2 |
| Total new matches | +30 | +60 |
| Unique total | 8,335 (40.6%) | 8,365 (40.8%) |
| 50% matchable milestone | ~8,500 | — |
