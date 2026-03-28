#!/usr/bin/env python3
"""Analyze same_op_reg_diff pattern in detail."""

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
    else:
        return f"op{opcode}:{word:08X}"


def main():
    dol_data = read_dol()
    matched_dir = REPO / "src" / "matched"
    obj_dir = REPO / "build" / "obj" / "matched"

    reg_diffs = []
    sub_patterns = Counter()

    for src_file in sorted(matched_dir.glob("*.cpp")):
        with open(src_file, "r") as f:
            content = f.read()
        obj_file = obj_dir / (src_file.stem + ".o")
        if not obj_file.exists():
            continue
        all_compiled = get_all_funcs_from_obj(obj_file)
        compiled_by_size = defaultdict(list)
        for name, fbytes in all_compiled:
            compiled_by_size[len(fbytes)].append((name, fbytes))

        in_if0 = 0
        lines = content.split("\n")
        pending = None
        annotations = []
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
                pending = None
                annotations.append((addr, size, line_idx + 1, s))
            elif s and not s.startswith("//") and not s.startswith("#"):
                pending = None

        matched_addrs = set()
        used = set()
        for addr, size, _, _ in annotations:
            orig = get_dol_bytes(dol_data, addr, size)
            if orig is None:
                continue
            if size in compiled_by_size:
                for cname, cbytes in compiled_by_size[size]:
                    if cname not in used and cbytes == orig:
                        used.add(cname)
                        matched_addrs.add(addr)
                        break

        used2 = set(used)
        for addr, size, line_num, src_text in annotations:
            if addr in matched_addrs:
                continue
            orig = get_dol_bytes(dol_data, addr, size)
            if orig is None:
                continue
            our_bytes = None
            our_name = "?"
            if size in compiled_by_size:
                for cname, cbytes in compiled_by_size[size]:
                    if cname not in used2:
                        our_bytes = cbytes
                        our_name = cname
                        used2.add(cname)
                        break
            if our_bytes and len(our_bytes) == size and our_bytes != orig:
                diffs = []
                for j in range(0, min(len(our_bytes), len(orig)), 4):
                    our_word = int.from_bytes(our_bytes[j:j+4], "big")
                    orig_word = int.from_bytes(orig[j:j+4], "big")
                    if our_word != orig_word:
                        diffs.append((j, our_word, orig_word))
                if len(diffs) == 1:
                    _, our_w, orig_w = diffs[0]
                    our_op = (our_w >> 26) & 0x3F
                    orig_op = (orig_w >> 26) & 0x3F
                    if our_op == orig_op:
                        our_rD = (our_w >> 21) & 0x1F
                        orig_rD = (orig_w >> 21) & 0x1F
                        our_rA = (our_w >> 16) & 0x1F
                        orig_rA = (orig_w >> 16) & 0x1F
                        if our_rD != orig_rD or our_rA != orig_rA:
                            pat = f"op{our_op}_r{our_rD}->r{orig_rD}_rA{our_rA}->rA{orig_rA}"
                            sub_patterns[pat] += 1
                            reg_diffs.append({
                                "src_file": src_file.name,
                                "src_line": line_num,
                                "src_text": src_text[:140],
                                "addr": addr, "size": size,
                                "our_instr": decode_instr(our_w),
                                "orig_instr": decode_instr(orig_w),
                                "pattern": pat,
                            })

    print(f"Total same_op_reg_diff: {len(reg_diffs)}")
    print("\nSub-patterns:")
    for pat, cnt in sub_patterns.most_common():
        print(f"  {cnt:4d}  {pat}")

    print("\nExamples:")
    for info in reg_diffs[:20]:
        print(f"  {info['src_file']}:{info['src_line']}  0x{info['addr']:08X}")
        print(f"    ours: {info['our_instr']}  orig: {info['orig_instr']}  ({info['pattern']})")
        print(f"    {info['src_text'][:120]}")


if __name__ == "__main__":
    main()
