// ERModel::DrawGeometry(ERC *) at 0x80318950 (108B)
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after=bge src=9 dst=28

struct ERC;
struct ESubModel_DG {
    char pad[24];
    void DrawGeometry(ERC *);
};

struct ESubModelArray_DG {
    ESubModel_DG *data;
    int count;
};

struct ERModel_DG {
    char _pad[60];
    ESubModelArray_DG subs;
    void DrawGeometry(ERC *);
};

void ERModel_DG::DrawGeometry(ERC *pRC) {
    ESubModelArray_DG *p = &subs;
    for (int i = 0; i < p->count; i++) {
        subs.data[i].DrawGeometry(pRC);
    }
}
