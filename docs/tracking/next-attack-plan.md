# Next Attack Plan — Session Starting Point

**Last session:** 2026-04-05 — 6,771 / 20,508 matched (33.0%)
**Remaining:** 13,737 functions

## Quick Context for New Session

The compiler is confirmed correct (all ProDG versions produce identical code). The toolchain works. What blocks remaining functions is per-function C++ accuracy — getting the exact variable declarations, cast patterns, and expression structure right so the register allocator matches.

### What's Already Done (DON'T REPEAT)
- All <=64B functions in asm_decomp — 100% cleared
- All 4-8B goldmine functions — auto-matcher cleared them
- All template families at 40-56B (dtors, factories, operators, wrappers, forwarding)
- All 65-128B asm_decomp systems scanned for template families
- Compiler flag investigation — `-fno-schedule-insns2` is the only useful addition
- All 4 ProDG versions (v3.5, v3.7, v3.81, v3.93) produce identical code

### Key Compiler Flags
- Default: `-O2 -fno-elide-constructors -fno-schedule-insns2 -msdata=eabi -G 8`
- Some functions need scheduling ENABLED: add `// FLAGS: -fno-elide-constructors` as first line
- verify_match.sh reads `// FLAGS:` from each file to override defaults

---

## Attack Vector 1: Goldmine Per-Function Analysis (2,384 functions, HIGH PRIORITY)

**What:** 2,384 functions at 8-64B from missing_functions_report.txt that the auto-matcher couldn't handle. These have conditional branches, if/else patterns, loops — too complex for auto-generation but still small enough to match manually.

**How:**
1. Run `tools/goldmine_matcher.py` first — it handles trivial patterns automatically
2. For remaining "unknown" functions, extract with `tools/extract_function.py 0xADDR SIZE`
3. Study the disassembly, write C++, verify with `tools/verify_match.sh`
4. Try BOTH scheduling flag states on each function
5. Functions WITH `bl` calls match better than leaf functions

**Team allocation:** Best for Claude workers (Opus/Sonnet) who can analyze complex patterns. Kimi workers hit VERSION_DIFF too often on non-trivial functions.

**Expected yield:** ~20-30% match rate = 500-700 new matches

---

## Attack Vector 2: Extend Auto-Matcher Patterns (MEDIUM PRIORITY)

**What:** The auto-matcher handles 16 patterns. More can be added:
- Simple if/else: `cmpwi r3,0; beq .L1; [action]; .L1: blr`
- Conditional return: `lwz r3,off(r3); cmpwi r3,0; bnelr; li r3,0; blr`
- Loop with counter: `mtctr rN; .loop: [body]; bdnz .loop; blr`
- Two-call chain: `bl func1; mr r4,r3; bl func2; blr`

**How:** Extend `tools/goldmine_matcher.py` with these patterns, re-run against unknowns.

**Expected yield:** 50-100 new matches per pattern added

---

## Attack Vector 3: VERSION_DIFF Recovery (40+ files, MEDIUM PRIORITY)

**What:** 40+ files in `src/wip/version_diff/` with correct C++ logic but wrong codegen. Some may match with:
- Different C++ expression structure (reorder operations)
- Different variable declarations (local vs inline)
- Different cast chains
- Per-file flag toggle

**How:** For each file, try 3-4 C++ variants and both flag states. Systematic experimentation.

**Expected yield:** ~25% recovery = 10 matches

---

## Attack Vector 4: 65-128B Per-Function Deep RE (3,275 functions, LOWER PRIORITY)

**What:** 3,275 unmatched 65-128B functions in asm_decomp. Template families exhausted. Remaining functions need:
- Correct struct layouts (use headers in include/)
- r11 vtable pattern filter (53% match rate on r11, ~0% on r3)
- Per-function register pressure matching
- Creative C++ restructuring

**How:** OpusWorker proved 53% match rate by filtering for r11 vtable pattern. Apply same filter systematically across all remaining functions.

**Expected yield:** ~15-20% match rate on r11 candidates = 200-400 new matches

---

## Attack Vector 5: 128B+ Tier (5,061 functions, FUTURE)

**What:** 5,061 unmatched functions at 128-512B. Confirmed hard — 0 matches from direct attempts.

**How:** Needs either:
- TU-based compilation approach (compile multiple functions together)
- Deep per-function RE with full class layout understanding
- Community help (decomp.me scratches, contributor PRs)

**Expected yield:** Unknown — this is the hard frontier

---

## Team Deployment Guide

| Worker Type | Best For | Avoid |
|-------------|----------|-------|
| Opus (Claude) | Complex per-function analysis, auto-matcher development, pattern discovery | Simple repetitive tasks |
| Sonnet (Claude) | Template blasting, medium complexity matching, systematic sweeps | Very complex single functions |
| Kimi | Headers/struct RE, tooling, documentation, triage scans | Direct matching on 65B+ functions (VERSION_DIFF hit rate too high) |
| Reviewer | Audit before commits, dedup monitoring, info board management | Matching work |
| Researcher | Online searches, community outreach, doc lookup | Code writing |

## Pre-Session Checklist

1. Run `tools/goldmine_matcher.py` — auto-match any new trivial functions
2. Check `git status` — ensure clean starting state
3. Check `find src/matched/ -name "*.cpp" | wc -l` — verify count matches expected
4. Review `src/wip/version_diff/` — any new ideas for recovery?
5. Deploy workers on Attack Vector 1 first (highest ROI)

## Infrastructure Reminders

- Pre-commit hook auto-verifies and auto-moves VERSION_DIFF
- `// FLAGS: -fno-elide-constructors` overrides default flags per-file
- Dedup check before EVERY file: `find src/matched/ -name "*ADDRESS*"`
- All workers MUST message MainGuy when done (standing order on info board)
- VERSION_DIFF files go to `src/wip/version_diff/` — NEVER delete work
