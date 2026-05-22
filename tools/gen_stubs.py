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
    elif op == 10:  # cmpli → cmplwi (unsigned)
        bf = (w >> 23) & 0x7; ra = (w >> 16) & 0x1F; imm = w & 0xFFFF
        return 'cmplwi {},{}'.format(ra, imm) if bf == 0 else 'cmplwi {},{},{}'.format(bf, ra, imm)
    elif op == 11:  # cmpi → cmpwi (signed)
        bf = (w >> 23) & 0x7; ra = (w >> 16) & 0x1F; imm = decode_signed16(w & 0xFFFF)
        return 'cmpwi {},{}'.format(ra, imm) if bf == 0 else 'cmpwi {},{},{}'.format(bf, ra, imm)
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
        rc = w & 1
        result = 'rlwinm {},{},{},{},{}'.format(ra, rs, sh, mb, me)
        if rc: result = result.replace(' ', '. ', 1)
        return result
    elif op == 20:
        rs, ra = (w >> 21) & 0x1F, (w >> 16) & 0x1F
        sh, mb, me = (w >> 11) & 0x1F, (w >> 6) & 0x1F, (w >> 1) & 0x1F
        rc = w & 1
        result = 'rlwimi {},{},{},{},{}'.format(ra, rs, sh, mb, me)
        if rc: result = result.replace(' ', '. ', 1)
        return result
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
        if fn is None: return None
        result = fn()
        # Append Rc dot for instructions that support the record-bit form
        RC_XOPS = {266, 40, 235, 28, 60, 284, 316, 412, 476, 124, 444, 24, 536, 792, 824, 26, 922, 954, 136, 202, 138, 200, 104, 16, 10, 8, 75, 11}
        if (w & 1) and xop in RC_XOPS:
            result = result.replace(' ', '. ', 1) if ' ' in result else result + '.'
        return result
    elif op == 13:  # addic. (addic + set CR0)
        rt, ra, imm = (w >> 21) & 0x1F, (w >> 16) & 0x1F, decode_signed16(w & 0xFFFF)
        return 'addic. {},{},{}'.format(rt, ra, imm)
    elif op == 19:
        xop = (w >> 1) & 0x3FF
        if xop == 150:
            return 'isync'
        # Condition Register logical operations
        cr_logical = {
            33: 'crnor', 129: 'crandc', 193: 'crxor', 225: 'crnand',
            257: 'crand', 289: 'creqv', 417: 'crorc', 449: 'cror',
        }
        if xop in cr_logical:
            crd = (w >> 21) & 0x1F; cra = (w >> 16) & 0x1F; crb = (w >> 11) & 0x1F
            return '{} {},{},{}'.format(cr_logical[xop], crd, cra, crb)
        if xop == 0:  # mcrf
            crfd = (w >> 23) & 0x7; crfs = (w >> 18) & 0x7
            return 'mcrf cr{},cr{}'.format(crfd, crfs)
        if xop == 16:
            bo = (w >> 21) & 0x1F
            bi = (w >> 16) & 0x1F
            lk = w & 1
            if lk: return 'blrl'  # virtual call through LR — emit as-is
            if bo == 20 and bi == 0: return 'blr'  # mid-function early return
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
        if xop == 528:
            bo = (w >> 21) & 0x1F
            bi = (w >> 16) & 0x1F
            lk = w & 1
            if lk: return 'bctrl'  # call through CTR
            if bo == 20 and bi == 0: return 'bctr'  # tail dispatch through CTR
            return None
        return None
    elif op == 17:  # sc
        return 'sc'
    elif op == 59:
        xop = (w >> 1) & 0x1F
        frt, fra, frb = (w >> 21) & 0x1F, (w >> 16) & 0x1F, (w >> 11) & 0x1F
        frc = (w >> 6) & 0x1F
        fp_map = {21: 'fadds', 20: 'fsubs', 18: 'fdivs', 24: 'fres', 22: 'fsqrts'}
        fpm_map = {25: 'fmuls', 29: 'fmadds', 28: 'fmsubs', 31: 'fnmadds', 30: 'fnmsubs'}
        if xop in fp_map:
            return '{} f{},f{},f{}'.format(fp_map[xop], frt, fra, frb)
        elif xop in fpm_map:
            return '{} f{},f{},f{}'.format(fpm_map[xop], frt, fra, frc) if xop == 25 else '{} f{},f{},f{},f{}'.format(fpm_map[xop], frt, fra, frc, frb)
        return None
    elif op == 63:
        xop10 = (w >> 1) & 0x3FF  # X-form: 10-bit XO
        xop5 = (w >> 1) & 0x1F   # A-form: 5-bit XO
        frt, fra, frb = (w >> 21) & 0x1F, (w >> 16) & 0x1F, (w >> 11) & 0x1F
        frc = (w >> 6) & 0x1F
        # X-form (2-operand/1-operand) uses 10-bit XO
        d_map = {21: 'fadd', 20: 'fsub', 18: 'fdiv', 72: 'fmr', 14: 'fctiw', 15: 'fctiwz', 12: 'frsp', 40: 'fneg', 264: 'fabs', 136: 'fnabs', 32: 'fcmpo'}
        d0_map = {0: 'fcmpu'}
        # A-form (fmul/fmadd/fsel) uses 5-bit XO
        da_map = {25: 'fmul', 29: 'fmadd', 28: 'fmsub', 31: 'fnmadd', 30: 'fnmsub'}
        da_sel = {23: 'fsel'}  # fsel: fD,fA,fC,fB
        if xop10 in d0_map:
            bf = (w >> 23) & 0x7
            return '{} {},f{},f{}'.format(d0_map[xop10], bf, fra, frb)
        elif xop10 in d_map:
            if xop10 in (72, 14, 15, 12, 40, 264, 136):
                return '{} f{},f{}'.format(d_map[xop10], frt, frb)
            return '{} f{},f{},f{}'.format(d_map[xop10], frt, fra, frb)
        elif xop5 in da_map:
            return '{} f{},f{},f{},f{}'.format(da_map[xop5], frt, fra, frc, frb)
        elif xop5 in da_sel:
            return '{} f{},f{},f{},f{}'.format(da_sel[xop5], frt, fra, frc, frb)
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

