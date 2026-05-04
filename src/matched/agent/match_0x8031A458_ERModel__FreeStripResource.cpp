// ERModel::FreeStripResource(void) at 0x8031A458 (100B)
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after=bge src=9 dst=28

struct ESubModel_FSR {
    char pad[24];
    void FreeStripResource(void);
};

struct ESubModelArray_FSR {
    ESubModel_FSR *data;
    int count;
};

struct ERModel_FSR {
    char _pad[60];
    ESubModelArray_FSR subs;
    void FreeStripResource(void);
};

void ERModel_FSR::FreeStripResource(void) {
    ESubModelArray_FSR *p = &subs;
    for (int i = 0; i < p->count; i++) {
        subs.data[i].FreeStripResource();
    }
}
