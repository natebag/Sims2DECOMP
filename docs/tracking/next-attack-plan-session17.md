# Attack Plan — Session 17: "Stub-to-Real C++ Phase 1 — The Big Classes"

**Date drafted:** 2026-05-22 (S17 pre-session planning, user + MainGuy, post-S16 100% close)
**Baseline entering:** 100.00% byte-match (18,458 / 18,458 functions, 4,145,724 / 4,145,724 bytes) — the DOL rebuilds bit-perfect from source. ~13% of game-code is genuinely handwritten C++; ~87% is auto-stub coverage (passthroughs, naked-asm injects, `func_ADDR(void){}` empties). **Byte-match is a floor we never give back.**
**Session framing:** **First major "semantic recovery" session.** Convert auto-stubs into readable, retargetable C++ for the largest classes while preserving the byte-match invariant. This unblocks PC port + lands real prestige in the decomp scene.
**Mode:** **MEGA long-haul marathon** — same vibe as S16, run until exhaustion. Celebration of 100% = capacity to swing big.
**Primary goal:** +300 KB of stubs converted to real C++ across the fleet, with byte-match preserved on every commit.
**Stretch goal:** +500 KB converted, with 1-2 large classes (>50 KB each) fully semantic.
**Mega goal:** +1 MB converted, **objectsim** and **object** units >80% semantic, type library covers the top 10 classes.

---

## Why This Session

S16 took the project from 11.50% → 100% byte-matched in ~30 hours. **That's the build-from-source milestone.** It is not the port-ready milestone.

The decomp scene's prestige distribution:
- **Byte-match 100%** = "the build is reproducible." Cool, but the source is mostly opaque.
- **Semantic ≥80%** = "the code is readable, modifiable, retargetable." This is what unlocks PC ports, modding, research papers, and the kind of writeups other decomp teams cite.

S17 is the first **semantic-recovery** session. The technique library, gen_stubs.py decoder cascade, ASMPROC mutator catalog, and TypeArchaeology methodology built in S15-S16 are exactly the tools needed for this phase. We have a working build, a verifying CI, a canonical metric source (report.json), and a fleet-coordination-protocol that survived a 30-hour gauntlet.

**Now the real decomp work begins.**

---

## Entering Assets (from S16 close)

### Repo state
- HEAD: `40749c450` (post-100% ISI twin closeout, after `dab6cdf3` DSI crosser at 18,458 fns)
- `build/G4ZE69/report.json` regenerates on every commit (pre-commit hook is healthy)
- `tools/verify_match.sh` proven across 7,000+ commits in S15-S16
- decomp.dev webhook firing on push to origin/main

### Technique library (locked in S16)
- `docs/tracking/s16-techniques.md` — 18 promoted techniques + 4 STANDARD-track mutators
- `docs/tracking/fleet-coordination-protocol.md` — git-concurrency discipline, lock recovery, dupe-detection
- `memory/project_sn_compiler.md` — GCC 2.95 / SN ProDG compiler-matching technique notes (S9-S15 archive)
- Family-blast methodology — proven on TileWalls, INVTarget, BBHTarget, HUDTarget, EI-Light family, IFFResFile2, ChainResFile, Behavior::Get* family, etc.

### Tooling (do not regress)
- `tools/verify_match.sh` — canonical byte-equivalence gate
- `tools/gen_stubs.py` — bl/bc/blrl + 512B/2KB/8KB body decoder cascade (do NOT regenerate stubs we then overwrite — flag and convert in-place)
- `tools/corrected_pool_v2_scout.py` — TUScout's matched-file-aware scout
- `tools/size_sweep.sh` — Reviewer's deep-pass batch
- ASMPROC `inject_before` / `replace_insn` / `swap_adj` / `gpr_relabel` / `force_reg_at_pos` (use for C++→asm coercion when handwritten C++ needs nudging to match)

