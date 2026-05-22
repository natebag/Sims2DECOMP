// 0x8023F6E4 SNDVDWrite_init(unsigned int) (100B)
// FLAGS: -fno-schedule-insns
// GCC hoists val>>8 into r30 (srwi before loops) making 26 insns vs DOL's 25.
// Fix: call SNWrite8(val) twice; ASMPROC replaces first mr 3,31 with inline rlwinm.
// Prologue: GCC uses stw r31 + frame -16; DOL uses stmw r28 + frame -24 (4 callee-saves).
// ASMPROC_replace_insn: match="stwu 1,-16(1)" replacement="mflr 0"
// ASMPROC_replace_insn: match="mflr 0" replacement="stwu 1,-24(1)" occurrence=1
// ASMPROC_replace_insn: match="stw 31,12(1)" replacement="stw 0,28(1)"
// ASMPROC_replace_insn: match="stw 0,20(1)" replacement="stmw 28,8(1)"
// ASMPROC_replace_insn: match="mr 3,31" replacement="rlwinm 3,31,24,8,31"
// ASMPROC_replace_insn: match="lwz 0,20(1)" replacement="lwz 0,28(1)"
// ASMPROC_replace_insn: match="lwz 31,12(1)" replacement="lmw 28,8(1)"
// ASMPROC_replace_insn: match="la 1,16(1)" replacement="addi 1,1,24"
void SNSelect();
unsigned int SNRead8();
void SNWiggleSelect();
void SNWrite8(unsigned int);

void SNDVDWrite_init(unsigned int val) {
    SNSelect();
    while (SNRead8() == 0);
    do { SNWiggleSelect(); } while (SNRead8() == 0xFF);
    SNWiggleSelect();
    SNWrite8(3);
    SNWrite8(val);
    SNWrite8(val);
}
