"""Quick script to find what blocks remaining BLR-ending functions."""
import struct, re, glob

dol = open('extracted/sys/main.dol','rb').read()
BLR = 0x4E800020
DOL_TEXT_START = 0x80003100
DOL_FILE_OFFSET = 0x100

matched = set()
for fn in glob.glob('src/matched/**/*.cpp', recursive=True):
    m = re.search(r'match_(0[xX])?([0-9A-Fa-f]{8})_', fn)
    if m: matched.add(int(m.group(2), 16))

def decode_signed16(v): return v - 0x10000 if v >= 0x8000 else v

def get_bc_mnemonic_and_cr(bo, bi):
    cond_map = {(12,0):'blt',(4,0):'bge',(12,1):'bgt',(4,1):'ble',(12,2):'beq',(4,2):'bne',(12,3):'bso',(4,3):'bns'}
    if bo==16 and bi==0: return ('bdnz','')
    if bo==18 and bi==0: return ('bdz','')
    key=(bo,bi%4); mn=cond_map.get(key)
    if mn is None: return None
    cr=bi//4; cr_str='cr{},'.format(cr) if cr!=0 else ''
    return (mn, cr_str)

def insn_asm_extended(w):
    op=(w>>26)&0x3F
    if op==14:
        rt=(w>>21)&31;ra=(w>>16)&31;imm=decode_signed16(w&0xFFFF)
        return 'li {},{}'.format(rt,imm) if ra==0 else 'addi {},{},{}'.format(rt,ra,imm)
    elif op in(32,33,34,35,40,41,42,43):
        names={32:'lwz',33:'lwzu',34:'lbz',35:'lbzu',40:'lhz',41:'lhzu',42:'lha',43:'lhau'}
        rt,ra,d=(w>>21)&31,(w>>16)&31,decode_signed16(w&0xFFFF)
        return '{} {},{:#x}({})'.format(names[op],rt,d,ra) if d>=0 else '{} {},{}({})'.format(names[op],rt,d,ra)
    elif op in(36,37,38,39,44,45):
        names={36:'stw',37:'stwu',38:'stb',39:'stbu',44:'sth',45:'sthu'}
        rs,ra,d=(w>>21)&31,(w>>16)&31,decode_signed16(w&0xFFFF)
        return '{} {},{:#x}({})'.format(names[op],rs,d,ra) if d>=0 else '{} {},{}({})'.format(names[op],rs,d,ra)
    elif op in(46,47):
        names={46:'lmw',47:'stmw'}; rt,ra,d=(w>>21)&31,(w>>16)&31,decode_signed16(w&0xFFFF)
        return '{} {},{:#x}({})'.format(names[op],rt,d,ra) if d>=0 else '{} {},{}({})'.format(names[op],rt,d,ra)
    elif op in(48,49,50,51):
        names={48:'lfs',49:'lfsu',50:'lfd',51:'lfdu'}; frt,ra,d=(w>>21)&31,(w>>16)&31,decode_signed16(w&0xFFFF)
        return '{} f{},{:#x}({})'.format(names[op],frt,d,ra) if d>=0 else '{} f{},{}({})'.format(names[op],frt,d,ra)
    elif op in(52,53,54,55):
        names={52:'stfs',53:'stfsu',54:'stfd',55:'stfdu'}; frs,ra,d=(w>>21)&31,(w>>16)&31,decode_signed16(w&0xFFFF)
        return '{} f{},{:#x}({})'.format(names[op],frs,d,ra) if d>=0 else '{} f{},{}({})'.format(names[op],frs,d,ra)
    elif op==15:
        rt,ra,imm=(w>>21)&31,(w>>16)&31,decode_signed16(w&0xFFFF)
        return 'lis {},{}'.format(rt,imm) if ra==0 else 'addis {},{},{}'.format(rt,ra,imm)
    elif op==24: rs,ra,imm=(w>>21)&31,(w>>16)&31,w&0xFFFF; return 'ori {},{},{}'.format(ra,rs,imm)
    elif op==25: rs,ra,imm=(w>>21)&31,(w>>16)&31,w&0xFFFF; return 'oris {},{},{}'.format(ra,rs,imm)
    elif op==26: rs,ra,imm=(w>>21)&31,(w>>16)&31,w&0xFFFF; return 'xori {},{},{}'.format(ra,rs,imm)
    elif op==27: rs,ra,imm=(w>>21)&31,(w>>16)&31,w&0xFFFF; return 'xoris {},{},{}'.format(ra,rs,imm)
    elif op==28: rs,ra,imm=(w>>21)&31,(w>>16)&31,w&0xFFFF; return 'andi. {},{},{}'.format(ra,rs,imm)
    elif op==29: rs,ra,imm=(w>>21)&31,(w>>16)&31,w&0xFFFF; return 'andis. {},{},{}'.format(ra,rs,imm)
    elif op==10: bf=(w>>23)&7;ra=(w>>16)&31;imm=w&0xFFFF; return 'cmplwi {},{}'.format(ra,imm) if bf==0 else 'cmplwi {},{},{}'.format(bf,ra,imm)
    elif op==11: bf=(w>>23)&7;ra=(w>>16)&31;imm=decode_signed16(w&0xFFFF); return 'cmpwi {},{}'.format(ra,imm) if bf==0 else 'cmpwi {},{},{}'.format(bf,ra,imm)
    elif op==12: rt,ra,imm=(w>>21)&31,(w>>16)&31,decode_signed16(w&0xFFFF); return 'addic {},{},{}'.format(rt,ra,imm)
    elif op==13: rt,ra,imm=(w>>21)&31,(w>>16)&31,decode_signed16(w&0xFFFF); return 'addic. {},{},{}'.format(rt,ra,imm)
    elif op==7: rt,ra,imm=(w>>21)&31,(w>>16)&31,decode_signed16(w&0xFFFF); return 'mulli {},{},{}'.format(rt,ra,imm)
    elif op==8: rt,ra,imm=(w>>21)&31,(w>>16)&31,decode_signed16(w&0xFFFF); return 'subfic {},{},{}'.format(rt,ra,imm)
    elif op==21:
        rs,ra=(w>>21)&31,(w>>16)&31; sh,mb,me=(w>>11)&31,(w>>6)&31,(w>>1)&31; rc=w&1
        result='rlwinm {},{},{},{},{}'.format(ra,rs,sh,mb,me)
        if rc: result=result.replace(' ','. ',1)
        return result
    elif op==20:
        rs,ra=(w>>21)&31,(w>>16)&31; sh,mb,me=(w>>11)&31,(w>>6)&31,(w>>1)&31; rc=w&1
        result='rlwimi {},{},{},{},{}'.format(ra,rs,sh,mb,me)
        if rc: result=result.replace(' ','. ',1)
        return result
    elif op==31:
        xop=(w>>1)&0x3FF; rs,ra,rb=(w>>21)&31,(w>>16)&31,(w>>11)&31
        xop_map={0:lambda:'cmpw {},{}'.format(ra,rb) if (rs>>2)==0 else 'cmpw cr{},{},{}'.format(rs>>2,ra,rb),
                 32:lambda:'cmplw {},{}'.format(ra,rb) if (rs>>2)==0 else 'cmplw cr{},{},{}'.format(rs>>2,ra,rb),
                 444:lambda:'mr {},{}'.format(ra,rs) if rs==rb else 'or {},{},{}'.format(ra,rs,rb),
                 339:lambda:'mfspr {},{}'.format(rs,ra|(rb<<5)),467:lambda:'mtspr {},{}'.format(ra|(rb<<5),rs),
                 54:lambda:'dcbst {},{}'.format(ra,rb),278:lambda:'dcbt {},{}'.format(ra,rb),
                 246:lambda:'dcbtst {},{}'.format(ra,rb),1014:lambda:'dcbz {},{}'.format(ra,rb),
                 982:lambda:'icbi {},{}'.format(ra,rb),86:lambda:'dcbf {},{}'.format(ra,rb),
                 598:lambda:'sync',124:lambda:'not {},{}'.format(ra,rs) if rs==rb else 'nor {},{},{}'.format(ra,rs,rb),
                 266:lambda:'add {},{},{}'.format(rs,ra,rb),40:lambda:'subf {},{},{}'.format(rs,ra,rb),
                 235:lambda:'mullw {},{},{}'.format(rs,ra,rb),28:lambda:'and {},{},{}'.format(ra,rs,rb),
                 60:lambda:'andc {},{},{}'.format(ra,rs,rb),284:lambda:'eqv {},{},{}'.format(ra,rs,rb),
                 316:lambda:'xor {},{},{}'.format(ra,rs,rb),412:lambda:'orc {},{},{}'.format(ra,rs,rb),
                 476:lambda:'nand {},{},{}'.format(ra,rs,rb),24:lambda:'slw {},{},{}'.format(ra,rs,rb),
                 536:lambda:'srw {},{},{}'.format(ra,rs,rb),792:lambda:'sraw {},{},{}'.format(ra,rs,rb),
                 824:lambda:'srawi {},{},{}'.format(ra,rs,rb),26:lambda:'cntlzw {},{}'.format(ra,rs),
                 922:lambda:'extsh {},{}'.format(ra,rs),954:lambda:'extsb {},{}'.format(ra,rs),
                 136:lambda:'subfe {},{},{}'.format(rs,ra,rb),202:lambda:'addze {},{}'.format(rs,ra),
                 138:lambda:'adde {},{},{}'.format(rs,ra,rb),200:lambda:'subfze {},{}'.format(rs,ra),
                 104:lambda:'neg {},{}'.format(rs,ra),16:lambda:'subfc {},{},{}'.format(rs,ra,rb),
                 10:lambda:'addc {},{},{}'.format(rs,ra,rb),19:lambda:'mfcr {}'.format(rs),
                 144:lambda:'mtcrf {},{}'.format((w>>12)&0xFF,rs),
                 23:lambda:'lwzx {},{},{}'.format(rs,ra,rb),87:lambda:'lbzx {},{},{}'.format(rs,ra,rb),
                 279:lambda:'lhzx {},{},{}'.format(rs,ra,rb),343:lambda:'lhax {},{},{}'.format(rs,ra,rb),
                 151:lambda:'stwx {},{},{}'.format(rs,ra,rb),215:lambda:'stbx {},{},{}'.format(rs,ra,rb),
                 407:lambda:'sthx {},{},{}'.format(rs,ra,rb),535:lambda:'lfsx f{},{},{}'.format(rs,ra,rb),
                 663:lambda:'stfsx f{},{},{}'.format(rs,ra,rb),8:lambda:'subfc {},{},{}'.format(rs,ra,rb),
                 75:lambda:'mulhw {},{},{}'.format(rs,ra,rb),11:lambda:'mulhwu {},{},{}'.format(rs,ra,rb),
                 470:lambda:'dcbi {},{}'.format(ra,rb),83:lambda:'mfmsr {}'.format(rs),
                 146:lambda:'mtmsr {}'.format(rs),210:lambda:'mtsr {},{}'.format(ra,rs),
                 854:lambda:'eieio'}
        fn=xop_map.get(xop)
        if fn is None: return None
        result=fn()
        RC_XOPS={266,40,235,28,60,284,316,412,476,124,444,24,536,792,824,26,922,954,136,202,138,200,104,16,10,8,75,11}
        if (w&1) and xop in RC_XOPS: result=result.replace(' ','. ',1) if ' ' in result else result+'.'
        return result
    elif op==17: return 'sc'
    elif op==19:
        xop=(w>>1)&0x3FF
        if xop==150: return 'isync'
        cr_logical={33:'crnor',129:'crandc',193:'crxor',225:'crnand',257:'crand',289:'creqv',417:'crorc',449:'cror'}
        if xop in cr_logical:
            crd=(w>>21)&31;cra=(w>>16)&31;crb=(w>>11)&31
            return '{} {},{},{}'.format(cr_logical[xop],crd,cra,crb)
        if xop==0:
            crfd=(w>>23)&7;crfs=(w>>18)&7; return 'mcrf cr{},cr{}'.format(crfd,crfs)
        if xop==16:
            bo=(w>>21)&31;bi=(w>>16)&31;lk=w&1
            if lk: return 'blrl'
            if bo==20 and bi==0: return 'blr'
            bclr_map={(12,0):'bltlr',(4,0):'bgelr',(12,1):'bgtlr',(4,1):'blelr',(12,2):'beqlr',(4,2):'bnelr',(12,3):'bsolr',(4,3):'bnslr'}
            key=(bo,bi%4); mn=bclr_map.get(key)
            if mn is None: return None
            cr=bi//4; return '{} cr{}'.format(mn,cr) if cr!=0 else mn
        if xop==528:
            bo=(w>>21)&31;bi=(w>>16)&31;lk=w&1
            if lk: return 'bctrl'
            if bo==20 and bi==0: return 'bctr'
            return None
        return None
    elif op==59:
        xop=(w>>1)&31; frt,fra,frb=(w>>21)&31,(w>>16)&31,(w>>11)&31; frc=(w>>6)&31
        fp_map={21:'fadds',20:'fsubs',18:'fdivs',24:'fres',22:'fsqrts'}
        fpm_map={25:'fmuls',29:'fmadds',28:'fmsubs',31:'fnmadds',30:'fnmsubs'}
        if xop in fp_map: return '{} f{},f{},f{}'.format(fp_map[xop],frt,fra,frb)
        elif xop in fpm_map: return '{} f{},f{},f{}'.format(fpm_map[xop],frt,fra,frc) if xop==25 else '{} f{},f{},f{},f{}'.format(fpm_map[xop],frt,fra,frc,frb)
        return None
    elif op==63:
        xop10=(w>>1)&0x3FF; xop5=(w>>1)&31
        frt,fra,frb=(w>>21)&31,(w>>16)&31,(w>>11)&31; frc=(w>>6)&31
        d_map={21:'fadd',20:'fsub',18:'fdiv',72:'fmr',14:'fctiw',15:'fctiwz',12:'frsp',40:'fneg',264:'fabs',136:'fnabs',32:'fcmpo'}
        d0_map={0:'fcmpu'}; da_map={25:'fmul',29:'fmadd',28:'fmsub',31:'fnmadd',30:'fnmsub'}; da_sel={23:'fsel'}
        if xop10 in d0_map: bf=(w>>23)&7; return '{} {},f{},f{}'.format(d0_map[xop10],bf,fra,frb)
        elif xop10 in d_map:
            if xop10 in(72,14,15,12,40,264,136): return '{} f{},f{}'.format(d_map[xop10],frt,frb)
            return '{} f{},f{},f{}'.format(d_map[xop10],frt,fra,frb)
        elif xop5 in da_map: return '{} f{},f{},f{},f{}'.format(da_map[xop5],frt,fra,frc,frb)
        elif xop5 in da_sel: return '{} f{},f{},f{},f{}'.format(da_sel[xop5],frt,fra,frc,frb)
        return None
    return None

