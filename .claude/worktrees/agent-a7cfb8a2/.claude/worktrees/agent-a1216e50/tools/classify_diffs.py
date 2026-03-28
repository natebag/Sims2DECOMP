#!/usr/bin/env python3
"""Classify all same-size-diff functions by their diff pattern."""

import re
import struct
import subprocess
from pathlib import Path
from collections import Counter

REPO = Path(r"F:\coding\Decompiles\Sims 2")
DEVKITPPC = Path(r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC")
OBJDUMP = str(DEVKITPPC / "bin" / "powerpc-eabi-objdump.exe")
DOL = REPO / "extracted" / "sys" / "main.dol"


def read_dol():
    with open(DOL, "rb") as f:
        return f.read()


def get_dol_bytes(dol_data, addr, size):
    for i in range(7):
        off = struct.unpack(">I", dol_data[0x00 + i * 4:0x04 + i * 4])[0]
        load = struct.unpack(">I", dol_data[0x48 + i * 4:0x4C + i * 4])[0]
        sz = struct.unpack(">I", dol_data[0x90 + i * 4:0x94 + i * 4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off:file_off + size]
    return None


def get_all_funcs_from_obj(obj_path):
    result = subprocess.run(
        [OBJDUMP, "-d", str(obj_path)],
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


def main():
    dol_data = read_dol()
    matched_dir = REPO / "src" / "matched"
    obj_dir = REPO / "build" / "obj" / "matched"

    all_diffs = []
    pattern_counts = Counter()

    for src_file in sorted(matched_dir.glob("*.cpp")):
        with open(src_file, "r") as f:
            content = f.read()
        obj_file = obj_dir / (src_file.stem + ".o")
        if not obj_file.exists():
            continue

        all_compiled = get_all_funcs_from_obj(obj_file)
        compiled_by_size = {}
        for name, fbytes in all_compiled:
            sz = len(fbytes)
            if sz not in compiled_by_size:
                compiled_by_size[sz] = []
            compiled_by_size[sz].append((name, fbytes))

        used_compiled = set()
        in_if0 = 0
        lines = content.split("\n")
        pending = None
        func_index = 0

        for line_idx, line in enumerate(lines):
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
                addr, size = pending
                orig_bytes = get_dol_bytes(dol_data, addr, size)
                pending = None
                if orig_bytes is None:
                    func_index += 1
                    continue

                our_bytes = None
                our_name = "?"
                if size in compiled_by_size:
                    for cname, cbytes in compiled_by_size[size]:
                        if cname not in used_compiled:
                            our_bytes = cbytes
                            our_name = cname
                            used_compiled.add(cname)
                            break

                if our_bytes is None and func_index < len(all_compiled):
                    cname, cbytes = all_compiled[func_index]
                    if cname not in used_compiled:
                        our_bytes = cbytes
                        our_name = cname
                        used_compiled.add(cname)

                func_index += 1

                if our_bytes and len(our_bytes) == size and our_bytes != orig_bytes:
                    diffs = []
                    for j in range(0, min(len(our_bytes), len(orig_bytes)), 4):
                        our_word = int.from_bytes(our_bytes[j:j + 4], "big")
                        orig_word = int.from_bytes(orig_bytes[j:j + 4], "big")
                        if our_word != orig_word:
                            our_opcode = (our_word >> 26) & 0x3F
                            orig_opcode = (orig_word >> 26) & 0x3F
                            our_rD = (our_word >> 21) & 0x1F
                            orig_rD = (orig_word >> 21) & 0x1F
                            our_rA = (our_word >> 16) & 0x1F
                            orig_rA = (orig_word >> 16) & 0x1F
                            diffs.append({
                                "offset": j,
                                "our_word": our_word,
                                "orig_word": orig_word,
                                "our_opcode": our_opcode,
                                "orig_opcode": orig_opcode,
                                "our_rD": our_rD,
                                "orig_rD": orig_rD,
                                "our_rA": our_rA,
                                "orig_rA": orig_rA,
                            })

                    diff_count = len(diffs)

                    # Check: GCC uses r9 where SN uses r0 (our=r9, orig=r0)
                    gcc_r9_sn_r0 = all(
                        d["our_opcode"] == d["orig_opcode"]
                        and d["our_rD"] == 9
                        and d["orig_rD"] == 0
                        for d in diffs
                    )

                    # Check: SN uses r0, GCC uses r9 in load/store/li type
                    li_stw_ops = {14, 32, 36, 38, 40, 42, 44, 48, 50, 52, 54}
                    gcc_r9_sn_r0_li_stw = gcc_r9_sn_r0 and all(
                        d["our_opcode"] in li_stw_ops for d in diffs
                    )

                    # Check for addis r9->r3 pattern (GCC: lis r9, SN: lis r3)
                    addis_r9_r3 = all(
                        d["our_opcode"] == d["orig_opcode"]
                        and d["our_opcode"] == 15
                        and d["our_rD"] == 9
                        and d["orig_rD"] == 3
                        for d in diffs
                    )

                    # Mixed r0/r9 patterns
                    all_same_opcode = all(d["our_opcode"] == d["orig_opcode"] for d in diffs)
                    all_reg_only = all_same_opcode and all(
                        (d["our_word"] ^ d["orig_word"]) & 0xFFFF == 0
                        or d["our_opcode"] in li_stw_ops
                        for d in diffs
                    )

                    if gcc_r9_sn_r0_li_stw:
                        pattern = "r9_to_r0_li_stw"
                    elif gcc_r9_sn_r0:
                        pattern = "r9_to_r0_other"
                    elif addis_r9_r3:
                        pattern = "addis_r9_to_r3"
                    elif all_same_opcode and diff_count == 1:
                        d = diffs[0]
                        pattern = f"single_reg_op{d['orig_opcode']}_r{d['our_rD']}->r{d['orig_rD']}"
                    elif all_same_opcode:
                        pattern = f"multi_reg_{diff_count}diffs"
                    else:
                        pattern = f"opcode_diff_{diff_count}diffs"

                    pattern_counts[pattern] += 1

                    all_diffs.append({
                        "addr": addr,
                        "size": size,
                        "name": our_name,
                        "src_file": src_file.name,
                        "src_line": line_idx + 1,
                        "src_text": s[:120],
                        "diff_count": diff_count,
                        "pattern": pattern,
                        "diffs": diffs,
                    })

            elif s and not s.startswith("//") and not s.startswith("#"):
                pending = None

    print(f"Total same-size-diff functions: {len(all_diffs)}")
    print()
    print("=== Pattern classification ===")
    for pat, cnt in pattern_counts.most_common():
        print(f"  {cnt:4d}  {pat}")

    # Count fixable
    fixable_r0 = [f for f in all_diffs if f["pattern"] == "r9_to_r0_li_stw"]
    print(f"\nFunctions fixable with r0 asm trick (li/stw r9->r0): {len(fixable_r0)}")

    print("\n=== r9_to_r0_li_stw examples ===")
    for f in fixable_r0[:20]:
        print(f"  {f['src_file']}:{f['src_line']}  0x{f['addr']:08X} ({f['size']}B) {f['diff_count']} diffs")
        print(f"    {f['src_text'][:100]}")

    # Show opcode_diff examples
    opcode_diffs = [f for f in all_diffs if "opcode_diff" in f["pattern"]]
    if opcode_diffs:
        print(f"\n=== opcode_diff examples (first 10) ===")
        for f in opcode_diffs[:10]:
            print(f"  {f['src_file']}:{f['src_line']}  0x{f['addr']:08X} ({f['size']}B) {f['pattern']}")
            for d in f["diffs"][:3]:
                print(f"    instr@{d['offset']}: ours={d['our_word']:08X} (op{d['our_opcode']}) orig={d['orig_word']:08X} (op{d['orig_opcode']})")
            print(f"    {f['src_text'][:100]}")


if __name__ == "__main__":
    main()
