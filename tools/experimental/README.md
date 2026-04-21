# tools/experimental/

Retained snapshots of one-off / exploration scripts used during the S9–S12
decomp campaigns. They are **not canonical** — they are frozen historical
references that proved useful for a specific investigation and were never
promoted to first-class tools.

## What lives here

- **batch_verify*.py** — S11 bulk verify drivers (superseded by
  `tools/verify_match.sh --outdir` + `tools/matcher_bot_bulk.py`).
- **check_*.py / check_*.sh** — ad-hoc diagnostic scripts for address
  collisions, DVD bytes, symbol presence. Often single-use.
- **compare_family.py** — family-shape comparator used to group sibling
  functions by disasm prefix/suffix tuples.
- **debug_parser.py** — one-off map-parser debug dumper.
- **dedup_*.py** — the dedup tooling lineage (inspect → verify → verify_seq).
  Parts of this inform `verify_match.sh` hardening but the scripts
  themselves are not used post-S11 cleanup.
- **disasm_dol.py / simple_disasm.py** — standalone PPC disasm utilities.
  `tools/disasm_func.py` is the current canonical.
- **find_families.py / find_targets2.py / find_targets3.py** — scout
  experiments; canonical is `tools/find_targets.py`.
- **qa_monitor*.py** — S11 QA-monitor prototypes. Superseded by the
  Reviewer agent's live 30-min cadence.
- **quick_scan.py / scan_64b.py / scout_temp*.py** — scout bulk exploration.
- **temp_check_wave8_state.py** — S10 wave-8 checkpoint investigation.
- **test_compiler.py** — compiler-flag matrix explorer; frozen because
  `memory/project_sn_compiler.md` codifies the findings.

## Policy

- These scripts may be `grep`'d or read for historical reference.
- Do **not** call them from CI or worker scripts — if you need the
  behavior, promote the relevant logic to `tools/` as a first-class
  utility (following the `feedback_review_shared_infra.md` proposal rule).
- If you prove a script here is genuinely dead after S14+, it can be
  deleted outright.
