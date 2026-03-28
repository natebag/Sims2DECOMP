#!/usr/bin/env python3
"""
Generate stub implementations for all unimplemented global functions.
Version 3: Regenerates ALL auto-generated files from scratch.

Progress tracker regex: ^[A-Za-z_][\\w:*&<> ]+\\s+(\\w[\\w:]+)\\s*\\(
This matches on the function identifier (word chars + colons only).
"""

import json, re, os
from collections import defaultdict
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent
SYMBOLS_PATH = PROJECT_ROOT / 'tools' / 'symbols.json'
SRC_DIR = PROJECT_ROOT / 'src'

# Files we auto-generate (will be deleted and recreated)
AUTO_GEN_FILES = set()

# ============================================================
# LOAD DATA
# ============================================================
with open(SYMBOLS_PATH, 'r') as f:
    data = json.load(f)

# Get all existing function names from NON-auto-generated source files only
existing_funcs = set()
pat = re.compile(r'^[A-Za-z_][\w:*&<> ]+\s+(\w[\w:]+)\s*\(', re.MULTILINE)

# First pass: identify auto-generated files
for root, dirs, files in os.walk(SRC_DIR):
    for f_name in files:
        if f_name.endswith('.cpp'):
            path = os.path.join(root, f_name)
            with open(path, 'r', encoding='utf-8', errors='ignore') as fh:
                first_line = fh.readline()
                fh.seek(0)
                header = fh.read(300)
                if 'Auto-generated stub' in header:
                    AUTO_GEN_FILES.add(path)

print(f"Auto-generated files to regenerate: {len(AUTO_GEN_FILES)}")

# Second pass: collect existing funcs from non-auto-generated files
for root, dirs, files in os.walk(SRC_DIR):
    for f_name in files:
        if f_name.endswith('.cpp'):
            path = os.path.join(root, f_name)
            if path in AUTO_GEN_FILES:
                continue
            with open(path, 'r', encoding='utf-8', errors='ignore') as fh:
                content = fh.read()
                for m in pat.finditer(content):
                    existing_funcs.add(m.group(1))

print(f"Manually implemented functions: {len(existing_funcs)}")

# Delete all auto-generated files
for path in AUTO_GEN_FILES:
    os.remove(path)
    print(f"  Deleted: {path}")

# ============================================================
# COLLECT GLOBAL FUNCTIONS
# ============================================================
skip_prefixes = ('__static_initialization', 'global constructors', 'global destructors')
all_global = []
seen_names = {}

for s in data['symbols']:
    if s.get('type') != 'function':
        continue
    name = s.get('name', '')
    if not name or name == '<default>':
        continue
    if any(name.startswith(p) for p in skip_prefixes):
        continue
    if 'virtual table' in name:
        continue

    paren_idx = name.find('(')
    prefix = name[:paren_idx] if paren_idx != -1 else name

    if '::' in prefix:
        continue

    fn = prefix.strip()
    if fn in existing_funcs:
        continue

    section = s.get('section', '')
    if section in ['.data', '.bss', '.rodata', '.sdata', '.sbss', '.sdata2', '.sbss2', '.scommon']:
        continue

    if '.' in fn and not fn.startswith('operator'):
        continue

    if fn not in seen_names:
        seen_names[fn] = s
        all_global.append(s)
    elif s.get('size', 0) > seen_names[fn].get('size', 0):
        all_global.remove(seen_names[fn])
        seen_names[fn] = s
        all_global.append(s)

print(f"Global functions to stub: {len(all_global)}")


