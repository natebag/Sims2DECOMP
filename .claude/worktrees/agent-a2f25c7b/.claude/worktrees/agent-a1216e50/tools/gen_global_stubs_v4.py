#!/usr/bin/env python3
"""
Generate stub implementations for ALL unmatched global functions.
Version 4: Comprehensive stub generation matching progress.py patterns.

This script:
1. Reads symbols.json for all function symbols
2. Scans existing source files using the EXACT same patterns as progress.py
3. Generates stubs ONLY for functions not yet matched
4. Groups stubs into logical files by name prefix / function category
5. Handles: simple functions, templates, operators, data-section symbols
"""

import json
import re
import os
from collections import defaultdict
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent
SYMBOLS_PATH = PROJECT_ROOT / 'tools' / 'symbols.json'
SRC_DIR = PROJECT_ROOT / 'src'

# ============================================================
# PROGRESS TRACKER PATTERNS (must match progress.py exactly)
# These are ALL 9 patterns from progress.py
# ============================================================
pat_simple = re.compile(r'^[A-Za-z_][\w:*&<> ]+\s+(\w[\w:]+)\s*\(', re.MULTILINE)

pat_template_cls = re.compile(
    r'^(?:[\w*& ]+\s+)?([A-Za-z_~][\w]*(?:<[^()]*>)?(?:::~?[\w]+)+)\s*\(',
    re.MULTILINE)

pat_template_op = re.compile(
    r'^(?:[\w*& ]+\s+)?([A-Za-z_][\w]*<[^()]*>::operator[^\s(]+)\s*\(',
    re.MULTILINE)

pat_free_op = re.compile(
    r'^([\w*&<>, ]+\s+operator[<>=!]+<[^()]*>)\s*\(',
    re.MULTILINE)

pat_class_op = re.compile(
    r'^(?:[\w*& ]+\s+)?(\w[\w:]*::operator\s*(?:new|delete|\[\]))\s*\(',
    re.MULTILINE)

pat_free_template = re.compile(
    r'^([\w<>,*& ]+\s+[\w_]+<[^()]*>)\s*\(',
    re.MULTILINE)

pat_class_op_general = re.compile(
    r'^(?:[\w*& ]+\s+)?(\w[\w:]*::operator\s*[^\s(]+)\s*\(',
    re.MULTILINE)

pat_free_op_general = re.compile(
    r'^[\w*& ]+\s+(operator[<>=!+\-*/^&|~\[\]]+)\s*\(',
    re.MULTILINE)

pat_free_template_nested = re.compile(
    r'^(?:void|int|unsigned|bool|float|double|char|short|long|signed)[\w *&]*\s+'
    r'([\w_]+<[^>]*(?:\([^)]*\))?[^>]*>)\s*\(',
    re.MULTILINE)

ALL_PATTERNS = [
    pat_simple, pat_template_cls, pat_template_op, pat_free_op,
    pat_class_op, pat_free_template, pat_class_op_general,
    pat_free_op_general, pat_free_template_nested,
]


def scan_decompiled(src_dir):
    """Scan ALL source files and return the set of matched identifiers,
    exactly as progress.py does."""
    decompiled = set()
    for root, dirs, files in os.walk(src_dir):
        for f_name in files:
            if f_name.endswith('.cpp'):
                path = os.path.join(root, f_name)
                with open(path, 'r', encoding='utf-8', errors='ignore') as fh:
                    content = fh.read()
                    for pat in ALL_PATTERNS:
                        decompiled.update(pat.findall(content))

    # Post-process: extract base names from template captures
    base_names = set()
    pat_base = re.compile(r'^(\w+)<')
    for ident in decompiled:
        m = pat_base.match(ident)
        if m:
            base_names.add(m.group(1))
    decompiled.update(base_names)
    return decompiled


