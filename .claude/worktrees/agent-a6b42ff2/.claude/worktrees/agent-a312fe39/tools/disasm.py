#!/usr/bin/env python3
"""
Sims 2 GameCube -- Disassemble any function by name from the original ELF.

Looks up the symbol in symbols.json (parsed from u2_ngc_release_dvd.map),
runs devkitPPC objdump, and formats the output.

Usage:
    python tools/disasm.py "ESimsApp::Init(void)"
    python tools/disasm.py "ESimsApp::Init"           # partial match
    python tools/disasm.py --addr 0x80003fdc --size 8  # raw address
    python tools/disasm.py --list "ESim::"             # list matching symbols
"""

import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve().parent
ROOT_DIR = SCRIPT_DIR.parent

OBJDUMP = Path("F:/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe")
ORIGINAL_ELF = ROOT_DIR / "extracted" / "files" / "u2_ngc_release_dvd.elf"
SYMBOLS_JSON = SCRIPT_DIR / "symbols.json"

# Sections that contain executable code
CODE_SECTIONS = {".text", ".init"}


def load_symbols():
    """Load symbols.json and return list of named function symbols."""
    with open(SYMBOLS_JSON, "r") as f:
        data = json.load(f)
    return data["symbols"]


def find_function(symbols, name):
    """Find a function symbol by exact or partial name match.

    Returns a list of matches. Exact match takes priority.
    """
    funcs = [
        s for s in symbols
        if s["type"] == "function" and s.get("name") and s["size"] > 0
    ]

    # Try exact match first
    exact = [f for f in funcs if f["name"] == name]
    if exact:
        return exact

    # Try partial match (substring)
    partial = [f for f in funcs if name in f["name"]]
    return partial


def run_objdump(addr, size, section=None):
    """Run objdump on the ELF for the given address range.

    Returns list of (address_int, hex_bytes, mnemonic, operands) tuples.
    """
    start = addr
    stop = addr + size

    cmd = [
        str(OBJDUMP), "-d",
        f"--start-address=0x{start:08X}",
        f"--stop-address=0x{stop:08X}",
    ]

    # If the function is in a known code section, use -j to target it
    if section and section in CODE_SECTIONS:
        cmd.extend(["-j", section])
    else:
        # Fall back to disassembling all sections
        cmd.append("-D")

    cmd.append(str(ORIGINAL_ELF))

    result = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
    if result.returncode != 0:
        print(f"objdump error: {result.stderr}", file=sys.stderr)
        return []

    return parse_objdump_output(result.stdout)


def parse_objdump_output(text):
    """Parse objdump output into structured instruction list."""
    instructions = []
    # Match lines like: 80003468:\t7c 00 00 a6 \tmfmsr   r0
    pattern = re.compile(
        r"^\s*([0-9a-f]+):\s+"   # address
        r"((?:[0-9a-f]{2} )+)\s*"  # hex bytes
        r"(\S+)"                 # mnemonic
        r"(?:\s+(.*))?$"         # operands (optional)
    )

    for line in text.split("\n"):
        m = pattern.match(line)
        if m:
            addr_int = int(m.group(1), 16)
            hex_bytes = m.group(2).strip()
            mnemonic = m.group(3)
            operands = m.group(4).strip() if m.group(4) else ""
            instructions.append((addr_int, hex_bytes, mnemonic, operands))

    return instructions


