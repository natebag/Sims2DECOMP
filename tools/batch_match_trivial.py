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

def classify_function(dol, addr, size=8):
    """Classify a trivial function and return (pattern, C++ code, class_name) or None."""
    foff = vaddr_to_offset(dol, addr)
    if foff is None:
        return None
    raw = dol[foff:foff+size]

    if size == 12:
        return classify_12byte(raw)

    # 8-byte functions below
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

    # Pattern: addi r3, r3, imm; blr → return pointer to member
    if op1 == 14 and rd == 3 and ra == 3:
        offset = d
        return ("ptr_member", f"return (int)((char*)this + 0x{offset & 0xFFFF:X});", None)

    # Pattern: or rA, rD, rD (mr); blr → return a parameter register
    if op1 == 31:
        xo = (w1 >> 1) & 0x3FF
        rb = (w1 >> 11) & 0x1F
        if xo == 444:  # or
            target_reg = (w1 >> 16) & 0x1F
            src_reg = rd
            if target_reg == 3 and src_reg == rb:
                # mr r3, rX; blr — return a parameter
                if src_reg == 4:
                    return ("mr_r3_r4", f"return p;", "member")
                elif src_reg == 5:
                    return ("mr_r3_r5", f"return p2;", "member")

    # Pattern: lha r3, off(r3); blr → return short member (sign-extended)
    if op1 == 42 and rd == 3 and ra == 3:
        offset = d
        return ("load_member_short", f"return *(short*)((char*)this + 0x{offset & 0xFFFF:X});", "member")

    # Pattern: lhz r3, off(r3); blr → return unsigned short member
    if op1 == 40 and rd == 3 and ra == 3:
        offset = d
        return ("load_member_ushort", f"return *(unsigned short*)((char*)this + 0x{offset & 0xFFFF:X});", "member")

    # Pattern: sth r4, off(r3); blr → set short member
    if op1 == 44 and rd == 4 and ra == 3:
        offset = d
        return ("store_member_short", f"*(short*)((char*)this + 0x{offset & 0xFFFF:X}) = (short)p;", "member")

    # Pattern: lbz r3, off(r3); blr → return byte member
    if op1 == 34 and rd == 3 and ra == 3:
        offset = d
        return ("load_member_byte", f"return *(unsigned char*)((char*)this + 0x{offset & 0xFFFF:X});", "member")

    # Pattern: stb r4, off(r3); blr → set byte member
    if op1 == 38 and rd == 4 and ra == 3:
        offset = d
        return ("store_member_byte", f"*(unsigned char*)((char*)this + 0x{offset & 0xFFFF:X}) = (unsigned char)p;", "member")

    return None  # not a trivially matchable pattern

