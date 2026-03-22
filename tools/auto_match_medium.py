#!/usr/bin/env python3
"""
Sims 2 GameCube -- Auto-match medium-complexity functions (21-64 bytes).

Extends the auto_match.py pipeline to handle 6-16 instruction leaf functions
(no function calls). These fall into two categories:

1. Pure leaf (no branches): multi-field init, struct copy, computed values
2. Branching leaf (conditional returns, loops): if/else, early returns, small loops

Key principle: Functions with `bl` (function call) instructions cannot be matched
at the .o level because the call offset is position-dependent and won't match
the DOL's final relocations. We skip those entirely.

Usage:
    python tools/auto_match_medium.py                    # report only
    python tools/auto_match_medium.py --generate         # generate C++ to src/matched/
    python tools/auto_match_medium.py --dry-run           # show what would generate
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
    try_match as try_match_small,
    INSN_RE, ORIGINAL_ELF, OBJDUMP, CODE_SECTIONS, SYMBOLS_JSON,
)


def format_cpp_function_v2(func_name, func_info, return_type, body):
    """Format a matched function as a C++ declaration + body.

    Improved version that handles:
    - Constructors (method_name == class_name) -> no return type
    - Destructors (~class_name) -> no return type
    - Proper parameter naming when body references val/val3/fval/fp1 etc.
    """
    method = func_info["method_name"] or func_name
    cls = func_info["class_name"]
    ns = func_info.get("namespace")
    params = func_info["params"]
    const = " const" if func_info["is_const"] else ""

    # Build the qualified name
    if ns and cls:
        qualified = f"{ns}::{cls}::{method}"
    elif cls:
        qualified = f"{cls}::{method}"
    else:
        qualified = method

    # Handle param formatting - add parameter names if body uses them
    if params == "void":
        params_decl = ""
    elif not params:
        params_decl = ""
    else:
        # Split params and add names if needed
        param_parts = []
        raw_parts = split_params(params)
        param_names = ['val', 'val3', 'val4', 'val5']
        float_param_names = ['fval', 'fval2', 'fval3']

        # Determine if body references val, val3, fp1, fval etc.
        needs_names = ('val' in body or 'val3' in body or 'val4' in body
                       or 'fval' in body or 'fp1' in body or 'fp2' in body)

        if needs_names:
            int_idx = 0
            float_idx = 0
            for i, p in enumerate(raw_parts):
                p = p.strip()
                if not p:
                    continue
                # Check if this param type is float/double
                is_float_param = p.startswith('float') or p.startswith('double')
                # Check if it already has a name (word followed by another word)
                has_name = len(p.split()) > 1 and not p.endswith('*') and not p.endswith('&')
                if has_name:
                    param_parts.append(p)
                elif is_float_param:
                    name = float_param_names[float_idx] if float_idx < len(float_param_names) else f'fparam{float_idx}'
                    param_parts.append(f'{p} {name}')
                    float_idx += 1
                else:
                    name = param_names[int_idx] if int_idx < len(param_names) else f'param{int_idx}'
                    param_parts.append(f'{p} {name}')
                    int_idx += 1
            params_decl = ', '.join(param_parts)
        else:
            params_decl = params

    # Detect constructors/destructors
    is_ctor = cls and method == cls
    is_dtor = cls and method == f"~{cls}"

    if is_ctor or is_dtor:
        line = f"{qualified}({params_decl}){const} {body}"
    else:
        line = f"{return_type} {qualified}({params_decl}){const} {body}"
    return line


def split_params(params_str):
    """Split a comma-separated parameter list, respecting template brackets."""
    result = []
    depth = 0
    current = ""
    for ch in params_str:
        if ch == '<':
            depth += 1
        elif ch == '>':
            depth -= 1
        elif ch == ',' and depth == 0:
            result.append(current)
            current = ""
            continue
        current += ch
    if current.strip():
        result.append(current)
    return result


# ============================================================================
# Instruction classification helpers
# ============================================================================

def is_load_insn(mnemonic):
    """Is this a load instruction?"""
    return mnemonic in ('lwz', 'lhz', 'lha', 'lbz', 'lfs', 'lfd',
                        'lwzx', 'lhzx', 'lhax', 'lbzx', 'lfsx', 'lfdx',
                        'lwzu', 'lhzu', 'lbzu', 'lhau', 'lfsu',
                        'lwzux', 'lhzux', 'lbzux', 'lhaux', 'lfsux')


def is_store_insn(mnemonic):
    """Is this a store instruction?"""
    return mnemonic in ('stw', 'sth', 'stb', 'stfs', 'stfd',
                        'stwx', 'sthx', 'stbx', 'stfsx', 'stfdx',
                        'stwu', 'sthu', 'stbu', 'stfsu',
                        'stwux', 'sthux', 'stbux', 'stfsux')


def is_branch_insn(mnemonic):
    """Is this a branch (not bl/blr)?"""
    return mnemonic.startswith('b') and mnemonic not in ('blr', 'bl', 'blrl')


def is_call_insn(mnemonic):
    """Is this a function call?"""
    return mnemonic in ('bl', 'blrl')


def has_calls(insns):
    """Check if instruction list contains function calls."""
    return any(is_call_insn(m) for m, _ in insns)


def has_branches(insns):
    """Check if instruction list contains branches."""
    return any(is_branch_insn(m) for m, _ in insns)


def has_unknowns(insns):
    """Check if instruction list contains unknown instructions."""
    return any(m == '???' for m, _ in insns)


def get_store_type(mnemonic):
    """Get C type string for a store instruction."""
    if mnemonic in ('stw', 'stwx'):
        return 'int'
    elif mnemonic in ('sth', 'sthx'):
        return 'short'
    elif mnemonic in ('stb', 'stbx'):
        return 'char'
    elif mnemonic in ('stfs', 'stfsx'):
        return 'float'
    elif mnemonic in ('stfd', 'stfdx'):
        return 'double'
    return 'int'


def get_load_type(mnemonic):
    """Get C type string for a load instruction."""
    if mnemonic in ('lwz', 'lwzx'):
        return 'int'
    elif mnemonic in ('lhz', 'lhzx'):
        return 'unsigned short'
    elif mnemonic in ('lha', 'lhax'):
        return 'short'
    elif mnemonic in ('lbz', 'lbzx'):
        return 'unsigned char'
    elif mnemonic in ('lfs', 'lfsx'):
        return 'float'
    elif mnemonic in ('lfd', 'lfdx'):
        return 'double'
    return 'int'


def format_offset(offset):
    """Format an offset value as hex."""
    if offset < 0:
        return f"-0x{(-offset) & 0xFFFF:X}"
    return f"0x{offset & 0xFFFF:X}"


# ============================================================================
# Generic multi-store pattern handler
# ============================================================================

def try_match_multi_store(func_name, insns, func_info):
    """Match functions that are purely a sequence of li/lis/mr + stores.

    Handles:
    - mr rN,r3; li r0,X; stw r0,off1(rN); stw r0,off2(rN); ...; blr
    - lis rN,hi; mr rM,r3; addi rN,rN,lo; stw rN,off(rM); ...; blr
    - li rN,X; stw rN,off1(r3); stw rN,off2(r3); ...; blr
    - Direct multi-stores to r3-based fields
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)

    # Must end with blr
    if mnemonics[-1] != 'blr':
        return None, None

    # Track register state
    regs = {}  # reg -> value or description
    this_reg = 'r3'  # register holding 'this' pointer
    statements = []
    return_val = None

    for i, (mnem, ops) in enumerate(insns[:-1]):  # skip final blr
        # li rN, val
        if mnem == 'li':
            reg, val = parse_li_operands(ops)
            if reg is None:
                return None, None
            regs[reg] = ('const', val)
            continue

        # mr rN, rM
        if mnem == 'mr':
            dst, src = parse_mr_operands(ops)
            if dst is None:
                return None, None
            if src == 'r3':
                this_reg = dst
                regs[dst] = ('this',)
            elif src in regs:
                regs[dst] = regs[src]
            else:
                regs[dst] = ('param', src)
            continue

        # lis rN, hi
        if mnem == 'lis':
            reg, val = parse_lis_operands(ops)
            if reg is None:
                return None, None
            regs[reg] = ('lis', val)
            continue

        # addi rD, rS, imm
        if mnem == 'addi':
            dst, src, imm = parse_addi_operands(ops)
            if dst is None:
                return None, None
            if src in regs and regs[src][0] == 'lis':
                # lis+addi = address load
                full_addr = reconstruct_address(regs[src][1], imm)
                regs[dst] = ('addr', full_addr)
            elif src == this_reg or (src in regs and regs[src][0] == 'this'):
                regs[dst] = ('this_off', imm)
            elif src in regs and regs[src][0] == 'const':
                regs[dst] = ('const', regs[src][1] + imm)
            else:
                regs[dst] = ('addi', src, imm)
            continue

        # ori rD, rS, imm (often used to set low 16 bits after lis)
        if mnem == 'ori':
            dst, src, val = parse_ori_operands(ops)
            if dst is None:
                return None, None
            if src in regs and regs[src][0] == 'lis':
                full_val = ((regs[src][1] & 0xFFFF) << 16) | (val & 0xFFFF)
                regs[dst] = ('const', full_val)
            elif src in regs and regs[src][0] == 'const':
                regs[dst] = ('const', regs[src][1] | val)
            else:
                return None, None
            continue

        # Store instructions: stw/sth/stb/stfs/stfd rN, off(rM)
        if is_store_insn(mnem) and not mnem.endswith('x') and not mnem.endswith('u'):
            reg, offset, base = parse_load_store_operands(ops)
            if reg is None:
                return None, None

            # Determine base pointer
            base_expr = None
            if base == 'r3' or base == this_reg or (base in regs and regs.get(base, (None,))[0] == 'this'):
                base_expr = 'this'
            elif base in regs and regs[base][0] == 'addr':
                base_expr = f'addr_0x{regs[base][1]:08X}'
            elif base == 'r13':
                base_expr = 'sda'
            elif base in regs and regs[base][0] == 'this_off':
                base_expr = 'this'
                offset += regs[base][1]
            else:
                return None, None

            # Determine value
            ctype = get_store_type(mnem)
            if reg in regs:
                rv = regs[reg]
                if rv[0] == 'const':
                    val_str = str(rv[1])
                elif rv[0] == 'addr':
                    val_str = f'(void*)0x{rv[1]:08X}'
                    ctype = 'void*'
                elif rv[0] == 'param':
                    val_str = rv[1].replace('r', 'param')
                elif rv[0] == 'this':
                    val_str = 'this_ptr'
                else:
                    return None, None
            elif reg.startswith('r'):
                # Parameter register
                param_map = {'r4': 'val', 'r5': 'val3', 'r6': 'val4', 'r7': 'val5'}
                val_str = param_map.get(reg, reg)
            elif reg.startswith('f'):
                val_str = reg.replace('f', 'fp')
            else:
                return None, None

            if base_expr == 'this':
                statements.append(
                    f'*({ctype}*)((char*)this + {format_offset(offset)}) = {val_str};'
                )
            elif base_expr == 'sda':
                statements.append(f'/* SDA @ r13{offset:+d} = {val_str} */;')
            elif base_expr.startswith('addr_'):
                statements.append(
                    f'*({ctype}*)(0x{base_expr[5:]} + {format_offset(offset)}) = {val_str};'
                )
            else:
                return None, None
            continue

        # Load instructions that feed a later store: lwz rN, off(rM)
        if is_load_insn(mnem) and not mnem.endswith('x') and not mnem.endswith('u'):
            reg, offset, base = parse_load_store_operands(ops)
            if reg is None:
                return None, None

            ctype = get_load_type(mnem)
            if base == 'r3' or base == this_reg or (base in regs and regs.get(base, (None,))[0] == 'this'):
                regs[reg] = ('field_load', ctype, offset, 'this')
            elif base == 'r13':
                regs[reg] = ('sda_load', ctype, offset)
            elif base in regs and regs[base][0] == 'addr':
                full = regs[base][1]
                regs[reg] = ('global_load', ctype, full + offset)
            elif base in regs and regs[base][0] == 'field_load':
                # Double deref
                regs[reg] = ('deref_load', ctype, offset, base)
            elif base in regs and regs[base][0] == 'this_off':
                regs[reg] = ('field_load', ctype, offset + regs[base][1], 'this')
            elif base == 'r4':
                regs[reg] = ('param_load', ctype, offset, 'r4')
            else:
                regs[reg] = ('unknown_load', base, offset)
            continue

        # lhz/lbz/lha + rlwimi -> bitfield insert (handled elsewhere)
        # Unsupported instruction
        return None, None

    if not statements:
        return None, None

    body = '{ ' + ' '.join(statements) + ' }'
    return 'void', body


