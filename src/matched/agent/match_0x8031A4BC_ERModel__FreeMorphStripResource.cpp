// ERModel::FreeMorphStripResource(void) at 0x8031A4BC (100B)
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after=bge src=9 dst=28

struct ESubModel_FMSR {
    char pad[24];
    void FreeMorphStripResource(void);
};

struct ESubModelArray_FMSR {
    ESubModel_FMSR *data;
    int count;
};

struct ERModel_FMSR {
    char _pad[60];
    ESubModelArray_FMSR subs;
    void FreeMorphStripResource(void);
};

void ERModel_FMSR::FreeMorphStripResource(void) {
    ESubModelArray_FMSR *p = &subs;
    for (int i = 0; i < p->count; i++) {
        subs.data[i].FreeMorphStripResource();
    }
}