# ============================================================
# CATEGORIZE
# ============================================================
def categorize(s):
    fn_name = s['name']
    fn = fn_name.split('(')[0].strip() if '(' in fn_name else fn_name
    addr = int(s['address'], 16)

    # Template streaming operators
    if ('operator<<' in fn_name or 'operator>>' in fn_name) and ('EStream' in fn_name or 'EFile' in fn_name):
        return 'streaming_operators'

    # STL algorithms
    if any(x in fn for x in ['sort<', 'heap<', 'partial_sort<', '__adjust_heap<', 'make_heap<', 'pop_heap<', '__push_heap<']):
        return 'stl_algorithms'

    # Other templates
    if '<' in fn and '>' in fn:
        return 'template_functions'

    # Regular operators
    if fn.startswith('operator'):
        return 'operators'

    clib_names = {'wcslen', 'wcscmp', 'wcscpy', 'wcsncpy', 'wcsncmp', 'wcschr', 'wcsstr', 'wcscat',
                  'remove', 'rename', 'clock', 'time', 'system', 'getenv', 'rand', 'srand',
                  'strlen', 'strcmp', 'strcpy', 'strncpy', 'strncmp', 'strchr', 'strstr', 'strcat',
                  'memcpy', 'memset', 'memmove', 'memcmp', 'qsort', 'bsearch',
                  'atoi', 'atof', 'strtol', 'strtoul', 'strtod',
                  'abs', 'labs', 'div', 'ldiv',
                  'toupper', 'tolower', 'isalpha', 'isdigit', 'isalnum', 'isspace', 'ispunct',
                  'sprintf', 'snprintf', 'printf', 'fprintf', 'sscanf', 'fscanf',
                  'malloc', 'calloc', 'realloc', 'free',
                  'fopen', 'fclose', 'fread', 'fwrite', 'fseek', 'ftell', 'fgets', 'fputs',
                  'exit', 'abort', 'atexit'}
    if fn in clib_names:
        return 'clib'

    if fn.startswith('_') and not fn.startswith('__'):
        if fn.startswith('_savefpr') or fn.startswith('_restfpr') or fn.startswith('_savegpr') or fn.startswith('_restgpr'):
            return 'ppc_register_save'
        if fn.startswith('_sn_'):
            return 'sn_runtime'
        return 'clib_internal'

    if fn.startswith('__'):
        if any(x in fn for x in ['kernel_cos', 'kernel_sin', 'kernel_tan', 'ieee754', 'kernel_rem']):
            return 'math_runtime'
        if any(x in fn for x in ['ashldi', 'ashrdi', 'lshrdi', 'divdi', 'moddi', 'cmpdi',
                                   'fixsfdi', 'fixunssfdi', 'floatdidf', 'floatdisf', 'muldi',
                                   'va_arg', 'shr2u', 'div2i', 'mod2i', 'shl2i', 'shr2i', 'div2u', 'mod2u',
                                   'cvt_fp']):
            return 'compiler_builtins'
        if any(x in fn for x in ['throw', 'catch', 'eh_', 'terminate', 'unexpected', 'pure_virtual',
                                   'unwind', 'cxa_', 'type_match']):
            return 'exception_handling'
        if any(x in fn for x in ['init', 'start', 'premain', 'flush']):
            return 'boot_runtime'
        if fn.startswith('__tcf'):
            return 'compiler_cleanup'
        return 'runtime_misc'

    if fn.startswith('GX'): return 'sdk_gx'
    if fn.startswith('OS'): return 'sdk_os'
    if fn.startswith('DVD'): return 'sdk_dvd'
    if fn.startswith('PAD'): return 'sdk_pad'
    if fn.startswith('SI') and addr > 0x803D0000: return 'sdk_si'
    if fn.startswith('VI'): return 'sdk_vi'
    if fn.startswith('DSP'): return 'sdk_dsp'
    if fn.startswith('AI') and addr > 0x80500000: return 'sdk_ai'
    if fn.startswith('AR') and addr > 0x80540000: return 'sdk_aram'
    if fn.startswith('CARD'): return 'sdk_card'
    if fn.startswith('EXI') or fn.startswith('EXT') or (fn.startswith('EX') and addr > 0x803B0000): return 'sdk_exi'

    if fn.startswith('SN') or fn.startswith('sn'): return 'sn_debug'
    if fn in ('cmdNop', 'cmdRecvMem', 'cmdSendMem', 'cmdGo', 'cmdReset',
              'DBcallback', 'EnableMetroTRKInterrupts', 'proviewtty'): return 'sn_debug'

    if fn.startswith('Apt') or fn.startswith('apt'): return 'apt_ui'
    if fn.startswith('E') and len(fn) > 1 and fn[1:2].isupper(): return 'engine'

    ip_names = {'Sharpen', 'Sharpen_MeanRemoval', 'GaussianBlur', 'Emboss', 'Emboss2',
                'EdgeDetect_Prewitt', 'EdgeDetect_Sobel', 'EdgeDetect_OnePass', 'EdgeDetect_NonConvolved',
                'Laplacian', 'Posterize', 'Solarize', 'InverseSolarize', 'Saturate',
                'CustomConvolution', 'ApplyConvolution', 'MergeEdges_Color', 'sort3IntPtrs', 'calcWeightSum'}
    if fn in ip_names: return 'image_processing'

    if fn.startswith('Handle'): return 'event_handlers'
    if fn.startswith('Draw') or fn.startswith('Render') or fn.startswith('render'): return 'game_rendering'
    if fn.startswith('Debug') or fn.startswith('debug'): return 'game_debug'
    if fn.startswith('Profile') or fn.startswith('profile'): return 'game_profiling'
    if fn.startswith('Sims') or fn.startswith('sims'): return 'sims_core'
    if fn.startswith('NGC') or fn.startswith('Ngc'): return 'ngc_platform'
    if fn.startswith('Xml') or fn.startswith('xml'): return 'xml_parser'

    if addr < 0x80020000: return 'game_core'
    if addr < 0x80080000: return 'game_systems'
    if addr < 0x80150000: return 'game_logic'
    if addr < 0x80200000: return 'game_data'
    if addr < 0x803B0000: return 'game_late'
    if addr < 0x80420000: return 'lib_misc'
    if addr < 0x80500000: return 'apt_lib'
    if addr < 0x80570000: return 'sdk_misc'

    return 'misc'


