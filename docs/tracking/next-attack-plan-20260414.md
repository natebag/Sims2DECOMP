# Attack Plan — Session 4: "The SDA Sweep"

**Date drafted:** 2026-04-13 (end of Session 3)
**Target session:** 2026-04-14+
**Baseline entering this session:** 8,250 / 20,508 unique addresses (40.2%)
**Session goal:** Crack the r13 SDA2 technique, sweep all SDA-dependent systems, push to **8,700+ unique (42%+)**

---

## Context — What Just Happened

Session 3 "The Dedup + Family Spotter" was the biggest session in the project:
- **+430 unique matches** (7,820 → 8,250), crushing both the +200 base and +400 stretch targets
- **40% milestone crossed** — first time over 40%
- **SDA extern breakthrough** — `extern char globalName[]` generates correct lis/addi relocations, unlocking hundreds of previously-walled functions
- **Scheduler insight** — default GCC scheduling reproduces SN ordering for complex functions
- **8 technique discoveries**, 3 TU completions, 1,209 stale files cleaned, 953 dedup aliases consolidated
- **SDK exclusion zone confirmed** — DolphinSDK at 0x8024-0x8039 is Metrowerks-compiled, unmatchable

**What's parked for next session:**

### SDA2 technique (TOP PRIORITY — session opener)
- r13-relative addressing (`lwz rN, offset(r13)`) is unsolved
- Researcher's preliminary findings: `-msdata=eabi` flag + `__attribute__((section(".sdata2")))` may work
- 200+ functions use this pattern — cracking it is the next wave unlock
- WAV/Stream voice functions confirmed as heavy r13 users

### Remaining walls
- **Register-allocation walls** — DOL picks different registers, no source-level fix known
- **Magic division constants** — complex arithmetic patterns
- **Store-combining walls** — compiler merges stores DOL keeps separate
- **Complex control flow** — branch structure mismatches in switch statements, loops

### Technique library (proven, carry forward)
1. `extern char name[]` — SDA lis/addi relocations (BREAKTHROUGH)
2. Default scheduling for complex functions >100B
3. Bitfield structs → single rlwimi
4. `unsigned int` + `~MASKu` → 32-bit rlwinm masks
5. Struct member access prevents constant folding
6. Local variables force load-before-store ordering
7. Empty struct + `__builtin_new` → vtable at offset 0
8. `volatile` store ordering for field sequence control
9. Virtual class declarations for blrl dispatch
10. Per-file `// FLAGS:` override system

---

## The Strategic Pivot — SDA2 + System Sweeps

Session 3 proved that technique breakthroughs are the real force multiplier:
1. The SDA1 extern breakthrough alone produced 50+ direct matches and enabled hundreds more
2. Family spotting + template replication is the batch mechanism (one crack → N matches)
3. The remaining ~12,000 functions break down roughly:
   - ~3,000 SDK (Metrowerks, unmatchable) — EXCLUDE from denominator
   - ~2,000 SDA-dependent (lis/addi or r13) — crackable with SDA techniques
   - ~3,000 medium complexity (scheduling/flag-fixable) — bot-blastable
   - ~4,000 hard (RA walls, complex control flow) — individual hand-cracks or new techniques

Session 4 targets the SDA-dependent and medium-complexity pools. The hard pool is Session 5+.

---

## Session Goals

### Track A: r13 SDA2 Crack (Day 1 priority — session opener)
Crack the r13-relative addressing pattern. If this works, it unlocks 200+ functions.

