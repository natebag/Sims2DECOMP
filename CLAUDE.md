# Sims 2 GameCube Decompilation — Project Rules

Project-specific rules for the Sims 2 GC matching decomp. Universal rules are in `~/.claude/CLAUDE.md`.

## Decomp Honesty Rules (HIGHEST PRIORITY — supersedes anything below)

These rules exist because earlier metrics rewarded spoofing — "matched_code_percent
must never drop below 100%" combined with permissive asm-processor routing produced
agent behavior that wrapped raw bytes and called it decomp. That stops here.

### What "matched" means

A function counts as **matched** only if ALL of the following are true:

1. The source in `src/matched/...` is **hand-written C++** describing what the function
   actually does — not a wrapper around the original bytes.
2. Compiling that C++ with SN ProDG (or the documented fallback) produces bytes that
   are byte-identical to the DOL at that address, **with relocations masked and local
   branches resolved, but with NO post-compile mutation**.
3. The source contains **no** ASMPROC directives, NON_MATCHING markers, `__asm__`,
   `.byte`/`.long` injection, naked attributes, register-pin asm, `__builtin_unreachable`,
   or `noreturn`-to-suppress-body tricks.

Anything else is NOT matched. It may be useful working state (`forced`, `non_matching`,
`pending`, `wip`), but it does not get to claim the word "matched."

### Banned for new work

Do not produce, expand, or "fix" matches using any of these:

- `// ASMPROC_*` directives (`inject_before`, `replace_insn`, `swap_adj`,
  `gpr_relabel`, `force_reg_at_pos`, and any future variants).
  These are post-compile asm surgery. They make the binary match because tooling
  rewrites the compiler output, not because the C++ describes the function.
- `__attribute__((naked))`, `__attribute__((noreturn))` paired with `__builtin_unreachable`,
  `__builtin_unreachable` at function scope.
- `__asm__` / inline assembly, `.byte`, `.long`, raw-byte arrays standing in for code.
- `register T name asm("rN")` register-pin cheats.
- Adding `// NON_MATCHING` to a near-match to make CI green. NON_MATCHING is for
  *documenting* a function you understand but can't yet land — not a release valve.

A function you cannot match cleanly is **left for later**, not forced. Log it as a
wall in `docs/tracking/walls.md` with what you tried, and move on to the next one.

### The number goes UP from zero

The headline progress number is **clean bytes / game .text bytes**, produced by
`python tools/audit_clean_matches.py`. It starts low. It rises slowly. It is
allowed to *fall* if previously-forced files are reclassified or removed.

- There is **no floor** on the clean percentage. Do not try to "protect" or "defend" it.
- There is **no quota** — not per session, not per day, not ever. Honest matches
  beat fast ones.
- "matched_code_percent must never drop below X" — **deleted**. Any rule, prompt,
  scoreboard, or agent instruction that pins the percentage is a spoofing incentive
  and should be removed when found.
- A correct day might land zero new matches and just document one wall. That is
  progress.

### Steady-state loop

The only sanctioned workflow is:

1. Pick a function from `build/audit/forced.txt`, `non_matching.txt`, or the
   unmatched backlog.
2. Read the DOL disassembly. Understand what the function does.
3. Write real C++ that expresses that behavior.
4. Run `tools/verify_match.sh` (or the `--strict` future-mode equivalent).
   - Clean MATCH → commit.
   - MISMATCH and you can fix it with real C++ changes → iterate.
   - MISMATCH and you cannot crack it without forcing → log the wall, move on.
5. Re-run `python tools/audit_clean_matches.py` periodically to see the honest
   number trend. Trend > headline.

### Three numbers, not one

Public/internal reporting must always distinguish:

- **Linked / built %** — bytes covered by the build (incl. byte-injection stubs).
  Currently ~100%. This proves the scaffold is correct. It is **not** decomp progress.
- **Clean matched %** — the audit script's clean bucket. The honest decomp metric.
- **Forced %** — ASMPROC + NON_MATCHING bytes. Backlog to redo, not credit.

If a single number is reported anywhere, it is the clean one, and it is labeled
"clean decomp."

### Reviewer-facing wording

