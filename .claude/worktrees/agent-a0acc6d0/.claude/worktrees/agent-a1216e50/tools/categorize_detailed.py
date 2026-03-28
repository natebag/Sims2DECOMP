#!/usr/bin/env python3
"""Detailed categorization of all same-size-diff functions for batch fixing."""

import re
import struct
import subprocess
from pathlib import Path
from collections import Counter, defaultdict

REPO = Path(r"F:\coding\Decompiles\Sims 2")
DEVKITPPC = Path(r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC")
OBJDUMP = str(DEVKITPPC / "bin" / "powerpc-eabi-objdump.exe")
DOL = REPO / "extracted" / "sys" / "main.dol"


def read_dol():
    with open(DOL, "rb") as f:
        return f.read()


def get_dol_bytes(dol_data, addr, size):
    for i in range(7):
        off = struct.unpack(">I", dol_data[0x00 + i*4:0x04 + i*4])[0]
        load = struct.unpack(">I", dol_data[0x48 + i*4:0x4C + i*4])[0]
        sz = struct.unpack(">I", dol_data[0x90 + i*4:0x94 + i*4])[0]
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
    sd = d - 0x10000 if d > 0x7FFF else d

    load_store_ops = {
        32: "lwz", 34: "lbz", 36: "stw", 38: "stb",
        40: "lhz", 42: "lha", 44: "sth",
        48: "lfs", 50: "lfd", 52: "stfs", 54: "stfd",
    }

    if opcode in load_store_ops:
        return f"{load_store_ops[opcode]} r{rD},{sd}(r{rA})"
    elif opcode == 14:
        if rA == 0:
            return f"li r{rD},{sd}"
        return f"addi r{rD},r{rA},{sd}"
    elif opcode == 15:
        if rA == 0:
            return f"lis r{rD},{sd}"
        return f"addis r{rD},r{rA},{sd}"
    elif opcode == 24:
        return f"ori r{rA},r{rD},{d}"
    elif opcode == 21:
        SH = rB
        MB = (word >> 6) & 0x1F
        ME = (word >> 1) & 0x1F
        return f"rlwinm r{rA},r{rD},{SH},{MB},{ME}"
    elif opcode == 31:
        xo = (word >> 1) & 0x3FF
        return f"op31.xo{xo} r{rD},r{rA},r{rB}"
    elif opcode == 19 and (word & 0xFFFF) == 0x0020:
        return "blr"
    elif opcode == 8:
        return f"subfic r{rD},r{rA},{sd}"
    elif opcode == 12:
        return f"addic r{rD},r{rA},{sd}"
    elif opcode == 7:
        return f"mulli r{rD},r{rA},{sd}"
    elif opcode == 26:
        return f"xori r{rA},r{rD},{d}"
    else:
        return f"op{opcode}:{word:08X}"


def main():
    dol_data = read_dol()
    matched_dir = REPO / "src" / "matched"
    obj_dir = REPO / "build" / "obj" / "matched"

    all_info = []

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
                        our_word = int.from_bytes(our_bytes[j:j+4], "big")
                        orig_word = int.from_bytes(orig_bytes[j:j+4], "big")
                        if our_word != orig_word:
                            diffs.append((j, our_word, orig_word))
                    all_info.append({
                        "addr": addr, "size": size, "name": our_name,
                        "src_file": src_file.name, "src_line": line_idx + 1,
                        "src_text": s, "diffs": diffs,
                        "our_bytes": our_bytes, "orig_bytes": orig_bytes,
                    })
            elif s and not s.startswith("//") and not s.startswith("#"):
                pending = None

    categories = defaultdict(list)

    for info in all_info:
        diffs = info["diffs"]
        if len(diffs) == 0:
            continue

        ops = []
        for j, our_w, orig_w in diffs:
            our_op = (our_w >> 26) & 0x3F
            orig_op = (orig_w >> 26) & 0x3F
            ops.append((our_op, orig_op, our_w, orig_w))

        if len(diffs) == 1:
            our_op, orig_op, our_w, orig_w = ops[0]
            orig_rA = (orig_w >> 16) & 0x1F

            if our_op == 14 and orig_op == 32 and orig_rA == 13:
                categories["sda_return"].append(info)
            elif our_op == 14 and orig_op == 32:
                categories["wrong_load"].append(info)
            elif our_op == 24 and orig_op == 14:
                categories["ori_vs_addi"].append(info)
            elif our_op == 24 and orig_op == 32:
                categories["ori_vs_lwz"].append(info)
            elif our_op == orig_op:
                our_rD = (our_w >> 21) & 0x1F
                orig_rD = (orig_w >> 21) & 0x1F
                our_rA = (our_w >> 16) & 0x1F
                if our_rD == orig_rD and our_rA == orig_rA:
                    categories["wrong_offset_1diff"].append(info)
                else:
                    categories["same_op_reg_diff"].append(info)
            else:
                categories[f"other_op{our_op}_vs_op{orig_op}"].append(info)
        else:
            has_ori_addi = any(our_op == 24 and orig_op == 14 for our_op, orig_op, _, _ in ops)
            has_ori_lwz = any(our_op == 24 and orig_op == 32 for our_op, orig_op, _, _ in ops)
            all_same_op = all(our_op == orig_op for our_op, orig_op, _, _ in ops)

            if has_ori_addi or has_ori_lwz:
                categories["multi_ori_pattern"].append(info)
            elif all_same_op:
                all_offset = True
                for _, _, our_w, orig_w in ops:
                    our_rD = (our_w >> 21) & 0x1F
                    orig_rD = (orig_w >> 21) & 0x1F
                    our_rA = (our_w >> 16) & 0x1F
                    orig_rA = (orig_w >> 16) & 0x1F
                    if our_rD != orig_rD or our_rA != orig_rA:
                        all_offset = False
                        break
                if all_offset:
                    categories["multi_wrong_offset"].append(info)
                else:
                    categories["multi_same_op_reg_diff"].append(info)
            else:
                categories["multi_complex"].append(info)

    print("=== Detailed category counts ===")
    total_fixable = 0
    for cat in sorted(categories.keys(), key=lambda c: -len(categories[c])):
        cnt = len(categories[cat])
        fixable = cat in ("sda_return", "ori_vs_addi", "multi_ori_pattern",
                         "wrong_offset_1diff", "multi_wrong_offset", "wrong_load")
        mark = " *** FIXABLE" if fixable else ""
        print(f"  {cnt:4d}  {cat}{mark}")
        if fixable:
            total_fixable += cnt

    print(f"\nTotal potentially fixable: {total_fixable}")
    print(f"Total same-size-diff: {len(all_info)}")

    # Show SDA return details
    print("\n=== SDA Return Details ===")
    sda_offsets = Counter()
    for info in categories["sda_return"]:
        for j, our_w, orig_w in info["diffs"]:
            off = orig_w & 0xFFFF
            if off > 0x7FFF:
                off -= 0x10000
            sda_offsets[off] += 1
    for off, cnt in sda_offsets.most_common():
        print(f"  r13{off:+d} (0x{off & 0xFFFF:04X}): {cnt} functions")

    # Show wrong_load details
    print("\n=== Wrong Load Details ===")
    for info in categories["wrong_load"][:10]:
        j, our_w, orig_w = info["diffs"][0]
        print(f"  {info['src_file']}:{info['src_line']}  0x{info['addr']:08X}")
        print(f"    ours: {decode_instr(our_w)}  orig: {decode_instr(orig_w)}")
        print(f"    {info['src_text'][:120]}")

    # Show wrong_offset details
    print("\n=== Wrong Offset Details ===")
    for info in categories.get("wrong_offset_1diff", [])[:10]:
        j, our_w, orig_w = info["diffs"][0]
        print(f"  {info['src_file']}:{info['src_line']}  0x{info['addr']:08X}")
        print(f"    ours: {decode_instr(our_w)}  orig: {decode_instr(orig_w)}")
        print(f"    {info['src_text'][:120]}")

    # Show ori_vs_addi details
    print("\n=== ori_vs_addi Details (first 5) ===")
    for info in categories["ori_vs_addi"][:5]:
        j, our_w, orig_w = info["diffs"][0]
        print(f"  {info['src_file']}:{info['src_line']}  0x{info['addr']:08X}")
        print(f"    ours: {decode_instr(our_w)}  orig: {decode_instr(orig_w)}")
        print(f"    {info['src_text'][:120]}")

    # Show multi_ori_pattern details
    print("\n=== multi_ori_pattern Details (first 5) ===")
    for info in categories.get("multi_ori_pattern", [])[:5]:
        print(f"  {info['src_file']}:{info['src_line']}  0x{info['addr']:08X} ({len(info['diffs'])} diffs)")
        for j, our_w, orig_w in info["diffs"][:4]:
            print(f"    @{j}: ours={decode_instr(our_w)}  orig={decode_instr(orig_w)}")
        print(f"    {info['src_text'][:120]}")


if __name__ == "__main__":
    main()
