// 0x8023F48C SNDeselect(void) (20B)
// ASMPROC_replace_insn: match="lis 9," replacement="lis 4,"
// ASMPROC_replace_insn: match="@l(9)" replacement="@l(4)" occurrence=0
// ASMPROC_replace_insn: match="@l(9)" replacement="@l(4)" occurrence=0
extern volatile unsigned int g_SN_CC006828[];

unsigned int SNDeselect() {
    unsigned int v = g_SN_CC006828[0] & 5U;
    g_SN_CC006828[0] = v;
    return v;
}
