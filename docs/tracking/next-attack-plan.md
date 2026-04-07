# Next Attack Plan — Session Starting Point

**Last session:** 2026-04-06/07 — ~9,192 / 20,508 matched (~44.8%)
**Session yield:** ~300 verified matches, 52 commits, 8 new techniques
**Remaining:** ~11,316 functions

## Quick Context for New Session

EPIC session. 3 waves of techniques unlocked functions across the entire codebase:
- **Wave 1:** Template family blasting (TArray, Recon*, static_init)
- **Wave 2:** TU compilation + blrl breakthrough
- **Wave 3:** Variable declaration order + sub-object pointer techniques

The remaining ~11,000 functions are NOT hopeless. Every session we discover new techniques that unlock chunks of previously-blocked functions. Keep iterating.

---

## 🔑 PROVEN TECHNIQUES (all verified this session)

### 1. blrl Virtual Dispatch (UNLOCKS HUNDREDS)
Declare proper C++ class with virtual methods in vtable order:
```cpp
struct Base {
    virtual void V0();  // entry 0 (offsets 8/12)
    virtual void V1();  // entry 1 (offsets 16/20)
    // ... declare up to entry needed
};
void func(Base* self) { self->V1(); }  // correct blrl codegen
```
**Identifying vtable entry:** Find `lha rX, OFFSET(r9)` near blrl → entry = `(OFFSET - 8) / 8`

**SN vtable-at-end layout:**
- +0: type_info ptr
- +8: entry0 this-adj (lha)
- +12: entry0 func ptr
- +16: entry1 this-adj
- +20: entry1 func ptr

Use `// FLAGS: -fno-elide-constructors`

### 2. Explicit retptr for Struct-Return (FIXES r30/r31 SWAP)
```cpp
// OLD (broken)
struct Foo func(int key);

// NEW (matches)
void* func(int* retptr, int key);
```
Applies to functions returning strings, structs, or complex objects with register allocation issues.

### 3. -fno-schedule-insns (STORE ORDERING FIX)
Add `// FLAGS: -fno-schedule-insns` as first line to disable scheduling pass 1. Fixes store-ordering VERSION_DIFF.

### 4. short Types Force extsh (SIGN EXTENSION)
When DOL uses `extsh` for loop counters or return values, declare those variables as `short` instead of `int`. GoalUnlock::GetUnlockTotal proven.

### 5. Anti-CSE with Separate Externs (PREVENT COMMON SUBEXPRESSION)
When DOL re-loads a global each call instead of caching, use DIFFERENT extern names for same-base globals to prevent compiler CSE.

### 6. Varargs `...` Generates crclr (BREAKTHROUGH)
When DOL has `crclr 4*cr1+eq` before a `bl` call:
```cpp
extern "C" void func(void*, ...);  // The ... forces crclr!
```
Proven on CDirtyXml::getFirstAttribute/getNextAttribute, INVTarget::SetPriceCheatString.

### 7. Sub-Object Pointer (FORCES INTERMEDIATE REGISTER) ⭐
When DOL uses r9 intermediate for field accesses:
```cpp
SubObj* sub = &self->subObj;  // Forces r9 = &self->subObj
sub->method();
```
Proven on TextItem/MenuItem/ButtonItem/TextBaseItem::Startup, ISimsObjectModel::AnimStart*.

### 8. Variable Declaration Order Controls Registers ⭐⭐⭐ GAME-CHANGER
**GCC 2.95 assigns callee-saved registers in DECLARATION ORDER:**
- First declared local → r31
- Second declared local → r30
- Third declared local → r29

When a function fails on r29↔r30 swap, REORDER your local variable declarations to match the DOL's register usage. Proven on ActionQueue::ctor.

**Limitation:** Works for int/pointer locals (r29-r31). Does NOT work for float registers (f0-f13).

---

## 🎯 PRIORITY TARGETS FOR NEXT SESSION

