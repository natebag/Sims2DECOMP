#!/usr/bin/env python3
"""
Sims 2 GameCube -- Byte-matching helper for decompilation.

Takes a function name, looks it up in symbols.json, disassembles the original
code from the ELF, classifies the function pattern, and suggests C++ code
that should produce matching output.

Usage:
    python tools/match_function.py "ESimsApp::GetStartLot(void)"
    python tools/match_function.py "ESim::GetShadow"          # partial match
    python tools/match_function.py --addr 0x80004670 --size 8  # raw address
    python tools/match_function.py --tier 1                    # list all Tier 1
    python tools/match_function.py --tier 2                    # list all Tier 2
    python tools/match_function.py --stats                     # show tier summary
"""

import argparse
import json
import struct
import subprocess
import sys
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve().parent
ROOT_DIR = SCRIPT_DIR.parent

OBJDUMP = Path(
    "F:/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe"
)
ORIGINAL_ELF = ROOT_DIR / "extracted" / "files" / "u2_ngc_release_dvd.elf"
ORIGINAL_DOL = ROOT_DIR / "extracted" / "sys" / "main.dol"
SYMBOLS_JSON = SCRIPT_DIR / "symbols.json"

CODE_SECTIONS = {".text", ".init"}

# Preloaded binary data (loaded lazily)
_text_data = None
_init_data = None


def load_binary():
    """Load DOL text sections into memory for direct byte access."""
    global _text_data, _init_data
    if _text_data is not None:
        return
    with open(ORIGINAL_DOL, "rb") as f:
        f.seek(0x100)
        _init_data = f.read(0x3C0)
        f.seek(0x4C0)
        _text_data = f.read(0x3C7440)


def get_word(addr):
    """Read a 32-bit big-endian word from the binary at the given address."""
    load_binary()
    init_base = 0x80003100
    text_base = 0x800034C0
    if init_base <= addr < init_base + len(_init_data):
        off = addr - init_base
        return struct.unpack(">I", _init_data[off : off + 4])[0]
    elif text_base <= addr < text_base + len(_text_data):
        off = addr - text_base
        return struct.unpack(">I", _text_data[off : off + 4])[0]
    return None


def get_bytes(addr, size):
    """Read raw bytes from the binary."""
    load_binary()
    init_base = 0x80003100
    text_base = 0x800034C0
    if init_base <= addr < init_base + len(_init_data):
        off = addr - init_base
        return _init_data[off : off + size]
    elif text_base <= addr < text_base + len(_text_data):
        off = addr - text_base
        return _text_data[off : off + size]
    return None


def load_symbols():
    """Load and return all symbols from symbols.json."""
    with open(SYMBOLS_JSON, "r") as f:
        data = json.load(f)
    return data["symbols"]


def get_code_functions(symbols):
    """Return deduplicated code functions with size > 0."""
    code_funcs = {}
    for s in symbols:
        if (
            s["type"] == "function"
            and s.get("section", "") in CODE_SECTIONS
            and "name" in s
            and s["name"] != "<default>"
            and s.get("size", 0) > 0
        ):
            addr = s["address"]
            if addr not in code_funcs or s["size"] > code_funcs[addr]["size"]:
                code_funcs[addr] = s
    return code_funcs


def find_function(symbols, name):
    """Find function(s) by exact or partial name match."""
    code_funcs = get_code_functions(symbols)
    all_funcs = list(code_funcs.values())

    # Exact match
    exact = [f for f in all_funcs if f["name"] == name]
    if exact:
        return exact

    # Partial match
    return [f for f in all_funcs if name in f["name"]]


