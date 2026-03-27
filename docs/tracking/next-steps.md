# Next Steps — Sims 2 GC Decomp

Current milestone: **Milestone 6: FULL MATCH** + **Milestone 7: PC PORT** (parallel)

Last updated: 2026-03-27

---

## Where We Are

The decompilation is technically complete. All 18,539 functions are byte-identical.
All 1,214 asm stubs have portable C++ equivalents. Every game system has been converted.
Milestones 1-5 are DONE. What remains is polish (docs, CI, release) and the PC port.

---

## Milestone 6: FULL MATCH — remaining gates

### Gate: CI pipeline
- [ ] Create `.github/workflows/build.yml` — runs `make inject` + `make diff` on push
- [ ] Verify 100% DOL match in CI
- [ ] Add `make compile` step for portable C++ verification

### Gate: Contributor documentation
- [ ] Write `CONTRIBUTING.md` — how to decompile a function, coding standards, PR process
- [ ] Write system docs in `docs/systems/` for:
  - [ ] Memory management (EAHeap, FastAllocPool)
  - [ ] Main game loop (ESimsApp)
  - [ ] Asset loading (.arc, .NGH, RefPack)
  - [ ] Renderer (ENgcRenderer)
  - [ ] DolphinSDK wrappers
- [ ] Document build flags used by EA

### Gate: GitHub release
- [ ] Tag v1.0 release once CI is green
- [ ] Write release notes summarizing the decomp achievement

---

## Milestone 7: PC PORT — in progress (separate session)

An x86 CMake build is being worked on. First compile achieved with 23 errors and
86 warnings (all 32-bit→64-bit portability issues). Status as of 2026-03-27:

- [x] Set up CMake x86/x64 build system
- [x] Update types.h for 64-bit (uintptr_t, size_t, nullptr)
- [ ] Create platform abstraction headers (GX→OpenGL, PAD→SDL, DVD→stdio, OS→stdlib)
- [ ] Get decomp_cpp compiling clean on x86
- [ ] Split batch decomp_cpp files into per-class/per-system source files
- [ ] Implement GX→OpenGL rendering backend
- [ ] Implement SDL input system
- [ ] Widescreen and high-res support

---

## Completed Milestones

| Milestone | Completed | Summary |
|-----------|-----------|---------|
| 1. Foundation | 2026-03-24 | Toolchain, 100% DOL match, map parser, README |
| 2. Portable C++ | 2026-03-27 | All 1,214 asm stubs converted (1.47M lines portable C++) |
| 3. Core Systems | 2026-03-27 | EAHeap, FastAllocPool, main loop, renderer, SDK wrappers, STL |
| 4. Gameplay | 2026-03-27 | ESim, cXObject, CAS, InteractorModule, inventory, goals |
| 5. Presentation | 2026-03-27 | APT UI, audio, camera, effects, skin compositor, save system |
