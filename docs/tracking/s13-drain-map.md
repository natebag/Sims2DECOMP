# S13 Drain Map: Fleet-Wide Scout Consolidation

> **Source:** build/scout_batches/ (56 files) + build/scout_batches_effects/ (17 files)
> **Total collision-verified targets from batch files:** 914
> **Plus TUScout info-board postings:** ~182 cXObjectImpl/cXMTObjectImpl targets
> **Combined S12 scout pool:** ~1,096 targets

## 1. Executive Summary

The S12 scout queue is **oversaturated** with 1,096+ collision-verified targets across 17 major families.

| Metric | Count |
|--------|-------|
| Total from batch files | 914 |
| 16-32B (trivial) | 3 |
| 32-48B (MI-vcall light) | 18 |
| 48-64B (structured light) | 33 |
| 64-128B (structured mid) | 303 |
| 128-256B (structured heavy) | 450 |
| 256B+ (frontier) | 107 |

**Critical insight:** The 16-64B trivial pool is nearly exhausted. Only ~54 targets remain across ALL families. The bulk of S13 value lies in **64-256B structured wrappers** (~753 targets) where template-blast and sub-family analysis can yield +200-300 matches at 30-40% hit rate.

## 2. Tier Rankings (Adjusted for Actual Pool)

Tier definitions adapted to reality — the 16-32B trivial pool is drained, so Tier 1 now means **large families with proven template patterns at any blast-friendly size (16-128B)**.

### Tier 1: Template-Blast Heavyweights (proven patterns, high volume)

