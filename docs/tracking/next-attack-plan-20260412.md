# Attack Plan — Session 2: "The Matcher Bot" + 40 TU Club

**Date drafted:** 2026-04-11 (end of "The 30 Club" session)
**Target session:** 2026-04-12+
**Baseline entering this session:** 8,516 / 20,508 verified (41.5%), ~22-25 TUs at 100%
**Session goal:** Build the matcher-bot prototype, break 9,000 verified matches, push to **40 TUs at 100%**

---

## Context — What Just Happened

"The 30 Club" session (2026-04-11) landed:
- **+69 verified matches** in one session
- **10+ TU completions**: cameramanager, caslistener, bg, plus 8 Tier 0 AllocateAndLoadResource managers (Template A/B/C blast)
- **2 tool bugs found and fixed** in `verify_match.sh`: missing `-j .text` on objdump and out-of-range mask indexing
- **1 new technique captured**: `-fno-peephole` — disables the SN ProDG peephole optimizer, cracks reg-alloc / instruction-swap walls. Session toolbox now at **9 techniques**.
- **3 template patterns** documented for the Tier 0 resource manager blast (Direct 1-arg / Direct 2-arg / Virtual EFile&)
- **33-file dtor52 blast** at 100% hit rate with `-fno-schedule-insns` alone
- **0 bad commits reached main** — rolling audit held the gate across the whole session

