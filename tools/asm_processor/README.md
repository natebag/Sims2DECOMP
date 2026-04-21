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
