# Attack Plan — Session 10: "The 10K Crossing"

**Date drafted:** 2026-04-15 (post Session 9 wrap)
**Baseline entering:** 9,000 unique (43.9%, ~54% matchable)
**Session goal:** Cross **10,000 unique** and push through **55% matchable**

---

## Context

Session 9 was project-defining:
- **+192 verified net matches** (8,808 → 9,000)
- **9K milestone crossed** — commit `a7bb20f4` by SonnetWorker2 (CASSelectionTarget::ConvertGridIdxToOptionIdx)
- **MI-vcall wall CRACKED** — virtual-interface-with-filler-methods technique now proven (commit `fe9019d7`)
- **~11 new techniques banked** (now 46+ total)
- **4+ permuter-ready near-matches** documented
- Audit methodology improved (git show --stat vs file-comment size bug fixed)
- 2 confirmed fakes removed, 277/280 false-MISMATCH audit cleared

### Top performers Session 9
| Agent | Contribution |
|-------|-------------|
| SonnetWorker | **+85** personal (Interaction blast 31, Track B 15, trivial sweep 39) |
| SonnetWorker2 | **+85** personal (milestone crosser, technique #36) |
| OpusWorker | **+28** (MI-wall crack, 4 permuter-ready, 11+ scouts) |
| KimiWorker | **+6** (WrapperPaneBase/InteractorModule residuals) |
| Reviewer | Track E: 277/280 false-positives cleared |

### The compounding model continues to prove out
**KimiGuy/OpusWorker scout → Claude crackers blast → Reviewer verifies → pre-commit hook gates.** 

---

## Track Zero: Infrastructure fixes (BEFORE cracking)

These block fleet throughput. Do first.

### Z1. Pre-commit hook bug fix
The current hook bulk-verifies ALL of `src/matched/` on every commit, moving non-verifying files to `src/wip/version_diff/` as a side effect. This causes:
- Net-zero commits (new files added offset by others swept out)
- Race conditions during concurrent fleet work
- Hook false-move of legit matches when compiler/state differs

**Fix scope:** Hook should only verify files being staged (`git diff --cached --name-only`), not the entire tree.

**File:** `.git/hooks/pre-commit` (installed via `tools/install-hooks.sh`)

### Z2. Commit the 23 untracked matched files
Session 9 end-state has 23 verified matched files on disk not in git. Run a targeted commit batch after Z1 hook fix (to avoid the bulk-sweep side effect). Verify each before commit.

### Z3. Remove 2 remaining fake matches
- `src/matched/agent/match_0x80204FD8_DirectInteractor_CheckCancelTimer.cpp` (SIZE_MISMATCH 60B vs DOL 120B)
- `src/matched/agent/match_0x803CA284_TArray_SndEvtHitPatch_Copy.cpp` (walled per KimiGuy Session 8 notes)

---

## Session 10 Tracks

### Track A: Permuter unlock wave (+15-50 potential)

Session 9 produced 4+ permuter-ready near-matches. Run `tools/matcher_bot.py --permute` on `src/wip/version_diff/` targeted at:

- **cXObjectImpl::Try* family** (15+ near-matches, OpusWorker structural crack ready, reg-alloc 3-byte diff)
- **pushAptButtonFilterALL** (1-byte diff, loop comparison)
- **CreateNewItemFromGuid** (scheduling wall, 4 swap positions)
- **DOGMA_PoolManager::GetFirstOutsideAllocation / GetNextOutsideAllocation** (pre-increment hoist)
- **MUWrapper::SetDisplayOkType/SetQueryType/SetInfoType** (zero-store ordering)
- **BitArray64::Clear** (dual-zero-merge)
- **BBI::InventoryItems::GetNewItemIndex** (loop structure)
- **RelMatrixImpl::GetNthKey / GetValue** (reg-alloc swap)
- **TreeTableQuickData::GetID / GetPrefixCheckTreeID** (pre-set-r3+beqlr pattern)
- **WantFear::Bookmark::Clear** (short-vs-int reg alloc)
- **AptScriptFunctionByteCodeBlock::GetConstantPool** (struct-return pathology)
- **AptCharacterSpriteInstBase::SetClipAction / RemoveClipAction** (rlwimi alignment)

### Track B: MI-vcall blast wave (fleet-wide unlock)

The virtual-interface-with-filler-methods technique is now validated (5 functions across SimpleReconObject, 6 InteractorVisualizer::PreDraw, 4 FamilyImpl, 5 NeighborhoodImpl). Apply broadly:

- **HouseImpl::IsResident** + remaining bool family (IsOwner, IsTenant, IsVisitor etc.)
- **GoalUnlock::Grant/Set** pair + siblings (GrantObjectUnlocks, others)
- **cXObjectImpl::Try* full 15-family** (if permuter doesn't close)
- **cXPersonImpl bool checks** (260-464B)
- **FamilyImpl / HouseImpl / NeighborhoodImpl** residual MI-vcall wrappers
- Any class using the `*(T**)g_singleton->v_methodN(args)` pattern

### Track C: Trivial sweep continuation (+30-60 potential)

SonnetWorker/SonnetWorker2's proven methodology: Python-find unmatched tiny functions in DVD map, collision check, blast.

- **16B/20B/24B/28B/32B pool** — still depth in PaneItem, XRoute, HUDTarget, E2ETarget, ObjectModuleImpl, cSoundPlayer, TileWalls, RoutingSlot, SpriteSlot, etc.
- **Expand to 40B/48B/56B** with the new technique library
- **Sister-class expansion** — when one class family cracks, sibling classes often share pattern

### Track D: Fresh scout areas (untouched classes)

- **UI/APT system** (3000+ functions per CLAUDE.md) — AptSprite, AptDisplayObject, AptButton subclasses, Apt event handlers
- **cXObject / cXObjectImpl residuals** — small accessors hidden in the ~3000-function class
- **Render state-check (integer-only)** — avoid FP alternation wall; check state booleans, visibility flags
- **EHouse / NeighborhoodImpl / FamilyImpl residuals** — after Track B MI-vcall blast, many remaining
- **AwarenessManager / Motive / Skill / Career** — narrow per Session 9 scouts, but some untouched remain

### Track E: Rolling audit + QA

- Continue 20-30 min QA cadence (Reviewer)
- Watch for more fake-match patterns (SIZE_MISMATCH, DVD-vs-release-map confusion)
- Spot-check 5-10 commits per cycle
- **Critical milestone: when count crosses 10,000** — celebrate + run broad 20-commit spot-check

---

## Fleet Roster (7+ agents)

Same as Session 9, compounding model locked in:
- **MainGuy** — orchestrator
- **SonnetWorker / SonnetWorker2** — blast crackers (trivials + techniques)
- **OpusWorker** — pioneer/scout, frontier (256-512B, MI vcall)
- **KimiWorker** — satellite blasts, target sweeps
- **KimiGuy / Kmiworker2** — scouts, family identification
- **Reviewer** — QA, audit, milestone watch

---

## Technique Library (46+ proven patterns)

Session 9 additions (beyond Session 8's 35):
- #36 Variadic fn-ptr forces crclr (PMF-via-vtable, SonnetWorker2)
- #37 Sized `extern char g_[N]` forces HA/LO absolute addressing; unsized stays SDA21
- #38 bne-over-return-0 vs beq-to-return-0 flow (write `if (x) { ...; return; } return 0;`)
- #39 SN ctor store ordering: source-order matches DOL, not declaration-order
- #40 Singleton-deref via `(T*)*(T**)g_foo` for absolute global pointers
- #41 Static-vs-member function r3/r4 distinction (check for `mr r30, r3` vs direct r4 use)
- #42 `(c-'0') <= 9` unsigned range via addi+subfic+adde
- #43 `(-N - x) == 0` compiles to subfic SIMM=-N + adde (vs xori for `== N`)
- #44 Named-locals force compiler arg-ordering decisions
- #45 Virtual-interface-with-filler-methods for MI vcall (slot_index − 1 filler pure-virtuals)
- #46 `goto alt_path` forces SN to emit alt return LAST in memory (fall-through default)
- Bonus: `using Base::method` INSUFFICIENT under SN ProDG — must redeclare virtual overloads in base

---

## Success Criteria

| Metric | Target | Stretch |
|--------|--------|---------|
| 10,000 milestone | CROSSED | +500 past |
| 55% matchable | CROSSED | N/A |
| New matches | +500 | +1,000 |
| Permuter batch run | 1+ successful | 5+ |
| Bad commits | **0** | 0 |
| Hook bug fixed | Yes | Yes (committed + documented) |

---

## Notes

- **Hook fix FIRST** — before any cracking. Every Session 9 commit paid a tax via the hook's bulk-sweep side effect.
- **Permuter is the unlock of unlocks** — 4 permuter-ready near-matches from Session 9 alone; full Session 10 permuter run could unlock 15-50 at once.
- **MI-vcall blast is the second force multiplier** — entire class families (Try*, HouseImpl, GoalUnlock) are newly viable.
- **Trivial sweeps compound** — SonnetWorker + SonnetWorker2 proved +170 matches this session via systematic tiny-function sweeps. Still depth remaining.
- **Audit rigor** — DVD map + symbols.json + disasm_func.py + verify_match.sh-with-file-comment-size is the gold-standard verification chain. Never use `git show --stat` for size. Regex-based bulk scripts need care.
- **10K is within reach.** 1,000 matches from 9,000 → 10,000. Ambitious for one session; plausible across 2 sessions with permuter + MI-blast + trivial sweeps firing in parallel.
