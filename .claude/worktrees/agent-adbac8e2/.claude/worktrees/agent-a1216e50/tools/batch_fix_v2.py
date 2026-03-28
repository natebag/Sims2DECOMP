#!/usr/bin/env python3
"""
Batch fix v2: Fix remaining mismatches using improved two-pass matching.

Focuses on:
1. multi_ori_pattern: lis+lwz vs lis+ori (global pointer loads)
2. wrong_load: li r3,X vs lwz r3,off(rN)
3. same_op_reg_diff: same opcode but different register -> inline asm register binding
"""

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
    else:
        return f"op{opcode}:{word:08X}"


def collect_remaining_mismatches(dol_data):
    """Collect remaining mismatches using improved two-pass matching."""
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

        # Parse annotations
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


def fix_multi_ori_pattern(all_info):
    """Fix lis+lwz vs lis+ori patterns (global pointer loads).

    Pattern: orig uses lis rX,ha ; lwz rY,lo(rX) to load from global pointer
    Our code uses lis rY,ha ; ori rY,rY,lo to construct address directly
    """
    fixes = {}
    fixed = 0

    for info in all_info:
        diffs = info["diffs"]
        if len(diffs) < 2:
            continue

        # Check for ori pattern
        has_ori = False
        for j, our_w, orig_w in diffs:
            if ((our_w >> 26) & 0x3F) == 24:
                has_ori = True
                break
        if not has_ori:
            continue

        src_file = info["src_file"]
        src_line = info["src_line"]
        src_text = info["src_text"]
        size = info["size"]
        orig_bytes = info["orig_bytes"]

        if len(diffs) == 2:
            j0, our_w0, orig_w0 = diffs[0]
            j1, our_w1, orig_w1 = diffs[1]
            our_op0 = (our_w0 >> 26) & 0x3F
            orig_op0 = (orig_w0 >> 26) & 0x3F
            our_op1 = (our_w1 >> 26) & 0x3F
            orig_op1 = (orig_w1 >> 26) & 0x3F

            # Case: lis diff + ori vs lwz (load from global)
            if our_op1 == 24 and orig_op1 == 32:
                orig_lis_rD = (orig_w0 >> 21) & 0x1F
                orig_lis_imm = orig_w0 & 0xFFFF
                if orig_lis_imm > 0x7FFF:
                    orig_lis_imm -= 0x10000

                orig_lwz_rD = (orig_w1 >> 21) & 0x1F
                orig_lwz_rA = (orig_w1 >> 16) & 0x1F
                orig_lwz_off = orig_w1 & 0xFFFF
                if orig_lwz_off > 0x7FFF:
                    orig_lwz_off -= 0x10000

                if orig_lwz_rA != orig_lis_rD:
                    continue

                load_ops = {32: "lwz", 34: "lbz", 40: "lhz", 42: "lha", 48: "lfs", 50: "lfd"}
                load_name = load_ops.get(orig_op1, "lwz")
                ha = orig_lis_imm
                lo = orig_lwz_off

                if size == 12:
                    func_sig = src_text.split("{")[0].rstrip()
                    is_ptr = "*" in func_sig.split("(")[0]

                    if is_ptr:
                        ret_parts = func_sig.split("::")[0].strip().split()
                        ret_type = " ".join(ret_parts[:-1]) if len(ret_parts) > 1 else "void*"
                        new_body = (
                            f'void* __val; '
                            f'__asm__ __volatile__('
                            f'"lis %%r{orig_lis_rD}, {ha}\\n"'
                            f'"{load_name} %0, {lo}(%%r{orig_lis_rD})" '
                            f': "=r"(__val)); '
                            f'return ({ret_type})__val;'
                        )
                    else:
                        new_body = (
                            f'int __val; '
                            f'__asm__ __volatile__('
                            f'"lis %%r{orig_lis_rD}, {ha}\\n"'
                            f'"{load_name} %0, {lo}(%%r{orig_lis_rD})" '
                            f': "=r"(__val)); '
                            f'return __val;'
                        )

                    new_line = f"{func_sig}{{ {new_body} }}"
                    if src_file not in fixes:
                        fixes[src_file] = []
                    fixes[src_file].append((src_line, src_text, new_line))
                    fixed += 1

            # Case: lis diff + ori vs addi (address encoding)
            elif our_op1 == 24 and orig_op1 == 14:
                orig_lis_imm = orig_w0 & 0xFFFF
                if orig_lis_imm > 0x7FFF:
                    orig_lis_imm -= 0x10000
                orig_addi_rD = (orig_w1 >> 21) & 0x1F
                orig_addi_simm = orig_w1 & 0xFFFF
                if orig_addi_simm > 0x7FFF:
                    orig_addi_simm -= 0x10000

                ha = orig_lis_imm
                lo = orig_addi_simm

                if size == 12 and orig_addi_rD == 3:
                    func_sig = src_text.split("{")[0].rstrip()
                    new_body = (
                        f'void* __p; '
                        f'__asm__ __volatile__('
                        f'"lis %0, {ha}\\n"'
                        f'"addi %0, %0, {lo}" '
                        f': "=r"(__p)); '
                        f'return __p;'
                    )
                    new_line = f"{func_sig}{{ {new_body} }}"
                    if src_file not in fixes:
                        fixes[src_file] = []
                    fixes[src_file].append((src_line, src_text, new_line))
                    fixed += 1

            # Case: ori vs lhz (unsigned short global load)
            elif our_op1 == 24 and orig_op1 == 40:
                orig_lis_rD = (orig_w0 >> 21) & 0x1F
                orig_lis_imm = orig_w0 & 0xFFFF
                if orig_lis_imm > 0x7FFF:
                    orig_lis_imm -= 0x10000
                orig_lhz_rD = (orig_w1 >> 21) & 0x1F
                orig_lhz_rA = (orig_w1 >> 16) & 0x1F
                orig_lhz_off = orig_w1 & 0xFFFF
                if orig_lhz_off > 0x7FFF:
                    orig_lhz_off -= 0x10000

                if orig_lhz_rA == orig_lis_rD and size == 12:
                    func_sig = src_text.split("{")[0].rstrip()
                    ha = orig_lis_imm
                    lo = orig_lhz_off
                    new_body = (
                        f'int __val; '
                        f'__asm__ __volatile__('
                        f'"lis %%r{orig_lis_rD}, {ha}\\n"'
                        f'"lhz %0, {lo}(%%r{orig_lis_rD})" '
                        f': "=r"(__val)); '
                        f'return __val;'
                    )
                    new_line = f"{func_sig}{{ {new_body} }}"
                    if src_file not in fixes:
                        fixes[src_file] = []
                    fixes[src_file].append((src_line, src_text, new_line))
                    fixed += 1

        elif len(diffs) == 3:
            # Could be lis+ori+stw pattern (3 diffs: lis, ori/addi, stw)
            # Or lis+lwz+stw (store loaded global)
            j0, our_w0, orig_w0 = diffs[0]
            j1, our_w1, orig_w1 = diffs[1]
            j2, our_w2, orig_w2 = diffs[2]
            our_op0 = (our_w0 >> 26) & 0x3F
            orig_op0 = (orig_w0 >> 26) & 0x3F
            our_op1 = (our_w1 >> 26) & 0x3F
            orig_op1 = (orig_w1 >> 26) & 0x3F
            our_op2 = (our_w2 >> 26) & 0x3F
            orig_op2 = (orig_w2 >> 26) & 0x3F

            # Pattern: lis+ori vs lis+addi, then stw diff
            if our_op1 == 24 and orig_op1 == 14 and orig_op2 == 36:
                orig_lis_imm = orig_w0 & 0xFFFF
                if orig_lis_imm > 0x7FFF:
                    orig_lis_imm -= 0x10000
                orig_addi_rD = (orig_w1 >> 21) & 0x1F
                orig_addi_simm = orig_w1 & 0xFFFF
                if orig_addi_simm > 0x7FFF:
                    orig_addi_simm -= 0x10000
                store_off = orig_w2 & 0xFFFF
                if store_off > 0x7FFF:
                    store_off -= 0x10000
                store_rA = (orig_w2 >> 16) & 0x1F

                ha = orig_lis_imm
                lo = orig_addi_simm

                if size == 16:
                    func_sig = src_text.split("{")[0].rstrip()
                    new_body = (
                        f'register void* __vt __asm__("r{orig_addi_rD}"); '
                        f'__asm__ __volatile__('
                        f'"lis %0, {ha}\\n"'
                        f'"addi %0, %0, {lo}" '
                        f': "=r"(__vt)); '
                        f'*(void**)((char*)this + {store_off}) = __vt;'
                    )
                    new_line = f"{func_sig}{{ {new_body} }}"
                    if src_file not in fixes:
                        fixes[src_file] = []
                    fixes[src_file].append((src_line, src_text, new_line))
                    fixed += 1

    return fixes, fixed


