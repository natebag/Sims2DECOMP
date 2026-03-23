#!/usr/bin/env python3
"""
Convert simple call-wrapper functions from inline asm to real C++.

Scans src/asm_decomp/ for functions with 1-2 `bl` instructions that are
"wrapper" functions and converts them to readable C++ calls.

PPC EABI calling convention:
  r1  = stack pointer
  r3  = this (member functions) / first int arg / int return value
  r4-r10 = subsequent int args
  r13 = SDA base
  f1-f8 = float args; f1 = float return
  r14-r31 = callee-saved (preserved across calls)
"""

import os
import re
import sys
from collections import defaultdict

BACKSLASH_N = chr(92) + 'n'
ASM_DIR = "F:/coding/Decompiles/Sims 2/src/asm_decomp"
MATCHED_DIR = "F:/coding/Decompiles/Sims 2/src/matched"


def extract_asm_lines(block):
    """Extract clean asm instruction lines from a function block."""
    asm_match = re.search(r'__asm__ __volatile__\(\s*(.*?)\s*\);', block, re.DOTALL)
    if not asm_match:
        return []
    lines = []
    for raw in asm_match.group(1).split('\n'):
        raw = raw.strip()
        if not raw.startswith('"'):
            continue
        inner = raw[1:]
        if inner.endswith('"'):
            inner = inner[:-1]
        if inner.endswith(BACKSLASH_N):
            inner = inner[:-2]
        inner = inner.strip()
        if inner:
            lines.append(inner)
    return lines


def extract_asm_body(block):
    """Extract the raw __asm__ __volatile__(...) text."""
    m = re.search(r'(__asm__ __volatile__\(.*?\);)', block, re.DOTALL)
    return m.group(1) if m else None


def is_epilogue(line):
    """Check if instruction is epilogue."""
    return (line == 'blr' or line == 'mtlr\t0' or
            (line.startswith('lwz\t0,') and '(1)' in line) or
            line.startswith('addi\t1,1,') or line.startswith('lmw\t') or
            (line.startswith('lfd\t') and '(1)' in line) or
            (re.match(r'lwz\t\d+,\d+\(1\)', line) is not None) or
            line.startswith('.L_'))


def extract_func_sig(block):
    """Extract C++ function signature."""
    m = re.search(r'^(__attribute__\(\(noreturn\)\)\s*\n)?(.+?)\s*\{',
                  block, re.MULTILINE)
    if m:
        return m.group(2).strip()
    return None


def get_return_type(sig):
    """Extract return type from function signature."""
    if not sig:
        return 'void'
    m = re.match(r'((?:const\s+)?(?:unsigned\s+)?(?:signed\s+)?'
                 r'(?:void|int|bool|float|double|char|short|long|'
                 r'\w+\s*[*&]|\w+))\s+(?:\w+::)+', sig)
    if m:
        return m.group(1).strip()
    return 'void'


def parse_func_name(full_name):
    """Parse 'ClassName::MethodName(params)' -> (class, method, params_str)"""
    m = re.match(r'((?:\w+::)*\w+)::(\w+|operator\S+|~\w+)(\(.*\))', full_name)
    if m:
        return m.group(1), m.group(2), m.group(3)
    m = re.match(r'(\w+)(\(.*\))', full_name)
    if m:
        return None, m.group(1), m.group(2)
    return None, full_name, '()'


def parse_params(params_str):
    """Parse parameter string into list of (type, name) tuples.

    In asm decomp signatures, params are type-only (no names).
    E.g. "(unsigned int, char *, BString2 &)"
    """
    params_str = params_str.strip('()')
    if not params_str or params_str == 'void':
        return []
    params = []
    for p in re.split(r',\s*(?![^<>()]*[>)])', params_str):
        p = p.strip()
        params.append((p, None))
    return params


def get_prologue_end(lines):
    """Find end of function prologue."""
    prologue_end = 0
    for i, line in enumerate(lines):
        if (line.startswith('stwu\t1,') or line == 'mflr\t0' or
                line.startswith('stmw\t') or
                (line.startswith('stw\t0,') and '(1)' in line) or
                (line.startswith('stfd\t') and '(1)' in line)):
            prologue_end = i + 1
        else:
            break
    return prologue_end


