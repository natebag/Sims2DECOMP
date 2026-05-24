# S19 Kickoff Plan

**Drafted:** 2026-05-24 (S18-ext close window)
**Sources:** s18-ext-review-cycle-5/6/7/8 (OpusReviewGuy), TUScout tick series T+0→T+300,
wall-catalog commits `bd2599308` + `f71391187`, fleet routing protocol `a7effc310`,
MainGuy S18-ext close directive, s16-techniques.md Deferred Wall Catalog.

---

## True Baseline at S19 Open

**Committed state (post Option-2-patch, contamination-proof):**
- Overall: 99.9838% (18,455 / 18,458 functions)
- Game code: 99.98% (3,652,780 / 3,653,648 bytes)
- SDK: 100.00% (492,076 / 492,076 bytes)
- Inject pool: ~9,270 (S18-ext close estimate; verify at S19 open with live count)
- Semantic ratio: ~55.8% (real C++ / total tracked files)

**3 genuinely missing functions (true 100% recovery targets):**
1. `SAnimator2::positionCharacter` — 868B @ 0x80065094 (purged in `34289428d`, fmul assembler error)
2. `EString::MakeUpper` — 52B @ 0x802D2C48 (lost when TypeArch recovery commit reverted)
3. `GXGetTexObjWrapT` — 12B @ 0x8038D9B0 (SDK, deleted in S17 cleanup wave)

---

## Deferred Carry-Overs from S18

These were ready or nearly-ready but couldn't land cleanly in S18:

| Item | Status | Notes |
|------|--------|-------|
| INVTarget::PushPlaceFilter 148B (0x801EEB64) | Verified MATCH on disk, uncommitted | Lost in catastrophe revert chain S18 |
| INVTarget::OnSetCurrentTab 164B (0x801F???) | Verified MATCH on disk, uncommitted | Uses ASMPROC_swap_operands; lost in same |
| TypeArch headers (EString.h v2, BString2.h, FastAllocPool.h) | Committed then reverted | Re-apply as S19 first act |
| OpusArchitect INVTarget converts (2 × 316B) | On origin/main | May need re-check for staleness |
| dupe_scan_v2.py | Authored but not committed | Re-commit to tools/ |

---

## S19 Three-Wave Priority Structure

### Wave 1 — 30-50B pool blast (HIGHEST PRIORITY, no infra required)

**Target:** agent/ directory, 30–50B inject stubs — **292 stubs** at S18-ext close.
All are in the 33-50B exact range (CRLF-corrected; see Fleet Targeting Guide note).

**Pattern matrix:**
- Pattern #1 (double-deref getter) — `return *(T**)this->field`
- Pattern #2 (deref+const) — `return this->field != NULL`
- Pattern #7 (bit extract) — rlwinm idiom, `return (val >> N) & 1`
- Pattern #8 (lha load) — signed short member read
- Pattern #9 (lbz+rlwinm&1) — byte-field boolean

**Assigned workers:** ObjectSimSlayer, SonnetWorker1 (source-coax fluency proven S18)

**Pre-claim discipline check (MANDATORY per S18-ext lesson):**
Before claiming any file in agent/, run:
```bash
git diff HEAD -- src/matched/agent/match_0x<ADDR>_<name>.cpp
```
If output is CRLF warnings only → file is clean to claim.
If output shows real content changes → file has prior WIP; do NOT stomp.
Windows git autocrlf generates false `M` flags on ~1,180 agent/ files — these
are line-ending artifacts, not prior work. Disambiguate before starting.

**Expected output:** ~80–120 converts per session (pattern blast rate)

---

### Wave 2 — MutatorSmith development (MID-PRIORITY, infra required)

**Target:** 81-128B+ inject stubs in class dirs + agent/, specifically:
- `eanimcontroller/`: 80 inject stubs, 17.5% real — blocked
- `sanimator2/`: ~122-127 inject stubs, 45-47% real — partially blocked
- `aptactioninterpreter/`: 127 inject stubs (102 × >256B VM-dispatch,
  24 × 129-256B, 1 × 51-80B) — requires different approach per band

**Required mutator development:**
- `region_gpr_relabel` + `swap_operands` compound recipes
- New mutators TBD based on wall-catalog analysis
- See s15-mutator-queue.md for existing backlog