def try_stub(addr, body):
    n = len(body)
    bl_stubs = {}; br_info = {}; label_targets = set(); bl_count = 0
    for i, w in enumerate(body):
        op = (w >> 26) & 0x3F
        if op == 18:
            lk = w & 1; aa = (w >> 1) & 1
            if lk:
                bl_stubs[i] = '_s{:08X}_{}'.format(addr, bl_count); bl_count += 1
            else:
                if aa: return None, f'op18 aa=1 at i={i}'
                li = (w >> 2) & 0xFFFFFF
                if li >= 0x800000: li -= 0x1000000
                t = i + li
                if 0 <= t <= n:
                    br_info[i] = {'mnemonic': 'b', 'cr_str': '', 'target': t}
                    label_targets.add(t)
                else:
                    return None, f'op18 oob at i={i} t={t} n={n}'
        elif op == 16:
            lk = w & 1; aa = (w >> 1) & 1
            if lk or aa: return None, f'op16 lk/aa at i={i}'
            bo = (w >> 21) & 0x1F; bi = (w >> 16) & 0x1F
            bd = (w >> 2) & 0x3FFF
            if bd >= 0x2000: bd -= 0x4000
            t = i + bd
            res = get_bc_mnemonic_and_cr(bo, bi)
            if res is None: return None, f'op16 bad cond at i={i} bo={bo} bi={bi}'
            if 0 <= t <= n:
                br_info[i] = {'mnemonic': res[0], 'cr_str': res[1], 'target': t}
                label_targets.add(t)
            else:
                return None, f'op16 oob at i={i} t={t} n={n}'
    for i, w in enumerate(body):
        if i in bl_stubs or i in br_info: continue
        asm = insn_asm_extended(w)
        if asm is None:
            op = (w >> 26) & 0x3F
            xop = (w >> 1) & 0x3FF if op in (19, 31, 59, 63) else -1
            return None, f'insn_asm None at i={i} op={op} xop={xop} w={w:08x}'
    return True, 'ok'

