#!/usr/bin/env python3
"""
Generate linker stubs to bridge GCC-mangled and SN Systems-mangled symbol names.

This script:
1. Finds all undefined symbols in compiled decomp object files
2. Matches them against skeleton-defined symbols (SN Systems naming)
3. Generates a linker script fragment with PROVIDE() aliases for matched symbols
4. Generates an assembly file with stub definitions for unmatched symbols

Output files:
    config/symbol_aliases.ld  - Linker script fragment (included by ldscript.lcf)
    src/linker_stubs.s        - Assembly stubs for truly-missing symbols

Usage:
    python tools/gen_linker_stubs.py
"""

import subprocess
import re
import os
import glob
import sys
from collections import defaultdict

# Toolchain paths - hardcoded for this project
DEVKITPPC = 'F:/coding/Decompiles/Tools/devkitPro/devkitPPC'
NM = f'{DEVKITPPC}/bin/powerpc-eabi-nm.exe'
CXXFILT = f'{DEVKITPPC}/bin/powerpc-eabi-c++filt.exe'

BUILD_DIR = 'build'
SKELETON_DIR = f'{BUILD_DIR}/skeleton'
OBJ_DIR = f'{BUILD_DIR}/obj'
OUTPUT_LD = 'config/symbol_aliases.ld'
OUTPUT_ASM = 'src/linker_stubs.s'
SYMBOLS_FILE = 'config/symbols.txt'


def run_nm(obj_path, flags=''):
    """Run nm on an object file and return output lines."""
    obj_path = obj_path.replace('\\', '/')
    cmd = [NM]
    if flags:
        cmd.extend(flags.split())
    cmd.append(obj_path)
    result = subprocess.run(cmd, capture_output=True, text=True)
    return result.stdout.strip().split('\n')


def demangle(symbols):
    """Demangle a list of symbols using c++filt."""
    if not symbols:
        return []
    result = subprocess.run(
        [CXXFILT],
        input='\n'.join(symbols),
        capture_output=True, text=True
    )
    return result.stdout.strip().split('\n')


def collect_undefined_symbols():
    """Collect all undefined symbols from decomp object files."""
    obj_files = []
    for root, dirs, files in os.walk(OBJ_DIR):
        for f in files:
            if f.endswith('.o'):
                obj_files.append(os.path.join(root, f))

    undef = set()
    for obj in obj_files:
        for line in run_nm(obj, '-u'):
            line = line.strip()
            if line.startswith('U '):
                sym = line[2:].strip()
                undef.add(sym)

    return undef


def collect_defined_symbols():
    """Collect all defined symbols from skeleton and decomp objects."""
    skel_defined = {}
    for obj in glob.glob(f'{SKELETON_DIR}/*.o'):
        for line in run_nm(obj.replace('\\', '/')):
            parts = line.strip().split()
            if len(parts) >= 3:
                skel_defined[parts[2]] = parts[1]

    decomp_defined = set()
    for root, dirs, files in os.walk(OBJ_DIR):
        for f in files:
            if f.endswith('.o'):
                obj = os.path.join(root, f)
                for line in run_nm(obj, '--defined-only'):
                    parts = line.strip().split()
                    if len(parts) >= 3:
                        decomp_defined.add(parts[2])

    return skel_defined, decomp_defined


def read_symbols_txt():
    """Read symbols.txt for section/size info."""
    sym_info = {}
    with open(SYMBOLS_FILE) as f:
        for line in f:
            m = re.match(r'^(\S+)\s*=\s*\.(\w+):0x([0-9A-Fa-f]+);\s*//\s*(.*)', line)
            if m:
                name, section, addr, rest = m.groups()
                size_m = re.search(r'size:0x([0-9A-Fa-f]+)', rest)
                size = int(size_m.group(1), 16) if size_m else 0
                kind = "function" if "type:function" in rest else "object"
                sym_info[name] = {
                    'section': section,
                    'addr': int(addr, 16),
                    'size': size,
                    'kind': kind,
                }
    return sym_info


