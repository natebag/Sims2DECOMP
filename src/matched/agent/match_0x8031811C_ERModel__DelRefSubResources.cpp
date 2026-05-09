// 0x8031811C (100B) ERModel::DelRefSubResources(void)
// GCC assigns r28=this, r29=p (swapped). Relabel 28 <-> 29, then volatile r9.
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after=bge src=9 dst=28

struct ESubModel_ERDR {
    char pad[24];
    void DelRefSubResources(void);
};

struct ESubModelArray_ERDR {
    ESubModel_ERDR *data;
    int count;
};

struct ERModel_ERDR {
    char _pad[60];
    ESubModelArray_ERDR subs;
    void DelRefSubResources(void);
};

void ERModel_ERDR::DelRefSubResources(void) {
    ESubModelArray_ERDR *p = &subs;
    for (int i = 0; i < p->count; i++) {
        subs.data[i].DelRefSubResources();
    }
}
