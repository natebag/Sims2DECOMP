#!/usr/bin/env python3
"""batch_match_trivial.py — Auto-generate and verify trivial 8-byte function matches.

Patterns handled:
  - return_const:    li r3, N; blr         → return N;
  - load_member:     lwz r3, off(r3); blr  → return *(int/u32*)((char*)this + off);
  - store_member:    stw r4, off(r3); blr  → *(int/u32*)((char*)this + off) = param;
  - load_sda:        lwz r3, off(r13); blr → return global (SDA-relative)
  - store_sda:       stw rX, off(r13); blr → global = param (SDA-relative)
  - load_float_member: lfs f1, off(r3); blr → return *(float*)((char*)this + off);
  - store_float:     stfs f1, off(r3); blr → *(float*)((char*)this + off) = param;

Usage:
  python tools/batch_match_trivial.py --dry-run     # show what would be generated
  python tools/batch_match_trivial.py --generate     # generate .cpp files
  python tools/batch_match_trivial.py --verify       # generate + compile + verify all
"""

import struct
import sys
import os
import re
import subprocess

DOL_PATH = "extracted/sys/main.dol"
MAP_PATH = "extracted/files/u2_ngc_release_dvd.map"
OUTPUT_DIR = "src/matched/trivial"
VERIFY_SCRIPT = "tools/verify_match.sh"
BASH_EXE = r"C:\Program Files\Git\bin\bash.exe"  # Git Bash on Windows

def read_dol():
    with open(DOL_PATH, "rb") as f:
        return f.read()