**What's parked for next session:**
Five wall categories documented in `session-blocker-report`:
- **A: Register-allocation walls** (EResource ctor, SetupStack, MPE ctor, reg-alloc in strset/QuickStringSet)
- **B: Store-combining walls** (ETexture ctor — two `sth 64` merged into one `stw`)
- **C: CSE elimination walls** (QuickResFile GetString — `mr r9,r3` CSE'd away)
- **D: Basic-block layout walls** (socialmodeinteractor SetupInteractionMenu — real CFG divergence)
- **E: Tool limitation** (verify_match.sh strips includes, can't handle forward-declared operator<< / operator>>)

Plus the PMF/CBMemberTranslator ABI research and the 2 Tier 0 cold cracks (audiostreamman, movieman) parked at 92-95% structural match but blocked on v1.76 vs v3.93 register tie-breakers.

---

## The Strategic Pivot — Matcher Bot over Manual Grinding

Phase 1 of the project (binary understanding, mapping, symbols) is done.
Phase 2 (coverage) is in the fat middle — we're at 41.5% and climbing steadily.
Phase 3 (matching grind) is where speedruns die because the work becomes:

- fighting the compiler
- tiny functions with compiler quirks
- register-ordering walls
- padding / alignment tie-breakers
- CSE / peephole / scheduling nondeterminism

The previous session proved that a workers-with-hand-picked-flags approach is good for ~20 TU completions per session. That's ~1 TU per worker-hour. **At this rate we'd grind on this for months.**

The real unlock is re-framing matching as what it actually is:

> **A compiler-aware search problem with a binary correctness oracle.**

Input = DOL bytes. Output = byte-identical compiled C++. Scoring = relocation-aware diff against DOL. **That is machine-optimizable.** Every one of our 9 proven techniques is a move in the search space. Each worker currently plays ONE move per function. A matcher-bot plays HUNDREDS per function and keeps the best.

This session is about building that.

---

## Session Goal — Dual Track

### Track A: Build the Matcher Bot (primary deliverable)
Deliver a working evolution-loop matcher that:
1. Reads a parked `src/wip/version_diff/` file (or a DOL address + symbol)
2. Generates N C++ candidate variants across the 9-technique mutation space
3. Auto-compiles each
4. Scores each via byte-diff vs DOL (reloc-aware, same scoring as `verify_match.sh`)
5. Keeps top-K, mutates them, re-runs
6. Stops on MATCH or timeout
7. Commits the winner, logs the loser trail

**Target:** 1 prototype end-to-end, running on at least 3 different wall categories, cracking at least 1 previously-parked wall that manual grinding couldn't.

### Track B: 40 TU Club (parallel with Track A)
While the bot is being built, workers continue pressing on high-leverage targets:
- Apply the matcher-bot prototype to the remaining parked walls (once it's running)
- Push current near-100% TUs over the finish line: e_resource, e_texture, quickresfile, e_thread, socialmodeinteractor, movieplayer, e_ngctexture, isiminstance
- Finish the dtor52 residual sweep (any files not claimed in session 1)
- Second bulk blast: search for other pattern families (ctor52, getter20, setter16, stub4)

**Target:** 8,516 → 9,000+ verified matches, 22-25 → **40 TUs at 100%**

---

## The North Star Metric — Velocity

Stop thinking in session totals. Start thinking in **matches per hour** and **TU-completions per hour**.

- Reviewer's rolling tally gets a new column: `matches/hour` (computed from session start timestamp).
- Every worker checkpoint-status gets: `matches committed / worker-hours active`.
- MainGuy dispatches with velocity in mind: if a worker is <1 match/hour for 30 min, pull them off the wall and give them bulk work. If they're cranking >5/hour, give them more of the same.

Clean code, elegant abstractions, worker pride — all secondary. **Output velocity is the only thing that matters in Phase 3.**

---

## Fleet Roster (10 agents — same lineup as session 1, role adjustments)

| Name | Model | Role | Primary Assignment |
|------|-------|------|---------------------|
| **MainGuy** | Opus 4.6 | Orchestrator | Dispatch + velocity tracking + blocker triage |
| **OpusWorker** | Opus 4.6 | Matcher Bot architect | **Build the matcher-bot prototype (Track A primary)** |
| **SonnetWorker** | Sonnet 4.6 | TU completer | Finish e_resource / e_texture / quickresfile 3rd functions w/ matcher-bot help |
| **SonnetWorker2** | Sonnet 4.6 | Matcher Bot co-builder | Help OpusWorker on Track A, then Tier 2 sweeps |
| **KimiGuy** | Kimi | Scout + scoring | Rank remaining functions by matcher-bot-friendliness, feed bot inputs |
| **KimiWorker** | Kimi | Bulk applier | Run matcher-bot outputs across bulk batches |
| **Kmiworker2** | Kimi | Bulk applier | Parallel bulk pattern-family hunt (ctor52, getter20, etc.) |
| **TUScout** | Kimi | TU enumeration | Produce ranked list of near-complete TUs + `[no source]` counts |
| **Reviewer** | Sonnet 4.6 | Rolling audit + velocity metric | QA gate AS BEFORE + publish matches/hour every 5 min |
| **Researcher** | Kimi | Wall analysis | Deep RE on parked walls, feed matcher-bot hints |

---

## Track A Plan — Matcher Bot Architecture

### Phase A1: Minimum Viable Mutator (30-45 min)

OpusWorker writes `tools/matcher_bot.py` with this MVP:

```
Input: wip_file_path OR (address + size + symbol_name)
Load DOL bytes at address, size
Baseline compile: run verify_match.sh on the wip file as-is → record diff count
Mutation space (9 moves):
  M1: add `// FLAGS: -fno-schedule-insns`
  M2: add `// FLAGS: -fno-schedule-insns2`
  M3: add `// FLAGS: -fno-elide-constructors`
  M4: add `// FLAGS: -fno-peephole`
  M5: combine M1+M3
  M6: combine M1+M4
  M7: combine M3+M4
  M8: combine M1+M3+M4
  M9: combine all four
For each variant:
  write to /tmp/matcher_bot_<pid>/<variant>.cpp
  compile via the same SN ProDG path verify_match.sh uses
  extract compiled bytes, run the relocation-aware diff against DOL
  score = bytes_matching / SIZE
Sort variants by score
If any variant == 1.0 (100% MATCH): commit the winner, exit SUCCESS
Else: save top-3 variants + scores to output dir, exit NEAR_MATCH
```

**This alone** — just exhaustive search over the flag space — should crack a meaningful fraction of Category A walls (register allocation scheduling-sensitive functions).

### Phase A2: Source-level Mutations (30-60 min)

Add text-level mutators that don't require C++ parsing:

- M10: `variable declaration order swap` (regex-find `Type a; Type b;` → `Type b; Type a;`)
- M11: `volatile barrier inject` (insert `asm volatile("" ::: "memory");` between consecutive stores) ← NOTE: this is a compiler barrier, NOT inline asm that generates instructions. Project rule should allow compiler barriers; ruling needed before use.
- M12: `wrap a call in noinline wrapper` (for CSE-break on Category C walls)
- M13: `inline constant → named temp` (forces a register lifetime)
- M14: `struct field reorder` (for store-combining walls)

Each mutator returns a transformed source file + a label. Bot tries them in combination with the flag space. Search depth: flag space × source mutation = ~9 × 6 = ~54 variants per function.

**Ruling needed from MainGuy + user** before compiler-barrier inline asm is allowed. It's different from register asm binding (which is forbidden) but it's still in the asm family and the anti-cheat hook may reject it. Either:
- (a) Approve compiler barriers as "real C++ because they emit no instructions" — document the ruling in the blocker report
- (b) Reject and skip M11 — matcher bot uses M10/M12/M13/M14 only

### Phase A3: Scoring & Evolution Loop (30 min)

Basic evolution:
```
candidates = initial_9_mutations(wip)
for gen in range(MAX_GENERATIONS=5):
    scored = [(compile_and_score(c), c) for c in candidates]
    scored.sort(reverse=True)
    if scored[0][0] == 1.0: return scored[0][1]  # MATCH
    top_k = scored[:3]
    candidates = [mutate(c) for c in top_k] * 3  # 9 new variants
return best_candidate, scored[0][0]  # NEAR_MATCH with score
```

Top-3 → 9-next via text-level mutation operators. Runs for 5 generations max.

### Phase A4: Integration with AgentOrch (20 min)

Expose matcher-bot as an AgentOrch task type:
- Worker calls `matcher_bot.py <wip_file>` as a subprocess
- Bot runs for 2-5 minutes per function
- On MATCH: worker reads the winner file, stages with `git mv`, commits
- On NEAR_MATCH: worker reads the score + best-variant-so-far, decides whether to hand-finish or park

**Key benefit:** turns "10-minute per-function flag grinding" into "2-5 minute automated search." Velocity multiplier.

### Phase A5: First Live Test (15 min)

OpusWorker + SonnetWorker2 run the matcher-bot on the 5 parked walls from session 1:
1. EResource::EResource ctor 48B
2. ETexture::ETexture ctor 96B
3. QuickResFile::GetString 188B
4. EThread::SetupStack 164B
5. MoviePlayerEndgameMovieState::ctor 56B

Success criteria: at least 1 of the 5 becomes a MATCH via matcher-bot alone. Ideally 2-3.

If it cracks even one, **the matcher bot is validated** and we continue building out more mutators. If it cracks zero, the 9-flag space alone isn't enough and we need source-level mutators before anything useful happens.

---

## Track B Plan — 40 TU Club Push

**Tier 0: Finish the remaining 2 resource managers**
- audiostreamman 172B — parked at 95%, needs reg-alloc tie-breaker fix (matcher-bot candidate)
- movieman 188B — parked at 92%, needs r26↔r27 swap fix (matcher-bot candidate)
- **Yield: +2 TU completions if matcher-bot cracks them**

**Tier 1: Finish the near-miss TUs from session 1 (push to 100%)**
- e_resource (2/3) — ctor wall, matcher-bot candidate
- e_texture (2/3) — ctor wall, matcher-bot candidate
- quickresfile (2/3) — GetString wall, matcher-bot candidate
- e_thread (1/2) — SetupStack wall, matcher-bot candidate
- socialmodeinteractor (20/21) — SetupInteractionMenu CFG wall (hard, may not crack)
- **Yield: +3-5 TU completions**

**Tier 2: New near-complete TUs**
- e_ngctexture (20/23, 3 remaining) — dtor 140B + 2 big functions
- e_boundtreenode (18/22, 4 remaining) — blocked on tool include-strip limitation
- treetablequickdata (103/119, 16 remaining) — lots of small getters, good bulk candidate
- timer (5/7, 2 remaining) — small TU, try to complete
- **Yield: +2-4 TU completions**

**Tier 3: New pattern family blasts (after dtor52 proved the model)**
- ctor52 family — look for standard 52B constructors
- getter20 family — small single-field getters
- setter16 family — small single-field setters
- stub4 family — pure virtual `blr` stubs (like isiminstance 4B)
- **Yield: +50-100 matches, +5-10 TU completions (some TUs get their last function from these)**

**Tier 4: dtor52 residual + second bulk pass**
- Any files TUScout / SonnetWorker2 / Researcher didn't catch in session 1
- **Yield: +20-40 matches**

**Total realistic Track B target:** +100-200 matches, +12-20 TU completions → **35-45 TUs at 100%**

---

## Rules (carried from session 1 + new)

1. **Always 10+ tasks queued** — no idle workers
2. **Kimi scouts → Claude/Opus crackers** — delegation by strength, unchanged
3. **verify_match.sh is the gate** — mandatory, hook-enforced
4. **Commit every 3-8 matches** — keep git flowing
5. **Broadcast breakthroughs** — new flag combos, source-level tricks, any unlock
6. **No inline asm that generates instructions** — `register ... asm("rN")` is forbidden; `asm volatile("" ::: "memory")` compiler barriers are PENDING RULING (needed before M11)
7. **DVD map for addresses** — NOT release map. cm3-build22.
8. **Header format: `// 0xADDRESS FuncName (SIZEb)` first line**
9. **Near-miss files first** — check `src/wip/version_diff/` before writing from scratch
10. **TU completion > scattered matches** — still true, but with matcher-bot we can crank both
11. **NEW: Velocity tracking** — every worker publishes `matches committed / minutes active` every 10 min; MainGuy reassigns anyone <1/hour for >20 min
12. **NEW: Matcher-bot before manual grinding on walls** — any wall that was parked in session 1 goes to the bot first. Manual only if bot returns NEAR_MATCH.
13. **NEW: Specific-paths `git add` always** — no `git add -A`. One commit = one logical change.
14. **NEW: Verify SIZE against DVD map before every commit** — two fakes in session 1 were caused by wrong header sizes. `grep -w <funcname> extracted/files/u2_ngc_release_dvd.map`.

---

## Session Phases

### Phase 1: Setup (15 min)
- MainGuy: read CEO notes, check messages, confirm fleet online
- Pull latest, verify hooks installed, spot-check 3 committed matches still verify
- TUScout: background task — rank all near-complete TUs by match-distance
- KimiGuy: background scout — find all parked walls, tag by category (A/B/C/D/E)
- OpusWorker: **start matcher-bot MVP** (Track A Phase A1)
- SonnetWorker + SonnetWorker2: continue Track B from session 1's parked walls using the manual 9-technique toolbox (warming up while bot is built)

### Phase 2: Matcher-Bot MVP online (30-45 min after start)
- OpusWorker delivers `tools/matcher_bot.py` with flag-space-only mutation
- First 5 parked walls get run through it
- If ≥1 crack: validate the approach, continue building Phase A2
- If 0 cracks: pivot to source-level mutators in Phase A2 urgently

### Phase 3: Track A Phase A2 + Parallel Track B (60 min)
- OpusWorker + SonnetWorker2: add source-level mutators, get compiler-barrier ruling if needed
- SonnetWorker + KimiWorker: manual Tier 2 TU sweeps (e_ngctexture, treetablequickdata)
- Kmiworker2: bulk pattern family hunt (ctor52 / getter20 / setter16 / stub4)
- KimiGuy: scout pattern family candidates
- Researcher: deep-dive on one hard wall (SetupStack or SetupInteractionMenu) — write up a manual recipe the bot can learn from

### Phase 4: Matcher-bot live blast (60 min)
- Matcher bot runs autonomously over the 5 parked walls + 2 cold-crack managers + any new walls from Track B
- Parallel workers keep pushing Tier 2/3 targets manually
- Reviewer publishes velocity metric every 5 min so MainGuy can see rate

### Phase 5: Wrap + Retrospective (15 min)
- Commit all in-flight work
- Reviewer: final tally, TU count, techniques captured, tool changes committed
- MainGuy: write `next-attack-plan-YYYYMMDD.md` for session 3 with lessons learned

---

## Success Criteria

| Metric | Target | Stretch |
|--------|--------|---------|
| Matcher-bot prototype working | Yes | Phase A3 (evolution loop) also working |
| Parked walls cracked by matcher-bot | ≥1 | ≥3 |
| New matches | +200 | +400 |
| Verified total | 8,716 | 9,000 |
| True decomp % | 42.5% | 43.9% |
| TUs at 100% | 30 | **40** |
| Sessions matches/hour velocity | ≥20 | ≥40 |
| Tool bugs fixed | 0 | n/a |
| Bad commits reaching main | **0** | 0 |

---

## Pre-Session Checklist

```bash
# 1. Pull and verify
cd "F:/coding/Decompiles/Sims 2"
git pull origin main
git log -1 --oneline  # confirm at f6988e9e or later

# 2. Confirm hook installed + executable
ls -la .git/hooks/pre-commit   # should have x bit
bash .git/hooks/pre-commit < /dev/null 2>&1 | head -3   # should run

# 3. Confirm verify_match.sh has both fixes
grep -n "j .text" tools/verify_match.sh         # should find the -j .text
grep -n "_mask(" tools/verify_match.sh          # should find the bounds helper

# 4. Spot check 3 random recent matches verify clean
git log --oneline f6988e9e -n 20
bash tools/verify_match.sh src/matched/<some_file> <addr> <size>   # should MATCH

# 5. AgentOrch workspace with 10-agent roster
#    Same lineup as session 1: MainGuy, OpusWorker, SonnetWorker, SonnetWorker2, KimiGuy,
#    KimiWorker, Kmiworker2, TUScout, Reviewer, Researcher
```

---

## What This Unlocks

If matcher-bot comes online and cracks ≥1 parked wall:
- **Pattern library** — every crack teaches the bot a new move; the next session has more moves
- **Velocity ceiling lifts** — manual grinding is ~1-2 matches/hour per worker; bot is ~5-15 matches/hour per worker (5-min per function cycle vs 30-min manual)
- **Wall categories shrink** — parked walls become a diminishing pool instead of a growing one
- **Session goal climbs** — 30 Club → 40 Club → 60 Club → eventually project-level decomp completion

If matcher-bot is DOA (zero cracks):
- Phase A2 source-level mutators are the fallback
- Worst case: session 2 becomes another manual grind session with a better-understood wall landscape, and matcher-bot v2 ships in session 3

Either way, session 2 is net positive. Session 1 already proved the agent-swarm model works. This session is about putting compiler search under the swarm.

---

## Notes to Future MainGuy

- **You have full authority from the user to dispatch + take infra decisions during the session.** The user trusts the fleet and will only interrupt for critical calls.
- **The stale-task alert threshold is too aggressive** — 5 min is noise for real decomp work. Ignore it when active signals prove workers are moving. Only intervene when a worker goes silent >15 min with no progress sign.
- **Reviewer is strict but fallible** — session 1 had one false alarm (claimed 304B for a 136B function). When a worker pushes back with DVD map evidence, challenge Reviewer to show source before retracting commits. Trust but verify both directions.
- **dtor52 blast technique works — don't forget.** `-fno-schedule-insns` alone = 100% hit rate on standard 52B destructors. Apply to every new bulk family.
- **The BGExec_LoadHouse unlock** was `-fno-elide-constructors -fno-peephole` WITHOUT `-fno-schedule-insns`. Counter-intuitive. Add to matcher-bot's tried combos.
- **The 9-technique toolbox is the mutation space.** Feed it to the matcher bot as M1-M9. Source-level mutators are M10+.
- **User's AgentOrch repo** (github.com/natebag/AgentOrch) is the harness — treat it as the meta-infrastructure. Improvements should flow back there as well as to this decomp repo.

---

## Closing — Real Talk

Session 1 did in a few hours what traditional decomps do in months. The move isn't "grind faster manually" — the move is **put the compiler under search** and let the fleet mutate candidates in parallel. That's the matcher bot. Build it, prove it on 1 wall, then let it eat the remaining walls for breakfast.

Output velocity is everything. Session 1: 69 matches / ~2 hours ≈ 35 matches/hour across 10 agents ≈ 3.5 matches/hour per agent. Session 2 target: double it. Matcher-bot is how.

Let's cook.