CATEGORY_FILES = {
    'streaming_operators': ('core', 'global_streaming.cpp', 'Streaming operators (EStream/EFile)'),
    'stl_algorithms': ('core', 'global_stl_algorithms.cpp', 'STL algorithm template instantiations'),
    'template_functions': ('core', 'global_templates.cpp', 'Template function instantiations'),
    'operators': ('core', 'global_operators.cpp', 'Global operator overloads'),
    'clib': ('libs', 'clib_functions.cpp', 'C standard library functions'),
    'clib_internal': ('libs', 'clib_internal.cpp', 'Internal C library functions'),
    'ppc_register_save': ('libs', 'ppc_register_save.cpp', 'PowerPC register save/restore'),
    'sn_runtime': ('libs', 'sn_runtime.cpp', 'SN Systems runtime functions'),
    'math_runtime': ('libs', 'math_runtime.cpp', 'Math kernel functions'),
    'compiler_builtins': ('libs', 'compiler_builtins.cpp', 'Compiler built-in functions'),
    'exception_handling': ('libs', 'exception_handling.cpp', 'C++ exception handling'),
    'boot_runtime': ('boot', 'global_boot.cpp', 'Boot and initialization'),
    'compiler_cleanup': ('libs', 'compiler_cleanup.cpp', 'Static destructor cleanup functions'),
    'runtime_misc': ('libs', 'runtime_misc.cpp', 'Miscellaneous runtime functions'),
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
    'sdk_misc': ('libs/dolphinsdk', 'sdk_misc.cpp', 'Miscellaneous SDK functions'),
    'sn_debug': ('libs', 'sn_debug.cpp', 'SN Systems debug/profiling'),
    'apt_ui': ('ui', 'global_apt.cpp', 'APT UI system globals'),
    'apt_lib': ('ui', 'apt_lib.cpp', 'APT library internals'),
    'engine': ('core', 'global_engine.cpp', 'Engine (E-prefix) global functions'),
    'image_processing': ('render', 'image_processing.cpp', 'Image processing filters'),
    'event_handlers': ('core', 'global_event_handlers.cpp', 'Event handler functions'),
    'game_rendering': ('render', 'global_render.cpp', 'Global rendering functions'),
    'game_debug': ('core', 'global_debug.cpp', 'Debug functions'),
    'game_profiling': ('core', 'global_profiling.cpp', 'Profiling functions'),
    'sims_core': ('sim', 'global_sims.cpp', 'Sims-specific global functions'),
    'ngc_platform': ('core', 'global_ngc.cpp', 'NGC platform functions'),
    'xml_parser': ('core', 'global_xml.cpp', 'XML parser functions'),
    'game_core': ('core', 'global_game_core.cpp', 'Core game functions (low address)'),
    'game_systems': ('core', 'global_game_systems.cpp', 'Game system functions'),
    'game_logic': ('core', 'global_game_logic.cpp', 'Game logic functions'),
    'game_data': ('core', 'global_game_data.cpp', 'Game data functions'),
    'game_late': ('core', 'global_game_late.cpp', 'Late-linked game functions'),
    'lib_misc': ('libs', 'lib_misc.cpp', 'Miscellaneous library functions'),
    'misc': ('core', 'global_misc.cpp', 'Uncategorized global functions'),
}