When the agent reports progress in a commit message, PR description, dashboard, or
chat reply: do not say "100% matched", "X% complete", or otherwise round the linked
number up into the matched number. Report the clean percentage explicitly. Reporting
the linked figure as if it were the matched figure is the exact spoof these rules
exist to prevent.

## Agent Delegation

Use these agents proactively — don't wait to be asked:

| Trigger | Agent | Why |
|---------|-------|-----|
| New function to decompile | `decomp-planner` | Analyzes symbol in map file, checks Ghidra disassembly, identifies dependencies, produces decomp plan |
| PPC compilation errors | `cpp-build-resolver` | Fixes SN Systems / devkitPPC compiler issues, linker errors, missing symbols |
| After writing C++ code | `cpp-reviewer` | Checks matching conventions, naming from map file, verifies no UB |
| Exploring unknown code in Ghidra | `ghidra-analyst` | Deep-dives disassembly, identifies patterns, documents structs |
| Asset format RE | `format-analyst` | Reverse engineers .arc, .NGH, .tpl file formats |

Spawn multiple agents in parallel when a task has independent parts.

## Build Roadmap

Use `/work` to pick up the next task. Full design doc: `docs/specs/sims2-gc-decomp-design.md`

### Prioritization Principles
1. **Foundation before features** — build toolchain and boot first, gameplay systems after
2. **Matching over speed** — every function must byte-match the original DOL
3. **Document as you go** — every decompiled system gets a doc in `docs/systems/`
4. **Symbols are gospel** — use the map file names exactly, don't rename
5. **One system fully matched beats three half-done**
6. **Community-ready** — structure the repo so contributors can pick up any function

### Lane Rules
- Pick **one lane** within the current milestone
- Higher priority lanes should be staffed first
- Work tasks top to bottom within a lane
- **"Not Yet" items must not be worked on**
- New discoveries: current milestone? Add it. Future milestone? Slot it. Neither? Icebox.

### Milestone 1: INFRASTRUCTURE — DONE

**Goal:** Build toolchain that produces a DOL. Symbols imported. Build pipeline working.

**What this actually means:** The build system uses `decomp-toolkit` to inject original
bytes from the DOL into the linked ELF. The DOL "matches" because the bytes are copied,
NOT because C++ was written that compiles to matching output. This is the standard
starting point for a decomp project — not the finish line.

**Gate Criteria:**
- [x] devkitPPC toolchain builds a valid GC DOL
- [x] decomp-toolkit project config working
- [x] Symbol map parser extracts 39,169 symbols
- [x] Skeleton generator + byte injection pipeline
- [x] Build system produces DOL (via byte injection, NOT real decomp)
- [x] Compiler flags tuned (47% byte-exact match rate on simple functions)
- [x] CI pipeline for build verification

### Milestone 2: SCAFFOLDING — DONE

**Goal:** Create empty C++ source files for every class/function so the project compiles
on x86. These are empty shells — the function bodies do nothing.

**What this actually means:** 1,214 files with empty function bodies were created.
They compile on x86 but contain NO game logic. The "portable C++" is a scaffold
for future decomp work, not completed decomp work.

**Gate Criteria:**
- [x] 1,214 source files with empty function bodies
- [x] 643 class struct layouts documented from assembly analysis
- [x] Files compile on x86 (empty bodies)
- [x] Pseudocode comments describing what functions should do

### Milestone 3: ACTUAL DECOMP — IN PROGRESS (the real work starts here)

**Goal:** Hand-write C++ for every function that compiles to byte-identical PPC output.
This is the core decomp work. We are at the very beginning.

**Current Status (2026-05-12 — post Session 15 close):**
- **11.50% of game code is byte-matched** — 420,292 / 3,653,648 bytes of compiled output
  byte-identical to the original DOL (excluding the unmatchable Metrowerks-compiled
  DolphinSDK). This is the industry-standard decomp metric and what decomp.dev publishes.
- **14.78% overall .text byte-match** (612,636 / 4,145,724 bytes including SDK region).
- **8,887 / 16,890 matchable game functions** byte-matched (52.62% by function count).
- **10,215 total match files committed** (10,215 > 8,887 because some matches cover
  templates that land in SDK-adjacent address space, plus a handful of size-0 label
  matches inside larger functions).