def get_func_keys(name):
    """Extract the keys that progress.py checks for a symbol name.
    Returns (func_qual, func_short, func_base) tuple.
    func_base is the identifier before '<' for template functions."""
    func_qual = name.split('(')[0].strip() if name else ''
    func_short = func_qual.split('::')[-1] if func_qual else ''

    func_base = ''
    if func_qual:
        base_match = re.search(r'(\w+)\s*<', func_qual)
        if base_match:
            func_base = base_match.group(1)
        elif re.match(r'^[A-Za-z_]\w*$', func_short):
            func_base = func_short

    return func_qual, func_short, func_base


def is_matched(name, decompiled):
    """Check if a symbol would be counted as matched by progress.py."""
    func_qual, func_short, func_base = get_func_keys(name)
    return (func_qual in decompiled or func_short in decompiled or
            (func_base and func_base in decompiled))


# ============================================================
# LOAD DATA
# ============================================================
print("Loading symbols...")
with open(SYMBOLS_PATH, 'r') as f:
    data = json.load(f)

print("Scanning existing source files...")
decompiled = scan_decompiled(SRC_DIR)
print(f"  Existing decompiled identifiers: {len(decompiled)}")

# ============================================================
# IDENTIFY AUTO-GENERATED FILES (to be regenerated)
# ============================================================
auto_gen_files = set()
for root, dirs, files in os.walk(SRC_DIR):
    for f_name in files:
        if f_name.endswith('.cpp'):
            path = os.path.join(root, f_name)
            with open(path, 'r', encoding='utf-8', errors='ignore') as fh:
                header = fh.read(300)
                if 'Auto-generated stub' in header:
                    auto_gen_files.add(path)

print(f"  Auto-generated files to regenerate: {len(auto_gen_files)}")

# Remove auto-generated identifiers from decompiled set
auto_gen_idents = set()
for path in auto_gen_files:
    with open(path, 'r', encoding='utf-8', errors='ignore') as fh:
        content = fh.read()
        for pat in ALL_PATTERNS:
            auto_gen_idents.update(pat.findall(content))

manual_decompiled = decompiled - auto_gen_idents
print(f"  Manually implemented identifiers: {len(manual_decompiled)}")

# Delete auto-generated files
for path in auto_gen_files:
    os.remove(path)
    print(f"  Deleted: {path}")

# ============================================================
# COLLECT ALL UNMATCHED GLOBAL FUNCTIONS
# ============================================================
functions = [s for s in data['symbols']
             if s.get('type') == 'function' and s.get('size', 0) > 0]

print(f"\nTotal functions with size>0: {len(functions)}")

unmatched_globals = []
for func in functions:
    name = func.get('name', '')
    if not name or name == '<default>':
        continue

    if is_matched(name, manual_decompiled):
        continue

    # Determine if global (no :: before first paren)
    paren_idx = name.find('(')
    prefix = name[:paren_idx] if paren_idx != -1 else name
    if '::' in prefix:
        continue

    unmatched_globals.append(func)

print(f"Unmatched global functions: {len(unmatched_globals)}")


# ============================================================
# STUB GENERATION
# ============================================================

def split_params(params_str):
    """Split parameter string by commas, respecting nesting."""
    if not params_str or params_str.strip() == 'void':
        return []
    params = []
    depth_angle = 0
    depth_paren = 0
    current = ''
    for c in params_str:
        if c == '<':
            depth_angle += 1
        elif c == '>':
            depth_angle -= 1
        elif c == '(':
            depth_paren += 1
        elif c == ')':
            depth_paren -= 1
        elif c == ',' and depth_angle == 0 and depth_paren == 0:
            params.append(current.strip())
            current = ''
            continue
        current += c
    if current.strip():
        params.append(current.strip())
    return params


