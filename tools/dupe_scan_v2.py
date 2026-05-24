#!/usr/bin/env python3
"""dupe_scan_v2.py -- Per-address virgin-check dupe scanner (3-tier classification).

Scans src/matched/agent/ for ASMPROC_inject_before stubs and classifies each
against the canonical src/matched/<subdir>/ counterpart at the same address.

Tiers
-----
TIER-0  NO COUNTERPART  agent/ is the sole provider -- DO NOT DELETE
TIER-1  SAFE            canonical has real non-inject C++ -- safe to delete agent/
TIER-2  MIRROR          canonical has identical inject content -- spot-check then delete
TIER-3  DIFFER          canonical has different inject content -- DO NOT DELETE

Usage
-----
    python tools/dupe_scan_v2.py                  # print summary
    python tools/dupe_scan_v2.py --verbose        # show every file classification
    python tools/dupe_scan_v2.py --write-pathspecs # write per-dir rmonly files for T1+T2
    python tools/dupe_scan_v2.py --tier 1         # show only tier-1 safe files

IsAskedToMove incident (2026-05-23): Wave 2 wrongly deleted
match_0x80122A14_IsAskedToMove_cXPersonImpl.cpp because the pre-scan classified
it as a dupe but no canonical hand-written counterpart existed. This script
prevents a recurrence via explicit 3-tier virgin check before any delete.
"""

import argparse
import re
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).parent.parent
AGENT_DIR = REPO_ROOT / "src" / "matched" / "agent"
MATCHED_DIR = REPO_ROOT / "src" / "matched"

MATCH_ADDR_RE = re.compile(r"match_(0[xX])?([0-9A-Fa-f]{8})_", re.IGNORECASE)
INJECT_RE = re.compile(r"^\s*//\s*ASMPROC_inject_before\b", re.MULTILINE)
INJECT_LINE_RE = re.compile(r"(^\s*//\s*ASMPROC_inject_before[^\n]*)", re.MULTILINE)


def get_inject_line(path: Path, read_bytes: int = 4096) -> str | None:
    """Return the first ASMPROC_inject_before directive line, or None if file has none."""
    try:
        with open(path, "r", encoding="utf-8", errors="replace") as f:
            head = f.read(read_bytes)
        m = INJECT_LINE_RE.search(head)
        if m:
            return m.group(1).strip()
        return None
    except OSError:
        return None


def has_inject(path: Path, read_bytes: int = 4096) -> bool:
    """Return True if path contains an ASMPROC_inject_before directive."""
    try:
        with open(path, "r", encoding="utf-8", errors="replace") as f:
            head = f.read(read_bytes)
        return bool(INJECT_RE.search(head))
    except OSError:
        return False


def find_canonical_counterpart(addr_hex: str) -> Path | None:
    """Find a non-agent/ match file for address addr_hex. Returns first match."""
    addr_lower = addr_hex.lower()
    for d in MATCHED_DIR.iterdir():
        if not d.is_dir() or d.name == "agent":
            continue
        for f in d.iterdir():
            if not f.name.endswith(".cpp"):
                continue
            m = MATCH_ADDR_RE.search(f.name)
            if m and m.group(2).lower() == addr_lower:
                return f
    return None


def classify_agent_file(agent_path: Path) -> tuple:
    """Classify an agent inject stub.

    Returns (tier, canonical_path_or_None).
    tier 0 = no counterpart, tier 1 = safe, tier 2 = mirror, tier 3 = differ.
    """
    m = MATCH_ADDR_RE.search(agent_path.name)
    if not m:
        return (0, None)
    addr_hex = m.group(2).lower()

    canonical = find_canonical_counterpart(addr_hex)
    if canonical is None:
        return (0, None)

    canon_inject = get_inject_line(canonical)
    if canon_inject is None:
        # canonical has real C++ -- safe delete
        return (1, canonical)

    agent_inject = get_inject_line(agent_path)
    if canon_inject == agent_inject:
        return (2, canonical)
    else:
        return (3, canonical)


