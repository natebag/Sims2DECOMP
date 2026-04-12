# Attack Plan — Session 3: "The Dedup + Family Spotter"

**Date drafted:** 2026-04-11 (end of "The Matcher Bot" session)
**Target session:** 2026-04-13+
**Baseline entering this session:** 8,773 / 20,508 files (42.78%), 7,820 unique addresses (38.13%)
**Session goal:** Dedupe 953 file aliases to honest metrics, introduce Family Spotter role, push to **9,500+ unique-address matches (46%+)**

---

## Context — What Just Happened

"The Matcher Bot + 40 TU Club" session (2026-04-11) landed:
- **+541 file matches** in one session (8,232 → 8,773), approx **+350 unique addresses**
- **91 commits** across 10 agents
- **Matcher bot built and validated** — `tools/matcher_bot.py` with 10+ mutators (A1→A2→A3→M12), 36-44% hit rate on random-pool near-misses
- **4-way parallel bulk blast** (940 files, 195 MATCH outcomes, ~192 committed) — first fleet-scale automated matching
- **3 ctor family patterns discovered** (A: vtable-only 20B, Z: pure-zero-field 20-52B, W: 56B state-machine) → +57 matches from just 3 initial cracks
- **Integrity audit landed** — 215 fake matches purged (byte-injection + register-asm cheats), `gen_ctor_matches.py` deleted, `verify_match.sh` hardened
- **15 infrastructure tool commits** — matcher_bot, bulk runner, shard splitter, git_safe wrappers ×3, rework_next.sh, verify_match --outdir fix, verify hardening
- **A5 parked-wall closures**: movieman (bot M3), EThread::SetupStack (bot A3 multi-barrier), MoviePlayerEndgameMovieState (Pattern W recognition)
- **0 bad commits reached main** across 91 commits

**What's parked for next session:**

### Parked walls (still unmatched)
- **audiostreamman 172B** — vtable-init from placement-new, compiler schedules freely. Needs M13 manual vtable init.
- **EResource ctor 48B** — ctor-return-value tail divergence. Needs source restructure.
- **ETexture ctor 96B** — store-combining wall (two `sth 64` → one `stw`). Needs barrier between non-adjacent fields.
- **QuickResFile GetString 188B** — SIZE_MISMATCH, source is structurally broken. Needs full rewrite from Ghidra.
- **socialmodeinteractor SetupInteractionMenu 200B** — basic-block layout divergence, not flag-fixable.
- **PiecewiseFn 28B + WidgetScreenFormat 28B** — scheduler ordering walls, need multi-swap M15 or hand-tune.

### Known issues
- **953 duplicate file aliases** in `src/matched/` — same function at same address, two files (case variants, worker race commits, placeholder + named). True unique count is 7,820, file count is 8,773.
- **~125 fake_matches files still untouched** — mostly complex ctors (SDA, loads, vtable+fields, control flow). Easy patterns exhausted.
- **Register-allocator walls** — new wall category discovered Session 2. DOL and compiled output pick different registers for `this` copies (r10 vs r11). Not flag-fixable, not text-mutator-fixable. Needs creative source-level hacks.

---

## The Strategic Pivot — Family Spotting + Honest Metrics

Session 2 proved two things:
1. **The matcher bot is a 36-44% weapon** on random near-miss pools. It's the default first pass.
2. **Family pattern recognition is the highest-ROI technique** — 3 families found (A/Z/W) → +57 matches from just 3 initial cracks. One person scanning for repeated asm signatures is an N× multiplier.

Session 3 combines both: **spot families first, then bot-blast them, then hand-crack the residual.**

But first: **the metrics are lying.** 953 duplicate aliases mean the file count and unique-address count diverge by 12%. Fixing this is both an integrity win and a UX win — future sessions need one honest number, not two.

---

## Session Goals — Triple Track

### Track A: Dedupe 953 Aliases (Day 1 priority)
Deliver a clean `src/matched/` tree where every function address has exactly one file.

**Approach:**
1. Build `tools/dedup_matched.py` — scan `src/matched/`, group files by canonical address (lowercase hex), identify duplicates
2. For each duplicate group: keep the file with the most descriptive name (named function > `func_XXXX` placeholder), delete the rest
3. Verify each kept file still passes `verify_match.sh`
4. Single atomic commit: `fix(dedup): consolidate 953 duplicate aliases in src/matched/ to unique-address canonical files`
5. Update `tools/count_matched.py` to report BOTH file count and unique-address count (already does, but make it the primary metric)
6. Update CLAUDE.md + README with the converged count

**Target:** file count = unique-address count = ~7,820 (may increase slightly if some "duplicates" are actually different functions at adjacent addresses)

