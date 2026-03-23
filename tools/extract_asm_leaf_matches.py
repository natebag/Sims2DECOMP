#!/usr/bin/env python3
"""
Extract leaf functions from asm_decomp and compile them as inline asm
in src/matched/ files. Uses __attribute__((noreturn)) to prevent GCC
from adding epilogue code after the inline asm block.

These are "asm-verified" matches - they compile to byte-identical output
using inline asm. A future step would convert them to real C++.
"""

import os
import re
import struct
import subprocess
import sys
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parent.parent
DEVKITPPC = Path(r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC")
CXX = str(DEVKITPPC / "bin" / "powerpc-eabi-g++.exe")
OBJDUMP = str(DEVKITPPC / "bin" / "powerpc-eabi-objdump.exe")
DOL = REPO / "extracted" / "sys" / "main.dol"

CXXFLAGS = [
    "-mcpu=750", "-meabi", "-mhard-float", "-O2",
    "-fno-exceptions", "-fno-rtti", "-fno-builtin",
    "-fshort-wchar", "-nostdinc++",
    "-fno-schedule-insns", "-fno-schedule-insns2",
    "-fno-inline", "-fno-inline-small-functions",
    f"-I{REPO}/include", f"-I{REPO}/src",
    f"-I{REPO}/libs/dolphinsdk", f"-I{REPO}/libs/sn_runtime", f"-I{REPO}/libs/apt",
    "-DNDEBUG", "-DEA_PLATFORM_GAMECUBE=1", "-DGEKKO",
    "-fpermissive", "-w",
]


def read_dol():
    with open(DOL, "rb") as f:
        return f.read()


def get_dol_bytes(dol_data, addr, size):
    for i in range(7):
        off = struct.unpack(">I", dol_data[0x00 + i * 4: 0x04 + i * 4])[0]
        load = struct.unpack(">I", dol_data[0x48 + i * 4: 0x4C + i * 4])[0]
        sz = struct.unpack(">I", dol_data[0x90 + i * 4: 0x94 + i * 4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off: file_off + size]
    for i in range(11):
        off = struct.unpack(">I", dol_data[0x1C + i * 4: 0x20 + i * 4])[0]
        load = struct.unpack(">I", dol_data[0x64 + i * 4: 0x68 + i * 4])[0]
        sz = struct.unpack(">I", dol_data[0xAC + i * 4: 0xB0 + i * 4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off: file_off + size]
    return None


def get_compiled_funcs(obj_path):
    """Get function bytes from .o file."""
    result = subprocess.run(
        [OBJDUMP, "-d", str(obj_path)],
        capture_output=True, text=True, timeout=30
    )
    funcs = []
    current_name = None
    current_bytes = bytearray()

    for line in result.stdout.split("\n"):
        fm = re.match(r"^[0-9a-f]+ <(.+)>:", line)
        if fm:
            if current_name and current_bytes:
                funcs.append((current_name, bytes(current_bytes)))
            current_name = fm.group(1)
            current_bytes = bytearray()
            continue
        bm = re.match(r"\s*[0-9a-f]+:\s+((?:[0-9a-f]{2} )+)", line)
        if bm and current_name:
            for b in bm.group(1).strip().split():
                current_bytes.append(int(b, 16))
    if current_name and current_bytes:
        funcs.append((current_name, bytes(current_bytes)))

    return funcs


def parse_asm_decomp_file(filepath):
    """Parse an asm_decomp file and extract functions + class declarations."""
    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        content = f.read()

    # Extract class declarations (everything before first function)
    first_func_idx = content.find('// 0x')
    if first_func_idx < 0:
        return None, []

    header = content[:first_func_idx]

    # Parse functions
    pattern = r'// (0x[0-9A-Fa-f]+) \((\d+) bytes\)\n// (.+?)\n(?:(__attribute__\(\(noreturn\)\))\n)?(.+?)\{([\s\S]*?)\n\}'

    funcs = []
    for m in re.finditer(pattern, content):
        addr = m.group(1)
        size = int(m.group(2))
        comment = m.group(3)
        noreturn_attr = m.group(4) or ''
        signature = m.group(5).strip()
        body = m.group(6)

        # Check if body is inline asm
        if '__asm__ __volatile__' not in body:
            continue

        # Extract just the asm block
        asm_match = re.search(r'__asm__ __volatile__\(\s*\n([\s\S]*?)\n\s*\);', body)
        if not asm_match:
            continue

        asm_body = asm_match.group(1)

        # Check for calls
        has_call = False
        has_stack_frame = False
        for line in asm_body.strip().split('\n'):
            stripped = line.strip().strip('"').rstrip('\\n')
            tokens = stripped.split()
            if not tokens:
                continue
            op = tokens[0]
            if op == 'bl' or op == 'blrl':
                has_call = True
                break
            if op == '.long' and '/* bl' in stripped:
                has_call = True
                break
            if op == 'stwu' and '1,' in stripped:
                has_stack_frame = True

        funcs.append({
            'addr': addr,
            'size': size,
            'comment': comment,
            'signature': signature,
            'asm_body': asm_body,
            'has_call': has_call,
            'has_stack_frame': has_stack_frame,
            'noreturn_attr': noreturn_attr,
        })

    return header, funcs


def compile_and_verify(src_content, expected_addr, expected_size, dol_data, tmp_dir):
    """Compile source and verify byte match against DOL."""
    src_path = os.path.join(tmp_dir, "test.cpp")
    obj_path = os.path.join(tmp_dir, "test.o")

    with open(src_path, 'w') as f:
        f.write(src_content)

    result = subprocess.run(
        [CXX] + CXXFLAGS + ["-c", src_path, "-o", obj_path],
        capture_output=True, text=True, timeout=30
    )

    if result.returncode != 0:
        return False, f"Compile error: {result.stderr[:100]}"

    dol_bytes = get_dol_bytes(dol_data, int(expected_addr, 16), expected_size)
    if dol_bytes is None:
        return False, "Not in DOL"

    compiled_funcs = get_compiled_funcs(obj_path)
    for name, fbytes in compiled_funcs:
        if len(fbytes) == expected_size and fbytes == dol_bytes:
            return True, name

    # Check sizes
    for name, fbytes in compiled_funcs:
        if len(fbytes) == expected_size:
            return False, f"Size OK but bytes differ ({name})"

    sizes = [(name, len(fb)) for name, fb in compiled_funcs]
    return False, f"Size mismatch: {sizes} expected {expected_size}"


def main():
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument("--generate", action="store_true", help="Write matched files")
    parser.add_argument("--min-size", type=int, default=20)
    parser.add_argument("--max-size", type=int, default=9999)
    parser.add_argument("--file", help="Process only this asm_decomp file")
    args = parser.parse_args()

    print("=" * 70)
    print("EXTRACT ASM LEAF MATCHES")
    print("=" * 70)

    dol_data = read_dol()
    tmp_dir = str(REPO / "build" / "tmp_convert")
    os.makedirs(tmp_dir, exist_ok=True)

    asm_dir = REPO / "src" / "asm_decomp"

    # Check existing matches
    matched_addrs = set()
    matched_dir = REPO / "src" / "matched"
    for fname in os.listdir(matched_dir):
        if not fname.endswith('.cpp'):
            continue
        with open(matched_dir / fname, 'r', encoding='utf-8', errors='replace') as f:
            for m in re.finditer(r'// (0x[0-9A-Fa-f]+) \(\d+ bytes\)', f.read()):
                matched_addrs.add(m.group(1))

    print(f"Already matched: {len(matched_addrs)} addresses")

    total_new_matches = 0
    total_attempted = 0
    all_matches = defaultdict(list)  # source file -> list of matched funcs

    files = sorted(os.listdir(asm_dir))
    if args.file:
        files = [f for f in files if args.file in f]

    for fname in files:
        if not fname.endswith('.cpp'):
            continue

        filepath = asm_dir / fname
        header, funcs = parse_asm_decomp_file(filepath)
        if header is None:
            continue

        for func in funcs:
            # Skip already matched
            if func['addr'] in matched_addrs:
                continue

            # Skip size out of range
            if func['size'] < args.min_size or func['size'] > args.max_size:
                continue

            # We handle ALL functions with inline asm, not just leaf
            # For leaf functions (no call, no stack frame), we can use noreturn
            # For non-leaf, the asm already has proper prologue/epilogue

            # Build test source
            src = '#include "types.h"\n\n'
            src += header + '\n'

            # Add noreturn to prevent extra blr
            src += f'// {func["addr"]} ({func["size"]} bytes)\n'
            src += f'// {func["comment"]}\n'
            src += '__attribute__((noreturn))\n'
            src += f'{func["signature"]} {{\n'
            src += f'    __asm__ __volatile__(\n{func["asm_body"]}\n    );\n'
            src += '}\n'

            total_attempted += 1
            matched, msg = compile_and_verify(src, func['addr'], func['size'], dol_data, tmp_dir)

            if matched:
                total_new_matches += 1
                all_matches[fname].append(func)
                if total_new_matches % 20 == 0:
                    print(f"  [{total_new_matches}] {func['addr']} ({func['size']}B) {func['comment']}")

            if total_attempted % 200 == 0:
                print(f"  Progress: {total_attempted} attempted, {total_new_matches} matched")

    print(f"\n{'=' * 70}")
    print(f"Results: {total_new_matches} new matches out of {total_attempted} attempted")
    print(f"{'=' * 70}")

    if args.generate and total_new_matches > 0:
        print("\nGenerating matched files...")

        for fname, funcs in sorted(all_matches.items()):
            base = fname.replace('.cpp', '')
            out_path = matched_dir / f"{base}_asm_leaf.cpp"

            # Check if file already exists - append if so
            existing_addrs = set()
            if out_path.exists():
                with open(out_path, 'r') as f:
                    for m in re.finditer(r'// (0x[0-9A-Fa-f]+) \(\d+ bytes\)', f.read()):
                        existing_addrs.add(m.group(1))
                funcs = [f for f in funcs if f['addr'] not in existing_addrs]
                if not funcs:
                    continue

            # Read header from asm_decomp
            filepath = asm_dir / fname
            header, _ = parse_asm_decomp_file(filepath)

            total_bytes = sum(f['size'] for f in funcs)

            with open(out_path, 'w') as f:
                f.write('#include "types.h"\n')
                f.write(f'// Inline asm leaf matches for {base}\n')
                f.write(f'// {len(funcs)} functions, {total_bytes} bytes\n\n')
                f.write(header + '\n')

                for func in funcs:
                    f.write(f'// {func["addr"]} ({func["size"]} bytes)\n')
                    f.write(f'// {func["comment"]}\n')
                    f.write('__attribute__((noreturn))\n')
                    f.write(f'{func["signature"]} {{\n')
                    f.write(f'    __asm__ __volatile__(\n{func["asm_body"]}\n    );\n')
                    f.write('}\n\n')

            print(f"  Wrote {len(funcs)} functions ({total_bytes}B) to {out_path.name}")

    return total_new_matches


if __name__ == "__main__":
    main()
