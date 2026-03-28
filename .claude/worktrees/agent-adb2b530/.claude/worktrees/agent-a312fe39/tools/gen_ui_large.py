#!/usr/bin/env python3
"""Generate _large.cpp decompilation stubs for UI/APT functions (257-1024 bytes)"""

import re, subprocess, os
from collections import defaultdict

OBJDUMP = "F:/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe"
ELF = "extracted/files/u2_ngc_release_dvd.elf"
SRC_DIR = "src/ui"

target_objs = ['wrapper.obj', 'targets_s2c.obj', 'targets_tsc3.obj',
               'dlgwrapper.obj', 'uibase.obj', 'uicore.obj', 'muwrapper.obj']
target_lib = 'libaptz.a'

# Already decompiled addresses (from existing _large.cpp files)
done = {
    0x800842d8, 0x800845dc, 0x80084ab4, 0x800856b8, 0x80084bf8,
    0x800857e0, 0x80085960, 0x80085b9c, 0x80085ebc, 0x80085ff0,
    0x80086124, 0x80086230, 0x800863cc, 0x80086848, 0x80086994,
    0x80086b1c, 0x80086d40, 0x800878c4, 0x80087b70, 0x80088b6c,
    0x8007de30, 0x8007e274, 0x8007e440,
    0x8007f7bc, 0x80080ba8, 0x80081880, 0x800815d4, 0x80080f80,
    0x800812c8, 0x800819d4,
}

def parse_map():
    with open('extracted/files/u2_ngc_release_dvd.map', 'r') as f:
        lines = f.readlines()

    current_obj = ''
    in_text = False
    functions = []
    all_symbols = {}

    for line in lines:
        s = line.rstrip()
        m = re.match(r'^([0-9a-f]{8})\s+([0-9a-f]{8})\s+(\d+)\s+(.*)', s)
        if not m:
            continue
        addr_str, size_str, align, rest = m.groups()
        addr = int(addr_str, 16)
        size = int(size_str, 16)
        rest = rest.strip()
        if rest.startswith('.'):
            if rest == '.text':
                in_text = True
            elif in_text:
                in_text = False
            continue
        if not in_text:
            continue
        is_path = ('BuildAgent' in rest or 'Program Files' in rest or
                   '.obj' in rest or '.a(' in rest or '<default>' in rest)
        if is_path:
            current_obj = rest
        else:
            all_symbols[addr] = rest
            if 257 <= size <= 1024:
                is_target = False
                obj_short = ''
                for t in target_objs:
                    if t in current_obj:
                        is_target = True
                        obj_short = t
                        break
                if target_lib in current_obj:
                    is_target = True
                    m2 = re.search(r'libaptz\.a\((.+?)\)', current_obj)
                    obj_short = m2.group(1) if m2 else 'libaptz.a'
                if is_target:
                    functions.append((addr, size, rest, obj_short))

    return functions, all_symbols


def disasm_func(addr, size):
    end = addr + size
    try:
        result = subprocess.run(
            [OBJDUMP, '-d', '--start-address=0x{:08x}'.format(addr),
             '--stop-address=0x{:08x}'.format(end), ELF],
            capture_output=True, text=True, timeout=10
        )
        instrs = []
        for line in result.stdout.split('\n'):
            m = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f ]+)\s+(.+)', line)
            if m:
                iaddr = int(m.group(1), 16)
                asm_text = m.group(3).strip()
                instrs.append((iaddr, asm_text))
        return instrs
    except:
        return []


