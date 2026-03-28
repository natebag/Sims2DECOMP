#!/usr/bin/env python3
"""Analyze the opcode_diff functions to find fixable sub-patterns."""

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


def decode_instr(word):
    opcode = (word >> 26) & 0x3F
    rD = (word >> 21) & 0x1F
    rA = (word >> 16) & 0x1F
    rB = (word >> 11) & 0x1F
    d = word & 0xFFFF
    if d > 0x7FFF:
        d -= 0x10000

    load_store_ops = {
        32: "lwz", 34: "lbz", 36: "stw", 38: "stb",
        40: "lhz", 42: "lha", 44: "sth",
        48: "lfs", 50: "lfd", 52: "stfs", 54: "stfd",
    }

    if opcode in load_store_ops:
        return f"{load_store_ops[opcode]} r{rD},{d}(r{rA})"
    elif opcode == 14:
        if rA == 0:
            return f"li r{rD},{d}"
        return f"addi r{rD},r{rA},{d}"
    elif opcode == 15:
        if rA == 0:
            return f"lis r{rD},{d}"
        return f"addis r{rD},r{rA},{d}"
    elif opcode == 19 and (word & 0xFFFF) == 0x0020:
        return "blr"
    else:
        return f"op{opcode}:{word:08X}"


def main():
    dol_data = read_dol()
    matched_dir = REPO / "src" / "matched"
    obj_dir = REPO / "build" / "obj" / "matched"

    sub_patterns = Counter()
    sda_global_returns = []
    wrong_source = []
    mismatched_offset_funcs = []

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
                    # Prefer exact match
                    for cname, cbytes in compiled_by_size[size]:
                        if cname not in used_compiled and cbytes == orig_bytes:
                            our_bytes = cbytes
                            our_name = cname
                            used_compiled.add(cname)
                            break
                    if our_bytes is None:
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
                            diffs.append((j, our_word, orig_word))

                    if not diffs:
                        continue

                    for j, our_w, orig_w in diffs:
                        our_op = (our_w >> 26) & 0x3F
                        orig_op = (orig_w >> 26) & 0x3F
                        if our_op != orig_op:
                            # Classify the opcode diff
                            our_dec = decode_instr(our_w)
                            orig_dec = decode_instr(orig_w)

                            # Pattern: ours=li r3,0 orig=lwz r3,off(r13) - SDA global return
                            orig_rA = (orig_w >> 16) & 0x1F
                            our_rD = (our_w >> 21) & 0x1F
                            if our_op == 14 and orig_op == 32 and orig_rA == 13:
                                sda_offset = orig_w & 0xFFFF
                                if sda_offset > 0x7FFF:
                                    sda_offset -= 0x10000
                                sub_patterns["sda_return"] += 1
                                sda_global_returns.append({
                                    "addr": addr, "size": size,
                                    "src_file": src_file.name, "src_line": line_idx + 1,
                                    "src_text": s[:120],
                                    "sda_offset": sda_offset,
                                })
                            elif our_op == 14 and orig_op == 32:
                                # ours=li r3,0 orig=lwz r3,off(rX) - should load from member
                                sub_patterns["wrong_return_load"] += 1
                                wrong_source.append({
                                    "addr": addr, "size": size,
                                    "src_file": src_file.name, "src_line": line_idx + 1,
                                    "src_text": s[:120],
                                    "our_instr": our_dec, "orig_instr": orig_dec,
                                })
                            elif our_op == 36 and orig_op == 14:
                                # ours=stw, orig=li - instruction order issue
                                sub_patterns["reorder_stw_li"] += 1
                            elif our_op in (48, 52) and orig_op in (32, 36, 14):
                                sub_patterns["float_vs_int"] += 1
                            else:
                                sub_patterns[f"op{our_op}_vs_op{orig_op}"] += 1

            elif s and not s.startswith("//") and not s.startswith("#"):
                pending = None

    print("=== Sub-pattern breakdown ===")
    for pat, cnt in sub_patterns.most_common():
        print(f"  {cnt:4d}  {pat}")

    print(f"\n=== SDA global return ({len(sda_global_returns)}) ===")
    sda_offsets = Counter(f["sda_offset"] for f in sda_global_returns)
    print("  SDA offsets:")
    for off, cnt in sda_offsets.most_common():
        print(f"    r13{off:+d} (0x{off & 0xFFFF:04X}): {cnt} functions")
    print("  Examples:")
    for f in sda_global_returns[:10]:
        print(f"    {f['src_file']}:{f['src_line']}  0x{f['addr']:08X}  {f['src_text'][:100]}")

    print(f"\n=== Wrong return/load ({len(wrong_source)}) ===")
    for f in wrong_source[:15]:
        print(f"  {f['src_file']}:{f['src_line']}  0x{f['addr']:08X}")
        print(f"    ours: {f['our_instr']}  orig: {f['orig_instr']}")
        print(f"    {f['src_text'][:100]}")


if __name__ == "__main__":
    main()
