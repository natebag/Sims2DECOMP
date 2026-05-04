// ERModel::DrawNormals(ERC *) at 0x80318A28 (108B)
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after=bge src=9 dst=28

struct ERC;
struct ESubModel_DN {
    char pad[24];
    void DrawNormals(ERC *);
};

struct ESubModelArray_DN {
    ESubModel_DN *data;
    int count;
};

struct ERModel_DN {
    char _pad[60];
    ESubModelArray_DN subs;
    void DrawNormals(ERC *);
};

void ERModel_DN::DrawNormals(ERC *pRC) {
    ESubModelArray_DN *p = &subs;
    for (int i = 0; i < p->count; i++) {
        subs.data[i].DrawNormals(pRC);
    }
}
