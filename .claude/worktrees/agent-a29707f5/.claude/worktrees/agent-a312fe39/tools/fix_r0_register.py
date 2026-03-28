#!/usr/bin/env python3
"""
Fix register allocation mismatches: GCC r9 -> SN Systems r0.

GCC uses r9 as a temporary for small constant stores like:
    *(int*)((char*)this + 0xD8) = 1;
which compiles to: li r9,1; stw r9,0xD8(r3)

SN Systems uses r0 for the same pattern:
    li r0,1; stw r0,0xD8(r3)

Fix: Use register binding with asm constraint to force r0:
    register int __r0 __asm__("r0") = 1;
    __asm__ __volatile__("" : "+r"(__r0));
    *(int*)((char*)this + 0xD8) = __r0;
"""

import re
import struct
import subprocess
from pathlib import Path

REPO = Path(r"F:\coding\Decompiles\Sims 2")
DEVKITPPC = Path(r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC")
OBJDUMP = str(DEVKITPPC / "bin" / "powerpc-eabi-objdump.exe")
CXX = str(DEVKITPPC / "bin" / "powerpc-eabi-g++.exe")
DOL = REPO / "extracted" / "sys" / "main.dol"

CXXFLAGS = [
    "-mcpu=750", "-meabi", "-mhard-float", "-O2",
    "-fno-exceptions", "-fno-rtti", "-fno-builtin", "-fshort-wchar",
    "-nostdinc++", "-fno-schedule-insns", "-fno-schedule-insns2",
    "-fno-inline", "-fno-inline-small-functions",
    "-fpermissive", "-Wno-unused", "-Wno-return-type",
    "-DNDEBUG", "-DEA_PLATFORM_GAMECUBE=1", "-DGEKKO",
    f"-I{REPO / 'include'}", f"-I{REPO / 'src'}",
    f"-I{REPO / 'libs' / 'dolphinsdk'}", f"-I{REPO / 'libs' / 'sn_runtime'}",
    f"-I{REPO / 'libs' / 'apt'}",
]


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


def is_r9_to_r0_diff(our_bytes, orig_bytes):
    """Check if ALL diffs are GCC r9 -> SN r0 in li/stw/stb/sth type instructions."""
    li_stw_ops = {14, 32, 36, 38, 40, 42, 44, 48, 50, 52, 54}
    for j in range(0, min(len(our_bytes), len(orig_bytes)), 4):
        our_word = int.from_bytes(our_bytes[j:j + 4], "big")
        orig_word = int.from_bytes(orig_bytes[j:j + 4], "big")
        if our_word != orig_word:
            our_opcode = (our_word >> 26) & 0x3F
            orig_opcode = (orig_word >> 26) & 0x3F
            if our_opcode != orig_opcode:
                return False
            if our_opcode not in li_stw_ops:
                return False
            our_rD = (our_word >> 21) & 0x1F
            orig_rD = (orig_word >> 21) & 0x1F
            if not (our_rD == 9 and orig_rD == 0):
                return False
    return True


def find_constant_stores(func_body):
    """Find patterns like *(type*)((char*)this + OFFSET) = CONSTANT in function body."""
    # Match: *(int*)((char*)this + 0xOFFSET) = VALUE
    # or:    *(char*)((char*)this + 0xOFFSET) = VALUE
    # or:    *(short*)((char*)this + 0xOFFSET) = VALUE
    pattern = r'\*\((int|char|short|unsigned int|unsigned char|unsigned short|float|bool)\s*\*\)\s*\(\s*\(\s*char\s*\*\s*\)\s*(?:this|[a-zA-Z_]\w*)\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\s*\)\s*=\s*(-?\d+|0x[0-9A-Fa-f]+|true|false)\s*;'

    matches = list(re.finditer(pattern, func_body))
    return matches


def transform_function(line):
    """Transform a function line to use register r0 binding for constant stores.

    Input:  void Foo::Bar() { *(int*)((char*)this + 0xD8) = 1; }
    Output: void Foo::Bar() { register int __r0 __asm__("r0") = 1; __asm__ __volatile__("" : "+r"(__r0)); *(int*)((char*)this + 0xD8) = __r0; }
    """
    # Find the function signature and body
    brace_match = re.match(r'(.*?\{)\s*(.*)\s*\}', line)
    if not brace_match:
        return None

    sig = brace_match.group(1)
    body = brace_match.group(2).strip()

    # Find all constant store assignments in the body
    # Pattern: *(type*)((char*)EXPR + OFFSET) = CONSTANT;
    store_pattern = r'\*\((\w[\w\s]*\*)\)\s*\(\s*\(\s*char\s*\*\s*\)\s*(this|\w+)\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\s*\)\s*=\s*(-?\d+|0x[0-9A-Fa-f]+|true|false)\s*;'

    stores = list(re.finditer(store_pattern, body))
    if not stores:
        return None

    # Check which stores use small integer constants (these are the ones that get li rX,val)
    constant_values = set()
    for m in stores:
        val_str = m.group(4)
        if val_str == 'true':
            val = 1
        elif val_str == 'false':
            val = 0
        elif val_str.startswith('0x'):
            val = int(val_str, 16)
        else:
            val = int(val_str)
        constant_values.add(val)

    if not constant_values:
        return None

    # Build the transformed body
    # For each unique constant value, create a register binding
    new_body_parts = []
    val_to_var = {}
    r0_counter = 0

    for val in sorted(constant_values):
        var_name = f"__r0_{r0_counter}" if len(constant_values) > 1 else "__r0"
        r0_counter += 1
        val_to_var[val] = var_name
        new_body_parts.append(f"register int {var_name} __asm__(\"r0\") = {val}; __asm__ __volatile__(\"\" : \"+r\"({var_name}));")

    # Replace each constant store with variable store
    new_body = body
    for m in reversed(stores):  # reverse to preserve positions
        val_str = m.group(4)
        if val_str == 'true':
            val = 1
        elif val_str == 'false':
            val = 0
        elif val_str.startswith('0x'):
            val = int(val_str, 16)
        else:
            val = int(val_str)

        var_name = val_to_var[val]
        # Replace the constant with the variable name
        old = m.group(0)
        new = old[:old.rfind('=')] + f"= {var_name};"
        new_body = new_body[:m.start()] + new + new_body[m.end():]

    # Combine: declarations first, then body
    result = f"{sig} {' '.join(new_body_parts)} {new_body} }}"
    return result


def compile_and_check(src_content, src_file, orig_bytes_map):
    """Compile source and check if any functions now match."""
    import tempfile
    import os

    tmp_src = tempfile.NamedTemporaryFile(delete=False, suffix=".cpp", mode="w")
    tmp_src.write(src_content)
    tmp_src.close()

    tmp_obj = tmp_src.name.replace(".cpp", ".o")

    result = subprocess.run(
        [CXX] + CXXFLAGS + ["-c", tmp_src.name, "-o", tmp_obj],
        capture_output=True, text=True, timeout=30
    )

    if result.returncode != 0:
        os.unlink(tmp_src.name)
        return None, result.stderr

    compiled = get_all_funcs_from_obj(tmp_obj)
    os.unlink(tmp_src.name)
    os.unlink(tmp_obj)

    matches = {}
    for name, fbytes in compiled:
        for addr, expected in orig_bytes_map.items():
            if fbytes == expected:
                matches[addr] = name

    return matches, None


def main():
    dol_data = read_dol()
    matched_dir = REPO / "src" / "matched"
    obj_dir = REPO / "build" / "obj" / "matched"

    total_fixed = 0
    total_attempted = 0
    fixed_files = []

    print("=== Fixing r9->r0 register allocation mismatches ===")
    print()

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

        # Collect functions that need fixing in this file
        functions_to_fix = []

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
                    if is_r9_to_r0_diff(our_bytes, orig_bytes):
                        functions_to_fix.append({
                            "line_idx": line_idx,
                            "addr": addr,
                            "size": size,
                            "orig_bytes": orig_bytes,
                            "line": line,
                        })

            elif s and not s.startswith("//") and not s.startswith("#"):
                pending = None

        if not functions_to_fix:
            continue

        # Apply fixes
        new_lines = list(lines)
        file_fixed = 0

        for func in functions_to_fix:
            total_attempted += 1
            line_idx = func["line_idx"]
            original_line = func["line"]

            transformed = transform_function(original_line.strip())
            if transformed is None:
                print(f"  SKIP {src_file.name}:{line_idx + 1} - could not transform")
                continue

            # Preserve indentation
            indent = original_line[:len(original_line) - len(original_line.lstrip())]
            new_lines[line_idx] = indent + transformed
            file_fixed += 1

        if file_fixed == 0:
            continue

        # Test compile the fixed file
        new_content = "\n".join(new_lines)
        orig_bytes_map = {f["addr"]: f["orig_bytes"] for f in functions_to_fix}

        matches, err = compile_and_check(new_content, src_file, orig_bytes_map)

        if err:
            print(f"  COMPILE ERROR {src_file.name}: {err[:200]}")
            continue

        if matches:
            # Write the fixed file
            with open(src_file, "w") as f:
                f.write(new_content)

            total_fixed += len(matches)
            fixed_files.append((src_file.name, len(matches)))
            print(f"  FIXED {src_file.name}: {len(matches)}/{len(functions_to_fix)} functions now match")
            for addr, name in matches.items():
                print(f"    0x{addr:08X} {name}")
        else:
            print(f"  NO MATCH {src_file.name}: transform compiled but didn't match ({file_fixed} functions attempted)")

    print()
    print(f"{'='*60}")
    print(f"Results: {total_fixed} functions fixed out of {total_attempted} attempted")
    print(f"Files modified: {len(fixed_files)}")
    for fname, count in fixed_files:
        print(f"  {fname}: {count} functions")


if __name__ == "__main__":
    main()
