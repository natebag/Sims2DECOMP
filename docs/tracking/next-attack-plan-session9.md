# Attack Plan — Session 9: "The 9K Push"

**Date drafted:** 2026-04-14 (post Session 8 wrap)
**Baseline entering:** 8,808 unique (43.0%, ~52% matchable)
**Session goal:** Cross **9,000 unique** and push toward **55% matchable**

---

## Context

Session 8 was the biggest single day in project history:
- **+558 verified matches** (8,250 → 8,808)
- **Three milestones crossed:** 52% matchable, +500 day, 8,800 unique
- **13 new techniques** (now 35 total)
- **~1,850+ files reorganized** by TUScout across 9 waves
- **0 QA failures at scale**

### Top performers Session 8
| Agent | Contribution |
|-------|-------------|
| SonnetWorker | **+130 personal** (record) |
| KimiGuy | **+70 personal** (scout → crack) |
| SonnetWorker2 | +110+ (trivial blasts + STL + BitMatrix64) |
| OpusWorker | +33 (128-256B + 256-512B pioneer) |
| Kmiworker2 | +17 |
| KimiWorker | +13 |
| TUScout | ~600+ files wave 3-9 |
| Reviewer | 100% QA pass rate |

### The compounding model (proven)
**KimiGuy scouts → Claude/Sonnet crackers → TUScout organizes → Reviewer verifies.** Each piece individually isn't 10x; together they multiply.

---

## Session 9 Tracks

### Track A: Remaining scouted families (+30-50 matches)
Still open from KimiGuy's wave 4 scout:
- **EAStringC 104B dtor / 116B operator= families** (walled at clrlwi register — try technique #34 pointer cast)
- **WrapperPaneBase 40B individual trivial** (18 files, ~50% hit rate possible)
- **InteractorModule swarm** (many dupe variants, some fresh matches)

### Track B: Big untouched clusters (+50-100 matches)
- **BBI::InventoryItem** — 6 getter cluster
- **ObjectDataID operators** — 6 operator family
- **XRoute / ReconBuffer** — 5+7 files
- **Behavior::GetBaseID/MaxID** — walled, try compiler-mutator technique

### Track C: OpusWorker's scouted 256-512B families (+30-50)
From `256-512b-frontier` info note:
- SaveGameTarget::Spawn*Dialog (15+ files @ 284-468B)
- LoadGameTarget::Spawn*Dialog (14 parallel)
- cXObjectImpl::Try* family (~12 @ 272-508B)
- cXPersonImpl bool checks (260-464B)
- InteractorResourceSet::Remove{Model,Shader,Texture} (3 @ 356B)

### Track D: KimiGuy-style new scout (+20-40 follow-on)
Untouched classes with 5+ similar functions. Focus scan on:
- EHouse / HouseImpl
- GoalUnlock
- Motive system
- AwarenessManager
- Career / Skill classes

### Track E: Permuter batch run (re-scan with 35 techniques)
The permuter (`tools/matcher_bot.py --permute`) was built in Session 4. Re-run on `src/wip/version_diff/` with the 35-technique library might flip old walls. Run overnight if possible.

---

## Fleet Roster (10 agents)

Same as Session 8. Compounding model locked in.

---

## Technique Library (35 proven patterns)

See info board notes for details. Session 8 additions:
- #33 Named locals force register allocation order
- #34 Pointer cast to int for signed cmpw emission
- #35 SDA vs non-SDA control via array size

---

## Success Criteria

| Metric | Target | Stretch |
|--------|--------|---------|
| 9,000 milestone | CROSSED | +500 past |
| 55% matchable | CROSSED | N/A |
| New matches | +200 | +500 |
| New techniques | +1 | +5 |
| Bad commits | **0** | 0 |

---

## Notes

- **The compounding model is the secret sauce.** Don't break the scout→crack→organize→verify chain.
- **KimiGuy scouting first** — always. His family IDs unlock 5-30 match blasts.
- **Full-tree collision check mandatory** — `find src/matched/ -name "*0xADDR*"`. Class-specific grep misses cross-TU matches.
- **Compact Claude agents past 70% context** — fresh context makes them 3-5x more productive.
- **TUScout reorg work compounds** — organized classes make families easier to spot.
- **9K is within reach.** 192 matches from 8,808 → 9,000. Plausible in a half-day.