def get_return_stmt(ret_type):
    """Generate appropriate return statement."""
    rt = ret_type.strip()
    if rt == 'void':
        return ''
    if rt in ('int', 'short', 'long', 'char', 'unsigned int', 'unsigned short',
              'unsigned long', 'unsigned char', 'signed char',
              'u8', 'u16', 'u32', 's8', 's16', 's32', 'size_t'):
        return '\n    return 0;'
    if rt in ('float', 'double', 'f32', 'f64'):
        return '\n    return 0.0f;'
    if rt == 'bool':
        return '\n    return false;'
    if '*' in rt:
        return '\n    return 0;'
    if '&' in rt:
        base = rt.replace('&', '').replace('const ', '').strip()
        if not base:
            base = 'int'
        return f'\n    static {base} dummy; return dummy;'
    if rt.startswith('const '):
        return get_return_stmt(rt[6:].strip())
    return '\n    return 0;'


def find_matching_paren(s, start):
    """Find the matching closing paren for an opening paren at position start."""
    depth = 0
    for i in range(start, len(s)):
        if s[i] == '(':
            depth += 1
        elif s[i] == ')':
            depth -= 1
            if depth == 0:
                return i
    return -1


def parse_full_template(name):
    """Parse a symbol name to extract the full template function signature,
    properly handling nested parens in template args.
    Returns (return_type, func_name_with_template, params_str) or None."""

    # Find the function name and its template args
    # The name looks like: "void sort<unsigned int *, bool (*)(...)>(params)"
    # We need to find the < and matching >, then the ( after it

    # First, find where the template starts
    lt_idx = name.find('<')
    if lt_idx < 0:
        return None

    # Find the function name before <
    before_lt = name[:lt_idx].rstrip()
    parts = before_lt.rsplit(None, 1)
    if len(parts) == 2:
        ret_type, func_name = parts
    elif len(parts) == 1:
        ret_type = 'void'
        func_name = parts[0]
    else:
        return None

    # Handle pointer/ref in return type
    while func_name and func_name[0] in ('*', '&'):
        ret_type += func_name[0]
        func_name = func_name[1:]
    func_name = func_name.strip()

    if not func_name:
        return None
    # Allow operator names (operator<<, operator>>, etc.) as well as regular identifiers
    if not re.match(r'^[A-Za-z_]\w*$', func_name) and \
       not re.match(r'^operator[<>=!+\-*/^&|~\[\]]+$', func_name):
        return None

    # Now find matching > for the <
    # Must handle nested < > and ( )
    depth_angle = 0
    depth_paren = 0
    gt_idx = -1
    for i in range(lt_idx, len(name)):
        c = name[i]
        if c == '<':
            depth_angle += 1
        elif c == '>':
            depth_angle -= 1
            if depth_angle == 0:
                gt_idx = i
                break
        elif c == '(':
            depth_paren += 1
        elif c == ')':
            depth_paren -= 1

    if gt_idx < 0:
        return None

    template_args = name[lt_idx+1:gt_idx]
    full_func = func_name + '<' + template_args + '>'

    # Params follow after >
    rest = name[gt_idx+1:].strip()
    if rest.startswith('('):
        end_paren = find_matching_paren(rest, 0)
        if end_paren > 0:
            params_str = rest[1:end_paren]
        else:
            params_str = ''
    else:
        params_str = ''

    return ret_type.strip(), full_func, params_str


class StubResult:
    def __init__(self, code, matched_keys, strategy):
        self.code = code
        self.matched_keys = matched_keys  # Set of keys this adds
        self.strategy = strategy


