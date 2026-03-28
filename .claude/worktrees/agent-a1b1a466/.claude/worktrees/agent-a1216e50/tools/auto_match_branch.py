#!/usr/bin/env python3
"""
Sims 2 GameCube -- Auto-match branching leaf functions (21-64 bytes).

Handles functions with conditional branches (beq, bne, beqlr, bnelr, etc.)
but NO function calls (no bl). These are leaf functions with if/else logic,
early returns, guard clauses, and small loops.

Key patterns matched:
  1. Guard clause + body: lwz; cmpwi; beqlr/bnelr; <body>; blr
  2. Bool check: lwz; li r3,1; cmpwi; bnelr; li r3,0; blr  (return field != 0)
  3. Bit flag setter: lwz; cmpwi r4; rlwinm; stw; beqlr; ori; stw; blr
  4. Type check: lwz; li; clrlwi; cmpwi; bne; rlwinm; mr; blr
  5. Conditional store: cmpwi; beq; lwz; ori; stw; blr; lwz; rlwinm; stw; blr
  6. Linked list length: lwz; li; cmpwi; beq; lwz; addi; cmpwi; bne; mr; blr
  7. Null check + load: lwz; li r3,0; cmpwi; beqlr; lwz r3,off; blr
  8. Bit flag test: lwz; li; andi.; beqlr/bnelr; li; blr
  9. Loop copy: addi; cmpwi; beqlr; lwz; cmpwi; addi; stw; bne; blr
 10. CopyReverse loops with slwi setup
 11. Two-condition check: lwz; li; cmpwi; bne; lwz; cmpwi; beq; li; mr; blr
 12. rlwimi bitfield setters with conditional values
 13. Table lookup loops with mtctr/bdnz

Usage:
    python tools/auto_match_branch.py                    # report only
    python tools/auto_match_branch.py --generate         # generate C++ to src/matched/
    python tools/auto_match_branch.py --dry-run          # show what would generate
"""

import argparse
import json
import os
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve().parent
ROOT_DIR = SCRIPT_DIR.parent

# Import helpers from auto_match.py
sys.path.insert(0, str(SCRIPT_DIR))
from auto_match import (
    load_functions, disassemble_batch, parse_function_name,
    guess_return_type,
    parse_load_store_operands, parse_li_operands, parse_mr_operands,
    parse_addi_operands, parse_lis_operands, parse_ori_operands,
    parse_rlwinm_operands, parse_rlwimi_operands, parse_clrlwi_operands,
    parse_clrrwi_operands, parse_srwi_operands, parse_slwi_operands,
    parse_two_reg_operands, parse_three_reg_operands, parse_mulli_operands,
    parse_indexed_load_store, reconstruct_address,
    INSN_RE, ORIGINAL_ELF, OBJDUMP, CODE_SECTIONS, SYMBOLS_JSON,
)
from auto_match_medium import (
    format_cpp_function_v2, split_params,
    is_load_insn, is_store_insn, is_branch_insn, is_call_insn,
    has_calls, has_branches, has_unknowns,
    get_store_type, get_load_type, format_offset,
)


# ============================================================================
# Branch instruction helpers
# ============================================================================

COND_BRANCH_LR = {'beqlr', 'bnelr', 'bltlr', 'bgtlr', 'blelr', 'bgelr',
                   'beqlr+', 'bnelr+', 'beqlr-', 'bnelr-',
                   'bltlr+', 'bgtlr+', 'blelr+', 'bgelr+',
                   'bltlr-', 'bgtlr-', 'blelr-', 'bgelr-'}

COND_BRANCH_FWD = {'beq', 'bne', 'blt', 'bgt', 'ble', 'bge',
                    'beq+', 'bne+', 'beq-', 'bne-',
                    'blt+', 'bgt+', 'ble+', 'bge+',
                    'blt-', 'bgt-', 'ble-', 'bge-',
                    'b', 'bdnz', 'bdz'}


def strip_branch_hint(mnem):
    """Strip branch prediction hints (+/-) from mnemonic."""
    return mnem.rstrip('+-')


def is_cond_branch_lr(mnem):
    """Is this a conditional branch-to-link-register?"""
    return strip_branch_hint(mnem) in {'beqlr', 'bnelr', 'bltlr', 'bgtlr', 'blelr', 'bgelr'}


def is_cond_branch(mnem):
    """Is this a conditional branch (not to LR)?"""
    return strip_branch_hint(mnem) in {'beq', 'bne', 'blt', 'bgt', 'ble', 'bge'}


def invert_condition(mnem):
    """Invert a branch condition. beq->bne, bne->beq, etc."""
    m = strip_branch_hint(mnem)
    inv_map = {
        'beq': 'bne', 'bne': 'beq',
        'blt': 'bge', 'bge': 'blt',
        'bgt': 'ble', 'ble': 'bgt',
        'beqlr': 'bnelr', 'bnelr': 'beqlr',
        'bltlr': 'bgelr', 'bgelr': 'bltlr',
        'bgtlr': 'blelr', 'blelr': 'bgtlr',
    }
    return inv_map.get(m, m)


def cond_to_c_op(mnem, negated=False):
    """Convert a branch condition to a C comparison operator."""
    m = strip_branch_hint(mnem)
    # beq/beqlr means "branch if equal" -> C condition "=="
    op_map = {
        'beq': '==', 'bne': '!=',
        'blt': '<', 'bge': '>=',
        'bgt': '>', 'ble': '<=',
        'beqlr': '==', 'bnelr': '!=',
        'bltlr': '<', 'bgelr': '>=',
        'bgtlr': '>', 'blelr': '<=',
    }
    op = op_map.get(m, '==')
    if negated:
        neg_map = {'==': '!=', '!=': '==', '<': '>=', '>=': '<', '>': '<=', '<=': '>'}
        op = neg_map.get(op, op)
    return op


def parse_cmpwi_operands(operands):
    """Parse cmpwi operands like 'r3,0' or 'cr0,r3,0' -> (reg, imm)."""
    # cmpwi rN, imm
    m = re.match(r'(r\d+),(-?\d+)', operands)
    if m:
        return m.group(1), int(m.group(2))
    # cmpwi crN, rN, imm
    m = re.match(r'cr\d+,(r\d+),(-?\d+)', operands)
    if m:
        return m.group(1), int(m.group(2))
    return None, None


def parse_cmplwi_operands(operands):
    """Parse cmplwi operands like 'r3,25' -> (reg, imm)."""
    m = re.match(r'(r\d+),(\d+)', operands)
    if m:
        return m.group(1), int(m.group(2))
    m = re.match(r'cr\d+,(r\d+),(\d+)', operands)
    if m:
        return m.group(1), int(m.group(2))
    return None, None


def parse_cmpw_operands(operands):
    """Parse cmpw operands like 'r3,r4' -> (reg1, reg2)."""
    m = re.match(r'(r\d+),(r\d+)', operands)
    if m:
        return m.group(1), m.group(2)
    m = re.match(r'cr\d+,(r\d+),(r\d+)', operands)
    if m:
        return m.group(1), m.group(2)
    return None, None


def parse_andi_operands(operands):
    """Parse andi. operands like 'r9,r0,48' -> (dst, src, imm)."""
    m = re.match(r'(r\d+),(r\d+),(\d+)', operands)
    if m:
        return m.group(1), m.group(2), int(m.group(3))
    return None, None, None


# ============================================================================
# Pattern matchers for branching leaf functions
# ============================================================================

def match_bool_field_check(insns, func_info):
    """Match: lwz rN,off(r3); li r3,1/0; cmpwi rN,0; bnelr/beqlr; li r3,0/1; blr

    Returns bool based on whether a field is zero or non-zero.
    Covers patterns:
      lwz_li_cmpwi_bnelr_li_blr  (22 functions)
      lwz_li_cmpwi_bgtlr_li_blr  (3 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 6 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]  # load
    m1, op1 = insns[1]  # li r3, val1
    m2, op2 = insns[2]  # cmpwi
    m3, op3 = insns[3]  # conditional branch LR
    m4, op4 = insns[4]  # li r3, val2

    if m1 != 'li' or m4 != 'li':
        return None, None
    if m2 != 'cmpwi':
        return None, None
    if not is_cond_branch_lr(m3):
        return None, None

    li1_reg, li1_val = parse_li_operands(op1)
    li2_reg, li2_val = parse_li_operands(op4)
    if li1_reg != 'r3' or li2_reg != 'r3':
        return None, None

    cmp_reg, cmp_val = parse_cmpwi_operands(op2)
    if cmp_reg is None:
        return None, None

    # Determine the load
    if is_load_insn(m0):
        ld_reg, ld_off, ld_base = parse_load_store_operands(op0)
        if ld_reg is None or ld_reg != cmp_reg:
            return None, None

        ctype = get_load_type(m0)
        cond = strip_branch_hint(m3)

        # Logic: if (cmp_reg <cond> cmp_val) return li1_val; return li2_val;
        # For the common "li r3,1; cmpwi r0,0; bnelr; li r3,0; blr"
        # -> if (field != 0) return 1; return 0; -> return field != 0;

        # Build the load expression
        if ld_base == 'r3':
            load_expr = f'*({ctype}*)((char*)this + {format_offset(ld_off)})'
        elif ld_base == 'r13':
            # SDA global - use inline asm
            load_expr = None  # handled below
        else:
            return None, None

        # SDA path - need inline asm for r13 access
        if ld_base == 'r13':
            c_op = cond_to_c_op(cond)
            # if (sda_val <c_op> cmp_val) return li1_val; return li2_val;
            return 'int', (
                f'{{ register int __sda __asm__("{ld_reg}"); '
                f'__asm__ __volatile__("{m0} %0, {ld_off}(%%r13)" : "=r"(__sda)); '
                f'if (__sda {c_op} {cmp_val}) return {li1_val}; return {li2_val}; }}'
            )

        # General case: if (load_expr <cond> cmp_val) return li1_val; return li2_val;
        c_op = cond_to_c_op(cond)

        # Simplify common bool patterns
        if li1_val == 1 and li2_val == 0 and cmp_val == 0:
            if c_op == '!=':
                return 'bool', f'{{ return {load_expr} != 0; }}'
            elif c_op == '==':
                return 'bool', f'{{ return {load_expr} == 0; }}'
            elif c_op == '>':
                return 'bool', f'{{ return {load_expr} > 0; }}'
            else:
                return 'bool', f'{{ return {load_expr} {c_op} 0; }}'

        elif li1_val == 0 and li2_val == 1 and cmp_val == 0:
            inv = cond_to_c_op(cond, negated=True)
            if inv == '!=':
                return 'bool', f'{{ return {load_expr} != 0; }}'
            elif inv == '==':
                return 'bool', f'{{ return {load_expr} == 0; }}'
            else:
                return 'bool', f'{{ return {load_expr} {inv} 0; }}'

        else:
            # General: non-zero comparison, arbitrary return values
            return 'int', f'{{ if ({load_expr} {c_op} {cmp_val}) return {li1_val}; return {li2_val}; }}'

    return None, None


def match_andi_bool_check(insns, func_info):
    """Match: lwz rN,off(r3); li r3,0/1; andi. rK,rN,mask; beqlr/bnelr; li r3,1/0; blr

    Returns bool based on a bitmask test.
    Covers patterns:
      lwz_li_andi._bnelr_li_blr  (6 functions)
      lwz_li_andi._beqlr_li_blr  (4 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 6 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]  # lwz
    m1, op1 = insns[1]  # li r3, val
    m2, op2 = insns[2]  # andi.
    m3, op3 = insns[3]  # beqlr/bnelr
    m4, op4 = insns[4]  # li r3, val2

    if not is_load_insn(m0):
        return None, None
    if m1 != 'li' or m4 != 'li':
        return None, None
    if m2 != 'andi.':
        return None, None
    if not is_cond_branch_lr(m3):
        return None, None

    li1_reg, li1_val = parse_li_operands(op1)
    li2_reg, li2_val = parse_li_operands(op4)
    if li1_reg != 'r3' or li2_reg != 'r3':
        return None, None

    ld_reg, ld_off, ld_base = parse_load_store_operands(op0)
    if ld_reg is None:
        return None, None
    ctype = get_load_type(m0)

    andi_dst, andi_src, andi_mask = parse_andi_operands(op2)
    if andi_dst is None:
        return None, None

    cond = strip_branch_hint(m3)

    if ld_base == 'r3':
        load_expr = f'*({ctype}*)((char*)this + {format_offset(ld_off)})'

        # andi. sets CR0 based on result: zero flag set if (src & mask) == 0
        # beqlr: branch if zero (mask test fails) -> return li1_val
        # bnelr: branch if non-zero (mask test succeeds) -> return li1_val
        if li1_val == 1 and li2_val == 0 and cond == 'bnelr':
            # bnelr -> return 1 if mask hit; fallthrough -> return 0
            return 'bool', f'{{ return ({load_expr} & 0x{andi_mask:X}) != 0; }}'
        elif li1_val == 0 and li2_val == 1 and cond == 'beqlr':
            # beqlr -> return 0 if no mask hit; fallthrough -> return 1
            return 'bool', f'{{ return ({load_expr} & 0x{andi_mask:X}) != 0; }}'
        elif li1_val == 0 and li2_val == 1 and cond == 'bnelr':
            # bnelr -> return 0 if mask hit; fallthrough -> return 1
            return 'bool', f'{{ return ({load_expr} & 0x{andi_mask:X}) == 0; }}'
        elif li1_val == 1 and li2_val == 0 and cond == 'beqlr':
            # beqlr -> return 1 if no mask hit; fallthrough -> return 0
            return 'bool', f'{{ return ({load_expr} & 0x{andi_mask:X}) == 0; }}'

    return None, None