**Prerequisites before Wave 2:**
1. Analyze top-10 eanimcontroller walls by band (81-128B cluster first)
2. Check for template families within eanimcontroller (may get partial blast via family detector)
3. Run `tu_match.py --combine` on eanimcontroller TU neighbors to resolve TU-dup confusion
4. Author new mutators as needed; validate on ≥2 instances before promotion

**Assigned workers:** MutatorSmith (dedicated session), OpusWorker for architecture

---

### Wave 3 — Specific wall resolution (LOW-PRIORITY, session-dependent)

**Banked wall catalog entries (from s16-techniques.md Deferred Wall Catalog):**

| Address | Name | Size | Pattern | Status |
|---------|------|------|---------|--------|
| 0x80329824 | ImageProcessingManager::FilterParams::Reset | 68B | Complex preamble: lis/lfs/stfs/stb mixed zero-init | S19 — struct layout analysis needed |
| 0x802CC934 | ENodeList::GetSizeRev | 48B | Pattern #12: 2-step bool materializer | S19 — MutatorSmith or find 2nd instance |
| 0x800B4214 | Commander::Commander | 60B | 4-way cyclic register rotation | region_gpr_relabel + this_alias_rN chain |
| 0x8004A2E0 | BBI::InventoryItem::CopyTo | 60B | this_alias_rN + site-specific renames | S15-carry |
| 0x8012B978 | (uncracked) | unknown | Unblocked by Option-2-patch | Cycle 4 attempt |

**Additional MutatorSmith candidates (8+ from S18-ext, not yet cataloged individually):**
Check s16-techniques.md "Deferred Wall Catalog" section for full list.

---

## Infrastructure Improvements for S19

### Per-worker git identity (OpusReviewGuy recommendation)
**Problem:** All workers commit as `njatobinyt@gmail.com`. Attribution requires
stylistic fingerprinting — slow and error-prone.  
**Fix:** Per-worker git config or per-worker branch → commit → PR flow.
**Benefit:** Tag-discipline verification, per-worker velocity tracking, incident routing.

### Per-worker worktrees (eliminates cwd-race)
**Problem:** Multiple workers operating in the same working tree cause index.lock
contention + false-modified CRLF artifacts polluting each other's `git status`.  
**Fix:** `git worktree add ../worker-N-wt main` — each worker gets isolated tree.
**Benefit:** Zero index.lock collisions, clean per-worker WIP isolation.

### verify_conversions.py — now production-ready
Tool committed at `4e5d4a0c2` + `303cb0319`. Statuses: OK / UNCLAIMED / INFLATE /
BULK_RELOCATE / UNDER_CLAIM. Run at session open to verify S18-ext conversion claims.

---

## Fleet Composition for S19

| Worker | Tier | Wave 1 fit | Wave 2 fit | Notes |
|--------|------|-----------|-----------|-------|
| OpusWorker | 1 | Pattern blast + technique origination | Architecture for MutatorSmith | Best for hard analysis + catalog |
| SonnetWorker1 | 2 | 30-50B source-coax (proven S18) | N/A | Wave 1 natural assignee |
| SonnetWorker2 | 2 | 30-50B source-coax | N/A | Wave 1 natural assignee |
| ObjectSimSlayer | 2 | 30-50B source-coax (proven S18) | N/A | Wave 1 natural assignee |
| OpusReviewGuy | 3 | Cross-check + tag-discipline | Wall-catalog analysis | Dual-confirmation protocol |
| TUScout | — | Tick monitoring + catalog hygiene | Carry-over tracking | This doc maintainer |

Drop: KimiWorker, KimiGuy, Researcher (per S13 fleet composition ruling).

---

## S19 Open Checklist

- [ ] Verify inject pool live count (committed, using `git ls-files --cached`)
- [ ] Re-apply TypeArch headers (EString.h v2 + BString2.h + FastAllocPool.h)
- [ ] Re-commit dupe_scan_v2.py
- [ ] Re-apply INVTarget::PushPlaceFilter + OnSetCurrentTab (from disk if still present)
- [ ] Recover 3 missing functions (positionCharacter / EString::MakeUpper / GXGetTexObjWrapT)
- [ ] Run verify_conversions.py --since S18-open-hash to audit S18-ext conversion claims
- [ ] Assign Wave 1 workers to 30-50B agent/ pool with CRLF pre-check briefing
- [ ] Route MutatorSmith to eanimcontroller wall analysis

---

_Maintained by TUScout. Last updated: S18-ext close, 2026-05-24._
