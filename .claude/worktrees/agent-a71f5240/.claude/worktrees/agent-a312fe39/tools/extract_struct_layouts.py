#!/usr/bin/env python3
"""
extract_struct_layouts.py - Extract class/struct layouts from Sims 2 GC decomp

Strategy:
1. Parse map files for class names and method signatures
2. Scan asm_decomp files for field access patterns (lwz/stw/lfs/stfs/lhz/sth/lbz/stb)
3. Cross-reference method names with field offsets to infer field names
4. Generate C++ header files with proper struct layouts

For small getters (< 60 bytes), the field mapping is very reliable:
  GetFoo() that loads offset 0x10 -> field at 0x10 is m_foo

For small setters (< 60 bytes), similarly:
  SetBar(int) that stores to offset 0x20 -> field at 0x20 is m_bar
"""

import os
import re
import sys
import json
from collections import defaultdict, OrderedDict
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent
ASM_DIR = PROJECT_ROOT / "src" / "asm_decomp"
MAP_FILE = PROJECT_ROOT / "extracted" / "files" / "u2_ngc_debug.map"
RELEASE_MAP = PROJECT_ROOT / "extracted" / "files" / "u2_ngc_release.map"
OUTPUT_DIR = PROJECT_ROOT / "include" / "classes"
SUMMARY_FILE = PROJECT_ROOT / "docs" / "struct_layouts.md"

# Map instruction to field type info
INSN_TO_TYPE = {
    'lwz': ('u32', 4),
    'stw': ('u32', 4),
    'lfs': ('f32', 4),
    'stfs': ('f32', 4),
    'lfd': ('f64', 8),
    'stfd': ('f64', 8),
    'lhz': ('u16', 2),
    'lha': ('s16', 2),
    'sth': ('u16', 2),
    'lbz': ('u8', 1),
    'stb': ('u8', 1),
}


def parse_map_file(map_path):
    """Parse the map file for class methods and static members."""
    classes = defaultdict(lambda: {
        'methods': [],
        'static_members': [],
        'base_class': None,
        'source_file': None,
    })

    with open(map_path, 'r') as f:
        current_obj = None
        for line in f:
            line = line.rstrip()

            obj_match = re.search(r'\\(\w+)\.obj\)', line)
            if obj_match:
                current_obj = obj_match.group(1)

            method_match = re.search(
                r'([0-9a-f]{8})\s+([0-9a-f]{8})\s+\d+\s+'
                r'(\S+)::(\S+\(.*?\))',
                line
            )
            if method_match:
                addr = int(method_match.group(1), 16)
                size = int(method_match.group(2), 16)
                class_name = method_match.group(3)
                method_sig = method_match.group(4)

                classes[class_name]['methods'].append({
                    'name': method_sig,
                    'address': addr,
                    'size': size,
                    'source_obj': current_obj,
                })
                if current_obj and not classes[class_name]['source_file']:
                    classes[class_name]['source_file'] = current_obj

            static_match = re.match(r'\s+_(\d+)(\w+)\.(\w+)\s*$', line)
            if static_match:
                name_len = int(static_match.group(1))
                class_name = static_match.group(2)
                member_name = static_match.group(3)
                if len(class_name) == name_len:
                    classes[class_name]['static_members'].append(member_name)

            qn_match = re.match(r'\s+_Q2(\d+)(\w+?)(\d+)(\w+)\.(\w+)\s*$', line)
            if qn_match:
                namespace = qn_match.group(2)
                class_name = qn_match.group(4)
                member_name = qn_match.group(5)
                full_name = f"{namespace}::{class_name}"
                classes[full_name]['static_members'].append(member_name)

    return classes


def clean_method_name(raw):
    """Clean method name, stripping __attribute__ noise."""
    name = re.sub(r'__attribute__\(\([^)]*\)\)', '', raw)
    name = name.strip().replace('\n', '').replace('\r', '')
    if '{' in name:
        name = name[:name.index('{')].strip()
    return name


