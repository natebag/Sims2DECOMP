"""
Extract small DolphinSDK functions from the ELF and generate .s assembly files.
Resolves branch targets to symbol names and internal labels.
"""
import re
import subprocess
import sys
import os

OBJDUMP = r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC\bin\powerpc-eabi-objdump.exe"
ELF = r"F:\coding\Decompiles\Sims 2\extracted\files\u2_ngc_release_dvd.elf"
MAP = r"F:\coding\Decompiles\Sims 2\extracted\files\u2_ngc_release_dvd.map"

BACKSLASH = chr(92)


def build_symbol_table():
    """Build a map of address -> symbol name from the map file."""
    symbols = {}
    with open(MAP, 'r') as f:
        for line in f:
            stripped = line.rstrip()
            m = re.match(r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+\d+\s+(\S.+)$', stripped)
            if m:
                addr = int(m.group(1), 16)
                size = int(m.group(2), 16)
                name = m.group(3).strip()
                if BACKSLASH in name or '/' in name or '.a(' in name:
                    continue
                if addr >= 0x80003100 and addr < 0x81000000:
                    # Don't overwrite existing entries (first one wins)
                    if addr not in symbols:
                        symbols[addr] = name
    return symbols


def parse_map():
    with open(MAP, 'r') as f:
        lines = f.readlines()

    target_libs = ['os.a', 'exi.a', 'si.a', 'vi.a', 'pad.a', 'ai.a', 'dvd.a']
    current_lib = None
    current_obj = None
    in_text_section = False
    results_os = []
    results_hw = []

    for line in lines:
        stripped = line.rstrip()

        m_sec = re.match(r'^([0-9a-fA-F]{8})\s+[0-9a-fA-F]+\s+\d+\s+(\.\w+)', stripped)
        if m_sec:
            sec_name = m_sec.group(2)
            if sec_name in ('.text', '.init'):
                in_text_section = True
            else:
                in_text_section = False
                current_lib = None
            continue

        if 'DolphinSDK' in stripped:
            for lib in target_libs:
                pat = lib + '('
                if pat in stripped:
                    current_lib = lib
                    mm = re.search(r'\(([^)]+)\)', stripped.split(lib)[1])
                    if mm:
                        current_obj = mm.group(1)
                    break
            else:
                current_lib = None
            continue

        if '.obj' in stripped:
            current_lib = None
            continue

        if '.a(' in stripped and not any(lib + '(' in stripped for lib in target_libs):
            current_lib = None
            continue

        if current_lib and in_text_section:
            m = re.match(r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+\d+\s+(\S.+)$', stripped)
            if m:
                addr_s = m.group(1)
                size_s = m.group(2)
                name = m.group(3).strip()

                if BACKSLASH in name or '/' in name:
                    current_lib = None
                    continue

                addr = int(addr_s, 16)
                size = int(size_s, 16)

                if size > 0 and size <= 0x40 and addr >= 0x80003100:
                    entry = (addr, size, name, current_lib, current_obj)
                    if current_lib == 'os.a':
                        results_os.append(entry)
                    else:
                        results_hw.append(entry)

    return results_os, results_hw


def disassemble_function(addr, size):
    """Disassemble a function from the ELF using objdump."""
    start = f"0x{addr:08x}"
    end = f"0x{addr + size:08x}"

    result = subprocess.run(
        [OBJDUMP, "-d", "-M", "gekko,broadway",
         f"--start-address={start}", f"--stop-address={end}",
         ELF],
        capture_output=True, text=True, timeout=30
    )

    insns = []
    for line in result.stdout.split('\n'):
        m = re.match(r'^\s*([0-9a-fA-F]+):\s+([0-9a-fA-F]{2}\s[0-9a-fA-F]{2}\s[0-9a-fA-F]{2}\s[0-9a-fA-F]{2})\s+(.+)$', line)
        if m:
            insn_addr = int(m.group(1), 16)
            raw_bytes = m.group(2)
            insn_text = m.group(3).strip()
            hex_word = int(raw_bytes.replace(' ', ''), 16)
            insns.append((insn_addr, hex_word, insn_text))

    return insns


# Branch instruction patterns
BRANCH_RE = re.compile(r'^(b[a-z]*)\s+(0x[0-9a-fA-F]+)$')
BRANCH_COND_RE = re.compile(r'^(b[a-z]*[+-]?)\s+(0x[0-9a-fA-F]+)$')


def fix_instruction(insn_addr, hex_word, insn_text, func_addr, func_size, symbol_table, local_labels):
    """Fix branch targets to use symbol names or local labels."""
    text = insn_text.strip()

    # Remove trailing comments
    if '#' in text:
        text = text[:text.index('#')].strip()

    # Check for branch instructions with absolute addresses
    # Matches: bl 0xADDR, b 0xADDR, beq 0xADDR, bne+ 0xADDR, etc.
    m = re.match(r'^(b[a-z]*[+-]?)\s+(cr\d,\s*)?(0x[0-9a-fA-F]+)$', text)
    if m:
        mnemonic = m.group(1)
        cr_field = m.group(2) or ''
        target_addr = int(m.group(3), 16)

        # Is it within this function? -> local label
        if func_addr <= target_addr < func_addr + func_size:
            label = f".L_{target_addr:08X}"
            local_labels.add(target_addr)
            return f"{mnemonic} {cr_field}{label}"
        else:
            # Look up in symbol table
            sym = symbol_table.get(target_addr)
            if sym:
                return f"{mnemonic} {cr_field}{sym}"
            else:
                # Emit as raw .4byte with comment
                return None  # Signal to use .4byte

    return text


def generate_asm(functions, output_path, header_comment, symbol_table):
    """Generate a .s assembly file from a list of functions."""

    # Group by object file
    obj_groups = {}
    for addr, size, name, lib, obj in functions:
        key = f"{lib}({obj})" if lib != 'os.a' else obj
        if key not in obj_groups:
            obj_groups[key] = []
        obj_groups[key].append((addr, size, name, obj))

    # Detect duplicate names and disambiguate
    name_counts = {}
    for addr, size, name, lib, obj in functions:
        if name not in name_counts:
            name_counts[name] = []
        name_counts[name].append((addr, obj))

    # Build a mapping from (addr, name) -> disambiguated name
    name_map = {}
    for name, entries in name_counts.items():
        if len(entries) > 1:
            for addr, obj in entries:
                obj_base = obj.replace('.o', '')
                name_map[(addr, name)] = f"{name}__{obj_base}"
        else:
            addr, obj = entries[0]
            name_map[(addr, name)] = name

    # First pass: disassemble everything and collect local labels
    all_func_data = {}
    for obj_key in obj_groups:
        funcs = sorted(obj_groups[obj_key], key=lambda x: x[0])
        for addr, size, name, obj in funcs:
            insns = disassemble_function(addr, size)
            local_labels = set()

            # First pass to find local labels
            fixed_insns = []
            for insn_addr, hex_word, insn_text in insns:
                fixed = fix_instruction(insn_addr, hex_word, insn_text, addr, size, symbol_table, local_labels)
                fixed_insns.append((insn_addr, hex_word, insn_text, fixed))

            label = name_map.get((addr, name), name)
            all_func_data[(addr, name)] = (insns, fixed_insns, local_labels, size, label)

    lines = []
    lines.append(f"# {header_comment}")
    lines.append(f"# Auto-generated from ELF disassembly")
    lines.append(f"# Small functions (<= 64 bytes)")
    lines.append(f"")
    lines.append(f".section .text")
    lines.append(f"")

    total = 0
    failed = 0

    for obj_key in obj_groups:
        funcs = sorted(obj_groups[obj_key], key=lambda x: x[0])
        lines.append(f"#")
        lines.append(f"# === {obj_key} ===")
        lines.append(f"#")
        lines.append(f"")

        for addr, size, name, obj in funcs:
            insns, fixed_insns, local_labels, _, label = all_func_data[(addr, name)]
            total += 1

            if not insns:
                lines.append(f"# FAILED TO DISASSEMBLE: {name} @ 0x{addr:08X} (size=0x{size:02X})")
                lines.append(f"")
                failed += 1
                continue

            lines.append(f".global {label}")
            lines.append(f".balign 4")
            lines.append(f"{label}:")
            if label != name:
                lines.append(f"/* 0x{addr:08X} | size=0x{size:02X} ({size} bytes) | original: {name} */")
            else:
                lines.append(f"/* 0x{addr:08X} | size=0x{size:02X} ({size} bytes) */")

            for insn_addr, hex_word, insn_text, fixed in fixed_insns:
                # Add local label if needed
                if insn_addr in local_labels:
                    lines.append(f".L_{insn_addr:08X}:")

                if fixed is None:
                    # Could not resolve branch target, use raw bytes
                    lines.append(f"    .4byte 0x{hex_word:08X}  /* {insn_text} */")
                else:
                    lines.append(f"    {fixed}")

            lines.append(f".size {label}, . - {label}")
            lines.append(f"")

    os.makedirs(os.path.dirname(output_path), exist_ok=True)
    with open(output_path, 'w', newline='\n') as f:
        f.write('\n'.join(lines))

    return total, failed


def main():
    print("Building symbol table from map file...")
    symbol_table = build_symbol_table()
    print(f"  {len(symbol_table)} symbols loaded")

    print("Parsing map file for small functions...")
    os_funcs, hw_funcs = parse_map()
    print(f"  Found {len(os_funcs)} os.a functions, {len(hw_funcs)} hw functions")

    base = r"F:\coding\Decompiles\Sims 2"

    print("\nDisassembling os.a functions...")
    os_total, os_failed = generate_asm(
        os_funcs,
        os.path.join(base, "libs", "dolphinsdk", "os.s"),
        "DolphinSDK os.a - Small functions",
        symbol_table
    )
    print(f"  os.a: {os_total} total, {os_failed} failed")

    print("\nDisassembling hw functions...")
    hw_total, hw_failed = generate_asm(
        hw_funcs,
        os.path.join(base, "libs", "dolphinsdk", "hw.s"),
        "DolphinSDK hardware libs (exi.a, si.a, vi.a, pad.a, ai.a, dvd.a) - Small functions",
        symbol_table
    )
    print(f"  hw: {hw_total} total, {hw_failed} failed")

    print(f"\nDone! Total: {os_total + hw_total} functions ({os_failed + hw_failed} failed)")


if __name__ == '__main__':
    main()
