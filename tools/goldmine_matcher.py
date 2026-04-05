#!/usr/bin/env python3
"""Auto-match goldmine functions from missing_functions_report.txt.

Classifies 8-64B functions by pattern and auto-generates C++ for trivial ones:
- Empty (blr only)
- Return constant (li r3, N; blr)
- Field getter (lwz/lha/lbz r3, off(r3); blr)
- Field setter (stw/sth/stb r4, off(r3); blr or with li r3,1)
- Chained getter (lwz r3, off(r3); lwz/lha r3, off2(r3); blr)
"""

import struct
import re
import os
import glob
import subprocess
import sys

DOL_PATH = "extracted/sys/main.dol"
PYTHON = "/c/Users/SCICO/AppData/Local/Programs/Python/Python313/python.exe"
MATCH_DIR = "src/matched/agent"
VERIFY_CMD = "bash tools/verify_match.sh"

with open(DOL_PATH, "rb") as f:
    dol = f.read()

def dol_read(vaddr, size):
    for i in range(7):
        off = struct.unpack(">I", dol[i*4:i*4+4])[0]
        addr = struct.unpack(">I", dol[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack(">I", dol[0x90+i*4:0x90+i*4+4])[0]
        if addr <= vaddr < addr + sz:
            foff = off + (vaddr - addr)
            return dol[foff:foff+size]
    return None

def decode_insn(w):
    op = (w >> 26) & 0x3F
    rd = (w >> 21) & 0x1F
    ra = (w >> 16) & 0x1F
    d = w & 0xFFFF
    if d >= 0x8000: d -= 0x10000
    rb = (w >> 11) & 0x1F
    return op, rd, ra, d, rb

def classify(addr, size, raw):
    """Classify function pattern. Returns (pattern, cpp_code) or (pattern, None)."""
    words = [struct.unpack(">I", raw[i:i+4])[0] for i in range(0, len(raw), 4)]
    n = len(words)
    name_safe = f"func_{addr:08X}"

    # Pattern: just blr (4B)
    if n == 1 and words[0] == 0x4E800020:
        return "empty_4B", f"void {name_safe}(void) {{}}\n"

    # Pattern: li r3, N; blr (8B)
    if n == 2 and words[1] == 0x4E800020:
        op, rd, ra, imm, _ = decode_insn(words[0])
        if op == 14 and rd == 3 and ra == 0:  # li r3, N
            return "ret_const", f"int {name_safe}(void) {{ return {imm}; }}\n"

    # Pattern: lwz/lha/lbz/lhz r3, off(r3); blr (8B getter)
    if n == 2 and words[1] == 0x4E800020:
        op, rd, ra, off, _ = decode_insn(words[0])
        if rd == 3 and ra == 3:
            type_map = {32: ("int", "lwz"), 42: ("short", "lha"), 34: ("unsigned char", "lbz"), 40: ("unsigned short", "lhz")}
            if op in type_map:
                rtype, _ = type_map[op]
                struct_pad = f"char pad[0x{off & 0xFFFF:02X}];" if off > 0 else ""
                return "getter_8B", (
                    f"struct S_{addr:08X} {{ {struct_pad} {rtype} m_val; }};\n"
                    f"{rtype} {name_safe}(S_{addr:08X} *self) {{ return self->m_val; }}\n"
                )

    # Pattern: field store + blr or field store + li r3,1 + blr (8-12B setter)
    if n >= 2 and words[-1] == 0x4E800020:
        op0, rd0, ra0, off0, _ = decode_insn(words[0])
        if ra0 == 3 and rd0 == 4:  # stw/sth/stb r4, off(r3)
            store_ops = {36: ("int", "stw", 4), 44: ("short", "sth", 2), 38: ("unsigned char", "stb", 1)}
            if op0 in store_ops:
                rtype, _, sz = store_ops[op0]
                # Check if followed by li r3,1; blr or just blr
                if n == 2:
                    struct_pad = f"char pad[0x{off0 & 0xFFFF:02X}];" if off0 > 0 else ""
                    return "setter_8B", (
                        f"struct SS_{addr:08X} {{ {struct_pad} {rtype} m_val; }};\n"
                        f"void {name_safe}(SS_{addr:08X} *self, {rtype} val) {{ self->m_val = val; }}\n"
                    )
                if n == 3 and words[1] == 0x38600001:  # li r3, 1
                    struct_pad = f"char pad[0x{off0 & 0xFFFF:02X}];" if off0 > 0 else ""
                    return "setter_ret1", (
                        f"struct SS_{addr:08X} {{ {struct_pad} {rtype} m_val; }};\n"
                        f"int {name_safe}(SS_{addr:08X} *self, {rtype} val) {{ self->m_val = val; return 1; }}\n"
                    )

    # Pattern: lwz r3, off(r3); lwz/lha r3, off2(r3); blr (12B chained getter)
    if n == 3 and words[2] == 0x4E800020:
        op0, rd0, ra0, off0, _ = decode_insn(words[0])
        op1, rd1, ra1, off1, _ = decode_insn(words[1])
        if rd0 == 3 and ra0 == 3 and op0 == 32 and rd1 == 3 and ra1 == 3:
            type_map = {32: "int", 42: "short", 34: "unsigned char", 40: "unsigned short"}
            if op1 in type_map:
                rtype = type_map[op1]
                return "chain_getter_12B", (
                    f"struct Inner_{addr:08X} {{ char pad[0x{off1 & 0xFFFF:02X}]; {rtype} m_val; }};\n"
                    f"struct S_{addr:08X} {{ char pad[0x{off0 & 0xFFFF:02X}]; Inner_{addr:08X} *m_inner; }};\n"
                    f"{rtype} {name_safe}(S_{addr:08X} *self) {{ return self->m_inner->m_val; }}\n"
                )

    # Pattern: mr r3, r4; blr (8B - return second param)
    if n == 2 and words[1] == 0x4E800020 and words[0] == 0x7C832378:
        return "ret_param2", f"void *{name_safe}(void *a, void *b) {{ return b; }}\n"

    return "unknown", None


def main():
    # Build matched set
    matched = set()
    for f in glob.glob("src/matched/**/*.cpp", recursive=True):
        m = re.search(r"0x([0-9a-fA-F]{8})", os.path.basename(f))
        if m: matched.add(int(m.group(1), 16))

    # Parse missing_functions_report.txt
    functions = []
    with open("missing_functions_report.txt", "r") as f:
        for line in f:
            m = re.match(r"(0x[0-9a-fA-F]+)\s+(\d+)B\s+(.+)", line)
            if m:
                addr = int(m.group(1), 16)
                size = int(m.group(2))
                name = m.group(3).strip()
                if 4 <= size <= 64 and addr not in matched:
                    functions.append((addr, size, name))

    print(f"Total unmatched 4-64B: {len(functions)}")

    stats = {"empty_4B": 0, "ret_const": 0, "getter_8B": 0, "setter_8B": 0,
             "setter_ret1": 0, "chain_getter_12B": 0, "ret_param2": 0, "unknown": 0,
             "matched": 0, "failed": 0}

    for addr, size, name in functions:
        raw = dol_read(addr, size)
        if not raw or len(raw) != size:
            continue

        pattern, cpp = classify(addr, size, raw)
        stats[pattern] = stats.get(pattern, 0) + 1

        if cpp is None:
            continue

        # Write match file
        safe_name = re.sub(r'[^a-zA-Z0-9_]', '_', name)[:50]
        filepath = f"{MATCH_DIR}/match_0x{addr:08X}_{safe_name}.cpp"

        # Dedup check
        if os.path.exists(filepath):
            continue

        with open(filepath, "w") as f:
            f.write(f"/* {name} at 0x{addr:08X} ({size}B) — auto-matched */\n\n")
            f.write(cpp)

        # Verify
        result = subprocess.run(
            f"{VERIFY_CMD} {filepath} 0x{addr:08X} {size}",
            shell=True, capture_output=True, text=True, cwd="."
        )
        output = result.stdout + result.stderr
        if "MATCH" in output and "MISMATCH" not in output:
            stats["matched"] += 1
            if stats["matched"] % 20 == 0:
                print(f"  ... {stats['matched']} matches so far")
        else:
            stats["failed"] += 1
            os.remove(filepath)  # Remove non-matching files

    print(f"\n=== RESULTS ===")
    print(f"Patterns found:")
    for k, v in sorted(stats.items()):
        if v > 0 and k not in ("matched", "failed"):
            print(f"  {k}: {v}")
    print(f"\nAuto-matched: {stats['matched']}")
    print(f"Failed verification: {stats['failed']}")
    print(f"Unknown/complex: {stats['unknown']}")


if __name__ == "__main__":
    main()
