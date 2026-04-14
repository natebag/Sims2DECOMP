# Attack Plan — Session 8: "The Milestone Push"

**Date drafted:** 2026-04-14
**Baseline entering:** 8,670 unique (42.3%, ~51% matchable)
**Session goal:** Cross **52% matchable (8,700)** and push to **8,900+ (43.4%+, 52.4% matchable)**

---

## Context

Session 7 was historic:
- **+420 matches** (8,250 → 8,670) — biggest single session in project history
- **SonnetWorker +123** personal (project record)
- **SonnetWorker2 +91** personal
- **13 new techniques** (now 32 total in library)
- **Multiple major template families cracked:** TArray (27), WrapperPaneBase + Item thunks (60), DlgWrapper (14+), EControllerManager (30), SafeDelete (12+), EdithVariableSet (13+), cXObjectImpl/cXPersonImpl trivial (83+), STL heap/sort (15+), SimpleReconObject (6)

**KimiGuy's scouting is the MVP model** — his family identification turns one crack into 10-30 matches via templates.

---

## Session 8 Tracks

### Track A: Finish KimiGuy's leftover scout targets (+30-50 matches)

From Session 7 final scout, still untouched or partially done:
- **CasClothingUnlocks 10 remaining pairs** (body-part + tattoo variants)
- **DlgWrapper SetText/AddButton 10+ remaining** (some done)
- **STL heap/sort remaining algorithms** (__unguarded_linear_insert, __unguarded_insertion_sort_aux)
- **cFixedWorldImpl remaining boundary checks**

### Track B: New KimiGuy scout — find next family wave (+30-80 matches)

With everything blasted so far, need NEW families. Priority scouts:
- **EHouse / NeighborhoodImpl** — object management class hierarchy
- **cSimulatorImpl** — main simulator, 50+ methods likely
- **ESim / ESimulator** — entity system
- **CAS* classes** — CasListener, CasEventResetSim, CasListener variants
- **BBI::InventoryItems** — inventory system

### Track C: Opus pioneer — 256B+ frontier (+10-20 matches)

We've cracked 128-256B. Next frontier: 256B-512B. Many more complex functions, but with the 32-technique library and the r11/r9 fix, some patterns will work.

### Track D: Re-verification sweep (+5-10 matches)

Some earlier "failed" attempts from Sessions 1-5 may now match with new techniques. Quick sweep of old version_diff files with current default flags + technique library could yield surprises.

---

## Fleet Roster (10 agents, ALL FRESH CONTEXT)

| Name | Role | Assignment |
|------|------|-----------|
| **MainGuy** | Orchestrator | Dispatch + milestone tracking |
| **OpusWorker** | Pioneer | 256-512B frontier |
| **SonnetWorker** | Template blaster | Track A leftovers (CasClothingUnlocks pairs) |
| **SonnetWorker2** | Template blaster | Track A leftovers (STL remaining + DlgWrapper) |
| **KimiGuy** | Family scout | Track B — find NEW families |
| **KimiWorker** | Applier | Track A leftovers (simpler pieces) |
| **Kmiworker2** | Applier | Track A leftovers |
| **TUScout** | Structure | Organize agent/ → TU wave 4 |
| **Reviewer** | QA | Rolling watch + 52% milestone verification |
| **Researcher** | Intel | Track D — re-verification sweep candidates |

---

## Technique Library (32 proven patterns)

Full list: see info board notes. Key Session 7 additions:
- #20 SDA2-mixed float trio
- #21 Double-vtable species check
- #22 Sprintf return capture for vararg scheduling
- #23 Void return forcing
- #24 rlwinm flag bit extraction formula
- #25 Signed vs unsigned loop counter
- #26 Local sub-struct pointer for instruction ordering
- #27 IsType == CONST bool idiom
- #28 TypeInfo 6-function family template
- #29 Varargs Sprintf declaration
- #30 this-null guard inside virtual-dispatch
- #31 STL make_heap loop idiom
- #32 Pre-loaded int temps for binary EVec2 copy

---

## Success Criteria

| Metric | Target | Stretch |
|--------|--------|---------|
| **52% matchable milestone** | **CROSSED** | +200 past |
| New matches | +30 | +200 |
| Unique total | 8,700 | 8,900 |
| New template families | +2 | +5 |
| Bad commits | **0** | 0 |

---

## Notes to Future MainGuy

- **30 matches from 52% milestone — this should be a quick session-opener push, not a whole-day grind.**
- **KimiGuy's scouting is force multiplier #1.** Always start with him on family scouts.
- **Full-tree collision check is mandatory** — SonnetWorker2 learned the hard way in S7 (200 commits but only 8 net new). `find src/matched/ -name "*0xADDR*"`, not just class-specific.
- **Opus on frontier, Sonnet on replication** — proven pattern.
- **Context management:** Claude agents lose edge past ~400k tokens. Compact when they cross 70% context.