### Priority 1: ✅ CBMemberTranslator PMF — SOLVED (commit a59f7729)

**OpusWorker cracked it 2026-04-07.** All 331 CBMemberTranslator0/1/2/1wRet thunks (120B each) matched in one blast. +1.61% project progress.

**The recipe (5 non-obvious keys, all load-bearing):**
1. **DVD map, not release map.** The shipped DOL is from cm3-build22, not cm3-build25. Use `u2_ngc_release_dvd.map` for address lookups.
2. **Free function or static member**, not non-static member. `&f` arrives in r3 directly with no `this` adjustment.
3. **Local variable** `obj = f.m_obj` — forces GCC 2.95 CSE on the load before the dispatch branch.
4. **0-arg PMF type** `void(T::*)()` works universally for ALL CBMT families. The 30-instruction dispatch is byte-identical regardless of actual arity.
5. **`-fno-schedule-insns` ALONE**, NOT `-insns2`.

**Working template:**
```cpp
// FLAGS: -fno-schedule-insns
class TargetClass;
class CBFunctorBase {
public:
    void (TargetClass::*m_pmf)();
    TargetClass* m_obj;
};
void cbmt_thunk_<addr>(CBFunctorBase& f) {
    TargetClass* obj = f.m_obj;
    (obj->*f.m_pmf)();
}
```

**Generator:** `tools/blast_cbmember.py` parses DVD map for `CBMemberTranslator*<...>::thunk(...)` symbols, generates one .cpp per thunk in `src/matched/cbmt_blast/`, runs verify_match.sh per file.

**Remaining work:**
- 3 144B UIDialog thunks (LoadGameTarget/SaveGameTarget/PDATarget at 0x802919CC, 0x80296024, 0x8034DC1C) — different code shape, separate task.
- Cleanup: delete fake `src/matched/agent/match_0x803B5E20_*.cpp` and `src/decomp_cpp/cb_member_translators.cpp` (147 unverified specs with wrong template).

### Priority 2: Mass Near-Miss Retry with Variable Declaration Order
Every function that failed with register allocation (r29↔r30 swap) is now a CANDIDATE. Systematically retry:
1. Read src/wip/version_diff/ files with reg alloc notes
2. Identify which vars the DOL puts in r29/r30/r31
3. Reorder C++ declarations to match
4. Re-verify

Expected yield: 50-200 more matches.

**⚠️ MAJOR CORRECTION (2026-04-07, SonnetWorker2 field report):**
Most version_diff files are NOT register-allocation issues. They're actually **stale C++ with wrong logic, wrong types, or wrong call sites** — fake "near-miss" framing on what's actually fully wrong source.

- Var-decl-order technique only applies when 3+ callee-saved locals exist
- Most version_diff files are leaf functions using r0-r12 only
- The real fixes involve: re-RE'ing the disassembly, fixing call signatures, fixing parameter types, fixing missing extsh/srawi, fixing anti-CSE patterns

**Realistic yield revised down: ~20-50 matches via patient re-RE, not 50-200 via mechanical reordering.** The technique is real but applies narrowly. Don't over-promise this lane.

**Proven patterns from SonnetWorker2's pass:**
- 0x800BCD04 GetLanguage (8B) — missing param caused `srawi r3,r3,8` mismatch
- 0x803A05D8 TextBlock_SetDirty (16B) — `oris` 0x10000000 constant flag
- 0x80038E50 ApplyFunFrame (20B) — anti-CSE 2-extern SDA trick
- 0x80077DD4 CUnlockDisplay::SetupForSocial (40B) — wrong call signature

### Priority 3: Productive TU Sweeps (CORRECTED 2026-04-07)

⚠️ **CRITICAL CORRECTION** — TUScout v2 ranking (info tag `tu-ranking-v2`) filters out `[no source]` functions. The TU sweep workflow is approaching its ceiling.

**Real ceiling per TU (v2 — only counts MISMATCH WITH source file):**

