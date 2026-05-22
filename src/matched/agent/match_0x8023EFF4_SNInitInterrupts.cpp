// 0x8023EFF4 SNInitInterrupts(void) (72 B)
// FLAGS: -fno-schedule-insns
// Prologue: DOL has mflr;stw4;stwu — GCC has stwu;mflr;stw12
// ASMPROC_replace_insn: match="stwu 1,-8(1)" replacement="mflr 0"
// ASMPROC_replace_insn: match="mflr 0" replacement="stw 0,4(1)" occurrence=1
// ASMPROC_replace_insn: match="stw 0,12(1)" replacement="stwu 1,-8(1)"
// Body: DOL emits ori r4 before li r3; GCC emits li r3 first
// ASMPROC_replace_insn: match="li 3,25" replacement="ori 4,4,62496"
// ASMPROC_replace_insn: match="ori 4,4,62496" replacement="li 3,25" occurrence=1
// Epilogue: DOL has la;mtlr — GCC has mtlr;la
// ASMPROC_replace_insn: match="mtlr 0" replacement="la 1,8(1)"
// ASMPROC_replace_insn: match="la 1,8(1)" replacement="mtlr 0" occurrence=1
extern "C" void __OSMaskInterrupts(unsigned int);
extern "C" void __OSSetInterruptHandler(int, void*);
extern "C" void __OSUnmaskInterrupts(unsigned int);

extern "C" void SNInitInterrupts() {
    __OSMaskInterrupts(0x18000);
    __OSMaskInterrupts(64);
    __OSSetInterruptHandler(25, (void*)0x8023F420);
    __OSUnmaskInterrupts(64);
}
