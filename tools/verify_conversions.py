#!/usr/bin/env python3
"""verify_conversions.py — Per-commit stub→real-C++ conversion verifier.

Cross-checks commit message claims against actual inject_before directive
removal in src/matched/. Flags commits where the claimed conversion count
is >50% higher than the measured inject-delta (inflation threshold).

Usage:
    python tools/verify_conversions.py                    # since last run (stored in .last_verify)
    python tools/verify_conversions.py --since <commit>   # from specific commit
    python tools/verify_conversions.py --since HEAD~20    # last 20 commits
    python tools/verify_conversions.py --all              # full history (slow)
    python tools/verify_conversions.py --summary-only     # no per-commit detail

Output:
    Per-commit: hash, author-claim, inject-delta, status (OK/WARN/INFLATE)
    Summary: total claimed, total measured, mismatch count

Designed for T+2h cadence by OpusReviewGuy + TUScout cross-check protocol.
"""

import argparse
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from paths import REPO_ROOT

INJECT_DIRECTIVE = "ASMPROC_inject_before"
MATCHED_PREFIX = "src/matched/"

# Regex to extract claimed conversion count from commit message.
# Matches explicit conversion-count declarations only:
#   "upgrade N inject", "N stubs", "N converts", "N real-C++" (word-boundary anchored)
#   "×N" (Unicode multiplication — NOT ASCII x which appears in hex addresses like 0x802C)
# Deliberately excludes bare "xN" to avoid false positives from 0x<hex> addresses.
CLAIM_RE = re.compile(
    r"(?:"
    r"upgrade\s+(\d+)\s+inject"          # "upgrade 20 inject stubs"
    r"|(?<!\w)(\d+)\s+stub"              # "3 stubs" (not mid-word)
    r"|(?<!\w)(\d+)\s+real-C\+\+"        # "5 real-C++ upgrades"
    r"|(?<!\w)(\d+)\s+convert"           # "7 converts" (not mid-word)
    r"|×(\d+)"                           # "×4" (Unicode × only, NOT ASCII x)
    r")",
    re.IGNORECASE,
)

LAST_VERIFY_FILE = REPO_ROOT / ".last_verify_commit"
INFLATE_THRESHOLD = 0.5  # flag if claimed > measured * (1 + threshold)
MISMATCH_FLOOR = 3       # don't flag if absolute mismatch < this (noise)
BULK_RELOCATE_FLOOR = 50 # measured >> claimed by this much = bulk relocate (not discipline incident)


def run_git(*args, cwd=None) -> str:
    result = subprocess.run(
        ["git"] + list(args),
        cwd=str(cwd or REPO_ROOT),
        capture_output=True,
        text=True,
        check=True,
    )
    return result.stdout.strip()


def count_inject_in_file(blob: str) -> bool:
    """Return True if the blob content contains ASMPROC_inject_before."""
    return INJECT_DIRECTIVE in blob


def get_inject_delta_for_commit(commit_hash: str) -> dict:
    """Count inject_before additions/removals for a single commit.

    Returns dict with:
      - removed: files where inject was present in parent, absent in commit
      - added: files where inject was absent in parent, present in commit
      - net: removed - added (positive = net conversions)
      - files_touched: total src/matched/ .cpp files changed
    """
    # Get diff for this commit vs its parent
    try:
        diff_output = run_git(
            "diff", "--name-only", f"{commit_hash}^", commit_hash,
            "--", MATCHED_PREFIX
        )
    except subprocess.CalledProcessError:
        # Initial commit or merge — skip
        return {"removed": 0, "added": 0, "net": 0, "files_touched": 0}

    changed_files = [
        f for f in diff_output.splitlines()
        if f.endswith(".cpp") and "wip" not in f.split("/")
    ]

    removed = added = 0
    for filepath in changed_files:
        # Check parent version
        try:
            parent_blob = run_git("show", f"{commit_hash}^:{filepath}")
            parent_has = count_inject_in_file(parent_blob)
        except subprocess.CalledProcessError:
            parent_has = False  # file didn't exist in parent

        # Check current version
        try:
            current_blob = run_git("show", f"{commit_hash}:{filepath}")
            current_has = count_inject_in_file(current_blob)
        except subprocess.CalledProcessError:
            current_has = False  # file was deleted

        if parent_has and not current_has:
            removed += 1
        elif not parent_has and current_has:
            added += 1

    return {
        "removed": removed,
        "added": added,
        "net": removed - added,
        "files_touched": len(changed_files),
    }


def extract_claimed_count(message: str) -> int | None:
    """Extract the highest claimed conversion number from a commit message."""
    # Look for explicit numbers in the message
    matches = CLAIM_RE.findall(message)
    candidates = []
    for groups in matches:
        for g in groups:
            if g:
                candidates.append(int(g))
    return max(candidates) if candidates else None


def get_commits_since(since_ref: str | None, all_history: bool) -> list:
    """Return list of (hash, subject) tuples."""
    if all_history:
        log = run_git("log", "--oneline", "--", MATCHED_PREFIX)
    elif since_ref:
        log = run_git("log", "--oneline", f"{since_ref}..HEAD", "--", MATCHED_PREFIX)
    else:
        # Default: last 50 commits touching src/matched/
        log = run_git("log", "--oneline", "-50", "--", MATCHED_PREFIX)

    commits = []
    for line in log.splitlines():
        if not line.strip():
            continue
        parts = line.split(None, 1)
        if len(parts) == 2:
            commits.append((parts[0], parts[1]))
    return commits


