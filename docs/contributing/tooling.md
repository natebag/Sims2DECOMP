# Tooling Guide

Every script in `tools/` documented with purpose, inputs, and when to use it.

## Build + verify

### `tools/verify_match.sh`
**Purpose**: confirms a compiled `.cpp` produces bytes identical to the original DOL for the named address range.

**Usage**: `tools/verify_match.sh <source.cpp> <hex_address> <size>`

**Output**: `MATCH` (exit 0) or `MISMATCH` (exit 1) with side-by-side disassembly. Also runs the same relocation-aware comparison the pre-commit hook uses, so green here = green at commit time.

### `tools/generate_report.py`
**Purpose**: regenerates `build/G4ZE69/report.json` — the canonical metric source consumed by decomp.dev.

**Usage**: `python tools/generate_report.py --print-summary` (or `ninja report`)

**Outputs**: per-function and per-data-section byte-match metrics. Compares `build/sims2.elf` against `extracted/files/u2_ngc_release_dvd.elf`.

### `tools/inject_matches.py`
**Purpose**: extracts byte-matching function bytes from `.o` files and patches them into the skeleton `.s` assembly. Bridges the GCC Itanium ↔ SN Systems symbol-mangling gap.

**Usage**: `python tools/inject_matches.py [--rebuild] [--verify] [--dry-run]`

**Note**: KimiWorker's S17 fixes added `rglob` (subdirectory scanning), `build/G4ZE69/obj/matched/` path, and multi-format annotation regex. Without those, 25,000+ files would be silently skipped.

## Audit + analysis

### `tools/corrected_pool_v2_scout.py`
**Purpose**: enumerates unmatched-function pools for scout reports. Matched-file-aware (only counts true unmatches, ignores existing `src/matched/` coverage).

**Usage**: `python tools/corrected_pool_v2_scout.py [--unit <unit_name>]`

### `tools/compare_obj_vs_dol.py`
**Purpose**: byte-compares compiled `.o` function bytes against original DOL bytes directly. Bypasses the linker entirely — checks if the *compiler* output matches before linking.

**Usage**: `python tools/compare_obj_vs_dol.py <obj_path>`

## Code generation

### `tools/gen_stubs.py`
**Purpose**: generates `ASMPROC inject_before` wrapper functions for unmatched addresses. Decoder cascade: `bl`/`bc` → `blrl` → 512B/2KB/8KB body decoders.

**Usage**: `python tools/gen_stubs.py [--addrs <list>] [--tier <decoder_tier>]`

**Output**: `src/matched/<class>/match_0xADDR_<name>.cpp` files with `ASMPROC inject_before` directives. **These are byte-matched but NOT readable C++** — they are stub-conversion candidates for the semantic-recovery phase.

## Fleet hygiene

### `tools/find_unmatched.py` (S17 artifact)
**Purpose**: lists addresses that have inject stubs but no semantic C++ — i.e., the metric-moving target pool for ratio gains.

### `tools/size_sweep.sh`
**Purpose**: batch size-vs-byte audit. Used by Reviewer cycles to spot-check that converted files match their declared sizes.

## Configuration

- **`config/G4ZE69/config.yml`** — dtk-style config (game ID, hash, symbols path)
- **`config/G4ZE69/splits.txt`** — section/object split declarations
- **`config/G4ZE69/symbols.txt`** — symbol table (SN Systems-style names + addresses)
- **`config/ldscript.lcf`** — linker script with section virtual addresses
- **`objdiff.json`** — objdiff config (consumed by decomp.dev)

## Pre-commit hook

Lives at `.git/hooks/pre-commit` (or its source in the repo). Behavior:

1. Detect added/modified `.cpp` files under `src/matched/`
2. Run `verify_match.sh` against each
3. Detect duplicate filenames for the same address — block if found
4. Detect prohibited `__asm__` / `.byte` / `.long` injection patterns — block these unless ASMPROC `replace=` is used
5. Regenerate `report.json` after successful commit

**Bypass via `SKIP_VERIFY=1` is only allowed for pure-deletion commits** (no `.cpp` content changes). Any other use is a protocol violation. See [methodology](../methodology/index.md) for the full hard-floor discipline.
