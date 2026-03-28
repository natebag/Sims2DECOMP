#!/usr/bin/env python3
"""
Sims 2 GameCube — Function matching checker

Compiles a single source file, extracts a function, and compares its
disassembly against the original DOL/ELF.

Usage:
    python check_func.py <source_file> <function_name>
    python check_func.py src/boot/crt0.s __start
"""

import argparse
import subprocess
import sys
from pathlib import Path

DEVKITPPC = Path("F:/coding/Decompiles/Tools/devkitPro/devkitPPC")
DTK = Path("F:/coding/Decompiles/Tools/dtk-windows-x86_64.exe")
ORIGINAL_ELF = Path("extracted/files/u2_ngc_release_dvd.elf")
BUILD_DIR = Path("build/check")

CXX = DEVKITPPC / "bin" / "powerpc-eabi-g++.exe"
CC = DEVKITPPC / "bin" / "powerpc-eabi-gcc.exe"
AS = DEVKITPPC / "bin" / "powerpc-eabi-as.exe"
OBJDUMP = DEVKITPPC / "bin" / "powerpc-eabi-objdump.exe"

CXXFLAGS = [
    "-mcpu=750", "-meabi", "-mhard-float",
    "-O2",
    "-fno-exceptions", "-fno-rtti", "-fno-builtin",
    "-fshort-wchar",
    "-Iinclude", "-Isrc",
    "-DNDEBUG", "-DEA_PLATFORM_GAMECUBE=1", "-DGEKKO",
]

CFLAGS = [
    "-mcpu=750", "-meabi", "-mhard-float",
    "-O2",
    "-fno-builtin",
    "-Iinclude", "-Isrc",
    "-DNDEBUG", "-DEA_PLATFORM_GAMECUBE=1", "-DGEKKO",
]


def compile_file(src_path):
    """Compile a single source file and return the object path."""
    BUILD_DIR.mkdir(parents=True, exist_ok=True)
    obj_path = BUILD_DIR / (src_path.stem + ".o")

    if src_path.suffix == '.cpp':
        cmd = [str(CXX)] + CXXFLAGS + ["-c", str(src_path), "-o", str(obj_path)]
    elif src_path.suffix == '.c':
        cmd = [str(CC)] + CFLAGS + ["-c", str(src_path), "-o", str(obj_path)]
    elif src_path.suffix == '.s':
        cmd = [str(AS), "-mcpu=750", "-meabi", str(src_path), "-o", str(obj_path)]
    else:
        print(f"Unknown file type: {src_path.suffix}")
        return None

    print(f"Compiling {src_path}...")
    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Compilation failed:\n{result.stderr}")
        return None

    return obj_path


def disassemble(obj_path, func_name=None):
    """Disassemble an object file, optionally filtering to a specific function."""
    cmd = [str(OBJDUMP), "-d", "-M", "gekko", str(obj_path)]
    result = subprocess.run(cmd, capture_output=True, text=True)

    if func_name:
        # Filter to just the requested function
        lines = result.stdout.split('\n')
        in_func = False
        func_lines = []
        for line in lines:
            if func_name in line and ':' in line:
                in_func = True
            elif in_func and (line.strip() == '' or (not line.startswith(' ') and ':' in line)):
                if func_lines:
                    break
            if in_func:
                func_lines.append(line)
        return '\n'.join(func_lines)

    return result.stdout


def disassemble_original(addr, size=256):
    """Disassemble from the original ELF at a given address."""
    cmd = [
        str(OBJDUMP), "-d", "-M", "gekko",
        f"--start-address=0x{addr:08X}",
        f"--stop-address=0x{addr + size:08X}",
        str(ORIGINAL_ELF)
    ]
    result = subprocess.run(cmd, capture_output=True, text=True)
    return result.stdout


def main():
    parser = argparse.ArgumentParser(description="Check function matching")
    parser.add_argument("source", help="Source file to compile")
    parser.add_argument("function", nargs="?", help="Function name to check")
    parser.add_argument("--addr", type=lambda x: int(x, 16),
                        help="Original address (hex) for comparison")
    parser.add_argument("--size", type=int, default=256,
                        help="Size of original function for comparison")
    args = parser.parse_args()

    src_path = Path(args.source)
    obj_path = compile_file(src_path)
    if not obj_path:
        sys.exit(1)

    print(f"\n=== Compiled output ===")
    asm = disassemble(obj_path, args.function)
    print(asm if asm else "(no matching function found)")

    if args.addr:
        print(f"\n=== Original (0x{args.addr:08X}) ===")
        orig = disassemble_original(args.addr, args.size)
        print(orig)


if __name__ == "__main__":
    main()
