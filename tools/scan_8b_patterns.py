#!/usr/bin/env python3
"""
Scan DOL for 8B matchable functions (getters, setters, return-const).
Generates match files for patterns that can be auto-solved.
"""
import sys, re, struct, os
from pathlib import Path

sys.stdout.reconfigure(encoding='utf-8')

DOL_PATH = Path("extracted/sys/main.dol")
MAP_PATH = Path("extracted/files/u2_ngc_release.map")
MATCHED_DIR = Path("src/matched")
OUT_DIR = Path("src/matched/agent")
GAME_LO = 0x80004000
GAME_HI = 0x80240000
BLR = 0x4E800020

def load_dol(path):
    with open(path, 'rb') as f:
        return f.read()

def dol_vaddr_to_offset(data, vaddr):
    for i in range(7):
        off = struct.unpack_from('>I', data, i*4)[0]
        addr = struct.unpack_from('>I', data, 0x48 + i*4)[0]
        size = struct.unpack_from('>I', data, 0x90 + i*4)[0]
        if off > 0 and addr <= vaddr < addr + size:
            return off + (vaddr - addr)
    return None

def read_word(data, vaddr):
    off = dol_vaddr_to_offset(data, vaddr)
    if off is None or off + 4 > len(data):
        return None
    return struct.unpack_from('>I', data, off)[0]

def parse_map(path):
    """Return list of (addr, map_size, name) for all .text function symbols."""
    syms = []
    pat = re.compile(r'^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+0\s+(.+)$')
    with open(path, 'r', errors='replace') as f:
        for line in f:
            m = pat.match(line)
            if m:
                addr = int(m.group(1), 16)
                size = int(m.group(2), 16)
                name = m.group(3).strip()
                if GAME_LO <= addr < GAME_HI:
                    syms.append((addr, size, name))
    return syms

def get_matched_addrs():
    """Collect already-matched addresses from src/matched/."""
    matched = set()
    pat = re.compile(r'match_(0[xX])?([0-9A-Fa-f]{8})_')
    for p in MATCHED_DIR.rglob('match_*.cpp'):
        m = pat.search(p.name)
        if m:
            matched.add(int(m.group(2), 16))
    return matched

def decode_pattern(w0, w1):
    """Return (pattern_tag, info_dict) or None if not recognized."""
    if w1 != BLR:
        return None

    # li r3, N  (addi r3, r0, N)  opcode=14, rD=3, rA=0
    # 0x38600000 | (N & 0xFFFF)
    if (w0 & 0xFFFF0000) == 0x38600000:
        n = w0 & 0xFFFF
        if n >= 0x8000: n -= 0x10000  # sign extend
        return ('li_r3', {'imm': n})

    # lwz r3, N(r3)  opcode=32, rD=3, rA=3
    # 0x80630000 | (N & 0xFFFF)
    if (w0 & 0xFFFF0000) == 0x80630000:
        n = w0 & 0xFFFF
        if n >= 0x8000: n -= 0x10000
        return ('lwz_r3_r3', {'off': n})

    # lwz r3, N(r1)  opcode=32, rD=3, rA=1 — stack load (less common but occurs)
    if (w0 & 0xFFFF0000) == 0x80610000:
        n = w0 & 0xFFFF
        if n >= 0x8000: n -= 0x10000
        return ('lwz_r3_r1', {'off': n})

    # lbz r3, N(r3)  opcode=34, rD=3, rA=3
    # 0x88630000 | (N & 0xFFFF)
    if (w0 & 0xFFFF0000) == 0x88630000:
        n = w0 & 0xFFFF
        if n >= 0x8000: n -= 0x10000
        return ('lbz_r3_r3', {'off': n})

    # lhz r3, N(r3)  opcode=40, rD=3, rA=3
    # 0xA0630000 | (N & 0xFFFF)
    if (w0 & 0xFFFF0000) == 0xA0630000:
        n = w0 & 0xFFFF
        if n >= 0x8000: n -= 0x10000
        return ('lhz_r3_r3', {'off': n})

    # lha r3, N(r3)  opcode=42, rD=3, rA=3
    # 0xA8630000 | (N & 0xFFFF)
    if (w0 & 0xFFFF0000) == 0xA8630000:
        n = w0 & 0xFFFF
        if n >= 0x8000: n -= 0x10000
        return ('lha_r3_r3', {'off': n})

    # lfs f1, N(r3)  opcode=48, frD=1, rA=3
    # 0xC0230000 | (N & 0xFFFF)
    if (w0 & 0xFFFF0000) == 0xC0230000:
        n = w0 & 0xFFFF
        if n >= 0x8000: n -= 0x10000
        return ('lfs_f1_r3', {'off': n})

    # lfd f1, N(r3)  opcode=50, frD=1, rA=3
    # 0xC8230000 | (N & 0xFFFF)
    if (w0 & 0xFFFF0000) == 0xC8230000:
        n = w0 & 0xFFFF
        if n >= 0x8000: n -= 0x10000
        return ('lfd_f1_r3', {'off': n})

    # mr r3, r4  (or r3, r4, r4)  opcode=31, X=444
    # 0x7C832378  (or r3,r4,r4)
    if w0 == 0x7C832378:
        return ('mr_r3_r4', {})

    # mr r3, r3  (nop essentially — or r3,r3,r3)  0x7C631B78
    if w0 == 0x7C631B78:
        return ('mr_r3_r3', {})

    # stw r4, N(r3)  opcode=36, rS=4, rA=3
    # 0x90830000 | (N & 0xFFFF)
    if (w0 & 0xFFFF0000) == 0x90830000:
        n = w0 & 0xFFFF
        if n >= 0x8000: n -= 0x10000
        return ('stw_r4_r3', {'off': n})

    # stb r4, N(r3)  opcode=38, rS=4, rA=3
    # 0x98830000 | (N & 0xFFFF)
    if (w0 & 0xFFFF0000) == 0x98830000:
        n = w0 & 0xFFFF
        if n >= 0x8000: n -= 0x10000
        return ('stb_r4_r3', {'off': n})

    # sth r4, N(r3)  opcode=44, rS=4, rA=3
    # 0xB0830000 | (N & 0xFFFF)
    if (w0 & 0xFFFF0000) == 0xB0830000:
        n = w0 & 0xFFFF
        if n >= 0x8000: n -= 0x10000
        return ('sth_r4_r3', {'off': n})

    # stfs f1, N(r3) opcode=52, frS=1, rA=3
    # 0xD0230000 | (N & 0xFFFF)
    if (w0 & 0xFFFF0000) == 0xD0230000:
        n = w0 & 0xFFFF
        if n >= 0x8000: n -= 0x10000
        return ('stfs_f1_r3', {'off': n})

    # li r3, 0 with ori (sometimes: li r3,0 ; ori r3,r3,N — but that's not 8B ending in blr)

    return None

