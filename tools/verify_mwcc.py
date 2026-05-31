#!/usr/bin/env python3
"""Verify a clean DolphinSDK match with the original MWCC compiler.

This helper is invoked by tools/verify_match.sh after its source-level cheat
checks. It masks only bit fields that the linker resolves from object-file
relocations. Unsupported relocations fail closed.
"""

from __future__ import annotations

import argparse
import os
import re
import shutil
import struct
import subprocess
import sys
from pathlib import Path


REPO = Path(__file__).resolve().parent.parent
MWCC = REPO / "compiler" / "mwcc" / "1.2.5n" / "mwcceppc.exe"
DOL = REPO / "extracted" / "sys" / "main.dol"
DEVKITPRO_ROOTS = (
    Path("/f/coding/Decompiles/Tools/devkitPro"),
    Path("/mnt/f/coding/Decompiles/Tools/devkitPro"),
    Path(r"F:\coding\Decompiles\Tools\devkitPro"),
)
MWCC_FLAGS = [
    "-c", "-proc", "gekko", "-fp", "hard", "-O4,p", "-enum", "int",
    "-Cpp_exceptions", "off", "-RTTI", "off", "-inline", "auto", "-nodefaults",
]
INCLUDE_DIRS = ("include", "src", "libs/dolphinsdk", "libs/sn_runtime")

# Bits set to 1 must still compare. Bits set to 0 are resolved by the linker.
RELOC_KEEP_MASKS = {
    # Linker patches rA (bits 11-15) and the displacement (bits 16-31).
    "R_PPC_EMB_SDA21": 0xFFE00000,
    # Linker patches the 16-bit immediate field.
    "R_PPC_ADDR16_LO": 0xFFFF0000,
    "R_PPC_ADDR16_HI": 0xFFFF0000,
    "R_PPC_ADDR16_HA": 0xFFFF0000,
    # Linker patches LI (bits 6-29); opcode, AA, and LK must still compare.
    "R_PPC_REL24": 0xFC000003,
}


def fail(message: str, exit_code: int = 2) -> None:
    print(f"MWCC VERIFY ERROR: {message}", file=sys.stderr)
    raise SystemExit(exit_code)


def find_objdump() -> Path:
    if override := os.environ.get("POWERPC_OBJDUMP"):
        candidate = Path(override)
        if candidate.is_file():
            return candidate
        fail(f"POWERPC_OBJDUMP does not exist: {override}")
    for root in DEVKITPRO_ROOTS:
        for name in ("powerpc-eabi-objdump", "powerpc-eabi-objdump.exe"):
            candidate = root / "devkitPPC" / "bin" / name
            if candidate.is_file():
                return candidate
    fail("powerpc-eabi-objdump not found under the supported devkitPro roots")


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


def get_dol_bytes(addr: int, size: int) -> bytes:
    data = DOL.read_bytes()
    for i in range(7):
        off = struct.unpack_from(">I", data, 0x00 + i * 4)[0]
        load = struct.unpack_from(">I", data, 0x48 + i * 4)[0]
        section_size = struct.unpack_from(">I", data, 0x90 + i * 4)[0]
        if section_size and load <= addr and addr + size <= load + section_size:
            file_off = off + (addr - load)
            return data[file_off:file_off + size]
    fail(f"DOL bytes not found for {addr:#x} ({size} bytes)")


def compile_obj(src: Path, out: Path) -> None:
    if not MWCC.is_file():
        fail("MWCC GC-1.2.5n not found; run: python tools/download_tool.py compilers")
    include_flags = [f"-I{host_path(REPO / include_dir)}" for include_dir in INCLUDE_DIRS]
    cmd = [str(MWCC), *MWCC_FLAGS, *include_flags, "-o", host_path(out), host_path(src)]
    result = subprocess.run(cmd, cwd=MWCC.parent, capture_output=True, text=True)
    if result.returncode != 0:
        print(result.stdout + result.stderr, end="", file=sys.stderr)
        fail("MWCC COMPILE FAILED")


