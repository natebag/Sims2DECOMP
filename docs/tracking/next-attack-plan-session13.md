# Attack Plan — Session 13: "Infrastructure First"

**Date drafted:** 2026-04-21 (S13 pre-session planning, user + MainGuy)
**Baseline entering:** 9,441 unique (post pre-session housekeeping; 14 S12-orphan walls moved to wip/version_diff)
**Session framing:** **Option B — infrastructure-first.** Build asm-processor + clear the wall catalog before resuming pure count-chase.
**Primary goal:** ship asm-processor Phase 1 MVP capable of cracking the S12 wall catalog (12+ scheduler / reg-alloc walls).
**Secondary goal:** +300-400 matches via lightly-tasked fleet drain on GREEN-cleared scout queue (self-funding).
**Stretch goal:** asm-processor lands first 5+ wall cracks mid-session + Kimi fleet expands into newly-unlocked structural territory.

---

## Why Option B

S12 delivered +93 net matches but surfaced **12+ scheduler / register-allocation walls** that are fundamentally un-crackable by hand at Sonnet-quality. Without asm-processor or equivalent permuter infrastructure:

- ~15-30 matches are **blocked indefinitely** (Manipulator walls, APT D-family pc-reading, cXObjectImpl cr7-reuse, FP-coloring, LIFO-vs-FIFO ctor stores, etc.)
- Future sessions will keep hitting the same walls and parking them
- Kimi fleet blast efficiency stalls as the "easy" queue drains and only wall-territory remains

Per OpusWorker + OpusReview's **co-signed S12 investment plan** (Cog info id `30e1cf16` + subsequent refinement):

- **Setup cost:** 13-21h total (Phase 1 MVP + mutator integration + first batch run)
- **Payoff window:** ~1.8 sessions. Break-even by S14 Day 1.
- **6-session yield estimate:** 44-58 matches from walls + ongoing template blast momentum.

This is the rare session where **infrastructure pays off faster than pure blast.**

---

## Entering Assets (from S12 close)