def extract_this_field_accesses(asm_body):
    """Extract field accesses through 'this' pointer from an asm body.

    Returns list of (offset, insn, is_store) tuples.
    """
    # Track which registers hold 'this'
    this_regs = {'3'}  # r3 is 'this' on entry

    for mr_match in re.finditer(r'"mr\t(\d+),3\\n"', asm_body):
        this_regs.add(mr_match.group(1))

    accesses = []
    for line in asm_body.split('\n'):
        for insn_match in re.finditer(
            r'"(lwz|stw|lfs|stfs|lfd|stfd|lhz|lha|sth|lbz|stb)\t'
            r'(\d+),\s*(-?\d+)\((\d+)\)',
            line
        ):
            insn = insn_match.group(1)
            offset = int(insn_match.group(3))
            base_reg = insn_match.group(4)

            if base_reg in this_regs and offset >= 0:
                accesses.append((offset, insn, insn.startswith('st')))

    return accesses


def parse_asm_file(filepath):
    """Parse an asm_decomp file for class info and field accesses."""
    with open(filepath, 'r') as f:
        content = f.read()

    class_match = re.search(r'class (\w+)\s*(?::\s*public\s+(\w+)\s*)?\{', content)
    class_name = class_match.group(1) if class_match else None
    base_class = class_match.group(2) if class_match and class_match.group(2) else None

    if not class_name:
        return None

    field_accesses = defaultdict(lambda: {'types': set(), 'methods': set(), 'is_store': False, 'is_load': False})

    # For small getter/setter naming: method -> list of unique offsets accessed
    method_offset_map = {}

    func_blocks = re.split(r'(?=// 0x[0-9A-Fa-f]+ \(\d+ bytes\))', content)

    for block in func_blocks:
        header_match = re.match(
            r'// (0x[0-9A-Fa-f]+) \((\d+) bytes\)\s*\n'
            r'// (\w+)::([^\n]+)',
            block
        )
        if not header_match:
            continue

        addr = header_match.group(1)
        func_size = int(header_match.group(2))
        cls = header_match.group(3)
        raw_method = header_match.group(4).strip()

        if cls != class_name:
            continue

        method_name = clean_method_name(raw_method)
        base_method = method_name.split('(')[0].strip() if '(' in method_name else method_name

        asm_match = re.search(r'__asm__\s*__volatile__\(\s*\n(.*?)\n\s*\);', block, re.DOTALL)
        if not asm_match:
            continue
        asm_body = asm_match.group(1)

        accesses = extract_this_field_accesses(asm_body)

        # Track unique offsets for this method (for getter/setter analysis)
        method_offsets = set()

        for offset, insn, is_store in accesses:
            type_name, type_size = INSN_TO_TYPE[insn]
            field_accesses[offset]['types'].add(type_name)
            field_accesses[offset]['methods'].add(base_method)
            if is_store:
                field_accesses[offset]['is_store'] = True
            else:
                field_accesses[offset]['is_load'] = True
            method_offsets.add(offset)

        # Store method -> offsets mapping for small methods (getter/setter candidates)
        if func_size <= 80 and method_offsets:
            # For getters, we want loads only; for setters, stores only
            load_offsets = set()
            store_offsets = set()
            for offset, insn, is_store in accesses:
                if is_store:
                    store_offsets.add(offset)
                else:
                    load_offsets.add(offset)

            method_offset_map[base_method] = {
                'size': func_size,
                'load_offsets': load_offsets,
                'store_offsets': store_offsets,
                'all_offsets': method_offsets,
            }

    return {
        'class_name': class_name,
        'base_class': base_class,
        'field_accesses': dict(field_accesses),
        'method_offset_map': method_offset_map,
    }


