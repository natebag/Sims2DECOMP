# Attack Plan — Session 7: "The Template Engine"

**Date drafted:** 2026-04-14
**Baseline entering:** ~8,531 / 20,508 unique (41.6%, ~50% of matchable)
**Session goal:** Exploit the proven template-blast model — push to **8,800+ (42.9%+, 52%+ matchable)**

---

## Context

Session 6 was the biggest day in project history:
- **+281 matches** (8,250 → 8,531)
- **50% matchable milestone crossed**
- **r11/r9 register allocation wall cracked** (removed `-fno-schedule-insns2` from defaults)
- **Permuter v2 built** (matcher_bot.py with hill-climbing + 8 mutations)
- **19 techniques documented**

**Proven template-blast model:**
1. KimiGuy scouts families
2. Claude agents crack one, replicate across the family
3. Reviewer does rolling QA
4. Repeat

This session applies the same model but aimed at bigger families in larger size ranges.

---

## Tracks

### Track A: Template family hunt in 64-128B (primary match source)
**1,727 targets** in the 64-128B pool. Proven family blasts in Session 6: TArray (27), EControllerManager (30), SafeDelete (12+). More families likely exist.

**Priority families to scout:**
- SAnimator2 (44 targets, some walled — crack the simple ones)
- BString / BString2 (28+16 targets, string ops often templatable)
- cXPersonImpl / cXObjectImpl (remaining 28+19 targets, vtable dispatch proven)
- cFixedWorldImpl (19 targets, bounds-check pattern proven)
- ObjectModuleImpl (16 targets)
- cSoundPlayer (16 targets, audio wrappers)

**Lane assignments:** KimiGuy scouts → Opus/Sonnet crack one per family → blast rest

### Track B: 128-256B frontier (Opus pioneer)
Researcher was queued to build the 128-256B target list. With the r11/r9 fix + technique library, this is unexplored territory with likely thousands of targets.

**Approach:**
1. Researcher finishes the 128-256B target list
2. OpusWorker pioneers — find what patterns work at this size range
3. Document 2-3 new techniques
4. Fleet blasts the replicable families

### Track C: Permuter batch re-run (automatic wins)
The permuter was built but only did one 449-file scan on the old default flags. With the new defaults (`-fno-schedule-insns2` removed), re-running on ALL version_diff files might flip previously-walled ones.

**Command:**
```bash
python tools/matcher_bot.py --batch-dir src/wip/version_diff/ --permute --budget 100
```

Runtime: ~6-8 hours. Can run in background while fleet works.

### Track D: Agent/ → TU reorganization (data quality)
~7,000 files still in agent/ directory. KimiGuy's reorg work moved 57 files. More can be done to properly organize matches by TU for clearer progress tracking.

**Low priority but valuable for the final push.**

---

## Fleet Roster (10 agents, all fresh context)

| Name | Role | Assignment |
|------|------|-----------|
| **MainGuy** | Orchestrator | Dispatch + triage |
| **OpusWorker** | Pioneer | 128-256B frontier |
| **SonnetWorker** | Template blaster | 64-128B family (TArray continue + new) |
| **SonnetWorker2** | Template blaster | 64-128B family (vtable dispatch expansion) |
| **KimiGuy** | Family scout | Scan for new template families |
| **KimiWorker** | Family applier | Blast cracked templates |
| **Kmiworker2** | Family applier | Blast cracked templates |
| **TUScout** | Structure | TU reorg + completion tracking |
| **Reviewer** | QA | Spot-check + dedup + milestone verification |
| **Researcher** | Intel | 128-256B target list + wall analysis |

---

## Technique Library (19 proven patterns — full toolbox)

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
11. `-fno-elide-constructors` scheduling pass 2
12. `!(x < y)` for bgelr encoding
13. Bitfield set/clear pattern
14. Scheduling flag heuristic (source-order vs interleaved)
15. Pre-set return value — 100% on 24B
15b. Signed comparison for bgtlr
16. Dual-exit shared return
17. `-fno-schedule-insns2` REMOVED from defaults (r11/r9 fix)
18. Compound `||` for multi-condition returns
19. Twin scanning via masked DOL patterns

---

## Success Criteria

| Metric | Target | Stretch |
|--------|--------|---------|
| New matches | +100 | +300 |
| Unique total | 8,631 (42.1%) | 8,831 (43.1%) |
| New template families | +3 | +8 |
| New techniques | +1 | +3 |
| 128-256B patterns proven | 2 | 5 |
| Bad commits | **0** | 0 |

---

## Notes to Future MainGuy

- **The compounding model works.** Every session that uses KimiGuy-scouts + Claude-crackers + Reviewer-QA produces. Don't break the pattern.
- **Opus is the pioneer.** Give him the frontier (128-256B). Sonnet workers replicate.
- **Fresh scans > reusing old version_diff.** With r11/r9 fix, DOL scans have higher hit rates than recovering old attempts.
- **50% milestone is behind us. 60% matchable = ~10,200 total = ~1,700 more matches.** Plausible in 3-5 more sessions at current pace.
- **Integer-heavy only.** Float walls (FP f0/f13 alternation) are still unsolved. Skip Rendering/ENgcRenderer float functions.
