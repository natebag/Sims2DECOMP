#!/usr/bin/env python3
"""
Second round flag sweep - focus on combinations of the best flags.
"""

import json
import re
import struct
import subprocess
import sys
import os
from pathlib import Path

REPO = Path(r"F:\coding\Decompiles\Sims 2")
DEVKITPPC = Path(r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC")
CXX = DEVKITPPC / "bin" / "powerpc-eabi-g++.exe"
OBJDUMP = DEVKITPPC / "bin" / "powerpc-eabi-objdump.exe"
DOL = REPO / "extracted" / "sys" / "main.dol"
TMP_DIR = Path(r"C:\Users\SCICO\AppData\Local\Temp\flag_sweep2")


def read_dol():
    with open(DOL, "rb") as f:
        return f.read()


def get_dol_bytes(dol_data, addr, size):
    for i in range(7):
        off = struct.unpack(">I", dol_data[0x00 + i * 4 : 0x04 + i * 4])[0]
        load = struct.unpack(">I", dol_data[0x48 + i * 4 : 0x4C + i * 4])[0]
        sz = struct.unpack(">I", dol_data[0x90 + i * 4 : 0x94 + i * 4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off : file_off + size]
    return None


def get_all_funcs_from_obj(obj_path):
    result = subprocess.run(
        [str(OBJDUMP), "-d", str(obj_path)],
        capture_output=True, text=True, timeout=30
    )
    all_funcs = []
    current_name = None
    current_bytes = bytearray()
    for line in result.stdout.split("\n"):
        fm = re.match(r"^[0-9a-f]+ <(.+)>:", line)
        if fm:
            if current_name and current_bytes:
                all_funcs.append((current_name, bytes(current_bytes)))
            current_name = fm.group(1)
            current_bytes = bytearray()
            continue
        bm = re.match(r"\s*[0-9a-f]+:\s+((?:[0-9a-f]{2} )+)", line)
        if bm and current_name:
            for b in bm.group(1).strip().split():
                current_bytes.append(int(b, 16))
    if current_name and current_bytes:
        all_funcs.append((current_name, bytes(current_bytes)))
    return all_funcs


def parse_source_files():
    matched_dir = REPO / "src" / "matched"
    src_files = {}
    for src_file in sorted(matched_dir.glob("*.cpp")):
        with open(src_file, "r") as f:
            content = f.read()
        func_specs = []
        in_if0 = 0
        pending = None
        for line in content.split("\n"):
            s = line.strip()
            if s == "#if 0":
                in_if0 += 1
                pending = None
                continue
            elif s == "#endif" and in_if0 > 0:
                in_if0 -= 1
                continue
            if in_if0 > 0:
                continue
            m = re.match(r"// 0x([0-9A-Fa-f]+)\s+\((\d+) bytes\)", s)
            if m:
                pending = (int(m.group(1), 16), int(m.group(2)))
                continue
            if pending and "::" in s and "{" in s and not s.startswith("//"):
                func_specs.append(pending)
                pending = None
            elif s and not s.startswith("//") and not s.startswith("#"):
                pending = None
        if func_specs:
            src_files[src_file] = func_specs
    return src_files


def count_matches(dol_data, flag_string, src_files):
    os.makedirs(TMP_DIR, exist_ok=True)
    inc_dirs = [
        str(REPO / "include"), str(REPO / "src"),
        str(REPO / "libs" / "dolphinsdk"),
        str(REPO / "libs" / "sn_runtime"),
        str(REPO / "libs" / "apt"),
    ]
    includes = [f"-I{d}" for d in inc_dirs]
    defines = ["-DNDEBUG", "-DEA_PLATFORM_GAMECUBE=1", "-DGEKKO"]

    total = 0
    matches = 0
    same_diff = 0

    for src_file, func_specs in src_files.items():
        obj_file = TMP_DIR / (src_file.stem + ".o")
        cmd = [str(CXX)] + flag_string.split() + includes + defines + [
            "-c", str(src_file), "-o", str(obj_file)
        ]
        result = subprocess.run(cmd, capture_output=True, timeout=30)
        if result.returncode != 0:
            continue

        all_compiled = get_all_funcs_from_obj(obj_file)
        compiled_by_size = {}
        for name, fbytes in all_compiled:
            sz = len(fbytes)
            if sz not in compiled_by_size:
                compiled_by_size[sz] = []
            compiled_by_size[sz].append((name, fbytes))

        used = set()
        func_idx = 0

        for addr, size in func_specs:
            orig_bytes = get_dol_bytes(dol_data, addr, size)
            if orig_bytes is None:
                continue
            our_bytes = None
            if size in compiled_by_size:
                for cname, cbytes in compiled_by_size[size]:
                    if cname not in used:
                        our_bytes = cbytes
                        used.add(cname)
                        break
            if our_bytes is None and func_idx < len(all_compiled):
                cname, cbytes = all_compiled[func_idx]
                if cname not in used:
                    our_bytes = cbytes
                    used.add(cname)
            func_idx += 1
            total += 1
            if our_bytes and our_bytes == orig_bytes:
                matches += 1
            elif our_bytes and len(our_bytes) == size:
                same_diff += 1

    return total, matches, same_diff


def main():
    dol_data = read_dol()
    src_files = parse_source_files()
    total_funcs = sum(len(v) for v in src_files.values())
    print(f"Parsed {len(src_files)} source files with {total_funcs} functions")
    print()

    base = "-mcpu=750 -meabi -mhard-float -fno-exceptions -fno-rtti -fno-builtin -fshort-wchar -nostdinc++ -fpermissive -Wno-return-type"

    combos = [
        # Best from round 1
        ("BEST: O2+nosched+noinline", f"{base} -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions"),
        # Try O2 with just no-inline (no no-sched)
        ("O2+noinline only", f"{base} -O2 -fno-inline -fno-inline-small-functions"),
        # O2 + nosched + noinline + other promising combos
        ("O2+nosched+noinline+noreorder", f"{base} -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions -fno-reorder-blocks -fno-reorder-functions"),
        ("O2+nosched+noinline+omitfp", f"{base} -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions -fomit-frame-pointer"),
        ("O2+nosched+noinline+nosibling", f"{base} -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions -fno-optimize-sibling-calls"),
        ("O2+nosched+noinline+nocrossjump", f"{base} -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions -fno-crossjumping"),
        ("O2+nosched+noinline+noifconv", f"{base} -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions -fno-if-conversion -fno-if-conversion2"),
        ("O2+nosched+noinline+allneg", f"{base} -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions -fno-crossjumping -fno-if-conversion -fno-if-conversion2 -fno-optimize-sibling-calls -fno-reorder-blocks"),
        # Try freg-struct-return
        ("O2+nosched+noinline+regstruct", f"{base} -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions -freg-struct-return"),
        # Try -fno-tree-* options
        ("O2+nosched+noinline+notree", f"{base} -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions -fno-tree-fre -fno-tree-pre"),
        ("O2+nosched+noinline+nocombine", f"{base} -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions -fno-combine-stack-adjustments"),
        # O1 + noinline
        ("O1+noinline", f"{base} -O1 -fno-inline -fno-inline-small-functions"),
        ("O1+nosched+noinline", f"{base} -O1 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions"),
        # Try -fno-strict-aliasing
        ("O2+nosched+noinline+nostrict", f"{base} -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions -fno-strict-aliasing"),
        # Try -fno-caller-saves
        ("O2+nosched+noinline+nocallersaves", f"{base} -O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline -fno-inline-small-functions -fno-caller-saves"),
    ]

    results = []
    for name, flags in combos:
        sys.stdout.write(f"  Testing: {name}... ")
        sys.stdout.flush()
        total, match, sd = count_matches(dol_data, flags, src_files)
        pct = match * 100.0 / total if total else 0
        print(f"{match}/{total} ({pct:.1f}%) match, {sd} same-size-diff")
        results.append((name, flags, total, match, sd, pct))

    print()
    print(f"{'='*70}")
    print(f"ROUND 2 RESULTS SORTED BY MATCH COUNT")
    print(f"{'='*70}")
    for name, flags, total, match, sd, pct in sorted(results, key=lambda x: -x[3]):
        print(f"  {match:4d}/{total} ({pct:5.1f}%) [{sd:4d} same-sz-diff] {name}")


if __name__ == "__main__":
    main()
