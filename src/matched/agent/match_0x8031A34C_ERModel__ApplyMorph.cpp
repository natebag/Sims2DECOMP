// ERModel::ApplyMorph(void) at 0x8031A34C (120B)
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after="lwz 0,4(9)" src=9 dst=28 occurrence=0

struct ESubModel_AM {
    char pad[24];
    void ApplyMorph(void);
};

struct ESubModelArray_AM {
    ESubModel_AM *data;
    int count;
};

struct ERModel_AM {
    char _pad[60];
    ESubModelArray_AM subs;
    char _pad2[184];
    void *m_morphPtr;
    void ApplyMorph(void);
};

void ERModel_AM::ApplyMorph(void) {
    if (m_morphPtr != 0) {
        ESubModelArray_AM *p = &subs;
        for (int i = 0; i < p->count; i++) {
            subs.data[i].ApplyMorph();
        }
        m_morphPtr = 0;
    }
}
