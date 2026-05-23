# Roadmap

## What's done

- ✅ **100% byte-match on `.text`** — closed in the marathon session, 4,145,724 / 4,145,724 bytes
- ✅ **Stub-to-real-C++ Phase 1 (S17)** — semantic ratio climbed from 50.4% → 56.7%
- ✅ **Cleanup pillar** — ~1,088 historical duplicate stubs purged
- ✅ **Data tracking** — `.data` family pillar instrumented; current baseline 9.21%
- ✅ **Tooling foundation** — `inject_matches.py` subdir fix, multi-format annotation regex, build path corrections (KimiWorker S17 work)

## What's next (S18+)

### Priority 1 — Per-agent worktrees
The single biggest architectural lesson from S17: a shared git working tree across multiple agents causes wildcard-staging incidents even when operators are disciplined. Three such incidents happened in S17 — all resolved cleanly, but the recurrence vector exists structurally. Moving to per-agent worktrees eliminates the entire incident class.

### Priority 2 — Net-new-address targeting for semantic ratio
The semantic-ratio classifier dedupes by unique address. Polishing already-counted addresses produces 0 ratio gain. Future sessions should default to `find src/matched -name "match*<ADDR>*.cpp" | grep -v agent/` checks before claiming work — pick the addresses that move the metric.

### Priority 3 — Data section conversion
Now that `.data` family tracking is live (9.21% baseline), the data pillar is open work:

- **`.dtors` (360 B at 0%)** — declare static destructor table → easy quick win
- **`.ctors` (644 B at 2%)** — declare static constructor table → easy quick win
- **`.rodata` (362 KB at 17%)** — vtable conversion per class (TypeArch headers already document layouts)
- **`.data` (306 KB at 0.25%)** — biggest opportunity (initialized globals, lookup tables, game-state structs)

### Priority 4 — Deep-RE on `objectsim` TU
The single largest deep-RE opportunity in the project. ~91 KB of `cXObjectImpl` methods in a separate TU — `Simulate`, `Try*` dispatchers, `KillSelf`. Multi-hour cracks per function. Scout intel (`m_objectTypeKey @ 0x488`, vtable layout) already banked from S17.

### Priority 5 — Cross-canonical-dir cleanup
~22 `targets_s2c` ↔ `famtarget` cross-canonical-directory duplicates remain (Phase A-E focused on `agent/` dupes). Quick hygiene pass.

## Stretch goals

- **PC port** — gated on bringing semantic ratio above ~80% across all major game-logic subsystems. A real, multi-year direction.
- **Mod tooling** — the matching infrastructure could support modifiability beyond byte-match (e.g., custom interactions, custom assets) once semantic recovery is high enough that authors can read what they're modifying.
- **Companion documentation** — character lore, asset format reverse-engineering, behavior-tree semantics. The empirical work done during the marathon (5 misnomer corrections, hot-field identification) is the first chapter of this.

## Session cadence

Marathon sessions like S17 produce the bulk of bulk-conversion output. Between marathons, smaller maintenance sessions can handle:

- Cleanup audits + cross-canonical hygiene
- New misnomer corrections from contributor work
- TypeArch header amendments as new fields surface
- decomp.dev metric drift watch

There's no fixed cadence. The repo is in a stable state — every commit verifies. Work resumes whenever someone has a multi-hour window and a target subsystem.
