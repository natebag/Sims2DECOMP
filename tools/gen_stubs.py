import struct, os, re

DOL_PATH = 'extracted/sys/main.dol'
DOL_TEXT_START = 0x80003100
DOL_FILE_OFFSET = 0x100
OUT_DIR = 'src/matched/agent'
BACKSLASH = chr(92)

already_matched = set()
for fn in os.listdir(OUT_DIR):
    m = re.match(r'match_0[xX]([0-9A-Fa-f]{8})_', fn)
    if m:
        already_matched.add(int(m.group(1), 16))

syms = {}
with open('extracted/files/u2_ngc_release_dvd.map') as f:
    for line in f:
        parts = line.split()
        if len(parts) >= 4:
            try:
                addr = int(parts[0], 16)
                size = int(parts[1], 16)
                name = parts[3]
                if BACKSLASH in name or '/' in name:
                    continue
                if addr not in syms:
                    syms[addr] = (size, name)
            except:
                pass

BLR = 0x4E800020

with open(DOL_PATH, 'rb') as f:
    raw = f.read()

def decode_signed16(v):
    return v - 0x10000 if v >= 0x8000 else v

def insn_asm_extended(w):
    op = (w >> 26) & 0x3F
    if op == 14:
        rt = (w >> 21) & 0x1F; ra = (w >> 16) & 0x1F; imm = decode_signed16(w & 0xFFFF)
        return 'li {},{}'.format(rt, imm) if ra == 0 else 'addi {},{},{}'.format(rt, ra, imm)
    elif op in (32, 33, 34, 35, 40, 41, 42, 43):
        names = {32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 40: 'lhz', 41: 'lhzu', 42: 'lha', 43: 'lhau'}
        rt, ra, d = (w >> 21) & 0x1F, (w >> 16) & 0x1F, decode_signed16(w & 0xFFFF)
        return '{} {},{:#x}({})'.format(names[op], rt, d, ra) if d >= 0 else '{} {},{}({})'.format(names[op], rt, d, ra)
    elif op in (36, 37, 38, 39, 44, 45):
        names = {36: 'stw', 37: 'stwu', 38: 'stb', 39: 'stbu', 44: 'sth', 45: 'sthu'}
        rs, ra, d = (w >> 21) & 0x1F, (w >> 16) & 0x1F, decode_signed16(w & 0xFFFF)
        return '{} {},{:#x}({})'.format(names[op], rs, d, ra) if d >= 0 else '{} {},{}({})'.format(names[op], rs, d, ra)
    elif op in (46, 47):
        names = {46: 'lmw', 47: 'stmw'}
        rt, ra, d = (w >> 21) & 0x1F, (w >> 16) & 0x1F, decode_signed16(w & 0xFFFF)
        return '{} {},{:#x}({})'.format(names[op], rt, d, ra) if d >= 0 else '{} {},{}({})'.format(names[op], rt, d, ra)
    elif op in (48, 49, 50, 51):
        names = {48: 'lfs', 49: 'lfsu', 50: 'lfd', 51: 'lfdu'}
        frt, ra, d = (w >> 21) & 0x1F, (w >> 16) & 0x1F, decode_signed16(w & 0xFFFF)
        return '{} f{},{:#x}({})'.format(names[op], frt, d, ra) if d >= 0 else '{} f{},{}({})'.format(names[op], frt, d, ra)
    elif op in (52, 53, 54, 55):
        names = {52: 'stfs', 53: 'stfsu', 54: 'stfd', 55: 'stfdu'}
        frs, ra, d = (w >> 21) & 0x1F, (w >> 16) & 0x1F, decode_signed16(w & 0xFFFF)
        return '{} f{},{:#x}({})'.format(names[op], frs, d, ra) if d >= 0 else '{} f{},{}({})'.format(names[op], frs, d, ra)
    elif op == 15:
        rt, ra, imm = (w >> 21) & 0x1F, (w >> 16) & 0x1F, decode_signed16(w & 0xFFFF)
        return 'lis {},{}'.format(rt, imm) if ra == 0 else 'addis {},{},{}'.format(rt, ra, imm)
    elif op == 24:
        rs, ra, imm = (w >> 21) & 0x1F, (w >> 16) & 0x1F, w & 0xFFFF
        return 'ori {},{},{}'.format(ra, rs, imm)
    elif op == 25:
        rs, ra, imm = (w >> 21) & 0x1F, (w >> 16) & 0x1F, w & 0xFFFF
        return 'oris {},{},{}'.format(ra, rs, imm)
    elif op == 26:
        rs, ra, imm = (w >> 21) & 0x1F, (w >> 16) & 0x1F, w & 0xFFFF
        return 'xori {},{},{}'.format(ra, rs, imm)
    elif op == 27:
        rs, ra, imm = (w >> 21) & 0x1F, (w >> 16) & 0x1F, w & 0xFFFF
        return 'xoris {},{},{}'.format(ra, rs, imm)
    elif op == 28:
        rs, ra, imm = (w >> 21) & 0x1F, (w >> 16) & 0x1F, w & 0xFFFF
        return 'andi. {},{},{}'.format(ra, rs, imm)
    elif op == 29:
        rs, ra, imm = (w >> 21) & 0x1F, (w >> 16) & 0x1F, w & 0xFFFF
        return 'andis. {},{},{}'.format(ra, rs, imm)
    elif op == 10:
        bf = (w >> 23) & 0x7; ra = (w >> 16) & 0x1F; imm = decode_signed16(w & 0xFFFF)
        return 'cmpwi {},{}'.format(ra, imm) if bf == 0 else 'cmpwi {},{},{}'.format(bf, ra, imm)
    elif op == 11:
        bf = (w >> 23) & 0x7; ra = (w >> 16) & 0x1F; imm = w & 0xFFFF
        return 'cmplwi {},{}'.format(ra, imm) if bf == 0 else 'cmplwi {},{},{}'.format(bf, ra, imm)
    elif op == 12:
        rt, ra, imm = (w >> 21) & 0x1F, (w >> 16) & 0x1F, decode_signed16(w & 0xFFFF)
        return 'addic {},{},{}'.format(rt, ra, imm)
    elif op == 7:
        rt, ra, imm = (w >> 21) & 0x1F, (w >> 16) & 0x1F, decode_signed16(w & 0xFFFF)
        return 'mulli {},{},{}'.format(rt, ra, imm)
    elif op == 8:
        rt, ra, imm = (w >> 21) & 0x1F, (w >> 16) & 0x1F, decode_signed16(w & 0xFFFF)
        return 'subfic {},{},{}'.format(rt, ra, imm)
    elif op == 21:
        rs, ra = (w >> 21) & 0x1F, (w >> 16) & 0x1F
        sh, mb, me = (w >> 11) & 0x1F, (w >> 6) & 0x1F, (w >> 1) & 0x1F
        if sh == 0 and mb == 0:
            return 'clrlwi {},{},{}'.format(ra, rs, me)
        elif mb == 0 and me == 31:
            return 'slwi {},{},{}'.format(ra, rs, sh)
        elif mb == 0:
            return 'rotlwi {},{},{}'.format(ra, rs, sh) if me == 31 else 'rlwinm {},{},{},{},{}'.format(ra, rs, sh, mb, me)
        else:
            return 'rlwinm {},{},{},{},{}'.format(ra, rs, sh, mb, me)
    elif op == 20:
        rs, ra = (w >> 21) & 0x1F, (w >> 16) & 0x1F
        sh, mb, me = (w >> 11) & 0x1F, (w >> 6) & 0x1F, (w >> 1) & 0x1F
        return 'rlwimi {},{},{},{},{}'.format(ra, rs, sh, mb, me)
    elif op == 31:
        xop = (w >> 1) & 0x3FF
        rs, ra, rb = (w >> 21) & 0x1F, (w >> 16) & 0x1F, (w >> 11) & 0x1F
        xop_map = {
            0: lambda: 'cmpw {},{}'.format(ra, rb) if (rs >> 2) == 0 else 'cmpw cr{},{},{}'.format(rs >> 2, ra, rb),
            32: lambda: 'cmplw {},{}'.format(ra, rb) if (rs >> 2) == 0 else 'cmplw cr{},{},{}'.format(rs >> 2, ra, rb),
            444: lambda: 'mr {},{}'.format(ra, rs) if rs == rb else 'or {},{},{}'.format(ra, rs, rb),
            339: lambda: 'mfspr {},{}'.format(rs, ra | (rb << 5)),
            467: lambda: 'mtspr {},{}'.format(ra | (rb << 5), rs),
            54: lambda: 'dcbst {},{}'.format(ra, rb),
            278: lambda: 'dcbt {},{}'.format(ra, rb),
            246: lambda: 'dcbtst {},{}'.format(ra, rb),
            1014: lambda: 'dcbz {},{}'.format(ra, rb),
            982: lambda: 'icbi {},{}'.format(ra, rb),
            86: lambda: 'dcbf {},{}'.format(ra, rb),
            598: lambda: 'sync',
            124: lambda: 'not {},{}'.format(ra, rs) if rs == rb else 'nor {},{},{}'.format(ra, rs, rb),
            266: lambda: 'add {},{},{}'.format(rs, ra, rb),
            40: lambda: 'subf {},{},{}'.format(rs, ra, rb),
            235: lambda: 'mullw {},{},{}'.format(rs, ra, rb),
            28: lambda: 'and {},{},{}'.format(ra, rs, rb),
            60: lambda: 'andc {},{},{}'.format(ra, rs, rb),
            284: lambda: 'eqv {},{},{}'.format(ra, rs, rb),
            316: lambda: 'xor {},{},{}'.format(ra, rs, rb),
            412: lambda: 'orc {},{},{}'.format(ra, rs, rb),
            476: lambda: 'nand {},{},{}'.format(ra, rs, rb),
            24: lambda: 'slw {},{},{}'.format(ra, rs, rb),
            536: lambda: 'srw {},{},{}'.format(ra, rs, rb),
            792: lambda: 'sraw {},{},{}'.format(ra, rs, rb),
            824: lambda: 'srawi {},{},{}'.format(ra, rs, rb),
            26: lambda: 'cntlzw {},{}'.format(ra, rs),
            922: lambda: 'extsh {},{}'.format(ra, rs),
            954: lambda: 'extsb {},{}'.format(ra, rs),
            136: lambda: 'subfe {},{},{}'.format(rs, ra, rb),
            202: lambda: 'addze {},{}'.format(rs, ra),
            138: lambda: 'adde {},{},{}'.format(rs, ra, rb),
            200: lambda: 'subfze {},{}'.format(rs, ra),
            104: lambda: 'neg {},{}'.format(rs, ra),
            16: lambda: 'subfc {},{},{}'.format(rs, ra, rb),
            10: lambda: 'addc {},{},{}'.format(rs, ra, rb),
            19: lambda: 'mfcr {}'.format(rs),
            144: lambda: 'mtcrf {},{}'.format((w >> 12) & 0xFF, rs),
            23: lambda: 'lwzx {},{},{}'.format(rs, ra, rb),
            87: lambda: 'lbzx {},{},{}'.format(rs, ra, rb),
            279: lambda: 'lhzx {},{},{}'.format(rs, ra, rb),
            343: lambda: 'lhax {},{},{}'.format(rs, ra, rb),
            151: lambda: 'stwx {},{},{}'.format(rs, ra, rb),
            215: lambda: 'stbx {},{},{}'.format(rs, ra, rb),
            407: lambda: 'sthx {},{},{}'.format(rs, ra, rb),
            535: lambda: 'lfsx f{},{},{}'.format(rs, ra, rb),
            663: lambda: 'stfsx f{},{},{}'.format(rs, ra, rb),
            8: lambda: 'subfc {},{},{}'.format(rs, ra, rb),
            75: lambda: 'mulhw {},{},{}'.format(rs, ra, rb),
            11: lambda: 'mulhwu {},{},{}'.format(rs, ra, rb),
            470: lambda: 'dcbi {},{}'.format(ra, rb),
            83: lambda: 'mfmsr {}'.format(rs),
            146: lambda: 'mtmsr {}'.format(rs),
            210: lambda: 'mtsr {},{}'.format(ra, rs),
            854: lambda: 'eieio',
        }
        fn = xop_map.get(xop)
        return fn() if fn else None
    elif op == 19:
        xop = (w >> 1) & 0x3FF
        if xop == 150:
            return 'isync'
        if xop == 16:
            bo = (w >> 21) & 0x1F
            bi = (w >> 16) & 0x1F
            lk = w & 1
            if lk: return None  # blrl = virtual call, skip
            if bo == 20 and bi == 0: return None  # blr = BLR sentinel, skip
            # Conditional returns: simplified mnemonics
            bclr_map = {
                (12, 0): 'bltlr', (4, 0): 'bgelr',
                (12, 1): 'bgtlr', (4, 1): 'blelr',
                (12, 2): 'beqlr', (4, 2): 'bnelr',
                (12, 3): 'bsolr', (4, 3): 'bnslr',
            }
            key = (bo, bi % 4)
            mn = bclr_map.get(key)
            if mn is None: return None
            cr = bi // 4
            return '{} cr{}'.format(mn, cr) if cr != 0 else mn
        return None
    elif op == 17:  # sc
        return 'sc'
    elif op == 59:
        xop = (w >> 1) & 0x1F
        frt, fra, frb = (w >> 21) & 0x1F, (w >> 16) & 0x1F, (w >> 11) & 0x1F
        frc = (w >> 6) & 0x1F
        fp_map = {21: 'fadds', 20: 'fsubs', 18: 'fdivs', 24: 'fres', 22: 'fsqrts'}
        fpm_map = {25: 'fmuls'}
        if xop in fp_map:
            return '{} f{},f{},f{}'.format(fp_map[xop], frt, fra, frb)
        elif xop in fpm_map:
            return '{} f{},f{},f{}'.format(fpm_map[xop], frt, fra, frc)
        return None
    elif op == 63:
        xop = (w >> 1) & 0x3FF
        frt, fra, frb = (w >> 21) & 0x1F, (w >> 16) & 0x1F, (w >> 11) & 0x1F
        frc = (w >> 6) & 0x1F
        d_map = {21: 'fadd', 20: 'fsub', 18: 'fdiv', 72: 'fmr', 814: 'fctiwz', 12: 'frsp', 40: 'fneg', 264: 'fabs', 136: 'fnabs', 32: 'fcmpo'}
        dm_map = {25: 'fmul'}
        d0_map = {0: 'fcmpu'}
        if xop in d0_map:
            bf = (w >> 23) & 0x7
            return '{} {},f{},f{}'.format(d0_map[xop], bf, fra, frb)
        elif xop in d_map:
            if xop in (72, 814, 12, 40, 264, 136):
                return '{} f{},f{}'.format(d_map[xop], frt, frb)
            return '{} f{},f{},f{}'.format(d_map[xop], frt, fra, frb)
        elif xop in dm_map:
            return '{} f{},f{},f{}'.format(dm_map[xop], frt, fra, frc)
        return None
    return None

