// 0x8023F550 SNRead32(void) (60B)
// FLAGS: -fno-schedule-insns
// Cascade ASMPROC: 16 GCC insns -> 15 DOL (trailing blr truncated by [:60]).
// Prologue reorder + extra CC006834 lis absorbed. No shift on return value.
// ASMPROC_replace_insn: match="stwu 1,-8(1)" replacement="mflr 4"
// ASMPROC_replace_insn: match="mflr 0" replacement="stw 4,4(1)"
// ASMPROC_replace_insn: match="stw 0,12(1)" replacement="stwu 1,-8(1)"
// ASMPROC_replace_insn: match="lis 9,g_SN_CC006838_w@ha" replacement="lis 4,g_SN_CC006838_w@ha"
// ASMPROC_replace_insn: match="li 0,0" replacement="li 3,0"
// ASMPROC_replace_insn: match="stw 0,g_SN_CC006838_w@l(9)" replacement="stw 3,g_SN_CC006838_w@l(4)"
// ASMPROC_replace_insn: match="lis 11,g_SN_CC006834@ha" replacement="li 3,49"
// ASMPROC_replace_insn: match="li 0,49" replacement="stw 3,g_SN_CC006834@l(4)"
// ASMPROC_replace_insn: match="stw 0,g_SN_CC006834@l(11)" replacement="bl SNSync__Fv"
// ASMPROC_replace_insn: match="bl SNSync__Fv" replacement="lis 4,g_SN_CC006838@ha" occurrence=1
// ASMPROC_replace_insn: match="lis 9,g_SN_CC006838@ha" replacement="lwz 3,g_SN_CC006838@l(4)"
// ASMPROC_replace_insn: match="lwz 3,g_SN_CC006838@l(9)" replacement="lwz 4,12(1)"
// ASMPROC_replace_insn: match="lwz 0,12(1)" replacement="la 1,8(1)"
// ASMPROC_replace_insn: match="mtlr 0" replacement="mtlr 4"
// ASMPROC_replace_insn: match="la 1,8(1)" replacement="blr" occurrence=1
extern volatile unsigned int g_SN_CC006838_w[];
extern volatile unsigned int g_SN_CC006834[];
extern volatile unsigned int g_SN_CC006838[];
void SNSync();

unsigned int SNRead32() {
    g_SN_CC006838_w[0] = 0;
    g_SN_CC006834[0] = 0x31;
    SNSync();
    return g_SN_CC006838[0];
}