def convert_demangled_to_sn(dem):
    """Convert a demangled C++ name to SN Systems skeleton style."""
    name = dem.strip()

    # Split into base and args
    depth = 0
    paren_pos = -1
    for i, ch in enumerate(name):
        if ch == '<':
            depth += 1
        elif ch == '>':
            depth -= 1
        elif ch == '(' and depth == 0:
            paren_pos = i
            break

    const_suffix = ''
    if paren_pos >= 0:
        base = name[:paren_pos]
        remainder = name[paren_pos:]
        if remainder.endswith(') const'):
            args_str = remainder[1:-len(') const')].strip()
            const_suffix = '__const'
        else:
            args_str = remainder[1:-1].strip()
        has_args = True
    else:
        base = name
        args_str = None
        has_args = False

    # Convert base: :: -> __, ~X -> dtor_X
    sn_base = base.replace('::', '__')
    sn_base = re.sub(r'~(\w+)', r'dtor_\1', sn_base)

    if not has_args:
        return sn_base + const_suffix

    if args_str == '' or args_str == 'void':
        return sn_base + '_void' + const_suffix

    # Parse args (split by comma at depth 0)
    arg_list = []
    depth = 0
    current = ''
    for ch in args_str:
        if ch in '<(':
            depth += 1
            current += ch
        elif ch in '>)':
            depth -= 1
            current += ch
        elif ch == ',' and depth == 0:
            arg_list.append(current.strip())
            current = ''
        else:
            current += ch
    if current.strip():
        arg_list.append(current.strip())

    sn_parts = []
    for arg in arg_list:
        a = arg.strip()
        a = re.sub(r'\bconst\s*\*', '_ptr', a)
        a = re.sub(r'\*\s*const\b', '_ptr', a)
        a = a.replace('*', '_ptr')
        a = a.replace('&', '_ref')
        a = re.sub(r'\bconst\b', '', a)
        a = a.replace('::', '__')
        a = a.strip()
        a = re.sub(r'\s+', '_', a)
        a = re.sub(r'_+', '_', a)
        a = a.strip('_')
        sn_parts.append(a)

    return sn_base + '_' + '__'.join(sn_parts) + const_suffix


def find_skeleton_match(mangled, demangled, skel_defined):
    """Try to find a skeleton symbol that matches this GCC undefined symbol."""
    is_cpp = mangled.startswith('_Z')

    # Strategy 1: Direct SN conversion for C++ symbols
    if is_cpp:
        sn = convert_demangled_to_sn(demangled)
        if sn in skel_defined:
            return sn

    # Strategy 2: For C/simple symbols, try base name with common suffixes
    base = demangled.split('(')[0].strip().replace('::', '__')

    for suffix in ['_void', '']:
        candidate = base + suffix
        if candidate in skel_defined:
            return candidate

    # Strategy 3: Unique prefix match
    candidates = [s for s in skel_defined if s == base or s.startswith(base + '_')]

    if len(candidates) == 1:
        return candidates[0]

    if len(candidates) > 1 and '(' in demangled:
        sn = convert_demangled_to_sn(demangled)
        if sn in skel_defined:
            return sn
        for try_name in [sn, sn.replace('__const', '')]:
            fuzzy = [c for c in candidates if c.startswith(try_name)]
            if len(fuzzy) == 1:
                return fuzzy[0]

    return None


def sanitize_asm_name(name):
    """Make a name safe for GAS assembly."""
    name = name.replace('|', '_OR_')
    name = name.replace('^', '_XOR_')
    if name.startswith('@'):
        name = '_anon_' + name[1:]
    return name