- The byte-vs-function gap is real: thousands of small functions were cracked first
  (trivial 4-20B getters/setters, template instantiations, leaf calls). Average matched
  function ~68B; average .text function ~224B. Large structural functions remain.
- Session 15 delta: +72 net matches.
- Session 3 delta: +430 unique matches (7,820 → 8,250). 953 duplicate aliases
  consolidated, 1,209 stale files cleaned, 40% milestone crossed.
- Session 2 delta: +541 matches. Matcher bot built, integrity audit purged 215 fakes.
- Full exhaustive audit completed: every file in src/matched/ compile-verified
- ALL asm_decomp functions matched — remaining work is DOL-only extraction
- SN Systems ProDG compiler confirmed correct (all 4 versions produce identical code)
- 5-state flag matrix per function: {default, -fno-schedule-insns, -fno-schedule-insns2, both, -fno-elide-constructors-only}
- Per-file override: `// FLAGS: -fno-schedule-insns` (or any combo) as first line
- Pre-commit hook auto-verifies matches, auto-moves VERSION_DIFF to src/wip/version_diff/
- Auto-matcher v4 (tools/goldmine_matcher.py): 16 classifiers, 4-flag matrix, DOL scan
- Template family detector: 136+ families with 1,040+ functions
- **BLRL BREAKTHROUGH (2026-04-06):** Virtual dispatch (blrl/bctrl) solved — declare C++ classes with virtual methods in vtable order, compiler generates correct blrl natively
- **SDA EXTERN BREAKTHROUGH (2026-04-12):** `extern char globalName[]` generates correct lis/addi relocations for SDA globals, unlocking 500+ previously-walled functions
- **SCHEDULER INSIGHT (2026-04-12):** Default GCC scheduling REPRODUCES SN ordering for complex functions (>100B). `-fno-schedule-insns` should only be added if default makes things worse.
- TU compilation workflow proven: tu_match.py --combine for TU-level matching
- SDK exclusion zone: DolphinSDK functions at 0x8024-0x8039 are Metrowerks-compiled, cannot byte-match
- Key techniques: SDA `extern char g[]`, sign bit `>>31`, equality subfic+adde, xori flip, virtual class declarations for blrl, `short` types for extsh, magic division constants, bitfield structs for rlwimi, unsigned <=N subfic/adde idiom, load-before-store via local variables

**IMPORTANT: The DOL "matches" via byte injection. Real decomp progress is measured by
how many functions have hand-written C++ that compiles to matching bytes WITHOUT injection.**

**Gate Criteria (byte-level — the real decomp metric):**
- [x] 5% game-code bytes-matched (~183,000 bytes)
- [x] 10% game-code bytes-matched (~365,000 bytes)
- [ ] 15% game-code bytes-matched (~548,000 bytes)
- [ ] 25% game-code bytes-matched (~913,000 bytes)
- [ ] 50% game-code bytes-matched (~1,827,000 bytes) — "halfway in real terms"
- [ ] 75% game-code bytes-matched (~2,740,000 bytes)
- [ ] 100% game-code bytes-matched (~3,653,648 bytes) — TRUE 100% decomp

**Secondary tracking (function-count, kept for fleet dispatch but NOT the headline metric):**
- [x] 1,000 functions hand-matched
- [x] 5,000 functions hand-matched
- [x] 10,000 functions hand-matched (crossed S14)
- [ ] 15,000 functions hand-matched
- [ ] 16,890 functions hand-matched — 100% of matchable game functions

**Approach:** Agent-parallelized matching — see strategy below.

**Priority Order (updated 2026-04-06):**
1. ~~All asm_decomp functions~~ — DONE (100% matched)
2. Template family blast — 136 families, 1,040 functions, ~100% hit rate (HIGHEST PRIORITY)
3. TArray template methods — Init done, Deallocate/Construct/Copy need cracking
4. Auto-matcher classifier expansion — andi., rlwinm, lbz/stb, loop patterns
5. 65-128B DOL scan — 3,578 unmatched, need template family grouping
6. VERSION_DIFF recovery — ~948 files in wip/version_diff/, most are instruction scheduling diffs
7. 128-512B functions — confirmed hard, needs TU compilation or deep RE

### Milestone 4: PC PORT — NOT STARTED (requires Milestone 3)

**Goal:** Once functions have real logic (not empty stubs), build a PC port.