def disassemble(addr, size, section=".text"):
    """Disassemble a function using objdump and return formatted lines."""
    if not OBJDUMP.exists():
        # Fall back to direct binary reading
        return disassemble_direct(addr, size)

    start = addr
    stop = addr + size
    cmd = [
        str(OBJDUMP),
        "-d",
        f"--start-address=0x{start:08X}",
        f"--stop-address=0x{stop:08X}",
    ]
    if section in CODE_SECTIONS:
        cmd.extend(["-j", section])
    cmd.append(str(ORIGINAL_ELF))

    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
    except (subprocess.TimeoutExpired, FileNotFoundError) as e:
        print(f"objdump failed: {e}", file=sys.stderr)
        return disassemble_direct(addr, size)

    # Parse output
    instructions = []
    for line in result.stdout.split("\n"):
        line = line.strip()
        if not line or ":" not in line:
            continue
        parts = line.split("\t")
        if len(parts) >= 3:
            addr_part = parts[0].rstrip(":")
            try:
                iaddr = int(addr_part.strip(), 16)
            except ValueError:
                continue
            hex_bytes = parts[1].strip()
            mnemonic_ops = "\t".join(parts[2:]).strip()
            instructions.append((iaddr, hex_bytes, mnemonic_ops))

    return instructions


def disassemble_direct(addr, size):
    """Disassemble directly from binary (basic fallback)."""
    instructions = []
    for off in range(0, size, 4):
        w = get_word(addr + off)
        if w is None:
            break
        instructions.append(
            (addr + off, f"{w:08x}", f"(raw word 0x{w:08X})")
        )
    return instructions


def classify_function(addr, size):
    """Classify a function by its instruction pattern.

    Returns (tier, pattern, description, suggested_cpp).
    """
    if size == 4:
        w = get_word(addr)
        if w == 0x4E800020:
            return (1, "blr", "Empty void function", "{ }")
        if w is not None and (w >> 26) & 0x3F == 18 and not (w & 1):
            target = addr + _sign_extend_26(w & 0x03FFFFFC)
            return (
                1,
                "tail-call",
                f"Tail call to 0x{target:08X}",
                f"{{ return other_func(args...); }}  // tail call to 0x{target:08X}",
            )
        return (5, "unknown-4b", "Unknown 4-byte pattern", None)

    if size == 8:
        w1 = get_word(addr)
        w2 = get_word(addr + 4)
        if w1 is not None and w2 == 0x4E800020:
            return _classify_8b(w1, addr)
        return (5, "unknown-8b", "8-byte, does not end with blr", None)

    if size == 12:
        w3 = get_word(addr + 8)
        if w3 == 0x4E800020:
            return (4, "12b-blr", "3-instruction function ending in blr", None)
        return (5, "other-12b", "12-byte, non-trivial", None)

    if size <= 16:
        w_last = get_word(addr + size - 4)
        if w_last == 0x4E800020:
            return (5, "16b-blr", "4-instruction function ending in blr", None)
        return (5, "other-16b", "16-byte, non-trivial", None)

    if size <= 64:
        return (6, "medium", f"{size}-byte function ({size // 4} instructions)", None)

    return (7, "large", f"{size}-byte function ({size // 4} instructions)", None)


def _sign_extend_26(val):
    """Sign-extend a 26-bit value."""
    if val & 0x02000000:
        val -= 0x04000000
    return val


