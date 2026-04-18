# Attack Plan — Session 11: "Claude Fleet Unleashed"

**Date drafted:** 2026-04-18 (post Session 10 wrap)
**Baseline entering:** 9,064 unique (44.2%, ~55% matchable)
**Session goal:** Cross **9,500 unique** and push toward **56-57% matchable**

---

## Context

Sessions 9-10 delivered the project's biggest two-session run:
- **Session 9:** +192 net (8,808 → 9,000). 9K milestone crossed.
- **Session 10:** +64 net (9,005 → 9,064, post-dedup). Hook fix shipped. MI-vcall technique validated fleet-wide. Permuter tested (budget-25 → 0/5 hits — needs improvement).
- **Combined S9-S10:** +256 verified matches in two sessions.

### Key learnings from Session 10
1. **Direct-grep trivial sweep > scout-based family blast** when scout collision-checking is unreliable
2. **Permuter at budget-25 insufficient** for reg-alloc/ctor-ordering walls. Needs budget 50-100 or new mutators (loop-bound, pre/post-increment, non-adjacent statement swap)
3. **Kimi agents hit capacity limits mid-session** — need Claude-only fleet for reliability
4. **Collision-check must be case-insensitive + filename-based** (not content-only grep). Many matched files use lowercase hex in filenames without 0x prefix.
5. **Pre-commit hook fixed** — scoped to staged files only (commit 578de060). Fleet-blocking bulk-sweep eliminated.
6. **Singleton Instance() pattern** is a high-yield blast template (+8 in one commit)
7. **State-machine Shutdown/Reset family** spans many classes with identical structure

### Top performers Sessions 9-10
| Agent | S9 | S10 | Cumulative |
|-------|-----|------|-----------|
| SonnetWorker | +85 | +39 | +124 |
| SonnetWorker2 | +85 | +48 | +133 |
| OpusWorker | +28 | +34 | +62 |

---

## Fleet Configuration: Claude-Only

**No Kimi agents this session** — usage limits reached. Fleet is 3 Claude workers + MainGuy orchestrator.

| Agent | Role | Strengths | Model |
|-------|------|-----------|-------|
| MainGuy | Orchestrator | Dispatch, QA, coordination | opus |
| SonnetWorker | Blast cracker | Interaction accessor goldmine, DlgWrapper, cFixedWorld | sonnet |
| SonnetWorker2 | Blast cracker | MI-vcall templates, cXPersonImpl quad, H2DTarget, trivial sweep | sonnet |
| OpusWorker | Pioneer/scout | Singleton/factory patterns, MI-vcall pioneer, 256-512B frontier | opus |

**QA duties:** MainGuy runs periodic count checks + spot-checks (Reviewer offline). Workers self-verify via direct-grep + verify_match.sh.

---

## Session 11 Tracks

### Track A: Trivial sweep expansion — 16-64B (Target: +50-100)

**Proven methodology from S9-S10.** The 16-48B pool delivered ~200 matches across two sessions. Expand into 48-64B range.

**Approach:**
1. Python-scan DVD map for unmatched functions by size (16/20/24/28/32/40/48/56/64B)
2. Exclude SDK zone (0x8024-0x8039 — Metrowerks)
3. Case-insensitive collision check: `find src/matched -iname "*ADDR*"`
4. Blast via proven accessor templates