# ============================================================
# SIGNATURE HANDLING
# ============================================================

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


def extract_func_name(before_paren):
    """Extract the function name from text before the opening paren."""
    s = before_paren.strip()

    # Handle templates: find identifier<...>
    # or just identifier
    # The function name is the LAST token (possibly with template args)

    # Remove {anonymous} prefix
    s = s.replace('{anonymous}', '').strip()

    # If ends with >, walk back to find matching <
    if s.endswith('>'):
        depth = 0
        for i in range(len(s)-1, -1, -1):
            if s[i] == '>': depth += 1
            elif s[i] == '<': depth -= 1
            if depth == 0:
                # Found matching <. Now find the identifier before it
                before = s[:i].rstrip()
                # Find last whitespace
                last_space = max(before.rfind(' '), before.rfind('*'), before.rfind('&'))
                if last_space >= 0:
                    func_with_template = s[last_space+1:]
                    ret = s[:last_space+1].strip()
                    return ret, func_with_template
                return '', s
        return '', s

    # For operator functions
    op_idx = s.find('operator')
    if op_idx >= 0:
        ret = s[:op_idx].strip()
        func = s[op_idx:]
        return ret, func

    # Regular: last space separates return type from name
    last_space = s.rfind(' ')
    if last_space >= 0:
        # But check for pointer/ref chars after space
        ret = s[:last_space+1]
        func = s[last_space+1:]
        # Include trailing * and & in return type
        while func and func[0] in ('*', '&', ' '):
            ret += func[0]
            func = func[1:]
        return ret.strip(), func.strip()

    return '', s


def get_base_name(func_name):
    """Get the base identifier from a function name (strip template args)."""
    idx = func_name.find('<')
    if idx >= 0:
        return func_name[:idx]
    return func_name


def is_valid_identifier(s):
    """Check if string is a valid C++ identifier."""
    return bool(re.match(r'^[A-Za-z_]\w*$', s))


