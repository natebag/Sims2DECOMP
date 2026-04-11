#!/usr/bin/env python3
"""matcher_bot_shard.py — split src/wip/version_diff/ into 4 parallel shards.

Phase A5-bulk support. Writes 4 round-robin manifest files that feed
tools/matcher_bot_bulk.py --manifest <shard> for parallel execution by
the OpusWorker / SonnetWorker / KimiWorker / Kmiworker2 fleet.

Usage:
    python tools/matcher_bot_shard.py
    python tools/matcher_bot_shard.py --dir src/wip/version_diff/
    python tools/matcher_bot_shard.py --out-dir build/matcher_bot_shards/
    python tools/matcher_bot_shard.py --shards 4 --names opus sonnet kimi kmi2
"""

from __future__ import annotations

import argparse
import subprocess
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
DEFAULT_POOL_DIR = REPO_ROOT / "src" / "wip" / "version_diff"
DEFAULT_OUT_DIR = REPO_ROOT / "tools" / "shards"
DEFAULT_NAMES = ["opus", "sonnet", "kimi", "kmi2"]


def list_wip_files(pool_dir: Path) -> list[Path]:
    """Enumerate all .cpp files in the pool that are tracked by git.

    Using git ls-files instead of a raw glob so that freshly renamed /
    deleted files don't slip into the shard list. Falls back to glob if
    git ls-files fails.
    """
    rel = pool_dir.relative_to(REPO_ROOT)
    try:
        result = subprocess.run(
            ["git", "ls-files", str(rel).replace("\\", "/") + "/*.cpp"],
            cwd=str(REPO_ROOT),
            capture_output=True,
            text=True,
            check=True,
        )
        lines = [line.strip() for line in result.stdout.splitlines() if line.strip()]
        return [REPO_ROOT / ln for ln in lines]
    except (FileNotFoundError, subprocess.CalledProcessError):
        return sorted(pool_dir.glob("*.cpp"))


def main() -> int:
    ap = argparse.ArgumentParser(description="Split wip pool into N shard manifests.")
    ap.add_argument("--dir", type=Path, default=DEFAULT_POOL_DIR,
                    help="Pool directory (default: src/wip/version_diff/)")
    ap.add_argument("--out-dir", type=Path, default=DEFAULT_OUT_DIR,
                    help="Where to write shard_<name>.txt files")
    ap.add_argument("--shards", type=int, default=4, help="Number of shards (default 4)")
    ap.add_argument("--names", nargs="+", default=DEFAULT_NAMES,
                    help="Shard names (default: opus sonnet kimi kmi2)")
    args = ap.parse_args()

    if len(args.names) != args.shards:
        print(f"error: --shards {args.shards} but got {len(args.names)} names", flush=True)
        return 1

    pool = args.dir
    if not pool.is_dir():
        print(f"error: pool dir missing: {pool}")
        return 1

    files = list_wip_files(pool)
    if not files:
        print(f"error: no .cpp files in {pool}")
        return 1

    # Sort by byte size ASCENDING so shards are easier to balance and so
    # runners see quick hit-rate feedback (small files crack fast).
    sized = sorted(
        ((f.stat().st_size if f.is_file() else 0, f) for f in files),
        key=lambda t: t[0],
    )

    # Round-robin split so every shard gets a mix of small/medium/large.
    shards: list[list[Path]] = [[] for _ in range(args.shards)]
    for idx, (_, f) in enumerate(sized):
        shards[idx % args.shards].append(f)

    args.out_dir.mkdir(parents=True, exist_ok=True)

    print(f"pool: {pool}  files: {len(files)}")
    print(f"out:  {args.out_dir}")
    print()
    total_bytes = 0
    for name, shard in zip(args.names, shards):
        dest = args.out_dir / f"shard_{name}.txt"
        lines: list[str] = []
        shard_bytes = 0
        for p in shard:
            rel = p.relative_to(REPO_ROOT).as_posix()
            lines.append(rel)
            shard_bytes += p.stat().st_size if p.is_file() else 0
        dest.write_text("\n".join(lines) + "\n", encoding="utf-8")
        total_bytes += shard_bytes
        print(
            f"  shard_{name:6s}: {len(shard):4d} files  "
            f"({shard_bytes/1024:7.1f} KB)  -> {dest.relative_to(REPO_ROOT).as_posix()}"
        )

    print()
    print(f"total: {sum(len(s) for s in shards)} files  ({total_bytes/1024:.1f} KB)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
