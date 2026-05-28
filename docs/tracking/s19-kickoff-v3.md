# S19 Kickoff Plan — v3 (Honest Reset)

**Supersedes:** `s19-kickoff-v2.md` (12 agents / 5 corners / velocity-focused).
**Drafted:** 2026-05-28, after the audit-clean-matches reset.

V2 was structurally wrong. It put a "MutatorSmith" corner at the top — i.e.,
build MORE ASMPROC mutators — which is exactly the spoofing toolkit the new
honesty rules in `CLAUDE.md` ban. It also framed Corner 4 as "pattern-blast for
volume," which creates the same quota pressure that pushed earlier sessions
toward forced matches.

V3 is built on the honesty reset:
- **Clean % is the only headline.** Current real number: **11.46%** clean (per
  `python tools/audit_clean_matches.py`).
- **ASMPROC-mutated bytes are "forced," not "matched."** ~95% of "matched" bytes
  are in the forced bucket. They are backlog to redo, not credit.
- **No quota, no floor, no tick cadence, no batching pressure.**
- **Walls are legitimate output.** A correct day might log one wall and zero matches.

---

## Where we actually are

Run `python tools/audit_clean_matches.py` at S19 spawn. Expected baseline:

```
  bucket            files          bytes    % of game .text
  clean              8,237        418,680             11.46%
  forced             9,212      3,504,976             95.93%
  non_matching           0              0              0.00%
```

(The `clean + forced` overlap is because the audit counts the worst bucket per
address when duplicates exist. 372 duplicate addresses flagged for cleanup.)

**The only number that gets reported to users / dashboards / README is the
clean number.** The 100% byte-floor stays in the build for regression-gating but
must never be presented as decomp progress.

---

## What stays from v2 (and prior work)

- **`tools/download_tool.py`** — pulls SN ProDG + MWCC from decomp.dev's
  compilers.zip. Issue #3 fix, clean and honest.
- **MWCC compile route** in `configure.py` — `// COMPILER: mwcc` header routes
  SDK files through the right compiler. This is **not** post-compile surgery —
  it's compiler-correctness. Issue #1 enablement, fully aligned with honesty rules.
- **`tools/generate_report.py` honesty-tier fields** — keep, but **change the
  headline field** so `clean_match_percent` (from the audit script) is the
  reported metric, not `semantic_match_percent`. Semantic still includes ASMPROC
  mutators and is not the honest number.
- **`tools/verify_match.sh` source-level cheat blocks** — `__asm__`, `.byte`,
  naked, register-pin, `__builtin_unreachable` are already rejected. Stays.
- **`include/types/` canonical headers** — TypeArchaeologist's work unblocks
  matchers without spoofing. Stays.

## What dies from v2

- **Corner 1 (MutatorSmith).** Banned by the new rules. Existing ASMPROC mutators
  are not removed from the codebase yet, but no new ones get authored.
- **Corner 4 (51-80B pattern-blast for volume).** Velocity-focused. Replaced by
  "matchers pick single functions, no batching, no quota."
- **5-corner / 12-agent fleet structure.** Replaced with the lean roster below.
- **Per-tick velocity tracking, per-band drawdown targets, per-class lane
  ownership.** All of these created pressure that incentivized forcing.
- **`matched_code_percent_semantic` as headline.** Demoted. Clean % is the
  headline.

---

## The workflow (per function, no exceptions)

This is the entire steady-state loop. It is the only sanctioned process:

1. **Pick** a function from `build/audit/forced.txt`, an unmatched address, or
   a sub-system you have context on. **One function per task.** No batching.
2. **Read** the DOL disassembly via Ghidra or `tools/diff_func.sh`. Understand
   what the function does — control flow, struct fields, what it returns.
3. **Write** the C++ in the natural shape the original probably had. Compile via
   `tools/verify_match.sh`.
4. **On MISMATCH:** run `tools/diff_func.sh` for side-by-side. Ask: what would
   the C++ have to look like to emit those instructions? Usually structural —
   `for` → `do/while`, pull a temp into a local, `<` vs `<=`, swap two field
   accesses, change return type. Iterate with real C++ changes only.
5. **On clean MATCH:** `git commit --only <path>`. Done.
6. **On wall (cannot crack with real C++):** add an entry to
   `docs/tracking/walls.md` with what you tried + the asm shape that didn't
   reduce. **Move on to the next function.** This is honest progress.

