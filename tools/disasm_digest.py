#!/usr/bin/env python3
"""Disassemble a DOL function and summarize RE-relevant instruction shapes.

Usage:
  bash tools/disasm_digest.sh <addr> <size>
  bash tools/py3.sh tools/disasm_digest.py <addr> <size>

The shell wrapper intentionally avoids assuming whether the caller's shell has
`python`, `python3`, or only the Windows `py -3` launcher.
"""

from __future__ import annotations

import argparse
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
from pathlib import Path


REPO = Path(__file__).resolve().parent.parent
DOL = REPO / "extracted" / "sys" / "main.dol"
MAP = REPO / "extracted" / "files" / "u2_ngc_release_dvd.map"

MEM_OPS = {
    32: "lwz", 33: "lwzu", 34: "lbz", 35: "lbzu", 36: "stw", 37: "stwu",
    38: "stb", 39: "stbu", 40: "lhz", 41: "lhzu", 42: "lha", 43: "lhau",
    44: "sth", 45: "sthu", 46: "lmw", 47: "stmw", 48: "lfs", 49: "lfsu",
    50: "lfd", 51: "lfdu", 52: "stfs", 53: "stfsu", 54: "stfd", 55: "stfdu",
}


def die(message: str) -> None:
    print(f"ERROR: {message}", file=sys.stderr)
    raise SystemExit(1)


def find_objdump() -> str:
    candidates = []
    if os.environ.get("POWERPC_OBJDUMP"):
        candidates.append(os.environ["POWERPC_OBJDUMP"])
    if os.environ.get("DEVKITPPC"):
        candidates.extend([
            str(Path(os.environ["DEVKITPPC"]) / "bin" / "powerpc-eabi-objdump"),
            str(Path(os.environ["DEVKITPPC"]) / "bin" / "powerpc-eabi-objdump.exe"),
        ])
    candidates.extend([
        "/f/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe",
        "/mnt/f/coding/Decompiles/Tools/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe",
        r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC\bin\powerpc-eabi-objdump.exe",
        "/opt/devkitpro/devkitPPC/bin/powerpc-eabi-objdump",
        "/c/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe",
        "/d/devkitPro/devkitPPC/bin/powerpc-eabi-objdump.exe",
    ])
    for candidate in candidates:
        if candidate and Path(candidate).is_file():
            return candidate
    for name in ("powerpc-eabi-objdump", "powerpc-linux-gnu-objdump", "ppc-eabi-objdump"):
        found = shutil.which(name)
        if found:
            return found
    die("powerpc-eabi-objdump not found; set POWERPC_OBJDUMP or DEVKITPPC")


def host_path(path: Path) -> str:
    path = path.resolve()
    if shutil.which("wslpath"):
        result = subprocess.run(
            ["wslpath", "-w", str(path)],
            capture_output=True,
            check=True,
            text=True,
        )
        return result.stdout.strip()
    return str(path)


def vaddr_to_offset(dol: bytes, vaddr: int) -> int | None:
    for i in range(7):
        off = struct.unpack_from(">I", dol, i * 4)[0]
        addr = struct.unpack_from(">I", dol, 0x48 + i * 4)[0]
        size = struct.unpack_from(">I", dol, 0x90 + i * 4)[0]
        if size and addr <= vaddr < addr + size:
            return off + (vaddr - addr)
    return None


def extract_dol_bytes(addr: int, size: int) -> bytes:
    dol = DOL.read_bytes()
    off = vaddr_to_offset(dol, addr)
    if off is None:
        die(f"0x{addr:08X} is not in a DOL text section")
    return dol[off:off + size]


def load_symbols() -> dict[int, str]:
    symbols: dict[int, str] = {}
    if not MAP.is_file():
        return symbols
    pattern = re.compile(r"^([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s+\d+\s+(.*)$")
    with MAP.open("r", encoding="utf-8", errors="replace") as f:
        for line in f:
            match = pattern.match(line)
            if not match:
                continue
            addr = int(match.group(1), 16)
            name = match.group(3).strip()
            if name:
                symbols[addr] = name
    return symbols


def run_objdump(raw: bytes, addr: int) -> list[str]:
    objdump = find_objdump()
    tmp_root = REPO / "build" / "tmp"
    tmp_root.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="disasm_digest.", dir=tmp_root) as tmp:
        raw_path = Path(tmp) / "func.bin"
        raw_path.write_bytes(raw)
        objdump_input = host_path(raw_path) if objdump.lower().endswith(".exe") else str(raw_path)
        result = subprocess.run(
            [
                objdump, "-D", "-b", "binary", "-m", "powerpc", "-EB",
                f"--adjust-vma=0x{addr:X}", objdump_input,
            ],
            capture_output=True,
            text=True,
        )
    if result.returncode != 0:
        print(result.stderr, file=sys.stderr, end="")
        die("objdump failed")
    return result.stdout.splitlines()


def parse_objdump(lines: list[str]) -> list[dict[str, object]]:
    instructions = []
    pattern = re.compile(
        r"^\s*([0-9a-fA-F]+):\s+"
        r"((?:[0-9a-fA-F]{2} ?)+)\s+"
        r"(\S+)"
        r"(?:\s+(.*?))?\s*$"
    )
    for line in lines:
        match = pattern.match(line)
        if not match:
            continue
        instructions.append({
            "addr": int(match.group(1), 16),
            "raw": match.group(2).strip(),
            "word": int(match.group(2).replace(" ", "")[:8], 16),
            "mnemonic": match.group(3),
            "operands": (match.group(4) or "").strip(),
        })
    return instructions


def sign_extend(value: int, bits: int) -> int:
    sign = 1 << (bits - 1)
    return (value ^ sign) - sign


