import struct, re, glob

dol = open('extracted/sys/main.dol','rb').read()
matched = set()
for f in glob.glob('src/matched/**/*.cpp', recursive=True):
    m = re.search(r'match_(0[xX])?([0-9A-Fa-f]{8})_', f)
    if m: matched.add(int(m.group(2), 16))

def decode_signed16(v): return v - 0x10000 if v >= 0x8000 else v

def insn_asm_full(w):
    op = (w >> 26) & 0x3F
    if op == 14:
        rt = (w >> 21) & 0x1F; ra = (w >> 16) & 0x1F; imm = decode_signed16(w & 0xFFFF)
        return 'li {},{}'.format(rt, imm) if ra == 0 else 'addi {},{},{}'.format(rt, ra, imm)
    elif op in (32,33,34,35,40,41,42,43):
        names = {32:'lwz',33:'lwzu',34:'lbz',35:'lbzu',40:'lhz',41:'lhzu',42:'lha',43:'lhau'}
        rt,ra,d = (w>>21)&0x1F,(w>>16)&0x1F,decode_signed16(w&0xFFFF)
        return '{} {},{:#x}({})'.format(names[op],rt,d,ra) if d>=0 else '{} {},{}({})'.format(names[op],rt,d,ra)
    elif op in (36,37,38,39,44,45):
        names = {36:'stw',37:'stwu',38:'stb',39:'stbu',44:'sth',45:'sthu'}
        rs,ra,d = (w>>21)&0x1F,(w>>16)&0x1F,decode_signed16(w&0xFFFF)
        return '{} {},{:#x}({})'.format(names[op],rs,d,ra) if d>=0 else '{} {},{}({})'.format(names[op],rs,d,ra)
    elif op in (46,47):
        names = {46:'lmw',47:'stmw'}; rt,ra,d=(w>>21)&0x1F,(w>>16)&0x1F,decode_signed16(w&0xFFFF)
        return '{} {},{:#x}({})'.format(names[op],rt,d,ra) if d>=0 else '{} {},{}({})'.format(names[op],rt,d,ra)
    elif op in (48,49,50,51):
        names={48:'lfs',49:'lfsu',50:'lfd',51:'lfdu'}; frt,ra,d=(w>>21)&0x1F,(w>>16)&0x1F,decode_signed16(w&0xFFFF)
        return '{} f{},{:#x}({})'.format(names[op],frt,d,ra) if d>=0 else '{} f{},{}({})'.format(names[op],frt,d,ra)
    elif op in (52,53,54,55):
        names={52:'stfs',53:'stfsu',54:'stfd',55:'stfdu'}; frs,ra,d=(w>>21)&0x1F,(w>>16)&0x1F,decode_signed16(w&0xFFFF)
        return '{} f{},{:#x}({})'.format(names[op],frs,d,ra) if d>=0 else '{} f{},{}({})'.format(names[op],frs,d,ra)
    elif op == 15:
        rt,ra,imm=(w>>21)&0x1F,(w>>16)&0x1F,decode_signed16(w&0xFFFF)
        return 'lis {},{}'.format(rt,imm) if ra==0 else 'addis {},{},{}'.format(rt,ra,imm)
    elif op in (24,25,26,27):
        names={24:'ori',25:'oris',26:'xori',27:'xoris'}
        rs,ra,imm=(w>>21)&0x1F,(w>>16)&0x1F,w&0xFFFF
        return '{} {},{},{}'.format(names[op],ra,rs,imm)
    elif op == 28:
        rs,ra,imm=(w>>21)&0x1F,(w>>16)&0x1F,w&0xFFFF
        return 'andi. {},{},{}'.format(ra,rs,imm)
    elif op == 31:
        xo = (w>>1)&0x3FF
        rS,rA,rB = (w>>21)&0x1F,(w>>16)&0x1F,(w>>11)&0x1F
        if xo == 444: return 'mr {},{}'.format(rA,rS) if rS==rB else 'or {},{},{}'.format(rA,rS,rB)
        if xo == 467:
            spr = (rA<<5)|rB
            sprnames = {8:'lr',9:'ctr',1:'xer'}
            sn = sprnames.get(spr,'spr{}'.format(spr))
            return 'mt{} {}'.format(sn,rS)
        if xo == 339:
            spr = (rA<<5)|rB
            sprnames = {8:'lr',9:'ctr',1:'xer'}
            sn = sprnames.get(spr,'spr{}'.format(spr))
            return 'mf{} {}'.format(rS,sn)
        if xo == 266: return 'add {},{},{}'.format(rS,rA,rB)
        if xo == 0:
            crfd=(w>>23)&0x7
            return 'cmpw cr{},{},{}'.format(crfd,rA,rB) if crfd else 'cmpw {},{}'.format(rA,rB)
        if xo == 32:
            crfd=(w>>23)&0x7
            return 'cmplw cr{},{},{}'.format(crfd,rA,rB) if crfd else 'cmplw {},{}'.format(rA,rB)
        if xo == 23: return 'lwzx {},{},{}'.format(rS,rA,rB)
        if xo == 87: return 'lbzx {},{},{}'.format(rS,rA,rB)
        if xo == 279: return 'lhzx {},{},{}'.format(rS,rA,rB)
        if xo == 343: return 'lhax {},{},{}'.format(rS,rA,rB)
        if xo == 40: return 'subf {},{},{}'.format(rS,rA,rB)
        if xo == 954: return 'extsh {},{}'.format(rA,rS)
        if xo == 922: return 'extsb {},{}'.format(rA,rS)
        if xo == 986: return 'extsb {},{}'.format(rA,rS)
        if xo == 151: return 'stwx {},{},{}'.format(rS,rA,rB)
        if xo == 215: return 'stbx {},{},{}'.format(rS,rA,rB)
        if xo == 407: return 'sthx {},{},{}'.format(rS,rA,rB)
        if xo == 824: sh=rB; return 'srawi {},{},{}'.format(rA,rS,sh)
        if xo == 536: return 'srw {},{},{}'.format(rA,rS,rB)
        if xo == 792: return 'sraw {},{},{}'.format(rA,rS,rB)
        if xo == 24: return 'slw {},{},{}'.format(rA,rS,rB)
        if xo == 28: return 'and {},{},{}'.format(rA,rS,rB)
        if xo == 476: return 'nand {},{},{}'.format(rA,rS,rB)
        if xo == 124: return 'nor {},{},{}'.format(rA,rS,rB)
        if xo == 316: return 'xor {},{},{}'.format(rA,rS,rB)
        if xo == 104: return 'neg {},{}'.format(rS,rA)
        if xo == 138: return 'addc {},{},{}'.format(rS,rA,rB)
        if xo == 234: return 'addme {},{}'.format(rS,rA)
        if xo == 202: return 'addze {},{}'.format(rS,rA)
        if xo == 8: return 'subfc {},{},{}'.format(rS,rA,rB)
        if xo == 11: return 'mulhwu {},{},{}'.format(rS,rA,rB)
        if xo == 75: return 'mulhw {},{},{}'.format(rS,rA,rB)
        if xo == 235: return 'mullw {},{},{}'.format(rS,rA,rB)
        if xo == 119: return 'lbzux {},{},{}'.format(rS,rA,rB)
        if xo == 55: return 'lwzux {},{},{}'.format(rS,rA,rB)
        if xo == 311: return 'lhzux {},{},{}'.format(rS,rA,rB)
        return None
    elif op == 11:
        crfd=(w>>23)&0x7; ra=(w>>16)&0x1F; uimm=w&0xFFFF
        return 'cmplwi cr{},{},{}'.format(crfd,ra,uimm) if crfd else 'cmplwi {},{}'.format(ra,uimm)
    elif op == 10:
        crfd=(w>>23)&0x7; ra=(w>>16)&0x1F; uimm=w&0xFFFF
        return 'cmpli cr{},0,{},{}'.format(crfd,ra,uimm) if crfd else 'cmpli 0,0,{},{}'.format(ra,uimm)
    elif op == 7:
        rt,ra,imm=(w>>21)&0x1F,(w>>16)&0x1F,decode_signed16(w&0xFFFF)
        return 'mulli {},{},{}'.format(rt,ra,imm)
    elif op == 8:
        rt,ra,imm=(w>>21)&0x1F,(w>>16)&0x1F,decode_signed16(w&0xFFFF)
        return 'subfic {},{},{}'.format(rt,ra,imm)
    elif op == 13:
        rt,ra,imm=(w>>21)&0x1F,(w>>16)&0x1F,decode_signed16(w&0xFFFF)
        return 'addi {},{},{}'.format(rt,ra,imm)
    elif op == 21:
        rs,ra,sh,mb,me=(w>>21)&0x1F,(w>>16)&0x1F,(w>>11)&0x1F,(w>>6)&0x1F,(w>>1)&0x1F
        return 'rlwinm {},{},{},{},{}'.format(ra,rs,sh,mb,me)
    elif op == 19:
        xop=(w>>1)&0x3FF
        if xop==16:
            bo=(w>>21)&0x1F; bi=(w>>16)&0x1F; lk=w&1
            if lk: return None
            if bo==20 and bi==0: return None
            bclr_map={(12,0):'bltlr',(4,0):'bgelr',(12,1):'bgtlr',(4,1):'blelr',(12,2):'beqlr',(4,2):'bnelr',(12,3):'bsolr',(4,3):'bnslr'}
            key=(bo,bi%4); mn=bclr_map.get(key)
            if mn is None: return None
            cr=bi//4; return '{} cr{}'.format(mn,cr) if cr!=0 else mn
        return None
    elif op == 59:
        xop=(w>>1)&0x1F; frt,fra,frb=(w>>21)&0x1F,(w>>16)&0x1F,(w>>11)&0x1F; frc=(w>>6)&0x1F
        fp_map={21:'fadds',20:'fsubs',18:'fdivs',24:'fres',22:'fsqrts'}; fpm_map={25:'fmuls'}
        if xop in fp_map: return '{} f{},f{},f{}'.format(fp_map[xop],frt,fra,frb)
        elif xop in fpm_map: return '{} f{},f{},f{}'.format(fpm_map[xop],frt,fra,frc)
        return None
    elif op == 63:
        xop=(w>>1)&0x3FF; frt,fra,frb=(w>>21)&0x1F,(w>>16)&0x1F,(w>>11)&0x1F
        d_map={21:'fadd',20:'fsub',18:'fdiv',72:'fmr',814:'fctiwz',12:'frsp',40:'fneg',264:'fabs',136:'fnabs'}
        d0_map={0:'fcmpu',32:'fcmpo'}; dm_map={25:'fmul'}
        if xop in d0_map: bf=(w>>23)&0x7; return '{} {},f{},f{}'.format(d0_map[xop],bf,fra,frb)
        elif xop in d_map:
            if xop in (72,814,12,40,264,136): return '{} f{},f{}'.format(d_map[xop],frt,frb)
            return '{} f{},f{},f{}'.format(d_map[xop],frt,fra,frb)
        elif xop in dm_map: return '{} f{},f{},f{}'.format(dm_map[xop],frt,fra,frc)
        return None
    return None

BLR = 0x4E800020
count = 0
with open('extracted/files/u2_ngc_release_dvd.map', errors='replace') as f:
    for line in f:
        parts = line.split()
        if len(parts) >= 4:
            try:
                addr = int(parts[0], 16)
                size = int(parts[1], 16)
                if 0x80001000 <= addr < 0x80240000 and 8 <= size <= 256 and addr not in matched:
                    data = None
                    for i in range(7):
                        off = struct.unpack_from('>I', dol, i*4)[0]
                        a = struct.unpack_from('>I', dol, 0x48 + i*4)[0]
                        sz = struct.unpack_from('>I', dol, 0x90 + i*4)[0]
                        if a <= addr < a+sz:
                            fo = off + (addr - a)
                            data = struct.unpack('>{}I'.format(size//4), dol[fo:fo+size])
                            break
                    if not data or data[-1] != BLR:
                        continue
                    body = data[:-1]
                    asms = [insn_asm_full(w) for w in body]
                    if all(a is not None for a in asms):
                        count += 1
            except: pass

print('Functions unlockable: {}'.format(count))