def _classify_8b(w1, addr):
    """Classify an 8-byte function (instruction + blr)."""
    op = (w1 >> 26) & 0x3F
    rd = (w1 >> 21) & 0x1F
    ra = (w1 >> 16) & 0x1F
    imm = w1 & 0xFFFF
    if imm > 0x7FFF:
        imm -= 0x10000

    if op == 14 and rd == 3 and ra == 0:  # li r3, N
        return (
            2,
            f"li-r3-{imm}",
            f"Return constant {imm}",
            f"{{ return {imm}; }}",
        )

    if op == 14 and rd == 3:  # addi r3, rX, N
        if ra == 3:
            return (
                2,
                f"addi-this-{imm}",
                f"Return address of member at offset {imm}",
                f"{{ return &this->member_at_{imm}; }}  // addi r3, r3, {imm}",
            )
        elif ra == 13:
            return (
                2,
                f"addi-sda-{imm}",
                f"Return SDA-relative address (r13 + {imm})",
                f"{{ return &global_at_sda_{imm}; }}  // addi r3, r13, {imm}",
            )
        return (
            2,
            f"addi-r{ra}-{imm}",
            f"Return r{ra} + {imm}",
            f"{{ return (char*)param + {imm}; }}",
        )

    if op == 32 and rd == 3:  # lwz r3, off(rX)
        if ra == 3:
            return (
                2,
                f"lwz-this-{imm}",
                f"Return int/ptr member at offset {imm}",
                f"{{ return this->member_at_{imm}; }}  // lwz r3, {imm}(r3)",
            )
        elif ra == 13:
            return (
                2,
                f"lwz-sda-{imm}",
                f"Return SDA global (r13 + {imm})",
                f"{{ return g_global; }}  // lwz r3, {imm}(r13)",
            )
        return (
            2,
            f"lwz-r{ra}-{imm}",
            f"Return word at r{ra}+{imm}",
            f"{{ return *(int*)((char*)r{ra} + {imm}); }}",
        )

    if op == 34 and rd == 3:  # lbz r3, off(rX)
        src = f"this->byte_at_{imm}" if ra == 3 else f"*(u8*)(r{ra}+{imm})"
        return (
            2,
            f"lbz-{imm}",
            f"Return byte member at offset {imm}",
            f"{{ return {src}; }}  // lbz r3, {imm}(r{ra})",
        )

    if op == 40 and rd == 3:  # lhz r3, off(rX)
        src = f"this->short_at_{imm}" if ra == 3 else f"*(u16*)(r{ra}+{imm})"
        return (
            2,
            f"lhz-{imm}",
            f"Return halfword member at offset {imm}",
            f"{{ return {src}; }}  // lhz r3, {imm}(r{ra})",
        )

    if op == 48:  # lfs fX, off(rX)
        fd = (w1 >> 21) & 0x1F
        src = f"this->float_at_{imm}" if ra == 3 else f"*(float*)(r{ra}+{imm})"
        return (
            2,
            f"lfs-{imm}",
            f"Return float member at offset {imm}",
            f"{{ return {src}; }}  // lfs f{fd}, {imm}(r{ra})",
        )

    if op == 36:  # stw rS, off(rX)
        rs = rd  # In stw, bits 21-25 are the source register
        if ra == 3:
            return (
                3,
                f"stw-this-{imm}",
                f"Set int/ptr member at offset {imm}",
                f"{{ this->member_at_{imm} = value; }}  // stw r{rs}, {imm}(r3)",
            )
        elif ra == 13:
            return (
                3,
                f"stw-sda-{imm}",
                f"Set SDA global (r13 + {imm})",
                f"{{ g_global = value; }}  // stw r{rs}, {imm}(r13)",
            )
        return (3, f"stw-r{ra}-{imm}", f"Store word at r{ra}+{imm}", None)

    if op == 52:  # stfs fS, off(rX)
        if ra == 3:
            return (
                3,
                f"stfs-this-{imm}",
                f"Set float member at offset {imm}",
                f"{{ this->float_at_{imm} = value; }}  // stfs, {imm}(r3)",
            )
        return (3, f"stfs-r{ra}-{imm}", f"Store float at r{ra}+{imm}", None)

    if op == 31:
        xo = (w1 >> 1) & 0x3FF
        rs = (w1 >> 21) & 0x1F
        rb = (w1 >> 11) & 0x1F
        if xo == 444 and ra == 3:  # or rA, rS, rB (mr r3, rX when rS==rB)
            return (
                2,
                f"mr-r3-r{rs}",
                f"Return parameter (r{rs})",
                f"{{ return param; }}  // mr r3, r{rs}",
            )

    return (5, "other-8b", f"8-byte: opcode {op}, unknown pattern", None)