**Priority class areas (still depth):**
- cXObjectImpl residuals (3000+ function class)
- cXPersonImpl residuals (species/bool checks)
- AptCharacter / AptSprite / AptDisplayObject (UI subsystem, 3000+ functions)
- Interaction / InteractionItem (SonnetWorker's goldmine, may have more)
- cSoundPlayer (volume/pause/play/stop methods)
- WrapperPaneBase / PaneItem (siblings of matched ones)
- EInstance / ERoom / EHouse / NeighborhoodImpl residuals
- ObjectModuleImpl / ObjectFolderImpl small getters

### Track B: Pattern blast — proven templates (Target: +30-50)

Apply the template patterns that delivered highest yield in S9-S10:

| Pattern | Yield in S9-S10 | Where to find more |
|---------|-----------------|-------------------|
| Singleton Instance() new-if-null | +8 in one commit | Any *Table, *Manager, *Factory class |
| State-machine Shutdown/Reset | +10+ across S10 | *State, *StateMachine classes |
| MI-vcall vtable dispatch (40-64B) | +20 in NeighborhoodImpl/FamilyImpl | cXObjectImpl, HouseImpl, GoalUnlock residuals |
| Standard dtor (vtable + conditional delete) | +9 _List_base, +10 Params/CallbackData | Any class with matched ctor but unmatched dtor |
| Bit-flag setter/getter pairs | +6 RoutingSlot, cXPersonImpl | Any class with short/int flag fields |
| SDA-indexed accessor | +10+ across classes | Any SDA-global-based singleton method |

### Track C: 64-128B range expansion (Target: +20-40)

Move past trivial sizes into structured wrappers:
- **MI-vcall wrappers** — virtual-interface-with-filler technique proven
- **Constructor/destructor families** — vtable stores + field zeroing patterns
- **Callback wrappers** — *Target callback forwarding (INVTarget/PCTTarget/H2DTarget templates proven)
- **String operation templates** — BString/BString2 append/assign/insert
- **Loop-count patterns** — end-begin ptr diff, linked-list traversal

### Track D: Scout + crack (Target: +10-20)

**Self-scouted only.** No reliance on external scout reports unless collision-checked inline.

**Priority areas to scan:**
- **APT UI subsystem** (AptViewer, AptCIH, AptActionInterpreter) — KimiWorker found 23+ unmatched in S10 scout, some stale but many valid
- **ERoom / ENeighborhood / EHouse** — MI-vcall pattern applies broadly
- **GoalUnlock / Careers / Skill** — partially scouted S9-S10, some singleton patterns remain
- **cSimulatorImpl** — 18+ functions scouted S8, partially cracked
- **ERLevel / ERModel / ENgcRenderer** (integer-only state checks)

### Track E: Permuter improvements (Target: +5-15)

**Build new mutators for matcher_bot.py** (Researcher's infra research says 30 min each):
- Loop-bound rewrite (`i < 49` ↔ `i <= 48` ↔ `i != 49`)
- Pre/post-increment swap (`++i` ↔ `i++`)
- Non-adjacent statement swap (generalize M12)
- Comparison signedness flip (unsigned/signed cast wrapping)
- Array deref style (`a[i]` ↔ `*(a+i)`)

Then re-run on high-score version_diff targets:
- UIAUDIO::InstallEntry (97.6%)
- UIReflow::Reflow_Id (97.3%)
- WXFTarget::UpdateMenuState (97.0%)
- _Parse dirtyxml (96.6%)
- TreeSimImpl::Reset (96.3%)

---

## Technique Library (46+ proven patterns)

Full library documented across Session 8-10 info board notes. Key unlocks:
- #45 Virtual-interface-with-filler-methods for MI vcall (slot − 1 fillers)
- #46 goto alt_path for memory ordering
- #37 Sized `extern char g_[N]` forces HA/LO (unsized stays SDA21)
- #38 bne-over-return-0 flow control
- #39 SN ctor store ordering (source-order, not declaration-order)
- #40 Singleton-deref `(T*)*(T**)g_foo` for absolute globals

---

## Workflow Rules (proven across S9-S10)

1. **Direct-grep-verify for every address:** `find src/matched -iname "*ADDR*"` before writing source
2. **verify_match.sh before every commit** — file-comment size is authoritative
3. **Case-insensitive collision check** — filenames use lowercase hex without 0x prefix
4. **No batch-commit of externally-scouted targets** without independent collision check per address
5. **Workers autonomous** — self-select targets from direct scans, report commit + wall results
6. **MainGuy spot-checks count** every 30-60 min via `python tools/count_matched.py`

---

## Success Criteria

| Metric | Target | Stretch |
|--------|--------|---------|
| 9,500 milestone | CROSSED | +500 past |
| 56% matchable | CROSSED | N/A |
| New matches | +200 | +436 |
| Permuter new mutators | +2 implemented | +5 |
| Bad commits | **0** | 0 |
| Dedup at session end | **0** | 0 |

---

## Notes

- **Claude-only fleet = simpler coordination** — no Kimi usage limits mid-session, consistent tool access, proven collision-check discipline
- **Trivial sweep has the deepest remaining pool** — 589 unmatched 24-64B functions per Researcher's scan. At 50% hit rate = ~300 more matches in this size range alone
- **MI-vcall technique is the gift that keeps giving** — every new class scanned reveals 5-20 MI-vcall wrappers, each a quick match
- **Permuter needs investment** — budget 25 produced 0/5 hits. Either increase budget to 50-100 per file (2-4hr batch) or build better mutators first
- **9,500 is within reach in one good session** — need +436 from 9,064. Two workers at +100 each + one at +50 = +250 minimum. With pattern blast templates = +436 plausible.
