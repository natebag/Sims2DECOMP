#!/usr/bin/env python3
"""
Extract remaining DolphinSDK XL functions (1024+ bytes) and all remaining
libgcc/libm/libc runtime functions from the Sims 2 GC ELF.

Writes:
  libs/dolphinsdk/sdk_xl.s    - DolphinSDK functions >= 1024 bytes
  libs/sn_runtime/runtime_xl.s - All remaining libgcc/libm/libc functions

Usage:
  cd "F:\\coding\\Decompiles\\Sims 2"
  python extract_and_assemble.py

Then assemble with:
  powerpc-eabi-as -mgekko -mregnames -memb libs/dolphinsdk/sdk_xl.s -o build/sdk_xl.o
  powerpc-eabi-as -mgekko -mregnames -memb libs/sn_runtime/runtime_xl.s -o build/runtime_xl.o
"""
import subprocess
import re
import os
import sys
from collections import defaultdict

# === Configuration ===
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
os.chdir(SCRIPT_DIR)

OBJDUMP = os.path.join("F:\\coding\\Decompiles\\Tools\\devkitPro\\devkitPPC\\bin",
                       "powerpc-eabi-objdump.exe")
AS = os.path.join("F:\\coding\\Decompiles\\Tools\\devkitPro\\devkitPPC\\bin",
                  "powerpc-eabi-as.exe")
ELF = os.path.join(SCRIPT_DIR, "extracted", "files", "u2_ngc_release_dvd.elf")
MAP = os.path.join(SCRIPT_DIR, "extracted", "files", "u2_ngc_release_dvd.map")

SDK_OUT = os.path.join(SCRIPT_DIR, "libs", "dolphinsdk", "sdk_xl.s")
RUNTIME_OUT = os.path.join(SCRIPT_DIR, "libs", "sn_runtime", "runtime_xl.s")


def parse_map():
    """Parse the map file to extract SDK and runtime function entries."""
    sdk_funcs = []
    runtime_funcs = []

    with open(MAP, 'r') as f:
        lines = f.readlines()

    current_obj = None
    current_lib = None  # 'sdk' or 'runtime'

    for line in lines:
        line = line.rstrip()

        # Detect object file lines (indented lines with .a( pattern)
        stripped = line.strip()
        if '.a(' in stripped and ('DolphinSDK' in stripped or 'NPDP' in stripped or 'amcstubs' in stripped):
            current_obj = stripped
            current_lib = 'sdk'
            continue
        elif '.a(' in stripped and any(x in stripped for x in ['libsn.a', 'libm.a', 'libc.a', 'libgcc.a']):
            current_obj = stripped
            current_lib = 'runtime'
            continue
        elif '.a(' in stripped or ('.obj' in stripped and not any(x in stripped for x in ['DolphinSDK', 'libsn', 'libm.a', 'libc.a', 'libgcc'])):
            # Different library or game code
            if not any(x in stripped for x in ['DolphinSDK', 'libsn', 'libm.a', 'libc.a', 'libgcc', 'NPDP', 'amcstubs']):
                current_obj = None
                current_lib = None
            continue

        if not current_obj or not current_lib:
            continue

        # Match symbol lines: address size align symbol_name
        m = re.match(r'\s*([89a-fA-F][0-9a-fA-F]{7})\s+([0-9a-fA-F]{8})\s+\d+\s+(\S.*)', line)
        if m:
            addr = int(m.group(1), 16)
            size = int(m.group(2), 16)
            name = m.group(3).strip()
            if not name or name.startswith('.') or name.startswith('<') or size == 0:
                continue

            # Extract library and object names
            obj_match = re.search(r'\.a\(([^)]+)\)', current_obj)
            obj_name = obj_match.group(1) if obj_match else "unknown"

            lib_match = re.search(r'[\\/]([^\\/]+)\.a\(', current_obj)
            lib_name = lib_match.group(1) if lib_match else "unknown"

            entry = (addr, size, name, obj_name, lib_name)
            if current_lib == 'sdk':
                sdk_funcs.append(entry)
            else:
                runtime_funcs.append(entry)

    return sdk_funcs, runtime_funcs


def get_existing_symbols():
    """Read all .global symbols from existing assembly files."""
    existing = set()
    for search_dir in ['libs', 'src']:
        base = os.path.join(SCRIPT_DIR, search_dir)
        if not os.path.exists(base):
            continue
        for root, dirs, files in os.walk(base):
            for f in files:
                if f.endswith('.s'):
                    path = os.path.join(root, f)
                    with open(path, 'r') as fh:
                        for line in fh:
                            m = re.match(r'\.global\s+(\S+)', line)
                            if m:
                                existing.add(m.group(1))
    return existing


