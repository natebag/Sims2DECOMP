#!/usr/bin/env python3
"""
Sims 2 GameCube -- Batch disassemble functions by size range.

Disassembles all functions in a given byte-size range, groups them by
instruction pattern, and produces a report. Useful for identifying trivial
functions that can be auto-matched.

Usage:
    python tools/batch_disasm.py --min-size 4 --max-size 16
    python tools/batch_disasm.py --min-size 4 --max-size 4          # blr-only
    python tools/batch_disasm.py --min-size 4 --max-size 8 --show   # print each
    python tools/batch_disasm.py --min-size 4 --max-size 16 --top 20
"""

import argparse
import json
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve().parent
ROOT_DIR = SCRIPT_DIR.parent

OBJDUMP = Path("F:/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe")
ORIGINAL_ELF = ROOT_DIR / "extracted" / "files" / "u2_ngc_release_dvd.elf"
SYMBOLS_JSON = SCRIPT_DIR / "symbols.json"

CODE_SECTIONS = {".text", ".init"}

# Pattern for objdump instruction lines
INSN_RE = re.compile(
    r"^\s*([0-9a-f]+):\s+"
    r"((?:[0-9a-f]{2} )+)\s*"
    r"(\S+)"
    r"(?:\s+(.*))?$"
)


def load_functions(min_size, max_size):
    """Load function symbols in the given size range from code sections."""
    with open(SYMBOLS_JSON, "r") as f:
        data = json.load(f)

    funcs = []
    for s in data["symbols"]:
        if (s["type"] == "function"
                and s.get("name")
                and s.get("section") in CODE_SECTIONS
                and min_size <= s["size"] <= max_size):
            funcs.append(s)

    funcs.sort(key=lambda f: int(f["address"], 16))
    return funcs


def disassemble_batch(funcs, batch_size=256):
    """Disassemble functions in batches for efficiency.

    Groups nearby functions and runs fewer objdump invocations.
    Returns dict mapping (address, name) -> list of (mnemonic, operands).
    """
    results = {}

    if not funcs:
        return results

    # Sort by address for batching
    sorted_funcs = sorted(funcs, key=lambda f: int(f["address"], 16))

    # Group into contiguous ranges
    batches = []
    current_batch = [sorted_funcs[0]]

    for func in sorted_funcs[1:]:
        prev = current_batch[-1]
        prev_end = int(prev["address"], 16) + prev["size"]
        curr_start = int(func["address"], 16)

        # If gap is small (< 4KB), keep in same batch
        if curr_start - prev_end < 4096 and len(current_batch) < batch_size:
            current_batch.append(func)
        else:
            batches.append(current_batch)
            current_batch = [func]
    batches.append(current_batch)

    total = len(sorted_funcs)
    done = 0

    for batch in batches:
        batch_start = int(batch[0]["address"], 16)
        last = batch[-1]
        batch_end = int(last["address"], 16) + last["size"]
        section = batch[0]["section"]

        cmd = [
            str(OBJDUMP), "-d",
            f"--start-address=0x{batch_start:08X}",
            f"--stop-address=0x{batch_end:08X}",
        ]
        if section in CODE_SECTIONS:
            cmd.extend(["-j", section])
        cmd.append(str(ORIGINAL_ELF))

        try:
            result = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
        except subprocess.TimeoutExpired:
            print(f"  Warning: objdump timed out for batch 0x{batch_start:08X}-0x{batch_end:08X}",
                  file=sys.stderr)
            continue

        # Parse all instructions from this batch
        all_insns = {}
        for line in result.stdout.split("\n"):
            m = INSN_RE.match(line)
            if m:
                addr = int(m.group(1), 16)
                mnemonic = m.group(3)
                operands = m.group(4).strip() if m.group(4) else ""
                all_insns[addr] = (mnemonic, operands)

        # Extract instructions for each function in the batch
        for func in batch:
            func_addr = int(func["address"], 16)
            func_size = func["size"]
            func_insns = []
            for offset in range(0, func_size, 4):
                insn_addr = func_addr + offset
                if insn_addr in all_insns:
                    func_insns.append(all_insns[insn_addr])
                else:
                    func_insns.append(("???", ""))
            results[(func_addr, func["name"])] = func_insns

        done += len(batch)
        if total > 100:
            pct = done * 100 // total
            print(f"\r  Disassembling... {done}/{total} ({pct}%)", end="", file=sys.stderr)

    if total > 100:
        print(file=sys.stderr)

    return results