def generate_stub(sym):
    """
    Generate a C++ stub for a symbol.
    Returns (code_lines, func_identifier) where func_identifier is what the regex will capture.
    """
    name = sym['name']
    addr = sym['address']
    size = sym.get('size', 0)
    has_sig = '(' in name

    lines = []
    lines.append(f"// {name}")
    lines.append(f"// Address: {addr}, Size: {size}")

    if not has_sig:
        fn = name.strip()
        if not is_valid_identifier(fn):
            return None, None
        lines.append(f"void {fn}() {{")
        lines.append(f"}}")
        lines.append(f"")
        return lines, fn

    # Parse the signature
    # Find the first '(' that's the function parameter list
    # For templates, there may be '(' inside template args (function pointers)
    # Strategy: find the position right after the function name (including template args)

    before_paren_full = name.split('(')[0]
    ret_type, func_name = extract_func_name(before_paren_full)

    if not ret_type:
        ret_type = 'void'

    base = get_base_name(func_name)
    if not is_valid_identifier(base):
        # Try harder - strip all non-identifier chars
        base = re.sub(r'[^A-Za-z0-9_]', '', base)
        if not base or not re.match(r'^[A-Za-z_]', base):
            return None, None

    is_template = '<' in func_name
    is_operator = 'operator' in func_name

    # Parse parameters - find the correct paren pair
    # The params start after the function name part
    paren_start = len(before_paren_full)
    if paren_start < len(name) and name[paren_start] == '(':
        # Find matching close
        depth = 0
        end = -1
        for i in range(paren_start, len(name)):
            if name[i] == '(': depth += 1
            elif name[i] == ')':
                depth -= 1
                if depth == 0:
                    end = i
                    break
        if end > paren_start:
            params_str = name[paren_start+1:end]
        else:
            params_str = ''
    else:
        params_str = 'void'

    params = split_params(params_str)

    # Build param list
    param_parts = []
    for i, p in enumerate(params):
        param_parts.append(f"{p} p{i}")
    params_text = ', '.join(param_parts)

    ret_stmt = get_return_stmt(ret_type)

    if is_template:
        # For template functions, write a plain stub using the base name
        # The comment preserves the full signature
        lines.append(f"// Template: {func_name}")
        lines.append(f"{ret_type} {base}({params_text}) {{{ret_stmt}")
        lines.append(f"}}")
    elif is_operator:
        # For operators, use the full operator name
        lines.append(f"{ret_type} {func_name}({params_text}) {{{ret_stmt}")
        lines.append(f"}}")
    else:
        # Regular function
        lines.append(f"{ret_type} {func_name}({params_text}) {{{ret_stmt}")
        lines.append(f"}}")

    lines.append(f"")
    return lines, base


# ============================================================
# GENERATE FILES
# ============================================================
cats = defaultdict(list)
for s in all_global:
    cat = categorize(s)
    cats[cat].append(s)

for cat in cats:
    cats[cat].sort(key=lambda s: int(s['address'], 16))

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

for cat, symbols in sorted(cats.items()):
    if cat not in CATEGORY_FILES:
        print(f"WARNING: Unknown category {cat} with {len(symbols)} functions")
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
            print(f"SKIP: {filepath} is manually written")
            continue

    file_lines = []
    file_lines.append(f"// {filename} - {description}")
    file_lines.append(f"// Part of the Sims 2 GC decompilation")
    file_lines.append(f"// Auto-generated stub implementations - {len(symbols)} functions")
    file_lines.append(f"//")
    file_lines.append(f"// These are stub implementations to be replaced with matching decompilations.")
    file_lines.append(f"// Each function needs to be decompiled to match the original binary.")
    file_lines.append(f"")
    file_lines.append(f'#include "types.h"')
    file_lines.append(f"")
    file_lines.append(FORWARD_DECLS)

    func_count = 0
    seen_idents = set()

    for sym in symbols:
        stub_lines, ident = generate_stub(sym)
        if stub_lines is None:
            continue

        # For template functions, skip duplicate base names
        # (multiple template instantiations share a base name)
        if ident in seen_idents:
            # Write a comment noting the additional instantiation
            file_lines.append(f"// Additional instantiation: {sym['name']}")
            file_lines.append(f"// Address: {sym['address']}, Size: {sym.get('size', 0)}")
            file_lines.append(f"")
            continue

        seen_idents.add(ident)
        file_lines.extend(stub_lines)
        func_count += 1

    content = '\n'.join(file_lines)
    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(content)

    print(f"CREATED: {filepath} ({func_count} functions)")
    total_generated += func_count
    files_created += 1

print(f"\n{'='*60}")
print(f"Total functions stubbed: {total_generated}")
print(f"Files created: {files_created}")
print(f"{'='*60}")
