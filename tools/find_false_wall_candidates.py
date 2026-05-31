#!/usr/bin/env python3
"""Locate forced-stub false-wall candidates.

This is a read-only worklist generator. It scans src/matched/**/*.cpp files
that still carry ASMPROC directives and buckets them by markers that have
recently proven to be honest-redo candidates:

* // FLAGS: -fno-schedule-insns combined with ASMPROC
* ASMPROC swap_operands directives
* hardcoded "unmatchable" notes
"""

from __future__ import annotations

import argparse
import re
from dataclasses import dataclass, field
from pathlib import Path


DEFAULT_ROOT = Path("src/matched")
DEFAULT_OUTPUT = Path("build/reports/false_wall_candidates.md")

ADDR_RE = re.compile(r"0x[0-9A-Fa-f]{8}")
ASMPROC_RE = re.compile(r"^\s*//\s*ASMPROC_[A-Za-z0-9_]+")
FLAGS_RE = re.compile(r"^\s*//\s*FLAGS:\s*(.*)$")
SWAP_OPERANDS_RE = re.compile(r"^\s*//\s*ASMPROC_[A-Za-z0-9_]*swap_operands\b", re.IGNORECASE)
UNMATCHABLE_RE = re.compile(
    r"^\s*//.*\b(unmatchable|not[ -]?matchable|cannot match|can't match)\b",
    re.IGNORECASE,
)

BUCKETS = (
    ("no_schedule_retry", "ASMPROC + // FLAGS: -fno-schedule-insns"),
    ("swap_operands", "ASMPROC swap_operands / lwzx source-shape candidates"),
    ("unmatchable_note", "ASMPROC + hardcoded unmatchable note"),
)


@dataclass
class Candidate:
    path: Path
    address: str
    signatures: list[str] = field(default_factory=list)
    detail: dict[str, list[str]] = field(default_factory=dict)


def first_address(path: Path, text: str) -> str:
    for source in ("\n".join(text.splitlines()[:8]), path.name):
        match = ADDR_RE.search(source)
        if match:
            return match.group(0)
    return "UNKNOWN"


def marker_lines(lines: list[str], pattern: re.Pattern[str]) -> list[str]:
    hits = []
    for index, line in enumerate(lines, start=1):
        if pattern.search(line):
            hits.append(f"L{index}: {line.strip()}")
    return hits


def scan_file(path: Path) -> Candidate | None:
    text = path.read_text(encoding="utf-8", errors="replace")
    lines = text.splitlines()
    asmproc_lines = marker_lines(lines, ASMPROC_RE)
    if not asmproc_lines:
        return None

    candidate = Candidate(path=path, address=first_address(path, text))

    flag_hits = []
    for index, line in enumerate(lines, start=1):
        match = FLAGS_RE.match(line)
        if match and "-fno-schedule-insns" in match.group(1):
            flag_hits.append(f"L{index}: {line.strip()}")
    if flag_hits:
        candidate.signatures.append("no_schedule_retry")
        candidate.detail["no_schedule_retry"] = flag_hits

    swap_hits = marker_lines(lines, SWAP_OPERANDS_RE)
    if swap_hits:
        candidate.signatures.append("swap_operands")
        candidate.detail["swap_operands"] = swap_hits

    unmatchable_hits = marker_lines(lines, UNMATCHABLE_RE)
    if unmatchable_hits:
        candidate.signatures.append("unmatchable_note")
        candidate.detail["unmatchable_note"] = unmatchable_hits

    if not candidate.signatures:
        return None
    return candidate


def scan(root: Path) -> list[Candidate]:
    return [
        candidate
        for path in sorted(root.rglob("*.cpp"))
        if (candidate := scan_file(path)) is not None
    ]


def render(candidates: list[Candidate], root: Path) -> str:
    by_bucket = {name: [] for name, _ in BUCKETS}
    for candidate in candidates:
        for signature in candidate.signatures:
            by_bucket[signature].append(candidate)

    lines = [
        "# False-Wall Candidate Worklist",
        "",
        f"Scan root: `{root.as_posix()}`",
        "Scope: files under `src/matched/` carrying `ASMPROC_*` directives.",
        "",
        "## Counts",
        "",
        f"- forced stubs with at least one false-wall signature: {len(candidates)}",
    ]
    for name, label in BUCKETS:
        lines.append(f"- {label}: {len(by_bucket[name])}")

    for name, label in BUCKETS:
        lines.extend(["", f"## {label}", ""])
        items = by_bucket[name]
        if not items:
            lines.append("_No candidates found._")
            continue
        for candidate in items:
            sigs = ",".join(candidate.signatures)
            lines.append(f"- {candidate.address} `{candidate.path.as_posix()}` signatures={sigs}")
            for detail in candidate.detail.get(name, []):
                lines.append(f"  - {detail}")

    return "\n".join(lines) + "\n"


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=DEFAULT_ROOT)
    parser.add_argument(
        "--output",
        type=Path,
        help=f"write report to this path, e.g. {DEFAULT_OUTPUT.as_posix()}",
    )
    parser.add_argument(
        "--write-default-report",
        action="store_true",
        help=f"write report to {DEFAULT_OUTPUT.as_posix()}",
    )
    args = parser.parse_args()

    candidates = scan(args.root)
    report = render(candidates, args.root)

    output = DEFAULT_OUTPUT if args.write_default_report else args.output
    if output:
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(report, encoding="utf-8")
        print(f"Wrote {output.as_posix()}")
    else:
        print(report, end="")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
