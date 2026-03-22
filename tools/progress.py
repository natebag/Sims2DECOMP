#!/usr/bin/env python3
"""
Sims 2 GameCube — Decomp Progress Tracker

Scans decompiled source files and compares against the symbol map
to report decomp completion percentage.

Usage:
    python progress.py [--update-docs]
"""

import json
import re
import argparse
from pathlib import Path


# Sections that contain executable code (not data)
CODE_SECTIONS = {'.text', '.init'}

# System classification based on symbol name prefixes/patterns
SYSTEM_PATTERNS = {
    'Boot / SDK': ['__start', '__init', '__premain', '__flush', 'DolphinSDK', 'SN_'],
    'Memory': ['EAHeap', 'FastAllocPool', 'allocat', 'malloc', 'free'],
    'Sim AI': ['ESim', 'CAS', 'CasEvent'],
    'Objects': ['cXObject', 'ISimsMultiTile', 'ObjectModel'],
    'Rendering': ['ENgcRenderer', 'Render', 'Shader', 'GX'],
    'Camera': ['ESimsCam', 'Camera'],
    'Build Mode': ['InteractorModule', 'WallManipulator', 'Wall'],
    'UI / APT': ['Apt', 'apt_', 'ActionInterpreter'],
    'Audio': ['Ambient', 'Score', 'Sound', 'Audio'],
    'Inventory': ['BBI', 'Inventory'],
    'Goals': ['GoalUnlock', 'Goal'],
    'Save': ['MemCard', 'Save'],
    'Skin': ['SkinCompositor', 'Skin'],
    'Effects': ['FrameEffect', 'Bloom', 'MotionBlur', 'DepthOfField', 'DOF'],
    'Animation': ['Anim', 'AnimEvent'],
}


def classify_symbol(name: str) -> str:
    """Classify a symbol into a system based on name patterns."""
    for system, patterns in SYSTEM_PATTERNS.items():
        for pattern in patterns:
            if pattern.lower() in name.lower():
                return system
    return 'Misc'


def is_code_symbol(sym: dict) -> bool:
    """Return True if this symbol represents executable code, not data.

    Symbols in .text/.init are code. Symbols in .data/.rodata/.bss/.sdata/
    .sbss/.sdata2/.scommon are data (vtables, static members, string literals,
    etc.) even if marked type='function' in the map file.
    """
    return sym.get('section', '') in CODE_SECTIONS


