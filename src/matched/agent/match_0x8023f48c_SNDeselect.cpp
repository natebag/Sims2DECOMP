// 0x8023F48C SNDeselect(void) (20B)
// FLAGS: -fno-schedule-insns
// Cascade ASMPROC: 5 GCC insns -> 5 DOL. Register rename only: r9->r4, r0->r3.
// g_SN_CC006828[] extern generates lis+lwz@l/stw@l (no ori). AND-then-store pattern.
// ASMPROC_replace_insn: match="lis 9,g_SN_CC006828@ha" replacement="lis 4,g_SN_CC006828@ha"
// ASMPROC_replace_insn: match="lwz 0,g_SN_CC006828@l(9)" replacement="lwz 3,g_SN_CC006828@l(4)"
// ASMPROC_replace_insn: match="andi. 0,0,5" replacement="andi. 3,3,5"
// ASMPROC_replace_insn: match="stw 0,g_SN_CC006828@l(9)" replacement="stw 3,g_SN_CC006828@l(4)"
extern volatile unsigned int g_SN_CC006828[];

void SNDeselect() {
    g_SN_CC006828[0] &= 5;
}