def make_padding_members(off, base_type='int'):
    """Generate struct members to pad to offset `off` before a given type."""
    if off == 0:
        return ''
    parts = []
    remaining = off
    # Use ints (4B) then shorts (2B) then chars (1B)
    while remaining >= 4:
        parts.append('int _p' + str(len(parts)) + ';')
        remaining -= 4
    while remaining >= 2:
        parts.append('short _ps' + str(len(parts)) + ';')
        remaining -= 2
    while remaining >= 1:
        parts.append('char _pc' + str(len(parts)) + ';')
        remaining -= 1
    return ' '.join(parts) + ' '

def align_up(n, align):
    return (n + align - 1) & ~(align - 1)

def effective_offset(off, member_align):
    """What offset will GCC actually place a member with given alignment at, after `off` bytes of padding?"""
    return align_up(off, member_align)

def gen_match_file(addr, name, pat_tag, info):
    """Generate C++ match file content for a recognized 8B pattern."""
    # Sanitize function name for use in output
    short_name = name.replace('(', '_').replace(')', '').replace(' ', '_')[:80]

    if pat_tag == 'li_r3':
        n = info['imm']
        return (
            f"// 0x{addr:08X} {name} (8B)\n"
            f"int _f(void) {{ return {n}; }}\n"
        )

    if pat_tag == 'mr_r3_r4':
        return (
            f"// 0x{addr:08X} {name} (8B)\n"
            f"int _f(int x) {{ return x; }}\n"
        )

    if pat_tag == 'mr_r3_r3':
        # mr r3,r3 followed by blr — identity function on r3; already in r3 so it's a no-op really
        # But what would generate this? Probably a function that takes a param and returns it unchanged.
        # Actually mr r3,r3 is a nop (or r3,r3,r3) — compiler might emit for register move that is same register.
        # This might come from returning 'this' in a method: struct T { T* f(void); }; T* T::f(void) { return this; }
        return (
            f"// 0x{addr:08X} {name} (8B)\n"
            f"struct _T {{ _T* _f(void); }};\n"
            f"_T* _T::_f(void) {{ return this; }}\n"
        )

    # Member getters — need struct with correct padding
    off_getters = {
        'lwz_r3_r3': ('int', 4, 'int'),
        'lbz_r3_r3': ('unsigned char', 1, 'unsigned int'),
        'lhz_r3_r3': ('unsigned short', 2, 'unsigned int'),
        'lha_r3_r3': ('short', 2, 'int'),
        'lfs_f1_r3': ('float', 4, 'float'),
        'lfd_f1_r3': ('double', 8, 'double'),
    }
    if pat_tag in off_getters:
        member_type, member_align, ret_type = off_getters[pat_tag]
        off = info['off']
        if off < 0:
            return None  # negative offsets are unusual, skip
        # Verify GCC will place the member at exactly `off`
        padded_off = effective_offset(off, member_align) if off > 0 else 0
        if padded_off != off:
            # Padding would misalign — need to use char padding approach more carefully
            # Try: fill with chars until alignment works
            # Actually if off % member_align != 0, the access in original code used a different type
            # or used __attribute__((packed)). Skip for now.
            return None
        # Build struct
        if off == 0:
            pad_str = ''
        else:
            pad_str = make_padding_members(off)
        return (
            f"// 0x{addr:08X} {name} (8B)\n"
            f"struct _T {{ {pad_str}{member_type} _m; {ret_type} _f(void); }};\n"
            f"{ret_type} _T::_f(void) {{ return _m; }}\n"
        )

    # Member setters (void return)
    off_setters = {
        'stw_r4_r3': ('int', 4, 'int'),
        'stb_r4_r3': ('char', 1, 'int'),
        'sth_r4_r3': ('short', 2, 'int'),
        'stfs_f1_r3': ('float', 4, 'float'),
    }
    if pat_tag in off_setters:
        member_type, member_align, param_type = off_setters[pat_tag]
        off = info['off']
        if off < 0:
            return None
        padded_off = effective_offset(off, member_align) if off > 0 else 0
        if padded_off != off:
            return None
        pad_str = make_padding_members(off) if off > 0 else ''
        return (
            f"// 0x{addr:08X} {name} (8B)\n"
            f"struct _T {{ {pad_str}{member_type} _m; void _f({param_type} v); }};\n"
            f"void _T::_f({param_type} v) {{ _m = v; }}\n"
        )

    return None

