// ERModel::DelRefSubResources(void) at 0x8031811C (100B)
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after=bge src=9 dst=28

struct ESubModel_Del {
    char pad[24];
    void DelRefSubResources(void);
};

struct ESubModelArray_Del {
    ESubModel_Del *data;
    int count;
};

struct ERModel_Del {
    char _pad[60];
    ESubModelArray_Del subs;
    void DelRefSubResources(void);
};

void ERModel_Del::DelRefSubResources(void) {
    ESubModelArray_Del *p = &subs;
    for (int i = 0; i < p->count; i++) {
        subs.data[i].DelRefSubResources();
    }
}
