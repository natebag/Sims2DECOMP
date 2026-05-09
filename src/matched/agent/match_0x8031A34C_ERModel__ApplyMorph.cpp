// 0x8031A34C (120B) ERModel::ApplyMorph(void)
// Variant 3 (no relabel): GCC assigns r29=this naturally (kept alive for m_252=0 post-loop store).
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after="lwz 0,4(9)" src=9 dst=28 occurrence=0

struct ESubModel_ERAM {
    char pad[24];
    void ApplyMorph(void);
};

struct ESubModelArray_ERAM {
    ESubModel_ERAM *data;
    int count;
};

struct ERModel_ERAM {
    char _pad[60];
    ESubModelArray_ERAM subs;
    char _pad2[184];
    int m_252;
    void ApplyMorph(void);
};

void ERModel_ERAM::ApplyMorph(void) {
    if (m_252 == 0) return;
    ESubModelArray_ERAM *p = &subs;
    for (int i = 0; i < p->count; i++) {
        subs.data[i].ApplyMorph();
    }
    m_252 = 0;
}
