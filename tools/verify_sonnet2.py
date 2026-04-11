#!/usr/bin/env python3
"""Local verifier that tolerates short final rows in objdump -s output.

Usage: python tools/verify_sonnet2.py <source.cpp> <addr_hex> <size>
Compiles with the same SN ProDG flags as tools/verify_match.sh, then compares
bytes with relocation masking. Exits 0 on MATCH, 1 on MISMATCH.
"""
import re
import struct
import subprocess
import sys
from pathlib import Path

REPO = Path(r"F:\coding\Decompiles\Sims 2")
DOL = REPO / "extracted/sys/main.dol"
SN_BIN = REPO / "compiler/ProDGforNGCv393/Disk1/data1/Build_Tools_Bin"
SN_CC1PLUS = SN_BIN / "cc1plus.exe"
SN_AS = SN_BIN / "NgcAs.exe"
DEVKITPPC = Path("F:/coding/Decompiles/Tools/devkitPro/devkitPPC")
OBJDUMP = DEVKITPPC / "bin/powerpc-eabi-objdump.exe"

DEFAULT_FLAGS = "-fno-elide-constructors -fno-schedule-insns2"

def vaddr_to_off(dol, vaddr):
    for i in range(7):
        off = struct.unpack('>I', dol[i*4:i*4+4])[0]
        addr = struct.unpack('>I', dol[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack('>I', dol[0x90+i*4:0x90+i*4+4])[0]
        if addr and addr <= vaddr < addr + sz:
            return off + (vaddr - addr)
    for i in range(11):
        off = struct.unpack('>I', dol[0x1C+i*4:0x1C+i*4+4])[0]
        addr = struct.unpack('>I', dol[0x64+i*4:0x64+i*4+4])[0]
        sz = struct.unpack('>I', dol[0xAC+i*4:0xAC+i*4+4])[0]
        if addr and addr <= vaddr < addr + sz:
            return off + (vaddr - addr)
    return None

def main():
    src = Path(sys.argv[1])
    addr = int(sys.argv[2], 0)
    size = int(sys.argv[3])

    build = REPO / "build/verify"
    build.mkdir(parents=True, exist_ok=True)
    base = src.stem
    clean = build / f"{base}_clean.cpp"
    asm = build / f"{base}.s"
    obj = build / f"{base}.o"

    # Strip C++ comments GCC 2.95 can't handle
    raw = src.read_text(errors='replace')
    # Detect per-file FLAGS override
    flags = DEFAULT_FLAGS
    m = re.search(r'//\s*FLAGS:\s*(.+)', raw)
    if m:
        flags = m.group(1).strip()
    # Strip // and /* */ comments (old GCC preprocessor chokes on them)
    cleaned = re.sub(r'/\*.*?\*/', '', raw, flags=re.DOTALL)
    cleaned = re.sub(r'//.*', '', cleaned)
    clean.write_text(cleaned)

    sn_flags = f"-quiet -O2 {flags} -msdata=eabi -G 8"
    r = subprocess.run(
        [str(SN_CC1PLUS), str(clean), "-o", str(asm)] + sn_flags.split(),
        capture_output=True, text=True
    )
    if r.returncode != 0:
        print("COMPILE FAILED:", r.stderr)
        return 1
    r = subprocess.run(
        [str(SN_AS), str(asm), "-o", str(obj)],
        capture_output=True, text=True
    )
    if r.returncode != 0:
        print("ASSEMBLE FAILED:", r.stderr)
        return 1

    # Extract compiled .text bytes via objdump -d (more reliable than -s)
    r = subprocess.run(
        [str(OBJDUMP), "-d", "-j", ".text", str(obj)],
        capture_output=True, text=True
    )
    comp_b = bytearray()
    for line in r.stdout.splitlines():
        m = re.match(r'\s*[0-9a-f]+:\s+([0-9a-f]{2})\s+([0-9a-f]{2})\s+([0-9a-f]{2})\s+([0-9a-f]{2})\s', line)
        if m:
            comp_b.extend(bytes.fromhex(m.group(1) + m.group(2) + m.group(3) + m.group(4)))
    comp_b = bytes(comp_b)[:size]

    # Extract DOL bytes
    dol = DOL.read_bytes()
    foff = vaddr_to_off(dol, addr)
    if foff is None:
        print("Address not in DOL")
        return 1
    dol_b = dol[foff:foff+size]

    if len(comp_b) != len(dol_b):
        print(f"SIZE_MISMATCH compiled={len(comp_b)} dol={len(dol_b)}")
        _diff(dol_b, comp_b)
        return 1

    # Get relocations
    r = subprocess.run(
        [str(OBJDUMP), "-r", str(obj)],
        capture_output=True, text=True
    )
    relocs = []
    for line in r.stdout.splitlines():
        m = re.match(r'([0-9a-f]+)\s+(\S+)\s+(\S+)', line)
        if m:
            relocs.append((int(m.group(1), 16), m.group(2), m.group(3)))

    mask = [False] * size
    comp_mut = bytearray(comp_b)
    for off, rtype, target in relocs:
        if off >= size:
            continue
        is_local = target.startswith('.text')
        if is_local and rtype in ('R_PPC_REL14', 'R_PPC_REL24'):
            tm = re.match(r'\.text\+0x([0-9a-fA-F]+)', target)
            if not tm:
                continue
            tgt_off = int(tm.group(1), 16)
            disp = tgt_off - off
            instr = (comp_mut[off]<<24)|(comp_mut[off+1]<<16)|(comp_mut[off+2]<<8)|comp_mut[off+3]
            if rtype == 'R_PPC_REL14':
                new = (instr & 0xFFFF0003) | (disp & 0xFFFC)
            else:
                new = (instr & 0xFC000003) | (disp & 0x03FFFFFC)
            comp_mut[off:off+4] = new.to_bytes(4, 'big')
        elif rtype in ('R_PPC_ADDR16_HA', 'R_PPC_ADDR16_LO'):
            if off+1 < size:
                mask[off] = mask[off+1] = True
        elif rtype == 'R_PPC_EMB_SDA21':
            for k in range(4):
                if off+k < size:
                    mask[off+k] = True
        elif rtype == 'R_PPC_REL24':
            for k in range(4):
                if off+k < size:
                    mask[off+k] = True

    ok = True
    for i in range(size):
        if mask[i]:
            continue
        if comp_mut[i] != dol_b[i]:
            ok = False
            break

    if ok:
        print(f"MATCH! Function at 0x{addr:08X} ({size} bytes)")
        return 0

    print("MISMATCH")
    for i in range(0, size, 4):
        d = dol_b[i:i+4].hex()
        c = comp_mut[i:i+4].hex()
        m_any = any(mask[i:i+4])
        mark = " [masked]" if m_any else ""
        flag = " <--" if d != c and not m_any else ""
        print(f"  0x{i:03x}: DOL={d}  COMPILED={c}{mark}{flag}")
    return 1

def _diff(a, b):
    for i in range(0, min(len(a), len(b)), 4):
        print(f"  0x{i:03x}: {a[i:i+4].hex()}  {b[i:i+4].hex()}")

if __name__ == '__main__':
    sys.exit(main())