def format_match_report(func_name, addr, size, section, instructions, tier_info):
    """Format a comprehensive matching report for a function."""
    tier, pattern, description, suggested = tier_info
    raw_bytes = get_bytes(addr, size)

    lines = []
    lines.append("=" * 76)
    lines.append(f"  MATCH HELPER: {func_name}")
    lines.append("=" * 76)
    lines.append("")
    lines.append(f"  Address:  0x{addr:08X}")
    lines.append(f"  Size:     {size} bytes ({size // 4} instructions)")
    lines.append(f"  Section:  {section}")
    lines.append(f"  Tier:     {tier} ({description})")
    lines.append(f"  Pattern:  {pattern}")
    lines.append("")

    if raw_bytes:
        hex_str = " ".join(f"{b:02X}" for b in raw_bytes)
        lines.append(f"  Target bytes: {hex_str}")
        lines.append("")

    # Disassembly
    lines.append("  --- Disassembly ---")
    if instructions:
        max_hex = max(len(inst[1]) for inst in instructions)
        for iaddr, hex_bytes, mnemonic_ops in instructions:
            lines.append(
                f"  0x{iaddr:08X}:  {hex_bytes:<{max_hex}}  {mnemonic_ops}"
            )
    else:
        lines.append("  (no disassembly available)")
    lines.append("")

    # Suggested C++
    if suggested:
        lines.append("  --- Suggested C++ ---")
        lines.append(f"  {suggested}")
        lines.append("")

    # Matching hints
    lines.append("  --- Matching Notes ---")
    if tier == 1:
        lines.append("  This function is trivially matchable.")
        lines.append("  Just write an empty function body: { }")
        lines.append("  The compiler will emit a single 'blr' instruction.")
    elif tier == 2:
        lines.append("  This is a simple getter. Write a one-line return statement.")
        lines.append(
            "  Make sure the struct layout has the correct field at the right offset."
        )
    elif tier == 3:
        lines.append("  This is a simple setter. Write a one-line assignment.")
        lines.append(
            "  The function parameter order determines which register is used."
        )
    elif tier == 4:
        lines.append("  Three instructions ending in blr.")
        lines.append("  Analyze the disassembly to determine the 1-2 line body.")
        lines.append("  Common: nested field access, flag check, or combined load.")
    elif tier <= 5:
        lines.append("  Small function with non-trivial pattern.")
        lines.append("  Examine the disassembly carefully.")
    elif tier == 6:
        lines.append(
            "  Medium function. Look for prologue/epilogue pattern "
            "and identify the core logic."
        )
        lines.append(
            "  Check if this is a wrapper (prologue + bl + epilogue) "
            "or has real logic."
        )
    else:
        lines.append("  Large function requiring full decompilation analysis.")
        lines.append("  Recommend using Ghidra for control flow graph analysis.")
    lines.append("")

    return "\n".join(lines)


def print_tier_list(symbols, tier_num):
    """Print all functions in a given tier."""
    code_funcs = get_code_functions(symbols)
    results = []

    for addr_str, f in code_funcs.items():
        addr = int(f["address"], 16)
        size = f["size"]
        tier, pattern, desc, _ = classify_function(addr, size)
        if tier == tier_num:
            results.append((f["name"], f["address"], size, pattern))

    results.sort(key=lambda x: x[0])
    print(f"Tier {tier_num} functions ({len(results)} total):")
    print(f"{'Name':<65} {'Address':<12} {'Size':>5}  Pattern")
    print("-" * 100)
    for name, addr, size, pattern in results:
        print(f"{name:<65} {addr:<12} {size:>5}  {pattern}")


