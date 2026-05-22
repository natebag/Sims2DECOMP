// 0x8023F4C8 SNSync(void) (20B)
// ASMPROC_replace_insn: match="lis 9," replacement="lis 4,"
// ASMPROC_replace_insn: match="@l(9)" replacement="@l(4)"
// ASMPROC_replace_insn: match="andi. 0,3,1" replacement="clrlwi. 3,3,31"
extern volatile unsigned int g_SN_CC006834[];

unsigned int SNSync() {
    unsigned int v;
    do {
        v = g_SN_CC006834[0];
    } while (v & 1U);
    return v;
}