# Analyze all unmatched BLR-ending functions
blockers = {}

with open('extracted/files/u2_ngc_release_dvd.map', errors='replace') as mf:
    for line in mf:
        parts = line.split()
        if len(parts) < 4: continue
        try: addr=int(parts[0],16); size=int(parts[1],16); name=' '.join(parts[3:])
        except: continue
        if not (0x80001000 <= addr < 0x80240000): continue
        if size < 8: continue
        if addr in matched: continue
        if chr(92) in name or '/' in name: continue
        if name.startswith('.'): continue
        off = (addr - DOL_TEXT_START) + DOL_FILE_OFFSET
        if off < 0 or off + size > len(dol): continue
        words = struct.unpack('>{}I'.format(size//4), dol[off:off+size])
        if words[-1] != BLR: continue
        body = words[:-1]
        ok, reason = try_stub(addr, body)
        if not ok:
            key = reason.split(' at ')[0].split(' w=')[0]
            if key not in blockers: blockers[key] = []
            blockers[key].append((addr, size, name[:50]))

print('Blocking reasons:')
for k, v in sorted(blockers.items(), key=lambda x: -len(x[1])):
    print(f'  {k}: {len(v)}')
    for addr, size, name in v[:3]:
        print(f'    {addr:08x} {size:5d}B {name}')
