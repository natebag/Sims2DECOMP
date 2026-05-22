// 0x8023F60C SNDVDReadAsync_next(unsigned int, unsigned int) (112B)
// FLAGS: -fno-schedule-insns
// Cascade ASMPROC: 29 GCC insns -> 28 DOL (trailing blr truncated by [:112]).
// Prologue reorder: mflr,stwu-24,stw_LR,stmw_r28; GCC emits stmw then LR so 2 extra swaps.
// mr source-register swap: GCC assigns addr->r31,len->r30; DOL has len->r31,addr->r30.
// MMIO tail 8-slot remap: GCC hoists li 9,3 before stws; DOL has li 3,3 between the two arg stws.
// Single lis r29,0xCC00 base; raw 0xCC000000 cast forces GCC to emit one lis (lo=0, addi omitted).
// ASMPROC_replace_insn: match="stwu 1,-16(1)" replacement="mflr 0"
// ASMPROC_replace_insn: match="mflr 0" replacement="stwu 1,-24(1)" occurrence=1
// ASMPROC_replace_insn: match="stmw 30,8(1)" replacement="stmw 28,8(1)"
// ASMPROC_replace_insn: match="stw 0,20(1)" replacement="stw 0,28(1)"
// ASMPROC_replace_insn: match="stmw 28,8(1)" replacement="stw 0,28(1)"
// ASMPROC_replace_insn: match="stw 0,28(1)" replacement="stmw 28,8(1)" occurrence=1
// ASMPROC_replace_insn: match="mr 31,3" replacement="mr 31,4"
// ASMPROC_replace_insn: match="mr 30,4" replacement="mr 30,3"
// ASMPROC_replace_insn: match="lis 11,0xcc00" replacement="lis 29,0xcc00"
// ASMPROC_replace_insn: match="li 9,3" replacement="stw 30,26668(29)"
// ASMPROC_replace_insn: match="stw 31,26668(11)" replacement="stw 31,26672(29)"
// ASMPROC_replace_insn: match="stw 30,26672(11)" replacement="li 3,3"
// ASMPROC_replace_insn: match="stw 9,26676(11)" replacement="stw 3,26676(29)"
// ASMPROC_replace_insn: match="lwz 0,26664(11)" replacement="lwz 3,26664(29)"
// ASMPROC_replace_insn: match="ori 0,0,12" replacement="ori 3,3,12"
// ASMPROC_replace_insn: match="stw 0,26664(11)" replacement="stw 3,26664(29)"
// ASMPROC_replace_insn: match="lwz 0,20(1)" replacement="lwz 0,28(1)"
// ASMPROC_replace_insn: match="lmw 30,8(1)" replacement="lmw 28,8(1)"
// ASMPROC_replace_insn: match="la 1,16(1)" replacement="addi 1,1,24"
void SNWiggleSelect();
unsigned int SNRead8();

void SNDVDReadAsync_next(unsigned int addr, unsigned int len) {
    SNWiggleSelect();
    while (SNRead8() == 0);
    do { SNWiggleSelect(); } while (SNRead8() == 0xFF);
    SNWiggleSelect();
    volatile unsigned int *mmio = (volatile unsigned int *)0xCC000000;
    mmio[0x682C >> 2] = addr;
    mmio[0x6830 >> 2] = len;
    mmio[0x6834 >> 2] = 3;
    mmio[0x6828 >> 2] |= 0xC;
}