# ============================================================================
# Multi-field copy pattern (lwz+stw sequences)
# ============================================================================

def try_match_field_copy(func_name, insns, func_info):
    """Match functions that copy multiple fields between objects.

    Pattern: lwz rN,off_src(rA); stw rN,off_dst(rB); ... blr
    Or with an initial addi to set up base pointer.
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)

    if mnemonics[-1] != 'blr':
        return None, None

    # Track register aliases
    regs = {}
    statements = []
    this_reg = 'r3'

    for i, (mnem, ops) in enumerate(insns[:-1]):
        if mnem == 'mr':
            dst, src = parse_mr_operands(ops)
            if dst is None:
                return None, None
            if src == 'r3':
                this_reg = dst
            regs[dst] = regs.get(src, src)
            continue

        if mnem == 'addi':
            dst, src, imm = parse_addi_operands(ops)
            if dst is None:
                return None, None
            regs[dst] = ('addi', src, imm)
            continue

        # Load
        if is_load_insn(mnem) and not mnem.endswith('x') and not mnem.endswith('u'):
            reg, offset, base = parse_load_store_operands(ops)
            if reg is None:
                return None, None
            regs[reg] = ('load', mnem, offset, base)
            continue

        # Store: must follow a corresponding load
        if is_store_insn(mnem) and not mnem.endswith('x') and not mnem.endswith('u'):
            reg, offset, base = parse_load_store_operands(ops)
            if reg is None:
                return None, None

            # Try to find the source from the load
            if reg in regs and isinstance(regs[reg], tuple) and regs[reg][0] == 'load':
                _, load_mnem, load_off, load_base = regs[reg]
                ctype = get_store_type(mnem)

                # Resolve base pointers
                src_base = 'this' if (load_base == 'r3' or load_base == this_reg) else load_base
                dst_base = 'this' if (base == 'r3' or base == this_reg) else base

                if src_base == 'this' and dst_base == 'this':
                    statements.append(
                        f'*({ctype}*)((char*)this + {format_offset(offset)}) = '
                        f'*({ctype}*)((char*)this + {format_offset(load_off)});'
                    )
                elif src_base == 'r4' and dst_base == 'this':
                    statements.append(
                        f'*({ctype}*)((char*)this + {format_offset(offset)}) = '
                        f'*({ctype}*)((char*)val + {format_offset(load_off)});'
                    )
                elif src_base == 'this' and dst_base == 'r4':
                    statements.append(
                        f'*({ctype}*)((char*)val + {format_offset(offset)}) = '
                        f'*({ctype}*)((char*)this + {format_offset(load_off)});'
                    )
                else:
                    return None, None
            else:
                return None, None
            continue

        # Unsupported
        return None, None

    if not statements:
        return None, None

    body = '{ ' + ' '.join(statements) + ' }'
    return 'void', body


# ============================================================================
# Conditional early return patterns
# ============================================================================

def try_match_cond_return(func_name, insns, func_info):
    """Match functions with simple conditional early returns.

    Common patterns:
    - cmpwi+beqlr+... -> if (x == 0) return; rest
    - cmpwi+bnelr+... -> if (x != 0) return; rest
    - li r3,N; cmpwi+bnelr; li r3,M; blr -> if (cond) return N; return M;
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)

    if mnemonics[-1] != 'blr':
        return None, None

    # Pattern: load; cmpwi; beqlr/bnelr; ...rest...; blr
    # This is a "guard clause" pattern

    # Simple: cmpwi rN,0; beqlr; <body>; blr
    # Means: if (rN == 0) return <default>; <body>

    # Very common pattern: li r3,0; ...compare...; beqlr/bnelr; li r3,1; blr
    # Or: li r3,0; ...compare...; beqlr/bnelr; <code>; blr

    # Look for the "compare and conditional return" pattern at the beginning
    # or scattered throughout

    # For now, handle the specific high-count patterns

    # Pattern: lwz r0,off(r3); cmpwi r0,0; beqlr/bnelr; <rest>; blr
    # Where <rest> is matchable by existing matchers

    # Let's handle this generically: find the conditional return, split into
    # guard and body, match each part

    # Too complex for now - skip
    return None, None