### Track B: Family Spotter + Second-Wave Blast (primary match-count work)
**New role: Family Spotter** — one agent dedicated to scanning wip pools for repeated asm signatures before dispatching hand-crackers or the matcher bot.

**Approach:**
1. Family Spotter scans `src/wip/version_diff/` residual pool — group by DOL asm signature (prologue + first 3 instructions + epilogue pattern)
2. Each identified family gets ONE representative file cracked first (via matcher bot or hand)
3. On crack → template-replicate across all family members (the Pattern A/Z/W model from Session 2)
4. Parallel: run `matcher_bot_bulk.py` with live-state manifests (rework_next.sh-style dedup per invocation) on the non-family residual

**Target:** +200-400 unique-address matches from the shrunken version_diff/ + fake_matches/ pools

### Track C: New Mutator Research (stretch)
Investigate 2-3 new mutator types for the walls that Session 2 couldn't crack:

- **M13 manual vtable init** — replace `new(mem) Class` with explicit `*(int**)ptr = VT;` placement. Target: audiostreamman.
- **M14 field-decl reorder** — reorder struct fields to influence register allocation graph. Target: EResource ctor.
- **M15 multi-swap** — C(N,2) pairs of statement swaps, analogous to A3 multi-barrier. Target: PiecewiseFn, WidgetScreenFormat.

**Target:** prototype at least M13, test on 3+ stuck targets. If it cracks even 1, integrate into matcher_bot.py for the next bulk blast.

---

## Fleet Roster (10 agents — role adjustments from Session 2)

| Name | Model | Role | Primary Assignment |
|------|-------|------|--------------------|
| **MainGuy** | Opus 4.6 | Orchestrator | Dispatch + velocity tracking + dedup oversight |
| **OpusWorker** | Opus 4.6 | Architect + cracker | M13 mutator research + hard-wall hand-cracks |
| **SonnetWorker** | Sonnet 4.6 | Bulk blaster | Second-wave version_diff blast + TU completion |
| **SonnetWorker2** | Sonnet 4.6 | Infrastructure + dedup | Build dedup_matched.py + dedup execution |
| **KimiGuy** | Kimi | **Family Spotter (NEW)** | Scan wip pools for asm signature families |
| **KimiWorker** | Kimi | Bulk applier | Family-template replication + bot batch runs |
| **Kmiworker2** | Kimi | Bulk applier | Parallel bot batch runs |
| **TUScout** | Kimi | TU enumeration | Rank near-complete TUs post-dedup |
| **Reviewer** | Kimi | Rolling audit + velocity | QA gate + matches/hour metric |
| **Researcher** | Kimi | Deep RE | Wall analysis for M13/M14/M15 targets |

---

## Rules (carried from Sessions 1+2 + new)

1. **Always 10+ tasks queued** — no idle workers
2. **Kimi scouts → Claude/Opus crackers** — delegation by strength
3. **verify_match.sh is the gate** — mandatory, hook-enforced
4. **Commit every 3-8 matches** — keep git flowing
5. **Broadcast breakthroughs** — new flag combos, source-level tricks, any unlock
6. **No inline asm that generates instructions** — compiler barriers (`asm volatile("" : : : "memory")`) ALLOWED; `register T asm("rN")` FORBIDDEN
7. **DVD map for addresses** — NOT release map. cm3-build22.
8. **Header format: `// 0xADDRESS FuncName (SIZEb)` first line**
9. **Near-miss files first** — check `src/wip/version_diff/` before writing from scratch
10. **TU completion > scattered matches** — still true
11. **Velocity tracking** — every worker publishes `matches committed / minutes active` every 10 min
12. **Matcher-bot before manual grinding on walls** — bot first, hand-tune after
13. **Specific-paths `git add` always** — no `git add -A`
14. **Verify SIZE against DVD map before every commit**
15. **Use `tools/git_safe_stage_and_commit.sh`** for all match-file commits (atomic, race-safe)
16. **Use `tools/rework_next.sh`** before picking rework targets (dedup-aware live-state)
17. **NEW: Address-based dedup before any rework** — `git ls-files src/matched/ | grep -i 0x<addr>` before every commit
18. **NEW: Family spotter first pass** on any new pool before dispatching crackers
19. **NEW: Bot is useless on __asm__ fake sources** — write a C++ skeleton FIRST, then bot-blast for flag/mutator optimization

---

## Session Phases

### Phase 1: Dedup + Metrics Reset (30-45 min)
- SonnetWorker2: build + execute `tools/dedup_matched.py` → 953 aliases consolidated
- TUScout: rank near-complete TUs using the clean post-dedup state
- KimiGuy (Family Spotter): begin scanning `src/wip/version_diff/` for asm signature families
- Everyone else: pull latest, verify hooks, confirm baseline numbers

