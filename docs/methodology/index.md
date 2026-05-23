# Methodology

How a byte-matching decompilation of The Sims 2 GameCube actually works at the technical level.

## The toolchain

- **Compiler**: devkitPPC GCC (matching SN Systems ProDG's output for the original cm3-build22 DVD build, 2005-09-12)
- **Linker**: GNU LD with a custom linker script (`config/ldscript.lcf`) that places each section at its authoritative DOL virtual address
- **Build orchestration**: Ninja, driven by `configure.py`
- **Match verification**: `tools/verify_match.sh` compares per-function compiled bytes against original DOL bytes via `objdump`
- **Inject pipeline**: `tools/inject_matches.py` extracts byte-matching function bytes from `.o` files and patches them directly into the skeleton `.s` assembly. This bypasses the GCC Itanium ↔ SN Systems symbol-mangling gap.

## Reference binaries

- `extracted/sys/main.dol` — the original DOL extracted from the disc image
- `extracted/files/u2_ngc_release_dvd.elf` — the authoritative ELF with named sections (used as the section/size source-of-truth)
- `extracted/files/u2_ngc_release_dvd.map` — the symbol map (used by `generate_report.py` to enumerate functions)

## What gets verified

Every commit's pre-commit hook runs `verify_match.sh` against any added/changed `.cpp` files. A commit that produces a non-matching output fails the hook and is rejected. After commit, `tools/generate_report.py` regenerates `build/G4ZE69/report.json` which feeds decomp.dev.

The hard rule across the project: **if a commit drops `matched_code_percent` below 100.00%, it is reverted immediately**.

## Detailed reading

The deep-dive documents below cover specific aspects:

- [**Byte Matching Plan**](../byte_matching_plan.md) — the overall approach to matching SN Systems' compilation output
- [**Matching Patterns**](../matching-patterns.md) — pattern-level recipes for common shapes
- [**Register Matching Recipes**](../register-matching-recipes.md) — handling compiler register-coloring decisions
- [**Struct Layouts**](../struct_layouts.md) — how class layouts are recovered from access patterns

## Tooling reference

- [Tooling Guide](../contributing/tooling.md) — every tool in `tools/` documented with what it does and when to use it