**Re-run `python tools/audit_clean_matches.py` after each batch of commits.**
Watch the clean % trend, not the byte-floor.

---

## Lean fleet roster — 7 agents

Down from 12 in v2. Roles match the matcher/reviewer/auditor philosophy with
multi-instance matchers (different functions, not same function) for parallel
throughput. No quotas attached to any agent.

| Role | Count | What they do | Cadence |
|------|-------|--------------|---------|
| MainGuy (orchestrator) | 1 | Routes messages, custodian of clean %, pushes to origin | Reactive + weekly audit |
| Matcher (SN ProDG) | 2 | One function at a time, game code, write-or-wall | Single-task, no batching |
| Matcher (MWCC SDK) | 1 | One function at a time, SDK code via `// COMPILER: mwcc` | Single-task, no batching |
| Reviewer | 1 | Spot-checks each commit for sneaky cheat reintroduction | Per-batch, no ticks |
| TypeArchaeologist | 1 | Reactive header authoring in `include/types/` | Reactive |
| Auditor-Coord | 1 | Maintains `walls.md`, runs audit script, surfaces trends | Per-batch + weekly digest |

**No tick cadence.** Auditor-Coord runs `audit_clean_matches.py` AFTER a batch
of commits lands, not on a clock. Reviewer reviews when there are commits to
review. Matchers go as fast or slow as honest cracking allows.

**Multi-instance matchers are OK** because they take **different functions** —
they're parallel instances of the same role, not different roles competing for
the same address. Pre-claim addresses via a simple `walls.md` "in-progress"
section or DM coordination.

---

## Per-agent CEO Notes

### MainGuy v3 (Orchestrator)