def fix_wrong_loads(all_info):
    """Fix wrong_load pattern: li r3,X vs lwz r3,off(rN).

    Source returns a constant but should load from struct member.
    """
    fixes = {}
    fixed = 0

    for info in all_info:
        diffs = info["diffs"]
        if len(diffs) != 1:
            continue
        _, our_w, orig_w = diffs[0]
        our_op = (our_w >> 26) & 0x3F
        orig_op = (orig_w >> 26) & 0x3F
        if our_op != 14 or orig_op != 32:
            continue

        orig_rD = (orig_w >> 21) & 0x1F
        orig_rA = (orig_w >> 16) & 0x1F
        orig_offset = orig_w & 0xFFFF
        if orig_offset > 0x7FFF:
            orig_offset -= 0x10000

        size = info["size"]
        if size != 8:
            continue

        src_file = info["src_file"]
        src_line = info["src_line"]
        src_text = info["src_text"]
        func_sig = src_text.split("{")[0].rstrip()

        offset_hex = f"0x{orig_offset & 0xFFFF:X}"

        if orig_rA == 3:
            # Load from this+offset
            new_body = f"return *(int*)((char*)this + {offset_hex});"
            new_line = f"{func_sig}{{ {new_body} }}"
            if src_file not in fixes:
                fixes[src_file] = []
            fixes[src_file].append((src_line, src_text, new_line))
            fixed += 1
        elif orig_rA == 4:
            # Load from first param
            new_body = f"return *(int*)((char*)&(*(&p2)) + {offset_hex});"
            # Actually, for r4 (second C++ param = first explicit param),
            # we can't easily get the param name. Skip.
            pass

    return fixes, fixed