class RegTracker:
    """Track register contents through PPC instruction sequence."""

    def __init__(self, is_member=True, wrapper_params=None):
        self.regs = {}  # int reg -> symbolic value
        self.fregs = {}  # float reg -> symbolic value
        self.param_names = {}  # reg -> param name for pretty printing

        if is_member:
            self.regs[3] = 'this'

        # Map wrapper parameters to registers
        if wrapper_params:
            int_reg = 4 if is_member else 3
            float_reg = 1
            for i, (ptype, pname) in enumerate(wrapper_params):
                auto_name = f'p{i}'
                if ptype in ('float', 'double'):
                    self.fregs[float_reg] = auto_name
                    self.param_names[f'f{float_reg}'] = auto_name
                    float_reg += 1
                else:
                    self.regs[int_reg] = auto_name
                    self.param_names[f'r{int_reg}'] = auto_name
                    int_reg += 1

    def copy(self):
        t = RegTracker.__new__(RegTracker)
        t.regs = dict(self.regs)
        t.fregs = dict(self.fregs)
        return t

    def process(self, line):
        """Process one instruction, return description of side effects or None."""
        parts = line.split('\t', 1)
        if len(parts) < 2:
            return None
        op, operands = parts[0], parts[1]

        # mr rD, rA
        m = re.match(r'(\d+),(\d+)$', operands)
        if op in ('mr', 'mr.') and m:
            dst, src = int(m.group(1)), int(m.group(2))
            self.regs[dst] = self.regs.get(src, f'r{src}')
            return None

        # li rD, imm
        m = re.match(r'(\d+),(-?\d+)$', operands)
        if op == 'li' and m:
            dst, imm = int(m.group(1)), int(m.group(2))
            self.regs[dst] = imm
            return None

        # lis rD, imm (load immediate shifted)
        if op == 'lis' and m:
            dst, imm = int(m.group(1)), int(m.group(2))
            self.regs[dst] = ('lis', imm)
            return None

        # lwz rD, offset(rA)
        m = re.match(r'(\d+),(-?\d+)\((\d+)\)$', operands)
        if op == 'lwz' and m:
            dst, offset, base = int(m.group(1)), int(m.group(2)), int(m.group(3))
            base_val = self.regs.get(base)
            if base_val == 'this':
                self.regs[dst] = ('field', offset)
            elif isinstance(base_val, str) and not base_val.startswith('r'):
                self.regs[dst] = ('deref', base_val, offset)
            elif isinstance(base_val, tuple) and base_val[0] == 'field':
                self.regs[dst] = ('deref_field', base_val[1], offset)
            elif base == 13:
                self.regs[dst] = ('sda', offset)
            elif base == 1:
                self.regs[dst] = ('stack', offset)
            else:
                self.regs[dst] = ('load', base, offset)
            return None

        # lbz/lhz/lha
        if op in ('lbz', 'lhz', 'lha') and m:
            dst, offset, base = int(m.group(1)), int(m.group(2)), int(m.group(3))
            base_val = self.regs.get(base)
            if base_val == 'this':
                self.regs[dst] = ('field', offset)
            else:
                self.regs[dst] = ('load', base, offset)
            return None

        # addi rD, rA, imm
        m = re.match(r'(\d+),(\d+),(-?\d+)$', operands)
        if op == 'addi' and m:
            dst, src, imm = int(m.group(1)), int(m.group(2)), int(m.group(3))
            src_val = self.regs.get(src)
            if src_val == 'this':
                self.regs[dst] = ('this_plus', imm)
            elif isinstance(src_val, tuple) and src_val[0] == 'lis':
                # lis + addi = full address
                addr = ((src_val[1] & 0xFFFF) << 16) + (imm & 0xFFFF)
                self.regs[dst] = ('addr', addr)
            elif isinstance(src_val, tuple) and src_val[0] == 'field':
                self.regs[dst] = ('field_plus', src_val[1], imm)
            elif isinstance(src_val, tuple) and src_val[0] == 'deref_field':
                self.regs[dst] = ('deref_field_plus', src_val[1], src_val[2], imm)
            else:
                self.regs[dst] = ('add', src, imm)
            return None

        # stw rS, offset(rA) - store word (side effect)
        m = re.match(r'(\d+),(-?\d+)\((\d+)\)$', operands)
        if op == 'stw' and m:
            src, offset, base = int(m.group(1)), int(m.group(2)), int(m.group(3))
            if base != 1:  # not stack store
                return ('store', src, offset, base)
            return None

        # stb/sth/stfs - stores (side effects)
        if op in ('stb', 'sth', 'stfs') and m:
            src, offset, base = int(m.group(1)), int(m.group(2)), int(m.group(3))
            if base != 1:
                return ('store', src, offset, base)
            return None

        # slwi rD, rA, shift
        m = re.match(r'(\d+),(\d+),(\d+)$', operands)
        if op == 'slwi' and m:
            dst, src, sh = int(m.group(1)), int(m.group(2)), int(m.group(3))
            self.regs[dst] = ('slwi', src, sh)
            return None

        # mulli rD, rA, imm
        if op == 'mulli' and m:
            dst, src, imm = int(m.group(1)), int(m.group(2)), int(m.group(3))
            self.regs[dst] = ('mulli', src, imm)
            return None

        # lfs fD, offset(rA)
        m = re.match(r'(\d+),(-?\d+)\((\d+)\)$', operands)
        if op == 'lfs' and m:
            dst, offset, base = int(m.group(1)), int(m.group(2)), int(m.group(3))
            base_val = self.regs.get(base)
            if base_val == 'this':
                self.fregs[dst] = ('float_field', offset)
            return None

        # fmr fD, fA
        m = re.match(r'(\d+),(\d+)$', operands)
        if op == 'fmr' and m:
            dst, src = int(m.group(1)), int(m.group(2))
            self.fregs[dst] = self.fregs.get(src, f'f{src}')
            return None

        return None

    def invalidate_caller_saved(self):
        """Invalidate caller-saved registers after a function call.

        r3-r12 and f0-f13 are caller-saved.
        r14-r31 are callee-saved (preserved).
        After a call, r3 = return value.
        """
        for reg in list(self.regs.keys()):
            if 3 <= reg <= 12:
                del self.regs[reg]
        self.regs[3] = 'ret_val'

    def format_value(self, val):
        """Format a register value as a C++ expression."""
        if val is None:
            return '/* ? */'
        if isinstance(val, int):
            if val < 0:
                return str(val)
            if val > 255:
                return f'{val:#x}'
            return str(val)
        if isinstance(val, str):
            return val
        if isinstance(val, tuple):
            kind = val[0]
            if kind == 'field':
                return f'this->field_{val[1]:#x}'
            if kind == 'deref':
                return f'{val[1]}->field_{val[2]:#x}'
            if kind == 'deref_field':
                return f'this->field_{val[1]:#x}->field_{val[2]:#x}'
            if kind == 'sda':
                return f'__SDA_r13[{val[1]}]'
            if kind == 'this_plus':
                return f'(this + {val[1]:#x})'
            if kind == 'field_plus':
                return f'(this->field_{val[1]:#x} + {val[2]})'
            if kind == 'deref_field_plus':
                return f'((char*)this->field_{val[1]:#x}->field_{val[2]:#x} + {val[3]})'
            if kind == 'addr':
                return f'(void*){val[1]:#010x}'
            if kind == 'lis':
                return f'{val[1]:#x}0000'
            if kind == 'load':
                return f'*(r{val[1]} + {val[2]:#x})'
            if kind == 'stack':
                return f'stack_{val[1]:#x}'
            if kind == 'add':
                return f'(r{val[1]} + {val[2]})'
            if kind == 'slwi':
                return f'(r{val[1]} << {val[2]})'
            if kind == 'float_field':
                return f'this->float_{val[1]:#x}'
        return str(val)


