// ERModel::ResetMorph(void) at 0x8031A1AC (112B)
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after="lwz 0,4(9)" src=9 dst=28 occurrence=0

struct ESubModel_RM {
    char pad[24];
    void ResetMorph(void);
};

struct ESubModelArray_RM {
    ESubModel_RM *data;
    int count;
};

struct ERModel_RM {
    char _pad[60];
    ESubModelArray_RM subs;
    char _pad2[184];
    void *m_morphPtr;
    void ResetMorph(void);
};

void ERModel_RM::ResetMorph(void) {
    if (m_morphPtr != 0) {
        ESubModelArray_RM *p = &subs;
        for (int i = 0; i < p->count; i++) {
            subs.data[i].ResetMorph();
        }
    }
}
