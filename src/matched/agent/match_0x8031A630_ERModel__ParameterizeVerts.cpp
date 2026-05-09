// 0x8031A630 (104B) ERModel::ParameterizeVerts(void)
// GCC assigns r30=this directly (no relabel); volatile r9 intermediate for &subs.
// ASMPROC_force_reg: match="addi 28,30" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after=bge src=9 dst=28

struct TArrayBSV_PV {};

struct ESubModel_PV {
    char pad[24];
    void ParameterizeVerts(TArrayBSV_PV *arr);
};

struct ESubModelArray_PV {
    ESubModel_PV *data;
    int count;
};

struct ERModel_PV {
    char _pad[60];
    ESubModelArray_PV subs;
    char _pad2[192];
    TArrayBSV_PV m_260;
    void ParameterizeVerts(void);
};

void ERModel_PV::ParameterizeVerts(void) {
    ESubModelArray_PV *p = &subs;
    for (int i = 0; i < p->count; i++) {
        subs.data[i].ParameterizeVerts(&m_260);
    }
}