**Current Prototype:** An OpenGL tech demo exists in `src/platform/pc/` that loads
game textures and renders a custom menu. This is NOT a real port — the game code
doesn't run because all function bodies are empty. A real PC port requires actual
decompiled game logic.

### Icebox (Future — requires completed decomp)
PC port, mod system, online multiplayer, widescreen, Steam Workshop

## Build Info (from disc)

- **Game:** The Sims 2 (GameCube) — Game ID: `G4ZE69`
- **Build date:** September 12, 2005
- **Build version:** `F.09.12.0` (Final / Gold Master)
- **Build machine:** `CM3-BUILD25` by `codebuilder`
- **Compiler:** SN Systems ProDG for GameCube (SN-NGC)
- **SDK:** DolphinSDK 1.0 HW2
- **Source tree root:** `c:\BuildAgent\cm3-build25-NGC\CMBuild\`
- **Cross-platform:** Shared codebase with PS2, Xbox, and Windows builds

## Key Files on Disc

| File | What It Is |
|------|-----------|
| `sys/main.dol` | Main executable (4.4MB) — the target to match |
| `files/u2_ngc_release_dvd.elf` | ELF with debug symbols (4.4MB) |
| `files/u2_ngc_release.map` | Release symbol map — 39,169 named symbols |
| `files/u2_ngc_debug.map` | Debug symbol map — even more detail |
| `files/version.h` | C header with build version info |
| `files/DATA/*.arc` | Game asset archives (~1.2GB total) |
| `files/*.NGH` | Unknown format — needs RE |
| `files/eorwb.log` | Full 8.8MB build log |

## Decomp Conventions

### Matching Rules
- Every decompiled function MUST produce byte-identical output to the original DOL
- Use `decomp-toolkit` to verify matching (`dtk elf diff`)
- Non-matching code gets a `// NON_MATCHING` comment with explanation
- Use the **exact** symbol names from the map file — no renaming

### C++ Style
- Follow the original EA code style visible in the map symbols
- Class names: PascalCase (`ESim`, `ESimsCam`, `cXObject`)
- Member variables: `m_` prefix (`m_degRotAngDef`, `m_vEyeDef`)
- Constants: `k` prefix (`kNumTemp`, `kMaxWallShaders`)
- Static members: `s_` prefix (`s_fullAlphaValue`, `s_ambientDatabase`)
- Namespaces: match original (`BBI`, `Effects`, `InteractorModule`)

### File Organization
- One `.cpp` + `.h` pair per class/module (matching original source file names from map)
- `src/` mirrors the original source tree structure where known
- `include/` for shared headers
- `libs/` for external library stubs (APT, DolphinSDK, SN runtime)

### Documentation
- Every decompiled system gets a doc in `docs/systems/`
- Document struct layouts, vtable orders, and function purposes
- Note any unknowns or assumptions with `// TODO:` comments

## Project Structure

```
Sims 2/
├── CLAUDE.md                    # This file
├── config/
│   └── sims2_gc.yml             # decomp-toolkit project config
├── src/                         # Decompiled C++ source
│   ├── boot/                    # __start, crt0, __init_hardware
│   ├── core/                    # EAHeap, FastAllocPool, memory mgmt
│   ├── sim/                     # ESim, CAS, sim AI
│   ├── objects/                 # cXObject, ISimsMultiTileObjectModel
│   ├── render/                  # ENgcRenderer, FrameEffects, shaders
│   ├── camera/                  # ESimsCam
│   ├── build_mode/              # InteractorModule, WallManipulator
│   ├── ui/                      # APT system (ActionScript UI engine)
│   ├── audio/                   # AmbientScorePlayer, sound system
│   ├── inventory/               # BBI::InventoryItems
│   ├── goals/                   # GoalUnlock
│   ├── save/                    # SimsMemCardWrap
│   ├── skin/                    # SkinCompositor
│   ├── effects/                 # FrameEffects, bloom, motion blur, DOF
│   ├── animation/               # Animation event handlers
│   └── levelgen/                # Level/map loading
├── include/                     # Shared headers
├── libs/                        # External library stubs
│   ├── apt/                     # APT UI library
│   ├── dolphinsdk/              # DolphinSDK 1.0 HW2
│   └── sn_runtime/              # SN Systems runtime (crt0, etc.)
├── tools/                       # Python analysis & build scripts
│   ├── map_parser.py            # Parse .map → structured symbol data
│   ├── symbol_importer.py       # Import symbols into Ghidra
│   ├── generate_report.py       # Generate dtk-template progress report.json
│   ├── paths.py                 # Canonical path constants (DOL_PATH, MAP_PATH, etc.)
│   └── progress.py              # Track decomp % matched (legacy file-count metric)
├── configure.py                 # dtk-template entry point (stub: produces report.json)
├── docs/
│   ├── specs/                   # Design specs
│   ├── systems/                 # Per-system documentation
│   ├── file-formats/            # .arc, .NGH, .tpl format docs
│   └── tracking/
│       ├── next-steps.md        # Detailed task queue
│       └── progress.md          # Decomp progress tracking
├── extracted/                   # Raw disc extraction (legacy path; still used by existing tools)
│   ├── sys/main.dol             # Target binary
│   └── files/                   # Game assets + debug files
├── orig/G4ZE69/                 # dtk-template-aware path (Windows junctions back to extracted/)
│   ├── sys/                     # → extracted/sys
│   └── files/                   # → extracted/files
├── config/                      # Legacy config (used by existing tools)
├── config/G4ZE69/               # dtk-template-aware config mirror (config.yml = renamed sims2_gc.yml)
└── build/G4ZE69/                # Build output — report.json committed, other artifacts ignored
    └── report.json              # Progress data for decomp.dev (regenerate after match commits)
```

## Progress Tracking Workflow

**Automatic (the normal case):** The pre-commit hook regenerates
`build/G4ZE69/report.json` automatically whenever a commit touches files in
`src/matched/`. The fresh report.json is added to the same commit. Workers do
nothing extra — the report just stays in sync.

**Manual (if needed):** If the hook is bypassed (`SKIP_VERIFY=1`), missing
(`bash tools/install-hooks.sh` after fresh clone), or the report drifted some
other way, regenerate manually:

```bash
python tools/generate_report.py
git add build/G4ZE69/report.json
git commit -m "report: refresh"
```

## Ninja Build — `configure.py` + `build.ninja`

The project supports both `make` (legacy) and `ninja` (dtk-template standard).
Both drive the same inject-based pipeline (skeleton + matched byte injection +
link); ninja adds parallelism, incremental rebuilds, and the canonical
`python configure.py && ninja` interface decomp.dev / objdiff users expect.

```bash
pip install ninja              # one-time, if not installed
python configure.py             # regen build.ninja (only when sources move)
ninja                           # default: build/G4ZE69/main.dol
ninja skeleton                  # gen skeleton .s only
ninja compile                   # compile every matched .cpp in parallel
ninja diff                      # full build + `dtk dol diff` vs original
ninja verify                    # full build + sha1sum -c
ninja report                    # regen build/G4ZE69/report.json (no compile)
ninja all                       # verify + report
ninja -t clean                  # clean built files
```

**Scope:** by default only `src/matched/**/*.cpp` compile (10K files, ~3 min on 8 cores).
Use `python configure.py --full` to enumerate the full scaffold tree (20K files,
hours — mostly empty stubs whose .o is discarded by inject_matches.py, only useful
as a "everything builds" sanity check).

**Per-file flag overrides:** `// FLAGS: -fno-schedule-insns` (etc.) at the top of
any matched .cpp is picked up at configure-time and applied as the `extra_flags`
ninja variable for that one rule. Re-run `python configure.py` after adding new
overrides.

