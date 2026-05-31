# S20 Kickoff Plan — The Hard-Tier Phase

**Drafted:** 2026-05-31, at S19 close (11.88% clean).
**Supersedes nothing** — extends `s19-kickoff-v3.md` (the honesty reset). All v3 rules
still apply verbatim: clean % is the only headline, no quotas, no velocity targets, walls
are legitimate output, ASMPROC/inline-asm/NON_MATCHING all banned, checkpoint honestly.

---

## Where we are

- **11.88% clean** (8,459 / 3,653,648 game .text bytes), pushed to origin/main.
- **+0.42pp this S19 session** via ~170 game-code + ~68 SDK forced→clean conversions.
- **The tractable getter/recipe veins are MINED.** E*/ENgc* getters, BString strings,
  sync/pool/heap, apt Dict-dispatch, C-math, SDK getters, the no-schedule false-wall
  sweep — all swept or honestly bounded.

**S20 is a different, harder phase.** Expect SMALLER %/session. That is the honest
long-horizon plateau v3 predicted — and it's fine. A session that lands 10 hard cracks +
documents 30 walls + ships one tooling unlock is a good S20 session.

---

## What carries over (don't rebuild)

- **The "swap-on-checkpoint" fleet pattern** (the big S19 win): a matcher self-picks a vein,
  converts one-at-a-time, and **checkpoints the instant context deepens or a match needs
  >1 attempt** — banking a continuity memory so a fresh-context successor resumes cold.
  This prevented degraded matches all session. Keep it.
- **The technique library** (all `feedback_*` memories): RAII lock-guard, no-schedule-retry
  (INT-branch scope), lwzx source-canonicalization (symbol-base only), float-temp-first,
  HW-register getter recipe, extern-array-base, ternary-anticoloring, `// LANG: c`,
  delegator-vs-allocator, vptr-after-5-data-words.
- **The wall taxonomies** (per-matcher continuity memories + walls.md): coloring, CSE,
  copy-prop / SN-ProDG-point-version, float-return-branch, comparison-constant, peephole-fold,
  store-sort, mtctr-loop, register-base-lwzx, privileged hand-asm. These tell S20 matchers
  what NOT to waste attempts on.
- **Verify-tooling**: `verify_match.sh --strict --symbol`, `// LANG: c` + `// VERIFY-SYMBOL:`
  markers, `tools/disasm_digest.sh`, `tools/verify_mwcc.py`, `tools/find_false_wall_candidates.py`.
- **Ops:** Codex/WSL agents NEVER commit (drvfs wedge) → MainGuy commits via native git.
  MainGuy runs the background orphan-lock auto-clearer (90s-age + zero-commit-procs gate).
  No `--flag` literals in commit MESSAGES (block-no-verify hook substring trips). Atomic
  forced→clean: `git rm` the legacy agent stub + add clean in ONE commit (else audit counts
  the address forced).

---

## The S20 work, in priority order

**Lane A — remaining tractable getters (the last easy surface, do first).**
SN-8 started fresh untouched subsystems (save/SimsMemCardWrap, SkinCompositor, GoalUnlock,
BBI::InventoryItems, levelgen) — these still have getter/predicate density crackable with the
banked recipes (SDA/TArray/bit-extract/int-predicate + default-flags-first). Finite but real.
MWCC-SDK still has VI/GX/PAD/CARD/DSP getters+setters (skip the lhzu-fold/privileged walls).

**Lane B — the objdiff / compiler-version unlock (the highest-leverage NEW work).**
A large class of remaining walls are *compiler-version differences*: our verify uses SN ProDG
3.9.3, but the 2005 build used a slightly different point-version (copy-prop, peephole-fold,
addi-vs-mr, redundant-li, comparison-constant canon all trace to this). **We have 3.8.1 / 3.7 /
3.5 installed.** If a per-file SN-ProDG-version override (like the existing `// FLAGS:` /
`// COMPILER:` markers) lets matchers try an older point-version, an entire wall CLASS could
unlock at once. This is Tooling's flagship S20 task. Pair with a real per-function asm-diff
view (extend `diff_func.sh`/`disasm_digest.sh`, or integrate objdiff) so coloring/scheduling
walls are diagnosable at the instruction level.

