#!/usr/bin/env python3
"""
Convert leaf asm_decomp functions to real C++.

Strategy: Parse inline PPC asm, identify patterns, generate matching C++.
Focus on true leaf functions (no stack frame, no calls) in 20-128 byte range.
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
CXX = DEVKITPPC / "bin" / "powerpc-eabi-g++.exe"
OBJDUMP = DEVKITPPC / "bin" / "powerpc-eabi-objdump.exe"
DOL = REPO / "extracted" / "sys" / "main.dol"

CXXFLAGS = [
    "-mcpu=750", "-meabi", "-mhard-float", "-O2",
    "-fno-exceptions", "-fno-rtti", "-fno-builtin",
    "-fshort-wchar", "-nostdinc++",
    "-fno-schedule-insns", "-fno-schedule-insns2",
    "-fno-inline", "-fno-inline-small-functions",
    "-Iinclude", "-Isrc", "-Ilibs/dolphinsdk", "-Ilibs/sn_runtime", "-Ilibs/apt",
    "-DNDEBUG", "-DEA_PLATFORM_GAMECUBE=1", "-DGEKKO",
    "-Wall", "-Wno-unused", "-Wno-return-type", "-fpermissive",
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


def get_compiled_bytes(obj_path):
    """Get all function bytes from a compiled .o file."""
    result = subprocess.run(
        [str(OBJDUMP), "-d", str(obj_path)],
        capture_output=True, text=True, timeout=30
    )

    funcs = {}
    current_name = None
    current_bytes = bytearray()

    for line in result.stdout.split("\n"):
        fm = re.match(r"^[0-9a-f]+ <(.+)>:", line)
        if fm:
            if current_name and current_bytes:
                funcs[current_name] = bytes(current_bytes)
            current_name = fm.group(1)
            current_bytes = bytearray()
            continue
        bm = re.match(r"\s*[0-9a-f]+:\s+((?:[0-9a-f]{2} )+)", line)
        if bm and current_name:
            for b in bm.group(1).strip().split():
                current_bytes.append(int(b, 16))
    if current_name and current_bytes:
        funcs[current_name] = bytes(current_bytes)

    return funcs


def parse_asm_instrs(asm_body):
    """Parse asm body into list of (op, operands, raw_line) tuples."""
    instrs = []
    for line in asm_body.strip().split('\n'):
        stripped = line.strip().strip('"').rstrip('\\n').strip()
        if not stripped:
            continue
        if stripped.startswith('.L_'):
            instrs.append(('label', stripped.rstrip(':'), stripped))
            continue
        if stripped.startswith('#'):
            continue

        # Parse instruction
        parts = stripped.split('\t', 1)
        if len(parts) == 2:
            op = parts[0].strip()
            operands = parts[1].strip()
        else:
            parts = stripped.split(None, 1)
            op = parts[0].strip() if parts else ''
            operands = parts[1].strip() if len(parts) > 1 else ''
        instrs.append((op, operands, stripped))
    return instrs


def parse_all_leaf_funcs():
    """Parse all leaf functions from asm_decomp."""
    asm_dir = REPO / "src" / "asm_decomp"
    leaf_funcs = []

    for fname in sorted(os.listdir(asm_dir)):
        if not fname.endswith('.cpp'):
            continue
        filepath = asm_dir / fname
        with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
            content = f.read()

        # Also extract the class declarations from the file header
        class_decls = content.split('// 0x')[0] if '// 0x' in content else ''

        pattern = r'// (0x[0-9A-Fa-f]+) \((\d+) bytes\)\n// (.+?)\n(?:__attribute__\(\(noreturn\)\)\n)?(.+?)\{[\s\S]*?__asm__ __volatile__\(\s*\n([\s\S]*?)\n\s*\);'

        for m in re.finditer(pattern, content):
            addr = m.group(1)
            size = int(m.group(2))
            comment = m.group(3)
            signature = m.group(4).strip()
            asm_body = m.group(5)

            if size < 20 or size > 128:
                continue

            instrs = parse_asm_instrs(asm_body)
            has_call = False
            has_stack_frame = False
            for op, operands, raw in instrs:
                if op == 'bl' or op == 'blrl':
                    has_call = True
                    break
                if op == '.long' and '/* bl' in raw:
                    has_call = True
                    break
                if op == 'stwu' and '1,' in operands:
                    has_stack_frame = True

            if not has_call and not has_stack_frame:
                leaf_funcs.append({
                    'file': fname,
                    'addr': addr,
                    'size': size,
                    'comment': comment,
                    'signature': signature,
                    'asm_body': asm_body,
                    'instrs': instrs,
                    'class_decls': class_decls,
                })

    return leaf_funcs


def compile_and_check(src_content, func_addr, func_size, dol_data, tmp_dir):
    """Compile C++ source and check if function bytes match DOL."""
    src_path = tmp_dir / "test.cpp"
    obj_path = tmp_dir / "test.o"

    with open(src_path, 'w') as f:
        f.write(src_content)

    result = subprocess.run(
        [str(CXX)] + CXXFLAGS + ["-c", str(src_path), "-o", str(obj_path)],
        capture_output=True, text=True, timeout=30
    )

    if result.returncode != 0:
        return None, f"Compile error: {result.stderr[:200]}"

    compiled_funcs = get_compiled_bytes(obj_path)
    if not compiled_funcs:
        return None, "No functions in .o"

    dol_bytes = get_dol_bytes(dol_data, int(func_addr, 16), func_size)
    if dol_bytes is None:
        return None, "Address not in DOL"

    # Find our function - it should be the last/main one
    for name, fbytes in compiled_funcs.items():
        if len(fbytes) == func_size:
            if fbytes == dol_bytes:
                return True, name
            else:
                # Show diff
                diff_pos = -1
                for i in range(min(len(fbytes), len(dol_bytes))):
                    if fbytes[i] != dol_bytes[i]:
                        diff_pos = i
                        break
                return False, f"Size matches but bytes differ at offset {diff_pos}"

    # Size mismatch
    sizes = {name: len(fb) for name, fb in compiled_funcs.items()}
    return False, f"Size mismatch: compiled={sizes} expected={func_size}"


def main():
    print("Parsing all leaf functions from asm_decomp...")
    leaf_funcs = parse_all_leaf_funcs()
    print(f"Found {len(leaf_funcs)} true leaf functions (20-128 bytes)")

    dol_data = read_dol()

    # Group by source file
    by_file = defaultdict(list)
    for func in leaf_funcs:
        by_file[func['file']].append(func)

    print(f"Across {len(by_file)} source files")

    # Create output directory
    tmp_dir = REPO / "build" / "tmp_convert"
    tmp_dir.mkdir(parents=True, exist_ok=True)

    # Track results
    total_attempted = 0
    total_matched = 0
    matched_funcs = defaultdict(list)  # file -> list of (addr, size, comment, sig, cpp_body)

    for func in leaf_funcs:
        cpp = try_convert_function(func, dol_data, tmp_dir)
        if cpp is not None:
            total_attempted += 1
            matched, msg = compile_and_check(cpp, func['addr'], func['size'], dol_data, tmp_dir)
            if matched:
                total_matched += 1
                # Extract just the function body from cpp
                matched_funcs[func['file']].append({
                    'addr': func['addr'],
                    'size': func['size'],
                    'comment': func['comment'],
                    'signature': func['signature'],
                    'cpp': cpp,
                })
                print(f"  MATCH: {func['addr']} ({func['size']}B) {func['comment']}")
            elif matched is False:
                # Close but not matching
                pass
            else:
                pass

    print(f"\nResults: {total_matched}/{total_attempted} functions matched")

    # Write matched functions to output files
    for fname, funcs in sorted(matched_funcs.items()):
        base = fname.replace('.cpp', '')
        out_path = REPO / "src" / "matched" / f"{base}_converted.cpp"

        total_bytes = sum(f['size'] for f in funcs)

        with open(out_path, 'w') as f:
            f.write('#include "types.h"\n')
            f.write('#include "stub_classes.h"\n')
            f.write(f'// Converted leaf functions for {base}\n')
            f.write(f'// {len(funcs)} functions, {total_bytes} bytes\n\n')

            for func in funcs:
                f.write(f'// {func["addr"]} ({func["size"]} bytes)\n')
                # Extract just the function definition from the full cpp
                # The cpp contains headers + function, we just want the function
                lines = func['cpp'].split('\n')
                # Find the function line
                for i, line in enumerate(lines):
                    if line.strip() and not line.startswith('#') and not line.startswith('//') and not line.startswith('class') and not line.startswith('template') and not line.startswith('enum') and not line.startswith('typedef') and not line.startswith('struct') and not line.startswith('};') and not line.startswith('public:') and not line.startswith('private:') and not line.startswith('protected:') and not line.strip().startswith('//'):
                        if '::' in line or 'operator' in line:
                            f.write('\n'.join(lines[i:]) + '\n\n')
                            break

        print(f"Wrote {len(funcs)} functions to {out_path}")

    return total_matched


def try_convert_function(func, dol_data, tmp_dir):
    """Try to convert an asm function to C++. Returns C++ source or None."""
    instrs = func['instrs']
    sig = func['signature']
    comment = func['comment']

    # Try different conversion strategies
    for strategy in [
        try_switch_pattern,
        try_linear_search_pattern,
        try_conditional_return_pattern,
        try_struct_manipulation_pattern,
        try_comparison_operator_pattern,
    ]:
        cpp = strategy(func)
        if cpp is not None:
            return cpp

    return None


def get_class_name(sig):
    """Extract class name from signature like 'void Foo::Bar(int)'."""
    m = re.match(r'(?:.*?\s+)?(\w+(?:::\w+)*)::\w+', sig)
    if m:
        return m.group(1)
    return None


def make_cpp_file(func, func_body):
    """Wrap a function body with proper headers and class declaration."""
    sig = func['signature']

    cpp = '#include "types.h"\n'
    cpp += '#include "stub_classes.h"\n\n'
    cpp += f'// {func["addr"]} ({func["size"]} bytes)\n'
    cpp += func_body + '\n'

    return cpp


def try_switch_pattern(func):
    """Convert switch/case patterns: cmpwi/beq sequences returning constants."""
    instrs = func['instrs']
    sig = func['signature']

    # Look for pattern: multiple cmpwi + beq, each beq target has li r3,N + blr
    # This is a switch on a parameter

    # Parse the assembly to understand the control flow
    ops = [(op, operands) for op, operands, _ in instrs if op != 'label']
    labels = {operands: i for i, (op, operands, _) in enumerate(instrs) if op == 'label'}

    # Check: does this look like a switch on r4 (first parameter)?
    cmpwi_r4 = [(i, op, operands) for i, (op, operands, _) in enumerate(instrs)
                if op == 'cmpwi' and operands.startswith('4,')]

    if len(cmpwi_r4) < 2:
        return None

    # Check that the function primarily does cmpwi on r4 and returns different values
    # Extract case -> return value mapping
    cases = {}
    default_val = None

    # Build a label -> instruction map
    label_to_idx = {}
    for i, (op, operands, raw) in enumerate(instrs):
        if op == 'label':
            label_to_idx[operands] = i

    # For each label target, check if it's a simple "li r3, N; blr"
    for i, (op, operands, raw) in enumerate(instrs):
        if op == 'label':
            lbl = operands
            # Look at next instructions
            next_instrs = []
            for j in range(i+1, min(i+4, len(instrs))):
                if instrs[j][0] != 'label':
                    next_instrs.append(instrs[j])
                else:
                    break

            if len(next_instrs) >= 2:
                if next_instrs[0][0] == 'li' and next_instrs[0][1].startswith('3,') and next_instrs[1][0] == 'blr':
                    val = next_instrs[0][1].split(',')[1].strip()
                    # Find what cmpwi/beq targets this label
                    for ci, (cop, coperands, _) in enumerate(instrs):
                        if cop == 'beq' and coperands.strip() == lbl:
                            # Look back for cmpwi
                            for k in range(ci-1, max(ci-3, -1), -1):
                                if instrs[k][0] in ('cmpwi', 'cmplwi'):
                                    cmp_operands = instrs[k][1]
                                    # Extract the comparison value
                                    parts = cmp_operands.split(',')
                                    if len(parts) >= 2:
                                        cmp_val = parts[-1].strip()
                                        reg = parts[0].strip()
                                        if reg == '4' or reg.startswith('cr'):
                                            cases[cmp_val] = val
                                    break

    if len(cases) < 2:
        return None

    # Find default value (the last li r3,N; blr that isn't a case target)
    for i in range(len(instrs)-1, -1, -1):
        op, operands, _ = instrs[i]
        if op == 'li' and operands.startswith('3,'):
            val = operands.split(',')[1].strip()
            # Check if this is a default (not a case target)
            if i+1 < len(instrs) and instrs[i+1][0] == 'blr':
                default_val = val
                break

    if default_val is None:
        return None

    # Check: is the switch on parameter p4 (r4)?
    # Build the switch statement
    param_name = 'p4'

    # Generate C++ switch
    body_lines = []
    body_lines.append(f'    switch ({param_name}) {{')
    for case_val, ret_val in sorted(cases.items(), key=lambda x: int(x[0])):
        body_lines.append(f'        case {case_val}: return {ret_val};')
    body_lines.append(f'        default: return {default_val};')
    body_lines.append(f'    }}')

    # Reconstruct function signature
    # Fix return type if needed
    fixed_sig = sig
    if sig.startswith('void '):
        fixed_sig = 'int ' + sig[5:]

    func_body = fixed_sig + ' {\n' + '\n'.join(body_lines) + '\n}'

    return make_cpp_file(func, func_body)


def try_linear_search_pattern(func):
    """Convert linear search: loop through array, compare, return index."""
    instrs = func['instrs']
    sig = func['signature']

    # Look for pattern:
    # li r9/r11, 0 (counter init)
    # loop: lwz r0, 0(r3); cmpw r0, r4; beq found; addi counter, 1; cmpw counter, limit; blt loop
    # not found: li r3, -1; blr
    # found: mr r3, counter; blr

    # This is complex - skip for now
    return None


def try_conditional_return_pattern(func):
    """Convert simple conditional patterns like:
    lwz r0, N(r3); cmpwi r0, 0; beq/bne label; ... blr
    """
    instrs = func['instrs']
    sig = func['signature']

    return None


def try_struct_manipulation_pattern(func):
    """Convert struct member read/write with conditions."""
    return None


def try_comparison_operator_pattern(func):
    """Convert comparison operators like operator<, operator==."""
    instrs = func['instrs']
    sig = func['signature']
    comment = func['comment']

    # Look for operator< pattern on CTilePt etc
    if 'operator<' not in comment and 'operator==' not in comment and 'operator!=' not in comment:
        return None

    return None


if __name__ == "__main__":
    matched = main()
    print(f"\nTotal new matches: {matched}")