def classify_pattern(insns):
    """Classify an instruction sequence into a human-readable pattern.

    Returns (pattern_name, pattern_detail) tuple.
    """
    mnemonics = [m for m, _ in insns]
    full = [(m, op) for m, op in insns]

    n = len(mnemonics)

    # 1 instruction patterns
    if n == 1:
        if mnemonics[0] == "blr":
            return "blr_only", "blr (empty function)"
        return f"single_{mnemonics[0]}", f"{mnemonics[0]} {full[0][1]}"

    # 2 instruction patterns (8 bytes)
    if n == 2 and mnemonics[-1] == "blr":
        m, op = full[0]
        if m == "li" and op.startswith("r3,"):
            return "li_r3_blr", f"return constant (li r3,N; blr)"
        if m == "lwz" and op.startswith("r3,"):
            return "lwz_r3_blr", f"getter: lwz r3,offset; blr"
        if m == "lhz" and op.startswith("r3,"):
            return "lhz_r3_blr", f"getter (short): lhz r3,offset; blr"
        if m == "lbz" and op.startswith("r3,"):
            return "lbz_r3_blr", f"getter (byte): lbz r3,offset; blr"
        if m == "lfs" and op.startswith("f1,"):
            return "lfs_f1_blr", f"getter (float): lfs f1,offset; blr"
        if m == "lfd" and op.startswith("f1,"):
            return "lfd_f1_blr", f"getter (double): lfd f1,offset; blr"
        if m == "stw" and op.startswith("r4,"):
            return "stw_r4_blr", f"setter: stw r4,offset; blr"
        if m == "sth" and op.startswith("r4,"):
            return "sth_r4_blr", f"setter (short): sth r4,offset; blr"
        if m == "stb" and op.startswith("r4,"):
            return "stb_r4_blr", f"setter (byte): stb r4,offset; blr"
        if m == "stfs" and op.startswith("f1,"):
            return "stfs_f1_blr", f"setter (float): stfs f1,offset; blr"
        if m == "stfd" and op.startswith("f1,"):
            return "stfd_f1_blr", f"setter (double): stfd f1,offset; blr"
        if m == "mr" and op.startswith("r3,"):
            return "mr_r3_blr", f"return param: mr r3,rN; blr"
        if m == "mr":
            return "mr_blr", f"move reg: {op}; blr"
        if m == "stw":
            return "stw_blr", f"store word: {m} {op}; blr"
        if m == "stb":
            return "stb_blr", f"store byte: {m} {op}; blr"
        return f"{m}_blr", f"{m} {op}; blr"

    # 3 instruction patterns (12 bytes)
    if n == 3 and mnemonics[-1] == "blr":
        m0, op0 = full[0]
        m1, op1 = full[1]

        # lis + ori + blr -> return 32-bit constant
        if m0 == "lis" and m1 == "ori" and op0.startswith("r3,") and op1.startswith("r3,"):
            return "lis_ori_r3_blr", "return 32-bit constant"

        # lwz + lwz + blr -> double deref getter
        if m0 == "lwz" and m1 == "lwz" and op1.startswith("r3,"):
            return "lwz_lwz_blr", "double-deref getter"

        # stw + stw + blr -> double store
        if m0 == "stw" and m1 == "stw":
            return "stw_stw_blr", "double store setter"

        # li + stw + blr or li + stb + blr -> store constant
        if m0 == "li" and m1 in ("stw", "stb", "sth"):
            return f"li_{m1}_blr", f"store constant: {m0} {op0}; {m1} {op1}; blr"

        # lwz + field access + blr
        if m1.startswith("l") and op1.startswith("r3,"):
            return f"{m0}_{m1}_blr", f"chained getter: {m0} {op0}; {m1} {op1}; blr"

        return f"{m0}_{m1}_blr", f"{m0} {op0}; {m1} {op1}; blr"

    # 4 instruction patterns (16 bytes)
    if n == 4 and mnemonics[-1] == "blr":
        joined = "_".join(mnemonics[:-1])
        desc = "; ".join(f"{m} {op}" for m, op in full[:-1]) + "; blr"
        return f"{joined}_blr", desc

    # Generic: just join mnemonics
    joined = "_".join(mnemonics)
    return joined, "; ".join(f"{m} {op}" for m, op in full)