def scan_all_wrappers():
    """Scan all asm_decomp files and find wrapper functions."""
    files = sorted([f for f in os.listdir(ASM_DIR) if f.endswith('.cpp')])
    all_wrappers = defaultdict(list)
    stats = defaultdict(int)

    for fname in files:
        filepath = os.path.join(ASM_DIR, fname)
        with open(filepath, 'r') as f:
            content = f.read()

        func_blocks = re.split(r'(?=// 0x[0-9A-Fa-f]+ \(\d+ bytes\))', content)

        for block in func_blocks:
            sig_match = re.search(
                r'// (0x[0-9A-Fa-f]+) \((\d+) bytes\)\n// (.+)', block)
            if not sig_match:
                continue

            addr = sig_match.group(1)
            size = int(sig_match.group(2))
            name = sig_match.group(3)

            bl_calls = re.findall(
                r'\.long\s+0x4[0-9a-fA-F]{7}\s+/\*\s*bl\s+(.+?)\s*\*/', block)
            if len(bl_calls) < 1 or len(bl_calls) > 2:
                continue

            lines = extract_asm_lines(block)
            if not lines or 'blr' not in lines:
                continue

            if any(l == 'blrl' for l in lines):
                continue

            bl_positions = [i for i, l in enumerate(lines)
                            if l.startswith('.long') and '/* bl' in l]
            blr_idx = lines.index('blr')

            last_bl = bl_positions[-1]
            post_bl = lines[last_bl + 1:blr_idx]
            if not all(is_epilogue(l) for l in post_bl):
                continue

            cond_branches = sum(
                1 for l in lines
                if re.match(r'b(eq|ne|lt|gt|le|ge|dnz|dz)\t', l))
            uncond_b = sum(1 for l in lines if re.match(r'b\t\.L_', l))

            if len(bl_calls) == 1 and cond_branches == 0 and uncond_b == 0:
                pattern = '1bl_no_branch'
            elif len(bl_calls) == 1:
                pattern = '1bl_with_branch'
            elif len(bl_calls) == 2 and cond_branches == 0 and uncond_b == 0:
                pattern = '2bl_no_branch'
            else:
                pattern = '2bl_with_branch'

            stats[pattern] += 1
            stats['total'] += 1

            func_sig = extract_func_sig(block)

            info = {
                'fname': fname,
                'name': name,
                'addr': addr,
                'size': size,
                'bl_calls': bl_calls,
                'bl_positions': bl_positions,
                'lines': lines,
                'blr_idx': blr_idx,
                'cond_branches': cond_branches,
                'uncond_b': uncond_b,
                'pattern': pattern,
                'block': block,
                'func_sig': func_sig,
            }

            all_wrappers[fname].append(info)

    return all_wrappers, stats


