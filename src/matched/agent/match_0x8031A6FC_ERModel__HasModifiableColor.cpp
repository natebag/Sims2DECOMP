// ERModel::HasModifiableColor(void) at 0x8031A6FC (120B)
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after=bge src=9 dst=28

struct ESubModel_HMC {
    char pad[24];
    int HasModifiableColor(void);
};

struct ESubModelArray_HMC {
    ESubModel_HMC *data;
    int count;
};

struct ERModel_HMC {
    char _pad[60];
    ESubModelArray_HMC subs;
    int HasModifiableColor(void);
};

int ERModel_HMC::HasModifiableColor(void) {
    ESubModelArray_HMC *p = &subs;
    for (int i = 0; i < p->count; i++) {
        if (subs.data[i].HasModifiableColor()) {
            return 1;
        }
    }
    return 0;
}
