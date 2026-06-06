# S20 Close + S21 Plan

**S20 first live run closed 2026-06-06.** Orchestrated via the Cog (MainGuy/Opus + multi-family matcher fleet). All work committed + pushed to origin/main. This doc = honest progress review + the next-session (S21) plan.

---

## S20 result — the number moved honestly

**11.88% → 12.38% clean** (+0.50pp; 434,044 → 452,332 game `.text` bytes; +~18,300 clean bytes). Every byte a strict-verified clean match replacing a forced/ASMPROC stub, **zero cheat-flags raised all session**, double-validated by two non-Claude reviewers (Kimi). Walls documented honestly. This is a strong hard-tier session (the plan predicted slow; +0.50pp is well above the "good session" bar).

### What landed
- **Both GeneralAllocator capstones** — EAHeap::InitializeHeapStatics (384B) + FPHeap sibling (180B), via the banked **function-local-static recipe** (raw char buffer for the pool array + extern dtor for the atexit path + `// VERIFY-SYMBOL` for the preceding `__tcf` thunk). Replaced 27-directive ASMPROC stubs.
- **AptDate sMethod sweep** — 24 clean getters/setters in ONE Opus seat (the high-yield highlight).
- **AptArray sMethod family swept** — ~10 clean (pop/shift/push/unshift/sort/sortOn/set/reserve/concat/etc.).
- **RECIPE-STR wall-class crack** (the session's best technique win) — see below.
- **Pi (GPT-5.5) Lane A** — save/SimsMemCardWrap, BBI::InventoryItems, GoalUnlock, levelgen getters; cracked a hard register-coloring fn (PreloadGame) via struct-modeling. The non-Claude matcher bet paid off.
- **DolphinSDK** (Sonnet, MWCC) — steady getter/setter/callback volume.

---

## Key strategic findings (carry into S21)

1. **SN-VERSION / Lane B is DEAD with the current toolchain.** Installed SN ProDG 3.8.1 / 3.7 / 3.5 produce **byte-identical** output to the 3.9.3 verify default (confirmed by Pi, Opus-1, Opus-2 across copy-prop / CSE / coloring classes). AND `toolchain-bootstrap.md` + our 12%+ exact-match rate prove **3.9.3 IS the original build compiler** (GCC 2.95.3 + SN BUILD v1.76). So point-version "walls" are NOT a wrong-compiler problem — they are genuine. `download_tool.py` only offers 3.5/3.7/3.8.1/3.9.3 from decomp.dev; there is no other SN ProDG to fetch. **Do not spend matcher effort hunting compiler versions.**

2. **The 392B+ GeneralAllocator deep-RE tier is exhausted-by-walls.** Opus-2f's definitive test: 3 maximally-different shapes (branchy ReportNext, guard+loop+lock Init, straight-line ctor) ALL wall on the **same redundant-mr register-coloring class** — the 2005 SN ProDG allocator makes less-optimal reg/order choices than our correct 3.9.3, with **no source lever** to force worse codegen. Combined with FindChunkBin/GetBlockInfoForChunk/DescribeChunk = the whole tier is this one class. **All near-match decodes parked in `src/wip/near_match/`, objdiff-ready.** This tier is a **Lane-B/objdiff target, NOT a matcher-attempt target.**

3. **apt VALUE/GC/CTOR is the high-yield Opus lane** (~10-24 clean/seat). Productive sub-families: AptValue, AptValueGC, AptValueVector, AptArray, AptDate, AptObject, AptNativeHash. **apt OPCODE HANDLERS** (InstanceOf/CastOp/Extends/TypeOf/GetMember) = objdiff/point-version walls — leave documented.

4. **RECIPE-STR (banked, prominent).** The stack-temp EAStringC string-box coloring wall is CRACKED: `struct EAStringC { char* m_ptr; int m_pad; }` is **8 bytes** (the pad forces 8-aligned compiler-temp slots reproducing the DOL temp region) + `// FLAGS: -fno-schedule-insns` (preserves the two m_ptr store order) + refcount-bump-once between the two stores + reverse-order inline dtor. Unlocks the whole toString/string-box sub-family. Re-test on any logged "slot-region coloring" wall.

5. **Swap-on-checkpoint works.** Each Opus seat cracked ~7-24 then banked a continuity memory and handed off cold to a fresh successor with zero ramp-up. Keep this.

6. **Lane A getters (Pi) + SDK (Sonnet)** are the steady-volume lanes; Opus belongs on deep-RE (apt), not small getters.

---

## Infra fixes shipped this session (all live)

- **Pre-commit hook** now passes a unique per-`(pid,file)` `--outdir` so concurrent fleet commits don't clobber each other's `build/verify` intermediates (was causing FALSE "MISMATCH on tracked file" blocks → needless SKIP_VERIFY). Commit `237e56a5b`. Match-decision logic unchanged.
- **Orphan-lock auto-clearer (MainGuy background watchdog)** — mtime-based, zombie-immune; clears `.git/index.lock` when 0-byte & age>20s OR age>60s, polling 10s.
- **Commit hygiene rule**: ALWAYS `git commit --only <exact paths>` — the fleet shares ONE git index, so a bare `git commit` sweeps other agents' staged files (and the working tree's ~1,271 benign LF/CRLF phantom files).
- **Timezone calibration**: local machine clock is EDT (UTC-4); Cog timestamps are UTC. Don't judge lock/process age against Cog timestamps (phantom +4h). Use local-clock file mtime.
- **Known cleanup (deferred)**: ~1,271 LF/CRLF phantom files in the working tree (empty-diff, not staged, harmless with the scoped-commit rule). Needs a one-time `git add --renormalize` + `.gitattributes eol=lf` at a quiet moment.

