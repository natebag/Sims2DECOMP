// ERModel::DrawAsShadow(ERC *) at 0x803189BC (108B)
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after=bge src=9 dst=28

struct ERC;
struct ESubModel_DAS {
    char pad[24];
    void DrawAsShadow(ERC *);
};

struct ESubModelArray_DAS {
    ESubModel_DAS *data;
    int count;
};

struct ERModel_DAS {
    char _pad[60];
    ESubModelArray_DAS subs;
    void DrawAsShadow(ERC *);
};

void ERModel_DAS::DrawAsShadow(ERC *pRC) {
    ESubModelArray_DAS *p = &subs;
    for (int i = 0; i < p->count; i++) {
        subs.data[i].DrawAsShadow(pRC);
    }
}
