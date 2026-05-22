// 0x8023F820 SNDVDWriteNoDMA_next(unsigned int, unsigned int) (164 B)
// FLAGS: -fno-schedule-insns
// Prologue reorder + stmw/LR swap:
// ASMPROC_replace_insn: match="stwu 1,-24(1)" replacement="mflr 0"
// ASMPROC_replace_insn: match="mflr 0" replacement="stwu 1,-24(1)" occurrence=1
// ASMPROC_replace_insn: match="stmw 28,8(1)" replacement="stw 0,28(1)"
// ASMPROC_replace_insn: match="stw 0,28(1)" replacement="stmw 28,8(1)" occurrence=1
// mr source/dest swap (GCC r28=addr,r29=len → DOL r31=len,r30=addr):
// ASMPROC_replace_insn: match="mr 28,3" replacement="mr 31,4"
// ASMPROC_replace_insn: match="mr 29,4" replacement="mr 30,3"
// Body register remap (GCC r28→DOL r30, r29→r31, r30→r28, r31→r29):
// ASMPROC_replace_insn: match="andi. 30,29,28" replacement="andi. 28,31,28"
// ASMPROC_replace_insn: match="li 31,0" replacement="li 29,0"
// ASMPROC_replace_insn: match="lwzx 3,28,31" replacement="lwzx 3,30,29"
// Word loop: addi before bl in GCC, bl before addi in DOL (slot swap):
// ASMPROC_replace_insn: match="addi 31,31,4" replacement="bl SNWrite32__FUi"
// ASMPROC_replace_insn: match="bl SNWrite32__FUi" replacement="addi 29,29,4" occurrence=1
// ASMPROC_replace_insn: match="cmplw 0,31,30" replacement="cmpw 0,29,28"
// ASMPROC_replace_insn: match="add 28,28,31" replacement="add 30,30,29"
// ASMPROC_replace_insn: match="andi. 30,29,3" replacement="andi. 28,31,3"
// ASMPROC_replace_insn: match="li 31,0" replacement="li 29,0"
// ASMPROC_replace_insn: match="lbzx 3,28,31" replacement="lbzx 3,30,29"
// Byte loop: same addi/bl slot swap:
// ASMPROC_replace_insn: match="addi 31,31,1" replacement="bl SNWrite8__FUi"
// ASMPROC_replace_insn: match="bl SNWrite8__FUi" replacement="addi 29,29,1" occurrence=1
// ASMPROC_replace_insn: match="cmplw 0,31,30" replacement="cmpw 0,29,28"
// Delay loop: GCC uses r0, DOL uses r3:
// ASMPROC_replace_insn: match="li 0,15" replacement="li 3,15"
// ASMPROC_replace_insn: match="mtctr 0" replacement="mtctr 3"
void SNWiggleSelect();
unsigned int SNRead8();
void SNWrite8(unsigned int);
void SNWrite32(unsigned int);
void SNSelect();

void SNDVDWriteNoDMA_next(unsigned int addr, unsigned int len) {
    SNWiggleSelect();
    while (SNRead8() == 0);
    do { SNWiggleSelect(); } while (SNRead8() == 0xFF);
    SNWiggleSelect();

    unsigned int count = len & 0x1C;
    if (count) {
        unsigned int idx = 0;
        do {
            SNWrite32(*(unsigned int *)(addr + idx));
            idx += 4;
        } while (idx < count);
        addr += idx;
    }

    count = len & 3;
    if (count) {
        unsigned int idx = 0;
        do {
            SNWrite8(*(unsigned char *)(addr + idx));
            idx++;
        } while (idx < count);
    }

    for (unsigned int n = 15; n != 0; n--) {}
    SNSelect();
}
