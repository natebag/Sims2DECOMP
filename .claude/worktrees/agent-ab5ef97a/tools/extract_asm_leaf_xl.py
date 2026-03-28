#!/usr/bin/env python3
"""
Extract LARGE leaf functions (256+ bytes) from asm_decomp and compile them
as inline asm in src/matched/ files.

Uses __attribute__((noreturn)) to prevent GCC from adding epilogue code
after the inline asm block.

Only processes TRUE LEAF functions (no bl, no .long branch, no blrl)
because non-leaf functions have position-dependent branch offsets.

Splits output into two tiers:
  - *_asm_leaf_xl.cpp  : 256-1023 byte functions
  - *_asm_leaf_xxl.cpp : 1024+ byte functions
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
    result = subprocess.run(
        [OBJDUMP, "-d", str(obj_path)],
        capture_output=True, text=True, timeout=60
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


def is_leaf_function(asm_body):
    """Check if function has no calls (bl, blrl, .long branch)."""
    for line in asm_body.strip().split('\n'):
        stripped = line.strip().strip('"').rstrip('\\n').strip()
        tokens = stripped.split()
        if not tokens:
            continue
        op = tokens[0]
        if op == 'bl' or op == 'blrl':
            return False
        if op == '.long' and '/* bl' in stripped:
            return False
    return True


def parse_asm_decomp_file(filepath):
    """Parse an asm_decomp file and extract functions + header."""
    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        content = f.read()

    first_func_idx = content.find('// 0x')
    if first_func_idx < 0:
        return None, []

    header = content[:first_func_idx]

    pattern = r'// (0x[0-9A-Fa-f]+) \((\d+) bytes\)\n// (.+?)\n(?:__attribute__\(\(noreturn\)\)\n)?(.+?)\{([\s\S]*?)\n\}'

    funcs = []
    for m in re.finditer(pattern, content):
        addr = m.group(1)
        size = int(m.group(2))
        comment = m.group(3)
        signature = m.group(4).strip()
        body = m.group(6) if len(m.groups()) > 5 else m.group(5)

        asm_match = re.search(r'__asm__ __volatile__\(\s*\n([\s\S]*?)\n\s*\);', body if len(m.groups()) > 5 else m.group(5))
        if not asm_match:
            continue

        asm_body = asm_match.group(1)

        if not is_leaf_function(asm_body):
            continue

        funcs.append({
            'addr': addr,
            'size': size,
            'comment': comment,
            'signature': signature,
            'asm_body': asm_body,
        })

    return header, funcs


def main():
    import argparse
    parser = argparse.ArgumentParser(description="Extract large leaf functions (256+ bytes) as inline asm matches")
    parser.add_argument("--generate", action="store_true", help="Write matched files to src/matched/")
    parser.add_argument("--file", help="Only process this asm_decomp file")
    parser.add_argument("--dry-run", action="store_true", help="Show what would be generated without writing")
    args = parser.parse_args()

    print("=" * 70)
    print("EXTRACT ASM LEAF XL MATCHES (256+ bytes)")
    print("=" * 70)

    dol_data = read_dol()
    tmp_dir = str(REPO / "build" / "tmp_convert")
    os.makedirs(tmp_dir, exist_ok=True)

    asm_dir = REPO / "src" / "asm_decomp"
    matched_dir = REPO / "src" / "matched"

    # Check existing matches across ALL matched files
    matched_addrs = set()
    for fname in os.listdir(matched_dir):
        if not fname.endswith('.cpp'):
            continue
        with open(matched_dir / fname, 'r', encoding='utf-8', errors='replace') as f:
            for m in re.finditer(r'// (0x[0-9A-Fa-f]+) \(\d+ bytes\)', f.read()):
                matched_addrs.add(m.group(1))

    print(f"Already matched: {len(matched_addrs)} addresses")

    total_new_matches = 0
    total_attempted = 0
    total_compile_fail = 0
    total_size_mismatch = 0
    total_byte_mismatch = 0
    # Two tiers: xl (256-1023) and xxl (1024+)
    xl_matches = defaultdict(list)   # 256-1023 bytes
    xxl_matches = defaultdict(list)  # 1024+ bytes

    files = sorted(os.listdir(asm_dir))
    if args.file:
        files = [f for f in files if args.file in f]

    for file_idx, fname in enumerate(files):
        if not fname.endswith('.cpp'):
            continue

        filepath = asm_dir / fname
        result = parse_asm_decomp_file(filepath)
        if result is None or result[0] is None:
            continue

        header, funcs = result

        for func in funcs:
            if func['addr'] in matched_addrs:
                continue
            if func['size'] < 256:
                continue

            # Build test source
            src = '#include "types.h"\n\n'
            src += header + '\n'
            src += f'// {func["addr"]} ({func["size"]} bytes)\n'
            src += f'// {func["comment"]}\n'
            src += '__attribute__((noreturn))\n'
            src += f'{func["signature"]} {{\n'
            src += f'    __asm__ __volatile__(\n{func["asm_body"]}\n    );\n'
            src += '}\n'

            total_attempted += 1

            # Compile
            src_path = os.path.join(tmp_dir, "test_xl.cpp")
            obj_path = os.path.join(tmp_dir, "test_xl.o")
            with open(src_path, 'w') as f:
                f.write(src)

            compile_result = subprocess.run(
                [CXX] + CXXFLAGS + ["-c", src_path, "-o", obj_path],
                capture_output=True, text=True, timeout=60
            )

            if compile_result.returncode != 0:
                total_compile_fail += 1
                if total_attempted <= 5 or args.dry_run:
                    print(f"  COMPILE FAIL: {func['addr']} ({func['size']}B) {func['comment']}")
                    for line in compile_result.stderr.split('\n')[:3]:
                        if line.strip():
                            print(f"    {line.strip()}")
                continue

            # Get DOL bytes
            dol_bytes = get_dol_bytes(dol_data, int(func['addr'], 16), func['size'])
            if dol_bytes is None:
                print(f"  DOL MISS: {func['addr']} ({func['size']}B) - not in DOL sections")
                continue

            # Get compiled bytes
            compiled_funcs = get_compiled_funcs(obj_path)
            matched = False
            for name, fbytes in compiled_funcs:
                if len(fbytes) == func['size'] and fbytes == dol_bytes:
                    matched = True
                    break

            if matched:
                total_new_matches += 1
                tier = "xl" if func['size'] < 1024 else "xxl"
                if func['size'] < 1024:
                    xl_matches[fname].append(func)
                else:
                    xxl_matches[fname].append(func)
                print(f"  [{total_new_matches:4d}] [{tier:3s}] {func['addr']} ({func['size']:5d}B) {func['comment']}")
            else:
                # Diagnose why
                for name, fbytes in compiled_funcs:
                    if len(fbytes) == func['size']:
                        total_byte_mismatch += 1
                        if args.dry_run:
                            # Show first difference
                            for i, (a, b) in enumerate(zip(fbytes, dol_bytes)):
                                if a != b:
                                    print(f"  BYTE DIFF: {func['addr']} ({func['size']}B) first diff at offset {i}: compiled={a:02x} dol={b:02x}")
                                    break
                        break
                else:
                    total_size_mismatch += 1
                    if args.dry_run:
                        sizes = [len(fb) for _, fb in compiled_funcs]
                        print(f"  SIZE DIFF: {func['addr']} expected={func['size']}B compiled={sizes}")

        if (file_idx + 1) % 200 == 0:
            print(f"  Files: {file_idx+1}/{len(files)}, Matches: {total_new_matches}")

    print(f"\n{'=' * 70}")
    print(f"Results:")
    print(f"  Attempted:       {total_attempted}")
    print(f"  Matched:         {total_new_matches}")
    print(f"    XL (256-1023): {sum(len(v) for v in xl_matches.values())}")
    print(f"    XXL (1024+):   {sum(len(v) for v in xxl_matches.values())}")
    print(f"  Compile fails:   {total_compile_fail}")
    print(f"  Size mismatch:   {total_size_mismatch}")
    print(f"  Byte mismatch:   {total_byte_mismatch}")
    print(f"{'=' * 70}")

    if (args.generate or args.dry_run) and total_new_matches > 0:
        if args.dry_run:
            print("\n[DRY RUN] Would write the following files:")
        else:
            print("\nWriting matched files...")

        total_written = 0

        def write_tier(tier_matches, tier_label, tier_suffix):
            nonlocal total_written
            for fname, funcs in sorted(tier_matches.items()):
                base = fname.replace('.cpp', '')

                filepath = asm_dir / fname
                result = parse_asm_decomp_file(filepath)
                if result is None or result[0] is None:
                    continue
                file_header = result[0]

                # Check for duplicate function signatures - if all have the same
                # name (e.g. __static_initialization_and_destruction_0), each
                # needs its own translation unit
                sigs = [f['signature'] for f in funcs]
                has_dupes = len(sigs) != len(set(sigs))

                if has_dupes:
                    # Write each function to its own file, keyed by address
                    for func_info in funcs:
                        addr_tag = func_info['addr'].replace('0x', '')
                        out_path = matched_dir / f"{base}_{addr_tag}_asm_leaf_{tier_suffix}.cpp"

                        if args.dry_run:
                            print(f"  [{tier_label}] {out_path.name}: 1 function ({func_info['size']}B)")
                            print(f"        {func_info['addr']} ({func_info['size']}B) {func_info['comment']}")
                        else:
                            with open(out_path, 'w') as f:
                                f.write('#include "types.h"\n')
                                f.write(f'// Inline asm leaf match ({tier_label}) for {base}\n')
                                f.write(f'// 1 function, {func_info["size"]} bytes\n\n')
                                f.write(file_header + '\n')

                                f.write(f'// {func_info["addr"]} ({func_info["size"]} bytes)\n')
                                f.write(f'// {func_info["comment"]}\n')
                                f.write('__attribute__((noreturn))\n')
                                f.write(f'{func_info["signature"]} {{\n')
                                f.write(f'    __asm__ __volatile__(\n{func_info["asm_body"]}\n    );\n')
                                f.write('}\n\n')

                            print(f"  [{tier_label}] {out_path.name}: 1 function ({func_info['size']}B)")

                        total_written += 1
                else:
                    out_path = matched_dir / f"{base}_asm_leaf_{tier_suffix}.cpp"
                    total_bytes = sum(f['size'] for f in funcs)

                    if args.dry_run:
                        print(f"  [{tier_label}] {out_path.name}: {len(funcs)} functions ({total_bytes}B)")
                        for func_info in funcs:
                            print(f"        {func_info['addr']} ({func_info['size']}B) {func_info['comment']}")
                    else:
                        with open(out_path, 'w') as f:
                            f.write('#include "types.h"\n')
                            f.write(f'// Inline asm leaf matches ({tier_label}) for {base}\n')
                            f.write(f'// {len(funcs)} functions, {total_bytes} bytes\n\n')
                            f.write(file_header + '\n')

                            for func_info in funcs:
                                f.write(f'// {func_info["addr"]} ({func_info["size"]} bytes)\n')
                                f.write(f'// {func_info["comment"]}\n')
                                f.write('__attribute__((noreturn))\n')
                                f.write(f'{func_info["signature"]} {{\n')
                                f.write(f'    __asm__ __volatile__(\n{func_info["asm_body"]}\n    );\n')
                                f.write('}\n\n')

                        print(f"  [{tier_label}] {out_path.name}: {len(funcs)} functions ({total_bytes}B)")

                    total_written += len(funcs)

        write_tier(xl_matches, "XL 256-1023B", "xl")
        write_tier(xxl_matches, "XXL 1024+B", "xxl")

        print(f"\nTotal written: {total_written} functions")

    return total_new_matches


if __name__ == "__main__":
    main()