def branch_info(addr: int, word: int) -> tuple[str, int, bool, bool] | None:
    opcode = (word >> 26) & 0x3F
    aa = bool((word >> 1) & 1)
    lk = bool(word & 1)
    if opcode == 18:
        disp = sign_extend(word & 0x03FFFFFC, 26)
        return ("b", disp if aa else addr + disp, lk, aa)
    if opcode == 16:
        disp = sign_extend(word & 0x0000FFFC, 16)
        return ("bc", disp if aa else addr + disp, lk, aa)
    return None


def memory_info(word: int) -> tuple[str, int, int, int] | None:
    opcode = (word >> 26) & 0x3F
    mnemonic = MEM_OPS.get(opcode)
    if not mnemonic:
        return None
    reg = (word >> 21) & 0x1F
    base = (word >> 16) & 0x1F
    disp = sign_extend(word & 0xFFFF, 16)
    return mnemonic, reg, base, disp


def symbol_for(symbols: dict[int, str], addr: int) -> str:
    return symbols.get(addr, "")


def print_summary(instructions: list[dict[str, object]], symbols: dict[int, str],
                  start: int, size: int) -> None:
    calls = []
    branches = []
    sda = []
    indirect = []
    stack = []
    returns = []

    end = start + size
    for ins in instructions:
        addr = int(ins["addr"])
        word = int(ins["word"])
        mnemonic = str(ins["mnemonic"])
        operands = str(ins["operands"])

        branch = branch_info(addr, word)
        if branch:
            kind, target, link, absolute = branch
            label = symbol_for(symbols, target)
            item = (addr, mnemonic, target, label, link, absolute)
            if link:
                calls.append(item)
            else:
                branches.append(item)
            continue

        mem = memory_info(word)
        if mem:
            mem_mnemonic, reg, base, disp = mem
            if base in (2, 13):
                sda.append((addr, mem_mnemonic, reg, base, disp))
            if mem_mnemonic == "stwu" and base == 1 and reg == 1:
                stack.append((addr, f"frame alloc {disp} bytes"))

        if mnemonic in ("bctrl", "blrl"):
            indirect.append((addr, mnemonic, operands))
        elif mnemonic == "mtctr":
            indirect.append((addr, mnemonic, operands))
        elif mnemonic in ("blr", "bclr", "beqlr", "bnelr", "bgelr", "bgtlr", "blelr", "bltlr"):
            returns.append((addr, mnemonic, operands))
        elif mnemonic in ("mflr", "mtlr"):
            stack.append((addr, f"{mnemonic} {operands}".strip()))
        elif mnemonic == "addi" and operands.startswith("r1,r1,"):
            stack.append((addr, f"stack restore {operands}"))

    print("Summary:")
    if calls:
        print("  Direct calls:")
        for addr, mnemonic, target, label, link, absolute in calls:
            suffix = f"  ; {label}" if label else ""
            aa = " absolute" if absolute else ""
            print(f"    0x{addr:08X}: {mnemonic} -> 0x{target:08X}{aa}{suffix}")
    else:
        print("  Direct calls: none")

    if branches:
        print("  Branches:")
        for addr, mnemonic, target, label, _link, absolute in branches:
            scope = "local" if start <= target < end else "external"
            suffix = f"  ; {label}" if label else ""
            aa = " absolute" if absolute else ""
            print(f"    0x{addr:08X}: {mnemonic} -> 0x{target:08X} ({scope}){aa}{suffix}")
    else:
        print("  Branches: none")

    if sda:
        print("  SDA / small-data accesses:")
        for addr, mnemonic, reg, base, disp in sda:
            area = "r13/sdata" if base == 13 else "r2/sdata2"
            print(f"    0x{addr:08X}: {mnemonic} reg {reg}, {disp:+#x}(r{base})  [{area}]")
    else:
        print("  SDA / small-data accesses: none")

    if indirect:
        print("  Indirect call / vcall hints:")
        for addr, mnemonic, operands in indirect:
            print(f"    0x{addr:08X}: {mnemonic} {operands}".rstrip())
    else:
        print("  Indirect call / vcall hints: none")

    if stack:
        print("  Stack/LR hints:")
        for addr, text in stack:
            print(f"    0x{addr:08X}: {text}")
    else:
        print("  Stack/LR hints: none")

    if returns:
        print("  Returns:")
        for addr, mnemonic, operands in returns:
            print(f"    0x{addr:08X}: {mnemonic} {operands}".rstrip())
    print()


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("addr", type=lambda s: int(s, 0))
    parser.add_argument("size", type=lambda s: int(s, 0))
    parser.add_argument("--raw", action="store_true", help="print raw objdump output too")
    args = parser.parse_args()

    raw = extract_dol_bytes(args.addr, args.size)
    symbols = load_symbols()
    lines = run_objdump(raw, args.addr)
    instructions = parse_objdump(lines)

    name = symbol_for(symbols, args.addr) or "unknown"
    print(f"Function: {name}")
    print(f"Address:  0x{args.addr:08X}")
    print(f"Size:     {args.size} bytes ({args.size // 4} instructions)")
    print(f"Raw:      {raw.hex()}")
    print()

    print("Disassembly:")
    for ins in instructions:
        print(
            f"  0x{int(ins['addr']):08X}: "
            f"{str(ins['raw']).ljust(11)}  "
            f"{str(ins['mnemonic']).ljust(8)} {ins['operands']}".rstrip()
        )
    print()
    print_summary(instructions, symbols, args.addr, args.size)

    if args.raw:
        print("Raw objdump:")
        print("\n".join(lines))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