| Family | Total | 16-128B | 128B+ | Blast Pattern |
|--------|-------|---------|-------|---------------|
| InteractorModule | 128 | 52 | 76 | Twin-blast families (ParseControls, OnCommand, etc.) |
| cXObjectImpl_family | 37 (+182 TUScout) | 12 | 25 | MI-vcall wrappers (Technique #47/#48/#49) |

**Blast recommendations:**
- **cXObjectImpl_family:** TUScout identified 147 MI-vcall wrappers across 32-348B. Technique #47 (virtual-interface-with-filler) applies at ALL sizes. Estimated yield: +50-70 matches if even 35% of MI-vcall wrappers crack.
- **InteractorModule:** 128 targets with 6 confirmed twin families (ParseControls, IsSimulatorPaused, OnCommandPressed/Released, UpdateStickState, ctor/dtor pairs). Twin-blast specialty — crack one subclass, blast 4-5 siblings. Estimated yield: +25-35.

### Tier 2: Medium Families (10-50 targets, mixed difficulty)

| Family | Total | 16-128B | 128B+ | Pattern |
|--------|-------|---------|-------|---------|
| SimModel_SimRenderer | 61 | 15 | 46 | Mixed structured + dtor patterns |
| Neighbor_NeighborhoodImpl | 53 | 21 | 32 | Mixed structured + dtor patterns |
| cXPersonImpl | 43 | 21 | 22 | Mixed |
| Behavior_BehaviorTree | 32 | 16 | 16 | Mixed |
| ESimsCam | 23 | 15 | 8 | Mixed |
| BBI_Inventory | 23 | 8 | 15 | Mixed |

**Notes:**
- **SimModel_SimRenderer:** 61 targets with Update*Part functions (UpdateHat, UpdateHead, UpdateLowerBody, etc.) that share composite logic. SkinCompositor (8 targets) is a related render family. Estimated yield: +8-12.
- **Neighbor_NeighborhoodImpl:** 53 targets with standard dtor + query patterns. Relationship functions have symmetric structure. Estimated yield: +8-12.
- **cXPersonImpl:** 43 targets, species/bool checks dominated by MI-vcall + bit-flag patterns. IsDog/IsCat/IsMonkey/IsChild quad blast proven in S10. Estimated yield: +8-12.
- **Behavior_BehaviorTree:** 32 targets, many are simple lookup wrappers. GetBaseID/GetMaxID pair (64B each) proven in S11. Estimated yield: +5-8.
- **ESimsCam:** 23 targets, SDA-indexed accessor family. GetCursorLimitTopWidth/GetCursorLimitDepth pair (56B each) are trivial twins. Estimated yield: +5-8.
- **BBI_Inventory:** 23 targets, stream family (DoStream/DoStreamRead/DoStreamWrite) + builder item creators. Estimated yield: +5-8.

### Tier 3: Frontier / Small Families (5-30 targets, structured or 128B+)

| Family | Total | 16-128B | 128B+ | Notes |
|--------|-------|---------|-------|-------|
| SAnimator2 | 121 | 19 | 102 | Sub-family clusters, no pure template |
| Animation_Core | 22 | 9 | 13 | Small family / frontier |
| FrameEffects_PostProcess | 13 | 3 | 10 | Small family / frontier |
| Effects_Particle | 12 | 3 | 9 | Small family / frontier |
| Ingredients | 10 | 5 | 5 | Small family / frontier |
| SkinCompositor | 8 | 1 | 7 | Small family / frontier |
| Target_Wrappers | 6 | 2 | 4 | Small family / frontier |
| EIStaticModel | 5 | 1 | 4 | Small family / frontier |
| Weather | 4 | 0 | 4 | Small family / frontier |

**Notes:**
- **SAnimator2:** 121 targets but 102 are 256B+. Sub-families exist (follow*Update trio, handle*Animation quintet, Unload*Optional*Anim trio) but each needs individual analysis. Not a pure template blast. Reserve for Opus-level analysis. Estimated yield: +10-15 with careful sub-family work.
- **FrameEffects_PostProcess:** 13 targets with symmetric MotionBlur/Bloom/DepthOfField structure. Pioneer one (HandleBloomEvent, 680B), blast the other two. Estimated yield: +3-5.
- **Effects_Particle:** 12 targets, EParticleEffect/EParticleObj family. SetPos/UpdateParticleEffectLoad/CreateEffects share particle state logic. Estimated yield: +2-4.
- **Animation_Core:** 22 targets including TArray<ERAnim> destructors, EIStaticModel draw functions, AnimTableImpl. Mostly container/standalone. Estimated yield: +3-5.
- **Ingredients:** 10 targets, simple query helpers. MixIngredients (280B) is the heavyweight. Estimated yield: +2-3.
- **SkinCompositor:** 8 targets, render texture pipeline. LoadAllTextureLayers (1164B) and BlendTexture (1932B) are frontier. Estimated yield: +1-2.
- **Weather:** 4 targets, RainEffect lifecycle. RainModeUpdate (928B) is standalone. Estimated yield: +1-2.
- **EIStaticModel:** 5 targets, Setup/SetModel/DrawImmediate variants. Template siblings. Estimated yield: +2-3.

### Tier 4: Skip / Singletons (<5 targets or wall-dominated)

| Family | Total | Notes |
|--------|-------|-------|
| Other_Misc | 303 | Skip / singletons |
| STL_Containers | 10 | Skip / singletons |

- **STL_Containers:** Compiler-generated template instantiations (TArray, vector, _Rb_tree). Typically unmatchable or already matched. Skip.
- **Other_Misc:** 313 fragmented targets across <5-target families (less_int16_t, global helpers, anonymous namespaces, cGZSndSys, ObjSelector, etc.). Too fragmented for template blast. Spot-pick only during dead cycles.

## 3. Cross-Class Pattern Families (Highest ROI Opportunities)

### Pattern A: FrameEffects Symmetry Trio
- **Classes:** MotionBlur, Bloom, DepthOfField
- **Functions:** TurnOn/Off, Handle*Event, Override*SettingsFromTokens
- **Total targets:** 13 (8 FrameEffects + 5 PostProcess)
- **Strategy:** Crack HandleBloomEvent (680B) as pioneer. The event dispatch shape is identical across all three — load EAnimNote, switch on type, mutate FrameEffectsManager state. HandleMotionBlurEvent (416B) and HandleDepthOfFieldEvent (508B) are smaller variants. The Override*SettingsFromTokens trio (280B, 360B, 600B) share token-parsing structure.
- **Expected yield:** +3-5 matches from a single pioneer crack.

### Pattern B: InteractorModule Twin Families
- **Classes:** DirectInteractor, SimInteractor, WallPainter, FloorPainter, GrabManipulator, ObjectManipulator
- **Twin pairs:** ParseControls (112B), IsSimulatorPaused (112B), OnCommandPressed (156-208B), OnCommandReleased (156-208B), UpdateStickState (84B), ctor/dtor (96-124B)
- **Total targets:** ~40 across 6 subclasses
- **Strategy:** Pick one subclass (DirectInteractor is simplest), crack ParseControls + IsSimulatorPaused + OnCommandPressed. Blast the same source shape to SimInteractor, WallPainter, FloorPainter with minimal tweaks. Proven twin-blast pattern from S9-S10.
- **Expected yield:** +12-18 matches from 3 pioneer cracks.

### Pattern C: cXObjectImpl MI-Vcall Scale Blast
- **Source:** TUScout s1-s12 (147 MI-vcall wrappers)
- **Range:** 32B-6KB, ALL blrl-based vtable dispatch
- **Strategy:** Technique #47 (virtual-interface-with-filler) applies universally. Start with smallest (32-80B, 8 targets) to validate template, then scale to 80-128B (15 targets), then 128-256B (32 targets). The 256B+ wrappers (103 targets) are larger but still pure MI-vcall — they just forward more arguments.
- **Expected yield:** +50-70 matches at 35-50% hit rate. This is the single largest remaining pool.

### Pattern D: SAnimator2 Sub-Family Clusters
- **Cluster 1 — follow*Update trio:** followStandToTurnUpdate (128B), followMiddleUpdate (252B), followSidestepUpdate (492B). Shared interpolation + state transition logic.
- **Cluster 2 — handle*Animation quintet:** handleTurnAnimation (1040B), handleSidestepAnimation (1168B), handleWalkRunAnimation (1268B), updateRenderAnimation (1280B), handleFreeMoveWalkRunAnimation (2332B), handleIdleAnimation (2584B). Shared animation pipeline structure.
- **Cluster 3 — Unload*Optional*Anim trio:** UnloadPendingLongIdleAnim (196B), UnloadDCOptionalMotionAnims (236B), UnloadSMOptionalMotionAnims (236B), UnloadOptionalIdleAnim (292B). Identical load/unload shape.
- **Expected yield:** +8-12 from cluster analysis.

### Pattern E: Inventory Stream Family
- **Classes:** BBI::InventoryItems, BBI::InventoryItem
- **Functions:** DoStream (148B), DoStreamRead (312B), DoStreamWrite (184B), CreateNewItemFromGuid (92B), CreateNewItemFromSelector (152B), CreateNewBuilderItem (116B)
- **Strategy:** Crack DoStream first as the base serialization shape. Read/write variants likely differ only in buffer direction. The CreateNew* functions are factory wrappers.
- **Expected yield:** +2-4.

## 4. S13 Recommended Match Route

| Phase | Worker | Territory | Targets | Pattern | Expected Yield |
|-------|--------|-----------|---------|---------|----------------|
| P1 | KimiWorker | cXObjectImpl MI-vcall 32-128B (TUScout s1-s3) | 23 | Technique #47/#48 | +8-12 |
| P1 | KimiGuy | cXObjectImpl MI-vcall 128-256B (TUScout s3-s4) | 32 | Scale blast | +10-15 |
| P2 | SonnetWorker | InteractorModule twins (Researcher s7-s8) | 40 | Twin-blast | +12-18 |
| P2 | SonnetWorker2 | cXPersonImpl accessors (Researcher s3-s5) | 43 | MI-vcall + bitflag | +8-12 |
| P3 | Kmiworker2 | Neighbor/NeighborhoodImpl (Researcher s13-s15) | 49 | dtor + query | +8-12 |
| P3 | KimiWorker | cXObjectImpl MI-vcall 256B+ (TUScout s6-s10) | 103 | Large wrapper blast | +20-30 |
| P4 | OpusWorker | FrameEffects pioneer (Researcher s6 + s9) | 13 | Symmetric dispatch | +3-5 |
| P4 | OpusWorker | SAnimator2 clusters (Researcher s10-s15) | 120 | Sub-family analysis | +10-15 |
| P5 | Any spare | SimModel/SkinCompositor/Weather (s16-s19) | 73 | Standalone | +5-8 |

**Total expected yield:** +84-127 matches from scout-queue blast alone.

## 5. Territories to SKIP

- **16-32B trivial pool:** Effectively drained across all families (~3 remaining). Do not allocate workers here.
- **WALL-cr7 functions:** 14 flagged by TUScout in cXObjectImpl s12. Structural walls per S11 catalog — unmatchable with current techniques.
- **STL/container instantiations:** TArray, vector, _Rb_tree, _List_base compiler-generated functions. Unmatchable or already matched.
- **Other_Misc singletons:** 313 fragmented targets across <5-target families. Not worth dedicated worker time unless spot-picked during dead cycles.

## 6. Risk Factors

1. **Collision drift:** Scout batches were verified at post time. S12 workers may have claimed some addresses. Every worker MUST re-run case-insensitive filename collision checks before committing.
2. **MI-vcall template saturation:** Technique #47 works well for 32-128B but may break down for 256B+ wrappers with complex argument forwarding. Expect hit rate to drop from ~50% (small) to ~30% (large).
3. **SAnimator2 complexity:** 120 targets but NO pure template family. Sub-family cluster analysis is required. Do NOT assign a Kimi worker to bulk-blast SAnimator2 — it will waste cycles. Reserve for Opus-level analysis.
4. **FrameEffects pioneer risk:** If the first pioneer (HandleBloomEvent) hits a wall, the entire symmetric blast is blocked. Have a backup pioneer ready (OverrideBloomSettingsFromTokens, 600B).

---

*Drain map generated from S12 batch files. TUScout info-board data integrated as summary counts. No new scouting or collision checks performed.*
