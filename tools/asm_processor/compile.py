"""SN ProDG compile + assemble + byte-diff wrappers.

Mirrors tools/verify_match.sh logic in Python so we can interpose between
cc1plus and NgcAs to run mutators on the .s output. Byte-diff reuses the
relocation-aware masking approach.
"""
from __future__ import annotations

import re
import struct
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[2]
SN_BIN = REPO_ROOT / "compiler" / "ProDGforNGCv393" / "Disk1" / "data1" / "Build_Tools_Bin"
SN_CC1PLUS = SN_BIN / "cc1plus.exe"
SN_AS = SN_BIN / "NgcAs.exe"
DEVKIT = Path(r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC")
OBJDUMP = DEVKIT / "bin" / "powerpc-eabi-objdump.exe"
FALLBACK_AS = DEVKIT / "bin" / "powerpc-eabi-as.exe"
DOL = REPO_ROOT / "extracted" / "sys" / "main.dol"

DEFAULT_SN_FLAGS = ["-quiet", "-O2", "-fno-elide-constructors", "-msdata=eabi", "-G", "8"]


class CompileError(RuntimeError):
    pass


@dataclass
class CompileResult:
    asm_text: str
    obj_path: Path
    stdout: str
    stderr: str


def strip_line_comments(cpp_text: str) -> str:
    out = []
    for line in cpp_text.splitlines():
        s = line
        if "//" in s:
            s = s.split("//", 1)[0]
        out.append(s)
    return "\n".join(out) + "\n"


def extract_flag_override(cpp_text: str) -> list[str] | None:
    m = re.search(r"//\s*FLAGS:\s*(.+)", cpp_text)
    if not m:
        return None
    return m.group(1).strip().split()


def run_cc1plus(clean_src: Path, asm_out: Path, extra_flags: list[str] | None = None) -> CompileResult:
    if not SN_CC1PLUS.is_file():
        raise CompileError(f"SN cc1plus not found at {SN_CC1PLUS}")
    flags = list(DEFAULT_SN_FLAGS)
    if extra_flags:
        flags = ["-quiet", "-O2", *extra_flags, "-msdata=eabi", "-G", "8"]
    cmd = [str(SN_CC1PLUS), str(clean_src), "-o", str(asm_out), *flags]
    proc = subprocess.run(cmd, capture_output=True, text=True)
    if proc.returncode != 0:
        raise CompileError(f"cc1plus failed:\n{proc.stderr}\n{proc.stdout}")
    asm_text = asm_out.read_text(encoding="utf-8", errors="replace")
    return CompileResult(asm_text=asm_text, obj_path=asm_out, stdout=proc.stdout, stderr=proc.stderr)


def run_as(asm_src: Path, obj_out: Path) -> None:
    if SN_AS.is_file():
        proc = subprocess.run(
            [str(SN_AS), str(asm_src), "-o", str(obj_out)],
            capture_output=True, text=True,
        )
        if proc.returncode == 0:
            return
    if not FALLBACK_AS.is_file():
        raise CompileError(f"Neither SN NgcAs nor devkitPPC as available ({SN_AS}, {FALLBACK_AS})")
    proc = subprocess.run(
        [str(FALLBACK_AS), "-mgekko", "-mregnames", str(asm_src), "-o", str(obj_out)],
        capture_output=True, text=True,
    )
    if proc.returncode != 0:
        raise CompileError(f"assembler failed:\n{proc.stderr}\n{proc.stdout}")


def extract_text_bytes(obj: Path) -> bytes:
    proc = subprocess.run(
        [str(OBJDUMP), "-s", "-j", ".text", str(obj)],
        capture_output=True, text=True,
    )
    if proc.returncode != 0:
        raise CompileError(f"objdump -s failed:\n{proc.stderr}")
    out = bytearray()
    for line in proc.stdout.splitlines():
        line = line.strip()
        if not line or line.startswith("Contents"):
            continue
        parts = line.split()
        for p in parts[1:]:
            if re.fullmatch(r"[0-9a-f]{8}", p):
                out.extend(bytes.fromhex(p))
            else:
                break
    return bytes(out)


def extract_relocations(obj: Path) -> list[tuple[int, str, str]]:
    proc = subprocess.run(
        [str(OBJDUMP), "-r", "-j", ".text", str(obj)],
        capture_output=True, text=True,
    )
    if proc.returncode != 0:
        return []
    relocs = []
    for line in proc.stdout.splitlines():
        parts = line.strip().split()
        if len(parts) < 3:
            continue
        try:
            off = int(parts[0], 16)
        except ValueError:
            continue
        relocs.append((off, parts[1], parts[2]))
    return relocs


def read_dol_bytes(vaddr: int, size: int) -> bytes:
    data = DOL.read_bytes()
    for i in range(7):
        off = struct.unpack(">I", data[i * 4 : i * 4 + 4])[0]
        addr = struct.unpack(">I", data[0x48 + i * 4 : 0x48 + i * 4 + 4])[0]
        sz = struct.unpack(">I", data[0x90 + i * 4 : 0x90 + i * 4 + 4])[0]
        if addr <= vaddr < addr + sz:
            foff = off + (vaddr - addr)
            return data[foff : foff + size]
    raise CompileError(f"vaddr 0x{vaddr:08x} not in any DOL text segment")


@dataclass
class DiffResult:
    match: bool
    size_mismatch: bool
    mismatch_offsets: list[int]
    dol_hex: str
    compiled_hex: str
    masked_dol_hex: str
    masked_compiled_hex: str

    def summary(self) -> str:
        if self.size_mismatch:
            return f"SIZE_MISMATCH dol={len(self.dol_hex)//2}B compiled={len(self.compiled_hex)//2}B"
        if self.match:
            return "MATCH"
        return f"MISMATCH {len(self.mismatch_offsets)} diff offsets"


def diff_bytes_with_relocs(
    dol_bytes: bytes, compiled_bytes: bytes, relocs: list[tuple[int, str, str]]
) -> DiffResult:
    if len(dol_bytes) != len(compiled_bytes):
        return DiffResult(
            match=False,
            size_mismatch=True,
            mismatch_offsets=[],
            dol_hex=dol_bytes.hex(),
            compiled_hex=compiled_bytes.hex(),
            masked_dol_hex="",
            masked_compiled_hex="",
        )

    dol_b = bytearray(dol_bytes)
    comp_b = bytearray(compiled_bytes)
    mask = [False] * len(dol_b)

    def _mask(i: int) -> None:
        if 0 <= i < len(mask):
            mask[i] = True

    for off, rtype, target in relocs:
        if off >= len(mask):
            continue
        is_local = target.startswith(".text")
        if is_local and rtype in ("R_PPC_REL14", "R_PPC_REL24"):
            # objdump omits the "+0x0" suffix when the target offset is zero
            m = re.match(r"\.text(?:\+0x([0-9a-fA-F]+))?$", target)
            if not m:
                continue
            tgt_off = int(m.group(1), 16) if m.group(1) else 0
            disp = tgt_off - off
            instr = (
                (comp_b[off] << 24)
                | (comp_b[off + 1] << 16)
                | (comp_b[off + 2] << 8)
                | comp_b[off + 3]
            )
            if rtype == "R_PPC_REL14":
                new = (instr & 0xFFFF0003) | (disp & 0xFFFC)
            else:
                new = (instr & 0xFC000003) | (disp & 0x03FFFFFC)
            comp_b[off] = (new >> 24) & 0xFF
            comp_b[off + 1] = (new >> 16) & 0xFF
            comp_b[off + 2] = (new >> 8) & 0xFF
            comp_b[off + 3] = new & 0xFF
        elif rtype in ("R_PPC_ADDR16_HA", "R_PPC_ADDR16_LO"):
            _mask(off); _mask(off + 1)
        elif rtype == "R_PPC_EMB_SDA21":
            _mask(off); _mask(off + 1); _mask(off + 2); _mask(off + 3)
        elif rtype == "R_PPC_REL24":
            _mask(off); _mask(off + 1); _mask(off + 2); _mask(off + 3)
        elif rtype == "R_PPC_REL14":
            _mask(off + 2); _mask(off + 3)
        else:
            _mask(off); _mask(off + 1); _mask(off + 2); _mask(off + 3)

    for i in range(len(dol_b)):
        if mask[i]:
            dol_b[i] = 0xCC
            comp_b[i] = 0xCC

    diffs = [i for i in range(len(dol_b)) if dol_b[i] != comp_b[i]]
    return DiffResult(
        match=(not diffs),
        size_mismatch=False,
        mismatch_offsets=diffs,
        dol_hex=dol_bytes.hex(),
        compiled_hex=compiled_bytes.hex(),
        masked_dol_hex=dol_b.hex(),
        masked_compiled_hex=comp_b.hex(),
    )


def disasm(obj: Path) -> str:
    proc = subprocess.run(
        [str(OBJDUMP), "-d", str(obj)],
        capture_output=True, text=True,
    )
    return proc.stdout