def build_offset_to_name_map(method_offset_map, field_accesses):
    """Build a mapping from offset -> inferred field name using multiple strategies.

    Strategy 1 (highest confidence): Small getter (Get*) that loads exactly 1 offset
    Strategy 2: Small setter (Set*) that stores to exactly 1 offset
    Strategy 3: Is*/Has*/Can* predicate that loads exactly 1 offset
    Strategy 4: For each field, look at its accessing methods for naming clues
    """
    offset_names = {}  # offset -> (name, confidence)

    # Strategy 1-3: Small getter/setter analysis
    for method, info in method_offset_map.items():
        name = None
        target_offset = None
        confidence = 0

        m = re.match(r'^Get(\w+)$', method)
        if m and len(info['load_offsets']) == 1:
            target_offset = list(info['load_offsets'])[0]
            raw_name = m.group(1)
            name = f"m_{raw_name[0].lower()}{raw_name[1:]}" if raw_name[0].isupper() else f"m_{raw_name}"
            confidence = 10

        if not name and m and len(info['load_offsets']) <= 3 and info['size'] <= 60:
            target_offset = min(info['load_offsets'])
            raw_name = m.group(1)
            name = f"m_{raw_name[0].lower()}{raw_name[1:]}" if raw_name[0].isupper() else f"m_{raw_name}"
            confidence = 5

        m2 = re.match(r'^Set(\w+)$', method)
        if not name and m2 and len(info['store_offsets']) == 1:
            target_offset = list(info['store_offsets'])[0]
            raw_name = m2.group(1)
            name = f"m_{raw_name[0].lower()}{raw_name[1:]}" if raw_name[0].isupper() else f"m_{raw_name}"
            confidence = 8

        m3 = re.match(r'^(Is|Has|Can)(\w+)$', method)
        if not name and m3 and len(info['load_offsets']) == 1:
            target_offset = list(info['load_offsets'])[0]
            name = f"m_b{m3.group(1)}{m3.group(2)}"
            confidence = 8

        if name and target_offset is not None:
            existing = offset_names.get(target_offset)
            if not existing or existing[1] < confidence:
                offset_names[target_offset] = (name, confidence)

    # Strategy 4: For each field, analyze all accessing method names
    for offset, access in field_accesses.items():
        if offset in offset_names:
            continue  # Already have a name from higher-confidence strategy

        methods = access['methods']
        best_name = None
        best_conf = 0

        for method in methods:
            # GetXxx accessing this field (even in larger functions)
            m = re.match(r'^Get(\w+)$', method)
            if m:
                raw_name = m.group(1)
                name = f"m_{raw_name[0].lower()}{raw_name[1:]}" if raw_name[0].isupper() else f"m_{raw_name}"
                if best_conf < 3:
                    best_name = name
                    best_conf = 3

            # SetXxx
            m = re.match(r'^Set(\w+)$', method)
            if m:
                raw_name = m.group(1)
                name = f"m_{raw_name[0].lower()}{raw_name[1:]}" if raw_name[0].isupper() else f"m_{raw_name}"
                if best_conf < 2:
                    best_name = name
                    best_conf = 2

            # IsXxx, HasXxx, CanXxx
            m = re.match(r'^(Is|Has|Can)(\w+)$', method)
            if m:
                name = f"m_b{m.group(1)}{m.group(2)}"
                if best_conf < 2:
                    best_name = name
                    best_conf = 2

            # UpdateXxx (lower confidence - but gives a clue about the subsystem)
            m = re.match(r'^Update(\w+)$', method)
            if m and len(methods) <= 3:
                raw_name = m.group(1)
                name = f"m_{raw_name[0].lower()}{raw_name[1:]}" if raw_name[0].isupper() else f"m_{raw_name}"
                if best_conf < 1:
                    best_name = name
                    best_conf = 1

            # DrawXxx (lower confidence)
            m = re.match(r'^Draw(\w+)$', method)
            if m and len(methods) <= 2:
                raw_name = m.group(1)
                name = f"m_{raw_name[0].lower()}{raw_name[1:]}" if raw_name[0].isupper() else f"m_{raw_name}"
                if best_conf < 1:
                    best_name = name
                    best_conf = 1

        if best_name:
            offset_names[offset] = (best_name, best_conf)

    return {offset: name for offset, (name, _) in offset_names.items()}


def resolve_type(types):
    """Resolve the most specific type for a field from observed access types."""
    if 'f32' in types:
        return 'f32'
    if 'f64' in types:
        return 'f64'
    if 's16' in types:
        return 's16'
    if 'u16' in types:
        return 'u16'
    if 'u8' in types:
        return 'u8'
    return 'u32'


