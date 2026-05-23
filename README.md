# Sims2DECOMP

[![Build Status]][actions] [![Game Code]][progress site] [![Overall]][progress site]

[Build Status]: https://github.com/natebag/Sims2DECOMP/actions/workflows/build.yml/badge.svg
[actions]: https://github.com/natebag/Sims2DECOMP/actions/workflows/build.yml
[Game Code]: https://decomp.dev/natebag/Sims2DECOMP.svg?mode=shield&measure=code&label=Game%20code&category=game
[Overall]: https://decomp.dev/natebag/Sims2DECOMP.svg?mode=shield&measure=code&label=Overall&category=all
[progress site]: https://decomp.dev/natebag/Sims2DECOMP

A matching decompilation of The Sims 2 for Nintendo GameCube (`G4ZE69`).

- Progress dashboard: <https://decomp.dev/natebag/Sims2DECOMP>
- Documentation: <https://natebag.github.io/Sims2DECOMP/>

## Status

| | Total | Matched | % |
|---|---|---|---|
| `.text` (code) | 4,145,724 B | 4,145,724 B | **100.00%** |
| Functions | 18,458 | 18,458 | **100.00%** |
| Data sections (`.ctors` / `.dtors` / `.rodata` / `.data` / `.sdata` / `.sdata2`) | 681,400 B | 62,778 B | **9.21%** |

`matched_code_percent` is verified on every commit by `tools/verify_match.sh` and regenerated into `build/G4ZE69/report.json` for [decomp.dev](https://decomp.dev/natebag/Sims2DECOMP).

A separate internal metric tracks the proportion of matched functions that have hand-written C++ source (as opposed to byte-equivalent stubs produced by the `ASMPROC inject_before` pipeline). It currently sits at ~57%. The remaining functions byte-match but read as wrapped raw bytes; stub-to-real-C++ conversion is the active work going forward.

## Building

Requires:

- [devkitPro](https://devkitpro.org/) with devkitPPC
- Python 3.10+
- [Ninja](https://ninja-build.org/) (`pip install ninja`)
- A legally obtained copy of The Sims 2 (GameCube)

```bash
git clone https://github.com/natebag/Sims2DECOMP.git
cd Sims2DECOMP

# Place your disc files:
#   extracted/sys/main.dol
#   extracted/files/u2_ngc_release_dvd.elf
#   extracted/files/u2_ngc_release_dvd.map

python configure.py
ninja diff     # build/G4ZE69/main.dol
ninja report   # build/G4ZE69/report.json
```

## Compiler

The retail build used SN Systems ProDG (GCC 2.95.3, SN BUILD v1.76). That compiler is used for verification:

```
cc1plus.exe -quiet -O2 -fno-elide-constructors -msdata=eabi -G 8
```

devkitPPC is used as a fallback for functions affected by known scheduling or register-allocation walls.

## Contributing

1. Pick an unmatched or stub function. The [subsystem map](https://natebag.github.io/Sims2DECOMP/contributing/subsystems/) lists current scope.
2. Write a matching C++ implementation under `src/matched/<class>/match_0xADDR_<name>.cpp`.
3. Verify it: `tools/verify_match.sh src/matched/<class>/<file>.cpp 0xADDR <size>` → must print `MATCH`.
4. Commit with explicit paths: `git commit --only src/matched/<class>/<file>.cpp -m "..."`. Wildcard staging (`git add -u`, `git commit -a`) is not permitted in this repo — see hard rules below.
5. Push. The pre-commit hook re-verifies, regenerates `report.json`, and the CI updates the badges.

Full workflow and tooling reference at <https://natebag.github.io/Sims2DECOMP/contributing/>.

### Hard rules

- `verify_match.sh` passes for every commit that adds or modifies a `.cpp` file under `src/matched/`. The pre-commit hook enforces this.
- `matched_code_percent` does not drop below 100.00%. Any commit that drops the percent is reverted.
- `git commit --only <explicit paths>` only; never `git add -u`, `git add .`, or `git commit -a`.
- No `__asm__`, `.byte`, or `.long` byte injection. ASMPROC `inject_before` / `replace_insn` / `swap_adj` / `gpr_relabel` / `force_reg_at_pos` directives only.
- `SKIP_VERIFY=1` is allowed only for commits that are purely `git rm` of duplicate match files, with the justification stated in the commit message.

## Notes on the disc

EA's build team left debug artifacts on the retail disc:

- Full ELF with symbols (`u2_ngc_release_dvd.elf`)
- Symbol map with 39,169 named symbols (`u2_ngc_release_dvd.map`)
- Build logs (`eorwb.log`)
- Version headers — Build F.09.12.0 (2005-09-12)

Function and class names are available without reverse engineering, which simplifies the matching work.

## Project layout

```
src/matched/              Verified byte-matching C++ implementations (per-class subdirs)
src/wip/                  Work-in-progress matches (non-verified)
include/types/            Canonical class layouts
include/classes/          Older class headers with struct layouts
config/G4ZE69/            dtk-template config (symbols, splits, build hash)
config/ldscript.lcf       Linker script — section virtual addresses
tools/                    Python scripts (verify, generate_report, gen_stubs, inject_matches, etc.)
tools/asm_processor/      Post-compile asm mutators
docs/                     Documentation site source (MkDocs Material → GitHub Pages)
docs/tracking/            Session plans, technique catalogs, cleanup audit trail
docs/systems/             Per-system documentation
docs/file-formats/        Asset format documentation
configure.py              dtk-template entry point — emits build.ninja
mkdocs.yml                Documentation site config
objdiff.json              objdiff config for external diff viewers
build/G4ZE69/report.json  Progress data for decomp.dev
extracted/                Disc files (provided by the user; not in the repo)
```

## Legal

This repository contains no original game assets or copyrighted code from The Sims 2. A legally obtained copy of the GameCube game is required to use this project.

## Credits

- The Sims 2 is a trademark of Electronic Arts Inc.
- [encounter/dtk-template](https://github.com/encounter/dtk-template) — project structure and decomp.dev integration
- [encounter/decomp-toolkit](https://github.com/encounter/decomp-toolkit) — symbol management and build orchestration
