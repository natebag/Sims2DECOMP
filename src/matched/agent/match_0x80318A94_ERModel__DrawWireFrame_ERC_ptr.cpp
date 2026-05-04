// ERModel::DrawWireFrame(ERC *) at 0x80318A94 (108B)
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after=bge src=9 dst=28

struct ERC;
struct ESubModel_DWF {
    char pad[24];
    void DrawWireFrame(ERC *);
};

struct ESubModelArray_DWF {
    ESubModel_DWF *data;
    int count;
};

struct ERModel_DWF {
    char _pad[60];
    ESubModelArray_DWF subs;
    void DrawWireFrame(ERC *);
};

void ERModel_DWF::DrawWireFrame(ERC *pRC) {
    ESubModelArray_DWF *p = &subs;
    for (int i = 0; i < p->count; i++) {
        subs.data[i].DrawWireFrame(pRC);
    }
}
