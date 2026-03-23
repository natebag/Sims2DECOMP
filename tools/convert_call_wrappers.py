#!/usr/bin/env python3
"""
Convert simple call-wrapper functions from inline asm to real C++.

Scans src/asm_decomp/ for functions with 1-2 `bl` instructions that are
"wrapper" functions: they set up arguments and call other functions.

Two output modes:
  1. Functions we can confidently convert to C++ -> real C++ code
  2. Functions too complex for auto-conversion -> preserved asm with call docs

The C++ won't byte-match at .o level (bl uses relative offsets) but will be
correct in the final linked binary.
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
    """Extract the raw __asm__ __volatile__(...) text from a block."""
    m = re.search(r'(__asm__ __volatile__\(.*?\);)', block, re.DOTALL)
    return m.group(1) if m else None


def is_epilogue(line):
    """Check if instruction is function epilogue (restore + return)."""
    return (line == 'blr' or
            line == 'mtlr\t0' or
            (line.startswith('lwz\t0,') and '(1)' in line) or
            line.startswith('addi\t1,1,') or
            line.startswith('lmw\t') or
            (line.startswith('lfd\t') and '(1)' in line) or
            (re.match(r'lwz\t\d+,\d+\(1\)', line) is not None) or
            line.startswith('.L_'))


def extract_func_sig(block):
    """Extract the C++ function signature from the block."""
    m = re.search(r'^(__attribute__\(\(noreturn\)\)\s*\n)?(.+?)\s*\{',
                  block, re.MULTILINE)
    if m:
        sig = m.group(2).strip()
        return sig
    return None


def get_return_type(sig):
    """Extract return type from a function signature."""
    if not sig:
        return 'void'
    # Match common return types before the class::method part
    m = re.match(r'((?:const\s+)?(?:unsigned\s+)?(?:signed\s+)?'
                 r'(?:void|int|bool|float|double|char|short|long|'
                 r'\w+\s*[*&]|\w+))\s+(?:\w+::)+', sig)
    if m:
        return m.group(1).strip()
    return 'void'


def parse_func_name(full_name):
    """Parse 'ClassName::MethodName(params)' -> (class, method, params_str)"""
    # Handle nested classes like ActionMenu::MenuItem::Method
    m = re.match(r'((?:\w+::)*\w+)::(\w+|operator\S+|~\w+)(\(.*\))', full_name)
    if m:
        return m.group(1), m.group(2), m.group(3)
    m = re.match(r'(\w+)(\(.*\))', full_name)
    if m:
        return None, m.group(1), m.group(2)
    return None, full_name, '()'


def get_prologue_end(lines):
    """Find the end of the function prologue."""
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
                r'\.long\s+0x4[0-9a-fA-F]{7}\s+/\*\s*bl\s+(.+?)\s*\*/',
                block)
            if len(bl_calls) < 1 or len(bl_calls) > 2:
                continue

            lines = extract_asm_lines(block)
            if not lines or 'blr' not in lines:
                continue

            # Skip indirect calls (blrl)
            if any(l == 'blrl' for l in lines):
                continue

            # Find bl and blr positions
            bl_positions = [i for i, l in enumerate(lines)
                            if l.startswith('.long') and '/* bl' in l]
            blr_idx = lines.index('blr')

            # Post-last-bl must be epilogue only
            last_bl = bl_positions[-1]
            post_bl = lines[last_bl + 1:blr_idx]
            if not all(is_epilogue(l) for l in post_bl):
                continue

            # Count branches
            cond_branches = sum(
                1 for l in lines
                if re.match(r'b(eq|ne|lt|gt|le|ge|dnz|dz)\t', l))
            uncond_b = sum(
                1 for l in lines if re.match(r'b\t\.L_', l))

            # Classify
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


def try_convert_to_cpp(info):
    """
    Try to convert a wrapper function to real C++.

    Returns (cpp_code, confidence) where confidence is:
      'high' - we're confident the conversion is correct
      'medium' - likely correct but may need review
      None - can't convert, use asm fallback
    """
    lines = info['lines']
    name = info['name']
    bl_calls = info['bl_calls']
    bl_positions = info['bl_positions']
    pattern = info['pattern']
    func_sig = info['func_sig']

    if not func_sig:
        return None, None

    wrapper_class, wrapper_method, wrapper_params_str = parse_func_name(name)
    is_member = wrapper_class is not None
    ret_type = get_return_type(func_sig)
    prologue_end = get_prologue_end(lines)

    # ================================================================
    # PATTERN: 2 calls, no branches - sequential call chains
    # ================================================================
    if pattern == '2bl_no_branch':
        target1 = bl_calls[0]
        target2 = bl_calls[1]
        t1_class, t1_method, t1_params = parse_func_name(target1)
        t2_class, t2_method, t2_params = parse_func_name(target2)
        middle_before = lines[prologue_end:bl_positions[0]]
        middle_between = lines[bl_positions[0] + 1:bl_positions[1]]

        # Sub-pattern: save this to callee-saved reg, call1, restore this, call2
        # This is: call1(...); this->call2(...);
        # Detect: mr 30, 3 (save this) ... bl call1 ... mr 3, 30 (restore this) ... bl call2

        # Find which reg 'this' was saved to
        this_saved_to = None
        for line in middle_before:
            m = re.match(r'mr\t(\d+),3$', line)
            if m:
                saved_reg = int(m.group(1))
                if saved_reg >= 14:  # callee-saved reg
                    this_saved_to = saved_reg
                    break

        # Check if r3 is restored from saved reg between calls
        r3_restored = False
        for line in middle_between:
            if this_saved_to and re.match(rf'mr\t3,{this_saved_to}$', line):
                r3_restored = True
                break

        # Check if call1 is on self (r3 = this at call1 point)
        call1_on_self = True
        for line in middle_before:
            m = re.match(r'mr\t3,', line)
            if m and not re.match(r'mr\t3,3$', line):
                # r3 was changed to something else
                # Check if it was changed back
                call1_on_self = False
            m = re.match(r'lwz\t3,', line)
            if m:
                call1_on_self = False
            m = re.match(r'addi\t3,', line)
            if m:
                call1_on_self = False
            m = re.match(r'li\t3,', line)
            if m:
                call1_on_self = False
            m = re.match(r'lis\t3,', line)
            if m:
                call1_on_self = False

        # Sub-pattern: Two self-calls with no side effects
        # Like: Wrapper::WrapperReset(); DialogPaneShow();
        if call1_on_self and r3_restored:
            # Check for side-effect stores before first call
            stores_before = [l for l in middle_before
                             if re.match(r'st[wbhfs]+\t', l) and '(1)' not in l]

            if not stores_before:
                # Pure two-call forwarding
                call1_name = t1_method if t1_class == wrapper_class else target1.split('(')[0]
                call2_name = t2_method if t2_class == wrapper_class else target2.split('(')[0]

                body = f'{call1_name}(); {call2_name}();'
                if ret_type != 'void':
                    body = f'{call1_name}(); return {call2_name}();'
                code = f"// {info['addr']} ({info['size']} bytes)\n{func_sig} {{ {body} }}"
                return code, 'high'
            else:
                # Has side effects before first call - still convertible but lower confidence
                call1_name = target1.split('(')[0]
                call2_name = target2.split('(')[0]
                body = f'{call1_name}(/* ... */); {call2_name}(/* ... */);'
                code = f"// {info['addr']} ({info['size']} bytes)\n{func_sig} {{ {body} }}"
                return code, 'medium'

        # Sub-pattern: call1 returns value, used as arg to call2
        # Like: r3 = CalcId(name); DelRef(r3, mode);
        if not call1_on_self and r3_restored is False:
            # call1 result (r3) might be passed to call2
            # Check if r3 from call1 is moved to another arg reg for call2
            r3_moved_to = None
            for line in middle_between:
                m = re.match(r'mr\t(\d+),3$', line)
                if m:
                    r3_moved_to = int(m.group(1))

            call1_name = target1.split('(')[0]
            call2_name = target2.split('(')[0]

            if r3_moved_to is not None:
                body = f'auto tmp = {call1_name}(/* ... */); {call2_name}(/* ..., tmp, ... */);'
            else:
                body = f'{call1_name}(/* ... */); {call2_name}(/* ... */);'
            code = f"// {info['addr']} ({info['size']} bytes)\n{func_sig} {{ {body} }}"
            return code, 'medium'

    # ================================================================
    # PATTERN: 1 call, no branches - direct forwarding
    # ================================================================
    if pattern == '1bl_no_branch':
        target = bl_calls[0]
        t_class, t_method, t_params = parse_func_name(target)
        middle = lines[prologue_end:bl_positions[0]]

        # Track r3 through the middle section
        r3_val = 'this' if is_member else 'arg0'
        r3_modified = False
        has_side_effects = False  # stores to non-stack memory

        for line in middle:
            # Check for r3 modifications
            if re.match(r'mr\t3,', line) or re.match(r'lwz\t3,', line) or \
               re.match(r'addi\t3,', line) or re.match(r'li\t3,', line) or \
               re.match(r'lis\t3,', line):
                r3_modified = True

            # Check for side-effect stores (not to stack)
            if re.match(r'st[wbhfs]+\t', line) and '(1)' not in line:
                has_side_effects = True

        # Sub-pattern: r3 unchanged, calling method on self
        if not r3_modified and is_member:
            # Check if it's the same class or parent class
            if t_class and t_class == wrapper_class:
                call_name = t_method
            else:
                call_name = target.split('(')[0]

            # Check what other args are set up
            # For simple forwarding, all params just pass through
            if not has_side_effects and len(middle) <= 3:
                if ret_type != 'void':
                    body = f'return {call_name}();'
                else:
                    body = f'{call_name}();'
                code = f"// {info['addr']} ({info['size']} bytes)\n{func_sig} {{ {body} }}"
                return code, 'high'

        # Sub-pattern: r3 loaded from this->field (calling method on member)
        if r3_modified and is_member:
            # Check if r3 is loaded from a field
            field_load = None
            for line in middle:
                m = re.match(r'lwz\t3,(-?\d+)\(3\)$', line)
                if m:
                    field_load = int(m.group(1))

            if field_load is not None and not has_side_effects:
                call_name = target.split('(')[0]
                field_expr = f'*(void**)((char*)this + {field_load:#x})'
                body = f'(({t_class}*){field_expr})->{t_method}();' if t_class else f'{call_name}({field_expr});'
                code = f"// {info['addr']} ({info['size']} bytes)\n{func_sig} {{ {body} }}"
                return code, 'medium'

    # ================================================================
    # PATTERN: 1 call with branches - conditional calls
    # ================================================================
    if pattern == '1bl_with_branch':
        target = bl_calls[0]
        call_name = target.split('(')[0]

        # For now, mark these as medium confidence with asm
        code = (f"// {info['addr']} ({info['size']} bytes)\n"
                f"// Conditional wrapper: calls {target}")
        return code, None  # Fall through to asm

    # ================================================================
    # PATTERN: 2 calls with branches
    # ================================================================
    if pattern == '2bl_with_branch':
        targets = ', '.join(bl_calls)
        code = (f"// {info['addr']} ({info['size']} bytes)\n"
                f"// Conditional wrapper: calls {targets}")
        return code, None  # Fall through to asm

    return None, None


def generate_output(info, cpp_code, confidence):
    """Generate final output for a function.

    If we have confident C++ code, use that.
    Otherwise, preserve the asm with documentation.
    """
    func_sig = info['func_sig']
    if not func_sig:
        return None

    bl_calls = info['bl_calls']
    targets_str = ', '.join(bl_calls)

    if confidence in ('high', 'medium'):
        # Real C++ conversion
        conf_tag = 'CONFIDENT' if confidence == 'high' else 'REVIEW'
        return f"// [{conf_tag}] {cpp_code}\n"

    # Asm fallback with documentation
    asm_body = extract_asm_body(info['block'])
    if not asm_body:
        return None

    output_lines = [
        f"// {info['addr']} ({info['size']} bytes)",
        f"// Call wrapper [{info['pattern']}]: {targets_str}",
        f"__attribute__((noreturn))",
        f"{func_sig} {{",
        f"    {asm_body}",
        f"    __builtin_unreachable();",
        f"}}",
    ]
    return '\n'.join(output_lines)


def main():
    print("=" * 60)
    print("Sims 2 GC Decomp: Call Wrapper Converter")
    print("=" * 60)
    print()

    print("Scanning asm_decomp for wrapper functions...")
    all_wrappers, stats = scan_all_wrappers()

    print(f"\nFound {stats.get('total', 0)} wrapper functions:")
    for k, v in sorted(stats.items()):
        if k != 'total':
            print(f"  {k}: {v}")
    print(f"Across {len(all_wrappers)} source files")

    # Attempt conversions
    conversions = defaultdict(list)  # fname -> [(info, cpp, confidence)]
    conv_stats = defaultdict(int)

    for source_file, func_list in sorted(all_wrappers.items()):
        for info in func_list:
            cpp_code, confidence = try_convert_to_cpp(info)
            conversions[source_file].append((info, cpp_code, confidence))
            if confidence == 'high':
                conv_stats['high_confidence'] += 1
            elif confidence == 'medium':
                conv_stats['medium_confidence'] += 1
            else:
                conv_stats['asm_preserved'] += 1

    print(f"\nConversion results:")
    print(f"  High confidence C++: {conv_stats['high_confidence']}")
    print(f"  Medium confidence C++: {conv_stats['medium_confidence']}")
    print(f"  Asm preserved (documented): {conv_stats['asm_preserved']}")

    # Write output files
    files_written = 0
    total_funcs = 0
    skipped = 0

    for source_file, conv_list in sorted(conversions.items()):
        base_name = source_file.replace('.cpp', '')
        out_name = f"{base_name}_call_converted.cpp"
        out_path = os.path.join(MATCHED_DIR, out_name)

        if os.path.exists(out_path):
            skipped += 1
            continue

        output_parts = [
            '#include "types.h"',
            '#include "stub_classes.h"',
            f'// Auto-converted call wrapper stubs for {base_name}',
            f'// Generated by convert_call_wrappers.py',
            f'// Functions that wrap 1-2 function calls',
            '',
        ]

        func_count = 0
        for info, cpp_code, confidence in conv_list:
            output = generate_output(info, cpp_code, confidence)
            if output:
                output_parts.append(output)
                output_parts.append('')
                func_count += 1

        if func_count > 0:
            with open(out_path, 'w', newline='\r\n') as f:
                f.write('\n'.join(output_parts))
            files_written += 1
            total_funcs += func_count

    print(f"\nOutput:")
    print(f"  Files written: {files_written}")
    print(f"  Functions: {total_funcs}")
    if skipped:
        print(f"  Files skipped (already exist): {skipped}")

    return 0


if __name__ == '__main__':
    sys.exit(main())