def get_type_size(type_name):
    sizes = {'u8': 1, 's8': 1, 'u16': 2, 's16': 2, 'u32': 4, 's32': 4,
             'f32': 4, 'f64': 8, 'u64': 8, 's64': 8, 'void*': 4, 'void**': 4}
    return sizes.get(type_name, 4)


def build_field_list(field_accesses, class_name, method_offset_map, static_members):
    """Build a sorted list of fields with inferred names and types."""
    if not field_accesses:
        return []

    # First, build the getter/setter-based name map
    offset_names = build_offset_to_name_map(method_offset_map, field_accesses)

    fields = []
    used_names = set()

    for offset in sorted(field_accesses.keys()):
        access = field_accesses[offset]
        type_name = resolve_type(access['types'])
        type_size = get_type_size(type_name)

        # Try getter/setter-based name first (highest quality)
        name = offset_names.get(offset)

        # Deduplicate names
        if name and name in used_names:
            name = f"{name}_{offset:03X}"

        if not name:
            name = f"m_field_{offset:03X}"

        used_names.add(name)

        accessed_by = sorted(access['methods'])

        fields.append({
            'offset': offset,
            'name': name,
            'type': type_name,
            'size': type_size,
            'accessed_by': accessed_by,
            'is_store': access['is_store'],
            'is_load': access['is_load'],
            'has_inferred_name': name != f"m_field_{offset:03X}",
        })

    return fields


def detect_vtable(fields, class_name):
    """Detect vtable pointer at offset 0."""
    for f in fields:
        if f['offset'] == 0 and f['type'] == 'u32':
            # In constructors, offset 0 is typically stored with a vtable address
            ctor_short = class_name.split('::')[-1]
            has_ctor = any(m.startswith(ctor_short) or m.startswith('~') for m in f.get('accessed_by', []))
            if has_ctor or f['is_store']:
                f['name'] = '_vtable'
                f['type'] = 'void**'
                f['comment'] = 'vtable pointer'
                f['has_inferred_name'] = True


def insert_padding(fields):
    """Insert padding fields where there are gaps."""
    if not fields:
        return fields

    result = []
    prev_end = 0

    for field in fields:
        if field['offset'] > prev_end:
            gap = field['offset'] - prev_end
            result.append({
                'offset': prev_end,
                'name': f'_pad_{prev_end:03X}',
                'type': 'u8',
                'size': gap,
                'is_padding': True,
                'array_size': gap,
            })
        result.append(field)
        prev_end = field['offset'] + field['size']

    return result