### Scout queue ready (~1,900 DVD-verified collision-checked targets)
- APT: ~500 remaining (HaikuResearch S11 queue, ~50% already drained by Kimi fleet)
- ESims*: 502 posted + 338 staged (Researcher S12)
- cXObject/cXMTObject: 182 targets (TUScout S12 — noted: trivial 16-32B pool FULLY DRAINED)
- cXPerson/Interaction/WrapperPane/SoundPlayer: 495 targets (TUScout S12)
- Effects/Animation/BBI: 229 targets (Researcher S12, 74% already matched)
- **Cross-reference:** `docs/tracking/s13-drain-map.md` (Researcher's S12 consolidation).

### Template libraries ready
- `docs/systems/apt-opcode-template.md` — APT <100B (Techniques #53-#55)
- `docs/systems/apt-opcode-middle-template.md` — APT 100-200B (Techniques #57-#60)
- ENgcRC family template (SonnetWorker S12, 22-sibling queue, info id `66a080d6`)
- Dtor template recipe (SonnetWorker2 S12)
- Printf-thunk recipe variant (Technique #59 refinement, SonnetWorker2 S12)

### Wall catalog (12+ targets for asm-processor)
**Category 1 — adjacent-insn swap (permuter):**
- lfs-vs-andi hoisting (GetAffectedWallHeight 24B, DisableRasterModes 64B)
- fcmpu-vs-stfs swap (CheckCancelTimer 60B)
- 2-3 insn-pair scheduler order (PushStringDictByte 128B, StackSwap middle-pool)

**Category 2 — register allocation / coloring:**
- FP register alternation f0/f13 (0x8001A03C Lerp, SpriteSlot::Reset, ENgcRenderer float ops)
- r11/r3 base-alias swap (cXPersonImpl::InvalidateRoutes 52B)
- Multi-zero-reg ctor (BBI::InventoryItem ctor 48B)
- 2-addi fold-vs-split (PushThisVariable pre-fix — now solved by Technique #60)

**Category 3 — RTL-level hoist / CFG:**
- cr7 reuse across mr (cXMTObjectImpl linked-list head)
- Backward-branch shared-epilogue (IsValidPlayerId, SetCameraFilter)
- 4-check validity cascade bool-folding (InteractorManager::IsValidPlayerId)

### Technique library at S13 start
- S12 Techniques #53-#60 codified in `memory/project_sn_compiler.md`
- S9-S11 techniques (#37-#52) still scattered — S14+ consolidation task
- Foundational #1-#8 in the memory doc

### S13 carryovers
- 74 Tier-3 legacy header mislabels (fix_legacy_headers.py script ready in tools/)
- 4,312 pre-QA-RULE-1 headerless files (gradual on-touch backfill)
- versioninfo/ folder full audit (OpusReview S12 flag — batch-gen mislabeled files)
- APT arithmetic 50-pool TU-pivot (OpusWorker shape analysis at `build/apt_arithmetic_pioneer_drafts/SHAPE_ANALYSIS_0x80272BC4_Add.md`)
- E-family single-sample monitor (per-handler OpusReview review only, no template blast)

---

## Fleet — Same 11 agents, re-scoped

| Agent | Role | S13 assignment |
|-------|------|----------------|
| MainGuy | orchestrator | Route + monitor + unblock |
| **OpusReview** | deep QA | 90-120min deep-pass + size-sweep on new commits + asm-processor design review |
| Reviewer | volume QA | 30-min count/dedup/spot-check cadence |
| **OpusWorker** | asm-processor architect | **Track I (infrastructure) lead** |
| **SonnetWorker2** | asm-processor infra pair | **Track I (infrastructure) pair** |
| SonnetWorker | template blast | Track T: ENgcRC family (22 siblings) + ENgcGraphics/Effects |
| KimiWorker | APT drain primary | Track A: remaining APT queue (~500 targets) |
| KimiGuy | APT template blast | Track A: middle-pool expanded queue (62+ cleared) |
| Kmiworker2 | float / APT assist | Track A assist OR Track C cleanup (74 Tier-3 legacy) |
| Researcher | S13 scout | Track S: NEW territories (ESim AI deeper, skin/movie/skillmovie/treetab) |
| TUScout | S13 scout | Track S: SAnimator2 145-target breakdown + other deep scouts |

**Worker-to-infra ratio:** 2 architects / 4 blasters / 2 reviewers / 2 scouts / 1 orchestrator. Infra is the critical path; blast is self-funding.

---

## Session 13 Tracks

### Track I: asm-processor Phase 1 MVP — OpusWorker + SonnetWorker2 (CRITICAL PATH)

**Estimated: 4-6 hours for Phase 1 MVP. Then Phase 2 (mutators) 3-5h. Then batch run 2-4h.**

**Phase 1 — MVP (Day 1):**
1. Port or re-implement the core asm-processor loop (reference: doldecomp/melee implementation if applicable)
2. Integrate with existing `tools/matcher_bot.py` + `verify_match.sh` (don't rewrite — adapt)
3. Target capability: can input a parked wall from src/wip/version_diff/ + its .s assembly + DOL bytes, run N permutations, output best-scoring variants
4. Success criterion: prove the flow on ONE of the Category 1 walls (lfs-vs-andi or fcmpu-vs-stfs — shortest scheduler swap). A clean MATCH is the target; if not, a measurable improvement over pre-asm-processor baseline is acceptable.

**Phase 2 — Mutator integration (Day 1-2):**
1. Wire up the S11 matcher_bot mutators (M21-M25) to run inside the asm-processor loop
2. Add 2-3 NEW mutators targeted at the Category 2 walls (register-pinning, FP coloring).
3. Test on 5 of the parked walls in batch mode.

**Phase 3 — First batch run (Day 2-3):**
1. Run asm-processor against the full 12-wall catalog from src/wip/version_diff/.
2. Collect results: hits (commit), near-misses (improve mutators), no-improvement (document as structural).
3. Expected hits: 3-6 matches on Category 1, 2-4 on Category 2, 0-1 on Category 3.

**Commit cadence:** OpusWorker + SonnetWorker2 commit tool changes incrementally. Each mutator addition is its own commit with a test-result note.

**Blockers to escalate to MainGuy:** >8h of no forward motion on Phase 1 MVP, or asm-processor dependency that requires shared-infra change beyond tools/.

### Track A: APT queue continuation — KimiWorker + KimiGuy + optional Kmiworker2

**Target: +100-150 matches.**

- KimiWorker: resume HaikuResearch APT ODD batches (~250 unmatched remaining)
- KimiGuy: template-blast expanded middle-pool scope (62+ handlers cleared at S12 close, apply techniques #57-#60 per middle-template.md)
- Kmiworker2: APT EVEN batches (4/6/8 remainder) OR optional Track C cleanup role

**Gates:** Reviewer 30-min ticks, OpusReview deep-pass cycles. No first-5-commit gates needed — all Kimi workers passed S12 gates.

**Non-negotiables (unchanged from S12):**
- Case-insensitive collision check per address
- verify_match.sh before commit
- `git commit --only <path>` per fleet advisory
- No extern-"C" thunk naming (use proper `Class::method()` form)
- File header size must match DVD map size

### Track T: ENgcRC + ENgcGraphics template blast — SonnetWorker

**Target: +30-50 matches.**

- **Phase 1 (20-40 min):** Finish ENgcRC family from S12 template (info id `66a080d6`, 22 siblings). Expected +14-18 per S12 carryover estimate.
- **Phase 2:** Pivot to ENgcGraphics / Effects per S12 plan. Apply Technique #58 MI-vcall dispatch-offset table.
- **Walls to skip:** 100B+ FP-arg siblings (DirectRect, AlphaTest, SetBlendMode, SpriteList — these go to asm-processor Track I)

### Track S: Scout for S14 — Researcher + TUScout

**Target: 300-500+ DVD-verified scouts banked.**

- **Researcher:** scan unexplored subsystems — skin/movie/skillmovie/treetab (TU completion 40-60% per S12 carryover). Also ERoom/Goals/Careers DVD-map re-scout (S12 Haiku2 contamination).
- **TUScout:** finish SAnimator2 145-target breakdown deferred from S12. Then scan CBMemberTranslator thunks (337-pool — the #1 long-term research target in memory:project_sims2_decomp.md).

**Methodology reinforced:**
- DVD map only (`extracted/files/u2_ngc_release_dvd.map`)
- Collision check both `*0xADDR*` and `*ADDR*` formats
- Post batches of 10-20 to info board with `Map:` metadata line

### Track C: Legacy cleanup (low priority / overflow role) — Kmiworker2 or opportunistic

**Target: 74 Tier-3 header mislabels fixed.**

- Run `tools/fix_legacy_headers.py` against the remaining 74 files identified in S12 legacy sweep
- Verify each via OpusReview's verify_at_mapsize logic (reuse /tmp/size_sweep.sh or promote to tools/)
- Single commit: `fix: 74 remaining legacy header size-label corrections per DVD map (bytes unchanged)`

**Owner:** Kmiworker2 if APT work stalls, OR any idle worker late-session.

---

## Workflow Rules

Unchanged from S12, with additions:

1. **verify_match.sh before every commit** (non-negotiable)
2. **Filename-based case-insensitive collision check per address** (non-negotiable)
3. **`git commit --only <path>`** — never `git add -u`
4. **Size-sweep on new commits** — OpusReview runs their size_sweep.sh in each deep-pass cycle
5. **Proper C++ class-member form** — no `extern "C" void <Class>_<Name>` thunk variants
6. **Template scope gates** — Kimi workers stay inside GREEN-cleared template scope; per-handler OpusReview review for HOLD families
7. **S13 NEW:** asm-processor tool changes go through OpusReview design-review before Phase 3 batch run. Phase 1 MVP + Phase 2 mutators are OpusWorker's discretion.
8. **S13 NEW:** stale .git/index.lock escalation threshold at 400s+ with zombie PID identification — fleet advisory still applies.

---

## Success Criteria

| Metric | Target | Stretch | Mega |
|--------|--------|---------|------|
| asm-processor Phase 1 MVP | shipped | shipped + Phase 2 + first batch run | + 10+ wall cracks committed |
| New matches | +300 | +500 | +700 (crosses 10K) |
| Crossing 10K | not primary goal | partial if asm-processor lands fast | yes if stretch holds |
| Wall catalog cracked | 3-6 | 8-12 | all 12+ |
| Scout queue for S14 | 300+ banked | 500+ | 700+ |
| Bad commits | 0 | 0 | 0 |
| Count drop events | 0 | 0 | 0 |

---

## Kickoff Sequence (S13 Day 1)

1. **MainGuy:** post Track assignments to Cog task board, brief all 11 workers
2. **OpusReview:** sync /tmp/size_sweep.sh → `tools/size_sweep.sh` (promote to shared infra), start 30-min audit rhythm
3. **Reviewer:** 30-min count tick cadence (baseline 9,441)
4. **OpusWorker + SonnetWorker2:** pair up, draft asm-processor MVP plan together, start Phase 1
5. **SonnetWorker:** start Track T — ENgcRC family continuation
6. **KimiWorker + KimiGuy + Kmiworker2:** re-claim APT queue slices, resume blast
7. **Researcher + TUScout:** start Track S on new territories
8. **MainGuy:** first checkpoint at 2-hour mark — asm-processor progress + match pace

---

## Why NOT cross 10K this session

If Track I succeeds, we defer the 10K crossing to S14 Day 1 with asm-processor doing some of the work. The math:

- S13 realistic: 9,441 + ~300-500 from blast = **9,741-9,941** by S13 close. Close to but not over 10K.
- S14 Day 1 with asm-processor warm: same blast pace + 10-15 wall cracks/day = **10,000 crossed within first 3-4h of S14.**

The alternative — pure blast — would maybe hit 9,850-10,000 this session, but S14+ would still face the walls we didn't crack. Long-term trajectory favors infrastructure.

---

## Key Documents / References

- `memory/project_sn_compiler.md` — 16+ techniques (updated with S12 #53-#60)
- `memory/feedback_mi_vcall_technique.md` — MI vcall recipes
- `memory/feedback_register_asm_policy.md` — register pinning is legal, codegen asm blocks are not
- `memory/feedback_git_lock_contention.md` — `git commit --only <path>` rule
- `memory/project_scout_map_incident.md` — DVD map vs release map rule
- `docs/systems/apt-opcode-template.md` + `apt-opcode-middle-template.md` — APT families
- `docs/tracking/s13-drain-map.md` — Researcher's S12 scout priority ranking
- `build/apt_arithmetic_pioneer_drafts/SHAPE_ANALYSIS_0x80272BC4_Add.md` — APT arithmetic TU-pivot starting material

---

## Notes

- **User was mostly AFK through S12.** Team is fresh for S13. No carryover fatigue.
- **Fleet cleanup done pre-session:** 14 S12 orphan walls moved, 30 experimental scripts moved to tools/experimental/, .cog/ gitignored, working tree clean.
- **Baseline is now 9,441** (was 9,455 pre-cleanup). Honest accounting — the 14 parked walls were never real matches. S13 starts from clean state.
- **Infrastructure investment is the right call.** If asm-processor fails Phase 1, we pivot back to pure blast for the session; worst case scenario is ~200 matches lost to the pivot cost. Best case: the S13+S14 trajectory shifts permanently toward structural match capability.
