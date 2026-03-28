#!/usr/bin/env python3
"""Find functions where diffs are: instruction reorder + r0/r9 register swap."""

import re
import struct
import subprocess
from pathlib import Path

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


def is_reorder_with_r0_r9(our_bytes, orig_bytes):
    """Check if diff is just reorder + r0/r9 swap."""
    # Get all instruction words
    num_instrs = len(our_bytes) // 4
    our_words = [int.from_bytes(our_bytes[i*4:(i+1)*4], "big") for i in range(num_instrs)]
    orig_words = [int.from_bytes(orig_bytes[i*4:(i+1)*4], "big") for i in range(num_instrs)]

    # Find differing positions
    diff_positions = [i for i in range(num_instrs) if our_words[i] != orig_words[i]]
    if len(diff_positions) < 2:
        return False

    # For each original instruction at a diff position, see if there's a matching
    # one in our code at a different diff position (possibly with r9->r0 change)
    orig_at_diff = {i: orig_words[i] for i in diff_positions}
    our_at_diff = {i: our_words[i] for i in diff_positions}

    # Check if orig instructions = our instructions with r9<->r0 swap and reorder
    def r9_r0_equiv(w1, w2):
        """Check if two words are the same instruction with r9/r0 swap in rD."""
        if w1 == w2:
            return True
        op1 = (w1 >> 26) & 0x3F
        op2 = (w2 >> 26) & 0x3F
        if op1 != op2:
            return False
        # Check if only rD differs (bits 6-10)
        mask = ~(0x1F << 21)  # mask out rD
        if (w1 & mask) == (w2 & mask):
            rD1 = (w1 >> 21) & 0x1F
            rD2 = (w2 >> 21) & 0x1F
            if (rD1 == 0 and rD2 == 9) or (rD1 == 9 and rD2 == 0):
                return True
        return False

    # Try to match each orig instruction to an our instruction
    used = set()
    for i in diff_positions:
        found = False
        for j in diff_positions:
            if j not in used and r9_r0_equiv(our_words[j], orig_words[i]):
                used.add(j)
                found = True
                break
        if not found:
            return False

    return True


def main():
    dol_data = read_dol()
    matched_dir = REPO / "src" / "matched"
    obj_dir = REPO / "build" / "obj" / "matched"

    reorder_r0_funcs = []

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
                    if is_reorder_with_r0_r9(our_bytes, orig_bytes):
                        reorder_r0_funcs.append({
                            "addr": addr,
                            "size": size,
                            "name": our_name,
                            "src_file": src_file.name,
                            "src_line": line_idx + 1,
                            "src_text": s[:140],
                            "our_bytes": our_bytes,
                            "orig_bytes": orig_bytes,
                        })

            elif s and not s.startswith("//") and not s.startswith("#"):
                pending = None

    print(f"Functions with reorder+r0/r9 pattern: {len(reorder_r0_funcs)}")
    print()
    for f in reorder_r0_funcs:
        print(f"  {f['src_file']}:{f['src_line']}  0x{f['addr']:08X} ({f['size']}B)")
        print(f"    {f['src_text']}")
        num_instrs = f["size"] // 4
        for i in range(num_instrs):
            our_w = int.from_bytes(f["our_bytes"][i*4:(i+1)*4], "big")
            orig_w = int.from_bytes(f["orig_bytes"][i*4:(i+1)*4], "big")
            marker = "  " if our_w == orig_w else "!!"
            print(f"    {marker} {i}: ours={decode_instr(our_w):30s} orig={decode_instr(orig_w)}")
        print()


if __name__ == "__main__":
    main()