def generate_header(class_name, base_class, fields, map_methods, static_members, source_file):
    """Generate a C++ header file for a class."""
    guard = class_name.upper().replace('::', '_').replace(' ', '_') + '_H'
    short_name = class_name.split('::')[-1]

    lines = []
    lines.append(f"#ifndef {guard}")
    lines.append(f"#define {guard}")
    lines.append("")
    lines.append('#include "types.h"')
    lines.append("")
    lines.append(f"// {class_name} - struct layout extracted from assembly analysis")
    if source_file:
        lines.append(f"// Source: {source_file}.obj")

    if fields:
        real_fields = [f for f in fields if not f.get('is_padding')]
        named_fields = [f for f in real_fields if f.get('has_inferred_name')]
        max_offset = max(f['offset'] for f in fields)
        max_field = [f for f in fields if f['offset'] == max_offset][0]
        estimated_size = max_offset + max_field['size']
        lines.append(f"// Estimated minimum size: 0x{estimated_size:X} ({estimated_size} bytes)")
        lines.append(f"// {len(real_fields)} known fields ({len(named_fields)} named), {len(map_methods)} methods")
    lines.append("")

    if base_class:
        lines.append(f"class {base_class};  // forward declaration")
        lines.append("")

    if base_class:
        lines.append(f"class {class_name} : public {base_class} {{")
    else:
        lines.append(f"class {class_name} {{")
    lines.append("public:")

    # Static members
    if static_members:
        lines.append("    // Static members (from map file)")
        for sm in static_members:
            lines.append(f"    // static ??? {sm};")
        lines.append("")

    # Constructor/destructor
    ctors = [m for m in map_methods if m['name'].startswith(f"{short_name}(")]
    dtors = [m for m in map_methods if m['name'].startswith('~')]
    other = [m for m in map_methods if m not in ctors and m not in dtors]

    if ctors or dtors:
        lines.append("    // Constructors / Destructors")
        seen = set()
        for m in ctors:
            sig = f"{short_name}({m['name'].split('(', 1)[1]}"
            if sig not in seen:
                lines.append(f"    {sig}  // 0x{m['address']:08X}")
                seen.add(sig)
        for m in dtors:
            sig = m['name']
            if sig not in seen:
                lines.append(f"    {sig};  // 0x{m['address']:08X}")
                seen.add(sig)
        lines.append("")

    if other:
        lines.append("    // Methods")
        seen = set()
        for m in other:
            name = m['name']
            base_name = name.split('(')[0]
            ret_type = "void"
            if base_name.startswith('Get'):
                ret_type = "/* ? */"
            elif base_name.startswith(('Is', 'Has', 'Can')):
                ret_type = "bool"

            sig = f"{ret_type} {name};"
            if sig not in seen:
                lines.append(f"    {sig}  // 0x{m['address']:08X} ({m['size']}B)")
                seen.add(sig)
        lines.append("")

    # Field layout
    if fields:
        lines.append("    // ---- Field Layout (from assembly analysis) ----")
        for field in fields:
            if field.get('is_padding'):
                arr_size = field.get('array_size', field['size'])
                if arr_size <= 8:
                    lines.append(f"    u8 {field['name']}[{arr_size}];  // 0x{field['offset']:03X}")
                else:
                    lines.append(f"    u8 {field['name']}[0x{arr_size:X}];  // 0x{field['offset']:03X}")
            else:
                comment = field.get('comment', '')
                rw = 'R/W' if (field.get('is_load') and field.get('is_store')) else ('R' if field.get('is_load') else 'W')
                accessed = ', '.join(field.get('accessed_by', [])[:3])
                if len(field.get('accessed_by', [])) > 3:
                    accessed += ', ...'
                extra = f" - {comment}" if comment else ""
                lines.append(f"    {field['type']} {field['name']};  // 0x{field['offset']:03X} [{rw}]{extra} ({accessed})")

    lines.append("};")
    lines.append("")
    lines.append(f"#endif // {guard}")
    lines.append("")
    return '\n'.join(lines)


