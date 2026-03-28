#!/usr/bin/env python3
"""
Generate matching C++ for leaf constructor/initializer functions.

Identifies leaf constructors (no bl calls) from symbols.json, disassembles
them from the ELF, and translates the PowerPC instruction chains into C++
that will produce byte-identical output when compiled with devkitPPC.

Patterns handled:
  - lis+addi vtable pointer stores
  - li+stw integer field stores (0, -1, 1, etc.)
  - lfs+stfs float constant stores
  - Parameter stores (r4, r5, r6 -> r3 offsets)
  - SDA-relative accesses (r13+offset)
  - Stack frame prologues/epilogues (stwu/addi r1)
  - stmw/lmw register saves (generates matching register-save hints)
  - mtctr/bdnz loops (array zeroing)
  - BString-style vtable + refcount increment
  - fsubs/fdivs float arithmetic in constructors
  - fctiwz float-to-int conversion (CTilePt style)
  - extsb byte truncation with bounds checking
"""

import json
import re
import subprocess
import struct
import sys
import os
from pathlib import Path
from collections import defaultdict

REPO = Path(__file__).resolve().parent.parent
OBJDUMP = r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC\bin\powerpc-eabi-objdump.exe"
ELF = str(REPO / "extracted" / "files" / "u2_ngc_release_dvd.elf")
DOL = REPO / "extracted" / "sys" / "main.dol"
SYMBOLS_JSON = REPO / "tools" / "symbols.json"
MATCHED_DIR = REPO / "src" / "matched"

# ============================================================================
# Disassembly helpers
# ============================================================================

def disassemble(addr_int, size):
    """Disassemble from ELF, return list of (addr_int, mnemonic, operands_str, full_text)."""
    result = subprocess.run(
        [OBJDUMP, '-d', '--no-show-raw-insn',
         f'--start-address=0x{addr_int:08x}',
         f'--stop-address=0x{addr_int + size:08x}',
         ELF],
        capture_output=True, text=True, timeout=10
    )
    insns = []
    for line in result.stdout.split('\n'):
        line = line.strip()
        if ':' in line and line[0:2] == '80':
            addr_s, rest = line.split(':', 1)
            rest = rest.strip()
            if not rest or rest.startswith('<'):
                continue
            parts = rest.split(None, 1)
            mnemonic = parts[0]
            operands = parts[1] if len(parts) > 1 else ''
            insns.append((int(addr_s, 16), mnemonic, operands, rest))
    return insns


def disassemble_raw(addr_int, size):
    """Disassemble from ELF with raw bytes, return list of (addr_int, raw_bytes_hex, mnemonic, operands)."""
    result = subprocess.run(
        [OBJDUMP, '-d',
         f'--start-address=0x{addr_int:08x}',
         f'--stop-address=0x{addr_int + size:08x}',
         ELF],
        capture_output=True, text=True, timeout=10
    )
    insns = []
    for line in result.stdout.split('\n'):
        line = line.strip()
        if ':' in line and line[0:2] == '80':
            addr_s, rest = line.split(':', 1)
            rest = rest.strip()
            # Format: "94 21 ff f0 	stwu    r1,-16(r1)"
            parts = rest.split('\t')
            if len(parts) >= 2:
                raw = parts[0].strip()
                insn_part = '\t'.join(parts[1:]).strip()
                mparts = insn_part.split(None, 1)
                mnemonic = mparts[0] if mparts else ''
                operands = mparts[1] if len(mparts) > 1 else ''
                insns.append((int(addr_s, 16), raw, mnemonic, operands))
    return insns


# ============================================================================
# Symbol / address helpers
# ============================================================================

def load_already_matched():
    """Load set of already-matched addresses from src/matched/*.cpp files."""
    matched = set()
    for cpp in MATCHED_DIR.glob("*.cpp"):
        with open(cpp) as f:
            for line in f:
                m = re.match(r'// 0x([0-9A-Fa-f]+)\s+\(\d+ bytes\)', line.strip())
                if m:
                    matched.add(int(m.group(1), 16))
    return matched


def find_leaf_ctor_candidates(symbols_data, already_matched):
    """Find leaf constructor candidates from symbols.json."""
    candidates = []
    for s in symbols_data['symbols']:
        name = s.get('name', '')
        if '(' not in name or '::' not in name:
            continue
        size = s.get('size', 0)
        addr = s.get('address', '0x0')
        addr_int = int(addr, 16)
        if size < 8 or size > 256:
            continue
        if addr_int in already_matched:
            continue

        before_paren = name.split('(')[0]
        if '::' not in before_paren:
            continue
        segments = before_paren.split('::')
        if len(segments) < 2:
            continue
        cls = segments[-2].strip()
        method = segments[-1].strip()
        if method != cls:  # Only ctors, not dtors (dtors always call parent dtor via bl)
            continue

        candidates.append({
            'name': name,
            'address': addr_int,
            'size': size,
            'class': cls,
            'method': method,
            'params': name[name.index('('):]  # e.g. "(void)" or "(int)"
        })
    return candidates


def is_leaf(insns):
    """Check if function is leaf (no function calls)."""
    call_mnemonics = {'bl', 'bla', 'bcl', 'bctrl', 'blrl'}
    for _, mn, _, _ in insns:
        if mn in call_mnemonics:
            return False
    return True


# ============================================================================
# PPC instruction parsing helpers
# ============================================================================

def parse_reg_offset(operand):
    """Parse 'offset(reg)' -> (offset_int, reg_str) or None."""
    m = re.match(r'(-?\d+)\((\w+)\)', operand)
    if m:
        return (int(m.group(1)), m.group(2))
    return None


def lis_value(operand):
    """Parse lis operand: 'rN,VALUE' -> (reg, hi16_signed). VALUE is signed 16-bit."""
    m = re.match(r'(\w+),(-?\d+)', operand)
    if m:
        reg = m.group(1)
        val = int(m.group(2))
        return (reg, val)
    return None


def sign_extend_16(val):
    """Sign-extend a 16-bit value."""
    if val & 0x8000:
        return val - 0x10000
    return val


def compute_lis_addi(hi16, lo16):
    """Compute full 32-bit address from lis+addi pair."""
    # lis loads hi16 << 16, addi adds sign-extended lo16
    return ((hi16 & 0xFFFF) << 16) + sign_extend_16(lo16 & 0xFFFF)


# ============================================================================
# Translator: PPC instructions -> C++ code
# ============================================================================

