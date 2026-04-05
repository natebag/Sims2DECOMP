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

    # Pattern: setter + li r3, 0; blr (12B setter returning 0)
    if n == 3 and words[2] == 0x4E800020 and words[1] == 0x38600000:
        op0, rd0, ra0, off0, _ = decode_insn(words[0])
        store_ops = {36: "int", 44: "short", 38: "unsigned char"}
        if ra0 == 3 and rd0 == 4 and op0 in store_ops:
            rtype = store_ops[op0]
            struct_pad = f"char pad[0x{off0 & 0xFFFF:02X}];" if off0 > 0 else ""
            return "setter_ret0", (
                f"struct SS_{addr:08X} {{ {struct_pad} {rtype} m_val; }};\n"
                f"int {name_safe}(SS_{addr:08X} *self, {rtype} val) {{ self->m_val = val; return 0; }}\n"
            )

    # Pattern: two-field setter (stw+stw+blr, 12B)
    if n == 3 and words[2] == 0x4E800020:
        op0, rd0, ra0, off0, _ = decode_insn(words[0])
        op1, rd1, ra1, off1, _ = decode_insn(words[1])
        if op0 == 36 and op1 == 36 and ra0 == 3 and ra1 == 3:
            return "two_store", (
                f"struct TS_{addr:08X} {{ char pad1[0x{min(off0,off1) & 0xFFFF:02X}]; int m_a; "
                f"char pad2[0x{abs(off1-off0)-4:02X}]; int m_b; }};\n"
                f"void {name_safe}(TS_{addr:08X} *self, int a, int b) {{ "
                f"self->{'m_a' if off0 < off1 else 'm_b'} = {'a' if rd0 == 4 else 'b'}; "
                f"self->{'m_b' if off0 < off1 else 'm_a'} = {'b' if rd1 == 5 else 'a'}; }}\n"
            ) if rd0 in (4,5) and rd1 in (4,5) and off0 != off1 else ("unknown", None)

    # Pattern: SDA global getter (lwz r3, off(r13); blr — 8B)
    if n == 2 and words[1] == 0x4E800020:
        op, rd, ra, off, _ = decode_insn(words[0])
        if rd == 3 and ra == 13 and op == 32:  # lwz r3, sda(r13)
            return "sda_getter", (
                f"extern int g_{addr:08X};\n"
                f"int {name_safe}(void) {{ return g_{addr:08X}; }}\n"
            )
        if rd == 3 and ra == 13 and op == 42:  # lha r3, sda(r13)
            return "sda_getter_s", (
                f"extern short g_{addr:08X};\n"
                f"short {name_safe}(void) {{ return g_{addr:08X}; }}\n"
            )

    # Pattern: SDA global setter (stw r3, off(r13); blr — 8B)
    if n == 2 and words[1] == 0x4E800020:
        op, rd, ra, off, _ = decode_insn(words[0])
        if ra == 13 and op == 36 and rd == 3:  # stw r3, sda(r13)
            return "sda_setter", (
                f"extern int g_{addr:08X};\n"
                f"void {name_safe}(int val) {{ g_{addr:08X} = val; }}\n"
            )

    # Pattern: lfs f1, off(r3); blr (8B float getter)
    if n == 2 and words[1] == 0x4E800020:
        op, rd, ra, off, _ = decode_insn(words[0])
        if op == 48 and rd == 1 and ra == 3:  # lfs f1, off(r3)
            struct_pad = f"char pad[0x{off & 0xFFFF:02X}];" if off > 0 else ""
            return "float_getter", (
                f"struct SF_{addr:08X} {{ {struct_pad} float m_val; }};\n"
                f"float {name_safe}(SF_{addr:08X} *self) {{ return self->m_val; }}\n"
            )

    # Pattern: stfs f1, off(r3); blr (8B float setter)
    if n == 2 and words[1] == 0x4E800020:
        op, rd, ra, off, _ = decode_insn(words[0])
        if op == 52 and rd == 1 and ra == 3:  # stfs f1, off(r3)
            struct_pad = f"char pad[0x{off & 0xFFFF:02X}];" if off > 0 else ""
            return "float_setter", (
                f"struct SF_{addr:08X} {{ {struct_pad} float m_val; }};\n"
                f"void {name_safe}(SF_{addr:08X} *self, float val) {{ self->m_val = val; }}\n"
            )

    # Pattern: tail call — bl target; (no blr needed, 4B but encoded differently)
    # Actually: b target (not bl) = unconditional branch = tail call (opcode 18, AA=0, LK=0)
    if n == 1 and (words[0] & 0xFC000003) == 0x48000000:
        return "tail_call", (
            f"extern int tail_{addr:08X}(void);\n"
            f"int {name_safe}(void) {{ return tail_{addr:08X}(); }}\n"
        )

    # ========== PROLOGUE-BASED PATTERNS (stwu functions) ==========

    def is_prologue(w):
        return (w >> 16) == 0x9421  # stwu r1, -N(r1)

    def is_mflr(w):
        return w == 0x7C0802A6

    def is_stw_lr(w, frame):
        op, rd, ra, d, _ = decode_insn(w)
        return op == 36 and rd == 0 and ra == 1 and d == frame + 4

    def is_epilogue_lwz_lr(w, frame):
        op, rd, ra, d, _ = decode_insn(w)
        return op == 32 and rd == 0 and ra == 1 and d == frame + 4

    def is_mtlr(w):
        return w == 0x7C0803A6

    def is_addi_sp(w, frame):
        op, rd, ra, d, _ = decode_insn(w)
        return op == 14 and rd == 1 and ra == 1 and d == frame

    def is_blr(w):
        return w == 0x4E800020

    def is_bl(w):
        return (w & 0xFC000003) == 0x48000001

    def is_mr(w):
        """Check for or rD, rS, rS (move register). Returns (dst, src) or None."""
        op = (w >> 26) & 0x3F
        if op != 31: return None
        xo = (w >> 1) & 0x3FF
        if xo != 444: return None
        rs = (w >> 21) & 0x1F
        ra = (w >> 16) & 0x1F
        rb = (w >> 11) & 0x1F
        if rs == rb:
            return (ra, rs)
        return None

    if n >= 5 and is_prologue(words[0]):
        d = words[0] & 0xFFFF
        if d >= 0x8000: d -= 0x10000  # sign-extend
        frame = -d  # positive frame size (e.g., stwu r1,-8(r1) → frame=8)

        # Identify prologue end and epilogue start
        # Minimal prologue: stwu + mflr + stw_lr (3 insns)
        # Minimal epilogue: lwz_lr + mtlr + addi_sp + blr (4 insns)
        if (is_mflr(words[1]) and is_stw_lr(words[2], frame) and
            is_blr(words[-1]) and is_addi_sp(words[-2], frame) and
            is_mtlr(words[-3]) and is_epilogue_lwz_lr(words[-4], frame)):

            body = words[3:-4]

            # Simple wrapper: just one bl call (body = [bl])
            if len(body) == 1 and is_bl(body[0]):
                return "wrapper_bl", (
                    f"extern int wrap_{addr:08X}(void);\n"
                    f"int {name_safe}(void) {{ return wrap_{addr:08X}(); }}\n"
                )

            # Wrapper passing params through: mr rN, r3 + bl (body has param shuffle + bl)
            if len(body) == 2 and is_bl(body[1]):
                mr = is_mr(body[0])
                if mr and mr[1] == 3:  # mr rN, r3 (save this)
                    return "wrapper_save_this", (
                        f"extern int wrap_{addr:08X}(void *);\n"
                        f"int {name_safe}(void *self) {{ return wrap_{addr:08X}(self); }}\n"
                    )
                # li r4, N + bl (add a constant param)
                op_b, rd_b, ra_b, imm_b, _ = decode_insn(body[0])
                if op_b == 14 and ra_b == 0:  # li rN, imm
                    return "wrapper_add_param", (
                        f"extern int wrap_{addr:08X}(void *, int);\n"
                        f"int {name_safe}(void *self) {{ return wrap_{addr:08X}(self, {imm_b}); }}\n"
                    )

            # Wrapper with param swap: mr r5,r4; mr r4,r3; lis+addi r3; bl
            # or: mr rN,r3; bl; use result
            if len(body) == 3 and is_bl(body[2]):
                mr0 = is_mr(body[0])
                mr1 = is_mr(body[1])
                if mr0 and mr1:
                    return "wrapper_param_swap", (
                        f"extern int wrap_{addr:08X}(int, int, int);\n"
                        f"int {name_safe}(int a, int b) {{ return wrap_{addr:08X}(a, b, 0); }}\n"
                    )

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
