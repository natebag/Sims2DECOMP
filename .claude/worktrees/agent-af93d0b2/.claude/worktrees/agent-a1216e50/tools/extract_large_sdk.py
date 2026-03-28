#!/usr/bin/env python3
"""Extract large SDK functions (257-1024 bytes) from the Sims 2 GC ELF and generate assembly files."""

import re
import subprocess
import sys
import os

OBJDUMP = r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC\bin\powerpc-eabi-objdump.exe"
ELF = r"F:\coding\Decompiles\Sims 2\extracted\files\u2_ngc_release_dvd.elf"
MAP = r"F:\coding\Decompiles\Sims 2\extracted\files\u2_ngc_release_dvd.map"

# Libraries to process
OS_LIBS = ['os.a']
HW_LIBS = ['dvd.a', 'gx.a', 'mtx.a', 'vi.a', 'pad.a', 'exi.a', 'si.a', 'ai.a', 'db.a']


def build_symbol_table():
    """Build a complete address -> symbol name lookup from the map file."""
    with open(MAP, 'r') as f:
        lines = f.readlines()

    symbols = {}
    for line in lines:
        line = line.rstrip()
        m = re.match(r'^([0-9a-f]{8})\s+([0-9a-f]{8})\s+\d+\s+(.+)$', line)
        if m:
            addr = int(m.group(1), 16)
            size = int(m.group(2), 16)
            name = m.group(3).strip()
            # Only add function/data symbols (size > 0, not file/section entries)
            if size > 0 and addr >= 0x80003100 and '(' not in name and '<' not in name:
                # Skip duplicate addresses - keep first (more specific) symbol
                if addr not in symbols:
                    symbols[addr] = name
            elif size == 0 and addr >= 0x80003100 and '(' not in name and '<' not in name:
                # Zero-size symbols are usually aliases/labels - still useful
                if addr not in symbols:
                    symbols[addr] = name

    return symbols


def parse_map():
    """Parse the map file for SDK functions 257-1024 bytes."""
    with open(MAP, 'r') as f:
        lines = f.readlines()

    target_libs = OS_LIBS + HW_LIBS
    pat_libobj = re.compile(r'lib[/\\]([\w.]+)\(([\w.]+)\)')

    current_lib = None
    current_obj = None
    funcs = []

    for line in lines:
        line = line.rstrip()
        m = re.match(r'^([0-9a-f]{8})\s+([0-9a-f]{8})\s+\d+\s+(.+)$', line)
        if m:
            addr_str, size_str, path = m.group(1), m.group(2), m.group(3).strip()
            if 'DolphinSDK1.0' in path:
                if any(lib in path for lib in target_libs):
                    lib_match = pat_libobj.search(path)
                    if lib_match:
                        current_lib = lib_match.group(1)
                        current_obj = lib_match.group(2)
                else:
                    current_lib = None
                    current_obj = None
                continue
            elif '.o)' in path or '.obj)' in path or '<default>' in path:
                current_lib = None
                current_obj = None
                continue

        if current_lib:
            sm = re.match(r'^([0-9a-f]{8})\s+([0-9a-f]{8})\s+\d+\s+(.+)$', line)
            if sm:
                addr = int(sm.group(1), 16)
                size = int(sm.group(2), 16)
                name = sm.group(3).strip()
                if size >= 0x101 and size <= 0x400 and addr >= 0x80003100 and addr < 0x80400000:
                    funcs.append({
                        'addr': addr,
                        'size': size,
                        'name': name,
                        'lib': current_lib,
                        'obj': current_obj,
                    })

    return funcs


def disasm_range(start, end):
    """Disassemble a range of the ELF and return cleaned assembly lines."""
    result = subprocess.run(
        [OBJDUMP, '-d', '-M', 'gekko,broadway', '--no-show-raw-insn',
         f'--start-address=0x{start:08x}', f'--stop-address=0x{end:08x}', ELF],
        capture_output=True, text=True, timeout=30
    )

    lines = []
    for raw in result.stdout.splitlines():
        raw = raw.rstrip()
        # Skip non-instruction lines
        if not raw or raw.startswith('Disassembly') or '<' in raw or 'file format' in raw:
            continue

        # Instruction line: "80xxxxxx:\tinstruction" or "  80xxxxxx:\tinstruction"
        m = re.match(r'\s*([0-9a-f]{8}):\s+(.+)', raw)
        if m:
            addr_val = int(m.group(1), 16)
            insn = m.group(2).strip()
            lines.append((addr_val, insn))

    return lines


# Branch mnemonics (all variants)
BRANCH_MNEMONICS = {
    'b', 'bl', 'ba', 'bla',
    'beq', 'bne', 'blt', 'bgt', 'ble', 'bge',
    'bdnz', 'bdz',
    'bso', 'bns',
    'bc', 'bcl', 'bca', 'bcla',
    'blr', 'bctr', 'bctrl', 'blrl',
    'bgelr', 'blelr', 'bnelr', 'beqlr', 'bltlr', 'bgtlr',
    'bsoctr', 'bnsctr',
    'beqctr', 'bnectr', 'bltctr', 'bgtctr', 'blectr', 'bgectr',
}

def get_branch_mnemonic(insn_text):
    """Extract the base mnemonic and determine if it's a branch with a target address."""
    parts = insn_text.split('\t', 1)
    if len(parts) < 2:
        parts = insn_text.split(None, 1)
    if len(parts) < 2:
        return None, None, None

    raw_mnemonic = parts[0].strip()
    operand = parts[1].strip()

    # Strip branch prediction hints for matching
    base = raw_mnemonic.rstrip('+').rstrip('-')

    if base in BRANCH_MNEMONICS:
        return raw_mnemonic, base, operand

    return None, None, None


