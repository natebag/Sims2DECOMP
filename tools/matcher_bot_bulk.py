#!/usr/bin/env python3
"""matcher_bot_bulk.py — run matcher_bot on a list of files, collect results.

Used for Phase A5 bulk-sample runs. Output is a JSON summary suitable for
reporting hit rate + top mutators + blocker patterns.

Usage:
    python tools/matcher_bot_bulk.py file1.cpp file2.cpp ...
    python tools/matcher_bot_bulk.py --from-stdin            (one path per line)
    python tools/matcher_bot_bulk.py --manifest path.txt    (one path per line)
    python tools/matcher_bot_bulk.py --manifest path.txt --out build/foo.json

Writes the JSON summary to --out (default build/matcher_bot/bulk_summary.json).
"""

from __future__ import annotations

import json
import re
import subprocess
import sys
import time
from collections import Counter
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
BOT = REPO_ROOT / "tools" / "matcher_bot.py"
OUT = REPO_ROOT / "build" / "matcher_bot" / "bulk_summary.json"

SCORE_RE = re.compile(r"\]\s+([0-9]+\.[0-9]+)%\s+flags=")
MATCH_LINE_RE = re.compile(r"MATCH found: (\S+)")
FLAGS_LINE_RE = re.compile(r"^\s*flags:\s*(.*)$", re.MULTILINE)


def run_one(path: Path) -> dict:
    start = time.monotonic()
    try:
        proc = subprocess.run(
            [sys.executable, str(BOT), "--wip", str(path)],
            cwd=str(REPO_ROOT),
            capture_output=True,
            text=True,
            timeout=600,
        )
    except subprocess.TimeoutExpired:
        return {
            "path": str(path),
            "outcome": "TIMEOUT",
            "elapsed": time.monotonic() - start,
        }
    elapsed = time.monotonic() - start

    combined = (proc.stdout or "") + "\n" + (proc.stderr or "")
    scores = [float(s) for s in SCORE_RE.findall(combined)]
    best = max(scores) if scores else 0.0
    compile_fails = combined.count("COMPILE_FAIL")

    out: dict = {
        "path": str(path),
        "exit": proc.returncode,
        "elapsed": elapsed,
        "best_score": best,
        "variants_with_compile_fail": compile_fails,
    }
    if proc.returncode == 0:
        m = MATCH_LINE_RE.search(combined)
        out["outcome"] = "MATCH"
        out["winner_label"] = m.group(1) if m else "(unknown)"
        fl = FLAGS_LINE_RE.search(combined)
        out["winner_flags"] = fl.group(1).strip() if fl else ""
    elif proc.returncode == 2:
        out["outcome"] = "NEAR_MATCH"
        # Try to find the top variant from the "report:" line's file.
        report_dir = None
        for line in combined.splitlines():
            if "report:" in line:
                report_dir = line.split("report:", 1)[1].strip()
                break
        if report_dir:
            report_path = Path(report_dir)
            if report_path.is_file():
                try:
                    rlines = report_path.read_text(encoding="utf-8").splitlines()
                    # First numeric-prefixed line is rank 1.
                    for rl in rlines:
                        if rl.startswith("1    "):
                            parts = rl.split(None, 4)
                            if len(parts) >= 5:
                                out["top_label"] = parts[1]
                                out["top_score_str"] = parts[2]
                                out["top_flags"] = parts[4]
                            break
                except Exception:
                    pass
    else:
        out["outcome"] = "ERROR"
        out["stderr_tail"] = "\n".join(combined.strip().splitlines()[-5:])
    return out


def _load_manifest(path: Path) -> list[Path]:
    out: list[Path] = []
    for raw in path.read_text(encoding="utf-8").splitlines():
        line = raw.strip()
        if not line or line.startswith("#"):
            continue
        out.append(Path(line))
    return out


def main() -> int:
    args = sys.argv[1:]
    if not args:
        print("error: need file paths or --manifest <path> or --from-stdin", file=sys.stderr)
        return 1

    out_path = OUT
    targets: list[Path] = []
    i = 0
    while i < len(args):
        a = args[i]
        if a == "--from-stdin":
            targets.extend(Path(line.strip()) for line in sys.stdin if line.strip())
            i += 1
        elif a == "--manifest":
            if i + 1 >= len(args):
                print("error: --manifest needs a path", file=sys.stderr)
                return 1
            targets.extend(_load_manifest(Path(args[i + 1])))
            i += 2
        elif a == "--out":
            if i + 1 >= len(args):
                print("error: --out needs a path", file=sys.stderr)
                return 1
            out_path = Path(args[i + 1])
            i += 2
        else:
            targets.append(Path(a))
            i += 1

    if not targets:
        print("error: no target files", file=sys.stderr)
        return 1

    results: list[dict] = []
    total = len(targets)
    print(f"[bulk] running bot on {total} files")
    for i, p in enumerate(targets, 1):
        if not p.is_file():
            print(f"[{i}/{total}] MISSING {p}")
            results.append({"path": str(p), "outcome": "MISSING"})
            continue
        print(f"[{i}/{total}] {p.name}...", flush=True)
        r = run_one(p)
        results.append(r)
        summary = r.get("outcome", "?")
        extra = ""
        if summary == "MATCH":
            extra = f" [{r.get('winner_label','?')} flags={r.get('winner_flags','')}]"
        elif summary == "NEAR_MATCH":
            extra = f" best={r.get('best_score',0)*100:.1f}%"
        print(f"    -> {summary}{extra}  ({r.get('elapsed',0):.1f}s)")

    # Summary statistics.
    outcomes = Counter(r.get("outcome", "?") for r in results)
    match_count = outcomes.get("MATCH", 0)
    near_count = outcomes.get("NEAR_MATCH", 0)
    tried = len(results)
    hit_rate = (match_count / tried) if tried else 0.0

    winning_labels: Counter = Counter()
    for r in results:
        if r.get("outcome") == "MATCH":
            # Extract mutator family from e.g. T11_barrier2x2__M0_default
            lab = r.get("winner_label", "")
            base = lab.split("__", 1)[0] if "__" in lab else lab
            winning_labels[base] += 1
    top_mutators = winning_labels.most_common(5)

    elapsed_total = sum(r.get("elapsed", 0.0) for r in results)
    avg_elapsed = elapsed_total / max(tried, 1)

    summary = {
        "tried": tried,
        "matched": match_count,
        "near_match": near_count,
        "hit_rate": hit_rate,
        "elapsed_total_sec": round(elapsed_total, 1),
        "elapsed_avg_sec": round(avg_elapsed, 1),
        "outcomes": dict(outcomes),
        "top_winning_mutators": top_mutators,
        "results": results,
    }
    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text(json.dumps(summary, indent=2), encoding="utf-8")
    print()
    print(f"[bulk] tried={tried}  matched={match_count}  near={near_count}")
    print(f"[bulk] hit rate={hit_rate*100:.1f}%  avg={avg_elapsed:.1f}s")
    print(f"[bulk] top winning mutators: {top_mutators}")
    print(f"[bulk] summary json: {out_path}")
    return 0 if match_count > 0 else 2


if __name__ == "__main__":
    sys.exit(main())