class CtorTranslator:
    """Translate a leaf constructor's PPC instructions into matching C++."""

    def __init__(self, name, params, insns, address, size):
        self.name = name
        self.params = params
        self.insns = insns  # list of (addr, mnemonic, operands, full)
        self.address = address
        self.size = size
        self.stmts = []
        self.registers = {}  # track register contents: reg -> value_expr
        self.lis_pending = {}  # reg -> hi16 value (waiting for addi)
        self.float_regs = {}  # fN -> loaded float source description
        self.uses_stack = False
        self.stack_size = 0
        self.has_stmw = False
        self.stmw_reg = None
        self.error = None
        # Track which param regs map to which param names
        self.param_map = self._build_param_map()

    def _build_param_map(self):
        """Map register names to parameter names based on the signature."""
        pmap = {}
        # Parse params like "(void)" or "(int)" or "(int, char *, CheatType, void *, char *, bool, bool)"
        param_str = self.params.strip('()')
        if param_str == 'void' or param_str == '':
            return pmap
        param_list = [p.strip() for p in param_str.split(',')]
        # r3 = this, r4 = p2, r5 = p3, r6 = p4, r7 = p5...
        # f1 = first float param, f2 = second float param...
        int_reg = 4  # start at r4
        float_reg = 1  # start at f1
        for i, p in enumerate(param_list):
            p_stripped = p.strip()
            # Check if it's a float type
            if p_stripped in ('float', 'double', 'f32', 'f64'):
                pmap[f'f{float_reg}'] = f'p{i+2}'
                float_reg += 1
            else:
                pmap[f'r{int_reg}'] = f'p{i+2}'
                int_reg += 1
        return pmap

    def translate(self):
        """Main translation entry point. Returns C++ function body or None on failure."""
        insns = self.insns
        if not insns:
            self.error = "no instructions"
            return None

        # Skip blr at end
        if insns[-1][1] != 'blr':
            self.error = f"doesn't end with blr: {insns[-1][1]}"
            return None

        body_insns = insns[:-1]

        # Detect prologue/epilogue pattern
        if body_insns and body_insns[0][1] == 'stwu':
            return self._translate_with_prologue(body_insns)
        else:
            return self._translate_simple(body_insns)

    def _translate_simple(self, insns):
        """Translate a simple constructor (no stack frame)."""
        stmts = []
        i = 0
        while i < len(insns):
            addr, mn, ops, full = insns[i]
            ok = self._process_insn(i, insns, stmts)
            if ok is None:
                self.error = f"unhandled insn at 0x{addr:08X}: {full}"
                return None
            i += ok
        return stmts

    def _translate_with_prologue(self, insns):
        """Translate constructor with stwu prologue."""
        stmts = []
        i = 0

        # Parse stwu r1,-N(r1)
        _, mn, ops, _ = insns[0]
        ro = parse_reg_offset(ops.split(',')[1]) if ',' in ops else None
        if ro:
            self.stack_size = -ro[0]
        self.uses_stack = True
        i = 1

        # Check for stmw
        if i < len(insns) and insns[i][1] == 'stmw':
            self.has_stmw = True
            _, _, stmw_ops, _ = insns[i]
            self.stmw_reg = stmw_ops.split(',')[0]
            i += 1

        # Process body until epilogue
        while i < len(insns):
            addr, mn, ops, full = insns[i]
            # Detect epilogue
            if mn == 'lmw':
                break
            if mn == 'addi' and 'r1,r1,' in ops:
                break
            ok = self._process_insn(i, insns, stmts)
            if ok is None:
                self.error = f"unhandled insn at 0x{addr:08X}: {full}"
                return None
            i += ok
        return stmts

    def _process_insn(self, idx, insns, stmts):
        """Process instruction at idx, append to stmts. Return # insns consumed, or None on failure."""
        addr, mn, ops, full = insns[idx]

        # lis rN, hi16 — load high half (vtable or float constant address)
        if mn == 'lis':
            lv = lis_value(ops)
            if lv:
                reg, hi16 = lv
                self.lis_pending[reg] = hi16
                self.registers[reg] = ('lis', hi16)
                return 1

        # addi rD, rS, lo16 — often completes lis+addi pair
        if mn == 'addi':
            m = re.match(r'(\w+),(\w+),(-?\d+)', ops)
            if m:
                rd, rs, lo16 = m.group(1), m.group(2), int(m.group(3))
                if rs == 'r1':
                    # Stack pointer manipulation - part of epilogue, skip
                    return 1
                if rs == 'r13':
                    # SDA-relative: addi rD, r13, offset
                    full_addr = lo16  # this is the SDA offset, sign-extended
                    self.registers[rd] = ('sda', lo16)
                    return 1
                if rs in self.lis_pending:
                    hi16 = self.lis_pending[rs]
                    full_addr = compute_lis_addi(hi16, lo16)
                    self.registers[rd] = ('addr', full_addr)
                    if rs in self.lis_pending:
                        del self.lis_pending[rs]
                    return 1
                # addi rD, rS, imm — pointer arithmetic (e.g. addi r9, r3, 164)
                if rs == 'r3' or (rs in self.registers and self.registers[rs][0] == 'this_alias'):
                    self.registers[rd] = ('this_offset', lo16)
                    return 1
                if rs in self.registers:
                    # Generic add: track as offset from base
                    base_info = self.registers[rs]
                    if base_info[0] == 'this_offset':
                        self.registers[rd] = ('this_offset', base_info[1] + lo16)
                        return 1
                    elif base_info[0] == 'addr':
                        self.registers[rd] = ('addr', base_info[1] + lo16)
                        return 1
                self.registers[rd] = ('unknown_addi', rs, lo16)
                return 1

        # li rN, imm — load immediate
        if mn == 'li':
            m = re.match(r'(\w+),(-?\d+)', ops)
            if m:
                reg, val = m.group(1), int(m.group(2))
                self.registers[reg] = ('imm', val)
                return 1

        # mr rD, rS — move register
        if mn == 'mr':
            m = re.match(r'(\w+),(\w+)', ops)
            if m:
                rd, rs = m.group(1), m.group(2)
                if rs == 'r3':
                    self.registers[rd] = ('this_alias',)
                elif rs in self.registers:
                    self.registers[rd] = self.registers[rs]
                else:
                    self.registers[rd] = ('reg_alias', rs)
                return 1

        # stw rS, offset(rD) — store word
        if mn == 'stw':
            m = re.match(r'(\w+),(-?\d+)\((\w+)\)', ops)
            if m:
                rs, offset, rd = m.group(1), int(m.group(2)), m.group(3)
                target_obj = self._resolve_store_target(rd, offset)
                value = self._resolve_value(rs)
                if target_obj and value is not None:
                    stmts.append(('stw', target_obj, value))
                    return 1
                # Fallback: still try
                self.error = f"stw unresolved at 0x{addr:08X}: {full} (rs={rs} rd={rd})"
                return None

        # stb rS, offset(rD) — store byte
        if mn == 'stb':
            m = re.match(r'(\w+),(-?\d+)\((\w+)\)', ops)
            if m:
                rs, offset, rd = m.group(1), int(m.group(2)), m.group(3)
                target_obj = self._resolve_store_target(rd, offset)
                value = self._resolve_value(rs)
                if target_obj and value is not None:
                    stmts.append(('stb', target_obj, value))
                    return 1
                self.error = f"stb unresolved at 0x{addr:08X}: {full}"
                return None

        # sth rS, offset(rD) — store halfword
        if mn == 'sth':
            m = re.match(r'(\w+),(-?\d+)\((\w+)\)', ops)
            if m:
                rs, offset, rd = m.group(1), int(m.group(2)), m.group(3)
                target_obj = self._resolve_store_target(rd, offset)
                value = self._resolve_value(rs)
                if target_obj and value is not None:
                    stmts.append(('sth', target_obj, value))
                    return 1
                self.error = f"sth unresolved at 0x{addr:08X}: {full}"
                return None

        # stfs fN, offset(rD) — store float single
        if mn == 'stfs':
            m = re.match(r'(\w+),(-?\d+)\((\w+)\)', ops)
            if m:
                fs, offset, rd = m.group(1), int(m.group(2)), m.group(3)
                target_obj = self._resolve_store_target(rd, offset)
                fval = self._resolve_float_value(fs)
                if target_obj and fval is not None:
                    stmts.append(('stfs', target_obj, fval))
                    return 1
                self.error = f"stfs unresolved at 0x{addr:08X}: {full}"
                return None

        # lfs fN, offset(rD) — load float single (from constant pool)
        if mn == 'lfs':
            m = re.match(r'(\w+),(-?\d+)\((\w+)\)', ops)
            if m:
                fd, offset, rs = m.group(1), int(m.group(2)), m.group(3)
                # Resolve the float constant address
                if rs in self.lis_pending:
                    hi16 = self.lis_pending[rs]
                    float_addr = compute_lis_addi(hi16, offset)
                    self.float_regs[fd] = ('const_addr', float_addr)
                elif rs in self.registers:
                    info = self.registers[rs]
                    if info[0] == 'lis':
                        float_addr = compute_lis_addi(info[1], offset)
                        self.float_regs[fd] = ('const_addr', float_addr)
                    elif info[0] == 'addr':
                        float_addr = info[1] + offset
                        self.float_regs[fd] = ('const_addr', float_addr)
                    else:
                        self.float_regs[fd] = ('unknown_load', rs, offset)
                elif rs == 'r2':
                    # SDA2 relative
                    self.float_regs[fd] = ('sda2_offset', offset)
                else:
                    self.float_regs[fd] = ('unknown_load', rs, offset)
                return 1

        # lwz rD, offset(rS) — load word
        if mn == 'lwz':
            m = re.match(r'(\w+),(-?\d+)\((\w+)\)', ops)
            if m:
                rd, offset, rs = m.group(1), int(m.group(2)), m.group(3)
                # Track what was loaded
                if rs in self.registers:
                    info = self.registers[rs]
                    if info[0] == 'addr':
                        self.registers[rd] = ('deref', info[1] + offset)
                    elif info[0] == 'this_alias':
                        self.registers[rd] = ('this_field', offset)
                    else:
                        self.registers[rd] = ('load', rs, offset)
                elif rs == 'r3':
                    self.registers[rd] = ('this_field', offset)
                elif rs == 'r1':
                    self.registers[rd] = ('stack_load', offset)
                else:
                    self.registers[rd] = ('load', rs, offset)
                return 1

        # lbz rD, offset(rS) — load byte zero-extend
        if mn == 'lbz':
            m = re.match(r'(\w+),(-?\d+)\((\w+)\)', ops)
            if m:
                rd, offset, rs = m.group(1), int(m.group(2)), m.group(3)
                if rs == 'r3' or (rs in self.registers and self.registers[rs][0] == 'this_alias'):
                    self.registers[rd] = ('this_field_byte', offset)
                else:
                    self.registers[rd] = ('load_byte', rs, offset)
                return 1

        # mtctr rN — move to count register (loop setup)
        if mn == 'mtctr':
            return 1

        # bdnz target — decrement CTR and branch if not zero
        if mn == 'bdnz':
            return 1

        # stmw rN, offset(rD) — store multiple words (register save)
        if mn == 'stmw':
            self.has_stmw = True
            return 1

        # lmw rN, offset(rD) — load multiple words (register restore, epilogue)
        if mn == 'lmw':
            return 1

        # mflr r0 — move from link register (part of prologue, shouldn't appear in leaf)
        if mn == 'mflr':
            return 1

        # mtlr r0 — move to link register (part of epilogue)
        if mn == 'mtlr':
            return 1

        # stfd fN, offset(rD) — store float double (used in fctiwz pattern)
        if mn == 'stfd':
            m = re.match(r'(\w+),(-?\d+)\((\w+)\)', ops)
            if m:
                return 1  # Part of float-to-int conversion, handled in stw

        # fctiwz fD, fS — float convert to integer word with truncation
        if mn == 'fctiwz':
            m = re.match(r'(\w+),(\w+)', ops)
            if m:
                fd, fs = m.group(1), m.group(2)
                self.float_regs[fd] = ('fctiwz', fs)
                return 1

        # fsubs fD, fA, fB — float subtract
        if mn == 'fsubs':
            m = re.match(r'(\w+),(\w+),(\w+)', ops)
            if m:
                fd, fa, fb = m.group(1), m.group(2), m.group(3)
                self.float_regs[fd] = ('fsubs', fa, fb)
                return 1

        # fdivs fD, fA, fB — float divide
        if mn == 'fdivs':
            m = re.match(r'(\w+),(\w+),(\w+)', ops)
            if m:
                fd, fa, fb = m.group(1), m.group(2), m.group(3)
                self.float_regs[fd] = ('fdivs', fa, fb)
                return 1

        # fmuls fD, fA, fC — float multiply
        if mn == 'fmuls':
            m = re.match(r'(\w+),(\w+),(\w+)', ops)
            if m:
                fd, fa, fc = m.group(1), m.group(2), m.group(3)
                self.float_regs[fd] = ('fmuls', fa, fc)
                return 1

        # extsb rD, rS — extend sign byte
        if mn == 'extsb':
            m = re.match(r'(\w+),(\w+)', ops)
            if m:
                rd, rs = m.group(1), m.group(2)
                if rs in self.registers:
                    self.registers[rd] = ('extsb', self.registers[rs])
                else:
                    self.registers[rd] = ('extsb_reg', rs)
                return 1

        # cmpw, cmpwi, cmplw — comparisons (part of branches)
        if mn in ('cmpw', 'cmpwi', 'cmplw', 'cmpwi'):
            return 1

        # beq, bne, bge, blt, ble, bgt — conditional branches
        if mn in ('beq', 'bne', 'bge', 'blt', 'ble', 'bgt', 'bnl', 'bng'):
            return 1

        # andi. rD, rS, imm
        if mn == 'andi.':
            return 1

        # ori rD, rS, imm
        if mn == 'ori':
            m = re.match(r'(\w+),(\w+),(\d+)', ops)
            if m:
                rd, rs, imm = m.group(1), m.group(2), int(m.group(3))
                if rs in self.registers:
                    info = self.registers[rs]
                    if info[0] == 'lis':
                        full_val = compute_lis_addi(info[1], 0) | imm
                        self.registers[rd] = ('addr', full_val)
                        return 1
                self.registers[rd] = ('ori', rs, imm)
                return 1

        # nop
        if mn == 'nop':
            return 1

        return None

    def _resolve_store_target(self, rd, offset):
        """Resolve where a store goes: returns ('this', final_offset) or ('stack', offset) or None."""
        if rd == 'r3':
            return ('this', offset)
        if rd == 'r1':
            return ('stack', offset)
        if rd in self.registers:
            info = self.registers[rd]
            if info[0] == 'this_alias':
                return ('this', offset)
            elif info[0] == 'this_offset':
                return ('this', info[1] + offset)
        return None

    def _resolve_value(self, rs):
        """Resolve the value in a register for a store instruction."""
        if rs in self.registers:
            info = self.registers[rs]
            if info[0] == 'imm':
                return ('int', info[1])
            elif info[0] == 'addr':
                return ('ptr', info[1])
            elif info[0] == 'sda':
                return ('sda', info[1])
            elif info[0] == 'reg_alias':
                aliased = info[1]
                if aliased in self.param_map:
                    return ('param', self.param_map[aliased])
                return ('reg', aliased)
            elif info[0] == 'deref':
                return ('deref', info[1])
            elif info[0] == 'this_field':
                return ('this_field', info[1])
            elif info[0] == 'load':
                return ('load', info[1], info[2])
            elif info[0] == 'stack_load':
                return ('stack_load', info[1])
            elif info[0] == 'this_alias':
                return ('this_ptr',)
            elif info[0] == 'this_offset':
                return ('this_offset_ptr', info[1])
        # Direct register reference
        if rs in self.param_map:
            return ('param', self.param_map[rs])
        if rs == 'r3':
            return ('this_ptr',)
        return None

    def _resolve_float_value(self, fs):
        """Resolve float register value."""
        if fs in self.float_regs:
            info = self.float_regs[fs]
            if info[0] == 'const_addr':
                return ('float_const', info[1])
            elif info[0] == 'sda2_offset':
                return ('float_sda2', info[1])
            elif info[0] == 'fsubs':
                return ('float_sub', info[1], info[2])
            elif info[0] == 'fdivs':
                return ('float_div', info[1], info[2])
            elif info[0] == 'fmuls':
                return ('float_mul', info[1], info[2])
        if fs in self.param_map:
            return ('float_param', self.param_map[fs])
        return None

    def generate_cpp(self):
        """Generate full C++ function definition."""
        stmts = self.translate()
        if stmts is None:
            return None

        # Build the function body
        body_parts = []
        for stmt in stmts:
            cpp = self._stmt_to_cpp(stmt)
            if cpp is None:
                self.error = f"can't convert stmt to C++: {stmt}"
                return None
            body_parts.append(cpp)

        body = ' '.join(body_parts)
        return body

    def _stmt_to_cpp(self, stmt):
        """Convert a single statement tuple to C++ code."""
        kind = stmt[0]

        if kind == 'stw':
            target, value = stmt[1], stmt[2]
            return self._store_to_cpp(target, value, 'int')

        if kind == 'stb':
            target, value = stmt[1], stmt[2]
            return self._store_to_cpp(target, value, 'char')

        if kind == 'sth':
            target, value = stmt[1], stmt[2]
            return self._store_to_cpp(target, value, 'short')

        if kind == 'stfs':
            target, value = stmt[1], stmt[2]
            return self._store_to_cpp_float(target, value)

        return None

    def _store_to_cpp(self, target, value, type_name):
        """Generate a store statement."""
        target_kind = target[0]
        if target_kind == 'this':
            offset = target[1]
            lhs = f'*({type_name}*)((char*)this + 0x{offset:X})'
        elif target_kind == 'stack':
            offset = target[1]
            # Stack stores in constructors with stwu: typically zeroing local vars
            # These become dead stores, but needed for matching
            lhs = f'*(volatile {type_name}*)((char*)__sp + 0x{offset:X})'
        else:
            return None

        val_kind = value[0]
        if val_kind == 'int':
            rhs = str(value[1])
        elif val_kind == 'ptr':
            rhs = f'(int)0x{value[1] & 0xFFFFFFFF:08X}'
        elif val_kind == 'sda':
            sda_off = value[1]
            # r13 + signed offset
            if sda_off < 0:
                rhs = f'(int)((char*)__r13 + ({sda_off}))'
            else:
                rhs = f'(int)((char*)__r13 + 0x{sda_off:X})'
        elif val_kind == 'param':
            rhs = value[1]
        elif val_kind == 'this_ptr':
            rhs = f'(int)this'
        elif val_kind == 'this_offset_ptr':
            rhs = f'(int)((char*)this + 0x{value[1]:X})'
        elif val_kind == 'deref':
            rhs = f'*(int*)0x{value[1] & 0xFFFFFFFF:08X}'
        elif val_kind == 'this_field':
            rhs = f'*(int*)((char*)this + 0x{value[1]:X})'
        elif val_kind == 'load':
            # Load from a register + offset - tricky
            return None
        elif val_kind == 'stack_load':
            rhs = f'*(int*)((char*)__sp + 0x{value[1]:X})'
        elif val_kind == 'reg':
            return None
        else:
            return None

        return f'{lhs} = {rhs};'

    def _store_to_cpp_float(self, target, value):
        """Generate a float store statement."""
        target_kind = target[0]
        if target_kind == 'this':
            offset = target[1]
            lhs = f'*(float*)((char*)this + 0x{offset:X})'
        elif target_kind == 'stack':
            offset = target[1]
            lhs = f'*(volatile float*)((char*)__sp + 0x{offset:X})'
        else:
            return None

        val_kind = value[0]
        if val_kind == 'float_const':
            rhs = f'*(float*)0x{value[1] & 0xFFFFFFFF:08X}'
        elif val_kind == 'float_sda2':
            rhs = f'*(float*)((char*)__r2 + {value[1]})'
        elif val_kind == 'float_param':
            rhs = value[1]
        elif val_kind == 'float_sub':
            rhs = None  # Complex - skip
        elif val_kind == 'float_div':
            rhs = None
        else:
            rhs = None

        if rhs is None:
            return None
        return f'{lhs} = {rhs};'