### Top stub-density units (s17 priority targets — from build/G4ZE69/report.json)

| Rank | Unit | Code (KB) | S17 lane |
|------|------|-----------|----------|
| 1 | `targets_s2c` | 312 | Lane 1 — OpusArchitect |
| 2 | `targets_tsc3` | 127 | Lane 1 — OpusArchitect (after s2c traction) |
| 3 | `objectsim` | 91 | Lane 2 — OpusWorker |
| 4 | `person` | 86 | Lane 3 — OpusReviewGuy (when not reviewing) |
| 5 | `object` | 77 | Lane 2 — OpusWorker (after objectsim) |
| 6 | `targets_cas` | 72 | Lane 1 — OpusArchitect (CAS trio close) |
| 7 | `sanimator2` | 68 | Lane 5 — SonnetWorker1 |
| 8 | `e_ngcrenderer` | 62 | **SKIP / defer** (SDK middleware — low PC-port value) |
| 9 | `e_animcontroller` | 39 | Lane 5 — SonnetWorker1 (animation family) |
| 10 | `eroom` | 39 | Lane 6 — SonnetWorker2 |
| 11 | `camera` | 39 | Lane 6 — SonnetWorker2 |
| 12 | `iobject` | 38 | Lane 2 — OpusWorker (object-family glue) |
| 13 | `objectfolder` | 34 | Lane 2 — OpusWorker (object-family glue) |
| 14 | `xrouting` | 30 | Lane 6 — SonnetWorker2 |
| 15 | `e_rlevel` | 30 | Lane 5 — SonnetWorker1 (renderer-adjacent) |
| 16 | `objectmodule` | 29 | Lane 2 — OpusWorker |
| 17 | `nghresfile` | 28 | **already mostly handwritten** — skip |
| 18 | `iffresfile2` | 22 | **already handwritten** — skip |
| 19-25 | aptz / SDK / library stubs | 20-25 KB each | Lane 7 — KimiWorker (batch SDK conversion) |

**Deferred (SDK / middleware — convert later or never):**
- `vmbase.a(VMBase.o)` 195 KB (Nintendo SDK)
- `thp.a(THPDec.o)` 30 KB (Nintendo SDK)
- `libaptz.a(AptActionInterpreter.cpp.obj)` 88 KB (Macromedia Flash bytecode — convert opportunistically)

---

## Fleet — 9 agents, fresh spawns (kill all S16 agents before S17 kickoff)

| Lane | Agent | Model | Role | S17 assignment |
|------|-------|-------|------|----------------|
| 0 | **MainGuy** | Opus | Orchestrator | Route + monitor + unblock + canonical-metric custodian |
| 1 | **OpusArchitect** | Opus | C++ writer (largest classes) | **targets_s2c trio** (s2c → tsc3 → cas, 511 KB total) — UI dispatch hub |
| 2 | **OpusWorker** | Opus | C++ writer (game-core) | **object family** (objectsim 91 + object 77 + iobject 38 + objectfolder 34 + objectmodule 29 = 269 KB) |
| 3 | **OpusReviewGuy** | Opus | Verify discipline + canonical metrics + opportunistic writer | **person 86 KB** when not reviewing |
| 4 | **TypeArchaeologist** | Opus | **NEW ROLE** — class layout recovery | Owns `include/types/*.h`. Feeds every writer with struct/class headers. **Rate-limiter for the fleet.** |
| 5 | **SonnetWorker1** | Sonnet | Animation family C++ | **sanimator2 68 + e_animcontroller 39 + e_rlevel 30 = 137 KB** |
| 6 | **SonnetWorker2** | Sonnet | Mid-tier systems C++ | **eroom 39 + camera 39 + xrouting 30 = 108 KB** |
| 7 | **KimiWorker** | Kimi | Batch SDK / APT conversion | **libaptz batch + small SDK objects** (target +50 KB across many small files) |
| 8 | **TUScout** | Sonnet | Coordinator | **Stub-density tracking + dupe detection + lock recovery** (same proven S16 role) |