def classify(claimed: int | None, measured: int) -> str:
    """Classify a commit's conversion claim vs measured inject delta.

    Statuses:
      OK           — claimed ≈ measured (within threshold)
      UNCLAIMED    — no numeric claim in commit message
      INFLATE      — claimed >> measured (tag-discipline incident, DM author)
      BULK_RELOCATE— measured >> claimed by large margin (relocate batch;
                     commit message understated but not a discipline incident)
      UNDER_CLAIM  — measured moderately > claimed (hidden wins, minor)
    """
    if claimed is None:
        return "UNCLAIMED"
    if measured == 0 and claimed == 0:
        return "OK"
    # INFLATE: claimed much more than measured
    if measured == 0 and claimed > MISMATCH_FLOOR:
        return "INFLATE"
    if claimed <= 0:
        # measured conversions but claimed 0 — check for bulk relocate
        if measured >= BULK_RELOCATE_FLOOR:
            return "BULK_RELOCATE"
        return "OK"
    # Both positive — compare ratio
    ratio = claimed / max(measured, 1)
    if ratio > (1 + INFLATE_THRESHOLD) and (claimed - measured) >= MISMATCH_FLOOR:
        return "INFLATE"
    # measured >> claimed
    if measured > claimed and (measured - claimed) >= BULK_RELOCATE_FLOOR:
        return "BULK_RELOCATE"
    if measured > claimed and (measured - claimed) >= MISMATCH_FLOOR:
        return "UNDER_CLAIM"
    return "OK"


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    parser.add_argument("--since", default=None,
                        help="Verify commits after this ref (exclusive)")
    parser.add_argument("--all", action="store_true",
                        help="Verify full git history (slow)")
    parser.add_argument("--summary-only", action="store_true",
                        help="Skip per-commit detail, show summary only")
    parser.add_argument("--save-last", action="store_true",
                        help="Save current HEAD as last-verified ref in .last_verify_commit")
    args = parser.parse_args()

    # Determine range
    since_ref = args.since
    if since_ref is None and not args.all:
        if LAST_VERIFY_FILE.exists():
            since_ref = LAST_VERIFY_FILE.read_text().strip()
            print(f"Resuming from last verify: {since_ref}")
        else:
            print("No --since and no .last_verify_commit — checking last 50 commits touching src/matched/")

    commits = get_commits_since(since_ref, args.all)
    if not commits:
        print("No commits to verify in range.")
        return 0

    print(f"\nVerifying {len(commits)} commits...\n")

    total_claimed = total_measured = inflate_count = bulk_count = under_count = 0
    results = []

    for commit_hash, subject in commits:
        delta = get_inject_delta_for_commit(commit_hash)
        claimed = extract_claimed_count(subject)
        status = classify(claimed, delta["net"])

        results.append({
            "hash": commit_hash,
            "subject": subject,
            "claimed": claimed,
            "measured": delta["net"],
            "removed": delta["removed"],
            "added": delta["added"],
            "files": delta["files_touched"],
            "status": status,
        })

        if claimed is not None:
            total_claimed += claimed
        total_measured += delta["net"]
        if status == "INFLATE":
            inflate_count += 1
        elif status == "BULK_RELOCATE":
            bulk_count += 1
        elif status == "UNDER_CLAIM":
            under_count += 1

    # Print per-commit detail
    if not args.summary_only:
        print(f"{'Hash':<10} {'Status':<10} {'Claimed':>8} {'Measured':>9} {'Files':>6}  Subject")
        print("-" * 90)
        for r in results:
            claimed_str = str(r["claimed"]) if r["claimed"] is not None else "—"
            flag = " <<<" if r["status"] == "INFLATE" else ""
            print(f"{r['hash']:<10} {r['status']:<10} {claimed_str:>8} {r['measured']:>9} "
                  f"{r['files']:>6}  {r['subject'][:50]}{flag}")

    # Summary
    print(f"\n{'='*60}")
    print(f"Commits checked:    {len(commits)}")
    print(f"Total claimed:      {total_claimed}")
    print(f"Total measured:     {total_measured}")
    print(f"INFLATE flags:      {inflate_count}  (claimed >> measured — tag discipline incident)")
    print(f"BULK_RELOCATE:      {bulk_count}  (measured >> claimed — unsung hygiene, not incident)")
    print(f"UNDER_CLAIM:        {under_count}  (measured moderately > claimed — hidden wins)")
    if inflate_count:
        print(f"\nINFLATED commits (DM author):")
        for r in results:
            if r["status"] == "INFLATE":
                print(f"  {r['hash']} claimed={r['claimed']} measured={r['measured']}: {r['subject'][:60]}")
    if bulk_count:
        print(f"\nBULK_RELOCATE commits (hygiene, no action needed):")
        for r in results:
            if r["status"] == "BULK_RELOCATE":
                claimed_str = str(r["claimed"]) if r["claimed"] is not None else "unclaimed"
                print(f"  {r['hash']} claimed={claimed_str} measured={r['measured']}: {r['subject'][:60]}")

    # Save last-verify ref
    if args.save_last:
        current_head = run_git("rev-parse", "HEAD")
        LAST_VERIFY_FILE.write_text(current_head + "\n")
        print(f"\nSaved HEAD {current_head[:8]} as last verify point.")

    return 1 if inflate_count else 0


if __name__ == "__main__":
    sys.exit(main())
