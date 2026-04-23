#!/usr/bin/env python3
"""
Case-insensitive filename-based collision check for 64-128B unmatched functions.
Fixes the content-only regex miss in generate_all_64_128b_targets.py.
"""
import re
import os
from pathlib import Path
from collections import defaultdict

PROJECT_ROOT = Path(__file__).parent.parent
MAP_PATH = PROJECT_ROOT / "extracted/files/u2_ngc_release_dvd.map"

def collect_matched_hex_tokens():
    """Scan src/matched and src/wip for any filename containing a hex address token."""
    matched = set()
    ADDR_IN_NAME = re.compile(r"(?:0x)?([0-9a-fA-F]{8})")
    for root in ["src/matched", "src/wip"]:
        root_path = PROJECT_ROOT / root
        if not root_path.exists():
            continue
        for fn in root_path.rglob("*.cpp"):
            name = fn.name
            for tok in ADDR_IN_NAME.findall(name):
                try:
                    v = int(tok, 16)
                    if 0x80000000 <= v < 0x80800000:
                        matched.add(v)
                except ValueError:
                    pass
            # also content
            try:
                text = fn.read_text(encoding="utf-8", errors="ignore")
                for m in re.finditer(r"0x(80[0-9a-fA-F]{6})", text):
                    matched.add(int(m.group(1), 16))
            except OSError:
                pass
    return matched

def parse_dvd_map():
    entries = []
    with MAP_PATH.open("r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            line = line.rstrip("\n")
            if not line.strip() or line.startswith("=") or line.startswith("Address"):
                continue
            parts = line.split(None, 3)
            if len(parts) < 4:
                continue
            addr_str, size_str, align_str, rest = parts
            if not re.match(r"^80[0-9A-Fa-f]{6}$", addr_str):
                continue
            try:
                size = int(size_str, 16)
            except ValueError:
                continue
            if not (64 <= size <= 128):
                continue
            addr = int(addr_str, 16)
            if 0x80240000 <= addr <= 0x8039FFFF:
                continue
            symbol = rest.strip()
            if ".obj)" in symbol or ".a(" in symbol or ".lib(" in symbol or symbol.startswith("c:\\") or symbol.startswith("C:\\"):
                continue
            if "(" not in symbol:
                continue
            entries.append((addr, size, symbol))
    return entries

def classify(symbol):
    if "::" in symbol:
        cls = symbol.split("::")[0].split("<")[0].strip()
        return cls if cls and not cls.startswith("{") else "anonymous"
    first = symbol.split("(")[0].split(" ")[-1].strip()
    return first or "global"

def main():
    matched = collect_matched_hex_tokens()
    print(f"Matched addrs (filename + content): {len(matched)}")
    entries = parse_dvd_map()
    unmatched = [(a, sz, s) for (a, sz, s) in entries if a not in matched]
    print(f"Total 64-128B entries in map: {len(entries)}")
    print(f"Unmatched: {len(unmatched)}")

    grouped = defaultdict(list)
    for a, sz, s in unmatched:
        grouped[classify(s)].append((a, sz, s))

    # Top 30 groups by count
    top = sorted(grouped.items(), key=lambda kv: -len(kv[1]))[:30]
    print("\nTop 30 groups by unmatched count:")
    for cls, items in top:
        print(f"  {cls}: {len(items)}")

    outpath = PROJECT_ROOT / "tools/unmatched_64_128b_real.txt"
    with outpath.open("w", encoding="utf-8") as f:
        f.write(f"# Real unmatched 64-128B (filename+content collision-checked)\n")
        f.write(f"# Total: {len(unmatched)}\n\n")
        for cls, items in sorted(grouped.items(), key=lambda kv: -len(kv[1])):
            f.write(f"[{cls}] — {len(items)} functions\n")
            for a, sz, s in sorted(items):
                f.write(f"  0x{a:08x}  {sz:3d}B  {s}\n")
            f.write("\n")
    print(f"\nWrote {outpath}")

if __name__ == "__main__":
    main()