def disassemble_function(addr, size, name):
    """Disassemble a single function from the ELF using objdump."""
    start = f"0x{addr:08x}"
    stop = f"0x{addr + size:08x}"

    try:
        result = subprocess.run(
            [OBJDUMP, "-d", "-M", "broadway",
             f"--start-address={start}", f"--stop-address={stop}", ELF],
            capture_output=True, text=True, timeout=60
        )

        if result.returncode != 0:
            return [f"    # objdump error: {result.stderr.strip()}"]

        lines = result.stdout.split('\n')

        # Parse instructions
        instructions = []
        for line in lines:
            m = re.match(
                r'\s*([0-9a-f]+):\s+([0-9a-f]{2}\s[0-9a-f]{2}\s[0-9a-f]{2}\s[0-9a-f]{2})\s+(.*)',
                line
            )
            if m:
                iaddr = int(m.group(1), 16)
                raw = m.group(3).strip()
                # Clean up objdump output
                # Remove trailing comments like "# 0x..."
                raw = re.sub(r'\s*#\s*0x[0-9a-f]+$', '', raw)
                instructions.append((iaddr, raw))

        if not instructions:
            return ["    # No instructions disassembled"]

        # Find internal branch targets
        branch_targets = set()
        for iaddr, instr in instructions:
            parts = instr.split()
            if not parts:
                continue
            mnemonic = parts[0]
            if mnemonic.startswith('b') and mnemonic not in ('blr', 'bctr', 'bctrl'):
                # Look for address operand
                for p in parts[1:]:
                    p_clean = p.strip(',')
                    if re.match(r'^[0-9a-f]{7,8}$', p_clean):
                        try:
                            target = int(p_clean, 16)
                            if addr <= target < addr + size:
                                branch_targets.add(target)
                        except ValueError:
                            pass

        # Generate output
        output = []
        for iaddr, instr in instructions:
            # Insert label if this is a branch target
            if iaddr in branch_targets:
                output.append(f".L_{iaddr:08X}:")

            # Replace branch target addresses with labels
            parts = instr.split()
            if parts and parts[0].startswith('b') and parts[0] not in ('blr', 'bctr', 'bctrl'):
                new_parts = [parts[0]]
                for j, p in enumerate(parts[1:], 1):
                    p_clean = p.strip(',')
                    has_comma = p.endswith(',')
                    if re.match(r'^[0-9a-f]{7,8}$', p_clean):
                        try:
                            target = int(p_clean, 16)
                            if addr <= target < addr + size:
                                suffix = ',' if has_comma else ''
                                new_parts.append(f".L_{target:08X}{suffix}")
                                continue
                        except ValueError:
                            pass
                    new_parts.append(p)
                instr = '\t'.join([new_parts[0], ', '.join(new_parts[1:])]) if len(new_parts) > 1 else new_parts[0]

            output.append(f"    {instr}")

        return output

    except subprocess.TimeoutExpired:
        return [f"    # TIMEOUT disassembling {name}"]
    except FileNotFoundError:
        return [f"    # ERROR: objdump not found at {OBJDUMP}"]
    except Exception as e:
        return [f"    # ERROR: {e}"]


def write_assembly_file(path, header_lines, functions_by_obj):
    """Write an assembly file with organized functions."""
    lines = list(header_lines)

    for (lib, obj), funcs in sorted(functions_by_obj.items()):
        lines.append("#")
        lines.append(f"# === {obj} ({lib}.a) ===")
        lines.append("#")
        lines.append("")

        for addr, size, name in funcs:
            sys.stdout.write(f"  {name} (0x{size:X} bytes)...")
            sys.stdout.flush()
            asm = disassemble_function(addr, size, name)
            sys.stdout.write(f" {len(asm)} instructions\n")

            lines.append(f".global {name}")
            lines.append(f".balign 4")
            lines.append(f"{name}:")
            lines.append(f"/* 0x{addr:08X} | size=0x{size:X} ({size} bytes) */")
            lines.extend(asm)
            lines.append(f".size {name}, . - {name}")
            lines.append("")

    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, 'w', newline='\n') as f:
        f.write('\n'.join(lines) + '\n')


def assemble_file(src_path, obj_path):
    """Assemble a .s file using powerpc-eabi-as."""
    os.makedirs(os.path.dirname(obj_path), exist_ok=True)
    try:
        result = subprocess.run(
            [AS, "-mgekko", "-mregnames", "-memb", src_path, "-o", obj_path],
            capture_output=True, text=True, timeout=120
        )
        if result.returncode == 0:
            print(f"  Assembled OK: {obj_path}")
        else:
            print(f"  Assembly FAILED: {result.stderr}")
        return result.returncode == 0
    except Exception as e:
        print(f"  Assembly ERROR: {e}")
        return False


