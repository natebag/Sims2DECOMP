# Bulk Audit Session Plan

**Purpose:** A dedicated session to establish the definitive verified-clean count of `src/matched/` and clean up all orphan files. Audit-only — no matching work.

**Scheduled for:** the next session after 2026-04-07 (the PMF + SDA + tool fix session).

**Estimated duration:** 80-100 minutes.

---

## Why a Dedicated Session?

The 2026-04-07 session discovered that:
- **9,321 files in `src/matched/`** but **only ~8,500 estimated truly verified** (~10% inflation)
- **30.4% orphan rate** in one bulk-add commit (`16a47f59`)
- **~3.3% orphan rate** in random samples of the broader tree
- **300-800 estimated orphan files** project-wide

Mixing this audit with active matching creates context switching and risks new orphans being added while old ones are being cleaned up. A dedicated focused session — different agent roster, single goal — produces a much cleaner outcome.

---

## Workspace Roster

**1 orchestrator + 5 reviewers (multi-LLM cross-validation).**

| Name | Model | Role | Specialty |
|------|-------|------|-----------|
| **AuditChief** | Sonnet 4.6 | Orchestrator | Dispatches, tracks, merges, commits, pushes |
| **KimiAuditA** | Kimi | Reviewer | Audits chunk 1 of `src/matched/agent/` (~2300 files) |
| **KimiAuditB** | Kimi | Reviewer | Audits chunk 2 of `src/matched/agent/` (~2300 files) |
| **OpusReview** | Opus 4.6 | Deep-Dive Reviewer | Deep-dive on FAILs + ambiguous cases. Final-call authority on edge cases. |
| **SonnetReview** | Sonnet 4.6 | Cleanup Reviewer | Cross-validates a 5% sample of PASSES + executes the cleanup commits |
| **CodexReview** | Codex (OpenAI) | Tooling Reviewer | Validates `audit_matched_dir.py` for bugs + writes `count_matched.py` validation patch |

**Why each LLM:**
- **2× Kimi:** fast, parallelizable file enumeration. Different sessions can be lock-contended; spreading load reduces collisions.
- **Opus:** deepest reasoning for ambiguous cases (TU-only matches, status-33 errors, parse failures that look like bugs).
- **Sonnet:** balanced speed/quality. Trustworthy executor for the cleanup commits where many files move at once.
- **Codex:** independent perspective from a different model family. Particularly good at the tooling validation (pure code, no game-specific knowledge needed).
- **AuditChief on Sonnet:** mid-range orchestrator. Opus is overkill for dispatch; Kimi may struggle with the parallel coordination across 5 workers.

---

## Pre-Flight Setup (5 min)

1. **Pull latest from remote:**
   ```bash
   cd "F:/coding/Decompiles/Sims 2"
   git pull origin main
   git log -1 --oneline  # confirm at expected SHA (≥ 947b984b)
   ```

2. **Install the pre-commit hook:**
   ```bash
   bash tools/install-hooks.sh
   ls -la .git/hooks/pre-commit  # confirm exists, executable
   ```

3. **Regenerate the file list:**
   ```bash
   find src/matched -name "match_*.cpp" -type f > /tmp/audit_filelist.txt
   wc -l /tmp/audit_filelist.txt  # should be ~9300
   ```

4. **Smoke-test the audit tool:**
   ```bash
   head -5 /tmp/audit_filelist.txt | xargs -I {} python tools/audit_matched_dir.py --file {}
   ```
   Confirm output is a clean PASS/FAIL/SKIP per file.

5. **Smoke-test verify_match.sh:**
   ```bash
   bash tools/verify_match.sh src/matched/cbmt_blast/match_0x803BCAA8_CBMemberTranslator1wRet_char__.cpp 0x803BCAA8 120
   ```
   Confirm `MATCH! Function ...`.

6. **Create the workspace** in AgentOrch with the 6-agent roster above.

7. **AuditChief reads CEO notes + this plan** before dispatching anyone.

---

