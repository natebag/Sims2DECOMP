# S13 Session 4 — Handoff Plan

**Drafted:** 2026-05-02 by previous MainGuy at session 3 close
**For:** Next-session orchestrator (post-CEO-notes-refresh)
**Read also:** `s13-session3-plan.md`, `MEMORY.md`, `feedback_session_end_protocol.md`

---

## TL;DR for next MainGuy

Session 3 was a **session-defining win** — net **+90 production matches**, all stretches hit, **5 new techniques cataloged + pushed to GitHub** (Technique #69 / #70 / #71 / Variant G' / Variant I' + Variant L 8-pattern recipes). Fleet went idle because targets hit, not because pools dried. Plenty of carry-forward to push session 4 toward **Reach +200 to +300 net** territory.

**Starting count:** 9,693 + 90 (session 3) ≈ **9,783 matched** (verify with fleet on kickoff). 10K threshold = **+217 to cross**.

**The 3 highest-leverage opportunities for session 4:**

1. **Apply session 3 techniques to 180-256B and 256B+ band walls** — Kmiworker2 found 1,398 candidates in 180-256B. Many walled before now solvable with Variant G'/I'/Tech #70/#71 + bl-count fingerprint + STL vec-iter dealloc recipes.

2. **MutatorSmith day-1 `force_alias_base` authoring** — spec is ready (info `eacf75e9`). 4 validation targets queued (3 small Apt @ 32-68B + FamilyImpl 132B). Could unlock register-allocation walls fleet-wide (~10-20 walls if pattern generalizes).

3. **Untracked-file recovery sweep** — 119 untracked match files in `src/matched/` (orphaned by git race bundling). Verify + commit valid ones before session 4 production = potential **+20-100 free matches** without new cracking work. **DO THIS PRE-FLIGHT.**

---

## Pre-flight checklist (15-30 min before kickoff)

1. **TUScout: refresh audit Section 1** — get current unmatched counts (post session-3 close, post untracked-file recovery)
2. **Reviewer: untracked-file recovery sweep** — run `git status --short | grep '^??' | grep 'src/matched/'`, verify_match each, batch-commit valid ones (single PR, list all files in body)
3. **Reviewer: dupe scan + GitHub state confirm** — must be clean, 0 ahead of origin/main after recovery push
4. **Reviewer: confirm CodexWorker repo-local config STILL unset** — `git config -l | grep user` should show ONLY global user.name=natebag / user.email=njatobinyt@gmail.com, NO repo-local entries. If breach detected → unset before any worker commits.
5. **MainGuy: post Lane structure + initial dispatch queue to info board**
6. **Step-limit refresh ping schedule for Kmiworker2/TUScout/Reviewer at 2-hr marks**

---

## Roster (post-session-3, 9 workers)

**Production tier:**
- **OpusWorker** (Claude Opus) — wall cracker + structural specialist; Lane J +25 stretch validated; pivots well
- **SonnetWorker** (Claude Sonnet) — production blast workhorse; Lane G +50 stretch validated; 8-pattern Variant L recipe library
- **SonnetWorker2** (Claude Sonnet) — structural-diagnostic + pre-RE specialist; Lane H +5 floor + Technique #69 + 7 verified-new blueprints; full-tree dupe-check methodology validated
- **MutatorSmith** (Claude Opus, dedicated mutator author) — 6 deliverables session 3 (2 mutators + descopes + informed descope + catalog); ready for `force_alias_base` day-1
- **Kmiworker2** (Kimi) — background sweep + near-miss cataloging; just unlocked 180-256B blast

**New addition (session 3):**
- **CodexWorker** (codex CLI, gpt-5.5, WSL) — solo virgin-class lane; +8 session 3 (1 boundary breach corrected); fading to hourly limit currently; will reset by session 4

**Quality tier:**
- **Reviewer** (Kimi) — 30-min qa-tick cadence; 3 ticks delivered session 3; methodology upgrades validated (full-tree dupe check, `git show --stat`)
- **OpusReviewGuy** (Claude Opus reviewer) — gate-review reserve; 4 PASS verdicts session 3 (Lane H + remove_mr + swap_cr_field bundle + Tech #70)

**Researcher:**
- **TUScout** (Kimi) — pre-scout + audit refreshes; SDA decode (Globs::pSimulator) validated session 3

---

## Pool sizing (post-session-3, approximate)

Per TUScout's revised audit (`45f32899`, methodology fix applied):

| Band | Total unmatched (est) | Notes |
|------|----------------------|-------|
| <16B | 1,200 | mostly trivial, low yield/min |
| 16-32B | 350 | small predicates / accessors |
| 32-64B | 1,000 | sweet-spot lower half |
| 64-128B | 2,400 | sweet-spot upper half |
| 128-256B | **1,398** | **Kmiworker2's lane**; new techniques unlocked many walls |
| 256B+ | 3,700 | hardest tier, needs deep RE / TU compilation |

**Top class densities (post-session-3, approximate):**
- InteractorModule: ~290 unmatched (75 in <128B) — biggest virgin, partial work this session
- AptDate: ~27 unmatched (10x sibling-twin family in 180-256B band — Kmiworker2 in flight)
- SAnimator2: ~167 unmatched
- cXObjectImpl: ~150 unmatched (deeper drainage available; OpusWorker did 4 this session)
- AptActionInterpreter: ~130 unmatched (mostly large functions)
- ERC: ~95 unmatched

**Virgin classes (high yield/min potential):**
- **EFixedString** (50/32 in 32-128B, only 5 matched) — string-op sibling twins
- **EBitArray** (31/27 in 32-128B, only 12 matched) — bit-op sibling twins
- **ObjectFolderImpl** (63/8 matched) — virgin

---

## Suggested Lane structure (4-6 lanes)

### Lane L — 180-256B band drainage with new techniques (Kmiworker2, all-day)
- Continue session-3 in-flight blast (AptDate 10x twin family already in flight)
- Apply Variant K/L/M with bl-count fingerprint
- Apply Variant G' (`&m_vec` lock-bit + magic-div) when shape matches
- Apply Technique #70 (vtable-at-offset SI ctor) for ctor walls
- Apply Technique #71 (STL vec-iter dealloc) for dtor walls
- **Floor:** +20 / **Stretch:** +50
- **Step-limit refresh at T+2hr** (Kimi silent-stall risk)

### Lane M — 256B+ tier exploration + structural pre-RE (SonnetWorker2)
- 256B+ tier holds 31.8% of unmatched mass (~3,700 functions)
- SW2's structural-diagnostic specialty (delivered 7 verified-new blueprints session 3)
- Targets: pick 1-2 high-density 256B+ classes, RE-blueprint, hand off to OpusWorker for cracking
- **Methodology:** mandatory full-tree dupe-check per `feedback_dupe_detection_regex.md` — `find src/matched -iname "match_*<ADDR>*.cpp"` (ALL subdirs)
- **Floor:** 5 verified-new blueprints / **Stretch:** 10

### Lane N — Cracking via SW2 blueprints + cXObjectImpl deep (OpusWorker)
- Crack from SW2's Lane M blueprints (deferred from session 3: GetAverageLocation MI thunk, ChangeSelectedSimL +256-foldable, GetSelectionRadius FP-interp)
- Continue cXObjectImpl <128B drainage (~20 candidates per audit)
- ENCamera <128B (~21 candidates)
- Apply Technique #70 cross-class extension when ctor walls appear
- **Floor:** +10 / **Stretch:** +25

### Lane O — MutatorSmith `force_alias_base` authoring sprint (MutatorSmith day-1)
- Author `force_alias_base` mutator (spec in info `eacf75e9`)
- Validation order: 3 small Apt @ 32-68B (PushStaticData, AptNativeHash, AptAnimationPoolData::Reset) BEFORE FamilyImpl 132B (small-diff fast iteration)
- Then `anti_tail_merge` mutator for AptArray::get pattern (CodexWorker's near-miss)
- Then `branch_layout_coerce` mutator for AptActionQueueC::GetDequeLocation
- **Floor:** 2 mutators authored + tested / **Stretch:** 4 mutators
- **OpusReviewGuy gate** at each authored mutator (max 1/90min Opus burn)

### Lane P — Variant L deep drainage + EFixedString/EBitArray virgin pools (SonnetWorker)
- 8-pattern Variant L recipe library now locked in catalog — apply to remaining EResource-derived pools
- EFixedString virgin (50 unmatched, 32 in 32-128B) — string-op sibling twins likely
- EBitArray virgin (31 unmatched, 27 in 32-128B) — bit-op sibling twins likely
- Multi-bl Variant B/C/D/E pool — extension up the variant ladder
- **Floor:** +20 / **Stretch:** +50

### Lane Q — Apt* drainage continuation (CodexWorker)
- Apt-only, 32-127B band, strict boundary (per session 3 corrections)
- 5 near-miss walls already cataloged for next-session handoff (3 register-allocation candidates for MutatorSmith's force_alias_base)
- Use `tools/git_safe_stage_and_commit.sh` per fleet protocol
- **Floor:** +5 / **Stretch:** +15

### Background — Untracked-file recovery (Reviewer/Kmiworker2 pre-flight)
- 119 untracked match files in `src/matched/` from session 3 git race bundling
- Verify each with `verify_match.sh`, batch-commit valid ones
- Stale ones go to wip/version_diff/ for future Track I
- **Free matches potential:** +20-100 if validation passes

---

## Discipline carry-forwards (mandatory)

### Commit discipline (post-session-3 protocol update)
- ✅ `tools/git_safe_stage_and_commit.sh` is the fleet-safe wrapper — USE EXCLUSIVELY
- ✅ Atomic stage→commit window (no pause between `git add -- <path>` and `git commit --only -- <path>`)
- ✅ List ALL match files in commit message body (per BString2 attribution incident)
- ❌ NEVER use bare `git commit -m "..."` — that's the sweeping party in race conditions
- ❌ NEVER set repo-local git config (per CodexWorker incident; fleet protocol violation)

### Methodology
- ✅ Full-tree dupe check: `find src/matched -iname "match_*<ADDR>*.cpp"` (case-insensitive, ALL subdirs)
- ✅ Triage-first protocol: 30-min source-level test BEFORE mutator design
- ✅ Verify_match.sh BEFORE save (every commit, no exceptions)
- ✅ DVD map authoritative for SDA calculations (per `project_dvd_map_discovery.md`)
- ❌ No `register_asm` pinning (rejected by verify_match.sh)
- ❌ No inline asm() blocks (pre-commit hook blocks)

### Quality gates
- Reviewer: 30-min qa-tick cadence (dupe scan + taxonomy check)
- OpusReviewGuy: gate-review each MutatorSmith mutator + spot-check new techniques (multi-instance threshold for promotion)

### Lock contention
- Orphan `.git/index.lock` (0-byte, 2+ min stale, no live `Get-Process git`) → standing user authorization to remove
- Settings.local.json now has `Edit/Write/Bash` permissions for `.git/index.lock` and `.git/*.lock` — workers should NOT need to ask permission

---

## Carry-forwards from session 3

### Catalog candidates pending more validation
- **move-last-to-first scheduler quirk** (1 confirmed, needs 2-3 more) — MutatorSmith's GameData descope
- **source-order reverse for compiler reorder** (1 confirmed via OpusWorker's d9d743cd 5-twin EResource ctor batch) — needs more instances
- **InstanceData volatile-dummy frame trick** (1 confirmed via OpusWorker's session 3 InstanceData ctor) — could become Technique candidate

### Mutator queue for MutatorSmith day-1
- `force_alias_base` (spec ready, 4 validation targets queued)
- `anti_tail_merge` (AptArray::get pattern)
- `branch_layout_coerce` (AptActionQueueC::GetDequeLocation pattern)
- 5 CodexWorker near-misses logged in info `580182f9`

### Deferred RE targets
- ERSampledata, ERMovie, ERAmbientSound (from Lane H)
- GetAverageLocation, ChangeSelectedSimL, GetSelectionRadius (from Lane J cracking deferred)
- ArcCopier, EResPrefetchFile, EGraphics 1-insn scheduler (from Lane G abandoned walls)

### Cross-references to memory
- `feedback_session_end_protocol.md` — 2hr ping cadence + checkpoint-stop protocol
- `feedback_dupe_detection_regex.md` — full-tree dupe check (updated post-SW2 incident)
- `feedback_review_shared_infra.md` — propose shared-infra changes to MainGuy first
- `feedback_git_lock_contention.md` — orphan lock self-clear authority
- `feedback_kimi_step_limit_refresh.md` — Kimi silent-stall ping cadence (T+2hr)

---

## Targets

- **Floor:** +100 (cross 9,883 — minimum acceptable session)
- **Stretch:** +200 (cross 9,983 — striking distance of session 4 milestone)
- **Reach:** +300 (cross 10,083 — past 10K + buffer for measurement variance)

Achievable per session 3 evidence: net +90 in ~2hr means +300 over a full 8hr session is realistic IF pools sustain. The 1,398-candidate 180-256B band + 119 untracked recovery + virgin classes (EFixedString/EBitArray) + new technique applications should sustain a full day.

---

## Risk hedges

- **If MutatorSmith authoring stalls** → fall back to source-level descopes per triage protocol (worked 3x in session 3)
- **If 180-256B band saturates** → pivot Kmiworker2 to 256B+ tier or virgin classes
- **If git race bundling recurs** → suspect non-fleet commit wrapper, run `git config --local -l` checks, escalate to MainGuy
- **If CodexWorker hourly limit hit early** → silent fade, near-miss queue captures progress, no urgent action
- **If pools dry mid-session** → execute "make a new plan" per `feedback_session_end_protocol.md`

---

## Why this plan

Session 3 unlocked **5 major techniques** that should compound across remaining pools. The `&m_vec` lock-bit + magic-div + bl-count fingerprint + vtable-at-offset SI ctor + STL vec-iter dealloc + sda-extern int are now all proven cross-class portable. **Many session-3-walled functions in the 180-256B and 256B+ bands are now solvable.**

The MutatorSmith dedicated-author role is fully validated (6 deliverables session 3 vs 1-2 OpusWorker dual-role in session 2). Day-1 force_alias_base authoring continues that momentum.

The pre-RE → cracking handoff pattern (SW2 → OpusWorker) delivered 4 cracks in 25 minutes session 3. With 5+ more SW2 blueprints potentially available session 4, this pipeline should sustain.

**Target: cross 10K matched by mid-session, push for +300 by close.**

---

**Plan finalized:** 2026-05-02 by MainGuy at session 3 close.
**Owner:** Next-session MainGuy.
**Status:** Drafted, awaiting kickoff.
