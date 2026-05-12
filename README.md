# The Sims 2 GameCube — Matching Decompilation

A work-in-progress byte-matching decompilation of **The Sims 2** for Nintendo GameCube (G4ZE69).

## Status

**🎯 49.81% DECOMPILED — PAST 51% OF MATCHABLE CODE — 10K MILESTONE CROSSED — 39 FROM 50% TOTAL 🎯**

**49.81% decompiled and verified** — 10,215 / 20,508 functions byte-matched against the original DOL. Excluding the ~500 DolphinSDK functions (address range 0x8024-0x8039) compiled with Metrowerks CodeWarrior, we're matching **~51% of the game's decompilable code**. The **10,000 matched milestone has been crossed**, and **50% total** is now within a single short session's reach (39 functions away).

| Metric | Value |
|--------|-------|
| **Verified matches** | **10,215 / 20,508 (49.81%)** |
| **% of matchable** | **~51%** (of ~20,008 excluding ~500 SDK functions) |
| Functions remaining | ~10,293 |
| Total symbols in map | 39,169 |
| Class struct layouts | 643 documented |
| Original compiler | SN Systems ProDG GCC 2.95.3 (recovered) |
| Toolchain | SN ProDG (primary) + devkitPPC (fallback) + decomp-toolkit + asm_processor |
| Matching techniques | 75+ proven patterns + 8 Variant L recipes + 3 Variant ' families + catalog-confirmed Tech entries (volatile-CSE, lazy-callee-save-volatile-r9, region_gpr_relabel, slot-pointer-hoist, ctrl-first source-ordering, goto-shared-label, swap_operands lwzx N=5) |

**How matching works:** Every matched function has C++ source code that, when compiled with the original SN Systems ProDG compiler, produces the exact same bytes as the original game binary. No byte injection, no copying — real compiled C++ output matching the original.

## What's Done