## Phase 1: Parallel Chunked Audit (30-45 min)

**Split the ~9300 files into 4 roughly equal chunks** by sorted line number, each ~2300 files.

```bash
LINES=$(wc -l < /tmp/audit_filelist.txt)
CHUNK=$((LINES / 4 + 1))
split -l $CHUNK -d /tmp/audit_filelist.txt /tmp/audit_chunk_
# Produces audit_chunk_00, _01, _02, _03
```

**Dispatch to 4 reviewers in parallel:**

| Agent | Chunk | Output file |
|-------|-------|-------------|
| KimiAuditA | `audit_chunk_00` (~2300 files) | `tools/audit_results_kimiA.txt` |
| KimiAuditB | `audit_chunk_01` (~2300 files) | `tools/audit_results_kimiB.txt` |
| OpusReview | `audit_chunk_02` (~2300 files) | `tools/audit_results_opus.txt` |
| SonnetReview | `audit_chunk_03` (~2300 files) | `tools/audit_results_sonnet.txt` |

**Each reviewer's task description:**
```
For each file in <CHUNK_FILE>:
1. Read first 5 lines to find // 0xADDRESS and (SIZEb)
2. If header unparseable, output: SKIP <file> (no header)
3. Run: bash tools/verify_match.sh <file> <addr> <size>
4. Categorize result:
   - "MATCH! Function" → PASS
   - "MISMATCH" or "SIZE_MISMATCH" → MISMATCH
   - "undeclared" or "COMPILE FAILED" → COMPILE_FAIL
   - Anything else → OTHER + first 3 lines of output
5. Append: <STATUS> <file> <addr> <size> [<details>] to your output file
6. After every 100 files, post a progress note: "Audited X / 2300, P pass, F fail, S skip"
7. When done, post info note tagged `audit-chunk-done` with totals
```

**Anti-coordination notes:**
- All 4 reviewers will hit `verify_match.sh` simultaneously, which means heavy SN ProDG compile load. Consider: limit to 2 parallel at first to gauge throughput, then ramp to 4 if no contention.
- Git lock contention: Reviewers should NOT commit during this phase. They write to their output files only. Only AuditChief commits in Phase 4.
- If a reviewer's session crashes or stalls, AuditChief can re-dispatch their chunk to a fresh agent — partial output files are useful.

**CodexReview's parallel task while Phase 1 runs:**
```
1. Read tools/audit_matched_dir.py and tools/verify_match.sh
2. Look for bugs that could produce false PASS or false FAIL
3. Specifically check:
   - Does the script handle files >100KB cleanly?
   - Does it handle missing source files gracefully?
   - Are there race conditions if 2 invocations hit the same temp file?
   - Are there hidden assumptions about CWD or file path encoding?
4. Output findings to tools/audit_tool_review.md
5. Don't change any files yet — just report
```

---

## Phase 2: Merge + Categorize (5 min)

**AuditChief executes:**
```bash
cat tools/audit_results_*.txt | sort -u > tools/full_audit_results.txt
wc -l tools/full_audit_results.txt
grep -c "^PASS" tools/full_audit_results.txt
grep -c "^MISMATCH" tools/full_audit_results.txt
grep -c "^COMPILE_FAIL" tools/full_audit_results.txt
grep -c "^SKIP" tools/full_audit_results.txt
grep -c "^OTHER" tools/full_audit_results.txt
```

**AuditChief posts to info channel** tagged `audit-phase2-merged`:
- Total files audited
- Per-category counts
- Estimated cleanup count (MISMATCH + COMPILE_FAIL + relevant OTHER)
- Estimated true verified count (PASS count)

---

## Phase 3: Deep-Dive on FAILs (15 min)

**OpusReview's mission:**
For each FAIL category in `tools/full_audit_results.txt`, classify each file:

