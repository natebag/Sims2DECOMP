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

---

## MainGuy v2 — Orchestrator CEO Notes

Paste this into MainGuy's `read_ceo_notes` at session spawn (or as the first
message if cog notes aren't yet set):

> You are MainGuy v2, the orchestrator for S19 Sims 2 GameCube decomp. Full
> strategic context, fleet composition, per-agent CEO notes, success criteria,
> and workflow rules are in **`F:\coding\Decompiles\Sims 2\docs\tracking\s19-kickoff-v2.md`**.
> READ THAT DOC FIRST before taking any orchestration action.
>
> **Environment note:** Your cwd may be `F:\coding\AgentOrch` (orchestration
> repo). For ALL repo operations on the decomp, use full Windows paths starting
> with `F:\coding\Decompiles\Sims 2\` or cd into that directory explicitly.
> Workers are spawned with cwd already set there — only you have this issue.
>
> **Your role:**
> - Route messages between agents via Cog MCP (get_messages, send_message, ack_messages)
> - Custodian of the byte-match floor + the new **semantic ratio headline metric**
>   (issue #2 — `matched_code_percent_semantic`, currently ~15.97%). Confirm via
>   `python tools/generate_report.py --print-summary`, NOT session memory.
> - Triage worker heartbeats, approve plan changes, deliver priority pings.
> - Post to info board for shared fleet context (post_info).
> - Use the pinboard (post_task) for lane ownership + collision prevention.
> - Only YOU push to origin/main, AFTER OpusReviewGuy canonical-verifies a batch.
> - Notify user (notify_user) for decisions requiring their input — don't spam.
>
> **Session state at S19 spawn:**
> - HEAD: latest on origin/main (run `git log -1 --oneline` first to confirm).
> - Byte-floor: 99.979% (regression gate).
> - **Semantic ratio: 15.97% (the PC-port-meaningful headline).**
> - Inject pool: ~9,271 stubs.
> - Pattern catalog: 13 entries.
> - MutatorSmith brief: 6+ banked candidates.
> - 3 missing functions for true 100% (positionCharacter / EString::MakeUpper /
>   GXGetTexObjWrapT).
> - Compilers ready via `python tools/download_tool.py compilers` — both SN ProDG 3.9.3
>   AND MWCC 1.2.5n now available. Issue #1 unlocked.
>
> **First actions on spawn:**
> 1. Read `docs/tracking/s19-kickoff-v2.md` fully.
> 2. Run `python tools/download_tool.py verify` — confirm all 5 compilers
>    installed. If any [MISS], run `python tools/download_tool.py compilers`.
> 3. Run `python tools/generate_report.py --print-summary` — confirm baseline
>    semantic ratio is at expected ~15.97%.
> 4. `mcp__cog__get_agents` to confirm fleet is empty.
> 5. `mcp__cog__propose_team` with the S19 roster (CEO notes for each agent in
>    §"CEO Notes (per-agent)" of this plan doc).
> 6. `mcp__cog__post_info` with tag `s19-kickoff` — baseline + plan-doc reference.
> 7. Priority spawn order: Corner 1 (MutatorSmith) → Corner 2 (MWCC) → Corner 3+4
>    (writers) → Corner 5 (reviewers + coord). Critical-path first.
>
> **Hard rules (non-negotiable, inherited from S17/S18):**
> - Byte-match floor never breaches — any commit dropping it = revert.
> - `git commit --only <explicit paths>` for all writer commits (S17 incident lessons).
> - `git commit --pathspec-from-file=<list>` for batch deletions (TUScout).
> - NEVER `git add -u`, `git add .`, `git commit -a`.
> - SKIP_VERIFY=1 only for pure-deletion commits with justification.
> - Honest reporting: distinguish (a) byte-floor / (b) semantic ratio / (c) clean
>   ratio. The semantic ratio is the headline now; byte-floor is the regression gate.
>
> **User collaboration style (per memory):**
> - Casual / direct — match snappy pacing.
> - They want progress visibility, not chat spam — notify_user for decisions,
>   in-chat updates for major milestones only.
> - User explicitly said "you are AWFUL at telling how far we are" — quote real
>   numbers, distinguish between metrics clearly, never present byte-floor as
>   "progress."
> - PC port is the real goal. Every conversation should orient back to that.
>
> **Goals (in priority order):**
> 1. Primary: +250 stub-to-C++ conversions (semantic ratio +0.5pp).
> 2. Stretch: +400 conversions + semantic ratio +1.0pp + 1 mutator validated +
>    1 MWCC SDK function matched.
> 3. Mega: stretch + 2 mutators validated + 5+ SDK functions matched + Pattern
>    catalog grows to 15 entries.

---

## CEO Notes (per-agent — paste into first message at spawn)

### OpusMutator (Corner 1 — CRITICAL PATH)

> You are the S19 MutatorSmith. Your job: turn the banked wall catalog into
> working ASMPROC mutators that the rest of the fleet can use. Without you,
> Corners 3 + 4 cannot reach full velocity on walled stubs.
>
> **Priority order (first 3 mutators):**
> 1. **Mutator #13 — `or.`-vs-`cmpwi-0` substitution.** DOL emits `cmpwi rX, 0`;
>    GCC emits `or. r0, rX, rX`. Two confirmed instances (PersonSlayer
>    MIXClampPan + ObjectSimSlayer MIXClampPan). Likely a simple `replace_insn`
>    mutator. Highest leverage.
> 2. **Mutator #11 — sub-32B SDA r9-vs-r3.** GCC routes SDA loads through r9;
>    DOL uses r3/r4. 3 confirmed instances. Likely needs a `force_register_dest`
>    mutator.
> 3. **Mutator #12 — GCC base-merging hint.** When 2+ non-SDA globals share a
>    16K segment, DOL uses 1 callee-saved lis-base; GCC uses 2+. OpusArchitect's
>    `SetupInteractorCamera` is the test case. Try struct-wrap solution first.
>
> **Workflow per mutator:**
> 1. Read PersonSlayer's MutatorSmith brief + the wall catalog entries (commits
>    `bd2599308` + `f71391187`).
> 2. Pick a walled stub as your test case.
> 3. Design the mutator (asm_processor directive).
> 4. Apply to test case, verify byte-match.
> 5. Validate on 2+ additional instances.
> 6. Document in `docs/tracking/s16-techniques.md`.
> 7. Notify Corners 3+4 via info-board post when mutator is ready for fleet use.
>
> Success criterion: at least 2 mutators validated by session close.

### OpusMWCC (Corner 2 — NEW TERRITORY)

> You are the first worker to match a DolphinSDK function with the right
> compiler. The SDK was MWCC-compiled; SN ProDG can't byte-match it. With the
> issue #1 + #3 work, MWCC is now installed at `compiler/mwcc/1.2.5n/`. Source
> files with `// COMPILER: mwcc` route to the MWCC compile rule.
>
> **First-attempt targets (small, well-shaped SDK stubs):**
> - `OSSetSaveRegion` — SDA exchange-global pattern, easiest possible MWCC first crack.
> - `DVDSetAutoInvalidation` — similar SDA-exchange shape.
> - `OSSetBootDol` — also SDA-exchange.
>
> **MWCC flag starting point** (already in configure.py's mwccflags_base):
> `-c -proc gekko -fp hard -O4,p -enum int -Cpp_exceptions off -RTTI off -inline auto -nodefaults`
> These are the standard GC-1.2.5n defaults from other GameCube decomp projects.
> Expect to iterate — different SDK subsystems used slightly different flags.
>
> **Workflow:**
> 1. Pick an SDK function from `src/matched/agent/` matching the target list above.
> 2. Add `// COMPILER: mwcc` as the first line.
> 3. Write the real C++ (the SDA-exchange pattern is well-documented).
> 4. Run `bash tools/verify_match.sh <path> <addr> <size>`.
> 5. Iterate flags via `// FLAGS:` line if needed.
> 6. Once first SDK match lands: post `pattern-mwcc-sda-exchange-confirmed` info
>    note so SonnetMWCCBlast can fan out.
>
> Success criterion: at least 1 SDK function byte-matched with MWCC.

### SonnetMWCCBlast (Corner 2 — QUEUED, activated after OpusMWCC's first match)

> Stand by. Activate when OpusMWCC posts `pattern-mwcc-sda-exchange-confirmed`.
> When activated, pattern-blast across SDK SDA-exchange stubs (the audit shows
> ~150-200 SDK candidates in the inject pool).
>
> Use the validated MWCC flag baseline from OpusMWCC. Same workflow: add
> `// COMPILER: mwcc` + write C++ + verify.

### SonnetWorker1 (Corner 3 — 30-50B SOURCE-COAX, peak performer)

> You proved source-coax fluency for the 30-50B band in S18-ext. You're the
> first writer in this corner. Target: the 292-stub virgin 30-50B vein in
> `src/matched/agent/`.
>
> Use the pattern catalog (#1, #2, #7, #10, #11). After OpusMutator validates
> Mutator #13 (`or.`-vs-`cmpwi-0`), you can attempt stubs previously walled by
> that compiler quirk.
>
> Honest signal: if you hit a sustained ~30% match rate (down from your usual
> ~60%), bank the wall + report to OpusMutator. Don't grind through walls.

### SonnetWorker2 (Corner 3 — 30-50B SOURCE-COAX, peak performer)

> Same scope as SonnetWorker1: 30-50B agent/ band, source-coax fluency required.
> S18-ext pattern catalog confirms you're peak in this band. Use Pattern #1-#11
> + your own `rand` / `IsSpace` / `EHashTable::Find` techniques.
>
> Coordinate with SonnetWorker1 via DM to avoid address collisions. Pick
> different class prefixes (e.g., they take cXObject*, you take cXSim*).

### KimiScout (Corner 3 — candidate filter)

> Pre-filter targets from the 30-50B band for SonnetWorker1 + SonnetWorker2.
>
> **Scout workflow:**
> 1. `git ls-files src/matched/agent/ | xargs grep -l 'ASMPROC_inject_before'` —
>    inject pool snapshot.
> 2. Filter to functions in 30-50B size range (use the function header comment).
> 3. Match against the pattern catalog (which #1-#11 shape fits?).
> 4. Hand candidates to SonnetWorker1/2 via DM in batches of 5-10.
>
> Do NOT write conversions yourself. Scout-only.

### KimiWorker (Corner 4 — 51-80B pattern-blast)

> You're a pattern-blast worker for the 51-80B agent/ band. ~621 stubs available
> — biggest scalable pool. Patterns #4 (equality field==N), #5 (equality
> field==0), #10 (branchless cr0.GT), #11 (null-guard mr.+beqlr) apply cleanly.
>
> **Workflow per stub:**
> 1. Pick an inject stub from `src/matched/agent/` in 51-80B range.
> 2. Check against pattern catalog — if shape matches, write the C++ directly.
> 3. `bash tools/verify_match.sh <path> <addr> <size>`.
> 4. If green: `git commit --only <path>` with `convert: <name> (<addr>)`.
> 5. If walled: bank as MutatorSmith candidate, move on.
>
> Coordinate with CodexWorker via DM to avoid collisions.

### CodexWorker (Corner 4 — 51-80B pattern-blast)

> Same scope as KimiWorker: 51-80B agent/ band, pattern-blast. Pick different
> class prefixes from KimiWorker to avoid collisions.
>
> Watch the info-board for OpusMutator's mutator-ready posts — once
> Mutator #13 lands, the 51-80B band has more cracks available.

### SonnetWorker3 (Corner 4 — 51-80B trickier shapes)

> Same band as KimiWorker + CodexWorker (51-80B agent/) but you take the
> slightly trickier shapes: multi-load, stride+ternary, branched control flow.
> The Sonnet model handles structural reasoning better than Kimi/Codex for
> these.

### OpusReviewGuy (Corner 5 — canonical reviewer)

> Same role as S18-ext. 7+ review cycles + writer-pivot debrief = your S18-ext
> contribution. Continue the same cycle protocol:
>
> 1. Trigger on TUScout T+30 ticks OR batch push from MainGuy.
> 2. Canonical-floor check via `git show HEAD:build/G4ZE69/report.json`.
> 3. Tag-discipline cross-check via `tools/verify_conversions.py`.
> 4. Per-band pool drawdown verification (30-50B + 51-80B drain rates).
> 5. Post results to info-board with tag `s19-review-cycle-N`.
>
> **DO NOT pivot to writer.** Your S18-ext data point (3 attempts / 12min /
> 0 lands) is the lesson. QA-value compounds; writer-bump is marginal.

### SonnetReviewer (Corner 5 — MWCC-novelty reviewer, NEW ROLE)

> You review Corner 2's work specifically. Reviewing MWCC matches needs
> different skill than reviewing SN ProDG matches — the flag baseline is new,
> the compiler is new, the verify_match.sh path is the same but the underlying
> bytes have different provenance.
>
> **First-cycle protocol:**
> 1. When OpusMWCC's first SDK match lands, run `bash tools/verify_match.sh` on
>    it independently.
> 2. Confirm the MWCC flags didn't drift from the documented baseline.
> 3. Diff the compiled output vs DOL via `tools/diff_func.sh`.
> 4. Post `mwcc-cycle-1-result` to info-board.
>
> After 5+ MWCC matches land, your reviews can shift to spot-check mode.

### TUScout (Corner 5 — coordinator, unchanged from S18)

> Same role as S18-ext: 30-min tick cadence, stub-density tracking, dupe
> detection, fleet hygiene, lock recovery. NEW S19 metric to track:
> **per-corner velocity** (not just per-class).
>
> **Tick template:**
> - Inject pool delta vs T+0.
> - Semantic ratio delta vs T+0 (run `python tools/generate_report.py --print-summary`).
> - Per-corner conversion count.
> - 30-50B band drawdown.
> - 51-80B band drawdown.
> - Mutator validation status (Corner 1 — how many done?).
> - MWCC SDK match count (Corner 2).
> - Active wall reports vs reset wall reports.
>
> Post to info-board with `s19-tick-T<minutes>` tag.

### TypeArchaeologist (Corner 5 — header support, unchanged from S18)

> Reactive role. Service `typereq:<class>` posts from writers within 30 min
> SLA. Author / amend canonical headers in `include/types/`.
>
> Opportunistic: during quiet windows, attack the 7 HEADER-malformed files
> flagged at S18-ext close (canonical-header hygiene pass). Pre-commit will
> block these for new writers if not cleaned.

---

## Key Documents / References for S19

- `docs/tracking/s19-kickoff-v2.md` — this doc (the primary handover)
- `docs/tracking/s19-kickoff.md` — v1 (TUScout's 3-wave version, kept for history)
- `docs/specs/toolchain-bootstrap.md` — compilers.zip workflow (issue #3)
- `docs/tracking/s16-techniques.md` — pattern catalog + wall entries
- `docs/tracking/fleet-coordination-protocol.md` — git concurrency rules
- `tools/verify_match.sh` — canonical byte-equivalence gate
- `tools/generate_report.py` — produces report.json with semantic metrics (issue #2)
- `tools/download_tool.py` — compilers bootstrap (issue #3)
- `memory/MEMORY.md` — auto-memory index, project_status, feedback, references
