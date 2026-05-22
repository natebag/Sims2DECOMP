// 0x8023F58C SNWrite32(unsigned int) (48B)
// FLAGS: -fno-schedule-insns
// Cascade ASMPROC: 13 GCC insns -> 12 DOL (trailing blr truncated by [:48]).
// Prologue reorder + GCC hoists both lis before stores. Extra CC006834 lis
// absorbed into DOL's stw-at-L4. Epilogue: addi-first, lwz 4(r1) not 12(r1).
// ASMPROC_replace_insn: match="stwu 1,-8(1)" replacement="mflr 4"
// ASMPROC_replace_insn: match="mflr 0" replacement="stw 4,4(1)"
// ASMPROC_replace_insn: match="stw 0,12(1)" replacement="stwu 1,-8(1)"
// ASMPROC_replace_insn: match="lis 9,g_SN_CC006838@ha" replacement="lis 4,g_SN_CC006838@ha"
// ASMPROC_replace_insn: match="lis 11,g_SN_CC006834@ha" replacement="stw 3,g_SN_CC006838@l(4)"
// ASMPROC_replace_insn: match="stw 3,g_SN_CC006838@l(9)" replacement="li 3,53"
// ASMPROC_replace_insn: match="li 0,53" replacement="stw 3,g_SN_CC006834@l(4)"
// ASMPROC_replace_insn: match="stw 0,g_SN_CC006834@l(11)" replacement="bl SNSync__Fv"
// ASMPROC_replace_insn: match="bl SNSync__Fv" replacement="la 1,8(1)" occurrence=1
// ASMPROC_replace_insn: match="lwz 0,12(1)" replacement="lwz 4,4(1)"
// ASMPROC_replace_insn: match="mtlr 0" replacement="mtlr 4"
// ASMPROC_replace_insn: match="la 1,8(1)" replacement="blr" occurrence=1
extern volatile unsigned int g_SN_CC006838[];
extern volatile unsigned int g_SN_CC006834[];
void SNSync();

void SNWrite32(unsigned int val) {
    g_SN_CC006838[0] = val;
    g_SN_CC006834[0] = 0x35;
    SNSync();
}