| Category | Action |
|----------|--------|
| MISMATCH (real byte diff) | Mark as RELOCATE — to `wip/version_diff/` |
| MISMATCH (TU-only — passes in `tu_match.py --combine`) | Mark as TU_ONLY — keep in matched/ but add `// TU_MODE_ONLY` header marker |
| COMPILE_FAIL (missing extern) | Mark as RELOCATE — broken source, wip until fixed |
| COMPILE_FAIL (parse error) | Mark as DELETE — usually unsalvageable |
| OTHER (status 33) | Re-investigate; usually compile-fail variant |
| SKIP (no header) | Mark as HEADER_FIX — file may be valid but unparseable; needs manual header repair |

**Output to `tools/cleanup_actions.txt`:**
```
RELOCATE  src/matched/agent/match_0xXXX_*.cpp  reason: <category>
DELETE    src/matched/agent/match_0xYYY_*.cpp  reason: <category>
TU_ONLY   src/matched/agent/match_0xZZZ_*.cpp  reason: TU compilation passes
HEADER_FIX src/matched/agent/match_0xWWW_*.cpp reason: unparseable header
```

**OpusReview also identifies the top 5 root causes** of failures and posts a summary tagged `audit-phase3-rootcauses`. This informs future workflow improvements.

**For TU_ONLY files:** these need a separate verification pass via `tu_match.py --combine`. OpusReview should sample 10 of them and confirm they actually pass TU mode before marking. If most don't, downgrade them all to RELOCATE.

---

## Phase 4: Cleanup Commit (10 min)

**SonnetReview executes the actions in `tools/cleanup_actions.txt`** using a script:

```bash
#!/usr/bin/env bash
# tools/execute_audit_cleanup.sh
set -e
RELOCATE_COUNT=0
DELETE_COUNT=0
HEADER_COUNT=0

while IFS= read -r line; do
    action=$(echo "$line" | awk '{print $1}')
    file=$(echo "$line" | awk '{print $2}')
    case "$action" in
        RELOCATE)
            basename=$(basename "$file")
            git mv "$file" "src/wip/version_diff/$basename" 2>&1 || echo "FAIL mv: $file"
            RELOCATE_COUNT=$((RELOCATE_COUNT + 1))
            ;;
        DELETE)
            git rm "$file" 2>&1 || echo "FAIL rm: $file"
            DELETE_COUNT=$((DELETE_COUNT + 1))
            ;;
        HEADER_FIX)
            # Don't auto-fix; just mark in a TODO list
            echo "$file" >> tools/audit_header_fix_todo.txt
            HEADER_COUNT=$((HEADER_COUNT + 1))
            ;;
    esac
done < tools/cleanup_actions.txt

echo "Relocated: $RELOCATE_COUNT  Deleted: $DELETE_COUNT  Header-fix queued: $HEADER_COUNT"
```

**Then commit as a single huge cleanup:**
```
fix: full bulk audit cleanup — relocate N orphans, delete M, queue K for header fix

Bulk audit of src/matched/ via tools/audit_matched_dir.py + tools/verify_match.sh
(post 6062cc25 fix). Ran across all 9,321 files in 4 parallel chunks via
KimiAuditA/B + OpusReview + SonnetReview. Cross-validated by deep-dive on
all FAILs.

Results:
- Audited: 9,321
- PASS:    <P>
- MISMATCH:    <M> (relocated to wip/version_diff/)
- COMPILE_FAIL: <C> (relocated to wip/version_diff/ or deleted)
- TU_ONLY:    <T> (kept with TU_MODE_ONLY marker)
- HEADER_FIX queued: <H> (in tools/audit_header_fix_todo.txt)

Verified-clean count after this commit: <V> (was 9,321 by file count).
True project progress: <V> / 20,508 = <PCT>% (was reported as 44.8%).

This commit closes the workflow gap that allowed orphans to accumulate
before the pre-commit hook (commit 80f3ec9d) was in place.
```

---

## Phase 5: count_matched.py Validation Patch (10 min — parallel to Phase 4)