def generate_linker_aliases(aliases, stubs):
    """Generate a linker script fragment with PROVIDE() statements.

    - Aliases: map GCC mangled name to the skeleton symbol
    - Stubs: define as address 0 (placeholder until decompiled)
    """
    lines = []
    lines.append("/* Auto-generated symbol definitions for the linker */")
    lines.append("/* Bridges the naming gap between GCC Itanium mangling and SN Systems mangling */")
    lines.append("/* Generated by tools/gen_linker_stubs.py - DO NOT EDIT */")
    lines.append("")

    if aliases:
        lines.append("/* ========== ALIASES: GCC mangled -> SN Systems skeleton ========== */")
        lines.append("")
        for gcc_mangled, skel_name, demangled in sorted(aliases, key=lambda x: x[2]):
            safe_skel = sanitize_asm_name(skel_name)
            lines.append(f"/* {demangled} */")
            lines.append(f"PROVIDE({gcc_mangled} = {safe_skel});")
        lines.append("")

    if stubs:
        # Stub addresses within the valid memory range to avoid relocation overflow.
        # Functions point to a blr instruction in .text range.
        # Data symbols point to .bss range.
        # These addresses are within the skeleton's address space.
        STUB_FUNC_ADDR = "0x800034C0"   # Start of .text (will overlap but --allow-multiple-definition handles it)
        STUB_DATA_ADDR = "0x8046E1E0"   # Start of .bss

        lines.append("/* ========== STUBS: Symbols not found in skeleton ========== */")
        lines.append("/* Placeholders at valid addresses to avoid relocation overflow. */")
        lines.append("/* They will be replaced as more code is decompiled. */")
        lines.append("")
        for gcc_mangled, demangled in sorted(stubs, key=lambda x: x[1]):
            # Heuristic: if demangled has () it's likely a function
            is_func = '(' in demangled
            addr = STUB_FUNC_ADDR if is_func else STUB_DATA_ADDR
            lines.append(f"/* {demangled} */")
            lines.append(f"PROVIDE({gcc_mangled} = {addr});")
        lines.append("")

    return '\n'.join(lines) + '\n'


def generate_stubs_asm(stubs):
    """Generate empty assembly file (stubs are now in linker script)."""
    lines = []
    lines.append("# Auto-generated linker stubs placeholder")
    lines.append("# All stub definitions are now in config/symbol_aliases.ld as PROVIDE() statements")
    lines.append("# Generated by tools/gen_linker_stubs.py - DO NOT EDIT")
    lines.append("")
    return '\n'.join(lines) + '\n'


def main():
    print("Collecting undefined symbols from decomp objects...")
    undef = collect_undefined_symbols()
    print(f"  Found {len(undef)} undefined symbols")

    print("Collecting defined symbols from skeleton and decomp objects...")
    skel_defined, decomp_defined = collect_defined_symbols()
    print(f"  Skeleton: {len(skel_defined)} symbols")
    print(f"  Decomp: {len(decomp_defined)} symbols")

    # Filter to truly undefined
    truly_undef = undef - set(skel_defined.keys()) - decomp_defined
    print(f"  Truly undefined: {len(truly_undef)}")

    if not truly_undef:
        print("No undefined symbols - nothing to do!")
        return

    # Demangle
    print("Demangling symbols...")
    sorted_undef = sorted(truly_undef)
    demangled = demangle(sorted_undef)
    demangle_map = dict(zip(sorted_undef, demangled))

    # Match symbols
    print("Matching symbols to skeleton...")
    aliases = []
    stubs = []

    for mangled in sorted_undef:
        dem = demangle_map[mangled]
        match = find_skeleton_match(mangled, dem, skel_defined)
        if match:
            aliases.append((mangled, match, dem))
        else:
            stubs.append((mangled, dem))

    print(f"  Aliases (GCC -> skeleton): {len(aliases)}")
    print(f"  Stubs (truly missing): {len(stubs)}")

    # Generate linker script with both aliases and stubs
    print(f"Generating {OUTPUT_LD}...")
    ld_content = generate_linker_aliases(aliases, stubs)
    os.makedirs(os.path.dirname(OUTPUT_LD), exist_ok=True)
    with open(OUTPUT_LD, 'w') as f:
        f.write(ld_content)
    print(f"  {len(aliases)} PROVIDE() aliases + {len(stubs)} PROVIDE() stubs")

    # Generate assembly stubs
    print(f"Generating {OUTPUT_ASM}...")
    asm_content = generate_stubs_asm(stubs)
    os.makedirs(os.path.dirname(OUTPUT_ASM), exist_ok=True)
    with open(OUTPUT_ASM, 'w') as f:
        f.write(asm_content)
    print(f"  {len(stubs)} stub definitions")

    print(f"\nDone! {len(aliases)} aliases + {len(stubs)} stubs = {len(aliases) + len(stubs)} total")

    if aliases:
        print("\nSample aliases:")
        for gcc, skel, dem in aliases[:5]:
            print(f"  {dem:50s} -> {skel}")

    if stubs:
        print(f"\nSample stubs:")
        for gcc, dem in stubs[:5]:
            print(f"  {dem}")


if __name__ == '__main__':
    main()