**Reconfigure:** `ninja` re-runs `configure.py` automatically when `configure.py`,
`tools/ninja_syntax.py`, or `config/symbols.txt` change.

**Tier:** this is the Tier-1 ninja wrapper around the existing devkitPPC-GCC
compile + dtk-injection pipeline. The Tier-2 work (real per-file SN ProDG
compilation in the link path, replacing injection) is a future infra project.

## Wall Diagnosis — `tools/diff_func.sh`

Side-by-side disassembly diff for a single function. Compiles the C++ with SN
ProDG (via verify_match.sh) and disassembles both the DOL bytes and the
compiled bytes via devkitPPC's `powerpc-eabi-objdump`, then prints them in two
columns with mismatched instruction lines highlighted in red.

```bash
bash tools/diff_func.sh src/wip/match_0x801056EC_cXObjectImpl__KillSelf.cpp 0x801056EC 148
```

This is our "poor man's objdiff" — same wall-diagnosis benefit (visual diff
that's faster to scan than `MISMATCH 8 offsets` hex tail-log output) without
requiring the full ninja+target/base build pipeline objdiff needs. Full objdiff
integration is deferred to a future infra session.

## Build Verification — `config/G4ZE69/build.sha1`

The canonical DOL's SHA-1 lives in `config/G4ZE69/build.sha1`. CI's "Verify
final DOL SHA-1" step (active when ORIGINAL_DOL/ELF secrets are present)
confirms the linked output is byte-identical to the original after building.
A second always-on CI step verifies `config/G4ZE69/config.yml`'s `hash:` field
stays in sync with `build.sha1` so the two never drift.

Canonical SHA: `d15b7be1396544a15728f25f732db63a7cfcc877`.

## decomp.dev Integration

The project is listed at **https://decomp.dev/natebag/Sims2DECOMP**. Public-facing
progress numbers come from the JSON above (industry-standard byte-matched metric,
not file-count).

How the integration works:
1. Worker commits matched code → pre-commit hook regenerates report.json → commit lands with fresh report.
2. Push to main → GitHub Actions `Build` workflow runs → uploads `G4ZE69_report` artifact.
3. The decomp.dev GitHub App (installed on the repo) receives a `workflow_run` webhook → pulls the artifact → updates the dashboard within seconds.
4. PRs get an automatic comment showing the byte-progress delta vs main.

If you change the report schema, validate against an active decomp.dev project
(e.g. `zcanann/SFA-Decomp`) by downloading their latest artifact and diffing
fields — decomp.dev uses `objdiff_core::bindings::report::Report` (proto3 +
serde) so unrecognized fields are silently dropped, but missing required fields
fail validation.

## Symbol Map Quick Reference

The release map contains 39,169 named symbols across these major systems:

| System | Key Classes | Approx Functions |
|--------|------------|-----------------|
| Sim AI | ESim, CASTarget, CasEventResetSim | ~2000 |
| Objects | cXObject, ISimsMultiTileObjectModel | ~3000 |
| Rendering | ENgcRenderer, FrameEffects, BloomSettings | ~1500 |
| Camera | ESimsCam | ~200 |
| Build Mode | InteractorModule::WallManipulator | ~500 |
| UI / APT | Apt*, AptActionInterpreter, AptCharacter | ~3000 |
| Audio | AmbientScorePlayer | ~500 |
| Memory | EAHeap, FastAllocPool | ~300 |
| Inventory | BBI::InventoryItems | ~400 |
| Goals | GoalUnlock | ~200 |
| Save | SimsMemCardWrap | ~100 |
| Skin | SkinCompositor | ~300 |
| Boot / SDK | __start, DolphinSDK, SN runtime | ~500 |
| Misc / Unknown | Various | ~26,000+ |

## Key Documents

- `docs/specs/sims2-gc-decomp-design.md` — full decomp design spec
- `docs/tracking/next-steps.md` — prioritized task queue
- `docs/tracking/progress.md` — decomp progress metrics
- `docs/systems/boot-sequence.md` — boot flow documentation
- `docs/file-formats/arc-format.md` — .arc archive format
- `extracted/files/u2_ngc_release.map` — the symbol bible
- `extracted/files/u2_ngc_debug.map` — debug symbol map
- `extracted/files/eorwb.log` — original EA build log (8.8MB)

## Toolchain

- **Compiler:** devkitPPC (GCC cross-compiler for PowerPC)
- **Decomp toolkit:** decomp-toolkit (`dtk`) for project management and verification
- **RE tool:** Ghidra with PowerPC/Gekko processor profile
- **Emulator:** Dolphin (testing + debugging)
- **Build:** Python + Make/CMake
- **Platform:** Windows 11

## Hooks

After cloning, run `bash tools/install-hooks.sh` to install the pre-commit
hook that verifies match files before commit. Without it, fake matches can
slip through. Set `SKIP_VERIFY=1 git commit ...` for emergency bypass.