def main():
    parser = argparse.ArgumentParser(
        description="Batch disassemble functions by size range"
    )
    parser.add_argument("--min-size", type=int, default=4,
                        help="Minimum function size in bytes (default: 4)")
    parser.add_argument("--max-size", type=int, default=16,
                        help="Maximum function size in bytes (default: 16)")
    parser.add_argument("--top", type=int, default=15,
                        help="Show top N patterns (default: 15)")
    parser.add_argument("--show", action="store_true",
                        help="Show each function's disassembly")
    parser.add_argument("--pattern", metavar="PAT",
                        help="Only show functions matching this pattern name")
    parser.add_argument("--section", default=None,
                        help="Filter to specific section (e.g., .text)")
    args = parser.parse_args()

    print(f"Loading functions with size {args.min_size}-{args.max_size} bytes...")
    funcs = load_functions(args.min_size, args.max_size)

    if args.section:
        funcs = [f for f in funcs if f["section"] == args.section]

    print(f"Found {len(funcs)} functions in code sections")

    if not funcs:
        return

    print(f"Disassembling...")
    results = disassemble_batch(funcs)

    # Classify each function
    patterns = defaultdict(list)
    for (addr, name), insns in results.items():
        pat_name, pat_desc = classify_pattern(insns)
        size = len(insns) * 4
        patterns[pat_name].append({
            "name": name,
            "address": addr,
            "size": size,
            "insns": insns,
            "pattern_desc": pat_desc,
        })

    # Sort patterns by count
    sorted_patterns = sorted(patterns.items(), key=lambda x: -len(x[1]))

    # Report
    print(f"\n{'=' * 72}")
    print(f"  Pattern Report: {args.min_size}-{args.max_size} byte functions")
    print(f"  Total functions: {len(results)}")
    print(f"  Unique patterns: {len(patterns)}")
    print(f"{'=' * 72}\n")

    shown = 0
    for pat_name, funcs_in_pat in sorted_patterns:
        if args.pattern and args.pattern not in pat_name:
            continue
        if shown >= args.top and not args.pattern:
            break
        shown += 1

        desc = funcs_in_pat[0]["pattern_desc"]
        count = len(funcs_in_pat)
        total_bytes = sum(f["size"] for f in funcs_in_pat)

        print(f"  Pattern: {pat_name}")
        print(f"  Description: {desc}")
        print(f"  Count: {count} functions ({total_bytes} bytes)")

        if args.show:
            for f in funcs_in_pat[:20]:
                insn_str = "; ".join(f"{m} {op}" for m, op in f["insns"])
                print(f"    0x{f['address']:08X}  {f['name']}")
                print(f"      {insn_str}")
            if len(funcs_in_pat) > 20:
                print(f"    ... and {len(funcs_in_pat) - 20} more")
        else:
            # Show a few examples
            for f in funcs_in_pat[:3]:
                print(f"    0x{f['address']:08X}  {f['name']}")
            if len(funcs_in_pat) > 3:
                print(f"    ... and {len(funcs_in_pat) - 3} more")

        print()

    # Summary of remaining patterns
    remaining = sorted_patterns[args.top:] if not args.pattern else []
    if remaining:
        print(f"  ... plus {len(remaining)} more patterns with fewer occurrences")
        rem_funcs = sum(len(fl) for _, fl in remaining)
        print(f"      ({rem_funcs} additional functions)")
        print()

    # C++ mapping summary
    print(f"{'=' * 72}")
    print(f"  C++ Code Mapping Summary")
    print(f"{'=' * 72}")

    mappable = {
        "blr_only": "void Func() { }",
        "li_r3_blr": "int Func() { return N; }",
        "lwz_r3_blr": "Type* Func() { return this->field; }  (or global getter)",
        "lhz_r3_blr": "short Func() { return this->field; }",
        "lbz_r3_blr": "char/bool Func() { return this->field; }",
        "lfs_f1_blr": "float Func() { return this->field; }",
        "lfd_f1_blr": "double Func() { return this->field; }",
        "stw_r4_blr": "void Func(int val) { this->field = val; }",
        "sth_r4_blr": "void Func(short val) { this->field = val; }",
        "stb_r4_blr": "void Func(char val) { this->field = val; }",
        "stfs_f1_blr": "void Func(float val) { this->field = val; }",
        "stfd_f1_blr": "void Func(double val) { this->field = val; }",
        "mr_r3_blr": "Type Func(Type val) { return val; }  (passthrough)",
        "lis_ori_r3_blr": "Type* Func() { return &global; }  (32-bit addr)",
    }

    auto_count = 0
    auto_bytes = 0
    for pat_name, funcs_in_pat in sorted_patterns:
        if pat_name in mappable:
            count = len(funcs_in_pat)
            total_bytes = sum(f["size"] for f in funcs_in_pat)
            auto_count += count
            auto_bytes += total_bytes
            print(f"  {pat_name:<20s} ({count:>4} funcs) -> {mappable[pat_name]}")

    print(f"\n  Auto-matchable: {auto_count} functions ({auto_bytes} bytes)")
    not_auto = len(results) - auto_count
    print(f"  Needs manual:   {not_auto} functions")
    print()


if __name__ == "__main__":
    main()