def format_branch_labels(lines, func_start, func_end, func_name, sym_table):
    """Add local branch labels for intra-function branches, resolve external calls."""
    # First pass: find all branch targets within the function
    branch_targets = set()

    for addr, insn in lines:
        raw_mn, base_mn, operand = get_branch_mnemonic(insn)
        if raw_mn and operand:
            bm = re.search(r'(0x[0-9a-f]+)', operand)
            if bm:
                target = int(bm.group(1), 16)
                if func_start <= target < func_end:
                    branch_targets.add(target)

    # Second pass: generate assembly with labels
    output = []
    for addr, insn in lines:
        if addr in branch_targets:
            output.append(f'.L_{addr:08X}:')

        new_insn = insn
        raw_mn, base_mn, operand = get_branch_mnemonic(insn)
        if raw_mn and operand:
            bm = re.search(r'(0x[0-9a-f]+)', operand)
            if bm:
                target = int(bm.group(1), 16)
                if func_start <= target < func_end:
                    # Internal branch - use local label
                    new_operand = operand.replace(bm.group(1), f'.L_{target:08X}')
                    new_insn = f'{raw_mn}\t{new_operand}'
                else:
                    # External branch - resolve to symbol name
                    sym_name = sym_table.get(target)
                    if sym_name:
                        new_operand = operand.replace(bm.group(1), sym_name)
                        new_insn = f'{raw_mn}\t{new_operand}'
                    else:
                        # Can't resolve - use .long with raw instruction encoding
                        # For now, leave as comment and use a stub
                        new_insn = f'{raw_mn}\t{operand}  /* UNRESOLVED: 0x{target:08X} */'

        output.append(f'    {new_insn}')

    return output


def generate_asm(funcs, output_path, title, lib_filter, sym_table):
    """Generate an assembly file for a set of functions."""
    filtered = [f for f in funcs if f['lib'] in lib_filter]
    filtered.sort(key=lambda x: (x['lib'], x['obj'], x['addr']))

    # Detect duplicate symbol names and disambiguate
    name_counts = {}
    for f in filtered:
        name_counts[f['name']] = name_counts.get(f['name'], 0) + 1

    # For duplicates, prefix with obj file name (sans .o)
    for f in filtered:
        if name_counts[f['name']] > 1:
            obj_prefix = f['obj'].replace('.o', '')
            f['asm_name'] = f'{obj_prefix}_{f["name"]}'
        else:
            f['asm_name'] = f['name']

    print(f"Generating {output_path} with {len(filtered)} functions...")

    from collections import OrderedDict
    groups = OrderedDict()
    for f in filtered:
        key = (f['lib'], f['obj'])
        if key not in groups:
            groups[key] = []
        groups[key].append(f)

    out_lines = []
    out_lines.append(f'# {title}')
    out_lines.append('# Auto-generated from ELF disassembly')
    out_lines.append('# Functions in the 257-1024 byte range')
    out_lines.append('')
    out_lines.append('.section .text')

    count = 0
    unresolved_count = 0
    for (lib, obj), obj_funcs in groups.items():
        out_lines.append('')
        out_lines.append('#')
        out_lines.append(f'# === {obj} ({lib}) ===')
        out_lines.append('#')

        for f in obj_funcs:
            name = f['name']
            asm_name = f['asm_name']
            addr = f['addr']
            size = f['size']
            end = addr + size

            # Disassemble
            disasm = disasm_range(addr, end)
            if not disasm:
                out_lines.append(f'# ERROR: Could not disassemble {name} @ 0x{addr:08X}')
                continue

            # Format with resolved branches
            asm_lines = format_branch_labels(disasm, addr, end, name, sym_table)

            # Count unresolved
            for l in asm_lines:
                if 'UNRESOLVED' in l:
                    unresolved_count += 1

            out_lines.append('')
            if asm_name != name:
                out_lines.append(f'# Original symbol: {name}')
            out_lines.append(f'.global {asm_name}')
            out_lines.append('.balign 4')
            out_lines.append(f'{asm_name}:')
            out_lines.append(f'/* 0x{addr:08X} | size=0x{size:X} ({size} bytes) */')
            out_lines.extend(asm_lines)
            out_lines.append(f'.size {asm_name}, . - {asm_name}')

            count += 1
            if count % 20 == 0:
                print(f"  ... {count}/{len(filtered)} done")

    with open(output_path, 'w', newline='\n') as f:
        f.write('\n'.join(out_lines) + '\n')

    print(f"Wrote {count} functions to {output_path}")
    if unresolved_count > 0:
        print(f"  WARNING: {unresolved_count} unresolved external references")
    return count


def main():
    print("Building symbol table from map file...")
    sym_table = build_symbol_table()
    print(f"  {len(sym_table)} symbols loaded")

    funcs = parse_map()
    print(f"Found {len(funcs)} SDK functions (257-1024 bytes)")

    base = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    sdk_dir = os.path.join(base, 'libs', 'dolphinsdk')

    os_count = generate_asm(funcs, os.path.join(sdk_dir, 'os_large.s'),
                           'DolphinSDK os.a - Large functions (257-1024 bytes)', OS_LIBS, sym_table)

    hw_count = generate_asm(funcs, os.path.join(sdk_dir, 'hw_large.s'),
                           'DolphinSDK hardware libraries - Large functions (257-1024 bytes)', HW_LIBS, sym_table)

    print(f"\nTotal: {os_count + hw_count} functions extracted")


if __name__ == '__main__':
    main()
