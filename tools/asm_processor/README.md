# asm_processor — Track I infrastructure (S13)

Wall-cracking infrastructure for the Sims 2 GC decomp. Post-processes the
`.s` emitted by SN ProDG cc1plus so we can reach scheduler / register-allocation /
FP-coloring transformations that are unreachable from clean C++ source.

Status: **PHASE 1 MVP (v0 skeleton)** — 2026-04-21 (S13 Track I).

**Ownership split (see Cog info / SonnetWorker2↔OpusWorker sync):**

- **OpusWorker** owns: `asm_processor.py` (entrypoint + pipeline), `compile.py`
  (SN invocation / `.s` capture), `directives.py` (parse `// ASMPROC_*` comments
  out of C++ source into structured mutation requests).
- **SonnetWorker2** owns: `mutators/` (one module per asm-text transformer) and
  `harness/test_walls.py` (regression harness + manifest).

## Why asm-level, not source-level

`tools/verify_match.sh` bans every source-level cheat we could reach for —
`register T asm("rN")`, `__asm__`, `.long/.byte` injection,
`__builtin_unreachable`, naked/noreturn attributes. `matcher_bot.py` M01-M25
have already saturated the source-mutation space; that is precisely why the
12-wall catalog exists. asm-processor earns its keep by transforming the `.s`
output between cc1plus and NgcAs.

## Flow

```
  C++ source (contains ONLY `// ASMPROC_*:` comment directives)
    │
    ▼
  directives.py  ──►  strip directives, collect mutation requests
    │
    ▼
  compile.py     ──►  SN cc1plus produces .s
    │
    ▼
  mutators/*.py  ──►  apply each requested mutator to the .s text
    │
    ▼
  compile.py     ──►  NgcAs assembles the mutated .s
    │
    ▼
  verify_match.sh ──►  diff compiled bytes vs DOL (with per-test --outdir)
```

## Layout

```
tools/asm_processor/
├── README.md              this file
├── asm_processor.py       entrypoint (OpusWorker)
├── compile.py             SN cc1plus + NgcAs driver (OpusWorker)
├── directives.py          `// ASMPROC_*` parser (OpusWorker)
├── walls_manifest.yaml    catalog of walls used as test inputs
├── mutators/              asm-text transformers (SonnetWorker2)
│   ├── __init__.py
│   ├── swap_adj.py        swap adjacent .s lines matching two opcodes
│   ├── force_reg.py       substitute operand register on a matching line
│   └── nop_before.py      insert nop before first match of an opcode
├── harness/               regression test harness (SonnetWorker2)
│   ├── __init__.py
│   ├── test_walls.py      load manifest, run pipelines, print matrix
│   └── report.py          pass/fail matrix renderer
└── walls/                 frozen wall C++ inputs (copied from src/wip)
```

## Mutator contract

Each module under `mutators/` exports:

```python
NAME: str                                   # short, stable; used in manifest
def apply(asm_text: str, args: dict) -> str
```

`apply` returns the mutated `.s` text or raises `NoApplicableSite` if the
asm does not contain what the mutator expects (harness treats that as a
skip, not a failure).

Mutators must be deterministic for a given `(asm_text, args)`. Any
randomness lives in `asm_processor.py`'s permuter driver, not here.

## Harness usage

```bash
python tools/asm_processor/harness/test_walls.py            # run all walls
python tools/asm_processor/harness/test_walls.py 80224048    # run one
python tools/asm_processor/harness/test_walls.py --verbose   # full logs
```

Outputs a pass/fail matrix. Every mutator change must re-run the full
harness so the fleet catches regressions. The harness always passes
`--outdir build/asm_processor/test/<wall_addr>/<variant>` to
`verify_match.sh` so concurrent runs never clash on shared artifact names
(fleet advisory: `memory/feedback_git_lock_contention.md`).

## Adding a new wall

1. Copy the wip `.cpp` into `tools/asm_processor/walls/`.
2. Add an entry to `walls_manifest.yaml`.
3. Re-run the harness.

## Adding a new mutator

1. `tools/asm_processor/mutators/<name>.py` exporting `NAME` + `apply`.
2. Register it in `mutators/__init__.py` (`REGISTRY` auto-imports).
3. Reference it from the relevant wall's `pipeline:` list in the manifest.

## Coordination rules

- `git commit --only tools/asm_processor/<path>` EVERY commit.
- Cog `send_message` between OpusWorker and SonnetWorker2 on each meaningful
  change so the test harness gets re-run promptly.
- OpusReview design-review gate before Phase 3 batch run (S13 rule #7).

## Production pipeline — verify_match.sh ASMPROC routing (S13, commit 740e7c77)

`tools/verify_match.sh` auto-detects `// ASMPROC_<name>:` pragma comments
in the source it's verifying and delegates to `asm_processor.py`. The
delegation block lives between the banned-pattern checks (register-asm,
__asm__, naked, noreturn, unreachable, .byte, .long) and the normal
compile step. The detection grep is:

```
grep -qE '^[[:space:]]*//[[:space:]]*ASMPROC_[A-Za-z][A-Za-z0-9_]*'
```

So ASMPROC directives must appear on a line whose first non-whitespace
token is the C++ comment `//`. Block comments are not supported.

Pre-commit hook is unchanged — it already calls verify_match.sh with
(file, addr, size). Sources under `src/matched/**/*.cpp` with ASMPROC
directives validate through the full pipeline automatically:

```
  git commit
    └── pre-commit hook
         └── anti-cheat grep checks (ASMPROC comment is NOT a banned pattern)
         └── parse_header for addr/size
         └── bash tools/verify_match.sh <file> <addr> <size>
              ├── banned-pattern checks (same set)
              ├── grep for ASMPROC_* directive
              └── if found -> python tools/asm_processor/asm_processor.py ...
                              ├── parse directives
                              ├── strip directives from source
                              ├── SN cc1plus -> .s
                              ├── apply mutators to .s
                              ├── SN NgcAs -> .o
                              ├── extract .text bytes + relocations
                              ├── diff vs DOL at (addr, size) with reloc masking
                              └── print "MATCH! Function at ..." on success
```

### MATCH output format

`asm_processor.py` prints `MATCH! Function at 0x<addr> (<size> bytes)
matches perfectly (with relocations masked).` on success — matches
pre-commit's `^MATCH! Function` regex. A secondary `  via asm_processor:
<file> after N mutator pass(es).` line follows for operator awareness.

### Promotion workflow per wall

To promote an asm-processor wall into `src/matched/`:

1. Rewrite the source with real class hierarchy (e.g. `namespace X { struct Y { float method(); }; }`) and field offsets per the DVD map. Aliased struct names used for scratch work in `tools/asm_processor/walls/` mangle to wrong symbols.
2. Keep the `// ASMPROC_<name>: ...` directive comment(s) at the top of the source.
3. Put the file at `src/matched/<dir>/match_0x<ADDR>_<Class>__<Method>.cpp`. The header must contain `(NN B)` for size parsing per QA-RULE #1.
4. `git add` + `git commit --only <path>`. Pre-commit's anti-cheat checks + verify_match.sh routing + asm_processor.py all run automatically.

Worked examples in-tree as of S13 session 1:
- `src/matched/interactormodule/match_0x80224048_WallManipulator__GetAffectedWallHeight.cpp` — uses `ASMPROC_swap_adj: a=lfs b=andi. which=first`
- `src/matched/camera/match_0x8001A03C_ESimsCam__GetCursorLimitTopWidth.cpp` — uses `ASMPROC_fp_relabel: swap=0:13,11:12`
