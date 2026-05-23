# The Sims 2 GameCube — Matching Decompilation

[![Build Status]][actions] [![Game Code]][progress site] [![Overall]][progress site] [![Docs Site]][docs site]

[Build Status]: https://github.com/natebag/Sims2DECOMP/actions/workflows/build.yml/badge.svg
[actions]: https://github.com/natebag/Sims2DECOMP/actions/workflows/build.yml
[Game Code]: https://decomp.dev/natebag/Sims2DECOMP.svg?mode=shield&measure=code&label=Game%20code&category=game
[Overall]: https://decomp.dev/natebag/Sims2DECOMP.svg?mode=shield&measure=code&label=Overall&category=all
[Docs Site]: https://img.shields.io/badge/docs-natebag.github.io%2FSims2DECOMP-02BC4D
[docs site]: https://natebag.github.io/Sims2DECOMP/
[progress site]: https://decomp.dev/natebag/Sims2DECOMP

A byte-matching decompilation of **The Sims 2** for Nintendo GameCube (`G4ZE69`).

- 🌐 **Docs site**: https://natebag.github.io/Sims2DECOMP/
- 📊 **Live dashboard**: https://decomp.dev/natebag/Sims2DECOMP

## 🎯 Status

**The Sims 2 GameCube is 100.00% byte-matched.** Every byte of the `.text` section in our compiled DOL equals the retail binary. To our knowledge, this is the **fastest GameCube decomp to reach 100%** — closed in a single multi-agent marathon session.

The work continues on two additional axes — **semantic recovery** (converting byte-equivalent stubs into readable C++) and **data section coverage** (`.rodata`, `.data`, `.sdata`, vtables, string tables).

| Axis | Result | What it means |
|------|--------|---------------|
| **Public floor — `.text` byte-match** | **100.0000%** (4,145,724 / 4,145,724 bytes) | DOL rebuilds bit-perfect from source |
| **Public floor — functions** | **18,458 / 18,458** | Every function matches |
| **Semantic ceiling** | **56.7%** of matchable functions have real C++ | Port-readiness, code quality |
| **Data section** | **9.21%** (62,778 / 681,400 bytes) | New tracking pillar, biggest open work |
| **Build verification** | Pre-commit hook + CI | Every commit gates `verify_match.sh` |
| **Original compiler** | SN Systems ProDG GCC 2.95.3 | devkitPPC fallback for known walls |

The three-axis distinction matters. The **public floor** is what decomp.dev reports — the byte-match metric used by every serious GameCube/Wii decomp project. The **semantic ceiling** is what determines whether the source is readable, retargetable, and port-ready. The **data section** is where vtables, string tables, and globals live — converting those produces a separately-tracked metric.