---

## S21 plan — focus the fleet on what works

**Roster (leaner, all-productive — no dead-end lanes):**
| Seat | Model | Lane |
|------|-------|------|
| MainGuy | Opus | orchestrator, commit-broker, pushes after review, runs lock-clearer |
| Matcher-Apt | Opus | apt value/GC/ctor: remaining AptDate (toString 728B, ctor, getDayOfWeek) + AptObject + objectMemberLookup 6612B + the 2 banked near-walls (sMethod_join 2/125, scriptFunctionSortFunc 65/92 — levers noted) |
| Matcher-Pi | Pi (GPT-5.5) | Lane A getters: remaining levelgen/save/GoalUnlock + the dense EA E*/ENgc* engine-getter veins (S19 found 0x802E-0x8033 game code, getter-dense) |
| Matcher-SDK | Sonnet | DolphinSDK MWCC getters/setters |
| Reviewer-K / K2 | Kimi | non-Claude cheat-detection; review proactively as commits land |
| Scout-Triage / Auditor-Coord | Haiku | worklist feed + audit-trend (nudge them early — they idle until pinged) |

**Do NOT re-staff:** the 392B+ allocator deep-RE tier (parked for objdiff). Wall-Analyst optional.

**The real S21 swing factor = OBJDIFF.** Both the allocator tier AND the point-version coloring walls are decoded + parked, waiting on an instruction-level objdiff view to either (a) confirm them as permanent compiler-version walls, or (b) reveal a source lever we missed. Tooling-Engineer's `diff_func.sh` asm-diff view is a start; a real objdiff integration is the highest-leverage NEW work. If it doesn't crack them, those bytes stay honestly walled.

**Operating notes for S21:** scoped commits only; reviewers review proactively; MainGuy pushes incrementally (push-then-confirm-sweep is validated); spin successors on checkpoint (apt is high-yield, worth continuing); nudge Scout/Auditor at kickoff; clean the retired-agent roster + the LF/CRLF phantom before starting.

---

## Honest bottom line

12.38% clean, every byte real, every wall documented, infra hardened, the productive veins (apt + Lane A + SDK) identified and the dead-end (allocator coloring tier) parked for the right tool. The plateau the plan predicted is real — the remaining easy surface is thinning, and the next big unlock is objdiff, not more matcher attempts on coloring walls. Months-to-years honest work; the number climbs correctly. That's the job.

---

## Per-agent CEO Notes (S21 — ready to paste into `propose_team`)

