#!/usr/bin/env python3
"""
Categorize instruction-level differences between our .o output and original DOL.
"""

import json
import re
import struct
import subprocess
import sys
from pathlib import Path
from collections import Counter

REPO = Path(r"F:\coding\Decompiles\Sims 2")
DEVKITPPC = Path(r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC")
OBJDUMP = DEVKITPPC / "bin" / "powerpc-eabi-objdump.exe"
DOL = REPO / "extracted" / "sys" / "main.dol"


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


def decode_ppc_reg(word):
    """Get the primary opcode and key register fields."""
    opcode = (word >> 26) & 0x3F
    rs = (word >> 21) & 0x1F  # also rD
    ra = (word >> 16) & 0x1F
    return opcode, rs, ra


def classify_diff(our_word, orig_word):
    """Classify the difference between two 32-bit PPC instructions."""
    our_op, our_rs, our_ra = decode_ppc_reg(our_word)
    orig_op, orig_rs, orig_ra = decode_ppc_reg(orig_word)

    # Same opcode, different registers only
    if our_op == orig_op:
        our_imm = our_word & 0xFFFF
        orig_imm = orig_word & 0xFFFF

        # li rX, imm (opcode 14 = addi with rA=0)
        if our_op == 14 and our_ra == 0 and orig_ra == 0 and our_imm == orig_imm:
            return f"REG_ALLOC: li r{our_rs} vs li r{orig_rs} (constant {our_imm})"

        # Store/load with same displacement but different register
        if our_op in (32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 46, 48, 50, 52, 54):
            op_names = {32: "lwz", 33: "lwzu", 34: "lbz", 36: "stw", 37: "stwu",
                       38: "stb", 39: "stbu", 40: "lhz", 42: "lha", 44: "sth",
                       46: "lmw", 48: "lfs", 50: "lfd", 52: "stfs", 54: "stfd"}
            name = op_names.get(our_op, f"op{our_op}")
            if our_rs != orig_rs and our_ra == orig_ra and our_imm == orig_imm:
                return f"REG_ALLOC: {name} r{our_rs} vs r{orig_rs} (same offset)"
            if our_rs == orig_rs and our_ra != orig_ra:
                return f"REG_BASE: {name} base r{our_ra} vs r{orig_ra}"
            if our_imm != orig_imm:
                return f"OFFSET_DIFF: {name} offset 0x{our_imm:x} vs 0x{orig_imm:x}"

        # Extended opcode instructions (opcode 31)
        if our_op == 31:
            xo = (our_word >> 1) & 0x3FF
            our_rb = (our_word >> 11) & 0x1F
            orig_rb = (orig_word >> 11) & 0x1F
            xo_orig = (orig_word >> 1) & 0x3FF
            if xo == xo_orig:
                if our_rs != orig_rs or our_ra != orig_ra or our_rb != orig_rb:
                    return f"REG_ALLOC: x31/{xo} regs differ"

        # rlwinm (opcode 21)
        if our_op == 21:
            return f"BIT_MANIP: rlwinm params differ"

    if our_op != orig_op:
        return f"OPCODE_DIFF: op {our_op} vs {orig_op}"

    return f"OTHER: {our_word:08x} vs {orig_word:08x}"


def main():
    dol_data = read_dol()
    matched_dir = REPO / "src" / "matched"
    obj_dir = REPO / "build" / "obj" / "matched"

    categories = Counter()
    total_checked = 0
    total_matching = 0
    total_same_size_diff = 0
    total_size_diff = 0
    reg_alloc_details = Counter()

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
        pending = None
        func_index = 0

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
                addr, size = pending
                orig_bytes = get_dol_bytes(dol_data, addr, size)
                pending = None

                if orig_bytes is None:
                    continue

                our_bytes = None
                if size in compiled_by_size:
                    for cname, cbytes in compiled_by_size[size]:
                        if cname not in used_compiled:
                            our_bytes = cbytes
                            used_compiled.add(cname)
                            break

                if our_bytes is None and func_index < len(all_compiled):
                    cname, cbytes = all_compiled[func_index]
                    if cname not in used_compiled:
                        our_bytes = cbytes
                        used_compiled.add(cname)

                func_index += 1
                total_checked += 1

                if our_bytes and our_bytes == orig_bytes:
                    total_matching += 1
                elif our_bytes and len(our_bytes) == size:
                    total_same_size_diff += 1
                    # Analyze each instruction difference
                    for i in range(0, size, 4):
                        if i + 4 <= len(our_bytes) and i + 4 <= len(orig_bytes):
                            our_w = struct.unpack(">I", our_bytes[i:i+4])[0]
                            orig_w = struct.unpack(">I", orig_bytes[i:i+4])[0]
                            if our_w != orig_w:
                                cat = classify_diff(our_w, orig_w)
                                categories[cat] += 1
                                # Track register allocation specifics
                                if cat.startswith("REG_ALLOC: li"):
                                    reg_alloc_details[cat] += 1
                else:
                    total_size_diff += 1

            elif s and not s.startswith("//") and not s.startswith("#"):
                pending = None

    print(f"{'='*70}")
    print(f"MISMATCH CATEGORIZATION")
    print(f"{'='*70}")
    print(f"Total functions:            {total_checked}")
    print(f"Byte-identical:             {total_matching} ({total_matching*100/total_checked:.1f}%)")
    print(f"Same size, byte diff:       {total_same_size_diff}")
    print(f"Size mismatch:              {total_size_diff}")
    print()
    print(f"Instruction-level diff categories (across {total_same_size_diff} same-size functions):")
    for cat, count in categories.most_common(30):
        print(f"  {count:5d}  {cat}")

    if reg_alloc_details:
        print(f"\nRegister allocation details (li instruction):")
        for detail, count in reg_alloc_details.most_common(20):
            print(f"  {count:5d}  {detail}")


if __name__ == "__main__":
    main()