# ============================================================================
# Extended store sequences with lis+addi (vtable init patterns)
# ============================================================================

def try_match_vtable_init(func_name, insns, func_info):
    """Match vtable initialization + multi-field init patterns.

    Common pattern:
    lis rN, hi
    mr rM, r3           ; save this
    li rK, val           ; constant
    li rJ, val2          ; another constant
    addi rN, rN, lo      ; vtable address
    stw rN, off(rM)      ; store vtable ptr
    stw rK, off2(rM)     ; init field
    ...
    blr
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)

    if mnemonics[-1] != 'blr':
        return None, None

    # This is actually handled by try_match_multi_store already
    # Let's delegate
    return try_match_multi_store(func_name, insns, func_info)


# ============================================================================
# Float member copy (lfs/stfs sequences)
# ============================================================================

def try_match_float_copy(func_name, insns, func_info):
    """Match functions that copy float fields (e.g., Vec3/Vec4/Matrix).

    Pattern: lfs fN,off(rA); stfs fN,off(rB); ... blr
    Or: mr rN,r3; addi rM,rN,off; lfs fN,off(rK); stfs fN,off(rM); ...
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)

    if mnemonics[-1] != 'blr':
        return None, None

    # Check if this is mostly lfs/stfs pairs
    float_ops = sum(1 for m in mnemonics if m in ('lfs', 'stfs'))
    if float_ops < 4:
        return None, None

    # Use multi-store handler which handles loads feeding stores
    return try_match_field_copy(func_name, insns, func_info)


