#!/usr/bin/env python3
"""verify_match.py — Verify a decompiled function matches the original DOL.

Usage:
    python tools/verify_match.py <source.cpp> [--addr 0xADDRESS --size SIZE]

If --addr/--size not given, reads them from the "// 0xADDRESS (SIZE bytes)" comment
in the source file.

Returns exit code 0 if ALL functions in the file match, 1 if any mismatch.
"""

import struct
import subprocess
import sys
import re
import os

# Paths
DEVKITPPC = os.environ.get("DEVKITPPC", "/f/coding/Decompiles/Tools/devkitPro/devkitPPC")
MSYS2_BIN = "/f/coding/Decompiles/Tools/devkitPro/msys2/usr/bin"
CXX = f"{DEVKITPPC}/bin/powerpc-eabi-g++"
OBJDUMP = f"{DEVKITPPC}/bin/powerpc-eabi-objdump"
DOL_PATH = "extracted/sys/main.dol"
BUILD_DIR = "build"

CXXFLAGS = [
    "-mcpu=750", "-meabi", "-mhard-float",
    "-O2",
    "-fno-schedule-insns", "-fno-schedule-insns2",
    "-fno-inline", "-fno-inline-small-functions",
    "-fno-exceptions", "-fno-rtti", "-fno-builtin",
    "-fshort-wchar",
    "-Wall", "-Wno-unused", "-Wno-return-type",
    "-fpermissive",
]

def read_dol():
    with open(DOL_PATH, "rb") as f:
        return f.read()

def dol_vaddr_to_offset(dol_data, vaddr):
    """Convert a virtual address to a file offset in the DOL."""
    for i in range(7):  # text sections
        off = struct.unpack(">I", dol_data[i*4:i*4+4])[0]
        addr = struct.unpack(">I", dol_data[0x48+i*4:0x48+i*4+4])[0]
        size = struct.unpack(">I", dol_data[0x90+i*4:0x90+i*4+4])[0]
        if addr <= vaddr < addr + size:
            return off + (vaddr - addr)
    for i in range(11):  # data sections
        off = struct.unpack(">I", dol_data[0x1C+i*4:0x1C+i*4+4])[0]
        addr = struct.unpack(">I", dol_data[0x64+i*4:0x64+i*4+4])[0]
        size = struct.unpack(">I", dol_data[0xAC+i*4:0xAC+i*4+4])[0]
        if addr <= vaddr < addr + size:
            return off + (vaddr - addr)
    return None

def extract_dol_bytes(dol_data, vaddr, size):
    """Extract raw bytes from the DOL at a given virtual address."""
    foff = dol_vaddr_to_offset(dol_data, vaddr)
    if foff is None:
        return None
    return dol_data[foff:foff+size]

def compile_source(src_path):
    """Compile a C++ source file to a PPC object file."""
    obj_name = os.path.splitext(os.path.basename(src_path))[0] + ".o"
    obj_path = os.path.join(BUILD_DIR, obj_name)
    os.makedirs(BUILD_DIR, exist_ok=True)

    flags_str = " ".join(CXXFLAGS)
    # Convert Windows paths to MSYS2 paths and quote for spaces
    src_msys = src_path.replace("\\", "/")
    obj_msys = obj_path.replace("\\", "/")
    bash_cmd = f'export PATH="{MSYS2_BIN}:$PATH" && "{CXX}" {flags_str} -c "{src_msys}" -o "{obj_msys}"'
    bash_exe = r"C:\Program Files\Git\usr\bin\bash.exe"
    result = subprocess.run([bash_exe, "-c", bash_cmd], capture_output=True, text=True)
    if result.returncode != 0:
        print(f"COMPILE ERROR:\n{result.stderr}")
        return None
    return obj_path

def get_compiled_functions(obj_path):
    """Extract function bytes from compiled object using objdump."""
    obj_msys = obj_path.replace("\\", "/")
    bash_cmd = f'export PATH="{MSYS2_BIN}:$PATH" && "{OBJDUMP}" -d "{obj_msys}"'
    bash_exe = r"C:\Program Files\Git\usr\bin\bash.exe"
    result = subprocess.run([bash_exe, "-c", bash_cmd], capture_output=True, text=True)
    if result.returncode != 0:
        return {}

    functions = {}
    current_func = None
    current_bytes = bytearray()

    for line in result.stdout.splitlines():
        # Function header: "00000000 <_ZN8ESimsApp18GetDefaultLanguageEv>:"
        m = re.match(r'^[0-9a-f]+ <(.+)>:', line)
        if m:
            if current_func:
                functions[current_func] = bytes(current_bytes)
            current_func = m.group(1)
            current_bytes = bytearray()
            continue

        # Instruction: "   0:	38 60 00 00 	li      r3,0"
        m = re.match(r'^\s+[0-9a-f]+:\s+((?:[0-9a-f]{2}\s)+)', line)
        if m and current_func:
            hex_str = m.group(1).strip()
            for byte_str in hex_str.split():
                current_bytes.append(int(byte_str, 16))

    if current_func:
        functions[current_func] = bytes(current_bytes)

    return functions

