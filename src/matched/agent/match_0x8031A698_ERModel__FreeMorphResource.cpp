// ERModel::FreeMorphResource(void) at 0x8031A698 (100B)
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after=bge src=9 dst=28

struct ESubModel_FMR {
    char pad[24];
    void FreeMorphResource(void);
};

struct ESubModelArray_FMR {
    ESubModel_FMR *data;
    int count;
};

struct ERModel_FMR {
    char _pad[60];
    ESubModelArray_FMR subs;
    void FreeMorphResource(void);
};

void ERModel_FMR::FreeMorphResource(void) {
    ESubModelArray_FMR *p = &subs;
    for (int i = 0; i < p->count; i++) {
        subs.data[i].FreeMorphResource();
    }
}