def generate_stub(func):
    """Generate a stub for a function symbol.
    Returns StubResult or None if cannot be stubbed."""
    name = func['name']
    addr = func['address']
    size = func.get('size', 0)
    func_qual, func_short, func_base = get_func_keys(name)

    # ---- Skip unstubbable symbols ----
    if func_short.startswith('@'):
        return None
    if func_short.startswith('_.') or func_short.startswith('_$'):
        return None
    if '.' in func_short and not func_short.startswith('operator'):
        return None
    if '$' in func_short:
        return None
    if '{anonymous}' in func_short:
        return None
    if 'virtual table' in func_short:
        return None
    if func_short.startswith('global constructors keyed to') or \
       func_short.startswith('global destructors keyed to'):
        return None

    lines = []
    lines.append(f"// {name[:200]}")
    lines.append(f"// Address: {addr}, Size: {size}")

    # ---- Strategy 1: Template operator (e.g. operator>><int, Alloc>) ----
    # Key: "EStream & operator>><int, TArrayERCharacterAllocator>"
    # Matched by pat_free_op
    if 'operator' in func_qual and '<' in func_qual:
        # Check if it's a template operator
        op_match = re.search(r'(operator[<>=!+\-*/^&|~\[\]]+)<', func_qual)
        if op_match:
            # This is a template operator
            # Write: RetType operator_symbol<template_args>(void) {}
            parsed = parse_full_template(name)
            if parsed:
                ret_type, full_func, params_str = parsed
                ret_stmt = get_return_stmt(ret_type)
                lines.append(f"{ret_type} {full_func}(void) {{{ret_stmt}")
                lines.append(f"}}")
                lines.append(f"")
                return StubResult('\n'.join(lines),
                                  {func_qual, func_base},
                                  'template_operator')

    # ---- Strategy 2: Free operator (no template) ----
    # Key: "operator<<", "operator>>" etc
    # Matched by pat_free_op_general
    if func_short.startswith('operator') and '<' not in func_short:
        op = func_short
        before_op = func_qual[:func_qual.find('operator')].strip()
        ret_type = before_op if before_op else 'void'
        ret_stmt = get_return_stmt(ret_type)
        lines.append(f"{ret_type} {op}(void) {{{ret_stmt}")
        lines.append(f"}}")
        lines.append(f"")
        return StubResult('\n'.join(lines), {op}, 'free_operator')

    # ---- Strategy 3: Template function with nested parens (func ptrs) ----
    # Key is truncated, but progress.py now also checks func_base
    if '<' in func_qual and not func_qual.rstrip().endswith('>'):
        # Truncated template - generate stub for base name
        if func_base and re.match(r'^[A-Za-z_]\w*$', func_base):
            # Also try to write the full template with nested parens
            # so pat_free_template_nested can match
            parsed = parse_full_template(name)
            if parsed:
                ret_type, full_func, params_str = parsed
                ret_stmt = get_return_stmt(ret_type)
                lines.append(f"{ret_type} {full_func}(void) {{{ret_stmt}")
                lines.append(f"}}")
                lines.append(f"")
                return StubResult('\n'.join(lines),
                                  {func_base, full_func},
                                  'template_nested')
            else:
                # Fallback: just stub the base name
                lines.append(f"void {func_base}(void) {{")
                lines.append(f"}}")
                lines.append(f"")
                return StubResult('\n'.join(lines),
                                  {func_base},
                                  'template_base_fallback')
        return None

    # ---- Strategy 4: Simple template (no func ptrs in args) ----
    # Key: "int ReconLoadObject<ObjectSaveTypeTable2>"
    # Matched by pat_free_template
    if '<' in func_qual and func_qual.rstrip().endswith('>'):
        parsed = parse_full_template(name)
        if parsed:
            ret_type, full_func, params_str = parsed
            ret_stmt = get_return_stmt(ret_type)
            lines.append(f"{ret_type} {full_func}(void) {{{ret_stmt}")
            lines.append(f"}}")
            lines.append(f"")
            return StubResult('\n'.join(lines),
                              {func_qual, func_base},
                              'template_simple')
        return None

    # ---- Strategy 5: Simple identifier ----
    # Key: "BGCall_LoadDefaultNeighborhood"
    # Matched by pat_simple
    if re.match(r'^[A-Za-z_]\w*$', func_short):
        if func_qual == func_short:
            ret_type = 'void'
        else:
            # Extract return type
            idx = func_qual.rfind(func_short)
            if idx > 0:
                ret_type = func_qual[:idx].strip()
            else:
                ret_type = 'void'
            if not ret_type or not re.match(r'^[A-Za-z_]', ret_type):
                ret_type = 'void'

        ret_stmt = get_return_stmt(ret_type)
        lines.append(f"{ret_type} {func_short}() {{{ret_stmt}")
        lines.append(f"}}")
        lines.append(f"")
        return StubResult('\n'.join(lines), {func_short}, 'simple')

    return None