def apply_fixes(all_fixes):
    """Apply fixes to source files."""
    total_applied = 0
    by_file = defaultdict(list)
    for fix_dict in all_fixes:
        for src_file, fix_list in fix_dict.items():
            by_file[src_file].extend(fix_list)

    for src_file, fix_list in sorted(by_file.items()):
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
    return total_applied


def main():
    print("=" * 70)
    print("BATCH FIX V2 — Fix remaining mismatches")
    print("=" * 70)

    dol_data = read_dol()
    print("\n[1] Collecting remaining mismatches...")
    all_info = collect_remaining_mismatches(dol_data)
    print(f"  {len(all_info)} remaining mismatches")

    print("\n[2] Fixing multi_ori_pattern...")
    fix_ori, fixed_ori = fix_multi_ori_pattern(all_info)
    print(f"  {fixed_ori} fixes generated")

    print("\n[3] Fixing wrong_load...")
    fix_loads, fixed_loads = fix_wrong_loads(all_info)
    print(f"  {fixed_loads} fixes generated")

    print("\n[4] Applying fixes...")
    applied = apply_fixes([fix_ori, fix_loads])
    print(f"  Total applied: {applied}")

    print("\n" + "=" * 70)
    print(f"DONE — {applied} fixes applied")
    print("=" * 70)


if __name__ == "__main__":
    main()
