#!/usr/bin/env python3
"""Analyze remaining same-size-diff patterns after r0 fix."""

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
    """Simple PPC instruction decoder."""
    opcode = (word >> 26) & 0x3F
    rD = (word >> 21) & 0x1F
    rA = (word >> 16) & 0x1F
    rB = (word >> 11) & 0x1F
    d = word & 0xFFFF
    if d > 0x7FFF:
        d -= 0x10000

    op_names = {
        14: "addi", 15: "addis", 21: "rlwinm", 24: "ori",
        32: "lwz", 33: "lwzu", 34: "lbz", 36: "stw", 38: "stb",
        40: "lhz", 42: "lha", 44: "sth", 46: "lmw", 47: "stmw",
        48: "lfs", 50: "lfd", 52: "stfs", 54: "stfd",
    }

    if opcode in (32, 33, 34, 36, 38, 40, 42, 44, 46, 47, 48, 50, 52, 54):
        name = op_names.get(opcode, f"op{opcode}")
        return f"{name} r{rD},{d}(r{rA})"
    elif opcode == 14:
        if rA == 0:
            return f"li r{rD},{d}"
        else:
            return f"addi r{rD},r{rA},{d}"
    elif opcode == 15:
        if rA == 0:
            return f"lis r{rD},{d}"
        else:
            return f"addis r{rD},r{rA},{d}"
    elif opcode == 21:
        SH = rB
        MB = (word >> 6) & 0x1F
        ME = (word >> 1) & 0x1F
        return f"rlwinm r{rA},r{rD},{SH},{MB},{ME}"
    elif opcode == 19 and (word & 0xFFFF) == 0x0020:
        return "blr"
    elif opcode == 31:
        xo = (word >> 1) & 0x3FF
        return f"op31.{xo} r{rD},r{rA},r{rB}"
    else:
        return f"op{opcode} {word:08X}"


def main():
    dol_data = read_dol()
    matched_dir = REPO / "src" / "matched"
    obj_dir = REPO / "build" / "obj" / "matched"

    categories = Counter()
    sda_returns = []
    offset_diffs = []
    reorder_diffs = []
    rlwinm_diffs = []
    other_diffs = []

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
                            diffs.append((j, our_word, orig_word))

                    if not diffs:
                        continue

                    info = {
                        "addr": addr, "size": size, "name": our_name,
                        "src_file": src_file.name, "src_line": line_idx + 1,
                        "src_text": s[:120], "diffs": diffs,
                    }

                    # Classify
                    has_sda = False
                    has_reorder = False
                    has_offset_diff = False
                    has_rlwinm = False

                    for j, our_w, orig_w in diffs:
                        our_op = (our_w >> 26) & 0x3F
                        orig_op = (orig_w >> 26) & 0x3F
                        orig_rA = (orig_w >> 16) & 0x1F

                        if orig_op == 32 and orig_rA == 13:
                            has_sda = True
                        elif our_op == orig_op == 21:
                            has_rlwinm = True
                        elif our_op == orig_op:
                            our_rD = (our_w >> 21) & 0x1F
                            orig_rD = (orig_w >> 21) & 0x1F
                            our_rA = (our_w >> 16) & 0x1F
                            if our_rD == orig_rD and our_rA == orig_rA:
                                has_offset_diff = True

                    # Check reorder: same set of instructions
                    if len(diffs) >= 2:
                        our_set = set(w for _, w, _ in diffs)
                        orig_set = set(w for _, _, w in diffs)
                        if our_set == orig_set:
                            has_reorder = True

                    if has_sda:
                        categories["sda_return"] += 1
                        sda_returns.append(info)
                    elif has_reorder:
                        categories["reorder"] += 1
                        reorder_diffs.append(info)
                    elif has_rlwinm:
                        categories["rlwinm_bitfield"] += 1
                        rlwinm_diffs.append(info)
                    elif has_offset_diff:
                        categories["offset_diff"] += 1
                        offset_diffs.append(info)
                    else:
                        categories["other"] += 1
                        other_diffs.append(info)

            elif s and not s.startswith("//") and not s.startswith("#"):
                pending = None

    total = sum(categories.values())
    print(f"Total remaining same-size-diff: {total}")
    print()
    print("=== Category breakdown ===")
    for cat, cnt in categories.most_common():
        print(f"  {cnt:4d}  {cat}")

    print(f"\n=== SDA return pattern ({len(sda_returns)}) ===")
    sda_offsets = Counter()
    for f in sda_returns:
        for j, our_w, orig_w in f["diffs"]:
            orig_op = (orig_w >> 26) & 0x3F
            orig_rA = (orig_w >> 16) & 0x1F
            if orig_op == 32 and orig_rA == 13:
                offset = orig_w & 0xFFFF
                if offset > 0x7FFF:
                    offset -= 0x10000
                sda_offsets[offset] += 1
    for off, cnt in sda_offsets.most_common(10):
        print(f"  r13{off:+d} (0x{off & 0xFFFF:04X}): {cnt} functions")
    print("  Examples:")
    for f in sda_returns[:5]:
        print(f"    {f['src_file']}:{f['src_line']}  {f['src_text'][:100]}")

    print(f"\n=== Instruction reorder ({len(reorder_diffs)}) ===")
    for f in reorder_diffs[:10]:
        print(f"  {f['src_file']}:{f['src_line']}  {f['src_text'][:100]}")
        for j, our_w, orig_w in f["diffs"]:
            print(f"    @{j:3d}: ours={decode_instr(our_w):30s} orig={decode_instr(orig_w)}")

    print(f"\n=== rlwinm/bitfield diffs ({len(rlwinm_diffs)}) ===")
    for f in rlwinm_diffs[:10]:
        print(f"  {f['src_file']}:{f['src_line']}  {f['src_text'][:100]}")
        for j, our_w, orig_w in f["diffs"]:
            print(f"    @{j:3d}: ours={decode_instr(our_w):30s} orig={decode_instr(orig_w)}")

    print(f"\n=== Offset diffs ({len(offset_diffs)}) ===")
    for f in offset_diffs[:10]:
        print(f"  {f['src_file']}:{f['src_line']}  {f['src_text'][:100]}")
        for j, our_w, orig_w in f["diffs"]:
            print(f"    @{j:3d}: ours={decode_instr(our_w):30s} orig={decode_instr(orig_w)}")

    print(f"\n=== Other ({len(other_diffs)}) ===")
    for f in other_diffs[:15]:
        print(f"  {f['src_file']}:{f['src_line']}  {f['src_text'][:100]}")
        for j, our_w, orig_w in f["diffs"]:
            print(f"    @{j:3d}: ours={decode_instr(our_w):30s} orig={decode_instr(orig_w)}")


if __name__ == "__main__":
    main()