- **Build pipeline** — devkitPPC toolchain, decomp-toolkit config, CI verification
- **Symbol map** — All 39,169 symbols from the disc imported and mapped
- **Struct layouts** — 643 classes with documented field offsets from assembly analysis
- **Trivial functions** — ~1,650 matched via automated batch script (getters, setters, empty functions)
- **Auto-matcher** — ~4,500 matched via goldmine_matcher.py (16 classifiers, 4-state flag matrix, DOL scanning)
- **AI agent matches** — ~3,000+ matched via parallel Claude Code + Kimi agents (template family blasting, pattern discovery, TU compilation, blrl breakthrough)
- **CBMemberTranslator family COMPLETE** — all **334/334 thunks** matched via the SN ProDG PMF ABI crack (single-day breakthrough, 2026-04-07). Five non-obvious keys: DVD-not-release map, free function thunk, local var CSE, 0-arg unified PMF type, `-fno-schedule-insns` alone.
- **Tier 0 AllocateAndLoadResource blast** — 8/10 resource manager TUs hit 100% via three C++ template families (Direct 1-arg Load, Direct 2-arg Load, Virtual Load(EFile&)) with `-fno-schedule-insns`. Closed `e_animman`, `e_characterman`, `e_flashman`, `e_modelman`, `e_shaderman`, `e_soundeventman`, `e_textureman`, `particleman`.
- **dtor52 pattern blast** — standard 52B destructors (vtable store + conditional delete) unlock at 100% hit rate with `-fno-schedule-insns` alone. Closes scheduling diffs in common-tail stores.
- **SDA externals technique** — globals wrapped in a `>= 8 byte` struct force the compiler to emit `lis/lfs` (or `lis/lwz`) absolute addressing instead of `@sda21`, matching the DOL pattern. Unblocks any function where DOL uses absolute addressing for globals.
- **blrl virtual dispatch SOLVED** — proper C++ virtual class declarations generate correct `blrl` codegen, unlocking thousands of previously-blocked functions
- **TU compilation workflow** — `tu_match.py --combine` compiles whole translation units for SDA and register allocation context
- **Verification tools** — `verify_match.sh` for end-to-end compile-and-compare. Handles R_PPC_REL14/REL24 relocations and filters `-j .text` section relocs to avoid vtable linkonce-section false positives on virtual-method classes.
- **19-technique library** — full matching toolbox covering SDA, virtual dispatch, scheduling, register allocation, comparison forms, pre-set returns, compound booleans, callback wrappers, and template instantiation. See `docs/tracking/techniques.md`.
- **r11/r9 register allocation wall CRACKED** — removing `-fno-schedule-insns2` from default flags fixes GCC's volatile register preference, unlocking hundreds of member method patterns that were previously walled.
- **Template family blasting** — WrapperPaneBase (19), TArray (27), EControllerManager (30), SafeDelete/DestroyInstance (12+), EdithVariableSet accessor (13+), DlgWrapper (5), INVTarget callback wrappers (10), cXObjectImpl/cXPersonImpl vtable dispatch (10+).
- **Permuter v2** — `tools/matcher_bot.py` with 8 stochastic mutations + hill-climbing search + batch mode for automated source-level permutation against the DOL.
- **Pre-commit verification gate** — every `src/matched/` commit is auto-verified against the DOL; fakes and broken matches are blocked before they land.
- **DVD vs release map gotcha confirmed** — the shipped DOL is from `cm3-build22`; address lookups MUST use `u2_ngc_release_dvd.map`. The release map (`cm3-build25`) has different addresses and will produce false leads.
- **Multi-agent fleet orchestration** — parallel Claude Code + Kimi + codex-cli agents coordinated via cog MCP. Specialized roles: production blast (SonnetWorker), structural-diagnostic (SonnetWorker2), wall cracking (OpusWorker), dedicated mutator authoring (MutatorSmith), background sweep (Kmiworker2), pre-scout audits (TUScout), 30-min qa-tick reviews (Reviewer), gate-review reserve (OpusReviewGuy), solo virgin-class lane (CodexWorker).
- **Variant K/L/M dtor classification** (Techniques #66/#67/#68) — bl-count fingerprint pre-classifies destructor patterns: 0 bl → K (vtable-only), 1 bl → L (single helper), 1 bl + Deallocate → M, 2 bl → B/C/D/E (multi-helper).
- **Technique #69 — SDA-extern int via -25836(r13) anchor** — `extern int s_instanceCount;` resolves to .sbss SDA cluster without map symbol entry. Sibling to existing `extern char globalName[]` SDA pattern.
- **Technique #70 — vtable-at-offset SI ctor with member-in-derived** — single-inheritance ctors with vtable stored at non-zero offset (e.g., +0x24, +0x54, +0xF0) require the offset member to be in the DERIVED class, not the base. Validated 7 classes / 3 different offsets.
- **Technique #71 — STL vec-iter dealloc** — `__node_alloc<128 / __builtin_delete>128` size-threshold dispatch with sizeof(T) variants (`& ~3U` for 4-byte, `& ~1U` for 2-byte, no mask for raw). Validated 7 classes (DialogPane family + EdithVariableSet + ObjectDataObjDefinition).
- **Variant G' / Variant I' / Variant L** — extended dtor recipe families:
  - **Variant G'** = vector-iter inline-dealloc loop with magic-div + `>128 byte` branch dispatch (validated sizeof=4/12/52). Key insight: explicit `&m_vec` pointer forces base-formation matching SGI STL `_Vector_base&` reference pattern.
  - **Variant I'** = base-I + Technique #69 SDA-extern + inline-derived-EBitArray-member-dtor (manually-managed-vtable footnote: derived dtors must stay non-virtual or vtable lands at wrong offset).
  - **Variant L 8-pattern recipes** — non-virtual `dtor(int flag)` method (sidesteps base/deleting variant ambiguity, 100% hit rate), MI vtable-transition (dual `m_vt = vt_a/vt_b`), `if (this != 0)` null-this guard, custom delete vectors (DOGMA_PoolManager / MainHeap / EResourceManager / AptValueGC / HeapStaticFree), singleton clear (SDA + non-SDA struct-cast variants), switch-case dispatch, virtual call slot N (8-byte slots, dtor takes 2), field-clear + flag-check interleaving.
- **asm_processor mutator system** — post-compile asm transformation pipeline with 8+ mutators (insert_mr, remove_mr, swap_cr_field, swap_operands, swap_adj, force_reg, nop_before, fp_relabel, gpr_relabel) for handling register-allocation and scheduling differences that source-coax cannot resolve. Multi-directive composition validated (StackSwap E-15 11-directive recipe).
- **Triage-first protocol** — every wall gets a 30-min source-level test BEFORE mutator authoring. If recipe generalizes → catalog descope (no mutator). If only mutator-shaped fix works → handoff. Caught GameData::GamePlayReset, BString2::assignDebug, ESimsCam::SetState as descopes saving authoring time.
- **Pre-RE → cracking handoff pattern** — structural-diagnostic worker (SW2) RE-blueprints functions with full disassembly decode + recipe sketch + class layout, hands to cracking worker (OpusWorker) for byte-match. Sustained 10-25min/blueprint pace; multiple cross-class portable insights compound across sessions.
- **volatile-CSE technique CONFIRMED (2026-05-04)** — `*(T *volatile *)&m_field` cast pattern defeats GCC 2.95 CSE when DOL emits multiple `lwz` of same offset on same base register with intermediate `mr`. Validated on 2 instances (cXObjectImpl::ChangeSelectedSimL + CTGFileImpl::GetSize 4× lwz). No asm_processor needed.
- **lazy-callee-save-volatile-r9 technique** — DOL pattern where `addi rN,rThis,off` → `lwz r0,4(rN)` → `mr r28,rN` (lazy callee-save cache) is reproduced via 4-directive asm_processor pipeline. Cracked the ERModel 17-member loop family (14 verified, +6 CTGDump op_shl twins). 5 documented variants for guard / no-relabel / r30-this / ESubModel-direct shapes.
- **region_gpr_relabel mutator (3 instances confirmed)** — when DOL allocates registers differently than cc1plus (e.g. r6/r11/f13 vs compiler's r10/r9/f0) but operations are byte-equivalent, post-compile asm rename realigns registers. Includes **dual-region sub-pattern**: split rename around `lfd 0`/`stfd 0` lines to dodge FPR-vs-GPR digit-conflation in `relabel_token`. Plus `unsafe_clobber=true` edge case for same-line use+redef.
- **slot-pointer-hoist technique** (catalog candidate, awaits 2nd instance) — when 3+ vcalls share callee-saved register pressure, hoist the LAST call's slot pointer + adjusted-this BEFORE earlier calls so r30/slot survive intervening CALL2/CALL3. Cracked cXObjectImpl::Error 152B (6-instruction divergence resolved).
- **S15 family blasts** — EFixedString string-manipulation family (15+ matches: TrimRight/TrimLeft/ExtractRoot/Extension/Filename/Directory/RemoveTrailingSlash/RemoveDriveLetter/FindReverse/Mid/Left/Remove/Replace/CompareNoCase/ReleaseBuffer/Init/GetLength), EAnimController batch (SetAllTrackSpeed/StopAllTracks/SetTrackPos/SetTrackBlend/SetNodeVisible/PrintTracks), SAnimator2 batch (StartAutoRun/getIsLeftFootUp/stopIdleOverlay/clearSuspendedCarry/GetTurnRate/getAnimDuration/triggerCameraBloom/setFollowDone/lockHandsUpCarryNodes), ENgcRenderer batch (ProcessFrameEffects/SetBlendMode/CycleToNextFrameBuffer/DisplayList/SetClearColor/ParticleListBegin), InteractorModule pair (Update/OnCommandReleased/GetPlayerInteractor/IsSimulatorPaused).
- **New asm_processor mutators (S15 1-INSTANCE-PROVISIONAL)** — `inject_before` (cross-function instruction injection at named labels) and `fuse_mr_recordbit` (merge `mr.` Rc-bit into adjacent `or.`).
- **ctrl-first source ordering PROMOTED** — when a controller-pointer is reused after a float-constant setup, computing the ctrl pointer FIRST in source forces GCC to match DOL's adjacent `lwz` + `lis` order (3 confirmed instances).
- **goto-shared-label PROMOTED** — `goto` to a shared epilogue label forces non-branchless emission, matching DOL's explicit branch + shared return tail (3 instances: GetTurnRate const-value share + 2× IsSimulatorPaused boolification).

## What's Not Done

- **~10,293 functions** still need matching (~50%)
- **SDK library functions** — DolphinSDK functions (address range 0x8024-0x8039) were compiled with Metrowerks CodeWarrior, not SN Systems — they cannot byte-match with our compiler. Excluded from the matchable pool (~500 functions).
- **LIFO vs FIFO store scheduling** — our GCC does LIFO store scheduling, original SN v1.76 does FIFO. Blocks most `ctor` functions. Requires compiler patch or TU compilation.
- **FP register alternation** — DOL alternates f0/f13 in float struct copies, our compiler uses f0 only. Blocks most float-heavy Rendering/ENgcRenderer functions.
- **InteractorModule struct layouts** — 86+ functions blocked on non-trivial member offsets requiring Ghidra-verified struct analysis.
- **Complex arithmetic** — magic division constants, bitfield packing patterns
- **PC port** — a prototype exists but is blocked until real decomp progress is further along

## Building

### Prerequisites

- devkitPro with devkitPPC
- decomp-toolkit (`dtk`)
- Python 3.10+
- A legally obtained copy of The Sims 2 (GameCube)

### Quick Start

```bash
git clone https://github.com/natebag/Sims2DECOMP.git
cd Sims2DECOMP

# Place your disc files:
#   extracted/sys/main.dol
#   extracted/files/u2_ngc_release_dvd.elf
#   extracted/files/u2_ngc_release_dvd.map

# Build and verify
python tools/gen_skeleton.py
make inject
make diff
```

### Compiler Note

The original game was compiled with **SN Systems ProDG** for GameCube (GCC 2.95.3, SN BUILD v1.76). We recovered the original compiler and use it directly for verification:

```
cc1plus.exe -quiet -O2 -fno-elide-constructors -msdata=eabi -G 8
```

This eliminates most compiler mismatch issues since we're using the exact compiler EA used. devkitPPC is available as a fallback for functions where the SN compiler has known scheduling differences (`[VERSION_DIFF]`).

## Contributing

### Matching a Function

```bash
# 1. Find an unmatched function
python tools/extract_function.py --name "FunctionName"

# 2. Write matching C++ in src/matched/
#    (see existing matches for patterns)

# 3. Verify it matches
bash tools/verify_match.sh src/matched/your_file.cpp 0xADDRESS SIZE

# 4. If MATCH — commit and PR. If not — iterate.
```

### Automated Matching

```bash
# Batch match trivial functions (getters/setters/empty)
python tools/batch_match_trivial.py --verify

# AI-assisted matching via API
python tools/decomp_agent.py --api openai --key YOUR_KEY --count 100
```

### Key Tools

| Tool | Purpose |
|------|---------|
| `tools/extract_function.py` | Disassemble any function from the DOL |
| `tools/verify_match.sh` | Compile C++ and verify bytes match DOL |
| `tools/batch_match_trivial.py` | Auto-match trivial 4-20 byte functions |
| `tools/decomp_agent.py` | AI-powered matching via Claude/OpenAI APIs |
| `tools/gen_skeleton.py` | Generate skeleton assembly from symbols |
| `tools/inject_matches.py` | Inject verified matches into build |

## Why This Game?

EA's build team left extensive debug artifacts on the retail disc:

- **Full ELF** with debug symbols (`u2_ngc_release_dvd.elf`)
- **Symbol maps** with 39,169 named symbols
- **Build logs** (`eorwb.log`, 8.8MB)
- **Version headers** — Build `F.09.12.0` (Gold Master, September 12, 2005)

This gives us every function name, class name, and variable name — dramatically reducing the RE effort.

## Project Structure

```
src/matched/                  — Verified byte-matching C++ implementations
src/asm_decomp/               — Original PPC assembly (reference)
src/core/                     — Annotated pseudocode for key systems
src/wip/                      — Work-in-progress matches (non-verified, version_diff archive)
include/classes/              — Class headers with struct layouts
config/                       — decomp-toolkit config, symbols, linker scripts
tools/                        — Python scripts for matching and verification
tools/asm_processor/          — Post-compile asm mutators (insert_mr, swap_cr_field, etc.)
tools/legacy_analysis/        — One-off analysis scripts from earlier sessions (kept for reference)
docs/tracking/                — Session plans, technique catalogs, progress tracking
docs/systems/                 — Per-system documentation (boot, sim AI, render, etc.)
docs/file-formats/            — Asset format docs (.arc, .NGH, .tpl)
extracted/                    — Disc files (not in repo — you provide these)
```

## Legal

This project does not contain any original game assets or copyrighted code. You must provide your own legally obtained copy of The Sims 2 (GameCube).

## Credits

- The Sims 2 is a trademark of Electronic Arts Inc.
- Built with [decomp-toolkit](https://github.com/encounter/decomp-toolkit)
- Inspired by the GameCube decompilation community