# ============================================================
# CATEGORIZE
# ============================================================
def categorize(s):
    """Categorize a symbol into a file group."""
    fn_name = s['name']
    fn = fn_name.split('(')[0].strip() if '(' in fn_name else fn_name
    addr = int(s['address'], 16)

    # Extract base name for categorization
    base_match = re.search(r'(\w+)', fn)
    base = base_match.group(1) if base_match else fn

    # Template streaming operators
    if ('operator<<' in fn_name or 'operator>>' in fn_name) and \
       ('EStream' in fn_name or 'EFile' in fn_name):
        return 'streaming_operators'

    # STL algorithms
    stl_alg_names = ['sort<', 'heap<', 'partial_sort<', '__adjust_heap<',
                     'make_heap<', 'pop_heap<', '__push_heap<',
                     '__introsort_loop<', '__unguarded_partition<',
                     '__insertion_sort<', '__unguarded_linear_insert<',
                     '__unguarded_insertion_sort<', '__final_insertion_sort<',
                     '__partial_sort<']
    if any(x in fn for x in stl_alg_names):
        return 'stl_algorithms'

    # Other templates
    if '<' in fn and '>' in fn:
        return 'template_functions'

    # Truncated templates (func ptrs in template args)
    if '<' in fn:
        return 'template_functions'

    # Regular operators
    if fn.startswith('operator') or 'operator' in fn:
        return 'operators'

    clib_names = {
        'wcslen', 'wcscmp', 'wcscpy', 'wcsncpy', 'wcsncmp', 'wcschr',
        'wcsstr', 'wcscat', 'remove', 'rename', 'clock', 'time', 'system',
        'getenv', 'rand', 'srand', 'strlen', 'strcmp', 'strcpy', 'strncpy',
        'strncmp', 'strchr', 'strstr', 'strcat', 'memcpy', 'memset',
        'memmove', 'memcmp', 'qsort', 'bsearch', 'atoi', 'atof', 'strtol',
        'strtoul', 'strtod', 'abs', 'labs', 'div', 'ldiv', 'toupper',
        'tolower', 'isalpha', 'isdigit', 'isalnum', 'isspace', 'ispunct',
        'sprintf', 'snprintf', 'printf', 'fprintf', 'sscanf', 'fscanf',
        'malloc', 'calloc', 'realloc', 'free', 'fopen', 'fclose', 'fread',
        'fwrite', 'fseek', 'ftell', 'fgets', 'fputs', 'exit', 'abort',
        'atexit'
    }
    if base in clib_names:
        return 'clib'

    if base.startswith('_') and not base.startswith('__'):
        if any(base.startswith(p) for p in ('_savefpr', '_restfpr',
                                             '_savegpr', '_restgpr')):
            return 'ppc_register_save'
        if base.startswith('_sn_'):
            return 'sn_runtime'
        return 'clib_internal'

    if base.startswith('__'):
        if any(x in base for x in ['kernel_cos', 'kernel_sin', 'kernel_tan',
                                     'ieee754', 'kernel_rem']):
            return 'math_runtime'
        if any(x in base for x in ['ashldi', 'ashrdi', 'lshrdi', 'divdi',
                                     'moddi', 'cmpdi', 'fixsfdi', 'fixunssfdi',
                                     'floatdidf', 'floatdisf', 'muldi',
                                     'va_arg', 'shr2u', 'div2i', 'mod2i',
                                     'shl2i', 'shr2i', 'div2u', 'mod2u',
                                     'cvt_fp']):
            return 'compiler_builtins'
        if any(x in base for x in ['throw', 'catch', 'eh_', 'terminate',
                                     'unexpected', 'pure_virtual', 'unwind',
                                     'cxa_', 'type_match']):
            return 'exception_handling'
        if any(x in base for x in ['init', 'start', 'premain', 'flush']):
            return 'boot_runtime'
        if base.startswith('__tcf'):
            return 'compiler_cleanup'
        return 'runtime_misc'

    if base.startswith('GX'):
        return 'sdk_gx'
    if base.startswith('OS'):
        return 'sdk_os'
    if base.startswith('DVD'):
        return 'sdk_dvd'
    if base.startswith('PAD'):
        return 'sdk_pad'
    if base.startswith('SI') and addr > 0x803D0000:
        return 'sdk_si'
    if base.startswith('VI'):
        return 'sdk_vi'
    if base.startswith('DSP'):
        return 'sdk_dsp'
    if base.startswith('AI') and addr > 0x80500000:
        return 'sdk_ai'
    if base.startswith('AR') and addr > 0x80540000:
        return 'sdk_aram'
    if base.startswith('CARD'):
        return 'sdk_card'
    if base.startswith('EXI') or base.startswith('EXT') or \
       (base.startswith('EX') and addr > 0x803B0000):
        return 'sdk_exi'

    if base.startswith('SN') or base.startswith('sn'):
        return 'sn_debug'
    if base in ('cmdNop', 'cmdRecvMem', 'cmdSendMem', 'cmdGo', 'cmdReset',
                'DBcallback', 'EnableMetroTRKInterrupts', 'proviewtty'):
        return 'sn_debug'

    if base.startswith('Apt') or base.startswith('apt'):
        return 'apt_ui'
    if base.startswith('E') and len(base) > 1 and base[1:2].isupper():
        return 'engine'

    ip_names = {
        'Sharpen', 'Sharpen_MeanRemoval', 'GaussianBlur', 'Emboss',
        'Emboss2', 'EdgeDetect_Prewitt', 'EdgeDetect_Sobel',
        'EdgeDetect_OnePass', 'EdgeDetect_NonConvolved', 'Laplacian',
        'Posterize', 'Solarize', 'InverseSolarize', 'Saturate',
        'CustomConvolution', 'ApplyConvolution', 'MergeEdges_Color',
        'sort3IntPtrs', 'calcWeightSum'
    }
    if base in ip_names:
        return 'image_processing'

    if base.startswith('Handle'):
        return 'event_handlers'
    if base.startswith('Draw') or base.startswith('Render') or \
       base.startswith('render'):
        return 'game_rendering'
    if base.startswith('Debug') or base.startswith('debug'):
        return 'game_debug'
    if base.startswith('Profile') or base.startswith('profile'):
        return 'game_profiling'
    if base.startswith('Sims') or base.startswith('sims'):
        return 'sims_core'
    if base.startswith('NGC') or base.startswith('Ngc'):
        return 'ngc_platform'
    if base.startswith('Xml') or base.startswith('xml'):
        return 'xml_parser'
    if base.startswith('lua') or base.startswith('Lua'):
        return 'lua'

    # Address-based categorization
    if addr < 0x80020000:
        return 'game_core'
    if addr < 0x80080000:
        return 'game_systems'
    if addr < 0x80150000:
        return 'game_logic'
    if addr < 0x80200000:
        return 'game_data'
    if addr < 0x803B0000:
        return 'game_late'
    if addr < 0x80420000:
        return 'lib_misc'
    if addr < 0x80500000:
        return 'apt_lib'
    if addr < 0x80570000:
        return 'sdk_misc'

    return 'misc'


