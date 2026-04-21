# Attack Plan — Session 12: "Full Fleet, 10K Milestone"

**Date drafted:** 2026-04-19 (post Session 11 wrap)
**Baseline entering:** 9,362 unique (45.7%, ~56% matchable)
**Session goal:** Cross **10,000 unique** — +638 net from baseline
**Stretch goal:** 10,000 + ship auto family-clusterer infrastructure
**Mega goal:** above + Dolphin boot-trace experiment

---

## Context

Sessions 9-11 delivered the project's biggest three-session run:
- **Session 9:** +192 net (8,808 → 9,000). 9K milestone crossed.
- **Session 10:** +64 net. MI-vcall technique validated fleet-wide. Hook fix shipped.
- **Session 11:** +298 net (149% of +200 target) + 104 integrity upgrades. Techniques #47-#52. QA-RULE #3 hook gate shipped.
- **Combined S9-S11:** +554 verified matches. Technique library grew 40 → 52.

### Key learnings from Session 11
1. **Kimi-free fleet worked but was slower** — 3-worker pace hit +298 vs 5-worker pace could have done +500+
2. **QA-RULE #3 pre-commit hook is load-bearing** — caught multiple dupe waves mid-session; keep it live
3. **Scout-ahead pipeline is the throttle** — workers drained scout queue faster than scouts filled it. Kimi back = parallel scout + blast keeps workers saturated
4. **Permuter at budget 100 + 5 new mutators = 0 hits on parked targets** — remaining gaps are STRUCTURAL not syntactic. Permuter should be parked until asm-processor-style transforms exist
5. **MI-vcall + filler + own-vtable 3-layer hierarchy** is the goldmine technique — every new class scanned reveals 5-20 wrappers
6. **Register-pin + `+=` accumulate** (Technique #50) unlocks pointer-walk functions scheduler otherwise reorders
7. **+104 fake-thunk→real integrity conversion in one day** proves the "quality sweep" template — worker-1's EResourceManager blast model should be reused
8. **OpusReviewer audit cycles caught 3 dupe waves + 1 policy-flag file** — 1M-context reviewer is worth its seat

### Top performers S9-S11
| Agent | S9 | S10 | S11 | Cumulative |
|-------|-----|------|------|-----------|
| worker-1 (sonnet) | +85 | +39 | +4 new + 104 integrity | +128 + 104 |
| worker-2 (sonnet) | +85 | +48 | ~+30 (Track B blast) | +163 |
| OpusWorker | +28 | +34 | +56 | +118 |
| KimiWorker (S9-S10) | offline S10-S11 | — | **back for S12** | — |

---

## Fleet Configuration: Full 9-Agent Squad

**Kimi access restored** — we can run the full fleet this time.

| Agent | Role | Strengths | Model |
|-------|------|-----------|-------|
| orchestrator (MainGuy) | Dispatch, QA, coordination | Task routing, pace monitoring | opus |
| OpusWorker | Pioneer / frontier | Hard 64-256B cracks, new technique discovery | opus |
| OpusReviewer | QA audit | 1M-context audit cycles, policy enforcement | opus[1m] |
| worker-1 (sonnet) | Blast + integrity | Trivial sweep, fake-thunk cleanup | sonnet |
| worker-2 (sonnet) | Pattern blast | MI-vcall templates, UI*Table siblings | sonnet |
| **KimiWorker1** | **Bulk template blast** | **APT scout-queue drain (drain 500+ target pool)** | kimi |
| **KimiWorker2** | **Bulk template blast** | **ERoom/Goals/Careers queue drain** | kimi |
| HaikuResearch | Scout | APT/UI subsystem scouts | haiku |
| Haiku2 | Scout | ERoom/ENeighborhood/GoalUnlock scouts | haiku |
| HaikuPermuter | **PARKED** — infra at budget limit | — | haiku |

**Worker-to-scout ratio:** 5 blasters / 2 scouts / 1 reviewer / 1 orchestrator. Scouts must stay ahead — if queue drops under 200, scouts get priority.

---

## Session 12 Tracks

### Track A: APT scout-queue drain — Kimi1 primary (Target: +200)

**The big drain.** S11 left 987 collision-verified APT targets in the scout queue. Kimi1 inherits the queue and blasts through.

**Queue contents (already collision-checked):**
- AptCharacter / AptSprite / AptDisplayObject residuals (40-64B MI-vcall wrappers)
- AptViewer / AptCIH / AptActionInterpreter trivial getters
- UI*Table sibling families (unopened twins)

**Approach:**
1. Read scout batches from Cog info board (HaikuResearch's 9 batches)
2. Template-match via proven MI-vcall + accessor recipes
3. verify_match.sh BEFORE every commit (Kimi1 MUST respect this)
4. Address-collision hook gate will catch anything duped — trust it

**Expected hit rate:** ~50% (S10-S11 baseline)

### Track B: ERoom/Goals/Careers queue drain — Kimi2 + worker-2 (Target: +100)

**Parallel to Track A.** Haiku2 scouted 176 targets. Kimi2 takes 40-64B high-priority batch (100 functions); worker-2 takes 16-40B low/medium priority (76 functions).

**Templates:**
- MI-vcall virtual-interface-with-filler (~40 targets)
- Standard dtor vtable-store + conditional delete (~30 targets)
- Callback wrappers INVTarget/PCTTarget pattern (~18 targets)

### Track C: AptActionInterpreter opcode family kill — OpusWorker (Target: +50)

**Pool kill.** 50 `_FunctionAptAction*` opcode handlers identified in S11. All 132-256B, all same dispatch shape:
```
load opcode arg from script → dispatch on opcode type → mutate AptCharacter state → return
```

**Approach:**
1. Pioneer 3 opcodes (simple → structured → complex)
2. Extract template pattern into reusable skeleton
3. Hand template to Kimi1 or worker-2 for bulk blast remaining 47
4. If blocked by structural walls: document and park

**Stretch:** if family cracks clean, attack InteractorModule Manipulators next (499-target pool).

### Track D: Trivial sweep expansion — worker-1 (Target: +80)

**Worker-1's specialty.** The 16-64B pool still has depth despite S9-S11 drain.

**Priority areas (still depth per DVD map):**
- cXObjectImpl residuals (3000+ function class, partially cracked)
- cXPersonImpl bit-flag setters (Technique #50 recipe proven)
- cSoundPlayer volume/pause/play/stop
- EInstance / ERoom / EHouse small getters
- ObjectModuleImpl / ObjectFolderImpl

**Also:** continue fake-thunk→real integrity conversion sweep. S11 shipped 104; scan remaining src/matched for any suspicious wrapper files.

### Track E: S12 cleanup — worker-1 or OpusReviewer (Target: -38 dupes + infra)

**Housekeeping. Run first thing to clean the board.**

1. **Dedup sweep:** 38 cross-dir legacy dupes from S11 auto-gen (task #13).
   - Apply OpusReviewer's 4-direction taxonomy: agent-wins / sub_passthrough / versioninfo-wrongname / class-dir-wins / no-twin-singleton
   - Delete: `src/matched/hook_smoketest/match_0xDEADBEEF_fake.cpp`
2. **Pre-commit hook bash quoting fix (task #14):** OpusWorker's follow-up — quote NEW_MATCH_FILES using `readarray -t` + `"${NEW_MATCH_FILES[@]}"` to survive paths with spaces.
3. **Count check after cleanup:** confirm 9,324 post-dedup (9,362 − 38). Baseline for S12 match work.

### Track F: Auto family-clustering infrastructure — OpusWorker or Kimi pair (Target: +infra)

**Meta-investment.** Build `tools/cluster_unmatched.py`:
1. For every unmatched function in DVD map, disasm first-16 + last-8 PPC instruction mnemonics
2. Hash the mnemonic tuple as the family key
3. Bucket all unmatched by hash → outputs grouped-by-shape worker queues
4. Families with ≥5 members become templated target packs

**Why it matters:** 2-3x speedup for every future session. S13+ workers pull from clustered queues instead of waiting on manual scouts.

**Deliverable:** script in `tools/`, output JSON in `tools/clustered_unmatched.json`, top-20 families documented.

### Track G: Scout-ahead for S13 — HaikuResearch + Haiku2 (Target: 1,500+ scouted)

**Don't run dry.** Scouts that finish their queue early pivot to scanning new classes:
- HaikuResearch: ESims* / ESim (sim AI subsystem, 2000+ funcs)
- Haiku2: cXObjectImpl deep residuals + cXMTObjectImpl family

**Collision-check rules (from S11 burn):**
- Case-insensitive: `find src/matched -iname "*ADDR*"` (lowercase hex, no 0x)
- Check BOTH formats (`0xADDR` and lowercase `addr`)
- Post batches of 10-20 to info board, tag with `scout` + class name

---

## Stretch: Dolphin boot-trace experiment

**If pace exceeds 10K target mid-session**, kick off boot-trace investigation:
1. Run Sims 2 in Dolphin with symbol-trace enabled
2. Dump first ~100 functions executed during boot (boot0 → __start → main → first menu frame)
3. Cross-reference with unmatched list
4. Prioritize those for next session — they unlock "game actually boots" milestone

**Owner:** OpusWorker (after Track C ships) or dedicated Kimi spin-up.

**Why:** first step toward Milestone 4 PC port. At 50%+ matched, runtime testing becomes feasible. Info value > just matching.

---

## Technique Library (52 proven patterns — S11 wrap)

Full library in memory:feedback_mi_vcall_technique.md + memory:project_sn_compiler.md. Key S11 unlocks:
- **#47** MI-vcall via pure-virtual filler class (fleet-wide standard)
- **#48** FlowGoto 2-arg MI-vcall + non-SDA `extern char g[16]`
- **#49** Own-vtable 3-layer hierarchy (filler between Base/Derived)
- **#50** Register-pin + `+=` accumulate (`e += i` not `e[i]`)
- **#51** `new(this) T` placement new for Construct(T*)
- **#52** SimpleReconObject<T> layout — `void* pad; T* m_obj` at offset 4
- **ARB-N** AptRegistry multi-register wrapper formula

### S12 new-technique targets (aim for +3)
- Opcode-dispatch template (from AptActionInterpreter family kill)
- Manipulator base-class wrapper (InteractorModule 499-pool)
- Whatever cracks 1 of the 5 structural walls (cr7, bnelr y-bit, etc.)

---

## Structural Walls (S11 catalog — still unsolved)

Do NOT burn worker cycles on these. If encountered, document and park:
1. cr7 dual-branch (cXMTObjectImpl variants)
2. bnelr y-bit prediction (HasModel, DatasetPendingAddRefAsync×2) — BO=4 vs BO=5
3. Backward-branch shared-return (IsValidPlayerId)
4. MI this-adjust pre-add (cXMTObjectImpl) — Itanium ABI pre-add vs adj-in-vtable
5. Base-ptr precomputation (EIStaticModel/EIStaticSubModel::GetBoundSphere)

**Why parked:** 5 mutators + budget 100 = 0 hits in S11. Need asm-processor-class transforms, not permuter.

---

## Workflow Rules (enforced — violations = commit reject)

1. **Direct-grep-verify per address:** `find src/matched -iname "*ADDR*"` BEFORE writing source
2. **verify_match.sh before every commit** — file-comment size is authoritative
3. **Case-insensitive filename-based collision check** — lowercase hex, check both `0xADDR` and `addr` formats
4. **Pre-commit hook address-collision gate** is LIVE — trust it, don't bypass
5. **No batch commits without per-address collision check**
6. **Workers autonomous** — self-select targets from queue, report commit + wall results
7. **MainGuy spot-checks count** every 30-60 min via `python tools/count_matched.py`
8. **Kimi collision discipline:** Kimi1/Kimi2 MUST case-insensitive verify EVERY address — S10 Kimi burned us with content-only greps
9. **Register-pinning `asm("rN")` is LEGAL** — codegen asm blocks still blocked (per S11 policy clarification)

---

## Success Criteria

| Metric | Target | Stretch | Mega |
|--------|--------|---------|------|
| 10,000 unique milestone | CROSSED (+638) | +700 past | +800 past |
| Matched % | 48.7% | 49.3% | 50.0% |
| New matches | +638 | +738 | +850 |
| New techniques | +2 | +3 | +5 |
| Auto-clusterer infra | deferred | shipped | shipped + first cluster blasted |
| Boot-trace | deferred | deferred | shipped + first 10 boot funcs matched |
| Bad commits | **0** | 0 | 0 |
| Dedup at session end | **0** | 0 | 0 |

---

## S12 Kickoff Sequence

1. **MainGuy:** post Track assignments to Cog task board
2. **OpusReviewer:** start 30-min audit cadence immediately
3. **HaikuResearch + Haiku2:** confirm S11 scout queue is addressable (re-verify collision-free)
4. **worker-1:** run Track E cleanup FIRST (dedup sweep + hook fix), then switch to Track D
5. **KimiWorker1 + KimiWorker2:** onboard — read S11 wrap memory + feedback files before first commit
6. **OpusWorker:** start Track C (AptActionInterpreter pioneer 3)
7. **worker-2:** start Track B low-end (16-40B ERoom/Goals/Careers)
8. **MainGuy:** count check at 30min, 1hr, 2hr. If pace < +50/hr after hour 1, re-route.

---

## Notes

- **10K is the milestone** — crossing a round number matters for morale and project visibility. Even if we only deliver +400 (not +638), S12 is a win if walls held.
- **Auto-clusterer is the lever** — every hour spent on infra saves 3+ hours of manual scout in S13+. Ship even a rough v1.
- **Kimi pair is unproven at this fleet size** — start Kimis on LOW-RISK template work (APT drain, ERoom drain). Don't hand them frontier work until S13.
- **Scout pipeline discipline:** if worker blast pace exceeds scout fill pace, scouts preempt everything else. Empty queue = idle workers = wasted session.
- **The structural walls aren't going anywhere** — skip them cleanly, come back with new tools later (asm-processor, Ghidra AST diff, etc.)

---

## Why 10K Is Real This Time

S11 delivered +298 with 3 active workers. S12 has 5 active workers (2 Kimi added). Linear scaling says +500. Pipeline scaling (scout queue already full) says +600-700. The number isn't aspirational — it's arithmetic.

What's new in S12 that wasn't in S11:
- Full fleet (5 blasters vs 3)
- Pre-populated scout queue (1,163 targets vs building from scratch)
- QA-RULE #3 hook prevents dupe waves (S11 lost 1-2 hrs to dupe cleanup)
- 6 new techniques from S11 wrap = bigger template bench
- AptActionInterpreter family = 50-match template-kill available

The only thing that stops 10K is structural walls hitting faster than we expect. Catalog says 5 walls; if S12 finds 10 more, pace drops. That's the only real risk.