def main():
    print("=" * 60)
    print("Sims 2 GC Decomp - SDK XL & Runtime Extraction")
    print("=" * 60)

    # Verify tools exist
    for tool in [OBJDUMP, AS, ELF, MAP]:
        if not os.path.exists(tool):
            print(f"ERROR: {tool} not found!")
            sys.exit(1)

    # Parse map
    print("\nParsing map file...")
    sdk_funcs, runtime_funcs = parse_map()
    print(f"  SDK functions in map: {len(sdk_funcs)}")
    print(f"  Runtime functions in map: {len(runtime_funcs)}")

    # Get existing symbols
    print("\nScanning existing assembly files...")
    existing = get_existing_symbols()
    print(f"  Already decompiled: {len(existing)} symbols")

    # Find missing SDK XL functions (>= 1024 bytes)
    sdk_xl = [(a, s, n, obj, lib) for a, s, n, obj, lib in sdk_funcs
              if s >= 1024 and n not in existing]

    # Find ALL missing runtime functions
    runtime_missing = [(a, s, n, obj, lib) for a, s, n, obj, lib in runtime_funcs
                       if n not in existing and s > 0]

    sdk_xl_bytes = sum(s for _, s, _, _, _ in sdk_xl)
    runtime_bytes = sum(s for _, s, _, _, _ in runtime_missing)

    print(f"\n  Missing SDK XL (>= 1024 bytes): {len(sdk_xl)} functions, {sdk_xl_bytes} bytes")
    for a, s, n, obj, lib in sorted(sdk_xl, key=lambda x: x[0]):
        print(f"    0x{a:08X} {s:5d}b {n} [{lib}/{obj}]")

    print(f"\n  Missing runtime: {len(runtime_missing)} functions, {runtime_bytes} bytes")
    for a, s, n, obj, lib in sorted(runtime_missing, key=lambda x: x[0]):
        print(f"    0x{a:08X} {s:5d}b {n} [{lib}/{obj}]")

    if not sdk_xl and not runtime_missing:
        print("\nNothing to do - all functions already decompiled!")
        return

    # Disassemble SDK XL functions
    if sdk_xl:
        print(f"\n{'='*60}")
        print(f"Disassembling {len(sdk_xl)} SDK XL functions...")
        print(f"{'='*60}")

        sdk_by_obj = defaultdict(list)
        for a, s, n, obj, lib in sorted(sdk_xl, key=lambda x: x[0]):
            sdk_by_obj[(lib, obj)].append((a, s, n))

        write_assembly_file(
            SDK_OUT,
            [
                "# DolphinSDK - Extra-Large functions (1024+ bytes)",
                "# Auto-generated from ELF disassembly",
                "",
                ".section .text",
                "",
            ],
            sdk_by_obj
        )
        print(f"\nWrote: {SDK_OUT}")

    # Disassemble runtime functions
    if runtime_missing:
        print(f"\n{'='*60}")
        print(f"Disassembling {len(runtime_missing)} runtime functions...")
        print(f"{'='*60}")

        runtime_by_obj = defaultdict(list)
        for a, s, n, obj, lib in sorted(runtime_missing, key=lambda x: x[0]):
            runtime_by_obj[(lib, obj)].append((a, s, n))

        write_assembly_file(
            RUNTIME_OUT,
            [
                "# SN Systems runtime - remaining libgcc, libm, libc functions",
                "# Auto-generated from ELF disassembly",
                "",
                ".section .text",
                "",
            ],
            runtime_by_obj
        )
        print(f"\nWrote: {RUNTIME_OUT}")

    # Assemble
    print(f"\n{'='*60}")
    print("Assembling...")
    print(f"{'='*60}")

    build_dir = os.path.join(SCRIPT_DIR, "build")
    os.makedirs(build_dir, exist_ok=True)

    if sdk_xl:
        assemble_file(SDK_OUT, os.path.join(build_dir, "sdk_xl.o"))
    if runtime_missing:
        assemble_file(RUNTIME_OUT, os.path.join(build_dir, "runtime_xl.o"))

    # Summary
    print(f"\n{'='*60}")
    print("SUMMARY")
    print(f"{'='*60}")
    print(f"  SDK XL functions: {len(sdk_xl)} ({sdk_xl_bytes} bytes)")
    print(f"  Runtime functions: {len(runtime_missing)} ({runtime_bytes} bytes)")
    print(f"  Total new bytes: {sdk_xl_bytes + runtime_bytes}")
    print(f"\nFiles written:")
    if sdk_xl:
        print(f"  {SDK_OUT}")
    if runtime_missing:
        print(f"  {RUNTIME_OUT}")
    print("\nDone!")


if __name__ == '__main__':
    main()