def scan_agent_dir() -> list:
    """Scan agent/ and classify every inject stub.

    Returns list of (agent_path, tier, canonical_or_None) sorted by tier then name.
    """
    results = []
    for f in sorted(AGENT_DIR.glob("match_*.cpp")):
        if not has_inject(f):
            continue
        tier, canon = classify_agent_file(f)
        results.append((f, tier, canon))
    return sorted(results, key=lambda x: (x[1], x[0].name))


TIER_LABELS = {
    0: "T0-NO-COUNTERPART",
    1: "T1-SAFE          ",
    2: "T2-MIRROR        ",
    3: "T3-DIFFER        ",
}

TIER_SYMBOLS = {
    0: "[ ]",
    1: "[->]",
    2: "[~~]",
    3: "[!!]",
}


def write_pathspecs(results: list, out_dir: Path) -> None:
    """Write per-dir rmonly pathspec files for tier-1 and tier-2 entries."""
    out_dir.mkdir(parents=True, exist_ok=True)
    t1 = [r for r in results if r[1] == 1]
    t2 = [r for r in results if r[1] == 2]

    if t1:
        p = out_dir / "wave_supplemental_tier1_safe.txt"
        with open(p, "w", encoding="utf-8") as fh:
            for agent_path, _, _ in t1:
                rel = agent_path.relative_to(REPO_ROOT).as_posix()
                fh.write(rel + "\n")
        print("  wrote {} ({} files)".format(p.name, len(t1)))

    if t2:
        p = out_dir / "wave_supplemental_tier2_mirror.txt"
        with open(p, "w", encoding="utf-8") as fh:
            for agent_path, _, _ in t2:
                rel = agent_path.relative_to(REPO_ROOT).as_posix()
                fh.write(rel + "\n")
        print("  wrote {} ({} files)".format(p.name, len(t2)))


def main() -> None:
    parser = argparse.ArgumentParser(description="Per-address virgin-check dupe scanner")
    parser.add_argument("--verbose", "-v", action="store_true",
                        help="Show every file classification")
    parser.add_argument("--tier", type=int, choices=[0, 1, 2, 3],
                        help="Show only files of this tier")
    parser.add_argument("--write-pathspecs", action="store_true",
                        help="Write per-dir rmonly files for T1+T2 to docs/tracking/")
    parser.add_argument("--out-dir", type=Path,
                        default=REPO_ROOT / "docs" / "tracking",
                        help="Directory for --write-pathspecs output")
    args = parser.parse_args()

    if not AGENT_DIR.exists():
        print("ERROR: agent dir not found: {}".format(AGENT_DIR), file=sys.stderr)
        sys.exit(1)

    print("Scanning src/matched/agent/ inject stubs...", flush=True)
    results = scan_agent_dir()

    counts = {0: 0, 1: 0, 2: 0, 3: 0}
    for _, tier, _ in results:
        counts[tier] += 1

    if args.verbose or args.tier is not None:
        for agent_path, tier, canon in results:
            if args.tier is not None and tier != args.tier:
                continue
            sym = TIER_SYMBOLS[tier]
            lbl = TIER_LABELS[tier]
            canon_str = str(canon.relative_to(MATCHED_DIR)) if canon else "n/a"
            print("  {} {}  {}".format(sym, lbl, agent_path.name))
            if tier in (1, 2, 3):
                print("       canonical: {}".format(canon_str))

    total = len(results)
    print()
    print("=== dupe_scan_v2 summary ({} inject stubs in agent/) ===".format(total))
    print("  T0 NO COUNTERPART : {:5d}  (DO NOT DELETE)".format(counts[0]))
    print("  T1 SAFE           : {:5d}  (canonical has real C++ -> delete agent/)".format(counts[1]))
    print("  T2 MIRROR         : {:5d}  (identical inject -> spot-check then delete)".format(counts[2]))
    print("  T3 DIFFER         : {:5d}  (!! different inject -> DO NOT DELETE)".format(counts[3]))
    print()

    if counts[3] > 0:
        print("WARNING: T3 DIFFER files present -- investigate before any batch delete.")

    if args.write_pathspecs:
        print("Writing pathspecs to {}...".format(args.out_dir))
        write_pathspecs(results, args.out_dir)


if __name__ == "__main__":
    main()