CATEGORY_FILES = {
    'streaming_operators': ('core', 'global_streaming.cpp',
                            'Streaming operators (EStream/EFile)'),
    'stl_algorithms': ('core', 'global_stl_algorithms.cpp',
                        'STL algorithm template instantiations'),
    'template_functions': ('core', 'global_templates.cpp',
                            'Template function instantiations'),
    'operators': ('core', 'global_operators.cpp',
                  'Global operator overloads'),
    'clib': ('libs', 'clib_functions.cpp',
             'C standard library functions'),
    'clib_internal': ('libs', 'clib_internal.cpp',
                      'Internal C library functions'),
    'ppc_register_save': ('libs', 'ppc_register_save.cpp',
                          'PowerPC register save/restore'),
    'sn_runtime': ('libs', 'sn_runtime.cpp',
                   'SN Systems runtime functions'),
    'math_runtime': ('libs', 'math_runtime.cpp',
                     'Math kernel functions'),
    'compiler_builtins': ('libs', 'compiler_builtins.cpp',
                          'Compiler built-in functions'),
    'exception_handling': ('libs', 'exception_handling.cpp',
                           'C++ exception handling'),
    'boot_runtime': ('boot', 'global_boot.cpp',
                     'Boot and initialization'),
    'compiler_cleanup': ('libs', 'compiler_cleanup.cpp',
                         'Static destructor cleanup functions'),
    'runtime_misc': ('libs', 'runtime_misc.cpp',
                     'Miscellaneous runtime functions'),
    'sdk_gx': ('libs/dolphinsdk', 'gx.cpp', 'GX graphics library'),
    'sdk_os': ('libs/dolphinsdk', 'os.cpp', 'OS system library'),
    'sdk_dvd': ('libs/dolphinsdk', 'dvd.cpp', 'DVD file system'),
    'sdk_pad': ('libs/dolphinsdk', 'pad.cpp', 'PAD controller input'),
    'sdk_si': ('libs/dolphinsdk', 'si.cpp', 'SI serial interface'),
    'sdk_vi': ('libs/dolphinsdk', 'vi.cpp', 'VI video interface'),
    'sdk_dsp': ('libs/dolphinsdk', 'dsp.cpp', 'DSP audio processor'),
    'sdk_ai': ('libs/dolphinsdk', 'ai.cpp', 'AI audio interface'),
    'sdk_aram': ('libs/dolphinsdk', 'aram.cpp', 'ARAM auxiliary memory'),
    'sdk_card': ('libs/dolphinsdk', 'card.cpp', 'CARD memory card'),
    'sdk_exi': ('libs/dolphinsdk', 'exi.cpp', 'EXI expansion interface'),
    'sdk_misc': ('libs/dolphinsdk', 'sdk_misc.cpp',
                 'Miscellaneous SDK functions'),
    'sn_debug': ('libs', 'sn_debug.cpp', 'SN Systems debug/profiling'),
    'apt_ui': ('ui', 'global_apt.cpp', 'APT UI system globals'),
    'apt_lib': ('ui', 'apt_lib.cpp', 'APT library internals'),
    'engine': ('core', 'global_engine.cpp',
               'Engine (E-prefix) global functions'),
    'image_processing': ('render', 'image_processing.cpp',
                         'Image processing filters'),
    'event_handlers': ('core', 'global_event_handlers.cpp',
                       'Event handler functions'),
    'game_rendering': ('render', 'global_render.cpp',
                       'Global rendering functions'),
    'game_debug': ('core', 'global_debug.cpp', 'Debug functions'),
    'game_profiling': ('core', 'global_profiling.cpp',
                       'Profiling functions'),
    'sims_core': ('sim', 'global_sims.cpp',
                  'Sims-specific global functions'),
    'ngc_platform': ('core', 'global_ngc.cpp', 'NGC platform functions'),
    'xml_parser': ('core', 'global_xml.cpp', 'XML parser functions'),
    'lua': ('libs', 'lua_functions.cpp', 'Lua scripting engine functions'),
    'game_core': ('core', 'global_game_core.cpp',
                  'Core game functions (low address)'),
    'game_systems': ('core', 'global_game_systems.cpp',
                     'Game system functions'),
    'game_logic': ('core', 'global_game_logic.cpp',
                   'Game logic functions'),
    'game_data': ('core', 'global_game_data.cpp',
                  'Game data functions'),
    'game_late': ('core', 'global_game_late.cpp',
                  'Late-linked game functions'),
    'lib_misc': ('libs', 'lib_misc.cpp',
                 'Miscellaneous library functions'),
    'misc': ('core', 'global_misc.cpp',
             'Uncategorized global functions'),
}