**Worker ratio:** 1 type-archaeologist (critical path), 4 opus writers, 2 sonnet writers, 1 kimi batch, 1 scout, 1 orchestrator. **TypeArchaeologist is the rate-limiter — protect his throughput.**

---

## Session 17 Tracks

### Track T (TypeArch): Class-layout recovery — TypeArchaeologist (CRITICAL PATH)

**Why first:** Every writer in Lanes 1-3 + 5-6 will block on "what does this class look like?" within the first 30 minutes. If TypeArch lags, writers either guess and break match, or stall. **He is the critical-path agent of S17.**

**Phase 1 (0-2h): Top-10 class layouts**
1. Open `include/types/` (create if absent)
2. For each of these classes, write a header file with documented field offsets, vtable layout, and inheritance chain:
   - `cXObjectImpl`, `cXObject` (object/iobject family)
   - `cXObjectSim` (objectsim)
   - `cXPersonImpl`, `cXPerson` (person family)
   - `SAnimator2`, `SAnimator2Bone`, `SAnimator2Channel` (sanimator2)
   - `cXRoom` (eroom)
   - `cXCamera` (camera)
   - `cXRouting` (xrouting)
   - `INVTarget`, `CASTarget`, `BBHTarget`, etc. — targets family vtable common shape
3. Layouts come from: existing handwritten `.cpp` files in src/matched/ (read access patterns), DOL vtable disassembly via `tools/dol_disasm.py`, decomp.dev TU-buddy reference matching (e.g., Sims 2 PS2 if available).
4. Commit cadence: 1 header per commit, message format `types(<class>): document layout from <evidence source>`

**Phase 2 (2h+): Reactive layout requests**
- Writers post layout requests to `info` channel with topic `typereq:<class>`
- TypeArch services them in priority order (block-radius: how many functions in flight need it)
- 30-minute response SLA — if longer, writer falls back to local guess with `// TODO: TypeArch confirm` marker

**Non-negotiables:**
- Headers must compile against existing matched C++ (run `make` / ninja smoke after each commit)
- No speculative fields — every documented offset must trace to at least 2 accessor functions
- Vtable slot numbers in comments (`/* slot 12 */`)
- Inheritance chain explicit (no flat structs for MI cases)

### Track 1: targets_s2c trio — OpusArchitect

**Target: 511 KB raw size → +200-300 KB converted to real C++.**

**Strategy:** The `targets_s2c` / `targets_tsc3` / `targets_cas` units are the UI-target dispatch hub for the various game modes (Sims 2 Core, The Sims Castaway / Container, CAS / Create-A-Sim). They have heavy family structure — typically:
- One vtable per target class (ACTTarget, INVTarget, HUDTarget, ...)
- Hundreds of small methods per target (event handlers, getters, message dispatch)
- Many cross-target shared base methods

**Approach:**
1. **Family-blast first** — pick one target class (e.g., `INVTarget` since INVTarget chunks already cracked in S16) and crush all its methods semantically.
2. Convert auto-matched `void func_XXXX(void){}` stubs into the actual method signature + body for that class.
3. Use the existing INVTarget handwritten matches as template signatures.
4. Once one target is 100% semantic, pivot to the sibling target class — most methods will port with minor edits.

**Commit cadence:** 1-3 methods per commit when small, 1 per commit for >100B funcs. Message: `convert(<class>): <method> — semantic (was <stub-shape>, NB)`

### Track 2: object family — OpusWorker

**Target: 269 KB → +150-200 KB converted.**

**Strategy:** Object family is the heart of game-object simulation. `cXObjectImpl` extends `cXObject`, `cXObjectSim` is the sim-tick logic. Order:
1. Start with `iobject` (38 KB) — smallest, the interface/glue file. Defines vtable shape that the bigger classes inherit.
2. `objectfolder` (34 KB) + `objectmodule` (29 KB) — folder/module helpers, mid-sized.
3. `object` (77 KB) — cXObject core. This is where most family-blast unlocks live.
4. `objectsim` (91 KB) — cXObjectSim simulation tick. Hardest — depends on everything above.