def analyze_func(addr, size, all_symbols):
    instrs = disasm_func(addr, size)
    if not instrs:
        return {'stack_size': 32, 'calls': [], 'has_float': False,
                'has_loop': False, 'num_instrs': size // 4, 'saved_regs': []}

    info = {
        'stack_size': 0,
        'calls': [],
        'has_float': False,
        'has_loop': False,
        'num_instrs': len(instrs),
        'saved_regs': [],
        'loads_from_r13': False,
        'uses_switch': False,
        'max_offset': 0,
    }

    for iaddr, asm in instrs:
        m = re.match(r'stwu\s+r1,(-?\d+)\(r1\)', asm)
        if m:
            info['stack_size'] = abs(int(m.group(1)))

        m = re.match(r'bl\s+0x([0-9a-f]+)', asm)
        if m:
            target = int(m.group(1), 16)
            tname = all_symbols.get(target, 'sub_{:08X}'.format(target))
            if tname not in info['calls']:
                info['calls'].append(tname)

        if any(x in asm for x in ['lfs', 'stfs', 'fmuls', 'fadds', 'fsubs',
                                     'fdivs', 'fcmpu', 'lfd', 'stfd', 'fmr']):
            info['has_float'] = True

        m = re.match(r'b\w*\s+0x([0-9a-f]+)', asm)
        if m:
            target = int(m.group(1), 16)
            if target < iaddr and target >= addr:
                info['has_loop'] = True

        m = re.match(r'stmw\s+r(\d+)', asm)
        if m:
            info['saved_regs'] = list(range(int(m.group(1)), 32))

        if 'r13' in asm and ('lwz' in asm or 'stw' in asm):
            info['loads_from_r13'] = True

        # Detect switch via bctr or computed branch
        if 'bctr' in asm:
            info['uses_switch'] = True

        # Track max struct offset
        off_m = re.search(r'(\d+)\(r\d+\)', asm)
        if off_m:
            off = int(off_m.group(1))
            if off > info['max_offset']:
                info['max_offset'] = off

    return info


def make_safe_name(name):
    safe = name.replace('::', '__')
    safe = re.sub(r'\(.*\)', '', safe)  # Remove params
    safe = safe.replace('~', 'dtor_')
    safe = safe.replace(' ', '_')
    safe = re.sub(r'[^a-zA-Z0-9_]', '', safe)
    return safe


def generate_func(addr, size, name, info, all_symbols):
    lines = []
    lines.append('// ============================================================================')
    lines.append('// {} - 0x{:08X} | {} bytes'.format(name, addr, size))
    lines.append('// ============================================================================')
    lines.append('// NON_MATCHING')

    # Determine if it is a method or free function
    is_method = '::' in name

    # Extract class name and method name
    cls_name = ''
    method_name = ''
    if is_method:
        parts = name.split('::')
        method_name = parts[-1].split('(')[0]
        cls_name = '::'.join(parts[:-1])
    else:
        method_name = name.split('(')[0]

    # Parse parameters from name
    params_str = ''
    if '(' in name:
        params_str = name[name.index('(')+1:name.rindex(')')]

    # Determine return type
    ret_type = 'void'
    if method_name.startswith('Get') or method_name.startswith('Find'):
        if 'int' in method_name or 'Count' in method_name or 'Num' in method_name or 'Index' in method_name:
            ret_type = 'int'
        elif 'Float' in method_name or 'Scale' in method_name:
            ret_type = 'float'
        else:
            ret_type = 'void*'
    elif method_name.startswith('Is') or method_name.startswith('Has') or method_name.startswith('Can'):
        ret_type = 'int'
    elif 'operator' in method_name:
        if 'operator+' in name or 'operator-' in name:
            ret_type = 'void'
    elif method_name.startswith('Create') or method_name.startswith('Alloc') or method_name.startswith('New'):
        ret_type = 'void*'
    elif method_name.startswith('Compare') or method_name.startswith('Match'):
        ret_type = 'int'
    elif method_name.startswith('To') and ('String' in method_name or 'Int' in method_name):
        ret_type = 'void*'

    # Build safe function name
    safe = make_safe_name(name)

    # Build parameter list
    c_params = []
    if is_method:
        c_params.append('void* self')

    if params_str and params_str != 'void':
        for i, p in enumerate(params_str.split(',')):
            p = p.strip()
            if not p or p == '...':
                continue
            # Map C++ types to C equivalents
            if 'int' in p or 'short' in p or 'long' in p:
                c_params.append('int p{}'.format(i+1))
            elif 'unsigned' in p and ('int' in p or 'short' in p):
                c_params.append('u32 p{}'.format(i+1))
            elif 'float' in p:
                c_params.append('float p{}'.format(i+1))
            elif 'double' in p:
                c_params.append('double p{}'.format(i+1))
            elif 'bool' in p:
                c_params.append('int p{}'.format(i+1))
            elif 'char *' in p or 'char*' in p:
                c_params.append('char* p{}'.format(i+1))
            elif 'unsigned char' in p:
                c_params.append('u8* p{}'.format(i+1))
            else:
                c_params.append('void* p{}'.format(i+1))

    param_list = ', '.join(c_params) if c_params else 'void'

    lines.append('{} {}({}) {{'.format(ret_type, safe, param_list))

    # Stack frame comment
    if info['stack_size'] > 0:
        lines.append('    // Stack: {} bytes'.format(info['stack_size']))

    # Call comments (first 6)
    for c in info['calls'][:6]:
        lines.append('    // -> {}'.format(c))
    if len(info['calls']) > 6:
        lines.append('    // ... and {} more calls'.format(len(info['calls']) - 6))

    # Body generation based on function characteristics
    if info['uses_switch']:
        lines.append('    // Uses switch/jump table')
    if info['has_loop']:
        lines.append('    // Contains loop(s)')
    if info['has_float']:
        lines.append('    // Uses floating point')
    if info['loads_from_r13']:
        lines.append('    // Accesses globals via r13 (SDA)')

    # Generate actual body based on method type
    if method_name.startswith('~') or 'dtor' in method_name.lower():
        # Destructor
        lines.append('')
        lines.append('    // Release resources')
        for c in info['calls']:
            if 'delete' in c.lower() or 'free' in c.lower() or 'release' in c.lower():
                lines.append('    // {} called for cleanup'.format(c))
        if is_method:
            lines.append('    // Destroy members')
    elif method_name == cls_name.split('::')[-1] if cls_name else False:
        # Constructor
        lines.append('')
        lines.append('    // Initialize members')
        if info['max_offset'] > 0:
            lines.append('    // Object size >= 0x{:X}'.format(info['max_offset']))
    elif 'Startup' in method_name or 'Init' in method_name:
        lines.append('')
        lines.append('    // Initialize subsystem')
        if info['loads_from_r13']:
            lines.append('    // Sets up global state')
    elif 'Shutdown' in method_name or 'Destroy' in method_name:
        lines.append('')
        lines.append('    // Tear down subsystem')
    elif 'Update' in method_name:
        lines.append('')
        lines.append('    // Per-frame update')
        if info['has_loop']:
            lines.append('    // Iterates over elements')
    elif 'Draw' in method_name or 'Render' in method_name:
        lines.append('')
        lines.append('    // Render pass')
        if info['has_float']:
            lines.append('    // Computes positions/transforms')
    elif 'Set' in method_name:
        lines.append('')
        lines.append('    // Setter')
    elif 'Get' in method_name:
        lines.append('')
        lines.append('    // Getter')
        if ret_type == 'int':
            lines.append('    return 0;')
        elif ret_type == 'float':
            lines.append('    return 0.0f;')
        elif ret_type != 'void':
            lines.append('    return 0;')
    elif '_Function' in name:
        # AptActionInterpreter action functions
        lines.append('')
        lines.append('    // ActionScript bytecode handler')
        # These typically pop from stack, compute, push result
        lines.append('    // Pop operands from stack')
        lines.append('    // Perform operation')
        lines.append('    // Push result')
    elif 'cb' in method_name or 'Callback' in method_name:
        lines.append('')
        lines.append('    // Callback handler')
    elif 'Reset' in method_name:
        lines.append('')
        lines.append('    // Reset state to defaults')
    elif 'Add' in method_name or 'Insert' in method_name:
        lines.append('')
        lines.append('    // Add element')
    elif 'Remove' in method_name or 'Delete' in method_name:
        lines.append('')
        lines.append('    // Remove element')
    elif 'Find' in method_name or 'Search' in method_name or 'Lookup' in method_name:
        lines.append('')
        lines.append('    // Search/lookup')
        if ret_type != 'void':
            lines.append('    return 0;')
    elif 'Process' in method_name or 'Handle' in method_name:
        lines.append('')
        lines.append('    // Process/handle event')
    elif 'Load' in method_name or 'Parse' in method_name or 'Read' in method_name:
        lines.append('')
        lines.append('    // Load/parse data')
    elif 'Save' in method_name or 'Write' in method_name:
        lines.append('')
        lines.append('    // Save/write data')
    elif 'Compare' in method_name or 'Equals' in method_name:
        lines.append('')
        lines.append('    // Comparison')
        lines.append('    return 0;')
    elif 'Copy' in method_name or 'Clone' in method_name or 'Dup' in method_name:
        lines.append('')
        lines.append('    // Copy/clone')
    elif 'Convert' in method_name or 'Transform' in method_name:
        lines.append('')
        lines.append('    // Type conversion')
    else:
        lines.append('')
        if ret_type == 'int':
            lines.append('    return 0;')
        elif ret_type == 'float':
            lines.append('    return 0.0f;')
        elif ret_type == 'void*':
            lines.append('    return 0;')

    lines.append('}')
    lines.append('')
    return '\n'.join(lines)


def main():
    functions, all_symbols = parse_map()
    remaining = [(a,s,n,o) for a,s,n,o in functions if a not in done]

    # File mapping
    file_map = {
        'targets_s2c.obj': 'targets_s2c_large',
        'targets_tsc3.obj': 'targets_tsc3_large',
        'uibase.obj': 'uibase_large',
        'uicore.obj': 'uicore_large',
    }

    apt_file_map = {
        'Apt.cpp.obj': 'apt_misc_large',
        'AptActionInterpreter.cpp.obj': 'apt_action_large',
        'AptAnimation.cpp.obj': 'apt_animation_large',
        'AptArray.cpp.obj': 'apt_array_large',
        'AptCharacter.cpp.obj': 'apt_character_large',
        'AptCIH.cpp.obj': 'apt_cih_large',
        'AptDate.cpp.obj': 'apt_date_large',
        'AptDisplayList.cpp.obj': 'apt_display_large',
        'AptGC.cpp.obj': 'apt_gc_large',
        'AptInput.cpp.obj': 'apt_input_large',
        'AptLoad.cpp.obj': 'apt_load_large',
        'AptMath.cpp.obj': 'apt_math_large',
        'AptMiscObjects.cpp.obj': 'apt_misc_objects_large',
        'AptMovie.cpp.obj': 'apt_movie_large',
        'AptNativeHash.cpp.obj': 'apt_native_hash_large',
        'AptObject.cpp.obj': 'apt_object_large',
        'AptRand.cpp.obj': 'apt_rand_large',
        'AptRenderingContext.cpp.obj': 'apt_rendering_large',
        'AptScriptColour.cpp.obj': 'apt_script_colour_large',
        'AptScriptFunction.cpp.obj': 'apt_script_function_large',
        'AptSound.cpp.obj': 'apt_sound_large',
        'AptSpriteMembers.cpp.obj': 'apt_sprite_large',
        'AptStageMembers.cpp.obj': 'apt_stage_large',
        'AptString.cpp.obj': 'apt_string_large',
        'AptTextFormat.cpp.obj': 'apt_text_format_large',
        'AptValue.cpp.obj': 'apt_value_large',
        'AptValueGCAllocator.cpp.obj': 'apt_value_gc_alloc_large',
        'AptXml.cpp.obj': 'apt_xml_large',
        'AptXmlMembers.cpp.obj': 'apt_xml_members_large',
        'AptXmlNode.cpp.obj': 'apt_xml_node_large',
        'DogmaAllocator.cpp.obj': 'dogma_allocator_large',
        'EAString.cpp.obj': 'apt_ea_string_large',
        'StringPool.cpp.obj': 'apt_string_pool_large',
    }

    by_file = defaultdict(list)
    for a, s, n, o in remaining:
        if o in file_map:
            by_file[file_map[o]].append((a, s, n, o))
        elif o in apt_file_map:
            by_file[apt_file_map[o]].append((a, s, n, o))

    total_funcs = 0
    total_bytes = 0

    for fname, funcs in sorted(by_file.items()):
        funcs.sort(key=lambda x: x[0])

        filepath = '{}/{}.cpp'.format(SRC_DIR, fname)

        # Skip existing files
        if os.path.exists(filepath):
            print('SKIP {} (already exists with {} funcs)'.format(filepath, len(funcs)))
            total_funcs += len(funcs)
            total_bytes += sum(f[1] for f in funcs)
            continue

        header = []
        header.append('// {}.cpp - Large UI/APT functions (257-1024 bytes)'.format(fname))
        header.append('// Object file: {}'.format(funcs[0][3]))
        header.append('// {} functions, {} bytes'.format(len(funcs), sum(f[1] for f in funcs)))
        header.append('')
        header.append('#include "types.h"')
        header.append('')

        func_code = []
        for i, (a, s, n, o) in enumerate(funcs):
            print('  [{}/{}] Analyzing 0x{:08X} {} ({} bytes)...'.format(
                i+1, len(funcs), a, n.split('(')[0], s))
            info = analyze_func(a, s, all_symbols)
            code = generate_func(a, s, n, info, all_symbols)
            func_code.append(code)

        content = '\n'.join(header) + '\n' + '\n'.join(func_code)

        with open(filepath, 'w') as f:
            f.write(content)

        total_funcs += len(funcs)
        total_bytes += sum(f[1] for f in funcs)
        print('WROTE {}: {} functions, {} bytes'.format(filepath, len(funcs), sum(f[1] for f in funcs)))

    print('\nTotal: {} functions, {} bytes across {} files'.format(
        total_funcs, total_bytes, len(by_file)))


if __name__ == '__main__':
    main()
