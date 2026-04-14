# The Sims 2 GameCube — Matching Decompilation

A work-in-progress byte-matching decompilation of **The Sims 2** for Nintendo GameCube (G4ZE69).

## Status

**🚀 42.3% DECOMPILED — APPROACHING 52% OF MATCHABLE CODE 🚀**

**42.3% decompiled and verified** — 8,670 / 20,508 functions byte-matched against the original DOL. Excluding the ~3,500 SDK functions compiled with Metrowerks CodeWarrior, we're matching **~51% of the game's decompilable code**.

| Metric | Value |
|--------|-------|
| **Verified matches** | **8,670 / 20,508 (42.3%)** |
| **% of matchable** | **~51%** (of ~17,000 excluding SDK) |
| Functions remaining | ~11,838 |
| Total symbols in map | 39,169 |
| Class struct layouts | 643 documented |
| Original compiler | SN Systems ProDG GCC 2.95.3 (recovered) |
| Toolchain | SN ProDG (primary) + devkitPPC (fallback) + decomp-toolkit |
| Matching techniques | 32 proven patterns |

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

## What's Not Done

- **~12,006 functions** still need matching (~58%)
- **SDK library functions** — DolphinSDK functions (address range 0x8024-0x8039) were compiled with Metrowerks CodeWarrior, not SN Systems — they cannot byte-match with our compiler. Excluded from the matchable pool (~3,000 functions).
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
src/matched/       — Verified byte-matching C++ implementations
src/asm_decomp/    — Original PPC assembly (reference)
src/core/          — Annotated pseudocode for key systems
include/classes/   — Class headers with struct layouts
config/            — decomp-toolkit config, symbols, linker scripts
tools/             — Python scripts for matching and verification
docs/              — Documentation and progress tracking
extracted/         — Disc files (not in repo — you provide these)
```

## Legal

This project does not contain any original game assets or copyrighted code. You must provide your own legally obtained copy of The Sims 2 (GameCube).

## Credits

- The Sims 2 is a trademark of Electronic Arts Inc.
- Built with [decomp-toolkit](https://github.com/encounter/decomp-toolkit)
- Inspired by the GameCube decompilation community
