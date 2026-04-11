# Attack Plan — "The 30 Club" Session

**Date:** 2026-04-11
**Baseline:** 8,447 / 20,508 verified (41.2%) — post full exhaustive audit
**TUs at 100%:** 10
**Session Goal:** Push to **30 TUs at 100%** + break 9,000 verified matches

---

## Context

The full audit (2026-04-10) established the honest baseline: 8,447 verified matches.
848 orphans cleaned up. The workflow gap is permanently closed (pre-commit hook).

The TU landscape scan revealed a **massive opportunity**: 20 TUs are within 1-3 functions
of 100% completion. Most missing functions are near-misses sitting in `src/wip/version_diff/`
or follow a common blast pattern (`AllocateAndLoadResource`).

**Strategy: TU completions over scattered matches.** Fully completed TUs are worth more
than random progress — they prove entire systems are byte-identical and build project credibility.

---

## Fleet Roster (AgentOrch)

| Name | Model | Role | Assignment |
|------|-------|------|------------|
| **MainGuy** | Opus 4.6 | Orchestrator | Dispatch, technique research, blockers |
| **OpusWorker** | Opus 4.6 | Deep RE + technique cracking | Tier 0 blast family, hard remaining functions |
| **SonnetWorker** | Sonnet 4.6 | TU sweep + near-miss fixes | Tier 1 TUs (2-3 left each) |
| **SonnetWorker2** | Sonnet 4.6 | TU sweep + blast applier | Tier 2 TUs (4-8 left each) |
| **KimiGuy** | Kimi | Scout + triage | Identify patterns in Tier 0/1 near-misses |
| **KimiWorker** | Kimi | Scout + verification | Version_diff retry with flag variants |
| **Kmiworker2** | Kimi | Backup grinder | Tier 3 small functions |
| **TUScout** | Kimi | Full TU enumeration | Background: rank remaining TUs |
| **Reviewer** | Sonnet 4.6 | Quality gate | Rolling audit on every commit |
| **CodexReview** | Codex | Tooling + cross-validation | Validate blast scripts, spot-check results |

---

## Tier 0: "One-Shot Completions" — 11 TUs, 1 function each

**Priority: HIGHEST. Do these FIRST.**

### The AllocateAndLoadResource Blast (10 TUs)

Every `*Manager` TU is missing the same function: `AllocateAndLoadResource(EFile*, uint, uint)`.
Pattern: allocate from pool → placement new → set ID field → call virtual Load → return.

Near-miss files exist for 8/10 in `src/wip/version_diff/`. These failed the audit on
byte comparison — likely instruction scheduling or register allocation diffs.

| TU | Address | Size | Near-miss? |
|----|---------|------|------------|
| e_animman | 0x80322D44 | 88B | YES |
| e_audiostreamman | 0x80322EA8 | 172B | no |
| e_characterman | 0x80323224 | 108B | YES |
| e_flashman | 0x80324BF4 | 96B | YES |
| e_modelman | 0x80324EF4 | 88B | YES |
| e_movieman | 0x80325058 | 188B | YES |
| e_shaderman | 0x803281FC | 108B | YES |
| e_soundeventman | 0x80328394 | 88B | YES |
| e_textureman | 0x80328678 | 108B | YES |
| particleman | 0x8032B5D8 | 96B | no |

**Attack plan:**
1. **OpusWorker** cracks one (start with e_animman at 88B — simplest).
   Read the near-miss, compare disassembly, identify what's wrong.
2. Once ONE matches → write a blast script (`tools/blast_allocateandload.py`)
   that generates all 10 with per-manager struct sizes and pool names.
3. Run blast → should get 8-10 in one shot.
4. **If the pattern doesn't blast cleanly**, each has slight variations (different
   struct sizes, some use virtual dispatch for Load, some direct call). Fall back
   to per-function cracking — still only 10 functions.

**Estimated yield: +10 matches, +10 TUs to 100%**

### e_cheatmenu — Just a 24B Constructor

| TU | Address | Size | Function |
|----|---------|------|----------|
| e_cheatmenu | 0x80303CCC | 24B | CheatMenuParams::CheatMenuParams(void) |

Near-miss exists. 24 bytes = 6 PPC instructions. Trivial constructor.

**Assign to: KimiWorker (5 min task)**

**Estimated yield: +1 match, +1 TU to 100%**

---

## Tier 1: "Almost There" — 9 TUs, 2-3 functions each

