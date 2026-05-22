// 0x8023F7B8 SNDVDWriteSync_next(unsigned int, unsigned int) (104B)
// FLAGS: -fno-schedule-insns
// Cascade ASMPROC: 26 GCC insns -> 26 DOL. Mirror of ReadSync with constant 7 (not 3).
// MMIO tail: base reg r9 (not r11), const reg r0 (not r9). No CC006828 ops; ends with SNSync.
// ASMPROC_replace_insn: match="stwu 1,-16(1)" replacement="mflr 0"
// ASMPROC_replace_insn: match="mflr 0" replacement="stwu 1,-24(1)" occurrence=1
// ASMPROC_replace_insn: match="stmw 30,8(1)" replacement="stmw 28,8(1)"
// ASMPROC_replace_insn: match="stw 0,20(1)" replacement="stw 0,28(1)"
// ASMPROC_replace_insn: match="stmw 28,8(1)" replacement="stw 0,28(1)"
// ASMPROC_replace_insn: match="stw 0,28(1)" replacement="stmw 28,8(1)" occurrence=1
// ASMPROC_replace_insn: match="mr 31,3" replacement="mr 31,4"
// ASMPROC_replace_insn: match="mr 30,4" replacement="mr 30,3"
// ASMPROC_replace_insn: match="lis 9,0xcc00" replacement="lis 29,0xcc00"
// ASMPROC_replace_insn: match="li 0,7" replacement="stw 30,26668(29)"
// ASMPROC_replace_insn: match="stw 31,26668(9)" replacement="stw 31,26672(29)"
// ASMPROC_replace_insn: match="stw 30,26672(9)" replacement="li 3,7"
// ASMPROC_replace_insn: match="stw 0,26676(9)" replacement="stw 3,26676(29)"
// ASMPROC_replace_insn: match="lwz 0,20(1)" replacement="lwz 0,28(1)"
// ASMPROC_replace_insn: match="lmw 30,8(1)" replacement="lmw 28,8(1)"
// ASMPROC_replace_insn: match="la 1,16(1)" replacement="addi 1,1,24"
void SNWiggleSelect();
unsigned int SNRead8();
void SNSync();

void SNDVDWriteSync_next(unsigned int addr, unsigned int len) {
    SNWiggleSelect();
    while (SNRead8() == 0);
    do { SNWiggleSelect(); } while (SNRead8() == 0xFF);
    SNWiggleSelect();
    volatile unsigned int *mmio = (volatile unsigned int *)0xCC000000;
    mmio[0x682C >> 2] = addr;
    mmio[0x6830 >> 2] = len;
    mmio[0x6834 >> 2] = 7;
    SNSync();
}