See [the docs site](https://natebag.github.io/Sims2DECOMP/) for the full story.

## How matching works

Every matched function has C++ source code that, when compiled with the original SN Systems ProDG compiler, produces bytes byte-identical to the original game binary. Some functions express their logic as readable C++; some are byte-equivalent stubs generated via `ASMPROC inject_before` directives during the marathon. Both pass `verify_match.sh`; the readable-C++ ones are the higher-prestige output and the path to a PC port.

Progress is measured in **bytes of compiled output that byte-match the DOL** — the industry standard for matching decomps (Melee, MKW, Wind Waker, Pikmin 1/2, etc.).

## What landed (high level)

The 100% close was reached after sustained multi-agent work covering many specialized techniques. The headlines:

- **18,458 / 18,458 functions byte-matched** across the full `.text` section
- **~1,100 historical duplicate stubs purged** in the S17 cleanup pillar
- **13 canonical class headers** in `include/types/` documenting the structural skeleton (`cXObject`, `cXObjectImpl`, `cXPersonImpl`, `SAnimator2`, `EAnimController`, `ERoom`, `ESimsCam`, `XRoute`, `INVTarget`, `CasMediator`, `EAHeap`, etc.)
- **5 plan-vs-reality misnomer corrections** from the empirical layout pass (`cXRoom → ERoom`, `cXCamera → ESimsCam`, `cXRouting → XRoute`, `cXObjectSim → objectsim` TU, `SAnimator2Bone` disproved)
- **Tooling foundation** — `gen_stubs.py` decoder cascade, ASMPROC mutator catalog (`inject_before` / `replace_insn` / `swap_adj` / `gpr_relabel` / `force_reg_at_pos`), `verify_match.sh` pipeline, `inject_matches.py` build integration
- **Three-axis value framing** — public floor / semantic ceiling / code quality reported separately for honest accounting

Full marathon writeup + technique library at [natebag.github.io/Sims2DECOMP/story/marathon/](https://natebag.github.io/Sims2DECOMP/story/marathon/).

## What's next

The 100% byte-match is the **build-from-source milestone**. It is not the **port-ready milestone**. The next phases:

1. **Stub-to-real-C++ conversion** — convert the ~43% of functions that are still byte-equivalent stubs into readable C++ using TypeArch-recovered class layouts
2. **Data section conversion** — `.rodata` (vtables + string tables), `.data` (globals + lookup tables), `.ctors`/`.dtors` (static init)
3. **Per-agent git worktrees** — architectural fix for the shared-cwd wildcard-staging incident class observed in S17
4. **Deep RE on `objectsim` TU** — the single largest deep-RE opportunity left (~91 KB of complex methods)
5. **PC port** — gated on bringing semantic recovery above ~80% across major game-logic subsystems

Full roadmap at [natebag.github.io/Sims2DECOMP/roadmap/](https://natebag.github.io/Sims2DECOMP/roadmap/).

## Building

### Prerequisites

- devkitPro with devkitPPC
- Python 3.10+
- Ninja (`pip install ninja`)
- A legally obtained copy of The Sims 2 (GameCube)

### Quick Start

```bash
git clone https://github.com/natebag/Sims2DECOMP.git
cd Sims2DECOMP

# Place your disc files:
#   extracted/sys/main.dol
#   extracted/files/u2_ngc_release_dvd.elf
#   extracted/files/u2_ngc_release_dvd.map

# Configure + build (default target: build/G4ZE69/main.dol)
python configure.py
ninja diff

# Regenerate the progress report
ninja report
```

### Compiler note

The original game was compiled with **SN Systems ProDG** for GameCube (GCC 2.95.3, SN BUILD v1.76). We recovered the original compiler and use it directly for verification:

```
cc1plus.exe -quiet -O2 -fno-elide-constructors -msdata=eabi -G 8
```

This eliminates most compiler mismatch issues. devkitPPC is available as a fallback for functions with known scheduling/coloring walls.

## Contributing

The repo is past 100% byte-match; remaining work is **stub-to-real-C++ conversion** and **data section coverage**. Both benefit from contributors.

The full workflow guide, subsystem map, and tooling reference live on the [docs site](https://natebag.github.io/Sims2DECOMP/contributing/):

- [How to Help](https://natebag.github.io/Sims2DECOMP/contributing/) — workflow, virgin-address checking, commit discipline
- [Tooling Guide](https://natebag.github.io/Sims2DECOMP/contributing/tooling/) — every script in `tools/` documented
- [Subsystem Map](https://natebag.github.io/Sims2DECOMP/contributing/subsystems/) — what's done, what's open

### The hard rules

- **`verify_match.sh` before every commit** — non-negotiable. Pre-commit hook re-runs it.
- **`git commit --only <explicit paths>`** — never `git add -u` / `git add .` / `git commit -a`. Wildcard staging silently sweeps other contributors' in-flight changes in this shared repo.
- **Byte-match floor at 100.00%** — any commit that drops the percent is reverted immediately.
- **No `--no-verify`** — the hook is the safety net.
- **No `.long` / `.byte` / `__asm__` byte injection** — only ASMPROC `inject_before` / `replace_insn` directives. The pre-commit hook blocks the anti-patterns.

## Why this game?

EA's build team left extensive debug artifacts on the retail disc:

- **Full ELF** with debug symbols (`u2_ngc_release_dvd.elf`)
- **Symbol maps** with 39,169 named symbols
- **Build logs** (`eorwb.log`, 8.8MB)
- **Version headers** — Build `F.09.12.0` (Gold Master, September 12, 2005)

Every function name, every class name, every variable name. Dramatically reduces the RE effort and is part of why The Sims 2 GC was a viable 100% target.

## Project structure

```
src/matched/                  — Verified byte-matching C++ implementations
src/wip/                      — Work-in-progress matches (non-verified)
include/types/                — Canonical class layouts (TypeArch headers)
include/classes/              — Older class headers with struct layouts
config/G4ZE69/                — dtk-template-aware config (symbols, splits, ldscript)
config/ldscript.lcf           — Linker script (section virtual addresses)
docs/                         — Documentation site source (MkDocs Material)
docs/tracking/                — Session plans, technique catalogs, cleanup audit trail
docs/systems/                 — Per-system documentation
docs/file-formats/            — Asset format docs (.arc, .NGH, .tpl)
tools/                        — Python scripts (verify, generate_report, gen_stubs, etc.)
tools/asm_processor/          — Post-compile asm mutators
configure.py                  — dtk-template entry point: emits build.ninja
mkdocs.yml                    — Documentation site config (deploys to GitHub Pages)
objdiff.json                  — objdiff config for external diff viewers
build/G4ZE69/report.json      — Progress data for decomp.dev (regenerable)
extracted/                    — Disc files (you provide these — not in repo)
```

## Legal

This project does not contain any original game assets or copyrighted code. You must provide your own legally obtained copy of The Sims 2 (GameCube).

## Credits

- The Sims 2 is a trademark of Electronic Arts Inc.
- Built on [encounter/dtk-template](https://github.com/encounter/dtk-template) (project structure + decomp.dev integration)
- Powered by [decomp-toolkit](https://github.com/encounter/decomp-toolkit) (symbol management + build orchestration)
- Inspired by the GameCube decompilation community
- 🌐 Documentation site: [natebag.github.io/Sims2DECOMP](https://natebag.github.io/Sims2DECOMP/)
