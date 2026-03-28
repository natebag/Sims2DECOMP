#!/usr/bin/env python3
"""
Generate assembly files for DolphinSDK functions 65-256 bytes.
Extracts disassembly from ELF using objdump, formats into .s files.
"""

import re
import subprocess
import sys
from collections import defaultdict

MAP_FILE = "extracted/files/u2_ngc_release_dvd.map"
ELF_FILE = "extracted/files/u2_ngc_release_dvd.elf"
OBJDUMP = r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC\bin\powerpc-eabi-objdump.exe"
SDK_LIBS = {'os.a', 'exi.a', 'si.a', 'dvd.a', 'vi.a', 'pad.a', 'ai.a', 'mtx.a', 'gx.a', 'db.a'}
OS_LIBS = {'os.a'}
HW_LIBS = {'exi.a', 'si.a', 'dvd.a', 'vi.a', 'pad.a', 'ai.a', 'mtx.a', 'gx.a', 'db.a'}

# Branch mnemonics that take address targets
BRANCH_MNEMONICS = {
    'b', 'bl', 'ba', 'bla',
    'beq', 'bne', 'blt', 'bgt', 'ble', 'bge',
    'beq+', 'bne+', 'blt+', 'bgt+', 'ble+', 'bge+',
    'beq-', 'bne-', 'blt-', 'bgt-', 'ble-', 'bge-',
    'bdnz', 'bdnz+', 'bdnz-', 'bdz', 'bdz+', 'bdz-',
    'bso', 'bns', 'bso+', 'bns+', 'bso-', 'bns-',
}

# ---- Step 1: Parse map file ----
print("Parsing map file...")
with open(MAP_FILE, 'r') as f:
    lines = f.readlines()

current_lib = None
current_obj = None
raw_symbols = []

lib_pat = re.compile(r'DolphinSDK.*?lib[/\\](\w+\.a)\((\w+\.o)\)')

for line in lines:
    ls = line.rstrip()
    m = lib_pat.search(ls)
    if m:
        lib_name = m.group(1)
        obj_name = m.group(2)
        if lib_name in SDK_LIBS:
            addr_m = re.match(r'\s*([0-9a-fA-F]+)', ls)
            if addr_m:
                addr = int(addr_m.group(1), 16)
                if 0x80003000 <= addr <= 0x803FFFFF:
                    current_lib = lib_name
                    current_obj = obj_name
                else:
                    current_lib = None
        else:
            current_lib = None
        continue

    if current_lib:
        sm = re.match(r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]+)\s+(\d+)\s+(.*)', ls)
        if sm:
            addr = int(sm.group(1), 16)
            size = int(sm.group(2), 16)
            name = sm.group(4).strip()
            if '\\' in name or '/' in name or name.endswith('.o)'):
                if 'DolphinSDK' not in ls:
                    current_lib = None
                continue
            if 65 <= size <= 256 and 0x80003000 <= addr <= 0x803FFFFF and name:
                raw_symbols.append((addr, size, name, current_lib, current_obj))

# Deduplicate by address
seen = set()
symbols = []
for s in raw_symbols:
    if s[0] not in seen:
        seen.add(s[0])
        symbols.append(s)

symbols.sort(key=lambda x: x[0])
print(f"Found {len(symbols)} SDK functions in 65-256 byte range")

# Build full symbol table for branch resolution
print("Building full symbol table for branch resolution...")
all_symbols = {}
for line in lines:
    ls = line.rstrip()
    sm = re.match(r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]+)\s+(\d+)\s+(.*)', ls)
    if sm:
        addr = int(sm.group(1), 16)
        size = int(sm.group(2), 16)
        name = sm.group(4).strip()
        if name and '\\' not in name and '/' not in name and not name.endswith('.o)'):
            if addr not in all_symbols or size > 0:
                all_symbols[addr] = name

print(f"Total symbols in lookup: {len(all_symbols)}")

# ---- Step 2: Objdump the ELF ----
def get_disassembly_range(start_addr, end_addr):
    cmd = [
        OBJDUMP, '-d', '-M', 'broadway',
        '--start-address', f'0x{start_addr:08x}',
        '--stop-address', f'0x{end_addr:08x}',
        ELF_FILE
    ]
    result = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
    return result.stdout

