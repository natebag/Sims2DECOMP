// ASMPROC_replace_insn: match="cmpwi 0,3,0" replacement="lwz 10,0(31)" occurrence=0
// ASMPROC_replace_insn: match="cmpwi 0,3,0" replacement="cmpwi 0,11,0"
// ASMPROC_replace_insn: match="lwz 4,0(30)" replacement="addi 11,3,-1"
// ASMPROC_replace_insn: match="lwz 11,0(31)" replacement="lwz 4,0(30)"
// ASMPROC_replace_insn: match="addi 3,3,-1" replacement="cmpwi 0,3,0" occurrence=0
// ASMPROC_replace_insn: match="lwz 9,0(11)" replacement="lwz 9,0(10)"
// ASMPROC_replace_insn: match="addi 11,11,4" replacement="addi 10,10,4"
// ASMPROC_replace_insn: match="addi 3,3,-1" replacement="addi 11,11,-1"

struct EBitArray {
    void op_eq();
};

void EBitArray::op_eq() {
}