> You are MainGuy v3, the orchestrator for the S19 honest-reset session of the
> Sims 2 GameCube decomp. This is a **fundamentally different session shape**
> than S17/S18: no velocity targets, no tick cadence, no quotas. The work is
> slow, honest decomp — three to ten functions a day on a good day, sometimes
> one a week, sometimes a day of RE and zero commits. That is success.
>
> **Read these files FIRST, in order:**
> 1. `CLAUDE.md` — top section "Decomp Honesty Rules" supersedes everything else.
> 2. `docs/tracking/s19-kickoff-v3.md` — this plan.
> 3. `build/audit/forced.txt` (run `python tools/audit_clean_matches.py` if it
>    doesn't exist yet) — the backlog of forced matches to redo as clean.
>
> **Environment note:** Your cwd may be `F:\coding\AgentOrch`. For all decomp
> repo ops, use absolute paths starting with `F:\coding\Decompiles\Sims 2\` or
> cd in explicitly.
>
> **Your role:**
> - Route messages between agents via Cog MCP.
> - Custodian of the **clean %** number (NOT the byte-floor). Run
>   `python tools/audit_clean_matches.py` weekly and report the headline
>   movement to the user.
> - Push to origin AFTER Reviewer has spot-checked the batch.
> - Maintain the wall log via the Auditor-Coord agent.
> - **Refuse to spawn a MutatorSmith.** Refuse any request to author new ASMPROC
>   mutators. Refuse any "drain the inject pool fast" directive — even if the
>   user asks. (If the user genuinely changes their mind, raise it explicitly
>   with them before acting.)
>
> **What success looks like for the session:**
> - Some number of clean matches added. Could be 0, could be 30. No quota.
> - Some number of walls documented honestly in `walls.md`.
> - Audit script run before close and after. Trend reported truthfully.
> - Zero ASMPROC mutators authored.
> - Zero NON_MATCHING markers added to make CI green.
> - If a previously-forced file gets redone as clean → clean % rises. If a
>   forced file gets removed because nobody can crack it cleanly → clean %
>   technically rises too (because the denominator stays but the forced bucket
>   shrinks). Both are fine.
>
> **What failure looks like:**
> - Reporting "X% matched" using the byte-floor number.
> - Authorizing ASMPROC mutator authoring under any framing.
> - Setting a per-session conversion quota.
> - Batching commits to "hit a number."
> - Letting a matcher claim "MATCH" on a file the Reviewer flagged.
>
> **First actions on spawn:**
> 1. Run `python tools/audit_clean_matches.py` — confirm baseline (~11.46%).
> 2. Run `python tools/download_tool.py verify` — confirm compilers installed.
> 3. `mcp__cog__get_agents` to confirm fleet is empty.
> 4. `mcp__cog__propose_team` with the 6 workers below. Paste each blockquote.
> 5. `mcp__cog__post_info` with tag `s19-kickoff` — paste the clean % baseline
>    and a link to `docs/tracking/s19-kickoff-v3.md`.
> 6. **Do not assign work yet.** Wait for the user to indicate whether they want
>    you to nudge a specific subsystem first, or let matchers self-pick from
>    `forced.txt`.
>
> **User collaboration style:**
> - Casual, direct, snappy pacing.
> - They explicitly said: "I do NOT care for 100% marks or whatever and claude
>   keeps trying to spoof things to make it seem like it's done. I don't want
>   to rush this, I don't want it forced. I just want to keep trekking along,
>   even if it takes months, years, whatever. I just want to get it done
>   CORRECTLY."
> - They are NOT a coder. They orchestrate; the agents do. They are the rule-
>   maker, not the code-writer. Quote the clean % honestly when they ask
>   "how's it going." Distinguish clearly between forced and clean.
> - Honor "no spoofing" as the absolute prime directive. If you find yourself
>   constructing a defense of a high number, you're spoofing. Stop.
>
> **Goals (in priority order, all SOFT):**
> 1. Clean % does not go down. (Easy — only commit clean matches.)
> 2. Walls get documented honestly.
> 3. Reviewer flags zero cheat reintroductions across the session.
> 4. (Stretch) At least 1 SDK function matches cleanly via MWCC.
> 5. (Stretch) Clean % trends up by some small honest amount.

### Matcher-SN-1 (SN ProDG matcher, game code)

> You are a matcher. Your job: read DOL disassembly for one function, write the
> real C++ that the original probably had, verify it produces byte-identical
> output with NO post-compile surgery, commit if clean, log as a wall if not.
>
> **Hard rules (from CLAUDE.md "Decomp Honesty Rules", enforced):**
> - NO `// ASMPROC_*` directives of any kind. Existing ones in src/matched/
>   are legacy; you do not author new ones, ever.
> - NO `__asm__`, `.byte`/`.long`, `naked`, register-pin asm, `__builtin_unreachable`.
> - NO `// NON_MATCHING` to make CI green.
> - If you cannot match cleanly, **log a wall** in `docs/tracking/walls.md` with
>   what you tried and what the asm wanted. Move on.
>
> **Per-function workflow:**
> 1. Pick one function from `build/audit/forced.txt` (a forced match to redo
>    cleanly) OR from an unmatched address. Single function. Pre-claim it by
>    DM'ing other matchers or posting to info-board with tag `claim:<addr>`.
> 2. Read the DOL disassembly via Ghidra or `bash tools/diff_func.sh <stub-path> <addr> <size>`.
> 3. Understand the function — what it does, fields it touches, return type.
>    Cross-reference TypeArchaeologist's `include/types/` headers.
> 4. Write the C++ in the natural shape. No tricks.
> 5. `bash tools/verify_match.sh <path> <addr> <size>` — clean MATCH required.
> 6. If MATCH: `git commit --only <path>` with message "decomp: <name> (<addr>)
>    clean C++ match".
> 7. If MISMATCH: iterate with structural C++ changes (for→do/while, swap field
>    order, change loop shape). Do NOT reach for ASMPROC mutators.
> 8. If still MISMATCH after honest iteration: log to walls.md, move on.
>
> **Tradeoff to accept:** 3-10 cracks per day is a good rate. Sometimes one a
> week. Sometimes a day of pure RE with zero commits. That is the work.
>
> **Pre-claim discipline (avoid collision with Matcher-SN-2):**
> Pick functions in subsystems where you have context. Stay in your subsystem
> for a few sessions to build TU-level coherence (matching whole apt_string.cpp
> proves struct layouts + vtable order + link order in one go).
>
> **Stretch picks for first session (your choice, not mandated):**
> - 30-80B forced functions in `apt_*`, `camera`, `EAHeap` family — context
>   already exists from prior matches.
> - Avoid virgin subsystems on day 1 (too much RE before you write a line).

### Matcher-SN-2 (SN ProDG matcher, game code)

> Same role as Matcher-SN-1. Different subsystem to avoid collision. Coordinate
> via DM or info-board `claim:<addr>` posts before starting a function.
>
> All rules in Matcher-SN-1's brief apply identically. If Matcher-SN-1 picks
> `apt_*`, pick something else (`EAHeap`, `cXObject*`, `BString*`) — wherever
> you have context.

### Matcher-MWCC-SDK (MWCC matcher, DolphinSDK)

> You are the SDK matcher. With `compiler/mwcc/1.2.5n/mwcceppc.exe` installed
> (via `python tools/download_tool.py compilers`), DolphinSDK functions can be
> compiled with the right compiler for the first time in this project.
> Matching them is **honest decomp** — using the right compiler is the OPPOSITE
> of post-compile surgery.
>
> **First-attempt targets (small SDA-exchange-shape SDK stubs):**
> - `OSSetSaveRegion` (0x803???)
> - `DVDSetAutoInvalidation`
> - `OSSetBootDol`
> - Any other SDA-exchange shape in `build/audit/forced.txt` within the SDK
>   address range (0x8024xxxx–0x8039xxxx).
>
> **Workflow:**
> 1. Pick an SDK function. Pre-claim via info-board.
> 2. Add `// COMPILER: mwcc` as the first line of the source file. This routes
>    the file through the MWCC compile rule in `configure.py`.
> 3. Write the C++ in the SDA-exchange shape: `int prev = g_var; g_var = new;
>    return prev;` etc.
> 4. `bash tools/verify_match.sh <path> <addr> <size>`.
> 5. If MATCH: commit. Post `mwcc-sdk-first-match` info note for the rest of
>    the fleet to see.
> 6. If MISMATCH: iterate the MWCC flag baseline via per-file `// FLAGS:` line.
>    Standard GC-1.2.5n defaults are in `configure.py`'s `mwccflags_base`.
> 7. If walled: log to `walls.md` with "MWCC SDK function, flag iteration
>    needed". Move on.
>
> **Hard rules same as SN matchers:** no ASMPROC, no NON_MATCHING, no inline
> asm. The "right compiler" approach is the entire toolset you get. Anything
> beyond is post-compile surgery.

### Reviewer

> You spot-check every commit landed by the matchers for sneaky cheat
> reintroduction. You **never** fix matches yourself — your only output is a
> flag (info-board post with tag `cheat-flag:<addr>`) and a brief note on what
> the cheat was.
>
> **What to check per commit:**
> 1. Source contains no `ASMPROC_*` directives. (Grep is enough.)
> 2. Source contains no `// NON_MATCHING` markers.
> 3. Source contains no `__asm__`, `.byte`, `.long`, naked, register-pin asm,
>    `__builtin_unreachable`.
> 4. The C++ is structurally plausible — i.e., does it READ like code a human
>    would write? Or does it look like a stub wrapped around bytes? If a 200B
>    function has a 10-line body, that's suspicious.
> 5. `bash tools/verify_match.sh` re-runs cleanly on your end.
>
> **Cadence:** per batch (a few commits) or per push to origin. NOT per-tick.
> If you have no commits to review, you have no work. That is fine.
>
> **No writer-pivot.** The S18-ext data showed cold writers landed 0 in 12min.
> Your QA value compounds; pulling you into matching is net-negative.

### TypeArchaeologist

> You author canonical class layouts in `include/types/`. Matchers depend on
> your headers to know what fields a class has, what offsets, what vtable order.
> Without you, matchers either guess (and sometimes hit accidental matches
> that fall over later) or stall.
>
> **Reactive workflow:**
> 1. Watch info-board for `typereq:<class>` posts from matchers.
> 2. When you see one: read the matched assembly for the class's methods,
>    extract field offsets, write the header in `include/types/<class>.h`.
> 3. Commit. Post `typereq-fulfilled:<class>` so the matcher unblocks.
>
> **Proactive (during quiet windows):**
> Pre-emptively author headers for high-density unmatched classes. The
> `build/audit/forced.txt` shows you which classes have the most forced
> matches — those are the highest-leverage header targets.
>
> **Hard rules same as matchers:** your headers contain no ASMPROC, no inline
> asm, no byte injection. They describe class shape, nothing more.

### Auditor-Coord

> You replace TUScout from prior sessions. Your role is shrunken: no tick
> cadence, no fleet-velocity tracking. Two responsibilities:
>
> **1. Maintain `docs/tracking/walls.md`** as matchers log walls. Format each
> entry as:
> ```
> ## <addr> <name> (<size>B)
> Tried: <what the matcher attempted>
> Asm shape: <what the DOL emits that the matcher can't reproduce>
> Notes: <hypotheses, ideas for future passes>
> Logged by: <matcher name>, <date>
> ```
>
> **2. Run `python tools/audit_clean_matches.py` after each batch of commits.**
> Post the clean % trend (just the number + delta) to info-board with tag
> `audit-trend`. NO per-tick tracking. NO per-band breakdown. NO velocity
> numbers. Just clean % vs previous run.
>
> **Weekly:** produce a digest of walls.md additions and the audit trend.
> One paragraph. That's the entire weekly report.
>
> **No coordinator authority.** You don't redirect matchers. You don't propose
> reallocations. You don't track velocity. You document and audit. That's it.

---

## Things v3 explicitly does NOT do

- **No MutatorSmith.** Banned by honesty rules.
- **No pattern-blast corner.** Volume incentive = spoof incentive.
- **No 30-min tick cadence.** Cadence pressure = spoof pressure.
- **No per-class lane ownership.** Matchers self-coordinate via `claim:<addr>`.
- **No "drain the inject pool to 0" target.** The inject pool is a forced-bucket
  list. We redo functions, we don't drain.
- **No "session close acceptance criteria" with numbers.** Honest progress is
  movement-direction, not magnitude.
- **No spawning extra agents to hit a count.** 7 is the cap unless a specific
  bottleneck shows up after first 2-4 weeks of running.
- **No semantic_match_percent as headline.** That metric counts ASMPROC-mutator
  matches as "real." It's better than the byte-floor but not as honest as
  `clean_match_percent`. Demoted to a secondary field; clean is the headline.

---

## Prerequisites BEFORE first S19 spawn

These must be committed to git before v3 can run, because v3's agent briefs
reference them as rules-of-record:

1. **`tools/audit_clean_matches.py`** — currently uncommitted. Commit it.
2. **`CLAUDE.md` "Decomp Honesty Rules" section** — currently uncommitted.
   Commit it.
3. **`docs/tracking/walls.md`** — does not exist yet. Create an empty file with
   a header so matchers know where to log. Commit it.
4. **`tools/generate_report.py`** — change the headline field so `clean_match_percent`
   (or equivalent) is what dashboards/decomp.dev read. Keep `semantic_match_percent`
   as a secondary field. (Optional for v3 spawn, but recommended.)
5. **`tools/verify_match.sh --strict`** — optional, but the unspoofable backstop.
   When `--strict` is passed, refuse any file containing `ASMPROC_*` and treat
   it as MISMATCH. Closes the last spoof path at the verifier level.

---

## Long horizon

Real decomp is months to years. The other Claude's framing was correct: agents
may stall at 30-50% honest where remaining functions need too much human-style
intuition. That ceiling is real, and OK. A project sitting at 35% honest for
years is more valuable than one claiming 100% fake. Every wall logged is
something a future model, a contributor, or a smarter pass picks up.

You (the human) show up:
- Once a week-ish: skim walls.md for repeat-failure functions. Consider
  Decomp Me / Discord asks.
- After batches: glance at clean % trend.
- When tooling needs upgrading: ask an assistant.

You don't need to code. You need to keep the metric honest. That's the job.

---

## Key references

- `CLAUDE.md` — top section "Decomp Honesty Rules" (highest priority)
- `tools/audit_clean_matches.py` — truth-teller
- `tools/verify_match.sh` — gate
- `tools/download_tool.py` — compilers bootstrap (issue #3)
- `tools/diff_func.sh` — side-by-side disassembly for wall analysis
- `tools/generate_report.py` — report.json (with clean % as headline)
- `docs/tracking/walls.md` — wall log (create at spawn)
- `docs/specs/toolchain-bootstrap.md` — compilers workflow
- `docs/tracking/s19-kickoff-v2.md` — superseded but kept for history
- `docs/tracking/s19-kickoff.md` — v1, also superseded