def parse_source_annotations(src_path):
    """Parse // 0xADDRESS (SIZE bytes) comments from source."""
    annotations = []
    with open(src_path, "r") as f:
        for line in f:
            m = re.match(r'//\s*0x([0-9A-Fa-f]+)\s*\((\d+)\s*bytes?\)', line.strip())
            if m:
                addr = int(m.group(1), 16)
                size = int(m.group(2))
                annotations.append((addr, size))
    return annotations

def main():
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <source.cpp> [--addr 0xADDR --size N]")
        sys.exit(1)

    src_path = sys.argv[1]

    # Parse optional addr/size from command line
    manual_addr = None
    manual_size = None
    i = 2
    while i < len(sys.argv):
        if sys.argv[i] == "--addr" and i+1 < len(sys.argv):
            manual_addr = int(sys.argv[i+1], 0)
            i += 2
        elif sys.argv[i] == "--size" and i+1 < len(sys.argv):
            manual_size = int(sys.argv[i+1], 0)
            i += 2
        else:
            i += 1

    # Read DOL
    dol_data = read_dol()

    # Compile source
    print(f"Compiling {src_path}...")
    obj_path = compile_source(src_path)
    if not obj_path:
        sys.exit(1)

    # Get compiled function bytes
    compiled = get_compiled_functions(obj_path)
    if not compiled:
        print("ERROR: No functions found in compiled output")
        sys.exit(1)

    # Get annotations from source
    annotations = parse_source_annotations(src_path)

    # If manual addr/size given, use that for the first (or only) function
    if manual_addr is not None and manual_size is not None:
        annotations = [(manual_addr, manual_size)]

    if not annotations:
        print("WARNING: No address annotations found. Showing compiled output:")
        for name, data in compiled.items():
            hex_str = " ".join(f"{b:02X}" for b in data)
            print(f"  {name}: {hex_str}")
        sys.exit(0)

    # Verify each annotated function
    total = 0
    matched = 0

    for addr, size in annotations:
        total += 1

        # Get DOL bytes
        dol_bytes = extract_dol_bytes(dol_data, addr, size)
        if dol_bytes is None:
            print(f"  0x{addr:08X} ({size}B): ERROR - address not found in DOL")
            continue

        # Find matching compiled function (by size)
        match_found = False
        for func_name, func_bytes in compiled.items():
            if len(func_bytes) == size:
                if func_bytes == dol_bytes:
                    print(f"  0x{addr:08X} ({size:4d}B): MATCH ✓  [{func_name}]")
                    matched += 1
                    match_found = True
                    break
                else:
                    dol_hex = " ".join(f"{b:02X}" for b in dol_bytes)
                    our_hex = " ".join(f"{b:02X}" for b in func_bytes)
                    print(f"  0x{addr:08X} ({size:4d}B): MISMATCH ✗  [{func_name}]")
                    print(f"    DOL: {dol_hex}")
                    print(f"    Ours: {our_hex}")
                    match_found = True
                    break

        if not match_found:
            # Try matching any function
            for func_name, func_bytes in compiled.items():
                if func_bytes[:size] == dol_bytes:
                    print(f"  0x{addr:08X} ({size:4d}B): PARTIAL MATCH (func is {len(func_bytes)}B) [{func_name}]")
                    match_found = True
                    break

            if not match_found:
                dol_hex = " ".join(f"{b:02X}" for b in dol_bytes)
                print(f"  0x{addr:08X} ({size:4d}B): NO MATCHING FUNCTION FOUND")
                print(f"    DOL: {dol_hex}")
                print(f"    Compiled functions:")
                for fn, fb in compiled.items():
                    print(f"      {fn}: {len(fb)}B")

    print(f"\nResult: {matched}/{total} functions matched")
    sys.exit(0 if matched == total else 1)

if __name__ == "__main__":
    main()