def match_guard_store(insns, func_info):
    """Match: lwz rN,off(r3); cmpwi rN,0; beqlr/bnelr; <stores>; blr

    Guard clause that returns early, then does stores.
    Covers patterns:
      lwz_cmpwi_beqlr_li_stw_blr  (23 functions)
      lwz_cmpwi_bnelr_li_stw_blr  (variant)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n < 4 or mnemonics[-1] != 'blr':
        return None, None

    # Look for: load; cmpwi; beqlr/bnelr; <body>; blr
    m0, op0 = insns[0]
    m1, op1 = insns[1]
    m2, op2 = insns[2]

    if not is_load_insn(m0):
        return None, None
    if m1 != 'cmpwi':
        return None, None
    if not is_cond_branch_lr(m2):
        return None, None

    ld_reg, ld_off, ld_base = parse_load_store_operands(op0)
    cmp_reg, cmp_val = parse_cmpwi_operands(op1)
    if ld_reg is None or cmp_reg is None:
        return None, None
    if ld_reg != cmp_reg:
        return None, None

    ctype = get_load_type(m0)
    cond = strip_branch_hint(m2)

    # Determine guard condition (the condition that causes early return)
    # beqlr: return if field == cmp_val
    # bnelr: return if field != cmp_val
    if cond == 'beqlr':
        guard_c_cond = '=='
        body_c_cond = '!='
    elif cond == 'bnelr':
        guard_c_cond = '!='
        body_c_cond = '=='
    elif cond == 'bgelr':
        guard_c_cond = '>='
        body_c_cond = '<'
    elif cond == 'blelr':
        guard_c_cond = '<='
        body_c_cond = '>'
    elif cond == 'bgtlr':
        guard_c_cond = '>'
        body_c_cond = '<='
    elif cond == 'bltlr':
        guard_c_cond = '<'
        body_c_cond = '>='
    else:
        return None, None

    # Build the guard condition expression
    if ld_base == 'r3':
        guard_expr = f'*({ctype}*)((char*)this + {format_offset(ld_off)})'
        is_sda = False
    elif ld_base == 'r13':
        guard_expr = f'__sda_val'
        is_sda = True
    else:
        return None, None

    # Now match the body (instructions after the guard, before blr)
    body_insns = insns[3:-1]  # skip guard + blr
    if not body_insns:
        return None, None

    # Simple body: li r0,val; stw r0,off(rM) -- store a constant
    body_stmts = []
    regs = {}
    # The guard loaded into ld_reg from ld_base -- body may use it
    if ld_base == 'r3':
        regs[ld_reg] = ('field_load', ctype, ld_off, 'this')
    elif ld_base == 'r13':
        regs[ld_reg] = ('sda_load', ctype, ld_off)

    for bi, (bm, bop) in enumerate(body_insns):
        if bm == 'li':
            reg, val = parse_li_operands(bop)
            if reg is None:
                return None, None
            regs[reg] = ('const', val)

        elif bm == 'addi':
            dst, src, imm = parse_addi_operands(bop)
            if dst is None:
                return None, None
            if src in regs and regs[src][0] == 'field_load' and regs[src][3] == 'this':
                regs[dst] = ('const', 'field_plus_imm')
                # this->field + imm
                body_stmts.append(None)  # placeholder
                return None, None  # too complex for now
            elif src in regs and regs[src][0] == 'const':
                regs[dst] = ('const', regs[src][1] + imm if isinstance(regs[src][1], int) else None)
            else:
                regs[dst] = ('addi_result', src, imm)

        elif is_load_insn(bm) and not bm.endswith('x') and not bm.endswith('u'):
            reg, off, base = parse_load_store_operands(bop)
            if reg is None:
                return None, None
            ct = get_load_type(bm)
            if base == 'r3':
                regs[reg] = ('field_load', ct, off, 'this')
            elif base == 'r13':
                regs[reg] = ('sda_load', ct, off)
            elif base in regs and regs[base][0] == 'field_load':
                regs[reg] = ('deref_load', ct, off, base)
            else:
                regs[reg] = ('raw_load', bm, off, base)

        elif is_store_insn(bm) and not bm.endswith('x') and not bm.endswith('u'):
            reg, off, base = parse_load_store_operands(bop)
            if reg is None:
                return None, None
            ct = get_store_type(bm)

            # Determine base
            if base == 'r3':
                base_str = 'this'
            elif base == 'r13':
                # SDA store - use inline asm
                if reg in regs and regs[reg][0] == 'const' and isinstance(regs[reg][1], int):
                    ct = get_store_type(bm)
                    body_stmts.append(
                        f'register int __{reg} __asm__("{reg}") = {regs[reg][1]}; '
                        f'__asm__ __volatile__("" : "+r"(__{reg})); '
                        f'__asm__ __volatile__("{bm} %0, {off}(%%r13)" : : "r"(__{reg}));'
                    )
                else:
                    body_stmts.append(f'__asm__ __volatile__("{bm} %0, {off}(%%r13)" : : "r"({reg}));')
                continue
            elif base in regs:
                binfo = regs[base]
                if binfo[0] == 'field_load' and binfo[3] == 'this':
                    # Store through dereferenced pointer
                    base_str = f'deref_{binfo[2]:X}'
                elif binfo[0] == 'sda_load':
                    # Store through SDA-loaded pointer
                    ct_s = get_store_type(bm)
                    if reg in regs and regs[reg][0] == 'const' and isinstance(regs[reg][1], int):
                        body_stmts.append(
                            f'register int __{reg} __asm__("{reg}") = {regs[reg][1]}; '
                            f'__asm__ __volatile__("" : "+r"(__{reg})); '
                            f'*({ct_s}*)((char*)__sda_val + {format_offset(off)}) = __{reg};'
                        )
                    else:
                        val_s = reg
                        if reg.startswith('r'):
                            pmap = {'r4': 'val', 'r5': 'val3', 'r6': 'val4'}
                            val_s = pmap.get(reg, reg)
                        body_stmts.append(
                            f'*({ct_s}*)((char*)__sda_val + {format_offset(off)}) = {val_s};'
                        )
                    continue
                else:
                    return None, None
            else:
                return None, None

            # Determine value
            if reg in regs:
                rv = regs[reg]
                if rv[0] == 'const' and isinstance(rv[1], int):
                    val_str = str(rv[1])
                elif rv[0] == 'field_load' and rv[3] == 'this':
                    val_str = f'*({rv[1]}*)((char*)this + {format_offset(rv[2])})'
                else:
                    return None, None
            elif reg.startswith('r'):
                pmap = {'r4': 'val', 'r5': 'val3', 'r6': 'val4'}
                val_str = pmap.get(reg, reg)
            else:
                return None, None

            if base_str == 'this':
                body_stmts.append(f'*({ct}*)((char*)this + {format_offset(off)}) = {val_str};')
            elif base_str.startswith('deref_'):
                off_hex = int(base_str[6:], 16)
                body_stmts.append(
                    f'*({ct}*)((char*)(*(void**)((char*)this + {format_offset(off_hex)})) + {format_offset(off)}) = {val_str};')
            else:
                return None, None
        else:
            return None, None

    if not body_stmts:
        return None, None

    body_code = ' '.join(body_stmts)

    if cmp_val == 0:
        if guard_c_cond == '==':
            guard_str = f'if ({guard_expr} != {cmp_val})'
        elif guard_c_cond == '!=':
            guard_str = f'if ({guard_expr} == {cmp_val})'
        else:
            guard_str = f'if ({guard_expr} {body_c_cond} {cmp_val})'
    else:
        guard_str = f'if ({guard_expr} {body_c_cond} {cmp_val})'

    if is_sda:
        # For SDA-based guards, need inline asm to load from r13
        # But the body stores may also go through the SDA-loaded pointer.
        # This is complex; only handle simple cases where body stores go through
        # the loaded pointer (ld_reg).
        return 'void', (
            f'{{ register int __sda_val __asm__("{ld_reg}"); '
            f'__asm__ __volatile__("{m0} %0, {ld_off}(%%r13)" : "=r"(__sda_val)); '
            f'{guard_str} {{ {body_code} }} }}'
        )

    return 'void', f'{{ {guard_str} {{ {body_code} }} }}'


def match_bitflag_setter(insns, func_info):
    """Match: lwz r0,off(r3); cmpwi r4,0; rlwinm r0,...; stw r0,off(r3); beqlr; ori r0,...; stw r0,off(r3); blr

    Set or clear a bit flag based on bool parameter.
    Covers patterns:
      lwz_cmpwi_rlwinm_stw_beqlr_ori_stw_blr  (21 functions)
      lhz_cmpwi_rlwinm_sth_beqlr_ori_sth_blr  (10 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 8 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]  # lwz/lhz r0,off(r3)
    m1, op1 = insns[1]  # cmpwi r4,0
    m2, op2 = insns[2]  # rlwinm r0,r0,0,MB,ME (clear bit)
    m3, op3 = insns[3]  # stw/sth r0,off(r3)
    m4, op4 = insns[4]  # beqlr
    m5, op5 = insns[5]  # ori r0,r0,mask
    m6, op6 = insns[6]  # stw/sth r0,off(r3)

    if not is_load_insn(m0):
        return None, None
    if m1 != 'cmpwi':
        return None, None
    if m2 != 'rlwinm':
        return None, None
    if not is_store_insn(m3):
        return None, None
    if strip_branch_hint(m4) != 'beqlr':
        return None, None
    if m5 != 'ori':
        return None, None
    if not is_store_insn(m6):
        return None, None

    ld_reg, ld_off, ld_base = parse_load_store_operands(op0)
    cmp_reg, cmp_val = parse_cmpwi_operands(op1)
    rl_dst, rl_src, rl_sh, rl_mb, rl_me = parse_rlwinm_operands(op2)
    st1_reg, st1_off, st1_base = parse_load_store_operands(op3)
    ori_dst, ori_src, ori_val = parse_ori_operands(op5)
    st2_reg, st2_off, st2_base = parse_load_store_operands(op6)

    if (ld_reg is None or cmp_reg is None or rl_dst is None or
            st1_reg is None or ori_dst is None or st2_reg is None):
        return None, None

    if ld_base != 'r3' or st1_base != 'r3' or st2_base != 'r3':
        return None, None
    if cmp_reg != 'r4' or cmp_val != 0:
        return None, None

    ctype = get_load_type(m0)
    st_type = get_store_type(m3)

    # The rlwinm clears the bit, ori sets it
    # Pattern: if (param == 0) store cleared; else store set
    # Simplify to: clear bit; if (param) set bit;
    # rlwinm r0,r0,0,MB,ME clears bits outside [MB,ME]
    # ori r0,r0,mask sets bits

    # Compute the clear mask from rlwinm r0,r0,0,MB,ME
    # rlwinm with shift=0 is an AND mask
    # The mask has 1s in positions [MB..ME] (PPC bit numbering, 0=MSB)
    if rl_sh == 0:
        # Build the mask
        if rl_mb <= rl_me:
            # Simple range: 1s from mb to me
            mask = 0
            for bit in range(rl_mb, rl_me + 1):
                mask |= (1 << (31 - bit))
        else:
            # Wrap-around: 1s from 0..me and mb..31
            mask = 0
            for bit in range(0, rl_me + 1):
                mask |= (1 << (31 - bit))
            for bit in range(rl_mb, 32):
                mask |= (1 << (31 - bit))

        # The ori mask is the bit(s) being set
        set_mask = ori_val

        # Use register __asm__("r0") to match SN Systems register allocation
        return 'void', (
            f'{{ register {st_type} __r0 __asm__("r0") = *({ctype}*)((char*)this + {format_offset(ld_off)}); '
            f'__asm__ __volatile__("" : "+r"(__r0)); '
            f'__r0 &= 0x{mask:X}; '
            f'*({st_type}*)((char*)this + {format_offset(st1_off)}) = __r0; '
            f'if (val) {{ __r0 |= 0x{set_mask:X}; '
            f'*({st_type}*)((char*)this + {format_offset(st2_off)}) = __r0; }} }}'
        )

    return None, None