### 2 functions remaining (5 TUs)

| TU | Functions remaining | Details |
|----|--------------------|---------|
| **caslistener** | HandleEvent (228B), ~CasListener (52B) | Both near-miss |
| **cameramanager** | Update (208B), GetSingleton (68B) | Both near-miss |
| **e_quickdataman** | AllocateAndLoadResource (204B), Reload (296B) | AllocAndLoad may blast with Tier 0 |
| **e_thread** | AttachToCallingThread (56B), SetupStack (164B) | Low-level thread stuff |
| **casscenedefault** | 2 functions | Small CAS scene TU |

### 3 functions remaining (4 TUs)

| TU | Functions remaining | Details |
|----|--------------------|---------|
| **quickresfile** | ctor (60B), dtor (100B), GetString (188B) | All near-miss |
| **e_resource** | ctor (48B), Write (84B), SetResSize (16B) | All small |
| **e_texture** | ctor (96B), dtor (80B), operator new (48B) | All near-miss likely |
| **e_ngcrenderer_unused** | 3× EDLEntry functions (36B each) | Same pattern, blastable |

**Strategy:**
- **SonnetWorker** takes the 2-remaining TUs (caslistener, cameramanager, e_thread)
- **SonnetWorker2** takes the 3-remaining TUs (quickresfile, e_resource, e_texture)
- **KimiGuy** scouts the near-miss files in version_diff for each, identifies what went wrong
- For e_ngcrenderer_unused: 3× 36B same-pattern functions → blast potential

**Estimated yield: +22 matches, +9 TUs to 100%**

---

## Tier 2: "Push to Finish" — 8 TUs, 4-8 functions each

| TU | Now | Total | Left | Key patterns |
|----|-----|-------|------|--------------|
| **socialmodeinteractor** | 17 | 21 | 4 | 1 dtor (52B) + 3 medium (136-200B), 3 UNTRIED |
| **bg** | 15 | 19 | 4 | Background system |
| **movieplayer** | 11 | 15 | 4 | Movie playback |
| **e_boundtreenode** | 17 | 22 | 5 | Bounding tree |
| **e_ngctexture** | 20 | 23 | 3 | dtor (140B) + CloneSwizzled (416B) + Create (460B) |
| **e_rflash** | 27 | 33 | 6 | Flash rendering |
| **e_rtexture** | 22 | 29 | 7 | Texture rendering |
| **isiminstance** | 41 | 49 | 8 | 5× 4B stubs + dtor + ctor + GetObCenter |

**Strategy:**
- **isiminstance** is the best target — 5 of its 8 remaining are trivial 4B virtual stubs
  (`blr` = empty virtual). Plus a 36B getter and a 52B dtor. The 200B ctor is the only hard one.
  **Should get 7/8 easily → 98% or 100%.**
- **socialmodeinteractor** has 3 untried medium functions. Kimi scouts the disassembly,
  Sonnet cracks them. Good candidate for blrl virtual dispatch technique.
- **e_ngctexture** remaining functions are large (416B, 460B) — hard. Park for later unless Opus has time.

**Assign to: SonnetWorker2 + KimiGuy scouting**

**Estimated yield: +30-40 matches, +4-6 TUs to 100%**

---

## Tier 3: Stretch Goals — High-function-count TUs

Only if Tier 0-2 are done and workers are idle.

| TU | Now | Total | Left | Notes |
|----|-----|-------|------|-------|
| **treetablequickdata** | 100 | 119 | 19 | 84% — lots of small getters, good blast candidate |
| **dirtyxml** | 47 | 67 | 20 | 70% — XML parsing, many 24-88B functions, 13 UNTRIED |
| **e_igameinstance** | 13 | 19 | 6 | 68% |
| **strset** | 34 | 50 | 16 | 68% — string set operations |
| **e_instance** | 65 | 97 | 32 | 67% — many small getters + medium stream ops |
| **dlgwrapper** | 50 | 76 | 26 | 65% — UI dialog wrappers |
| **wrapper** | 165 | 257 | 92 | 64% — massive but highest raw yield |

**Priority order within Tier 3:**
1. **treetablequickdata** (19 left, 84%) — closest to 100%, likely small getters
2. **dirtyxml** (20 left, 70%) — XML node traversal, known patterns
3. **e_instance** (32 left, 67%) — many small getters at end of function list

---

## Session Phases