def vaddr_to_offset(dol, vaddr):
    for i in range(7):
        off = struct.unpack(">I", dol[i*4:i*4+4])[0]
        addr = struct.unpack(">I", dol[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack(">I", dol[0x90+i*4:0x90+i*4+4])[0]
        if addr <= vaddr < addr + sz:
            return off + (vaddr - addr)
    return None

def parse_map():
    funcs = []
    with open(MAP_PATH, "r", errors="replace") as f:
        for line in f:
            m = re.match(r'([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s+\d+\s+(.*)', line)
            if m:
                addr = int(m.group(1), 16)
                size = int(m.group(2), 16)
                name = m.group(3).strip()
                if size == 8 and 0x80003100 <= addr < 0x80600000:
                    funcs.append((addr, name))
    return funcs

def classify_function(dol, addr):
    """Classify an 8-byte function and return (pattern, C++ code, class_name) or None."""
    foff = vaddr_to_offset(dol, addr)
    if foff is None:
        return None
    raw = dol[foff:foff+8]
    w1 = struct.unpack(">I", raw[0:4])[0]
    w2 = struct.unpack(">I", raw[4:8])[0]

    if w2 != 0x4E800020:  # must end with blr
        return None

    op1 = (w1 >> 26) & 0x3F
    rd = (w1 >> 21) & 0x1F
    ra = (w1 >> 16) & 0x1F
    d = w1 & 0xFFFF
    if d >= 0x8000:
        d -= 0x10000

    # Pattern: li r3, N; blr → return N
    if op1 == 14 and ra == 0 and rd == 3:
        imm = d
        return ("return_const", f"return {imm};", None)

    # Pattern: lwz r3, off(r3); blr → return this->member (int)
    if op1 == 32 and rd == 3 and ra == 3:
        offset = d
        return ("load_member_int", f"return *(int*)((char*)this + 0x{offset & 0xFFFF:X});", "member")

    # Pattern: stw r4, off(r3); blr → this->member = param (int)
    if op1 == 36 and rd == 4 and ra == 3:
        offset = d
        return ("store_member_int", f"*(int*)((char*)this + 0x{offset & 0xFFFF:X}) = p;", "member")

    # Pattern: lfs f1, off(r3); blr → return this->member (float)
    if op1 == 48 and rd == 1 and ra == 3:
        offset = d
        return ("load_member_float", f"return *(float*)((char*)this + 0x{offset & 0xFFFF:X});", "member")

    # Pattern: stfs f1, off(r3); blr → this->member = param (float)
    if op1 == 52 and rd == 1 and ra == 3:
        offset = d
        return ("store_member_float", f"*(float*)((char*)this + 0x{offset & 0xFFFF:X}) = p;", "member")

    return None  # not a trivially matchable pattern

def parse_func_name(full_name):
    """Parse 'ClassName::MethodName(params)' into components."""
    # Remove trailing const
    name = full_name.rstrip()
    if name.endswith(" const"):
        name = name[:-6].rstrip()

    m = re.match(r'(?:(.+)::)?(\w+)\((.*)\)', name)
    if not m:
        return None, full_name, ""

    class_name = m.group(1) or ""
    method_name = m.group(2)
    params = m.group(3)
    return class_name, method_name, params

def generate_cpp(addr, func_name, pattern, code):
    """Generate a standalone .cpp file for one function."""
    class_name, method_name, params = parse_func_name(func_name)

    if not class_name:
        # Free function
        if "return" in code:
            ret_type = "float" if "float" in code else "int"
            return f"""// 0x{addr:08X} (8 bytes)
{ret_type} {method_name}({params}) {{
    {code}
}}
"""
        else:
            return f"""// 0x{addr:08X} (8 bytes)
void {method_name}({params}) {{
    {code}
}}
"""

    # Determine return type and param
    if "load_member_float" in pattern or "store_member_float" in pattern:
        ret_type = "float" if "return" in code else "void"
        param_decl = "float p" if "store" in pattern else ""
    else:
        ret_type = "int" if "return" in code else "void"
        param_decl = "int p" if "store" in pattern else ""

    # Handle nested classes (e.g., "InteractorModule::WallManipulator")
    class_parts = class_name.split("::")

    class_decl = f"class {class_parts[0]} {{\npublic:\n"
    if len(class_parts) > 1:
        class_decl += f"    class {class_parts[1]} {{\n    public:\n"
        class_decl += f"        {ret_type} {method_name}({param_decl});\n"
        class_decl += f"    }};\n"
    else:
        class_decl += f"    {ret_type} {method_name}({param_decl});\n"
    class_decl += f"}};\n"

    full_class = "::".join(class_parts)

    return f"""// 0x{addr:08X} (8 bytes)
{class_decl}
{ret_type} {full_class}::{method_name}({param_decl}) {{
    {code}
}}
"""

def main():
    dry_run = "--dry-run" in sys.argv
    generate = "--generate" in sys.argv or "--verify" in sys.argv
    verify = "--verify" in sys.argv

    dol = read_dol()
    funcs = parse_map()

    matchable = []
    skipped = 0

    for addr, name in funcs:
        result = classify_function(dol, addr)
        if result:
            pattern, code, _ = result
            matchable.append((addr, name, pattern, code))
        else:
            skipped += 1

    print(f"Matchable: {len(matchable)} | Skipped: {skipped}")

    if dry_run:
        for addr, name, pattern, code in matchable[:20]:
            print(f"  0x{addr:08X} [{pattern:25s}] {name}")
            print(f"    -> {code}")
        if len(matchable) > 20:
            print(f"  ... and {len(matchable) - 20} more")
        return

    if generate:
        os.makedirs(OUTPUT_DIR, exist_ok=True)
        generated = 0
        verified = 0
        failed = 0

        for addr, name, pattern, code in matchable:
            cpp_code = generate_cpp(addr, name, pattern, code)
            if cpp_code is None:
                continue

            safe_name = re.sub(r'[^a-zA-Z0-9_]', '_', name.split('(')[0])
            filename = f"{OUTPUT_DIR}/match_{addr:08X}_{safe_name}.cpp"

            with open(filename, "w") as f:
                f.write(cpp_code)
            generated += 1

            if verify:
                result = subprocess.run(
                    [BASH_EXE, VERIFY_SCRIPT, filename, f"0x{addr:08X}", "8"],
                    capture_output=True, text=True, timeout=30
                )
                if result.returncode == 0:
                    verified += 1
                    if verified <= 5 or verified % 50 == 0:
                        print(f"  OK {name}")
                else:
                    failed += 1
                    if failed <= 10:
                        last_line = result.stdout.strip().split('\n')[-1] if result.stdout.strip() else "unknown"
                        print(f"  FAIL {name} -- {last_line}")
                    # Remove failed file
                    os.remove(filename)

        print(f"\nGenerated: {generated}")
        if verify:
            print(f"Verified:  {verified}")
            print(f"Failed:    {failed}")

if __name__ == "__main__":
    main()
