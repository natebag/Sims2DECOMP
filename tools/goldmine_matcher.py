#!/usr/bin/env python3
"""Auto-match goldmine functions from missing_functions_report.txt.

Classifies 4-64B functions by pattern and auto-generates C++ for trivial ones:
- Phase 1 (4-12B): empty, return constant, getter, setter, chained getter, tail call
- Phase 2 (40-56B): vtable dtor, op_delete, save-this-call-return, Construct,
  op_new, op_delete_alt, load_addr_call, global_destructors
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

    # ========== CONDITIONAL BRANCH PATTERNS ==========

    # Helpers for generic cmpwi detection
    def is_cmpwi_0(w):
        """Check for cmpwi cr0, rN, 0. Returns rN or None."""
        if (w & 0xFFE0FFFF) == 0x2C000000:  # cmpwi cr0, rN, 0
            return (w >> 16) & 0x1F
        return None

    BNELR = 0x4C820020
    BEQLR = 0x4D820020
    BLR = 0x4E800020

    # Pattern: cmpwi r3,0; bnelr/beqlr; li r3,N; blr (16B conditional return)
    if n == 4 and words[3] == BLR:
        if words[0] == 0x2C030000:  # cmpwi r3, 0
            op2, rd2, ra2, imm2, _ = decode_insn(words[2])
            if op2 == 14 and rd2 == 3 and ra2 == 0:  # li r3, N
                if words[1] == BNELR:
                    return "cond_ret_16B", (
                        f"int {name_safe}(int param) {{\n"
                        f"    if (param) return param;\n"
                        f"    return {imm2};\n"
                        f"}}\n"
                    )
                if words[1] == BEQLR:
                    return "cond_ret_beq_16B", (
                        f"int {name_safe}(int param) {{\n"
                        f"    if (!param) return 0;\n"
                        f"    return {imm2};\n"
                        f"}}\n"
                    )

    # Pattern: or. r3,r3,r3 (mr. r3,r3); beqlr; stw r3,off(r13); blr (16B SDA conditional store)
    if n == 4 and words[0] == 0x7C631B79 and words[1] == BEQLR and words[3] == BLR:
        op2, rd2, ra2, off2, _ = decode_insn(words[2])
        if op2 == 36 and rd2 == 3 and ra2 == 13:  # stw r3, off(r13) — SDA store
            return "cond_sda_store_16B", (
                f"extern int g_{addr:08X};\n"
                f"void {name_safe}(int val) {{\n"
                f"    if (!val) return;\n"
                f"    g_{addr:08X} = val;\n"
                f"}}\n"
            )

    # Pattern: lwz r3,off(r3); cmpwi r3,0; bnelr/beqlr; li r3,N; blr (20B field conditional)
    if n == 5 and words[4] == BLR:
        op0, rd0, ra0, off0, _ = decode_insn(words[0])
        if op0 == 32 and rd0 == 3 and ra0 == 3:  # lwz r3, off(r3)
            if words[1] == 0x2C030000:  # cmpwi r3, 0
                op3, rd3, ra3, imm3, _ = decode_insn(words[3])
                if op3 == 14 and rd3 == 3 and ra3 == 0:  # li r3, N
                    struct_pad = f"char pad[0x{off0 & 0xFFFF:02X}];" if off0 > 0 else ""
                    if words[2] == BNELR:
                        return "cond_field_ret_20B", (
                            f"struct S_{addr:08X} {{ {struct_pad} int m_val; }};\n"
                            f"int {name_safe}(S_{addr:08X}* self) {{\n"
                            f"    int x = self->m_val;\n"
                            f"    if (x) return x;\n"
                            f"    return {imm3};\n"
                            f"}}\n"
                        )
                    if words[2] == BEQLR:
                        return "cond_field_beq_20B", (
                            f"struct S_{addr:08X} {{ {struct_pad} int m_val; }};\n"
                            f"int {name_safe}(S_{addr:08X}* self) {{\n"
                            f"    if (!self->m_val) return 0;\n"
                            f"    return {imm3};\n"
                            f"}}\n"
                        )

    # Pattern: cmpwi r3,0; beq/bne +12; li r3,X; blr; li r3,Y; blr (24B if/else)
    if n == 6 and words[0] == 0x2C030000:  # cmpwi r3, 0
        is_beq = (words[1] & 0xFFFF0003) == 0x41820000
        is_bne = (words[1] & 0xFFFF0003) == 0x40820000
        if is_beq or is_bne:
            bd = words[1] & 0xFFFC
            if bd >= 0x8000: bd -= 0x10000
            if bd == 12 and words[3] == BLR and words[5] == BLR:
                op2, rd2, ra2, imm2, _ = decode_insn(words[2])
                op4, rd4, ra4, imm4, _ = decode_insn(words[4])
                if (op2 == 14 and rd2 == 3 and ra2 == 0 and
                    op4 == 14 and rd4 == 3 and ra4 == 0):
                    if is_beq:
                        return "if_else_24B", (
                            f"int {name_safe}(int param) {{\n"
                            f"    if (param) return {imm2};\n"
                            f"    return {imm4};\n"
                            f"}}\n"
                        )
                    else:
                        return "if_else_bne_24B", (
                            f"int {name_safe}(int param) {{\n"
                            f"    if (!param) return {imm2};\n"
                            f"    return {imm4};\n"
                            f"}}\n"
                        )

    # Pattern: SDA flag clear (24B) — lwz rX,off(r13); cmpwi rX,0; beqlr; li rY,val; stw rY,off(r13); blr
    # Stores back to same SDA base — ~18 functions (huge template family)
    if n == 6 and words[5] == BLR:
        op0, rd0, ra0, off0, _ = decode_insn(words[0])
        cmp_reg = is_cmpwi_0(words[1])
        if op0 == 32 and cmp_reg is not None and cmp_reg == rd0 and words[2] == BEQLR:
            op3, rd3, ra3, imm3, _ = decode_insn(words[3])
            op4, rd4, ra4, off4, _ = decode_insn(words[4])
            if (op3 == 14 and ra3 == 0 and  # li rY, val
                op4 == 36 and rd4 == rd3 and ra4 == ra0):  # stw rY, off2(rBase) — SAME base as lwz
                off0u = off0 & 0xFFFF
                off4u = off4 & 0xFFFF
                if ra0 == 13:  # SDA flag clear
                    return "sda_flag_clear_24B", (
                        f"extern int g_{addr:08X};\n"
                        f"void {name_safe}(void) {{\n"
                        f"    if (!g_{addr:08X}) return;\n"
                        f"    g_{addr:08X} = {imm3};\n"
                        f"}}\n"
                    )
                elif ra0 == 3:  # this->field check + store to different field of same object
                    pad1 = f"char pad1[0x{min(off0u,off4u):02X}];" if min(off0u,off4u) > 0 else ""
                    if off0u != off4u:
                        return "null_check_self_store_24B", (
                            f"struct S_{addr:08X} {{ {pad1} int m_check; char gap[0x{abs(off4u-off0u)-4:02X}]; int m_field; }};\n"
                            f"void {name_safe}(S_{addr:08X} *self) {{\n"
                            f"    if (!self->m_check) return;\n"
                            f"    self->m_field = {imm3};\n"
                            f"}}\n"
                        )

    # Pattern: null-check + store to deref'd pointer (24B)
    # lwz rN,off(rM); cmpwi rN,0; beqlr; li rD,val; stw rD,off2(rN); blr
    if n == 6 and words[5] == BLR:
        op0, rd0, ra0, off0, _ = decode_insn(words[0])
        cmp_reg = is_cmpwi_0(words[1])
        if op0 == 32 and cmp_reg is not None and cmp_reg == rd0 and words[2] == BEQLR:
            op3, rd3, ra3, imm3, _ = decode_insn(words[3])
            op4, rd4, ra4, off4, _ = decode_insn(words[4])
            if (op3 == 14 and ra3 == 0 and  # li rD, val
                op4 == 36 and rd4 == rd3 and ra4 == rd0 and ra4 != ra0):  # stw rD, off2(rN) — deref pointer
                off0u = off0 & 0xFFFF
                off4u = off4 & 0xFFFF
                if ra0 == 3:  # this->m_ptr
                    return "null_check_store_24B", (
                        f"struct Inner_{addr:08X} {{ char pad[0x{off4u:02X}]; int m_field; }};\n"
                        f"struct S_{addr:08X} {{ char pad[0x{off0u:02X}]; Inner_{addr:08X} *m_ptr; }};\n"
                        f"void {name_safe}(S_{addr:08X} *self) {{\n"
                        f"    Inner_{addr:08X} *p = self->m_ptr;\n"
                        f"    if (!p) return;\n"
                        f"    p->m_field = {imm3};\n"
                        f"}}\n"
                    )
                elif ra0 == 13:  # SDA global pointer
                    return "null_check_sda_store_24B", (
                        f"struct Target_{addr:08X} {{ char pad[0x{off4u:02X}]; int m_field; }};\n"
                        f"extern Target_{addr:08X} *g_ptr_{addr:08X};\n"
                        f"void {name_safe}(void) {{\n"
                        f"    Target_{addr:08X} *p = g_ptr_{addr:08X};\n"
                        f"    if (!p) return;\n"
                        f"    p->m_field = {imm3};\n"
                        f"}}\n"
                    )

    # Pattern: null-check + deref return (24B) — multiple instruction orderings
    # Variant A: lwz rN,off(rM); cmpwi rN,0; li r3,DEFAULT; beqlr; lwz r3,off2(rN); blr
    # Variant B: lwz rN,off(rM); li r3,DEFAULT; cmpwi rN,0; beqlr; lwz r3,off2(rN); blr
    # Variant C: lwz rN,off(rM); cmpwi rN,0; beqlr; lwz rD,off2(rN); stw rD,off3(rN); blr  (field copy)
    if n == 6 and words[5] == BLR:
        op0, rd0, ra0, off0, _ = decode_insn(words[0])
        if op0 == 32:  # first insn is lwz
            # Check variant A: lwz, cmpwi, li r3 VAL, beqlr, lwz r3, blr
            cmp1 = is_cmpwi_0(words[1])
            if cmp1 is not None and cmp1 == rd0 and words[3] == BEQLR:
                op2, rd2, ra2, imm2, _ = decode_insn(words[2])
                if op2 == 14 and rd2 == 3 and ra2 == 0:  # li r3, DEFAULT
                    op4, rd4, ra4, off4, _ = decode_insn(words[4])
                    if op4 == 32 and rd4 == 3 and ra4 == rd0:  # lwz r3, off2(rN)
                        off0u = off0 & 0xFFFF
                        off4u = off4 & 0xFFFF
                        if ra0 == 3:
                            return "null_deref_ret_24B", (
                                f"struct Inner_{addr:08X} {{ char pad[0x{off4u:02X}]; int m_val; }};\n"
                                f"struct S_{addr:08X} {{ char pad[0x{off0u:02X}]; Inner_{addr:08X} *m_ptr; }};\n"
                                f"int {name_safe}(S_{addr:08X} *self) {{\n"
                                f"    Inner_{addr:08X} *p = self->m_ptr;\n"
                                f"    if (!p) return {imm2};\n"
                                f"    return p->m_val;\n"
                                f"}}\n"
                            )
                        elif ra0 == 13:
                            return "null_deref_sda_ret_24B", (
                                f"struct Inner_{addr:08X} {{ char pad[0x{off4u:02X}]; int m_val; }};\n"
                                f"extern Inner_{addr:08X} *g_ptr_{addr:08X};\n"
                                f"int {name_safe}(void) {{\n"
                                f"    Inner_{addr:08X} *p = g_ptr_{addr:08X};\n"
                                f"    if (!p) return {imm2};\n"
                                f"    return p->m_val;\n"
                                f"}}\n"
                            )
            # Check variant B: lwz, li r3 VAL, cmpwi, beqlr, lwz r3, blr
            cmp2 = is_cmpwi_0(words[2])
            if cmp2 is not None and cmp2 == rd0 and words[3] == BEQLR:
                op1, rd1, ra1, imm1, _ = decode_insn(words[1])
                if op1 == 14 and rd1 == 3 and ra1 == 0:  # li r3, DEFAULT
                    op4, rd4, ra4, off4, _ = decode_insn(words[4])
                    if op4 == 32 and rd4 == 3 and ra4 == rd0:  # lwz r3, off2(rN)
                        off0u = off0 & 0xFFFF
                        off4u = off4 & 0xFFFF
                        if ra0 == 3:
                            return "null_deref_ret_24B", (
                                f"struct Inner_{addr:08X} {{ char pad[0x{off4u:02X}]; int m_val; }};\n"
                                f"struct S_{addr:08X} {{ char pad[0x{off0u:02X}]; Inner_{addr:08X} *m_ptr; }};\n"
                                f"int {name_safe}(S_{addr:08X} *self) {{\n"
                                f"    Inner_{addr:08X} *p = self->m_ptr;\n"
                                f"    if (!p) return {imm1};\n"
                                f"    return p->m_val;\n"
                                f"}}\n"
                            )
                        elif ra0 == 13:
                            return "null_deref_sda_ret_24B", (
                                f"struct Inner_{addr:08X} {{ char pad[0x{off4u:02X}]; int m_val; }};\n"
                                f"extern Inner_{addr:08X} *g_ptr_{addr:08X};\n"
                                f"int {name_safe}(void) {{\n"
                                f"    Inner_{addr:08X} *p = g_ptr_{addr:08X};\n"
                                f"    if (!p) return {imm1};\n"
                                f"    return p->m_val;\n"
                                f"}}\n"
                            )
            # Variant C: lwz rN, cmpwi rN, beqlr, lwz rD, stw rD, blr (field copy)
            cmp1c = is_cmpwi_0(words[1])
            if cmp1c is not None and cmp1c == rd0 and words[2] == BEQLR:
                op3, rd3, ra3, off3, _ = decode_insn(words[3])
                op4, rd4, ra4, off4, _ = decode_insn(words[4])
                if (op3 == 32 and ra3 == rd0 and  # lwz rD, off2(rN)
                    op4 == 36 and rd4 == rd3 and ra4 == rd0):  # stw rD, off3(rN)
                    off0u = off0 & 0xFFFF
                    off3u = off3 & 0xFFFF
                    off4u = off4 & 0xFFFF
                    if ra0 == 3:
                        return "null_field_copy_24B", (
                            f"struct Inner_{addr:08X} {{ char p1[0x{min(off3u,off4u):02X}]; int m_src; char p2[0x{abs(off4u-off3u)-4:02X}]; int m_dst; }};\n"
                            f"struct S_{addr:08X} {{ char pad[0x{off0u:02X}]; Inner_{addr:08X} *m_ptr; }};\n"
                            f"void {name_safe}(S_{addr:08X} *self) {{\n"
                            f"    Inner_{addr:08X} *p = self->m_ptr;\n"
                            f"    if (!p) return;\n"
                            f"    p->m_dst = p->m_src;\n"
                            f"}}\n"
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
                # li rN, imm + bl (set register rN to constant, pass-through others)
                op_b, rd_b, ra_b, imm_b, _ = decode_insn(body[0])
                if op_b == 14 and ra_b == 0 and 4 <= rd_b <= 10:  # li rN, imm
                    # r3=self passes through, r4..rd_b-1 pass through, rd_b = imm
                    n_pass = rd_b - 4  # number of pass-through params after self
                    pass_decls = "".join(f", int a{i}" for i in range(n_pass))
                    pass_args = "".join(f", a{i}" for i in range(n_pass))
                    ext_args = ", ".join(["void *"] + ["int"] * (rd_b - 3))
                    return "wrapper_add_param", (
                        f"extern int wrap_{addr:08X}({ext_args});\n"
                        f"int {name_safe}(void *self{pass_decls}) {{ return wrap_{addr:08X}(self{pass_args}, {imm_b}); }}\n"
                    )

            # lwz rN,off(r13) + bl — load SDA global as param and call
            if len(body) == 2 and is_bl(body[1]):
                op_b, rd_b, ra_b, off_b, _ = decode_insn(body[0])
                if op_b == 32 and ra_b == 13 and 3 <= rd_b <= 10:  # lwz rN, off(r13)
                    if rd_b == 3:
                        return "sda_load_call", (
                            f"extern char g_{addr:08X}[4];\n"
                            f"extern int wrap_{addr:08X}(int);\n"
                            f"int {name_safe}(void) {{ return wrap_{addr:08X}(*(int*)g_{addr:08X}); }}\n"
                        )
                    else:
                        n_pass = rd_b - 3  # params r3..rN-1 pass through
                        pass_decls = ", ".join(f"int a{i}" for i in range(n_pass))
                        pass_args = ", ".join(f"a{i}" for i in range(n_pass))
                        ext_args = ", ".join(["int"] * (rd_b - 2))
                        return "sda_extra_param_call", (
                            f"extern char g_{addr:08X}[4];\n"
                            f"extern int wrap_{addr:08X}({ext_args});\n"
                            f"int {name_safe}({pass_decls}) {{ return wrap_{addr:08X}({pass_args}, *(int*)g_{addr:08X}); }}\n"
                        )

            # lwz rN,off(r3) + bl where rN != r3 — load field as extra param
            if len(body) == 2 and is_bl(body[1]):
                op_b, rd_b, ra_b, off_b, _ = decode_insn(body[0])
                if op_b == 32 and ra_b == 3 and rd_b != 3 and 4 <= rd_b <= 10:
                    off_u = off_b & 0xFFFF
                    n_pass = rd_b - 4  # params r4..rN-1 pass through
                    pass_decls = "".join(f", int a{i}" for i in range(n_pass))
                    pass_args = "".join(f", a{i}" for i in range(n_pass))
                    ext_params = ", ".join(["void *"] + ["int"] * (rd_b - 3))
                    struct_pad = f"char pad[0x{off_u:02X}];" if off_b > 0 else ""
                    return "field_extra_param_call", (
                        f"struct S_{addr:08X} {{ {struct_pad} int m_val; }};\n"
                        f"extern int wrap_{addr:08X}({ext_params});\n"
                        f"int {name_safe}(S_{addr:08X} *self{pass_decls}) {{ return wrap_{addr:08X}(self{pass_args}, self->m_val); }}\n"
                    )

            # addi r3,r3,OFF + bl — adjust this pointer and forward
            if len(body) == 2 and is_bl(body[1]):
                op_b = (body[0] >> 26) & 0x3F
                rd_b = (body[0] >> 21) & 0x1F
                ra_b = (body[0] >> 16) & 0x1F
                if op_b == 14 and rd_b == 3 and ra_b == 3:  # addi r3, r3, off
                    off_b = body[0] & 0xFFFF
                    if off_b >= 0x8000: off_b -= 0x10000
                    return "wrapper_addi_this", (
                        f"typedef unsigned char u8;\n"
                        f"extern int wrap_{addr:08X}(u8 *);\n"
                        f"int {name_safe}(u8 *self) {{ return wrap_{addr:08X}(self + {off_b}); }}\n"
                    )

            # lwz r3,off(r3) + bl — load member and forward to function
            if len(body) == 2 and is_bl(body[1]):
                op_b, rd_b, ra_b, off_b, _ = decode_insn(body[0])
                if op_b == 32 and rd_b == 3 and ra_b == 3:  # lwz r3, off(r3)
                    return "wrapper_deref_call", (
                        f"struct W_{addr:08X} {{ char pad[0x{off_b & 0xFFFF:X}]; void *m_ptr; }};\n"
                        f"extern int wrap_{addr:08X}(void *);\n"
                        f"int {name_safe}(W_{addr:08X} *self) {{ return wrap_{addr:08X}(self->m_ptr); }}\n"
                    )

            # bl + li r3,N — call function then return constant
            if len(body) == 2 and is_bl(body[0]):
                op_b, rd_b, ra_b, imm_b, _ = decode_insn(body[1])
                if op_b == 14 and rd_b == 3 and ra_b == 0:  # li r3, N
                    return "call_ret_const", (
                        f"extern void call_{addr:08X}(void *);\n"
                        f"int {name_safe}(void *self) {{ call_{addr:08X}(self); return {imm_b}; }}\n"
                    )

            # Two-call chain: bl + bl (return func2(func1(self)))
            if len(body) == 2 and is_bl(body[0]) and is_bl(body[1]):
                return "two_call_chain", (
                    f"extern int inner1_{addr:08X}(void*);\n"
                    f"extern int inner2_{addr:08X}(int);\n"
                    f"int {name_safe}(void *self) {{\n"
                    f"    return inner2_{addr:08X}(inner1_{addr:08X}(self));\n"
                    f"}}\n"
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

            # body=3: mr rN+1,rN + li rN,val + bl (shift param and set)
            if len(body) == 3 and is_bl(body[2]):
                mr0 = is_mr(body[0])
                op_li1 = (body[1] >> 26) & 0x3F
                ra_li1 = (body[1] >> 16) & 0x1F
                if mr0 and op_li1 == 14 and ra_li1 == 0:  # li check
                    li_rd = (body[1] >> 21) & 0x1F
                    li_val = body[1] & 0xFFFF
                    if li_val >= 0x8000: li_val -= 0x10000
                    if mr0[0] == li_rd + 1 and mr0[1] == li_rd:
                        # mr rN+1,rN (shift param up) + li rN,val
                        n_pass = li_rd - 4  # params from r4 to li_rd-1
                        wrapper_p = ["void *self"] + [f"int a{i}" for i in range(n_pass)] + [f"int a_shift"]
                        target_p = ["void *"] + ["int"] * (mr0[0] - 3)
                        call_a = ["self"] + [f"a{i}" for i in range(n_pass)] + [str(li_val), "a_shift"]
                        return "shift_param_call", (
                            f"extern int tgt_{addr:08X}({', '.join(target_p)});\n"
                            f"int {name_safe}({', '.join(wrapper_p)}) {{ return tgt_{addr:08X}({', '.join(call_a)}); }}\n"
                        )

            # body=3: lwz rN,off(r3) + li rM,val + bl (load field + set param + call)
            if len(body) == 3 and is_bl(body[2]):
                op_b0 = (body[0] >> 26) & 0x3F
                rd_b0 = (body[0] >> 21) & 0x1F
                ra_b0 = (body[0] >> 16) & 0x1F
                off_b0 = body[0] & 0xFFFF
                if off_b0 >= 0x8000: off_b0 -= 0x10000
                op_li1b = (body[1] >> 26) & 0x3F
                ra_li1b = (body[1] >> 16) & 0x1F
                if op_b0 == 32 and ra_b0 == 3 and op_li1b == 14 and ra_li1b == 0:  # lwz rN,off(r3) + li rM,val
                    li_rd = (body[1] >> 21) & 0x1F
                    li_val = body[1] & 0xFFFF
                    if li_val >= 0x8000: li_val -= 0x10000
                    if rd_b0 >= 4 and li_rd >= 4:
                        max_reg = max(rd_b0, li_rd)
                        n_args = max_reg - 3 + 1
                        tgt_params = ", ".join(["void *"] + ["int"] * (n_args - 1))
                        call_args = ["self"]
                        for i in range(1, n_args):
                            r = 3 + i
                            if r == rd_b0:
                                if off_b0 >= 0:
                                    call_args.append(f"*(int*)((char*)self + {off_b0})")
                                else:
                                    call_args.append(f"*(int*)((char*)self + ({off_b0}))")
                            elif r == li_rd:
                                call_args.append(str(li_val))
                            else:
                                call_args.append(f"a{i}")
                        # Determine which params pass through from caller
                        pass_params = []
                        for i in range(1, n_args):
                            r = 3 + i
                            if r != rd_b0 and r != li_rd:
                                pass_params.append(f"int a{i}")
                        wrapper_p = ["void *self"] + pass_params
                        return "load_field_param_call", (
                            f"extern int tgt_{addr:08X}({tgt_params});\n"
                            f"int {name_safe}({', '.join(wrapper_p)}) {{ return tgt_{addr:08X}({', '.join(call_args)}); }}\n"
                        )

            # Two-call chain with mr: bl + mr rN,r3 + bl
            if len(body) == 3 and is_bl(body[0]) and is_bl(body[2]):
                mr_pair = is_mr(body[1])
                if mr_pair and mr_pair[1] == 3:  # mr rN, r3 (save func1 result)
                    dst = mr_pair[0]
                    if dst == 4:
                        # mr r4,r3: func2 gets (func1_result, func1_result)
                        return "two_call_mr_chain", (
                            f"extern int inner1_{addr:08X}(void*);\n"
                            f"extern int inner2_{addr:08X}(int, int);\n"
                            f"int {name_safe}(void *self) {{\n"
                            f"    int x = inner1_{addr:08X}(self);\n"
                            f"    return inner2_{addr:08X}(x, x);\n"
                            f"}}\n"
                        )
                    elif 5 <= dst <= 10:
                        # mr rN,r3: result goes to higher param register
                        n_args = dst - 3 + 1
                        tgt_params = ", ".join(["int"] * n_args)
                        call_args = ["x"] + ["0"] * (dst - 4) + ["x"]
                        return "two_call_mr_chain", (
                            f"extern int inner1_{addr:08X}(void*);\n"
                            f"extern int inner2_{addr:08X}({tgt_params});\n"
                            f"int {name_safe}(void *self) {{\n"
                            f"    int x = inner1_{addr:08X}(self);\n"
                            f"    return inner2_{addr:08X}({', '.join(call_args)});\n"
                            f"}}\n"
                        )

            # ========== NEW BODY PATTERNS (round 2) ==========

            # body=3: li rN,val + bl + bl (constant param → two-call chain)
            if len(body) == 3 and is_bl(body[1]) and is_bl(body[2]):
                op_b0, rd_b0, ra_b0, imm_b0, _ = decode_insn(body[0])
                if op_b0 == 14 and ra_b0 == 0 and rd_b0 == 3:  # li r3, val
                    return "li_two_call_chain", (
                        f"extern int inner1_{addr:08X}(int);\n"
                        f"extern int inner2_{addr:08X}(int);\n"
                        f"int {name_safe}(void) {{\n"
                        f"    return inner2_{addr:08X}(inner1_{addr:08X}({imm_b0}));\n"
                        f"}}\n"
                    )

            # body=3: addi r3,r13,off + li rN,val + bl (SDA addr + param + call)
            if len(body) == 3 and is_bl(body[2]):
                op_b0 = (body[0] >> 26) & 0x3F
                rd_b0 = (body[0] >> 21) & 0x1F
                ra_b0 = (body[0] >> 16) & 0x1F
                op_b1 = (body[1] >> 26) & 0x3F
                ra_b1 = (body[1] >> 16) & 0x1F
                if op_b0 == 14 and rd_b0 == 3 and ra_b0 == 13:  # addi r3, r13, off (SDA)
                    if op_b1 == 14 and ra_b1 == 0:  # li rN, val
                        li_rd1 = (body[1] >> 21) & 0x1F
                        li_val1 = body[1] & 0xFFFF
                        if li_val1 >= 0x8000: li_val1 -= 0x10000
                        if li_rd1 == 4:
                            return "sda_addr_param_call", (
                                f"extern char g_{addr:08X}[4];\n"
                                f"extern int func_{addr:08X}(void *, int);\n"
                                f"int {name_safe}(void) {{\n"
                                f"    return func_{addr:08X}(g_{addr:08X}, {li_val1});\n"
                                f"}}\n"
                            )

            # body=3: mr r4,r3 + lwz r3,off(r4) + bl (deref with self pass-through)
            if len(body) == 3 and is_bl(body[2]):
                mr_b0 = is_mr(body[0])
                if mr_b0 and mr_b0[1] == 3 and mr_b0[0] == 4:  # mr r4, r3
                    op_b1, rd_b1, ra_b1, off_b1, _ = decode_insn(body[1])
                    if op_b1 == 32 and rd_b1 == 3 and ra_b1 == 4:  # lwz r3, off(r4)
                        off_u = off_b1 & 0xFFFF
                        struct_pad = f"char pad[0x{off_u:02X}];" if off_b1 > 0 else ""
                        return "deref_self_call", (
                            f"struct S_{addr:08X} {{ {struct_pad} void *m_inner; }};\n"
                            f"extern int func_{addr:08X}(void *, S_{addr:08X} *);\n"
                            f"int {name_safe}(S_{addr:08X} *self) {{\n"
                            f"    return func_{addr:08X}(self->m_inner, self);\n"
                            f"}}\n"
                        )

            # body=4: mr r0,r3 + mr r3,r4 + mr r4,r0 + bl (param swap via r0)
            if len(body) == 4 and is_bl(body[3]):
                mr_b0 = is_mr(body[0])
                mr_b1 = is_mr(body[1])
                mr_b2 = is_mr(body[2])
                if (mr_b0 and mr_b1 and mr_b2 and
                    mr_b0[1] == 3 and mr_b0[0] == 0 and  # mr r0, r3
                    mr_b1[1] == 4 and mr_b1[0] == 3 and  # mr r3, r4
                    mr_b2[1] == 0 and mr_b2[0] == 4):    # mr r4, r0
                    return "param_swap_call", (
                        f"extern int func_{addr:08X}(int, int);\n"
                        f"int {name_safe}(int a, int b) {{\n"
                        f"    return func_{addr:08X}(b, a);\n"
                        f"}}\n"
                    )

            # body=4: li rA,val1 + li rB,val2 + ori rC,rD,mask + bl (generalized global ctor/dtor)
            if len(body) == 4 and is_bl(body[3]):
                op_b0 = (body[0] >> 26) & 0x3F
                ra_b0 = (body[0] >> 16) & 0x1F
                op_b1 = (body[1] >> 26) & 0x3F
                ra_b1 = (body[1] >> 16) & 0x1F
                op_b2 = (body[2] >> 26) & 0x3F
                if op_b0 == 14 and ra_b0 == 0 and op_b1 == 14 and ra_b1 == 0 and op_b2 == 24:
                    # li + li + ori + bl — setup params with ori for large unsigned values
                    rd_b0 = (body[0] >> 21) & 0x1F
                    val_b0 = body[0] & 0xFFFF
                    if val_b0 >= 0x8000: val_b0 -= 0x10000
                    rd_b1 = (body[1] >> 21) & 0x1F
                    val_b1 = body[1] & 0xFFFF
                    if val_b1 >= 0x8000: val_b1 -= 0x10000
                    ori_ra = (body[2] >> 16) & 0x1F
                    ori_rs = (body[2] >> 21) & 0x1F
                    ori_mask = body[2] & 0xFFFF
                    if ori_rs == rd_b0 and ori_ra == rd_b0:  # ori extends first li
                        combined = (val_b0 & 0xFFFF) | ori_mask  # NOT sign-extended for ori
                        if rd_b0 == 4 and rd_b1 == 3:
                            return "global_init_44B", (
                                f"// FLAGS: -fno-elide-constructors\n"
                                f"extern void cleanup_{addr:08X}(int a, unsigned int b);\n"
                                f"\n"
                                f"void global_init_{addr:08X}(void) {{\n"
                                f"    cleanup_{addr:08X}({val_b1}, {combined}u);\n"
                                f"}}\n"
                            )
                    elif ori_rs == rd_b1 and ori_ra == rd_b1:  # ori extends second li
                        combined = (val_b1 & 0xFFFF) | ori_mask
                        if rd_b1 == 4 and rd_b0 == 3:
                            return "global_init_44B", (
                                f"// FLAGS: -fno-elide-constructors\n"
                                f"extern void cleanup_{addr:08X}(int a, unsigned int b);\n"
                                f"\n"
                                f"void global_init_{addr:08X}(void) {{\n"
                                f"    cleanup_{addr:08X}({val_b0}, {combined}u);\n"
                                f"}}\n"
                            )

    # ========== PHASE 2: 40-56B TEMPLATE PATTERNS ==========

    def is_lis(w):
        return (w >> 26) & 0x3F == 15  # addis rd, 0, imm

    def is_li(w):
        op = (w >> 26) & 0x3F
        ra = (w >> 16) & 0x1F
        return op == 14 and ra == 0

    def get_li_val(w):
        d = w & 0xFFFF
        if d >= 0x8000: d -= 0x10000
        return d

    def get_li_rd(w):
        return (w >> 21) & 0x1F

    def get_lis_hi(w):
        d = w & 0xFFFF
        if d >= 0x8000: d -= 0x10000
        return d

    def is_addi(w):
        op = (w >> 26) & 0x3F
        ra = (w >> 16) & 0x1F
        return op == 14 and ra != 0

    def is_stw(w):
        return (w >> 26) & 0x3F == 36

    def is_ori(w):
        return (w >> 26) & 0x3F == 24

    def is_stmw(w):
        return (w >> 26) & 0x3F == 47

    def is_lmw(w):
        return (w >> 26) & 0x3F == 46

    # --- Frame8 prologue/epilogue (stwu r1,-8; mflr; stw r0,12(r1) / lwz r0,12; mtlr; addi r1,8; blr)
    FRAME8_PRO = [0x9421FFF8, 0x7C0802A6, 0x9001000C]
    FRAME8_EPI = [0x8001000C, 0x7C0803A6, 0x38210008, 0x4E800020]

    def check_frame8(words):
        if len(words) < 8: return None
        if words[:3] == FRAME8_PRO and words[-4:] == FRAME8_EPI:
            return words[3:-4]
        return None

    # --- Frame16 prologue/epilogue with stmw r30 (stwu r1,-16; mflr; stmw r30,8; stw r0,20 / lwz r0,20; mtlr; lmw r30,8; addi r1,16; blr)
    FRAME16_R30_PRO = [0x9421FFF0, 0x7C0802A6, 0xBFC10008, 0x90010014]
    FRAME16_R30_EPI = [0x80010014, 0x7C0803A6, 0xBBC10008, 0x38210010, 0x4E800020]

    def check_frame16_r30(words):
        if len(words) < 10: return None
        if words[:4] == FRAME16_R30_PRO and words[-5:] == FRAME16_R30_EPI:
            return words[4:-5]
        return None

    body = None

    # --- Pattern: 48B vtable dtor (frame8) ---
    # body: lis rN,HI + mr rM,r3 + addi rN,rN,LO + stw rN,OFF(rM) + bl
    body = check_frame8(words)
    if body is not None and len(body) == 5:
        w0, w1, w2, w3, w4 = body
        mr1 = is_mr(w1)
        if (is_lis(w0) and mr1 and mr1[1] == 3 and is_addi(w2) and is_stw(w3) and is_bl(w4)):
            vt_reg = (w0 >> 21) & 0x1F
            addi_rd = (w2 >> 21) & 0x1F
            addi_ra = (w2 >> 16) & 0x1F
            stw_rd = (w3 >> 21) & 0x1F
            stw_ra = (w3 >> 16) & 0x1F
            stw_off = w3 & 0xFFFF
            if stw_off >= 0x8000: stw_off -= 0x10000
            if (addi_rd == vt_reg and addi_ra == vt_reg and
                stw_rd == vt_reg and stw_ra == mr1[0]):
                return "vtable_dtor_48B", (
                    f"typedef unsigned char u8;\n"
                    f"extern int VT_{addr:08X}[];\n"
                    f"void base_{addr:08X}(u8*);\n"
                    f"void dtor_{addr:08X}(u8* self) {{\n"
                    f"    *(int**)(self + 0x{stw_off & 0xFFFF:X}) = VT_{addr:08X};\n"
                    f"    base_{addr:08X}(self);\n"
                    f"}}\n"
                )

    # --- Pattern: 48B save-this-call-return (frame16 r30) ---
    # body: mr r30,r3 + bl + mr r3,r30
    body = check_frame16_r30(words)
    if body is not None and len(body) == 3:
        if (body[0] == 0x7C7E1B78 and is_bl(body[1]) and body[2] == 0x7FC3F378):
            return "save_this_call_ret_48B", (
                f"extern void inner_{addr:08X}(void*);\n"
                f"void *save_call_ret_{addr:08X}(void *self) {{\n"
                f"    inner_{addr:08X}(self);\n"
                f"    return self;\n"
                f"}}\n"
            )

    # --- Pattern: 52B op_delete (frame16 r30) ---
    # body: mr r30,r3 + bl(getHeap) + mr r4,r30 + bl(free)
    body = check_frame16_r30(words)
    if body is not None and len(body) == 4:
        if (body[0] == 0x7C7E1B78 and is_bl(body[1]) and
            body[2] == 0x7FC4F378 and is_bl(body[3])):
            return "op_delete_52B", (
                f"extern void *getDelHeap_{addr:08X}(void);\n"
                f"extern void heapDel_{addr:08X}(void *, void *);\n"
                f"\n"
                f"void op_delete_{addr:08X}(void *ptr) {{\n"
                f"    void *heap = getDelHeap_{addr:08X}();\n"
                f"    heapDel_{addr:08X}(heap, ptr);\n"
                f"}}\n"
            )

    # --- Pattern: 52B field-load-call-store (frame16 r30) ---
    # body: mr rN,r3 + lwz r3,off(rN) + bl + stw r3,off2(rN) where rN is r30 or r31
    body = check_frame16_r30(words)
    if body is not None and len(body) == 4:
        mr0 = is_mr(body[0])
        if mr0 and mr0[1] == 3 and mr0[0] in (30, 31):
            save_reg = mr0[0]
            op1, rd1, ra1, off1, _ = decode_insn(body[1])
            op3, rd3, ra3, off3, _ = decode_insn(body[3])
            if (op1 == 32 and rd1 == 3 and ra1 == save_reg and  # lwz r3, off(rN)
                is_bl(body[2]) and
                op3 == 36 and rd3 == 3 and ra3 == save_reg):  # stw r3, off2(rN)
                off_in = off1 if off1 >= 0 else off1 + 0x10000
                off_out = off3 if off3 >= 0 else off3 + 0x10000
                if off_in == off_out:
                    pad = f"char pad[0x{off_in:02X}];" if off_in > 0 else ""
                    return "field_call_store_52B", (
                        f"struct S_{addr:08X} {{ {pad} int m_val; }};\n"
                        f"extern int call_{addr:08X}(int);\n"
                        f"void {name_safe}(S_{addr:08X} *self) {{\n"
                        f"    self->m_val = call_{addr:08X}(self->m_val);\n"
                        f"}}\n"
                    )
                else:
                    min_off = min(off_in, off_out)
                    max_off = max(off_in, off_out)
                    pad1 = f"char pad1[0x{min_off:02X}];" if min_off > 0 else ""
                    gap = max_off - min_off - 4
                    pad2 = f" char pad2[0x{gap:02X}];" if gap > 0 else ""
                    if off_in < off_out:
                        return "field_call_store_52B", (
                            f"struct S_{addr:08X} {{ {pad1} int m_in;{pad2} int m_out; }};\n"
                            f"extern int call_{addr:08X}(int);\n"
                            f"void {name_safe}(S_{addr:08X} *self) {{\n"
                            f"    self->m_out = call_{addr:08X}(self->m_in);\n"
                            f"}}\n"
                        )
                    else:
                        return "field_call_store_52B", (
                            f"struct S_{addr:08X} {{ {pad1} int m_out;{pad2} int m_in; }};\n"
                            f"extern int call_{addr:08X}(int);\n"
                            f"void {name_safe}(S_{addr:08X} *self) {{\n"
                            f"    self->m_out = call_{addr:08X}(self->m_in);\n"
                            f"}}\n"
                        )

    # --- Pattern: 52B two-call-self (frame16 r30) ---
    # body: mr rN,r3 + bl + mr r3,rN + bl — call two funcs with same self
    body = check_frame16_r30(words)
    if body is not None and len(body) == 4:
        mr0 = is_mr(body[0])
        mr2 = is_mr(body[2])
        if (mr0 and mr0[1] == 3 and mr0[0] in (30, 31) and
            is_bl(body[1]) and
            mr2 and mr2[0] == 3 and mr2[1] == mr0[0] and
            is_bl(body[3])):
            return "two_call_self_52B", (
                f"extern void call1_{addr:08X}(void*);\n"
                f"extern int call2_{addr:08X}(void*);\n"
                f"int {name_safe}(void *self) {{\n"
                f"    call1_{addr:08X}(self);\n"
                f"    return call2_{addr:08X}(self);\n"
                f"}}\n"
            )

    # --- Pattern: 44B Construct (frame8) ---
    # body: mr r4,r3 + li r3,SIZE + bl(new) + bl(ctor)
    body = check_frame8(words)
    if body is not None and len(body) == 4:
        mr0 = is_mr(body[0])
        if (mr0 and mr0[1] == 3 and mr0[0] == 4 and
            is_li(body[1]) and get_li_rd(body[1]) == 3 and
            is_bl(body[2]) and is_bl(body[3])):
            alloc_size = get_li_val(body[1])
            return "construct_44B", (
                f"struct S_{addr:08X};\n"
                f"extern \"C\" void* operator_new_{addr:08X}(unsigned int size);\n"
                f"extern \"C\" void ctor_{addr:08X}(S_{addr:08X}* self);\n"
                f"\n"
                f"S_{addr:08X}* construct_{addr:08X}(S_{addr:08X}* self) {{\n"
                f"    S_{addr:08X}* obj = (S_{addr:08X}*)operator_new_{addr:08X}({alloc_size});\n"
                f"    ctor_{addr:08X}(obj);\n"
                f"    return obj;\n"
                f"}}\n"
            )

    # --- Pattern: 48B op_new with lis+addi (frame8) ---
    # body: mr r4,r3 + li r5,ALIGN + lis r3,HI + addi r3,r3,LO + bl(alloc)
    body = check_frame8(words)
    if body is not None and len(body) == 5:
        mr0 = is_mr(body[0])
        if (mr0 and mr0[1] == 3 and mr0[0] == 4 and
            is_li(body[1]) and get_li_rd(body[1]) == 5 and
            is_lis(body[2]) and (body[2] >> 21) & 0x1F == 3 and
            is_addi(body[3]) and (body[3] >> 21) & 0x1F == 3 and (body[3] >> 16) & 0x1F == 3 and
            is_bl(body[4])):
            align_val = get_li_val(body[1])
            return "op_new_48B", (
                f"// FLAGS: -fno-elide-constructors\n"
                f"extern int gHeap_{addr:08X}[];\n"
                f"void *Heap_Alloc_{addr:08X}(void *, int, int);\n"
                f"\n"
                f"void *op_new_{addr:08X}(int size) {{\n"
                f"    return Heap_Alloc_{addr:08X}(gHeap_{addr:08X}, size, {align_val});\n"
                f"}}\n"
            )

    # --- Pattern: 44B op_delete with lis+addi (frame8) ---
    # body: mr r4,r3 + lis r3,HI + addi r3,r3,LO + bl(free)
    body = check_frame8(words)
    if body is not None and len(body) == 4:
        mr0 = is_mr(body[0])
        if (mr0 and mr0[1] == 3 and mr0[0] == 4 and
            is_lis(body[1]) and (body[1] >> 21) & 0x1F == 3 and
            is_addi(body[2]) and (body[2] >> 21) & 0x1F == 3 and (body[2] >> 16) & 0x1F == 3 and
            is_bl(body[3])):
            return "op_delete_44B", (
                f"// FLAGS: -fno-elide-constructors\n"
                f"extern int g_heap_{addr:08X}[];\n"
                f"extern void heapFree_{addr:08X}(void *, void *);\n"
                f"\n"
                f"void op_delete_{addr:08X}(void *ptr) {{\n"
                f"    heapFree_{addr:08X}(g_heap_{addr:08X}, ptr);\n"
                f"}}\n"
            )

    # --- Pattern: 40B load_addr_call (frame8) ---
    # body: lis r3,HI + addi r3,r3,LO + bl
    body = check_frame8(words)
    if body is not None and len(body) == 3:
        if (is_lis(body[0]) and (body[0] >> 21) & 0x1F == 3 and
            is_addi(body[1]) and (body[1] >> 21) & 0x1F == 3 and (body[1] >> 16) & 0x1F == 3 and
            is_bl(body[2])):
            return "load_addr_call_40B", (
                f"// FLAGS: -fno-elide-constructors\n"
                f"extern int g_obj_{addr:08X}[];\n"
                f"extern void func_{addr:08X}(void *);\n"
                f"\n"
                f"void load_call_{addr:08X}(void) {{\n"
                f"    func_{addr:08X}(g_obj_{addr:08X});\n"
                f"}}\n"
            )

    # --- Pattern: 44B global_destructors (frame8) ---
    # body: li r4,0 + li r3,0 + ori r4,r4,0xFFFF + bl
    body = check_frame8(words)
    if body is not None and len(body) == 4:
        if (body[0] == 0x38800000 and body[1] == 0x38600000 and
            body[2] == 0x6084FFFF and is_bl(body[3])):
            return "global_destructors_44B", (
                f"// FLAGS: -fno-elide-constructors\n"
                f"extern void cleanup_{addr:08X}(int a, unsigned short b);\n"
                f"\n"
                f"void global_dtor_{addr:08X}(void) {{\n"
                f"    cleanup_{addr:08X}(0, 0xFFFF);\n"
                f"}}\n"
            )

    # --- Pattern: 52B op_new with bl+li sequence (frame8) ---
    # body: bl(getHeap) + li r4,SIZE + li r5,ALIGN + li r6,0 + li r7,0 + bl(alloc)
    body = check_frame8(words)
    if body is not None and len(body) == 6:
        if (is_bl(body[0]) and
            is_li(body[1]) and get_li_rd(body[1]) == 4 and
            is_li(body[2]) and get_li_rd(body[2]) == 5 and
            is_li(body[3]) and get_li_rd(body[3]) == 6 and get_li_val(body[3]) == 0 and
            is_li(body[4]) and get_li_rd(body[4]) == 7 and get_li_val(body[4]) == 0 and
            is_bl(body[5])):
            alloc_size = get_li_val(body[1])
            align_val = get_li_val(body[2])
            return "op_new_52B", (
                f"extern void *getNewHeap_{addr:08X}(void);\n"
                f"extern void *heapAlloc_{addr:08X}(void *, int, int, int, int);\n"
                f"\n"
                f"void *op_new_{addr:08X}(unsigned int) {{\n"
                f"    void *heap = getNewHeap_{addr:08X}();\n"
                f"    return heapAlloc_{addr:08X}(heap, {alloc_size}, {align_val}, 0, 0);\n"
                f"}}\n"
            )

    # --- Pattern: 44B param forwarding (frame8) ---
    # body: li rA,X + li rB,Y + li rC,Z + bl  (3 li + bl, various regs)
    body = check_frame8(words)
    if body is not None and len(body) == 4:
        if (is_li(body[0]) and is_li(body[1]) and is_li(body[2]) and is_bl(body[3])):
            # All 3 are li instructions — build param list
            params = []
            for i in range(3):
                rd = get_li_rd(body[i])
                val = get_li_val(body[i])
                params.append((rd, val))
            # Sort by register to determine function signature
            # r3=self/1st arg, r4=2nd, r5=3rd, r6=4th, etc.
            # Skip if any non-standard register pattern
            regs = [p[0] for p in params]
            if all(3 <= r <= 10 for r in regs):
                max_reg = max(regs)
                n_args = max_reg - 3 + 1
                # Build arg string
                arg_decls = ", ".join(f"int a{i}" for i in range(n_args))
                call_args = []
                for i in range(n_args):
                    r = 3 + i
                    found = False
                    for rd, val in params:
                        if rd == r:
                            call_args.append(str(val))
                            found = True
                            break
                    if not found:
                        call_args.append(f"a{i}")
                call_str = ", ".join(call_args)
                return "param_fwd_44B_3li", (
                    f"extern int target_{addr:08X}({arg_decls});\n"
                    f"\n"
                    f"int param_fwd_{addr:08X}({arg_decls}) {{\n"
                    f"    return target_{addr:08X}({call_str});\n"
                    f"}}\n"
                )

    # --- Pattern: 44B_f8 with addi r3 + li + li + bl (param forwarding with this offset) ---
    body = check_frame8(words)
    if body is not None and len(body) == 4:
        if (is_addi(body[0]) and (body[0] >> 21) & 0x1F == 3 and (body[0] >> 16) & 0x1F == 3 and
            is_li(body[1]) and is_li(body[2]) and is_bl(body[3])):
            off = body[0] & 0xFFFF
            if off >= 0x8000: off -= 0x10000
            rd1 = get_li_rd(body[1])
            val1 = get_li_val(body[1])
            rd2 = get_li_rd(body[2])
            val2 = get_li_val(body[2])
            if 4 <= rd1 <= 10 and 4 <= rd2 <= 10:
                max_reg = max(rd1, rd2)
                n_args = max_reg - 3 + 1
                arg_decls = ", ".join(f"int a{i}" for i in range(n_args))
                call_args = []
                for i in range(n_args):
                    r = 3 + i
                    if r == 3:
                        call_args.append(f"a0")  # this+offset handled separately
                    elif r == rd1:
                        call_args.append(str(val1))
                    elif r == rd2:
                        call_args.append(str(val2))
                    else:
                        call_args.append(f"a{i}")
                call_str = ", ".join(call_args)
                return "param_fwd_44B_addi", (
                    f"typedef unsigned char u8;\n"
                    f"extern int target_{addr:08X}({arg_decls});\n"
                    f"\n"
                    f"int param_fwd_{addr:08X}(u8 *self, {', '.join(f'int a{i}' for i in range(1, n_args))}) {{\n"
                    f"    return target_{addr:08X}((int)(self + {off}), {', '.join(call_args[1:])});\n"
                    f"}}\n"
                ) if n_args > 1 else ("unknown", None)

    # --- Pattern: 44B_f8 with lis + li + addi + bl (load addr + set param + call) ---
    # Scheduling ON interleaves li between lis and addi:
    #   lis r3, HI; li rN, VAL; addi r3, r3, LO; bl target
    # r3 replaced by loaded address, rN set to VAL, r4..rN-1 pass through
    body = check_frame8(words)
    if body is not None and len(body) == 4:
        if (is_lis(body[0]) and is_li(body[1]) and is_addi(body[2]) and is_bl(body[3])):
            lis_rd = (body[0] >> 21) & 0x1F
            addi_rd = (body[2] >> 21) & 0x1F
            addi_ra = (body[2] >> 16) & 0x1F
            li_rd = get_li_rd(body[1])
            li_val = get_li_val(body[1])
            if lis_rd == 3 and addi_rd == 3 and addi_ra == 3 and 4 <= li_rd <= 10:
                # Wrapper: original func receives (self, a1, ..., aN-1)
                # Target gets: (global_addr, a1, ..., li_val at rN position)
                # The wrapper must declare params for r3(self) + r4..rN-1 (pass-through)
                n_pass = li_rd - 4  # pass-through params between r4 and li_rd-1
                wrapper_params = ["void *self"] + [f"int a{i}" for i in range(n_pass)]
                target_args = [f"(int)g_obj_{addr:08X}"]
                for i in range(n_pass):
                    target_args.append(f"a{i}")
                target_args.append(str(li_val))
                ext_params = ", ".join(["int"] * (li_rd - 3 + 1))
                return "load_addr_param_44B", (
                    f"// FLAGS: -fno-elide-constructors\n"
                    f"extern int g_obj_{addr:08X}[];\n"
                    f"extern int func_{addr:08X}({ext_params});\n"
                    f"\n"
                    f"int fwd_{addr:08X}({', '.join(wrapper_params)}) {{\n"
                    f"    return func_{addr:08X}({', '.join(target_args)});\n"
                    f"}}\n"
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

    stats = {"matched": 0, "failed": 0, "retry_matched": 0, "unknown": 0}

    # 4-state flag matrix: try all scheduling flag combinations
    FLAG_STATES = [
        "",                                                   # state 1: default (verify_match.sh adds -fno-schedule-insns2)
        "// FLAGS: -fno-elide-constructors\n",                # state 2: scheduling enabled (no -fno-schedule-insns2)
        "// FLAGS: -fno-schedule-insns\n",                    # state 3: -fno-schedule-insns (insns1 disabled)
        "// FLAGS: -fno-schedule-insns -fno-schedule-insns2\n", # state 4: both disabled
    ]

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

        header = f"/* {name} at 0x{addr:08X} ({size}B) — auto-matched [{pattern}] */\n\n"

        def try_verify(code, fpath):
            with open(fpath, "w") as f:
                f.write(header + code)
            result = subprocess.run(
                f"{VERIFY_CMD} {fpath} 0x{addr:08X} {size}",
                shell=True, capture_output=True, text=True, cwd="."
            )
            output = result.stdout + result.stderr
            return "MATCH" in output and "MISMATCH" not in output

        # Strip any existing FLAGS from cpp for clean retry
        base_cpp = cpp
        for fs in FLAG_STATES:
            base_cpp = base_cpp.replace(fs, "")

        found = False
        for flag in FLAG_STATES:
            test_cpp = flag + base_cpp
            if try_verify(test_cpp, filepath):
                stats["matched"] += 1
                if flag:
                    stats["retry_matched"] += 1
                if stats["matched"] % 20 == 0:
                    print(f"  ... {stats['matched']} matches so far")
                found = True
                break

        if not found:
            stats["failed"] += 1
            if os.path.exists(filepath):
                os.remove(filepath)

    print(f"\n=== RESULTS ===")
    print(f"Patterns found:")
    for k, v in sorted(stats.items()):
        if v > 0 and k not in ("matched", "failed", "retry_matched"):
            print(f"  {k}: {v}")
    print(f"\nAuto-matched: {stats['matched']} (including {stats['retry_matched']} via flag retry)")
    print(f"Failed verification: {stats['failed']}")
    print(f"Unknown/complex: {stats['unknown']}")


if __name__ == "__main__":
    main()
