// 0x8023F5BC SNDVDRead_init(void) (80B)
// FLAGS: -fno-schedule-insns
// Cascade ASMPROC: 21 GCC insns -> 20 DOL (trailing blr truncated by [:80]).
// Prologue reorder (mflr r0 before stwu). stmw r28 + lmw r28 injected.
// Frame size 8->24; LR at 12->28. Epilogue: lmw injected before la, la->addi.
// ASMPROC_inject_before: before="bl SNSelect__Fv" lines="stmw 28,8(1)"
// ASMPROC_replace_insn: match="stwu 1,-8(1)" replacement="mflr 0"
// ASMPROC_replace_insn: match="mflr 0" replacement="stwu 1,-24(1)" occurrence=1
// ASMPROC_replace_insn: match="stw 0,12(1)" replacement="stw 0,28(1)"
// ASMPROC_replace_insn: match="lwz 0,12(1)" replacement="lwz 0,28(1)"
// ASMPROC_inject_before: before="la 1,8(1)" lines="lmw 28,8(1)"
// ASMPROC_replace_insn: match="la 1,8(1)" replacement="addi 1,1,24"
void SNSelect();
unsigned int SNRead8();
void SNWiggleSelect();
void SNWrite8(unsigned int);

void SNDVDRead_init() {
    SNSelect();
    while (SNRead8() == 0);
    do { SNWiggleSelect(); } while (SNRead8() == 0xFF);
    SNWiggleSelect();
    SNWrite8(2);
}