> **Shared preamble — every agent reads this first, no exceptions:**
> 1. Read `CLAUDE.md` "Decomp Honesty Rules" — supersedes everything.
> 2. Read `docs/tracking/s20-close-s21-plan.md` (this doc) + `docs/tracking/s20-kickoff-v2.md`.
> 3. cwd may be `F:\coding\AgentOrch`; for ALL repo ops use absolute paths under `F:\coding\Decompiles\Sims 2\`.
> 4. **Honest clean matches ONLY** — no ASMPROC / inline asm / `.byte`/`.long` / naked / register-pin / `__builtin_unreachable` / `// NON_MATCHING`. Can't match cleanly → **log a wall and move on. That is success.**
> 5. **No quota.** A degraded/forced match is worse than no match.
> 6. **Commit hygiene (shared git index!):** ALWAYS `git commit --only <your exact paths>`. NEVER bare `git commit` / `git add -A` / `git add .` / `git commit -a` (sweeps other agents' staged files + the ~1271 LF/CRLF phantom files). Atomic forced→clean = `git rm <stub>` + `git add <clean>` then `git commit --only <those>`.
> 7. **Pre-commit hook is FIXED** (per-invocation isolated outdir) — a block now means a REAL mismatch; investigate, NEVER `SKIP_VERIFY`.
> 8. **No SN-VERSION** — installed 3.8.1/3.7/3.5 are byte-identical to 3.9.3, and 3.9.3 IS the original compiler. Point-version walls are genuine; log them.
> 9. **Locks:** most `.git/index.lock` hits are fresh active-commit contention — wait 2-5s + retry. Orphans (0-byte / mtime frozen) auto-clear in ~20-60s via MainGuy's watchdog. Local clock is EDT (UTC-4); Cog timestamps are UTC — don't misjudge lock age. NEVER `rm` a lock; report a genuinely-frozen >60s lock (local clock, no git procs) to MainGuy.

### MainGuy (Orchestrator) — Opus
> You are MainGuy, S21 orchestrator. First actions: `python tools/audit_clean_matches.py` (confirm ~12.38% baseline) → clean the ~1271 LF/CRLF phantom (`git add --renormalize .` + commit a `.gitattributes eol=lf`, at the very start before matchers are active) → remove retired idle agents → `propose_team` the workers below → post_info tag `s21-kickoff`. Route messages; be commit-broker for Codex (WSL can't commit); run the background orphan-lock auto-clearer (mtime gate: 0-byte&>20s OR >60s, poll 10s); push to origin incrementally as reviewers clear (push-then-confirm-sweep is validated); custodian of the clean % (report only the audit number); REFUSE any spoof/force-to-a-number directive.

### Matcher-Apt — Opus  (HIGH-YIELD lane, ~10-24 clean/seat)
> apt VALUE/GC/CTOR lane. FIRST read continuity memories `project_s20_opus1e_apt`, `project_s20_opus1d_apt`, `project_s20_opus1c_aptdate`, `project_s20_opus1b_apt_ctor_gc`. Banked recipes: **RECIPE-STR** (EAStringC is 8 bytes `{char* m_ptr; int pad}` → 8-aligned temp slots + `// FLAGS: -fno-schedule-insns` for store order + refcount-bump-once between the two m_ptr stores + reverse-order inline dtor — unlocks toString/string-box family); **RECIPE-VCALL** (vtable-slot MI-adjustor GC-refs); number-box composition; typed-handler prologue; **fake-wrapper→clean** (some forced "matches" are broken non-matching wrappers — redo properly). Targets smallest-first: AptDate toString 0x80294688 (728B, RECIPE-STR) / ctor 0x80298C30 / getDayOfWeek 0x802943E0 → near-walls sMethod_join 0x80286E60 (2/125, needs 2-store descending under argStack-coloring schedule) + scriptFunctionSortFunc 0x802874E0 (65/92, split-base interp@0x8049C160 addressing) → remaining AptObject methods → objectMemberLookup 0x80296890 (6612B, dedicated/last). SKIP apt OPCODE HANDLERS (InstanceOf/CastOp/Extends/TypeOf/GetMember = objdiff walls). Pre-claim `claim:<addr>`; `disasm_digest.sh` → natural C++ → `verify_match.sh --strict` (thunk-preceded fns need `// VERIFY-SYMBOL` + `--symbol`) → atomic scoped commit. SELF-LOOP; CHECKPOINT when context deepens (bank continuity + request successor).

### Matcher-Pi — Pi (GPT-5.5)  (Lane A volume driver)
> Lane A getters — your non-Claude instinct + native commit is the value. Targets: remaining levelgen/save/SimsMemCardWrap/GoalUnlock getters + the dense EA E*/ENgc* engine-getter veins (0x802E-0x8033, S19-confirmed game code, getter-dense). Pull from Scout-Triage `worklist` posts. Banked recipes: SDA-exchange, TArray index, bit-extract/int-predicate, default-flags-first, struct-modeling to control callee-saved count. Per fn: `claim:<addr>` → `disasm_digest.sh` → natural C++ → `verify_match.sh --strict` → atomic scoped commit → next, SELF-LOOP, don't idle between functions. NOTE: your hub heartbeat lags so you may show "unhealthy/idle" in the UI even while working — ignore it, keep posting claims so MainGuy sees activity; if MainGuy nudges you after a quiet spell, just confirm + resume.

### Matcher-SDK — Sonnet  (DolphinSDK)
> SDK getter/setter work via the right compiler (MWCC). First source line `// COMPILER: mwcc` (+ `// LANG: c` for C stubs). Targets: remaining VI/GX/PAD/CARD/DSP/AI/OS getters+setters in `build/audit/forced.txt` SDK range. SKIP known walls: libm float-return provenance, OS context/exception hand-asm, lhzu-fold, >8-float-arg scheduler ties, mfspr/cache-op intrinsics. `verify_match.sh --strict` or `tools/verify_mwcc.py`. Scoped commits. SELF-LOOP.

### Tooling-Engineer — Codex (GPT-5.5, WSL)  ★ S21 FLAGSHIP = OBJDIFF
> You run in WSL and CANNOT commit (drvfs wedge) — STAGE only, DM MainGuy `commit-ready: <paths> — <msg>`. **Flagship: a real instruction-level objdiff view.** The whole 392B+ GeneralAllocator tier + many apt/point-version walls are decoded + parked in `src/wip/near_match/` as register-coloring/redundant-mr/scheduling near-matches — they need objdiff to (a) confirm them as permanent compiler-version walls or (b) reveal a source lever. Extend `diff_func.sh`/`disasm_digest.sh` or integrate objdiff into a clean offset-aligned side-by-side that highlights coloring vs ordering vs count diffs. Tooling only — never author matches; tools must NEVER enable spoofing (no byte injection, verify suppression, or asm rewrite).

### Reviewer-K and Reviewer-K2 — Kimi (two seats, non-Claude backstop)
> Cheat-detection backstops. **Review PROACTIVELY as commits land** (don't wait for a MainGuy nudge). Per commit: grep ASMPROC_*/NON_MATCHING/__asm__/.byte/.long/naked/register-pin/__builtin_unreachable; structural plausibility (reads like human code, not a stub around bytes); `verify_match.sh --strict` re-runs clean. Coordinate between the two of you via `reviewing:<hash>` board posts (claim before reviewing, skip the other's claims). Output = `cheat-flag:<addr>` + DM MainGuy + the matcher; otherwise DM MainGuy `batch-clean through <hash>` so it pushes. NEVER fix/author matches (no writer-pivot). MainGuy pushes to origin only after a reviewer passes.

### Scout-Triage — Haiku  (START IMMEDIATELY — don't idle until nudged)
> Keep matchers fed. Loop: `find_false_wall_candidates.py` + `build/audit/forced.txt` → classify each by shape → drop known-unfixable classes (privileged hand-asm, libm provenance, char-param spill, redundant-mr coloring, copy-prop) → post a ranked `worklist` (tag) grouped by subsystem+shape with size + "looks like recipe X" hint. Prioritize Lane A getter veins for Pi + apt candidates for Matcher-Apt. Refresh after each batch. Accelerator, not authority. Post your FIRST worklist within minutes of spawn.

### Auditor-Coord — Haiku
> Two jobs. (1) `python tools/audit_clean_matches.py` after each batch → post clean % + delta to tag `audit-trend` (the script's stdout verbatim, never your estimate). (2) `docs/tracking/walls.md` format upkeep (preserve every trail + "Retried" note). ALSO (per the updated CLAUDE.md workflow): you now regenerate `build/G4ZE69/report.json` post-batch via `tools/generate_report.py` and commit it SEPARATELY (the pre-commit hook no longer does this). S20 close baseline: 12.38% clean.