def count_decompiled_functions(src_dir: Path) -> set:
    """Scan source files for decompiled function names."""
    decompiled = set()
    if not src_dir.exists():
        return decompiled

    # Pattern 1: Simple functions — e.g. "void ESim::Init(" or "int main("
    pat_simple = re.compile(r'^[A-Za-z_][\w:*&<> ]+\s+(\w[\w:]+)\s*\(', re.MULTILINE)

    # Pattern 2: Template class methods — e.g. "void TArray<int, Alloc>::Init("
    # Captures the full qualified name including template params
    pat_template = re.compile(
        r'^(?:[\w*& ]+\s+)?([A-Za-z_~][\w]*(?:<[^()]*>)?(?:::~?[\w]+)+)\s*\(',
        re.MULTILINE)

    # Pattern 3: Template class operators — e.g. "void TArray<int, Alloc>::operator=("
    pat_template_op = re.compile(
        r'^(?:[\w*& ]+\s+)?([A-Za-z_][\w]*<[^()]*>::operator[^\s(]+)\s*\(',
        re.MULTILINE)

    # Pattern 4: Free template operators — e.g. "EStream & operator<<<int, Alloc>("
    pat_free_op = re.compile(
        r'^([\w*&<>, ]+\s+operator[<>=!]+<[^()]*>)\s*\(',
        re.MULTILINE)

    # Pattern 5: Class-scoped operator new/delete/[] — e.g. "void* SAnimator2::operator new("
    # Captures "SAnimator2::operator new" or "EdithVariableSet::operator[]"
    pat_class_op = re.compile(
        r'^(?:[\w*& ]+\s+)?(\w[\w:]*::operator\s*(?:new|delete|\[\]))\s*\(',
        re.MULTILINE)

    # Pattern 5b: Class-scoped operator new[]/delete[] with space before bracket
    # e.g. "void * AptString::operator new [](unsigned int)" — note the space before []
    pat_class_op_array = re.compile(
        r'^(?:[\w*& ]+\s+)?(\w[\w:]*::operator\s*(?:new|delete)\s*\[\])\s*\(',
        re.MULTILINE)

    # Pattern 6: Free template functions — e.g. "void DoContainerStream<...>(" or
    # "unsigned int CopyTArray<...>(" or "int ReconLoadVector<...>("
    # Captures the full "return_type FuncName<template_params>"
    pat_free_template = re.compile(
        r'^([\w<>,*& ]+\s+[\w_]+<[^()]*>)\s*\(',
        re.MULTILINE)

    # Pattern 7: General class operators — e.g. "void EMat4::operator=("
    # or "bool EString::operator==(" — captures "ClassName::operator<symbol>"
    # Must start at beginning of line with optional return type
    pat_class_op_general = re.compile(
        r'^(?:[\w*& ]+\s+)?(\w[\w:]*::operator\s*[^\s(]+)\s*\(',
        re.MULTILINE)

    # Pattern 8: Free operators — e.g. "void operator>>(EStream &, ..."
    # Requires a return type prefix to avoid matching random code lines
    pat_free_op_general = re.compile(
        r'^[\w*& ]+\s+(operator[<>=!+\-*/^&|~\[\]]+)\s*\(',
        re.MULTILINE)

    # Pattern 9: Free template functions with nested parens in template args
    # e.g. "void sort<unsigned int *, bool (*)(unsigned int &, ...)>(..."
    # Requires the line to start with a return type keyword, allows pointer/ref chars between
    pat_free_template_nested = re.compile(
        r'^(?:void|int|unsigned|bool|float|double|char|short|long|signed)[\w *&]*\s+'
        r'([\w_]+<[^>]*(?:\([^)]*\))?[^>]*>)\s*\(',
        re.MULTILINE)

    # Pattern 10: Conversion operators — e.g. "EString::operator char *(void) const"
    # These have a type name after "operator" that includes spaces
    pat_conversion_op = re.compile(
        r'^(?:[\w*& ]+\s+)?(\w[\w:]*::operator\s+[\w ]+\*?)\s*\(',
        re.MULTILINE)

    # Pattern 11: PRAGMA_STUB markers — explicit progress registration comments
    # e.g. "// PRAGMA_STUB: global constructors keyed to gRebootTimer"
    pat_pragma = re.compile(
        r'//\s*PRAGMA_STUB:\s*(.+)',
        re.MULTILINE)

    for cpp_file in src_dir.rglob('*.cpp'):
        with open(str(cpp_file), 'r', encoding='utf-8', errors='replace') as f:
            content = f.read()
            decompiled.update(pat_simple.findall(content))
            decompiled.update(pat_template.findall(content))
            decompiled.update(pat_template_op.findall(content))
            decompiled.update(pat_free_op.findall(content))
            decompiled.update(pat_class_op.findall(content))
            decompiled.update(pat_class_op_array.findall(content))
            decompiled.update(pat_free_template.findall(content))
            decompiled.update(pat_class_op_general.findall(content))
            decompiled.update(pat_free_op_general.findall(content))
            decompiled.update(pat_free_template_nested.findall(content))
            decompiled.update(pat_conversion_op.findall(content))
            decompiled.update(pat_pragma.findall(content))

    # Post-process: extract base function names from template captures.
    # E.g. "sort<unsigned int *, bool (*)()>" -> also add "sort".
    # This ensures template instantiations match their truncated symbol keys.
    base_names = set()
    pat_base = re.compile(r'^(\w+)<')
    for ident in decompiled:
        m = pat_base.match(ident)
        if m:
            base_names.add(m.group(1))
    decompiled.update(base_names)

    return decompiled


def _extract_symbol_keys(name: str):
    """Extract all matchable keys from a symbol name.

    Returns (func_qual, func_short, func_base, extra_keys) where extra_keys
    is a set of additional strings to match against the decompiled set.
    """
    extra_keys = set()

    # Always add the exact full symbol name — PRAGMA_STUB comments use this
    extra_keys.add(name)

    # Handle "global constructors/destructors keyed to X"
    # These are compiler-generated init functions tied to a specific symbol.
    # Match them if the embedded symbol name is present.
    gc_match = re.match(
        r'global (?:constructors|destructors) keyed to (.+)', name)
    if gc_match:
        key = gc_match.group(1).strip()
        extra_keys.add(key)   # embedded symbol
        # Also try the qualified name without params
        embedded_qual = key.split('(')[0].strip()
        if embedded_qual:
            extra_keys.add(embedded_qual)
            # And the short name
            embedded_short = embedded_qual.split('::')[-1]
            if embedded_short:
                extra_keys.add(embedded_short)

    # Handle {anonymous}:: prefix — strip it for matching
    stripped = name
    if stripped.startswith('{anonymous}::'):
        stripped = stripped[len('{anonymous}::'):]
        extra_keys.add(stripped)
        extra_keys.add(stripped.split('(')[0].strip())

    func_qual = name.split('(')[0].strip() if name else ''
    func_short = func_qual.split('::')[-1] if func_qual else ''

    # For template functions with function pointers in template args,
    # name.split('(') truncates at the first '(' inside the template args.
    # Also extract the base function name (before '<') as a fallback.
    func_base = ''
    if func_qual:
        base_match = re.search(r'(\w+)\s*<', func_qual)
        if base_match:
            func_base = base_match.group(1)
        elif re.match(r'^[A-Za-z_]\w*$', func_short):
            func_base = func_short

    # For conversion operators like "EString::operator char *"
    # func_qual will be "EString::operator char *" and func_short will be "char" (wrong)
    # Add the operator-including form
    if '::operator ' in func_qual:
        extra_keys.add(func_qual)

    return func_qual, func_short, func_base, extra_keys


