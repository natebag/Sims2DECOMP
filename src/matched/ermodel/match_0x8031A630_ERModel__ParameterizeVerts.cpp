// 0x8031A630 (104B) ERModel::ParameterizeVerts(void)
// ASMPROC_force_reg: match="addi 28,30" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after=bge src=9 dst=28

struct ERModel {
    void ParameterizeVerts();
};

void ERModel::ParameterizeVerts() {
}