**Approach:** Pair with TypeArch — submit `typereq:cXObject` and `typereq:cXObjectImpl` Hour 0 so Phase-1 layouts are landed before Hour 1.

### Track 3: person — OpusReviewGuy (backup writer)

**Target: 86 KB → +50-80 KB converted.**

**Strategy:** Primary duty is review (see Track R). Person conversion is opportunistic between review cycles. Existing handwritten `cXPersonImpl::Skipping3D`, `Place`, `Turn` from S16 serve as template — extend the same class layout to convert sibling methods.

### Track 5: animation family — SonnetWorker1

**Target: 137 KB → +60-100 KB converted.**

**Strategy:** sanimator2 + e_animcontroller + e_rlevel form a layered rendering+animation stack. sanimator2 is the high-level skeletal animator, e_animcontroller is per-bone playback state, e_rlevel is render-pass control. Start at sanimator2 (most stubs there), get the SAnimator2 class layout from TypeArch first.

### Track 6: mid-tier systems — SonnetWorker2

**Target: 108 KB → +50-80 KB converted.**

**Strategy:** eroom + camera + xrouting are three independent subsystems. Pick whichever has the most existing handwritten signatures to bootstrap from. eroom likely easiest (smaller class count).

### Track 7: SDK/APT batch — KimiWorker

**Target: small-file blast across libaptz + sdk_os + minor SDK objects.**

**Strategy:** Many small auto-matched stubs in SDK-adjacent units (APT scripting, OS helpers). Kimi's strength is high-volume same-pattern blast. Pick families like `AptValue` accessors, `EString` operators, where one cracked pattern unlocks dozens of siblings.

### Track R: Review + canonical metrics — OpusReviewGuy + TUScout

**Cadence:**
- **OpusReviewGuy**: 60-90 min deep-pass cycles. For each pass:
  1. `git log --since=<last-pass>` — survey what landed
  2. Spot-check 3-5 random conversions: does verify_match.sh still pass? Does the C++ look semantic (not just renamed func_XXXX)? Does the type layout match TypeArch's header?
  3. Run canonical metric: `git show HEAD:build/G4ZE69/report.json | python -c "..."` — confirm still 100.00% byte-match (this is the floor we never give back).
  4. Post `info` board update with cycle summary.
- **TUScout**: 30-min ticks tracking stub-density-by-unit. New metric in S17: **semantic ratio** = (handwritten functions / total functions) per unit. Goal: watch each top-15 unit climb from <20% to >50% over the session.

**Hard floor (non-negotiable):** any commit that drops below 100.00% byte-match is **immediately reverted** by Reviewer. No discussion. This is the difference between S16's "byte-match floor" and the S17 "semantic ceiling" — we climb the ceiling, never crack the floor.

---

## Workflow Rules

Inherited from S16 fleet-coordination-protocol + additions:

