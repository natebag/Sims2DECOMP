# matcher_bot.py v2 — "The Permuter"

**Date:** 2026-04-13
**Status:** Approved
**Goal:** Extend matcher_bot.py with hill-climbing search + 8 new source mutations to automatically crack version_diff files that are 1-2 mutations away from matching.

---

## Context

Session 4 revealed that the version_diff pool (~200 files) is exhausted for flag-only fixes. The remaining files have deeper structural issues (store ordering, comparison forms, type widths, branch layout) that need source-level mutations. OpusWorker and SonnetWorker manually try 5-10 variations per function — a permuter automates this at 50-200 iterations/second.

Inspired by: https://gist.github.com/malvarezcastillo/b1a2cb3ee1bf0e790f85aa61b06051d1

## Architecture

Extends `tools/matcher_bot.py` (not a new file). Same entry point, new `--permute` flag activates hill-climbing mode.

### Core Loop: Hill-Climbing Search

```
1. Compile baseline source, score it (% matching bytes)
2. Pick random mutation from pool (M0-M19 + flag variants)
3. Apply mutation, compile, score
4. If score improved → keep as new baseline, chain more (up to 20 deep)
5. If score same/worse → 60% reset to best-known, 40% keep exploring
6. Repeat until MATCH or budget exhausted (default 200)
```

### Scoring

Parse verify_match.sh's hex diff output on mismatch. Count matching bytes / total bytes = score (0.0 to 1.0). Score of 1.0 = MATCH.

Extract from verify_match.sh stdout lines like:
```
DOL:      80556040 38000000 90030008 4E800020
Compiled: 80556040 38000000 90030004 4E800020
                                 ^^
```

Count positions where DOL == Compiled after relocation masking.

### Existing Mutations (keep as-is)

| ID | Type | Description |
|----|------|-------------|
| M0-M10 | Flag variants | 11 compiler flag combinations |
| M10 | Text | Variable declaration reordering (adjacent swap) |
| M11 | Text | Compiler barrier injection between stores |

### New Mutations

| ID | Mutation | Method | Description |
|----|----------|--------|-------------|
| M12 | Type width swap | Regex | `int` ↔ `short` ↔ `char`, `unsigned` toggle on local vars |
| M13 | Cast insertion | Regex | Wrap random expressions in `(int)`, `(short)`, `(unsigned)` |
| M14 | Comparison inversion | Regex | `x >= y` → `!(x < y)`, `x == 0` → `!x` |
| M15 | Pre-set return | Regex | `if(c) return v; return 0;` → `r=0; if(c) r=v; return r;` |
| M16 | Operand swap | Regex | `a + b` → `b + a` for commutative ops (+, |, &, ^, *) |
| M17 | Expression split | Regex | `a = b + c;` → `a = b; a += c;` |
| M18 | Negate condition | Regex | `if(x)` → `if(!(!x))`, DeMorgan on `&&`/`||` |
| M19 | Struct deref swap | Regex | `a.field` → `(&a)->field` and vice versa |

All regex-based — no C/C++ parser dependency. Each picks a random applicable site per invocation.

### Batch Mode

```bash
python tools/matcher_bot.py --batch-dir src/wip/version_diff/ --permute --budget 200
```

Iterates all `.cpp` files in the directory. Per-file results saved to `build/permuter_results/`. Report format:

```
MATCH:  match_0x80084464_TextBaseItem_Startup.cpp (score: 1.00, attempt 47/200, mutations: M3+M14)
NEAR:   match_0x800B4214_Commander_ctor.cpp (score: 0.93, best at attempt 112/200)
STUCK:  match_0x80017070_ESimsCam_SetZoom.cpp (score: 0.72, no improvement after 200)
```

### CLI Interface

```bash
# Existing mode (unchanged)
python tools/matcher_bot.py --wip file.cpp --budget 60

# New permuter mode
python tools/matcher_bot.py --wip file.cpp --permute --budget 200

# Batch mode
python tools/matcher_bot.py --batch-dir src/wip/version_diff/ --permute --budget 200

# Verbose (print each attempt's score)
python tools/matcher_bot.py --wip file.cpp --permute --budget 200 --verbose
```

### File Changes

Only `tools/matcher_bot.py` is modified. No new files, no new dependencies.

### Success Criteria

- Cracks ≥20 of ~200 version_diff files (10% hit rate minimum)
- ≥50 iterations/second on single core
- Zero false positives (every MATCH passes verify_match.sh)
- Batch mode produces actionable report

### What It Won't Fix

- Frame size differences (TU compilation needed)
- FP register alternation f0/f13 (compiler internal)
- Register allocation in complex functions >128B
- Fundamentally wrong C++ logic
