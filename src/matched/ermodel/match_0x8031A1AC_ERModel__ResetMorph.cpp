// 0x8031A1AC (112B) ERModel::ResetMorph(void)
// ASMPROC_gpr_relabel: swap=28:29 skip_opcodes=stmw,lmw
// ASMPROC_force_reg: match="addi 28,29" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_force_reg: match="lwz 0,4(28)" from_reg=28 to_reg=9 occurrence=0
// ASMPROC_nop_before: match="cmpw 0,31,0" occurrence=0
// ASMPROC_replace_insn: match="nop" replacement="mr 28,9"

struct ERModel {
    void ResetMorph();
};

void ERModel::ResetMorph() {
}
