// 0x8031A34C (120B) ERModel::ApplyMorph(void)
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after="lwz 0,4(9)" src=9 dst=28 occurrence=0

struct ERModel {
    void ApplyMorph();
};

void ERModel::ApplyMorph() {
}