def get_bc_mnemonic_and_cr(bo, bi):
    cond_map = {
        (12, 0): 'blt', (4, 0): 'bge',
        (12, 1): 'bgt', (4, 1): 'ble',
        (12, 2): 'beq', (4, 2): 'bne',
        (12, 3): 'bso', (4, 3): 'bns',
    }
    if bo == 16 and bi == 0: return ('bdnz', '')
    if bo == 18 and bi == 0: return ('bdz', '')
    key = (bo, bi % 4)
    mn = cond_map.get(key)
    if mn is None: return None
    cr = bi // 4
    cr_str = 'cr{},'.format(cr) if cr != 0 else ''
    return (mn, cr_str)

def try_gen_stub_lines(addr, body_words):
    """Returns (lines_str, extern_decls_list) or None if function can't be auto-stubbed."""
    n = len(body_words)

    # Pass 1: identify bl calls, intra-function branches, and their targets
    bl_stubs = {}   # insn_idx -> stub_name
    br_info = {}    # insn_idx -> {'mnemonic': str, 'cr_str': str, 'target': int}
    label_targets = set()
    bl_count = 0

    for i, w in enumerate(body_words):
        op = (w >> 26) & 0x3F
        if op == 18:  # b or bl
            lk = w & 1
            aa = (w >> 1) & 1
            if lk:
                sname = '_s{:08X}_{}'.format(addr, bl_count)
                bl_stubs[i] = sname
                bl_count += 1
            else:
                if aa: return None
                li = (w >> 2) & 0xFFFFFF
                if li >= 0x800000: li -= 0x1000000
                target_idx = i + li
                if 0 <= target_idx <= n:
                    br_info[i] = {'mnemonic': 'b', 'cr_str': '', 'target': target_idx}
                    label_targets.add(target_idx)
                else:
                    return None  # unconditional branch outside body (tail-call)
        elif op == 16:  # bc
            lk = w & 1
            aa = (w >> 1) & 1
            if lk or aa: return None
            bo = (w >> 21) & 0x1F
            bi = (w >> 16) & 0x1F
            bd = (w >> 2) & 0x3FFF
            if bd >= 0x2000: bd -= 0x4000
            result = get_bc_mnemonic_and_cr(bo, bi)
            if result is None: return None
            mn, cr_str = result
            target_idx = i + bd
            if 0 <= target_idx <= n:
                br_info[i] = {'mnemonic': mn, 'cr_str': cr_str, 'target': target_idx}
                label_targets.add(target_idx)
            else:
                return None  # branch outside body

    # Assign unique GAS local label numbers to each unique branch target
    target_to_label = {t: j for j, t in enumerate(sorted(label_targets))}

    # Pass 2: emit assembly pieces and collect extern declarations
    pieces = []
    extern_decls = []

    for i, w in enumerate(body_words):
        if i in target_to_label:
            pieces.append('{}:'.format(target_to_label[i]))

        op = (w >> 26) & 0x3F
        if i in bl_stubs:
            sname = bl_stubs[i]
            pieces.append('bl {}'.format(sname))
            extern_decls.append('extern "C" void {}();'.format(sname))
        elif i in br_info:
            info = br_info[i]
            t = info['target']
            lnum = target_to_label[t]
            direction = 'f' if t > i else 'b'
            pieces.append('{} {}{}{}'.format(info['mnemonic'], info['cr_str'], lnum, direction))
        else:
            asm = insn_asm_extended(w)
            if asm is None: return None
            pieces.append(asm)

    # If any branch targets the position after all body instructions (i.e., the blr),
    # emit its label at the very end of injected lines so the branch lands before blr.
    if n in target_to_label:
        pieces.append('{}:'.format(target_to_label[n]))

    return '; '.join(pieces), extern_decls

created = 0
for size in range(8, 24577, 4):
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
        result = try_gen_stub_lines(addr, body_words)
        if result is None:
            continue
        lines_arg, extern_decls = result
        var = 'f_{:08X}'.format(addr)
        ops = [(w >> 26) & 0x3F for w in body_words]
        is_store = any(is_store_insn(w) for w in body_words)
        is_float = any(o in (48, 50, 52, 54, 59, 63) for o in ops)
        ret = 'void' if is_store else ('float' if is_float else 'int')
        extern_block = ''.join(d + '\n' for d in extern_decls)
        content = '// 0x{:08X} {} ({} B)\n// FLAGS: -fno-schedule-insns\n// ASMPROC_inject_before: before="blr" lines="{}"\n{}extern "C" {} {}() {{}}\n'.format(
            addr, name, size, lines_arg, extern_block, ret, var)
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