def match_null_check_load(insns, func_info):
    """Match: lwz rN,off(r3); li/cmpwi r3,0; cmpwi rN,0; beqlr; lwz r3,off2(rN); blr
    OR: lwz rN,off(r3); cmpwi rN,0; li r3,0; beqlr; lwz r3,off2(rN); blr

    Null pointer check + field access: if (!ptr) return 0; return ptr->field;
    Covers patterns:
      lwz_li_cmpwi_beqlr_lwz_blr  (5 functions)
      lwz_cmpwi_li_beqlr_lwz_blr  (4 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 6 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]
    m4, op4 = insns[4]

    if m0 != 'lwz' or not is_load_insn(m4):
        return None, None

    ld0_reg, ld0_off, ld0_base = parse_load_store_operands(op0)
    if ld0_reg is None:
        return None, None

    # Two variants: li before or after cmpwi
    # Variant 1: lwz; li r3,0; cmpwi rN,0; beqlr; lwz r3,off(rN); blr
    if insns[1][0] == 'li' and insns[2][0] == 'cmpwi':
        li_reg, li_val = parse_li_operands(insns[1][1])
        cmp_reg, cmp_val = parse_cmpwi_operands(insns[2][1])
        br_mnem = insns[3][0]

        if li_reg != 'r3' or cmp_reg != ld0_reg or cmp_val != 0:
            return None, None
        if strip_branch_hint(br_mnem) != 'beqlr':
            return None, None

    # Variant 2: lwz; cmpwi rN,0; li r3,0; beqlr; lwz r3,off(rN); blr
    elif insns[1][0] == 'cmpwi' and insns[2][0] == 'li':
        cmp_reg, cmp_val = parse_cmpwi_operands(insns[1][1])
        li_reg, li_val = parse_li_operands(insns[2][1])
        br_mnem = insns[3][0]

        if li_reg != 'r3' or cmp_reg != ld0_reg or cmp_val != 0:
            return None, None
        if strip_branch_hint(br_mnem) != 'beqlr':
            return None, None
    else:
        return None, None

    # Final load
    ld1_reg, ld1_off, ld1_base = parse_load_store_operands(op4)
    if ld1_reg is None or ld1_reg != 'r3' or ld1_base != ld0_reg:
        return None, None

    ctype_ret = get_load_type(m4)

    if ld0_base == 'r3':
        ptr_expr = f'*(void**)((char*)this + {format_offset(ld0_off)})'
        return ctype_ret, f'{{ void* __p = {ptr_expr}; if (!__p) return {li_val}; return *({ctype_ret}*)((char*)__p + {format_offset(ld1_off)}); }}'
    elif ld0_base == 'r13':
        return None, None  # SDA, skip

    return None, None


def match_type_check_rlwinm(insns, func_info):
    """Match: lwz r3,0(r3); li r9,0; clrlwi r0,r3,N; cmpwi r0,val; bne .skip; rlwinm r9,r3,sh,mb,me; mr r3,r9; blr

    Type check + bit extraction. Common in AptValue methods.
    Covers patterns:
      lwz_li_clrlwi_cmpwi_bne_rlwinm_mr_blr  (19 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 8 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]  # lwz r3,0(r3)
    m1, op1 = insns[1]  # li r9,0
    m2, op2 = insns[2]  # clrlwi r0,r3,N
    m3, op3 = insns[3]  # cmpwi r0,val
    m4, op4 = insns[4]  # bne .skip
    m5, op5 = insns[5]  # rlwinm r9,r3,sh,mb,me
    m6, op6 = insns[6]  # mr r3,r9

    if m0 != 'lwz' or m1 != 'li' or m2 != 'clrlwi':
        return None, None
    if m3 != 'cmpwi':
        return None, None
    if strip_branch_hint(m4) != 'bne':
        return None, None
    if m5 != 'rlwinm' or m6 != 'mr':
        return None, None

    ld_reg, ld_off, ld_base = parse_load_store_operands(op0)
    li_reg, li_val = parse_li_operands(op1)
    clr_dst, clr_src, clr_n = parse_clrlwi_operands(op2)
    cmp_reg, cmp_val = parse_cmpwi_operands(op3)
    rl_dst, rl_src, rl_sh, rl_mb, rl_me = parse_rlwinm_operands(op5)
    mr_dst, mr_src = parse_mr_operands(op6)

    if (ld_reg is None or li_reg is None or clr_dst is None or
            cmp_reg is None or rl_dst is None or mr_dst is None):
        return None, None
    if mr_dst != 'r3' or mr_src != li_reg:
        return None, None

    # The pattern: load a value, check low bits for type tag, extract a bit field
    # load val; default = 0; if ((val & mask) == type_tag) default = extract(val); return default;
    mask_bits = 32 - clr_n
    type_tag = cmp_val

    # The rlwinm extracts a specific bit
    if rl_mb == 31 and rl_me == 31:
        bit_pos = (32 - rl_sh) % 32

        if ld_base == 'r3':
            load_expr = f'*({get_load_type(m0)}*)((char*)this + {format_offset(ld_off)})'
            return 'bool', (
                f'{{ int __v = {load_expr}; '
                f'if ((__v & 0x{(1 << mask_bits) - 1:X}) == {type_tag}) '
                f'return (__v >> {bit_pos}) & 1; '
                f'return {li_val}; }}'
            )

    return None, None


def match_cond_flag_setter(insns, func_info):
    """Match: cmpwi r4,0; beq/bne; lwz; ori; stw; blr; lwz; rlwinm; stw; blr

    Two-path flag setter: if (param) set_flag; else clear_flag;
    Covers patterns:
      cmpwi_beq_lwz_ori_stw_blr_lwz_rlwinm_stw_blr  (3 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 10:
        return None, None

    m0, op0 = insns[0]  # cmpwi r4,0
    m1, op1 = insns[1]  # beq .else
    m2, op2 = insns[2]  # lwz r0,off(r3)
    m3, op3 = insns[3]  # ori r0,r0,mask
    m4, op4 = insns[4]  # stw r0,off(r3)
    m5, op5 = insns[5]  # blr
    m6, op6 = insns[6]  # lwz r0,off(r3)
    m7, op7 = insns[7]  # rlwinm r0,r0,0,MB,ME
    m8, op8 = insns[8]  # stw r0,off(r3)
    m9, op9 = insns[9]  # blr

    if m0 != 'cmpwi':
        return None, None
    if not is_cond_branch(m1):
        return None, None
    if not is_load_insn(m2) or m3 != 'ori' or not is_store_insn(m4):
        return None, None
    if m5 != 'blr':
        return None, None
    if not is_load_insn(m6) or m7 != 'rlwinm' or not is_store_insn(m8):
        return None, None
    if m9 != 'blr':
        return None, None

    cmp_reg, cmp_val = parse_cmpwi_operands(op0)
    if cmp_reg != 'r4' or cmp_val != 0:
        return None, None

    cond = strip_branch_hint(m1)

    ld1_reg, ld1_off, ld1_base = parse_load_store_operands(op2)
    ori_dst, ori_src, ori_val = parse_ori_operands(op3)
    st1_reg, st1_off, st1_base = parse_load_store_operands(op4)

    ld2_reg, ld2_off, ld2_base = parse_load_store_operands(op6)
    rl_dst, rl_src, rl_sh, rl_mb, rl_me = parse_rlwinm_operands(op7)
    st2_reg, st2_off, st2_base = parse_load_store_operands(op8)

    if (ld1_reg is None or ori_dst is None or st1_reg is None or
            ld2_reg is None or rl_dst is None or st2_reg is None):
        return None, None

    if ld1_base != 'r3' or st1_base != 'r3' or ld2_base != 'r3' or st2_base != 'r3':
        return None, None

    ctype_ld = get_load_type(m2)
    ctype_st = get_store_type(m4)

    # Build clear mask from rlwinm
    if rl_sh == 0:
        if rl_mb <= rl_me:
            clear_mask = 0
            for bit in range(rl_mb, rl_me + 1):
                clear_mask |= (1 << (31 - bit))
        else:
            # Wrap-around mask
            clear_mask = 0
            for bit in range(0, rl_me + 1):
                clear_mask |= (1 << (31 - bit))
            for bit in range(rl_mb, 32):
                clear_mask |= (1 << (31 - bit))

        # beq -> if (param == 0) goto else_path (clear); true_path = ori (set)
        # bne -> if (param != 0) goto else_path (clear); true_path = ori (set)
        if cond == 'beq':
            # fallthrough = set, branch = clear
            return 'void', (
                f'{{ {ctype_st} __flags = *({ctype_ld}*)((char*)this + {format_offset(ld1_off)}); '
                f'if (val) {{ __flags |= 0x{ori_val:X}; }} '
                f'else {{ __flags &= 0x{clear_mask:X}; }} '
                f'*({ctype_st}*)((char*)this + {format_offset(st1_off)}) = __flags; }}'
            )
        elif cond == 'bne':
            # fallthrough = set, branch (!=0) = clear? No...
            # bne: branch if param != 0 -> to clear path
            return 'void', (
                f'{{ {ctype_st} __flags = *({ctype_ld}*)((char*)this + {format_offset(ld1_off)}); '
                f'if (!val) {{ __flags |= 0x{ori_val:X}; }} '
                f'else {{ __flags &= 0x{clear_mask:X}; }} '
                f'*({ctype_st}*)((char*)this + {format_offset(st1_off)}) = __flags; }}'
            )

    return None, None


def match_rlwimi_bitfield_setter(insns, func_info):
    """Match: cmpwi r4,0; li r9,1; bne; li r9,0; lwz r0,off(r3); rlwimi r0,r9,sh,mb,me; stw r0,off(r3); blr
    Also: cmpwi r4,0; li r9,0; beq; li r9,1; ...

    Bit field insertion based on bool parameter.
    Covers patterns:
      cmpwi_li_bne_li_lwz_rlwimi_stw_blr  (4 functions)
      cmpwi_li_beq_li_lwz_rlwimi_stw_blr  (4 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 8 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]  # cmpwi r4,0
    m1, op1 = insns[1]  # li r9, val1
    m2, op2 = insns[2]  # bne/beq
    m3, op3 = insns[3]  # li r9, val2
    m4, op4 = insns[4]  # lwz r0,off(r3)
    m5, op5 = insns[5]  # rlwimi r0,r9,sh,mb,me
    m6, op6 = insns[6]  # stw r0,off(r3)

    if m0 != 'cmpwi' or m1 != 'li' or m3 != 'li':
        return None, None
    if not is_cond_branch(m2):
        return None, None
    if not is_load_insn(m4) or m5 != 'rlwimi' or not is_store_insn(m6):
        return None, None

    cmp_reg, cmp_val = parse_cmpwi_operands(op0)
    li1_reg, li1_val = parse_li_operands(op1)
    li2_reg, li2_val = parse_li_operands(op3)
    ld_reg, ld_off, ld_base = parse_load_store_operands(op4)
    rl_dst, rl_src, rl_sh, rl_mb, rl_me = parse_rlwimi_operands(op5)
    st_reg, st_off, st_base = parse_load_store_operands(op6)

    if (cmp_reg is None or li1_reg is None or li2_reg is None or
            ld_reg is None or rl_dst is None or st_reg is None):
        return None, None

    if cmp_reg != 'r4' or cmp_val != 0:
        return None, None
    if ld_base != 'r3' or st_base != 'r3':
        return None, None

    ctype_ld = get_load_type(m4)
    ctype_st = get_store_type(m6)

    cond = strip_branch_hint(m2)
    # Determine the final value of li_reg based on condition
    # cmpwi r4,0; li r9,1; bne .skip; li r9,0; .skip:
    # -> if (r4 != 0) r9=1; else r9=0; -> r9 = (param != 0) ? 1 : 0
    # cmpwi r4,0; li r9,0; beq .skip; li r9,1; .skip:
    # -> if (r4 == 0) r9=0; else r9=1; -> r9 = param ? 1 : 0

    if cond == 'bne':
        # bne skips li2; so if param != 0, use li1; else use li2
        val_if_true = li1_val   # param != 0
        val_if_false = li2_val  # param == 0
    elif cond == 'beq':
        # beq skips li2; so if param == 0, use li1; else use li2
        val_if_true = li2_val   # param != 0 (fallthrough)
        val_if_false = li1_val  # param == 0 (branch taken)
    else:
        return None, None

    # Common case: val_if_true=1, val_if_false=0 -> insert (bool)param
    # rlwimi inserts bits from rS into rD at position [mb:me] shifted by sh
    bit_count = rl_me - rl_mb + 1 if rl_me >= rl_mb else 32 - rl_mb + rl_me + 1

    if val_if_true == 1 and val_if_false == 0:
        # Insert val as a boolean bit field
        return 'void', (
            f'{{ {ctype_st} __flags = *({ctype_ld}*)((char*)this + {format_offset(ld_off)}); '
            f'register int __bit __asm__("r9") = val ? 1 : 0; '
            f'__asm__ __volatile__("" : "+r"(__bit)); '
            f'__asm__ __volatile__("rlwimi %0, %1, {rl_sh}, {rl_mb}, {rl_me}" '
            f': "+r"(__flags) : "r"(__bit)); '
            f'*({ctype_st}*)((char*)this + {format_offset(st_off)}) = __flags; }}'
        )
    elif val_if_true == 0 and val_if_false == 1:
        return 'void', (
            f'{{ {ctype_st} __flags = *({ctype_ld}*)((char*)this + {format_offset(ld_off)}); '
            f'register int __bit __asm__("r9") = val ? 0 : 1; '
            f'__asm__ __volatile__("" : "+r"(__bit)); '
            f'__asm__ __volatile__("rlwimi %0, %1, {rl_sh}, {rl_mb}, {rl_me}" '
            f': "+r"(__flags) : "r"(__bit)); '
            f'*({ctype_st}*)((char*)this + {format_offset(st_off)}) = __flags; }}'
        )

    return None, None


