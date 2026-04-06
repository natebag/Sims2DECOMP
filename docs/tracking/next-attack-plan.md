# Next Attack Plan — Session Starting Point

**Last session:** 2026-04-06 — ~9,045 / 20,508 matched (~44.1%)
**Session yield:** +164 verified matches (template blasting + TU compilation + blrl breakthrough)
**Remaining:** ~11,463 functions

## Quick Context for New Session

MASSIVE session: three phases. Phase 1 cleared template families (TArray, Recon*, static_init = 112 matches). Phase 2 pivoted to TU compilation (21 matches, proved workflow). Phase 3 discovered blrl virtual dispatch solution (31+ matches, unlocks thousands more).

### THE BREAKTHROUGH: blrl Virtual Dispatch SOLVED

**The #1 blocker (60-90% of remaining functions) has a solution.**

The SN compiler generates correct `blrl` virtual dispatch natively when you use proper C++ virtual class declarations. We were doing it wrong — using manual function pointers instead of actual virtual methods.

**The technique:**
1. Find `lha rX, OFFSET(r9)` near blrl → entry = `(OFFSET - 8) / 8`
2. Declare class with N+1 virtual methods:
```cpp
struct Base {
    virtual void V0();  // entry 0 (offsets 8/12)
    virtual void V1();  // entry 1 (offsets 16/20)
    // ... up to entry needed
};
```
3. Call normally: `self->VN()` → compiler generates correct blrl
4. Use `// FLAGS: -fno-elide-constructors`

**SN vtable-at-end layout:**
```
+0: type_info ptr (4B)
+4: padding (4B)
+8: entry0_this_adj (2B via lha, sign-extended)
+10: padding (2B)
+12: entry0_func_ptr (4B)
+16: entry1_this_adj
+20: entry1_func_ptr
...
```

**Proven on:** GoalUnlock::DoStream, ESim::RefreshSkin, 14x ENgcTexture virtual trampolines, 6x SimsMemCardWrap CardSys interface, GameData::GetSelectedPlayerFamily

**Limitation:** Works reliably for single-blrl functions. Multi-blrl (2+ virtual calls in one function) may have scheduling issues with interleaved vtable setup.

### What's Already Done (DON'T REPEAT)

**Individual matching (exhausted):**
- All <=64B trivial functions — auto-matcher cleared
- ALL asm_decomp functions at ANY size — 100% cleared
- All template families: TArray (127/165), Recon* (33/33), static_init (16/16), AptValue (11)
- 40B: 59 matches — OpusWorker verified "exhausted" claim was WRONG, found 38 more
- 44B: 15 matches
- 48B: 69 matches — pool tapped out
- 52B: 18 matches
- 56B: 21 matches
- 60B: 2 matches (13% hit rate)
- STL templates: 92/92 already matched
- All Recon* templates exhausted (Save/Load/Stream/PtrVector)

**TU compilation (proven but slow):**
- caslistener: 12/12 (validated workflow)
- catalogresource: 8/10 (+5 this session)
- movieplayer: 13/15 (+3)
- careers: 12/23 (+4)
- simhead: 7/11 (+2)
- skincompositor: 5/14 (+1 fix)
- e_ngctexture: 20/23 (+15 via blrl)
- goalunlock: 5/14 (+2 via blrl)
- simsmemcardwrap: 15/35 (+6 via blrl CardSys)
- actionqueuehud: 6/32 (+1)
- frameeffects: 7/26 (+2)
- esim: 53/84 (+1 via blrl)
- wallmanipulator: 22/58 (+1)

**Confirmed dead ends:**
- Leaf functions (any size) — register allocation VERSION_DIFF
- mflr-first prologue — VERSION_DIFF
- blrl with 2+ virtual calls — scheduling VERSION_DIFF (sometimes)
- Hardcoded DATA addresses (lis+addi) — compiler generates lis+ori
- Register shuffling (or rX,rY,rY) — compiler optimizes away
- 152B-236B template families — SDA + data addresses
- -fno-elide-constructors outside Recon* — narrow fix
- Branch layout (error path inline vs end) — systemic compiler difference
- Load grouping (lwz;lwz;stw;stw vs lwz;stw;lwz;stw) — scheduling difference

### All Discovered Techniques

| Technique | What It Does | Where It Works |
|-----------|-------------|----------------|
| Template family blast | Match 1 → blast all instantiations | TArray, Recon*, static_init (100% rate) |
| blrl virtual dispatch | Declare C++ virtual class → correct blrl | Single-blrl functions (proven) |
| TU compilation (--combine) | Compile whole TU for context | SDA globals, some register allocation |
| SDA extern | `extern char g[4]` → r13-relative | All SDA globals |
| -fno-elide-constructors | Prevents RVO | Recon* stack struct patterns |
| -fno-schedule-insns | Disables insn scheduling pass 1 | Store ordering VERSION_DIFF |
| `short` return/loop types | Forces `extsh` sign extension | GoalUnlock, counter loops |
| Magic division constants | 0xCCCCCCCD for /20, 0x2AAAAAAB for %24 | Careers arithmetic |
| Local variable for callee-save | `char* obj = g_obj` forces r30 save | static_init family |
| NonVirtualBase wrapper | `struct NVB { char data[N]; }` for vtable offset | Vtable-at-end constructors |
| Verify before write | verify_match.sh BEFORE saving | ALL matches (71% failure without) |

