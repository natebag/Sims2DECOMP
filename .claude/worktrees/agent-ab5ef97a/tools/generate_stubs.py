#!/usr/bin/env python3
"""
Generate stub implementations for target classes from symbols.json.
Writes one _stubs.cpp file per target class containing all missing functions.
"""

import json
import os
import re


def load_symbols(path):
    with open(path) as f:
        return json.load(f)


def get_existing_func_names(src_dir):
    """Scan all .cpp files for function names already defined.
    Excludes *_stubs.cpp files (our generated output)."""
    existing = set()
    for root, dirs, files in os.walk(src_dir):
        for f in files:
            if f.endswith('.cpp') and not f.endswith('_stubs.cpp'):
                path = os.path.join(root, f)
                with open(path, 'r', encoding='utf-8', errors='ignore') as fh:
                    content = fh.read()
                matches = re.findall(r'(\w[\w:]+)\s*\(', content)
                for m in matches:
                    existing.add(m)
    return existing


def parse_symbol_name(sym_name):
    """Parse symbol name into (return_type, qualified_name, params_str) or None."""
    # Skip non-function entries
    if 'virtual table' in sym_name:
        return None
    if 'typeinfo' in sym_name.lower():
        return None
    if '__sinit' in sym_name:
        return None

    paren_idx = sym_name.find('(')
    if paren_idx < 0:
        return None

    qualified_name = sym_name[:paren_idx].strip()
    params_str = sym_name[paren_idx:]

    parts = qualified_name.split('::')
    method_name = parts[-1]

    # Build set of class names in hierarchy
    class_names = set(parts[:-1])
    class_names.add(parts[0])

    is_ctor = method_name in class_names
    is_dtor = method_name.startswith('~')

    if is_ctor or is_dtor:
        return_type = ''
    elif 'operator new' in method_name:
        return_type = 'void*'
    elif 'operator delete' in method_name:
        return_type = 'void'
    elif 'operator[]' in method_name:
        return_type = 'void*'
    elif 'operator==' in method_name or 'operator!=' in method_name:
        return_type = 'bool'
    elif 'operator' in method_name:
        return_type = 'void'
    else:
        return_type = 'void'

    return (return_type, qualified_name, params_str)


def format_stub(return_type, qualified_name, params_str, address, size):
    """Format a single C++ stub function."""
    if return_type:
        sig = f"{return_type} {qualified_name}{params_str}"
    else:
        sig = f"{qualified_name}{params_str}"

    if not return_type or return_type == 'void':
        body = ''
    elif return_type == 'void*':
        body = '\n    return 0;'
    elif return_type == 'bool':
        body = '\n    return false;'
    elif return_type in ('int', 'float', 'double'):
        body = '\n    return 0;'
    else:
        body = ''

    return f"// {address} | {size} bytes\n{sig} {{{body}\n}}\n"


