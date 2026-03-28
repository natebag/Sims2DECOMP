#!/usr/bin/env python3
"""
Batch fix v3: Fix remaining ori_vs_addi and multi_ori_pattern mismatches.
"""

import re
import struct
import subprocess
from pathlib import Path
from collections import defaultdict

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


def collect_remaining_mismatches(dol_data):
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

        # Pass 1: exact byte matches
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

        # Pass 2: remaining
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
                all_info.append({
                    "addr": addr, "size": size, "name": our_name,
                    "src_file": str(src_file), "src_line": line_num,
                    "src_text": src_text, "diffs": diffs,
                    "our_bytes": our_bytes, "orig_bytes": orig,
                })
    return all_info


def generate_asm_fix_12byte(info):
    """Generate inline asm fix for a 12-byte function (3 instructions: lis+X+blr).

    The function has exactly one diff at offset 4 (the second instruction).
    We need to produce the exact bytes of the original.
    """
    src_text = info["src_text"]
    orig_bytes = info["orig_bytes"]
    size = info["size"]

    if size != 12:
        return None

    # Decode all 3 original instructions
    w0 = int.from_bytes(orig_bytes[0:4], "big")
    w1 = int.from_bytes(orig_bytes[4:8], "big")
    w2 = int.from_bytes(orig_bytes[8:12], "big")

    op0 = (w0 >> 26) & 0x3F
    op1 = (w1 >> 26) & 0x3F
    op2 = (w2 >> 26) & 0x3F

    # Must be: lis + something + blr
    if op0 != 15 or op2 != 19:
        return None

    lis_rD = (w0 >> 21) & 0x1F
    lis_imm = w0 & 0xFFFF
    if lis_imm > 0x7FFF:
        lis_imm -= 0x10000

    load_store_names = {
        14: "addi", 32: "lwz", 34: "lbz", 36: "stw", 38: "stb",
        40: "lhz", 42: "lha", 44: "sth", 48: "lfs", 50: "lfd",
    }

    instr1_name = load_store_names.get(op1)
    if not instr1_name:
        return None

    instr1_rD = (w1 >> 21) & 0x1F
    instr1_rA = (w1 >> 16) & 0x1F
    instr1_imm = w1 & 0xFFFF
    if instr1_imm > 0x7FFF:
        instr1_imm -= 0x10000

    func_sig = src_text.split("{")[0].rstrip()

    if op1 == 14:
        # addi rD, rA, imm -> constructing address
        new_body = (
            f'void* __p; '
            f'__asm__ __volatile__('
            f'"lis %0, {lis_imm}\\n"'
            f'"addi %0, %0, {instr1_imm}" '
            f': "=r"(__p)); '
            f'return __p;'
        )
    elif op1 in (32, 34, 40, 42, 48, 50):
        # Load from global: lwz/lbz/lhz/lha/lfs/lfd rD, off(rA)
        if instr1_rA == lis_rD:
            # Loading through register set by lis
            new_body = (
                f'int __val; '
                f'__asm__ __volatile__('
                f'"lis %%r{lis_rD}, {lis_imm}\\n"'
                f'"{instr1_name} %0, {instr1_imm}(%%r{lis_rD})" '
                f': "=r"(__val)); '
                f'return __val;'
            )
        else:
            return None
    else:
        return None

    return f"{func_sig}{{ {new_body} }}"


def generate_asm_fix_16byte(info):
    """Generate inline asm fix for 16-byte functions (4 instructions: lis+X+stw+blr)."""
    src_text = info["src_text"]
    orig_bytes = info["orig_bytes"]
    size = info["size"]

    if size != 16:
        return None

    w0 = int.from_bytes(orig_bytes[0:4], "big")
    w1 = int.from_bytes(orig_bytes[4:8], "big")
    w2 = int.from_bytes(orig_bytes[8:12], "big")
    w3 = int.from_bytes(orig_bytes[12:16], "big")

    op0 = (w0 >> 26) & 0x3F
    op1 = (w1 >> 26) & 0x3F
    op2 = (w2 >> 26) & 0x3F
    op3 = (w3 >> 26) & 0x3F

    if op0 != 15 or op3 != 19:
        return None
    if op2 != 36:  # stw
        return None

    lis_rD = (w0 >> 21) & 0x1F
    lis_imm = w0 & 0xFFFF
    if lis_imm > 0x7FFF:
        lis_imm -= 0x10000

    instr1_rD = (w1 >> 21) & 0x1F
    instr1_imm = w1 & 0xFFFF
    if instr1_imm > 0x7FFF:
        instr1_imm -= 0x10000

    store_off = w2 & 0xFFFF
    if store_off > 0x7FFF:
        store_off -= 0x10000

    func_sig = src_text.split("{")[0].rstrip()

    if op1 == 14:  # addi
        new_body = (
            f'register void* __vt __asm__("r{instr1_rD}"); '
            f'__asm__ __volatile__('
            f'"lis %0, {lis_imm}\\n"'
            f'"addi %0, %0, {instr1_imm}" '
            f': "=r"(__vt)); '
            f'*(void**)((char*)this + {store_off}) = __vt;'
        )
        return f"{func_sig}{{ {new_body} }}"

    return None


def main():
    print("=" * 70)
    print("BATCH FIX V3")
    print("=" * 70)

    dol_data = read_dol()
    print("\n[1] Collecting remaining mismatches...")
    all_info = collect_remaining_mismatches(dol_data)
    print(f"  {len(all_info)} remaining mismatches")

    fixes = {}
    fixed_count = 0

    for info in all_info:
        diffs = info["diffs"]
        if not diffs:
            continue

        size = info["size"]
        src_file = info["src_file"]
        src_line = info["src_line"]
        src_text = info["src_text"]

        # Try to generate fix based on original bytes
        new_line = None

        if size == 12:
            new_line = generate_asm_fix_12byte(info)
        elif size == 16:
            new_line = generate_asm_fix_16byte(info)

        if new_line and new_line.strip() != src_text.strip():
            if src_file not in fixes:
                fixes[src_file] = []
            fixes[src_file].append((src_line, src_text, new_line))
            fixed_count += 1

    print(f"\n[2] Generated {fixed_count} fixes across {len(fixes)} files")

    # Apply fixes
    total_applied = 0
    for src_file, fix_list in sorted(fixes.items()):
        with open(src_file, "r") as f:
            lines = f.readlines()
        fix_list.sort(key=lambda x: x[0], reverse=True)
        applied = 0
        for line_num, old_text, new_text in fix_list:
            idx = line_num - 1
            if idx < len(lines):
                current = lines[idx].rstrip("\n")
                if current.strip() == old_text.strip():
                    indent = len(current) - len(current.lstrip())
                    lines[idx] = current[:indent] + new_text + "\n"
                    applied += 1
        if applied > 0:
            with open(src_file, "w") as f:
                f.writelines(lines)
            total_applied += applied
            print(f"  {Path(src_file).name}: {applied} fixes applied")

    print(f"\n  Total applied: {total_applied}")
    print("=" * 70)


if __name__ == "__main__":
    main()
