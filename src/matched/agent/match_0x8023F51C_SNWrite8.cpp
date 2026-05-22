// 0x8023F51C SNWrite8(unsigned int) (52B)
// FLAGS: -fno-schedule-insns
// Cascade ASMPROC: 14 GCC insns -> 13 DOL (trailing blr truncated by [:52]).
// Prologue reorder + GCC swaps lis/slwi order vs DOL (rlwinm then lis).
// Extra CC006834 lis absorbed into following li.
// ASMPROC_replace_insn: match="stwu 1,-8(1)" replacement="mflr 4"
// ASMPROC_replace_insn: match="mflr 0" replacement="stw 4,4(1)"
// ASMPROC_replace_insn: match="stw 0,12(1)" replacement="stwu 1,-8(1)"
// ASMPROC_replace_insn: match="lis 9,g_SN_CC006838_w@ha" replacement="slwi 3,3,24"
// ASMPROC_replace_insn: match="slwi 3,3,24" replacement="lis 4,g_SN_CC006838_w@ha" occurrence=1
// ASMPROC_replace_insn: match="stw 3,g_SN_CC006838_w@l(9)" replacement="stw 3,g_SN_CC006838_w@l(4)"
// ASMPROC_replace_insn: match="lis 11,g_SN_CC006834@ha" replacement="li 3,5"
// ASMPROC_replace_insn: match="li 0,5" replacement="stw 3,g_SN_CC006834@l(4)"
// ASMPROC_replace_insn: match="stw 0,g_SN_CC006834@l(11)" replacement="bl SNSync__Fv"
// ASMPROC_replace_insn: match="bl SNSync__Fv" replacement="lwz 4,12(1)" occurrence=1
// ASMPROC_replace_insn: match="lwz 0,12(1)" replacement="la 1,8(1)"
// ASMPROC_replace_insn: match="mtlr 0" replacement="mtlr 4"
// ASMPROC_replace_insn: match="la 1,8(1)" replacement="blr" occurrence=1
extern volatile unsigned int g_SN_CC006838_w[];
extern volatile unsigned int g_SN_CC006834[];
void SNSync();

void SNWrite8(unsigned int val) {
    g_SN_CC006838_w[0] = val << 24;
    g_SN_CC006834[0] = 5;
    SNSync();
}
