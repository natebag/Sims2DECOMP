# Next Attack Plan — Session Starting Point

**Last session:** 2026-04-06 — 8,678 / 20,508 matched (42.3%)
**Remaining:** ~11,830 functions

## Quick Context for New Session

The auto-matcher cleared all 4-64B trivial functions. This session focused on DOL-only functions at 20-96B sizes using parallel agent workers. Key discovery: `stwu`-first prologue + `bl` calls = reliable match pattern. `mflr`-first prologue = VERSION_DIFF everywhere.

### What's Already Done (DON'T REPEAT)
- All <=64B trivial functions — auto-matcher cleared them
- ALL asm_decomp functions at ANY size — 100% cleared
- All 4-8B goldmine functions — auto-matcher cleared
- Template families at 40-56B (dtors, factories, operators, wrappers)
- 40B: 37 matches (26 OpusWorker + 11 SonnetWorker) — all stwu-first exhausted
- 44B: 10 matches — remaining are all mflr-first VERSION_DIFF
- 48B: 69 matches (35 SonnetWorker2 + 17 OpusWorker + 17 OpusWorker) — ENgcTexture, PCTTarget, EMat4, null-field families
- 52B: 17 matches (SonnetWorker) — null-check-forward 8-member, save-call-store 5-member
- 56B: 21 matches (3 ESimsCam + 18 OpusWorker stb+nonsda family)
- 60B: Hard — SDA globals, virtual dispatch, complex control flow
- 64B: Confirmed mostly VERSION_DIFF
- 68-96B: Confirmed dead — all leaf/mflr/blrl = VERSION_DIFF
- Non-leaf constructors: 5 matched at 60-80B, leaf ctors = VERSION_DIFF
- TArray methods (Construct/Copy/SetSize/operator=): TU-inlined, unmatchable standalone
- Compiler flag investigation complete — 4-state matrix discovered
- VERSION_DIFF files tested with all flag combos — most are register allocation (unfixable)
- Reviewer audit: 75 bad files cleaned, proper header format enforced

### Key Compiler Flags (4-state matrix)
- **State 1 (default):** `-O2 -fno-elide-constructors -fno-schedule-insns2 -msdata=eabi -G 8`
- **State 2 (scheduling enabled):** add `// FLAGS: -fno-elide-constructors` as first line
- **State 3 (insns1 disabled):** add `// FLAGS: -fno-schedule-insns` as first line
- **State 4 (both disabled):** add `// FLAGS: -fno-schedule-insns -fno-schedule-insns2` as first line

### Key Matching Rules (discovered this session)
- **stwu-first prologue = matchable** — functions starting with `stwu r1, -X(r1)`
- **mflr-first prologue = VERSION_DIFF** — functions starting with `mflr r0` before `stwu`
- **bl calls = high match rate** — functions that call other functions match reliably
- **blrl = VERSION_DIFF** — virtual dispatch through register = unfixable instruction reorder
- **Leaf functions = mostly VERSION_DIFF** — register allocation differs for leaf functions
- **Non-leaf constructors = matchable** — vtable store + bl to base class init
- **Leaf constructors = VERSION_DIFF** — `mr r9,r3` codegen not replicated
- **SDA globals:** `extern char varname[4]` forces r13-relative with -G 8
- **Non-SDA globals:** `extern int varname[4]` forces lis+lwz
- **Proper header required:** `// 0xADDRESS FuncName (SIZEb)` — files without get deleted

---

## Attack Vector 1: Second Pass on Productive Sizes (HIGHEST PRIORITY)

**What:** 48B, 52B, 56B still have hundreds of unmatched functions. First pass got ~107 matches. Second/third passes can find more sub-families.

**Remaining pools:**
- 48B: ~95 remaining (69 matched of 164)
- 52B: ~196 remaining (17 matched of 213)
- 56B: ~208 remaining (21 matched of 229)

**How:** Same workflow — extract, filter for stwu-first + bl, group by pattern, crack one per family, blast.

**Expected yield:** 30-60 more per size if new sub-families found

---

## Attack Vector 2: Non-Leaf Constructor Sweep (HIGH PRIORITY)

**What:** Constructors with bl calls (calling base class constructors or init methods) match reliably at any size. Only 5 matched so far.

**How:** Grep map for `ClassName::ClassName` symbols, filter for sizes 40-200B, extract and check for bl + stwu-first.

**Expected yield:** 20-50 matches

---

## Attack Vector 3: 60B Functions (MEDIUM — largest pool, hard)

**What:** 241 unmatched — the single biggest pool. But Kmiworker2 found them hard (SDA globals, virtual dispatch, complex control flow).

**How:** Highly selective filtering — only attempt stwu-first + bl-only (no blrl). May yield few matches.

**Expected yield:** 5-20 matches (low hit rate expected)

---

## Attack Vector 4: Recover Deleted Files (MEDIUM)

**What:** KimiWorker recovered 11 of 75 deleted files. There may be more recoverable from the git diff.

**How:** `git show HEAD~3:PATH` for files deleted by reviewer, add proper headers, re-verify.

**Expected yield:** 5-15 more recoveries

---

## Attack Vector 5: Extend Auto-Matcher (LOWER PRIORITY)

**What:** goldmine_matcher.py handles 4-64B. Extend classifiers for 48-64B complex patterns found this session (null-check-forward, save-call-store, stb+nonsda).

**How:** Add new pattern classifiers, run against DOL.

**Expected yield:** 10-30 per new classifier

---

## What's Blocked (Don't Attempt)

| Pattern | Why Blocked |
|---------|-------------|
| mflr-first prologue | VERSION_DIFF — no flag fixes this |
| Leaf functions (any size) | Register allocation VERSION_DIFF |
| blrl (virtual dispatch) | Instruction reordering VERSION_DIFF |
| Leaf constructors | `mr r9,r3` codegen not replicated |
| TArray::Construct/Copy/SetSize | TU-inlined (inner labels, not standalone) |
| 64B functions | Confirmed mostly VERSION_DIFF |
| 68-96B functions | Confirmed dead (all leaf/mflr/blrl) |

---

## Team Deployment Guide

| Worker Type | Best For | Avoid |
|-------------|----------|-------|
| Opus (Claude) | Sub-family cracking, complex per-function analysis, technique discovery | Simple repetitive tasks |
| Sonnet (Claude) | Family blasting, pattern scanning, high-volume matching | Very complex single functions |
| Kimi | Symbol lookup, recon, pattern decoding, file recovery | Direct matching on hard functions |
| Reviewer | Audit, dedup, header format enforcement, quality gate | Matching work |

## Pre-Session Checklist

1. Check `find src/matched/ -name "*.cpp" | wc -l` — should be ~8,678
2. Run `git status` — make sure working tree is clean
3. Deploy workers on Attack Vector 1 (second pass on 48B/52B/56B)
4. Enforce proper header format: `// 0xADDRESS FuncName (SIZEb)`
5. Run reviewer audit after each batch of matches

## Infrastructure Reminders

- Pre-commit hook auto-verifies and auto-moves VERSION_DIFF
- `// FLAGS:` header overrides default flags per-file (4 states)
- Dedup check before EVERY file: `find src/matched/ -name "*ADDRESS*"`
- VERSION_DIFF files go to `src/wip/version_diff/` — NEVER delete work
- **GIT LOCK ISSUE:** Worker agents spawn `git status` that creates lock files. `rm -f .git/index.lock` before commits
- missing_functions_report.txt is in the **PROJECT ROOT** (not docs/tracking/)
