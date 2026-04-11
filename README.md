# The Sims 2 GameCube — Matching Decompilation

A work-in-progress byte-matching decompilation of **The Sims 2** for Nintendo GameCube (G4ZE69).

## Status

**41.5% decompiled and verified.** Functions are being matched one at a time — hand-written C++ that compiles to byte-identical PPC output, verified against the original DOL.

| Metric | Value |
|--------|-------|
| **Verified matches** | **8,516 / 20,508 (41.5%)** |
| Functions remaining | ~11,992 |
| Total symbols in map | 39,169 |
| Class struct layouts | 643 documented |
| Original compiler | SN Systems ProDG GCC 2.95.3 (recovered) |
| Toolchain | SN ProDG (primary) + devkitPPC (fallback) + decomp-toolkit |

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
- **9-technique compiler flag toolbox** — per-function flag overrides for the common wall classes: `-fno-schedule-insns` (SDA load ordering + dtor scheduling), `-fno-schedule-insns2` (post-alloc scheduling), `-fno-elide-constructors` (virtual class emission / schedule2 re-enable), `-fno-peephole` (reg-alloc walls / tight basic-block reorderings), full virtual class declarations (natural `blrl` emission), raw ptr arithmetic for ID fields, SDA extern struct wrap, address-based near-miss grep.
- **Pre-commit verification gate** — every `src/matched/` commit is auto-verified against the DOL; fakes and broken matches are blocked before they land.
- **DVD vs release map gotcha confirmed** — the shipped DOL is from `cm3-build22`; address lookups MUST use `u2_ngc_release_dvd.map`. The release map (`cm3-build25`) has different addresses and will produce false leads.

## What's Not Done

- **~11,992 functions** still need matching (the other ~58%)
- **`[no source]` functions (~1,926)** — exist in the DOL but have no asm_decomp counterpart, so the TU sweep workflow can't extract them. Require direct DOL extraction (`extract_function.py`) and manual RE.
- **Inline-asm-stub functions (~10,913 with source)** — many `src/asm_decomp/` files contain functions with `__asm__` placeholders rather than real C++. Each one needs the inline-asm replaced with hand-written matching C++.
- **Register-allocation walls** — certain functions hit SN ProDG v1.76 vs v3.93 graph-coloring tie-breaker diffs (DOL reuses scratch registers, current compiler allocates fresh). No flag combo currently cracks these; needs source-level restructuring or future flag research.
- **Store-combining walls** — compiler merges adjacent same-value stores the DOL kept separate (e.g. two `sth 64` → one `stw`). Needs a separating volatile barrier or different class layout.
- **CSE elimination walls** — compiler eliminates `mr rN, rM` register copies the DOL uses. Needs CSE-breaking idioms like `noinline` wrapper calls.
- **Multi-blrl vtable aliasing** — 2+ virtual calls in one function still problematic; the compiler re-loads the vtable.
- **Float register allocation (f0-f13)** — variable declaration order trick doesn't work for floats.
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
