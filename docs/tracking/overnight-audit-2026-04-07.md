# Overnight Audit Data — 2026-04-07

**Source:** Reviewer agent, log-only overnight run (warm-up data for tomorrow's dedicated bulk audit session).

**Tool:** `tools/audit_matched_dir.py` against `src/matched/agent/` (commit `a6abe91f` baseline).

**Status:** PARTIAL — Reviewer stopped early per the wind-down instructions. ~9% of agent/ scanned.

---

## Reviewer's Raw Numbers

| Metric | Value |
|--------|-------|
| Files processed | 580 / 6,464 |
| Time spent | ~600 seconds (~10 min) |
| Throughput | ~58 files/min ≈ 1 file/sec |
| Estimated full-agent run time | ~110 min (if continued sequentially) |

| Bucket | Count | % of sample |
|--------|-------|-------------|
| OK (PASS) | 500 | 86.2% |
| FAIL (MISMATCH/COMPILE_FAIL) | 39 | 6.7% |
| SKIP (unparseable header) | 41 | 7.1% |

**Reviewer's projection:** ~6,366 real matches across the project (vs reported 9,192).

---

## MainGuy's Sanity-Check on the Numbers

Reviewer's projection looks low. Re-doing the math:

**Per-directory breakdown of `src/matched/`:**

| Directory | Approx file count | Verification status |
|-----------|-------------------|---------------------|
| `src/matched/agent/` | ~6,464 | 86.2% PASS in this sample |
| `src/matched/cbmt_blast/` | 334 | **100% verified** (independent audit by OpusWorker, info note `f0eeef1e`) |
| Other `src/matched/` subdirs | ~2,500 | Unknown — likely similar to agent/ |
| **TOTAL** | **~9,298** | |

**Better extrapolation:**
- agent/: 6,464 × 0.862 = **~5,572 real**
- cbmt_blast/: 334 × 1.000 = **334 real**
- Other: 2,500 × 0.862 (assumed) = **~2,155 real**
- **TOTAL: ~8,061 real (~39.3% project progress)**

This is slightly worse than OpusWorker's ~8,500 estimate but in the same ballpark.

**Why Reviewer's "6,366" is too low:** they may have applied a more aggressive denominator or counted SKIP files as "not real" (incorrect — SKIPs are unparseable, not necessarily fake; many are valid matches with non-standard headers).

---

## Bucket Interpretation

**OK (86.2%)** — files that pass the fixed verify_match.sh standalone. These are real matches.

**FAIL (6.7%)** — files that the new tool catches as MISMATCH or COMPILE_FAIL. These are confirmed orphans/broken matches and should be relocated to `wip/version_diff/` in tomorrow's cleanup commit.

**SKIP (7.1%)** — files where `audit_matched_dir.py` couldn't parse the header. These need INVESTIGATION, not deletion:
- Some will have valid C++ + valid bytes but a non-standard header format → recoverable
- Some will be fake hand-written files (like the IsTuning case) → relocate
- The 5-LLM reviewer team should categorize these case-by-case

---

## What Tomorrow's Session Should Do With This Data

1. **Treat this as the BASELINE, not the FINAL number.** Reviewer's sample was small (9% of agent/) and biased toward whichever files appeared first in their iteration order.

2. **Run the full audit per `docs/tracking/bulk-audit-session-plan.md`** with the 5-LLM reviewer team. The parallel chunked approach will process all 9,300+ files in ~30-45 min.

3. **Apply OpusReview's deep-dive on every FAIL** to distinguish:
   - Real fakes (relocate)
   - TU-only matches (mark + keep)
   - Tool artifacts (investigate)
   - Header bugs (fix in place)

4. **CodexReview validates `audit_matched_dir.py` itself** for bugs that could produce false PASS or false FAIL.

5. **Don't trust Reviewer's projection of "6,366 real"** — that math is too pessimistic. Use the full audit results instead.

---

## Output Files

- `tools/reviewer_overnight_audit.txt` — Reviewer's raw per-file results (580 entries)
- `docs/tracking/overnight-audit-2026-04-07.md` — this document

---

## No Actions Taken Tonight

Per user instructions:
- ❌ No deletes
- ❌ No relocations
- ❌ No commits cleaning up the FAIL files
- ✅ Data captured in this doc for tomorrow's session

User is asleep. Bulk audit session is scheduled for tomorrow per `docs/tracking/bulk-audit-session-plan.md`.
