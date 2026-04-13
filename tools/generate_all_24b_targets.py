#!/usr/bin/env python3
"""
Full 24B target scan across ALL systems.
Parses DVD map, excludes already-matched functions, excludes SDK range.
Outputs grouped list to tools/all_24b_targets.txt
"""
import re
import json
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent
MAP_PATH = PROJECT_ROOT / "extracted/files/u2_ngc_release_dvd.map"
MATCHED_DIR = PROJECT_ROOT / "src/matched"
WIP_DIR = PROJECT_ROOT / "src/wip"
OUTPUT_PATH = PROJECT_ROOT / "tools/all_24b_targets.txt"
JSON_PATH = PROJECT_ROOT / "tools/all_24b_targets.json"

# Regex to extract hex addresses from C++ comments
ADDR_RE = re.compile(r"0x(80[0-9A-Fa-f]{6})")

def collect_matched_addrs(directory: Path):
    matched = set()
    if not directory.exists():
        return matched
    for cpp in directory.rglob("*.cpp"):
        text = cpp.read_text(encoding="utf-8", errors="ignore")
        for m in ADDR_RE.finditer(text):
            matched.add(int(m.group(1), 16))
    return matched

def is_file_path(text: str) -> bool:
    """Heuristic: Windows paths contain backslashes or specific obj/lib extensions."""
    return "\\" in text or "/" in text or ".obj" in text or ".a(" in text or ".lib(" in text or text.endswith(".o)")

def parse_dvd_map():
    entries = []
    with MAP_PATH.open("r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            line = line.rstrip("\n")
            if not line.strip() or line.startswith("=") or line.startswith("Address"):
                continue
            # Split into max 4 parts: address, size, align, rest
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
            if size != 24:
                continue
            addr = int(addr_str, 16)
            # Exclude SDK range: 0x80240000 - 0x8039FFFF
            if 0x80240000 <= addr <= 0x8039FFFF:
                continue
            # Skip if rest looks like a file path or section name
            if is_file_path(rest):
                continue
            if rest.startswith("."):
                # Section names like .text, .init, etc.
                continue
            symbol = rest.strip()
            # Skip non-function symbols (virtual tables, data tables, globals, etc.)
            low = symbol.lower()
            if "virtual table" in low:
                continue
            # Actual functions in the map almost always contain `(` from demangling.
            # Filter out data symbols like gFoo, sBar, kBaz, IconNames, etc.
            if "(" not in symbol:
                continue
            entries.append((addr, symbol))
    return entries

def classify_system(symbol: str):
    """Group by class name or system prefix."""
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
    print(f"  Matched in src/matched: {len(matched_addrs)}")
    print(f"  Matched in src/wip: {len(wip_addrs)}")
    print(f"  Total matched: {len(all_matched)}")

    print("Parsing DVD map for size-24 functions...")
    entries = parse_dvd_map()
    print(f"  Total size-24 entries in map (excl. SDK): {len(entries)}")

    unmatched = [(addr, sym) for addr, sym in entries if addr not in all_matched]
    print(f"  Unmatched: {len(unmatched)}")

    # Group by system
    groups = {}
    for addr, sym in unmatched:
        sys = classify_system(sym)
        groups.setdefault(sys, []).append((addr, sym))

    # Sort groups by count desc, then entries by address
    sorted_groups = sorted(groups.items(), key=lambda x: (-len(x[1]), x[0]))

    lines = []
    lines.append("=" * 70)
    lines.append("FULL 24B TARGET SCAN — ALL SYSTEMS")
    lines.append(f"Map: {MAP_PATH.name}")
    lines.append(f"Total size-24 functions in map (SDK excluded): {len(entries)}")
    lines.append(f"Already matched (src/matched + src/wip): {len(all_matched)}")
    lines.append(f"UNMATCHED 24B TARGETS: {len(unmatched)}")
    lines.append("=" * 70)
    lines.append("")

    json_data = {
        "total_24b_in_map": len(entries),
        "matched_count": len(all_matched),
        "unmatched_count": len(unmatched),
        "groups": {}
    }

    for sys, funcs in sorted_groups:
        funcs_sorted = sorted(funcs, key=lambda x: x[0])
        lines.append(f"[{sys}] — {len(funcs_sorted)} functions")
        json_data["groups"][sys] = [{"addr": hex(a), "symbol": s} for a, s in funcs_sorted]
        for addr, sym in funcs_sorted:
            lines.append(f"  {hex(addr)}  {sym}")
        lines.append("")

    OUTPUT_PATH.write_text("\n".join(lines), encoding="utf-8")
    JSON_PATH.write_text(json.dumps(json_data, indent=2), encoding="utf-8")

    print(f"\nWrote text report to {OUTPUT_PATH}")
    print(f"Wrote JSON data to {JSON_PATH}")
    print(f"Top 20 groups by count:")
    for sys, funcs in sorted_groups[:20]:
        print(f"  {sys}: {len(funcs)}")

if __name__ == "__main__":
    main()