def main():
    print("Loading DOL...")
    dol = load_dol(DOL_PATH)

    print("Parsing map...")
    syms = parse_map(MAP_PATH)
    print(f"  {len(syms)} game-code symbols")

    print("Scanning matched files...")
    matched = get_matched_addrs()
    print(f"  {len(matched)} already matched")

    unmatched = [(a, s, n) for a, s, n in syms if a not in matched]
    print(f"  {len(unmatched)} unmatched")

    # Scan for 8B patterns
    candidates = []
    counts = {}
    for addr, map_size, name in unmatched:
        w0 = read_word(dol, addr)
        w1 = read_word(dol, addr + 4)
        if w0 is None or w1 is None:
            continue
        result = decode_pattern(w0, w1)
        if result is None:
            continue
        pat_tag, info = result
        counts[pat_tag] = counts.get(pat_tag, 0) + 1
        candidates.append((addr, name, pat_tag, info))

    print(f"\n8B pattern summary ({len(candidates)} total):")
    for tag, cnt in sorted(counts.items(), key=lambda x: -x[1]):
        print(f"  {tag}: {cnt}")

    # Generate files
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    generated = []
    skipped = []

    for addr, name, pat_tag, info in candidates:
        # Skip if file already exists (shouldn't happen but be safe)
        fname = f"match_0x{addr:08X}_{name.split('(')[0].replace('::', '__').replace(' ', '_').replace('<', '_').replace('>', '_').replace(',', '_').replace('*', 'p').replace('&', 'r').replace('{', '').replace('}', '').replace('~', 'dtor_').strip('_')[:60]}.cpp"
        out_path = OUT_DIR / fname

        if out_path.exists():
            skipped.append((addr, name, 'file_exists'))
            continue

        content = gen_match_file(addr, name, pat_tag, info)
        if content is None:
            skipped.append((addr, name, f'no_gen/{pat_tag}'))
            continue

        out_path.write_text(content, encoding='utf-8')
        generated.append((addr, name, pat_tag, out_path))

    print(f"\nGenerated: {len(generated)} files")
    print(f"Skipped: {len(skipped)}")

    # Write a batch test script
    if generated:
        lines = ['#!/bin/bash', 'PASS=0; FAIL=0']
        for addr, name, pat_tag, out_path in generated:
            lines.append(
                f'result=$(bash tools/verify_match.sh "{out_path}" 0x{addr:08X} 8 2>&1 | tail -1); '
                f'if echo "$result" | grep -q "MATCH"; then PASS=$((PASS+1)); '
                f'else FAIL=$((FAIL+1)); echo "FAIL 0x{addr:08X} {name[:60]}: $result"; fi'
            )
        lines.append('echo "Done: $PASS PASS, $FAIL FAIL"')
        Path('src/wip/_batch_test_8b.sh').write_text('\n'.join(lines) + '\n', encoding='utf-8')
        print(f"Wrote src/wip/_batch_test_8b.sh")

    # Print first 20 generated
    for addr, name, pat_tag, out_path in generated[:20]:
        print(f"  0x{addr:08X} [{pat_tag}] {name[:70]}")

if __name__ == '__main__':
    main()