def match_linked_list_length(insns, func_info):
    """Match: lwz r3,off(r3); li r9,0; cmpwi r3,0; beq .done; lwz r3,off2(r3); addi r9,r9,1; cmpwi r3,0; bne .loop; mr r3,r9; blr

    Linked list length counter.
    Covers patterns:
      lwz_li_cmpwi_beq_lwz_addi_cmpwi_bne_mr_blr  (7 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 10 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]  # lwz r3,off(r3)  -- get head
    m1, op1 = insns[1]  # li r9,0  -- count = 0
    m2, op2 = insns[2]  # cmpwi r3,0  -- null check
    m3, op3 = insns[3]  # beq .done
    m4, op4 = insns[4]  # lwz r3,off2(r3) -- next = node->next
    m5, op5 = insns[5]  # addi r9,r9,1 -- count++
    m6, op6 = insns[6]  # cmpwi r3,0 -- null check
    m7, op7 = insns[7]  # bne .loop
    m8, op8 = insns[8]  # mr r3,r9 -- return count

    if m0 != 'lwz' or m1 != 'li' or m2 != 'cmpwi':
        return None, None
    if strip_branch_hint(m3) != 'beq':
        return None, None
    if m4 != 'lwz' or m5 != 'addi' or m6 != 'cmpwi':
        return None, None
    if strip_branch_hint(m7) != 'bne':
        return None, None
    if m8 != 'mr':
        return None, None

    ld0_reg, ld0_off, ld0_base = parse_load_store_operands(op0)
    li_reg, li_val = parse_li_operands(op1)
    ld1_reg, ld1_off, ld1_base = parse_load_store_operands(op4)
    mr_dst, mr_src = parse_mr_operands(op8)

    if (ld0_reg is None or li_reg is None or ld1_reg is None or mr_dst is None):
        return None, None
    if mr_dst != 'r3' or mr_src != li_reg:
        return None, None
    if li_val != 0:
        return None, None

    if ld0_base == 'r3':
        return 'int', (
            f'{{ int __p = *(int*)((char*)this + {format_offset(ld0_off)}); '
            f'int __cnt = 0; '
            f'while (__p) {{ __p = *(int*)((char*)__p + {format_offset(ld1_off)}); __cnt++; }} '
            f'return __cnt; }}'
        )

    return None, None


def match_loop_destruct_construct(insns, func_info):
    """Match: addi r9,r4,-1; cmpwi r4,0; beqlr; cmpwi r9,0; addi r9,r9,-1; bne .loop; blr

    Trivial count-down loop (Destruct/Construct patterns).
    Covers patterns:
      addi_cmpwi_beqlr_cmpwi_addi_bne_blr  (27 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 7 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]  # addi r9,r4,-1
    m1, op1 = insns[1]  # cmpwi r4,0
    m2, op2 = insns[2]  # beqlr
    m3, op3 = insns[3]  # cmpwi r9,0
    m4, op4 = insns[4]  # addi r9,r9,-1
    m5, op5 = insns[5]  # bne .loop

    if m0 != 'addi' or m1 != 'cmpwi':
        return None, None
    if strip_branch_hint(m2) != 'beqlr':
        return None, None
    if m3 != 'cmpwi' or m4 != 'addi':
        return None, None
    if strip_branch_hint(m5) != 'bne':
        return None, None

    cmp_reg, cmp_val = parse_cmpwi_operands(op1)
    if cmp_reg != 'r4' or cmp_val != 0:
        return None, None

    # This is a trivial loop that does nothing (Destruct/Construct for POD types)
    return 'void', '{ }'


