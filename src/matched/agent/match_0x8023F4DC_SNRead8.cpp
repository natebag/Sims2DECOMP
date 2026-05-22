// 0x8023F4DC SNRead8(void) (64B)
// FLAGS: -fno-schedule-insns
// Cascade ASMPROC: 17 GCC insns -> 16 DOL insns (trailing blr truncated by [:64]).
// Prologue reorder: DOL has mflr r4/stw r4,4(r1)/stwu; GCC has stwu/mflr r0/stw r0,12(r1).
// Extra lis (for CC006834 base) absorbed into the following li.
// All register renames: r9->r4 (base), r11->r4 (CC006834 base), r0->r3 (value).
// ASMPROC_replace_insn: match="stwu 1,-8(1)" replacement="mflr 4"
// ASMPROC_replace_insn: match="mflr 0" replacement="stw 4,4(1)"
// ASMPROC_replace_insn: match="stw 0,12(1)" replacement="stwu 1,-8(1)"
// ASMPROC_replace_insn: match="lis 9,g_SN_CC006838_w@ha" replacement="lis 4,g_SN_CC006838_w@ha"
// ASMPROC_replace_insn: match="li 0,0" replacement="li 3,0"
// ASMPROC_replace_insn: match="g_SN_CC006838_w@l(9)" replacement="g_SN_CC006838_w@l(4)"
// ASMPROC_replace_insn: match="stw 0,g_SN_CC006838_w@l(4)" replacement="stw 3,g_SN_CC006838_w@l(4)"
// ASMPROC_replace_insn: match="lis 11,g_SN_CC006834@ha" replacement="li 3,1"
// ASMPROC_replace_insn: match="li 0,1" replacement="stw 3,g_SN_CC006834@l(4)"
// ASMPROC_replace_insn: match="stw 0,g_SN_CC006834@l(11)" replacement="bl SNSync__Fv"
// ASMPROC_replace_insn: match="bl SNSync__Fv" replacement="lis 4,g_SN_CC006838@ha" occurrence=1
// ASMPROC_replace_insn: match="lis 9,g_SN_CC006838@ha" replacement="lwz 3,g_SN_CC006838@l(4)"
// ASMPROC_replace_insn: match="lwz 3,g_SN_CC006838@l(9)" replacement="srwi 3,3,24"
// ASMPROC_replace_insn: match="srwi 3,3,24" replacement="lwz 4,12(1)" occurrence=1
// ASMPROC_replace_insn: match="lwz 0,12(1)" replacement="la 1,8(1)"
// ASMPROC_replace_insn: match="mtlr 0" replacement="mtlr 4"
// ASMPROC_replace_insn: match="la 1,8(1)" replacement="blr" occurrence=1
extern volatile unsigned int g_SN_CC006838_w[];
extern volatile unsigned int g_SN_CC006834[];
extern volatile unsigned int g_SN_CC006838[];
void SNSync();

unsigned int SNRead8() {
    g_SN_CC006838_w[0] = 0;
    g_SN_CC006834[0] = 1;
    SNSync();
    return g_SN_CC006838[0] >> 24;
}