1. **verify_match.sh before every commit** (non-negotiable, unchanged)
2. **Byte-match floor at 100.00%** (NEW for S17) — if a commit drops the percent, revert. Period.
3. **`git commit --only <path>`** — never `git add -u` or `git add .` (unchanged)
4. **Filename-based case-insensitive collision check per address** (unchanged)
5. **TypeArch headers must compile** — `make` smoke after every header commit
6. **Layout requests via Cog `info` board** — topic `typereq:<class>`, response SLA 30 min
7. **Family-blast preferred** — when one method cracks semantically, parallel-port its siblings in the same session arc (don't park siblings for later)
8. **No speculative refactors** — only convert function bodies and add type headers. Do NOT reshape directory tree, rename matched files, or "tidy" existing handwritten code. (Save that for S18+ cleanup pass.)
9. **Pre-commit hook regenerates report.json** — never edit it manually
10. **Stale .git/index.lock recovery:** unchanged from S16 protocol — 30s threshold, `rm -f .git/index.lock` if PID is zombie
11. **Push discipline:** only orchestrator (MainGuy) pushes to origin. Workers commit locally; MainGuy pushes in batches after Reviewer canonical-verify

---

## Success Criteria

| Metric | Target | Stretch | Mega |
|--------|--------|---------|------|
| Byte-match (FLOOR) | 100.00% | 100.00% | 100.00% (never dropped) |
| Stub→Real KB converted | +300 KB | +500 KB | +1 MB |
| Top-15 units at >50% semantic ratio | 3 units | 6 units | 10 units |
| Type headers in include/types/ | 10 classes | 20 classes | 40 classes |
| objectsim semantic ratio | 30% | 60% | 80% |
| object semantic ratio | 40% | 70% | 90% |
| Reverts (byte-match floor breaches) | 0 | 0 | 0 |
| Bad type-header commits (don't compile) | 0 | 0 | 0 |

**Decomp.dev still reads 100.00%** — semantic conversion does not change the byte-match metric. We're trading invisible-to-public progress for **prestige-with-the-scene** progress. Inboxes / writeups / blog posts get written *about* this work, not the dashboard.

---

## Kickoff Sequence (S17 Day 1)

1. **MainGuy:** kill all 9 S16 agents (`mcp__cog__get_agents` then abandon any active tasks, dismiss workers cleanly). Spawn fresh 9-agent fleet per roster above.
2. **MainGuy:** post Track assignments to Cog task board. Brief each worker with their lane + CEO notes.
3. **TypeArchaeologist:** Hour 0 — open `include/types/`, draft `cXObject.h` and `cXObjectImpl.h` first (Lane 2 will block on these immediately).
4. **OpusArchitect:** Hour 0 — start INVTarget semantic blast (already have S16 handwritten work to extend).
5. **OpusWorker:** Hour 0 — submit `typereq:cXObject` + `typereq:cXObjectImpl`, start with `iobject` while waiting on layouts.
6. **OpusReviewGuy:** Hour 0 — establish review baseline. Run canonical metric check, confirm 100.00%, post baseline to info board.
7. **SonnetWorker1:** Hour 0 — submit `typereq:SAnimator2`, start surveying sanimator2 stub list.
8. **SonnetWorker2:** Hour 0 — pick eroom (smallest, easiest bootstrap of the three). Submit `typereq:cXRoom`.
9. **KimiWorker:** Hour 0 — survey libaptz + SDK small-stub list. Pick one family (e.g., AptValue accessors) for first blast.
10. **TUScout:** Hour 0 — establish stub-density-by-unit dashboard. Post baseline to info board. Set up 30-min tick cadence.
11. **MainGuy:** first checkpoint at 2-hour mark — TypeArch progress (Phase 1 done?), Lane 1+2 first commits landed?, review baseline clean?

---

## CEO Notes (per agent — paste into first message at spawn)

### OpusArchitect (Lane 1)
> You own the targets_s2c trio (s2c → tsc3 → cas, 511 KB total). This is UI-target dispatch — large vtable-per-class shape with hundreds of small methods each. Use family-blast: crack one target class (INVTarget recommended — already has S16 handwritten work) and port siblings in parallel. Block TypeArch with `typereq:` for any class layout you need. Verify-match-or-revert on every commit. Goal: +200-300 KB semantic by S17 close.

### OpusWorker (Lane 2)
> You own the object family (iobject → objectfolder → objectmodule → object → objectsim, 269 KB total). This is the heart of game-object simulation. Order: smallest first to build TypeArch dependency, then biggest. Submit `typereq:cXObject` and `typereq:cXObjectImpl` immediately at spawn. Goal: +150-200 KB semantic.

### OpusReviewGuy (Lane 3 / Track R)
> Primary duty: verify discipline + canonical metric custodian. 60-90 min deep-pass cycles. Hard rule: any commit dropping below 100.00% byte-match is reverted immediately, no discussion. Secondary: convert person stubs (86 KB) opportunistically between review cycles. Existing S16 cXPersonImpl::Skipping3D / Place / Turn are templates — extend the same class layout. Goal: clean review record + 50-80 KB person conversion.

### TypeArchaeologist (Lane 4 — NEW ROLE, critical path)
> You are the fleet rate-limiter. Every writer blocks on "what does this class look like?" Phase 1 (first 2h): top-10 class layouts in include/types/ — cXObject, cXObjectImpl, cXObjectSim, cXPersonImpl, SAnimator2, cXRoom, cXCamera, cXRouting, INVTarget shape, CASTarget shape. Phase 2 (2h+): reactive — service `typereq:<class>` posts on info board with 30-min SLA. Headers MUST compile against existing matched C++. Goal: protect writer throughput.

### SonnetWorker1 (Lane 5)
> You own the animation family (sanimator2 → e_animcontroller → e_rlevel, 137 KB total). Start at sanimator2 (most stubs). Submit `typereq:SAnimator2` at spawn. Goal: +60-100 KB semantic.

### SonnetWorker2 (Lane 6)
> You own mid-tier systems (eroom → camera → xrouting, 108 KB total). Pick eroom first (smallest, easiest bootstrap). Submit `typereq:cXRoom` at spawn. Goal: +50-80 KB semantic.

### KimiWorker (Lane 7)
> Batch small-file SDK/APT conversion. libaptz, sdk_os, minor SDK objects. Pick high-volume same-pattern families (AptValue accessors, EString operators). Goal: +50 KB across many small files.

### TUScout (Lane 8)
> Coordinator role same as S16: stub-density tracking, dupe detection, lock recovery. NEW S17 metric: semantic-ratio-by-unit. Watch top-15 units climb from <20% → >50%. 30-min tick cadence to info board.

---

## Key Documents / References

- `docs/tracking/s16-techniques.md` — 18 promoted techniques + 4 STANDARD-track mutators (S17 inherits all)
- `docs/tracking/fleet-coordination-protocol.md` — git concurrency, lock recovery, dupe detection
- `memory/project_sn_compiler.md` — SN ProDG / GCC 2.95 technique archive (S9-S15)
- `tools/verify_match.sh` — canonical byte-equivalence gate
- `tools/gen_stubs.py` — auto-stub generator (use for unexplored territory; do NOT regen stubs we're converting)
- `build/G4ZE69/report.json` — canonical metric source (regenerated per commit)
- `include/types/` — **NEW IN S17** — TypeArchaeologist's class-layout headers

---

## Why NOT cleanup / docs site this session

We considered scaffolding a docs site (vetritheretri/ssb-decomp-re style) but chose to defer. Rationale:
- The site is best after we have semantic coverage to document. Right now ~13% semantic = thin encyclopedia.
- Mega-session capacity is better spent on +1 MB stub conversion than on writing pages about what we already know.
- S18 or S19 can scaffold the site once top-10 units are >50% semantic — the site will write itself from include/types/ headers.

---

## Notes

- **User is hands-on this session** — checkpoints landing in real time, can re-steer mid-session.
- **Fleet is fresh** — all S16 agents killed before S17 kickoff. No context carryover. Fresh CEO notes per worker.
- **S16 100% achievement is permanent** — the byte-match floor is the safety net. We can afford ambitious semantic targets because the rollback target is always "100% bytes."
- **Push discipline tighter than S16** — only MainGuy pushes, after Reviewer canonical-verify. No worker-shell credential drama.
- **TypeArch is the critical path** — if his throughput stalls, every writer slows. Watch him first at every checkpoint.

**Let's cook. 🚀**
