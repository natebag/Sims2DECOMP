// ERModel::Draw(ERC *) at 0x80318B18 (108B)
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after=bge src=9 dst=28

struct ERC;
struct ESubModel_Draw {
    char pad[24];
    void Draw(ERC *);
};

struct ESubModelArray_Draw {
    ESubModel_Draw *data;
    int count;
};

struct ERModel_Draw {
    char _pad[60];
    ESubModelArray_Draw subs;
    void Draw(ERC *);
};

void ERModel_Draw::Draw(ERC *pRC) {
    ESubModelArray_Draw *p = &subs;
    for (int i = 0; i < p->count; i++) {
        subs.data[i].Draw(pRC);
    }
}
