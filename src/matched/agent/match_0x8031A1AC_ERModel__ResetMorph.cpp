// 0x8031A1AC (112B) ERModel::ResetMorph(void)
// GCC assigns r28=this, r29=p. Relabel 28<->29, then volatile r9 lazy + mr before cmpw.
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_nop_before: match="cmpw 0,31,0" occurrence=0
// ASMPROC_replace_insn: match="nop" replacement="mr 28,9"

struct ESubModel_RSM {
    char pad[24];
    void ResetMorph(void);
};

struct ESubModelArray_RSM {
    ESubModel_RSM *data;
    int count;
};

struct ERModel_RSM {
    char _pad[60];
    ESubModelArray_RSM subs;
    char _pad2[184];
    int m_252;
    void ResetMorph(void);
};

void ERModel_RSM::ResetMorph(void) {
    if (m_252 == 0) return;
    ESubModelArray_RSM *p = &subs;
    for (int i = 0; i < p->count; i++) {
        subs.data[i].ResetMorph();
    }
}