**CodexReview's mission:**
Patch `tools/count_matched.py` to validate before counting. Currently it counts files in `src/matched/`. New behavior:
1. Optionally accept a `--audit` flag that uses `tools/full_audit_results.txt` if it exists
2. With `--audit`, count only PASS files
3. Without `--audit`, fall back to file count but PRINT A WARNING that the count may be inflated
4. Always print BOTH numbers (file count vs verified count) when audit data is available

**Test cases CodexReview should validate:**
- Run on the current tree → produces sane output
- Run with stale audit file → warns about staleness
- Run with no audit file → file count + warning

**Commit as:** `feat(tools): count_matched.py — validate before counting via audit data`

---

## Phase 6: Final Count + Report (5 min)

**AuditChief executes:**
```bash
python tools/count_matched.py --audit
```

Expected output: file count, verified count, percentage of 20,508.

**AuditChief updates README.md** with the new honest numbers in the Status table (replacing the "~8,400-8,900 estimate" with the actual count).

**AuditChief updates `docs/tracking/next-attack-plan.md`** with:
- Final verified count
- Cleanup committed (commit SHA)
- Workflow gap permanently closed (hook + tool fix + count fix)
- Next session can return to matching work without audit overhead

**AuditChief posts a final summary to info channel** tagged `bulk-audit-complete`:
- Total time
- Reviewer contributions
- Final number
- Lessons learned

---

## Phase 7: Push (1 min)

**AuditChief executes:**
```bash
git push origin main
```

---

## Success Criteria

- ✅ Definitive verified count established (not just file count)
- ✅ All confirmed orphans relocated to `wip/version_diff/` or deleted
- ✅ `count_matched.py` reflects reality going forward
- ✅ README + attack plan updated with the honest number
- ✅ No matching work attempted in this session (audit-only discipline maintained)
- ✅ All commits pushed to remote
- ✅ Workflow gap closure verified by attempting to commit a known-bad file (should be blocked by hook)

---

## Risk Mitigation

| Risk | Mitigation |
|------|------------|
| Reviewer session crashes mid-chunk | Output files are line-appended after every file; AuditChief can re-dispatch the unfinished portion |
| Git lock contention from 5 agents | Only AuditChief commits; reviewers write to text files only |
| `verify_match.sh` is slow | 4-way parallelization brings ~9300 files × ~2s/file = ~80 min sequential down to ~20 min wall clock |
| OpusReview deep-dive takes longer than 15 min | Pre-classify by category; OpusReview only re-checks ambiguous cases |
| Codex reviewer can't access AgentOrch | Run their tasks via direct prompt + paste outputs, treat as a "read-only agent" |
| Cleanup commit is too large | Split by directory (`src/matched/agent/` vs `src/matched/cbmt_blast/` vs `src/matched/global/` etc.) into 3-5 smaller commits |
| TU_ONLY classification is wrong | OpusReview samples 10 of them with `tu_match.py --combine` before marking the whole batch |

---

## Estimated Timeline

| Phase | Duration | Cumulative |
|-------|----------|------------|
| Pre-flight | 5 min | 5 min |
| Phase 1: Parallel chunked audit | 30-45 min | 35-50 min |
| Phase 2: Merge + categorize | 5 min | 40-55 min |
| Phase 3: Deep-dive on FAILs | 15 min | 55-70 min |
| Phase 4: Cleanup commit | 10 min | 65-80 min |
| Phase 5: count_matched.py patch (parallel to 4) | 10 min | 65-80 min |
| Phase 6: Final report + doc updates | 5 min | 70-85 min |
| Phase 7: Push | 1 min | 71-86 min |
| **TOTAL** | **~80-90 min** | |

---

## What Comes After

Once this audit lands, the project is back on solid ground for matching work. The next session can:
- **Track 1:** Inline-asm-stub conversion (~10,913 functions, slow per-function but largest pool)
- **Track 2:** Direct DOL extraction for `[no source]` functions (~1,926 functions)
- **Track 3:** Targeted blocker research (instruction scheduling, multi-blrl, float reg alloc)

With the honest count established and the workflow gap closed, every match committed from this point forward is real progress that compounds correctly.