def convert_2bl_no_branch(info):
    """Convert a 2-bl no-branch wrapper to C++."""
    lines = info['lines']
    name = info['name']
    bl_calls = info['bl_calls']
    bl_positions = info['bl_positions']
    func_sig = info['func_sig']

    if not func_sig:
        return None

    wrapper_class, wrapper_method, wrapper_params_str = parse_func_name(name)
    is_member = wrapper_class is not None
    ret_type = get_return_type(func_sig)
    prologue_end = get_prologue_end(lines)
    wrapper_params = parse_params(wrapper_params_str)

    target1 = bl_calls[0]
    target2 = bl_calls[1]
    t1_class, t1_method, t1_params_str = parse_func_name(target1)
    t2_class, t2_method, t2_params_str = parse_func_name(target2)

    # Trace registers through the function
    tracker = RegTracker(is_member, wrapper_params)
    side_effects_before_call1 = []

    # Process instructions before call 1
    for i in range(prologue_end, bl_positions[0]):
        effect = tracker.process(lines[i])
        if effect:
            side_effects_before_call1.append(effect)

    # Save state at call 1 (before invalidation)
    tracker_before_call1 = tracker.copy()

    # After call 1: invalidate caller-saved, r3 = return value
    tracker.invalidate_caller_saved()

    side_effects_between = []
    # Process instructions between call 1 and call 2
    for i in range(bl_positions[0] + 1, bl_positions[1]):
        effect = tracker.process(lines[i])
        if effect:
            side_effects_between.append(effect)

    # Build C++ call expressions
    t1_params = parse_params(t1_params_str)
    t2_params = parse_params(t2_params_str)

    def build_call(target_name, t_class, t_method, arg_regs, t_params,
                   wrapper_class):
        """Build a C++ call expression.

        arg_regs: dict mapping 'r3','r4','r5',... to formatted values
        """
        r3 = arg_regs.get('r3', '/* ? */')
        is_self_call = (r3 == 'this')
        is_same_class = (t_class and t_class == wrapper_class)
        t_is_member = (t_class is not None)

        # Build argument list from r4+ (member) or r3+ (free)
        start_reg = 4 if t_is_member else 3
        args = []
        for pi in range(len(t_params)):
            reg_key = f'r{start_reg + pi}'
            val = arg_regs.get(reg_key, '/* ? */')
            args.append(val)
        args_str = ', '.join(args)

        if t_is_member:
            if is_self_call:
                if is_same_class:
                    return f'{t_method}({args_str})'
                else:
                    return f'{t_class}::{t_method}({args_str})'
            else:
                # r3 is not 'this' - this is either:
                #   a) a method call on another object: obj->Method(args)
                #   b) a static method: Class::Method(arg)
                # Since we can't distinguish, format as the full name
                # treating the implicit this (r3) as part of the call.
                full_name = target_name.split('(')[0]
                # The actual args start at r4 for member functions
                return f'{full_name}({args_str})  /* on {r3} */'
        else:
            call_name = target_name.split('(')[0]
            return f'{call_name}({args_str})'

    # Build reg dicts for both calls
    call1_regs = {f'r{i}': tracker_before_call1.format_value(
        tracker_before_call1.regs.get(i)) for i in range(3, 11)}
    call2_regs = {f'r{i}': tracker.format_value(
        tracker.regs.get(i)) for i in range(3, 11)}

    call1_expr = build_call(target1, t1_class, t1_method,
                            call1_regs, t1_params, wrapper_class)
    call2_expr = build_call(target2, t2_class, t2_method,
                            call2_regs, t2_params, wrapper_class)

    # Check if call2 uses the return value of call1
    uses_ret = any('ret_val' in call2_regs.get(f'r{i}', '')
                    for i in range(3, 11)
                    if isinstance(call2_regs.get(f'r{i}', ''), str))

    # Build body
    body_parts = []

    # Add side effects before call1 as comments
    if side_effects_before_call1:
        for se in side_effects_before_call1:
            if se[0] == 'store':
                src_reg, offset, base_reg = se[1], se[2], se[3]
                src_val = tracker.format_value(tracker.regs.get(src_reg, f'r{src_reg}'))
                # Can't easily express these without knowing the types
                pass

    if uses_ret:
        body_parts.append(f'auto _ret = {call1_expr};')
        # Replace ret_val in call2 args
        call2_expr = call2_expr.replace('ret_val', '_ret')
        body_parts.append(f'{call2_expr};')
    else:
        body_parts.append(f'{call1_expr};')
        body_parts.append(f'{call2_expr};')

    body = ' '.join(body_parts)
    code = f"// {info['addr']} ({info['size']} bytes)\n{func_sig} {{ {body} }}"
    return code