def parse_objdump_line(line):
    """Parse an objdump disassembly line using tab-splitting."""
    line = line.rstrip('\r\n')
    # Format: "  ADDR:\tHEX BYTES \tMNEMONIC\tOPERANDS" or "  ADDR:\tHEX BYTES \tMNEMONIC OPERANDS"
    # Split by tab
    parts = line.split('\t')
    if len(parts) < 3:
        return None

    # Part 0: "  ADDR:" (with leading spaces)
    addr_part = parts[0].strip()
    if not addr_part.endswith(':'):
        return None
    addr_str = addr_part[:-1]
    try:
        addr = int(addr_str, 16)
    except ValueError:
        return None

    # Part 1: hex bytes "XX XX XX XX "
    raw_hex = parts[1].strip()

    # Part 2+: instruction "mnemonic operands" or "mnemonic\toperands"
    instr = '\t'.join(parts[2:]).strip()

    # Split mnemonic from operands (first whitespace)
    instr_parts = instr.split(None, 1)
    if not instr_parts:
        return None

    mnemonic = instr_parts[0]
    operands = instr_parts[1].strip() if len(instr_parts) > 1 else ""

    return (addr, raw_hex, mnemonic, operands)


print("Disassembling from ELF...")
batch_size = 50
batches = []
for i in range(0, len(symbols), batch_size):
    batch = symbols[i:i+batch_size]
    start = batch[0][0]
    end = batch[-1][0] + batch[-1][1]
    batches.append((start, end, batch))

all_disasm = {}

for batch_idx, (start, end, batch) in enumerate(batches):
    print(f"  Batch {batch_idx+1}/{len(batches)}: 0x{start:08X}-0x{end:08X} ({len(batch)} functions)")
    output = get_disassembly_range(start, end)

    for line in output.split('\n'):
        result = parse_objdump_line(line)
        if result:
            addr, raw_hex, mnemonic, operands = result
            all_disasm[addr] = (raw_hex, mnemonic, operands)

print(f"  Disassembled {len(all_disasm)} instructions total")

# ---- Step 3: Resolve branch targets ----
def resolve_operands(mnemonic, operands, func_addr, func_size):
    """Resolve branch target addresses to symbol names or local labels."""
    if not operands:
        return operands

    # Check if this is a branch instruction
    is_branch = mnemonic in BRANCH_MNEMONICS

    if not is_branch:
        return operands

    # Try to find hex address in operands
    parts = operands.split(',')
    last_part = parts[-1].strip()

    # Remove angle-bracket annotations
    last_clean = re.sub(r'\s*<[^>]*>', '', last_part).strip()

    # Try to parse as hex address
    addr_match = re.match(r'^(0x)?([0-9a-fA-F]{7,8})$', last_clean)
    if addr_match:
        target = int(addr_match.group(2), 16)

        # Resolve to symbol or local label
        if target in all_symbols:
            target_name = all_symbols[target]
        elif func_addr <= target < func_addr + func_size:
            target_name = f".L_{target:08X}"
        else:
            target_name = f"0x{target:08X}"

        # Rebuild operands
        if len(parts) > 1:
            prefix = ','.join(parts[:-1]) + ','
            return prefix + target_name
        else:
            return target_name

    return operands


def format_function(addr, size, name, lib, obj):
    """Format a single function as assembly text."""
    lines_out = []
    lines_out.append(f".global {name}")
    lines_out.append(f".balign 4")
    lines_out.append(f"{name}:")
    lines_out.append(f"/* 0x{addr:08X} | size=0x{size:X} ({size} bytes) */")

    num_instrs = size // 4

    # First pass: identify branch targets within this function
    local_targets = set()
    for i in range(num_instrs):
        iaddr = addr + i * 4
        if iaddr in all_disasm:
            _, mnemonic, operands = all_disasm[iaddr]
            if mnemonic in BRANCH_MNEMONICS:
                parts = operands.split(',')
                last_part = parts[-1].strip()
                last_clean = re.sub(r'\s*<[^>]*>', '', last_part).strip()
                addr_match = re.match(r'^(0x)?([0-9a-fA-F]{7,8})$', last_clean)
                if addr_match:
                    target = int(addr_match.group(2), 16)
                    if addr <= target < addr + size:
                        local_targets.add(target)

    # Second pass: emit instructions
    for i in range(num_instrs):
        iaddr = addr + i * 4

        # Add local label if needed
        if iaddr in local_targets:
            lines_out.append(f".L_{iaddr:08X}:")

        if iaddr in all_disasm:
            raw_hex, mnemonic, operands = all_disasm[iaddr]
            resolved = resolve_operands(mnemonic, operands, addr, size)

            if resolved:
                # Ensure at least one space between mnemonic and operands
                pad = max(8, len(mnemonic) + 1)
                lines_out.append(f"    {mnemonic:{pad}s}{resolved}")
            else:
                lines_out.append(f"    {mnemonic}")
        else:
            lines_out.append(f"    .long   0x00000000  /* missing at 0x{iaddr:08X} */")

    lines_out.append(f".size {name}, . - {name}")
    return '\n'.join(lines_out)


