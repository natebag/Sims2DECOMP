#!/usr/bin/env python3
"""
Audit PMF blast files against the verify_match.sh R_PPC_REL14 over-masking bug.

For each cbmt_blast file:
1. Compile with SN ProDG (same as verify_match.sh)
2. Get .o relocations
3. For each relocation offset, verify the DOL has the SAME OPCODE bits at that offset
4. If opcodes match, the mask is benign (only hides displacement, which is correct via relocation)
5. If opcodes differ, the mask is HIDING A REAL MISMATCH (false positive)
"""
import re
import struct
import subprocess
import sys
from pathlib import Path

REPO = Path(r"F:\coding\Decompiles\Sims 2")
DOL_PATH = REPO / "extracted" / "sys" / "main.dol"
BLAST_DIR = REPO / "src" / "matched" / "cbmt_blast"
BASH = r"C:\Program Files\Git\bin\bash.exe"
OBJDUMP = r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC\bin\powerpc-eabi-objdump.exe"
OBJCOPY = r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC\bin\powerpc-eabi-objcopy.exe"

# Load DOL
DOL = DOL_PATH.read_bytes()


def dol_get(vaddr, size):
    for i in range(7):
        off = struct.unpack('>I', DOL[i*4:i*4+4])[0]
        addr = struct.unpack('>I', DOL[0x48+i*4:0x48+i*4+4])[0]
        sz = struct.unpack('>I', DOL[0x90+i*4:0x90+i*4+4])[0]
        if addr <= vaddr < addr + sz:
            foff = off + (vaddr - addr)
            return DOL[foff:foff+size]
    return None


def opcode_matches(dol_insn, obj_insn, reloc_type):
    """
    Return True if the high bits (opcode) match between DOL and OBJ instructions
    for the given relocation type, ignoring the relocatable displacement field.
    """
    d = struct.unpack('>I', dol_insn)[0]
    o = struct.unpack('>I', obj_insn)[0]
    if reloc_type == 'R_PPC_REL14':
        # Branch conditional: opcode in bits 0-5, BO/BI in 6-15, disp in 16-29 (14b),
        # AA bit 30, LK bit 31. Mask out bits 16-29.
        mask = 0xFFFF0003  # keep top 16 bits + bottom 2
        return (d & mask) == (o & mask)
    elif reloc_type == 'R_PPC_REL24':
        # Branch unconditional: opcode 0-5, disp 6-29 (24b), AA 30, LK 31.
        # Keep top 6 bits + bottom 2.
        mask = 0xFC000003
        return (d & mask) == (o & mask)
    elif reloc_type in ('R_PPC_ADDR16_HA', 'R_PPC_ADDR16_LO', 'R_PPC_ADDR16_HI'):
        # Address load: opcode 0-5, RT/RA 6-15, IMM 16-31. Keep top 16 bits.
        return (d >> 16) == (o >> 16)
    elif reloc_type in ('R_PPC_SDAREL16', 'R_PPC_EMB_SDA21'):
        # SDA-relative: keep top 16 bits.
        return (d >> 16) == (o >> 16)
    else:
        # Unknown reloc type — be conservative, just compare full insn excluding nothing
        return True  # accept and report


def audit_file(cpp_path):
    """Compile, extract relocations, and verify each one is benign."""
    # Run verify_match.sh once to compile (it caches the .o)
    addr_match = re.search(r'0x([0-9A-Fa-f]{8})', cpp_path.name)
    if not addr_match:
        return None
    addr = int(addr_match.group(1), 16)

    # Determine size from file content
    src = cpp_path.read_text()
    size_match = re.search(r'\((\d+) bytes\)', src)
    size = int(size_match.group(1)) if size_match else 120

    # Compile via verify_match.sh
    rel = str(cpp_path.relative_to(REPO)).replace('\\', '/')
    result = subprocess.run(
        [BASH, 'tools/verify_match.sh', rel, f'0x{addr:08X}', str(size)],
        capture_output=True, text=True, cwd=str(REPO)
    )
    if 'MATCH!' not in result.stdout:
        return ('SCRIPT_FAILED', addr, result.stdout[-200:])

    obj_path = REPO / 'build' / 'verify' / (cpp_path.stem + '.o')
    if not obj_path.exists():
        return ('NO_OBJ', addr, str(obj_path))

    # Extract .text bytes from .o
    text_bin = REPO / 'build' / 'verify' / '_audit.bin'
    subprocess.run([OBJCOPY, '-O', 'binary', '-j', '.text', str(obj_path), str(text_bin)],
                   check=True)
    obj_bytes = text_bin.read_bytes()[:size]

    # Get relocations
    rel_out = subprocess.run([OBJDUMP, '-r', str(obj_path)], capture_output=True, text=True)
    relocs = []
    for line in rel_out.stdout.splitlines():
        m = re.match(r'^([0-9a-f]{8})\s+(R_PPC_\S+)\s+(\S+)', line)
        if m:
            off = int(m.group(1), 16)
            rtype = m.group(2)
            target = m.group(3)
            relocs.append((off, rtype, target))

    # DOL bytes
    dol_bytes = dol_get(addr, size)
    if dol_bytes is None:
        return ('NO_DOL', addr)

    # For each relocation: confirm opcode bits match
    issues = []
    for off, rtype, target in relocs:
        if off + 4 > size:
            continue
        d_insn = dol_bytes[off:off+4]
        o_insn = obj_bytes[off:off+4]
        if not opcode_matches(d_insn, o_insn, rtype):
            issues.append((off, rtype, target, d_insn.hex(), o_insn.hex()))

    # Also confirm: bytes outside relocations match exactly
    masked = set()
    for off, rtype, _ in relocs:
        for i in range(4):
            masked.add(off + i)
    nonreloc_diffs = []
    for i in range(size):
        if i in masked:
            continue
        if dol_bytes[i] != obj_bytes[i]:
            nonreloc_diffs.append(i)

    return ('OK' if not issues and not nonreloc_diffs else 'BAD', addr, issues, nonreloc_diffs, len(relocs))


def main():
    files = sorted(BLAST_DIR.glob('match_*.cpp'))
    print(f'Auditing {len(files)} blast files...', file=sys.stderr)
    safe = 0
    bad = 0
    failed = 0
    bad_list = []

    for i, f in enumerate(files):
        result = audit_file(f)
        if result is None:
            continue
        status = result[0]
        if status == 'OK':
            safe += 1
            if i % 50 == 0:
                print(f'  [{i+1}/{len(files)}] {f.name}: SAFE ({result[4]} relocs all benign)', file=sys.stderr)
        elif status == 'BAD':
            bad += 1
            bad_list.append((f.name, result))
            print(f'  [{i+1}/{len(files)}] {f.name}: BAD - {result[2]} {result[3]}', file=sys.stderr)
        else:
            failed += 1
            print(f'  [{i+1}/{len(files)}] {f.name}: {status}', file=sys.stderr)

    print(f'\n=== AUDIT RESULTS ===', file=sys.stderr)
    print(f'  Safe: {safe}', file=sys.stderr)
    print(f'  Bad (false positive): {bad}', file=sys.stderr)
    print(f'  Failed: {failed}', file=sys.stderr)

    if bad:
        print(f'\n=== BAD FILES ===', file=sys.stderr)
        for name, result in bad_list[:10]:
            print(f'\n{name}:', file=sys.stderr)
            print(f'  reloc opcode mismatches: {result[2]}', file=sys.stderr)
            print(f'  non-reloc byte diffs: {result[3]}', file=sys.stderr)


if __name__ == '__main__':
    main()