| TU | MISMATCH+source | [no source] | Realistic via sweep |
|----|-----------------|-------------|---------------------|
| **wrapper** | 5 | 85 | **5** (was 44) |
| **iobject** | 23 | 76 | **15-20 if SDA cracked** |
| **person** | 5 | 134 | **5** |
| **e_rlevel** | 1 | 79 | **1** |
| **object** | 0 | 121 | **0** (FULLY MINED) |
| **sanimator2** | ~4 | ~180 | **0-2** (float reg blocker) |

**Total TU sweep ceiling: ~30-50 matches** (was estimated at 50-200 in v1).

After these are exhausted, the remaining ~11,000 unmatched functions are `[no source]` and require:
1. `extract_function.py` to pull bytes from DOL
2. Manual RE of disassembly into C++
3. 10-50x slower per function than TU sweep

**Workflow lesson:** `[no source]` ≠ sweepable. Filter accordingly.

### Priority 3a: SDA Externals Blocker — SOLVED (2026-04-07)

**KimiGuy cracked it.** See info channel tag `sda-externals` (note 9f7a2624).

**The fix:** Wrap SDA globals in a struct >= 8 bytes to force them above the `-G 8` SDA threshold. This makes the compiler emit `lis/lfs` (or `lis/lwz`) instead of `@sda21` r13-relative loads.

```cpp
// BEFORE (compiler emits @sda21, doesn't match DOL):
extern float g_FarZVal;
float GetFarZVal() { return g_FarZVal; }

// AFTER (forces lis/lfs, matches DOL):
struct EGraphicsGlobals {
    float farZ;
    float nearZ;
    float aspect;
};
extern EGraphicsGlobals g_graphicsGlobals;
float GetFarZVal() { return g_graphicsGlobals.farZ; }
```

**Where to apply (immediate):**
- e_graphics: 3 functions (GetFarZVal/GetNearZVal/GetScreenAspect) — KimiGuy applying
- iobject: ~23 type-info getters — KimiWorker applying
- Any other function with `lis/lfs` or `lis/lwz` in DOL where compiler emits `@sda21`

**Estimated unlock: ~30+ matches across the project from this single technique.**

### Priority 3b: TU Sweep Wind-Down
Finish the realistic targets in wrapper, iobject, person — then pivot to extraction work.

### Priority 4: Animation/Math System Deep RE
- **e_animcontroller** (7+/103, ~95 remaining) — apply subobj ptr + var order
- **sanimator2** (10+/159, ~150 remaining) — lots of leaf functions but some non-leaf
- **e_mat4** (44+/83, ~38 remaining) — matrix operations
- **e_graphics** (57+/93, ~35 remaining) — graphics helpers

### Priority 5: 5 TUs at 100% — Maintain These
Already fully decompiled:
- caslistener (12/12)
- quickresfile (37/37)
- isiminstance (49/49)
- socialmodeinteractor (21/21)
- cameramanager (8/8)

Don't let any regressions slip in.

---

## 🚧 KNOWN SYSTEMIC BLOCKERS (avoid wasting time)

