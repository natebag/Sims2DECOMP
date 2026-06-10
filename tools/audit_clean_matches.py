#!/usr/bin/env python3
"""
audit_clean_matches.py — honest decomp progress audit

Walks src/matched/**/*.cpp and sorts each match file into one of three buckets:
  - clean         : hand-written C++, no ASMPROC routing, no NON_MATCHING marker
  - forced        : uses // ASMPROC_* directives (post-compile asm mutation)
  - non_matching  : contains NON_MATCHING marker

Prints honest totals (file count + byte count) and writes worklists so the
forced / non_matching buckets become a concrete backlog to redo cleanly.

Run from repo root:
  python tools/audit_clean_matches.py
"""

import os
import re
import sys
from pathlib import Path
from collections import defaultdict

ROOT = Path(__file__).resolve().parent.parent
MATCHED_DIR = ROOT / "src" / "matched"
SYMBOLS_FILE = ROOT / "config" / "symbols.txt"
WORKLIST_DIR = ROOT / "build" / "audit"

# From CLAUDE.md: total game .text bytes excluding the Metrowerks-compiled
# DolphinSDK region at 0x8024-0x8039. This is the denominator for an honest
# decomp percentage.
GAME_TEXT_BYTES = 3_653_648

MATCH_FILENAME_RE = re.compile(r"match_(0x[0-9A-Fa-f]+)_")
SYMBOL_LINE_RE = re.compile(
    r"^\S+ = \.text:(0x[0-9A-Fa-f]+);\s*//\s*type:function\s+size:(0x[0-9A-Fa-f]+)"
)
ASMPROC_RE = re.compile(r"^\s*//\s*ASMPROC_[A-Za-z][A-Za-z0-9_]*", re.MULTILINE)
NON_MATCHING_RE = re.compile(r"\bNON_MATCHING\b")
# Banned-construct gates — keep in sync with tools/verify_match.sh step 0.
# A file using any of these is post-compile/codegen cheating regardless of
# whether its bytes match; it goes to the forced bucket, never clean.
# (2026-06-09: 52 register-asm files were found sitting in the clean bucket
# because the audit only gated on ASMPROC/NON_MATCHING.)
BANNED_RES = [
    re.compile(r"register[ \t]+[a-zA-Z_*&][a-zA-Z_0-9*&\t ]*[ \t]asm[ \t]*\("),
    re.compile(r"__asm__"),
    re.compile(r"__attribute__\s*\(\(\s*naked\s*\)\)"),
    re.compile(r"__builtin_unreachable"),
    re.compile(r"__attribute__\s*\(\(\s*noreturn\s*\)\)"),
    re.compile(r"\.long 0x"),
    re.compile(r"\.byte 0x"),
]


def load_symbol_sizes():
    """Return {addr_int: size_int} from config/symbols.txt."""
    sizes = {}
    if not SYMBOLS_FILE.exists():
        print(f"ERROR: {SYMBOLS_FILE} not found", file=sys.stderr)
        sys.exit(1)
    for line in SYMBOLS_FILE.read_text(encoding="utf-8", errors="replace").splitlines():
        m = SYMBOL_LINE_RE.match(line)
        if m:
            sizes[int(m.group(1), 16)] = int(m.group(2), 16)
    return sizes


def classify(source_text):
    """Return one of: 'forced', 'non_matching', 'clean'."""
    if ASMPROC_RE.search(source_text):
        return "forced"
    if NON_MATCHING_RE.search(source_text):
        return "non_matching"
    for banned in BANNED_RES:
        if banned.search(source_text):
            return "forced"
    return "clean"


