# The Sims 2 GameCube — Matching Decompilation

A byte-matching decompilation of **The Sims 2** for Nintendo GameCube.

## Status

**Early development** — Project infrastructure and toolchain setup.

| Metric | Value |
|--------|-------|
| Functions matched | 0 / 39,169 |
| Progress | 0.00% |

## What is this?

This project aims to produce C++ source code that compiles to a byte-identical copy of the original Sims 2 GameCube executable (`main.dol`). Once complete, this enables:

- **PC port** with modern resolution, widescreen, uncapped framerate
- **Modding** — new objects, NPCs, maps, and gameplay mechanics
- **Online multiplayer** without splitscreen
- **Preservation** of a beloved game

## Why is this possible?

EA's build team left extensive debug artifacts on the retail disc:

- Full ELF binary with debug symbols
- Symbol maps with 39,169 named functions and variables
- Original build logs
- C header files

This gives us every function name, class name, and variable name — dramatically reducing the reverse engineering effort compared to a typical decomp.

## Building

### Prerequisites

- [devkitPro](https://devkitpro.org/) with devkitPPC
- [decomp-toolkit](https://github.com/encounter/decomp-toolkit)
- [Python 3.10+](https://www.python.org/)
- A legally obtained copy of The Sims 2 (GameCube)

### Setup

```bash
# Clone the repo
git clone <repo-url>
cd "Sims 2"

# Parse the symbol map (requires your extracted disc in extracted/)
python tools/map_parser.py extracted/files/u2_ngc_release.map -o tools/symbols.json --stats

# Build (once source is available)
# TBD — build system setup in progress
```

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for how to decompile a function and submit a PR.

### Quick Start
1. Pick an unmatched function from the progress tracker
2. Analyze it in Ghidra or [decomp.me](https://decomp.me)
3. Write matching C++
4. Verify with `dtk elf diff`
5. Submit a PR

## Project Structure

```
src/          — Decompiled C++ source code
include/      — Shared headers
libs/         — External library stubs (APT, DolphinSDK, SN runtime)
tools/        — Python scripts (map parser, progress tracker)
docs/         — Documentation and specs
extracted/    — Raw disc extraction (not in repo)
build/        — Build output (not in repo)
```

## Legal

This project does not contain any original game assets or copyrighted code. You must provide your own legally obtained copy of The Sims 2 (GameCube) to use this project.

## Credits

- The Sims 2 is a trademark of Electronic Arts Inc.
- Built with [decomp-toolkit](https://github.com/encounter/decomp-toolkit)
- Inspired by the GameCube decompilation community