**Approach:**
1. OpusWorker + Researcher: test `-msdata=eabi` flag with SN ProDG compiler
2. Try `__attribute__((section(".sdata2")))` on extern declarations
3. Test on 5 known r13 functions (WAV voice functions from Researcher's report)
4. If technique works: document and blast across all r13-dependent functions
5. If technique fails: investigate linker script modifications or section placement

**Target:** Crack the technique on at least 1 function. If proven, blast 50+ more.

### Track B: Systematic SDA1 Sweep (primary match-count work)
Session 3's SDA sweep was ad-hoc. Session 4 does it systematically.

**Approach:**
1. Build `tools/sda_scanner.py` — scan all version_diff files, identify which ones have lis/addi patterns
2. For each SDA-dependent file: apply `extern char[]` pattern + flag variants automatically
3. Batch-verify with matcher_bot integration
4. Target systems in order: APT (569 remaining), Effects, Camera, Sim, Audio, Render

**Target:** +100-200 matches from systematic SDA1 sweep of all remaining systems.

### Track C: APT Deep Mining (secondary)
APT system has ~569 unmatched functions. Session 3 cracked ~50. Session 4 targets the medium pool (80-200B).

**Approach:**
1. APT type system is now decoded — use AptValue tagged-value knowledge
2. AptActionInterpreter is the biggest single class — prioritize its methods
3. Apply bitfield/rlwimi technique on APT set* methods
4. Use virtual class declarations for APT classes with blrl dispatch

**Target:** +50-100 APT matches from medium-complexity functions.

### Track D: TU Completion Sprint (tertiary)
12 TUs at 100%. Many more are close but have files scattered in agent/.

**Approach:**
1. Build proper agent/ → TU mapping (TUScout started this)
2. Identify TUs that are actually near-complete when counting agent/ files
3. Target the genuinely missing functions

**Target:** +5 TU completions (17 total).

---

## Fleet Roster (10 agents — adjusted from Session 3 attrition)

| Name | Model | Role | Primary Assignment |
|------|-------|------|--------------------|
| **MainGuy** | Opus 4.6 | Orchestrator | Dispatch + velocity tracking |
| **OpusWorker** | Opus 4.6 | Architect + cracker | SDA2 crack + APT deep mining |
| **SonnetWorker** | Sonnet 4.6 | Bulk blaster | SDA1 systematic sweep |
| **SonnetWorker2** | Sonnet 4.6 | Bulk blaster | SDA1 systematic sweep + cleanup |
| **KimiGuy** | Kimi | Family Spotter | Scan for new SDA-dependent families |
| **KimiWorker** | Kimi | Bulk applier | SDA1 family replication |
| **Kmiworker2** | Kimi | Bulk applier | SDA1 family replication |
| **TUScout** | Kimi | TU enumeration | Agent/ → TU mapping, completion tracking |
| **Reviewer** | Kimi | Rolling audit + QA | Spot-check + dupe detection |
| **Researcher** | Kimi | Deep RE | SDA2 research + wall analysis |

Note: 3 Codex agents (CodexWorker, CodexWorker2, CodexReview) died mid-Session 3. Recruit replacements if available.

---

## Rules (carried from Sessions 1-3 + new)

1. **Always 10+ tasks queued** — no idle workers
2. **Kimi scouts → Claude/Opus crackers** — delegation by strength
3. **verify_match.sh is the gate** — mandatory, hook-enforced
4. **Address collision check before EVERY commit** — `py tools/count_matched.py 2>&1 | grep -i <addr>`
5. **Non-overlapping lane assignments** — each agent owns a specific system/address range
6. **No inline asm that generates instructions** — compiler barriers ALLOWED; register bindings FORBIDDEN
7. **DVD map for addresses** — NOT release map. cm3-build22.
8. **Skip SDK range 0x8024-0x8039** — Metrowerks-compiled, unmatchable
9. **Default scheduling first on complex functions** — only add -fno-schedule-insns if default is worse
10. **SDA extern pattern: `extern char name[]`** — array notation, not scalar
11. **Commit every 5-8 matches** — keep git flowing
12. **Use `tools/git_safe_stage_and_commit.sh`** for all match-file commits
13. **Broadcast technique discoveries** — new patterns benefit the whole fleet

---

## Session Phases

### Phase 1: SDA2 Crack (30-60 min)
- OpusWorker + Researcher: test `-msdata=eabi` on 5 WAV voice functions
- Everyone else: pull latest, verify hooks, review Session 3 technique notes
- If SDA2 cracks: broadcast technique, begin r13 sweep immediately

### Phase 2: Systematic SDA1 Sweep (90-120 min)
- SonnetWorker/2: build sda_scanner.py + sweep all version_diff systems
- KimiGuy: family-spot SDA-dependent clusters in agent/
- KimiWorker/Kmiworker2: replicate SDA family templates
- OpusWorker: APT deep mining (80-200B functions)

### Phase 3: APT + TU Completion (60 min)
- OpusWorker: AptActionInterpreter methods
- TUScout: updated TU ranking with agent/ mapping
- Workers: target near-complete TUs from ranking

### Phase 4: Wrap (15 min)
- Final commit, dedup pass, tally
- Write Session 5 plan

---

## Success Criteria

| Metric | Target | Stretch |
|--------|--------|---------|
| r13 SDA2 technique cracked | Yes | Blast 50+ functions |
| SDA1 systematic sweep | +100 | +200 |
| APT deep mining | +50 | +100 |
| New matches total | +200 | +400 |
| Unique-address total | 8,450 (41.2%) | 8,650 (42.2%) |
| TU completions | +5 (17 total) | +10 |
| Bad commits | **0** | 0 |

---

## Notes to Future MainGuy

- **SDA2 is the opening play.** If `-msdata=eabi` works, it's another Session 3-scale unlock. If it fails, pivot immediately to SDA1 systematic sweep — don't waste the session debugging compiler flags.
- **Non-overlapping lanes are MANDATORY.** Session 3's dupe problem came from mob pushes. Every agent gets a specific system. No exceptions.
- **Address collision check before every commit.** `py tools/count_matched.py 2>&1 | grep -i <addr>` catches cross-directory collisions that `git ls-files` misses.
- **SDK exclusion (0x8024-0x8039) saves time.** Don't assign anyone to DolphinSDK functions — they're Metrowerks-compiled and will never match.
- **OpusWorker is the technique pioneer.** Give him the hardest unsolved problem first. His pattern-recognition instincts found 8 techniques in one session.
- **The effective matchable pool is ~17,000 (not 20,508).** ~3,000 SDK functions are unmatchable. So 8,250/17,000 ≈ 48.5% of matchable functions are done. The real 50% milestone is closer than it looks.

---

## Closing

Session 3 proved the compounding model: technique breakthrough → family spotting → template blast → clean up → repeat. Session 4 applies the same model to SDA2 + systematic SDA1 sweeps. The technique library is now 10+ proven patterns deep. The remaining ~9,000 matchable functions are a mix of SDA-dependent (crackable with current + SDA2 techniques) and hard walls (future sessions).

Target: 8,450-8,650 unique addresses (41-42%). Honest numbers, proven techniques, clean lanes.
