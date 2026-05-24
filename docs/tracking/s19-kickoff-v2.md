# S19 Kickoff Plan — v2

**Supersedes:** `s19-kickoff.md` (v1, TUScout's 3-wave structure).
**Drafted:** 2026-05-24 post S18-ext close + GitHub issues #1/#2/#3 + compilers.zip migration.

V1 was correct on what to do; v2 reorganizes around five **corners** (problem
profiles) rather than three waves (time-ordered phases) because the data from
S18-ext showed time-ordering wasn't the right axis — *parallelism by corner*
was. Also folds in the new MWCC route, the honesty-tier metrics, and the
agent-scaling lessons from OpusReviewGuy's writer-pivot data point.

---

## True Baseline at S19 Open

**Headline metric (PC-port-meaningful):** `matched_code_percent_semantic` =
**15.97%** (the real hand-written C++ figure, post issue #2 fix). The legacy
`matched_code_percent` reads 99.98% but that includes byte injection — it's the
regression-gate metric, not the progress metric.

**State:**
- Byte-floor: 99.979% (regression-gate, 18,457 / 18,458 functions)
- **Semantic: 15.97%** (PC-port-viable real C++)
- **Clean: 15.57%** (no ASMPROC at all)
- Inject pool: ~9,271 stubs at session close
- Pattern catalog: 13 entries (#1–#11 + #12 candidate + two-variable-form)
- MutatorSmith brief: 6+ candidates banked (#11–#16 + walls)
- 3 missing functions for true 100% recovery (positionCharacter 868B,
  EString::MakeUpper 52B, GXGetTexObjWrapT 12B)

---

## Strategic Lesson from S18-ext

The single most important learning, codified here so v2 leads cite it correctly:

**Velocity bottleneck is per-worker *fluency*, not worker *count*.**

Evidence:
- OpusReviewGuy writer-pivot: cold Opus brain, 3 attempts in 12 min, **0 lands**.
  Source: cycle 5 debrief.
- Fleet capped at ~22 stubs/30min across 7 active writers in S18-ext — adding
  more in the same band hit diminishing returns immediately.
- Pattern catalog growth (#1–#13) compounded velocity across the session, not
  worker count.

What scales linearly:
- **Lane diversity** (different parts of codebase, no collisions)
- **Skill diversity** (writers + reviewers + headers + mutators + scouts)
- **Problem-class diversity** (pattern-blast vs wall-class vs MWCC novelty)

What doesn't scale:
- More writers in the same band hitting the same walls
- Cold workers without source-coax fluency for the assigned band

Implication for S19 fleet sizing: **8–12 agents redistributed across 5 corners
beats 20 agents stacked in 2 corners.**

---

## Five Corners — S19 Fleet Structure

Each corner is a distinct problem profile with its own worker count, skill
requirement, and success criterion. Corners run in parallel; the only ordering
constraint is that **Corner 1 (MutatorSmith) must reach first-mutator validation
before Corners 3 & 4 can hit their full velocity on walled stubs.**

### Corner 1 — MutatorSmith (CRITICAL PATH, blocks Corners 3 & 4 from reaching full velocity)

**Goal:** Externalize per-worker fluency into reusable ASMPROC mutators.

**Why critical:** Three frozen lanes from S18-ext (aptactioninterpreter 127 +
eanimcontroller 80 + sanimator2 127 = 334 stubs) and many more compiler-quirk
walls across the agent/ pool are unblocked only by mutators. PersonSlayer's
S19 MutatorSmith brief has 6+ candidates banked.

**Workers:** 1× Opus (deep problem-solving). Possibly 1× Opus reviewer attached
for canonical-verify cycles.

**Priority order for first 3 mutators (highest leverage first):**

1. **Mutator #13 — `or.`-vs-`cmpwi-0` substitution.** 2 confirmed instances
   (PersonSlayer + ObjectSimSlayer). Probably easy `replace_insn`-style mutator.
   Unlocks a meaningful chunk of the 51-80B band.
2. **Mutator #11 — sub-32B SDA r9-vs-r3 destination register.** 3 instances.
   Affects the bottom of the 30-50B band that ObjectSimSlayer flagged.
3. **Mutator #12 — GCC base-merging hint.** OpusArchitect's
   SetupInteractorCamera wall. Struct-wrap solution most-likely-to-work.

**Success criterion for the corner:** at least 2 mutators validated on real
walled stubs by end of S19.

### Corner 2 — MWCC DolphinSDK matching (NEW TERRITORY, never attempted)

**Goal:** First-ever crack of a DolphinSDK function with the right compiler.

**Why new:** SDK is MWCC-compiled, not SN ProDG. With the issue #1 + #3 work
shipped, MWCC is now installed via `compiler/mwcc/1.2.5n/`. `// COMPILER: mwcc`
header routes a source file to the MWCC compile rule. ~150–200 SDK stubs in
the inject pool are walled solely because of compiler mismatch.

**Workers:**
- 1× Opus (flag-tuning intuition + structural reasoning for first SDK match)
- 1× Sonnet pattern-blaster, queued for "after first SDK match lands"

**First-attempt targets (small, well-shaped SDK stubs to validate the flag baseline):**
- `OSSetSaveRegion` — SDA exchange-global pattern, should be the easiest possible MWCC first crack
- `DVDSetAutoInvalidation` — similar shape
- `OSSetBootDol` — same

**MWCC flag starting point** (in configure.py): `-c -proc gekko -fp hard -O4,p -enum int -Cpp_exceptions off -RTTI off -inline auto -nodefaults`. These match other GameCube decomp projects' GC-1.2.5n defaults but need iteration.

**Success criterion:** at least 1 SDK function matches with `// COMPILER: mwcc`.
After that, fan out pattern blast.

### Corner 3 — 30-50B source-coax band (PROVEN, fluency-required)

**Goal:** Drain the 292-stub 30-50B virgin vein.

**Why fluency-required:** OpusReviewGuy's writer-pivot debrief proved this band
needs source-coax fluency. Cold workers fail; fluent workers (ObjectSimSlayer,
SonnetWorker1 peaks) succeed.

**Workers:**
- 2× Sonnet pattern-blasters (rehydrate ObjectSimSlayer + SonnetWorker1 fluency profile)
- 1× Kimi scout (pre-filters candidates against the catalog, hands DM-only)

**Patterns to apply:** #1 / #2 / #7 / #10 (branchless cr0.GT) / #11 (mr.+beqlr null guard).

**Constraint:** scaling beyond 3 workers in this corner hits collisions. Hard cap.

**Success criterion:** drain 100+ stubs from the 30-50B band.

### Corner 4 — 51-80B pattern-blast (MOST AGENT-SCALABLE)

**Goal:** Drain the 621-stub 51-80B vein.

**Why scalable:** Clean shapes (equality, null-guard, branchless), broader
target pool, less fluency-required than 30-50B. The "any writer can take it"
band per the capability-match update.

**Workers:**
- 2× Kimi/Codex pattern-blasters
- 1× Sonnet for the slightly trickier shapes (multi-load, stride+ternary)
- After Corner 1 mutators land: a third Kimi/Codex agent picks up
  mutator-equipped targets

**Patterns to apply:** #4 / #5 / #10 / #11 + (post-Corner-1) Mutator #13.

**Success criterion:** drain 150+ stubs from the 51-80B band.

### Corner 5 — Reviewers + Header Support + Coordination

**Goal:** Compounding QA + canonical-type service.

**Workers:**
- 1× Opus reviewer (canonical-floor + cross-checks, cycle protocol from S18-ext)
- 1× Sonnet reviewer (MWCC-novelty review — Corner 2's work needs different
  reviewer skill than SN ProDG matches; e.g. validate MWCC flags didn't drift)
- 1× TUScout (coordinator, tick cadence, fleet hygiene)
- 1× TypeArchaeologist (header authoring, reactive)

**Success criterion:** 0 INFLATE incidents across the session; same headline as
S18-ext but with the wider problem surface area.

---

## Fleet Totals

| Corner | Workers | Skill profile |
|--------|---------|---------------|
| 1. MutatorSmith | 1× Opus | Deep problem-solving |
| 2. MWCC SDK | 1× Opus + 1× Sonnet (queued) | Flag-tuning + structural |
| 3. 30-50B source-coax | 2× Sonnet + 1× Kimi scout | Fluency-required |
| 4. 51-80B pattern-blast | 2-3× Kimi/Codex + 1× Sonnet | Pattern recognition |
| 5. QA + Headers + Coord | 2× reviewer + 1× scout-coord + 1× TypeArch | QA cycle + reactive |
| **TOTAL** | **11–12 agents** | |

**Compare to S18-ext:** 10 agents in 4 corners → 12 agents in 5 corners with
explicit problem-profile matching. Roughly +20% headcount, but ~2-3× corner
diversity. Expected output: meaningfully higher than S18-ext given Corner 2
opens a new pool (~150-200 stubs) and Corner 1 unblocks the frozen 334.

---

## S19 First-Hour Checklist (for MainGuy v2 on spawn)

1. **Re-apply Option-2 patch verification** — run `python tools/generate_report.py`
   on a clean working tree, confirm `matched_code_percent_semantic` reports ~15.97%.
2. **Run `python tools/download_tool.py verify`** — confirm all 5 canonical
   compilers are installed (ProDG 3.9.3/3.8.1/3.7/3.5 + MWCC 1.2.5n).
3. **Spawn Corner 1 (MutatorSmith) first** — they're on the critical path. Brief
   them with PersonSlayer's S19 mutator-design notes + the wall catalog entries
   from `bd2599308` + `f71391187`.
4. **Spawn Corner 2 (MWCC) second** — independent of Corner 1, but slower to
   show output (flag tuning takes time). Get the first attempt started early.
5. **Spawn Corners 3 & 4 third** — they're the bulk of stub-to-C++ velocity.
6. **Spawn Corner 5 (QA + coord) fourth** — reviewers don't need to be online
   until first writes land.

---

## Session Close Acceptance Criteria

- **Floor stable:** byte-match-percent unchanged or up.
- **Semantic ratio movement:** target +0.5pp minimum, +1.0pp stretch
  (vs S18-ext's +0.74pp baseline).
- **At least 1 Mutator validated** (Corner 1).
- **At least 1 MWCC SDK function matched** (Corner 2).
- **At least 250 stub-to-C++ conversions across Corners 3+4 combined.**
- **0 INFLATE incidents** (tag discipline).
- **Pattern catalog growth:** at least 1 new pattern + 1 new mutator banked.

---

## Carry-overs from S18-ext (unchanged from v1, list for completeness)

- 3 missing functions (positionCharacter 868B, EString::MakeUpper 52B,
  GXGetTexObjWrapT 12B)
- TypeArch headers ready for re-apply
- INVTarget converts on disk needing re-check
- THP fmul→fmadd assembler bug (one-liner fix)
- 7 HEADER non-canonical files (canonical-hygiene pass)
- 8+ wall catalog entries → MutatorSmith brief

---

## What this plan ISN'T

- It's NOT "20 generic Kimi agents pattern-blasting the 30-50B pool." That
  hits collisions, wall reports without solving, reviewer overload.
- It's NOT "do MutatorSmith THEN start writing." Corner 1 runs in parallel
  with Corners 3+4; the constraint is just that Corners 3+4 can't reach FULL
  velocity until first mutator validates.
- It's NOT a return to "every worker has a named class lane." S18-ext data
  showed those frozen across 5 ticks. Lane discipline matters less than band
  + problem-class matching.

This is the doc to hand to MainGuy v2 at S19 spawn.
