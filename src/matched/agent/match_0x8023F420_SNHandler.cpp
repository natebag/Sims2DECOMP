// 0x8023F420 SNHandler(void) (84B)
// FLAGS: -fno-schedule-insns
// Cascade ASMPROC: 21 GCC insns -> 21 DOL.
// Prologue reorder (mflr r0, not r4). g_CC003000[] array extern generates lis+stw@l
// (no ori needed, 2 insns for address), keeping .L4 at offset 0x44 so bc 12,2,.L4
// resolves to the correct +0x1c offset. Epilogue: DOL has addi-before-mtlr; swap via cascade.
// ASMPROC_replace_insn: match="stwu 1,-8(1)" replacement="mflr 0"
// ASMPROC_replace_insn: match="mflr 0" replacement="stw 0,4(1)" occurrence=1
// ASMPROC_replace_insn: match="stw 0,12(1)" replacement="stwu 1,-8(1)"
// ASMPROC_replace_insn: match="lis 9,g_CC003000@ha" replacement="li 0,4096"
// ASMPROC_replace_insn: match="li 0,4096" replacement="lis 5,g_CC003000@ha" occurrence=1
// ASMPROC_replace_insn: match="stw 0,g_CC003000@l(9)" replacement="stw 0,g_CC003000@l(5)"
// ASMPROC_replace_insn: match="lis 11,0x8043" replacement="lis 5,0x8043"
// ASMPROC_replace_insn: match="ori 11,11,42048" replacement="ori 5,5,42048"
// ASMPROC_replace_insn: match="lwz 11,0(11)" replacement="lwz 5,0(5)"
// ASMPROC_replace_insn: match="cmpwi 0,11,0" replacement="cmpwi 0,5,0"
// ASMPROC_replace_insn: match="mtlr 11" replacement="mtlr 5"
// ASMPROC_replace_insn: match="lis 9,0x8043" replacement="lis 5,0x8043"
// ASMPROC_replace_insn: match="ori 9,9,42056" replacement="ori 5,5,42056"
// ASMPROC_replace_insn: match="stb 0,0(9)" replacement="stb 0,0(5)"
// ASMPROC_replace_insn: match="mtlr 0" replacement="la 1,8(1)"
// ASMPROC_replace_insn: match="la 1,8(1)" replacement="mtlr 0" occurrence=1
extern volatile unsigned int g_CC003000[];
typedef void (*HandlerFn)();

void SNHandler() {
    g_CC003000[0] = 0x1000;
    HandlerFn fn = *(HandlerFn *)0x8043A440;
    if (fn) {
        *(volatile unsigned char *)0x8043A448 = 1;
        fn();
    }
}