---

## Attack Vector 1: blrl Single-Function Sweep (HIGHEST PRIORITY)

**What:** 118 single-blrl candidates identified across all TUs. Each needs individual RE but the virtual dispatch technique is proven.

**Best targets (interface pattern = multiple functions same class):**
- SimsMemCardWrap CardSys (6 matched, more possible)
- Any TU with Manager/System/Service patterns

**How:** For each TU, identify single-blrl functions, declare virtual class, crack.

**Expected yield:** 30-60 matches across all TUs

---

## Attack Vector 2: TU-by-TU Deep RE (MEDIUM — the long game)

**What:** Pick TUs with high existing match rates. Replace asm stubs with real C++. TU context helps with SDA and some register allocation.

**Best TU targets (most unmatched, some matches for context):**
- wallmanipulator: 22/58 (36 remaining)
- actionmenu: 14/34 (20 remaining)
- actionqueuehud: 6/32 (26 remaining)
- cascostumes: 5/34 (29 remaining)
- casgenetics: 7/29 (22 remaining)
- simsmemcardwrap: 15/35 (20 remaining)

**How:** TU-by-TU, function-by-function. Start with smallest stwu+bl functions.

**Expected yield:** 2-6 per TU for quick functions, more with deep RE

---

## Attack Vector 3: Class Hierarchy Reconstruction (HIGH — enables blrl at scale)

**What:** Build vtable maps for major classes. Once we know the vtable layout, ALL virtual dispatch in that class becomes matchable.

**How:**
1. Parse vtable addresses from DOL
2. Map virtual function names to vtable entries
3. Declare class hierarchies in TU files
4. All blrl functions using that class become matchable

**Priority classes:** ESim, GoalUnlock, CardSys, ActionQueue, CAS system

**Expected yield:** 50-200 per major class fully reconstructed

---

## Attack Vector 4: Auto-matcher Expansion (LOWER)

**What:** Add new classifiers to goldmine_matcher.py for patterns discovered this session.

**New classifiers to add:**
- blrl single-dispatch (with virtual class template)
- ReconSave/Load pattern
- static_init pattern
- Magic division constants
- CardSys interface pattern

**Expected yield:** 10-30 per new classifier

---

## What's Blocked (Don't Attempt)

| Pattern | Why Blocked |
|---------|-------------|
| Leaf functions (any size) | Register allocation VERSION_DIFF |
| mflr-first prologue | VERSION_DIFF |
| Multi-blrl (2+ virtual calls) | Scheduling VERSION_DIFF (sometimes) |
| Hardcoded DATA addresses (lis+addi) | Compiler generates lis+ori |
| Branch layout differences | Error path inline vs at end |
| Load grouping (lwz;lwz vs lwz;stw) | Scheduling difference |
| Complex rendering (GX API) | 288B-2168B, needs deep RE |
| bdnz delay loops | Unmatchable without inline asm |

---

## Team Deployment Guide

| Worker Type | Best For | Avoid |
|-------------|----------|-------|
| Opus (Claude) | blrl class reconstruction, deep per-function analysis, technique discovery | Simple leaf triage |
| Sonnet (Claude) | TU-level matching, blrl application, template blasting | Very complex single functions |
| Kimi | Quick leaf/non-leaf triage, symbol lookup, vtable recon | Complex blrl class reconstruction |
| Researcher (Kimi) | Vtable mapping, class hierarchy analysis, TU scanning | Code writing |
| Reviewer | Audit, dedup, cleanup, quality gate | Matching work |

## Pre-Session Checklist

1. Check `find src/matched/ -name "*.cpp" | wc -l` — should be ~9,045+
2. Run `git status` — make sure working tree is clean
3. Regenerate missing_functions_report.txt (stale from this session)
4. Deploy Researcher on class hierarchy reconstruction (Attack Vector 3)
5. Deploy Opus/Sonnet on blrl single-function sweep (Attack Vector 1)
6. Deploy Kimi on TU triage (which TUs have single-blrl candidates?)
7. Enforce verify-before-write workflow
8. Use tu_match.py --combine for ALL TU work

## Infrastructure Reminders

- Pre-commit hook auto-verifies and auto-moves VERSION_DIFF
- `// FLAGS:` header overrides default flags per-file (5 states)
- Dedup check before EVERY file
- VERSION_DIFF files go to `src/wip/version_diff/`
- **GIT LOCK ISSUE:** Worker agents create lock files. `rm -f .git/index.lock` before commits
- **VERIFY BEFORE WRITE:** mandatory (71% failure without)
- **blrl technique:** declare virtual class → call self->VN() → correct codegen
- missing_functions_report.txt in **PROJECT ROOT** — may need regeneration