def match_loop_copy(insns, func_info):
    """Match: addi r9,r5,-1; cmpwi r5,0; beqlr; lwz r0,0(r4); cmpwi r9,0; addi r4,r4,4; addi r9,r9,-1; stw r0,0(r3); addi r3,r3,4; bne .loop; blr

    Element-by-element copy loop.
    Covers patterns:
      addi_cmpwi_beqlr_lwz_cmpwi_addi_addi_stw_addi_bne_blr  (6 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 11 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]   # addi r9,r5,-1
    m1, op1 = insns[1]   # cmpwi r5,0
    m2, op2 = insns[2]   # beqlr
    m3, op3 = insns[3]   # lwz r0,0(r4)
    m4, op4 = insns[4]   # cmpwi r9,0
    m5, op5 = insns[5]   # addi r4,r4,4
    m6, op6 = insns[6]   # addi r9,r9,-1
    m7, op7 = insns[7]   # stw r0,0(r3)
    m8, op8 = insns[8]   # addi r3,r3,4
    m9, op9 = insns[9]   # bne .loop

    if m0 != 'addi' or m1 != 'cmpwi':
        return None, None
    if strip_branch_hint(m2) != 'beqlr':
        return None, None
    if not is_load_insn(m3) or m4 != 'cmpwi' or m5 != 'addi':
        return None, None
    if m6 != 'addi' or not is_store_insn(m7) or m8 != 'addi':
        return None, None
    if strip_branch_hint(m9) != 'bne':
        return None, None

    # This is a simple memcpy-like loop
    # The element size is from the load/store and the addi increment
    ld_reg, ld_off, ld_base = parse_load_store_operands(op3)
    st_reg, st_off, st_base = parse_load_store_operands(op7)

    # Get element size from addi for dst (insns[8])
    dst_addi, _, elem_size = parse_addi_operands(op8)

    if ld_reg is None or st_reg is None or dst_addi is None:
        return None, None

    # Generate a simple copy loop using raw pointers
    ctype = get_load_type(m3)
    return 'void', (
        f'{{ for (int __i = 0; __i < val3; __i++) '
        f'(({ctype}*)this)[__i] = (({ctype}*)val)[__i]; }}'
    )


def match_copy_reverse_loop(insns, func_info):
    """Match: slwi r9,r5,2; cmpwi r5,0; addi r9,r9,-4; addi r5,r5,-1; add r3,r3,r9; add r4,r4,r9; beqlr; lwz r0,0(r4); cmpwi r5,0; addi r4,r4,-4; addi r5,r5,-1; stw r0,0(r3); addi r3,r3,-4; bne .loop; blr

    Reverse copy loop.
    Covers patterns:
      slwi_cmpwi_addi_addi_add_add_beqlr_lwz_cmpwi_addi_addi_stw_addi_bne_blr  (3 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 15 or mnemonics[-1] != 'blr':
        return None, None

    if mnemonics[0] != 'slwi' or mnemonics[1] != 'cmpwi':
        return None, None
    if strip_branch_hint(mnemonics[6]) != 'beqlr':
        return None, None
    if strip_branch_hint(mnemonics[13]) != 'bne':
        return None, None

    # This is a reverse copy loop
    ctype = get_load_type(mnemonics[7])
    return 'void', (
        f'{{ for (int __i = val3 - 1; __i >= 0; __i--) '
        f'(({ctype}*)this)[__i] = (({ctype}*)val)[__i]; }}'
    )


def match_guard_addi_bnelr(insns, func_info):
    """Match: lwz r3,off(r3); cmpwi r3,0; addi r3,r3,N; bnelr; li r3,0; blr

    Null check + pointer offset.
    Covers: lwz_cmpwi_addi_bnelr_li_blr  (3 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 6 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]  # lwz r3,off(r3)
    m1, op1 = insns[1]  # cmpwi r3,0
    m2, op2 = insns[2]  # addi r3,r3,N
    m3, op3 = insns[3]  # bnelr
    m4, op4 = insns[4]  # li r3,0

    if m0 != 'lwz' or m1 != 'cmpwi' or m2 != 'addi':
        return None, None
    if strip_branch_hint(m3) != 'bnelr':
        return None, None
    if m4 != 'li':
        return None, None

    ld_reg, ld_off, ld_base = parse_load_store_operands(op0)
    cmp_reg, cmp_val = parse_cmpwi_operands(op1)
    addi_dst, addi_src, addi_imm = parse_addi_operands(op2)
    li_reg, li_val = parse_li_operands(op4)

    if (ld_reg is None or cmp_reg is None or addi_dst is None or li_reg is None):
        return None, None
    if ld_reg != 'r3' or cmp_reg != 'r3' or addi_dst != 'r3' or li_reg != 'r3':
        return None, None

    if ld_base == 'r3':
        return 'void*', (
            f'{{ void* __p = *(void**)((char*)this + {format_offset(ld_off)}); '
            f'if (!__p) return {li_val}; '
            f'return (char*)__p + {format_offset(addi_imm)}; }}'
        )

    return None, None


def match_null_deref_chain(insns, func_info):
    """Match: lwz rN,off(r3); li r3,0; lwz rN,off2(rN); cmpwi rN,0; beqlr; lwz r3,off3(rN); blr

    Double-deref with null check in the middle.
    Covers: lwz_li_lwz_cmpwi_beqlr_lwz_blr  (3 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 7 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]  # lwz rN,off(r3)
    m1, op1 = insns[1]  # li r3,0
    m2, op2 = insns[2]  # lwz rN,off2(rN)
    m3, op3 = insns[3]  # cmpwi rN,0
    m4, op4 = insns[4]  # beqlr
    m5, op5 = insns[5]  # lwz r3,off3(rN)

    if m0 != 'lwz' or m1 != 'li' or m2 != 'lwz':
        return None, None
    if m3 != 'cmpwi':
        return None, None
    if strip_branch_hint(m4) != 'beqlr':
        return None, None
    if not is_load_insn(m5):
        return None, None

    ld0_reg, ld0_off, ld0_base = parse_load_store_operands(op0)
    li_reg, li_val = parse_li_operands(op1)
    ld1_reg, ld1_off, ld1_base = parse_load_store_operands(op2)
    cmp_reg, cmp_val = parse_cmpwi_operands(op3)
    ld2_reg, ld2_off, ld2_base = parse_load_store_operands(op5)

    if (ld0_reg is None or li_reg is None or ld1_reg is None or
            cmp_reg is None or ld2_reg is None):
        return None, None

    if li_reg != 'r3' or ld2_reg != 'r3':
        return None, None
    if ld1_base != ld0_reg or cmp_reg != ld0_reg:
        return None, None

    ctype = get_load_type(m5)

    if ld0_base == 'r3':
        return ctype, (
            f'{{ void* __p = *(void**)((char*)this + {format_offset(ld0_off)}); '
            f'__p = *(void**)((char*)__p + {format_offset(ld1_off)}); '
            f'if (!__p) return {li_val}; '
            f'return *({ctype}*)((char*)__p + {format_offset(ld2_off)}); }}'
        )

    return None, None


def match_lis_cmpwi_beqlr(insns, func_info):
    """Match: lis r3,-N; cmpwi r4,0; ori r3,r3,N; beqlr; li r3,0; blr

    Return a 32-bit constant if param == 0, else return 0.
    Covers: lis_cmpwi_ori_beqlr_li_blr  (3 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 6 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]  # lis r3,hi
    m1, op1 = insns[1]  # cmpwi r4,0
    m2, op2 = insns[2]  # ori r3,r3,lo
    m3, op3 = insns[3]  # beqlr
    m4, op4 = insns[4]  # li r3,0

    if m0 != 'lis' or m1 != 'cmpwi' or m2 != 'ori':
        return None, None
    if strip_branch_hint(m3) != 'beqlr':
        return None, None
    if m4 != 'li':
        return None, None

    lis_reg, lis_val = parse_lis_operands(op0)
    cmp_reg, cmp_val = parse_cmpwi_operands(op1)
    ori_dst, ori_src, ori_val = parse_ori_operands(op2)
    li_reg, li_val = parse_li_operands(op4)

    if lis_reg != 'r3' or ori_dst != 'r3' or li_reg != 'r3':
        return None, None
    if cmp_reg != 'r4':
        return None, None

    full_val = ((lis_val & 0xFFFF) << 16) | (ori_val & 0xFFFF)

    if cmp_val == 0:
        return 'unsigned int', (
            f'{{ if (val == 0) return 0x{full_val & 0xFFFFFFFF:08X}; return {li_val}; }}'
        )

    return None, None


def match_mr_null_check(insns, func_info):
    """Match: mr. r3,r3; beq .else; lwz r9,0(r3); lwz r3,off(r9); blr; lis r3,hi; ori r3,r3,lo; blr

    Null check returning different values.
    Covers: mr._beq_lwz_lwz_blr_lis_ori_blr  (3 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 8:
        return None, None

    m0, op0 = insns[0]  # mr. r3,r3 (or mr. rN,rM)
    m1, op1 = insns[1]  # beq
    m2, op2 = insns[2]  # lwz r9,0(r3)
    m3, op3 = insns[3]  # lwz r3,off(r9)
    m4, op4 = insns[4]  # blr
    m5, op5 = insns[5]  # lis r3,hi
    m6, op6 = insns[6]  # ori r3,r3,lo
    m7, op7 = insns[7]  # blr

    if m0 != 'mr.' or m4 != 'blr' or m7 != 'blr':
        return None, None
    if strip_branch_hint(m1) != 'beq':
        return None, None
    if m2 != 'lwz' or m3 != 'lwz':
        return None, None
    if m5 != 'lis' or m6 != 'ori':
        return None, None

    # Parse the null path
    lis_reg, lis_val = parse_lis_operands(op5)
    ori_dst, ori_src, ori_val = parse_ori_operands(op6)
    if lis_reg != 'r3' or ori_dst != 'r3':
        return None, None
    default_val = ((lis_val & 0xFFFF) << 16) | (ori_val & 0xFFFF)

    # Parse the non-null path
    ld0_reg, ld0_off, ld0_base = parse_load_store_operands(op2)
    ld1_reg, ld1_off, ld1_base = parse_load_store_operands(op3)
    if ld0_reg is None or ld1_reg is None:
        return None, None

    return 'unsigned int', (
        f'{{ if (!this) return 0x{default_val & 0xFFFFFFFF:08X}; '
        f'void* __p = *(void**)((char*)this + {format_offset(ld0_off)}); '
        f'return *(int*)((char*)__p + {format_offset(ld1_off)}); }}'
    )


def match_two_cond_check(insns, func_info):
    """Match: lwz r0,off1(r3); li r9,0; cmpwi r0,0; bne .done; lwz r0,off2(r3); cmpwi r0,0; beq .done; li r9,1; mr r3,r9; blr

    Two-condition check: return (field1 == 0 && field2 != 0).
    Covers: lwz_li_cmpwi_bne_lwz_cmpwi_beq_li_mr_blr  (3 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 10 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]  # lwz r0,off1(r3)
    m1, op1 = insns[1]  # li r9,0
    m2, op2 = insns[2]  # cmpwi r0,0
    m3, op3 = insns[3]  # bne .done
    m4, op4 = insns[4]  # lwz r0,off2(r3)
    m5, op5 = insns[5]  # cmpwi r0,0
    m6, op6 = insns[6]  # beq .done
    m7, op7 = insns[7]  # li r9,1
    m8, op8 = insns[8]  # mr r3,r9

    if m0 != 'lwz' or m1 != 'li' or m2 != 'cmpwi':
        return None, None
    if not is_cond_branch(m3):
        return None, None
    if m4 != 'lwz' or m5 != 'cmpwi':
        return None, None
    if not is_cond_branch(m6):
        return None, None
    if m7 != 'li' or m8 != 'mr':
        return None, None

    ld0_reg, ld0_off, ld0_base = parse_load_store_operands(op0)
    li0_reg, li0_val = parse_li_operands(op1)
    cmp0_reg, cmp0_val = parse_cmpwi_operands(op2)
    ld1_reg, ld1_off, ld1_base = parse_load_store_operands(op4)
    cmp1_reg, cmp1_val = parse_cmpwi_operands(op5)
    li1_reg, li1_val = parse_li_operands(op7)
    mr_dst, mr_src = parse_mr_operands(op8)

    if (ld0_reg is None or li0_reg is None or ld1_reg is None or
            li1_reg is None or mr_dst is None):
        return None, None

    if mr_dst != 'r3' or mr_src != li0_reg:
        return None, None

    cond1 = strip_branch_hint(m3)
    cond2 = strip_branch_hint(m6)

    if ld0_base == 'r3' and ld1_base == 'r3':
        ct0 = get_load_type(m0)
        ct1 = get_load_type(m4)
        f0 = f'*({ct0}*)((char*)this + {format_offset(ld0_off)})'
        f1 = f'*({ct1}*)((char*)this + {format_offset(ld1_off)})'

        # bne: if field1 != 0, skip to done (return 0)
        # beq: if field2 == 0, skip to done (return 0)
        # -> return field1 == 0 && field2 != 0
        op1_c = cond_to_c_op(cond1, negated=True)
        op2_c = cond_to_c_op(cond2, negated=True)

        return 'bool', f'{{ return ({f0} {op1_c} {cmp0_val}) && ({f1} {op2_c} {cmp1_val}); }}'

    return None, None


def match_guard_store_sda(insns, func_info):
    """Match SDA-based guard + store patterns.
    lwz r9,off(r13); cmpwi r9,0; beqlr; li r0,val; stw r0,off2(r9); blr

    Guard on SDA global, then store through it.
    Subset of lwz_cmpwi_beqlr_li_stw_blr (23 functions) with r13 base.
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 6 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]  # lwz r9,off(r13)
    m1, op1 = insns[1]  # cmpwi r9,0
    m2, op2 = insns[2]  # beqlr
    m3, op3 = insns[3]  # li r0,val
    m4, op4 = insns[4]  # stw r0,off2(r9)

    if m0 != 'lwz' or m1 != 'cmpwi':
        return None, None
    if not is_cond_branch_lr(m2):
        return None, None
    if m3 != 'li' or not is_store_insn(m4):
        return None, None

    ld_reg, ld_off, ld_base = parse_load_store_operands(op0)
    cmp_reg, cmp_val = parse_cmpwi_operands(op1)
    li_reg, li_val = parse_li_operands(op3)
    st_reg, st_off, st_base = parse_load_store_operands(op4)

    if ld_reg is None or cmp_reg is None or li_reg is None or st_reg is None:
        return None, None
    if cmp_reg != ld_reg or cmp_val != 0:
        return None, None
    if st_base != ld_reg or st_reg != li_reg:
        return None, None

    cond = strip_branch_hint(m2)
    if cond != 'beqlr':
        return None, None

    if ld_base == 'r13':
        ct = get_store_type(m4)
        # SDA global load + null check + store through pointer
        # We need inline asm for SDA access
        return 'void', (
            f'{{ register void* __p __asm__("r9"); '
            f'__asm__ __volatile__("lwz %0, {ld_off}(%%r13)" : "=r"(__p)); '
            f'if (!__p) return; '
            f'register int __r0 __asm__("{li_reg}") = {li_val}; '
            f'__asm__ __volatile__("" : "+r"(__r0)); '
            f'*({ct}*)((char*)__p + {format_offset(st_off)}) = __r0; }}'
        )

    return None, None


def match_table_lookup_loop(insns, func_info):
    """Match: li r0,N; lis r9,hi; mtctr r0; mr r11,r3; addi r9,r9,lo; li r3,0;
              lwz r0,0(r9); addi r9,r9,4; cmpw r0,r11; beqlr; addi r3,r3,1; bdnz .loop;
              li r3,-1; blr

    Table lookup loop with counted iterations.
    Covers: li_lis_mtctr_mr_addi_li_lwz_addi_cmpw_beqlr_addi_bdnz_li_blr  (3 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 14 or mnemonics[-1] != 'blr':
        return None, None

    if mnemonics[0] != 'li' or mnemonics[1] != 'lis' or mnemonics[2] != 'mtctr':
        return None, None
    if mnemonics[3] != 'mr' or mnemonics[4] != 'addi' or mnemonics[5] != 'li':
        return None, None
    if mnemonics[6] != 'lwz' or mnemonics[7] != 'addi':
        return None, None
    if mnemonics[8] not in ('cmpw', 'cmplw'):
        return None, None
    if strip_branch_hint(mnemonics[9]) != 'beqlr':
        return None, None
    if mnemonics[10] != 'addi' or mnemonics[11] != 'bdnz' or mnemonics[12] != 'li':
        return None, None

    # Extract the loop count and table address
    li_reg, li_val = parse_li_operands(insns[0][1])
    lis_reg, lis_val = parse_lis_operands(insns[1][1])
    addi_dst, addi_src, addi_imm = parse_addi_operands(insns[4][1])
    li2_reg, li2_val = parse_li_operands(insns[12][1])

    if li_reg is None or lis_reg is None or addi_dst is None:
        return None, None

    table_addr = reconstruct_address(lis_val, addi_imm)
    count = li_val
    not_found_val = li2_val

    return 'int', (
        f'{{ int* __tbl = (int*)0x{table_addr:08X}; '
        f'for (int __i = 0; __i < {count}; __i++) '
        f'{{ if (__tbl[__i] == val) return __i; }} '
        f'return {not_found_val}; }}'
    )


def match_cond_sda_store(insns, func_info):
    """Match: lwz r0,off(r13); cmpwi r0,0; beq .skip; li r0,0; stw r0,off(r13);
              lwz r9,off2(r3); addi r9,r9,N; stw r9,off2(r3); blr

    Conditional SDA flag clear + field increment.
    Covers: lwz_cmpwi_beq_li_stw_lwz_addi_stw_blr  (3 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 9 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]  # lwz r0,off(r13)
    m1, op1 = insns[1]  # cmpwi r0,0
    m2, op2 = insns[2]  # beq .skip
    m3, op3 = insns[3]  # li r0,0
    m4, op4 = insns[4]  # stw r0,off(r13)
    m5, op5 = insns[5]  # lwz r9,off2(r3)
    m6, op6 = insns[6]  # addi r9,r9,N
    m7, op7 = insns[7]  # stw r9,off2(r3)

    if m0 != 'lwz' or m1 != 'cmpwi':
        return None, None
    if not is_cond_branch(m2):
        return None, None
    if m3 != 'li' or not is_store_insn(m4):
        return None, None
    if not is_load_insn(m5) or m6 != 'addi' or not is_store_insn(m7):
        return None, None

    ld0_reg, ld0_off, ld0_base = parse_load_store_operands(op0)
    cmp_reg, cmp_val = parse_cmpwi_operands(op1)
    li_reg, li_val = parse_li_operands(op3)
    st0_reg, st0_off, st0_base = parse_load_store_operands(op4)
    ld1_reg, ld1_off, ld1_base = parse_load_store_operands(op5)
    addi_dst, addi_src, addi_imm = parse_addi_operands(op6)
    st1_reg, st1_off, st1_base = parse_load_store_operands(op7)

    if ld0_base != 'r13' or st0_base != 'r13':
        return None, None
    if ld1_base != 'r3' or st1_base != 'r3':
        return None, None

    cond = strip_branch_hint(m2)

    ct = get_store_type(m7)
    # SDA conditional + field increment
    return 'void', (
        f'{{ register int __sda __asm__("{ld0_reg}"); '
        f'__asm__ __volatile__("lwz %0, {ld0_off}(%%r13)" : "=r"(__sda)); '
        f'if (__sda {cond_to_c_op(cond, negated=True)} {cmp_val}) {{ '
        f'register int __r0 __asm__("{li_reg}") = {li_val}; '
        f'__asm__ __volatile__("" : "+r"(__r0)); '
        f'__asm__ __volatile__("stw %0, {st0_off}(%%r13)" : : "r"(__r0)); }} '
        f'*({ct}*)((char*)this + {format_offset(ld1_off)}) += {addi_imm}; }}'
    )


def match_find_in_array_loop(insns, func_info):
    """Match: lwz r0,off1(r3); lwz r9,off2(r3); cmpw r9,r0; beq .notfound;
              mr r11,r0; lwz r3,0(r9); lwz r0,0(r3); cmpw r0,r4; beqlr;
              addi r9,r9,4; cmpw r9,r11; bne .loop; li r3,0; blr

    Find element in array by ID.
    Covers: lwz_lwz_cmpw_beq_mr_lwz_lwz_cmpw_beqlr_addi_cmpw_bne_li_blr (3 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 14 or mnemonics[-1] != 'blr':
        return None, None

    if mnemonics[0] != 'lwz' or mnemonics[1] != 'lwz':
        return None, None
    if mnemonics[2] not in ('cmpw', 'cmplw'):
        return None, None
    if strip_branch_hint(mnemonics[3]) != 'beq':
        return None, None
    if mnemonics[4] != 'mr':
        return None, None
    if mnemonics[5] != 'lwz' or mnemonics[6] != 'lwz':
        return None, None
    if mnemonics[7] not in ('cmpw', 'cmplw'):
        return None, None
    if strip_branch_hint(mnemonics[8]) != 'beqlr':
        return None, None
    if mnemonics[9] != 'addi':
        return None, None
    if mnemonics[10] not in ('cmpw', 'cmplw'):
        return None, None
    if strip_branch_hint(mnemonics[11]) != 'bne':
        return None, None
    if mnemonics[12] != 'li':
        return None, None

    ld0_reg, ld0_off, ld0_base = parse_load_store_operands(insns[0][1])  # end ptr
    ld1_reg, ld1_off, ld1_base = parse_load_store_operands(insns[1][1])  # begin ptr
    ld_item_reg, ld_item_off, ld_item_base = parse_load_store_operands(insns[5][1])  # *iter
    ld_id_reg, ld_id_off, ld_id_base = parse_load_store_operands(insns[6][1])  # item->id

    if ld0_base != 'r3' or ld1_base != 'r3':
        return None, None

    return 'void*', (
        f'{{ int* __end = *(int**)((char*)this + {format_offset(ld0_off)}); '
        f'int* __p = *(int**)((char*)this + {format_offset(ld1_off)}); '
        f'while (__p != __end) {{ '
        f'void* __item = *(void**)__p; '
        f'if (*(int*)((char*)__item + {format_offset(ld_id_off)}) == val) return __item; '
        f'__p++; }} return 0; }}'
    )


def match_cond_or_andc(insns, func_info):
    """Match: cmpwi r5,0; beq .else; lwz r0,off(r3); or r0,r0,r4; stw r0,off(r3); blr;
              lwz r0,off(r3); andc r0,r0,r4; stw r0,off(r3); blr

    Conditional flag set/clear using or/andc with mask parameter.
    Covers: cmpwi_beq_lwz_or_stw_blr_lwz_andc_stw_blr (2 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 10:
        return None, None

    m0, op0 = insns[0]  # cmpwi r5,0
    m1, op1 = insns[1]  # beq
    m2, op2 = insns[2]  # lwz r0,off(r3)
    m3, op3 = insns[3]  # or r0,r0,r4
    m4, op4 = insns[4]  # stw r0,off(r3)
    m5, op5 = insns[5]  # blr
    m6, op6 = insns[6]  # lwz r0,off(r3)
    m7, op7 = insns[7]  # andc r0,r0,r4
    m8, op8 = insns[8]  # stw r0,off(r3)
    m9, op9 = insns[9]  # blr

    if m0 != 'cmpwi':
        return None, None
    if not is_cond_branch(m1):
        return None, None
    if not is_load_insn(m2) or m3 not in ('or', 'or.') or not is_store_insn(m4):
        return None, None
    if m5 != 'blr':
        return None, None
    if not is_load_insn(m6) or m7 != 'andc' or not is_store_insn(m8):
        return None, None
    if m9 != 'blr':
        return None, None

    cmp_reg, cmp_val = parse_cmpwi_operands(op0)
    ld_reg, ld_off, ld_base = parse_load_store_operands(op2)
    st_reg, st_off, st_base = parse_load_store_operands(op4)

    if ld_base != 'r3' or st_base != 'r3':
        return None, None

    cond = strip_branch_hint(m1)
    ctype = get_load_type(m2)
    st_ctype = get_store_type(m4)

    # beq: if param3 == 0, branch to andc path (clear); fallthrough = or path (set)
    if cond == 'beq':
        return 'void', (
            f'{{ {st_ctype} __flags = *({ctype}*)((char*)this + {format_offset(ld_off)}); '
            f'if (val3) __flags |= val; else __flags &= ~val; '
            f'*({st_ctype}*)((char*)this + {format_offset(st_off)}) = __flags; }}'
        )

    return None, None


def match_float_clamp(insns, func_info):
    """Match: lfs f0,off(r3); fcmpu cr0,f1,f0; cror so,eq,gt; bsolr; stfs f1,off2(r3); blr

    Float clamp/min setter: if (val <= field) return; field = val;
    Covers: lfs_fcmpu_cror_bsolr_stfs_blr (4 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 6 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]  # lfs f0,off(r3)
    m1, op1 = insns[1]  # fcmpu cr0,f1,f0
    m2, op2 = insns[2]  # cror
    m3, op3 = insns[3]  # bsolr (branch if summary overflow = unordered or condition)
    m4, op4 = insns[4]  # stfs f1,off2(r3)

    if m0 not in ('lfs', 'lfd'):
        return None, None
    if m1 != 'fcmpu':
        return None, None
    if m2 != 'cror':
        return None, None
    if strip_branch_hint(m3) not in ('bsolr', 'bsolr+', 'bsolr-'):
        return None, None
    if m4 not in ('stfs', 'stfd'):
        return None, None

    ld_reg, ld_off, ld_base = parse_load_store_operands(op0)
    st_reg, st_off, st_base = parse_load_store_operands(op4)

    if ld_base != 'r3' or st_base != 'r3':
        return None, None

    # This is a "set if less than" pattern with float comparison
    # The cror merges unordered (NaN) with the comparison result
    # fcmpu cr0,f1,f0 compares f1 (param) with f0 (field)
    # cror so,eq,gt -> bsolr branches if f1 >= f0 (or unordered)
    # So: if (param < field) store param
    return 'void', (
        f'{{ float __limit = *(float*)((char*)this + {format_offset(ld_off)}); '
        f'if (fval < __limit) *(float*)((char*)this + {format_offset(st_off)}) = fval; }}'
    )


def match_guard_store_extended(insns, func_info):
    """Match more complex guard + body patterns.

    Handles guard clauses followed by bodies with loads and multiple stores.
    lwz rN,off(r3); cmpwi rN,0; beqlr/bnelr; <multi-insn body>; blr
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n < 6 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]
    m1, op1 = insns[1]
    m2, op2 = insns[2]

    if not is_load_insn(m0):
        return None, None
    if m1 != 'cmpwi':
        return None, None
    if not is_cond_branch_lr(m2):
        return None, None

    ld_reg, ld_off, ld_base = parse_load_store_operands(op0)
    cmp_reg, cmp_val = parse_cmpwi_operands(op1)
    if ld_reg is None or cmp_reg is None or ld_reg != cmp_reg:
        return None, None

    cond = strip_branch_hint(m2)
    ctype = get_load_type(m0)

    # The body is insns[3:-1]
    body_insns = insns[3:-1]
    if len(body_insns) < 3:
        return None, None  # too short for extended, basic patterns handle shorter

    # Try to interpret the body as a series of operations
    regs = {}
    stmts = []

    if ld_base == 'r3':
        regs[ld_reg] = ('field_load', ctype, ld_off, 'this')
    elif ld_base == 'r13':
        regs[ld_reg] = ('sda_load', ctype, ld_off)
    else:
        return None, None

    for bi, (bm, bop) in enumerate(body_insns):
        if bm == 'li':
            reg, val = parse_li_operands(bop)
            if reg is None:
                return None, None
            regs[reg] = ('const', val)

        elif bm == 'lis':
            reg, val = parse_lis_operands(bop)
            if reg is None:
                return None, None
            regs[reg] = ('lis', val)

        elif bm == 'addi':
            dst, src, imm = parse_addi_operands(bop)
            if dst is None:
                return None, None
            if src in regs and regs[src][0] == 'lis':
                full_addr = reconstruct_address(regs[src][1], imm)
                regs[dst] = ('addr', full_addr)
            elif src in regs and regs[src][0] == 'field_load' and regs[src][3] == 'this':
                # field + offset
                regs[dst] = ('const', f'field_addi')
                return None, None
            elif src in regs and regs[src][0] == 'const' and isinstance(regs[src][1], int):
                regs[dst] = ('const', regs[src][1] + imm)
            elif src == 'r3':
                regs[dst] = ('this_off', imm)
            else:
                regs[dst] = ('addi_result', src, imm)

        elif is_load_insn(bm) and not bm.endswith('x') and not bm.endswith('u'):
            reg, off, base = parse_load_store_operands(bop)
            if reg is None:
                return None, None
            ct = get_load_type(bm)
            if base == 'r3':
                regs[reg] = ('field_load', ct, off, 'this')
            elif base in regs:
                binfo = regs[base]
                if binfo[0] == 'field_load' and binfo[3] == 'this':
                    regs[reg] = ('deref_load', ct, off, base)
                elif binfo[0] == 'sda_load':
                    regs[reg] = ('sda_deref_load', ct, off, base)
                elif binfo[0] == 'addr':
                    regs[reg] = ('global_load', ct, binfo[1] + off)
                else:
                    return None, None
            elif base == 'r13':
                regs[reg] = ('sda_load', ct, off)
            else:
                return None, None

        elif is_store_insn(bm) and not bm.endswith('x') and not bm.endswith('u'):
            reg, off, base = parse_load_store_operands(bop)
            if reg is None:
                return None, None
            ct = get_store_type(bm)

            if base == 'r3':
                # Determine value
                if reg in regs:
                    rv = regs[reg]
                    if rv[0] == 'const' and isinstance(rv[1], int):
                        stmts.append(f'*({ct}*)((char*)this + {format_offset(off)}) = {rv[1]};')
                    elif rv[0] == 'addr':
                        stmts.append(f'*(void**)((char*)this + {format_offset(off)}) = (void*)0x{rv[1]:08X};')
                    elif rv[0] == 'field_load' and rv[3] == 'this':
                        stmts.append(f'*({ct}*)((char*)this + {format_offset(off)}) = *({rv[1]}*)((char*)this + {format_offset(rv[2])});')
                    else:
                        return None, None
                elif reg.startswith('r'):
                    pmap = {'r4': 'val', 'r5': 'val3', 'r6': 'val4'}
                    stmts.append(f'*({ct}*)((char*)this + {format_offset(off)}) = {pmap.get(reg, reg)};')
                elif reg.startswith('f'):
                    stmts.append(f'*({ct}*)((char*)this + {format_offset(off)}) = {reg.replace("f", "fp")};')
                else:
                    return None, None
            elif base == 'r13':
                return None, None  # SDA store in extended body too complex
            else:
                return None, None
        elif bm in ('stfs', 'stfd') and not bm.endswith('x'):
            reg, off, base = parse_load_store_operands(bop)
            if reg is None:
                return None, None
            ct = 'float' if bm == 'stfs' else 'double'
            if base == 'r3':
                if reg in regs and regs[reg][0] == 'global_load':
                    stmts.append(f'*({ct}*)((char*)this + {format_offset(off)}) = *({ct}*)0x{regs[reg][2]:08X};')
                else:
                    stmts.append(f'*({ct}*)((char*)this + {format_offset(off)}) = {reg};')
            else:
                return None, None

        elif bm in ('lfs', 'lfd') and not bm.endswith('x'):
            reg, off, base = parse_load_store_operands(bop)
            if reg is None:
                return None, None
            ct = 'float' if bm == 'lfs' else 'double'
            if base == 'r3':
                regs[reg] = ('field_load', ct, off, 'this')
            elif base in regs and regs[base][0] == 'lis':
                full = reconstruct_address(regs[base][1], off)
                regs[reg] = ('global_load', ct, full)
            elif base in regs and regs[base][0] == 'addr':
                regs[reg] = ('global_load', ct, regs[base][1] + off)
            else:
                return None, None
        else:
            return None, None

    if not stmts:
        return None, None

    body_code = ' '.join(stmts)

    if cmp_val == 0:
        if cond == 'beqlr':
            guard_str = f'if (*({ctype}*)((char*)this + {format_offset(ld_off)}) != 0)' if ld_base == 'r3' else None
        elif cond == 'bnelr':
            guard_str = f'if (*({ctype}*)((char*)this + {format_offset(ld_off)}) == 0)' if ld_base == 'r3' else None
        else:
            return None, None
    else:
        return None, None

    if guard_str is None:
        return None, None

    return 'void', f'{{ {guard_str} {{ {body_code} }} }}'


def match_double_guard_check(insns, func_info):
    """Match: lwz rN,off(r3); li r3,0; cmpwi rN,0; beqlr; cmpwi r4,val; beqlr; li r3,1; blr

    Two sequential guard checks.
    Covers: lwz_li_cmpwi_beqlr_cmpwi_beqlr_li_blr  (2 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 8 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]  # lwz
    m1, op1 = insns[1]  # li r3,0
    m2, op2 = insns[2]  # cmpwi
    m3, op3 = insns[3]  # beqlr
    m4, op4 = insns[4]  # cmpwi
    m5, op5 = insns[5]  # beqlr
    m6, op6 = insns[6]  # li r3,1

    if not is_load_insn(m0):
        return None, None
    if m1 != 'li' or m6 != 'li':
        return None, None
    if m2 != 'cmpwi' or m4 != 'cmpwi':
        return None, None
    if not is_cond_branch_lr(m3) or not is_cond_branch_lr(m5):
        return None, None

    li0_reg, li0_val = parse_li_operands(op1)
    li1_reg, li1_val = parse_li_operands(op6)
    if li0_reg != 'r3' or li1_reg != 'r3':
        return None, None

    ld_reg, ld_off, ld_base = parse_load_store_operands(op0)
    cmp0_reg, cmp0_val = parse_cmpwi_operands(op2)
    cmp1_reg, cmp1_val = parse_cmpwi_operands(op4)

    if ld_reg is None or cmp0_reg is None or cmp1_reg is None:
        return None, None

    cond0 = strip_branch_hint(m3)
    cond1 = strip_branch_hint(m5)

    if ld_base == 'r3':
        ct = get_load_type(m0)
        load_expr = f'*({ct}*)((char*)this + {format_offset(ld_off)})'

        # beqlr on field == 0 -> return 0 (default)
        # beqlr on r4 == val -> return 0 (default)
        # li r3,1 -> return 1
        # So: return field != 0 && r4 != val
        c0 = cond_to_c_op(cond0, negated=True)
        c1 = cond_to_c_op(cond1, negated=True)

        return 'bool', f'{{ return ({load_expr} {c0} {cmp0_val}) && (val {c1} {cmp1_val}); }}'

    return None, None


def match_guard_load_return(insns, func_info):
    """Match: lwz rN,off(r3); cmpwi rN,0; beqlr/bnelr; lwz r0,off2(rN); stw r0,off3(rN); blr
    And similar guard + field store patterns.
    Covers: lwz_cmpwi_beqlr_lwz_stw_blr (2 functions)
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n != 6 or mnemonics[-1] != 'blr':
        return None, None

    m0, op0 = insns[0]  # lwz
    m1, op1 = insns[1]  # cmpwi
    m2, op2 = insns[2]  # beqlr/bnelr
    m3, op3 = insns[3]  # lwz
    m4, op4 = insns[4]  # stw

    if not is_load_insn(m0) or m1 != 'cmpwi':
        return None, None
    if not is_cond_branch_lr(m2):
        return None, None
    if not is_load_insn(m3) or not is_store_insn(m4):
        return None, None

    ld0_reg, ld0_off, ld0_base = parse_load_store_operands(op0)
    cmp_reg, cmp_val = parse_cmpwi_operands(op1)
    ld1_reg, ld1_off, ld1_base = parse_load_store_operands(op3)
    st_reg, st_off, st_base = parse_load_store_operands(op4)

    if (ld0_reg is None or cmp_reg is None or ld1_reg is None or st_reg is None):
        return None, None
    if ld0_reg != cmp_reg:
        return None, None

    cond = strip_branch_hint(m2)

    # Common: guard on pointer, then copy a field through it
    if ld0_base == 'r3' and ld1_base == ld0_reg and st_base == ld0_reg:
        ct_ld = get_load_type(m3)
        ct_st = get_store_type(m4)
        if cond == 'beqlr' and cmp_val == 0:
            return 'void', (
                f'{{ void* __p = *(void**)((char*)this + {format_offset(ld0_off)}); '
                f'if (__p) {{ *({ct_st}*)((char*)__p + {format_offset(st_off)}) = '
                f'*({ct_ld}*)((char*)__p + {format_offset(ld1_off)}); }} }}'
            )

    return None, None


def match_static_init_guard(insns, func_info):
    """Match: li r0,0; ori r0,r0,65535; cmpw r4,r0; bnelr; cmpwi r3,0; beqlr; ...

    Static initialization guard (__static_initialization_and_destruction_0).
    These check (d == 65535 && priority == 1).
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)
    if n < 8 or mnemonics[-1] != 'blr':
        return None, None

    if mnemonics[0] != 'li' or mnemonics[1] != 'ori':
        return None, None
    if mnemonics[2] not in ('cmpw', 'cmplw'):
        return None, None
    if strip_branch_hint(mnemonics[3]) != 'bnelr':
        return None, None
    if mnemonics[4] != 'cmpwi':
        return None, None
    if strip_branch_hint(mnemonics[5]) != 'beqlr':
        return None, None

    # This is a static init guard. The body after the guards contains
    # the actual initialization. These are complex and architecture-specific.
    # Skip for now - they contain lis+lfs patterns that need careful handling.
    return None, None


# ============================================================================
# Master matcher for branching leaf functions
# ============================================================================

def try_match_branch(func_name, insns, func_info):
    """Try to match a branching leaf function.

    Returns (return_type, body_code) or (None, None) if no match.
    """
    mnemonics = [m for m, _ in insns]

    # Must have branches and no calls
    if has_calls(insns):
        return None, None
    if not has_branches(insns):
        return None, None
    if has_unknowns(insns):
        return None, None

    # Try patterns in order of frequency / specificity

    # 1. Loop Destruct/Construct (27 functions) - most common
    ret, body = match_loop_destruct_construct(insns, func_info)
    if ret is not None:
        return ret, body

    # 2. Guard clause + store (23 functions)
    ret, body = match_guard_store(insns, func_info)
    if ret is not None:
        return ret, body

    # 3. Bool field check (22 + 3 = 25 functions)
    ret, body = match_bool_field_check(insns, func_info)
    if ret is not None:
        return ret, body

    # 4. Bitflag setter (21 + 10 = 31 functions)
    ret, body = match_bitflag_setter(insns, func_info)
    if ret is not None:
        return ret, body

    # 5. Type check with rlwinm (19 functions)
    ret, body = match_type_check_rlwinm(insns, func_info)
    if ret is not None:
        return ret, body

    # 6. Bool andi. check (6 + 4 = 10 functions)
    ret, body = match_andi_bool_check(insns, func_info)
    if ret is not None:
        return ret, body

    # 7. Linked list length (7 functions)
    ret, body = match_linked_list_length(insns, func_info)
    if ret is not None:
        return ret, body

    # 8. Loop copy (6 functions)
    ret, body = match_loop_copy(insns, func_info)
    if ret is not None:
        return ret, body

    # 9. Null check + load (5 + 4 = 9 functions)
    ret, body = match_null_check_load(insns, func_info)
    if ret is not None:
        return ret, body

    # 10. rlwimi bitfield setters (4 + 4 = 8 functions)
    ret, body = match_rlwimi_bitfield_setter(insns, func_info)
    if ret is not None:
        return ret, body

    # 11. Conditional flag setter (3 functions)
    ret, body = match_cond_flag_setter(insns, func_info)
    if ret is not None:
        return ret, body

    # 12. Guard + addi + bnelr (3 functions)
    ret, body = match_guard_addi_bnelr(insns, func_info)
    if ret is not None:
        return ret, body

    # 13. Null deref chain (3 functions)
    ret, body = match_null_deref_chain(insns, func_info)
    if ret is not None:
        return ret, body

    # 14. lis+cmpwi+beqlr (3 functions)
    ret, body = match_lis_cmpwi_beqlr(insns, func_info)
    if ret is not None:
        return ret, body

    # 15. mr. null check (3 functions)
    ret, body = match_mr_null_check(insns, func_info)
    if ret is not None:
        return ret, body

    # 16. Two-condition check (3 functions)
    ret, body = match_two_cond_check(insns, func_info)
    if ret is not None:
        return ret, body

    # 17. Copy reverse loop (3 functions)
    ret, body = match_copy_reverse_loop(insns, func_info)
    if ret is not None:
        return ret, body

    # 18. SDA guard + store (subset of guard_store)
    ret, body = match_guard_store_sda(insns, func_info)
    if ret is not None:
        return ret, body

    # 19. Table lookup loop (3 functions)
    ret, body = match_table_lookup_loop(insns, func_info)
    if ret is not None:
        return ret, body

    # 20. Find in array loop (3 functions)
    ret, body = match_find_in_array_loop(insns, func_info)
    if ret is not None:
        return ret, body

    # 21. Conditional SDA store (3 functions)
    ret, body = match_cond_sda_store(insns, func_info)
    if ret is not None:
        return ret, body

    # 22. Conditional or/andc (2 functions)
    ret, body = match_cond_or_andc(insns, func_info)
    if ret is not None:
        return ret, body

    # 23. Float clamp/min setter (4 functions)
    ret, body = match_float_clamp(insns, func_info)
    if ret is not None:
        return ret, body

    # 24. Double guard check (2 functions)
    ret, body = match_double_guard_check(insns, func_info)
    if ret is not None:
        return ret, body

    # 25. Guard + load + store (field copy through pointer) (2 functions)
    ret, body = match_guard_load_return(insns, func_info)
    if ret is not None:
        return ret, body

    # 26. Extended guard + store (catch-all for guard patterns with longer bodies)
    ret, body = match_guard_store_extended(insns, func_info)
    if ret is not None:
        return ret, body

    return None, None


def _valid_body(body, func_info):
    """Check if generated body is valid C++ (no placeholder comments)."""
    if not body:
        return False
    bad_markers = ['/* addi result */', '/* raw_load */', '/* deref load */',
                   '/* ori result */', '/* oris result */', '/* float_op */',
                   '/* indexed store', '/* SDA']
    for marker in bad_markers:
        if marker in body:
            return False
    # Skip if body uses 'this' but function is not a member
    if 'this' in body and not func_info.get("class_name"):
        return False
    return True


# ============================================================================
# Output and main
# ============================================================================

def main():
    parser = argparse.ArgumentParser(
        description="Auto-match branching leaf functions (21-64 bytes)"
    )
    parser.add_argument("--min-size", type=int, default=21,
                        help="Minimum function size in bytes (default: 21)")
    parser.add_argument("--max-size", type=int, default=64,
                        help="Maximum function size in bytes (default: 64)")
    parser.add_argument("--name", metavar="PATTERN",
                        help="Only process functions matching this name pattern")
    parser.add_argument("--generate", action="store_true",
                        help="Generate C++ code to src/matched/")
    parser.add_argument("--dry-run", action="store_true",
                        help="Show what would be generated without writing files")
    parser.add_argument("--show-unmatched", action="store_true",
                        help="Show all unmatched branching function disassembly")
    args = parser.parse_args()

    print(f"Loading functions ({args.min_size}-{args.max_size} bytes)...")
    funcs = load_functions(args.min_size, args.max_size, args.name)
    print(f"Found {len(funcs)} functions in code sections")

    if not funcs:
        return

    print("Disassembling...")
    results = disassemble_batch(funcs)

    # Filter to only branching leaf functions (branches but no bl)
    branch_leaf = {}
    skipped_bl = 0
    skipped_no_branch = 0
    skipped_unknown = 0

    for (addr, name), insns in sorted(results.items()):
        mnemonics = [m for m, _ in insns]

        if has_calls(insns):
            skipped_bl += 1
            continue
        if has_unknowns(insns):
            skipped_unknown += 1
            continue
        if not has_branches(insns):
            skipped_no_branch += 1
            continue

        branch_leaf[(addr, name)] = insns

    print(f"Branching leaf functions: {len(branch_leaf)}")

    # Try to match each function
    matched = []
    unmatched = []
    pattern_counts = defaultdict(int)

    for (addr, name), insns in sorted(branch_leaf.items()):
        func_info = parse_function_name(name)
        return_type, body = try_match_branch(name, insns, func_info)

        if return_type is not None and _valid_body(body, func_info):
            cpp_line = format_cpp_function_v2(name, func_info, return_type, body)
            matched.append({
                "name": name,
                "address": addr,
                "size": len(insns) * 4,
                "cpp": cpp_line,
                "return_type": return_type,
                "body": body,
                "func_info": func_info,
                "insns": insns,
            })
            # Classify by instruction pattern for stats
            pat = '_'.join(m for m, _ in insns)
            pattern_counts[pat] += 1
        else:
            insn_str = "; ".join(f"{m} {op}" for m, op in insns)
            unmatched.append({
                "name": name,
                "address": addr,
                "size": len(insns) * 4,
                "insns_str": insn_str,
                "insns": insns,
            })

    # Report
    matched_count = len(matched)
    matched_bytes = sum(m["size"] for m in matched)
    unmatched_count = len(unmatched)

    print(f"\n{'=' * 72}")
    print(f"  Branching Leaf Function Auto-Match Report")
    print(f"{'=' * 72}")
    print(f"  Total functions in range:       {len(results)}")
    print(f"  Skipped (has bl):               {skipped_bl}")
    print(f"  Skipped (no branch):            {skipped_no_branch}")
    print(f"  Skipped (unknown insns):        {skipped_unknown}")
    print(f"  Branching leaf candidates:      {len(branch_leaf)}")
    print(f"  Auto-matched:                   {matched_count}")
    print(f"  Matched bytes:                  {matched_bytes}")
    print(f"  Unmatched:                      {unmatched_count}")
    print(f"  Match rate:                     {matched_count * 100 / len(branch_leaf):.1f}%")
    print()

    # Show sample generated code
    if args.generate or args.dry_run:
        print(f"  Generated C++ ({matched_count} functions):")
        print(f"{'=' * 72}\n")

        by_class = defaultdict(list)
        for m in matched:
            cls = m["func_info"]["class_name"] or "(global)"
            by_class[cls].append(m)

        for cls in sorted(by_class.keys()):
            funcs_in_class = by_class[cls]
            if args.dry_run:
                print(f"// --- {cls} ({len(funcs_in_class)} functions) ---")
                for m in funcs_in_class[:5]:
                    insn_str = "; ".join(f"{mn} {op}" for mn, op in m["insns"])
                    print(f"// 0x{m['address']:08X} ({m['size']}b) {m['name']}")
                    print(f"//   {insn_str}")
                    print(m["cpp"])
                    print()
                if len(funcs_in_class) > 5:
                    print(f"// ... and {len(funcs_in_class) - 5} more")
                    print()

    # Write output files
    if args.generate and not args.dry_run:
        out_dir = ROOT_DIR / "src" / "matched"
        out_dir.mkdir(parents=True, exist_ok=True)

        # Collect ALL existing addresses from ALL files to avoid duplicates
        all_existing_addrs = set()
        for existing_file in out_dir.glob("*.cpp"):
            content = existing_file.read_text()
            for m_match in re.finditer(r"// 0x([0-9A-Fa-f]+)\s+\(\d+ bytes\)", content):
                all_existing_addrs.add(int(m_match.group(1), 16))

        by_class = defaultdict(list)
        for m in matched:
            cls = m["func_info"]["class_name"] or "_global"
            by_class[cls].append(m)

        files_written = 0
        funcs_added = 0
        for cls, funcs_in_class in sorted(by_class.items()):
            # Use _branch_auto.cpp suffix
            filename = (cls.replace("::", "_").replace("<", "_").replace(">", "_")
                          .replace("*", "ptr").replace(" ", "_").replace(",", "_")
                          + "_branch_auto.cpp")
            filepath = out_dir / filename

            # Check for existing branch file
            existing_addrs = set()
            if filepath.exists():
                content = filepath.read_text()
                for m_match in re.finditer(r"// 0x([0-9A-Fa-f]+)\s+\(\d+ bytes\)", content):
                    existing_addrs.add(int(m_match.group(1), 16))

            # Filter out functions already in any file
            new_funcs = [fn for fn in funcs_in_class
                         if fn["address"] not in all_existing_addrs
                         and fn["address"] not in existing_addrs]
            if not new_funcs:
                continue

            with open(filepath, "w") as f:
                f.write('#include "types.h"\n')
                f.write('#include "stub_classes.h"\n')
                f.write(f"// Auto-generated matching stubs for {cls} (branching leaf functions)\n")
                f.write(f"// Generated by auto_match_branch.py\n")
                f.write(f"// {len(new_funcs)} functions, "
                        f"{sum(fn['size'] for fn in new_funcs)} bytes\n\n")

                for fn in new_funcs:
                    f.write(f"// 0x{fn['address']:08X} ({fn['size']} bytes)\n")
                    f.write(fn["cpp"] + "\n\n")
                    funcs_added += 1

            files_written += 1

        print(f"  Wrote {funcs_added} new functions to {files_written} files in {out_dir}/")
        print(f"  Total matched: {matched_count} functions, {matched_bytes} bytes")

    # Show unmatched samples
    if not args.generate and not args.dry_run:
        print(f"  Sample unmatched branching functions (first 20):")
        # Group unmatched by instruction pattern
        unmatched_patterns = defaultdict(list)
        for u in unmatched:
            pat = '_'.join(m for m, _ in u["insns"])
            unmatched_patterns[pat].append(u)

        sorted_up = sorted(unmatched_patterns.items(), key=lambda x: -len(x[1]))
        shown = 0
        for pat, funcs_list in sorted_up[:20]:
            print(f"    [{len(funcs_list):3d}] {pat}")
            for u in funcs_list[:2]:
                print(f"         0x{u['address']:08X} {u['name']}")
                print(f"           {u['insns_str']}")
            shown += 1
        print(f"  Total unmatched patterns: {len(unmatched_patterns)}")
        print()

    if args.show_unmatched:
        print(f"\n  All unmatched branching functions ({unmatched_count}):")
        for u in unmatched:
            print(f"    0x{u['address']:08X} ({u['size']:3d}b) {u['name']}")
            print(f"      {u['insns_str']}")


if __name__ == "__main__":
    main()