def main():
    parser = argparse.ArgumentParser(description='Track Sims 2 GC decomp progress')
    parser.add_argument('--symbols', default='tools/symbols.json',
                        help='Path to parsed symbols JSON')
    parser.add_argument('--src', default='src', help='Source directory')
    parser.add_argument('--update-docs', action='store_true',
                        help='Update docs/tracking/progress.md')
    args = parser.parse_args()

    project_root = Path(__file__).parent.parent

    symbols_path = project_root / args.symbols
    src_dir = project_root / args.src

    if not symbols_path.exists():
        print(f"No symbols file at {symbols_path}")
        print("Run map_parser.py first to generate symbols.json")
        return

    with open(symbols_path) as f:
        data = json.load(f)

    # Only count symbols in code sections (.text, .init) — exclude data sections
    # (.data, .rodata, .bss, .sdata, .sbss, .sdata2, .scommon) which contain
    # vtables, static members, string literals, etc.
    all_syms = [s for s in data['symbols'] if s.get('type') == 'function' and s.get('size', 0) > 0]
    functions = [s for s in all_syms if is_code_symbol(s)]
    data_syms = [s for s in all_syms if not is_code_symbol(s)]

    total_funcs = len(functions)
    total_bytes = sum(f['size'] for f in functions)

    decompiled = count_decompiled_functions(src_dir)

    matched_funcs = 0
    matched_bytes = 0
    system_stats = {}

    for func in functions:
        name = func.get('name', '')
        system = classify_symbol(name)

        if system not in system_stats:
            system_stats[system] = {'total': 0, 'matched': 0, 'total_bytes': 0, 'matched_bytes': 0}

        system_stats[system]['total'] += 1
        system_stats[system]['total_bytes'] += func['size']

        func_qual, func_short, func_base, extra_keys = _extract_symbol_keys(name)

        if func_qual in decompiled or func_short in decompiled or \
           (func_base and func_base in decompiled) or \
           any(k in decompiled for k in extra_keys):
            matched_funcs += 1
            matched_bytes += func['size']
            system_stats[system]['matched'] += 1
            system_stats[system]['matched_bytes'] += func['size']

    pct = (matched_funcs / total_funcs * 100) if total_funcs > 0 else 0
    byte_pct = (matched_bytes / total_bytes * 100) if total_bytes > 0 else 0

    print(f"\n  Sims 2 GC Decomp Progress")
    print(f"  {'='*50}")
    print(f"  Functions: {matched_funcs:,} / {total_funcs:,} ({pct:.2f}%)")
    print(f"  Bytes:     {matched_bytes:,} / {total_bytes:,} ({byte_pct:.2f}%)")
    print(f"  Data syms: {len(data_syms):,} excluded (vtables, static data, etc.)")
    print(f"\n  By System:")

    for system in sorted(system_stats.keys()):
        s = system_stats[system]
        spct = (s['matched'] / s['total'] * 100) if s['total'] > 0 else 0
        print(f"    {system:20s}  {s['matched']:4d} / {s['total']:4d}  ({spct:5.1f}%)")

    if args.update_docs:
        update_progress_doc(project_root, matched_funcs, total_funcs, matched_bytes,
                           total_bytes, pct, byte_pct, system_stats, len(data_syms))


def update_progress_doc(root, matched_funcs, total_funcs, matched_bytes,
                        total_bytes, pct, byte_pct, system_stats,
                        data_syms_excluded=0):
    """Update docs/tracking/progress.md with current stats."""
    doc_path = root / 'docs' / 'tracking' / 'progress.md'

    lines = [
        '# Decomp Progress — Sims 2 GameCube\n',
        '\n',
        '## Overview\n',
        '\n',
        '| Metric | Value |\n',
        '|--------|-------|\n',
        f'| Total code symbols | {total_funcs:,} |\n',
        f'| Functions matched | {matched_funcs:,} |\n',
        f'| Bytes matched | {matched_bytes:,} / {total_bytes:,} |\n',
        f'| % Complete (funcs) | {pct:.2f}% |\n',
        f'| % Complete (bytes) | {byte_pct:.2f}% |\n',
        f'| Data symbols excluded | {data_syms_excluded:,} |\n',
        '\n',
        '## By System\n',
        '\n',
        '| System | Matched | Total | % |\n',
        '|--------|---------|-------|---|\n',
    ]

    for system in sorted(system_stats.keys()):
        s = system_stats[system]
        spct = (s['matched'] / s['total'] * 100) if s['total'] > 0 else 0
        lines.append(f"| {system} | {s['matched']} | {s['total']} | {spct:.1f}% |\n")

    with open(doc_path, 'w') as f:
        f.writelines(lines)

    print(f"\n  Updated {doc_path}")


if __name__ == '__main__':
    main()