def generate_summary(all_classes):
    """Generate a markdown summary document."""
    lines = []
    lines.append("# Struct Layouts - Sims 2 GameCube Decompilation")
    lines.append("")
    lines.append("Auto-generated from assembly analysis of `src/asm_decomp/` files and symbol map files.")
    lines.append("Field names are inferred from getter/setter patterns in the assembly.")
    lines.append("")

    with_fields = {k: v for k, v in all_classes.items() if v.get('fields')}
    total_fields = sum(len([f for f in v['fields'] if not f.get('is_padding')]) for v in with_fields.values())
    total_named = sum(len([f for f in v['fields'] if f.get('has_inferred_name')]) for v in with_fields.values())

    lines.append(f"**Total classes with field layouts:** {len(with_fields)}")
    lines.append(f"**Total fields discovered:** {total_fields} ({total_named} with inferred names)")
    lines.append("")

    sorted_classes = sorted(
        with_fields.items(),
        key=lambda x: len([f for f in x[1]['fields'] if not f.get('is_padding')]),
        reverse=True
    )

    lines.append("## Class Summary")
    lines.append("")
    lines.append("| Class | Fields | Named | Methods | Base | Min Size |")
    lines.append("|-------|--------|-------|---------|------|----------|")

    for class_name, info in sorted_classes:
        fields = info.get('fields', [])
        real_fields = [f for f in fields if not f.get('is_padding')]
        named = [f for f in real_fields if f.get('has_inferred_name')]
        if len(real_fields) < 2:
            continue
        n_methods = len(info.get('map_methods', []))
        base = info.get('base_class') or '-'
        max_offset = max(f['offset'] for f in fields)
        max_field = [f for f in fields if f['offset'] == max_offset][0]
        min_size = f"0x{max_offset + max_field['size']:X}"
        lines.append(f"| `{class_name}` | {len(real_fields)} | {len(named)} | {n_methods} | {base} | {min_size} |")

    lines.append("")
    lines.append("## Detailed Layouts (Top 50 by field count)")
    lines.append("")

    for class_name, info in sorted_classes[:50]:
        fields = info.get('fields', [])
        real_fields = [f for f in fields if not f.get('is_padding')]
        if len(real_fields) < 3:
            continue

        lines.append(f"### `{class_name}`")
        lines.append("")
        if info.get('base_class'):
            lines.append(f"**Base class:** `{info['base_class']}`")

        named = [f for f in real_fields if f.get('has_inferred_name')]
        max_offset = max(f['offset'] for f in fields)
        max_field = [f for f in fields if f['offset'] == max_offset][0]
        min_size = max_offset + max_field['size']
        lines.append(f"**Size:** >= 0x{min_size:X} ({min_size} bytes) | **Fields:** {len(real_fields)} ({len(named)} named)")
        lines.append("")

        lines.append("| Offset | Type | Name | R/W | Accessed By |")
        lines.append("|--------|------|------|-----|-------------|")

        for field in fields:
            if field.get('is_padding'):
                arr = field.get('array_size', field['size'])
                if arr > 16:
                    lines.append(f"| 0x{field['offset']:03X} | `u8[0x{arr:X}]` | _(gap)_ | - | - |")
                continue  # Skip small padding in detail view

            rw = 'R/W' if (field.get('is_load') and field.get('is_store')) else ('R' if field.get('is_load') else 'W')
            accessed = ', '.join(f'`{m}`' for m in field.get('accessed_by', [])[:3])
            if len(field.get('accessed_by', [])) > 3:
                accessed += ', ...'
            comment = field.get('comment', '')
            name_str = f"`{field['name']}`"
            if comment:
                name_str += f" ({comment})"
            if field.get('has_inferred_name'):
                name_str = f"**{name_str}**"
            lines.append(f"| 0x{field['offset']:03X} | `{field['type']}` | {name_str} | {rw} | {accessed} |")

        lines.append("")

    # Static members
    statics = [(k, v) for k, v in all_classes.items() if v.get('static_members')]
    if statics:
        lines.append("## Static Members (from Map File)")
        lines.append("")
        for class_name, info in sorted(statics):
            lines.append(f"**`{class_name}`:** " + ', '.join(f'`{s}`' for s in info['static_members']))
            lines.append("")

    return '\n'.join(lines)