def convert_1bl_no_branch(info):
    """Convert a 1-bl no-branch wrapper to C++."""
    lines = info['lines']
    name = info['name']
    bl_calls = info['bl_calls']
    bl_positions = info['bl_positions']
    func_sig = info['func_sig']

    if not func_sig:
        return None

    wrapper_class, wrapper_method, wrapper_params_str = parse_func_name(name)
    is_member = wrapper_class is not None
    ret_type = get_return_type(func_sig)
    prologue_end = get_prologue_end(lines)
    wrapper_params = parse_params(wrapper_params_str)

    target = bl_calls[0]
    t_class, t_method, t_params_str = parse_func_name(target)
    t_params = parse_params(t_params_str)

    # Trace registers
    tracker = RegTracker(is_member, wrapper_params)
    side_effects = []

    for i in range(prologue_end, bl_positions[0]):
        effect = tracker.process(lines[i])
        if effect:
            side_effects.append(effect)

    # Build reg dict for call
    call_regs = {f'r{i}': tracker.format_value(tracker.regs.get(i))
                 for i in range(3, 11)}

    # Use build_call helper (same as used in 2bl)
    def build_call_1bl(target_name, t_class, t_method, arg_regs, t_params,
                       wrapper_class):
        r3 = arg_regs.get('r3', '/* ? */')
        is_self_call = (r3 == 'this')
        is_same_class = (t_class and t_class == wrapper_class)
        t_is_member = (t_class is not None)

        start_reg = 4 if t_is_member else 3
        args = []
        for pi in range(len(t_params)):
            reg_key = f'r{start_reg + pi}'
            val = arg_regs.get(reg_key, '/* ? */')
            args.append(val)
        args_str = ', '.join(args)

        if t_is_member:
            if is_self_call:
                if is_same_class:
                    return f'{t_method}({args_str})'
                else:
                    return f'{t_class}::{t_method}({args_str})'
            else:
                full_name = target_name.split('(')[0]
                return f'{full_name}({args_str})  /* on {r3} */'
        else:
            call_name = target_name.split('(')[0]
            return f'{call_name}({args_str})'

    call_expr = build_call_1bl(target, t_class, t_method, call_regs,
                               t_params, wrapper_class)

    # Handle side effects (stores to fields before the call)
    body_parts = []
    for se in side_effects:
        if se[0] == 'store':
            src_reg, offset, base_reg = se[1], se[2], se[3]
            src_val = tracker.regs.get(src_reg)
            base_val = tracker.regs.get(base_reg)
            if base_val == 'this' and isinstance(src_val, int):
                body_parts.append(
                    f'*(int*)((char*)this + {offset:#x}) = {src_val};')
            elif isinstance(base_val, str) and base_val == 'this' and \
                    isinstance(src_val, str):
                body_parts.append(
                    f'*(int*)((char*)this + {offset:#x}) = (int){src_val};')

    if ret_type != 'void':
        body_parts.append(f'return {call_expr};')
    else:
        body_parts.append(f'{call_expr};')

    body = ' '.join(body_parts)
    code = f"// {info['addr']} ({info['size']} bytes)\n{func_sig} {{ {body} }}"
    return code