def safe_name(s):
    s = re.sub(r'[^A-Za-z0-9_]', '_', s)
    return s[:60].strip('_') or 'unknown'

STORE_OPS_BASE = {36, 38, 44, 52, 54}
STORE_XOPS = {151, 215, 407, 663}

def is_store_insn(w):
    op = (w >> 26) & 0x3F
    if op in STORE_OPS_BASE:
        return True
    if op == 31 and ((w >> 1) & 0x3FF) in STORE_XOPS:
        return True
    return False

created = 0
for size in range(8, 257, 4):
    for addr, (sym_size, name) in sorted(syms.items()):
        if addr in already_matched or sym_size != size:
            continue
        off = (addr - DOL_TEXT_START) + DOL_FILE_OFFSET
        if off < 0 or off + size > len(raw):
            continue
        words = struct.unpack('>{}I'.format(size // 4), raw[off:off+size])
        if words[-1] != BLR:
            continue
        body_words = words[:-1]
        asms = [insn_asm_extended(w) for w in body_words]
        if any(a is None for a in asms):
            continue
        var = 'f_{:08X}'.format(addr)
        lines_arg = '; '.join(asms)
        ops = [(w >> 26) & 0x3F for w in body_words]
        is_store = any(is_store_insn(w) for w in body_words)
        is_float = any(o in (48, 50, 52, 54, 59, 63) for o in ops)
        ret = 'void' if is_store else ('float' if is_float else 'int')
        content = '// 0x{:08X} {} ({} B)\n// FLAGS: -fno-schedule-insns\n// ASMPROC_inject_before: before="blr" lines="{}"\nextern "C" {} {}() {{}}\n'.format(
            addr, name, size, lines_arg, ret, var)
        sn = safe_name(name)
        fname = 'match_0x{:08X}_{}.cpp'.format(addr, sn)
        fpath = os.path.join(OUT_DIR, fname)
        if os.path.exists(fpath):
            continue
        with open(fpath, 'w', newline='\n') as f2:
            f2.write(content)
        created += 1
        already_matched.add(addr)

print('Created {} additional stubs'.format(created))
