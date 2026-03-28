#!/usr/bin/env python3
"""
Sims 2 GameCube — Decomp Progress Tracker

Scans decompiled source files and compares against the symbol map
to report decomp completion percentage.

Usage:
    python progress.py [--update-docs]
"""

import json
import argparse
from pathlib import Path


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


def count_decompiled_functions(src_dir: Path) -> set:
    """Scan source files for decompiled function names."""
    decompiled = set()
    if not src_dir.exists():
        return decompiled

    for cpp_file in src_dir.rglob('*.cpp'):
        with open(cpp_file, 'r', encoding='utf-8', errors='replace') as f:
            content = f.read()
            # Simple heuristic: look for function definitions
            # This is a rough count — refine as project matures
            import re
            funcs = re.findall(r'^[A-Za-z_][\w:*&<> ]+\s+(\w[\w:]+)\s*\(', content, re.MULTILINE)
            decompiled.update(funcs)

    return decompiled


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

    functions = [s for s in data['symbols'] if s.get('type') == 'function' and s.get('size', 0) > 0]
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

        # Check if function name appears in decompiled source
        func_short = name.split('(')[0].split('::')[-1] if name else ''
        if func_short in decompiled:
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
    print(f"\n  By System:")

    for system in sorted(system_stats.keys()):
        s = system_stats[system]
        spct = (s['matched'] / s['total'] * 100) if s['total'] > 0 else 0
        print(f"    {system:20s}  {s['matched']:4d} / {s['total']:4d}  ({spct:5.1f}%)")

    if args.update_docs:
        update_progress_doc(project_root, matched_funcs, total_funcs, matched_bytes,
                           total_bytes, pct, byte_pct, system_stats)


def update_progress_doc(root, matched_funcs, total_funcs, matched_bytes,
                        total_bytes, pct, byte_pct, system_stats):
    """Update docs/tracking/progress.md with current stats."""
    doc_path = root / 'docs' / 'tracking' / 'progress.md'

    lines = [
        '# Decomp Progress — Sims 2 GameCube\n',
        '\n',
        '## Overview\n',
        '\n',
        '| Metric | Value |\n',
        '|--------|-------|\n',
        f'| Total symbols | {total_funcs:,} |\n',
        f'| Functions matched | {matched_funcs:,} |\n',
        f'| Bytes matched | {matched_bytes:,} / {total_bytes:,} |\n',
        f'| % Complete (funcs) | {pct:.2f}% |\n',
        f'| % Complete (bytes) | {byte_pct:.2f}% |\n',
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