def convert_with_branches(info):
    """Convert wrapper with branches - preserve asm but document calls."""
    func_sig = info['func_sig']
    if not func_sig:
        return None

    bl_calls = info['bl_calls']
    targets_str = ', '.join(bl_calls)
    asm_body = extract_asm_body(info['block'])
    if not asm_body:
        return None

    lines = [
        f"// {info['addr']} ({info['size']} bytes)",
        f"// Call wrapper [{info['pattern']}]: {targets_str}",
        f"__attribute__((noreturn))",
        f"{func_sig} {{",
        f"    {asm_body}",
        f"    __builtin_unreachable();",
        f"}}",
    ]
    return '\n'.join(lines)


def main():
    print("=" * 60)
    print("Sims 2 GC Decomp: Call Wrapper Converter")
    print("=" * 60)

    print("\nScanning asm_decomp for wrapper functions...")
    all_wrappers, stats = scan_all_wrappers()

    print(f"\nFound {stats.get('total', 0)} wrapper functions:")
    for k, v in sorted(stats.items()):
        if k != 'total':
            print(f"  {k}: {v}")
    print(f"Across {len(all_wrappers)} source files")

    # Convert
    conv_stats = defaultdict(int)
    files_written = 0
    total_funcs = 0
    total_cpp = 0
    total_asm = 0

    for source_file, func_list in sorted(all_wrappers.items()):
        base_name = source_file.replace('.cpp', '')
        out_name = f"{base_name}_call_converted.cpp"
        out_path = os.path.join(MATCHED_DIR, out_name)

        if os.path.exists(out_path):
            continue

        output_parts = [
            '#include "types.h"',
            '#include "stub_classes.h"',
            f'// Auto-converted call wrapper stubs for {base_name}',
            f'// Generated by convert_call_wrappers.py',
            '',
        ]

        func_count = 0
        cpp_count = 0
        asm_count = 0

        for info in func_list:
            pattern = info['pattern']
            code = None

            if pattern in ('1bl_no_branch', '2bl_no_branch'):
                if pattern == '1bl_no_branch':
                    code = convert_1bl_no_branch(info)
                else:
                    code = convert_2bl_no_branch(info)

                if code:
                    output_parts.append(code)
                    output_parts.append('')
                    func_count += 1
                    cpp_count += 1
                    conv_stats['cpp_converted'] += 1
            else:
                # Preserve asm with documentation
                code = convert_with_branches(info)
                if code:
                    output_parts.append(code)
                    output_parts.append('')
                    func_count += 1
                    asm_count += 1
                    conv_stats['asm_documented'] += 1

        if func_count > 0:
            with open(out_path, 'w', newline='\r\n') as f:
                f.write('\n'.join(output_parts))
            files_written += 1
            total_funcs += func_count
            total_cpp += cpp_count
            total_asm += asm_count

    print(f"\nConversion results:")
    print(f"  C++ converted (no branches): {conv_stats.get('cpp_converted', 0)}")
    print(f"  Asm documented (with branches): {conv_stats.get('asm_documented', 0)}")
    print(f"\nOutput:")
    print(f"  Files written: {files_written}")
    print(f"  Total functions: {total_funcs}")
    print(f"    Real C++: {total_cpp}")
    print(f"    Asm preserved: {total_asm}")


if __name__ == '__main__':
    main()