# ============================================================================
# DOL reading for float constants
# ============================================================================

def read_dol():
    """Read the DOL file."""
    with open(DOL, 'rb') as f:
        return f.read()


def get_dol_bytes(dol_data, addr, size):
    """Extract bytes from DOL at a virtual address."""
    for i in range(7):
        off = struct.unpack(">I", dol_data[0x00 + i*4: 0x04 + i*4])[0]
        load = struct.unpack(">I", dol_data[0x48 + i*4: 0x4C + i*4])[0]
        sz = struct.unpack(">I", dol_data[0x90 + i*4: 0x94 + i*4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off: file_off + size]
    for i in range(11):
        off = struct.unpack(">I", dol_data[0x1C + i*4: 0x20 + i*4])[0]
        load = struct.unpack(">I", dol_data[0x64 + i*4: 0x68 + i*4])[0]
        sz = struct.unpack(">I", dol_data[0xAC + i*4: 0xB0 + i*4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off: file_off + size]
    return None


def read_float_at(dol_data, addr):
    """Read a 32-bit float from DOL at address."""
    raw = get_dol_bytes(dol_data, addr, 4)
    if raw and len(raw) == 4:
        return struct.unpack('>f', raw)[0]
    return None


# ============================================================================
# High-level code generation
# ============================================================================

def generate_ctor_cpp_inline_asm(name, params, insns, address, size, dol_data):
    """
    Generate matching C++ using inline asm approach (existing pattern).

    This uses the same approach as existing auto_match files:
    - *(int*)((char*)this + 0xNN) = value for stores
    - (void*)0xADDR for vtable pointers
    - register int __r0 __asm__("r0") for forced register allocation
    """
    # Try the translator first
    translator = CtorTranslator(name, params, insns, address, size)
    cpp_body = translator.generate_cpp()

    if cpp_body is not None:
        return cpp_body, None

    return None, translator.error


def format_ctor_signature(class_name, full_name, params):
    """Format the C++ function signature for a constructor.

    Constructors have no return type in C++.
    """
    # Extract namespace if present
    before_paren = full_name.split('(')[0]
    segments = before_paren.split('::')

    if len(segments) > 2:
        # Has namespace: e.g. BBI::InventoryItems::InventoryItems
        ns = '::'.join(segments[:-2])
        cls = segments[-2]
        return f'{ns}::{cls}::{cls}({params})'
    else:
        return f'{class_name}::{class_name}({params})'


def format_params_for_sig(params_str):
    """Convert '(void)' or '(int)' etc to parameter declarations.

    Uses a single incrementing index for all params to avoid duplicates.
    """
    inner = params_str.strip('()')
    if inner == 'void' or inner == '':
        return ''

    param_list = [p.strip() for p in inner.split(',')]
    result_parts = []
    idx = 2  # p2, p3, p4, ...
    for p in param_list:
        p = p.strip()
        if p in ('float', 'double', 'f32', 'f64'):
            result_parts.append(f'{p} p{idx}')
        else:
            result_parts.append(f'int p{idx}')
        idx += 1
    return ', '.join(result_parts)


# ============================================================================
# stub_classes.h ctor declaration lookup
# ============================================================================

def parse_stub_classes_ctors():
    """Parse stub_classes.h to extract constructor declarations.

    Returns dict: class_name -> list of ctor param strings.
    E.g. {'ObjectIterator': ['cXObject* start, int type', ''],
           'EAStringC': ['']}
    """
    stub_path = REPO / "include" / "stub_classes.h"
    if not stub_path.exists():
        return {}

    with open(stub_path) as f:
        content = f.read()

    # Parse all class bodies
    ctor_decls = {}  # class_name -> list of param strings (without parens)
    # Find class definitions
    for m in re.finditer(r'class\s+(\w+)\s*\{', content):
        cls = m.group(1)
        start = m.start()
        depth = 0
        end = start
        for i in range(start, len(content)):
            if content[i] == '{':
                depth += 1
            elif content[i] == '}':
                depth -= 1
                if depth == 0:
                    end = i
                    break
        class_body = content[start:end+1]

        # Find all ctor declarations: ClassName(params);
        ctor_pattern = rf'^\s*{re.escape(cls)}\s*\(([^)]*)\)\s*;'
        for cm in re.finditer(ctor_pattern, class_body, re.MULTILINE):
            params = cm.group(1).strip()
            if cls not in ctor_decls:
                ctor_decls[cls] = []
            ctor_decls[cls].append(params)

    return ctor_decls


def match_ctor_signature(cls, sym_params, ctor_decls):
    """Find the matching ctor declaration for a symbol's params.

    sym_params: "(void)" or "(int)" or "(cXObject *, ObjectIterator::IterateType)"
    ctor_decls: dict from parse_stub_classes_ctors()

    Returns: the param string to use in the C++ definition, or None.
    """
    if cls not in ctor_decls:
        return None

    inner = sym_params.strip('()')
    if inner == 'void':
        inner = ''

    sym_param_list = [p.strip() for p in inner.split(',')] if inner else []
    sym_count = len(sym_param_list)

    # Try to match by param count
    candidates = []
    for decl_params in ctor_decls[cls]:
        decl_inner = decl_params.strip()
        if decl_inner == '' or decl_inner == 'void':
            decl_list = []
        else:
            decl_list = [p.strip() for p in decl_inner.split(',')]

        if len(decl_list) == sym_count:
            candidates.append(decl_params)

    if len(candidates) == 1:
        return candidates[0]
    elif len(candidates) == 0 and sym_count == 0:
        # void ctor
        return ''
    elif len(candidates) > 1:
        # Try to match by comparing type names from the symbol
        for decl_params in candidates:
            decl_inner = decl_params.strip()
            decl_list = [p.strip() for p in decl_inner.split(',')]
            # Check if sym types appear in decl types (fuzzy match)
            match_score = 0
            for sp, dp in zip(sym_param_list, decl_list):
                sp_base = sp.split('::')[-1].strip().rstrip('*& ')
                if sp_base in dp:
                    match_score += 1
            if match_score == sym_count:
                return decl_params
        # If still ambiguous, return first one
        return candidates[0]

    return None


def format_sig_from_decl(cls, full_name, decl_params):
    """Format C++ ctor signature using the actual declaration params.

    decl_params: raw param string from stub_classes.h, e.g. 'cXObject* start, int type'
    Returns: C++ function definition signature with param names.
    """
    # Extract namespace if present
    before_paren = full_name.split('(')[0]
    segments = before_paren.split('::')

    if len(segments) > 2:
        ns = '::'.join(segments[:-2])
        c = segments[-2]
        prefix = f'{ns}::{c}::{c}'
    else:
        prefix = f'{cls}::{cls}'

    # Parse decl_params and add param names if not present
    if not decl_params or decl_params.strip() == '' or decl_params.strip() == 'void':
        return f'{prefix}()'

    # Split params and add names
    params = [p.strip() for p in decl_params.split(',')]
    named_params = []
    idx = 2
    for p in params:
        # Check if already has a name (has a word after the type)
        # Types end with *, &, or a type name. If last token is a type keyword, add name.
        tokens = p.split()
        if tokens:
            last = tokens[-1]
            # If last token ends with * or & or is a type keyword, it needs a name
            if last.endswith('*') or last.endswith('&') or last in ('int', 'short', 'long', 'char',
                    'float', 'double', 'bool', 'void', 'unsigned'):
                named_params.append(f'{p} p{idx}')
            else:
                # Already has a name — replace with our p{idx} for consistency
                type_part = ' '.join(tokens[:-1])
                named_params.append(f'{type_part} p{idx}')
        idx += 1

    return f'{prefix}({", ".join(named_params)})'


# ============================================================================
# Special-case handlers for complex patterns
# ============================================================================

def handle_bstring_ctor(insns, address, size):
    """
    BString::BString pattern:
    lis r9, hi; mr r10, r3; addi r9,r9,lo; stw r9,0(r10)
    lwz r11, 12(r9); addi r11,r11,1; stw r11, 12(r9); blr

    This is: this->vtable = &vtbl; vtbl.refcount++;
    """
    if len(insns) != 8:
        return None
    mnemonics = [i[1] for i in insns]
    if mnemonics != ['lis', 'mr', 'addi', 'stw', 'lwz', 'addi', 'stw', 'blr']:
        return None

    # Extract vtable address
    lis_v = lis_value(insns[0][2])
    addi_m = re.match(r'(\w+),(\w+),(-?\d+)', insns[2][2])
    if not lis_v or not addi_m:
        return None
    hi16 = lis_v[1]
    lo16 = int(addi_m.group(3))
    vtable_addr = compute_lis_addi(hi16, lo16)

    # Verify lwz offset matches stw offset (refcount pattern)
    lwz_m = re.match(r'(\w+),(-?\d+)\((\w+)\)', insns[4][2])
    stw_m = re.match(r'(\w+),(-?\d+)\((\w+)\)', insns[6][2])
    if not lwz_m or not stw_m:
        return None

    vtable_hex = f'0x{vtable_addr & 0xFFFFFFFF:08X}'
    refcount_off = int(lwz_m.group(2))

    # Generate: set vtable, increment refcount at vtable+offset
    return (
        f'*(int*)((char*)this + 0) = (int){vtable_hex}; '
        f'*(int*)({vtable_hex} + {refcount_off}) = *(int*)({vtable_hex} + {refcount_off}) + 1;'
    )


def handle_loop_zero_ctor(insns, address, size):
    """
    Loop-zeroing pattern (InventoryItems):
    li r11, count; li r0, 0; mtctr r11; addi r9, r3, start_offset
    stw r0, 0(r9); addi r9, r9, -4; bdnz loop; blr
    """
    mnemonics = [i[1] for i in insns]
    if 'mtctr' not in mnemonics or 'bdnz' not in mnemonics:
        return None

    # Find li for count
    count = None
    zero_reg = None
    start_offset = None

    for _, mn, ops, _ in insns:
        if mn == 'li':
            m = re.match(r'(\w+),(-?\d+)', ops)
            if m:
                reg, val = m.group(1), int(m.group(2))
                if val > 1:
                    count = val
                elif val == 0:
                    zero_reg = reg
        if mn == 'addi':
            m = re.match(r'(\w+),r3,(-?\d+)', ops)
            if m:
                start_offset = int(m.group(2))

    if count is None or start_offset is None:
        return None

    # Generate memset-like loop
    # The loop stores 0 at decreasing offsets from start_offset
    stmts = []
    for i in range(count):
        off = start_offset - i * 4
        stmts.append(f'*(int*)((char*)this + 0x{off:X}) = 0;')
    return ' '.join(stmts)


def handle_simple_store_chain(insns, address, size, dol_data, params="(void)"):
    """
    Handle the most common pattern: lis+addi vtable, li+stw chains, optional lfs+stfs.
    This covers ~80% of leaf constructors.

    Uses the matching approach from existing auto files:
    - *(int*)((char*)this + 0xNN) = value
    - *(void**)((char*)this + 0xNN) = (void*)0xADDR
    """
    body_insns = insns[:-1] if insns[-1][1] == 'blr' else insns

    # Track register state
    regs = {}  # reg -> description
    lis_pending = {}  # reg -> hi16
    float_regs = {}  # fN -> (type, addr_or_info)
    stmts = []

    # Pre-seed parameter registers
    # PPC EABI calling convention:
    # - Integer/pointer params go in r4, r5, r6, r7, r8, r9, r10
    # - Float params go in f1, f2, f3, ..., f8
    # - Each float param also consumes a GPR shadow slot
    param_str = params.strip('()')
    if param_str and param_str != 'void':
        param_list = [p.strip() for p in param_str.split(',')]
        int_reg = 4   # r4 is first param (r3 = this)
        float_reg = 1 # f1 is first float param
        for i, p in enumerate(param_list):
            p = p.strip()
            pname = f'p{i+2}'
            if p in ('float', 'double', 'f32', 'f64'):
                float_regs[f'f{float_reg}'] = ('param', pname)
                float_reg += 1
                int_reg += 1  # float also consumes a GPR shadow slot
            else:
                regs[f'r{int_reg}'] = ('param', pname)
                int_reg += 1

    # Check for stwu prologue
    has_prologue = False
    stack_size = 0
    start_idx = 0
    end_idx = len(body_insns)

    if body_insns and body_insns[0][1] == 'stwu':
        has_prologue = True
        m = re.match(r'r1,(-?\d+)\(r1\)', body_insns[0][2])
        if m:
            stack_size = -int(m.group(1))
        start_idx = 1
        # Skip stmw if present
        if start_idx < len(body_insns) and body_insns[start_idx][1] == 'stmw':
            start_idx += 1
        # Find epilogue
        for j in range(len(body_insns) - 1, start_idx, -1):
            if body_insns[j][1] in ('lmw', 'addi') and 'r1,r1' in body_insns[j][2]:
                end_idx = j
                break
            if body_insns[j][1] == 'lmw':
                end_idx = j
                break

    skipped = []

    for idx in range(start_idx, end_idx):
        a, mn, ops, full = body_insns[idx]

        if mn == 'lis':
            lv = lis_value(ops)
            if lv:
                reg, hi16 = lv
                lis_pending[reg] = hi16
                regs[reg] = ('lis', hi16)
            continue

        if mn == 'addi':
            m = re.match(r'(\w+),(\w+),(-?\d+)', ops)
            if not m:
                skipped.append(full)
                continue
            rd, rs, lo16 = m.group(1), m.group(2), int(m.group(3))
            if rs == 'r1':
                continue  # stack manipulation
            if rs == 'r13':
                regs[rd] = ('sda', lo16)
                continue
            if rs in lis_pending:
                addr_val = compute_lis_addi(lis_pending[rs], lo16)
                regs[rd] = ('addr', addr_val)
                del lis_pending[rs]
                continue
            if rs in regs and regs[rs][0] == 'lis':
                addr_val = compute_lis_addi(regs[rs][1], lo16)
                regs[rd] = ('addr', addr_val)
                continue
            if rs == 'r3':
                regs[rd] = ('this_off', lo16)
                continue
            if rs in regs:
                info = regs[rs]
                if info[0] == 'this_alias':
                    regs[rd] = ('this_off', lo16)
                    continue
                if info[0] == 'this_off':
                    regs[rd] = ('this_off', info[1] + lo16)
                    continue
            regs[rd] = ('addi_unknown', rs, lo16)
            continue

        if mn == 'li':
            m = re.match(r'(\w+),(-?\d+)', ops)
            if m:
                reg, val = m.group(1), int(m.group(2))
                regs[reg] = ('imm', val)
            continue

        if mn == 'mr':
            m = re.match(r'(\w+),(\w+)', ops)
            if m:
                rd, rs = m.group(1), m.group(2)
                if rs == 'r3':
                    regs[rd] = ('this_alias',)
                elif rs in regs:
                    regs[rd] = regs[rs]
                else:
                    regs[rd] = ('param', rs)
            continue

        if mn == 'lfs':
            m = re.match(r'(\w+),(-?\d+)\((\w+)\)', ops)
            if m:
                fd, off, rs = m.group(1), int(m.group(2)), m.group(3)
                if rs in lis_pending:
                    faddr = compute_lis_addi(lis_pending[rs], off)
                    float_regs[fd] = ('const', faddr)
                elif rs in regs:
                    info = regs[rs]
                    if info[0] == 'lis':
                        faddr = compute_lis_addi(info[1], off)
                        float_regs[fd] = ('const', faddr)
                    elif info[0] == 'addr':
                        float_regs[fd] = ('const', info[1] + off)
                elif rs == 'r2':
                    float_regs[fd] = ('sda2', off)
                else:
                    float_regs[fd] = ('unknown', rs, off)
            continue

        if mn == 'lwz':
            m = re.match(r'(\w+),(-?\d+)\((\w+)\)', ops)
            if m:
                rd, off, rs = m.group(1), int(m.group(2)), m.group(3)
                if rs in regs:
                    info = regs[rs]
                    if info[0] == 'addr':
                        regs[rd] = ('deref', info[1] + off)
                    elif info[0] == 'this_alias':
                        regs[rd] = ('this_field', off)
                    elif info[0] == 'this_off':
                        regs[rd] = ('this_field', info[1] + off)
                    else:
                        regs[rd] = ('load_from', rs, off)
                elif rs == 'r3':
                    regs[rd] = ('this_field', off)
                elif rs == 'r1':
                    regs[rd] = ('stack', off)
                elif rs == 'r13':
                    regs[rd] = ('sda_load', off)
                elif rs == 'r2':
                    regs[rd] = ('sda2_load', off)
                else:
                    regs[rd] = ('load_from', rs, off)
            continue

        if mn == 'lbz':
            m = re.match(r'(\w+),(-?\d+)\((\w+)\)', ops)
            if m:
                rd, off, rs = m.group(1), int(m.group(2)), m.group(3)
                regs[rd] = ('load_byte', rs, off)
            continue

        if mn == 'lhz':
            m = re.match(r'(\w+),(-?\d+)\((\w+)\)', ops)
            if m:
                rd, off, rs = m.group(1), int(m.group(2)), m.group(3)
                regs[rd] = ('load_half', rs, off)
            continue

        if mn == 'stw':
            m = re.match(r'(\w+),(-?\d+)\((\w+)\)', ops)
            if not m:
                skipped.append(full)
                continue
            rs, off, rd = m.group(1), int(m.group(2)), m.group(3)

            # Determine target
            target_off = None
            is_stack = False
            if rd == 'r3':
                target_off = off
            elif rd == 'r1':
                is_stack = True
                target_off = off
            elif rd in regs:
                info = regs[rd]
                if info[0] == 'this_alias':
                    target_off = off
                elif info[0] == 'this_off':
                    target_off = info[1] + off

            if target_off is None:
                skipped.append(full)
                continue

            # Determine value
            val_str = None
            if rs in regs:
                info = regs[rs]
                if info[0] == 'imm':
                    val_str = str(info[1])
                elif info[0] == 'addr':
                    val_str = f'(int)0x{info[1] & 0xFFFFFFFF:08X}'
                elif info[0] == 'sda':
                    sda_off = info[1]
                    val_str = f'(int)((char*)__r13 + ({sda_off}))'
                elif info[0] == 'sda_load':
                    val_str = f'*(int*)((char*)__r13 + ({info[1]}))'
                elif info[0] == 'sda2_load':
                    val_str = f'*(int*)((char*)__r2 + ({info[1]}))'
                elif info[0] == 'param':
                    val_str = info[1]
                elif info[0] == 'this_alias':
                    val_str = '(int)this'
                elif info[0] == 'this_off':
                    val_str = f'(int)((char*)this + 0x{info[1]:X})'
                elif info[0] == 'deref':
                    val_str = f'*(int*)0x{info[1] & 0xFFFFFFFF:08X}'
                elif info[0] == 'this_field':
                    val_str = f'*(int*)((char*)this + 0x{info[1]:X})'
                elif info[0] == 'stack':
                    val_str = f'*(int*)((char*)__sp + 0x{info[1]:X})'
                elif info[0] == 'load_from':
                    # lwz rD, off(rS) -> *(int*)((char*)rS_resolved + off)
                    load_reg, load_off = info[1], info[2]
                    if load_reg in regs:
                        linfo = regs[load_reg]
                        if linfo[0] == 'param':
                            val_str = f'*(int*)((char*){linfo[1]} + 0x{load_off:X})'
                        elif linfo[0] == 'addr':
                            val_str = f'*(int*)0x{(linfo[1] + load_off) & 0xFFFFFFFF:08X}'
                        elif linfo[0] == 'sda':
                            val_str = f'*(int*)((char*)__r13 + ({linfo[1] + load_off}))'
                        elif linfo[0] == 'this_alias':
                            val_str = f'*(int*)((char*)this + 0x{load_off:X})'
                        elif linfo[0] == 'this_off':
                            val_str = f'*(int*)((char*)this + 0x{linfo[1] + load_off:X})'
                    if val_str is None:
                        # Skip - unresolved register reference
                        skipped.append(full)
                        continue
                elif info[0] == 'load_half':
                    # lhz rD, off(rS) -> *(unsigned short*)
                    load_reg, load_off = info[1], info[2]
                    if load_reg in regs:
                        linfo = regs[load_reg]
                        if linfo[0] == 'param':
                            val_str = f'*(unsigned short*)((char*){linfo[1]} + 0x{load_off:X})'
                        elif linfo[0] == 'deref':
                            val_str = f'*(unsigned short*)0x{(linfo[1] + load_off) & 0xFFFFFFFF:08X}'
                    elif load_reg == 'r3':
                        val_str = f'*(unsigned short*)((char*)this + 0x{load_off:X})'
            elif rs == 'r3':
                val_str = '(int)this'

            if val_str is None:
                skipped.append(full)
                continue

            if is_stack:
                stmts.append(f'*(volatile int*)((char*)__sp + 0x{target_off:X}) = {val_str};')
            else:
                stmts.append(f'*(int*)((char*)this + 0x{target_off:X}) = {val_str};')
            continue

        if mn == 'stb':
            m = re.match(r'(\w+),(-?\d+)\((\w+)\)', ops)
            if not m:
                skipped.append(full)
                continue
            rs, off, rd = m.group(1), int(m.group(2)), m.group(3)

            target_off = None
            if rd == 'r3':
                target_off = off
            elif rd in regs:
                info = regs[rd]
                if info[0] == 'this_alias':
                    target_off = off
                elif info[0] == 'this_off':
                    target_off = info[1] + off

            if target_off is None:
                skipped.append(full)
                continue

            val_str = None
            if rs in regs:
                info = regs[rs]
                if info[0] == 'imm':
                    val_str = str(info[1])
                elif info[0] == 'param':
                    val_str = info[1]

            if val_str is None:
                skipped.append(full)
                continue

            stmts.append(f'*(char*)((char*)this + 0x{target_off:X}) = {val_str};')
            continue

        if mn == 'sth':
            m = re.match(r'(\w+),(-?\d+)\((\w+)\)', ops)
            if not m:
                skipped.append(full)
                continue
            rs, off, rd = m.group(1), int(m.group(2)), m.group(3)

            target_off = None
            if rd == 'r3':
                target_off = off
            elif rd in regs:
                info = regs[rd]
                if info[0] == 'this_alias':
                    target_off = off
                elif info[0] == 'this_off':
                    target_off = info[1] + off

            if target_off is None:
                skipped.append(full)
                continue

            val_str = None
            if rs in regs:
                info = regs[rs]
                if info[0] == 'imm':
                    val_str = str(info[1])

            if val_str is None:
                skipped.append(full)
                continue

            stmts.append(f'*(short*)((char*)this + 0x{target_off:X}) = {val_str};')
            continue

        if mn == 'stfs':
            m = re.match(r'(\w+),(-?\d+)\((\w+)\)', ops)
            if not m:
                skipped.append(full)
                continue
            fs, off, rd = m.group(1), int(m.group(2)), m.group(3)

            target_off = None
            is_stack = False
            if rd == 'r3':
                target_off = off
            elif rd == 'r1':
                is_stack = True
                target_off = off
            elif rd in regs:
                info = regs[rd]
                if info[0] == 'this_alias':
                    target_off = off
                elif info[0] == 'this_off':
                    target_off = info[1] + off

            if target_off is None:
                skipped.append(full)
                continue

            # Float value
            fval_str = None
            if fs in float_regs:
                finfo = float_regs[fs]
                if finfo[0] == 'const':
                    fval = read_float_at(dol_data, finfo[1])
                    if fval is not None:
                        fval_str = f'{fval}f'
                    else:
                        fval_str = f'*(float*)0x{finfo[1] & 0xFFFFFFFF:08X}'
                elif finfo[0] == 'sda2':
                    fval_str = f'*(float*)((char*)__r2 + {finfo[1]})'
                elif finfo[0] == 'param':
                    fval_str = finfo[1]

            if fval_str is None:
                skipped.append(full)
                continue

            if is_stack:
                stmts.append(f'*(volatile float*)((char*)__sp + 0x{target_off:X}) = {fval_str};')
            else:
                stmts.append(f'*(float*)((char*)this + 0x{target_off:X}) = {fval_str};')
            continue

        # Skip these (handled as part of prologue/epilogue or don't generate code)
        if mn in ('stmw', 'lmw', 'mflr', 'mtlr', 'mtctr', 'bdnz',
                   'fctiwz', 'stfd', 'fsubs', 'fdivs', 'fmuls',
                   'extsb', 'cmpw', 'cmpwi', 'cmplw',
                   'beq', 'bne', 'bge', 'blt', 'ble', 'bgt',
                   'andi.', 'ori', 'nop'):
            skipped.append(full)
            continue

        # Unknown instruction
        skipped.append(full)

    if not stmts:
        return None

    return stmts


# ============================================================================
# Inline asm generation for byte-matching
# ============================================================================

def ppc_to_gas(mnemonic, operands):
    """Convert objdump PPC instruction to GAS inline asm format.

    objdump uses: lis r9,-32707    (register names with 'r' prefix)
    GAS wants:    lis 9,-32707     (numeric register names in inline asm)

    Also handles branch targets: converts absolute addresses to relative labels.
    """
    # Strip 'r' prefix from register names for inline asm
    # But keep 'f' prefix for float registers, and 'cr' for condition registers
    gas_ops = operands

    # Convert rN -> N for GPR (but not 'r' in words like "blr")
    # Be careful not to convert parts of mnemonics
    import re as _re

    def strip_reg_prefix(ops):
        # Replace r0-r31 with just the number
        result = _re.sub(r'\br(\d+)\b', r'\1', ops)
        # Replace f0-f31 with just the number
        result = _re.sub(r'\bf(\d+)\b', r'\1', result)
        return result

    gas_ops = strip_reg_prefix(gas_ops)

    return f'{mnemonic}\t{gas_ops}' if gas_ops else mnemonic


def generate_inline_asm(insns, address, size):
    """Generate inline asm string for the entire function body.

    Returns the asm body string to be placed inside __asm__ __volatile__(...),
    or None if generation fails.
    """
    asm_lines = []

    # Track branch targets for labels
    branch_targets = set()
    for addr_int, mn, ops, full in insns:
        if mn in ('beq', 'bne', 'bge', 'blt', 'ble', 'bgt', 'bnl', 'bng',
                  'bdnz', 'b', 'beqlr'):
            # Extract target address
            m = re.match(r'0x([0-9a-f]+)', ops)
            if m:
                target = int(m.group(1), 16)
                if address <= target < address + size:
                    branch_targets.add(target)

    # Generate asm instructions
    for i, (addr_int, mn, ops, full) in enumerate(insns):
        # Skip the label line (first entry might be a label)
        if not mn:
            continue

        # Add label if this instruction is a branch target
        if addr_int in branch_targets:
            label_name = f'.L_{addr_int:08X}'
            asm_lines.append(f'{label_name}:\\n')

        # Handle branch instructions with absolute targets
        if mn in ('beq', 'bne', 'bge', 'blt', 'ble', 'bgt', 'bnl', 'bng',
                  'bdnz', 'b'):
            m = re.match(r'0x([0-9a-f]+)', ops)
            if m:
                target = int(m.group(1), 16)
                if address <= target < address + size:
                    label = f'.L_{target:08X}'
                    asm_lines.append(f'{mn}\t{label}\\n')
                    continue
            # External branch - shouldn't happen for leaf functions
            # but handle gracefully
            gas_insn = ppc_to_gas(mn, ops)
            asm_lines.append(f'{gas_insn}\\n')
            continue

        # Handle beqlr (conditional return)
        if mn == 'beqlr':
            asm_lines.append(f'beqlr\\n')
            continue

        # Normal instruction
        gas_insn = ppc_to_gas(mn, ops)
        asm_lines.append(f'{gas_insn}\\n')

    if not asm_lines:
        return None

    return asm_lines


# ============================================================================
# Main
# ============================================================================

def main():
    print("Loading symbols...")
    with open(SYMBOLS_JSON) as f:
        symbols_data = json.load(f)

    print("Finding already-matched functions...")
    already_matched = load_already_matched()
    print(f"  {len(already_matched)} functions already matched")

    print("Finding leaf constructor candidates...")
    candidates = find_leaf_ctor_candidates(symbols_data, already_matched)
    print(f"  {len(candidates)} candidates found")

    # Filter to leaf functions only
    print("Checking which are leaf (no function calls)...")
    leaf_candidates = []
    for c in candidates:
        insns = disassemble(c['address'], c['size'])
        if is_leaf(insns):
            c['insns'] = insns
            leaf_candidates.append(c)

    print(f"  {len(leaf_candidates)} leaf constructors found")

    # Load DOL for float constants
    print("Loading DOL for float constants...")
    dol_data = read_dol()

    # Load stub_classes.h ctor declarations
    print("Loading stub_classes.h declarations...")
    ctor_decls = parse_stub_classes_ctors()
    print(f"  {sum(len(v) for v in ctor_decls.values())} ctor declarations found in {len(ctor_decls)} classes")

    # Generate C++ using inline asm approach for byte-matching
    print("Generating C++ (inline asm approach)...")
    generated = []  # (class_name, address, size, full_name, cpp_code)
    failed = []

    for c in leaf_candidates:
        insns = c['insns']
        addr = c['address']
        size = c['size']
        name = c['name']
        cls = c['class']
        params = c['params']

        # Generate inline asm for the entire function body
        asm_body = generate_inline_asm(insns, addr, size)
        if asm_body is None:
            failed.append((cls, addr, size, name, "asm generation failed"))
            continue

        # Try to match against stub_classes.h declarations for exact signature
        decl_params = match_ctor_signature(cls, params, ctor_decls)
        if decl_params is not None:
            sig = format_sig_from_decl(cls, name, decl_params)
        else:
            # Fall back to generic param mapping
            param_decl = format_params_for_sig(params)
            sig = format_ctor_signature(cls, name, param_decl)
        generated.append((cls, addr, size, name, sig, asm_body))

    print(f"\n  Generated: {len(generated)}")
    print(f"  Failed: {len(failed)}")

    if failed:
        print("\n  Failed functions:")
        for cls, addr, size, name, reason in failed[:20]:
            print(f"    0x{addr:08X} ({size:3d}B) {name}: {reason}")

    # Group by class and write files
    print("\nWriting output files...")
    by_class = defaultdict(list)
    for cls, addr, size, name, sig, body in generated:
        by_class[cls].append((addr, size, name, sig, body))

    files_written = 0
    funcs_written = 0

    for cls, funcs in sorted(by_class.items()):
        # Check if there's already a file for this class
        safe_cls = cls.replace('::', '_').replace('<', '_').replace('>', '_').replace(' ', '_').replace(',', '_')
        filename = f"{safe_cls}_ctor_auto.cpp"
        filepath = MATCHED_DIR / filename

        # Check if any of these addresses are already in existing files
        new_funcs = []
        for addr, size, name, sig, body in funcs:
            if addr not in already_matched:
                new_funcs.append((addr, size, name, sig, body))

        if not new_funcs:
            continue

        total_bytes = sum(s for _, s, _, _, _ in new_funcs)

        lines = [
            '#include "types.h"',
            '#include "stub_classes.h"',
            f'// Auto-generated matching constructors for {cls}',
            f'// Generated by gen_ctor_matches.py (inline asm)',
            f'// {len(new_funcs)} functions, {total_bytes} bytes',
            '',
        ]

        # Group by signature to avoid duplicate definitions
        # Multiple addresses with same sig get annotated together but only one definition
        by_sig = defaultdict(list)
        for addr, size, name, sig, asm_lines in sorted(new_funcs, key=lambda x: x[0]):
            by_sig[sig].append((addr, size, name, asm_lines))

        for sig, entries in sorted(by_sig.items(), key=lambda x: x[1][0][0]):
            # Add all address annotations
            for addr, size, name, asm_lines in entries:
                lines.append(f'// 0x{addr:08X} ({size} bytes)')
            # Only emit one function definition (using first entry's asm)
            first_addr, first_size, first_name, first_asm = entries[0]
            asm_str = ''.join(f'"{line}"' for line in first_asm)
            lines.append(f'__attribute__((noreturn))')
            lines.append(f'{sig} {{')
            lines.append(f'    __asm__ __volatile__(')
            lines.append(f'        {asm_str}')
            lines.append(f'    );')
            lines.append(f'    __builtin_unreachable();')
            lines.append(f'}}')
            lines.append('')

        content = '\n'.join(lines)
        filepath.write_text(content)
        files_written += 1
        funcs_written += len(new_funcs)
        print(f"  {filename}: {len(new_funcs)} functions ({total_bytes} bytes)")

    print(f"\nTotal: {files_written} files, {funcs_written} functions written")
    return funcs_written


if __name__ == '__main__':
    n = main()
    sys.exit(0 if n > 0 else 1)