| Blocker | Affects | Workaround |
|---------|---------|------------|
| Multi-blrl vtable aliasing | 2+ virtual calls in one function | None known — compiler re-loads vtable |
| Leaf function register allocation | All leaf functions | Try variable declaration order (sometimes works) |
| Float register allocation (f0/f13) | Float-heavy functions | None known |
| Load-store interleaving | Leaf setters | -fno-schedule-insns helps some |
| Branch layout ordering | Error paths | None known |
| Hardcoded DATA addresses (lis+addi) | Global data pointers | Compiler generates lis+ori instead |
| bdnz delay loops | Hardware cache flushes | None known — unmatchable without inline asm |
| ~~PMF ABI mismatch~~ | ~~CBMemberTranslator (335)~~ | **✅ SOLVED 2026-04-07** — see commit a59f7729, info note dbca4a3a. Recipe: free function + 0-arg PMF type + local CSE var + `-fno-schedule-insns`. 334/334 thunks matched. |
| ~~SDA addressing differences~~ | ~~Functions using r13-relative~~ | **✅ SOLVED 2026-04-07** — see commit 5290e636. Wrap globals in struct >= 8 bytes to force above `-G 8` SDA threshold → compiler emits `lis/lfs` instead of `@sda21`. |
| Instruction scheduling (mr/stw swap, etc) | ~100-200 functions | None — deep compiler heuristic, accept as VERSION_DIFF |
| `[no source]` functions | ~1,926 functions | Direct DOL extraction via `extract_function.py` (next-phase track) |
| Inline-asm-stub source files | ~10,913 functions in `src/asm_decomp/` | Pilot workflow doc at `docs/systems/inline-asm-stub-workflow.md` |
| **Workflow gap (orphan files)** | **~300-800 estimated stale files in src/matched/** | Bulk audit via `tools/audit_matched_dir.py` + cleanup commit |

---

## 🧑‍🤝‍🧑 TEAM DEPLOYMENT STRATEGY

### Agent Roles (proven effective)

| Agent | Role | Strengths |
|-------|------|-----------|
| **OpusWorker** | Deep RE + technique discovery | Complex analysis, finding new techniques |
| **SonnetWorker** | TU matching, cross-TU sweeps | Fast iteration, good pattern recognition |
| **SonnetWorker2** | TU matching, blast specialist | Template family blasting |
| **KimiGuy** | TU scouting, target hunting | Fast recon, finding productive TUs |
| **KimiWorker** | Triage, quick verification | Leaf vs non-leaf checks |
| **Kmiworker2** | Backup grinder | VERSION_DIFF retests |
| **Researcher** | Deep research, docs | Class hierarchies, ABI analysis |
| **TUScout** | Full TU scans | Mass enumeration, ranking |
| **Reviewer** | Quality gate | Audit, verify, cleanup |

### Rules That Work
1. **Always have 10+ tasks queued** — workers should NEVER be idle waiting for tasks
2. **Kimi scouts → Claude crackers** — let Kimi find targets, Claude matches them
3. **Commit every 3-8 matches** — keep the git history flowing
4. **Verify before save** — mandatory, no exceptions
5. **Mass broadcasts for breakthroughs** — everyone applies new techniques immediately
6. **Proactive check-ins** — check agent status BEFORE they message you idle

### Task Format That Works
```
[TECHNIQUE] TU_name — X/Y matched, Z to crack (description)
Brief task description with specific targets and expected patterns.
`python tools/tu_match.py --combine TU_NAME`
Edit TU file directly. Verify before saving. Header format required.
```

---

## 📋 PRE-SESSION CHECKLIST (UPDATED 2026-04-07)

1. `find src/matched/ -name "match_*.cpp" | wc -l` — should be ~9,321+ (file count, not verified count)
2. `git status` — verify clean working tree
3. `git pull origin main` — make sure you have latest from remote (we now push regularly)
4. **Run `bash tools/install-hooks.sh`** — installs the pre-commit hook that rejects unverified match files (NEW; required to prevent orphans)
5. Regenerate `missing_functions_report.txt` (likely stale)
6. **First task of the session: bulk audit cleanup.** Run `python tools/audit_matched_dir.py` and review results with the user before doing other work. Don't dispatch matching work until the orphan count is known.
7. Deploy TUScout on full TU scan (background) — but with v2 ranking methodology (filter `[no source]` from "potential")
8. Post initial wave of tasks targeting the new productivity tracks: inline-asm-stub conversions, DOL extraction for [no source]
9. Enforce verify-before-write workflow (now hook-enforced)
10. Use `tu_match.py --combine` for ALL TU work
11. Reviewer always on rolling audit (now spot-checks the hook isn't bypassed)

## 🏗️ INFRASTRUCTURE REMINDERS

- **NEW (2026-04-07):** Pre-commit hook BLOCKS commits where match files don't pass verify_match.sh (COMPILE_FAIL → BLOCK, HEADER_UNPARSEABLE → BLOCK, MISMATCH → auto-move to wip/version_diff/). Bypass with `SKIP_VERIFY=1 git commit ...` (logged loudly).
- **NEW:** After clone, run `bash tools/install-hooks.sh` to install the pre-commit hook locally.
- `// FLAGS: XXX` header overrides default flags per-file
- Dedup check before EVERY file: `find src/matched/ -name "*ADDRESS*"`
- **GIT LOCK:** Workers spawn `git status` — `rm -f .git/index.lock` before commits (Windows file locking is sticky; this is the standard workaround in this multi-agent workspace)
- **HEADER FORMAT:** `// 0xADDRESS FuncName (SIZEb)` — mandatory first line. Pre-commit hook now ENFORCES this (was previously SKIP-and-pass).
- **DVD MAP, NOT RELEASE MAP** — the shipped DOL is from `cm3-build22`. All address lookups MUST use `extracted/files/u2_ngc_release_dvd.map`. The release map (`cm3-build25`) has different addresses and will produce false leads. This was the source of multiple wasted sessions.
- missing_functions_report.txt in **PROJECT ROOT**
- goldmine_matcher.py extended with 4 classifiers from session

## 📊 SESSION METRICS TO TRACK

- Starting file count: ______
- Target: +300-500 matches
- Commits: aim for 30+
- New techniques: document anything discovered
- TUs hitting 100%: celebrate each one

---

## 🚀 WHAT'S NEXT AFTER THIS SESSION (UPDATED 2026-04-07)

**The headline task for the next session: BULK AUDIT + ORPHAN CLEANUP.**

Goal: convert "9,321 files / ~8,500 estimated verified" into "N files / N verified" — get the file count to actually mean something. Steps:

1. **Run full `tools/audit_matched_dir.py`** across all 9,321 files in `src/matched/` (60-90 min sequential, faster with parallel workers)
2. **Relocate all FAIL files to `src/wip/version_diff/`** in one big cleanup commit
3. **Patch `count_matched.py` to validate before counting** (currently counts files only)
4. **Confirm the post-audit count** — that's the new honest baseline

After cleanup, the next big productivity tracks are:

**Track 1: Inline-asm-stub conversion** (~10,913 functions)
- Workflow doc at `docs/systems/inline-asm-stub-workflow.md` (KimiGuy authored)
- Pick one stub at a time, replace inline asm with hand-written matching C++
- Slower per-function but unlocks the largest pool of "have source, need real C++" functions

**Track 2: Direct DOL extraction for `[no source]` functions** (~1,926 functions)
- Use `extract_function.py` to pull bytes from DOL
- Manual RE → write C++ from disassembly
- 10-50x slower per function than TU sweep
- SonnetWorker has the pilot mission for this (ERFont::GetStringSize)

**Track 3: Targeted blocker research** (next 1-2 systemic issues)
- After PMF and SDA were cracked this session, the next systemic blocker is **instruction scheduling/register allocation** (TUScout's research). Hard problem, may not be solvable.
- Worth spending time finding a workaround before grinding the long-tail tracks.

**Goal for next session:**
1. **Honest count established** (post-bulk-audit)
2. **+50-100 inline-asm-stub conversions** as a realistic target via the new workflow
3. **+10-30 DOL extraction matches** to validate that workflow
4. **Run the SonnetWorker pre-commit hook installer** so future workers can't introduce new orphans

The compounding-techniques era is over. The systemic blockers are largely solved (PMF + SDA + blrl + var-decl-order + sub-obj ptr + crclr + extsh + retptr). What remains is grind work on individual functions, divided into clear productivity tracks. Pick a track and execute.

---

## 🛰️ ACTIVE ORCHESTRATION LOG (2026-04-07 session)

**MainGuy live dispatch state. Update as things change.**

### Open pinboard tasks
| ID | Title | Claimed by | Status |
|----|-------|------------|--------|
| 60eedd56 | [CRACK] CBMemberTranslator PMF ABI | OpusWorker | in progress — pivoted to verification of `src/decomp_cpp/cb_member_translators.cpp` (147 specializations) |
| abae262f | [NEAR-MISS RETRY] Variable declaration order sweep on src/wip/version_diff/ | unclaimed | nudged KimiWorker |
| 8ddcd5fe | [TU SWEEP] person — 71/216 matched | unclaimed | open to all workers |

### Critical PMF intel (TUScout note 33c57e94, KimiWorker note 51877add)
- **Working CBFunctorBase layout** (from matched file `src/matched/agent/match_0x803B5E20_CBMemberTranslator0_ACTTarget_thunk.cpp`):
  ```cpp
  struct CBFunctorBase {
      short m_thisAdj;     // offset 0
      short m_vtblIndex;   // offset 2 (negative = direct call)
      int   m_vtblOff;     // offset 4 (or m_funcPtr — union)
      int   m_obj;         // offset 8
  };
  ```
- **Existing implementations:** `src/decomp_cpp/cb_member_translators.cpp` — 147 specializations (69 CBMemberTranslator0 + 78 CBMemberTranslator1).
- **Specimen list:** `tools/cbmember_specimens.txt` — 337 entries sorted by size (334 @ 120B, 3 @ 144B).
- **Already-matched references:** 0x803B5E20 (ACTTarget), 0x8013E628 (constructor stub), 0x802AED8C (wrapper).
- **Approach pivot:** verify-and-blast, NOT write-from-scratch.

### Outstanding research dispatches
- **TUScout:** rank-order next 5 productive TUs → `tools/tu_priority_ranking.txt`, info tag `tu-ranking`. Inputs: person, object, iobject, wrapper, eroom, e_rlevel, nghresfile, e_animcontroller, sanimator2, e_mat4, e_graphics. Will inform next round of TU sweep tasks.
- **Reviewer:** rolling audit on every new commit on main — header format, file location, no inline asm, re-run verify_match.sh. Report regressions immediately.

### Backup task queue (post next when board empties)
1. [TU SWEEP] object — 115/238 matched (~120 remaining, 48%)
2. [TU SWEEP] iobject — 90/189 matched (~95 remaining, 47%)
3. [TU SWEEP] wrapper — 170/257 matched (~85 remaining, 66%)
4. [TU SWEEP] dirtyxml — 50/67 matched (~15 remaining, 75% — easy 100% candidate)
5. [TU SWEEP] e_instance — 67/97 matched (~30 remaining, 69% — easy 100% candidate)
6. [TU SWEEP] eroom — 57/149 matched (~92 remaining, 38%)
7. [TU SWEEP] nghresfile — 54/133 matched (~79 remaining, 40%)
8. [BLAST] CBMemberTranslator post-crack mass apply (gated on 60eedd56)
9. [DEEP RE] e_animcontroller (~95 remaining)
10. [DEEP RE] sanimator2 (~150 remaining)

### Worker assignments snapshot (last refresh: 2026-04-07T09:50)
- SonnetWorker — working
- SonnetWorker2 — working
- OpusWorker — working (PMF crack 60eedd56)
- KimiGuy — working
- Kmiworker2 — working
- Researcher — working
- KimiWorker — idle (nudged toward abae262f)
- TUScout — idle (nudged toward TU ranking)
- Reviewer — idle (running rolling audit)

### Rules being enforced this session
- 3+ tasks always queued on the board
- Verify-before-save mandatory (anti-cheat)
- Real C++ only, no inline asm
- Header format `// 0xADDRESS FuncName (SIZEb)` first line
- 5 matches minimum per claim before re-checking the board
- Commit every 3-8 matches
