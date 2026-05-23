# The Marathon

## The setup

Nine specialized agents, one shared git working tree, one orchestrator, one goal: take The Sims 2 GameCube from 11.50% byte-match to as close to 100% as we could push in a marathon window. Fleet composition was tuned per session as the work changed character.

## The arc, in milestones

| Marker | What changed |
|--------|--------------|
| **11.50% → 12%** | False-alarm milestone broadcast (stale `report.json` reads). Established the "canonical 2x-regen + diff" verification discipline that prevented every subsequent miscount. |
| **12% → ~13%** | Hand-cracked phase. Family-blast methodology proved out on TileWalls, INVTarget, BBHTarget, HUDTarget, EI-Light family, ChainResFile / IFFResFile2 / Behavior::Get*. |
| **~13% → 99.8%** | Tooling unlock. `gen_stubs.py` decoder cascade (`bl`/`bc` → `blrl` → 512B/2KB/8KB body decoders) generated ASMPROC `inject_before` directives for thousands of functions. Each byte-identical, none readable C++. |
| **99.8% → 100%** | Mop-up. 10 final SDK functions cracked individually, including the VMBASE DSI/ISI exception handler twin pair. |
| **100% → S17** | Stub-to-real-C++ Phase 1. Semantic recovery climbed from 50.4% → 56.7% across the fleet. ~1,100 historical duplicate stubs purged. |

## The protocol stack

The fleet ran on a small set of explicit invariants:

1. **`verify_match.sh` before every commit** — non-negotiable. Pre-commit hook re-verifies on every commit; a commit that drops the byte-match floor is reverted immediately.
2. **`git commit --only <explicit paths>`** — never wildcard staging. Three wildcard incidents during S17 ultimately validated this rule (see below).
3. **Reviewer canonical-metric verification** — every milestone broadcast had to be backed by `git show HEAD:build/G4ZE69/report.json` analysis, not session-local memory.
4. **Lane ownership** — each writer owned a specific subset of `src/matched/<dir>/`; cross-lane touches required a DM-coordinated handoff.

## What broke (and what we learned)

- **Three wildcard-staging incidents** in S17. Despite disciplined operators, a `git commit --only <dir>` pattern silently swept files staged by other workers because all agents shared the same git index. The fix: `git commit --pathspec-from-file=<list>` with literal file lists. The architectural fix: per-agent worktrees in S18+.
- **Pre-existing duplicate files** in `src/matched/agent/` accumulated over earlier sessions. Total dupes purged in S17: **~1,112 files across 5 cleanup phases**. The pre-commit hook's dupe detection now keeps this from accumulating again.
- **Plan-doc class names were inferences, not facts**. TypeArch's empirical layout work corrected five misnomers (`cXRoom` → `ERoom`, `cXCamera` → `ESimsCam`, `cXRouting` → `XRoute`, `cXObjectSim` → `objectsim` TU, `SAnimator2Bone` → disproved). The empirical pass is the authority.
- **Semantic-ratio metric ≠ work done**. Late-session insight: writers polishing already-counted addresses produced "0 ratio gain" even though the conversions made the code more readable. We adopted a **three-axis value framing** (public floor / semantic ceiling / code quality) for honest reporting.

## What the marathon shipped

| Lane | Output highlight |
|------|------------------|
| Lane 1 — Targets-family | 35 semantic conversions, 15 commits, scout-helper evolution |
| Lane 2 — Object family | 42 conversions / 708B real semantic + RTTI recovery |
| Lane 3 — Reviewer + person | 86-target person pool re-survey, classifier discipline |
| Lane 4 — TypeArchaeologist | 13 substantive headers + 5 misnomer corrections in ~95 min |
| Lane 5 — Animation family | 230+ conversions + 1,241-file refactor |
| Lane 6 — Mid-tier systems | 250 conversions across eroom / camera / xrouting |
| Lane 7 — SDK / APT batch | 21 conversions + 3 critical tooling bug fixes |
| Lane 8 — Coordinator | 5 cleanup phases (~1,100 dupes) + policy formalization |

Total: 91 commits pushed in the session, floor 100.0000% throughout, zero reverts.