### Phase 2: Family Spotter Blast (60-90 min)
- KimiGuy reports family list with member counts
- For each family: one representative cracked (via matcher bot or hand), then template-replicated
- Parallel: SonnetWorker + KimiWorker + Kmiworker2 run `matcher_bot_bulk.py` with live-state manifests on the non-family residual

### Phase 3: TU Completion Push (60 min)
- TUScout's ranked list drives dispatch
- OpusWorker + SonnetWorker target near-complete TUs (1-3 functions missing)
- Each TU completion = a visible milestone

### Phase 4: M13 Mutator Research (stretch, 30-60 min)
- OpusWorker + Researcher prototype M13 on audiostreamman
- If crack: integrate into matcher_bot.py, re-run on other stuck targets
- If miss: document findings for Session 4

### Phase 5: Wrap (15 min)
- Commit all in-flight work
- Reviewer: final tally, TU count
- MainGuy: write `next-attack-plan-YYYYMMDD.md` for Session 4

---

## Success Criteria

| Metric | Target | Stretch |
|--------|--------|---------|
| 953 aliases deduped | Yes | — |
| File count = unique-address count | Yes | — |
| New families found by spotter | ≥3 | ≥6 |
| New matches (unique addresses) | +200 | +400 |
| Unique-address total | 8,020 (41%) | 8,220 (42%) |
| TUs at 100% (post-dedup) | count established | +5 completions |
| M13 prototype working | Yes | M13 cracks ≥1 target |
| Bad commits reaching main | **0** | 0 |

---

## Pre-Session Checklist

```bash
# 1. Pull and verify
cd "F:/coding/Decompiles/Sims 2"
git pull origin main
git log -1 --oneline  # confirm at 82bfbad0 or later

# 2. Confirm hooks installed + executable
ls -la .git/hooks/pre-commit
bash .git/hooks/pre-commit < /dev/null 2>&1 | head -3

# 3. Confirm tools work
python tools/count_matched.py 2>&1 | head -5    # should show 8773 files / 7820 unique
bash tools/rework_next.sh --count 5              # should return 5 untouched candidates
python tools/matcher_bot.py --help               # should print usage

# 4. AgentOrch workspace with 10-agent roster
#    Same lineup: MainGuy, OpusWorker, SonnetWorker, SonnetWorker2, KimiGuy,
#    KimiWorker, Kmiworker2, TUScout, Reviewer, Researcher
```

---

## Notes to Future MainGuy

- **Dedup FIRST.** Don't let any worker start matching until the 953 aliases are consolidated. Otherwise new matches on dedup'd addresses create MORE duplicates.
- **Family Spotter is the force multiplier.** Session 2 proved: 3 families = +57 matches. Session 3 should find 3-6 more families in the remaining 900+ version_diff files. Each family of size N gets cracked in time(1) + time(N-1) × copy ≈ time(1) + N seconds.
- **The matcher bot on fake_matches is useless** until a C++ skeleton replaces the `__asm__` injection. `verify_match.sh` rejects `__asm__` immediately, so the bot grades 0% across all variants. SonnetWorker discovered this in Session 2. Write skeleton first, THEN bot-blast for optimization.
- **Register-allocator walls are the new frontier.** M1-M12 are all scheduling / ordering / CSE tools. The remaining hard walls are RA-specific: DOL picks r10 for `this`, our compiler picks r11, and no flag or source-level trick found so far can coax a different choice. M13/M14 are the first attempt at this. If they fail, we may need to accept ~50-100 functions as "RA-blocked" and move on.
- **`git_safe_stage_and_commit.sh` is mandatory.** Session 2 had 3 stale-lock incidents and 2 commit-hygiene incidents. The wrappers saved the fleet from a 53-minute hang. Don't ship without them.
- **Session 2's retrospective info note `bd8d6752`** has the full canonical record. Read it if you need to reconstruct what happened.

---

## Closing

Session 2 built the tooling. Session 3 uses it. The matcher bot, the family blast model, the dedup helper, the git-safe wrappers — all exist now. Session 3 is about **harvesting at scale with honest metrics**.

The 953 dedup is a one-time cost that pays forever — after that, every number we publish is trustworthy. The family spotter role is the new meta: find a pattern once, replicate it N times. The remaining ~900 version_diff files are a rich vein for both.

Target: 8,020 → 8,220+ unique addresses (41% → 42%+). Honest numbers, compounding velocity, fleet self-optimizing.

Let's cook.