**Lane C — the parked deep-RE tiers (deliberate, slow, fresh context each).**
- apt deep tier (SN-3's notes): EAStringC PushString* refcount-inlining, 348B AptValue
  refcount ops, 372-1060B type-system opcodes (isObjectOfType/InstanceOf/CastOp/Extends/
  GetMember). Use ternary-anticoloring; loop Wall-Analyst.
- allocator-wall class + 384B InitializeHeapStatics capstone (SN-7's notes) — objdiff-tier.

**Lane D — wall re-validation.** Old `// NOTE: unmatchable` labels proved untrustworthy
(SN-8 cracked 3). With the banked techniques + (Lane B) version-override, re-attempt walls
periodically. `tools/find_false_wall_candidates.py` + the swap_operands/symbol-base list seed this.

---

## Proposed S20 roster (~6–7 agents; scale to the work, not a number)

| Role | Model/CLI | Shell | S20 focus |
|------|-----------|-------|-----------|
| **MainGuy** (orchestrator) | Claude opus | powershell | Route, commit-broker for WSL agents, run auto-clearer, custodian of clean %, push after Reviewer-K passes. |
| **Matcher-A** (game-code) | Claude opus | powershell | Lane A fresh-subsystem getters first; then Lane C apt deep tier with fresh context. |
| **Matcher-B** (game-code) | Claude opus | powershell | Lane A other subsystems / Lane C allocator tier + capstone. Different lane from A (claim:<addr>). |
| **Matcher-MWCC-SDK** | Claude opus | powershell | Remaining SDK getters/setters (VI/GX/PAD/CARD/DSP) via // COMPILER: mwcc + // LANG: c. |
| **Tooling-Engineer** | Codex | wsl | **Lane B flagship:** per-file SN-ProDG-version-override + asm-diff/objdiff view. Stage-only; MainGuy commits. |
| **Reviewer-K** | **Kimi** | powershell | Non-Claude cheat-detection backstop (KEEP — Codex-reviewer went dormant). Per-batch spot-checks. |
| **Wall-Analyst** | Kimi | powershell | Second-opinion reshapes — MORE important in S20 as walls dominate. No commit. |
| *(optional)* **Auditor-Coord** | Claude sonnet | powershell | walls.md + post-batch audit-trend. Can fold into MainGuy if trimming. |

CEO-note essentials for every matcher (derive full notes + continuity-memory pointers per agent):
1. Read CLAUDE.md "Decomp Honesty Rules" + this plan FIRST.
2. Resume from the relevant continuity memory (per-matcher S19 docs) for your lane.
3. Per function: claim:<addr> → disasm_digest.sh → natural C++ → `verify_match.sh --strict`
   (+ `--symbol`/`// LANG: c`/version-override as needed) → ATOMIC forced→clean commit → or wall.
4. Use the banked techniques; consult the wall taxonomy to skip non-source-fixable classes;
   loop Wall-Analyst before logging a new wall.
5. CHECKPOINT honestly when context deepens or a match needs >1 attempt — bank continuity.
6. Locks: wait/retry, NEVER rm, flag MainGuy if stuck >2min (auto-clearer handles orphans).
   No `--flag` literals in commit messages. Tight single-shot commits.
7. NO quota. Walls are success. A degraded match is worse than no match.

---

## Long horizon — trekking this along

This is months-to-years honest work. The realistic trajectory:
- **Lane A** gives the last incremental easy %.
- **Lane B (version-override + objdiff)** is the swing factor — if it cracks a compiler-version
  wall class, it could move the number meaningfully; if not, those bytes stay walled honestly.
- **Lane C** is slow, high-byte-value deep-RE — a few cracks/session.
- The clean % may plateau somewhere in the teens-to-low-30s on agent effort alone, where
  remaining functions need human-style intuition or asm-level work. **That ceiling is real and
  OK.** A project honestly at 30% for a long time, with every wall documented for a smarter
  future pass / contributor / Decomp Me / Discord ask, is worth infinitely more than a fake 100%.

The human shows up to: skim walls.md for repeat-failure clusters, glance at the clean-%
trend after batches, approve roster/tooling changes, and free host-side disk space when
convenient. You keep the metric honest; the agents do the cracking. That's the job.

---

## First actions on S20 spawn
1. `python tools/audit_clean_matches.py` — confirm baseline (~11.88%).
2. `python tools/find_false_wall_candidates.py` — refresh the candidate worklist.
3. Read `project_status_20260531_s19_close.md` + the per-matcher continuity memories.
4. Propose the roster above (adjust to taste); paste CEO notes from §roster + continuity pointers.
5. Decide Lane A vs Lane B first emphasis with the user. Tooling starts Lane B (version-override) early — it's the leverage.
