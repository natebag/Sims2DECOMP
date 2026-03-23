#!/usr/bin/env python3
"""
Compare compiled .o function bytes against original DOL bytes directly.
This bypasses the linker entirely to check if our COMPILER output matches.
"""

import json
import re
import struct
import subprocess
import sys
from pathlib import Path

REPO = Path(r"F:\coding\Decompiles\Sims 2")
DEVKITPPC = Path(r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC")
OBJDUMP = DEVKITPPC / "bin" / "powerpc-eabi-objdump.exe"
DOL = REPO / "extracted" / "sys" / "main.dol"
SYMBOLS = REPO / "tools" / "symbols.json"


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
    """Get all functions and their bytes from a .o file."""
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


def main():
    dol_data = read_dol()
    matched_dir = REPO / "src" / "matched"
    obj_dir = REPO / "build" / "obj" / "matched"

    total = 0
    byte_match = 0
    size_match_byte_diff = 0
    other = 0

    match_list = []
    mismatch_list = []

    for src_file in sorted(list(matched_dir.glob("*.cpp")) + list(matched_dir.glob("*.c"))):
        with open(src_file, "r") as f:
            content = f.read()

        obj_file = obj_dir / (src_file.stem + ".o")
        if not obj_file.exists():
            continue

        # Parse all compiled functions from the .o
        all_compiled = get_all_funcs_from_obj(obj_file)
        # Index by size for matching
        compiled_by_size = {}
        for name, fbytes in all_compiled:
            sz = len(fbytes)
            if sz not in compiled_by_size:
                compiled_by_size[sz] = []
            compiled_by_size[sz].append((name, fbytes))

        # Track which compiled functions we have already used
        used_compiled = set()

        # Parse source for address annotations
        in_if0 = 0
        lines = content.split("\n")
        pending = None
        func_index = 0  # track order of functions in source

        for line in lines:
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

            if pending and "{" in s and not s.startswith("//") and not s.startswith("__attr") and ("::" in s or "(" in s):
                addr, size = pending
                orig_bytes = get_dol_bytes(dol_data, addr, size)
                pending = None

                if orig_bytes is None:
                    continue

                # Find matching compiled function by size
                # Prefer exact byte match, then first unused same-size
                our_bytes = None
                our_name = "?"
                if size in compiled_by_size:
                    # First pass: look for exact byte match
                    for cname, cbytes in compiled_by_size[size]:
                        if cname not in used_compiled and cbytes == orig_bytes:
                            our_bytes = cbytes
                            our_name = cname
                            used_compiled.add(cname)
                            break
                    # Second pass: first unused same-size
                    if our_bytes is None:
                        for cname, cbytes in compiled_by_size[size]:
                            if cname not in used_compiled:
                                our_bytes = cbytes
                                our_name = cname
                                used_compiled.add(cname)
                                break

                if our_bytes is None:
                    # Try finding by order in the .o
                    if func_index < len(all_compiled):
                        cname, cbytes = all_compiled[func_index]
                        if cname not in used_compiled:
                            our_bytes = cbytes
                            our_name = cname
                            used_compiled.add(cname)

                func_index += 1
                total += 1

                if our_bytes and our_bytes == orig_bytes:
                    byte_match += 1
                    match_list.append((addr, size, s[:70]))
                elif our_bytes and len(our_bytes) == size:
                    size_match_byte_diff += 1
                    # Find first diff
                    diff_pos = -1
                    for i in range(min(len(our_bytes), len(orig_bytes))):
                        if our_bytes[i] != orig_bytes[i]:
                            diff_pos = i
                            break
                    mismatch_list.append((addr, size, our_name, diff_pos, our_bytes, orig_bytes))
                else:
                    other += 1
                    ours_len = len(our_bytes) if our_bytes else 0
                    mismatch_list.append((addr, size, our_name, -1, our_bytes, orig_bytes))

            elif s and not s.startswith("//") and not s.startswith("#") and not s.startswith("__attr"):
                pending = None

    pct = byte_match * 100.0 / total if total else 0
    print(f"{'='*70}")
    print(f"COMPILER OUTPUT COMPARISON (.o bytes vs original DOL)")
    print(f"{'='*70}")
    print(f"Total functions checked:        {total}")
    print(f"Byte-identical matches:         {byte_match} ({pct:.1f}%)")
    print(f"Same size, different bytes:     {size_match_byte_diff}")
    print(f"Size mismatch / not found:      {other}")

    if match_list:
        print(f"\nByte-identical functions ({len(match_list)}):")
        for addr, size, desc in match_list[:50]:
            print(f"  0x{addr:08X} ({size:4d}B) {desc}")

    if mismatch_list:
        print(f"\nMismatched functions (showing first 20 of {len(mismatch_list)}):")
        for item in mismatch_list[:20]:
            addr, size, name, diff_pos, ours, orig = item
            if diff_pos >= 0 and ours:
                # Show the differing instruction
                instr_idx = diff_pos // 4
                our_word = ours[instr_idx*4:(instr_idx+1)*4].hex() if instr_idx*4+4 <= len(ours) else "??"
                orig_word = orig[instr_idx*4:(instr_idx+1)*4].hex() if instr_idx*4+4 <= len(orig) else "??"
                print(f"  0x{addr:08X} ({size:4d}B) [{name}] diff@instr{instr_idx}: ours={our_word} orig={orig_word}")
            else:
                ours_len = len(ours) if ours else 0
                print(f"  0x{addr:08X} ({size:4d}B) [{name}] size: ours={ours_len} orig={size}")


if __name__ == "__main__":
    main()