### Phase 1: Blast Setup (first 15 min)
1. Pull latest, install hooks, verify clean tree
2. MainGuy dispatches all Tier 0 tasks immediately
3. OpusWorker starts cracking AllocateAndLoadResource pattern
4. KimiGuy scouts ALL Tier 0+1 near-miss files in version_diff
5. TUScout runs background scan for any TUs we missed

### Phase 2: Tier 0 Blast (30-60 min)
1. OpusWorker cracks first AllocateAndLoadResource → blast script
2. Run blast across all 10 manager TUs
3. KimiWorker cracks e_cheatmenu constructor (5 min)
4. **Checkpoint: 11 new TUs at 100%? (total: 21)**

### Phase 3: Tier 1 Sweep (60-90 min)
1. SonnetWorker takes caslistener + cameramanager + e_thread (6 functions)
2. SonnetWorker2 takes quickresfile + e_resource + e_texture (9 functions)
3. KimiGuy handles e_ngcrenderer_unused blast (3× 36B same pattern)
4. OpusWorker tackles e_quickdataman if AllocAndLoad blast covers it
5. **Checkpoint: 9 more TUs at 100%? (total: 30)**

### Phase 4: Tier 2 Push (90-150 min)
1. isiminstance — SonnetWorker (easy: 5× 4B stubs + 3 small)
2. socialmodeinteractor — SonnetWorker2 (3 untried medium functions)
3. bg, movieplayer — Kimi scouts, Sonnet cracks
4. e_rflash, e_rtexture, e_boundtreenode — parallel sweep
5. **Checkpoint: 4-6 more TUs at 100%? (total: 34-36)**

### Phase 5: Tier 3 + Cleanup (150+ min)
1. treetablequickdata (19 left) — SonnetWorker
2. dirtyxml (20 left) — SonnetWorker2
3. Any remaining near-misses from version_diff
4. Final commit, update docs, push

---

## Rules (proven from previous sessions)

1. **Always 10+ tasks queued** — workers must NEVER wait
2. **Kimi scouts → Claude crackers** — delegation by strength
3. **Verify before save** — mandatory, hook-enforced
4. **Commit every 3-8 matches** — keep git flowing
5. **Broadcast breakthroughs** — if a pattern cracks, ALL workers apply it
6. **No inline asm** — real C++ only, pre-commit hook blocks fakes
7. **DVD map for addresses** — NOT release map (cm3-build22 DOL)
8. **Header format required** — `// 0xADDRESS FuncName (SIZEb)` first line
9. **Near-miss files first** — check version_diff before writing from scratch
10. **TU completion over volume** — finishing a TU > random scattered matches

## Success Criteria

| Metric | Target | Stretch |
|--------|--------|---------|
| TUs at 100% | 30 (from 10) | 35+ |
| New matches | +200 | +350 |
| Verified total | 8,650 | 8,800 |
| True decomp % | 42.2% | 42.9% |
| AllocateAndLoadResource blast | 8/10 | 10/10 |
| Near-miss recoveries | 30 | 50 |

---

## Pre-Session Checklist

```bash
# 1. Pull and verify
cd "F:/coding/Decompiles/Sims 2"
git pull origin main
git log -1 --oneline  # confirm at f4e61d10 or later

# 2. Install hooks
bash tools/install-hooks.sh
ls -la .git/hooks/pre-commit

# 3. Verify baseline
find src/matched -name "match_*.cpp" -type f | wc -l  # should be ~8,453

# 4. Quick sanity check — pick 5 random matched files, verify
shuf -n 5 <(find src/matched -name "match_*.cpp") | while read f; do
  addr=$(basename "$f" .cpp | grep -oE '[0-9A-Fa-f]{8}' | head -1)
  echo "Testing $f..."
done

# 5. Deploy workspace in AgentOrch with 10-agent roster
```

---

## What This Unlocks

If we hit 30 TUs at 100%, the project enters a new phase:
- **Credibility:** 30 fully-verified systems prove the decomp methodology works
- **Compounding:** Each completed TU reduces the search space for remaining functions
- **PC port viability:** Complete TUs can be compiled for PC without gaps
- **Community:** Contributors can pick up any incomplete TU and push it to 100%

After this session, the next priority shifts to the BIG TUs:
wrapper (92 left), person (140 left), object (143 left), sanimator2 (166 left).
Those are the real mountains. But first — **let's plant 30 flags.**
