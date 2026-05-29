# Sims2DECOMP

[![Build Status]][actions] [![Game Code]][progress site] [![Overall]][progress site]

[Build Status]: https://github.com/natebag/Sims2DECOMP/actions/workflows/build.yml/badge.svg
[actions]: https://github.com/natebag/Sims2DECOMP/actions/workflows/build.yml
[Game Code]: https://decomp.dev/natebag/Sims2DECOMP.svg?mode=shield&measure=code&label=Game%20code&category=game
[Overall]: https://decomp.dev/natebag/Sims2DECOMP.svg?mode=shield&measure=code&label=Overall&category=all
[progress site]: https://decomp.dev/natebag/Sims2DECOMP

A matching decompilation of *The Sims 2* for Nintendo GameCube (`G4ZE69`, build `F.09.12.0`, 2005-09-12).

- Progress dashboard: <https://decomp.dev/natebag/Sims2DECOMP>
- Documentation: <https://natebag.github.io/Sims2DECOMP/>

## Status

This is an early-stage decomp. The DOL links and is byte-identical to the retail disc, but most of that comes from byte-injection of the original binary during the build — only a fraction of functions have been hand-decompiled to real C++. The headline metric is **clean game code byte-matched**: hand-written C++ that compiles to bytes identical to the retail DOL without asm-processor mutation.

| | Total | Matched (clean) | % |
|---|---:|---:|---:|
| Game `.text` | 3,653,648 B | 452,920 B | **12.40%** |
| Game functions | 16,890 | 9,215 | 54.56% |
| Translation units (fully clean) | 691 | 67 | 9.70% |
| Data sections | 681,400 B | 62,778 B | 9.21% |

The function-count vs byte-count gap is real: thousands of small leaf functions (getters, templates, math helpers) are matched. Most medium and large structural functions are still injected stubs awaiting hand-decomp. Live numbers on the [decomp.dev dashboard][progress site].

For the internal clean / mutator / injected breakdown:

```bash
python tools/audit_clean_matches.py
```

## Building

Requires:

- [devkitPro](https://devkitpro.org/) with devkitPPC
- Python 3.10+
- [Ninja](https://ninja-build.org/) (`pip install ninja`)
- A legally obtained copy of *The Sims 2* (GameCube)

```bash
git clone https://github.com/natebag/Sims2DECOMP.git
cd Sims2DECOMP

# Place your disc files:
#   extracted/sys/main.dol
#   extracted/files/u2_ngc_release_dvd.elf
#   extracted/files/u2_ngc_release_dvd.map

# One-time toolchain bootstrap (downloads SN Systems ProDG)
python tools/download_tool.py compilers

python configure.py
ninja diff       # build/G4ZE69/main.dol vs the retail DOL
ninja report     # build/G4ZE69/report.json (decomp.dev format)
```

## Contributing

The active work is converting injected stubs into hand-written C++ that matches the retail bytes without tooling assistance.

1. Generate the current worklist:
   ```bash
   python tools/audit_clean_matches.py
   ```
   This writes `build/audit/forced.txt` (functions currently matching only via asm-processor surgery — redo candidates) and `build/audit/clean.txt` (already done).
2. Pick a function from `forced.txt` or from the [subsystem map](https://natebag.github.io/Sims2DECOMP/contributing/subsystems/).
3. Write a matching C++ implementation at `src/matched/<class>/match_0xADDR_<name>.cpp`.
4. Verify byte-identity:
   ```bash
   tools/verify_match.sh src/matched/<class>/<file>.cpp 0xADDR <size>
   ```
   Must print `MATCH`.
5. Commit with explicit paths:
   ```bash
   git commit --only src/matched/<class>/<file>.cpp -m "match: <name>"
   ```
6. Push. The pre-commit hook re-verifies, regenerates `report.json`, and the decomp.dev GitHub App updates the dashboard.

Functions that cannot be matched cleanly should be logged in [`docs/tracking/walls.md`](docs/tracking/walls.md) with what was tried, not forced through with asm-processor mutation.

Full workflow reference: <https://natebag.github.io/Sims2DECOMP/contributing/>.

## Conventions

The project's hard rules. They exist to keep the public match percent honest.

- **Match means clean.** A function counts as matched only when hand-written C++ compiles to byte-identical output with no asm-processor mutation, no `NON_MATCHING` markers, and no byte injection.
- **No floor on the percent.** The matched percent may fall when previously-forced files are reclassified. Falling honestly beats a defended inflated number.
- **No ASMPROC for new matches.** `inject_before`, `replace_insn`, `swap_adj`, `gpr_relabel`, `force_reg_at_pos`, and other mutators are post-compile asm surgery and do not count. Legacy ASMPROC files remain in tree as backlog to redo.
- **No source-level cheats.** `__asm__`, `.byte`, `.long`, naked attributes, register-pin `asm("rN")`, and `__builtin_unreachable` to suppress function bodies are all rejected by `tools/verify_match.sh`.
- **`NON_MATCHING` documents walls, not greens the build.** Use `docs/tracking/walls.md` instead.
- **Pre-commit verification is mandatory** for any new or modified `.cpp` under `src/matched/`.
- **Explicit-path staging only.** `git add -u`, `git add .`, and `git commit -a` are disallowed; use `git commit --only <path>`.
- **`SKIP_VERIFY=1`** is reserved for `git rm` of duplicate match files, with justification in the commit message.

## Notes on the disc

EA's build team left debug artifacts on the retail disc that materially help the matching work:

- Full ELF with symbols (`u2_ngc_release_dvd.elf`)
- Symbol map with 39,169 named symbols (`u2_ngc_release_dvd.map`)
- Original build log (`eorwb.log`)
- Version headers — Build `F.09.12.0`, 2005-09-12

Function and class names are recoverable without reverse engineering. The matching work is to recover the C++ shape that compiles to the known bytes.

## Compiler

The retail build used SN Systems ProDG (GCC 2.95.3, SN BUILD v1.76), invoked during verification as:

```
cc1plus.exe -quiet -O2 -fno-elide-constructors -msdata=eabi -G 8
```

devkitPPC is used as a fallback for functions affected by known scheduling or register-allocation walls.

## Project layout

```
src/matched/                  Verified clean / forced matches (per-class subdirs)
src/wip/                      Work-in-progress matches (non-verified)
include/types/                Canonical class layouts
include/classes/              Older class headers
config/G4ZE69/                dtk-template config (symbols, splits, build hash)
config/ldscript.lcf           Linker script — section virtual addresses
tools/                        Build, verification, and analysis scripts
tools/audit_clean_matches.py  Honest clean / mutator / injected audit
tools/verify_match.sh         Per-function byte-match verifier
tools/asm_processor/          Legacy post-compile asm mutators
docs/                         Documentation site (MkDocs Material → GH Pages)
docs/tracking/walls.md        Logged matching walls
docs/systems/                 Per-system documentation
docs/file-formats/            Asset format documentation
configure.py                  dtk-template entry — emits build.ninja
mkdocs.yml                    Documentation site config
objdiff.json                  objdiff config
build/G4ZE69/report.json      Progress data for decomp.dev
build/audit/                  Audit script output worklists
extracted/                    Disc files (provided by user; not in the repo)
```

## Legal

This repository contains no original game assets or copyrighted code from *The Sims 2*. A legally obtained copy of the GameCube game is required to use this project.

## Credits

- *The Sims 2* is a trademark of Electronic Arts Inc.
- [encounter/dtk-template](https://github.com/encounter/dtk-template) — project structure and decomp.dev integration
- [encounter/decomp-toolkit](https://github.com/encounter/decomp-toolkit) — symbol management and build orchestration
- [encounter/objdiff](https://github.com/encounter/objdiff) — diff viewer and report schema
- The [decomp.dev](https://decomp.dev) maintainers for the review feedback that shaped the honesty metric.