# ============================================================
# GENERATE STUBS
# ============================================================
print("\nGenerating stubs...")

cats = defaultdict(list)
skipped = 0
all_generated_keys = set()

for func in unmatched_globals:
    result = generate_stub(func)
    if result is None:
        skipped += 1
        continue

    # Avoid duplicate keys - check if ANY key in this result's set
    # is already generated or manually decompiled
    dominated = all(k in all_generated_keys or k in manual_decompiled
                    for k in result.matched_keys)
    if dominated:
        skipped += 1
        continue

    all_generated_keys.update(result.matched_keys)

    cat = categorize(func)
    cats[cat].append((func, result))

print(f"  Stubs to generate: {sum(len(v) for v in cats.values())}")
print(f"  Unique keys generated: {len(all_generated_keys)}")
print(f"  Skipped (unstubbable/duplicate): {skipped}")

# ============================================================
# WRITE FILES
# ============================================================
FORWARD_DECLS = """// Forward declarations
class EStream;
class EFile;
class ERC;
class EMat4;
class EVec3;
class EVec4;
class EStorable;
class FastAllocPool;
struct ImageProcessingManager;
struct AptSysClock;
struct DVDFileInfo;
struct DVDCommandBlock;
struct DVDDiskID;
struct GXColor;
struct GXTexObj;
struct GXTlutObj;
struct OSThread;
struct OSAlarm;
struct OSContext;
struct OSMutex;
struct OSMessageQueue;
struct GXRenderModeObj;
struct GXFifoObj;
struct GXLightObj;
struct PADStatus;
struct CARDFileInfo;
struct DSPTask;
class BString;
class BString2;
class EAnimNodeDataPos;
class iResFile;
struct FrameEffectsManager;
struct EAnimNote;
struct AptGetBytesEnum;
struct ObjectSaveTypeTable2;
struct ObjectSaveTypeTable3;
struct ObjectSaveIDTable;
struct UserDataSaveLoad;
struct SpriteIdToResIdNode;
class cSimulator;
class Neighbor;
class CasSimDescriptionS2C;
struct AptValue;
struct AptObject;
struct CBFunctorBase;
"""

