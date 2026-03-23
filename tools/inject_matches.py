#!/usr/bin/env python3
"""
Inject byte-matched functions into the skeleton assembly.

This script solves the core integration problem: our compiled C++ code produces
GCC Itanium-mangled symbol names, while the skeleton assembly uses SN Systems
names from config/symbols.txt. The linker can't merge them, so our code ends
up at wrong addresses.

Solution: For functions that byte-match at the .o level (comparing compiled
bytes against original DOL), we extract the function bytes and patch them
directly into the skeleton's .s file, replacing .space (zeros) with .byte
directives containing the actual code bytes.

Pipeline:
  1. Parse src/matched/*.cpp for address annotations (// 0xADDR (N bytes))
  2. Extract function bytes from compiled build/obj/matched/*.o files
  3. Compare against DOL bytes — only inject confirmed matches
  4. Regenerate skeleton .s files with matched function bytes baked in
  5. Rebuild everything and verify with dtk dol diff

Usage:
    python tools/inject_matches.py [--rebuild] [--verify] [--dry-run]
"""

import argparse
import os
import re
import struct
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

# ============================================================================
# Configuration
# ============================================================================
REPO = Path(__file__).resolve().parent.parent
DEVKITPPC = Path(r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC")
OBJDUMP = DEVKITPPC / "bin" / "powerpc-eabi-objdump.exe"
NM = DEVKITPPC / "bin" / "powerpc-eabi-nm.exe"
OBJCOPY = DEVKITPPC / "bin" / "powerpc-eabi-objcopy.exe"
AS = DEVKITPPC / "bin" / "powerpc-eabi-as.exe"
LD = DEVKITPPC / "bin" / "powerpc-eabi-ld.exe"
CXX = DEVKITPPC / "bin" / "powerpc-eabi-g++.exe"

DOL = REPO / "extracted" / "sys" / "main.dol"
SYMBOLS_FILE = REPO / "config" / "symbols.txt"
SKELETON_DIR = REPO / "build" / "skeleton"
MATCHED_SRC = REPO / "src" / "matched"
MATCHED_OBJ = REPO / "build" / "obj" / "matched"
OUTPUT_ELF = REPO / "build" / "sims2.elf"
LDSCRIPT = REPO / "config" / "ldscript.lcf"

# Section mapping (same as gen_skeleton.py)
DTK_TO_ELF = {
    "init": "init", "text": "text", "data2": "ctors",
    "data3": "rodata", "data4": "data", "bss": "bss",
    "data5": "sdata", "sbss": "sbss", "data6": "sdata2",
}

SECTION_BASES = {
    "init": 0x80003100, "text": 0x800034C0, "ctors": 0x803CA900,
    "rodata": 0x803CAD20, "data": 0x804235E0, "bss": 0x8046E1E0,
    "sdata": 0x804FD920, "sbss": 0x804FF6C0, "sdata2": 0x80500600,
}

SECTION_ENDS = {
    "init": 0x800034C0, "text": 0x803CA900, "ctors": 0x803CAD20,
    "rodata": 0x804235E0, "data": 0x8046E1E0, "bss": 0x804FD920,
    "sdata": 0x804FF6C0, "sbss": 0x80500600, "sdata2": 0x8050158C,
}

SECTION_FLAGS = {
    "init": '"ax"', "text": '"ax"', "ctors": '"wa"',
    "rodata": '"a"', "data": '"wa"', "bss": '"wa", @nobits',
    "sdata": '"wa"', "sbss": '"wa", @nobits', "sdata2": '"a"',
}


# ============================================================================
# DOL reading
# ============================================================================
def read_dol():
    with open(DOL, "rb") as f:
        return f.read()


def get_dol_bytes(dol_data, addr, size):
    """Extract bytes from DOL at a given virtual address."""
    # Text sections (7 max)
    for i in range(7):
        off = struct.unpack(">I", dol_data[0x00 + i * 4: 0x04 + i * 4])[0]
        load = struct.unpack(">I", dol_data[0x48 + i * 4: 0x4C + i * 4])[0]
        sz = struct.unpack(">I", dol_data[0x90 + i * 4: 0x94 + i * 4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off: file_off + size]
    # Data sections (11 max)
    for i in range(11):
        off = struct.unpack(">I", dol_data[0x1C + i * 4: 0x20 + i * 4])[0]
        load = struct.unpack(">I", dol_data[0x64 + i * 4: 0x68 + i * 4])[0]
        sz = struct.unpack(">I", dol_data[0xAC + i * 4: 0xB0 + i * 4])[0]
        if sz > 0 and addr >= load and addr + size <= load + sz:
            file_off = off + (addr - load)
            return dol_data[file_off: file_off + size]
    return None


# ============================================================================
# Object file parsing
# ============================================================================
def get_all_funcs_from_obj(obj_path):
    """Get all functions and their bytes from a .o file using objdump."""
    result = subprocess.run(
        [str(OBJDUMP), "-d", str(obj_path)],
        capture_output=True, text=True, timeout=30
    )

    all_funcs = []
    current_name = None
    current_bytes = bytearray()

    for line in result.stdout.split("\n"):
        fm = re.match(r"^[0-9a-f]+ <(.+)>:", line)
        if fm:
            if current_name and current_bytes:
                all_funcs.append((current_name, bytes(current_bytes)))
            current_name = fm.group(1)
            current_bytes = bytearray()
            continue
        bm = re.match(r"\s*[0-9a-f]+:\s+((?:[0-9a-f]{2} )+)", line)
        if bm and current_name:
            for b in bm.group(1).strip().split():
                current_bytes.append(int(b, 16))
    if current_name and current_bytes:
        all_funcs.append((current_name, bytes(current_bytes)))

    return all_funcs


def get_obj_raw_bytes(obj_path, section=".text"):
    """Get raw bytes of a section from a .o file using objcopy."""
    import tempfile
    with tempfile.NamedTemporaryFile(suffix=".bin", delete=False) as tmp:
        tmp_path = tmp.name
    try:
        subprocess.run(
            [str(OBJCOPY), "-O", "binary", "-j", section, str(obj_path), tmp_path],
            capture_output=True, timeout=30
        )
        with open(tmp_path, "rb") as f:
            return f.read()
    finally:
        try:
            os.unlink(tmp_path)
        except OSError:
            pass


# ============================================================================
# Symbol parsing
# ============================================================================
def parse_symbols():
    """Parse config/symbols.txt into a dict: name -> (addr, size, elf_section, kind)."""
    symbols = {}
    with open(SYMBOLS_FILE) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('#'):
                continue
            m = re.match(
                r'^(\S+)\s*=\s*\.(\w+):0x([0-9A-Fa-f]+);\s*//\s*(.*)',
                line
            )
            if not m:
                continue
            name, dtk_section, addr_hex, rest = m.groups()
            addr = int(addr_hex, 16)
            elf_section = DTK_TO_ELF.get(dtk_section)
            if elf_section is None:
                continue
            size_m = re.search(r'size:0x([0-9A-Fa-f]+)', rest)
            size = int(size_m.group(1), 16) if size_m else 0
            kind = "function" if "type:function" in rest else "object"
            symbols[name] = (addr, size, elf_section, kind)
    return symbols


def build_addr_to_symbol(symbols):
    """Build reverse map: addr -> [(name, size, elf_section, kind)]."""
    addr_map = defaultdict(list)
    for name, (addr, size, section, kind) in symbols.items():
        addr_map[addr].append((name, size, section, kind))
    return addr_map


# ============================================================================
# Source annotation parsing
# ============================================================================
def parse_source_annotations(src_path):
    """Parse a matched .cpp file for address annotations.

    Returns list of (addr, size) for each function.
    """
    functions = []
    with open(src_path, 'r') as f:
        content = f.read()

    in_if0 = 0
    pending = None

    for line in content.split("\n"):
        s = line.strip()
        if s == "#if 0":
            in_if0 += 1
            pending = None
            continue
        elif s == "#endif" and in_if0 > 0:
            in_if0 -= 1
            continue
        if in_if0 > 0:
            continue

        m = re.match(r"// 0x([0-9A-Fa-f]+)\s+\((\d+) bytes\)", s)
        if m:
            pending = (int(m.group(1), 16), int(m.group(2)))
            continue

        if pending and not s.startswith("//") and not s.startswith("#") and s:
            # This is a function definition line
            functions.append(pending)
            pending = None
        elif s and not s.startswith("//") and not s.startswith("#"):
            pending = None

    return functions


# ============================================================================
# Match finding
# ============================================================================
def find_matching_functions(dol_data, verbose=False):
    """Find all functions that byte-match between .o files and DOL.

    Returns: dict of addr -> bytes for each matching function.
    """
    matches = {}  # addr -> bytes
    total = 0
    byte_match = 0
    mismatch = 0
    skipped = 0

    for src_file in sorted(MATCHED_SRC.glob("*.cpp")):
        obj_file = MATCHED_OBJ / (src_file.stem + ".o")
        if not obj_file.exists():
            continue

        # Parse source annotations
        annotations = parse_source_annotations(src_file)
        if not annotations:
            continue

        # Get compiled functions from .o
        compiled_funcs = get_all_funcs_from_obj(obj_file)
        compiled_by_size = defaultdict(list)
        for name, fbytes in compiled_funcs:
            compiled_by_size[len(fbytes)].append((name, fbytes))

        used = set()

        # Two-pass matching:
        # Pass 1: Find exact byte matches (highest confidence)
        for addr, size in annotations:
            orig_bytes = get_dol_bytes(dol_data, addr, size)
            if orig_bytes is None:
                continue
            if size in compiled_by_size:
                for cname, cbytes in compiled_by_size[size]:
                    if cname not in used and cbytes == orig_bytes:
                        used.add(cname)
                        matches[addr] = cbytes
                        break

        # Pass 2: Count all annotations
        for addr, size in annotations:
            total += 1
            orig_bytes = get_dol_bytes(dol_data, addr, size)
            if orig_bytes is None:
                skipped += 1
                continue

            if addr in matches:
                byte_match += 1
                if verbose:
                    print(f"  MATCH  0x{addr:08X} ({size:4d}B)")
            else:
                mismatch += 1

    return matches, total, byte_match, mismatch, skipped


# ============================================================================
# Skeleton generation with injected bytes
# ============================================================================
def sanitize_asm_name(name):
    """Same as gen_skeleton.py."""
    name = name.replace('|', '_OR_')
    name = name.replace('^', '_XOR_')
    if name.startswith('@'):
        name = '_anon_' + name[1:]
    return name


def is_anon_symbol(name):
    return name.startswith('@')


def format_bytes_as_asm(data, bytes_per_line=16):
    """Format raw bytes as .byte assembly directives."""
    lines = []
    for i in range(0, len(data), bytes_per_line):
        chunk = data[i:i + bytes_per_line]
        hex_vals = ", ".join(f"0x{b:02X}" for b in chunk)
        lines.append(f"    .byte {hex_vals}")
    return "\n".join(lines)


def parse_symbols_for_skeleton():
    """Parse symbols.txt into section-grouped data (same as gen_skeleton.py)."""
    sections = defaultdict(list)
    with open(SYMBOLS_FILE) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('#'):
                continue
            m = re.match(
                r'^(\S+)\s*=\s*\.(\w+):0x([0-9A-Fa-f]+);\s*//\s*(.*)',
                line
            )
            if not m:
                continue
            name, dtk_section, addr_hex, rest = m.groups()
            addr = int(addr_hex, 16)
            elf_section = DTK_TO_ELF.get(dtk_section)
            if elf_section is None:
                continue
            size_m = re.search(r'size:0x([0-9A-Fa-f]+)', rest)
            size = int(size_m.group(1), 16) if size_m else 0
            kind = "function" if "type:function" in rest else "object"
            base = SECTION_BASES[elf_section]
            offset = addr - base
            sections[elf_section].append((offset, name, size, kind, addr))

    for section in sections:
        sections[section].sort(key=lambda x: x[0])
    return sections


def write_section_asm_with_injections(section, symbols, outdir, injections):
    """Write assembly for a section, injecting matched bytes where possible.

    injections: dict of addr -> bytes for functions to inject.
    """
    outdir.mkdir(parents=True, exist_ok=True)
    outpath = outdir / f"{section}.s"

    base = SECTION_BASES[section]
    end_addr = SECTION_ENDS[section]
    total_size = end_addr - base
    flags = SECTION_FLAGS[section]
    is_bss = "nobits" in flags

    injected_count = 0

    with open(outpath, 'w') as f:
        f.write(f"# Auto-generated skeleton for .{section}\n")
        f.write(f"# Base: 0x{base:08X}  End: 0x{end_addr:08X}  Size: 0x{total_size:X}\n")
        f.write(f"# Injected matching function bytes by inject_matches.py\n\n")
        f.write(f"    .section .{section}, {flags}\n\n")

        # Group symbols by offset
        by_offset = defaultdict(list)
        for offset, name, size, kind, addr in symbols:
            by_offset[offset].append((name, size, kind, addr))

        offsets_sorted = sorted(by_offset.keys())
        cursor = 0

        for offset in offsets_sorted:
            # Only emit .space if cursor hasn't already passed this offset.
            # Cursor can be past offset when a prior symbol's injection covered
            # this region (e.g. fall-through functions like _savefpr_14..31).
            if cursor < offset:
                gap = offset - cursor
                f.write(f"    .space 0x{gap:X}\n")
                cursor = offset

            # Determine injection data.
            # Only inject if cursor is exactly at this offset — if cursor has
            # passed (due to a prior overlapping injection), just emit labels.
            inject_data = None
            if cursor == offset:
                for name, size, kind, addr in by_offset[offset]:
                    if addr in injections and kind == "function":
                        inject_data = injections[addr]
                        break

            # Emit labels (always, even if cursor has passed — labels are
            # position-independent and will point into the prior injection)
            for name, size, kind, addr in by_offset[offset]:
                safe_name = sanitize_asm_name(name)
                anon = is_anon_symbol(name)
                if not anon:
                    f.write(f"    .global {safe_name}\n")
                if kind == "function":
                    f.write(f"    .type {safe_name}, @function\n")
                f.write(f"{safe_name}:\n")
                if kind == "function" and size > 0:
                    f.write(f"    .size {safe_name}, 0x{size:X}\n")
                elif kind == "object" and size > 0:
                    f.write(f"    .size {safe_name}, 0x{size:X}\n")

            # Emit injected bytes
            if inject_data is not None and not is_bss:
                f.write(f"    # INJECTED: {len(inject_data)} bytes matching original DOL\n")
                f.write(format_bytes_as_asm(inject_data) + "\n")
                cursor = offset + len(inject_data)
                injected_count += 1

        # Pad to section end
        remaining = total_size - cursor
        if remaining > 0:
            f.write(f"    .space 0x{remaining:X}\n")

    return outpath, injected_count


# ============================================================================
# Build
# ============================================================================
def compile_matched_sources():
    """Compile all src/matched/*.cpp files to build/obj/matched/*.o."""
    MATCHED_OBJ.mkdir(parents=True, exist_ok=True)

    cxxflags = [
        "-mcpu=750", "-meabi", "-mhard-float",
        "-O2",
        "-fno-schedule-insns", "-fno-schedule-insns2",
        "-fno-inline", "-fno-inline-small-functions",
        "-fno-exceptions", "-fno-rtti", "-fno-builtin",
        "-fshort-wchar", "-nostdinc++",
        "-Wall", "-Wno-unused", "-Wno-return-type", "-fpermissive",
        "-Iinclude", "-Isrc", "-Ilibs/dolphinsdk", "-Ilibs/sn_runtime", "-Ilibs/apt",
        "-DNDEBUG", "-DEA_PLATFORM_GAMECUBE=1", "-DGEKKO",
    ]

    compiled = 0
    errors = 0
    for src_file in sorted(MATCHED_SRC.glob("*.cpp")):
        obj_file = MATCHED_OBJ / (src_file.stem + ".o")
        # Skip if .o is newer than .cpp
        try:
            if obj_file.exists() and obj_file.stat().st_mtime > src_file.stat().st_mtime:
                compiled += 1
                continue
        except (OSError, FileNotFoundError):
            pass  # Recompile on stat failure

        result = subprocess.run(
            [str(CXX)] + cxxflags + ["-c", str(src_file), "-o", str(obj_file)],
            capture_output=True, text=True, timeout=60,
            cwd=str(REPO)
        )
        if result.returncode == 0:
            compiled += 1
        else:
            errors += 1
            # Don't spam — just count

    return compiled, errors


def rebuild_skeleton_and_link():
    """Assemble skeleton .s files and relink the ELF."""
    as_flags = ["-mgekko", "-mregnames", "-memb"]

    # Assemble all skeleton sections
    skeleton_objs = []
    for section in SECTION_BASES:
        s_file = SKELETON_DIR / f"{section}.s"
        o_file = SKELETON_DIR / f"{section}.o"
        if not s_file.exists():
            continue
        result = subprocess.run(
            [str(AS)] + as_flags + [str(s_file), "-o", str(o_file)],
            capture_output=True, text=True, timeout=60,
            cwd=str(REPO)
        )
        if result.returncode != 0:
            print(f"  ERROR assembling {s_file}: {result.stderr[:200]}")
            return False
        skeleton_objs.append(o_file)

    # IMPORTANT: Only link skeleton objects. The compiled .o files served their
    # purpose for byte comparison — their matching bytes are already baked into
    # the skeleton. Linking compiled .o files would concatenate their .text
    # sections with the skeleton, shifting all addresses and breaking matches.
    all_objs = skeleton_objs

    # Write response file for linker — use quoted paths for spaces
    rsp_file = REPO / "build" / "objects.rsp"
    with open(rsp_file, 'w') as f:
        for obj in all_objs:
            # Use forward slashes and quote paths with spaces
            p = str(obj).replace("\\", "/")
            f.write(f'"{p}"\n')

    ld_flags = [
        "-T", str(LDSCRIPT),
        "-nostdlib",
        "--allow-multiple-definition",
        "--no-check-sections",
        "--noinhibit-exec",
    ]

    result = subprocess.run(
        [str(LD)] + ld_flags + ["-o", str(OUTPUT_ELF), f"@{rsp_file}"],
        capture_output=True, text=True, timeout=120,
        cwd=str(REPO)
    )
    if result.returncode != 0:
        print(f"  Link warnings/errors (may be expected with --noinhibit-exec):")
        # Only show first few lines of errors
        for line in result.stderr.split("\n")[:10]:
            if line.strip():
                print(f"    {line}")
        # Check if output exists despite warnings
        if not OUTPUT_ELF.exists():
            print("  FATAL: Link failed, no output ELF produced")
            return False

    return True


def verify_elf_matches(dol_data, injections):
    """Verify that injected functions in the linked ELF match the DOL."""
    if not OUTPUT_ELF.exists():
        print("  ERROR: No ELF to verify")
        return 0

    # Read the ELF and compare at each injected address
    # We need to read the ELF's loadable segments
    with open(OUTPUT_ELF, "rb") as f:
        elf_data = f.read()

    # Parse ELF headers to find section load addresses
    # ELF32 format
    if elf_data[:4] != b'\x7fELF':
        print("  ERROR: Not a valid ELF file")
        return 0

    # Parse program headers to build virtual address -> file offset mapping
    e_phoff = struct.unpack(">I", elf_data[28:32])[0]
    e_phentsize = struct.unpack(">H", elf_data[42:44])[0]
    e_phnum = struct.unpack(">H", elf_data[44:46])[0]

    segments = []
    for i in range(e_phnum):
        ph_off = e_phoff + i * e_phentsize
        p_type = struct.unpack(">I", elf_data[ph_off:ph_off + 4])[0]
        if p_type != 1:  # PT_LOAD
            continue
        p_offset = struct.unpack(">I", elf_data[ph_off + 4:ph_off + 8])[0]
        p_vaddr = struct.unpack(">I", elf_data[ph_off + 8:ph_off + 12])[0]
        p_filesz = struct.unpack(">I", elf_data[ph_off + 16:ph_off + 20])[0]
        p_memsz = struct.unpack(">I", elf_data[ph_off + 20:ph_off + 24])[0]
        segments.append((p_vaddr, p_offset, p_filesz, p_memsz))

    def get_elf_bytes(addr, size):
        for vaddr, foff, fsz, msz in segments:
            if addr >= vaddr and addr + size <= vaddr + fsz:
                off = foff + (addr - vaddr)
                return elf_data[off:off + size]
        return None

    matched = 0
    failed = 0
    for addr, expected_bytes in sorted(injections.items()):
        elf_bytes = get_elf_bytes(addr, len(expected_bytes))
        dol_bytes = get_dol_bytes(dol_data, addr, len(expected_bytes))
        if elf_bytes is not None and dol_bytes is not None and elf_bytes == dol_bytes:
            matched += 1
        else:
            failed += 1
            if failed <= 5:
                if elf_bytes is None:
                    print(f"  FAIL 0x{addr:08X}: not found in ELF segments")
                elif dol_bytes is None:
                    print(f"  FAIL 0x{addr:08X}: not found in DOL")
                else:
                    # Find first diff
                    for i in range(min(len(elf_bytes), len(dol_bytes))):
                        if elf_bytes[i] != dol_bytes[i]:
                            print(f"  FAIL 0x{addr:08X}: diff at offset +0x{i:X}")
                            break

    return matched


def count_all_elf_matches(dol_data):
    """Count ALL byte-matching functions in the ELF vs DOL (not just injected ones)."""
    if not OUTPUT_ELF.exists():
        return 0, 0

    with open(OUTPUT_ELF, "rb") as f:
        elf_data = f.read()

    if elf_data[:4] != b'\x7fELF':
        return 0, 0

    # Parse program headers
    e_phoff = struct.unpack(">I", elf_data[28:32])[0]
    e_phentsize = struct.unpack(">H", elf_data[42:44])[0]
    e_phnum = struct.unpack(">H", elf_data[44:46])[0]

    segments = []
    for i in range(e_phnum):
        ph_off = e_phoff + i * e_phentsize
        p_type = struct.unpack(">I", elf_data[ph_off:ph_off + 4])[0]
        if p_type != 1:
            continue
        p_offset = struct.unpack(">I", elf_data[ph_off + 4:ph_off + 8])[0]
        p_vaddr = struct.unpack(">I", elf_data[ph_off + 8:ph_off + 12])[0]
        p_filesz = struct.unpack(">I", elf_data[ph_off + 16:ph_off + 20])[0]
        p_memsz = struct.unpack(">I", elf_data[ph_off + 20:ph_off + 24])[0]
        segments.append((p_vaddr, p_offset, p_filesz, p_memsz))

    def get_elf_bytes(addr, size):
        for vaddr, foff, fsz, msz in segments:
            if addr >= vaddr and addr + size <= vaddr + fsz:
                off = foff + (addr - vaddr)
                return elf_data[off:off + size]
        return None

    # Parse all function symbols from symbols.txt
    all_symbols = parse_symbols()
    total_funcs = 0
    total_match = 0
    total_bytes_matched = 0

    for name, (addr, size, section, kind) in all_symbols.items():
        if kind != "function" or size == 0:
            continue
        if section not in ("text", "init"):
            continue

        total_funcs += 1
        dol_bytes = get_dol_bytes(dol_data, addr, size)
        elf_bytes = get_elf_bytes(addr, size)

        if dol_bytes is not None and elf_bytes is not None and dol_bytes == elf_bytes:
            # Make sure it's not all zeros (skeleton space)
            if dol_bytes != b'\x00' * size:
                total_match += 1
                total_bytes_matched += size

    return total_match, total_bytes_matched


# ============================================================================
# Main
# ============================================================================
def main():
    parser = argparse.ArgumentParser(
        description="Inject byte-matched functions into the skeleton assembly."
    )
    parser.add_argument("--rebuild", action="store_true",
                        help="Rebuild skeleton and relink after injection")
    parser.add_argument("--verify", action="store_true",
                        help="Verify matches in the linked ELF")
    parser.add_argument("--dry-run", action="store_true",
                        help="Don't write files, just show what would be injected")
    parser.add_argument("--verbose", "-v", action="store_true",
                        help="Show each matching function")
    parser.add_argument("--compile", action="store_true",
                        help="Compile matched sources before injection")
    args = parser.parse_args()

    # Default: do everything
    if not args.rebuild and not args.verify and not args.compile:
        args.compile = True
        args.rebuild = True
        args.verify = True

    print("=" * 70)
    print("INJECT MATCHES — Bake matched function bytes into skeleton")
    print("=" * 70)

    # Step 1: Compile
    if args.compile:
        print("\n[1/5] Compiling src/matched/*.cpp...")
        compiled, errors = compile_matched_sources()
        print(f"  {compiled} compiled, {errors} errors")

    # Step 2: Find matches
    print("\n[2/5] Finding byte-matching functions (.o vs DOL)...")
    dol_data = read_dol()
    matches, total, byte_match, mismatch, skipped = find_matching_functions(
        dol_data, verbose=args.verbose
    )
    print(f"  Total functions checked:    {total}")
    print(f"  Byte-identical matches:     {byte_match} ({byte_match*100.0/total:.1f}%)" if total > 0 else "  No functions found")
    print(f"  Mismatched:                 {mismatch}")
    print(f"  Skipped (not in DOL):       {skipped}")
    print(f"  Total bytes to inject:      {sum(len(b) for b in matches.values()):,}")

    if not matches:
        print("\n  No matches to inject!")
        return

    # Step 2b: Also inject bytes from .s-based .o files
    # The _final_rawbyte.s file contains raw DOL bytes for functions that
    # GCC can't compile without adding prologues. We assemble it with GAS
    # and compare the resulting .o bytes against the DOL.
    asm_o = MATCHED_OBJ.parent.parent / "obj" / "matched" / "_final_rawbyte.o"
    asm_s = MATCHED_SRC / "_final_rawbyte.s"
    if asm_s.exists():
        # Assemble
        subprocess.run(
            [str(AS), "-mgekko", "-mregnames", "-memb",
             str(asm_s), "-o", str(asm_o)],
            capture_output=True, timeout=60, cwd=str(REPO)
        )
        if asm_o.exists():
            asm_funcs = get_all_funcs_from_obj(asm_o)
            asm_added = 0
            for fname, fbytes in asm_funcs:
                # Parse address from function name: __asmrawbyte_0xADDR
                m = re.match(r'__asmrawbyte_0x([0-9A-Fa-f]+)', fname)
                if not m:
                    continue
                addr = int(m.group(1), 16)
                if addr in matches:
                    continue  # Already matched
                size = len(fbytes)
                dol_bytes = get_dol_bytes(dol_data, addr, size)
                if dol_bytes and dol_bytes == fbytes:
                    matches[addr] = fbytes
                    asm_added += 1
            if asm_added > 0:
                print(f"  Added {asm_added} matches from _final_rawbyte.s")

    if args.dry_run:
        print("\n  DRY RUN — not writing any files")
        print(f"\n  Would inject {len(matches)} functions into skeleton")
        return

    # Step 3: Regenerate skeleton with injected bytes
    print(f"\n[3/5] Regenerating skeleton with {len(matches)} injected functions...")
    skeleton_symbols = parse_symbols_for_skeleton()
    SKELETON_DIR.mkdir(parents=True, exist_ok=True)

    total_injected = 0
    for section in SECTION_BASES:
        syms = skeleton_symbols.get(section, [])
        path, count = write_section_asm_with_injections(
            section, syms, SKELETON_DIR, matches
        )
        if count > 0:
            print(f"  {section:8s}: {count:4d} functions injected -> {path}")
            total_injected += count
        else:
            # Write without injections (same as gen_skeleton.py)
            pass

    print(f"  Total injected: {total_injected}")

    # Step 4: Rebuild
    if args.rebuild:
        print("\n[4/5] Assembling skeleton and linking ELF...")
        ok = rebuild_skeleton_and_link()
        if ok:
            print(f"  Linked: {OUTPUT_ELF}")
        else:
            print("  Build failed!")
            return

    # Step 5: Verify
    if args.verify and args.rebuild:
        print("\n[5/5] Verifying matches in linked ELF...")
        verified = verify_elf_matches(dol_data, matches)
        print(f"  Injected functions verified in ELF: {verified}/{len(matches)}")

        # Also count ALL matches
        all_match, all_bytes = count_all_elf_matches(dol_data)
        print(f"\n  TOTAL functions matching in ELF vs DOL: {all_match}")
        print(f"  TOTAL bytes matching: {all_bytes:,}")

    print("\n" + "=" * 70)
    print(f"DONE — {len(matches)} functions injected into skeleton")
    print("=" * 70)


if __name__ == "__main__":
    main()