def main():
    project_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    os.chdir(project_root)

    targets = {
        'InteractorModule': 'build_mode',
        'cXObjectImpl': 'objects',
        'SAnimator2': 'animation',
        'AptActionInterpreter': 'ui',
        'cXPersonImpl': 'sim',
        'INVTarget': 'inventory',
        'ENgcRenderer': 'render',
        'EAnimController': 'animation',
        'PCTTarget': 'ui',
        'ERLevel': 'render',
        'ObjectModuleImpl': 'objects',
        'NghResFile': 'core',
        'Effects': 'effects',
        'EdithVariableSet': 'sim',
        'ISimsObjectModel': 'sim',
        'AptCharacterInst': 'ui',
    }

    file_names = {
        'InteractorModule': 'interactor_stubs',
        'cXObjectImpl': 'cxobjectimpl_stubs',
        'SAnimator2': 'sanimator2_stubs',
        'AptActionInterpreter': 'apt_action_stubs',
        'cXPersonImpl': 'person_stubs',
        'INVTarget': 'invtarget_stubs',
        'ENgcRenderer': 'engcrenderer_stubs',
        'EAnimController': 'eanimcontroller_stubs',
        'PCTTarget': 'pcttarget_stubs',
        'ERLevel': 'erlevel_stubs',
        'ObjectModuleImpl': 'objectmoduleimpl_stubs',
        'NghResFile': 'nghresfile_stubs',
        'Effects': 'effects_stubs',
        'EdithVariableSet': 'edithvariableset_stubs',
        'ISimsObjectModel': 'isimsobjectmodel_stubs',
        'AptCharacterInst': 'apt_characterinst_stubs',
    }

    data = load_symbols('tools/symbols.json')
    symbols = data['symbols']

    # Collect functions per target class
    class_funcs = {t: [] for t in targets}
    for sym in symbols:
        name = sym.get('name', '')
        if sym.get('type') != 'function':
            continue
        if sym.get('size', 0) == 0:
            continue
        for t in targets:
            if name.startswith(t + '::'):
                class_funcs[t].append(sym)
                break

    existing = get_existing_func_names('src')

    total_stubs = 0
    for t in sorted(targets.keys()):
        funcs = class_funcs[t]

        # Filter out already-existing and non-parseable
        new_funcs = []
        for sym in funcs:
            name = sym['name']
            qual_name = name.split('(')[0].strip()
            if qual_name in existing:
                continue
            parsed = parse_symbol_name(name)
            if parsed is None:
                continue
            new_funcs.append((sym, parsed))

        if not new_funcs:
            print(f'{t}: no new stubs needed')
            continue

        # Sort by address
        new_funcs.sort(key=lambda x: x[0].get('address', '0x00000000'))

        dir_name = targets[t]
        fname = file_names[t]

        lines = []
        lines.append(f'// {fname}.cpp - Stub implementations for {t} class methods')
        lines.append(f'// Auto-generated from symbols.json - {len(new_funcs)} functions')
        lines.append(f'// These are stub implementations to register progress.')
        lines.append(f'// Each function needs proper decompilation to match the original binary.')
        lines.append(f'//')
        lines.append(f'// Class: {t}')
        lines.append(f'')
        lines.append(f'#include "types.h"')
        lines.append(f'')

        # Collect forward declarations
        fwd_types = set()
        for sym, parsed in new_funcs:
            name = sym['name']
            paren_idx = name.find('(')
            if paren_idx >= 0:
                close_paren = name.rfind(')')
                if close_paren > paren_idx:
                    params = name[paren_idx+1:close_paren]
                else:
                    params = name[paren_idx+1:]
                for param in params.split(','):
                    param = param.strip()
                    ptype = param.replace('*', '').replace('&', '').replace('const ', '').strip()
                    if '<' in ptype:
                        continue
                    if ptype and ptype not in ('void', 'int', 'unsigned int', 'unsigned long',
                                               'float', 'double', 'bool', 'char', 'short',
                                               'unsigned char', 'unsigned short', 'long',
                                               'signed char', 'signed short', 'signed int',
                                               'signed long', '...', 'enum'):
                        if '::' not in ptype:
                            fwd_types.add(ptype)

        if fwd_types:
            lines.append('// Forward declarations')
            for ft in sorted(fwd_types):
                # Skip malformed types (containing parens, spaces before parens, etc)
                if ')' in ft or '(' in ft or ' ' in ft or ft.startswith('void') or ft.startswith('int'):
                    continue
                # Skip if not a valid C++ identifier
                if not re.match(r'^[A-Za-z_]\w*$', ft):
                    continue
                lines.append(f'class {ft};')
            lines.append('')

        # Group by sub-class
        groups = {}
        for sym, parsed in new_funcs:
            ret_type, qual_name, params = parsed
            parts = qual_name.split('::')
            if len(parts) > 2:
                group_key = '::'.join(parts[:2])
            else:
                group_key = parts[0]
            if group_key not in groups:
                groups[group_key] = []
            groups[group_key].append((sym, parsed))

        for group_key in sorted(groups.keys()):
            group = groups[group_key]
            lines.append(f'// {"="*70}')
            lines.append(f'// {group_key}')
            lines.append(f'// {"="*70}')
            lines.append('')

            for sym, parsed in group:
                ret_type, qual_name, params = parsed
                addr = sym.get('address', '0x00000000')
                size = sym.get('size', 0)

                stub = format_stub(ret_type, qual_name, params, addr, size)
                lines.append(stub)

        content = '\n'.join(lines)

        filepath = os.path.join('src', dir_name, f'{fname}.cpp')
        os.makedirs(os.path.join('src', dir_name), exist_ok=True)
        with open(filepath, 'w') as f:
            f.write(content)

        total_stubs += len(new_funcs)
        print(f'{t}: wrote {len(new_funcs)} stubs to {filepath}')

    print(f'\nTotal: {total_stubs} stubs written')


if __name__ == '__main__':
    main()
