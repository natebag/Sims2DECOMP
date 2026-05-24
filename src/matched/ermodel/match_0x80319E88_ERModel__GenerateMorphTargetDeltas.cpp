// 0x80319E88 (128B) ERModel::GenerateMorphTargetDeltas(ERModel *)
// ASMPROC_gpr_relabel: swap=27:29 skip_opcodes=stmw,lmw
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 27,28" from_reg=27 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 9,64(29)" from_reg=9 to_reg=11 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(27)" from_reg=27 to_reg=9 occurrence=0
// ASMPROC_insert_mr: after="lwz 0,4(9)" src=9 dst=27 occurrence=0
// ASMPROC_force_reg: match="cmpw 0,9,0" from_reg=9 to_reg=11 occurrence=0
// ASMPROC_force_reg: match="cmpw 0,30,9" from_reg=9 to_reg=11 occurrence=0

struct ERModel {
    void GenerateMorphTargetDeltas();
};

void ERModel::GenerateMorphTargetDeltas() {
}