def parse_obj(obj: Path, want_symbol: str | None) -> tuple[bytes, dict[int, int], dict[int, list[str]]]:
    result = subprocess.run(
        [str(find_objdump()), "-dr", os.path.relpath(obj, REPO)],
        cwd=REPO,
        capture_output=True,
        text=True,
    )
    if result.returncode != 0:
        print(result.stdout + result.stderr, end="", file=sys.stderr)
        fail("objdump failed")

    funcs: dict[str, dict[str, object]] = {}
    current: dict[str, object] | None = None
    for line in result.stdout.splitlines():
        func_match = re.match(r"^[0-9a-fA-F]+ <(.+)>:$", line)
        if func_match:
            current = {"bytes": bytearray(), "relocs": {}, "types": {}, "start": None}
            funcs[func_match.group(1)] = current
            continue
        byte_match = re.match(r"^\s*([0-9a-fA-F]+):\s+((?:[0-9a-fA-F]{2} ){1,4})", line)
        if byte_match and current is not None:
            offset = int(byte_match.group(1), 16)
            if current["start"] is None:
                current["start"] = offset
            current["bytes"].extend(int(byte, 16) for byte in byte_match.group(2).split())
            continue
        reloc_match = re.match(r"^\s*([0-9a-fA-F]+):\s+(R_PPC_\S+)", line)
        if reloc_match and current is not None:
            start = current["start"]
            if start is None:
                fail("relocation appeared before function bytes")
            reloc_type = reloc_match.group(2)
            keep_mask = RELOC_KEEP_MASKS.get(reloc_type)
            if keep_mask is None:
                fail(f"unsupported relocation {reloc_type}; refusing to wildcard unknown bits")
            word_offset = (int(reloc_match.group(1), 16) - start) & ~0x3
            current["relocs"][word_offset] = current["relocs"].get(word_offset, 0xFFFFFFFF) & keep_mask
            current["types"].setdefault(word_offset, []).append(reloc_type)

    if want_symbol:
        if want_symbol not in funcs:
            fail(f"symbol {want_symbol!r} not found in MWCC object")
        selected = funcs[want_symbol]
    elif len(funcs) == 1:
        selected = next(iter(funcs.values()))
    else:
        fail(f"MWCC object contains {len(funcs)} functions; pass an explicit symbol")
    return bytes(selected["bytes"]), selected["relocs"], selected["types"]


def masked_words(data: bytes, masks: dict[int, int]) -> list[int]:
    if len(data) % 4:
        fail(f"function size {len(data)} is not instruction-aligned")
    words = []
    for offset in range(0, len(data), 4):
        word = struct.unpack_from(">I", data, offset)[0]
        words.append(word & masks.get(offset, 0xFFFFFFFF))
    return words


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("src", type=Path)
    parser.add_argument("addr", type=lambda value: int(value, 0))
    parser.add_argument("size", type=lambda value: int(value, 0))
    parser.add_argument("--outdir", type=Path, default=Path("build/mwcc_verify"))
    parser.add_argument("--symbol")
    args = parser.parse_args()

    outdir = REPO / args.outdir
    outdir.mkdir(parents=True, exist_ok=True)
    obj = outdir / f"{args.src.stem}.o"
    compile_obj(args.src, obj)

    obj_bytes, masks, reloc_types = parse_obj(obj, args.symbol)
    dol_bytes = get_dol_bytes(args.addr, args.size)
    if len(obj_bytes) != args.size:
        print(f"SIZE_MISMATCH: obj={len(obj_bytes)}B dol={args.size}B")
        return 1

    dol_words = masked_words(dol_bytes, masks)
    obj_words = masked_words(obj_bytes, masks)
    ok = dol_words == obj_words
    print(f"{'addr':>10}  {'DOL':>8}  {'OBJ':>8}  relocation")
    for index, (dol_word, obj_word) in enumerate(zip(dol_words, obj_words)):
        offset = index * 4
        dol_raw = struct.unpack_from(">I", dol_bytes, offset)[0]
        obj_raw = struct.unpack_from(">I", obj_bytes, offset)[0]
        suffix = "" if dol_word == obj_word else "  <-- DIFF"
        types = ",".join(reloc_types.get(offset, []))
        print(f"  {args.addr + offset:08x}  {dol_raw:08x}  {obj_raw:08x}  {types}{suffix}")
    print("RESULT:", "MATCH" if ok else "MISMATCH")
    if ok:
        print(f"MATCH! Function at {args.addr:#x} ({args.size} bytes) matches perfectly (MWCC relocations masked).")
    return 0 if ok else 1


if __name__ == "__main__":
    raise SystemExit(main())
