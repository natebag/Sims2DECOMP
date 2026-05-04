// ERModel::AddRefSubResources(void) at 0x80318180 (100B)
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after=bge src=9 dst=28

struct ESubModel_AR {
    char pad[24];
    void AddRefSubResources(void);
};

struct ESubModelArray_AR {
    ESubModel_AR *data;
    int count;
};

struct ERModel_AR {
    char _pad[60];
    ESubModelArray_AR subs;
    void AddRefSubResources(void);
};

void ERModel_AR::AddRefSubResources(void) {
    ESubModelArray_AR *p = &subs;
    for (int i = 0; i < p->count; i++) {
        subs.data[i].AddRefSubResources();
    }
}