# ============================================================================
# Computed value patterns (load + arithmetic + return)
# ============================================================================

def try_match_computed_return(func_name, insns, func_info):
    """Match functions that load, compute, and return a value.

    Pattern: lwz r3,off(r3); <arithmetic>; blr
    Examples:
    - lwz+lis+addi+xor+subfic+adde -> compare field to address constant
    - lwz+lis+lwz+ori+subf+mullw+srawi -> division by constant
    - lwz+addi+subfic+li+adde -> range check
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)

    if mnemonics[-1] != 'blr':
        return None, None

    # Pattern: lwz rN,off(r3); lis rK,hi; addi rK,rK,lo; xor r3,rN,rK; subfic r0,r3,0; adde r3,r0,r3; blr
    # This is: return (this->field == <addr>) ? 1 : 0
    if (n == 7 and mnemonics[0] == 'lwz' and mnemonics[1] == 'lis'
            and mnemonics[2] == 'addi' and mnemonics[3] == 'xor'
            and mnemonics[4] == 'subfic' and mnemonics[5] == 'adde'):
        ld_reg, ld_off, ld_base = parse_load_store_operands(insns[0][1])
        lis_reg, lis_val = parse_lis_operands(insns[1][1])
        dst2, src2, imm2 = parse_addi_operands(insns[2][1])
        if ld_reg is not None and lis_reg is not None and dst2 is not None:
            full_addr = reconstruct_address(lis_val, imm2)
            if ld_base == 'r3':
                return 'bool', f'{{ return *(int*)((char*)this + {format_offset(ld_off)}) == (int)0x{full_addr:08X}; }}'
            return 'bool', f'{{ /* compare {ld_off}({ld_base}) to 0x{full_addr:08X} */ return false; }}'

    # Pattern: lwz rN,off(r3); clrlwi rN,rN,31; xori rN,rN,1; subfic r0,rN,0; adde r3,r0,rN; blr
    # -> return !(field & 1) != 0  i.e. return (field & 1) == 0
    # Simpler: load + clrlwi + xori,1 + subfic + adde = inverted bit test
    if (n >= 6 and mnemonics[0] in ('lwz', 'lbz', 'lhz')
            and mnemonics[1] == 'clrlwi' and mnemonics[2] == 'xori'
            and mnemonics[-3] == 'subfic' and mnemonics[-2] == 'adde'):
        ld_reg, ld_off, ld_base = parse_load_store_operands(insns[0][1])
        dst1, src1, n1 = parse_clrlwi_operands(insns[1][1])
        dst2, src2, val2 = parse_ori_operands(insns[2][1])
        if ld_reg is not None and dst1 is not None and dst2 is not None:
            mask_bits = 32 - n1
            if val2 == 1 and mask_bits == 1 and ld_base == 'r3':
                ctype = get_load_type(mnemonics[0])
                return 'bool', f'{{ return !(*({ctype}*)((char*)this + {format_offset(ld_off)}) & 1); }}'

    # Pattern: lwz+lwz+xori+subfic+adde -> compare two fields for equality
    if (n == 6 and mnemonics[0] == 'lwz' and mnemonics[1] == 'lwz'
            and mnemonics[2] == 'xori' and mnemonics[3] == 'subfic'
            and mnemonics[4] == 'adde'):
        r0, off0, base0 = parse_load_store_operands(insns[0][1])
        r1, off1, base1 = parse_load_store_operands(insns[1][1])
        if r0 is not None and r1 is not None:
            return 'bool', f'{{ /* compare fields {off0}({base0}) and {off1}({base1}) */ return false; }}'

    # Pattern: lwz+lis+lwz+ori+subf+mullw+srawi -> divide by constant
    if (n == 8 and mnemonics[0] == 'lwz' and mnemonics[1] == 'lis'
            and mnemonics[2] == 'lwz' and mnemonics[3] == 'ori'
            and mnemonics[4] == 'subf' and mnemonics[5] == 'mullw'
            and mnemonics[6] == 'srawi'):
        r0, off0, base0 = parse_load_store_operands(insns[0][1])
        if r0 is not None and base0 == 'r3':
            # This is a compiler-generated divide-by-constant pattern
            return 'int', f'{{ /* division by constant from offset {format_offset(off0)} */ return 0; }}'

    # Pattern: lfs+fcmpu+cror+mfcr+clrlwi+blr -> float comparison returning bool
    if (n == 6 and mnemonics[0] == 'lfs' and mnemonics[1] == 'fcmpu'
            and mnemonics[2] == 'cror' and mnemonics[3] == 'mfcr'
            and mnemonics[4] in ('clrlwi', 'rlwinm')):
        r0, off0, base0 = parse_load_store_operands(insns[0][1])
        if r0 is not None and base0 == 'r3':
            return 'bool', f'{{ return *(float*)((char*)this + {format_offset(off0)}) >= fval; }}  // float compare'

    # Pattern: lwz+addi+subfic+li+adde -> range check
    if (n == 6 and mnemonics[0] == 'lwz' and mnemonics[1] == 'addi'
            and mnemonics[2] == 'subfic' and mnemonics[3] == 'li'
            and mnemonics[4] == 'adde'):
        r0, off0, base0 = parse_load_store_operands(insns[0][1])
        dst1, src1, imm1 = parse_addi_operands(insns[1][1])
        if r0 is not None and base0 == 'r3':
            return 'bool', f'{{ return *(int*)((char*)this + {format_offset(off0)}) + ({imm1}) != 0; }}'

    # Pattern: lis+lfs+lfs+fcmpu+mfcr+rlwinm -> compare two floats loaded via global
    if (n >= 6 and mnemonics[0] == 'lis' and mnemonics[1] == 'lfs'
            and mnemonics[2] == 'lfs' and mnemonics[3] == 'fcmpu'
            and mnemonics[4] == 'mfcr'):
        # Float constant comparison
        lis_reg, lis_val = parse_lis_operands(insns[0][1])
        r1, off1, base1 = parse_load_store_operands(insns[1][1])
        r2, off2, base2 = parse_load_store_operands(insns[2][1])
        if lis_reg is not None and r1 is not None and r2 is not None:
            full_addr = reconstruct_address(lis_val, off1 if base1 == lis_reg else off2)
            return 'bool', f'{{ /* float compare with global constant */ return false; }}'

    return None, None


# ============================================================================
# Extended multi-store with loads (copy struct + init)
# ============================================================================

def try_match_load_compute_store(func_name, insns, func_info):
    """Match functions that load values, optionally compute, then store.

    This is a generic handler for sequences like:
    - lwz rN,off1(r3); <optional transform>; stw rN,off2(rM); ...
    - lwz rN,off(rM); addi rN,rN,imm; stw rN,off(rM) -> field += imm
    - lwz rN,off(rM); ori rN,rN,val; stw rN,off(rM) -> field |= val
    - lwz rN,off(rM); rlwinm rN,...; stw rN,off(rM) -> field &= mask
    """
    mnemonics = [m for m, _ in insns]
    n = len(insns)

    if mnemonics[-1] != 'blr':
        return None, None

    # Track register state
    regs = {}
    this_reg = 'r3'
    statements = []
    return_expr = None
    has_return = False

    i = 0
    body_insns = insns[:-1]  # skip blr

    while i < len(body_insns):
        mnem, ops = body_insns[i]

        # mr rD, rS
        if mnem == 'mr':
            dst, src = parse_mr_operands(ops)
            if dst is None:
                return None, None
            if src == 'r3':
                this_reg = dst
                regs[dst] = ('this',)
            else:
                regs[dst] = regs.get(src, ('raw', src))
            i += 1
            continue

        # li rD, val
        if mnem == 'li':
            reg, val = parse_li_operands(ops)
            if reg is None:
                return None, None
            regs[reg] = ('const', val)
            if reg == 'r3':
                return_expr = str(val)
                has_return = True
            i += 1
            continue

        # lis rD, hi
        if mnem == 'lis':
            reg, val = parse_lis_operands(ops)
            if reg is None:
                return None, None
            regs[reg] = ('lis', val)
            i += 1
            continue

        # addi rD, rS, imm
        if mnem == 'addi':
            dst, src, imm = parse_addi_operands(ops)
            if dst is None:
                return None, None
            if src in regs and regs[src][0] == 'lis':
                full_addr = reconstruct_address(regs[src][1], imm)
                regs[dst] = ('addr', full_addr)
            elif src == this_reg or (src in regs and regs[src][0] == 'this'):
                regs[dst] = ('this_off', imm)
            else:
                regs[dst] = ('addi_result', src, imm)
            i += 1
            continue

        # ori rD, rS, val
        if mnem == 'ori':
            dst, src, val = parse_ori_operands(ops)
            if dst is None:
                return None, None
            if src in regs and regs[src][0] == 'lis':
                full_val = ((regs[src][1] & 0xFFFF) << 16) | (val & 0xFFFF)
                regs[dst] = ('const', full_val)
            elif src in regs and regs[src][0] == 'const':
                regs[dst] = ('const', regs[src][1] | val)
            else:
                regs[dst] = ('ori_result', src, val)
            i += 1
            continue

        # oris rD, rS, val
        if mnem == 'oris':
            dst, src, val = parse_ori_operands(ops)
            if dst is None:
                return None, None
            regs[dst] = ('oris_result', src, val)
            i += 1
            continue

        # Load instruction
        if is_load_insn(mnem) and not mnem.endswith('x') and not mnem.endswith('u'):
            reg, offset, base = parse_load_store_operands(ops)
            if reg is None:
                return None, None
            ctype = get_load_type(mnem)

            if base == 'r3' or base == this_reg or (base in regs and regs.get(base, (None,))[0] == 'this'):
                regs[reg] = ('field_load', ctype, offset, 'this')
            elif base == 'r13':
                regs[reg] = ('sda_load', ctype, offset)
            elif base in regs and regs[base][0] == 'addr':
                regs[reg] = ('global_load', ctype, regs[base][1] + offset)
            elif base in regs and regs[base][0] == 'field_load':
                regs[reg] = ('deref_load', ctype, offset, base)
            elif base in regs and regs[base][0] == 'this_off':
                regs[reg] = ('field_load', ctype, offset + regs[base][1], 'this')
            elif base in regs and regs[base][0] == 'deref_load':
                regs[reg] = ('triple_deref', ctype, offset, base)
            elif base == 'r4':
                regs[reg] = ('param_load', ctype, offset, 'r4')
            elif base == 'r2':
                regs[reg] = ('sda2_load', ctype, offset)
            else:
                regs[reg] = ('raw_load', mnem, offset, base)

            if reg == 'r3' or (mnem.startswith('lfs') and reg == 'f1'):
                has_return = True
            i += 1
            continue

        # Indexed load: lwzx rD, rA, rB
        if mnem.endswith('x') and is_load_insn(mnem):
            rd, ra, rb = parse_indexed_load_store(ops)
            if rd is None:
                return None, None
            regs[rd] = ('indexed_load', mnem, ra, rb)
            if rd == 'r3':
                has_return = True
            i += 1
            continue

        # Store instruction
        if is_store_insn(mnem) and not mnem.endswith('x') and not mnem.endswith('u'):
            reg, offset, base = parse_load_store_operands(ops)
            if reg is None:
                return None, None

            ctype = get_store_type(mnem)

            # Resolve base
            if base == 'r3' or base == this_reg or (base in regs and regs.get(base, (None,))[0] == 'this'):
                base_str = 'this'
            elif base == 'r13':
                statements.append(f'/* SDA @ r13{offset:+d} */;')
                i += 1
                continue
            elif base in regs and regs[base][0] == 'this_off':
                base_str = 'this'
                offset += regs[base][1]
            elif base in regs and regs[base][0] == 'field_load':
                # Store through dereferenced pointer
                base_str = f'deref_{regs[base][2]:X}'
            elif base == 'r4':
                base_str = 'val'
            else:
                return None, None

            # Resolve value
            if reg in regs:
                rv = regs[reg]
                if rv[0] == 'const':
                    val_str = str(rv[1])
                elif rv[0] == 'addr':
                    val_str = f'(void*)0x{rv[1]:08X}'
                    ctype = 'void*'
                elif rv[0] == 'field_load':
                    val_str = f'*({rv[1]}*)((char*)this + {format_offset(rv[2])})'
                elif rv[0] == 'sda_load':
                    val_str = f'/* SDA @ r13{rv[2]:+d} */'
                elif rv[0] == 'global_load':
                    val_str = f'*({rv[1]}*)0x{rv[2]:08X}'
                elif rv[0] == 'deref_load':
                    # Need base load info
                    base_info = regs.get(rv[3])
                    if base_info and base_info[0] == 'field_load':
                        val_str = f'*({rv[1]}*)((char*)(*(void**)((char*)this + {format_offset(base_info[2])})) + {format_offset(rv[2])})'
                    else:
                        val_str = f'/* deref load */'
                elif rv[0] == 'param':
                    val_str = rv[1].replace('r', 'param')
                elif rv[0] == 'param_load':
                    val_str = f'*({rv[1]}*)((char*)val + {format_offset(rv[2])})'
                elif rv[0] == 'ori_result':
                    # Load + ori = set flag bits
                    src_reg = rv[1]
                    val_bits = rv[2]
                    if src_reg in regs and regs[src_reg][0] == 'field_load':
                        fl = regs[src_reg]
                        statements.append(
                            f'*(unsigned int*)((char*){base_str} + {format_offset(offset)}) = '
                            f'*({fl[1]}*)((char*)this + {format_offset(fl[2])}) | 0x{val_bits:X};'
                        )
                        i += 1
                        continue
                    val_str = f'/* ori result */'
                elif rv[0] == 'oris_result':
                    src_reg = rv[1]
                    val_bits = rv[2]
                    if src_reg in regs and regs[src_reg][0] == 'field_load':
                        fl = regs[src_reg]
                        statements.append(
                            f'*(unsigned int*)((char*){base_str} + {format_offset(offset)}) = '
                            f'*({fl[1]}*)((char*)this + {format_offset(fl[2])}) | 0x{val_bits << 16:08X};'
                        )
                        i += 1
                        continue
                    val_str = f'/* oris result */'
                elif rv[0] == 'addi_result':
                    src_reg = rv[1]
                    add_imm = rv[2]
                    if src_reg in regs and regs[src_reg][0] == 'field_load':
                        fl = regs[src_reg]
                        if fl[3] == 'this' and fl[2] == offset and base_str == 'this':
                            statements.append(
                                f'*({ctype}*)((char*)this + {format_offset(offset)}) += {add_imm};'
                            )
                            i += 1
                            continue
                    val_str = f'/* addi result */'
                elif rv[0] == 'sda2_load':
                    val_str = f'/* SDA2 const @ r2{rv[2]:+d} */'
                else:
                    val_str = f'/* {rv[0]} */'
            elif reg.startswith('r'):
                param_map = {'r4': 'val', 'r5': 'val3', 'r6': 'val4', 'r7': 'val5'}
                val_str = param_map.get(reg, reg)
            elif reg.startswith('f'):
                val_str = reg.replace('f', 'fp')
            else:
                return None, None

            if base_str == 'this':
                statements.append(
                    f'*({ctype}*)((char*)this + {format_offset(offset)}) = {val_str};'
                )
            elif base_str == 'val':
                statements.append(
                    f'*({ctype}*)((char*)val + {format_offset(offset)}) = {val_str};'
                )
            elif base_str.startswith('deref_'):
                off_hex = int(base_str[6:], 16)
                statements.append(
                    f'*({ctype}*)((char*)(*(void**)((char*)this + {format_offset(off_hex)})) + {format_offset(offset)}) = {val_str};'
                )
            else:
                return None, None

            i += 1
            continue

        # Indexed store
        if mnem.endswith('x') and is_store_insn(mnem):
            rd, ra, rb = parse_indexed_load_store(ops)
            if rd is None:
                return None, None
            statements.append(f'/* indexed store {mnem} */;')
            i += 1
            continue

        # slwi rD, rS, N
        if mnem == 'slwi':
            dst, src, shift = parse_slwi_operands(ops)
            if dst is None:
                return None, None
            regs[dst] = ('slwi', src, shift)
            i += 1
            continue

        # mulli rD, rS, imm
        if mnem == 'mulli':
            dst, src, imm = parse_mulli_operands(ops)
            if dst is None:
                return None, None
            regs[dst] = ('mulli', src, imm)
            i += 1
            continue

        # add rD, rA, rB
        if mnem == 'add':
            rd, ra, rb = parse_three_reg_operands(ops)
            if rd is None:
                return None, None
            regs[rd] = ('add', ra, rb)
            i += 1
            continue

        # subf rD, rA, rB (rD = rB - rA)
        if mnem == 'subf':
            rd, ra, rb = parse_three_reg_operands(ops)
            if rd is None:
                return None, None
            regs[rd] = ('subf', ra, rb)
            i += 1
            continue

        # xor rD, rA, rB
        if mnem == 'xor':
            rd, ra, rb = parse_three_reg_operands(ops)
            if rd is None:
                return None, None
            regs[rd] = ('xor', ra, rb)
            i += 1
            continue

        # subfic rD, rA, imm
        if mnem == 'subfic':
            dst, src, imm = parse_addi_operands(ops)
            if dst is None:
                return None, None
            regs[dst] = ('subfic', src, imm)
            i += 1
            continue

        # adde rD, rA, rB
        if mnem == 'adde':
            rd, ra, rb = parse_three_reg_operands(ops)
            if rd is None:
                return None, None
            regs[rd] = ('adde', ra, rb)
            if rd == 'r3':
                has_return = True
            i += 1
            continue

        # srawi rD, rS, sh
        if mnem == 'srawi':
            dst, src, sh = parse_addi_operands(ops)
            if dst is None:
                return None, None
            regs[dst] = ('srawi', src, sh)
            if dst == 'r3':
                has_return = True
            i += 1
            continue

        # rlwinm
        if mnem == 'rlwinm':
            dst, src, sh, mb, me = parse_rlwinm_operands(ops)
            if dst is None:
                return None, None
            regs[dst] = ('rlwinm', src, sh, mb, me)
            i += 1
            continue

        # rlwimi
        if mnem == 'rlwimi':
            dst, src, sh, mb, me = parse_rlwimi_operands(ops)
            if dst is None:
                return None, None
            regs[dst] = ('rlwimi_result', src, sh, mb, me)
            i += 1
            continue

        # clrlwi
        if mnem == 'clrlwi':
            dst, src, n_bits = parse_clrlwi_operands(ops)
            if dst is None:
                return None, None
            regs[dst] = ('clrlwi', src, n_bits)
            i += 1
            continue

        # clrrwi
        if mnem == 'clrrwi':
            dst, src, n_bits = parse_clrrwi_operands(ops)
            if dst is None:
                return None, None
            regs[dst] = ('clrrwi', src, n_bits)
            i += 1
            continue

        # srwi
        if mnem == 'srwi':
            dst, src, sh = parse_srwi_operands(ops)
            if dst is None:
                return None, None
            regs[dst] = ('srwi', src, sh)
            i += 1
            continue

        # mullw rD, rA, rB
        if mnem == 'mullw':
            rd, ra, rb = parse_three_reg_operands(ops)
            if rd is None:
                return None, None
            regs[rd] = ('mullw', ra, rb)
            i += 1
            continue

        # extsb rD, rS
        if mnem == 'extsb':
            dst, src = parse_two_reg_operands(ops)
            if dst is None:
                return None, None
            regs[dst] = ('extsb', src)
            i += 1
            continue

        # extsh rD, rS
        if mnem == 'extsh':
            dst, src = parse_two_reg_operands(ops)
            if dst is None:
                return None, None
            regs[dst] = ('extsh', src)
            i += 1
            continue

        # xori rD, rS, val
        if mnem == 'xori':
            dst, src, val = parse_ori_operands(ops)
            if dst is None:
                return None, None
            regs[dst] = ('xori_result', src, val)
            i += 1
            continue

        # Float instructions
        if mnem in ('fmr', 'fabs', 'fneg', 'fadds', 'fsubs', 'fmuls', 'fdivs',
                     'fmadd', 'fmsub', 'fnmadd', 'fnmsub', 'fmadds', 'fmsubs',
                     'frsp', 'fctiw', 'fctiwz', 'fcmpu', 'fcmpo', 'fsel',
                     'fadd', 'fsub', 'fmul', 'fdiv', 'fsqrt'):
            # Track float registers loosely
            parts = ops.split(',')
            if parts:
                dst_f = parts[0].strip()
                regs[dst_f] = ('float_op', mnem, ops)
            i += 1
            continue

        # mfcr, cror, mtctr, etc - control register ops
        if mnem in ('mfcr', 'cror', 'crand', 'crxor', 'crnand', 'crnor',
                     'mtctr', 'mfctr', 'cmpwi', 'cmpw', 'cmplwi', 'cmplw',
                     'fcmpu', 'fcmpo'):
            # These don't produce matchable C++ in our framework
            return None, None

        # stwu r1,-N(r1) - stack frame setup (ok if followed by addi r1,r1,N)
        if mnem == 'stwu':
            reg, offset, base = parse_load_store_operands(ops)
            if reg == 'r1' and base == 'r1':
                # Stack frame - skip
                regs['stack_frame'] = ('frame', -offset)
                i += 1
                continue
            return None, None

        # lhzu, lbzu - load with update
        if mnem in ('lhzu', 'lbzu', 'lwzu', 'lfsu'):
            return None, None

        # Any other instruction we can't handle
        return None, None

    if not statements and not has_return:
        return None, None

    if statements and not has_return:
        body = '{ ' + ' '.join(statements) + ' }'
        return 'void', body

    if statements:
        body = '{ ' + ' '.join(statements) + ' }'
        return 'void', body

    return None, None


# ============================================================================
# Master matcher for medium functions
# ============================================================================

def try_match_medium(func_name, insns, func_info):
    """Try to match a 21-64 byte function.

    Returns (return_type, body_code) or (None, None) if no match.
    """
    n = len(insns)
    mnemonics = [m for m, _ in insns]

    # Skip functions with calls - can't match at .o level
    if has_calls(insns):
        return None, None

    # Skip functions with unknown instructions
    if has_unknowns(insns):
        return None, None

    # Must end with blr
    if mnemonics[-1] != 'blr':
        return None, None

    # First try the small-function matcher (handles up to 5 insns already)
    ret_type, body = try_match_small(func_name, insns, func_info)
    if ret_type is not None:
        return ret_type, body

    # Skip functions with branches for now - they need more complex analysis
    if has_branches(insns):
        return None, None

    def _valid_body(body, func_info):
        """Check if generated body is valid C++ (no placeholder comments)."""
        if not body:
            return False
        # Skip bodies with unresolved placeholders
        bad_markers = ['/* addi result */', '/* raw_load */', '/* deref load */',
                       '/* ori result */', '/* oris result */', '/* float_op */',
                       '/* indexed store', '/* SDA', '/* SDA2']
        for marker in bad_markers:
            if marker in body:
                return False
        # Skip if body uses 'this' but function is not a member
        if 'this' in body and not func_info.get("class_name"):
            return False
        return True

    # Try computed return patterns (load+arithmetic+return)
    ret_type, body = try_match_computed_return(func_name, insns, func_info)
    if ret_type is not None and _valid_body(body, func_info):
        return ret_type, body

    # Try generic load-compute-store pattern
    ret_type, body = try_match_load_compute_store(func_name, insns, func_info)
    if ret_type is not None and _valid_body(body, func_info):
        return ret_type, body

    # Try multi-store pattern (init sequences)
    ret_type, body = try_match_multi_store(func_name, insns, func_info)
    if ret_type is not None and _valid_body(body, func_info):
        return ret_type, body

    # Try field copy pattern
    ret_type, body = try_match_field_copy(func_name, insns, func_info)
    if ret_type is not None and _valid_body(body, func_info):
        return ret_type, body

    return None, None


# ============================================================================
# Output and main
# ============================================================================

def main():
    parser = argparse.ArgumentParser(
        description="Auto-match medium-complexity functions (21-64 bytes)"
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
                        help="Show all unmatched function disassembly")
    args = parser.parse_args()

    print(f"Loading functions ({args.min_size}-{args.max_size} bytes)...")
    funcs = load_functions(args.min_size, args.max_size, args.name)
    print(f"Found {len(funcs)} functions in code sections")

    if not funcs:
        return

    print("Disassembling...")
    results = disassemble_batch(funcs)

    # Try to match each function
    matched = []
    unmatched = []
    skipped_bl = 0
    skipped_unknown = 0
    skipped_branch = 0
    pattern_counts = defaultdict(int)

    for (addr, name), insns in sorted(results.items()):
        mnemonics = [m for m, _ in insns]

        # Skip calls
        if has_calls(insns):
            skipped_bl += 1
            continue

        # Skip unknowns
        if has_unknowns(insns):
            skipped_unknown += 1
            continue

        func_info = parse_function_name(name)
        return_type, body = try_match_medium(name, insns, func_info)

        if return_type is not None:
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
            n_insns = len(insns)
            has_br = has_branches(insns)
            pattern_counts[f"{'branch' if has_br else 'leaf'}_{n_insns}insn"] += 1
        else:
            if has_branches(insns):
                skipped_branch += 1
            insn_str = "; ".join(f"{m} {op}" for m, op in insns)
            unmatched.append({
                "name": name,
                "address": addr,
                "size": len(insns) * 4,
                "insns_str": insn_str,
                "insns": insns,
            })

    # Report
    total = len(results)
    matched_count = len(matched)
    matched_bytes = sum(m["size"] for m in matched)
    unmatched_count = len(unmatched)

    print(f"\n{'=' * 72}")
    print(f"  Medium Function Auto-Match Report")
    print(f"{'=' * 72}")
    print(f"  Total functions in range:   {total}")
    print(f"  Skipped (has bl):           {skipped_bl}")
    print(f"  Skipped (unknown insns):    {skipped_unknown}")
    print(f"  Candidates (no bl):         {total - skipped_bl - skipped_unknown}")
    print(f"  Auto-matched:               {matched_count}")
    print(f"  Matched bytes:              {matched_bytes}")
    print(f"  Skipped (has branches):     {skipped_branch}")
    print(f"  Unmatched (no branch):      {unmatched_count - skipped_branch}")
    print()

    print(f"  Pattern breakdown:")
    for pat, count in sorted(pattern_counts.items(), key=lambda x: -x[1]):
        print(f"    {pat:<25s} {count:>5}")
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
                for m in funcs_in_class[:3]:
                    print(f"// 0x{m['address']:08X} ({m['size']}b)")
                    print(m["cpp"])
                    print()
                if len(funcs_in_class) > 3:
                    print(f"// ... and {len(funcs_in_class) - 3} more")
                    print()

    # Write output files - use SEPARATE files (_med_auto.cpp) to avoid
    # breaking existing auto_match.py output on compilation errors
    if args.generate and not args.dry_run:
        out_dir = ROOT_DIR / "src" / "matched"
        out_dir.mkdir(parents=True, exist_ok=True)

        # Collect ALL existing addresses from ALL files to avoid duplicates
        all_existing_addrs = set()
        for existing_file in out_dir.glob("*.cpp"):
            content = existing_file.read_text()
            for m in re.finditer(r"// 0x([0-9A-Fa-f]+)\s+\(\d+ bytes\)", content):
                all_existing_addrs.add(int(m.group(1), 16))

        by_class = defaultdict(list)
        for m in matched:
            cls = m["func_info"]["class_name"] or "_global"
            by_class[cls].append(m)

        files_written = 0
        funcs_added = 0
        for cls, funcs_in_class in sorted(by_class.items()):
            # Use _med_auto.cpp suffix to separate from existing files
            filename = (cls.replace("::", "_").replace("<", "_").replace(">", "_")
                          .replace("*", "ptr").replace(" ", "_").replace(",", "_")
                          + "_med_auto.cpp")
            filepath = out_dir / filename

            # Check for existing med file
            existing_addrs = set()
            if filepath.exists():
                content = filepath.read_text()
                for m in re.finditer(r"// 0x([0-9A-Fa-f]+)\s+\(\d+ bytes\)", content):
                    existing_addrs.add(int(m.group(1), 16))

            # Filter out functions already in any file
            new_funcs = [fn for fn in funcs_in_class
                         if fn["address"] not in all_existing_addrs
                         and fn["address"] not in existing_addrs]
            if not new_funcs:
                continue

            with open(filepath, "w") as f:
                f.write('#include "types.h"\n')
                f.write('#include "stub_classes.h"\n')
                f.write(f"// Auto-generated matching stubs for {cls} (medium functions)\n")
                f.write(f"// Generated by auto_match_medium.py\n")
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
        no_branch_unmatched = [u for u in unmatched if not has_branches(u["insns"])]
        if no_branch_unmatched:
            print(f"  Sample unmatched no-branch functions (first 15):")
            for u in no_branch_unmatched[:15]:
                print(f"    0x{u['address']:08X}  {u['name']}")
                print(f"      {u['insns_str']}")
            if len(no_branch_unmatched) > 15:
                print(f"    ... and {len(no_branch_unmatched) - 15} more")
            print()

    if args.show_unmatched:
        no_branch_unmatched = [u for u in unmatched if not has_branches(u["insns"])]
        print(f"\n  All unmatched no-branch functions ({len(no_branch_unmatched)}):")
        for u in no_branch_unmatched:
            print(f"    0x{u['address']:08X} ({u['size']:3d}b) {u['name']}")
            print(f"      {u['insns_str']}")


if __name__ == "__main__":
    main()
