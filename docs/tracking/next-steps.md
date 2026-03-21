# Next Steps — Sims 2 GC Decomp

Current milestone: **Milestone 1: FOUNDATION**

## Lane 1: Toolchain & Build (HIGHEST PRIORITY)

### Phase 1A: Environment Setup
- [ ] Verify devkitPPC is working (`powerpc-eabi-gcc --version`)
- [ ] Download and configure decomp-toolkit (`dtk`)
- [ ] Create `config/sims2_gc.yml` with DOL sections from map file
- [ ] Set up basic Makefile / build script that links a minimal DOL
- [ ] Verify build output matches expected DOL format

### Phase 1B: Build System
- [ ] Configure decomp-toolkit to split DOL into object files
- [ ] Set up function-level matching verification (`dtk elf diff`)
- [ ] Create CI-ready build script (even if no CI yet)
- [ ] Document build process in `docs/systems/build-system.md`

## Lane 2: Symbol Analysis

### Phase 2A: Map File Parser
- [ ] Write `tools/map_parser.py` — parse `u2_ngc_release.map` into structured JSON
- [ ] Extract: address, size, alignment, source file, symbol name for all 39,169 symbols
- [ ] Generate symbol statistics (functions per system, size distribution)
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
- [ ] Decompile `__start` (SN Systems crt0)
- [ ] Decompile `__init_hardware`
- [ ] Decompile `__premain`
- [ ] Decompile `__init_vm`
- [ ] Decompile `__flush_cache`
- [ ] Verify all boot functions match original DOL

### Phase 3B: Main Function
- [ ] Identify and decompile `main()`
- [ ] Trace initialization order (what gets set up and in what order)
- [ ] Decompile early init functions called from main
- [ ] Document the full boot → main loop flow

## Lane 4: Documentation

### Phase 4A: Project Docs
- [ ] Write README.md (project overview, goals, how to contribute)
- [ ] Write CONTRIBUTING.md (how to decompile a function, style guide, PR process)
- [ ] Write `docs/systems/boot-sequence.md` after boot is decompiled
- [ ] Document the compiler and build flags used by EA

### Phase 4B: Format Research
- [ ] Document .arc archive format (`docs/file-formats/arc-format.md`)
- [ ] Document .NGH file format
- [ ] Document .tpl texture format
- [ ] Document .ddf disc descriptor format
