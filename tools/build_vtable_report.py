#!/usr/bin/env python3
"""Build vtable maps from the map file."""

import re
from collections import defaultdict

def main():
    # Parse the map file
    vtables = []
    all_functions = {}

    with open('extracted/files/u2_ngc_release.map', 'r') as f:
        for line in f:
            parts = line.strip().split()
            if len(parts) >= 4:
                addr = parts[0]
                size = parts[1]
                name = ' '.join(parts[3:])
                
                # Store all functions by address
                all_functions[addr] = name
                
                # Collect vtables
                if 'virtual table' in name.lower():
                    vtables.append((addr, size, name))

    # Sort by size (descending)
    vtables.sort(key=lambda x: int(x[1], 16), reverse=True)

    # Build the report
    report_lines = [
        "# VTABLE MAPS - TOP CLASSES FOR BLRL DECOMP",
        "",
        "## Overview",
        "This document maps virtual table layouts for the most important classes in The Sims 2.",
        "The blrl virtual dispatch technique requires methods declared in vtable order.",
        "",
        "## TOP 5 CLASSES BY VTABLE SIZE (Most Virtual Methods)",
        "",
    ]

    # Top 5 by size
    top5 = vtables[:5]
    for i, (addr, size, name) in enumerate(top5, 1):
        num_entries = int(size, 16) // 4
        report_lines.append(f"### {i}. {name}")
        report_lines.append(f"- **Address:** 0x{addr}")
        report_lines.append(f"- **Size:** 0x{size} bytes")
        report_lines.append(f"- **Entries:** {num_entries} virtual methods")
        report_lines.append("")

    # Priority classes mentioned in task
    report_lines.append("## PRIORITY CLASSES FOR BLRL UNLOCKING")
    report_lines.append("")
    report_lines.append("### ESim (32 blrl functions in esim TU)")
    
    esim_vtables = [(a, s, n) for a, s, n in vtables if 'esim' in n.lower() and 'esimshadow' not in n.lower()]
    for addr, size, name in esim_vtables:
        num_entries = int(size, 16) // 4
        report_lines.append(f"- **{name}**: 0x{addr}, {num_entries} entries")

    report_lines.append("")
    report_lines.append("### GoalUnlock / GoalBase")
    goal_vtables = [(a, s, n) for a, s, n in vtables if 'goal' in n.lower() or 'unlock' in n.lower()]
    for addr, size, name in goal_vtables:
        num_entries = int(size, 16) // 4
        report_lines.append(f"- **{name}**: 0x{addr}, {num_entries} entries")

    report_lines.append("")
    report_lines.append("### CardSys / MemoryCard")
    card_vtables = [(a, s, n) for a, s, n in vtables if 'memorycard' in n.lower() or 'memcard' in n.lower()]
    for addr, size, name in card_vtables:
        num_entries = int(size, 16) // 4
        report_lines.append(f"- **{name}**: 0x{addr}, {num_entries} entries")

    report_lines.append("")
    report_lines.append("### ActionQueue")
    action_vtables = [(a, s, n) for a, s, n in vtables if 'action' in n.lower() or 'queue' in n.lower()]
    for addr, size, name in action_vtables:
        num_entries = int(size, 16) // 4
        report_lines.append(f"- **{name}**: 0x{addr}, {num_entries} entries")

    report_lines.append("")
    report_lines.append("### APT Classes (Top 20)")
    apt_vtables = [(a, s, n) for a, s, n in vtables if 'apt' in n.lower()]
    for addr, size, name in apt_vtables[:20]:
        num_entries = int(size, 16) // 4
        report_lines.append(f"- **{name}**: 0x{addr}, {num_entries} entries")

    # Complete sorted list
    report_lines.append("")
    report_lines.append("## ALL VTABLES SORTED BY SIZE (Top 50)")
    report_lines.append("")
    report_lines.append("| Rank | Class | Address | Size | Entries |")
    report_lines.append("|------|-------|---------|------|----------|")

    for i, (addr, size, name) in enumerate(vtables[:50], 1):
        num_entries = int(size, 16) // 4
        report_lines.append(f"| {i} | {name} | 0x{addr} | 0x{size} | {num_entries} |")

    # Statistics
    report_lines.append("")
    report_lines.append("## STATISTICS")
    report_lines.append(f"- Total vtables found: {len(vtables)}")
    report_lines.append(f"- Largest vtable: {vtables[0][2]} with {int(vtables[0][1], 16) // 4} entries")
    report_lines.append(f"- Smallest vtable: {vtables[-1][2]} with {int(vtables[-1][1], 16) // 4} entries")

    report = "\n".join(report_lines)
    
    # Write to file
    with open('build/reports/vtable_report.md', 'w') as f:
        f.write(report)
    
    print("Report written to build/reports/vtable_report.md")
    print("\n" + "="*60)
    print(report[:3000])
    print("\n... (truncated)")

if __name__ == '__main__':
    main()