def main():
    print("=" * 70)
    print("Sims 2 GC - Struct Layout Extractor")
    print("=" * 70)

    # Step 1: Parse map files
    print("\n[1/4] Parsing map files...")
    map_classes = {}
    for map_path in [MAP_FILE, RELEASE_MAP]:
        if map_path.exists():
            print(f"  Parsing {map_path.name}...")
            parsed = parse_map_file(str(map_path))
            for cls, info in parsed.items():
                if cls not in map_classes:
                    map_classes[cls] = info
                else:
                    existing_addrs = {m['address'] for m in map_classes[cls]['methods']}
                    for m in info['methods']:
                        if m['address'] not in existing_addrs:
                            map_classes[cls]['methods'].append(m)
                    for sm in info['static_members']:
                        if sm not in map_classes[cls]['static_members']:
                            map_classes[cls]['static_members'].append(sm)

    print(f"  Found {len(map_classes)} classes in map files")

    # Step 2: Parse asm_decomp files
    print("\n[2/4] Parsing asm_decomp files...")
    asm_classes = {}
    asm_files = list(ASM_DIR.glob("*.cpp"))
    print(f"  Found {len(asm_files)} asm_decomp files")

    for asm_file in asm_files:
        try:
            result = parse_asm_file(str(asm_file))
            if result and result['class_name']:
                asm_classes[result['class_name']] = result
        except Exception as e:
            print(f"  WARNING: Error parsing {asm_file.name}: {e}")

    classes_with_fields = {k: v for k, v in asm_classes.items() if v.get('field_accesses')}
    print(f"  Extracted {len(asm_classes)} classes ({len(classes_with_fields)} with field data)")

    # Step 3: Generate struct layouts
    print("\n[3/4] Generating struct layouts...")
    all_class_info = {}
    total_named = 0
    total_fields = 0

    for class_name, asm_info in asm_classes.items():
        map_info = map_classes.get(class_name)
        if not map_info:
            short_name = class_name.split('::')[-1]
            for mk, mv in map_classes.items():
                if mk.split('::')[-1] == short_name:
                    map_info = mv
                    break

        static_members = map_info.get('static_members', []) if map_info else []
        method_offset_map = asm_info.get('method_offset_map', {})

        fields = build_field_list(
            asm_info.get('field_accesses', {}),
            class_name,
            method_offset_map,
            static_members
        )

        if fields:
            detect_vtable(fields, class_name)
            fields = insert_padding(fields)
            real_fields = [f for f in fields if not f.get('is_padding')]
            total_fields += len(real_fields)
            total_named += len([f for f in real_fields if f.get('has_inferred_name')])

        all_class_info[class_name] = {
            'fields': fields,
            'base_class': asm_info.get('base_class'),
            'map_methods': map_info.get('methods', []) if map_info else [],
            'static_members': static_members,
            'source_file': map_info.get('source_file') if map_info else None,
        }

    classes_with_layouts = {k: v for k, v in all_class_info.items() if v['fields']}
    print(f"  Generated layouts for {len(classes_with_layouts)} classes")
    print(f"  Total: {total_fields} fields, {total_named} with inferred names ({100*total_named//max(total_fields,1)}%)")

    # Step 4: Write output
    print("\n[4/4] Writing output files...")
    os.makedirs(OUTPUT_DIR, exist_ok=True)
    os.makedirs(SUMMARY_FILE.parent, exist_ok=True)

    headers_written = 0
    for class_name, info in sorted(all_class_info.items()):
        if not info['fields']:
            continue
        real_fields = [f for f in info['fields'] if not f.get('is_padding')]
        if len(real_fields) < 2:
            continue

        header = generate_header(
            class_name, info.get('base_class'), info['fields'],
            info['map_methods'], info['static_members'], info.get('source_file'),
        )

        safe_name = class_name.replace('::', '_').replace('<', '_').replace('>', '_').replace(' ', '_')
        filepath = OUTPUT_DIR / f"{safe_name}.h"
        with open(filepath, 'w') as f:
            f.write(header)
        headers_written += 1

    print(f"  Wrote {headers_written} header files to {OUTPUT_DIR}")

    summary = generate_summary(all_class_info)
    with open(SUMMARY_FILE, 'w') as f:
        f.write(summary)
    print(f"  Wrote summary to {SUMMARY_FILE}")

    # Top classes
    print("\n" + "=" * 70)
    print("Top 25 classes by field count:")
    print("=" * 70)
    sorted_by_fields = sorted(
        classes_with_layouts.items(),
        key=lambda x: len([f for f in x[1]['fields'] if not f.get('is_padding')]),
        reverse=True
    )
    for class_name, info in sorted_by_fields[:25]:
        real_fields = [f for f in info['fields'] if not f.get('is_padding')]
        named = [f for f in real_fields if f.get('has_inferred_name')]
        max_offset = max(f['offset'] for f in info['fields'])
        print(f"  {class_name:40s} {len(real_fields):3d} fields ({len(named):3d} named)  size>=0x{max_offset:X}")

    # JSON data
    json_path = OUTPUT_DIR / "_struct_data.json"
    json_data = {}
    for class_name, info in all_class_info.items():
        if not info['fields']:
            continue
        json_data[class_name] = {
            'base_class': info['base_class'],
            'fields': [
                {
                    'offset': f['offset'],
                    'name': f['name'],
                    'type': f['type'],
                    'size': f['size'],
                    'is_padding': f.get('is_padding', False),
                    'has_inferred_name': f.get('has_inferred_name', False),
                    'accessed_by': f.get('accessed_by', []),
                }
                for f in info['fields']
            ],
            'method_count': len(info['map_methods']),
            'static_members': info['static_members'],
            'source_file': info.get('source_file'),
        }
    with open(json_path, 'w') as f:
        json.dump(json_data, f, indent=2)
    print(f"\n  Wrote JSON data to {json_path}")


if __name__ == '__main__':
    main()