total_generated = 0
files_created = 0

for cat, items in sorted(cats.items()):
    if cat not in CATEGORY_FILES:
        print(f"  WARNING: Unknown category '{cat}' with {len(items)} functions")
        if 'misc' in cats:
            cats['misc'].extend(items)
        continue

    subdir, filename, description = CATEGORY_FILES[cat]
    dirpath = SRC_DIR / subdir
    dirpath.mkdir(parents=True, exist_ok=True)
    filepath = dirpath / filename

    # Skip if file already exists and is NOT auto-generated
    if filepath.exists():
        with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
            header = f.read(300)
        if 'Auto-generated stub' not in header:
            print(f"  SKIP: {filepath} is manually written")
            continue

    # Sort items by address
    items.sort(key=lambda x: int(x[0]['address'], 16))

    file_lines = []
    file_lines.append(f"// {filename} - {description}")
    file_lines.append(f"// Part of the Sims 2 GC decompilation")
    file_lines.append(
        f"// Auto-generated stub implementations - {len(items)} functions")
    file_lines.append(f"//")
    file_lines.append(
        f"// These are stub implementations to be replaced with "
        f"matching decompilations.")
    file_lines.append(
        f"// Each function needs to be decompiled to match the "
        f"original binary.")
    file_lines.append(f"")
    file_lines.append(f'#include "types.h"')
    file_lines.append(f"")
    file_lines.append(FORWARD_DECLS)

    func_count = 0
    for func, result in items:
        file_lines.append(result.code)
        func_count += 1

    content = '\n'.join(file_lines)
    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(content)

    print(f"  CREATED: {filepath} ({func_count} functions)")
    total_generated += func_count
    files_created += 1

print(f"\n{'='*60}")
print(f"Total functions stubbed: {total_generated}")
print(f"Files created: {files_created}")
print(f"{'='*60}")