def print_stats(symbols):
    """Print tier summary statistics."""
    code_funcs = get_code_functions(symbols)
    tier_counts = {}
    tier_bytes = {}

    for addr_str, f in code_funcs.items():
        addr = int(f["address"], 16)
        size = f["size"]
        tier, _, _, _ = classify_function(addr, size)
        tier_counts[tier] = tier_counts.get(tier, 0) + 1
        tier_bytes[tier] = tier_bytes.get(tier, 0) + size

    total_f = sum(tier_counts.values())
    total_b = sum(tier_bytes.values())

    descriptions = {
        1: "GUARANTEED (blr / tail-call)",
        2: "TRIVIAL getter (8b, X+blr)",
        3: "TRIVIAL setter (8b, stw+blr)",
        4: "EASY (12b ending in blr)",
        5: "STRAIGHTFORWARD (other <=16b)",
        6: "MODERATE (20-64b)",
        7: "COMPLEX (65b+)",
    }

    print("Byte-Matching Tier Summary")
    print("=" * 80)
    print(
        f"{'Tier':<6} {'Description':<40} {'Count':>7} {'%':>6} {'Bytes':>10} {'%':>6}"
    )
    print("-" * 80)
    cumulative_f = 0
    for tier in sorted(tier_counts.keys()):
        count = tier_counts[tier]
        byt = tier_bytes[tier]
        cumulative_f += count
        pct_f = count / total_f * 100
        pct_b = byt / total_b * 100
        desc = descriptions.get(tier, "?")
        print(
            f"  {tier:<4} {desc:<40} {count:>7,} {pct_f:>5.1f}% {byt:>10,} {pct_b:>5.1f}%"
        )
    print("-" * 80)
    print(
        f"  {'':4} {'TOTAL':<40} {total_f:>7,} {'':>6} {total_b:>10,}"
    )
    print()

    quick = sum(tier_counts.get(t, 0) for t in [1, 2, 3, 4])
    print(f"  Quick wins (Tiers 1-4): {quick:,} functions ({quick / total_f * 100:.1f}%)")
    print(
        f"  Free matches (Tiers 1-3): "
        f"{sum(tier_counts.get(t, 0) for t in [1, 2, 3]):,} functions"
    )


def main():
    parser = argparse.ArgumentParser(
        description="Byte-matching helper for Sims 2 GC decompilation"
    )
    parser.add_argument(
        "name",
        nargs="?",
        help="Function name (exact or partial match)",
    )
    parser.add_argument(
        "--addr",
        type=lambda x: int(x, 16),
        help="Raw address (hex) to analyze",
    )
    parser.add_argument("--size", type=int, help="Size in bytes (with --addr)")
    parser.add_argument(
        "--tier",
        type=int,
        choices=[1, 2, 3, 4, 5, 6, 7],
        help="List all functions in the given tier",
    )
    parser.add_argument(
        "--stats",
        action="store_true",
        help="Show tier summary statistics",
    )
    args = parser.parse_args()

    symbols = load_symbols()

    if args.stats:
        print_stats(symbols)
        return

    if args.tier is not None:
        print_tier_list(symbols, args.tier)
        return

    # Raw address mode
    if args.addr is not None:
        if args.size is None:
            print("Error: --size is required with --addr", file=sys.stderr)
            sys.exit(1)
        addr = args.addr
        size = args.size
        instructions = disassemble(addr, size)
        tier_info = classify_function(addr, size)
        output = format_match_report(
            f"(raw @ 0x{addr:08X})", addr, size, ".text", instructions, tier_info
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
        sys.exit(1)

    if len(matches) > 10:
        print(f"Found {len(matches)} matches for '{args.name}'. Showing first 10.")
        print(f"Be more specific to narrow results.\n")
        matches = matches[:10]
    elif len(matches) > 1:
        print(f"Found {len(matches)} matches for '{args.name}':\n")

    for func in matches:
        addr = int(func["address"], 16)
        size = func["size"]
        name = func["name"]
        section = func.get("section", ".text")

        instructions = disassemble(addr, size, section)
        tier_info = classify_function(addr, size)
        output = format_match_report(name, addr, size, section, instructions, tier_info)
        print(output)


if __name__ == "__main__":
    main()
