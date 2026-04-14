#!/usr/bin/env python3
"""
Full 256-512B target scan across ALL systems.
Parses DVD map, excludes already-matched functions, excludes SDK range.
Outputs grouped list to tools/all_256_512b_targets.txt
"""
import re
import json
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent
MAP_PATH = PROJECT_ROOT / "extracted/files/u2_ngc_release_dvd.map"
MATCHED_DIR = PROJECT_ROOT / "src/matched"
WIP_DIR = PROJECT_ROOT / "src/wip"
OUTPUT_PATH = PROJECT_ROOT / "tools/all_256_512b_targets.txt"
JSON_PATH = PROJECT_ROOT / "tools/all_256_512b_targets.json"

ADDR_RE = re.compile(r"0x(80[0-9A-Fa-f]{6})")

def collect_matched_addrs(directory: Path):
    matched = set()
    if not directory.exists():
        return matched
    for cpp in directory.rglob("*.cpp"):
        try:
            text = cpp.read_text(encoding="utf-8", errors="ignore")
        except OSError:
            continue
        for m in ADDR_RE.finditer(text):
            matched.add(int(m.group(1), 16))
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
            if not (256 < size <= 512):
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

def classify_system(symbol: str):
    symbol = symbol.strip()
    if "::" in symbol:
        cls = symbol.split("::")[0]
        cls = cls.split("<")[0].strip()
        if cls.startswith("{"):
            return "anonymous"
        return cls
    first = symbol.split("(")[0].split(" ")[-1].strip()
    if not first:
        return "global"
    return first

def main():
    print("Collecting matched addresses...")
    matched_addrs = collect_matched_addrs(MATCHED_DIR)
    wip_addrs = collect_matched_addrs(WIP_DIR)
    all_matched = matched_addrs | wip_addrs

    print("Parsing DVD map for size 257-512 functions...")
    entries = parse_dvd_map()
    print(f"  Total 257-512B in map (excl. SDK): {len(entries)}")

    unmatched = [(addr, size, sym) for addr, size, sym in entries if addr not in all_matched]
    print(f"  Unmatched: {len(unmatched)}")

    groups = {}
    for addr, size, sym in unmatched:
        sys = classify_system(sym)
        groups.setdefault(sys, []).append((addr, size, sym))

    sorted_groups = sorted(groups.items(), key=lambda x: (-len(x[1]), x[0]))

    lines = []
    lines.append("=" * 70)
    lines.append("FULL 257-512B TARGET SCAN — ALL SYSTEMS")
    lines.append(f"Total in map (SDK excluded): {len(entries)}")
    lines.append(f"Unmatched: {len(unmatched)}")
    lines.append("=" * 70)
    lines.append("")

    json_data = {
        "total": len(entries),
        "unmatched": len(unmatched),
        "groups": {}
    }

    for sys, funcs in sorted_groups:
        funcs_sorted = sorted(funcs, key=lambda x: x[0])
        lines.append(f"[{sys}] — {len(funcs_sorted)} functions")
        json_data["groups"][sys] = [{"addr": hex(a), "size": s, "symbol": sym} for a, s, sym in funcs_sorted]
        for addr, size, sym in funcs_sorted:
            lines.append(f"  {hex(addr)}  ({size}B)  {sym}")
        lines.append("")

    OUTPUT_PATH.write_text("\n".join(lines), encoding="utf-8")
    JSON_PATH.write_text(json.dumps(json_data, indent=2), encoding="utf-8")

    print(f"\nWrote text report to {OUTPUT_PATH}")
    print(f"Top 20 groups:")
    for sys, funcs in sorted_groups[:20]:
        print(f"  {sys}: {len(funcs)}")

if __name__ == "__main__":
    main()
