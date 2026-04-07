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

### Priority 1: THE BIG UNLOCK — CBMemberTranslator (335 functions!)
**Still blocked on PMF (pointer-to-member-function) ABI.**

The SN GCC 2.95 member function pointer layout:
- +0: this-adjustment (short)
- +2: vtable offset (short, -1 = non-virtual)
- +4: field_4 (int)
- +8: object pointer (int)

Two-stage this-adjustment: (1) from vtable entry via lha, (2) from functor delta. Multi-inheritance support.

**Research needed:**
- Find original EA CBFunctor template source (Rich Hickey 1994 is the basis)
- Reverse-engineer the exact PMF byte layout from DOL thunks
- Test template patterns that make GCC 2.95 generate the matching dispatch

**If cracked:** 335 functions match in one blast. Biggest single unlock available.

### Priority 2: Mass Near-Miss Retry with Variable Declaration Order
Every function that failed with register allocation (r29↔r30 swap) is now a CANDIDATE. Systematically retry:
1. Read src/wip/version_diff/ files with reg alloc notes
2. Identify which vars the DOL puts in r29/r30/r31
3. Reorder C++ declarations to match
4. Re-verify

Expected yield: 50-200 more matches.

### Priority 3: Productive TU Sweeps (Untapped Pools)

| TU | Matched | Remaining | Rate |
|----|---------|-----------|------|
| **person** | 71/216 | 145 | 32% |
| **object** | 115+/238 | ~120 | 48% |
| **iobject** | 90+/189 | ~95 | 47% |
| **wrapper** | 170+/257 | ~85 | 66% |
| **eroom** | 57/149 | 92 | 38% |
| **e_rlevel** | 53/135 | 82 | 39% |
| **nghresfile** | 54/133 | 79 | 40% |
| **e_instance** | 67/97 | 30 | 69% |
| **dirtyxml** | 50+/67 | ~15 | 75% |

Apply ALL 8 techniques systematically to each TU.

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
| PMF ABI mismatch | CBMemberTranslator (335) | Research needed |
| SDA addressing differences | Functions using r13-relative | `extern char g[4]` for SDA globals |

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

## 📋 PRE-SESSION CHECKLIST

1. `find src/matched/ -name "*.cpp" | wc -l` — should be ~9,192+
2. `git status` — verify clean working tree
3. `git pull` — make sure you have latest
4. Regenerate `missing_functions_report.txt` (likely stale)
5. Deploy TUScout on full TU scan (background)
6. Deploy Researcher on CBMemberTranslator PMF research
7. Post initial wave of 10+ tasks to the board
8. Enforce verify-before-write workflow
9. Use `tu_match.py --combine` for ALL TU work
10. Reviewer always on rolling audit

## 🏗️ INFRASTRUCTURE REMINDERS

- Pre-commit hook auto-verifies and auto-moves VERSION_DIFF to `src/wip/version_diff/`
- `// FLAGS: XXX` header overrides default flags per-file
- Dedup check before EVERY file: `find src/matched/ -name "*ADDRESS*"`
- **GIT LOCK:** Workers spawn `git status` — `rm -f .git/index.lock` before commits
- **HEADER FORMAT:** `// 0xADDRESS FuncName (SIZEb)` — mandatory first line
- missing_functions_report.txt in **PROJECT ROOT**
- goldmine_matcher.py extended with 4 classifiers from session

## 📊 SESSION METRICS TO TRACK

- Starting file count: ______
- Target: +300-500 matches
- Commits: aim for 30+
- New techniques: document anything discovered
- TUs hitting 100%: celebrate each one

---

## 🚀 WHAT'S NEXT AFTER THIS SESSION

If we crack CBMemberTranslator (335 functions), we jump from 44.8% to ~46.4% in one shot.
If multi-blrl vtable hoisting gets solved, another 5-10% unlock.
Without new technique discoveries, expect 2-3% per session from grinding.

**Goal for next session:** Hit 46% (9,400+ matches). Focus on CBMemberTranslator research and mass near-miss retries with variable declaration order.

The road to 100% is clear. Every session compounds the techniques. Keep grinding.
