// 0x8023F4A0 SNWiggleSelect(void) (40B)
// FLAGS: -fno-schedule-insns
// ASMPROC_replace_insn: match="lis 9," replacement="lis 4," occurrence=0
// ASMPROC_replace_insn: match="@l(9)" replacement="@l(4)" occurrence=0
// ASMPROC_replace_insn: match="@l(9)" replacement="@l(4)" occurrence=0
// ASMPROC_replace_insn: match="lis 9,g_SN_CC006828@ha" replacement="stw 5,g_SN_CC006828@l(4)"
// ASMPROC_replace_insn: match="stw 0,g_SN_CC006828@l(9)" replacement="blr"
// ASMPROC_replace_insn: match="lwz 0," replacement="lwz 5,"
// ASMPROC_replace_insn: match="andi. 0,0,5" replacement="andi. 5,5,5"
// ASMPROC_replace_insn: match="stw 0,g_SN_CC006828@l(4)" replacement="stw 5,g_SN_CC006828@l(4)"
// ASMPROC_replace_insn: match="li 9,6" replacement="li 3,6"
// ASMPROC_replace_insn: match="mtctr 9" replacement="mtctr 3"
// ASMPROC_replace_insn: match="ori 0,0,208" replacement="ori 5,5,208"
extern volatile unsigned int g_SN_CC006828[];

void SNWiggleSelect() {
    int cnt = 6;
    unsigned int v = g_SN_CC006828[0] & 5U;
    g_SN_CC006828[0] = v;
    while (cnt-- > 0) {}
    v |= 0xD0U;
    g_SN_CC006828[0] = v;
}
