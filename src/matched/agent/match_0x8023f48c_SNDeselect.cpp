// 0x8023F48C SNDeselect(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_replace_insn: match="lis 9," replacement="lis 4,"
// ASMPROC_replace_insn: match="@l(9)" replacement="@l(4)" occurrence=0
// ASMPROC_replace_insn: match="@l(9)" replacement="@l(4)" occurrence=0
// ASMPROC_replace_insn: match="lwz 0," replacement="lwz 3,"
// ASMPROC_replace_insn: match="andi. 0,0,5" replacement="andi. 3,3,5"
// ASMPROC_replace_insn: match="stw 0," replacement="stw 3,"
extern volatile unsigned int g_SN_CC006828[];

void SNDeselect() {
    unsigned int v = g_SN_CC006828[0] & 5U;
    g_SN_CC006828[0] = v;
}