def format_disassembly(func_name, addr, size, section, instructions):
    """Format disassembly output with header and stats."""
    lines = []
    lines.append(f"{'=' * 72}")
    lines.append(f"  {func_name}")
    lines.append(f"  Address: 0x{addr:08X}  Size: {size} bytes ({size // 4} instructions)  Section: {section}")
    lines.append(f"{'=' * 72}")
    lines.append("")

    if not instructions:
        lines.append("  (no instructions disassembled -- address may be in non-code section)")
        lines.append("")
        return "\n".join(lines)

    # Find max widths for alignment
    max_hex_len = max(len(inst[1]) for inst in instructions) if instructions else 0
    max_mnemonic_len = max(len(inst[2]) for inst in instructions) if instructions else 0

    for addr_int, hex_bytes, mnemonic, operands in instructions:
        hex_padded = hex_bytes.ljust(max_hex_len)
        mnemonic_padded = mnemonic.ljust(max_mnemonic_len)
        lines.append(f"  0x{addr_int:08X}:  {hex_padded}  {mnemonic_padded}  {operands}")

    lines.append("")
    actual_count = len(instructions)
    expected_count = size // 4
    if actual_count != expected_count:
        lines.append(f"  Note: Expected {expected_count} instructions, got {actual_count}")
        lines.append("")

    return "\n".join(lines)


def list_symbols(symbols, pattern):
    """List all function symbols matching a pattern."""
    funcs = find_function(symbols, pattern)
    if not funcs:
        print(f"No functions matching '{pattern}'")
        return

    # Sort by address
    funcs.sort(key=lambda f: int(f["address"], 16))

    print(f"Functions matching '{pattern}' ({len(funcs)} results):")
    print(f"{'Address':<12} {'Size':>6} {'Section':<8} Name")
    print(f"{'-' * 12} {'-' * 6} {'-' * 8} {'-' * 40}")
    for f in funcs:
        print(f"{f['address']:<12} {f['size']:>6} {f['section']:<8} {f['name']}")


def main():
    parser = argparse.ArgumentParser(
        description="Disassemble a function from the Sims 2 GC original ELF"
    )
    parser.add_argument(
        "name", nargs="?",
        help="Function name (exact or partial match)"
    )
    parser.add_argument(
        "--addr", type=lambda x: int(x, 16),
        help="Raw address (hex) to disassemble"
    )
    parser.add_argument(
        "--size", type=int, default=None,
        help="Size in bytes (required with --addr)"
    )
    parser.add_argument(
        "--section", default=".text",
        help="Section name for raw address mode (default: .text)"
    )
    parser.add_argument(
        "--list", "-l", metavar="PATTERN",
        help="List all functions matching a pattern"
    )
    parser.add_argument(
        "--raw", action="store_true",
        help="Print raw objdump output (no formatting)"
    )
    args = parser.parse_args()

    symbols = load_symbols()

    # List mode
    if args.list:
        list_symbols(symbols, args.list)
        return

    # Raw address mode
    if args.addr is not None:
        if args.size is None:
            print("Error: --size is required with --addr", file=sys.stderr)
            sys.exit(1)
        instructions = run_objdump(args.addr, args.size, args.section)
        output = format_disassembly(
            f"(raw @ 0x{args.addr:08X})",
            args.addr, args.size, args.section, instructions
        )
        print(output)
        return

    # Name-based lookup
    if not args.name:
        parser.print_help()
        sys.exit(1)

    matches = find_function(symbols, args.name)

    if not matches:
        print(f"No function found matching '{args.name}'")
        print("Tip: Use --list to search for partial matches")
        sys.exit(1)

    if len(matches) > 10:
        print(f"Found {len(matches)} matches for '{args.name}'. Showing first 10:")
        print(f"Use --list '{args.name}' to see all, or be more specific.\n")
        matches = matches[:10]
    elif len(matches) > 1:
        print(f"Found {len(matches)} matches for '{args.name}':\n")

    for func in matches:
        addr = int(func["address"], 16)
        size = func["size"]
        name = func["name"]
        section = func["section"]

        if args.raw:
            start = addr
            stop = addr + size
            cmd = [
                str(OBJDUMP), "-d",
                f"--start-address=0x{start:08X}",
                f"--stop-address=0x{stop:08X}",
            ]
            if section in CODE_SECTIONS:
                cmd.extend(["-j", section])
            cmd.append(str(ORIGINAL_ELF))
            result = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
            print(result.stdout)
        else:
            instructions = run_objdump(addr, size, section)
            output = format_disassembly(name, addr, size, section, instructions)
            print(output)


if __name__ == "__main__":
    main()
