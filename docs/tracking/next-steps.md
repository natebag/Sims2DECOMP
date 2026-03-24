# Next Steps — Sims 2 GC Decomp

Current milestone: **Milestone 1: FOUNDATION**

## Lane 1: Toolchain & Build (HIGHEST PRIORITY)

### Phase 1A: Environment Setup
- [x] Verify devkitPPC is working (GCC 15.2.0 at F:\coding\Decompiles\Tools\devkitPro\devkitPPC)
- [x] Download and configure decomp-toolkit (dtk 1.8.3 at F:\coding\Decompiles\Tools\)
- [x] Create `config/sims2_gc.yml` with DOL sections from map file
- [x] Set up basic Makefile / build script that compiles with devkitPPC
- [x] Verify build output produces valid Gekko PPC assembly

### Phase 1B: Build System
- [x] Extract symbols from DVD map into dtk format (tools/sn_map_to_dtk.py — 23,068 symbols)
- [x] Set up function-level matching verification (`dtk dol diff`)
- [x] Create linker script for producing matching DOL (config/ldscript.lcf)
- [x] Skeleton generator (tools/gen_skeleton.py) with overlapping symbol handling
- [x] Inject pipeline (tools/inject_matches.py) — compiles, verifies, injects into skeleton
- [x] Data section injection — .rodata/.data/.sdata/.sdata2/.ctors filled from DOL
- [x] Gap filling — inter-symbol padding filled from DOL for 100% match
- [x] **100% DOL byte match achieved** (4,644,364 / 4,644,364 bytes)
- [ ] Create CI-ready build script (even if no CI yet)
- [ ] Document build process in `docs/systems/build-system.md`

**NOTE:** Full `dtk dol split` deferred — SN Systems binary causes section naming
and cyclic dependency issues with dtk (designed for CodeWarrior). Using direct
compile-and-diff workflow instead.

## Lane 2: Symbol Analysis

### Phase 2A: Map File Parser
- [x] Write `tools/map_parser.py` — parse `u2_ngc_release.map` into structured JSON
- [x] Write `tools/sn_map_to_dtk.py` — convert SN Systems map to dtk format
- [x] Extract symbols from DVD map (u2_ngc_release_dvd.map — the one matching the DOL)
- [x] Generate symbol statistics (18,547 functions, 3.77 MB code)
- [ ] Cross-reference release map with debug map for additional info

### Phase 2B: Ghidra Setup
- [ ] Create Ghidra project for Sims 2 GC
- [ ] Import `main.dol` with PowerPC/Gekko processor
- [ ] Import `u2_ngc_release_dvd.elf` for debug symbols
- [ ] Write `tools/symbol_importer.py` — Ghidra script to apply map symbols
- [ ] Run auto-analysis with applied symbols
- [ ] Identify and label vtables, string references, data sections

## Lane 3: Boot Decomp

### Phase 3A: Entry Point
- [x] `__start` — bytes matching via DOL injection (real C decomp is future work)
- [x] `__init_hardware` — decompiled in src/boot/__ppc_eabi_init.s
- [x] `__flush_cache` — decompiled in src/boot/__ppc_eabi_init.s
- [ ] Decompile `__premain` to portable C
- [ ] Decompile `__init_vm` to portable C
- [ ] Decompile `__start` to portable C (currently injected bytes only)

### Phase 3B: Main Function
- [ ] Identify and decompile `main()`
- [ ] Trace initialization order (what gets set up and in what order)
- [ ] Decompile early init functions called from main
- [ ] Document the full boot -> main loop flow

## Lane 4: Documentation

### Phase 4A: Project Docs
- [x] Write README.md (project overview, goals, how to contribute)
- [ ] Write CONTRIBUTING.md (how to decompile a function, style guide, PR process)
- [ ] Write `docs/systems/boot-sequence.md` after boot is decompiled
- [ ] Document the compiler and build flags used by EA

### Phase 4B: Format Research
- [ ] Document .arc archive format (`docs/file-formats/arc-format.md`)
- [ ] Document .NGH file format
- [ ] Document .tpl texture format
- [ ] Document .ddf disc descriptor format

## Lane 5: Portable C++ Conversion (ongoing)

The primary work toward a PC port. Convert remaining 1,214 asm_decomp stubs
to real portable C++ that compiles on both PPC (matching) and x86 (PC port).

### Priority targets (largest remaining asm stubs):
- [ ] Batch convert remaining asm stubs in src/asm_decomp/
- [ ] Focus on systems with lowest conversion %: UI/APT (82%), Sim AI (85%), Effects (86%)
- [ ] Verify converted code compiles clean with `make compile`