# ---- Step 4: Deduplicate symbol names within each file ----
def deduplicate_names(func_list):
    """Rename duplicate symbols by appending _objname suffix."""
    name_count = defaultdict(int)
    for a, s, n, l, o in func_list:
        name_count[n] += 1

    duplicates = {n for n, c in name_count.items() if c > 1}
    if duplicates:
        print(f"  Deduplicating {len(duplicates)} duplicate names: {duplicates}")

    result = []
    for a, s, n, l, o in func_list:
        if n in duplicates:
            # Append obj name (without .o) as suffix
            obj_base = o.replace('.o', '')
            new_name = f"{n}_{obj_base}"
            result.append((a, s, new_name, l, o))
        else:
            result.append((a, s, n, l, o))
    return result

os_funcs = [(a, s, n, l, o) for a, s, n, l, o in symbols if l in OS_LIBS]
hw_funcs = [(a, s, n, l, o) for a, s, n, l, o in symbols if l in HW_LIBS]

os_funcs = deduplicate_names(os_funcs)
hw_funcs = deduplicate_names(hw_funcs)

print(f"\nGenerating os_medium.s ({len(os_funcs)} functions)...")
os_by_obj = defaultdict(list)
for s in os_funcs:
    os_by_obj[s[4]].append(s)

with open("libs/dolphinsdk/os_medium.s", "w") as f:
    f.write("# DolphinSDK os.a - Medium functions (65-256 bytes)\n")
    f.write("# Auto-generated from ELF disassembly\n")
    f.write("# Functions in the 65-256 byte range\n\n")
    f.write(".section .text\n")

    for obj in sorted(os_by_obj.keys()):
        funcs = os_by_obj[obj]
        f.write(f"\n#\n# === {obj} ===\n#\n")
        for addr, size, name, lib, obj_name in funcs:
            f.write("\n")
            f.write(format_function(addr, size, name, lib, obj_name))
            f.write("\n")

print(f"Generating hw_medium.s ({len(hw_funcs)} functions)...")
hw_by_lib_obj = defaultdict(lambda: defaultdict(list))
for s in hw_funcs:
    hw_by_lib_obj[s[3]][s[4]].append(s)

lib_order = ['exi.a', 'si.a', 'db.a', 'mtx.a', 'dvd.a', 'vi.a', 'pad.a', 'ai.a', 'gx.a']

with open("libs/dolphinsdk/hw_medium.s", "w") as f:
    f.write("# DolphinSDK hardware libraries - Medium functions (65-256 bytes)\n")
    f.write("# Auto-generated from ELF disassembly\n")
    f.write("# Libraries: exi.a, si.a, dvd.a, vi.a, pad.a, ai.a, mtx.a, gx.a, db.a\n\n")
    f.write(".section .text\n")

    for lib in lib_order:
        if lib not in hw_by_lib_obj:
            continue
        f.write(f"\n# ============================================================\n")
        f.write(f"# {lib}\n")
        f.write(f"# ============================================================\n")

        for obj in sorted(hw_by_lib_obj[lib].keys()):
            funcs = hw_by_lib_obj[lib][obj]
            f.write(f"\n#\n# === {obj} ===\n#\n")
            for addr, size, name, lib_name, obj_name in funcs:
                f.write("\n")
                f.write(format_function(addr, size, name, lib_name, obj_name))
                f.write("\n")

print("\nDone!")
print(f"Total functions: {len(symbols)}")
print(f"  os_medium.s: {len(os_funcs)} functions")
print(f"  hw_medium.s: {len(hw_funcs)} functions")
