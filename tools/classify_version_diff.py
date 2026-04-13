#!/usr/bin/env python3
"""Classify remaining version_diff files by wall type."""

import re
import subprocess
from pathlib import Path
from collections import Counter, defaultdict

VERSION_DIFF_DIR = Path("src/wip/version_diff")

WALL_CATEGORIES = [
    "SIZE_MISMATCH",
    "REGISTER_ALLOCATION",
    "BRANCH_STRUCTURE",
    "FP_ALTERNATION",
    "FRAME_SIZE",
    "STORE_ORDER",
    "COMPILATION_ERROR",
    "SDA_R13",
    "VTABLE_SCHEDULING",
    "CTOR_EPILOGUE",
    "UNKNOWN",
    "NO_ADDRESS",
    "OTHER",
]


def extract_addr_size_from_header(text: str):
    """Extract 0xADDR and optional size from header comments."""
    # Pattern: // 0x80012345 FuncName (123b)
    m = re.search(r"0x([0-9A-Fa-f]{8})[^\(]*\((\d+)[bB]?\)", text)
    if m:
        return f"0x{m.group(1)}", int(m.group(2))
    # Pattern: // 0x80012345 (123 bytes)
    m = re.search(r"0x([0-9A-Fa-f]{8})[^\d]*?(\d+)\s*bytes?", text)
    if m:
        return f"0x{m.group(1)}", int(m.group(2))
    return None, None


def extract_addr_from_filename(name: str):
    m = re.search(r"0x([0-9A-Fa-f]{8})", name)
    if m:
        return f"0x{m.group(1)}"
    return None


def classify_from_verify_output(stderr: str, stdout: str, dol_size=None, compiled_size=None):
    """Classify wall type from verify_match.sh output."""
    combined = stderr + stdout
    
    if "error" in combined.lower() and "compile" in combined.lower():
        return "COMPILATION_ERROR"
    
    if "DOL length" in combined and "Compiled length" in combined:
        return "SIZE_MISMATCH"
    
    if dol_size is not None and compiled_size is not None and dol_size != compiled_size:
        return "SIZE_MISMATCH"
    
    # Look at mismatch details
    lines = combined.splitlines()
    
    for line in lines:
        line_lower = line.lower()
        
        if "beqlr" in line_lower or "bnelr" in line_lower or "blelr" in line_lower:
            return "BRANCH_STRUCTURE"
        
        if "blt" in line_lower and ("bne" in line_lower or "beq" in line_lower):
            return "BRANCH_STRUCTURE"
        
        if "f0" in line or "f13" in line or "fmadd" in line_lower or "fmuls" in line_lower:
            if any(x in line for x in ["f0", "f13"]):
                return "FP_ALTERNATION"
        
        if "stwu" in line_lower:
            # Frame size differences
            m1 = re.search(r"stwu\s+r1,-(0x[0-9a-f]+|\d+)\(r1\)", line_lower)
            if m1:
                return "FRAME_SIZE"
        
        if "mr " in line_lower:
            return "REGISTER_ALLOCATION"
        
        if "li " in line_lower and "addi" in line_lower:
            # Often register allocation differences in address formation
            pass
    
    # If we see store differences with same size
    if "stw" in combined.lower() and "lwz" in combined.lower():
        # Check if it's mostly store ordering
        return "STORE_ORDER"
    
    # Default: try to detect from common patterns
    if "sda21" in combined.lower() or "r13" in combined.lower() or "lis" in combined.lower():
        return "SDA_R13"
    
    if "vtable" in combined.lower():
        return "VTABLE_SCHEDULING"
    
    return "UNKNOWN"


def classify_from_content(text: str, filename: str):
    """Fallback classification from file content when verify can't run."""
    lines = text.splitlines()
    first_lines = '\n'.join(lines[:10]).lower()
    
    if "compilation error" in first_lines or "does not compile" in first_lines:
        return "COMPILATION_ERROR"
    
    if "r13" in first_lines or "sda" in first_lines:
        return "SDA_R13"
    
    if "vtable" in first_lines:
        return "VTABLE_SCHEDULING"
    
    if "schedule" in first_lines or "store order" in first_lines:
        return "STORE_ORDER"
    
    if "branch" in first_lines or "beqlr" in first_lines:
        return "BRANCH_STRUCTURE"
    
    if "size mismatch" in first_lines:
        return "SIZE_MISMATCH"
    
    # GoalUnlock files are known branch structure walls
    if "goalunlock" in filename.lower():
        return "BRANCH_STRUCTURE"
    
    # __init_hardware is SDK
    if "init_hardware" in filename.lower():
        return "OTHER"
    
    return "UNKNOWN"


def run_verify(filepath: Path, addr: str, size: int):
    """Run verify_match.sh and capture output."""
    try:
        result = subprocess.run(
            ["bash", "tools/verify_match.sh", str(filepath), addr, str(size)],
            capture_output=True,
            text=True,
            timeout=30,
        )
        return result.returncode, result.stdout, result.stderr
    except subprocess.TimeoutExpired:
        return -1, "", "TIMEOUT"
    except Exception as e:
        return -1, "", str(e)


def main():
    files = sorted(VERSION_DIFF_DIR.glob("*.cpp"))
    
    results = {cat: [] for cat in WALL_CATEGORIES}
    
    for f in files:
        try:
            text = f.read_text(errors="ignore")
        except FileNotFoundError:
            continue
        addr, size = extract_addr_size_from_header(text)
        
        if addr is None:
            addr = extract_addr_from_filename(f.name)
        
        if addr and size:
            code, stdout, stderr = run_verify(f, addr, size)
            if code == 0:
                # Unexpected match! But version_diff shouldn't have matches
                wall = "UNKNOWN"
            elif code == -1:
                wall = classify_from_content(text, f.name)
            else:
                wall = classify_from_verify_output(stderr, stdout, size, size)
                # If still unknown, try content
                if wall == "UNKNOWN":
                    wall = classify_from_content(text, f.name)
        else:
            wall = classify_from_content(text, f.name)
            if wall == "UNKNOWN":
                wall = "NO_ADDRESS"
        
        results[wall].append((f.name, addr, size))
    
    # Print summary
    print("=" * 60)
    print("VERSION_DIFF WALL CLASSIFICATION")
    print("=" * 60)
    
    total = len(files)
    for cat in WALL_CATEGORIES:
        count = len(results[cat])
        pct = count / total * 100 if total else 0
        if count > 0:
            print(f"\n{cat}: {count} files ({pct:.1f}%)")
            for name, addr, size in results[cat][:10]:
                size_str = f"{size}b" if size else "?"
                addr_str = addr or "?"
                print(f"  - {name} @ {addr_str} ({size_str})")
            if len(results[cat]) > 10:
                print(f"  ... and {len(results[cat]) - 10} more")
    
    print(f"\n{'=' * 60}")
    print(f"TOTAL: {total} files")
    
    # Save detailed results
    out_path = Path("wall_classification.json")
    import json
    with open(out_path, "w") as out:
        json.dump({k: [{"file": n, "addr": a, "size": s} for n, a, s in v] for k, v in results.items()}, out, indent=2)
    print(f"Detailed results saved to {out_path}")


if __name__ == "__main__":
    main()
