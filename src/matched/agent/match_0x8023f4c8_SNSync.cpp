// 0x8023F4C8 SNSync(void) (20B)
// FLAGS: -fno-schedule-insns
// Cascade ASMPROC: 6 GCC insns -> 5 DOL (trailing blr truncated by [:20]).
// Volatile-pointer hoist: lis+la outside loop, lwz inside. inject_before injects
// .L3new: before the la (->lwz) so branch at offset 0x0c targets offset 0x04.
// rlwinm. replaces andi. for bit-0 extract. BO=4,BI=2 = bne cr0.
// ASMPROC_inject_before: before="la 9,g_SN_CC006834@l(9)" lines=".L3new:"
// ASMPROC_replace_insn: match="lis 9,g_SN_CC006834@ha" replacement="lis 4,g_SN_CC006834@ha"
// ASMPROC_replace_insn: match="la 9,g_SN_CC006834@l(9)" replacement="lwz 3,g_SN_CC006834@l(4)"
// ASMPROC_replace_insn: match="lwz 0,0(9)" replacement="rlwinm. 3,3,0,31,31"
// ASMPROC_replace_insn: match="andi. 11,0,1" replacement="bc 4,2,.L3new"
// ASMPROC_replace_insn: match="bc 4,2,.L3" replacement="blr" occurrence=1
extern volatile unsigned int g_SN_CC006834[];

void SNSync() {
    volatile unsigned int *p = g_SN_CC006834;
loop:
    if (p[0] & 1) goto loop;
}
