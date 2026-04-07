# The Sims 2 GameCube — Matching Decompilation

A work-in-progress byte-matching decompilation of **The Sims 2** for Nintendo GameCube (G4ZE69).

## Status

**~45% decompiled (file count) / ~42-44% truly verified.** Functions are being matched one at a time — hand-written C++ that compiles to byte-identical PPC output, verified against the original DOL.

| Metric | Value |
|--------|-------|
| **Files in `src/matched/`** | **9,321 / 20,508 (45.4%)** |
| **Verified-clean estimate** | **~8,400-8,900 (~42-44%)** — full audit pending |
| Functions remaining | ~11,200 |
| Total symbols in map | 39,169 |
| Class struct layouts | 643 documented |
| Original compiler | SN Systems ProDG GCC 2.95.3 (recovered) |
| Toolchain | SN ProDG (primary) + devkitPPC (fallback) + decomp-toolkit |

**How matching works:** Every matched function has C++ source code that, when compiled with the original SN Systems ProDG compiler, produces the exact same bytes as the original game binary. No byte injection, no copying — real compiled C++ output matching the original.

**Honest count caveat:** A 2026-04-07 audit discovered a workflow gap where files could land in `src/matched/` without ever passing `verify_match.sh` (a tool bug + no pre-commit gate). Spot-checks of one bulk-add commit showed a 30% orphan rate. The "files in src/matched/" number above is the file count; the "verified-clean estimate" is what we believe will survive a full audit. The verify tool has been fixed (commit `6062cc25`) and a bulk verifier (`tools/audit_matched_dir.py`) has been authored to identify remaining orphans in a future cleanup pass.

## What's Done

- **Build pipeline** — devkitPPC toolchain, decomp-toolkit config, CI verification
- **Symbol map** — All 39,169 symbols from the disc imported and mapped
- **Struct layouts** — 643 classes with documented field offsets from assembly analysis
- **Trivial functions** — ~1,650 matched via automated batch script (getters, setters, empty functions)
- **Auto-matcher** — ~4,500 matched via goldmine_matcher.py (16 classifiers, 4-state flag matrix, DOL scanning)
- **AI agent matches** — ~3,000+ matched via parallel Claude Code + Kimi agents (template family blasting, pattern discovery, TU compilation, blrl breakthrough)
- **CBMemberTranslator family COMPLETE** — all **334/334 thunks** matched via the SN ProDG PMF ABI crack (single-day breakthrough, 2026-04-07). Five non-obvious keys: DVD-not-release map, free function thunk, local var CSE, 0-arg unified PMF type, `-fno-schedule-insns` alone.
- **SDA externals technique** — globals wrapped in a `>= 8 byte` struct force the compiler to emit `lis/lfs` (or `lis/lwz`) absolute addressing instead of `@sda21`, matching the DOL pattern. Unblocks any function where DOL uses absolute addressing for globals.
- **blrl virtual dispatch SOLVED** — proper C++ virtual class declarations generate correct `blrl` codegen, unlocking thousands of previously-blocked functions
- **TU compilation workflow** — `tu_match.py --combine` compiles whole translation units for SDA and register allocation context
- **Verification tools** — `verify_match.sh` for end-to-end compile-and-compare. **R_PPC_REL14/REL24 relocation handling fix** (2026-04-07) eliminated a long-standing false-positive vector.
- **Bulk audit infrastructure** — `tools/audit_matched_dir.py` (orphan detection) and `tools/audit_pmf_safety.py` (per-relocation opcode preservation check)
- **5-state compiler flag matrix** — per-function flag overrides (`-fno-schedule-insns`, `-fno-schedule-insns2`, `-fno-elide-constructors`)
- **DVD vs release map gotcha confirmed** — the shipped DOL is from `cm3-build22`; address lookups MUST use `u2_ngc_release_dvd.map`. The release map (`cm3-build25`) has different addresses and will produce false leads.

## What's Not Done

- **~11,200 functions** still need matching (the other ~55%)
- **`[no source]` functions (~1,926)** — exist in the DOL but have no asm_decomp counterpart, so the TU sweep workflow can't extract them. Require direct DOL extraction (`extract_function.py`) and manual RE. This is the next-phase productivity track.
- **Inline-asm-stub functions (~10,913 with source)** — many `src/asm_decomp/` files contain functions with `__asm__` placeholders rather than real C++. Each one needs the inline-asm replaced with hand-written matching C++.
- **Instruction scheduling / register allocation differences** — affects an estimated 100-200 functions; the same logic compiles to different GPR choices or instruction order than the DOL. Deep compiler heuristic, hard to fix without per-function tuning.
- **Float register allocation (f0-f13)** — variable declaration order trick doesn't work for floats. ~unknown count.
- **Multi-blrl vtable aliasing** — 2+ virtual calls in one function still problematic; the compiler re-loads the vtable.
- **Orphan cleanup** — estimated 200-800 stale "matched" files don't actually match (committed via the bypass vectors discovered 2026-04-07). Bulk audit + cleanup pending.
- **`count_matched.py` validation** — currently counts files, not verified matches. Needs to integrate `audit_matched_dir.py` so the project's reported progress matches reality.
- **Pre-commit verification gate** — patch in flight to reject `src/matched/` commits whose files don't pass the (now-fixed) `verify_match.sh`.
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
