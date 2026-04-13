# Attack Plan — Session 5: "The Permuter Sweep"

**Date drafted:** 2026-04-13 (end of Session 4)
**Target session:** 2026-04-15+
**Baseline entering this session:** ~8,370 / 20,508 unique addresses (~40.8%)
**Session goal:** Deploy the permuter on the full version_diff pool, exhaust 24B leaf pool with technique #15, push to **8,700+ unique (42.4%+)**

---

## Context — What Just Happened

Session 4 "The SDA Sweep" delivered +120 verified matches and 5 new techniques:

- **+120 verified matches** (8,250 → ~8,370), 40.2% → 40.8%
- **5 new techniques:** `-fno-elide-constructors` (#11), FP comparison inversion (#12), bitfield set/clear (#13), scheduling flag heuristic (#14), pre-set return value (#15, 100% hit rate on 24B)
- **TU completions:** bg, objectdatafactory, caslistener
- **57+ files rehomed** from agent/ to proper TU directories
- **Version_diff pool:** exhausted for flag-only fixes, ~449 remain with structural diffs
- **Walls documented:** LIFO/FIFO ctor scheduling, FP f0/f13 alternation, beq/bne layout, float-heavy Rendering
- **PERMUTER v2 BUILT:** matcher_bot.py extended with 8 stochastic mutations + hill-climbing search + batch mode

### Key Strategic Insight
Individual function compilation hits diminishing returns above 36B. The next wave needs:
1. Permuter batch sweep (automate mutation search on 449 version_diff files)
2. Exhausting the 24-36B pure leaf pool with technique #15 (~180 functions)
3. TU compilation research (fixes beq/bne, LIFO, frame sizes — future sessions)

---

## Session Goals

### Track A: Permuter Batch Sweep (Session Opener — 60 min)

Deploy matcher_bot.py v2 on the full version_diff pool.

**Phase 1 — Quick pass (budget 50, ~1.5 hours):**
```bash
python tools/matcher_bot.py --batch-dir src/wip/version_diff/ --permute --budget 50
```

**Phase 2 — Deep search on 80%+ files (budget 500):**
```bash
python tools/matcher_bot.py --wip <file> --permute --budget 500 --verbose
```

**Target:** +20-50 matches from permuter sweep.

### Track B: 24B Leaf Function Blast (Primary Match Count)

Technique #15 (pre-set return) has 100% hit rate on 24B null-check getters. ~180 unmatched 24B functions identified.

1. Scan DVD map for ALL unmatched 24B functions (every system, not just Sim/Person)
2. Workers apply: `r=0; if(c) r=v; return r;`
3. Batch-verify with matcher_bot

**Target:** +50-100 from 24B pool.

### Track C: Fresh DOL Cracks 28-36B (Secondary)

OpusWorker: 75 remaining Sim core/Camera/Person targets.
SonnetWorker: CAS system.
New: Build mode / Interactor getters, Audio wrappers (integer-heavy only).

**Target:** +30-50 from 28-36B DOL cracks.

### Track D: TU Compilation Research (Investment)

Pick cameramanager or bg as test TU. Prove `tu_match.py --combine` fixes beq/bne layout. Document for Session 6.

**Target:** Prove concept on 1 TU. No match count target.

---

## Permuter v2 Quick Reference

**Mutations (M13-M20):**
| ID | What |
|----|------|
| M13 | Type width swap (int↔short↔char↔unsigned) |
| M14 | Cast insertion |
| M15 | Comparison inversion (x >= y → !(x < y)) |
| M16 | Pre-set return pattern |
| M17 | Operand swap (commutative ops) |
| M18 | Expression split (a = b+c → a=b; a+=c;) |
| M19 | Negate condition (DeMorgan, double-negate) |
| M20 | Struct deref swap (a.field → (&a)->field) |

**Usage:**
```bash
python tools/matcher_bot.py --wip <file> --permute --budget 200      # single file
python tools/matcher_bot.py --batch-dir <dir> --permute --budget 50   # batch
python tools/matcher_bot.py --wip <file> --budget 60                  # classic mode
```

---

## Fleet Roster (10 agents)

| Name | Model | Role | Assignment |
|------|-------|------|-----------|
| MainGuy | Opus 4.6 | Orchestrator | Dispatch + permuter triage |
| OpusWorker | Opus 4.6 | Cracker | DOL cracks 28-36B Sim core |
| SonnetWorker | Sonnet 4.6 | Blaster | 24B blast + CAS |
| SonnetWorker2 | Sonnet 4.6 | Blaster | 24B blast + permuter hits |
| KimiGuy | Kimi | Spotter | 24B target scan + TU reorg |
| KimiWorker | Kimi | Applier | 24B technique #15 |
| Kmiworker2 | Kimi | Applier | 24B technique #15 |
| TUScout | Kimi | Research | TU compilation PoC |
| Reviewer | Kimi | QA | Spot-check + permuter validation |
| Researcher | Kimi | RE | 24B target expansion + TU support |

---

## Technique Library (15 patterns)

1. `extern char name[]` — SDA lis/addi
2. Default scheduling for complex functions >100B
3. Bitfield structs → rlwimi
4. `unsigned int` + `~MASKu` → 32-bit rlwinm
5. Struct member access prevents constant folding
6. Local variables force load-before-store
7. Empty struct + `__builtin_new` → vtable at offset 0
8. `volatile` store ordering
9. Virtual class declarations for blrl dispatch
10. Per-file `// FLAGS:` overrides
11. `-fno-elide-constructors` scheduling pass 2 (**Session 4**)
12. `!(x < y)` for bgelr encoding (**Session 4**)
13. Bitfield set/clear pattern (**Session 4**)
14. Scheduling flag heuristic: source-order vs interleaved (**Session 4**)
15. Pre-set return value: `r=0; if(c) r=v; return r;` — 100% on 24B (**Session 4**)

---

## Success Criteria

| Metric | Target | Stretch |
|--------|--------|---------|
| Permuter matches | +20 | +50 |
| 24B leaf blast | +50 | +100 |
| Fresh DOL cracks | +30 | +50 |
| **Total new matches** | **+100** | **+200** |
| Unique total | 8,470 (41.3%) | 8,570 (41.8%) |
| TU compilation PoC | 1 TU | 5 functions via TU |

---

## Notes to Future MainGuy

- **Permuter is Phase 1.** Launch immediately. Quick pass (budget 50) first, deep search (budget 500) on 80%+ files second.
- **24B is guaranteed yield.** Technique #15 at 100% hit rate on ~180 functions = easy 100+ matches.
- **36B+ ceiling is real.** Don't assign workers to 48B+ without a specific technique.
- **Version_diff is 449 files but most are hard.** The permuter tells you which are crackable. Trust its scores.
- **50% matchable milestone is ~8,500.** Within reach this session (8,370/17,000 = 49.2% of matchable).
- **Integer systems only for DOL scan.** Float-heavy Rendering is a documented wall.