def classify_12byte(raw):
    """Classify a 12-byte function (3 instructions)."""
    w1 = struct.unpack(">I", raw[0:4])[0]
    w2 = struct.unpack(">I", raw[4:8])[0]
    w3 = struct.unpack(">I", raw[8:12])[0]

    if w3 != 0x4E800020:  # must end with blr
        return None

    o1 = (w1 >> 26) & 0x3F
    d1 = (w1 >> 21) & 0x1F
    a1 = (w1 >> 16) & 0x1F
    imm1 = w1 & 0xFFFF
    if imm1 >= 0x8000: imm1 -= 0x10000

    o2 = (w2 >> 26) & 0x3F
    d2 = (w2 >> 21) & 0x1F
    a2 = (w2 >> 16) & 0x1F
    imm2 = w2 & 0xFFFF
    if imm2 >= 0x8000: imm2 -= 0x10000

    # li rX, imm; stw rX, off(r3); blr → this->field = constant
    if o1 == 14 and a1 == 0 and o2 == 36 and a2 == 3 and d2 == d1:
        return ("12_li_stw", f"*(int*)((char*)this + 0x{imm2 & 0xFFFF:X}) = {imm1};", "member")

    # li r0, imm; stb r0, off(r3); blr → this->byte_field = constant
    if o1 == 14 and a1 == 0 and d1 == 0 and o2 == 38 and a2 == 3 and d2 == 0:
        return ("12_li_stb", f"*(unsigned char*)((char*)this + 0x{imm2 & 0xFFFF:X}) = {imm1};", "member")

    # lwz r3, off(r3); lwz r3, off2(r3); blr → double dereference
    if o1 == 32 and d1 == 3 and a1 == 3 and o2 == 32 and d2 == 3 and a2 == 3:
        return ("12_double_deref", f"return *(int*)((char*)(*(int*)((char*)this + 0x{imm1 & 0xFFFF:X})) + 0x{imm2 & 0xFFFF:X});", None)

    # stw r4, off(r3); stw r5, off2(r3); blr → set two fields
    if o1 == 36 and d1 == 4 and a1 == 3 and o2 == 36 and d2 == 5 and a2 == 3:
        return ("12_store_two", f"*(int*)((char*)this + 0x{imm1 & 0xFFFF:X}) = p1; *(int*)((char*)this + 0x{imm2 & 0xFFFF:X}) = p2;", "member")

    # stw r4, off(r3); li r3, N; blr → set field, return constant
    if o1 == 36 and d1 == 4 and a1 == 3 and o2 == 14 and a2 == 0 and d2 == 3:
        return ("12_store_retconst", f"*(int*)((char*)this + 0x{imm1 & 0xFFFF:X}) = p; return {imm2};", "member")

    # stfs f1, off(r3); stfs f2, off2(r3); blr → set two float fields
    if o1 == 52 and d1 == 1 and a1 == 3 and o2 == 52 and d2 == 2 and a2 == 3:
        return ("12_store_two_float", f"*(float*)((char*)this + 0x{imm1 & 0xFFFF:X}) = p1; *(float*)((char*)this + 0x{imm2 & 0xFFFF:X}) = p2;", "member")

    # lwz rX, off(r3); lwz r3, off2(rX); blr — dereference through intermediate
    if o1 == 32 and a1 == 3 and d1 != 3 and o2 == 32 and d2 == 3 and a2 == d1:
        return ("12_deref_field", f"return *(int*)((char*)(*(int*)((char*)this + 0x{imm1 & 0xFFFF:X})) + 0x{imm2 & 0xFFFF:X});", None)

    # lwz rX, off(r3); lfs f1, off2(rX); blr — load float through pointer
    if o1 == 32 and a1 == 3 and o2 == 48 and d2 == 1 and a2 == d1:
        return ("12_deref_float", f"return *(float*)((char*)(*(int*)((char*)this + 0x{imm1 & 0xFFFF:X})) + 0x{imm2 & 0xFFFF:X});", None)

    # lwz rX, off(r3); addi r3, rX, imm; blr — return pointer to sub-struct
    if o1 == 32 and a1 == 3 and o2 == 14 and d2 == 3 and a2 == d1:
        return ("12_deref_ptr", f"return (int)((char*)(*(int*)((char*)this + 0x{imm1 & 0xFFFF:X})) + 0x{imm2 & 0xFFFF:X});", None)

    return None


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
    if "float" in pattern:
        ret_type = "float" if "return" in code else "void"
        param_decl = "float p" if "store" in pattern else ""
    elif "short" in pattern:
        ret_type = "short" if "return" in code and "load" in pattern else ("int" if "return" in code else "void")
        param_decl = "int p" if "store" in pattern else ""
    elif "byte" in pattern:
        ret_type = "int" if "return" in code else "void"
        param_decl = "int p" if "store" in pattern else ""
    elif "ptr_member" in pattern:
        ret_type = "int"
        param_decl = ""
    elif "mr_r3_r4" in pattern:
        ret_type = "int"
        param_decl = "int p"
    elif "mr_r3_r5" in pattern:
        ret_type = "int"
        param_decl = "int p1, int p2"
    elif "store_two_float" in pattern:
        ret_type = "void"
        param_decl = "float p1, float p2"
    elif "store_two" in pattern:
        ret_type = "void"
        param_decl = "int p1, int p2"
    elif "store_retconst" in pattern or "12_store_retconst" in pattern:
        ret_type = "int"
        param_decl = "int p"
    elif "12_li_st" in pattern:
        ret_type = "void"
        param_decl = ""
    elif "12_double_deref" in pattern or "12_deref" in pattern:
        ret_type = "float" if "float" in pattern else "int"
        param_decl = ""
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
    funcs8 = []
    funcs12 = []
    with open(MAP_PATH, "r", errors="replace") as f:
        for line in f:
            m = re.match(r'([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s+\d+\s+(.*)', line)
            if m:
                addr = int(m.group(1), 16)
                size = int(m.group(2), 16)
                name = m.group(3).strip()
                if 0x80003100 <= addr < 0x80600000:
                    if size == 8: funcs8.append((addr, name, 8))
                    elif size == 12: funcs12.append((addr, name, 12))

    matchable = []
    skipped = 0

    for addr, name, size in funcs8 + funcs12:
        result = classify_function(dol, addr, size)
        if result:
            pattern, code, _ = result
            matchable.append((addr, name, pattern, code, size))
        else:
            skipped += 1

    print(f"Matchable: {len(matchable)} | Skipped: {skipped}")

    if dry_run:
        for item in matchable[:30]:
            addr, name, pattern, code = item[0], item[1], item[2], item[3]
            sz = item[4] if len(item) > 4 else 8
            print(f"  0x{addr:08X} ({sz:2d}B) [{pattern:25s}] {name}")
            print(f"    -> {code}")
        if len(matchable) > 30:
            print(f"  ... and {len(matchable) - 30} more")
        return

    if generate:
        os.makedirs(OUTPUT_DIR, exist_ok=True)
        generated = 0
        verified = 0
        failed = 0

        for item in matchable:
            addr, name, pattern, code = item[0], item[1], item[2], item[3]
            size = item[4] if len(item) > 4 else 8
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
                    [BASH_EXE, VERIFY_SCRIPT, filename, f"0x{addr:08X}", str(size)],
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