def main():
    if not MATCHED_DIR.exists():
        print(f"ERROR: {MATCHED_DIR} not found", file=sys.stderr)
        sys.exit(1)

    sizes = load_symbol_sizes()

    buckets = defaultdict(list)  # bucket -> [(addr, size, path), ...]
    skipped_unknown_size = []
    duplicates = defaultdict(list)  # addr -> [paths]

    for cpp in MATCHED_DIR.rglob("*.cpp"):
        m = MATCH_FILENAME_RE.search(cpp.name)
        if not m:
            continue
        addr = int(m.group(1), 16)
        duplicates[addr].append(cpp)
        size = sizes.get(addr)
        if size is None:
            skipped_unknown_size.append(cpp)
            continue
        text = cpp.read_text(encoding="utf-8", errors="replace")
        bucket = classify(text)
        buckets[bucket].append((addr, size, cpp))

    # Count each unique address once (use the first file we found per addr,
    # but for bytes use the worst bucket — forced beats clean — so a function
    # only counts as clean if EVERY copy is clean).
    rank = {"clean": 0, "forced": 1, "non_matching": 2}
    worst_per_addr = {}
    size_per_addr = {}
    path_per_addr = {}
    for bucket, entries in buckets.items():
        for addr, size, path in entries:
            if addr not in worst_per_addr or rank[bucket] > rank[worst_per_addr[addr]]:
                worst_per_addr[addr] = bucket
                path_per_addr[addr] = path
            size_per_addr[addr] = size

    final = defaultdict(list)
    for addr, bucket in worst_per_addr.items():
        final[bucket].append((addr, size_per_addr[addr], path_per_addr[addr]))

    total_files = sum(len(v) for v in final.values())
    counts = {b: len(final[b]) for b in ("clean", "forced", "non_matching")}
    bytes_ = {b: sum(s for _, s, _ in final[b]) for b in ("clean", "forced", "non_matching")}
    matched_bytes_total = sum(bytes_.values())

    print()
    print("=" * 70)
    print("HONEST DECOMP AUDIT — src/matched/")
    print("=" * 70)
    print()
    print(f"Functions with C++ source in src/matched/: {total_files}")
    print(f"Game .text denominator (excl. SDK):        {GAME_TEXT_BYTES:,} bytes")
    print()
    print(f"  {'bucket':<14} {'files':>8} {'bytes':>14} {'% of game .text':>18}")
    print(f"  {'-'*14} {'-'*8} {'-'*14} {'-'*18}")
    for bucket in ("clean", "forced", "non_matching"):
        pct = 100.0 * bytes_[bucket] / GAME_TEXT_BYTES
        print(f"  {bucket:<14} {counts[bucket]:>8} {bytes_[bucket]:>14,} {pct:>17.2f}%")
    print(f"  {'-'*14} {'-'*8} {'-'*14} {'-'*18}")
    total_pct = 100.0 * matched_bytes_total / GAME_TEXT_BYTES
    clean_pct = 100.0 * bytes_["clean"] / GAME_TEXT_BYTES
    print(f"  {'all w/ source':<14} {total_files:>8} {matched_bytes_total:>14,} {total_pct:>17.2f}%")
    print()
    print(f"Headline: {clean_pct:.2f}% clean decomp")
    print(f"  ({bytes_['clean']:,} / {GAME_TEXT_BYTES:,} bytes; hand-written C++,")
    print(f"   no asm-processor mutation, no NON_MATCHING)")
    print()

    dup_addrs = {a: p for a, p in duplicates.items() if len(p) > 1}
    if dup_addrs:
        print(f"NOTE: {len(dup_addrs)} addresses have >1 source file in src/matched/")
        print("      (audit counts the WORST bucket per address)")
        print()
    if skipped_unknown_size:
        print(f"NOTE: {len(skipped_unknown_size)} files skipped — address not in symbols.txt")
        print()

    # Worklists — concrete backlog.
    WORKLIST_DIR.mkdir(parents=True, exist_ok=True)
    for bucket in ("clean", "forced", "non_matching"):
        out = WORKLIST_DIR / f"{bucket}.txt"
        with out.open("w", encoding="utf-8") as f:
            f.write(f"# {bucket} — {counts[bucket]} files, {bytes_[bucket]:,} bytes\n")
            f.write("# format: <addr>  <size>  <path>\n")
            for addr, size, path in sorted(final[bucket]):
                rel = path.relative_to(ROOT).as_posix()
                f.write(f"0x{addr:08X}  {size:>6}  {rel}\n")
        print(f"  wrote {out.relative_to(ROOT).as_posix()}")

    if dup_addrs:
        out = WORKLIST_DIR / "duplicates.txt"
        with out.open("w", encoding="utf-8") as f:
            f.write(f"# {len(dup_addrs)} addresses with multiple source files\n")
            for addr in sorted(dup_addrs):
                f.write(f"0x{addr:08X}\n")
                for p in sorted(dup_addrs[addr]):
                    f.write(f"    {p.relative_to(ROOT).as_posix()}\n")
        print(f"  wrote {out.relative_to(ROOT).as_posix()}")

    print()
    print("Next: pick a function from build/audit/forced.txt or non_matching.txt,")
    print("redo it as clean C++, run tools/verify_match.sh, commit.")
    print()

    # Exit code 0 always — this is a measurement, not a gate.
    return 0


if __name__ == "__main__":
    sys.exit(main())
